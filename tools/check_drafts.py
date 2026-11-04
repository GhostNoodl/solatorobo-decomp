#!/usr/bin/env python3

# Compiles every NONMATCHING draft and (with --score) scores it against the base ROM.
#
#   python tools/check_drafts.py                 # compile every file that has a NONMATCHING block
#   python tools/check_drafts.py --score         # also score each draft against docs/UNMATCHED.md
#   python tools/check_drafts.py --score src/ov010/ov010_02203ff4.cpp
#
# The default build leaves the `#ifdef NONMATCHING` blocks out, so a refactor (a retyped struct, a rename, a header
# change) can break a draft without the build noticing. Run this after such a change.
#
# Each file is compiled with its exact command from build.ninja (compiler version, flags, include paths), with
# NONMATCHING defined, into a temporary directory. The copy sits next to the original so that relative includes
# resolve, and is removed afterwards. Run `ninja` first: the draft functions are the functions the NONMATCHING
# object defines and the built object (build/<version>/...) does not.
#
# --score counts the differing instruction lines the way tools/match.py does (branch targets and pool words with
# relocations ignored), raw and with every register name masked, and compares them with the "Raw / masked" column of
# docs/UNMATCHED.md. A draft that scores worse than its entry is a regression. The ROM code is read from
# extract/<version> at run time; nothing derived from it is written anywhere.
#
# Fakematches (round fkA, experimental): a function listed in docs/FAKEMATCHES.md is matched in the default build by
# a labelled trick (the `#else` branch) and keeps its honest draft in the NONMATCHING branch. That draft is scored too,
# against the table's "Honest draft" column, although the built object also defines the function.

from concurrent.futures import ThreadPoolExecutor
from pathlib import Path
import argparse
import os
import re
import shlex
import shutil
import struct
import subprocess
import sys
import tempfile

root_path = Path(__file__).resolve().parent.parent

NONMATCHING_RE = re.compile(r"^\s*#\s*(ifdef\s+NONMATCHING\b|if\s+.*\bNONMATCHING\b)", re.M)
REG_RE = re.compile(r"\b(r\d+|ip|lr|sl|fp|sb)\b")


def find_draft_files(paths: list[Path]) -> list[Path]:
    files = []
    for base in paths:
        candidates = [base] if base.is_file() else sorted(p for p in base.rglob("*") if p.suffix in (".c", ".cpp"))
        for path in candidates:
            if path.name.startswith("_dc_"):
                continue
            if NONMATCHING_RE.search(path.read_text(errors="replace")):
                files.append(path)
    return files


def ninja_command(obj: str) -> list[str]:
    result = subprocess.run(["ninja", "-t", "commands", obj], cwd=root_path, capture_output=True, text=True)
    if result.returncode != 0 or not result.stdout.strip():
        raise RuntimeError(f"no build.ninja command for {obj} (run tools/configure.py first)")
    command = result.stdout.strip().splitlines()[-1].split("&&")[0]
    tokens = shlex.split(command)
    if tokens[0].endswith(".py"):
        tokens.insert(0, sys.executable)
    return tokens


def compile_draft(source: Path, version: str, out_dir: str) -> tuple[Path | None, str]:
    """Compiles source with NONMATCHING defined. Returns (object path or None, compiler output)."""
    rel = source.relative_to(root_path)
    tokens = ninja_command(str(Path("build") / version / rel.with_suffix(".o")))
    tmp_source = source.parent / f"_dc_{os.getpid()}_{source.name}"
    # A #define line rather than -D, so that the code is the same as tools/match.py on a `#define NONMATCHING` copy;
    # #line keeps the compiler's line numbers and file name those of the original.
    tmp_source.write_text(f'#define NONMATCHING\n#line 1 "{rel.as_posix()}"\n' + source.read_text(errors="replace"))
    try:
        c = tokens.index("-c")
        tokens[c + 1] = str(tmp_source.relative_to(root_path))
        o = tokens.index("-o")
        tokens[o + 1] = out_dir
        if "-MD" in tokens:
            tokens.remove("-MD")
        result = subprocess.run(tokens, cwd=root_path, capture_output=True, text=True)
    finally:
        tmp_source.unlink(missing_ok=True)
    obj = Path(out_dir) / tmp_source.with_suffix(".o").name
    output = (result.stdout + result.stderr).replace(tmp_source.name, source.name)
    if result.returncode != 0 or not obj.exists():
        return None, output
    return obj, output


def functions(obj: Path) -> dict[str, tuple[bytes, bool, set[int]]]:
    from elftools.elf.elffile import ELFFile
    funcs = {}
    with open(obj, "rb") as f:
        elf = ELFFile(f)
        relocs: dict[int, list[int]] = {}
        for section in elf.iter_sections():
            if section.header["sh_type"] in ("SHT_REL", "SHT_RELA"):
                relocs.setdefault(section.header["sh_info"], []).extend(
                    r["r_offset"] for r in section.iter_relocations() if r["r_info_type"] == 2)  # R_ARM_ABS32
        for symbol in elf.get_section_by_name(".symtab").iter_symbols():
            if symbol["st_info"]["type"] != "STT_FUNC" or not isinstance(symbol["st_shndx"], int):
                continue
            start = symbol["st_value"] & ~1
            data = elf.get_section(symbol["st_shndx"]).data()[start:start + symbol["st_size"]]
            relocated = {r - start for r in relocs.get(symbol["st_shndx"], []) if 0 <= r - start < len(data)}
            funcs[symbol.name] = (data, bool(symbol["st_value"] & 1), relocated)
    return funcs


def disassemble(code: bytes, address: int, thumb: bool, relocated: set[int]) -> list[str]:
    # Same as tools/match.py
    import capstone
    md = capstone.Cs(capstone.CS_ARCH_ARM, capstone.CS_MODE_THUMB if thumb else capstone.CS_MODE_ARM)
    lines, offset, step = [], 0, 2 if thumb else 4
    while offset < len(code):
        if offset in relocated:
            lines.append(".word <reloc>")
            offset += 4
            continue
        ins = next(md.disasm(code[offset:offset + 4], address + offset, 1), None)
        if ins is None:
            lines.append(f".word {struct.unpack_from('<H' if thumb else '<I', code, offset)[0]:#x}")
            offset += step
            continue
        text = f"{ins.mnemonic} {ins.op_str}"
        if ins.mnemonic.rstrip("sw.") in ("bl", "blx", "b") and ins.op_str.startswith("#"):
            text = ins.mnemonic
        lines.append(text)
        offset += ins.size
    return lines


def count_diffs(ours: list[str], theirs: list[str]) -> int:
    return sum(1 for i in range(max(len(ours), len(theirs)))
               if i >= len(ours) or i >= len(theirs) or ours[i] != theirs[i])


class Rom:
    def __init__(self, version: str):
        import yaml
        self.yaml = yaml
        self.extract = root_path / "extract" / version
        self.config = root_path / "config" / version / "arm9"
        self.modules: dict[str, tuple[bytes, int]] = {}
        self.names: dict[str, tuple[str, int]] = {}
        for path in [self.config / "symbols.txt", *sorted(self.config.glob("*/symbols.txt")),
                     *sorted(self.config.glob("overlays/*/symbols.txt"))]:
            module = "main" if path.parent == self.config else path.parent.name
            for line in path.read_text().splitlines():
                m = re.match(r"(\S+) kind:function\S* addr:0x([0-9a-f]+)", line)
                if m:
                    self.names[m.group(1)] = (module, int(m.group(2), 16))

    def module(self, module: str) -> tuple[bytes, int]:
        if module not in self.modules:
            if module == "main" or module in ("itcm", "dtcm"):
                name = "arm9" if module == "main" else module
                config = self.yaml.safe_load((self.extract / "arm9" / f"{name}.yaml").read_text())
                self.modules[module] = (self.extract / "arm9" / f"{name}.bin").read_bytes(), config["base_address"]
            else:
                overlays = self.yaml.safe_load((self.extract / "arm9_overlays" / "overlays.yaml").read_text())
                o = next(o for o in overlays["overlays"] if o["id"] == int(module.removeprefix("ov")))
                self.modules[module] = (self.extract / "arm9_overlays" / o["file_name"]).read_bytes(), o["base_address"]
        return self.modules[module]

    def score(self, module: str, address: int, func: tuple[bytes, bool, set[int]]) -> tuple[int, int]:
        code, thumb, relocated = func
        base_code, base_address = self.module(module)
        theirs = base_code[address - base_address:address - base_address + len(code)]
        a, b = disassemble(code, address, thumb, relocated), disassemble(theirs, address, thumb, relocated)
        return count_diffs(a, b), count_diffs([REG_RE.sub("R", x) for x in a], [REG_RE.sub("R", x) for x in b])


def read_unmatched() -> dict[int, dict]:
    """Address -> {module, file, raw, masked} from the table in docs/UNMATCHED.md."""
    entries = {}
    path = root_path / "docs" / "UNMATCHED.md"
    for line in path.read_text().splitlines():
        cells = [c.strip().strip("`") for c in line.strip().strip("|").split("|")]
        if len(cells) < 5 or not re.fullmatch(r"[0-9a-f]{8}", cells[0]):
            continue
        m = re.match(r"(\d+)\s*/\s*(\d+)", cells[4])
        if m:
            entries[int(cells[0], 16)] = {"module": cells[1], "file": cells[3],
                                          "raw": int(m.group(1)), "masked": int(m.group(2))}
    return entries


def read_fakematches() -> dict[int, dict]:
    """Address -> {module, file, raw, masked, name} from the table in docs/FAKEMATCHES.md (round fkA): functions the
    default build matches with a labelled trick. Their honest draft (the NONMATCHING branch) is scored like an
    UNMATCHED.md row, although the built object also defines the function."""
    entries = {}
    path = root_path / "docs" / "FAKEMATCHES.md"
    if not path.exists():
        return entries
    for line in path.read_text().splitlines():
        cells = [c.strip().strip("`") for c in line.strip().strip("|").split("|")]
        if len(cells) < 6 or not re.fullmatch(r"[0-9a-f]{8}", cells[0]):
            continue
        m = re.match(r"(\d+)\s*/\s*(\d+)", cells[5])
        if m:
            entries[int(cells[0], 16)] = {"module": cells[1], "name": cells[2], "file": cells[3],
                                          "raw": int(m.group(1)), "masked": int(m.group(2))}
    return entries


def module_for(path: Path) -> str:
    first = path.relative_to(root_path).parts[1]
    return first if re.fullmatch(r"ov\d{3}", first) else "main"


def main():
    parser = argparse.ArgumentParser(description="Compiles (and scores) every NONMATCHING draft")
    parser.add_argument("paths", nargs="*", type=Path, help="Files or directories (default: src and libs)")
    parser.add_argument("--version", default="usa")
    parser.add_argument("--score", action="store_true", help="Score each draft against the ROM and docs/UNMATCHED.md")
    parser.add_argument("-j", "--jobs", type=int, default=2)
    parser.add_argument("-v", "--verbose", action="store_true", help="Print the full compiler output of failures")
    args = parser.parse_args()

    paths = [p.resolve() for p in args.paths] or [root_path / "src", root_path / "libs"]
    files = find_draft_files(paths)
    rom = Rom(args.version) if args.score else None
    unmatched = read_unmatched() if args.score else {}
    fakes = read_fakematches() if args.score else {}
    unmatched.update(fakes)
    fake_names = {(e["file"], e["name"]) for e in fakes.values()}
    temp_root = Path(tempfile.mkdtemp(prefix="check_drafts_"))

    def check(source: Path):
        out_dir = tempfile.mkdtemp(dir=temp_root)
        try:
            obj, output = compile_draft(source, args.version, out_dir)
            if obj is None or not args.score:
                return source, obj is not None, output, []
            built = root_path / "build" / args.version / source.relative_to(root_path).with_suffix(".o")
            known = set(functions(built)) if built.exists() else set()
            rel = source.relative_to(root_path).as_posix()
            drafts = {name: f for name, f in functions(obj).items() if name not in known or (rel, name) in fake_names}
            return source, True, output, sorted(drafts.items())
        finally:
            shutil.rmtree(out_dir, ignore_errors=True)

    failures = regressions = 0
    seen: set[int] = set()
    rows = []
    try:
        with ThreadPoolExecutor(args.jobs) as ex:
            for source, ok, output, drafts in ex.map(check, files):
                rel = source.relative_to(root_path).as_posix()
                if not ok:
                    failures += 1
                    errors = [l for l in output.splitlines() if re.search(r":\d+: ", l)] or output.strip().splitlines()[-1:]
                    print(f"FAIL  {rel}")
                    for line in (output.strip().splitlines() if args.verbose else errors[:10]):
                        print(f"        {line}")
                    continue
                if not args.score:
                    print(f"ok    {rel}")
                    continue
                file_entries = {a: e for a, e in unmatched.items() if e["file"] == rel}
                unresolved = []
                for name, func in drafts:
                    if name in rom.names:
                        module, address = rom.names[name]
                    elif m := re.search(r"_([0-9a-f]{8})$", name):
                        module, address = module_for(source), int(m.group(1), 16)
                    else:
                        unresolved.append((name, func))
                        continue
                    rows.append((rel, name, module, address, func))
                # A draft with an SDK name (CARDi_ReadRomWithCPU): the file's single remaining entry
                missing = [a for a in file_entries if a not in {r[3] for r in rows if r[0] == rel}]
                if len(unresolved) >= 1 and len(missing) == 1:
                    name, func = max(unresolved, key=lambda u: len(u[1][0]))
                    rows.append((rel, name, file_entries[missing[0]]["module"], missing[0], func))
                if not drafts:
                    print(f"ok    {rel}  (no draft function in the object)")
    finally:
        shutil.rmtree(temp_root, ignore_errors=True)

    if args.score:
        print(f"\n{'address':8}  {'module':6}  {'raw/masked':>10}  {'recorded':>8}  status  function / file")
        for rel, name, module, address, func in sorted(rows, key=lambda r: (r[2] != "main", r[2], r[3])):
            raw, masked = rom.score(module, address, func)
            entry = unmatched.get(address)
            seen.add(address)
            if entry is None:
                recorded, status = "-", "new" if raw else "MATCH"
            else:
                recorded = f"{entry['raw']}/{entry['masked']}"
                if raw > entry["raw"] or masked > entry["masked"]:
                    status = "WORSE"
                    regressions += 1
                elif raw < entry["raw"] or masked < entry["masked"]:
                    status = "better"
                else:
                    status = "same"
            print(f"{address:08x}  {module:6}  {f'{raw}/{masked}':>10}  {recorded:>8}  {status:6}  {name}  {rel}")
        def in_scope(file: str) -> bool:
            path = root_path / file
            return any(path == p or p in path.parents for p in paths)
        for address, entry in sorted(unmatched.items()):
            if address not in seen and in_scope(entry["file"]):
                regressions += 1
                print(f"{address:08x}  {entry['module']:6}  {'-':>10}  {entry['raw']}/{entry['masked']:<6}  "
                      f"NODRAFT {entry['file']}")

    print(f"\n{len(files)} files, {failures} failed to compile" +
          (f", {regressions} drafts worse than docs/UNMATCHED.md or missing" if args.score else ""))
    sys.exit(1 if failures or regressions else 0)


if __name__ == "__main__":
    main()
