#!/usr/bin/env python3

# Tries every order of a function's leading local declarations and reports the closest match.
#
#   python tools/permute_decls.py src/Main/Heap/GroupHeap.c func_020305c8 "HeapGroup *group;" "HeapItem *item;" -- --module main
#
# The declarations must appear, one per line and in the given order, right after the function's opening brace.

from pathlib import Path
import itertools
import os
import re
import subprocess
import sys
import tempfile

root_path = Path(__file__).parent.parent

source, function = sys.argv[1:3]
rest = sys.argv[3:]
match_flags = rest[rest.index("--") + 1:] if "--" in rest else []
decls = rest[:rest.index("--")] if "--" in rest else rest

text = Path(source).read_text()
definition = re.search(r"^\w[^\n]*\b" + re.escape(function) + r"\([^;\n]*\)\s*\{\n", text, re.M)
if definition is None:
    print(f"Definition of {function} not found")
    exit(1)
body_start = definition.end()
block = "".join(f"    {decl}\n" for decl in decls)
if text[body_start:body_start + len(block)] != block:
    print("Declarations not found right after the opening brace, in the given order")
    exit(1)

best = None
fd, temp_path = tempfile.mkstemp(suffix=Path(source).suffix, dir=Path(source).parent)
os.close(fd)
try:
    for order in itertools.permutations(decls):
        Path(temp_path).write_text(text[:body_start] + "".join(f"    {d}\n" for d in order) + text[body_start + len(block):])
        out = subprocess.run([sys.executable, str(root_path / "tools" / "match.py"), temp_path, function, "-q", *match_flags],
                             capture_output=True, text=True).stdout.strip().splitlines()
        diffs = int(out[-1]) if out and out[-1].isdigit() else None
        print(diffs if diffs is not None else "error", order)
        if diffs is not None and (best is None or diffs < best[0]):
            best = (diffs, order)
finally:
    os.remove(temp_path)
print("Best:", best)
