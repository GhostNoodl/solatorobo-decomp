#!/usr/bin/env python3
# Prototype audit (round ptA): finds C-linkage functions that are declared with different return types or
# parameter lists across the tree, and the hack sites / NONMATCHING drafts that call them.
#
#   python3 tools/protoaudit.py [--all] [--sites] [--asm] [--name SUBSTR] [--json OUT]
#   python3 tools/protoaudit.py --rewrite-returns LOG [--only PREFIX,...] [--skip FILE]
#
# Default output: one block per function whose return class differs between declarations (void vs value, or
# integer width/sign), with the "truth" (the matched C definition's prototype when the function is defined in C,
# preferring one outside `#ifdef NONMATCHING`; otherwise the asm heuristic with --asm) and every declaration
# grouped by signature.
#   --all    also list functions whose only difference is the parameter list or ptr-vs-int / struct-pointer type
#   --sites  list hack sites (functions with a `(u32)x & 3` test, a local `volatile`, or a comment mentioning
#            a hack/trick/fake/junk) and NONMATCHING drafts, with every callee whose prototype visible in that
#            TU disagrees with the truth (MISMATCH = return class, PARAMS = count or integer param class)
#   --asm    for callees with no C definition, guess from the base ROM whether r0 is a return value (every
#            return path writes r0 after the last call/branch without reading it again). Weak: a hint only.
#   --rewrite-returns LOG
#            rewrite the return type of every non-defining declaration to the definition's class (pointers are
#            only touched when one side is void). Every edit is appended to LOG. Always rebuild and compare the
#            objects afterwards: some wrong prototypes are load-bearing (docs/MATCHING.md, round ptA).
#
# Caveat on "truth": a `void` definition whose body ends in a call, or a constructor-style init that never
# touches r0, compiles the same as one that returns the callee's value / `self`. When callers use a value and the
# definition says void, the definition is usually the one to fix (round ptA fixed several this way).
# Classes: void, i32 (int/s32/u32/BOOL/long/enum), i16u/i16s, i8u/i8s, ptr, f32, f64, i64, named:T.
# Only names that are in a symbols.txt (linker names) are audited; C++ members and statics are skipped.
# Declarations are found textually (comments and strings blanked), so macros that build prototypes are missed.
import argparse
import json
import re
import struct
import sys
from collections import defaultdict
from pathlib import Path

root = Path(__file__).resolve().parent.parent

INT_CLASS = {
    'void': 'void', 'int': 'i32', 'signed int': 'i32', 'unsigned int': 'i32', 'unsigned': 'i32', 'signed': 'i32',
    's32': 'i32', 'u32': 'i32', 'BOOL': 'i32', 'long': 'i32', 'unsigned long': 'i32', 'vs32': 'i32', 'vu32': 'i32',
    'short': 'i16s', 's16': 'i16s', 'signed short': 'i16s', 'unsigned short': 'i16u', 'u16': 'i16u',
    'char': 'i8s', 'signed char': 'i8s', 's8': 'i8s', 'unsigned char': 'i8u', 'u8': 'i8u', 'bool': 'i8u',
    'float': 'f32', 'f32': 'f32', 'double': 'f64', 'f64': 'f64',
    's64': 'i64', 'u64': 'i64', 'long long': 'i64', 'unsigned long long': 'i64',
    'fx32': 'i32', 'fx16': 'i16s', 'size_t': 'i32', 'OSIntrMode': 'i32',
}
KEYWORDS = {'return', 'else', 'goto', 'case', 'do', 'if', 'while', 'for', 'switch', 'sizeof', 'new', 'delete',
            'throw', 'typedef', 'using', 'operator', 'define', 'elif', 'ifdef', 'ifndef', 'undef', 'include'}


def strip(text):
    """Blank out comments and string/char literals, keeping offsets and newlines."""
    out = []
    i, n = 0, len(text)
    while i < n:
        c = text[i]
        if c == '/' and i + 1 < n and text[i + 1] == '/':
            j = text.find('\n', i)
            j = n if j < 0 else j
            out.append(' ' * (j - i))
            i = j
        elif c == '/' and i + 1 < n and text[i + 1] == '*':
            j = text.find('*/', i + 2)
            j = n if j < 0 else j + 2
            out.append(re.sub(r'[^\n]', ' ', text[i:j]))
            i = j
        elif c in '"\'':
            j = i + 1
            while j < n and text[j] != c:
                j += 2 if text[j] == '\\' else 1
            j = min(j + 1, n)
            # keep extern "C" recognisable
            if text[i:j] == '"C"':
                out.append('"C"')
            else:
                out.append(c + ' ' * (j - i - 2) + c if j - i >= 2 else ' ' * (j - i))
            i = j
        else:
            out.append(c)
            i += 1
    return ''.join(out)


def load_symbols():
    syms = {}
    for p in (root / 'config').rglob('symbols.txt'):
        mod = 'main' if p.parent.name == 'arm9' else p.parent.name
        if p.parent.name in ('itcm', 'dtcm'):
            mod = p.parent.name
        for line in p.read_text().splitlines():
            parts = line.split()
            if len(parts) < 3 or not parts[1].startswith('kind:function'):
                continue
            m = re.search(r'size=0x([0-9a-f]+)', parts[1])
            a = re.search(r'addr:0x([0-9a-f]+)', line)
            syms[parts[0]] = (mod, int(a.group(1), 16), int(m.group(1), 16) if m else 0, 'thumb' in parts[1])
    return syms


def norm_type(t, typedefs):
    t = t.replace('"C"', ' ')
    t = re.sub(r'\b(extern|static|inline|__inline|register|"C"|asm|const|volatile|struct|union|enum|class)\b', ' ', t)
    t = re.sub(r'\s+', ' ', t).strip()
    t = t.replace(' *', '*').replace('* ', '*')
    return t


def classify(t, typedefs, depth=0):
    if '*' in t or '&' in t:
        return 'ptr'
    base = t.strip()
    if base in INT_CLASS:
        return INT_CLASS[base]
    if base in typedefs and depth < 8:
        return classify(typedefs[base], typedefs, depth + 1)
    if base in ENUMS:
        return 'i32'
    return 'named:' + base


def split_params(p):
    p = p.strip()
    if p in ('', 'void'):
        return []
    parts, depth, cur = [], 0, ''
    for c in p:
        if c in '([<':
            depth += 1
        elif c in ')]>':
            depth -= 1
        if c == ',' and depth == 0:
            parts.append(cur)
            cur = ''
        else:
            cur += c
    parts.append(cur)
    return [x.strip() for x in parts]


def param_type(p):
    p = re.sub(r'=.*$', '', p).strip()
    if p == '...':
        return '...'
    if '(' in p:
        return '*'  # function pointer
    m = re.match(r'^(.*?)([A-Za-z_]\w*)?\s*(\[[^\]]*\])*$', p)
    if p.endswith(']'):
        return 'ptr'
    toks = re.findall(r'[A-Za-z_]\w*|\*|&', p)
    # drop a trailing name when more than one type token
    words = [x for x in toks if x not in ('const', 'volatile', 'struct', 'union', 'enum', 'register')]
    if len(words) >= 2 and re.match(r'[A-Za-z_]', words[-1]) and words[-1] not in INT_CLASS:
        if not (len(words) == 2 and words[0] in ('unsigned', 'signed')):
            words = words[:-1]
    return ' '.join(words).replace(' *', '*').replace('* ', '*').replace(' &', '&')


DECL_RE = re.compile(
    r'(?:(?<=[;{}\n])|^)[ \t]*((?:(?:extern|static|inline|__inline|"C"|const|volatile|unsigned|signed|struct|enum|union)\s+)*'
    r'[A-Za-z_]\w*(?:\s*::\s*\w+)?(?:\s+(?:const|int|long|short|char))*[\s\*&]+(?:const\s+)?)'
    r'([A-Za-z_]\w*)\s*\(([^;{}()]*(?:\([^()]*\)[^;{}()]*)*)\)\s*(;|\{|__attribute__)', re.M)
INCL_RE = re.compile(r'^\s*#\s*include\s*[<"]([^>"]+)[>"]', re.M)
TYPEDEF_RE = re.compile(r'typedef\s+((?:unsigned|signed|const|volatile|struct|enum|union|\s)*[A-Za-z_]\w*[\s\*]*)\s+([A-Za-z_]\w*)\s*;')
ENUM_RE = re.compile(r'(?:typedef\s+)?enum\s+(\w+)?\s*\{[^}]*\}\s*(\w+)?')
ENUMS = set()


class Decl:
    __slots__ = ('name', 'file', 'line', 'ret', 'rcls', 'params', 'pcls', 'is_def', 'off', 'static', 'rspan', 'in_nm',
                 'path')

    def __init__(self, **kw):
        for k, v in kw.items():
            setattr(self, k, v)

    def sig(self):
        return f"{self.ret} ({', '.join(self.params) or 'void'})"


def scan_files():
    files = []
    for d in ('src', 'libs', 'include'):
        for p in sorted((root / d).rglob('*')):
            if p.suffix in ('.c', '.cpp', '.h', '.hpp', '.inc') and p.is_file():
                files.append(p)
    return files


def line_of(text, off):
    return text.count('\n', 0, off) + 1


def nonmatching_ranges(raw):
    """Line ranges [a, b) of `#ifdef NONMATCHING` arms (to #else/#endif, nesting aware)."""
    lines = raw.split('\n')
    res, stack = [], []
    for i, l in enumerate(lines, 1):
        s = l.strip()
        if re.match(r'#\s*if', s):
            stack.append((i, 'NONMATCHING' in s and '!' not in s and 'ndef' not in s))
        elif re.match(r'#\s*(else|elif)', s) and stack:
            a, nm = stack[-1]
            if nm:
                res.append((a, i))
            stack[-1] = (i, False)
        elif re.match(r'#\s*endif', s) and stack:
            a, nm = stack.pop()
            if nm:
                res.append((a, i))
    return res


def func_bodies(stripped, decls_in_file):
    """(name, start_off, end_off) of each definition in this file."""
    res = []
    for d in decls_in_file:
        if not d.is_def:
            continue
        i = stripped.find('{', d.off)
        depth, j = 0, i
        while j < len(stripped):
            if stripped[j] == '{':
                depth += 1
            elif stripped[j] == '}':
                depth -= 1
                if depth == 0:
                    break
            j += 1
        res.append((d.name, i, j))
    return res


def main():
    ap = argparse.ArgumentParser()
    ap.add_argument('--all', action='store_true')
    ap.add_argument('--sites', action='store_true')
    ap.add_argument('--asm', action='store_true')
    ap.add_argument('--name')
    ap.add_argument('--json')
    ap.add_argument('--rewrite-returns', metavar='LOG',
                    help='rewrite the return type of every declaration whose return class differs from the matched '
                         'C definition (void / integer width+sign; a pointer is written as `void *` only where the '
                         'declaration had no pointer); append `file<TAB>offset<TAB>old<TAB>new` lines to LOG')
    ap.add_argument('--only', default='', help='with --rewrite-returns: comma-separated path prefixes to touch')
    ap.add_argument('--skip', default='', help='with --rewrite-returns: file of paths / function names / '
                    'path:name pairs (one per line) to leave alone')
    a = ap.parse_args()

    syms = load_symbols()
    files = scan_files()
    texts, stripped = {}, {}
    typedefs = {}
    for p in files:
        raw = p.read_text(errors='replace')
        texts[p] = raw
        s = strip(raw)
        stripped[p] = s
        for m in TYPEDEF_RE.finditer(s):
            t = norm_type(m.group(1), typedefs)
            if m.group(2) not in typedefs:
                typedefs[m.group(2)] = t
        for m in ENUM_RE.finditer(s):
            for g in m.groups():
                if g:
                    ENUMS.add(g)

    decls = defaultdict(list)
    by_file = defaultdict(list)
    for p in files:
        s = stripped[p]
        nmr = nonmatching_ranges(texts[p])
        for m in DECL_RE.finditer(s):
            name = m.group(2)
            if name not in syms:
                continue
            rt = m.group(1)
            toks = re.findall(r'\w+', rt)
            if any(t in KEYWORDS for t in toks):
                continue
            ret = norm_type(rt, typedefs)
            if not ret or ret in KEYWORDS:
                continue
            params = [param_type(x) for x in split_params(m.group(3))]
            # a call like `foo(bar(x));` can't match because the type part needs a type token then the name
            d = Decl(name=name, file=p.relative_to(root), line=line_of(s, m.start(2)), ret=ret,
                     rcls=classify(ret, typedefs), params=params,
                     pcls=tuple('...' if x == '...' else classify(x, typedefs) for x in params),
                     is_def=m.group(4) == '{', off=m.start(2), static='static' in rt,
                     rspan=(m.start(1), m.end(1)), path=p,
                     in_nm=any(a_ <= line_of(s, m.start(2)) < b_ for a_, b_ in nmr))
            decls[name].append(d)
            by_file[p].append(d)

    # includes (transitive) for visibility
    incl = {}
    for p in files:
        out = []
        for m in INCL_RE.finditer(texts[p]):
            inc = m.group(1)
            for base in (p.parent, root / 'include', root / 'libs'):
                q = (base / inc)
                if q.exists():
                    out.append(q.resolve())
                    break
        incl[p.resolve()] = out
    bf = {p.resolve(): v for p, v in by_file.items()}

    def visible(p):
        seen, stack, res = set(), [p.resolve()], []
        while stack:
            q = stack.pop()
            if q in seen:
                continue
            seen.add(q)
            res.extend(bf.get(q, []))
            stack.extend(incl.get(q, []))
        return res

    # asm heuristic
    rom = {}

    def asm_returns_value(name):
        mod, addr, size, thumb = syms[name]
        if thumb or size == 0:
            return None
        if mod not in rom:
            rom[mod] = module_code(mod)
        code, base = rom[mod]
        if code is None:
            return None
        import capstone
        md = capstone.Cs(capstone.CS_ARCH_ARM, capstone.CS_MODE_ARM)
        md.detail = True
        insns = list(md.disasm(code[addr - base: addr - base + size], addr))
        verdicts = []
        for k, ins in enumerate(insns):
            ret = (ins.mnemonic.startswith('bx') and ins.op_str == 'lr') or \
                  (ins.mnemonic.startswith(('pop', 'ldm')) and 'pc' in ins.op_str)
            if not ret:
                continue
            v = 'unknown'
            read = False
            for j in range(k - 1, -1, -1):
                q = insns[j]
                if q.mnemonic.startswith('b') and not q.mnemonic.startswith(('bic',)):
                    v = 'call' if q.mnemonic.startswith('bl') else 'unknown'
                    break
                try:
                    rr, ww = q.regs_access()
                except Exception:
                    break
                rnames = [q.reg_name(r) for r in rr]
                wnames = [q.reg_name(r) for r in ww]
                if 'r0' in wnames:
                    v = 'used' if read or 'r0' in rnames else 'set'
                    break
                if 'r0' in rnames:
                    read = True
            verdicts.append(v)
        if not verdicts:
            return None
        if all(v == 'set' for v in verdicts):
            return 'value'
        if any(v == 'set' for v in verdicts):
            return 'value?'
        return 'no-value?' if all(v == 'used' for v in verdicts) else None

    results = []
    for name, ds in sorted(decls.items()):
        if a.name and a.name not in name:
            continue
        if any(d.static for d in ds):
            continue
        defs = sorted([d for d in ds if d.is_def], key=lambda d: d.in_nm)
        rcls = {d.rcls for d in ds}
        npar = {len(d.pcls) for d in ds if '...' not in d.pcls}
        rcls_core = {('void' if c == 'void' else 'ptr' if c == 'ptr' else c) for c in rcls}
        serious = 'void' in rcls and len(rcls) > 1 or len({c for c in rcls_core if c not in ('ptr',) and not c.startswith('named:')}) > 1
        diff = len(rcls) > 1 or len(npar) > 1
        if not diff:
            continue
        if not serious and not a.all and len(npar) <= 1:
            continue
        truth = None
        tpcls = None
        if defs:
            truth = defs[0].rcls
            tpcls = defs[0].pcls
            truth_src = f'definition {defs[0].file}:{defs[0].line}: {defs[0].sig()}'
        elif a.asm:
            v = asm_returns_value(name)
            truth_src = f'asm heuristic: {v}'
            truth = {'value': 'value', 'value?': 'value', 'no-value?': 'void'}.get(v)
        else:
            truth_src = 'no C definition'
        results.append(dict(name=name, serious=serious, truth=truth, truth_src=truth_src, tpcls=tpcls,
                            truth_ret=defs[0].ret if defs else None,
                            truth_params=defs[0].params if defs else None,
                            decls=[dict(file=str(d.file), line=d.line, sig=d.sig(), rcls=d.rcls, npar=len(d.pcls),
                                        is_def=d.is_def) for d in ds]))

    if not a.sites:
        for r in results:
            print(f"== {r['name']}{'  [RETURN CLASS]' if r['serious'] else ''}  truth: {r['truth_src']}")
            groups = defaultdict(list)
            for d in r['decls']:
                groups[(d['sig'])].append(f"{d['file']}:{d['line']}{' (def)' if d['is_def'] else ''}")
            for sig, locs in sorted(groups.items(), key=lambda x: -len(x[1])):
                print(f"   {len(locs):3d}x {sig}")
                for l in locs[:6]:
                    print(f"         {l}")
                if len(locs) > 6:
                    print(f"         ... +{len(locs) - 6}")
        print(f"\n{len(results)} functions listed, {sum(r['serious'] for r in results)} with a return-class conflict")

    if a.sites:
        bad = {r['name']: r for r in results}
        for p in files:
            if p.suffix not in ('.c', '.cpp'):
                continue
            raw, s = texts[p], stripped[p]
            nmr = nonmatching_ranges(raw)
            vis = visible(p)
            vis_by = defaultdict(list)
            for d in vis:
                vis_by[d.name].append(d)
            bodies = func_bodies(s, by_file.get(p, []))
            relp = p.relative_to(root)

            def in_other_body(d, b0):
                return d.file == relp and any(x0 < d.off < x1 and x0 != b0 for _, x0, x1 in bodies)

            for fname, b0, b1 in bodies:
                body_raw, body = raw[b0:b1], s[b0:b1]
                l0 = line_of(s, b0)
                tags = []
                if any(a_ <= l0 < b_ for a_, b_ in nmr):
                    tags.append('NONMATCHING')
                if re.search(r'\(u32\)\s*\w+\s*&\s*3\)', body):
                    tags.append('ptrbit')
                if re.search(r'(^|[;{(,]\s*)volatile\b', body, re.M):
                    tags.append('volatile')
                if re.search(r'\b(hack|trick|fake|junk)\b', body_raw, re.I):
                    tags.append('comment')
                if not tags:
                    continue
                called = set(re.findall(r'\b([A-Za-z_]\w*)\s*\(', body))
                nmis = 0
                print(f"-- {p.relative_to(root)}:{fname} [{','.join(tags)}]")
                for c in sorted(called):
                    if c not in bad:
                        # single-prototype callee with no C definition, declared void here: ask the ROM
                        if a.asm and c in syms and c in decls and not any(d.is_def for d in decls[c]):
                            vd = [d for d in vis_by.get(c, []) if not in_other_body(d, b0)]
                            if vd and vd[-1].rcls == 'void':
                                v = asm_returns_value(c)
                                if v in ('value', 'value?'):
                                    nmis += 1
                                    print(f"     calls {c}: visible {vd[-1].sig()}; asm-only callee, heuristic: {v}"
                                          f"  <-- MISMATCH?")
                        continue
                    r = bad[c]
                    # visible prototype: the last one before the body in this file, else any from includes
                    loc = [d for d in vis_by.get(c, []) if not d.is_def and (d.file != relp or d.off < b1)
                           and not in_other_body(d, b0)]
                    loc = loc[-1:] if loc else []
                    vr = loc[0].rcls if loc else '?'
                    vsig = loc[0].sig() if loc else '(none visible)'
                    mism = proto_mismatch(r['truth'], vr)
                    pm = []
                    if loc and r['tpcls'] is not None:
                        vp, tp = loc[0].pcls, r['tpcls']
                        if len(vp) != len(tp) and '...' not in vp + tp:
                            pm.append('count')
                        ints = ('i32', 'i16u', 'i16s', 'i8u', 'i8s')
                        for k, (x, y) in enumerate(zip(vp, tp)):
                            if x != y and x in ints and y in ints:
                                pm.append(f'p{k}:{x}->{y}')
                    nmis += mism or bool(pm)
                    flag = ('  <-- MISMATCH' if mism else '') + (f"  <-- PARAMS {' '.join(pm)}" if pm else '')
                    print(f"     calls {c}: visible {vsig}; truth {r['truth_src']}{flag}")

    if a.rewrite_returns:
        canon = {'i32': 's32', 'i16u': 'u16', 'i16s': 's16', 'i8u': 'u8', 'i8s': 's8', 'void': 'void'}
        basic = set(INT_CLASS) - {'fx32', 'fx16', 'size_t', 'OSIntrMode', 'vs32', 'vu32', 'f32', 'f64', 'float', 'double'}
        edits = defaultdict(list)
        only = [x for x in a.only.split(',') if x]
        skip = set(Path(a.skip).read_text().split()) if a.skip else set()
        for name, ds in decls.items():
            defs = sorted([d for d in ds if d.is_def and not d.static], key=lambda d: d.in_nm)
            if not defs or defs[0].in_nm or any(d.static for d in ds):
                continue
            t = defs[0]
            if t.rcls.startswith('named:') or t.rcls in ('f32', 'f64', 'i64'):
                continue
            for d in ds:
                if d.is_def or d.rcls == t.rcls or d.rcls.startswith('named:'):
                    continue
                if only and not any(str(d.file).startswith(o) for o in only):
                    continue
                if str(d.file) in skip or name in skip or f'{d.file}:{name}' in skip:
                    continue
                if t.rcls == 'ptr':
                    if d.rcls != 'void':
                        continue  # int-vs-pointer gives the same code
                    new = 'void *'
                elif t.ret in basic:
                    new = t.ret
                else:
                    new = canon[t.rcls]
                if d.rcls == 'ptr' and t.rcls != 'void':
                    continue  # pointer-vs-int: same code, leave the caller's view alone
                edits[d.path].append((d.rspan, new, d.name))
        with open(a.rewrite_returns, 'a') as log:
            for path, es in edits.items():
                raw = texts[path]
                for (b0, b1), new, name in sorted(es, reverse=True):
                    old = raw[b0:b1]
                    pm = re.match(r'(\s*(?:(?:extern|static|inline|__inline|"C")\s+)*)', old)
                    pre = pm.group(1)
                    repl = pre + new + ('' if new.endswith('*') else ' ')
                    raw = raw[:b0] + repl + raw[b1:]
                    log.write(f"{path.relative_to(root)}\t{name}\t{old.strip()!r}\t{new}\n")
                path.write_text(raw)
        print(f"rewrote {sum(len(v) for v in edits.values())} declarations in {len(edits)} files")
        return

    if a.json:
        Path(a.json).write_text(json.dumps(results, indent=1))


def proto_mismatch(truth, visible):
    """True when the caller's visible return class can change the call site's code: void vs value, or two
    different integer widths/signs. ptr / named struct types are treated as compatible with each other."""
    if truth is None or visible == '?':
        return False
    if truth == 'value':
        return visible == 'void'
    if (truth == 'void') != (visible == 'void'):
        return True
    ints = ('i32', 'i16u', 'i16s', 'i8u', 'i8s')
    return truth in ints and visible in ints and truth != visible


def module_code(mod):
    try:
        import yaml
    except ImportError:
        return None, 0
    ex = root / 'extract' / 'usa'
    if mod == 'main':
        c = yaml.safe_load((ex / 'arm9' / 'arm9.yaml').read_text())
        return (ex / 'arm9' / 'arm9.bin').read_bytes(), c['base_address']
    if mod in ('itcm', 'dtcm'):
        c = yaml.safe_load((ex / 'arm9' / f'{mod}.yaml').read_text())
        return (ex / 'arm9' / f'{mod}.bin').read_bytes(), c['base_address']
    oid = int(mod.removeprefix('ov'))
    ovs = yaml.safe_load((ex / 'arm9_overlays' / 'overlays.yaml').read_text())['overlays']
    o = next(o for o in ovs if o['id'] == oid)
    return (ex / 'arm9_overlays' / o['file_name']).read_bytes(), o['base_address']


if __name__ == '__main__':
    main()
