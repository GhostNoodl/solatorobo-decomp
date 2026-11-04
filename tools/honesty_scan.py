#!/usr/bin/env python3
"""Honesty scanner for matched code (round auA).

    python3 tools/honesty_scan.py [PATH ...] [--cat CAT[,CAT]] [--all] [--drafts] [--summary] [--tsv]

Scans the C/C++ sources (default: src/ libs/ include/) for the source shapes that the project does not accept as
a match (docs/UNMATCHED.md, "Rules for a match") and prints one line per hit:

    CAT  FILE:LINE  FUNC  TEXT

Code inside `#ifdef NONMATCHING` (or `#if ... NONMATCHING`) blocks and `#if 0` blocks is skipped, since the default
build leaves it out; pass --drafts to scan it too. Hits that docs/MATCHING.md round auA triaged as legitimate are
listed in tools/honesty_allow.txt (by category, file and a text fragment) and are hidden unless --all is given. A new hit should be fixed,
or triaged and added to tools/honesty_allow.txt with its reason.

Categories (--cat):
  ptrbit     a pointer cast to an integer and masked: `(u32)self & 3` (the two-definition trick)
  volatile   `volatile` or a `vu8`/`vu16`/`vu32`/`vs*` type, except on a constant hardware address
  asm        inline `asm` / `__asm` in C or C++ (whole `asm` functions and blocks)
  empty      an `if`/`else`/`while`/`for` with an empty body (`{}` or `;`)
  deadstore  a local assigned and overwritten with no read in between, or assigned and never read
  unusedparam a named parameter that the body never mentions
  onceloop   `do {} while (0)` outside a macro, or a loop whose body ends in an unconditional `break` with no
             `continue`
  oob        negative constant indexes, `(&x)[i]` views, indexes into `[0]`/`[1]` arrays, constant indexes past a
             member array's declared size
  selfassign `x = x;`
  pragma     any `#pragma` other than the documented ones (PRAGMA_OK)
  noise      permuter shapes: `__typeof__`, `if (0)`/`if (1)`, `!!`, statement-level comma expressions, `(void)x;`,
             `register`, `goto`, permuter names (`temp_`, `var_`, `sp1c`, `pad`, `junk`, `dummy`, `fake`), no-op
             arithmetic (`+ 0`, `* 1`, `<< 0`), stacked integer casts
  comment    a comment inside or just above a matched function that says the shape is a trick ("junk", "fake",
             "hack", "trick", "permuter", "needed to match", "cast kept", ...)

--summary prints the hit count per category, --tsv prints tab-separated rows. The exit status is 1 when there is a
hit that is not in tools/honesty_allow.txt (0 otherwise), so the scanner can run in a check.

Labelled fakematches (round fkA, experimental): docs/FAKEMATCHES.md lists functions that match only through a trick.
A hit is a fakematch hit, not a failure, when (1) its file and function are a row of that table, (2) its category is
one of the row's categories (the "Scan categories" column; `comment` is always accepted, since the label itself
says "fake"), and (3) the function carries a `// FAKEMATCH:` comment (in its body or in the comments between the
previous function or preprocessor line and its head). Fakematch hits are hidden like allowed ones (--fake shows
them), counted separately in --summary and on stderr, and never change the exit status. Unlabelled tricks still
fail. Two consistency checks report as category `fakelist` and fail: a `FAKEMATCH:` comment in live code of a
function that is not in the table, and a table row whose function has no `FAKEMATCH:` comment in its file.
"""

import argparse
import os
import re
import sys
from collections import Counter, defaultdict

ROOT = os.path.dirname(os.path.dirname(os.path.abspath(__file__)))
EXTS = (".c", ".cpp", ".h", ".hpp", ".inc")

PRAGMA_OK = re.compile(
    r"#\s*pragma\s+(force_active|thumb|dont_reuse_strings|pool_strings|optimization_level|push|pop|section|"
    r"define_section|unused|unsigned_char|exceptions|ipa|once|optimize_for_size|opt_propagation)\b")

CATS = ["fakelist", "ptrbit", "volatile", "asm", "empty", "emptyloop", "deadstore", "unusedlocal", "unusedparam", "paramlocal", "arity", "onceloop", "oob", "selfassign", "pragma",
        "noise", "comment"]

# Triaged hits (round auA, docs/MATCHING.md), read from tools/honesty_allow.txt: tab-separated
# (category or "*", file suffix or a directory prefix ending in "/", text fragment or function name or "*", verdict).
# A hit is allowed when its category and file match and the fragment occurs in its text or is its function name.
ALLOW = []
_allow_path = os.path.join(os.path.dirname(os.path.abspath(__file__)), "honesty_allow.txt")


def load_allow():
    if not os.path.exists(_allow_path):
        return
    for ln in open(_allow_path, encoding="utf-8"):
        ln = ln.rstrip("\n")
        if not ln.strip() or ln.lstrip().startswith("#"):
            continue
        parts = ln.split("\t")
        if len(parts) < 4:
            continue
        ALLOW.append(tuple(parts[:4]))


FAKE = {}  # (file, function) -> set of accepted categories
FAKE_SEEN = set()  # (file, function) rows whose FAKEMATCH comment was found
_fake_path = os.path.join(ROOT, "docs", "FAKEMATCHES.md")


def load_fake():
    """Rows of the docs/FAKEMATCHES.md table: | Address | Module | Function | File | Scan categories | ... |"""
    if not os.path.exists(_fake_path):
        return
    for ln in open(_fake_path, encoding="utf-8"):
        cells = [c.strip().strip("`") for c in ln.strip().strip("|").split("|")]
        if len(cells) < 5 or not re.fullmatch(r"[0-9a-f]{8}", cells[0]):
            continue
        cats = {c.strip().strip("`") for c in cells[4].split(",") if c.strip()}
        FAKE[(cells[3], cells[2])] = cats | {"comment"}


def allowed(cat, path, func, text):
    for c, f, frag, _ in ALLOW:
        if c != cat and c != "*":
            continue
        if not (path.startswith(f) if f.endswith("/") else path.endswith(f)):
            continue
        if frag == "*" or frag in text or frag == func:
            return True
    return False


# ---------------------------------------------------------------------------------------------------------------
# Lexing helpers


def strip_comments(src):
    """Blank comments and string/char literals (keeping length and newlines). Returns (code, comments) where
    comments is a list of (offset, text)."""
    out = list(src)
    comments = []
    i, n = 0, len(src)
    while i < n:
        c = src[i]
        if c == "/" and i + 1 < n and src[i + 1] == "/":
            j = src.find("\n", i)
            j = n if j < 0 else j
            comments.append((i, src[i:j]))
            for k in range(i, j):
                out[k] = " "
            i = j
        elif c == "/" and i + 1 < n and src[i + 1] == "*":
            j = src.find("*/", i + 2)
            j = n if j < 0 else j + 2
            comments.append((i, src[i:j]))
            for k in range(i, j):
                if out[k] != "\n":
                    out[k] = " "
            i = j
        elif c in "\"'":
            j = i + 1
            while j < n and src[j] != c:
                if src[j] == "\\":
                    j += 1
                if j < n and src[j] == "\n":
                    break
                j += 1
            for k in range(i + 1, min(j, n)):
                if out[k] != "\n":
                    out[k] = "x" if c == '"' else "0"
            i = j + 1
        else:
            i += 1
    return "".join(out), comments


def preproc_regions(code):
    """Mark lines: 'draft' (NONMATCHING / #if 0 regions that the default build drops), 'macro' (#define bodies),
    'pp' (other preprocessor lines). Returns list of per-line tags (index = line number - 1)."""
    lines = code.split("\n")
    tags = [""] * len(lines)
    stack = []  # entries: True if this level is dropped
    i = 0
    while i < len(lines):
        s = lines[i].strip()
        dropped = any(stack)
        m = re.match(r"#\s*(\w+)(.*)", s)
        if m:
            d, rest = m.group(1), m.group(2)
            if d in ("ifdef", "if", "ifndef"):
                drop = False
                if d == "ifdef" and re.match(r"\s*NONMATCHING\b", rest):
                    drop = True
                elif d == "if" and re.search(r"\bNONMATCHING\b", rest) and "!" not in rest:
                    drop = True
                elif d == "if" and re.match(r"\s*0\s*$", rest):
                    drop = True
                stack.append(drop)
            elif d in ("else", "elif"):
                if stack:
                    stack[-1] = not stack[-1] if d == "else" else stack[-1]
            elif d == "endif":
                if stack:
                    stack.pop()
            tags[i] = "pp"
            if d == "define":
                tags[i] = "macro"
                while lines[i].rstrip().endswith("\\") and i + 1 < len(lines):
                    i += 1
                    tags[i] = "macro"
            if dropped:
                tags[i] = "draft"
        elif dropped:
            tags[i] = "draft"
        i += 1
    return tags


def match_paren(code, i, o="(", c=")"):
    depth = 0
    n = len(code)
    while i < n:
        ch = code[i]
        if ch == o:
            depth += 1
        elif ch == c:
            depth -= 1
            if depth == 0:
                return i
        i += 1
    return -1


CTRL = {"if", "for", "while", "switch", "catch", "return", "sizeof", "else", "do"}


def find_functions(code, tags, line_of):
    """Yield (name, params_text, body_start, body_end, head_start) for every function definition."""
    n = len(code)
    i = 0
    stmt_start = 0
    depth_stack = []  # 'f' function body, 'o' other scope
    funcs = []
    while i < n:
        ch = code[i]
        if ch == "#" and (i == 0 or code[i - 1] == "\n"):
            j = code.find("\n", i)
            while j > 0 and code[j - 1] == "\\":
                j = code.find("\n", j + 1)
            i = n if j < 0 else j
            stmt_start = i
            continue
        if ch in ";}":
            if ch == "}" and depth_stack:
                depth_stack.pop()
            i += 1
            stmt_start = i
            continue
        if ch == "{":
            head = code[stmt_start:i]
            hs = head.strip()
            kind = "o"
            m = None
            if "f" not in depth_stack:
                h2 = re.sub(r"\s+", " ", hs)
                # strip constructor initializer list
                h3 = re.sub(r"\)\s*:\s*[^{}]*$", ")", h2) if re.search(r"\)\s*:\s*\w", h2) else h2
                h3 = re.sub(r"\)\s*(const|throw\s*\(\s*\))\s*$", ")", h3)
                if h3.endswith(")") and "=" not in h3.split("(")[0]:
                    po = h3.rfind(")")
                    # find matching '(' for final ')'
                    depth = 0
                    k = po
                    while k >= 0:
                        if h3[k] == ")":
                            depth += 1
                        elif h3[k] == "(":
                            depth -= 1
                            if depth == 0:
                                break
                        k -= 1
                    pre = h3[:k].rstrip()
                    mm = re.search(r"([~\w:]+(?:operator\s*\S+)?)$", pre)
                    if mm and mm.group(1).split("::")[-1] not in CTRL and not re.match(r"^\s*(struct|class|enum|union)\b", pre):
                        kind = "f"
                        m = (mm.group(1), h3[k + 1:po])
            if kind == "f":
                end = match_paren(code, i, "{", "}")
                if end < 0:
                    end = n - 1
                funcs.append((m[0], m[1], i, end, stmt_start + (len(head) - len(head.lstrip()))))
                i = end + 1
                stmt_start = i
                continue
            depth_stack.append(kind)
            i += 1
            stmt_start = i
            continue
        i += 1
    return funcs


# ---------------------------------------------------------------------------------------------------------------
# Statement splitting (for dead stores and once-loops)


def split_block(body, base):
    """Split the inside of a { } block into top-level statements: list of (start, end, text, kind) where kind is
    'ctrl' for if/for/while/do/switch/else/label/case and 'stmt' otherwise; offsets are absolute (base + local)."""
    out = []
    i, n = 0, len(body)
    while i < n:
        while i < n and body[i] in " \t\n\r":
            i += 1
        if i >= n:
            break
        if body[i] == "#":
            j = body.find("\n", i)
            i = n if j < 0 else j
            continue
        m = re.match(r"(if|for|while|switch|do|else|case\b[^:]*:|default\s*:|\w+\s*:(?!:))", body[i:])
        if body[i] == "{":
            j = match_paren(body, i, "{", "}")
            j = n - 1 if j < 0 else j
            out.append((base + i, base + j + 1, body[i:j + 1], "block"))
            i = j + 1
            continue
        if m and re.match(r"(if|for|while|switch|do|else)\b", body[i:]):
            kw = re.match(r"\w+", body[i:]).group(0)
            j = i + len(kw)
            if kw in ("if", "for", "while", "switch"):
                p = body.find("(", j)
                j = match_paren(body, p) + 1
            # following statement
            k = j
            while k < n and body[k] in " \t\n\r":
                k += 1
            if kw == "while" and k < n and body[k] == ";":
                out.append((base + i, base + k + 1, body[i:k + 1], "ctrl"))
                i = k + 1
                continue
            if k < n and body[k] == "{":
                e = match_paren(body, k, "{", "}") + 1
            else:
                e = end_of_stmt(body, k)
            # an `if` may be followed by `else`
            out.append((base + i, base + e, body[i:e], "ctrl"))
            i = e
            continue
        if m and (m.group(0).startswith("case") or m.group(0).startswith("default") or re.match(r"\w+\s*:$", m.group(0))):
            e = i + len(m.group(0))
            out.append((base + i, base + e, body[i:e], "ctrl"))
            i = e
            continue
        e = end_of_stmt(body, i)
        out.append((base + i, base + e, body[i:e], "stmt"))
        i = e
    return out


def end_of_stmt(s, i):
    depth = 0
    n = len(s)
    while i < n:
        c = s[i]
        if c in "([{":
            depth += 1
        elif c in ")]}":
            depth -= 1
            if depth < 0:
                return i
        elif c == ";" and depth == 0:
            return i + 1
        i += 1
    return n


def iter_blocks(code, start, end):
    """Yield (inner_start, inner_end) for the function body and every nested { } block."""
    yield start + 1, end
    for m in re.finditer(r"\{", code[start + 1:end]):
        j = start + 1 + m.start()
        e = match_paren(code, j, "{", "}")
        if e > 0:
            yield j + 1, e


# ---------------------------------------------------------------------------------------------------------------

ID = r"[A-Za-z_]\w*"
INT_T = r"(?:u8|u16|u32|s8|s16|s32|u64|s64|int|unsigned(?:\s+int|\s+long|\s+short|\s+char)?|long|short|char|uintptr_t|intptr_t|size_t|BOOL|bool|fx32|fx16)"
HW = re.compile(r"0x0[34][0-9a-fA-F]{6}|0x027[fF]|0x02[fF]{2}|0x0380|0x01[fF]{2}[0-9a-fA-F]{4}|\bREG_|\bHW_|\bGX_|reg_|OS_IE|OS_IME|0x[0-9a-fA-F]*[0-9a-fA-F]{7}\b")
COMMENT_KW = re.compile(r"\b(junk|fake|hack|trick|permuter|perm(?:uted)?\s+output|needed (?:to|for) (?:the )?match|"
                        r"for the match|to match\b|required to match|otherwise (?:the|it)|keeps? the (?:match|code)|"
                        r"cast (?:is )?(?:kept|needed)|no-op|noop|dummy|bogus|placebo|regalloc)\b", re.I)


def scan_file(path, args, results):
    src = open(path, encoding="utf-8", errors="replace").read()
    code, comments = strip_comments(src)
    tags = preproc_regions(code)
    line_starts = [0]
    for m in re.finditer("\n", code):
        line_starts.append(m.end())

    import bisect

    def line_of(off):
        return bisect.bisect_right(line_starts, off)

    def tag_of(off):
        return tags[line_of(off) - 1]

    def live(off):
        t = tag_of(off)
        return args.drafts or t != "draft"

    def line_text(off):
        ln = line_of(off)
        return src.split("\n")[ln - 1].strip() if False else _lines[ln - 1].strip()

    _lines = src.split("\n")
    rel = os.path.relpath(path, ROOT)
    funcs = find_functions(code, tags, line_of)
    func_spans = [(b0, b1, name) for name, _, b0, b1, _ in funcs]

    def func_at(off):
        for b0, b1, name in func_spans:
            if b0 <= off <= b1:
                return name
        return "-"

    # Fakematch labels (round fkA): a live `FAKEMATCH:` comment belongs to the function whose body holds it, or to
    # the next function when it sits in the comment run between the previous function / preprocessor line and
    # that function's head.
    marked = set()
    heads = sorted((hs, b1, name) for name, _, b0, b1, hs in funcs)
    for coff, ctext in comments:
        if "FAKEMATCH:" not in ctext or not live(coff):
            continue
        owner = None
        for hs, b1, name in heads:
            if coff <= b1:
                if coff >= hs:
                    owner = name
                else:
                    gap = code[coff:hs]
                    if not re.search(r"^[ \t]*#|[;}]", gap, re.M):
                        owner = name
                break
        if owner is None:
            continue
        marked.add(owner)
        if (rel, owner) in FAKE:
            FAKE_SEEN.add((rel, owner))
        else:
            results.append(("fakelist", rel, line_of(coff), owner,
                            "FAKEMATCH comment in a function that is not in docs/FAKEMATCHES.md", False))

    def add(cat, off, text=None, func=None):
        if not live(off):
            return
        ln = line_of(off)
        t = (text if text is not None else _lines[ln - 1].strip())[:160]
        f = func or func_at(off)
        al = allowed(cat, rel, f, t)
        if not al and f in marked and cat in FAKE.get((rel, f), ()):
            al = "fake"
        results.append((cat, rel, ln, f, t, al))

    # pragma (file level)
    for m in re.finditer(r"^[ \t]*#\s*pragma\b.*$", code, re.M):
        if not PRAGMA_OK.match(m.group(0).strip()):
            add("pragma", m.start())

    # asm anywhere (except asm-function bodies are reported once at the head)
    for m in re.finditer(r"\b(asm|__asm__|__asm)\b", code):
        if tag_of(m.start()) in ("macro",):
            continue
        add("asm", m.start())

    # volatile anywhere in live code (headers too)
    for m in re.finditer(r"\bvolatile\b|\bv[us](?:8|16|32|64)\b", code):
        ln = line_of(m.start())
        stmt = _lines[ln - 1]
        if HW.search(stmt):
            continue
        add("volatile", m.start())

    # comments in or just above live functions
    for off, text in comments:
        if not COMMENT_KW.search(text):
            continue
        f = func_at(off)
        if f == "-":
            # just above a function head (within 3 lines)
            ln = line_of(off)
            nxt = [name for name, _, b0, b1, hs in funcs if 0 <= line_of(hs) - ln <= 3]
            if not nxt:
                continue
            f = nxt[0]
        m = COMMENT_KW.search(text)
        add("comment", off + m.start(), text.strip()[:160], f)

    # out-of-bounds views (anywhere in live code)
    for m in re.finditer(r"\[\s*-\s*(?:0x)?[0-9]+\s*\]", code):
        add("oob", m.start())
    for m in re.finditer(r"\(\s*&\s*[\w.>\-\[\]]+\s*\)\s*\[", code):
        add("oob", m.start())
    for m in re.finditer(r"\(\s*\(\s*[\w\s]+\*\s*\)\s*&[^;()]*\)\s*\[\s*(?!0\s*\])", code):
        add("oob", m.start())

    # self-assignment
    for m in re.finditer(r"(?<![\w.>=!<+\-*/&|^%])\s*([A-Za-z_][\w.\[\]]*(?:->\w+)*)\s*=\s*\1\s*;", code):
        add("selfassign", m.start(1))

    # noise
    noise = [
        (r"\b__typeof__\b|\btypeof\b", None),
        (r"\bif\s*\(\s*[01]\s*\)", None),
        (r"!!", None),
        (r"\(void\)\s*\w+\s*;", None),
        (r"\bregister\b", None),
        (r"\bgoto\b", None),
        (r"\b(temp_[a-z]\w*|var_[a-z]\w*|sp[0-9A-F]{1,3}|junk\w*|dummy\w*|fake\w*)\b", None),
        (r"[^\w.](?:\+|-|\|)\s*0\s*[;)]|\*\s*1\s*[;)]|<<\s*0\s*[;)]|>>\s*0\s*[;)]", None),
        (r"\(\s*" + INT_T + r"\s*\)\s*\(\s*" + INT_T + r"\s*\)", None),
        (r"\bwhile\s*\(\s*0\s*\)", "w0"),
    ]
    for rx, tag in noise:
        if tag == "w0":
            continue  # handled under onceloop
        for name, params, b0, b1, hs in funcs:
            if not live(b0) or re.match(r"\s*(static\s+)?asm\b", code[hs:b0]):
                continue
            for m in re.finditer(rx, code[hs:b1]):
                if tag_of(hs + m.start()) == "macro":
                    continue
                add("noise", hs + m.start(), func=name)

    # do { } while (0) outside macros
    for m in re.finditer(r"\bwhile\s*\(\s*0\s*\)\s*;", code):
        if tag_of(m.start()) == "macro":
            continue
        add("onceloop", m.start())

    # per-function checks
    member_arrays = args._member_arrays
    for name, params, b0, b1, hs in funcs:
        if not live(b0):
            continue
        body = code[b0 + 1:b1]
        # asm function
        # ptrbit: pointer operand
        ptrs = set(["self", "this"])
        for pm in re.finditer(r"\*+\s*(?:const\s+)?(" + ID + r")\s*(?=[,;=)\[])", params + ";" + body):
            ptrs.add(pm.group(1))
        for m in re.finditer(r"\(\s*" + INT_T + r"\s*\)\s*\(?\s*(&?\s*" + ID + r"(?:\s*(?:->|\.)\s*\w+)*)\s*\)?\s*&\s*((?:0x)?[0-9a-fA-F]+)\b", body):
            opnd = m.group(1).replace(" ", "")
            base = re.match(r"&?(\w+)", opnd).group(1)
            is_ptr = opnd.startswith("&") or (base in ptrs and "->" not in opnd and "." not in opnd)
            if is_ptr:
                add("ptrbit", b0 + 1 + m.start(), func=name)
        # empty bodies
        for m in re.finditer(r"\b(if|while|for)\s*\(", body):
            if m.group(1) == "while":
                # skip do-while tail
                before = body[:m.start()].rstrip()
                if before.endswith("}"):
                    # find the matching '{' and check for 'do'
                    k = len(before) - 1
                    depth = 0
                    while k >= 0:
                        if before[k] == "}":
                            depth += 1
                        elif before[k] == "{":
                            depth -= 1
                            if depth == 0:
                                break
                        k -= 1
                    if before[:k].rstrip().endswith("do"):
                        continue
            p = m.end() - 1
            q = match_paren(body, p)
            if q < 0:
                continue
            rest = body[q + 1:q + 40]
            if re.match(r"\s*(;|\{\s*\})", rest):
                add("empty" if m.group(1) == "if" else "emptyloop", b0 + 1 + m.start(), func=name)
        for m in re.finditer(r"\belse\s*(;|\{\s*\})", body):
            add("empty", b0 + 1 + m.start(), func=name)
        # unused params
        asmfn = re.search(r"\basm\s+[\w\s\*]*$", code[hs:b0].split("(")[0] + " ") is not None or re.match(r"\s*(static\s+)?asm\b", code[hs:b0]) is not None
        plist = [p.strip() for p in split_params(params)]
        for p in ([] if asmfn else plist):
            if p in ("", "void", "...") or "(" in p and "*" in p and ")" in p and not re.search(r"\(\s*\*\s*\w+\s*\)", p):
                continue
            pm = re.search(r"\(\s*\*\s*(\w+)\s*\)", p) or re.search(r"(" + ID + r")\s*(?:\[[^\]]*\])?\s*(?:=.*)?$", p)
            if not pm:
                continue
            pn = pm.group(1)
            toks = re.findall(ID, re.sub(r"=.*$", "", p))
            if len(toks) < 2 and not re.search(r"\(\s*\*\s*\w+\s*\)", p):
                continue  # unnamed parameter
            if pn in ("const", "unsigned", "signed", "struct", "int", "char", "long", "short", "void") or pn in KNOWN_TYPES:
                continue
            first = re.search(r"\b" + re.escape(pn) + r"\b", body)
            if not first:
                add("unusedparam", hs, "%s: param `%s` unused" % (re.sub(r"\s+", " ", code[hs:b0]).strip()[:100], pn), name)
            elif (re.match(r"\s*=(?!=)", body[first.end():first.end() + 4])
                  and not re.search(r"(\*|\.|->|\))\s*$", body[max(0, first.start() - 3):first.start()])
                  and not re.search(r"\b" + re.escape(pn) + r"\b", body[first.end():].split(";")[0])):
                add("paramlocal", b0 + 1 + first.start(), "param `%s` is assigned before it is read: %s" % (pn, body[first.start():first.start() + 70].split(";")[0]), name)
        if not asmfn and name in args._decls:
            n_def = len([q for q in plist if q not in ("", "void")])
            other = sorted(set(args._decls[name]) - {n_def})
            if other and "..." not in params:
                add("arity", hs, "%s defined with %d params, declared elsewhere with %s" % (name, n_def, other), name)
        locs = local_vars(code, b0, b1)
        # once-loops and dead stores
        for ib, ie in iter_blocks(code, b0, b1):
            stmts = split_block(code[ib:ie], ib)
            for k, (s0, s1, txt, kind) in enumerate(stmts):
                if kind == "ctrl" and re.match(r"(for|while|do)\b", txt):
                    lb = txt.find("{")
                    if lb >= 0 and (txt.startswith("do") or lb > txt.find(")")):
                        inner = txt[lb + 1:match_paren(txt, lb, "{", "}")]
                        sub = split_block(inner, 0)
                        if sub and re.match(r"break\s*;", sub[-1][2].strip()) and "continue" not in inner:
                            add("onceloop", s0, func=name)
            dead_stores(stmts, add, name, body, locs)
        # locals assigned but never read
        locs = local_vars(code, b0, b1)
        macro_text = " ".join(code.split("\n")[i] for i, t in enumerate(tags) if t == "macro")
        for v, doff in locs.items():
            if re.search(r"\b" + re.escape(v) + r"\b", macro_text):
                continue  # used by a macro the body expands
            reads = writes = 0
            for o in re.finditer(r"\b" + re.escape(v) + r"\b", body):
                ao = b0 + 1 + o.start()
                if ao == doff:
                    continue
                pre = body[max(0, o.start() - 3):o.start()]
                if re.search(r"(\.|->|::)\s*$", pre):
                    continue  # a member of the same name
                if re.match(r"\s*=(?!=)", body[o.end():o.end() + 4]) and not re.search(r"\*\s*$", pre):
                    writes += 1
                    continue
                reads += 1
                break
            init = re.match(r"\s*=", code[doff + len(v):doff + len(v) + 4])
            if reads == 0 and writes == 0 and not init:
                add("unusedlocal", doff, "local `%s` is declared and never used" % v, name)
            elif reads == 0:
                add("deadstore", doff, "local `%s` is written and never read" % v, name)
        # member-array index past declared size, or into [0]/[1] arrays
        for m in re.finditer(r"(?:->|\.)\s*(\w+)\s*\[\s*([^\]]+?)\s*\]", body):
            mem, idx = m.group(1), m.group(2)
            sizes = member_arrays.get(mem)
            if not sizes:
                continue
            try:
                iv = int(idx, 0)
            except ValueError:
                iv = None
            known = [s for s in sizes if s is not None]
            if iv is not None:
                if known and all(iv >= s for s in known):
                    add("oob", b0 + 1 + m.start(), func=name)
            elif all(s is not None and s <= 1 for s in sizes):
                add("oob", b0 + 1 + m.start(), func=name)
        for m in re.finditer(r"\b(?:" + INT_T + r"|" + ID + r")\s+(\w+)\s*\[\s*1\s*\]\s*;", body):
            add("oob", b0 + 1 + m.start(), "one-element local array `%s`" % m.group(1), name)


KNOWN_TYPES = set()


def split_params(p):
    out, depth, cur = [], 0, ""
    for i, c in enumerate(p):
        if c in "([{" or (c == "<" and p[i + 1:i + 2] != "<" and p[i - 1:i] != "<"):
            depth += 1
        elif c in ")]}" or (c == ">" and p[i - 1:i] not in ("-", ">") and p[i + 1:i + 2] != ">"):
            depth -= 1
        if c == "," and depth == 0:
            out.append(cur)
            cur = ""
        else:
            cur += c
    out.append(cur)
    return out


DECL_KW = {"return", "delete", "goto", "else", "case", "new", "throw", "break", "continue", "do", "if", "for",
           "while", "switch", "sizeof", "typedef", "using", "default"}


def local_vars(code, b0, b1):
    """Plain scalar/pointer locals declared in the body: {name: offset of the name}. Arrays, statics and locals
    whose address is taken are left out."""
    out = {}
    body = code[b0 + 1:b1]
    for ib, ie in iter_blocks(code, b0, b1):
        for s0, s1, txt, kind in split_block(code[ib:ie], ib):
            if kind != "stmt":
                continue
            t = txt.strip()
            m = re.match(r"((?:const\s+|volatile\s+|struct\s+|unsigned\s+|signed\s+)*)(" + ID + r"(?:::" + ID + r")*)\s*([*&\s]+)(.*);$", t, re.S)
            if not m or m.group(2) in DECL_KW or "static" in m.group(1):
                continue
            if not (re.fullmatch(INT_T, m.group(2)) or m.group(2) in KNOWN_TYPES or m.group(2) in ("void", "float", "double")):
                continue
            rest = m.group(3).replace(" ", "").replace("\n", "") + m.group(4)
            for part in split_params(rest):
                pm = re.match(r"\s*[*&\s]*(" + ID + r")\s*(=|$)", part)
                if not pm:
                    continue
                v = pm.group(1)
                if re.search(r"&\s*" + v + r"\b", body):
                    continue
                off = code.find(v, s0 + len(m.group(1)) + len(m.group(2)))
                out.setdefault(v, off)
    return out


def dead_stores(stmts, add, name, body, locs):
    """x = A; ... x = B; with no read of x and no control flow in between (straight line in one block)."""
    for k, (s0, s1, txt, kind) in enumerate(stmts):
        if kind != "stmt":
            continue
        m = re.match(r"(?:" + INT_T + r"\s+|" + ID + r"\s+\**)?(" + ID + r")\s*=(?!=)([^;]*);", txt.strip())
        if not m:
            continue
        v = m.group(1)
        if v not in locs or re.search(r"\b" + v + r"\b", m.group(2)):
            continue
        rhs = m.group(2).strip()
        # v = E; if (C) v = E;   (the two-definition trick in any form)
        if k + 1 < len(stmts) and stmts[k + 1][3] == "ctrl":
            mm = re.match(r"if\s*\(.*\)\s*\{?\s*" + v + r"\s*=\s*(.*?);\s*\}?$", stmts[k + 1][2].strip(), re.S)
            if mm and mm.group(1).strip() == rhs and "else" not in stmts[k + 1][2]:
                add("deadstore", s0, "`%s` set twice to the same value: %s" % (v, stmts[k + 1][2].strip()[:80]), name)
        for s0b, s1b, txt2, kind2 in stmts[k + 1:]:
            if kind2 != "stmt":
                break
            m2 = re.match(r"(" + ID + r")\s*=(?!=)([^;]*);", txt2.strip())
            if m2 and m2.group(1) == v and not re.search(r"\b" + v + r"\b", m2.group(2)):
                add("deadstore", s0, "`%s` overwritten: %s / %s" % (v, txt.strip()[:60], txt2.strip()[:60]), name)
                break
            if re.search(r"\b" + v + r"\b", txt2) or re.search(r"&\s*" + v, txt2):
                break
            if re.search(r"\w+\s*\(", txt2) and not re.search(r"\bsizeof\s*\(", txt2):
                # a call may read x through a pointer only if x's address was taken; stay conservative
                if re.search(r"&\s*" + v + r"\b", body):
                    break


def collect_decls(files):
    """{function name: [parameter counts of its prototypes (declarations ending in `;`)]} over the tree."""
    decls = defaultdict(list)
    rx = re.compile(r"(?:^|[;}\n])\s*(?:extern\s+(?:\"C\"\s+)?)?(?:static\s+)?(?:inline\s+)?(?:const\s+)?(?:struct\s+)?\w+[\s\*&]+(\w+)\s*\(([^;{}()]*)\)\s*;")
    for f in files:
        code, _ = strip_comments(open(f, encoding="utf-8", errors="replace").read())
        tags = preproc_regions(code)
        lines = code.split("\n")
        code = "\n".join("" if t in ("draft", "macro") else l for l, t in zip(lines, tags))
        for m in rx.finditer(code):
            name, ps = m.group(1), m.group(2).strip()
            if name in CTRL or name in ("return",):
                continue
            n = 0 if ps in ("", "void") else len(split_params(ps))
            if "..." in ps:
                continue
            decls[name].append(n)
    return decls


def collect_member_arrays(files):
    sizes = defaultdict(set)
    for f in files:
        if not f.endswith((".h", ".hpp", ".cpp", ".c")):
            continue
        code, _ = strip_comments(open(f, encoding="utf-8", errors="replace").read())
        for m in re.finditer(r"^\s*(?:const\s+)?(?:struct\s+)?(\w+)\s*\**\s*(\w+)\s*\[\s*([^\]]*)\s*\]\s*(?:\[[^\]]*\]\s*)*;", code, re.M):
            n = m.group(3)
            try:
                s = int(n, 0)
            except ValueError:
                s = None
            sizes[m.group(2)].add(s)
        for m in re.finditer(r"\btypedef\s+(?:struct|union|enum)?\s*\w*\s*\{?[^;]*?\b(\w+)\s*;", code):
            pass
        for m in re.finditer(r"\btypedef\b[^;{]*?(\w+)\s*;", code):
            KNOWN_TYPES.add(m.group(1))
        for m in re.finditer(r"\}\s*(\w+)\s*;", code):
            KNOWN_TYPES.add(m.group(1))
        for m in re.finditer(r"\b(?:struct|class|union|enum)\s+(\w+)", code):
            KNOWN_TYPES.add(m.group(1))
    return sizes


def main():
    ap = argparse.ArgumentParser(description=__doc__.split("\n")[0])
    ap.add_argument("paths", nargs="*")
    ap.add_argument("--cat", default="")
    ap.add_argument("--all", action="store_true", help="also show hits listed in tools/honesty_allow.txt")
    ap.add_argument("--drafts", action="store_true", help="also scan NONMATCHING / #if 0 blocks")
    ap.add_argument("--fake", action="store_true", help="also show labelled fakematch hits (docs/FAKEMATCHES.md)")
    ap.add_argument("--summary", action="store_true")
    ap.add_argument("--tsv", action="store_true")
    args = ap.parse_args()
    load_allow()
    load_fake()
    paths = args.paths or [os.path.join(ROOT, d) for d in ("src", "libs", "include")]
    files = []
    for p in paths:
        if os.path.isfile(p):
            files.append(os.path.abspath(p))
        else:
            for dp, _, fs in os.walk(p):
                for f in sorted(fs):
                    if f.endswith(EXTS) and not f.startswith("_dc_"):
                        files.append(os.path.join(dp, f))
    allfiles = []
    for d in ("src", "libs", "include"):
        for dp, _, fs in os.walk(os.path.join(ROOT, d)):
            allfiles += [os.path.join(dp, f) for f in fs if f.endswith(EXTS)]
    args._member_arrays = collect_member_arrays(allfiles)
    args._decls = collect_decls(allfiles)
    cats = set(args.cat.split(",")) if args.cat else set(CATS)
    results = []
    for f in sorted(files):
        scan_file(f, args, results)
    seen = set()
    shown = []
    for r in results:
        key = r[:4] + (r[4],)
        if key in seen or r[0] not in cats:
            continue
        seen.add(key)
        if r[5] == "fake" and (args.fake or args.all):
            shown.append(r)
            continue
        if r[5] and not args.all:
            continue
        shown.append(r)
    if not args.paths:
        for (rel, fn) in sorted(set(FAKE) - FAKE_SEEN):
            r = ("fakelist", rel, 0, fn, "docs/FAKEMATCHES.md row without a FAKEMATCH comment in its file", False)
            results.append(r)
            if "fakelist" in cats:
                shown.append(r)
    fake_hits = [r for r in results if r[5] == "fake" and r[0] in cats]
    fake_funcs = {(r[1], r[3]) for r in fake_hits}
    if args.summary:
        c = Counter(r[0] for r in shown)
        c = Counter(r[0] for r in shown if r[5] != "fake")
        a = Counter(r[0] for r in results if r[0] in cats and r[5] and r[5] != "fake")
        fk = Counter(r[0] for r in fake_hits)
        for cat in CATS:
            if cat in cats:
                print("%-12s %5d shown  %5d allowed  %5d fakematch" % (cat, c.get(cat, 0), a.get(cat, 0), fk.get(cat, 0)))
    else:
        for cat, rel, ln, f, t, al in shown:
            t = " ".join(t.split())
            if args.tsv:
                print("\t".join([cat, "%s:%d" % (rel, ln), f, t, "fakematch" if al == "fake" else "allowed" if al else ""]))
            else:
                print("%-11s %s:%d  %s  %s%s" % (cat, rel, ln, f, t, "  [fakematch]" if al == "fake" else "  [allowed]" if al else ""))
    if FAKE:
        print("fakematch: %d labelled hits in %d functions (docs/FAKEMATCHES.md, not failures; --fake shows them)"
              % (len(fake_hits), len(fake_funcs)), file=sys.stderr)
    return 1 if any(not r[5] for r in shown) else 0


if __name__ == "__main__":
    sys.exit(main())
