#!/usr/bin/env python3
"""Append absolute symbol definitions to the dsd-generated arm9.lcf.

Some code calls or loads addresses that no module defines, such as the
TWL-only main region at 0x0221xxxx-0x0228xxxx (`module:none` in relocs.txt).
A C file can only reach such an address by name, so the linker needs an
absolute symbol for it. The names and addresses are listed in
config/<version>/arm9/abs_symbols.txt, one `name addr` pair per line
(`#` starts a comment). This script inserts `name = addr;` after the
`__OVERLAY_COUNT` line that dsd writes, like dsd's own linker-script symbols.

An absolute symbol has no ARM/Thumb type, so MWLD always calls it with a
plain `bl`. For ARM code called from Thumb (`blx`), add `arm` as a third
column: `name addr arm`. The symbol is then defined instead by a 4-byte ARM
stub section (with a `$a` mapping symbol) in a generated object,
`<lcf dir>/abs_arm.o`, which the .lcf places at `addr` in a memory region of
its own (`build/abs_<name>.bin`, not part of the ROM). The object is added to
the objects file.

    python3 tools/lcf_abs.py build/usa/arm9.lcf config/usa/arm9/abs_symbols.txt [build/usa/objects.txt]
"""
import os
import re
import struct
import sys

MARK = ' /* abs_symbols */'


def write_arm_object(path, names):
    """ELF32 ARM relocatable: one 4-byte `bx lr` section `.abs.<name>` per name,
    each holding a local `$a` and a global STT_FUNC `name` at offset 0."""
    code = b'\x1e\xff\x2f\xe1'
    shstr = b'\0.symtab\0.strtab\0.shstrtab\0'
    sec_names = []
    for n in names:
        sec_names.append(len(shstr))
        shstr += f'.abs.{n}'.encode() + b'\0'
    strtab = b'\0$a\0'
    name_offs = []
    for n in names:
        name_offs.append(len(strtab))
        strtab += n.encode() + b'\0'
    # section indices: 0 null, 1 symtab, 2 strtab, 3 shstrtab, 4.. code
    symtab = b'\0' * 16
    for i in range(len(names)):
        symtab += struct.pack('<IIIBBH', 1, 0, 0, 2, 0, 4 + i)  # $a, local func
    n_local = 1 + len(names)
    for i, off in enumerate(name_offs):
        symtab += struct.pack('<IIIBBH', off, 0, 4, (1 << 4) | 2, 0, 4 + i)
    data = bytearray(b'\0' * 52)
    code_offs = []
    for _ in names:
        code_offs.append(len(data))
        data += code
    o_sym = len(data); data += symtab
    o_str = len(data); data += strtab
    o_shs = len(data); data += shstr
    while len(data) % 4:
        data += b'\0'
    shoff = len(data)

    def sh(name, typ, flags, off, size, link=0, info=0, align=1, ent=0):
        return struct.pack('<10I', name, typ, flags, 0, off, size, link, info, align, ent)

    data += sh(0, 0, 0, 0, 0)
    data += sh(1, 2, 0, o_sym, len(symtab), 2, n_local, 4, 16)
    data += sh(9, 3, 0, o_str, len(strtab))
    data += sh(17, 3, 0, o_shs, len(shstr))
    for so, co in zip(sec_names, code_offs):
        data += sh(so, 1, 0x6, co, len(code), 0, 0, 4)
    data[0:52] = b'\x7fELF\x01\x01\x01' + b'\0' * 9 + struct.pack(
        '<HHIIIIIHHHHHH', 1, 40, 1, 0, 0, shoff, 0x05000000, 52, 0, 0, 40,
        4 + len(names), 3)
    with open(path, 'wb') as f:
        f.write(data)


def main():
    lcf_path, list_path = sys.argv[1], sys.argv[2]
    objects_path = sys.argv[3] if len(sys.argv) > 3 else None
    defs = []
    arm = []
    for line in open(list_path):
        line = line.split('#', 1)[0].strip()
        if not line:
            continue
        fields = line.split()
        name, addr = fields[0], fields[1]
        int(addr, 0)
        if fields[2:] == ['arm']:
            arm.append((name, addr))
        elif fields[2:]:
            sys.exit(f'{list_path}: bad line: {line}')
        else:
            defs.append(f'    {name} = {addr};')
    lines = open(lcf_path).readlines()
    lines = [l for l in lines if not l.rstrip().endswith(MARK.strip())]
    for i, l in enumerate(lines):
        if re.match(r'\s*__OVERLAY_COUNT\s*=', l):
            lines[i + 1:i + 1] = [d + MARK + '\n' for d in defs]
            break
    else:
        sys.exit(f'{lcf_path}: no __OVERLAY_COUNT line')

    if objects_path is not None:
        objs = [l for l in open(objects_path).readlines() if 'abs_arm.o' not in l]
    if arm:
        if objects_path is None:
            sys.exit('arm entries need the objects file argument')
        obj = os.path.join(os.path.dirname(lcf_path), 'abs_arm.o')
        write_arm_object(obj, [n for n, _ in arm])
        # MEMORY regions: before the first closing brace (end of MEMORY).
        mem = lines.index('}\n')
        lines[mem:mem] = [f'    ABS_{n} : ORIGIN = {a} > build/abs_{n}.bin' + MARK + '\n'
                          for n, a in arm]
        # SECTIONS entries: before the last closing brace (end of SECTIONS).
        end = len(lines) - 1 - lines[::-1].index('}\n')
        lines[end:end] = [f'    .abs_{n} : {{ abs_arm.o(.abs.{n}) }} > ABS_{n}' + MARK + '\n'
                          for n, _ in arm]
        if objs and not objs[-1].endswith('\n'):
            objs[-1] += '\n'
        objs.append(f'"{obj}"\n')
    if objects_path is not None:
        open(objects_path, 'w').writelines(objs)
    open(lcf_path, 'w').writelines(lines)


if __name__ == '__main__':
    main()
