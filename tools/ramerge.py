#!/usr/bin/env python3
"""What-if search on mwccarm 1.3's register colouring (round bgU).

    tools/ramerge.sh SRC                      dump the colour graphs of SRC to build/ramerge/ra.out
    python3 tools/ramerge.py RA OBJ NODE REG  search

RA is the dump, OBJ the name of any named local of the function (picks its graph), NODE the vreg whose
register is wrong and REG the register the ROM gives it (0-11). The script rebuilds the allocator's
simplify/select order (K=14, cost/degree spill metric, lowest free register, callee-saved registers opened
one at a time; round bgS's sim.py) and checks that it reproduces the dump's colours. It then lists:

  merge  every other node that, coalesced with NODE (one node, union of neighbours), gives NODE the
         register REG with no other node changing colour. A hit names the value NODE must share a
         live range with in the ROM (same variable lifetime, or joined by a copy).
  renum  the positions NODE could be renumbered to (alone) that give REG with nothing else changing.
"""
import copy, sys


def parse(path, which):
    blocks = open(path).read().split('=== ')[1:]
    B = blocks[which].split('\n')
    hdr = B[0].split()
    first = int(hdr[hdr.index('first') + 1]); cnt = int(hdr[hdr.index('count') + 1])
    nodes, names = {}, {}
    for l in B[2:]:
        p = l.split()
        if not p: continue
        i = int(p[0])
        nb = [int(x) for x in p[5][3:].split(',')] if p[5] != 'nb=' else []
        nodes[i] = dict(c=int(p[1][2:]), fl=int(p[2][3:], 16), cost=int(p[4][5:]), nb=nb)
        names[i] = p[-1][4:]
    return first, cnt, nodes, names


def simplify(first, cnt, nodes, K=14):
    deg = {i: len(n['nb']) for i, n in nodes.items()}
    pushed = set(); stack = []
    excl = {i for i, n in nodes.items() if n['fl'] & 4}
    def push(i):
        pushed.add(i); stack.append(i)
        for j in nodes[i]['nb']:
            if j in deg: deg[j] -= 1
    def sweep():
        changed = True; high = []
        while changed:
            changed = False; high = []
            for i in range(first, cnt):
                if i not in nodes or i in pushed or i in excl: continue
                if deg[i] < K: push(i); changed = True
                else: high.append(i)
        return high
    high = sweep()
    while high:
        def m(i):
            n = nodes[i]
            if n['fl'] & 0x80: return 3.4e38
            if n['fl'] & 0x400: return 1.7e38
            return n['cost'] / deg[i]
        push(min(high, key=m))
        high = sweep()
    return stack[::-1]


def color(order, nodes, vol=(0, 1, 2, 3, 12, 14), nonvol=(4, 5, 6, 7, 8, 9, 10, 11)):
    col = {}; mask = set(vol); opened = 0
    for i in order:
        while True:
            used = {j if j < 16 else col[j] for j in nodes[i]['nb'] if j < 16 or j in col}
            av = sorted(r for r in mask if r not in used)
            if av: col[i] = av[0]; break
            if opened < len(nonvol): mask.add(nonvol[opened]); opened += 1
            else: col[i] = -1; break
    return col


def run(first, cnt, nodes):
    return color(simplify(first, cnt, nodes), nodes)


def merge(N, a, b):
    nodes = copy.deepcopy(N)
    nb = (set(nodes[a]['nb']) | set(nodes[b]['nb'])) - {a, b}
    nodes[a]['nb'] = sorted(nb)
    for j in nb:
        if j in nodes:
            l = [x for x in nodes[j]['nb'] if x != b]
            if a not in l: l.append(a)
            nodes[j]['nb'] = l
    del nodes[b]
    return nodes


def main():
    path, obj, node, reg = sys.argv[1], sys.argv[2], int(sys.argv[3]), int(sys.argv[4])
    nblk = open(path).read().count('=== ')
    which = None
    for w in range(nblk - 1, -1, -1):
        f, c, N, names = parse(path, w)
        if obj in names.values(): which = w; break
    if which is None: sys.exit('no graph has a local named %s' % obj)
    first, cnt, N0, names = parse(path, which)
    c0 = run(first, cnt, N0)
    bad = [i for i in c0 if c0[i] != N0[i]['c']]
    print('graph %d: model %s the dump (%d nodes differ)' % (which + 1, 'reproduces' if not bad else 'does NOT reproduce', len(bad)))
    want = dict(c0); want[node] = reg
    for a in sorted(N0):
        if a == node or a in N0[node]['nb']: continue
        lo, hi = min(a, node), max(a, node)
        col = run(first, cnt, merge(N0, lo, hi)); col[hi] = col.get(lo)
        if all(col.get(i) == want[i] for i in want):
            print('merge %d (%s) with %d (%s): OK' % (node, names[node], a, names[a]))
    keys = sorted(N0)
    for pos in range(first, cnt + 1):
        order = [k for k in keys if k != node]
        order = [k for k in order if k < pos] + [node] + [k for k in order if k >= pos]
        m = {old: i + first for i, old in enumerate(order)}
        nodes = {m[o]: dict(n, nb=[m.get(j, j) if j >= first else j for j in n['nb']]) for o, n in N0.items()}
        col = run(first, first + len(order), nodes)
        inv = {v: k for k, v in m.items()}
        col = {inv[i]: c for i, c in col.items()}
        if all(col.get(i) == want[i] for i in want):
            print('renum %d to position %d: OK' % (node, pos))


if __name__ == '__main__':
    main()
