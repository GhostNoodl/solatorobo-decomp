#!/usr/bin/env python3
# splitmod.py: split-then-modify search for register-coalescing near-misses.
#
#   python3 tools/splitmod.py draft.cpp func_ov000_02199554 --module ov000 [-o out.cpp] [-j 4]
#
# Variants, in the target function and in every function of the same file it calls (inlines):
#   split    `T v = A op B;` / `v = A op B;`  ->  `T v = A; v op= B;` (and `T v = B; v op= A;` when op
#            is commutative), op in + - * / % << >> & | ^. The `v op= B;` goes right after the first
#            statement, or (`@run`) after the declarations that follow it.
#   extract  a pure `A op B` inside a statement, an if/switch condition or an argument
#            ->  `s32 sm_tN = A; sm_tN op= B;` before the statement, with sm_tN in its place
#            (also u32 for >> / %). --no-extract turns this off.
#   For `-`, both also get the right-operand split `T v = B; v = A - v;` (labels ending in `r`),
#   which loads B first and keeps the result in B's register (round ovhimid5).
# Singles and pairs of the best singles (plus "every site at once") are scored with tools/match.py
# (raw and register-masked sequence diff). The best states (--beam) are kept and expanded again.
# A final sweep moves one declaration within its run, or swaps two adjacent plain statements.
# Prints the scores and writes the best text to -o (default: <draft>.split.<ext>). Labels name
# function:line:op; tidy the sm_tN names before landing a result.
# Uses the repository the script sits in (tools/..), or $W. Set TMPDIR to keep temp files elsewhere.
import argparse, difflib, hashlib, os, re, subprocess, sys, tempfile
from concurrent.futures import ThreadPoolExecutor

ROOT = os.environ.get('W') or os.path.dirname(os.path.dirname(os.path.abspath(__file__)))

# ---------------------------------------------------------------- scoring
RG = re.compile(r"\b(r[0-9]+|sb|sl|fp|ip|lr)\b")
LINE = re.compile(r'(?:!!|  ) [0-9a-f]{8}  (.*?)\s*\|\s(.*)$')


def norm0(s):
    return re.sub(r'^blx\b', 'bl', re.sub(r'#0x2[0-9a-f]{6}\b|\[pc, #0x[0-9a-f]+\]', 'X', s))


def seqdiff(L, R):
    n = 0
    for op, i1, i2, j1, j2 in difflib.SequenceMatcher(None, L, R, autojunk=False).get_opcodes():
        if op != 'equal':
            n += max(i2 - i1, j2 - j1)
    return n


_size = {}


def fsize(func, mod):
    if (func, mod) not in _size:
        p = ROOT + ('/config/usa/arm9/symbols.txt' if mod == 'main' else
                    '/config/usa/arm9/%s/symbols.txt' % mod if mod in ('itcm', 'dtcm') else
                    '/config/usa/arm9/overlays/%s/symbols.txt' % mod)
        size = None
        try:
            for l in open(p):
                if l.startswith(func + ' '):
                    m = re.search(r'size=0x([0-9a-f]+)', l)
                    if m:
                        size = int(m.group(1), 16) // 4
        except OSError:
            pass
        _size[func, mod] = size
    return _size[func, mod]


BAD = (99999, 99999, None)


def score_text(text, func, mod, ext):
    d = tempfile.mkdtemp()
    try:
        p = d + '/x.' + ext
        open(p, 'w').write(text)
        out = subprocess.run(['python3', 'tools/match.py', p, func, '--module', mod], capture_output=True,
                             text=True, cwd=ROOT, timeout=300).stdout
    except subprocess.TimeoutExpired:
        return BAD
    finally:
        subprocess.run(['rm', '-rf', d])
    L, R = [], []
    for l in out.split('\n'):
        m = LINE.match(l)
        if m:
            a, b = m.group(1).strip(), m.group(2).strip()
            if a: L.append(norm0(a))
            if b: R.append(norm0(b))
    if not L:
        return BAD
    size = fsize(func, mod)
    pad = size - len(R) if size and len(R) < size - 2 else 0
    raw = seqdiff(L, R) + pad
    masked = seqdiff([RG.sub('R', x) for x in L], [RG.sub('R', x) for x in R]) + pad
    return raw, masked, hashlib.md5('\n'.join(L).encode()).hexdigest()[:10]


def key(s):
    return (s[0] + s[1], s[0])


# ---------------------------------------------------------------- parsing
def mask(t):
    """Same-length copy with comments, strings, chars and preprocessor lines blanked."""
    o = list(t); i = 0; n = len(t)
    while i < n:
        c = t[i]
        if t.startswith('//', i):
            j = t.find('\n', i); j = n if j < 0 else j
            o[i:j] = ' ' * (j - i); i = j
        elif t.startswith('/*', i):
            j = t.find('*/', i + 2); j = n if j < 0 else j + 2
            o[i:j] = [ch if ch == '\n' else ' ' for ch in t[i:j]]; i = j
        elif c in '"\'':
            j = i + 1
            while j < n and t[j] != c:
                j += 2 if t[j] == '\\' else 1
            j += 1
            o[i + 1:j - 1] = ' ' * max(0, j - 1 - (i + 1)); i = j
        elif c == '#' and (i == 0 or t[t.rfind('\n', 0, i) + 1:i].strip() == ''):
            j = i
            while True:
                j = t.find('\n', j); j = n if j < 0 else j
                if t[j - 1:j] == '\\': j += 1; continue
                break
            o[i:j] = ' ' * (j - i); i = j
        else:
            i += 1
    return ''.join(o)


def match_close(m, i, o='{', c='}'):
    d = 0
    for j in range(i, len(m)):
        if m[j] == o: d += 1
        elif m[j] == c:
            d -= 1
            if d == 0: return j
    return -1


def functions(m):
    """name -> (body_open, body_close) for brace bodies preceded by a parameter list."""
    out = {}
    i = 0
    while True:
        i = m.find('{', i)
        if i < 0: break
        k = i - 1
        while k >= 0 and m[k].isspace(): k -= 1
        if m[k - 4:k + 1] == 'const': k -= 5
        while k >= 0 and m[k].isspace(): k -= 1
        if k >= 0 and m[k] == ')':
            d = 0; j = k
            while j >= 0:
                if m[j] == ')': d += 1
                elif m[j] == '(':
                    d -= 1
                    if d == 0: break
                j -= 1
            nm = re.search(r'([A-Za-z_]\w*)\s*$', m[:j])
            if nm and nm.group(1) not in KW:
                e = match_close(m, i)
                if e < 0: break
                out.setdefault(nm.group(1), (i, e))
                i = e + 1
                continue
        # struct / class / namespace / extern bodies: descend into them
        i += 1
    return out


KW = {'if', 'for', 'while', 'switch', 'return', 'else', 'do', 'case', 'default', 'goto', 'break', 'continue',
      'sizeof', 'delete', 'new', 'throw', 'typedef', 'using', 'static_cast', 'reinterpret_cast'}


def statements(m, a, b, hdr=None):
    """Statements inside body (a,b): list of (start, end, block_id). end is index of ';'.
    Block headers (`if (...) {`) go to hdr as (start, end) when hdr is a list."""
    out = []
    stack = [a]
    st = a + 1; i = a + 1; par = 0
    while i < b:
        c = m[i]
        if c in '([': par += 1
        elif c in ')]': par -= 1
        elif par == 0 and c == '{':
            pre = m[st:i].strip()
            if pre.endswith('=') or pre.endswith('return'):  # aggregate initialiser
                j = match_close(m, i)
                if j < 0: break
                i = j + 1; continue
            if hdr is not None and pre: hdr.append((st, i))
            stack.append(i); st = i + 1
        elif par == 0 and c == '}':
            if len(stack) > 1: stack.pop()
            st = i + 1
        elif par == 0 and c == ';':
            out.append((st, i, stack[-1]))
            st = i + 1
        i += 1
    return out


DECL = re.compile(r'^(?:(?:const|volatile|unsigned|signed|struct|union|enum|register)\s+)*'
                  r'([A-Za-z_][\w:]*)(?:\s*<[^;=]*?>)?(?:[\s\*&]+)\**\s*([A-Za-z_]\w*)\s*(\[[^\]]*\]\s*)?(=|,|$)', re.S)


def is_decl(s):
    m = DECL.match(s)
    return bool(m) and m.group(1) not in KW and not s.startswith('static ')


OPS = {'|': 0, '^': 1, '&': 2, '<<': 3, '>>': 3, '+': 4, '-': 4, '*': 5, '/': 5, '%': 5}
COMM = set('+*&|^')
TYPES = {'s8', 'u8', 's16', 'u16', 's32', 'u32', 's64', 'u64', 'int', 'char', 'short', 'long', 'void', 'BOOL',
         'fx32', 'fx16', 'f32', 'vu8', 'vu16', 'vu32', 'const'}
RSPLIT = {'-'}  # non-commutative ops that also get the right-operand split (round ovhimid5)
CASTTY = re.compile(r'^\s*(?:const\s+|unsigned\s+|signed\s+|struct\s+|volatile\s+)*'
                    r'(?:s8|u8|s16|u16|s32|u32|s64|u64|int|char|short|long|unsigned|BOOL|fx32|fx16|void|f32|vu8|vu16|vu32|[A-Z]\w*)\s*\**\s*$')


def split_expr(e):
    """Top-level `A op B` of masked expression e -> (ia, op, ib) or None."""
    d = 0; cand = []; i = 0; n = len(e); lastgrp = None
    while i < n:
        c = e[i]
        if c in '([{':
            if d == 0: gs = i
            d += 1; i += 1; continue
        if c in ')]}':
            d -= 1; i += 1
            if d == 0: lastgrp = (gs, i)
            continue
        if d:
            i += 1; continue
        two = e[i:i + 2]; three = e[i:i + 3]
        if three in ('<<=', '>>='): return None
        if two in ('&&', '||', '==', '!=', '<=', '>=', '+=', '-=', '*=', '/=', '%=', '&=', '|=', '^='): return None
        if two in ('->', '++', '--', '::'): i += 2; continue
        if two in ('<<', '>>'):
            tok = two
        elif c in '?,=<>': return None
        elif c in '|^&+-*/%':
            tok = c
        else:
            i += 1; continue
        prev = e[:i].rstrip()
        if prev and (prev[-1].isalnum() or prev[-1] in '_)]'):
            iscast = prev[-1] == ')' and lastgrp and lastgrp[1] == len(prev) and CASTTY.match(e[lastgrp[0] + 1:lastgrp[1] - 1]) \
                and (lastgrp[0] == 0 or not (e[:lastgrp[0]].rstrip()[-1:].isalnum() or e[:lastgrp[0]].rstrip()[-1:] in '_)]'))
            if not iscast:
                cand.append((OPS[tok], i, tok))
        i += len(tok)
    if not cand: return None
    lo = min(c[0] for c in cand)
    _, i, tok = [c for c in cand if c[0] == lo][-1]
    return i, tok, i + len(tok)


def strip_parens(s):
    s = s.strip()
    while s.startswith('(') and match_close(s, 0, '(', ')') == len(s) - 1:
        s = s[1:-1].strip()
    return s


def idents(s):
    return set(re.findall(r'(?<![\w.>])(?<!->)\s*([A-Za-z_]\w*)', re.sub(r'(->|\.)\s*[A-Za-z_]\w*', ' ', s)))


# ---------------------------------------------------------------- variant generation
def scope(m, fn, func):
    """The target function and every function of the file it calls, transitively."""
    todo = [func]; seen = set()
    while todo:
        f = todo.pop()
        if f in seen or f not in fn: continue
        seen.add(f)
        a, b = fn[f]
        for c in re.findall(r'([A-Za-z_]\w*)\s*\(', m[a:b]):
            if c in fn and c not in seen: todo.append(c)
    return seen


LOWTOK = re.compile(r'<<=|>>=|&&|\|\||==|!=|<=|>=|[-+*/%&|^]=|(?<![<>-])[<>](?![<>=])|[?:,=]')


def subexprs(m, a, b, out):
    """Spans (s, e) in m[a:b] that are `A op B` with one of our ops at their top level."""
    # recurse into groups, and cut the top level at low-precedence tokens
    d = 0; cuts = [a]; i = a
    while i < b:
        c = m[i]
        if c in '([':
            j = match_close(m, i, c, ')' if c == '(' else ']')
            if j < 0 or j >= b: return
            subexprs(m, i + 1, j, out); i = j + 1; continue
        mm = LOWTOK.match(m, i)
        if mm and not m.startswith('->', i - 1) and not m.startswith('::', i) and not m.startswith('::', i - 1):
            cuts.append(i); cuts.append(mm.end()); i = mm.end(); continue
        i += 1
    cuts.append(b)
    for k in range(0, len(cuts), 2):
        s, e = cuts[k], cuts[k + 1]
        while s < e and m[s].isspace(): s += 1
        while e > s and m[e - 1].isspace(): e -= 1
        if e <= s: continue
        sp = split_expr(m[s:e])
        if sp:
            out.append((s, e))
            subexprs(m, s, s + sp[0], out); subexprs(m, s + sp[2], e, out)


IMPURE = re.compile(r'\+\+|--|(?<![=!<>])=(?!=)|\b(?!sizeof\b)[A-Za-z_]\w*\s*\(')


def gen_extract(t, func, typ='s32'):
    """`stmt(... A op B ...)` -> `typ x = A; x op= B; stmt(... x ...)` for pure subexpressions."""
    m = mask(t)
    fn = functions(m)
    if func not in fn: return []
    out = []; n = max([int(x) for x in re.findall(r'\bsm_t(\d+)\b', t)] + [0])
    for f in sorted(scope(m, fn, func)):
        a, b = fn[f]
        hdr = []
        sts = [(s, e) for s, e, _ in statements(m, a, b, hdr)] + hdr
        for s, e in sts:
            s0 = s
            while s0 < e and m[s0].isspace(): s0 += 1
            mm = re.match(r'(case\b[^:]*|default\s*):(?!:)\s*', m[s0:e])
            if mm: s0 += mm.end()
            w = re.match(r'[A-Za-z_]\w*', m[s0:e])
            w = w.group(0) if w else ''
            if w in ('for', 'while', 'do', 'else', 'goto', 'break', 'continue', 'case', 'default'): continue
            if w == 'if' or w == 'switch':
                lo = m.find('(', s0); hi = match_close(m, lo, '(', ')')
                if lo < 0 or hi < 0 or hi > e: continue
                rng = (lo + 1, hi)
            elif w == 'return':
                rng = (s0 + 6, e)
            elif is_decl(m[s0:e]):
                if '=' not in m[s0:e]: continue
                rng = (m.find('=', s0) + 1, e)
            elif re.match(r'[A-Za-z_]\w*\s*=[^=]', m[s0:e]):
                rng = (m.find('=', s0) + 1, e)
            else:
                rng = (s0, e)
            subs = []
            subexprs(m, rng[0], rng[1], subs)
            ind = re.match(r'[ \t]*', t[t.rfind('\n', 0, s0) + 1:]).group(0)
            line = t.count('\n', 0, s0) + 1
            whole = m[rng[0]:rng[1]].strip()
            for x, y in sorted(set(subs)):
                ex = m[x:y]
                if IMPURE.search(ex) or re.search(r'\b[su]64\b|long long', ex): continue
                if ex.strip() == whole and rng[0] != s0 and w not in ('if', 'switch', 'return'): continue
                ia, op, ib = split_expr(ex)
                A = strip_parens(t[x:x + ia]); B = strip_parens(t[x + ib:y])
                if not A or not B or A in TYPES or B in TYPES: continue  # e.g. `FLD(u8 *, p, 4)`
                forms = [(A, B, '')] + ([(B, A, 'c')] if op in COMM else []) + ([(A, B, 'r')] if op in RSPLIT else [])
                for ty in [typ] + (['u32'] if op in ('>>', '/', '%') else []):
                    for X, Y, tag in forms:
                        n += 1; v = 'sm_t%d' % n
                        if tag == 'r':  # split from the right operand: `x = B; x = A op x;`
                            ins = '%s %s = %s; %s = %s %s %s;\n%s' % (ty, v, Y, v, X, op, v, ind)
                        else:
                            ins = '%s %s = %s; %s %s= %s;\n%s' % (ty, v, X, v, op, Y, ind)
                        out.append(('%s:%d:x%s%s%s' % (f, line, op, tag, '' if ty == typ else ty), [(s0, s0, ins), (x, y, v)]))
    return out


def gen_split(t, func):
    """Return list of (label, edits); edits = [(start, end, new)] on t."""
    m = mask(t)
    fn = functions(m)
    if func not in fn: return []
    seen = scope(m, fn, func)
    out = []
    for f in sorted(seen):
        a, b = fn[f]
        sts = statements(m, a, b)
        for si, (s, e, blk) in enumerate(sts):
            raw = m[s:e]
            lead = len(raw) - len(raw.lstrip())
            body = raw.strip()
            s0 = s + lead
            mm = re.match(r'(case\b[^:]*|default\s*):(?!:)\s*', body)
            if mm:
                s0 += mm.end(); body = body[mm.end():]
            if not body or body.split()[0].rstrip('(') in KW: continue
            decl = None
            md = re.match(r'^(?P<ty>(?:(?:volatile|unsigned|signed|struct|union|enum|register)\s+)*(?P<const>const\s+)?'
                          r'(?:(?:volatile|unsigned|signed|struct|union|enum|register)\s+)*[A-Za-z_][\w:]*(?:\s*<[^;=]*?>)?[\s\*&]+\**\s*)'
                          r'(?P<v>[A-Za-z_]\w*)\s*=\s*(?P<x>.*)$', body, re.S)
            ma = re.match(r'^(?P<v>[A-Za-z_]\w*)\s*=\s*(?P<x>.*)$', body, re.S)
            if md and md.group('ty').split()[0] not in KW and md.group('ty').split()[0] != 'static':
                kind = 'D'; v = md.group('v'); xo = s0 + md.start('x'); ty = md.group('ty')
                if md.group('const'): ty = ty.replace(md.group('const'), '', 1)
            elif ma:
                kind = 'A'; v = ma.group('v'); xo = s0 + ma.start('x'); ty = ''
            else:
                continue
            xm = m[xo:e]
            sp = split_expr(xm)
            if not sp: continue
            ia, op, ib = sp
            A = t[xo:xo + ia].strip(); B = t[xo + ib:e].strip()
            Am = strip_parens(xm[:ia]); Bm = strip_parens(xm[ib:])
            A = strip_parens(A); B = strip_parens(B)
            forms = []
            if v not in idents(Bm): forms.append((A, B, ''))
            if op in COMM and v not in idents(Am): forms.append((B, A, 'c'))
            if op in RSPLIT and v not in idents(Am): forms.append((A, B, 'r'))
            # end of the declaration run that follows this statement in the same block
            j = si + 1; runend = None
            while j < len(sts) and sts[j][2] == blk and is_decl(m[sts[j][0]:sts[j][1]].strip()):
                runend = sts[j][1]; j += 1
            line = t.count('\n', 0, s0) + 1
            ind = re.match(r'[ \t]*', t[t.rfind('\n', 0, s0) + 1:]).group(0)
            for X, Y, tag in forms:
                if tag == 'r':  # split from the right operand: `T v = B; v = A op v;`
                    first = (ty + v + ' = ' + Y + ';') if kind == 'D' else (v + ' = ' + Y + ';')
                    mod = ' ' + v + ' = ' + X + ' ' + op + ' ' + v + ';'
                else:
                    first = (ty + v + ' = ' + X + ';') if kind == 'D' else (v + ' = ' + X + ';')
                    mod = ' ' + v + ' ' + op + '= ' + Y + ';'
                lab = '%s:%d:%s%s' % (f, line, op, tag)
                out.append((lab, [(s0, e + 1, first + mod)]))
                if runend is not None:
                    out.append((lab + '@run', [(s0, e + 1, first), (runend + 1, runend + 1, '\n' + ind + mod.strip())]))
    return out


def gen_declorder(t, func):
    m = mask(t)
    fn = functions(m)
    if func not in fn: return []
    names = scope(m, fn, func)
    out = []
    for f in sorted(names):
        a, b = fn[f]
        sts = statements(m, a, b)
        runs = []; cur = []
        for s, e, blk in sts:
            txt = m[s:e].strip()
            if is_decl(txt) and (not cur or cur[-1][2] == blk) and (not cur or m[cur[-1][1] + 1:s].strip() == ''):
                cur.append((s, e, blk))
            else:
                if len(cur) > 1: runs.append(cur)
                cur = [(s, e, blk)] if is_decl(txt) else []
        if len(cur) > 1: runs.append(cur)
        for run in runs:
            if len(run) > 9: continue
            texts = [t[s:e + 1].strip() for s, e, _ in run]
            lo = run[0][0] + len(m[run[0][0]:run[0][1]]) - len(m[run[0][0]:run[0][1]].lstrip())
            hi = run[-1][1] + 1
            seg = t[lo:hi]
            # keep the original separators
            seps = []
            for k in range(len(run) - 1):
                seps.append(t[run[k][1] + 1:run[k + 1][0] + len(m[run[k + 1][0]:run[k + 1][1]]) - len(m[run[k + 1][0]:run[k + 1][1]].lstrip())])
            for i in range(len(run)):
                for j in range(len(run)):
                    if i == j: continue
                    order = list(range(len(run)))
                    x = order.pop(i); order.insert(j, x)
                    new = texts[order[0]] + ''.join(seps[k] + texts[order[k + 1]] for k in range(len(run) - 1))
                    if new != seg:
                        out.append(('%s:decl%d->%d@%d' % (f, i, j, t.count('\n', 0, lo) + 1), [(lo, hi, new)]))
    return out


def gen_swap(t, func):
    """Swap two adjacent simple statements of the same block (no declarations, no control flow)."""
    m = mask(t)
    fn = functions(m)
    if func not in fn: return []
    out = []
    for f in sorted(scope(m, fn, func)):
        a, b = fn[f]
        sts = statements(m, a, b)
        for k in range(len(sts) - 1):
            (s1, e1, b1), (s2, e2, b2) = sts[k], sts[k + 1]
            if b1 != b2 or m[e1 + 1:s2].strip(): continue
            x1, x2 = m[s1:e1].strip(), m[s2:e2].strip()
            if not x1 or not x2 or is_decl(x1) or is_decl(x2): continue
            if re.match(r'(if|for|while|do|else|switch|return|case|default|goto|break|continue)\b', x1) or \
               re.match(r'(if|for|while|do|else|switch|return|case|default|goto|break|continue)\b', x2): continue
            l1 = s1 + len(m[s1:e1]) - len(m[s1:e1].lstrip()); l2 = s2 + len(m[s2:e2]) - len(m[s2:e2].lstrip())
            seg = t[l1:e2 + 1]
            new = t[l2:e2 + 1] + t[e1 + 1:l2] + t[l1:e1 + 1]
            if new != seg:
                out.append(('%s:swap@%d' % (f, t.count('\n', 0, l1) + 1), [(l1, e2 + 1, new)]))
    return out


def apply(t, edits):
    for s, e, new in sorted(edits, key=lambda x: (x[0], x[1]), reverse=True):
        t = t[:s] + new + t[e:]
    return t


def overlap(e1, e2):
    for s1, t1, _ in e1:
        for s2, t2, _ in e2:
            if s1 < t2 and s2 < t1: return True
            if s1 == s2 == t1 == t2: return True
    return False


# ---------------------------------------------------------------- search
def combos(V, top):
    """Pairs of the best singles, plus 'every site at once' per function and overall."""
    out = []
    for i in range(len(top)):
        for j in range(i + 1, len(top)):
            if not overlap(top[i][1], top[j][1]):
                out.append((top[i][0] + '+' + top[j][0], top[i][1] + top[j][1]))
    for tag in ('', '@run'):
        groups = {}
        for lab, ed in V:
            if lab.endswith('c' + tag) or lab.endswith('r' + tag) or (tag == '' and lab.endswith('@run')) or (tag and not lab.endswith(tag)):
                continue
            groups.setdefault(lab.split(':')[0], []).append((lab, ed))
        allg = []
        for f, L in sorted(groups.items()):
            acc = []
            for lab, ed in L:
                if not overlap(acc, ed): acc = acc + ed
            if len(L) > 2: out.append(('all:%s%s' % (f, tag), acc))
            allg.append(acc)
        acc = []
        for ed in allg:
            if not overlap(acc, ed): acc = acc + ed
        if acc and len(groups) > 1 or (len(groups) == 1 and len(list(groups.values())[0]) <= 2 and acc):
            out.append(('all%s' % tag, acc))
    return out


def main():
    ap = argparse.ArgumentParser()
    ap.add_argument('src'); ap.add_argument('func')
    ap.add_argument('--module', default='main')
    ap.add_argument('-o', default=None)
    ap.add_argument('-j', type=int, default=int(os.environ.get('J', '4')))
    ap.add_argument('--iters', type=int, default=3)
    ap.add_argument('--beam', type=int, default=2, help='states kept per round (distinct code)')
    ap.add_argument('--pairs', type=int, default=10, help='pair up the best N singles')
    ap.add_argument('--no-decl', action='store_true')
    ap.add_argument('--no-extract', action='store_true', help='only split existing locals')
    ap.add_argument('--list', action='store_true', help='only print the split sites')
    ap.add_argument('-v', action='store_true')
    g = ap.parse_args()
    ext = g.src.rsplit('.', 1)[1]
    t = open(g.src).read()
    if g.list:
        for lab, ed in gen_split(t, g.func) + gen_extract(t, g.func):
            print(lab, repr(apply(t, ed)[ed[0][0]:ed[0][0] + 80]))
        return
    ex = ThreadPoolExecutor(g.j)
    cache = {}

    def sc(txt):
        h = hashlib.md5(txt.encode()).hexdigest()
        if h not in cache: cache[h] = score_text(txt, g.func, g.module, ext)
        return cache[h]

    def run(state, V):
        _, txt, hist = state
        texts = [apply(txt, ed) for _, ed in V]
        return [(s, tx, hist + [lab]) for (lab, _), tx, s in zip(V, texts, ex.map(sc, texts))]

    base = sc(t)
    print('base %d %d %s' % base, flush=True)
    if base[2] is None:
        print('final %d %d %s' % base, '(base does not compile)'); return
    pool = {base[2]: (base, t, [])}
    beam = [(base, t, [])]
    for it in range(g.iters):
        new = []
        for st in beam:
            V = gen_split(st[1], g.func) + ([] if g.no_extract else gen_extract(st[1], g.func))
            if not V: continue
            res = sorted(run(st, V), key=lambda r: key(r[0]))
            if g.v:
                for s, _, h in res: print('  %s %s' % (h[-1], s[:2]))
            okv = [V[[l for l, _ in V].index(h[-1])] for s, _, h in res if s[2] is not None][:g.pairs]
            new += res + run(st, combos(V, okv))
        grew = False
        for r in new:
            if r[0][2] is not None and r[0][2] not in pool:
                pool[r[0][2]] = r; grew = True
        ranked = sorted(pool.values(), key=lambda r: key(r[0]))
        b = ranked[0]
        print('iter %d: %d variants, best %d %d  %s' % (it, len(new), b[0][0], b[0][1], ' '.join(b[2])), flush=True)
        if b[0][0] == 0 or not grew: break
        beam = [r for r in ranked[:g.beam]]
    ranked = sorted(pool.values(), key=lambda r: key(r[0]))
    if not g.no_decl and ranked[0][0][0] != 0:
        beam = ranked[:g.beam]
        for it in range(2):
            new = []
            for st in beam:
                new += run(st, gen_declorder(st[1], g.func) + gen_swap(st[1], g.func))
            for r in new:
                if r[0][2] is not None and r[0][2] not in pool: pool[r[0][2]] = r
            ranked = sorted(pool.values(), key=lambda r: key(r[0]))
            print('decl %d: %d variants, best %d %d  %s' % (it, len(new), ranked[0][0][0], ranked[0][0][1], ' '.join(ranked[0][2])), flush=True)
            if ranked[0][0][0] == 0: break
            beam = ranked[:g.beam]
    best = ranked[0]
    out = g.o or g.src.rsplit('.', 1)[0] + '.split.' + ext
    open(out, 'w').write(best[1])
    print('final %d %d %s' % best[0], ' '.join(best[2]) or '(unchanged)', '->', out, flush=True)


if __name__ == '__main__':
    main()
