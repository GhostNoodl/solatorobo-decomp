#!/usr/bin/env python3

# Compiles one source file and diffs a function against the base ROM, without running the whole build.
#
#   python tools/match.py src/Main/Heap/GroupHeap.c func_0203053c
#   python tools/match.py src/ov000/Foo.cpp func_ov000_0214b1a0 --module ov000
#   python tools/match.py src/Main/Foo.c func_02030000 --all-compilers
#
# Branch targets are ignored, since they're only resolved at link time. Requires capstone and pyelftools.

from pathlib import Path
import argparse
import os
import struct
import subprocess
import sys
import tempfile

import capstone
import yaml
from elftools.elf.elffile import ELFFile

root_path = Path(__file__).parent.parent
sys.path.insert(0, str(root_path / "tools"))

parser = argparse.ArgumentParser(description="Diffs a compiled function against the base ROM")
parser.add_argument("source", type=Path)
parser.add_argument("function", help="Symbol name in the compiled object")
parser.add_argument("--module", default="main", help="main, itcm, dtcm or ovNNN")
parser.add_argument("--address", type=lambda x: int(x, 16), help="Address in the base ROM (default: taken from the name)")
parser.add_argument("--version", default="usa")
parser.add_argument("--compiler", default=None, help="Compiler version under tools/mwccarm (default: dsi/1.3, or the file's entry in mwcc_versions.py)")
parser.add_argument("--all-compilers", action="store_true", help="Only print a diff count for every compiler version")
parser.add_argument("--wine", default=str(root_path / "wibo"))
parser.add_argument("-q", "--quiet", action="store_true", help="Only print the number of differing instructions")
args = parser.parse_args()

CC_FLAGS = [
    "-O4,p", "-enum", "int", "-char", "signed", "-str", "noreuse", "-proc", "arm946e", "-gccext,on", "-fp", "soft",
    "-inline", "noauto", "-Cpp_exceptions", "off", "-RTTI", "off", "-interworking", "-w", "off", "-sym", "on",
    "-gccinc", "-nolink", "-msgstyle", "gcc", "-i", str(root_path / "include"), "-d", args.version,
]


def module_code() -> tuple[bytes, int]:
    extract = root_path / "extract" / args.version
    if args.module == "main":
        config = yaml.safe_load((extract / "arm9" / "arm9.yaml").read_text())
        return (extract / "arm9" / "arm9.bin").read_bytes(), config["base_address"]
    if args.module in ("itcm", "dtcm"):
        config = yaml.safe_load((extract / "arm9" / f"{args.module}.yaml").read_text())
        return (extract / "arm9" / f"{args.module}.bin").read_bytes(), config["base_address"]
    overlay_id = int(args.module.removeprefix("ov"))
    overlays = yaml.safe_load((extract / "arm9_overlays" / "overlays.yaml").read_text())["overlays"]
    overlay = next(o for o in overlays if o["id"] == overlay_id)
    return (extract / "arm9_overlays" / overlay["file_name"]).read_bytes(), overlay["base_address"]


def compile_function(compiler: str) -> tuple[bytes, bool, set[int]] | str:
    lang = "-lang=c++" if args.source.suffix == ".cpp" else "-lang=c"
    with tempfile.TemporaryDirectory() as temp_dir:
        out = os.path.join(temp_dir, "out.o")
        exe = root_path / "tools" / "mwccarm" / compiler / "mwccarm.exe"
        result = subprocess.run([args.wine, str(exe), *CC_FLAGS, lang, "-c", str(args.source), "-o", out],
                                capture_output=True, text=True)
        if not os.path.exists(out):
            return result.stdout + result.stderr
        with open(out, "rb") as f:
            elf = ELFFile(f)
            for symbol in elf.get_section_by_name(".symtab").iter_symbols():
                if symbol.name == args.function and symbol["st_info"]["type"] == "STT_FUNC":
                    start = symbol["st_value"] & ~1
                    section = elf.get_section(symbol["st_shndx"])
                    data = section.data()[start:start + symbol["st_size"]]
                    # Pool constants with relocations are only known at link time, so blank them in both copies
                    relocated = set()
                    for rel_section in elf.iter_sections():
                        if rel_section.header["sh_type"] in ("SHT_REL", "SHT_RELA") and \
                                rel_section.header["sh_info"] == symbol["st_shndx"]:
                            for reloc in rel_section.iter_relocations():
                                offset = reloc["r_offset"] - start
                                if 0 <= offset < len(data) and reloc["r_info_type"] == 2:  # R_ARM_ABS32
                                    relocated.add(offset)
                    return data, bool(symbol["st_value"] & 1), relocated
    return f"symbol {args.function} not found"


def disassemble(code: bytes, address: int, thumb: bool, relocated: set[int] = frozenset()) -> list[str]:
    md = capstone.Cs(capstone.CS_ARCH_ARM, capstone.CS_MODE_THUMB if thumb else capstone.CS_MODE_ARM)
    lines = []
    offset = 0
    step = 2 if thumb else 4
    while offset < len(code):
        if offset in relocated:
            lines.append(".word <reloc>")
            offset += 4
            continue
        ins = next(md.disasm(code[offset:offset + 4], address + offset, 1), None)
        if ins is None:
            word = struct.unpack_from("<H" if thumb else "<I", code, offset)[0]
            lines.append(f".word {word:#x}")
            offset += step
            continue
        text = f"{ins.mnemonic} {ins.op_str}"
        # Branch targets depend on where the linker puts things
        if ins.mnemonic.rstrip("sw.") in ("bl", "blx", "b") and ins.op_str.startswith("#"):
            text = ins.mnemonic
        lines.append(text)
        offset += ins.size
    return lines


def count_diffs(ours: list[str], theirs: list[str]) -> int:
    return sum(1 for i in range(max(len(ours), len(theirs)))
               if i >= len(ours) or i >= len(theirs) or ours[i] != theirs[i])


base_code, base_address = module_code()
address = args.address
if address is None:
    address = int(args.function.rsplit("_", 1)[-1], 16)

if args.all_compilers:
    for exe in sorted((root_path / "tools" / "mwccarm").glob("**/mwccarm.exe")):
        compiler = exe.parent.relative_to(root_path / "tools" / "mwccarm").as_posix()
        result = compile_function(compiler)
        if isinstance(result, str):
            print(f"{compiler:12} error: {result.strip().splitlines()[-1] if result.strip() else '?'}")
            continue
        code, thumb, relocated = result
        theirs = base_code[address - base_address:address - base_address + len(code)]
        ours, theirs = disassemble(code, address, thumb, relocated), disassemble(theirs, address, thumb, relocated)
        print(f"{compiler:12} {count_diffs(ours, theirs)} diffs", flush=True)
    exit(0)

if args.compiler is None:
    from mwcc_versions import FILE_MWCC_VERSIONS
    try:
        relative_source = Path(os.path.relpath(args.source.resolve(), root_path.resolve())).as_posix()
    except ValueError:
        relative_source = None
    args.compiler = FILE_MWCC_VERSIONS.get(relative_source, "dsi/1.3")
result = compile_function(args.compiler)
if isinstance(result, str):
    print(result)
    exit(1)
code, thumb, relocated = result
theirs_code = base_code[address - base_address:address - base_address + len(code)]
ours, theirs = disassemble(code, address, thumb, relocated), disassemble(theirs_code, address, thumb, relocated)
diffs = count_diffs(ours, theirs)
if args.quiet:
    print(diffs)
    exit(0 if diffs == 0 else 1)
step = 2 if thumb else 4
for i in range(max(len(ours), len(theirs))):
    a = ours[i] if i < len(ours) else ""
    b = theirs[i] if i < len(theirs) else ""
    print(f"{'  ' if a == b else '!!'} {address + i * step:08x}  {a:40} | {b}")
print(f"{diffs} differing instructions" if diffs else "Match!")
exit(0 if diffs == 0 else 1)
