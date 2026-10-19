#!/usr/bin/env python3
"""Turn a range of hand-written ARM code from the extracted ROM into MWCC `asm` functions.

Reads the bytes from extract/<version>, function boundaries from the module's symbols.txt and
relocations from its relocs.txt, disassembles with capstone and prints a C file to stdout.

    asm2mw.py MODULE START END [--root REPO] [--version usa] [--data A-B,...]
              [--split NAME@ADDR,...] [--rename OLD=NEW,...] [--verify]

MODULE is main, itcm, dtcm or ovNNN. START/END are hex addresses (END exclusive).

Conventions (same as libs/runtime/FP_fastI_*.c):
  * relocated words become `dcd symbol+addend`, relocated calls become `bl symbol`;
  * a branch to a label inside the same function becomes `b @L<addr>`;
  * a branch with no relocation that leaves the function (or lands mid-way into a
    neighbouring routine) becomes a raw `dcd` with the instruction as a comment;
  * pc-relative loads are kept literally (`ldr r0, [pc, #0x10]`) and the pool words are
    emitted as `dcd`, so the layout is exactly the original one.

With --verify the file is compiled with MWCC and compared against the ROM; any word that
does not assemble to the original encoding is replaced by a `dcd` (with the instruction in
a comment) and the file is compiled again. The final mismatch count goes to stderr.
"""
import argparse
import os
import re
import subprocess
import sys
import tempfile

import capstone

CONDS = "eq|ne|cs|hs|cc|lo|mi|pl|vs|vc|hi|ls|ge|lt|gt|le|al"
SHIFTS = "lsl|lsr|asr|ror"


def parse_symbols(path):
    syms = []
    if not os.path.exists(path):
        return syms
    for line in open(path):
        m = re.match(r"^(\S+) kind:(\w+)(?:\(([^)]*)\))? addr:0x([0-9a-f]+)", line)
        if not m:
            continue
        name, kind, attrs, addr = m.group(1), m.group(2), m.group(3) or "", int(m.group(4), 16)
        size = None
        mm = re.search(r"size=0x([0-9a-f]+)", attrs)
        if mm:
            size = int(mm.group(1), 16)
        syms.append(dict(name=name, kind=kind, attrs=attrs, addr=addr, size=size))
    return syms


def parse_relocs(path):
    rel = {}
    for line in open(path):
        m = re.match(r"^from:0x([0-9a-f]+) kind:(\w+)(?:\(\w+\))?(?: to:0x([0-9a-f]+))?(?: add:(-?0x[0-9a-f]+))?(?: module:(\S+))?", line)
        if not m:
            continue
        rel[int(m.group(1), 16)] = dict(kind=m.group(2), to=int(m.group(3), 16) if m.group(3) else None,
                                        add=int(m.group(4), 16) if m.group(4) else 0, module=m.group(5))
    return rel


class Repo:
    def __init__(self, root, version):
        self.root = root
        self.cfg = os.path.join(root, "config", version, "arm9")
        self.ext = os.path.join(root, "extract", version)

    def module_dir(self, module):
        if module == "main":
            return self.cfg
        if module in ("itcm", "dtcm"):
            return os.path.join(self.cfg, module)
        return os.path.join(self.cfg, "overlays", module)

    def module_bin(self, module):
        import yaml  # noqa: only needed here
        if module == "main":
            y = yaml.safe_load(open(os.path.join(self.ext, "arm9", "arm9.yaml")))
            return y["base_address"], open(os.path.join(self.ext, "arm9", "arm9.bin"), "rb").read()
        if module in ("itcm", "dtcm"):
            y = yaml.safe_load(open(os.path.join(self.ext, "arm9", module + ".yaml")))
            return y["base_address"], open(os.path.join(self.ext, "arm9", module + ".bin"), "rb").read()
        y = yaml.safe_load(open(os.path.join(self.ext, "arm9_overlays", "overlays.yaml")))
        oid = int(module[2:])
        for o in y["overlays"]:
            if o["id"] == oid:
                return o["base_address"], open(os.path.join(self.ext, "arm9_overlays", o["file_name"]), "rb").read()
        raise SystemExit("no overlay " + module)

    def symbols(self, module):
        return parse_symbols(os.path.join(self.module_dir(module), "symbols.txt"))

    def relocs(self, module):
        return parse_relocs(os.path.join(self.module_dir(module), "relocs.txt"))


def reloc_module_name(m):
    if m is None or m == "main":
        return "main"
    mm = re.match(r"overlay\((\d+)\)", m)
    if mm:
        return "ov%03d" % int(mm.group(1))
    mm = re.match(r"overlays\(", m)
    if mm:
        return None
    return m


def name_for(repo, cache, module, addr):
    """Symbol expression for an address in a module: exact symbol or nearest preceding one + offset."""
    if module is None:
        return None
    if module not in cache:
        try:
            cache[module] = sorted(repo.symbols(module), key=lambda s: s["addr"])
        except FileNotFoundError:
            cache[module] = []
    best = None
    for s in cache[module]:
        if s["addr"] == addr and s["kind"] != "label":
            return s["name"], 0
        if s["addr"] <= addr and s["kind"] in ("function", "data", "bss"):
            best = s
    if best is None:
        return None
    return best["name"], addr - best["addr"]


def conv(op, args):
    """Capstone UAL text -> MWCC (pre-UAL) syntax."""
    if re.match(r"^(mcr|mrc|cdp|ldc|stc)2?", op):
        args = re.sub(r"#(\d+)", r"\1", args)
    mm = re.match(rf"^({SHIFTS})(s?)({CONDS})?$", op)
    if mm:
        sh, s, c = mm.group(1), mm.group(2), mm.group(3) or ""
        a = [x.strip() for x in args.split(",")]
        if len(a) == 2:
            return f"mov{c}{s} {a[0]}, {a[0]}, {sh} {a[1]}"
        return f"mov{c}{s} {a[0]}, {a[1]}, {sh} {a[2]}"
    mm = re.match(rf"^rrx(s?)({CONDS})?$", op)
    if mm:
        a = [x.strip() for x in args.split(",")]
        return f"mov{mm.group(2) or ''}{mm.group(1)} {a[0]}, {a[1]}, rrx"
    mm = re.match(rf"^(push|pop)({CONDS})?$", op)
    if mm:
        c = mm.group(2) or ""
        return (f"stm{c}fd sp!, " if mm.group(1) == "push" else f"ldm{c}fd sp!, ") + args
    mm = re.match(rf"^(ldm|stm)(ia|ib|da|db|fd|fa|ed|ea)?({CONDS})?$", op)
    if mm:
        return f"{mm.group(1)}{mm.group(3) or ''}{mm.group(2) or 'ia'} {args}"
    mm = re.match(rf"^(and|eor|sub|rsb|add|adc|sbc|rsc|orr|mov|bic|mvn|mul|mla|umull|smull|umlal|smlal)s({CONDS})$", op)
    if mm:
        op = mm.group(1) + mm.group(2) + "s"
    mm = re.match(rf"^(ldr|str)(b|h|sb|sh|d|bt|t)({CONDS})$", op)
    if mm:
        op = mm.group(1) + mm.group(3) + mm.group(2)
    return f"{op} {args}".strip()


missing_relocs = []


def add_relocs(repo, module, new):
    """Add arm_call/arm_branch relocations that dsd's analysis missed to the module's relocs.txt."""
    path = os.path.join(repo.module_dir(module), "relocs.txt")
    lines = [l for l in open(path).read().split("\n") if l]
    have = {int(l.split()[0][7:], 16) for l in lines}
    mod = "main" if module == "main" else (module if module in ("itcm", "dtcm") else "overlay(%d)" % int(module[2:]))
    for a, kind, tgt in new:
        if a not in have:
            lines.append(f"from:0x{a:08x} kind:{kind} to:0x{tgt:08x} module:{mod}")
    lines.sort(key=lambda l: int(l.split()[0][7:], 16))
    open(path, "w").write("\n".join(lines) + "\n")


def generate(repo, module, start, end, data_ranges=(), splits=(), rename=None, force_dcd=(), explicit=()):
    """Returns (C text, base, binary, functions) where functions is a list of (name, start, end).
    Functions named in `explicit` keep pc-relative loads and pool words literally; the others use
    `ldr rX, =value` when their literal pool sits at the end of the function."""
    rename = rename or {}
    base, binary = repo.module_bin(module)
    syms = repo.symbols(module)
    relocs = repo.relocs(module)
    cache = {}

    def word(a):
        return int.from_bytes(binary[a - base:a - base + 4], "little")

    funcs = {s["addr"]: s for s in syms if s["kind"] == "function" and start <= s["addr"] < end}
    for nm, a in splits:
        funcs[a] = dict(name=nm, addr=a, attrs="arm")
    if start not in funcs:
        raise SystemExit(f"no function symbol at start 0x{start:08x}")
    starts = sorted(funcs)
    bounds = [(a, starts[i + 1] if i + 1 < len(starts) else end) for i, a in enumerate(starts)]
    for a, _ in bounds:
        if "thumb" in funcs[a]["attrs"]:
            raise SystemExit(f"thumb function at 0x{a:08x} not supported")

    cs = capstone.Cs(capstone.CS_ARCH_ARM, capstone.CS_MODE_ARM)
    cs.syntax = capstone.CS_OPT_SYNTAX_NOREGNAME

    def is_data(a):
        return any(lo <= a < hi for lo, hi in data_ranges)

    externs = set()
    fexterns = set()
    out_funcs = []
    missing_relocs.clear()
    for fstart, fend in bounds:
        fname = rename.get(funcs[fstart]["name"], funcs[fstart]["name"])
        # first pass: decode, find pools and branch targets
        ins = {}
        pool = set()
        poolref = {}
        targets = set()
        for a in range(fstart, fend, 4):
            if is_data(a) or a in relocs and relocs[a]["kind"] == "load":
                continue
            d = list(cs.disasm(binary[a - base:a - base + 4], a))
            if not d:
                continue
            i = d[0]
            ins[a] = i
            mm = re.match(r"^ldr\w*$", i.mnemonic)
            m2 = re.search(r"\[pc, #(-?0x[0-9a-f]+|-?\d+)\]$", i.op_str)
            if mm and m2:
                tgt = a + 8 + int(m2.group(1), 0)
                if fstart <= tgt < fend:
                    pool.add(tgt)
                    poolref[a] = tgt
            if re.match(rf"^bl?({CONDS})?$", i.mnemonic) and i.op_str.startswith("#"):
                targets.add(int(i.op_str[1:], 0))
        def pool_value(pa):
            r = relocs.get(pa)
            if r and r["kind"] == "load":
                nm = name_for(repo, cache, reloc_module_name(r["module"]), r["to"]) if r["to"] is not None else None
                if nm is None:
                    return None
                n, off = nm
                n = rename.get(n, n)
                off += r["add"]
                return n, n + (f"+0x{off:x}" if off > 0 else (f"-0x{-off:x}" if off < 0 else ""))
            return None, f"0x{word(pa):x}"

        code_end = max([a for a in ins if a not in pool] + [fstart]) + 4
        ldr_eq = (fname not in explicit and pool and min(pool) >= code_end
                  and all(pool_value(pa) is not None for pa in pool)
                  # MWCC rejects `ldr rX, =symbol+offset`
                  and not any(pool_value(pa)[0] and re.search(r"[+-]0x", pool_value(pa)[1]) for pa in pool)
                  and all(a not in force_dcd for a in poolref))
        body = []
        for a in range(fstart, fend, 4):
            w = word(a)
            if a in targets and fstart < a:
                body.append(f"@L{a:08x}:")
            if ldr_eq and a in poolref:
                n, expr = pool_value(poolref[a])
                if n:
                    externs.add(n)
                i = ins[a]
                body.append("    " + conv(i.mnemonic, i.op_str.split(", [pc")[0] + ", =" + expr))
                continue
            if ldr_eq and a in pool:
                continue
            r = relocs.get(a)
            if a in force_dcd:
                i = ins.get(a)
                body.append(f"    dcd 0x{w:08x}" + (f" // {i.mnemonic} {i.op_str}" if i else ""))
                continue
            if r and r["kind"] == "load":
                tm = reloc_module_name(r["module"])
                nm = name_for(repo, cache, tm, r["to"]) if r["to"] is not None else None
                if nm is None:
                    body.append(f"    dcd 0x{w:08x} // unresolved reloc")
                    continue
                n, off = nm
                n = rename.get(n, n)
                externs.add(n)
                off += r["add"]
                body.append(f"    dcd {n}" + (f"+0x{off:x}" if off > 0 else (f"-0x{-off:x}" if off < 0 else "")))
                continue
            if a in pool or is_data(a) or a not in ins or w == 0:
                body.append(f"    dcd 0x{w:08x}")
                continue
            i = ins[a]
            op, args = i.mnemonic, i.op_str
            mb = re.match(rf"^(bl?|blx)({CONDS})?$", op)
            if mb and args.startswith("#"):
                tgt = int(args[1:], 0)
                if r and r["kind"] in ("arm_call", "arm_branch", "arm_call_thumb") and op != "blx":
                    tm = reloc_module_name(r["module"])
                    nm = name_for(repo, cache, tm, r["to"])
                    if nm and nm[1] == 0:
                        n = rename.get(nm[0], nm[0])
                        if n != fname:
                            fexterns.add(n)
                        body.append(f"    {op} {n}")
                        continue
                if fstart <= tgt < fend and op != "blx":
                    body.append(f"    {op} @L{tgt:08x}")
                    continue
                nm = name_for(repo, cache, module, tgt)
                # dsd delinks every arm_call/arm_branch as an unconditional branch, so only
                # unconditional ones can be given a relocation
                if (nm and nm[1] == 0 and not mb.group(2)
                        and any(x["addr"] == tgt and x["kind"] == "function" for x in syms)):
                    missing_relocs.append((a, "arm_call" if mb.group(1) == "bl" else "arm_branch", tgt))
                desc = f"0x{tgt:08x}"
                if nm:
                    n = rename.get(nm[0], nm[0])
                    desc = n + (f"+0x{nm[1]:x}" if nm[1] else "")
                body.append(f"    dcd 0x{w:08x} // {op} {desc}")
                continue
            mp = re.match(rf"^(push|pop)({CONDS})?$", op)
            if mp and (w & 0x0fff0fff) in (0x049d0004, 0x052d0004):
                # single-register push/pop encoded as a post-indexed ldr / pre-indexed str
                c, reg = mp.group(2) or "", args.strip("{} ")
                body.append(f"    ldr{c} {reg}, [sp], #4" if mp.group(1) == "pop" else f"    str{c} {reg}, [sp, #-4]!")
                continue
            body.append("    " + conv(op, args))
        out_funcs.append((fname, body, fstart, fend))

    lines = []
    own = {f[0] for f in out_funcs}
    for n in sorted(fexterns - own):
        lines.append(f"void {n}(void);")
    for n in sorted(externs - own - fexterns):
        lines.append(f"extern char {n}[];")
    for f in out_funcs:
        lines.append(f"void {f[0]}(void);")
    lines.append("")
    for fname, body, _, _ in out_funcs:
        lines.append(f"asm void {fname}(void) {{")
        lines.extend(body)
        lines.append("}")
        lines.append("")
    return "\n".join(lines), base, binary, [(f[0], f[2], f[3]) for f in out_funcs]


# ---------------------------------------------------------------------------------------------
def compile_c(repo, src_text, workdir):
    c = os.path.join(workdir, "t.c")
    o = os.path.join(workdir, "t.o")
    open(c, "w").write("#pragma force_active on\n\n" + src_text)
    cmd = ["./wibo", "./sjiswrap.exe", "./tools/mwccarm/dsi/1.3p1/mwccarm.exe", "-O4,p", "-enum", "int",
           "-char", "signed", "-str", "noreuse", "-proc", "arm946e", "-gccext,on", "-fp", "soft",
           "-inline", "noauto", "-lang=c", "-Cpp_exceptions", "off", "-RTTI", "off", "-interworking",
           "-w", "off", "-nolink", "-msgstyle", "gcc", "-i", "include", "-c", c, "-o", o]
    p = subprocess.run(cmd, cwd=repo.root, capture_output=True, text=True)
    if p.returncode != 0 or not os.path.exists(o):
        sys.stderr.write(p.stdout + p.stderr)
        raise SystemExit("compile failed")
    return o


def sections_of(o):
    """{function name: (bytes, set of relocated offsets)} for each .text section (MWCC emits one
    per function)."""
    from elftools.elf.elffile import ELFFile
    from elftools.elf.relocation import RelocationSection
    from elftools.elf.sections import SymbolTableSection
    f = ELFFile(open(o, "rb"))
    secs = {idx: sec for idx, sec in enumerate(f.iter_sections()) if sec.name == ".text"}
    names = {}
    for sec in f.iter_sections():
        if isinstance(sec, SymbolTableSection):
            for sym in sec.iter_symbols():
                if sym["st_info"]["type"] == "STT_FUNC" and sym["st_shndx"] in secs and sym["st_value"] == 0:
                    names[sym["st_shndx"]] = sym.name
    relocated = {idx: set() for idx in secs}
    for sec in f.iter_sections():
        if isinstance(sec, RelocationSection) and sec["sh_info"] in secs:
            for r in sec.iter_relocations():
                relocated[sec["sh_info"]].add(r["r_offset"])
    return {names.get(idx, "?%d" % idx): (sec.data(), relocated[idx]) for idx, sec in secs.items()}


def verify(repo, text, base, binary, funcs):
    """Returns (bad word addresses, names of functions whose size is wrong)."""
    with tempfile.TemporaryDirectory() as td:
        o = compile_c(repo, text, td)
        secs = sections_of(o)
    bad, badsize = [], []
    for name, fs, fe in funcs:
        data, rel = secs.get(name, (b"", set()))
        orig = binary[fs - base:fe - base]
        if len(data) != len(orig):
            badsize.append(name)
            continue
        for off in range(0, len(orig), 4):
            if off not in rel and data[off:off + 4] != orig[off:off + 4]:
                bad.append(fs + off)
    return bad, badsize


def main():
    ap = argparse.ArgumentParser(description=__doc__, formatter_class=argparse.RawDescriptionHelpFormatter)
    ap.add_argument("module")
    ap.add_argument("start")
    ap.add_argument("end")
    ap.add_argument("--root", default=os.getcwd())
    ap.add_argument("--version", default="usa")
    ap.add_argument("--data", default="", help="comma separated A-B hex ranges to emit as dcd")
    ap.add_argument("--split", default="", help="comma separated NAME@ADDR extra function starts")
    ap.add_argument("--rename", default="", help="comma separated OLD=NEW names")
    ap.add_argument("--verify", action="store_true")
    ap.add_argument("--add-relocs", action="store_true",
                    help="add relocations for branches to function starts that relocs.txt lacks, so they are "
                         "written symbolically instead of as dcd")
    a = ap.parse_args()
    repo = Repo(os.path.abspath(a.root), a.version)
    start, end = int(a.start, 16), int(a.end, 16)
    data = [tuple(int(x, 16) for x in r.split("-")) for r in a.data.split(",") if r]
    splits = [(s.split("@")[0], int(s.split("@")[1], 16)) for s in a.split.split(",") if s]
    rename = dict(x.split("=") for x in a.rename.split(",") if x)
    force, explicit = set(), set()
    text, base, binary, funcs = generate(repo, a.module, start, end, data, splits, rename, force, explicit)
    if a.add_relocs and missing_relocs:
        sys.stderr.write("adding %d relocations to relocs.txt\n" % len(missing_relocs))
        add_relocs(repo, a.module, list(missing_relocs))
        text, base, binary, funcs = generate(repo, a.module, start, end, data, splits, rename, force, explicit)
    if a.verify:
        for _ in range(6):
            bad, badsize = verify(repo, text, base, binary, funcs)
            if not bad and not badsize:
                sys.stderr.write("verify: OK\n")
                break
            if badsize:
                if set(badsize) <= explicit:
                    sys.stderr.write("verify: size mismatch in %s\n" % ", ".join(badsize))
                    break
                explicit |= set(badsize)
                sys.stderr.write("verify: size mismatch in %s, keeping their pools literal\n" % ", ".join(badsize))
            elif bad:
                inpool = {f for f, fs, fe in funcs if any(fs <= b < fe for b in bad)} - explicit
                if inpool:
                    # first try literal pools for the affected functions, then fall back to dcd
                    explicit |= inpool
                    sys.stderr.write("verify: mismatches in %s, keeping their pools literal\n" % ", ".join(sorted(inpool)))
                else:
                    sys.stderr.write("verify: %d mismatching words, emitting as dcd: %s\n" % (len(bad), " ".join("%08x" % b for b in bad)))
                    force |= set(bad)
            text, base, binary, funcs = generate(repo, a.module, start, end, data, splits, rename, force, explicit)
        else:
            sys.stderr.write("verify: gave up\n")
    print(text)


if __name__ == "__main__":
    main()
