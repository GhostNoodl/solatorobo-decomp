#!/usr/bin/env python3
"""Twin search: find matched functions whose code is a near copy of an unmatched one.

Disassembles every ARM function of main and the overlays (capstone), masks the
registers, branch targets and pool offsets, builds a K-gram index of the matched
functions, and for every unmatched function scores the best candidates with
difflib.  Two scores are printed:

  cov  - matched instructions / length of the unmatched function
  sym  - difflib ratio() (2*matches / (len a + len b)), penalises size mismatch

Usage:
  python3 tools/twins.py [--modules ov000,ov001,...] [--min-len 40] [--th 0.55]
                         [-K 4] [--cf 0.2] [-j 4] [-o twins.tsv]

Modules default to every overlay but ov004.  The candidate pool is always
main plus every overlay but ov004.  Run from the repository root after
`configure.py` has extracted the ROM to extract/usa.
"""
import argparse, collections, difflib, os, re, sys
from multiprocessing import Pool

import capstone
import yaml

ROOT = os.path.dirname(os.path.dirname(os.path.abspath(__file__)))
EXT = os.path.join(ROOT, 'extract', 'usa')
CFG = os.path.join(ROOT, 'config', 'usa', 'arm9')
RG = re.compile(r"\b(r[0-9]+|sb|sl|fp|ip|lr)\b")


MASK_IMM = False


def norm(i):
    s = i.mnemonic + ' ' + i.op_str
    if i.mnemonic.startswith('b') and not i.mnemonic.startswith('bic'):
        s = re.sub(r'#0x[0-9a-f]+', 'T', s)
    s = re.sub(r'\[pc, #0x[0-9a-f]+\]', '[pc]', s)
    if MASK_IMM:
        s = re.sub(r'#-?(0x[0-9a-f]+|[0-9]+)', '#I', s)
    return RG.sub('R', s)


def text_ranges(d):
    rng = []
    for l in open(os.path.join(d, 'delinks.txt')):
        mm = re.search(r"\.text\s+start:0x([0-9a-f]+) end:0x([0-9a-f]+)", l)
        if mm and 'kind:' not in l:
            rng.append((int(mm.group(1), 16), int(mm.group(2), 16)))
    return rng


def load(mod, ovs, md):
    if mod == 'main':
        cfg = yaml.safe_load(open(os.path.join(EXT, 'arm9', 'arm9.yaml')))
        data = open(os.path.join(EXT, 'arm9', 'arm9.bin'), 'rb').read()
        base = cfg['base_address']
        d = CFG
    else:
        o = next(o for o in ovs if o['id'] == int(mod[2:]))
        data = open(os.path.join(EXT, 'arm9_overlays', o['file_name']), 'rb').read()
        base = o['base_address']
        d = os.path.join(CFG, 'overlays', mod)
    rng = text_ranges(d)
    out = {}
    for l in open(os.path.join(d, 'symbols.txt')):
        m = re.match(r'(\S+) kind:function\(arm,size=0x([0-9a-f]+)\) addr:0x([0-9a-f]+)', l)
        if not m:
            continue
        a, n = int(m.group(3), 16), int(m.group(2), 16)
        if a - base < 0 or a - base + n > len(data):
            continue
        ins = [norm(i) for i in md.disasm(data[a - base:a - base + n], a)]
        out[(mod, m.group(1))] = (ins, any(s <= a < e for s, e in rng), a)
    return out


G = {}


def work(key):
    D, idx, K, CF, TH = G['D'], G['idx'], G['K'], G['CF'], G['TH']
    ins = D[key][0]
    grams = set(hash(tuple(ins[i:i + K])) for i in range(len(ins) - K + 1))
    cnt = collections.Counter()
    for g in grams:
        for k in idx.get(g, ()):
            cnt[k] += 1
    res = []
    for k, c in cnt.most_common(20):
        if c < CF * len(grams) or k == key:
            continue
        sm = difflib.SequenceMatcher(None, ins, D[k][0], autojunk=False)
        mt = sum(b.size for b in sm.get_matching_blocks())
        cov = mt / len(ins)
        sym = 2 * mt / (len(ins) + len(D[k][0]))
        if cov >= TH:
            res.append((round(cov, 3), round(sym, 3), k[0], k[1], len(D[k][0])))
    res.sort(reverse=True)
    return key, len(ins), res[:3]


def main():
    ap = argparse.ArgumentParser()
    ap.add_argument('--modules', default=','.join('ov%03d' % i for i in range(16) if i != 4))
    ap.add_argument('--min-len', type=int, default=40)
    ap.add_argument('--th', type=float, default=0.55)
    ap.add_argument('-K', type=int, default=4)
    ap.add_argument('--cf', type=float, default=0.2)
    ap.add_argument('-j', type=int, default=4)
    ap.add_argument('-o', default='-')
    ap.add_argument('--mask-imm', action='store_true',
                    help='also mask immediates and field offsets (finds structural twins)')
    a = ap.parse_args()
    global MASK_IMM
    MASK_IMM = a.mask_imm
    ovs = yaml.safe_load(open(os.path.join(EXT, 'arm9_overlays', 'overlays.yaml')))['overlays']
    md = capstone.Cs(capstone.CS_ARCH_ARM, capstone.CS_MODE_ARM)
    D = {}
    for m in ['main'] + ['ov%03d' % i for i in range(16) if i != 4]:
        D.update(load(m, ovs, md))
    idx = collections.defaultdict(set)
    for k, (ins, matched, _) in D.items():
        if not matched or len(ins) < 30:
            continue
        for i in range(len(ins) - a.K + 1):
            idx[hash(tuple(ins[i:i + a.K]))].add(k)
    G.update(D=D, idx=idx, K=a.K, CF=a.cf, TH=a.th)
    mods = set(a.modules.split(','))
    todo = [k for k, v in D.items() if k[0] in mods and not v[1] and len(v[0]) >= a.min_len]
    rows = []
    with Pool(a.j) as p:
        for key, n, res in p.imap_unordered(work, todo, chunksize=4):
            if res:
                cov, sym, tm, tf, tn = res[0]
                alt = ';'.join('%s:%s:%.3f' % (r[2], r[3], r[0]) for r in res[1:])
                rows.append((cov, sym, key[0], key[1], n, tm, tf, tn, alt))
    rows.sort(reverse=True)
    f = sys.stdout if a.o == '-' else open(a.o, 'w')
    f.write('cov\tsym\tmodule\tfunction\tninsn\ttwin_module\ttwin\ttwin_ninsn\talternatives\n')
    for r in rows:
        f.write('%.3f\t%.3f\t%s\t%s\t%d\t%s\t%s\t%d\t%s\n' % r)


if __name__ == '__main__':
    main()
