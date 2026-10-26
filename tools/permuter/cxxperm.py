#!/usr/bin/env python3
"""Randomized source permuter for C and C++ drafts.

decomp-permuter needs pycparser, which only reads C. This tool works on the source text instead, so
it takes any draft that `tools/match.py` takes (classes, references, member and virtual calls,
templates, `extern "C"`, project headers). It only rewrites the bodies of the functions you name and
leaves everything else alone.

    python3 tools/permuter/cxxperm.py draft.cpp func_ov014_022153e0 --module ov014 --time 900 -j 4

It compiles the draft with the project's MWCC flags, scores it against the base ROM and then runs a
random walk: each step applies one to three random rewrites to the current source, compiles it and
keeps the result if the score did not get worse. Rewrites:

  move     move a statement, block or declaration up or down by 1-3 places in its block
  scope    hoist a block declaration to the top of the function, or sink a function-level one
           into the smallest non-loop block that holds all its uses
  dummy    insert an unused local (`s32 _pN;`), or remove one
  temp     hoist a call argument, assignment right-hand side, `if` operand or parenthesized
           subexpression into a `__typeof__(e) _tN = e;` temporary just before the statement
  inline   put a single-use temporary that this tool made back into its use
  rename   from a function-level `x = e;` on, use a new variable instead of `x`
  arr1     turn a local into a one-element array
  param    turn a scalar or pointer local of the target function into a trailing parameter
  comma    `x = e;` <-> `x = (0, e);`
  comm     swap the operands of a commutative operator (`a + b`, `x == y`, `p & q`, ...)
  split    split `T x = e;` into `T x; x = e;`, or join the two back
  cond     `if (x != 0)` <-> `if (x)`, `if (x == 0)` <-> `if (!x)`
  ifswap   `if (c) {A} else {B}` -> `if (!(c)) {B} else {A}`
  type     change the integer type of a local or a parameter (s32, u16, u8, BOOL, ...)
  incdec   `x++;` <-> `++x;` <-> `x += 1;`, and `x op= e;` <-> `x = x op (e);`

Every rewrite that changes the score for the better is written to the output directory, named by
its score. The score is the number of differing instructions after aligning the two listings
(insertions and deletions count once), plus the same count with registers renamed away, so a
register-only miss scores half as much as a wrong instruction. `blx` counts as `bl`, since the linker
picks it for Thumb callees, and `bl` targets are compared by address (callees the draft can't name by
a symbols.txt symbol are masked), so swapping two calls with the same argument setup is a miss. A result is a match when its listing equals the target's.

Rewrites keep the program's meaning in most cases (moves are refused when they would cross a
use or assignment of a local they touch), but they do not know about memory aliasing or calls with
side effects. Read each result and write the change that matters as normal source.
"""
import argparse
import difflib
import hashlib
import multiprocessing
import os
import random
import re
import shutil
import struct
import subprocess
import sys
import tempfile
import time
from pathlib import Path

import capstone
import yaml
from elftools.elf.elffile import ELFFile

ROOT = Path(__file__).resolve().parent.parent.parent
sys.path.insert(0, str(ROOT / "tools"))

CC_FLAGS = [
    "-O4,p", "-enum", "int", "-char", "signed", "-str", "noreuse", "-proc", "arm946e", "-gccext,on", "-fp", "soft",
    "-inline", "noauto", "-Cpp_exceptions", "off", "-RTTI", "off", "-interworking", "-w", "off", "-sym", "on",
    "-gccinc", "-nolink", "-msgstyle", "gcc", "-i", str(ROOT / "include"),
]

# ---------------------------------------------------------------------------------------------------------------
# Target and scoring


def module_code(version, module):
    extract = ROOT / "extract" / version
    if module == "main":
        config = yaml.safe_load((extract / "arm9" / "arm9.yaml").read_text())
        return (extract / "arm9" / "arm9.bin").read_bytes(), config["base_address"]
    if module in ("itcm", "dtcm"):
        config = yaml.safe_load((extract / "arm9" / f"{module}.yaml").read_text())
        return (extract / "arm9" / f"{module}.bin").read_bytes(), config["base_address"]
    overlay_id = int(module.removeprefix("ov"))
    overlays = yaml.safe_load((extract / "arm9_overlays" / "overlays.yaml").read_text())["overlays"]
    overlay = next(o for o in overlays if o["id"] == overlay_id)
    return (extract / "arm9_overlays" / overlay["file_name"]).read_bytes(), overlay["base_address"]


def symbol_addresses(version, module):
    """Name -> address of every function symbol, the given module's own symbols taking precedence."""
    cfg = ROOT / "config" / version / "arm9"
    own = cfg / "symbols.txt"
    if module in ("itcm", "dtcm"):
        own = cfg / module / "symbols.txt"
    elif module != "main":
        own = cfg / "overlays" / module / "symbols.txt"
    paths = sorted(cfg.glob("**/symbols.txt"))
    paths = [q for q in paths if q != own] + [own]
    out = {}
    for path in paths:
        for line in path.read_text().splitlines():
            m = re.match(r"(\S+) kind:function\([^)]*\) addr:0x([0-9a-f]+)", line)
            if m:
                out[m[1]] = int(m[2], 16) & ~1
    return out


def symbol_size(version, module, func, address):
    cfg = ROOT / "config" / version / "arm9"
    path = cfg / "symbols.txt"
    if module in ("itcm", "dtcm"):
        path = cfg / module / "symbols.txt"
    elif module != "main":
        path = cfg / "overlays" / module / "symbols.txt"
    for line in path.read_text().splitlines():
        m = re.match(r"(\S+) kind:function\([^)]*size=0x([0-9a-f]+)[^)]*\) addr:0x([0-9a-f]+)", line)
        if m and (m[1] == func or int(m[3], 16) == address):
            return int(m[2], 16)
    return None


class Scorer:
    def __init__(self, args, suffix, workdir):
        self.func = args.function
        self.suffix = suffix
        self.workdir = workdir
        self.exe = ROOT / "tools" / "mwccarm" / args.compiler / "mwccarm.exe"
        self.wine = args.wine
        self.lang = "-lang=c++" if suffix == ".cpp" else "-lang=c"
        self.flags = CC_FLAGS + ["-d", args.version]
        code, base = module_code(args.version, args.module)
        self.address = args.address
        size = symbol_size(args.version, args.module, args.function, args.address)
        if size is None:
            sys.exit(f"{args.function} not found in symbols.txt")
        self.target_code = code[self.address - base:self.address - base + size]
        self.md = capstone.Cs(capstone.CS_ARCH_ARM, capstone.CS_MODE_ARM)
        self.src_dir = args.src_dir
        # bl targets are compared by address; callees whose address is unknown are masked (see init_calls)
        self.symaddr = symbol_addresses(args.version, args.module)
        self.masked_calls = set()

    def compile(self, text):
        src = os.path.join(self.workdir, "x" + self.suffix)
        out = os.path.join(self.workdir, "x.o")
        with open(src, "w") as f:
            f.write(text)
        if os.path.exists(out):
            os.remove(out)
        # -gccinc searches the source's own directory first, so also pass the draft's directory
        # tools/fpucw.py gives mwccarm the x87 control word it gets on Windows
        fpucw = [sys.executable, str(ROOT / "tools" / "fpucw.py")] if os.name != "nt" else []
        r = subprocess.run([*fpucw, self.wine, str(self.exe), *self.flags, "-i", self.src_dir, self.lang, "-c", src, "-o", out],
                           capture_output=True, text=True, env=dict(os.environ, TMPDIR=self.workdir))
        if not os.path.exists(out):
            return None, r.stdout + r.stderr
        with open(out, "rb") as f:
            elf = ELFFile(f)
            for sym in elf.get_section_by_name(".symtab").iter_symbols():
                if sym.name == self.func and sym["st_info"]["type"] == "STT_FUNC":
                    start = sym["st_value"] & ~1
                    sec = elf.get_section(sym["st_shndx"])
                    data = sec.data()[start:start + sym["st_size"]]
                    relocated = set()
                    calls = {}
                    symtab = elf.get_section_by_name(".symtab")
                    for rs in elf.iter_sections():
                        if rs.header["sh_type"] in ("SHT_REL", "SHT_RELA") and rs.header["sh_info"] == sym["st_shndx"]:
                            for rel in rs.iter_relocations():
                                o = rel["r_offset"] - start
                                if 0 <= o < len(data) and rel["r_info_type"] == 2:
                                    relocated.add(o)
                                elif 0 <= o < len(data):
                                    calls[o] = self.symaddr.get(symtab.get_symbol(rel["r_info_sym"]).name)
                    return (data, (relocated, calls), line_rows(elf, self.func, "x" + self.suffix)), ""
        return None, f"symbol {self.func} not found"

    def disasm(self, code, relocated, calls=None):
        """calls: offset -> callee address for our code (None: unknown); omitted for the target."""
        lines = []
        off = 0
        while off < len(code):
            if off in relocated:
                lines.append(".word <reloc>")
                off += 4
                continue
            ins = next(self.md.disasm(code[off:off + 4], self.address + off, 1), None)
            if ins is None:
                lines.append(".word %#x" % struct.unpack_from("<I", code, off)[0])
            else:
                t = f"{ins.mnemonic} {ins.op_str}"
                if ins.mnemonic.rstrip("sw.") in ("bl", "blx", "b") and ins.op_str.startswith("#"):
                    # the linker turns bl into blx for Thumb callees
                    t = "bl" if ins.mnemonic == "blx" else ins.mnemonic
                    if t == "bl":
                        if calls is None:
                            dest = int(ins.op_str[1:], 16) & ~1
                            if dest not in self.masked_calls:
                                t = "bl %#x" % dest
                        elif calls.get(off) is not None and calls[off] not in self.masked_calls:
                            t = "bl %#x" % calls[off]
                lines.append(t)
            off += 4
        return lines

    def init_calls(self, text):
        """Masks the bl targets that the draft's own code can't name: callees missing from symbols.txt
        (static helpers, unnamed symbols), paired with the target's calls by a masked alignment of the draft."""
        res, _ = self.compile(text)
        if res is None:
            return
        code, (relocated, calls), _ = res
        ours = self.disasm(code, relocated, calls)
        saved, self.masked_calls = self.masked_calls, set()
        theirs = self.disasm(self.target_code, relocated)
        self.masked_calls = saved
        strip = lambda x: "bl" if x.startswith("bl ") else x
        sm = difflib.SequenceMatcher(None, [strip(x) for x in ours], [strip(x) for x in theirs], autojunk=False)
        for op, i1, i2, j1, j2 in sm.get_opcodes():
            if op == "equal":
                for i, j in zip(range(i1, i2), range(j1, j2)):
                    if ours[i] == "bl" and theirs[j].startswith("bl "):
                        self.masked_calls.add(int(theirs[j][3:], 16))

    def score(self, text):
        """Returns (key, positional diffs, aligned diffs, register-free aligned diffs) or None on a compile error."""
        self.hot = set()
        res, _ = self.compile(text)
        if res is None:
            return None
        code, (relocated, calls), rows = res
        ours = self.disasm(code, relocated, calls)
        theirs = self.disasm(self.target_code, relocated)
        pos = sum(1 for i in range(max(len(ours), len(theirs)))
                  if i >= len(ours) or i >= len(theirs) or ours[i] != theirs[i])
        if pos == 0:
            return (0, 0, 0, 0)
        raw, bad = aligned(ours, theirs)
        rg = re.compile(r"\b(r[0-9]+|sb|sl|fp|ip|lr)\b")
        nr, _ = aligned([rg.sub("R", x) for x in ours], [rg.sub("R", x) for x in theirs])
        # source lines (0-based) of the instructions that differ
        hot = set()
        for i in bad:
            ln = None
            for a, l in rows:
                if a > i * 4:
                    break
                ln = l
            if ln:
                hot.add(ln - 1)
        self.hot = hot
        return (raw + nr, pos, raw, nr)


def aligned(a, b):
    """Aligned diff count, and the indices in a of the instructions that differ."""
    sm = difflib.SequenceMatcher(None, a, b, autojunk=False)
    n = 0
    bad = []
    for op, i1, i2, j1, j2 in sm.get_opcodes():
        if op != "equal":
            n += max(i2 - i1, j2 - j1)
            bad += list(range(i1, i2)) if i2 > i1 else [i1]
    return n, bad


def uleb(b, i):
    v = sh = 0
    while True:
        x = b[i]
        i += 1
        v |= (x & 0x7f) << sh
        sh += 7
        if not x & 0x80:
            return v, i


def sleb(b, i):
    v = sh = 0
    while True:
        x = b[i]
        i += 1
        v |= (x & 0x7f) << sh
        sh += 7
        if not x & 0x80:
            if x & 0x40:
                v -= 1 << sh
            return v, i


def line_rows(elf, func, filename):
    """(offset in func, line) rows of func's DWARF 2 line program, for lines in filename. Empty if unavailable."""
    try:
        symtab = elf.get_section_by_name(".symtab")
        for idx in range(elf.num_sections()):
            sec = elf.get_section(idx)
            if sec.name == ".debug_line" and sec.header.sh_size:
                break
        else:
            return []
        b = sec.data()
        relocs = []
        for rs in elf.iter_sections():
            if rs.header["sh_type"] in ("SHT_REL", "SHT_RELA") and rs.header["sh_info"] == idx:
                relocs = sorted((r["r_offset"], symtab.get_symbol(r["r_info_sym"]).name) for r in rs.iter_relocations())
        relname = dict(relocs)
        rows = []
        pos = 0
        while pos < len(b):
            unit_len = struct.unpack_from("<I", b, pos)[0]
            end = pos + 4 + unit_len
            hlen = struct.unpack_from("<I", b, pos + 6)[0]
            prog = pos + 10 + hlen
            min_inst, _, line_base, line_range, op_base = struct.unpack_from("<BBbBB", b, pos + 10)
            lens = b[pos + 15:pos + 15 + op_base - 1]
            i = pos + 15 + op_base - 1
            while b[i]:
                i = b.index(0, i) + 1
            i += 1
            files = []
            while b[i]:
                j = b.index(0, i)
                files.append(b[i:j].decode("latin-1"))
                i = j + 1
                for _ in range(3):
                    _, i = uleb(b, i)
            want = {k + 1 for k, f in enumerate(files) if re.split(r"[\\/]", f)[-1] == filename}
            i = prog
            addr, line, fileno, cur = 0, 1, 1, None
            while i < end:
                op = b[i]
                i += 1
                if op >= op_base:
                    adj = op - op_base
                    addr += (adj // line_range) * min_inst
                    line += line_base + adj % line_range
                    if cur == func and fileno in want:
                        rows.append((addr, line))
                elif op == 0:
                    n, i = uleb(b, i)
                    sub = b[i]
                    if sub == 1:
                        addr, line, fileno, cur = 0, 1, 1, None
                    elif sub == 2:
                        cur = relname.get(i + 1)
                        addr = struct.unpack_from("<I", b, i + 1)[0]
                    i += n
                elif op == 1:
                    if cur == func and fileno in want:
                        rows.append((addr, line))
                elif op == 2:
                    v, i = uleb(b, i)
                    addr += v * min_inst
                elif op == 3:
                    v, i = sleb(b, i)
                    line += v
                elif op == 4:
                    fileno, i = uleb(b, i)
                elif op == 8:
                    addr += ((255 - op_base) // line_range) * min_inst
                elif op == 9:
                    addr += struct.unpack_from("<H", b, i)[0]
                    i += 2
                else:
                    for _ in range(lens[op - 1]):
                        _, i = uleb(b, i)
            pos = end
        return sorted(rows)
    except Exception:
        return []


# ---------------------------------------------------------------------------------------------------------------
# Source structure (line based: one statement per line, as the project's drafts are written)

STRIP = re.compile(r'"(?:\\.|[^"\\])*"|\'(?:\\.|[^\'\\])*\'|//.*|/\*.*?\*/')
BARRIER = re.compile(r"^\s*(case\b|default\s*:|[A-Za-z_]\w*\s*:(?!:)|break\s*;|return\b|goto\b|continue\s*;|#)")
KEYWORDS = {"return", "goto", "break", "continue", "else", "case", "delete", "throw", "do", "if", "while", "for",
            "switch", "sizeof", "new", "default"}
DECL = re.compile(r"^\s*(?:(?:const|volatile|unsigned|signed|struct|class|union|enum|static|register)\s+)*"
                  r"([A-Za-z_][\w:]*(?:<[^;=()]*>)?)\s*[\s\*&]\s*\**\s*([A-Za-z_]\w*)\s*(\[[^\]]*\])?\s*(=.*)?;\s*$")
IDENT = re.compile(r"[A-Za-z_]\w*")


def code_of(line):
    return STRIP.sub("", line)


def depth_delta(line):
    c = code_of(line)
    return c.count("{") - c.count("}")


def decl_name(line):
    m = DECL.match(code_of(line))
    if not m or m[1] in KEYWORDS or m[2] in KEYWORDS:
        return None
    return m[2]


def func_bodies(lines, names):
    """(open_line, close_line) for each function whose name is in names; the body is lines open+1..close-1."""
    out = []
    i = 0
    while i < len(lines):
        l = lines[i]
        if l and not l[0].isspace() and l.rstrip().endswith("{") and not l.lstrip().startswith(("extern", "struct", "class", "namespace", "union", "enum")):
            m = re.search(r"([A-Za-z_][\w:~]*)\s*\(", code_of(l))
            if m and (m[1] in names or m[1].split("::")[-1] in names):
                d = 0
                j = i
                while True:
                    d += depth_delta(lines[j])
                    if d <= 0 and j > i:
                        break
                    j += 1
                out.append((i, j))
                i = j + 1
                continue
        i += 1
    return out


def join_brace_lines(text):
    """Puts a definition's `{` on its own line back onto the head line, as func_bodies expects."""
    lines = text.split("\n")
    out = []
    for l in lines:
        if l.strip() == "{" and out and out[-1] and not out[-1][0].isspace() and ")" in out[-1] \
                and not out[-1].rstrip().endswith((";", "{", "}", ",")) and not out[-1].startswith("#"):
            out[-1] = out[-1].rstrip() + " {"
            continue
        out.append(l)
    return "\n".join(out)


def inline_names(lines):
    names = set()
    for l in lines:
        if l.startswith("static inline") and l.rstrip().endswith("{"):
            m = re.search(r"([A-Za-z_]\w*)\s*\(", l)
            if m:
                names.add(m[1])
    return names


def blocks(lines, lo, hi):
    """Every brace block inside lines[lo:hi], as (first body line, closing line)."""
    out = [(lo, hi)]
    st = []
    for i in range(lo, hi):
        for ch in code_of(lines[i]):
            if ch == "{":
                st.append(i + 1)
            elif ch == "}" and st:
                out.append((st.pop(), i))
    return out


def units(lines, lo, hi):
    """Statement units directly inside lines[lo:hi]: one line, a multi-line statement, or a compound statement
    with its else arms. Returns (start, end) pairs, end exclusive."""
    us = []
    i = lo
    while i < hi:
        s = lines[i].strip()
        if not s or s.startswith("}") or s.startswith("//"):
            i += 1
            continue
        j = i
        d = 0
        while j < hi:
            d += depth_delta(lines[j])
            j += 1
            if d <= 0:
                c = code_of(lines[j - 1]).rstrip()
                if d == 0 and not c.endswith((";", "}", "{", ":")) and j < hi:
                    continue  # statement continues on the next line
                if d == 0 and j < hi and lines[j].strip().startswith("else"):
                    continue
                break
        us.append((i, j))
        i = j
    return us


def idents(text):
    return set(IDENT.findall(code_of(text)))


ASSIGN = re.compile(r"(?<![=!<>.>])\b([A-Za-z_]\w*)\s*(?:\[[^\]]*\]\s*)*(?:[-+*/%&|^]|<<|>>)?=(?!=)"
                    r"|\b([A-Za-z_]\w*)\s*(?:\[[^\]]*\]\s*)*(?:\+\+|--)|(?:\+\+|--)\s*([A-Za-z_]\w*)")


# `&x` hands x to code that may write it (a call, or a pointer that is written through later)
# (unary when it follows an operator, a bracket or a cast; `(a) & b` also counts, which only blocks a move)
ADDR = re.compile(r"(?:^|[^&\w\]\s.]|\breturn)\s*&\s*([A-Za-z_]\w*)")


def writes(text):
    t = code_of(text)
    return {a or b or c for a, b, c in ASSIGN.findall(t)} | set(ADDR.findall(t))


# ---------------------------------------------------------------------------------------------------------------
# Rewrites. Each takes (lines, regions, rng, state) and returns new lines or None.


def all_blocks(lines, regions):
    out = []
    for o, c in regions:
        out += blocks(lines, o + 1, c)
    return out


def m_move(lines, regions, rng, st):
    bl = all_blocks(lines, regions)
    rng.shuffle(bl)
    for lo, hi in bl[:6]:
        us = units(lines, lo, hi)
        segs = [[]]
        for u in us:
            if BARRIER.match(lines[u[0]]):
                segs.append([])
            else:
                segs[-1].append(u)
        segs = [s for s in segs if len(s) >= 2]
        if not segs:
            continue
        seg = rng.choice(segs)
        a = rng.randrange(len(seg))
        k = rng.choice([1, 1, 1, 2, 2, 3])
        b = max(0, min(len(seg) - 1, a + rng.choice([-k, k])))
        if a == b:
            continue
        u = seg[a]
        ut = "\n".join(lines[u[0]:u[1]])
        un = decl_name(lines[u[0]]) if u[1] - u[0] == 1 else None
        uids = idents(ut)
        uw = writes(ut)
        crossed = seg[b:a] if b < a else seg[a + 1:b + 1]
        ok = True
        for v in crossed:
            vt = "\n".join(lines[v[0]:v[1]])
            vn = decl_name(lines[v[0]]) if v[1] - v[0] == 1 else None
            vids = idents(vt)
            if un and un in vids or vn and vn in uids:
                ok = False
                break
            vw = writes(vt)
            # keep the order of reads and writes of plain identifiers (locals, parameters)
            if (uw & vids) or (vw & uids):
                ok = False
                break
        if not ok:
            continue
        order = list(range(len(seg)))
        x = order.pop(a)
        order.insert(b, x)
        chunks = [lines[seg[i][0]:seg[i][1]] for i in order]
        # lines between units (blank lines, comments) stay where they are
        new = lines[:seg[0][0]]
        pos = seg[0][0]
        for idx, (s, e) in enumerate(seg):
            new += lines[pos:s]
            new += chunks[idx]
            pos = e
        new += lines[pos:]
        return new
    return None


def indent_of(line):
    return line[:len(line) - len(line.lstrip())]


def m_dummy(lines, regions, rng, st):
    dummies = [i for o, c in regions for i in range(o + 1, c) if re.match(r"\s*s32 _p\d+;\s*$", lines[i])]
    if dummies and rng.random() < 0.3:
        i = rng.choice(dummies)
        return lines[:i] + lines[i + 1:]
    bl = all_blocks(lines, regions)
    lo, hi = rng.choice(bl)
    us = [u for u in units(lines, lo, hi)]
    cands = [lo] + [u[1] for u in us if not BARRIER.match(lines[u[0]])]
    at = rng.choice(cands)
    if at >= len(lines):
        return None
    ref = lines[at] if at < hi and lines[at].strip() and not lines[at].strip().startswith("}") else (lines[us[0][0]] if us else "    ")
    st["n"] += 1
    return lines[:at] + [indent_of(ref) + "s32 _p%d;" % st["n"]] + lines[at:]


def split_top(s, sep=","):
    """Split s at top-level separators, returning (start, end) spans."""
    spans = []
    d = 0
    start = 0
    i = 0
    while i < len(s):
        ch = s[i]
        if ch in "([{":
            d += 1
        elif ch in ")]}":
            d -= 1
        elif ch in "\"'":
            q = ch
            i += 1
            while i < len(s) and s[i] != q:
                i += 2 if s[i] == "\\" else 1
        elif ch == sep and d == 0:
            spans.append((start, i))
            start = i + 1
        i += 1
    spans.append((start, len(s)))
    return spans


def close_paren(s, i):
    d = 0
    while i < len(s):
        if s[i] == "(":
            d += 1
        elif s[i] == ")":
            d -= 1
            if d == 0:
                return i
        elif s[i] in "\"'":
            q = s[i]
            i += 1
            while i < len(s) and s[i] != q:
                i += 2 if s[i] == "\\" else 1
        i += 1
    return -1


TRIVIAL = re.compile(r"^\s*(-?(0x[0-9a-fA-F]+|\d+)[uUlL]*|[A-Za-z_]\w*|NULL|TRUE|FALSE)\s*$")
NOT_CALLS = {"if", "while", "for", "switch", "return", "sizeof", "__typeof__", "FLD", "FIELD", "LFLD"}


def expr_candidates(line):
    """Spans (start, end) in line of subexpressions that can be evaluated just before the statement."""
    c = line
    if "//" in c or "/*" in c or '"' in c:
        return []
    s = c.strip()
    if not s.endswith((";", "{")) or s.startswith(("for", "while", "do", "}", "case", "default", "else")):
        return []
    if s.endswith("{") and not s.startswith(("if", "switch")):
        return []
    if decl_name(c) and "=" not in c:
        return []
    cands = []
    # call arguments
    for m in re.finditer(r"([A-Za-z_]\w*)\s*\(", c):
        if m[1] in NOT_CALLS or m[1] in KEYWORDS:
            continue
        o = m.end() - 1
        e = close_paren(c, o)
        if e < 0:
            continue
        inner = c[o + 1:e]
        if not inner.strip():
            continue
        for a, b in split_top(inner):
            if not TRIVIAL.match(inner[a:b]):
                lead = len(inner[a:b]) - len(inner[a:b].lstrip())
                tail = len(inner[a:b].rstrip())
                cands.append((o + 1 + a + lead, o + 1 + a + tail))
    # any other parenthesized subexpression that is not a cast, a call or a condition
    for o in range(len(c)):
        if c[o] != "(":
            continue
        before = c[:o].rstrip()
        if before.endswith(("if", "switch", "while", "for", "sizeof", "__typeof__")) or (before and (before[-1].isalnum() or before[-1] in "_)]")):
            continue
        e = close_paren(c, o)
        if e < 0:
            continue
        inner = c[o + 1:e]
        if TRIVIAL.match(inner) or re.match(r"^\s*(const\s+|unsigned\s+|signed\s+|struct\s+)*[A-Za-z_][\w:]*\s*\**\s*$", inner):
            continue
        if "?" in inner or "&&" in inner or "||" in inner:
            continue
        cands.append((o + 1, e))
    # right-hand side of an assignment statement
    m = re.match(r"^(\s*)([^=;{}]*?[^=!<>+\-*/%&|^])\s*([-+*/%&|^]|<<|>>)?=(?!=)\s*(.*?);\s*$", c)
    if m and not decl_name(c) and not TRIVIAL.match(m[4]):
        cands.append((m.start(4), m.end(4)))
    # operands of the condition of an if
    m = re.match(r"^\s*(if|switch)\s*\(", c)
    if m:
        o = m.end() - 1
        e = close_paren(c, o)
        if e > 0:
            inner = c[o + 1:e]
            if not TRIVIAL.match(inner) and "&&" not in inner and "||" not in inner:
                cands.append((o + 1, e))
                mm = re.match(r"^(.*?)\s*(==|!=|<=|>=|<|>)\s*(.*)$", inner)
                if mm and mm[1].count("(") == mm[1].count(")"):
                    for g in (1, 3):
                        if not TRIVIAL.match(mm[g]):
                            cands.append((o + 1 + mm.start(g), o + 1 + mm.end(g)))
    return cands


def body_lines(lines, regions):
    return [i for o, c in regions for i in range(o + 1, c)]


def m_temp(lines, regions, rng, st):
    idx = body_lines(lines, regions)
    rng.shuffle(idx)
    for i in idx[:40]:
        cs = expr_candidates(lines[i])
        if not cs:
            continue
        a, b = rng.choice(cs)
        e = lines[i][a:b].strip()
        if not e or "=" in re.sub(r"[=!<>]=", "", e):
            continue
        st["n"] += 1
        t = "_t%d" % st["n"]
        decl = indent_of(lines[i]) + "__typeof__(%s) %s = %s;" % (e, t, e)
        new_line = lines[i][:a] + t + lines[i][b:]
        return lines[:i] + [decl, new_line] + lines[i + 1:]
    return None


def m_inline(lines, regions, rng, st):
    idx = [i for i in body_lines(lines, regions) if re.match(r"\s*__typeof__\(.*\) _t\d+ = .*;\s*$", lines[i])]
    if not idx:
        return None
    i = rng.choice(idx)
    m = re.match(r"\s*__typeof__\((.*)\) (_t\d+) = (.*);\s*$", lines[i])
    t, e = m[2], m[3]
    uses = [j for j in body_lines(lines, regions) if j != i and re.search(r"\b%s\b" % t, lines[j])]
    if len(uses) != 1:
        return None
    j = uses[0]
    new = list(lines)
    new[j] = re.sub(r"\b%s\b" % t, lambda _: "(" + e + ")" if not TRIVIAL.match(e) and not re.match(r"^[\w\->.\[\]]+$", e) else e, new[j], count=1)
    del new[i]
    return new


OPERAND = r"([A-Za-z_][\w]*(?:(?:->|\.)\w+|\[[^\[\]]*\])*|-?0x[0-9a-fA-F]+|-?\d+)"
COMM = re.compile(r"(?<=[(,=]\s)" + OPERAND + r" (\+|\*|&|\||\^|==|!=) " + OPERAND + r"(?=\s*[),;])"
                  r"|(?<=[(,])" + OPERAND + r" (\+|\*|&|\||\^|==|!=) " + OPERAND + r"(?=\s*[),;])")


def m_comm(lines, regions, rng, st):
    idx = body_lines(lines, regions)
    hits = []
    for i in idx:
        if "//" in lines[i] or '"' in lines[i]:
            continue
        for m in COMM.finditer(lines[i]):
            hits.append((i, m))
    if not hits:
        return None
    i, m = rng.choice(hits)
    g = m.groups()
    x, op, y = (g[0], g[1], g[2]) if g[0] else (g[3], g[4], g[5])
    new = list(lines)
    new[i] = lines[i][:m.start()] + "%s %s %s" % (y, op, x) + lines[i][m.end():]
    return new


def m_split(lines, regions, rng, st):
    idx = body_lines(lines, regions)
    rng.shuffle(idx)
    for i in idx:
        l = lines[i]
        n = decl_name(l)
        if not n:
            continue
        m = DECL.match(l)
        if m[4] and not m[3] and "{" not in m[4] and rng.random() < 0.6:
            head = l[:l.index("=")].rstrip()
            return lines[:i] + [head + ";", indent_of(l) + "%s %s;" % (n, m[4].rstrip())] + lines[i + 1:]
        if not m[4] and i + 1 < len(lines):
            mm = re.match(r"^\s*%s = (.*);\s*$" % re.escape(n), lines[i + 1])
            if mm and n not in idents(mm[1]):
                return lines[:i] + [l.rstrip()[:-1].rstrip() + " = %s;" % mm[1]] + lines[i + 2:]
    return None


def m_cond(lines, regions, rng, st):
    idx = body_lines(lines, regions)
    rng.shuffle(idx)
    for i in idx:
        l = lines[i]
        m = re.match(r"^(\s*(?:\} else )?if \()(.*)(\) \{\s*)$", l)
        if not m:
            continue
        c = m[2]
        if "&&" in c or "||" in c or "?" in c:
            continue
        for pat, rep in ((r"^(.+) != 0$", r"\1"), (r"^(.+) == 0$", r"!(\1)"), (r"^!\((.+)\)$", r"\1 == 0"),
                         (r"^!([\w\->.\[\]]+)$", r"\1 == 0"), (r"^([\w\->.\[\]]+)$", r"\1 != 0"),
                         (r"^(.+) != NULL$", r"\1"), (r"^(.+) == NULL$", r"!(\1)")):
            if re.match(pat, c) and (pat != r"^(.+) != 0$" or c.count("(") == c.count(")")):
                nc = re.sub(pat, rep, c)
                if nc.count("(") != nc.count(")"):
                    continue
                return lines[:i] + [m[1] + nc + m[3]] + lines[i + 1:]
    return None


def m_ifswap(lines, regions, rng, st):
    idx = body_lines(lines, regions)
    rng.shuffle(idx)
    for i in idx:
        m = re.match(r"^(\s*)if \((.*)\) \{\s*$", lines[i])
        if not m or (i > 0 and lines[i - 1].rstrip().endswith("else")):
            continue
        d = 0
        j = i
        mid = None
        while j < len(lines):
            d += depth_delta(lines[j])
            if d == 1 and j > i and re.match(r"^\s*\} else \{\s*$", lines[j]):
                if mid is not None:
                    break
                mid = j
            if d == 0:
                break
            j += 1
        if mid is None or d != 0 or not re.match(r"^\s*\}\s*$", lines[j]):
            continue
        c = m[2]
        mm = re.match(r"^!\((.*)\)$", c)
        nc = mm[1] if mm and mm[1].count("(") == mm[1].count(")") else "!(" + c + ")"
        return lines[:i] + [m[1] + "if (%s) {" % nc] + lines[mid + 1:j] + [lines[mid]] + lines[i + 1:mid] + lines[j:]
    return None


def local_decls(lines, o, c):
    """Declarations without initializer in a body: (line, name, depth) with depth 0 = function level."""
    out = []
    d = 0
    for i in range(o + 1, c):
        if d == 0 or True:
            n = decl_name(lines[i])
            if n and "=" not in code_of(lines[i]) and "[" not in code_of(lines[i]):
                out.append((i, n, d))
        d += depth_delta(lines[i])
    return out


def uses_of(lines, o, c, name, skip):
    pat = re.compile(r"(?<![\w.>])%s\b" % re.escape(name))
    return [i for i in range(o + 1, c) if i != skip and pat.search(code_of(lines[i]))]


def m_comma(lines, regions, rng, st):
    idx = body_lines(lines, regions)
    rng.shuffle(idx)
    for i in idx:
        l = lines[i]
        m = re.match(r"^(\s*(?:[\w:<>]+\s*[\s\*]+)?[A-Za-z_]\w*) = \(0, (.*)\);\s*$", l)
        if m:
            return lines[:i] + [m[1] + " = " + m[2] + ";"] + lines[i + 1:]
        m = re.match(r"^(\s*(?:[\w:<>]+\s*[\s\*]+)?[A-Za-z_]\w*) = (.*);\s*$", l)
        if m and "//" not in l and not m[1].strip().startswith(("return", "case")) and "{" not in m[2] \
                and not TRIVIAL.match(m[2]):
            return lines[:i] + [m[1] + " = (0, " + m[2] + ");"] + lines[i + 1:]
    return None


def m_arr1(lines, regions, rng, st):
    o, c = rng.choice(regions)
    ds = [(i, n) for i, n, d in local_decls(lines, o, c)]
    if not ds:
        return None
    i, n = rng.choice(ds)
    pat = re.compile(r"(?<![\w.>])%s\b(?!\s*\()" % re.escape(n))
    new = list(lines)
    new[i] = re.sub(r"\b%s\s*;" % re.escape(n), n + "[1];", lines[i], count=1)
    for j in uses_of(lines, o, c, n, i):
        if '"' in lines[j]:
            return None
        new[j] = pat.sub(n + "[0]", lines[j])
    return new


def m_scope(lines, regions, rng, st):
    o, c = rng.choice(regions)
    ds = local_decls(lines, o, c)
    names = [n for _, n, _ in ds]
    ds = [x for x in ds if names.count(x[1]) == 1]
    if not ds:
        return None
    i, n, d = rng.choice(ds)
    if d > 0:
        # hoist to the end of the function's leading declarations
        at = o + 1
        while at < c and (decl_name(lines[at]) or not lines[at].strip()):
            at += 1
        if at > i:
            return None
        line = indent_of(lines[o + 1]) + lines[i].strip()
        return lines[:at] + [line] + lines[at:i] + lines[i + 1:]
    us = uses_of(lines, o, c, n, i)
    if not us:
        return None
    best = None
    for lo, hi in blocks(lines, o + 1, c)[1:]:
        if lo <= min(us) and max(us) < hi and lo > i:
            opener = code_of(lines[lo - 1])
            if re.search(r"\b(for|while|do)\b", opener):
                continue
            if best is None or hi - lo < best[1] - best[0]:
                best = (lo, hi)
    if best is None:
        return None
    lo = best[0]
    ref = next((lines[k] for k in range(lo, best[1]) if lines[k].strip() and not BARRIER.match(lines[k])), lines[lo])
    line = indent_of(ref) + lines[i].strip()
    return lines[:i] + lines[i + 1:lo] + [line] + lines[lo:]


def m_param(lines, regions, rng, st):
    # the target function only: it has C linkage, so its callers don't see the extra parameter
    tgt = [r for r in regions if re.search(r"\b%s\s*\(" % re.escape(st["func"]), lines[r[0]])]
    if not tgt:
        return None
    o, c = tgt[0]
    ds = [(i, n) for i, n, d in local_decls(lines, o, c)
          if d == 0 and ("*" in lines[i] or re.match(r"\s*(unsigned |signed )?(s8|u8|s16|u16|s32|u32|int|BOOL|bool|char|short|long|fx32|fx16)\b", lines[i]))]
    if not ds:
        return None
    i, n = rng.choice(ds)
    head = lines[o]
    k = head.rfind(")")
    if k < 0 or "..." in head:
        return None
    decl = lines[i].strip()[:-1].strip()
    if re.search(r"\(\s*(void)?\s*\)", head[:k + 1]):
        nh = head[:head.rfind("(", 0, k) + 1] + decl + head[k:]
    else:
        nh = head[:k] + ", " + decl + head[k:]
    new = list(lines)
    new[o] = nh
    del new[i]
    return new


def m_rename(lines, regions, rng, st):
    """Give a local's value from one function-level assignment onwards a new variable."""
    o, c = rng.choice(regions)
    d = 0
    cands = []
    for i in range(o + 1, c):
        if d == 0:
            m = re.match(r"^\s*([A-Za-z_]\w*) = (.*);\s*$", lines[i])
            if m:
                cands.append((i, m[1]))
        d += depth_delta(lines[i])
    rng.shuffle(cands)
    for i, n in cands:
        decl = [j for j in range(o + 1, c) if decl_name(lines[j]) == n]
        if len(decl) != 1 or decl[0] > i:
            continue
        dm = DECL.match(code_of(lines[decl[0]]))
        if dm[3]:
            continue
        typ = code_of(lines[decl[0]]).strip()
        typ = typ[:typ.index(n, len(typ) - len(typ.lstrip()) + len(dm[1]))].strip()
        if typ.startswith("static"):
            continue
        st["n"] += 1
        nn = "%s_%d" % (n, st["n"])
        pat = re.compile(r"(?<![\w.>])%s\b" % re.escape(n))
        new = list(lines)
        new[i] = indent_of(lines[i]) + "%s %s = %s;" % (typ, nn, re.match(r"^\s*\w+ = (.*);\s*$", lines[i])[1])
        for j in range(i + 1, c):
            new[j] = pat.sub(nn, lines[j])
        if new[i + 1:c] == lines[i + 1:c]:
            continue
        return new
    return None


INT_TYPES = ["s32", "u32", "int", "s16", "u16", "s8", "u8", "BOOL", "long", "unsigned int", "unsigned short",
             "short", "unsigned char", "char", "fx32"]
TYPE_DECL = re.compile(r"^(\s*(?:const\s+|volatile\s+|register\s+)*)(unsigned int|unsigned short|unsigned char|"
                       r"s32|u32|int|s16|u16|s8|u8|BOOL|long|short|char|fx32)(\s+\**\s*[A-Za-z_]\w*\s*(?:\[[^\]]*\])?\s*(?:=.*)?;\s*)$")


def m_type(lines, regions, rng, st):
    """Change the integer type of a local or of a parameter of the rewritten functions."""
    cands = []
    for o, c in regions:
        for i in range(o + 1, c):
            if TYPE_DECL.match(lines[i]):
                cands.append((i, None))
        # parameters on the definition's line(s), as `type name` between the parentheses
        j = o
        while j > 0 and "(" not in lines[j]:
            j -= 1
        cands.append((j, "param"))
    rng.shuffle(cands)
    for i, kind in cands[:8]:
        l = lines[i]
        if kind is None:
            m = TYPE_DECL.match(l)
            t = rng.choice([x for x in INT_TYPES if x != m[2]])
            return lines[:i] + [m[1] + t + m[3]] + lines[i + 1:]
        lp = l.find("(")
        if lp < 0:
            continue
        hits = [mm for mm in re.finditer(r"(?<=[(,])(\s*(?:const\s+)?)(unsigned int|unsigned short|unsigned char|s32|u32|int|"
                                         r"s16|u16|s8|u8|BOOL|long|short|char|fx32)(\s+[A-Za-z_]\w*\s*)(?=[,)])", l[lp:])]
        if not hits:
            continue
        mm = rng.choice(hits)
        t = rng.choice([x for x in INT_TYPES if x != mm[2]])
        a, b = lp + mm.start(2), lp + mm.end(2)
        return lines[:i] + [l[:a] + t + l[b:]] + lines[i + 1:]
    return None


INCDEC = re.compile(r"^(\s*)(?:(\+\+|--)\s*([A-Za-z_][\w.\->\[\]]*)|([A-Za-z_][\w.\->\[\]]*)\s*(\+\+|--)|"
                    r"([A-Za-z_][\w.\->\[\]]*)\s*([-+*/%&|^]|<<|>>)=\s*(.+?)|([A-Za-z_][\w.\->\[\]]*)\s*=\s*(.+?))\s*;\s*$")


def m_incdec(lines, regions, rng, st):
    """`x++;` <-> `++x;` <-> `x += 1;`, and `x op= e;` <-> `x = x op (e);` for statement-level updates."""
    idx = body_lines(lines, regions)
    rng.shuffle(idx)
    for i in idx:
        l = lines[i]
        m = INCDEC.match(code_of(l))
        if not m or l.rstrip() != code_of(l).rstrip():
            continue
        ind = m[1]
        if m[2] or m[5]:
            x, op = (m[3], m[2]) if m[2] else (m[4], m[5])
            forms = ["%s%s;" % (op, x), "%s%s;" % (x, op), "%s %s= 1;" % (x, op[0]), "%s = %s %s 1;" % (x, x, op[0])]
        elif m[6]:
            x, op, e = m[6], m[7], m[8]
            forms = ["%s = %s %s (%s);" % (x, x, op, e)]
            if e.strip() == "1" and op in "+-":
                forms += ["%s%s;" % (x, op * 2), "%s%s;" % (op * 2, x)]
        else:
            x, e = m[9], m[10]
            mm = re.match(r"^%s\s*([-+*/%%&|^]|<<|>>)\s*\((.*)\)$|^%s\s*([-+*/%%&|^]|<<|>>)\s*([\w.]+)$"
                          % (re.escape(x), re.escape(x)), e.strip())
            if not mm:
                continue
            op, rhs = (mm[1], mm[2]) if mm[1] else (mm[3], mm[4])
            forms = ["%s %s= %s;" % (x, op, rhs)]
        cur = l.strip()
        forms = [f for f in forms if f != cur]
        if not forms:
            continue
        return lines[:i] + [ind + rng.choice(forms)] + lines[i + 1:]
    return None


REWRITES = {"move": (m_move, 6), "dummy": (m_dummy, 2), "temp": (m_temp, 2), "inline": (m_inline, 1),
            "comm": (m_comm, 1), "split": (m_split, 1), "cond": (m_cond, 1), "ifswap": (m_ifswap, 1),
            "comma": (m_comma, 1), "arr1": (m_arr1, 1), "scope": (m_scope, 2), "param": (m_param, 1),
            "rename": (m_rename, 1), "type": (m_type, 1), "incdec": (m_incdec, 1)}


def mutate(text, names, rng, st, kinds):
    lines = text.split("\n")
    regions = func_bodies(lines, names)
    if not regions:
        return None
    total = sum(REWRITES[k][1] for k in kinds)
    r = rng.uniform(0, total)
    for k in kinds:
        r -= REWRITES[k][1]
        if r <= 0:
            break
    new = REWRITES[k][0](lines, regions, rng, st)
    if new is None or new == lines:
        return None
    return "\n".join(new)


def changed_span(a, b):
    """First and last line index of a that differs from b."""
    la, lb = a.split("\n"), b.split("\n")
    i = 0
    while i < min(len(la), len(lb)) and la[i] == lb[i]:
        i += 1
    j = 0
    while j < min(len(la), len(lb)) - i and la[-1 - j] == lb[-1 - j]:
        j += 1
    return i, len(la) - 1 - j


def mutate_near(text, names, rng, st, kinds, hot, width):
    """A rewrite that touches a line within width lines of a hot line, or None after 40 tries."""
    for _ in range(40):
        new = mutate(text, names, rng, st, kinds)
        if new is None:
            continue
        a, b = changed_span(text, new)
        if any(a - width <= h <= b + width for h in hot):
            return new
    return None


# ---------------------------------------------------------------------------------------------------------------
# Search


def fmt(s):
    return "score %d (aligned %d, without registers %d, positional %d)" % (s[0], s[2], s[3], s[1])


def worker(wid, args, base, base_score, names, deadline, outdir, suffix, stop, lock, best_val, counts):
    rng = random.Random(args.seed * 1000 + wid if args.seed is not None else None)
    workdir = tempfile.mkdtemp(prefix="cxxperm%d_" % wid, dir=args.tmpdir)
    scorer = Scorer(args, suffix, workdir)
    scorer.init_calls(base)
    st = {"n": 1000 * (wid + 1), "func": args.function}
    cur, cur_s = base, base_score
    best, best_s = base, base_score
    scorer.score(base)
    cur_hot = best_hot = scorer.hot
    seen = set()
    tries = 0
    try:
        while time.time() < deadline and not stop.is_set():
            if rng.random() < 0.02:
                cur, cur_s, cur_hot = best, best_s, best_hot
            cand = cur
            for _ in range(rng.choice([1, 1, 1, 2, 2, 3])):
                if cur_hot and rng.random() < args.focus:
                    c2 = mutate_near(cand, names, rng, st, args.rewrites, cur_hot, 3)
                else:
                    c2 = mutate(cand, names, rng, st, args.rewrites)
                if c2:
                    cand = c2
            if cand == cur:
                continue
            h = hashlib.md5(cand.encode()).digest()
            if h in seen:
                continue
            seen.add(h)
            s = scorer.score(cand)
            tries += 1
            with counts.get_lock():
                counts[0] += 1
                counts[1] += s is None
            if s is None:
                continue
            if s[0] < best_s[0] or s[0] == 0:
                best, best_s, best_hot = cand, s, scorer.hot
                with lock:
                    if s[0] < best_val.value or s[0] == 0:
                        best_val.value = s[0]
                        path = os.path.join(outdir, "out-%03d-%d-%d%s" % (s[0], wid, tries, suffix))
                        with open(path, "w") as f:
                            f.write(cand)
                        print("[%d] %s -> %s" % (wid, fmt(s), path), flush=True)
                if s[1] == 0 and args.stop_on_zero:
                    stop.set()
            if s[0] < cur_s[0] or s[0] == cur_s[0] or (s[0] <= cur_s[0] + args.slack and rng.random() < 0.05):
                cur, cur_s, cur_hot = cand, s, scorer.hot
    finally:
        shutil.rmtree(workdir, ignore_errors=True)
    return tries


def main():
    p = argparse.ArgumentParser(description=__doc__.split("\n")[0], epilog=__doc__, formatter_class=argparse.RawDescriptionHelpFormatter)
    p.add_argument("source", type=Path)
    p.add_argument("function")
    p.add_argument("--module", default="main", help="main, itcm, dtcm or ovNNN")
    p.add_argument("--address", type=lambda x: int(x, 16), help="default: taken from the name")
    p.add_argument("--version", default="usa")
    p.add_argument("--compiler", default=None, help="default: dsi/1.3, or the file's entry in mwcc_versions.py")
    p.add_argument("--wine", default=str(ROOT / "wibo"))
    p.add_argument("--funcs", default="", help="comma-separated extra functions whose bodies may be rewritten")
    p.add_argument("--inlines", action="store_true", help="also rewrite every `static inline` function in the file")
    p.add_argument("--rewrites", default=",".join(REWRITES), help="comma-separated rewrites to use (default: all)")
    p.add_argument("--time", type=float, default=600, help="seconds to run (default 600)")
    p.add_argument("-j", "--jobs", type=int, default=1)
    p.add_argument("-o", "--out", type=Path, help="output directory (default: build/cxxperm/<function>)")
    p.add_argument("--seed", type=int)
    p.add_argument("--slack", type=int, default=0, help="sometimes accept results this much worse (default 0)")
    p.add_argument("--focus", type=float, default=0.8,
                   help="share of rewrites made near the source lines of differing instructions (default 0.8)")
    p.add_argument("--stop-on-zero", action="store_true", help="stop when a result matches")
    p.add_argument("--score-only", action="store_true", help="print the draft's score and exit")
    args = p.parse_args()
    if args.address is None:
        args.address = int(args.function.rsplit("_", 1)[-1], 16)
    if args.compiler is None:
        from mwcc_versions import FILE_MWCC_VERSIONS
        try:
            rel = Path(os.path.relpath(args.source.resolve(), ROOT)).as_posix()
        except ValueError:
            rel = None
        args.compiler = FILE_MWCC_VERSIONS.get(rel, "dsi/1.3")
    args.rewrites = [r for r in args.rewrites.split(",") if r]
    for r in args.rewrites:
        if r not in REWRITES:
            p.error("unknown rewrite " + r)
    args.src_dir = str(args.source.resolve().parent)
    args.tmpdir = os.environ.get("TMPDIR") or None
    suffix = args.source.suffix if args.source.suffix in (".c", ".cpp") else ".cpp"
    base = join_brace_lines(args.source.read_text())
    names = {args.function} | {n for n in args.funcs.split(",") if n}
    if args.inlines:
        names |= inline_names(base.split("\n"))
    if not func_bodies(base.split("\n"), names):
        sys.exit("no body found for " + ", ".join(sorted(names)) + " (function definitions must start in column 0)")

    workdir = tempfile.mkdtemp(prefix="cxxperm_", dir=args.tmpdir)
    try:
        scorer = Scorer(args, suffix, workdir)
        res, err = scorer.compile(base)
        if res is None:
            sys.exit("the draft does not compile:\n" + err)
        scorer.init_calls(base)
        base_score = scorer.score(base)
    finally:
        shutil.rmtree(workdir, ignore_errors=True)
    print("base", fmt(base_score), flush=True)
    if args.score_only or base_score[1] == 0:
        return
    outdir = args.out or ROOT / "build" / "cxxperm" / args.function
    outdir.mkdir(parents=True, exist_ok=True)
    deadline = time.time() + args.time
    ctx = multiprocessing.get_context("fork")
    stop = ctx.Event()
    lock = ctx.Lock()
    best_val = ctx.Value("i", base_score[0])
    counts = ctx.Array("i", 2)
    procs = [ctx.Process(target=worker, args=(w, args, base, base_score, names, deadline, str(outdir), suffix, stop, lock, best_val, counts))
             for w in range(args.jobs)]
    for pr in procs:
        pr.start()
    try:
        for pr in procs:
            pr.join()
    except KeyboardInterrupt:
        stop.set()
        for pr in procs:
            pr.join()
    print("best score %d (base %d) after %d compiles (%d failed), results in %s"
          % (best_val.value, base_score[0], counts[0], counts[1], outdir))


if __name__ == "__main__":
    main()
