#!/usr/bin/env python3
"""Append absolute symbol definitions to the dsd-generated arm9.lcf.

Some code calls or loads addresses that no module defines, such as the
TWL-only main region at 0x0221xxxx-0x0228xxxx (`module:none` in relocs.txt).
A C file can only reach such an address by name, so the linker needs an
absolute symbol for it. The names and addresses are listed in
config/<version>/arm9/abs_symbols.txt, one `name addr` pair per line
(`#` starts a comment). This script inserts `name = addr;` after the
`__OVERLAY_COUNT` line that dsd writes, like dsd's own linker-script symbols.

    python3 tools/lcf_abs.py build/usa/arm9.lcf config/usa/arm9/abs_symbols.txt
"""
import re
import sys


def main():
    lcf_path, list_path = sys.argv[1], sys.argv[2]
    defs = []
    for line in open(list_path):
        line = line.split('#', 1)[0].strip()
        if not line:
            continue
        name, addr = line.split()
        int(addr, 0)
        defs.append(f'    {name} = {addr};\n')
    lines = open(lcf_path).readlines()
    lines = [l for l in lines if not l.rstrip().endswith('/* abs_symbols */')]
    for i, l in enumerate(lines):
        if re.match(r'\s*__OVERLAY_COUNT\s*=', l):
            lines[i + 1:i + 1] = [d.rstrip('\n') + ' /* abs_symbols */\n' for d in defs]
            break
    else:
        sys.exit(f'{lcf_path}: no __OVERLAY_COUNT line')
    open(lcf_path, 'w').writelines(lines)


if __name__ == '__main__':
    main()
