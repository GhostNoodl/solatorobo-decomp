#!/usr/bin/env python3
# Single-move declaration sweep for one function.
#
#   [ITER=n] [USE=1] [INNER=1] [TOP=n] [SCORER=py] python3 tools/declsweep.py SRC FUNC MODULE [OUTDIR] [-j N] [--use]
#
# Finds the run of declarations at the top of FUNC's body (its last top-level definition in SRC).
# Only bare `T a;` / `T a, b;` lines are moved; `T a = init;` lines stay where they are as fixed
# points of the run. For every declaration line it writes one variant per other position in that
# run, compiles each with tools/match.py -q (NONMATCHING defined) and prints the variants that score
# better than the unchanged source, best first. NONMATCHING is defined in every variant; SCORER=path
# swaps in another match.py-compatible scorer (first number of its last output line is the score). The colouring order of user variables is reverse
# declaration order (round frA), so this is the cheapest test of rule 3 in docs/MATCHING.md
# ("### Round frC": a variable declared late is the last user variable and gets the lowest node).
import os
import re
import subprocess
import sys
from concurrent.futures import ThreadPoolExecutor
from pathlib import Path

root = Path(__file__).resolve().parent.parent
args = [a for a in sys.argv[1:] if a != '--use']
jobs = 2
if '-j' in args:
    k = args.index('-j')
    jobs = int(args[k + 1])
    del args[k:k + 2]
src, func, mod = args[:3]
out = Path(args[3]) if len(args) > 3 else Path('/tmp') / ('declsweep_' + func)
out.mkdir(parents=True, exist_ok=True)
lines = Path(src).read_text().split('\n')
# the last top-level definition of FUNC (an in-tree draft sits after any earlier prototype or call)
fs = [i for i, l in enumerate(lines) if re.match(r'^[A-Za-z_][^;(]*\b' + func + r'\s*\(', l)
      and not l.rstrip().endswith(';') and '{' in (l + lines[i + 1])][-1]
start = fs + 1 if lines[fs].rstrip().endswith('{') else fs + 2
one = r'(const\s+)?[A-Za-z_][\w ]*[\s*]+\**\s*[A-Za-z_]\w*(\[\w*\])?(\s*,\s*\**\s*[A-Za-z_]\w*(\[\w*\])?)*;'
decl = re.compile(r'^\s+' + one + r'(\s*' + one + r')*\s*$')
# a declaration with an initialiser stays in the run as a fixed point and is never moved
idecl = re.compile(r'^\s+(const\s+)?[A-Za-z_][\w ]*[\s*]+\**\s*[A-Za-z_]\w*\s*=\s*[^;]*;\s*$')
end = start
while end < len(lines) and (decl.match(lines[end]) or idecl.match(lines[end]) or lines[end].strip().startswith('//')) \
        and not re.match(r'\s*(return|goto)\b', lines[end]):
    end += 1
block = lines[start:end]
if len(block) < 2:
    sys.exit('no declaration run found at line %d' % (start + 1))
print('declarations: lines %d-%d (%d)' % (start + 1, end, len(block)), flush=True)


def score(path):
    scorer = os.environ.get('SCORER', str(root / 'tools' / 'match.py'))
    r = subprocess.run([sys.executable, scorer, str(path), func, '--module', mod, '-q'],
                       capture_output=True, text=True, cwd=root)
    t = (r.stdout + r.stderr).strip().split('\n')[-1].split()
    if os.environ.get("DBG"): print(repr(r.stdout + r.stderr)[-300:])
    try:
        return int(t[0])
    except (ValueError, IndexError):
        return 10 ** 6


use = bool(os.environ.get('USE')) or '--use' in sys.argv


def make_variants(block, tail):
    variants = [('base', block, tail)]
    for i in range(len(block)):
        if not decl.match(block[i]):
            continue
        rest = block[:i] + block[i + 1:]
        for p in range(len(rest) + 1):
            if p == i:
                continue
            variants.append(('%s->%d' % (block[i].strip(), p), rest[:p] + [block[i]] + rest[p:], tail))
    # --use: also try each single-variable declaration moved down to its first plain assignment
    # (`v = x;` becomes `T v = x;`, `for (v = 0;` becomes `for (T v = 0;`); variants that no longer
    # compile (a use before it, or a jump past it) score 10**6 and are not printed.
    if use:
        for i, l in enumerate(block):
            m = re.match(r'^(\s+)((?:const\s+)?[A-Za-z_][\w ]*?[\s*]+\**)\s*([A-Za-z_]\w*);\s*$', l)
            if not m:
                continue
            typ, v = m.group(2).rstrip(), m.group(3)
            for j, b in enumerate(tail):
                if re.search(r'\b%s\b' % v, b):
                    n = re.sub(r'^(\s+)%s = ' % v, lambda k: k.group(1) + typ + ' ' + v + ' = ', b, count=1)
                    if n == b:
                        n = re.sub(r'\bfor \(%s = ' % v, 'for (' + typ + ' ' + v + ' = ', b, count=1)
                    if n != b:
                        variants.append(('%s -> first use (body line %d)' % (l.strip(), j + 1),
                                         block[:i] + block[i + 1:], tail[:j] + [n] + tail[j + 1:]))
                    break
    # INNER=1: also single moves inside every other run of two or more declarations in the body
    # (block-scope locals: loop bodies, case blocks).
    if os.environ.get('INNER'):
        depth, fe = 1, len(tail)
        for j, b in enumerate(tail):
            depth += b.count('{') - b.count('}')
            if depth <= 0:
                fe = j
                break
        j = 0
        while j < fe:
            k = j
            while k < fe and (decl.match(tail[k]) or idecl.match(tail[k])):
                k += 1
            if k - j >= 2:
                run_ = tail[j:k]
                for i in range(len(run_)):
                    if not decl.match(run_[i]):
                        continue
                    rest = run_[:i] + run_[i + 1:]
                    for q in range(len(rest) + 1):
                        if q != i:
                            variants.append(('body %d: %s->%d' % (j + 1, run_[i].strip(), q), block,
                                             tail[:j] + rest[:q] + [run_[i]] + rest[q:] + tail[k:]))
            j = max(k, j + 1)
    return variants


def sweep(block, tail, tag):
    variants = make_variants(block, tail)

    def run(k):
        name, b, t = variants[k]
        path = out / ('%sv%04d%s' % (tag, k, Path(src).suffix))
        path.write_text('#define NONMATCHING\n' + '\n'.join(lines[:start] + b + t))
        return score(path), k

    with ThreadPoolExecutor(jobs) as ex:
        res = list(ex.map(run, range(len(variants))))
    return variants, res


# ITER=n: apply the best improving move and sweep again, up to n rounds (greedy descent);
# the final source is written to OUTDIR/best<ext>.
block, tail = block, lines[end:]
for it in range(int(os.environ.get('ITER', '1'))):
    variants, res = sweep(block, tail, 'i%d_' % it)
    base = res[0][0]
    print('round', it, 'base', base, flush=True)
    better = sorted((r for r in res[1:] if r[0] < base))
    for s_, k in better[:int(os.environ.get('TOP', '12'))]:
        print(' ', s_, variants[k][0], flush=True)
    if not better:
        break
    _, block, tail = variants[better[0][1]]
(out / ('best' + Path(src).suffix)).write_text('\n'.join(lines[:start] + block + tail))
