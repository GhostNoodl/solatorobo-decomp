#!/usr/bin/env python3
# Declaration audit (round hdA): finds globals, C-linkage functions, typedefs and struct/class/union tags that are
# declared in more than one place with different types, and struct definitions that are duplicated word for word.
#
#   python3 tools/declaudit.py [--jobs N] [--cache DIR] [--kind var,func,typedef,record] [--name RE]
#                              [--scope hh|hs|all] [--dups] [--json OUT]
#
# Every translation unit in compile_commands.json, and every header under include/ on its own, is parsed with
# clang (`-ast-dump=json`; clang is only used as a parser, its errors are ignored). Each file-scope declaration
# whose location is in src/, include/ or libs/ is recorded once per source location with its canonical type
# (typedefs resolved, `struct` keywords dropped). Records are compared by their field lists (name and canonical
# type, anonymous members expanded) and bases; C++-linkage functions are skipped, since a different parameter list
# is a different function there.
#
# Output: one block per name that has more than one canonical type, each type followed by its locations.
#   --scope hh   only conflicts where at least two of the disagreeing locations are headers (these stop the
#                headers from being included together)
#   --scope hs   conflicts involving at least one header (default: all)
#   --dups       also list record tags with more than one definition location (identical or not); two identical
#                definitions still can't be included together
#   --cache DIR  keep the per-TU extraction (keyed by file mtime) to make reruns fast
# Caveats: macros that build declarations are only seen after expansion; clang's errors (MWCC-only syntax such as
# `asm` bodies) can drop a declaration now and then. `#ifdef NONMATCHING` arms are not seen (the macro is not
# defined). Use the MWCC build to confirm a fix, not this tool.
import argparse
import hashlib
import json
import os
import re
import subprocess
import sys
from collections import defaultdict
from concurrent.futures import ThreadPoolExecutor
from pathlib import Path

root = Path(__file__).resolve().parent.parent
CLANG = os.environ.get('CLANG', 'clang++')
BASE = [CLANG, '-fsyntax-only', '-target', 'armv5te-none-eabi', '-w', '-ferror-limit=0', '-Wno-everything',
        '-I', 'include', '-I', 'build/gen', '-I', 'libs', '-Dusa', '-Xclang', '-ast-dump=json']
UNNAMED = re.compile(r'\((?:unnamed|anonymous) (?:struct|union|class|enum)?\s*at [^)]*\)')


def norm(t):
    t = UNNAMED.sub('(anon)', t)
    t = re.sub(r'\b(struct|class|union|enum)\s+', '', t)
    t = re.sub(r'\s+', ' ', t).strip()
    return t


class Walker:
    def __init__(self):
        self.file = None
        self.line = None
        self.out = []
        self.records = {}   # id -> record info
        self.anon_by_id = {}

    def loc(self, d):
        """Update the running file/line from a loc dict (clang omits unchanged fields)."""
        if not isinstance(d, dict):
            return
        if 'spellingLoc' in d:
            self.loc(d['spellingLoc'])
            self.loc(d.get('expansionLoc'))
            return
        if 'file' in d:
            self.file = d['file']
        if 'line' in d:
            self.line = d['line']

    def touch(self, node):
        """Walk a node only for its location side effects."""
        if isinstance(node, dict):
            if 'offset' in node or 'spellingLoc' in node:
                self.loc(node)
                return
            for k, v in node.items():
                if k == 'includedFrom':
                    continue
                self.touch(v)
        elif isinstance(node, list):
            for v in node:
                self.touch(v)

    def here(self, node):
        self.loc(node.get('loc'))
        f, l = self.file, self.line
        self.touch(node.get('range'))
        return f, l

    def ours(self, f):
        if not f:
            return None
        p = Path(f)
        if not p.is_absolute():
            p = root / p
        try:
            r = p.resolve().relative_to(root)
        except ValueError:
            return None
        if r.parts[0] in ('src', 'include', 'libs'):
            return str(r)
        return None

    def record_sig(self, node):
        fields, bases = [], []
        for b in node.get('bases', []) or []:
            bases.append(norm(b['type'].get('desugaredQualType', b['type']['qualType'])))
        virt = False
        for c in node.get('inner', []) or []:
            k = c.get('kind')
            if k == 'FieldDecl':
                t = c['type']
                ts = norm(t.get('desugaredQualType', t['qualType']))
                if '(anon)' in ts:
                    sub = self.anon_by_id.get(('last',))
                    ts = ts.replace('(anon)', '{' + (sub or '?') + '}', 1)
                bw = ''
                if c.get('isBitfield'):
                    bw = ':' + str(_const(c))
                fields.append((c.get('name', ''), ts + bw))
            elif k in ('CXXRecordDecl', 'RecordDecl') and c.get('completeDefinition'):
                s = self.record_sig(c)
                if not c.get('name'):
                    self.anon_by_id[('last',)] = s
                    if not any(cc.get('kind') == 'FieldDecl' for cc in []):
                        pass
            elif k == 'CXXMethodDecl' and c.get('virtual'):
                virt = True
        sig = '%s%s{%s}' % ((':' + ','.join(bases)) if bases else '', '[v]' if virt else '',
                             ';'.join('%s %s' % (t, n) for n, t in fields))
        return sig

    def walk(self, nodes, ns=''):
        for node in nodes or []:
            if not isinstance(node, dict) or node.get('isImplicit'):
                self.touch(node)
                continue
            k = node.get('kind')
            if k == 'LinkageSpecDecl':
                self.here(node)
                self.walk(node.get('inner'), ns)
                continue
            if k == 'NamespaceDecl':
                self.here(node)
                self.walk(node.get('inner'), ns + node.get('name', '') + '::')
                continue
            f, l = self.here(node)
            of = self.ours(f)
            name = node.get('name')
            if k == 'VarDecl' and of and name:
                t = node['type']
                self.out.append(('var', ns + name, norm(t.get('desugaredQualType', t['qualType'])),
                                 norm(t['qualType']), of, l, node.get('storageClass', '') + ('=' if node.get('init') else '')))
            elif k == 'FunctionDecl' and of and name:
                mn = node.get('mangledName', name)
                if mn == name and not ns:
                    t = node['type']
                    self.out.append(('func', name, norm(t.get('desugaredQualType', t['qualType'])), norm(t['qualType']),
                                     of, l, 'def' if any(c.get('kind') == 'CompoundStmt' for c in node.get('inner', []) or [])
                                     else ''))
            elif k == 'TypedefDecl' and of and name:
                t = node['type']
                can = norm(t.get('desugaredQualType', t['qualType']))
                rid = _owned(node)
                if rid and rid in self.records:
                    rec = self.records[rid]
                    if not rec['name']:
                        # typedef struct { ... } Name;  -> the record is named by the typedef
                        self.out.append(('record', ns + name, rec['sig'], rec['kw'], rec['file'], rec['line'], 'td'))
                        can = '{anon}' + rec['sig']
                self.out.append(('typedef', ns + name, can, norm(t['qualType']), of, l, ''))
            elif k in ('CXXRecordDecl', 'RecordDecl'):
                if node.get('completeDefinition'):
                    sig = self.record_sig(node)
                    self.records[node['id']] = dict(name=name, sig=sig, kw=node.get('tagUsed', ''), file=of, line=l)
                    if of and name:
                        self.out.append(('record', ns + name, sig, node.get('tagUsed', ''), of, l, ''))
                    self.touch(node.get('inner'))
                else:
                    self.touch(node.get('inner'))
                continue
            elif k == 'EnumDecl':
                if of and name:
                    vals = [c.get('name') for c in node.get('inner', []) or [] if c.get('kind') == 'EnumConstantDecl']
                    if vals:
                        self.out.append(('enum', ns + name, ','.join(vals), '', of, l, ''))
            self.touch(node.get('inner'))


def _const(fd):
    for c in fd.get('inner', []) or []:
        if c.get('kind') == 'ConstantExpr' and 'value' in c:
            return c['value']
        for cc in c.get('inner', []) or []:
            if 'value' in cc:
                return cc['value']
    return '?'


def _owned(node):
    def find(n):
        if isinstance(n, dict):
            if 'ownedTagDecl' in n:
                return n['ownedTagDecl'].get('id')
            if n.get('kind') == 'RecordType' and 'decl' in n:
                return n['decl'].get('id')
            for v in n.values():
                r = find(v)
                if r:
                    return r
        elif isinstance(n, list):
            for v in n:
                r = find(v)
                if r:
                    return r
        return None
    return find(node.get('inner'))


IDENT = re.compile(r'[A-Za-z_]\w*')


def canonicalizer(entries):
    """Resolve the unit's typedef names inside a type string, and spell `()` as `(void)`."""
    td = {}
    for kind, name, can, spelled, f, l, extra in entries:
        if kind == 'typedef' and not can.startswith('{anon}') and name not in td:
            td[name] = can
    memo = {}

    def one(t, depth=0):
        if depth > 10:
            return t
        n = IDENT.sub(lambda m: td[m.group(0)] if m.group(0) in td and td[m.group(0)] != m.group(0)
                      else m.group(0), t)
        if n == t:
            return t
        return one(n, depth + 1)

    def tidy(t):
        t = re.sub(r'\(\)', '(void)', t)
        t = re.sub(r'\s*\*', ' *', t).replace('* *', '**').replace('* *', '**')
        t = re.sub(r'\s+', ' ', t).strip()
        return t

    def canon(t):
        if t not in memo:
            memo[t] = tidy(one(t))
        return memo[t]
    return canon


def extract(path, lang):
    args = BASE + (['-x', 'c', '-std=gnu99'] if lang == 'c' else ['-x', 'c++', '-std=gnu++98']) + [path]
    p = subprocess.run(args, cwd=root, capture_output=True, text=True)
    try:
        data = json.loads(p.stdout)
    except json.JSONDecodeError:
        return []
    w = Walker()
    w.walk(data.get('inner'))
    return w.out


def units():
    cc = json.load(open(root / 'compile_commands.json'))
    res = []
    for e in cc:
        f = e['file']
        if f.endswith('.c'):
            res.append((f, 'c'))
        elif f.endswith('.cpp'):
            res.append((f, 'c++'))
    for h in sorted((root / 'include').rglob('*.h')):
        res.append((str(h.relative_to(root)), 'c++'))
    return res


def main():
    ap = argparse.ArgumentParser()
    ap.add_argument('--jobs', type=int, default=2)
    ap.add_argument('--cache')
    ap.add_argument('--kind', default='var,func,typedef,record')
    ap.add_argument('--name')
    ap.add_argument('--scope', default='all', choices=['all', 'hs', 'hh'])
    ap.add_argument('--dups', action='store_true')
    ap.add_argument('--json')
    ap.add_argument('--only', help='only parse units whose path starts with one of these comma-separated prefixes')
    a = ap.parse_args()
    us = units()
    if a.only:
        pre = a.only.split(',')
        us = [u for u in us if any(u[0].startswith(x) for x in pre)]
    cache = Path(a.cache) if a.cache else None
    if cache:
        cache.mkdir(parents=True, exist_ok=True)

    def run(u):
        f, lang = u
        if cache:
            # key on the unit and every header's mtime would be exact; the tree's header mtimes are cheap to hash
            key = hashlib.md5((f + lang + HDRKEY).encode()).hexdigest()
            cp = cache / (key + '.json')
            if cp.exists():
                return json.load(open(cp))
            r = extract(f, lang)
            json.dump(r, open(cp, 'w'))
            return r
        return extract(f, lang)

    global HDRKEY
    HDRKEY = ''
    if cache:
        h = hashlib.md5()
        for p in sorted(list((root / 'include').rglob('*')) + list((root / 'src').rglob('*')) + list((root / 'libs').rglob('*'))):
            if p.is_file():
                h.update(('%s%d' % (p, p.stat().st_mtime_ns)).encode())
        HDRKEY = h.hexdigest()
    with ThreadPoolExecutor(a.jobs) as ex:
        results = list(ex.map(run, us))

    kinds = set(a.kind.split(','))
    by = defaultdict(lambda: defaultdict(set))   # (kind,name) -> canon -> {(file,line,extra,spelled)}
    for r in results:
        canon = canonicalizer(r)
        for kind, name, can, spelled, f, l, extra in r:
            if kind in ('var', 'func', 'typedef'):
                can = canon(can)
            elif kind == 'record':
                can = canon(can)
            if kind == 'var' and extra.startswith('static'):
                continue
            by[(kind, name)][can].add((f, l, extra, spelled))
    out = []
    for (kind, name), cans in sorted(by.items()):
        if kind not in kinds or (a.name and not re.search(a.name, name)):
            continue
        locs = {(f, l) for c in cans.values() for (f, l, _, _) in c}
        if kind == 'var':
            # `T x[]` and `T x[N]` are compatible
            merged = defaultdict(set)
            for c, s in cans.items():
                merged[re.sub(r'\[\d*\]', '[]', c)] |= s
            cans = merged
        conflict = len(cans) > 1
        dup = kind == 'record' and len(locs) > 1
        if not conflict and not (a.dups and dup):
            continue
        hdr_kinds = [c for c, s in cans.items() if any(f.endswith('.h') for (f, _, _, _) in s)]
        if a.scope == 'hh' and conflict and len(hdr_kinds) < 2:
            if not (a.dups and dup and sum(f.endswith('.h') for f, _ in locs) >= 1):
                continue
        if a.scope == 'hs' and not hdr_kinds:
            continue
        out.append(dict(kind=kind, name=name, conflict=conflict,
                        types={c: sorted(s) for c, s in cans.items()}))
    for o in out:
        print('%s %s%s' % (o['kind'], o['name'], '' if o['conflict'] else '  (duplicate definition)'))
        for c, s in sorted(o['types'].items(), key=lambda x: -len(x[1])):
            print('    %s' % (c if len(c) < 300 else c[:300] + '...'))
            for f, l, extra, sp in s[:12]:
                print('        %s:%s%s%s' % (f, l, ' [%s]' % extra if extra else '', '' if sp == c else '  (%s)' % sp[:120]))
            if len(s) > 12:
                print('        ... %d more' % (len(s) - 12))
    n = sum(1 for o in out if o['conflict'])
    print('# %d conflicting names, %d duplicate-only record definitions' % (n, len(out) - n), file=sys.stderr)
    cnt = defaultdict(int)
    for o in out:
        if o['conflict']:
            cnt[o['kind']] += 1
    print('# by kind: %s' % dict(cnt), file=sys.stderr)
    if a.json:
        json.dump(out, open(a.json, 'w'), indent=1)


HDRKEY = ''
if __name__ == '__main__':
    main()
