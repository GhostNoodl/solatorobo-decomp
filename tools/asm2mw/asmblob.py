#!/usr/bin/env python3
"""Disassemble position-independent hand-written ARM code (a blob with computed jumps and tables
inside it) into MWCC `asm` blocks that build byte-identical.

    asmblob.py MODULE BLOCK [BLOCK ...] [--root REPO] [--version usa] [--verify]

Each BLOCK is NAME:START:END:KIND[:ENTRY,ENTRY...] with hex addresses (END exclusive). KIND is
`code` or `data`. A data block is written as `dcd` words. In a code block, the code/data split
comes from a flow analysis that starts at START and at the listed entries:

  * it follows `b`/`bl` and conditional fall-through, and stops at unconditional `b`, `bx`
    and anything that writes `pc`;
  * it tracks `add/sub rX, pc, #imm` (and `add/sub #imm`, `mov` on such a register): an
    address that ends up in `lr`, `bx`, `mov pc` or a `pc` load is code, an address used as
    the base of `add pc, rOff, rBase` is a jump table of offsets from that base (each entry is
    followed as code), and any other use marks the address as data (a table base);
  * `ldr rX, [pc, #imm]` marks a pool word;
  * when nothing is left to follow, a word with condition AL right after an unconditional
    terminator is taken as a new entry (these are the routines reached only through tables
    the analysis does not see).

Words the analysis never reaches are written as `dcd`. Branch targets, computed entries,
pool words and table bases get `@L<addr>` labels; pc-relative operands stay numeric (the MWCC
assembler has no label arithmetic) with the address they resolve to in a comment, so the code
stays position-independent and no relocations are emitted. A branch that leaves its block
must have a relocation in relocs.txt (it is then written with the symbol).

With --verify the output is compiled with MWCC and each block is compared against the ROM.

With --labels, the symbols.txt lines that give the delinked target the same mapping symbols
as the build are printed to stderr: `kind:label(arm,data)` (a `$d`, needs the dsd patch in
tools/dsd-patches) where a data run starts inside a code block and `kind:label(arm)` (a `$a`)
where code resumes. Without them the target block is all `$a` and objdiff compares the data
words as instructions.
"""
import argparse
import os
import re
import struct
import sys
import tempfile

import capstone
from capstone import arm as A

sys.path.insert(0, os.path.dirname(os.path.abspath(__file__)))
import asm2mw  # noqa: E402

PC, LR = A.ARM_REG_PC, A.ARM_REG_LR
LOADS = (A.ARM_INS_LDR, A.ARM_INS_LDRH, A.ARM_INS_LDRB, A.ARM_INS_LDRSH, A.ARM_INS_LDRSB, A.ARM_INS_LDRD)


class Flow:
    def __init__(self, word, dis, start, end, entries):
        self.word, self.dis, self.S, self.E = word, dis, start, end
        self.code, self.data, self.jtbases, self.codeptrs = set(), {}, set(), set()
        self.work = [(start, {})] + [(e, {}) for e in entries]
        self.speculative = []
        self.run()

    def push(self, a, st):
        self.codeptrs.add(a)
        self.work.append((a, st))

    def flow(self, a, st):
        S, E = self.S, self.E
        while S <= a < E:
            if a in self.code:
                return
            i = self.dis(a)
            if i is None:
                raise SystemExit("undecodable word on a code path at 0x%08x" % a)
            self.code.add(a)
            ops, cond = i.operands, i.cc != A.ARM_CC_AL
            rd, wr = i.regs_access()
            if (i.id in (A.ARM_INS_ADD, A.ARM_INS_SUB) and len(ops) == 3 and ops[1].type == A.ARM_OP_REG
                    and ops[1].reg == PC and ops[2].type == A.ARM_OP_IMM):
                v = a + 8 + (ops[2].imm if i.id == A.ARM_INS_ADD else -ops[2].imm)
                r = ops[0].reg
                if r == PC:
                    self.push(v, dict(st))
                    if not cond:
                        return
                elif r == LR:
                    self.push(v, {})
                    st.pop(LR, None)
                elif cond:
                    st.pop(r, None)
                else:
                    st[r] = v
                a += 4
                continue
            if (i.id in (A.ARM_INS_ADD, A.ARM_INS_SUB) and not cond and len(ops) == 3 and ops[1].type == A.ARM_OP_REG
                    and ops[1].reg in st and ops[2].type == A.ARM_OP_IMM and ops[0].reg != PC):
                st[ops[0].reg] = st[ops[1].reg] + (ops[2].imm if i.id == A.ARM_INS_ADD else -ops[2].imm)
                a += 4
                continue
            if (i.id == A.ARM_INS_MOV and not cond and len(ops) == 2 and ops[1].type == A.ARM_OP_REG
                    and ops[1].reg in st and ops[0].reg != PC and ops[1].shift.type == 0):
                st[ops[0].reg] = st[ops[1].reg]
                a += 4
                continue
            if (i.id == A.ARM_INS_MOV and len(ops) == 2 and ops[0].reg == LR and ops[1].type == A.ARM_OP_REG
                    and ops[1].reg == PC):
                self.push(a + 8, {})
            if i.id in LOADS and len(ops) >= 2 and ops[1].type == A.ARM_OP_MEM and ops[1].mem.base == PC \
                    and ops[1].mem.index == 0:
                t = a + 8 + ops[1].mem.disp * (-1 if ops[1].subtracted else 1)
                self.data.setdefault(t & ~3, "pool")
                if i.id == A.ARM_INS_LDRD:
                    self.data.setdefault((t & ~3) + 4, "pool")
            writes_pc = PC in wr
            for r in rd:
                if r in st:
                    if writes_pc and i.id == A.ARM_INS_ADD:
                        self.jtbases.add(st[r])
                    elif writes_pc or i.id in (A.ARM_INS_BX, A.ARM_INS_BLX):
                        self.push(st[r], {})
                    else:
                        self.data.setdefault(st[r], "table")
            for r in wr:
                st.pop(r, None)
            if i.id in (A.ARM_INS_B, A.ARM_INS_BL) and ops[0].type == A.ARM_OP_IMM:
                if S <= ops[0].imm < E:
                    self.work.append((ops[0].imm, dict(st) if i.id == A.ARM_INS_B else {}))
                if i.id == A.ARM_INS_B and not cond:
                    return
                if i.id == A.ARM_INS_BL:
                    st = {}
                a += 4
                continue
            if (writes_pc or i.id == A.ARM_INS_BX) and not cond:
                return
            a += 4

    def is_terminator(self, a):
        i = self.dis(a)
        _, wr = i.regs_access()
        return i.cc == A.ARM_CC_AL and (i.id in (A.ARM_INS_B, A.ARM_INS_BX) or PC in wr)

    def run(self):
        while True:
            while self.work:
                a, st = self.work.pop()
                self.flow(a, st)
            more = False
            for T in sorted(self.jtbases):
                p = T
                while self.S <= p < self.E and p not in self.code:
                    w = self.word(p)
                    w = w - (1 << 32) if w & 0x80000000 else w
                    if w == 0 or w % 4 or not (self.S <= T + w < self.E):
                        break
                    self.data[p] = "jt"
                    if T + w not in self.code:
                        self.push(T + w, {})
                        more = True
                    p += 4
            if more:
                continue
            for a in sorted(self.code):
                n = a + 4
                if n in self.code or n in self.data or not (self.S <= n < self.E) or not self.is_terminator(a):
                    continue
                if self.word(n) >> 28 == 0xE and self.dis(n) is not None:
                    self.speculative.append(n)
                    self.push(n, {})
                    more = True
                    break
            if not more:
                break
        bad = sorted(set(self.data) & self.code)
        if bad:
            raise SystemExit("words both code and data: " + " ".join("%08x" % b for b in bad))


def generate(repo, module, blocks):
    base, binary = repo.module_bin(module)
    relocs = repo.relocs(module)
    cache = {}

    def word(a):
        return struct.unpack_from("<I", binary, a - base)[0]

    det = capstone.Cs(capstone.CS_ARCH_ARM, capstone.CS_MODE_ARM)
    det.detail = True
    txt = capstone.Cs(capstone.CS_ARCH_ARM, capstone.CS_MODE_ARM)
    txt.syntax = capstone.CS_OPT_SYNTAX_NOREGNAME
    dcache = {}

    def dis(a):
        if a not in dcache:
            l = list(det.disasm(binary[a - base:a - base + 4], a))
            dcache[a] = l[0] if l else None
        return dcache[a]

    def text(a):
        l = list(txt.disasm(binary[a - base:a - base + 4], a))
        return l[0] if l else None

    out, decls, externs, stats, maplabels = [], [], set(), [], []
    names = {b[0] for b in blocks}

    def where(v, start, end):
        if start <= v < end:
            return f"@L{v:08x}"
        for n, s, e, _, _ in blocks:
            if s <= v < e:
                return n + (f"+0x{v - s:x}" if v > s else "")
        return f"0x{v:08x}"
    for name, start, end, kind, entries in blocks:
        decls.append(f"void {name}(void);")
        body = []
        if kind == "data":
            for a in range(start, end, 4):
                if a in relocs:
                    raise SystemExit("relocation in data block at 0x%08x" % a)
                body.append(f"    dcd 0x{word(a):08x}")
            out.append((name, body))
            stats.append((name, start, end, 0, (end - start) // 4))
            continue
        fl = Flow(word, dis, start, end, entries)
        labels = set(fl.codeptrs) | set(fl.jtbases) | {a for a, why in fl.data.items() if why != "jt"}
        jt_of = {}
        for T in sorted(fl.jtbases):
            p = T
            while fl.data.get(p) == "jt" and p not in jt_of:
                jt_of[p] = T
                p += 4
        comment = {}
        for a in fl.code:
            i = dis(a)
            ops = i.operands
            if i.id in (A.ARM_INS_B, A.ARM_INS_BL) and ops[0].type == A.ARM_OP_IMM and start <= ops[0].imm < end:
                labels.add(ops[0].imm)
            if (i.id in (A.ARM_INS_ADD, A.ARM_INS_SUB) and len(ops) == 3 and ops[1].type == A.ARM_OP_REG
                    and ops[1].reg == PC and ops[2].type == A.ARM_OP_IMM):
                v = a + 8 + (ops[2].imm if i.id == A.ARM_INS_ADD else -ops[2].imm)
                labels.add(v)
                comment[a] = where(v, start, end)
            if i.id in LOADS and len(ops) >= 2 and ops[1].type == A.ARM_OP_MEM and ops[1].mem.base == PC \
                    and ops[1].mem.index == 0:
                v = a + 8 + ops[1].mem.disp * (-1 if ops[1].subtracted else 1)
                labels.add(v)
                comment[a] = where(v, start, end)
        for a in range(start, end, 4):
            if a in labels and a > start:
                body.append(f"@L{a:08x}:")
            w = word(a)
            r = relocs.get(a)
            if a not in fl.code:
                if r:
                    raise SystemExit("relocation on a data word at 0x%08x" % a)
                c = ""
                if a in jt_of:
                    T = jt_of[a]
                    c = f" // @L{T + (w - (1 << 32) if w & 0x80000000 else w):08x} - @L{T:08x}"
                body.append(f"    dcd 0x{w:08x}{c}")
                continue
            i = text(a)
            op, args = i.mnemonic, i.op_str
            mb = re.match(rf"^(bl?)({asm2mw.CONDS})?$", op)
            if mb and args.startswith("#"):
                tgt = int(args[1:], 0)
                if r and r["kind"] in ("arm_call", "arm_branch"):
                    nm = asm2mw.name_for(repo, cache, asm2mw.reloc_module_name(r["module"]), r["to"])
                    if not nm or nm[1]:
                        raise SystemExit("relocated branch at 0x%08x has no symbol" % a)
                    if nm[0] not in names:
                        externs.add(nm[0])
                    body.append(f"    {op} {nm[0]}")
                    continue
                if not (start <= tgt < end):
                    raise SystemExit("branch at 0x%08x leaves the block without a relocation" % a)
                body.append(f"    {op} @L{tgt:08x}")
                continue
            if r:
                raise SystemExit("unexpected relocation on an instruction at 0x%08x" % a)
            mp = re.match(rf"^(push|pop)({asm2mw.CONDS})?$", op)
            if mp and (w & 0x0fff0fff) in (0x049d0004, 0x052d0004):
                c, reg = mp.group(2) or "", args.strip("{} ")
                line = f"ldr{c} {reg}, [sp], #4" if mp.group(1) == "pop" else f"str{c} {reg}, [sp, #-4]!"
            else:
                line = asm2mw.conv(op, args)
            if a in comment:
                line += " // " + comment[a]
            body.append("    " + line)
        out.append((name, body))
        stats.append((name, start, end, len(fl.code), (end - start) // 4 - len(fl.code)))
        prev = True
        for a in range(start, end, 4):
            if (a in fl.code) != prev:
                prev = a in fl.code
                maplabels.append(f".L_{a:08x} kind:label(arm) addr:0x{a:08x}" if prev
                                 else f".D_{a:08x} kind:label(arm,data) addr:0x{a:08x}")
    lines = [f"void {n}(void);" for n in sorted(externs)] + decls + [""]
    for name, body in out:
        lines.append(f"asm void {name}(void) {{")
        lines.extend(body)
        lines.append("}")
        lines.append("")
    return "\n".join(lines), base, binary, stats, maplabels


def main():
    ap = argparse.ArgumentParser(description=__doc__, formatter_class=argparse.RawDescriptionHelpFormatter)
    ap.add_argument("module")
    ap.add_argument("blocks", nargs="+")
    ap.add_argument("--root", default=os.getcwd())
    ap.add_argument("--version", default="usa")
    ap.add_argument("--verify", action="store_true")
    ap.add_argument("--labels", action="store_true", help="print mapping-symbol labels for symbols.txt")
    a = ap.parse_args()
    repo = asm2mw.Repo(os.path.abspath(a.root), a.version)
    blocks = []
    for b in a.blocks:
        p = b.split(":")
        ents = [int(x, 16) for x in p[4].split(",")] if len(p) > 4 and p[4] else []
        blocks.append((p[0], int(p[1], 16), int(p[2], 16), p[3], ents))
    text, base, binary, stats, maplabels = generate(repo, a.module, blocks)
    if a.labels:
        sys.stderr.write("\n".join(maplabels) + "\n")
    for name, s, e, nc, nd in stats:
        sys.stderr.write(f"{name}: 0x{s:08x}..0x{e:08x}, {nc} instruction words, {nd} data words\n")
    if a.verify:
        with tempfile.TemporaryDirectory() as td:
            secs = asm2mw.sections_of(asm2mw.compile_c(repo, text, td))
        ok = True
        for name, s, e, _, _ in stats:
            data, rel = secs.get(name, (b"", set()))
            want = {x - s for x in repo.relocs(a.module) if s <= x < e}
            orig = binary[s - base:e - base]
            same = len(data) == len(orig) and all(
                data[o:o + 4] == orig[o:o + 4] for o in range(0, len(orig), 4) if o not in want)
            if not same or rel != want:
                ok = False
                sys.stderr.write(f"verify: {name} differs (size {len(data):#x}, {len(rel)} relocations)\n")
        if ok:
            sys.stderr.write("verify: OK\n")
    print(text)


if __name__ == "__main__":
    main()
