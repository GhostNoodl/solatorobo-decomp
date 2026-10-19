#!/usr/bin/env python3

# Lists the strings and other data a function loads from its module's .data/.rodata, and the string pools they
# sit in, so you can write them as real string literals (see docs/MATCHING.md, "String literals").
#
#   python tools/strrefs.py ov006 func_ov006_021d3f04           # what one function loads
#   python tools/strrefs.py ov006 0x021d37d0 0x021d40a8         # everything a .text range loads
#   python tools/strrefs.py ov006 --pools                       # every string pool in the module
#   python tools/strrefs.py ov006 --claim 0x021ec080 0x021ec094 # turn a pool into one @stringBase0 symbol
#   python tools/strrefs.py ov006 --literalize src/ov006/foo.cpp # print foo.cpp with string symbols as literals
#
# A pool is a run of strings packed back to back, which is what one source file's literals compile to. For each
# string it prints the C literal and every function that loads it, marking functions not in any delinks.txt file
# with '*'. A file can only own a pool if it contains every function that loads a string in it, and the pool's
# first string is the first one the file uses.

from pathlib import Path
import argparse
import bisect
import re
import signal
import sys

import yaml

root_path = Path(__file__).parent.parent
signal.signal(signal.SIGPIPE, signal.SIG_DFL)

parser = argparse.ArgumentParser(description="Lists string literals and data loaded by functions")
parser.add_argument("module", help="main or ovNNN")
parser.add_argument("targets", nargs="*", help="Function names or addresses; two addresses give a .text range")
parser.add_argument("--pools", action="store_true", help="List every string pool in the module")
parser.add_argument("--claim", nargs=2, metavar=("START", "END"),
                    help="Rewrite symbols.txt and relocs.txt for a pool your file now compiles: rename the symbol at START "
                         "to @stringBase0 (local), drop the other symbols inside it and point loads at START plus an offset")
parser.add_argument("--literalize", metavar="SOURCE", type=Path,
                    help="Print SOURCE with every data symbol that names a string in .data replaced by its literal")
parser.add_argument("--version", default="usa")
args = parser.parse_args()

extract = root_path / "extract" / args.version
config = root_path / "config" / args.version / "arm9"
if args.module == "main":
    module_config = yaml.safe_load((extract / "arm9" / "arm9.yaml").read_text())
    code = (extract / "arm9" / "arm9.bin").read_bytes()
    base = module_config["base_address"]
    module_tag = "main"
else:
    overlay_id = int(args.module.removeprefix("ov"))
    overlays = yaml.safe_load((extract / "arm9_overlays" / "overlays.yaml").read_text())["overlays"]
    overlay = next(o for o in overlays if o["id"] == overlay_id)
    code = (extract / "arm9_overlays" / overlay["file_name"]).read_bytes()
    base = overlay["base_address"]
    config = config / "overlays" / args.module
    module_tag = f"overlay({overlay_id})"

functions: list[tuple[int, int, str]] = []
symbols: dict[int, str] = {}
pool_symbols: dict[int, int] = {}
for line in (config / "symbols.txt").read_text().splitlines():
    m = re.match(r"(\S+) kind:(\w+)(?:\((\w+)(?:,size=(0x[0-9a-f]+))?.*?\))? addr:(0x[0-9a-f]+)", line)
    if not m:
        continue
    addr = int(m[5], 16)
    if m[2] == "function":
        functions.append((addr, int(m[4], 16) if m[4] else 0, m[1]))
    elif m[2] in ("data", "bss"):
        symbols.setdefault(addr, m[1])
        if size := re.search(r"kind:data\(byte\[(0x[0-9a-f]+)\]\)", line):
            if m[1].startswith("@"):
                pool_symbols[addr] = int(size[1], 16)
functions.sort()
function_starts = [f[0] for f in functions]

sections: dict[str, tuple[int, int]] = {}
files: list[tuple[int, int, str]] = []
current = None
for line in (config / "delinks.txt").read_text().splitlines():
    if m := re.match(r"^(\S.*):$", line):
        current = m[1]
    elif m := re.match(r"\s+(\.\w+)\s+start:(0x\w+) end:(0x\w+)", line):
        start, end = int(m[2], 16), int(m[3], 16)
        if current is None:
            sections[m[1]] = (start, end)
        elif m[1] == ".text":
            files.append((start, end, current))

loads: dict[int, set[int]] = {}
for line in (config / "relocs.txt").read_text().splitlines():
    m = re.match(r"from:(0x\w+) kind:load to:(0x\w+)(?: add:(0x\w+))? module:(\S+)", line)
    if m and m[4] == module_tag:
        loads.setdefault(int(m[2], 16) + int(m[3] or "0", 16), set()).add(int(m[1], 16))


def function_at(addr: int) -> tuple[int, int, str] | None:
    i = bisect.bisect_right(function_starts, addr) - 1
    if i >= 0 and functions[i][0] <= addr < functions[i][0] + max(functions[i][1], 1):
        return functions[i]
    return None


def file_of(addr: int) -> str | None:
    return next((name for start, end, name in files if start <= addr < end), None)


def section_of(addr: int) -> str | None:
    return next((name for name, (start, end) in sections.items() if start <= addr < end), None)


def string_at(addr: int) -> bytes | None:
    off = addr - base
    if not 0 <= off < len(code):
        return None
    end = code.find(b"\0", off)
    if end < 0:
        return None
    s = code[off:end]
    printable = sum(32 <= c < 127 for c in s)
    if section_of(addr) == ".data":
        # Literals live in .data. Allow a few non-ASCII bytes (Shift-JIS text).
        return s if printable >= len(s) * 3 // 4 else None
    # In .rodata, only trust fully printable strings: most short runs there are numeric constants.
    return s if len(s) >= 2 and printable == len(s) else None


def c_literal(s: bytes) -> str:
    out = ""
    for c in s:
        ch = chr(c)
        if ch in '"\\':
            out += "\\" + ch
        elif ch == "\n":
            out += "\\n"
        elif 32 <= c < 127:
            out += ch
        else:
            out += f"\\x{c:02x}"
    return f'"{out}"'


def referrers(addr: int, limit: int = 12) -> str:
    names = []
    for f in sorted({function_at(a) or (a, 0, f"{a:#010x}") for a in loads.get(addr, ())}):
        names.append(f[2] + ("" if file_of(f[0]) else "*"))
    if len(names) > limit:
        names = names[:limit] + [f"and {len(names) - limit} more"]
    return ", ".join(names)


def symbol_name(addr: int) -> str:
    if addr in symbols:
        return symbols[addr]
    for start, size in pool_symbols.items():
        if start < addr < start + size:
            return f"{symbols[start]}+{addr - start:#x}"
    return "?"


def is_string_target(addr: int) -> bool:
    return section_of(addr) in (".data", ".rodata") and string_at(addr) is not None


def pool_runs() -> list[list[int]]:
    """Groups loaded strings into runs packed back to back (strings follow each other with no padding)."""
    targets = sorted(a for a in loads if is_string_target(a))
    runs: list[list[int]] = []
    for addr in targets:
        if runs:
            prev = runs[-1][-1]
            if prev + len(string_at(prev)) + 1 == addr:
                runs[-1].append(addr)
                continue
        runs.append([addr])
    return runs


def print_pool(run: list[int]) -> None:
    start = run[-1]
    end = start + len(string_at(start)) + 1
    print(f"pool {run[0]:#010x}..{end:#010x} in {section_of(run[0])}"
          + ("" if run[0] % 4 == 0 else "  (starts unaligned: the real pool starts earlier, or this is not a pool)"))
    for addr in run:
        aligned = "|" if addr % 4 == 0 else " "
        print(f"  {aligned}{addr:#010x} {symbol_name(addr):24} {c_literal(string_at(addr)):34} {referrers(addr)}")


def claim(start: int, end: int) -> None:
    symbols_path = config / "symbols.txt"
    lines = []
    for line in symbols_path.read_text().splitlines():
        m = re.search(r" addr:(0x[0-9a-f]+)", line)
        addr = int(m[1], 16) if m else None
        if addr == start and " kind:data" in line:
            old = line.split()[0]
            lines.append(f"@stringBase0 kind:data(byte[{end - start:#x}]) addr:{start:#010x} local")
            print(f"symbols.txt: {old} -> @stringBase0")
        elif addr is not None and start < addr < end and " kind:data" in line:
            print(f"symbols.txt: removed {line.split()[0]}")
        else:
            lines.append(line)
    symbols_path.write_text("\n".join(lines) + "\n")

    relocs_path = config / "relocs.txt"
    lines = []
    for line in relocs_path.read_text().splitlines():
        m = re.match(r"(from:0x\w+ kind:\w+) to:(0x\w+) (module:\S+)$", line)
        if m and m[3] == f"module:{module_tag}" and start < int(m[2], 16) < end:
            line = f"{m[1]} to:{start:#010x} add:{int(m[2], 16) - start:#x} {m[3]}"
            print(f"relocs.txt: {line}")
        lines.append(line)
    relocs_path.write_text("\n".join(lines) + "\n")


def literalize(source: Path) -> None:
    by_name = {name: addr for addr, name in symbols.items()}
    text = source.read_text()

    def literal_for(name: str) -> str | None:
        addr = by_name.get(name)
        if addr is None or section_of(addr) != ".data":
            return None
        s = string_at(addr)
        return c_literal(s) if s is not None else None

    out = []
    for line in text.splitlines():
        m = re.match(r"\s*extern\s+(?:const\s+)?(?:unsigned\s+|signed\s+)?char\s*(?:const\s*)?\*?\s*(\w+)\s*(\[\w*\])?\s*;\s*$", line)
        if m and literal_for(m[1]) is not None:
            continue
        line = re.sub(r"\b(data_\w+)\b", lambda m: literal_for(m[1]) or m[1], line)
        out.append(line)
    print("\n".join(out))


if args.literalize:
    literalize(args.literalize)
    sys.exit(0)

if args.claim:
    claim(*(int(a, 16) for a in args.claim))
    sys.exit(0)

if args.pools:
    for run in pool_runs():
        print_pool(run)
    sys.exit(0)

if not args.targets:
    parser.error("give a function, an address range or --pools")
if len(args.targets) == 2 and all(t.startswith("0x") for t in args.targets):
    lo, hi = (int(t, 16) for t in args.targets)
else:
    lo = hi = None
    picked = []
    for t in args.targets:
        f = next((f for f in functions if f[2] == t), None) if not t.startswith("0x") else function_at(int(t, 16))
        if f is None:
            sys.exit(f"Unknown function {t}")
        picked.append(f)

refs: dict[int, list[int]] = {}
for to, froms in loads.items():
    for a in froms:
        if lo is not None:
            hit = lo <= a < hi
        else:
            hit = any(f[0] <= a < f[0] + f[1] for f in picked)
        if hit:
            refs.setdefault(to, []).append(a)

runs = pool_runs()
shown_runs = set()
print("Loaded data:")
for to in sorted(refs):
    s = string_at(to) if is_string_target(to) else None
    desc = c_literal(s) if s is not None else "(not a string)"
    print(f"  {to:#010x} {section_of(to) or '-':8} {symbol_name(to):24} {desc:34} loaded by {referrers(to)}")
    for i, run in enumerate(runs):
        if to in run:
            shown_runs.add(i)
print()
for i in sorted(shown_runs):
    print_pool(runs[i])
