#!/usr/bin/env python3
"""Builds the game's data objects from the user's own ROM dump at build time.

The repository holds no game data. Data the project matches without code (string pools, name
tables, the Lang tables, ...) is described by a *data spec* (`data/<module>/<Name>.dspec`): which
symbols it holds and what type each one has. The address ranges are the spec's entry in the
module's `delinks.txt`, the symbol names are `symbols.txt`, and the pointers are `relocs.txt`, as
for any other file. This script reads the bytes for those ranges from `extract/<version>/` (the
`dsd rom extract` output of the user's ROM), checks them against the spec's types, and writes a
relocatable ELF object into `build/`: one section per range, one symbol per `symbols.txt` entry,
one `R_ARM_ABS32` relocation per `relocs.txt` entry. Nothing it writes is ever committed.

Spec syntax (one item per line, `#` starts a comment):

    struct Name {           a C struct with natural alignment (u16 -> 2, u32/ptr -> 4)
        ptr  name;          fields: TYPE NAME; or TYPE NAME[N];
        u16  id;
    }
    default TYPE            type of the symbols the spec does not list (default: raw)
    0xADDR TYPE             the type of the symbol at ADDR, e.g. `0x02082bf8 ptr[3]`
    SYMBOL TYPE             the same by symbols.txt name (breaks when the symbol is renamed, so
                            the specs use addresses, with the name as a comment)

Types: u8 s8 u16 s16 u32 s32 (plain numbers: a relocation inside one is an error), ptr (a word
that is either 0 or carries a relocation), str (one or more NUL-terminated strings, no
relocations), raw (anything: bytes plus relocations), a struct name, and arrays `T[N]` or `T[]`
(as many as fit). A typed symbol may be followed by up to 3 zero bytes of alignment padding
before the next symbol; anything else that does not fit the type is an error, so a wrong layout
fails the build instead of producing a different object.

Usage:
  extract_data.py object --config config/usa/arm9 --extract extract/usa SPEC OUT.o
  extract_data.py check  --config config/usa/arm9 --extract extract/usa [SPEC...]
  extract_data.py inc    --config config/usa/arm9 --extract extract/usa INCSPEC OUTDIR

`inc` writes C initializers (`{ 0x.., ... }`) for single objects that live inside a compiled
translation unit, listed in an inc spec (`MODULE 0xADDR TYPE` per line, TYPE `str` for the
NUL-terminated string at ADDR or `u8[N]`). The source defines the object with
`#include "romdata/<module>/<addr>.inc"` as its initializer.
"""

from __future__ import annotations

import argparse
import re
import struct
import sys
from dataclasses import dataclass, field
from pathlib import Path

try:
    import yaml  # PyYAML is in tools/requirements.txt
except ImportError:  # pragma: no cover
    yaml = None


# --------------------------------------------------------------------------------------------
# dsd configs

SECTION_RE = re.compile(r"\s+(\.\w+)\s+start:0x([0-9a-fA-F]+)\s+end:0x([0-9a-fA-F]+)(.*)")
SYMBOL_RE = re.compile(r"(\S+)\s+kind:(\S+)\s+addr:0x([0-9a-fA-F]+)(.*)")
RELOC_RE = re.compile(r"from:0x([0-9a-fA-F]+)\s+kind:(\w+)(?:\(([^)]*)\))?(?:\s+to:0x([0-9a-fA-F]+))?(?:\s+add:(-?0x[0-9a-fA-F]+|-?\d+))?(?:\s+module:(\S+))?")


@dataclass
class Symbol:
    name: str
    kind: str
    addr: int
    local: bool
    weak: bool
    explicit_size: int | None


@dataclass
class Reloc:
    src: int
    kind: str
    dst: int
    addend: int
    module: str | None


@dataclass
class DelinkEntry:
    name: str
    sections: list[tuple[str, int, int]]


@dataclass
class Module:
    name: str
    dir: Path
    sections: dict[str, tuple[int, int, str]] = field(default_factory=dict)
    entries: list[DelinkEntry] = field(default_factory=list)
    symbols: list[Symbol] = field(default_factory=list)
    relocs: list[Reloc] = field(default_factory=list)
    base: int = 0
    binary: bytes = b""

    def symbol_at(self, addr: int) -> Symbol | None:
        for s in self.symbols:
            if s.addr == addr and not s.kind.startswith("label"):
                return s
        return None


def data_size(kind: str) -> int | None:
    m = re.fullmatch(r"data\((byte|short|word)(?:\[(0x[0-9a-fA-F]+|\d+)\])?\)", kind)
    if not m:
        return None
    count = int(m.group(2), 0) if m.group(2) else 1
    return {"byte": 1, "short": 2, "word": 4}[m.group(1)] * count


def parse_module(name: str, mdir: Path) -> Module:
    mod = Module(name, mdir)
    cur: DelinkEntry | None = None
    for line in (mdir / "delinks.txt").read_text().splitlines():
        if not line.strip():
            continue
        if not line[0].isspace():
            cur = DelinkEntry(line.strip().rstrip(":"), [])
            mod.entries.append(cur)
            continue
        m = SECTION_RE.match(line)
        if not m:
            continue
        sec, a, b = m.group(1), int(m.group(2), 16), int(m.group(3), 16)
        if cur is None:
            mod.sections[sec] = (a, b, m.group(4))
        else:
            cur.sections.append((sec, a, b))
    for line in (mdir / "symbols.txt").read_text().splitlines():
        m = SYMBOL_RE.match(line)
        if m:
            flags = m.group(4).split()
            mod.symbols.append(Symbol(m.group(1), m.group(2), int(m.group(3), 16),
                                      "local" in flags, "weak" in flags, data_size(m.group(2))))
    mod.symbols.sort(key=lambda s: s.addr)
    rpath = mdir / "relocs.txt"
    if rpath.exists():
        for line in rpath.read_text().splitlines():
            m = RELOC_RE.match(line)
            if m:
                mod.relocs.append(Reloc(int(m.group(1), 16), m.group(2) + (f"({m.group(3)})" if m.group(3) else ""),
                                        int(m.group(4), 16) if m.group(4) else 0,
                                        int(m.group(5), 0) if m.group(5) else 0, m.group(6)))
    return mod


class Program:
    def __init__(self, config: Path, extract: Path):
        self.config = config
        self.modules: dict[str, Module] = {}
        self.modules["main"] = parse_module("main", config)
        for n in ("itcm", "dtcm"):
            if (config / n / "delinks.txt").exists():
                self.modules[n] = parse_module(n, config / n)
        ovdir = config / "overlays"
        if ovdir.is_dir():
            for d in sorted(ovdir.iterdir()):
                if (d / "delinks.txt").exists():
                    self.modules[d.name] = parse_module(d.name, d)
        self.extract = extract
        self._loaded = False

    def load_binaries(self) -> None:
        if self._loaded:
            return
        if yaml is None:
            sys.exit("extract_data.py: PyYAML is required (pip install -r tools/requirements.txt)")
        ex = self.extract
        if not (ex / "arm9" / "arm9.yaml").exists():
            sys.exit(f"extract_data.py: {ex} has no extracted ROM; put your ROM in extract/ and run ninja")
        main = self.modules["main"]
        main.base = yaml.safe_load((ex / "arm9" / "arm9.yaml").read_text())["base_address"]
        main.binary = (ex / "arm9" / "arm9.bin").read_bytes()
        for n in ("itcm", "dtcm"):
            if n in self.modules:
                self.modules[n].base = yaml.safe_load((ex / "arm9" / f"{n}.yaml").read_text())["base_address"]
                self.modules[n].binary = (ex / "arm9" / f"{n}.bin").read_bytes()
        ovs = yaml.safe_load((ex / "arm9_overlays" / "overlays.yaml").read_text())
        ovs = ovs["overlays"] if isinstance(ovs, dict) else ovs
        for o in ovs:
            name = f"ov{o['id']:03d}"
            if name in self.modules:
                self.modules[name].base = o["base_address"]
                self.modules[name].binary = (ex / "arm9_overlays" / o["file_name"]).read_bytes()
        self._loaded = True

    def module_by_reloc(self, spec: str | None) -> Module | None:
        if spec is None or spec == "none":
            return None
        if spec in self.modules:
            return self.modules[spec]
        m = re.fullmatch(r"overlays?\((\d+)(?:,\d+)*\)", spec)
        if m:
            return self.modules.get(f"ov{int(m.group(1)):03d}")
        return None

    def suggest_reloc(self, src: int, value: int) -> str:
        """The relocs.txt line for a pointer at `src` holding `value`, if one symbol owns it."""
        hits = []
        for mod in self.modules.values():
            syms = [x for x in mod.symbols if not x.kind.startswith("label")]
            inside = [x for x in syms if x.addr == value]
            if inside:
                hits.append((mod, inside[0], 0))
            else:
                lo, hi = min(a for a, _, _ in mod.sections.values()), max(b for _, b, _ in mod.sections.values())
                if lo <= value < hi:
                    before = [x for x in syms if x.addr <= value]
                    if before:
                        hits.append((mod, before[-1], value - before[-1].addr))
        if len(hits) != 1:
            return f"(0x{value:08x} is in {len(hits)} modules: pick by hand)"
        mod, sym, add = hits[0]
        mname = "main" if mod.name == "main" else mod.name if mod.name in ("itcm", "dtcm") else f"overlay({int(mod.name[2:])})"
        addtxt = f" add:0x{add:x}" if add else ""
        return f"from:0x{src:08x} kind:load to:0x{sym.addr:08x}{addtxt} module:{mname}  ({sym.name})"

    def find_entry(self, spec_path: str) -> tuple[Module, DelinkEntry]:
        for mod in self.modules.values():
            for e in mod.entries:
                if e.name == spec_path:
                    return mod, e
        sys.exit(f"extract_data.py: {spec_path} has no entry in any delinks.txt")

    def specs(self) -> list[str]:
        return [e.name for mod in self.modules.values() for e in mod.entries if e.name.endswith(".dspec")]

    def read(self, mod: Module, addr: int, size: int) -> bytes:
        self.load_binaries()
        off = addr - mod.base
        if off < 0 or off + size > len(mod.binary):
            sys.exit(f"extract_data.py: {mod.name} 0x{addr:08x}+0x{size:x} is outside the extracted module")
        return mod.binary[off:off + size]


# --------------------------------------------------------------------------------------------
# Spec types

PRIMS = {"u8": (1, 1), "s8": (1, 1), "u16": (2, 2), "s16": (2, 2), "u32": (4, 4), "s32": (4, 4),
         "fx16": (2, 2), "fx32": (4, 4), "ptr": (4, 4)}


@dataclass
class Type:
    base: str          # prim name, struct name, "str" or "raw"
    count: int | None  # None: scalar, -1: fill, N: array

    def __str__(self) -> str:
        return self.base + ("" if self.count is None else "[]" if self.count < 0 else f"[{self.count}]")


@dataclass
class Struct:
    name: str
    fields: list[tuple[str, Type]]
    size: int = 0
    align: int = 1
    layout: list[tuple[int, str, Type]] = field(default_factory=list)


TYPE_RE = re.compile(r"(\w+)(?:\[(0x[0-9a-fA-F]+|\d*)\])?$")


def parse_type(text: str) -> Type:
    m = TYPE_RE.match(text.strip())
    if not m:
        raise ValueError(f"bad type `{text}`")
    if m.group(2) is None:
        return Type(m.group(1), None)
    return Type(m.group(1), -1 if m.group(2) == "" else int(m.group(2), 0))


@dataclass
class Spec:
    path: Path
    structs: dict[str, Struct] = field(default_factory=dict)
    types: dict[str, Type] = field(default_factory=dict)
    types_by_addr: dict[int, Type] = field(default_factory=dict)
    default: Type = field(default_factory=lambda: Type("raw", None))

    def size_align(self, t: Type) -> tuple[int, int]:
        if t.base in PRIMS:
            sz, al = PRIMS[t.base]
        elif t.base in self.structs:
            sz, al = self.structs[t.base].size, self.structs[t.base].align
        else:
            raise ValueError(f"{self.path}: type `{t.base}` has no fixed size")
        if t.count is None:
            return sz, al
        if t.count < 0:
            raise ValueError(f"{self.path}: `{t}` has no fixed size")
        return sz * t.count, al


def parse_spec(path: Path) -> Spec:
    spec = Spec(path)
    cur: Struct | None = None
    for no, raw in enumerate(path.read_text().splitlines(), 1):
        line = raw.split("#", 1)[0].strip()
        if not line:
            continue
        where = f"{path}:{no}"
        if cur is not None:
            if line == "}" or line == "};":
                off, al = 0, 1
                for fname, ft in cur.fields:
                    fsz, fal = spec.size_align(ft)
                    off = (off + fal - 1) & ~(fal - 1)
                    cur.layout.append((off, fname, ft))
                    off += fsz
                    al = max(al, fal)
                cur.size, cur.align = (off + al - 1) & ~(al - 1), al
                spec.structs[cur.name] = cur
                cur = None
                continue
            m = re.fullmatch(r"(\w+)\s+(\w+)(\[(?:0x[0-9a-fA-F]+|\d+)\])?\s*;", line)
            if not m:
                sys.exit(f"{where}: bad struct field `{line}`")
            ft = parse_type(m.group(1) + (m.group(3) or ""))
            if ft.base not in PRIMS and ft.base not in spec.structs:
                sys.exit(f"{where}: unknown field type `{ft.base}`")
            cur.fields.append((m.group(2), ft))
            continue
        m = re.fullmatch(r"struct\s+(\w+)\s*\{", line)
        if m:
            cur = Struct(m.group(1), [])
            continue
        parts = line.split()
        if len(parts) != 2:
            sys.exit(f"{where}: expected `SYMBOL TYPE`, `default TYPE` or `struct NAME {{`")
        try:
            t = parse_type(parts[1])
        except ValueError as e:
            sys.exit(f"{where}: {e}")
        if t.base not in PRIMS and t.base not in spec.structs and t.base not in ("str", "raw"):
            sys.exit(f"{where}: unknown type `{t.base}`")
        if parts[0] == "default":
            spec.default = t
        elif re.fullmatch(r"0x[0-9a-fA-F]+", parts[0]):
            spec.types_by_addr[int(parts[0], 16)] = t
        else:
            spec.types[parts[0]] = t
    if cur is not None:
        sys.exit(f"{path}: struct {cur.name} is not closed")
    return spec


class LayoutError(Exception):
    pass


def check_type(spec: Spec, t: Type, data: bytes, rel_offsets: set[int], base: int, sym: str) -> list[int]:
    """Checks one symbol's bytes (relocation offsets relative to the symbol) against its type.

    Returns the offsets of non-NULL ptr fields that have no relocation (the caller reports them,
    with the relocs.txt line that would fix each).
    """
    n = len(data)
    missing: list[int] = []
    if t.base == "raw":
        return missing
    if t.base == "str":
        if rel_offsets:
            raise LayoutError(f"{sym}: str has a relocation")
        # The last string's NUL, then at most 3 bytes of zero padding (all zero too).
        if n == 0 or data[-1] != 0:
            raise LayoutError(f"{sym}: str does not end with a NUL")
        return missing
    if t.count is not None and t.count < 0:
        esz, eal = spec.size_align(Type(t.base, None))
        count = n // esz
        if count == 0:
            raise LayoutError(f"{sym}: {t} does not fit 0x{n:x} bytes")
        t = Type(t.base, count)
    size, _ = spec.size_align(t)
    if size > n:
        raise LayoutError(f"{sym}: {t} is 0x{size:x} bytes, the symbol 0x{n:x}")
    pad = data[size:]
    if len(pad) >= 4 or any(pad):
        raise LayoutError(f"{sym}: {t} is 0x{size:x} bytes, the symbol 0x{n:x} (more than alignment padding)")
    if any(o >= size for o in rel_offsets):
        raise LayoutError(f"{sym}: relocation in the padding after {t}")
    ptrs: set[int] = set()

    def walk(tt: Type, off: int) -> None:
        if tt.count is not None:
            esz, _ = spec.size_align(Type(tt.base, None))
            for i in range(tt.count):
                walk(Type(tt.base, None), off + i * esz)
            return
        if tt.base == "ptr":
            ptrs.add(off)
            if off not in rel_offsets and struct.unpack_from("<I", data, off)[0] != 0:
                missing.append(off)
            return
        if tt.base in PRIMS:
            sz = PRIMS[tt.base][0]
            for o in rel_offsets:
                if off - 3 <= o < off + sz:
                    raise LayoutError(f"{sym}+0x{off:x}: {tt.base} overlaps a relocation")
            return
        for foff, _, ft in spec.structs[tt.base].layout:
            walk(ft, off + foff)

    walk(t, 0)
    for o in rel_offsets:
        if o not in ptrs:
            raise LayoutError(f"{sym}+0x{o:x}: relocation outside a ptr field")
    return missing


# --------------------------------------------------------------------------------------------
# ELF writer

R_ARM_ABS32 = 2
SHT_PROGBITS, SHT_SYMTAB, SHT_STRTAB, SHT_RELA, SHT_NOBITS = 1, 2, 3, 4, 8
SHF_WRITE, SHF_ALLOC, SHF_EXECINSTR, SHF_INFO_LINK = 1, 2, 4, 0x40
STB_LOCAL, STB_GLOBAL, STB_WEAK = 0, 1, 2
STT_NOTYPE, STT_OBJECT, STT_SECTION = 0, 1, 3


class StrTab:
    def __init__(self) -> None:
        self.data = bytearray(b"\0")
        self.index: dict[str, int] = {"": 0}

    def add(self, s: str) -> int:
        if s not in self.index:
            self.index[s] = len(self.data)
            self.data += s.encode() + b"\0"
        return self.index[s]


@dataclass
class OutSection:
    name: str
    flags: int
    data: bytes
    align: int
    nobits: int = 0
    relocs: list[tuple[int, str, int]] = field(default_factory=list)  # offset, symbol, addend


def write_elf(path: Path, sections: list[OutSection],
              symbols: list[tuple[str, int, int, int, int, int]], undefined: list[str]) -> None:
    """symbols: (name, section index (1-based among `sections`), value, size, bind, type)."""
    strtab, shstrtab = StrTab(), StrTab()
    # Symbol table: null, section symbols, $d mapping symbols and locals, then globals, then undefined.
    syms: list[tuple[int, int, int, int, int]] = [(0, 0, 0, 0, 0)]  # name, value, size, info, shndx
    for i, _ in enumerate(sections):
        syms.append((0, 0, 0, (STB_LOCAL << 4) | STT_SECTION, i + 1))
    for name, sec, value, size, bind, typ in symbols:
        syms.append((strtab.add("$d"), value, 0, (STB_LOCAL << 4) | STT_NOTYPE, sec))
    index: dict[str, int] = {}
    for name, sec, value, size, bind, typ in symbols:
        if bind == STB_LOCAL:
            index[name] = len(syms)
            syms.append((strtab.add(name), value, size, (bind << 4) | typ, sec))
    first_global = len(syms)
    for name, sec, value, size, bind, typ in symbols:
        if bind != STB_LOCAL:
            index[name] = len(syms)
            syms.append((strtab.add(name), value, size, (bind << 4) | typ, sec))
    for name in undefined:
        index[name] = len(syms)
        syms.append((strtab.add(name), 0, 0, (STB_WEAK << 4) | STT_NOTYPE, 0))

    nsec = len(sections)
    rela_secs = [(i, s) for i, s in enumerate(sections) if s.relocs]
    # Section header order: null, data sections, rela sections, symtab, strtab, shstrtab.
    symtab_idx = 1 + nsec + len(rela_secs)
    headers = []
    body = bytearray()
    off0 = 0x34

    def place(blob: bytes, align: int) -> int:
        nonlocal body
        while (off0 + len(body)) % align:
            body += b"\0"
        o = off0 + len(body)
        body += blob
        return o

    for s in sections:
        flags = s.flags
        if s.nobits:
            headers.append((shstrtab.add(s.name), SHT_NOBITS, flags, off0 + len(body), s.nobits, 0, 0, s.align, 0))
        else:
            o = place(s.data, max(s.align, 1))
            headers.append((shstrtab.add(s.name), SHT_PROGBITS, flags, o, len(s.data), 0, 0, s.align, 0))
    for i, s in rela_secs:
        blob = b"".join(struct.pack("<IIi", off, (index[sym] << 8) | R_ARM_ABS32, add) for off, sym, add in s.relocs)
        o = place(blob, 4)
        headers.append((shstrtab.add(".rela" + s.name), SHT_RELA, SHF_INFO_LINK, o, len(blob), symtab_idx, i + 1, 4, 12))
    symblob = b"".join(struct.pack("<IIIBBH", n, v, sz, info, 0, sh) for n, v, sz, info, sh in syms)
    o = place(symblob, 4)
    headers.append((shstrtab.add(".symtab"), SHT_SYMTAB, 0, o, len(symblob), symtab_idx + 1, first_global, 4, 16))
    o = place(bytes(strtab.data), 1)
    headers.append((shstrtab.add(".strtab"), SHT_STRTAB, 0, o, len(strtab.data), 0, 0, 1, 0))
    shname = shstrtab.add(".shstrtab")
    o = place(bytes(shstrtab.data), 1)
    headers.append((shname, SHT_STRTAB, 0, o, len(shstrtab.data), 0, 0, 1, 0))
    while (off0 + len(body)) % 4:
        body += b"\0"
    shoff = off0 + len(body)
    ehdr = struct.pack("<4sBBBBB7sHHIIIIIHHHHHH", b"\x7fELF", 1, 1, 1, 0, 0, b"\0" * 7,
                       1, 40, 1, 0, 0, shoff, 0, 0x34, 0, 0, 40, len(headers) + 1, len(headers))
    shdrs = struct.pack("<10I", *([0] * 10))
    for h in headers:
        name, typ, flags, off, size, link, info, align, entsize = h
        shdrs += struct.pack("<10I", name, typ, flags, 0, off, size, link, info, align, entsize)
    blob = ehdr + bytes(body) + shdrs
    if path.exists() and path.read_bytes() == blob:
        return  # unchanged: ninja's restat skips the relink
    path.parent.mkdir(parents=True, exist_ok=True)
    tmp = path.with_suffix(path.suffix + ".tmp")
    tmp.write_bytes(blob)
    tmp.replace(path)


# --------------------------------------------------------------------------------------------
# Building a spec's object

SECTION_FLAGS = {
    ".text": SHF_ALLOC | SHF_EXECINSTR,
    ".rodata": SHF_ALLOC,
    ".data": SHF_ALLOC | SHF_WRITE,
    ".bss": SHF_ALLOC | SHF_WRITE,
}


def build_unit(prog: Program, spec_path: str, out: Path | None) -> int:
    mod, entry = prog.find_entry(spec_path)
    spec = parse_spec(Path(spec_path))
    out_sections: list[OutSection] = []
    out_symbols: list[tuple[str, int, int, int, int, int]] = []
    undefined: list[str] = []
    defined: dict[tuple[str, int], str] = {}
    pending: list[tuple[OutSection, int, Reloc]] = []
    errors: list[str] = []
    seen_types: set[str] = set()
    seen_addrs: set[int] = set()
    total = 0

    for secname, start, end in entry.sections:
        if secname not in SECTION_FLAGS:
            errors.append(f"{spec_path}: section {secname} is not supported")
            continue
        if secname == ".bss":
            data = b""
        else:
            data = prog.read(mod, start, end - start)
        osec = OutSection(secname, SECTION_FLAGS[secname], data, 4 if secname == ".text" else 1,
                          nobits=(end - start) if secname == ".bss" else 0)
        out_sections.append(osec)
        secidx = len(out_sections)
        syms = [s for s in mod.symbols if start <= s.addr < end and not s.kind.startswith("label")]
        if secname != ".bss" and (not syms or syms[0].addr != start):
            errors.append(f"{spec_path}: {secname} 0x{start:08x} has no symbol at its start")
        for s in syms:
            if not (s.kind.startswith("data") or s.kind.startswith("bss")):
                errors.append(f"{spec_path}: {s.name} is a {s.kind}, not data")
        relocs = [r for r in mod.relocs if start <= r.src < end]
        rel_by_off: dict[int, Reloc] = {}
        for r in relocs:
            if r.kind != "load":
                errors.append(f"{spec_path}: relocation of kind {r.kind} at 0x{r.src:08x} in data")
                continue
            if (r.src - start) % 4:
                errors.append(f"{spec_path}: unaligned relocation at 0x{r.src:08x}")
            rel_by_off[r.src - start] = r
        for i, s in enumerate(syms):
            nxt = syms[i + 1].addr if i + 1 < len(syms) else end
            size = s.explicit_size if s.explicit_size is not None else nxt - s.addr
            bind = STB_LOCAL if s.local else STB_WEAK if s.weak else STB_GLOBAL
            out_symbols.append((s.name, secidx, s.addr - start, size, bind, STT_OBJECT))
            defined[(mod.name, s.addr)] = s.name
            if secname == ".bss":
                continue
            t = spec.types_by_addr.get(s.addr, spec.types.get(s.name, spec.default))
            if s.name in spec.types:
                seen_types.add(s.name)
            if s.addr in spec.types_by_addr:
                seen_addrs.add(s.addr)
            lo, hi = s.addr - start, nxt - start
            try:
                missing = check_type(spec, t, data[lo:hi], {o - lo for o in rel_by_off if lo <= o < hi}, s.addr, s.name)
            except (LayoutError, ValueError) as e:
                errors.append(f"{spec_path}: {e}")
                continue
            for o in missing:
                value = struct.unpack_from("<I", data, lo + o)[0]
                errors.append(f"{spec_path}: {s.name}+0x{o:x} is a ptr (0x{value:08x}) with no relocation; "
                              f"relocs.txt needs: {prog.suggest_reloc(s.addr + o, value)}")
        for off, r in sorted(rel_by_off.items()):
            pending.append((osec, off, r))
        total += end - start

    for name in spec.types:
        if name not in seen_types:
            errors.append(f"{spec_path}: {name} is not a symbol of this file")
    for addr in spec.types_by_addr:
        if addr not in seen_addrs:
            errors.append(f"{spec_path}: no symbol of this file is at 0x{addr:08x}")

    # Relocations: the symbol at the destination (in this object or any module), as dsd does.
    for osec, off, r in pending:
        tmod = prog.module_by_reloc(r.module)
        if tmod is None:
            errors.append(f"{spec_path}: relocation at 0x{r.src:08x} has no module ({r.module})")
            continue
        name = defined.get((tmod.name, r.dst))
        if name is None:
            sym = tmod.symbol_at(r.dst)
            if sym is None:
                errors.append(f"{spec_path}: no symbol at 0x{r.dst:08x} in {tmod.name} (relocation at 0x{r.src:08x})")
                continue
            if sym.local:
                errors.append(f"{spec_path}: relocation at 0x{r.src:08x} targets local {sym.name}")
                continue
            name = sym.name
            if name not in undefined:
                undefined.append(name)
        osec.relocs.append((off, name, r.addend))
        # RELA: the field itself holds zero, as in the delinked objects.
        if not osec.nobits:
            osec.data = osec.data[:off] + b"\0\0\0\0" + osec.data[off + 4:]

    if errors:
        for e in errors:
            print(e, file=sys.stderr)
        sys.exit(1)
    if out is not None:
        write_elf(out, out_sections, out_symbols, undefined)
    return total


# --------------------------------------------------------------------------------------------
# C initializers for objects inside compiled TUs

def parse_inc_spec(incspec: Path) -> list[tuple[int, str, int, Type]]:
    out = []
    for no, raw in enumerate(incspec.read_text().splitlines(), 1):
        line = raw.split("#", 1)[0].strip()
        if not line:
            continue
        parts = line.split()
        if len(parts) != 3 or not re.fullmatch(r"0x[0-9a-fA-F]{8}", parts[1]):
            sys.exit(f"{incspec}:{no}: expected `MODULE 0xADDR TYPE`")
        out.append((no, parts[0], int(parts[1], 16), parse_type(parts[2])))
    return out


def inc_name(module: str, addr: int) -> str:
    return f"romdata/{module}/{addr:08x}.inc"


def build_incs(prog: Program, incspec: Path, outdir: Path) -> None:
    errors = []
    for no, modname, addr, t in parse_inc_spec(incspec):
        where = f"{incspec}:{no}"
        mod = prog.modules.get(modname)
        if mod is None:
            sys.exit(f"{where}: unknown module {modname}")
        syms = [s for s in mod.symbols if not s.kind.startswith("label")]
        idx = next((i for i, s in enumerate(syms) if s.addr == addr), None)
        if idx is None:
            sys.exit(f"{where}: no symbol at 0x{addr:08x} in {modname}'s symbols.txt")
        nxt = next((s.addr for s in syms[idx + 1:] if s.addr > addr), None)
        if t.base == "str" and t.count is None:
            if nxt is None:
                sys.exit(f"{where}: the symbol at 0x{addr:08x} has no next symbol to bound it")
            data = prog.read(mod, addr, nxt - addr)
            end = data.find(b"\0")
            if end < 0:
                errors.append(f"{where}: no NUL before the next symbol")
                continue
            data = data[:end + 1]
        elif t.base in ("u8", "s8") and t.count and t.count > 0:
            if nxt is not None and addr + t.count > nxt:
                errors.append(f"{where}: {t} runs into the next symbol")
                continue
            data = prog.read(mod, addr, t.count)
        else:
            sys.exit(f"{where}: unsupported type {t} (str or u8[N])")
        if any(addr <= r.src < addr + len(data) for r in mod.relocs):
            errors.append(f"{where}: the object contains a relocation")
            continue
        text = "{ " + ", ".join(f"0x{b:02x}" for b in data) + " }\n"
        dest = outdir / inc_name(modname, addr)
        dest.parent.mkdir(parents=True, exist_ok=True)
        if not dest.exists() or dest.read_text() != text:
            dest.write_text(text)
    if errors:
        for e in errors:
            print(e, file=sys.stderr)
        sys.exit(1)


def inc_outputs(incspec: Path) -> list[str]:
    return [inc_name(mod, addr) for _, mod, addr, _ in parse_inc_spec(incspec)]


def main() -> None:
    ap = argparse.ArgumentParser(description=__doc__, formatter_class=argparse.RawDescriptionHelpFormatter)
    ap.add_argument("mode", choices=["object", "check", "inc"])
    ap.add_argument("--config", type=Path, required=True)
    ap.add_argument("--extract", type=Path, required=True)
    ap.add_argument("args", nargs="*")
    a = ap.parse_args()
    prog = Program(a.config, a.extract)
    if a.mode == "object":
        if len(a.args) != 2:
            ap.error("object takes SPEC OUT.o")
        build_unit(prog, a.args[0], Path(a.args[1]))
    elif a.mode == "check":
        total, failed = 0, 0
        for s in a.args or prog.specs():
            try:
                n = build_unit(prog, s, None)
            except SystemExit as e:
                if e.code not in (None, 0, 1):
                    print(e.code, file=sys.stderr)
                failed += 1
                continue
            print(f"{s}: 0x{n:x} bytes OK")
            total += n
        print(f"total 0x{total:x} ({total}) bytes, {failed} specs failed")
        sys.exit(1 if failed else 0)
    else:
        if len(a.args) != 2:
            ap.error("inc takes INCSPEC OUTDIR")
        build_incs(prog, Path(a.args[0]), Path(a.args[1]))


if __name__ == "__main__":
    main()
