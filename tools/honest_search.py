#!/usr/bin/env python3
"""Combined honest-transformation search for one function (round cmA).

    python3 tools/honest_search.py SRC FUNC [--module ovNNN] [--iters 60] [--beam 4] [--sample 24] [--out DIR]

Starting from SRC (a draft whose FUNC compiles), it applies *combinations* of the source transformations that
earlier rounds found to be honest levers, compiles every variant (2 jobs at most) and scores FUNC against the
base ROM. The search is a beam search with plateau moves, compound (2-move) steps and restarts, so it explores
combinations instead of single moves. Every move is one of:

  decl   swap two declarations of a leading declaration run (target body or an inline it calls); initialised
         declarations keep their relative order (rounds bgD, mcA)
  enum   replace an integer literal used as a call argument or plain store value by an enum-typed local, assigned
         0..BACK statements earlier in the same block or initialised at its declaration (rounds lfA, o4B, o4C)
  nl     read a field/element, or pass a non-trivial call argument, through a named local assigned 0..BACK
         statements earlier in the same block (rounds frB, mcA, smY)
  move   move a one-line statement 1..3 lines up or down inside its block (rounds tmB)
  tern   rewrite `x = c ? a : b;` / `return c ? a : b;` as if/else (round frB)
  late   move an uninitialised top-level declaration into the innermost block holding all its uses (round frC)
  merge  one variable for two roles: `x = E; ... y = x - 1;` (x used nowhere else) becomes `y = E; ... y -= 1;`
         (rounds mgX, cmA)

Moves keep the program's meaning by construction: values read earlier (nl/enum/move) may not cross a statement
that writes one of their variables, and a statement with memory effects (call, store through a pointer) never
crosses another one that reads or writes memory (use --loose to drop the memory rule). The search is bounded
by --max-enum / --max-nl / --max-move so the result stays a plausible source.

Named locals are written as `__typeof__(e) hs_nK = e;` during the search. The winner is then rewritten with
concrete types (the compiler's own error message for a deliberately bad pointer conversion names the type), and
the enum typedefs get placeholder names `HsEnumK` / `HS_ENUM_K` that you must rename by hand. Review the winner
by eye before keeping it.

Output (in --out, default build/honest_search/FUNC): best<ext> (concrete types), log.txt, top.txt.
Score is (masked, raw): masked = register-masked sequence diff, raw = positional diff (the ce.py/ms.py scores).
"""
import argparse, hashlib, os, random, re, struct, subprocess, sys, tempfile, time
from concurrent.futures import ThreadPoolExecutor
from pathlib import Path

import capstone
import yaml
from elftools.elf.elffile import ELFFile

ROOT = Path(__file__).resolve().parent.parent
CC_FLAGS = ["-O4,p", "-enum", "int", "-char", "signed", "-str", "noreuse", "-proc", "arm946e", "-gccext,on", "-fp",
            "soft", "-inline", "noauto", "-Cpp_exceptions", "off", "-RTTI", "off", "-interworking", "-w", "off",
            "-sym", "on", "-gccinc", "-nolink", "-msgstyle", "gcc", "-i", str(ROOT / "include"), "-d", "usa",
            "-DNONMATCHING"]

# ----------------------------------------------------------------------------------------------- ROM and scoring

def rom_func(mod, func):
    ex = ROOT / "extract" / "usa"
    if mod == "itcm":
        code = (ex / "arm9" / "itcm.bin").read_bytes()
        base = yaml.safe_load((ex / "arm9" / "itcm.yaml").read_text())["base_address"]
        syms = ROOT / "config/usa/arm9/itcm/symbols.txt"
    elif mod == "main":
        code = (ex / "arm9" / "arm9.bin").read_bytes()
        base = yaml.safe_load((ex / "arm9" / "arm9.yaml").read_text())["base_address"]
        syms = ROOT / "config/usa/arm9/symbols.txt"
    else:
        ovs = yaml.safe_load((ex / "arm9_overlays" / "overlays.yaml").read_text())["overlays"]
        o = next(o for o in ovs if o["id"] == int(mod[2:]))
        code = (ex / "arm9_overlays" / o["file_name"]).read_bytes()
        base = o["base_address"]
        syms = ROOT / ("config/usa/arm9/overlays/%s/symbols.txt" % mod)
    for l in open(syms):
        if l.startswith(func + " "):
            size = int(re.search(r"size=0x([0-9a-f]+)", l)[1], 16)
            addr = int(re.search(r"addr:0x([0-9a-f]+)", l)[1], 16)
            return code[addr - base:addr - base + size], addr
    raise SystemExit("no symbol %s in %s" % (func, syms))


MD = capstone.Cs(capstone.CS_ARCH_ARM, capstone.CS_MODE_ARM)
REG = re.compile(r"\b(r\d+|sb|sl|fp|ip|lr|sp)\b")


def listing(code, addr, rel):
    ins = []
    for off in range(0, len(code), 4):
        i = next(MD.disasm(code[off:off + 4], addr + off, 1), None)
        ins.append(i)
    out = []
    pool = set(o // 4 for o in rel)
    for k, i in enumerate(ins):
        if i is not None and i.mnemonic.startswith("ldr") and "[pc, #" in i.op_str:
            m = re.search(r"\[pc, #(-?0x[0-9a-f]+|-?\d+)\]", i.op_str)
            o = (4 * k + 8 + int(m[1], 0)) // 4
            if k < o < len(ins): pool.add(o)
    for k, i in enumerate(ins):
        if k in pool or i is None: out.append(".word"); continue
        s = "%s %s" % (i.mnemonic, i.op_str)
        if i.mnemonic.startswith("b") and i.op_str.startswith("#") and not i.mnemonic.startswith("bic"):
            s = i.mnemonic
        out.append(re.sub(r"\[pc, #-?(0x[0-9a-f]+|\d+)\]", "[pc,X]", s))
    return out


def seqdiff(a, b):
    import difflib
    sm = difflib.SequenceMatcher(None, a, b, autojunk=False)
    return sum(max(i2 - i1, j2 - j1) for t, i1, i2, j1, j2 in sm.get_opcodes() if t != "equal")


class Scorer:
    def __init__(self, src, func, mod):
        self.src = Path(src).resolve(); self.func = func
        rc, self.addr = rom_func(mod, func)
        self.rom = listing(rc, self.addr, set())
        self.romm = [REG.sub("R", x) for x in self.rom]
        self.lang = "-lang=c++" if self.src.suffix == ".cpp" else "-lang=c"
        self.cache = {}

    def compile(self, text, keep_err=False):
        d = self.src.parent
        fd, p = tempfile.mkstemp(suffix=self.src.suffix, dir=str(d), prefix=".hs_")
        os.write(fd, text.encode("latin1")); os.close(fd)
        o = p + ".o"
        try:
            r = subprocess.run([sys.executable, str(ROOT / "tools/fpucw.py"), str(ROOT / "wibo"),
                                str(ROOT / "tools/mwccarm/dsi/1.3/mwccarm.exe"), *CC_FLAGS, self.lang, "-c", p, "-o", o],
                               capture_output=True, text=True, cwd=str(ROOT))
            if keep_err: return r.stdout + r.stderr
            if not os.path.exists(o): return None
            e = ELFFile(open(o, "rb"))
            for s in e.get_section_by_name(".symtab").iter_symbols():
                if s["st_info"]["type"] != "STT_FUNC": continue
                if s.name == self.func or s.name.startswith(self.func + "__"):
                    st = s["st_value"] & ~1; sec = s["st_shndx"]
                    code = e.get_section(sec).data()[st:st + s["st_size"]]
                    rel = set()
                    for rs in e.iter_sections():
                        if rs.header["sh_type"] in ("SHT_REL", "SHT_RELA") and rs.header["sh_info"] == sec:
                            for x in rs.iter_relocations():
                                off = x["r_offset"] - st
                                if 0 <= off < len(code) and x["r_info_type"] == 2: rel.add(off)
                    return code, rel
            return None
        finally:
            for f in (p, o):
                if os.path.exists(f): os.remove(f)

    def score(self, text):
        h = hashlib.sha1(text.encode("latin1")).hexdigest()
        if h in self.cache: return self.cache[h]
        r = self.compile(text)
        if r is None: sc = None
        else:
            ours = listing(r[0], self.addr, r[1])
            raw = sum(1 for k in range(max(len(ours), len(self.rom)))
                      if k >= len(ours) or k >= len(self.rom) or ours[k] != self.rom[k])
            msk = seqdiff([REG.sub("R", x) for x in ours], self.romm)
            sc = (msk, raw)
        self.cache[h] = sc
        return sc

# ------------------------------------------------------------------------------------------------- source model

KW = {"if", "for", "while", "switch", "return", "sizeof", "do", "else", "case", "goto", "break", "continue",
      "default", "typedef", "struct", "union", "enum", "const", "volatile", "unsigned", "signed", "static", "inline"}
DECL = re.compile(r"^(\s+)((?:const\s+|register\s+|unsigned\s+|signed\s+|struct\s+|volatile\s+)*[A-Za-z_]\w*"
                  r"(?:\s*<[^>]*>)?[\s\*&]+)([A-Za-z_]\w*)(\[[^\]]*\])?(\s*=\s*[^;]*)?;\s*(//.*)?$")
LIT = re.compile(r"-?(?:0x[0-9a-fA-F]+|\d+)[uUlL]*")


def is_decl(l):
    m = DECL.match(l)
    if not m: return None
    first = l.split()[0]
    if first in KW - {"const", "unsigned", "signed", "struct", "volatile"} or first in ("return", "delete", "goto"):
        return None
    if "(" in l.split("=")[0]: return None
    return m


def find_body(lines, func):
    for i, l in enumerate(lines):
        if re.search(r"\b" + re.escape(func) + r"\s*\(", l) and not l.rstrip().endswith(";") \
                and not l.lstrip().startswith(("//", "#", "*")):
            j = i
            while "{" not in lines[j]:
                if lines[j].rstrip().endswith(";"): break
                j += 1
            else:
                d = 0
                for k in range(j, len(lines)):
                    d += lines[k].count("{") - lines[k].count("}")
                    if d == 0: return i, j, k
    return None


def func_bodies(lines, func):
    """Target body plus the bodies of inline functions called from it."""
    tb = find_body(lines, func)
    out = [tb]
    body = "\n".join(lines[tb[1]:tb[2] + 1])
    for i, l in enumerate(lines[:tb[0]]):
        m = re.match(r"^\s*(?:static\s+)?inline\b[^;(]*?\b([A-Za-z_]\w*)\s*\(", l)
        if m and re.search(r"\b" + m.group(1) + r"\s*\(", body):
            b = find_body(lines[:tb[0]], m.group(1))
            if b and b[0] == i: out.append(b)
    return out


def block_ok(lines, a, b):
    """Lines a..b-1 contain no brace, label, case, jump or preprocessor line (same block, straight line)."""
    for x in lines[a:b]:
        s = x.strip()
        if s.startswith(("return", "break", "continue", "goto")): return False
        if "{" in x or "}" in x: return False
        if s.startswith(("case ", "default", "#")) or re.match(r"^[A-Za-z_]\w*\s*:(?!:)", s): return False
    return True


def strip_strings(s):
    return re.sub(r'"(\\.|[^"\\])*"|\'(\\.|[^\'\\])*\'', '""', s.split("//")[0])


CALL = re.compile(r"\b([A-Za-z_]\w*)\s*\(")


def effects(l):
    """(written idents, read idents, writes memory, reads memory) of one statement line."""
    s = strip_strings(l)
    ids = set(re.findall(r"(?<![\w.>])[A-Za-z_]\w*", s)) - KW
    W = set()
    for m in re.finditer(r"(?<![\w.>])([A-Za-z_]\w*)\s*(?:[-+*/%|&^]|<<|>>)?=(?!=)", s): W.add(m.group(1))
    for m in re.finditer(r"(?:\+\+|--)\s*([A-Za-z_]\w*)|([A-Za-z_]\w*)\s*(?:\+\+|--)", s): W.add(m.group(1) or m.group(2))
    for m in re.finditer(r"&\s*([A-Za-z_]\w*)", s):   # address taken: assume written
        if not re.search(r"&&\s*$", s[:m.start() + 1]): W.add(m.group(1))
    calls = [m.group(1) for m in CALL.finditer(s) if m.group(1) not in KW and not m.group(1).isupper()]
    memw = bool(calls) or bool(re.search(r"(->|\]|\.)\s*[\w\s]*(?:[-+*/%|&^]|<<|>>)?=(?!=)", s)) or \
        bool(re.search(r"(^|[;{(=,]\s*)\*\s*[A-Za-z_(]", s.strip()) and re.search(r"=(?!=)", s))
    memr = bool(calls) or "->" in s or "[" in s or bool(re.search(r"\*\s*[A-Za-z_(]", s)) or \
        bool(re.search(r"\b(FLD|FIELD|LFLD)\s*\(", s))
    # an upper-case macro may hide anything; treat as memory access too
    if any(m.group(1).isupper() and m.group(1) not in ("FLD", "FIELD", "LFLD") for m in CALL.finditer(s)):
        memw = memr = True
    return W, ids, memw, memr


def conflict(a, b, loose):
    Wa, Ra, mwa, mra = effects(a); Wb, Rb, mwb, mrb = effects(b)
    if Wa & (Rb | Wb) or Wb & Ra: return True
    if not loose and ((mwa and (mrb or mwb)) or (mwb and mra)): return True
    return False


def bal(l, k):
    d = 0
    while k < len(l):
        if l[k] in "([": d += 1
        elif l[k] in ")]":
            d -= 1
            if d == 0: return k + 1
        k += 1
    return None


def call_args(l):
    out = []
    for m in CALL.finditer(l):
        name = m.group(1)
        if name in KW or name.isupper() or name.startswith(("FLD", "LFLD", "FIELD")): continue
        k = m.end(); d = 1; st = k
        while k < len(l) and d > 0:
            ch = l[k]
            if ch in "([": d += 1
            elif ch in ")]": d -= 1
            if (ch == "," and d == 1) or d == 0:
                if l[st:k].strip(): out.append((st, k))
                st = k + 1
            k += 1
    res = []
    for a, b in out:
        t = l[a:b]; s = a + (len(t) - len(t.lstrip())); e = b - (len(t) - len(t.rstrip()))
        res.append((s, e, l[s:e]))
    return res


def field_reads(l):
    out = []
    for m in re.finditer(r"\b(FLD|FIELD|LFLD)\s*\(", l):
        e = bal(l, m.end() - 1)
        if e: out.append((m.start(), e))
    for m in re.finditer(r"(?<![\w>.])[A-Za-z_]\w*", l):
        if m.group(0) in KW: continue
        k = m.end(); n = 0
        while True:
            mm = re.match(r"\s*(->|\.)\s*[A-Za-z_]\w*", l[k:])
            if mm: k += mm.end(); n += 1; continue
            if k < len(l) and l[k] == "[":
                e = bal(l, k)
                if not e: break
                k = e; n += 1; continue
            break
        if n and not (k < len(l) and l[k] == "("): out.append((m.start(), k))
    res = []
    for st, en in out:
        rest = l[en:]
        if re.match(r"\s*([-+*/|&^]|<<|>>)?=(?!=)", rest) or re.match(r"\s*(\+\+|--)", rest): continue
        if re.search(r"(\+\+|--|&)\s*$", l[:st]): continue
        res.append((st, en, l[st:en]))
    return res


class State:
    def __init__(self, lines, hist=(), cnt=None):
        self.lines = lines; self.hist = tuple(hist)
        self.cnt = dict(cnt or {"enum": 0, "nl": 0, "move": 0, "tern": 0, "late": 0, "decl": 0, "merge": 0})
        self.text = "\n".join(lines)


class Gen:
    def __init__(self, func, a):
        self.func = func; self.a = a
        self.kinds = set(a.kinds.split(","))

    def moves(self, st):
        L = st.lines; a = self.a
        bodies = func_bodies(L, self.func)
        hd, ob, end = bodies[0]
        mv = []
        # decl swaps
        if "decl" in self.kinds:
            for (h, o, e) in bodies:
                k = o + 1
                while k < e:
                    if L[k - 1].rstrip().endswith("{") and is_decl(L[k]):
                        run = []
                        while k < e and is_decl(L[k]): run.append(k); k += 1
                        for x in range(len(run)):
                            for y in range(x + 1, len(run)):
                                i, j = run[x], run[y]
                                if is_decl(L[i]).group(5) and is_decl(L[j]).group(5): continue
                                if is_decl(L[i]).group(5) or is_decl(L[j]).group(5):
                                    # an initialiser may not move past a declaration it uses
                                    mi, mj = is_decl(L[i]), is_decl(L[j])
                                    if re.search(r"\b%s\b" % mi.group(3), mj.group(5) or "") or \
                                            re.search(r"\b%s\b" % mj.group(3), mi.group(5) or ""): continue
                                mv.append(("decl", i, j))
                    else:
                        k += 1
        if st.cnt["enum"] < a.max_enum and "enum" in self.kinds:
            for li in range(ob + 1, end):
                l = L[li]; s = l.strip()
                if s.startswith(("//", "#", "case", "if", "for", "while", "switch", "return", "}", "{", "else", "do")):
                    continue
                if not s.endswith(";"): continue
                tg = [(s0, e0, t) for s0, e0, t in call_args(l) if LIT.fullmatch(t)]
                m = re.fullmatch(r"(\s*)(.+?)\s=\s(-?(?:0x[0-9a-fA-F]+|\d+)[uUlL]*);\s*", l)
                if m and "==" not in l:
                    s0 = l.rindex(m.group(3)); tg.append((s0, s0 + len(m.group(3)), m.group(3)))
                for s0, e0, t in tg:
                    for b in range(0, a.back + 1):
                        ins = li - b
                        if ins <= ob or not block_ok(L, ins, li): break
                        mv.append(("enum", li, s0, e0, ins))
                    mv.append(("enum", li, s0, e0, -1))  # initialised at the declaration
        if st.cnt["nl"] < a.max_nl and "nl" in self.kinds:
            for li in range(ob + 1, end):
                l = L[li]; s = l.strip()
                if not s.endswith(";") or s.startswith(("//", "#", "for", "case")) or is_decl(l) and "hs_n" in l:
                    continue
                cands = {}
                for s0, e0, t in field_reads(l): cands[(s0, e0)] = t
                for s0, e0, t in call_args(l):
                    if LIT.fullmatch(t) or re.fullmatch(r"[A-Za-z_]\w*", t) or "(" in t and CALL.search(t) \
                            and any(not x.isupper() for x in CALL.findall(t)): continue
                    if re.fullmatch(r"\"[^\"]*\"", t): continue
                    cands[(s0, e0)] = t
                for (s0, e0), t in cands.items():
                    if CALL.search(t) and any(x not in ("FLD", "FIELD", "LFLD") and x not in KW
                                              for x in CALL.findall(t)): continue
                    for b in range(0, a.back + 1):
                        ins = li - b
                        if ins <= ob or not block_ok(L, ins, li): break
                        if b and any(conflict("x = " + t + ";", L[q], a.loose) for q in range(ins, li)): break
                        mv.append(("nl", li, s0, e0, ins))
        if st.cnt["move"] < a.max_move and "move" in self.kinds:
            for li in range(ob + 1, end):
                l = L[li]; s = l.strip()
                if not s.endswith(";") or s.startswith(("return", "break", "continue", "case", "if", "for", "while",
                                                         "}", "goto", "//", "#", "default", "else")) or is_decl(l):
                    continue
                if s.count("(") != s.count(")"): continue
                for d in (-3, -2, -1, 1, 2, 3):
                    j = li + d
                    if j <= ob or j >= end: continue
                    lo, hi = (j, li) if d < 0 else (li + 1, j + 1)
                    if not block_ok(L, lo, hi): continue
                    if any(is_decl(L[q]) and not is_decl(L[q]).group(5) for q in range(lo, hi)) and d < 0: continue
                    if any(L[q].strip().startswith(("return", "break", "continue", "goto")) for q in range(lo, hi)):
                        continue
                    if any(conflict(l, L[q], a.loose) for q in range(lo, hi)): continue
                    mv.append(("move", li, j))
        if st.cnt["tern"] < a.max_tern and "tern" in self.kinds:
            for li in range(ob + 1, end):
                if self.tern_split(L[li]): mv.append(("tern", li))
        if st.cnt["late"] < a.max_late and "late" in self.kinds:
            k = ob + 1
            while k < end and (is_decl(L[k]) or not L[k].strip()):
                m = is_decl(L[k])
                if m and not m.group(5) and not m.group(4):
                    tgt = self.late_target(L, ob, end, k, m.group(3))
                    if tgt is not None: mv.append(("late", k, tgt))
                k += 1
        if st.cnt["merge"] < a.max_merge and "merge" in self.kinds:
            mv += self.merge_moves(L, ob, end)
        return mv

    @staticmethod
    def merge_moves(L, ob, end):
        """x = E; ... y = F(x);  with x used nowhere else  ->  y = E; ... y = F(y);  (one variable for both roles,
        round mgX / cmA). y may not be referenced between the two statements nor in E."""
        out = []
        asg = re.compile(r"^\s*([A-Za-z_]\w*)\s*=(?!=)\s*(.*);\s*$")
        body = [strip_strings(x) for x in L]
        for i in range(ob + 1, end):
            m = asg.match(L[i])
            if not m or is_decl(L[i]): continue
            x = m.group(1); rx = re.compile(r"\b%s\b" % re.escape(x))
            uses = [q for q in range(ob + 1, end) if q != i and rx.search(body[q])]
            uses = [q for q in uses if not (is_decl(L[q]) and is_decl(L[q]).group(3) == x)]
            if len(uses) != 1 or uses[0] < i: continue
            j = uses[0]; mj = asg.match(L[j])
            if not mj or len(rx.findall(body[j])) != 1: continue
            y = mj.group(1)
            if y == x or re.search(r"\b%s\b" % re.escape(y), m.group(2)): continue
            ry = re.compile(r"\b%s\b" % re.escape(y))
            if any(ry.search(body[q]) for q in range(i + 1, j)): continue
            if not block_ok(L, i + 1, j) and any("{" in L[q] or "}" in L[q] for q in range(i + 1, j)):
                # allow crossing whole nested blocks, but both statements must be at the same depth
                d = 0
                for q in range(i + 1, j): d += L[q].count("{") - L[q].count("}")
                if d != 0: continue
            out.append(("merge", i, j))
        return out

    @staticmethod
    def tern_split(l):
        s = strip_strings(l)
        m = re.match(r"^(\s*)(return\s+|[^=?:]+?\s=\s)(.*);\s*$", l)
        if not m or "==" in m.group(2) or "//" in l: return None
        e = m.group(3); d = 0; q = c = None
        for i, ch in enumerate(e):
            if ch in "([": d += 1
            elif ch in ")]": d -= 1
            elif ch == "?" and d == 0 and q is None: q = i
            elif ch == ":" and d == 0 and q is not None and c is None: c = i
        if q is None or c is None or "?" in e[c:]: return None
        return m.group(1), m.group(2), e[:q].strip(), e[q + 1:c].strip(), e[c + 1:].strip()

    @staticmethod
    def late_target(L, ob, end, k, name):
        uses = [q for q in range(ob + 1, end + 1) if q != k and re.search(r"\b%s\b" % re.escape(name), strip_strings(L[q]))]
        if not uses: return None
        # innermost block containing every use: walk depth
        depth = []; stack = []; opens = {}
        d = 0
        for q in range(ob, end + 1):
            for ch in L[q]:
                if ch == "{": stack.append(q)
                elif ch == "}" and stack: stack.pop()
            opens[q] = list(stack)
        def chain(q):  # open-block lines enclosing line q (before q's own braces)
            c = list(opens[q - 1]) if q - 1 >= ob else []
            return c
        cs = [chain(q) for q in uses]
        common = cs[0]
        for c in cs[1:]:
            n = 0
            while n < min(len(common), len(c)) and common[n] == c[n]: n += 1
            common = common[:n]
        if len(common) < 2: return None
        o = common[-1]
        if not L[o].rstrip().endswith("{"): return None
        if any(q <= o for q in uses): return None
        if re.match(r"\s*(switch|do)\b", L[o]) : return None
        return o

    def apply(self, st, m, rnd):
        L = list(st.lines); cnt = dict(st.cnt); kind = m[0]
        hd = find_body(L, self.func)[0]
        ob = find_body(L, self.func)[1]
        if kind == "decl":
            _, i, j = m; L[i], L[j] = L[j], L[i]
            desc = "decl swap %s <-> %s" % (L[j].strip(), L[i].strip())
        elif kind == "enum":
            _, li, s0, e0, ins = m; n = cnt["enum"]; lit = L[li][s0:e0]
            v = "hs_e%d" % n; T = "HsEnum%d" % n; K = "HS_ENUM_%d" % n
            L[li] = L[li][:s0] + v + L[li][e0:]
            ind = re.match(r"\s*", L[li]).group(0); ind0 = re.match(r"\s*", L[ob + 1]).group(0) or "    "
            if ins >= 0:
                L.insert(ins, ind + "%s = %s;" % (v, K))
                L.insert(ob + 1, ind0 + "%s %s;" % (T, v))
                desc = "enum %s at line %d, assigned %d stmts earlier" % (lit, li + 1, li - ins)
            else:
                L.insert(ob + 1, ind0 + "%s %s = %s;" % (T, v, K))
                desc = "enum %s at line %d, initialised at declaration" % (lit, li + 1)
            L.insert(hd, "typedef enum { %s = %s } %s;" % (K, re.sub(r"[uUlL]+$", "", lit), T))
        elif kind == "nl":
            _, li, s0, e0, ins = m; n = cnt["nl"]; e = L[li][s0:e0]; v = "hs_n%d" % n
            L[li] = L[li][:s0] + v + L[li][e0:]
            ind = re.match(r"\s*", L[li]).group(0)
            L.insert(ins, ind + "__typeof__(%s) %s = %s;" % (e, v, e))
            desc = "named local for %s at line %d, %d stmts earlier" % (e, li + 1, li - ins)
        elif kind == "move":
            _, li, j = m; x = L.pop(li); L.insert(j, x)
            desc = "move '%s' %+d" % (x.strip(), j - li)
        elif kind == "tern":
            _, li = m; ind, lhs, c, x, y = self.tern_split(L[li])
            L[li:li + 1] = ["%sif (%s) {" % (ind, c), "%s    %s%s;" % (ind, lhs, x), "%s} else {" % ind,
                            "%s    %s%s;" % (ind, lhs, y), "%s}" % ind]
            desc = "if/else for ?: at line %d" % (li + 1)
        elif kind == "merge":
            _, i, j = m
            mi = re.match(r"^(\s*)([A-Za-z_]\w*)\s*=(?!=)\s*(.*);\s*$", L[i])
            mj = re.match(r"^(\s*)([A-Za-z_]\w*)\s*=(?!=)\s*(.*);\s*$", L[j])
            x, y = mi.group(2), mj.group(2)
            L[i] = "%s%s = %s;" % (mi.group(1), y, mi.group(3))
            rhs = re.sub(r"\b%s\b" % re.escape(x), y, mj.group(3))
            mm = re.fullmatch(r"%s\s*([-+*/|&^]|<<|>>)\s*(.+)" % re.escape(y), rhs)
            L[j] = "%s%s %s= %s;" % (mj.group(1), y, mm.group(1), mm.group(2)) if mm else "%s%s = %s;" % (mj.group(1), y, rhs)
            for q in range(ob + 1, i):   # drop x's now unused declaration
                d = is_decl(L[q])
                if d and d.group(3) == x and not d.group(5):
                    del L[q]; break
            desc = "merge %s into %s ('%s' / '%s')" % (x, y, L[i - 1 if L[i - 1].strip().startswith(y) else i].strip(), mj.group(3))
        elif kind == "late":
            _, k, o = m; x = L.pop(k); ind = re.match(r"\s*", L[o]).group(0) + "    "
            L.insert(o, ind + x.strip())   # o shifted by -1 after pop: insert after the '{' line
            desc = "late decl '%s' into block at line %d" % (x.strip(), o + 1)
        cnt[kind] += 1
        return State(L, st.hist + (desc,), cnt)

# ------------------------------------------------------------------------------------------- concrete types

def unwrap(err):
    """Join MWCC's wrapped message lines (each continuation repeats the `file:line: ` prefix)."""
    return re.sub(r"\n[^\n]*?:\d+: ", "", err)


def resolve_types(scorer, text):
    """Replace every `__typeof__(e) v = e;` by the concrete type the compiler reports for e."""
    lines = text.split("\n")
    for i, l in enumerate(lines):
        m = re.match(r"^(\s*)__typeof__\((.*)\) (hs_n\d+) = (.*);$", l)
        if not m: continue
        probe = list(lines)
        probe[i] = m.group(1) + "struct HsProbe { int x; } *hs_probe = &(%s);" % m.group(2)
        err = unwrap(scorer.compile("\n".join(probe), keep_err=True))
        t = None
        mm = re.search(r"'([^']*?) ?\*' to ?'[^']*HsProbe \*'", err) or re.search(r"from '([^']*?) ?\*' to", err)
        if mm: t = mm.group(1)
        else:
            probe[i] = m.group(1) + "struct HsProbe { int x; } hs_probe = (%s);" % m.group(2)
            err = unwrap(scorer.compile("\n".join(probe), keep_err=True))
            mm = re.search(r"from '([^']*)' to", err)
            if mm: t = mm.group(1)
        if t:
            t = re.sub(r"\bstruct\s+", "", t).strip()
            base = re.sub(r"[\s\*]+$", "", t); stars = t[len(base):].replace(" ", "")
            base = {"unsigned short": "u16", "short": "s16", "int": "s32", "unsigned int": "u32", "long": "s32",
                    "unsigned long": "u32", "unsigned char": "u8", "signed char": "s8", "char": "s8",
                    "long long": "s64", "unsigned long long": "u64"}.get(base, base)
            lines[i] = "%s%s %s%s = %s;" % (m.group(1), base, stars, m.group(3), m.group(4))
    return "\n".join(lines)

# ------------------------------------------------------------------------------------------------------ search

def main():
    ap = argparse.ArgumentParser(description=__doc__, formatter_class=argparse.RawDescriptionHelpFormatter)
    ap.add_argument("src"); ap.add_argument("func")
    ap.add_argument("--module"); ap.add_argument("--out")
    ap.add_argument("--iters", type=int, default=60)
    ap.add_argument("--beam", type=int, default=4)
    ap.add_argument("--sample", type=int, default=24, help="neighbours tried per beam state per iteration")
    ap.add_argument("--pair", type=float, default=0.35, help="fraction of neighbours that apply two moves at once")
    ap.add_argument("--patience", type=int, default=6, help="iterations without a new best before a restart")
    ap.add_argument("--kick", type=int, default=3, help="random moves applied on a restart")
    ap.add_argument("--kinds", default="decl,enum,nl,move,tern,late,merge")
    ap.add_argument("--back", type=int, default=4)
    ap.add_argument("--max-enum", type=int, default=1); ap.add_argument("--max-nl", type=int, default=2)
    ap.add_argument("--max-move", type=int, default=3); ap.add_argument("--max-tern", type=int, default=2)
    ap.add_argument("--max-late", type=int, default=2); ap.add_argument("--max-merge", type=int, default=2)
    ap.add_argument("--loose", action="store_true", help="let memory statements cross each other")
    ap.add_argument("--diff", action="store_true", help="print SRC's listing against the ROM, then stop")
    ap.add_argument("--list", action="store_true", help="print the moves available on SRC and their scores, then stop")
    ap.add_argument("--seed", type=int, default=1); ap.add_argument("-j", type=int, default=2)
    a = ap.parse_args()
    a.j = min(a.j, 2)
    func = a.func if a.func.startswith("func_") or "_" in a.func else a.func
    mod = a.module or (re.match(r"func_(ov\d+)_", func).group(1) if re.match(r"func_ov\d+_", func) else "main")
    out = Path(a.out or ROOT / "build" / "honest_search" / func); out.mkdir(parents=True, exist_ok=True)
    rnd = random.Random(a.seed)
    sc = Scorer(a.src, func, mod)
    gen = Gen(func, a)
    base = State(open(a.src, encoding="latin1").read().split("\n"))
    b0 = sc.score(base.text)
    log = open(out / "log.txt", "w")
    def P(*x):
        s = " ".join(str(y) for y in x); print(s, flush=True); log.write(s + "\n"); log.flush()
    P("base", b0, "moves", len(gen.moves(base)))
    if b0 is None: raise SystemExit("base does not compile")
    if a.diff:
        r = sc.compile(base.text); ours = listing(r[0], sc.addr, r[1])
        for k in range(max(len(ours), len(sc.rom))):
            x = ours[k] if k < len(ours) else ""; y = sc.rom[k] if k < len(sc.rom) else ""
            print("%s %08x %-40s | %s" % ("  " if x == y else "!!", sc.addr + 4 * k, x, y))
        return
    if a.list:
        ms = gen.moves(base); sts = [gen.apply(base, m, rnd) for m in ms]
        with ThreadPoolExecutor(a.j) as ex: scs = list(ex.map(lambda s: sc.score(s.text), sts))
        for s, st in sorted(zip(scs, sts), key=lambda r: r[0] or (9999, 9999)): P(s, st.hist[0])
        return
    best = (b0, base); beam = [(b0, base)]; stale = 0; seen = {base.text}; ncomp = 0; t0 = time.time()
    allres = []
    def neighbour(st):
        ms = gen.moves(st)
        if not ms: return None
        s2 = gen.apply(st, rnd.choice(ms), rnd)
        if rnd.random() < a.pair:
            ms2 = gen.moves(s2)
            if ms2: s2 = gen.apply(s2, rnd.choice(ms2), rnd)
        return s2
    for it in range(a.iters):
        cands = []
        for _, st in beam:
            for _ in range(a.sample):
                s2 = neighbour(st)
                if s2 is not None and s2.text not in seen: seen.add(s2.text); cands.append(s2)
        with ThreadPoolExecutor(a.j) as ex: scs = list(ex.map(lambda s: sc.score(s.text), cands))
        ncomp += len(cands)
        new = [(s, c) for s, c in zip(scs, cands) if s is not None]
        allres += [(s, c.hist) for s, c in new]
        pool = beam + new
        rnd.shuffle(pool)   # ties: random, so equal-score variants (plateau moves) can take beam slots
        pool.sort(key=lambda r: (r[0], len(r[1].hist)))
        nb = []; keys = set()
        for r in pool:
            if r[1].text in keys: continue
            keys.add(r[1].text); nb.append(r)
            if len(nb) >= a.beam: break
        beam = nb
        if beam[0][0] < best[0]:
            best = beam[0]; stale = 0
            P("it %d new best %s after %d compiles: %s" % (it, best[0], ncomp, " | ".join(best[1].hist)))
            open(out / ("best" + Path(a.src).suffix), "w", encoding="latin1").write(best[1].text)
        else:
            stale += 1
        if best[0] == (0, 0): break
        if stale >= a.patience:
            stale = 0
            st = best[1] if rnd.random() < 0.5 else base
            for _ in range(a.kick):
                s2 = neighbour(st)
                if s2: st = s2
            ks = sc.score(st.text)
            beam = [(ks, st)] if ks else [best]
            P("it %d restart from %s (%s)" % (it, ks, " | ".join(st.hist)))
    P("done: %d compiles in %.0fs, best %s" % (ncomp, time.time() - t0, best[0]))
    P("best moves:", " | ".join(best[1].hist) or "(none)")
    allres.sort(key=lambda r: r[0])
    with open(out / "top.txt", "w") as f:
        for s, h in allres[:60]: f.write("%s %s\n" % (s, " | ".join(h)))
    txt = resolve_types(sc, best[1].text)
    if sc.score(txt) != best[0]: P("warning: concrete-type rewrite scores %s" % (sc.score(txt),))
    open(out / ("best" + Path(a.src).suffix), "w", encoding="latin1").write(txt)
    P("wrote", out / ("best" + Path(a.src).suffix))


if __name__ == "__main__":
    main()
