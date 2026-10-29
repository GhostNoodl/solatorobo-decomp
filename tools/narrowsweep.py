#!/usr/bin/env python3
"""Narrow/wide local type sweep for one function (round bgQ).

    python3 tools/narrowsweep.py SRC FUNC [--module ovNNN] [--reverse] [--params] [--place] [--only a,b] [--out F]

Round bgN: a `u8` (or other narrow) local whose every use is promoted to int is folded into an int compiler
temp (an `@N` object, numbered below every user variable), so no declaration order can move it. Declaring it
`s32` keeps it a named local (the loads from a `u8` field stay `ldrb`). This tool tries that on every narrow
local (u8/s8/u16/s16/char/short/bool) of FUNC and of the inline functions FUNC calls in SRC: one variant per
local and per wider type (s32, u32), each compiled with NONMATCHING defined and scored against the base ROM
with honest_search's scorer (register-masked sequence diff, positional diff). `--reverse` also narrows the
int-typed locals (s32/u32/int -> u8/s8/u16/s16), for the opposite case (a named local the ROM treats as a
temp). `--params` includes the parameters of the inlines. `--place` also moves each widened bare declaration
to every slot of its declaration run (a widened local is a new user variable, so its node depends on where it
is declared). Improving variants are then combined greedily; `--out F` writes the combination.

Every variant is a type change: read the winners and keep only the ones whose value range fits the new type
and whose code does not rely on truncation (an added or dropped `and #0xff` / `lsl #24; asr #24` is a
semantic change, not a colouring lever).
"""
import argparse, os, re, sys
from concurrent.futures import ThreadPoolExecutor

sys.path.insert(0, os.path.dirname(os.path.abspath(__file__)))
from honest_search import Scorer, find_body  # noqa: E402


def func_bodies(lines, func):
    """FUNC's body plus the bodies of the inline functions it calls, transitively (target first)."""
    tb = find_body(lines, func); out = [tb]; todo = [tb]; seen = {func}
    while todo:
        b = todo.pop(); body = "\n".join(lines[b[1]:b[2] + 1])
        for i, l in enumerate(lines[:tb[0]]):
            m = re.match(r"^\s*(?:static\s+)?inline\b[^;(]*?\b([A-Za-z_]\w*)\s*\(", l)
            if m and m.group(1) not in seen and re.search(r"\b" + m.group(1) + r"\s*\(", body):
                nb = find_body(lines[:tb[0]], m.group(1))
                if nb and nb[0] == i: seen.add(m.group(1)); out.append(nb); todo.append(nb)
    return out

NARROW = r"(?:u8|s8|u16|s16|char|unsigned char|signed char|short|unsigned short|bool)"
WIDE = r"(?:s32|u32|int|unsigned int|unsigned)"
TO_WIDE = ["s32", "u32"]
TO_NARROW = ["u8", "s8", "u16", "s16"]


def split_decls(lines):
    """Split `T a, b = x;` into one declaration per line (same order, same meaning)."""
    out = []
    for l in lines:
        m = re.match(r"^(\s+)((?:const\s+)?(?:unsigned\s+|signed\s+)?[A-Za-z_]\w*)\s+([^;(]*?(?:\([^;]*\))?[^;]*);\s*(//.*)?$", l)
        if m and "," in m.group(3) and not re.match(r"\s*(return|goto|case|delete)\b", l):
            parts, d, cur = [], 0, ""
            for c in m.group(3):
                if c in "([{": d += 1
                if c in ")]}": d -= 1
                if c == "," and d == 0: parts.append(cur.strip()); cur = ""; continue
                cur += c
            parts.append(cur.strip())
            if all(re.match(r"^\**\s*[A-Za-z_]\w*(\[\w*\])?(\s*=.*)?$", p) for p in parts):
                out += ["%s%s %s;" % (m.group(1), m.group(2), p) for p in parts]
                continue
        out.append(l)
    return out


def candidates(lines, func, reverse, params):
    tys = NARROW + ("|" + WIDE if reverse else "")
    dre = re.compile(r"^(\s+)((?:const\s+)?)(" + tys + r")(\s+)([A-Za-z_]\w*)(\s*(=|;|\[))")
    out = []
    for i0, j0, k0 in func_bodies(lines, func):
        for i in range(j0, k0 + 1):
            m = dre.match(lines[i])
            if m and m.group(7) != "[":
                out.append((i, m.start(3), m.end(3), m.group(3), m.group(5), "local"))
        if params and i0 != func_bodies(lines, func)[0][0]:
            sig = lines[i0]
            for m in re.finditer(r"[(,]\s*((?:const\s+)?)(" + tys + r")\s+([A-Za-z_]\w*)\s*(?=[,)])", sig):
                out.append((i0, m.start(2), m.end(2), m.group(2), m.group(3), "param"))
    return out


def main():
    ap = argparse.ArgumentParser(description=__doc__, formatter_class=argparse.RawDescriptionHelpFormatter)
    ap.add_argument("src"); ap.add_argument("func"); ap.add_argument("--module")
    ap.add_argument("--reverse", action="store_true"); ap.add_argument("--params", action="store_true")
    ap.add_argument("--place", action="store_true",
                    help="also move each widened bare declaration to every slot of its declaration run")
    ap.add_argument("--only", help="comma-separated local names to try (default: all)")
    ap.add_argument("-j", type=int, default=2); ap.add_argument("--out")
    a = ap.parse_args()
    mod = a.module or (re.match(r"func_(ov\d+)_", a.func).group(1) if re.match(r"func_ov\d+_", a.func) else "main")
    sc = Scorer(a.src, a.func, mod)
    lines = split_decls(open(a.src, encoding="latin1").read().split("\n"))
    base = sc.score("\n".join(lines))
    print("base", base, flush=True)
    if base is None: raise SystemExit("base does not compile")
    cands = candidates(lines, a.func, a.reverse, a.params)
    if a.only: cands = [c for c in cands if c[4] in a.only.split(",")]
    bare = re.compile(r"^\s+(?:const\s+)?[A-Za-z_][\w ]*[\s*]+\**\s*[A-Za-z_]\w*(\[\w*\])?;\s*(//.*)?$")
    vars_ = []
    for (i, s, e, ty, name, kind) in cands:
        narrow = re.fullmatch(NARROW, ty) is not None
        for nt in (TO_WIDE if narrow else TO_NARROW):
            if nt == ty: continue
            vars_.append(((i, s, e, nt), "%s %s %s:%d %s -> %s" % (kind, "widen" if narrow else "NARROW", name, i + 1, ty, nt)))
            if a.place and narrow and kind == "local" and bare.match(lines[i]):
                lo = i
                while lo - 1 >= 0 and bare.match(lines[lo - 1]): lo -= 1
                hi = i
                while hi + 1 < len(lines) and bare.match(lines[hi + 1]): hi += 1
                for pos in range(lo, hi + 1):
                    if pos != i:
                        vars_.append(((i, s, e, nt, pos), "%s widen %s:%d %s -> %s, moved to line %d" % (kind, name, i + 1, ty, nt, pos + 1)))

    def apply(edits):
        ls = list(lines)
        for (i, s, e, nt) in sorted((x[:4] for x in edits), key=lambda x: (x[0], -x[1])):
            ls[i] = ls[i][:s] + nt + ls[i][e:]
        for x in edits:   # declaration moves (at most one per edit, applied after the type changes)
            if len(x) > 4:
                l = ls.pop(x[0]); ls.insert(x[4], l)
        return "\n".join(ls)

    with ThreadPoolExecutor(min(a.j, 2)) as ex:
        scs = list(ex.map(lambda v: sc.score(apply([v[0]])), vars_))
    res = sorted(zip(scs, vars_), key=lambda r: r[0] or (9999, 9999))
    for s, (ed, desc) in res: print(s, desc, "*" if s and s < base else "")
    good = [(s, v) for s, v in res if s is not None and s < base]
    # greedy combination of improving variants (one type per line)
    cur, cur_ed = base, []
    for s, (ed, desc) in good:
        if any(x[0] == ed[0] and x[1] == ed[1] for x in cur_ed) or (len(ed) > 4 and cur_ed): continue
        t = sc.score(apply(cur_ed + [ed]))
        if t is not None and t < cur: cur, cur_ed = t, cur_ed + [ed]; print("combo", t, "+", desc, flush=True)
    if a.out and cur_ed:
        open(a.out, "w", encoding="latin1").write(apply(cur_ed)); print("wrote", a.out, cur)


if __name__ == "__main__":
    main()
