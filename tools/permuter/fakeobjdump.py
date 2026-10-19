#!/usr/bin/env python3
# fake arm objdump for decomp-permuter: prints "addr:\tword \tmnem\targs"
import sys, json, struct, os
import capstone
from elftools.elf.elffile import ELFFile
path = sys.argv[-1]
data = open(path, 'rb').read()
md = capstone.Cs(capstone.CS_ARCH_ARM, capstone.CS_MODE_ARM)
if data[20:27] == b'FAKETGT':
    j = json.loads(data[27:])
    code = bytes.fromhex(j['code']); relocated = set(j['relocated']); base = j['base']
else:
    func = os.environ.get('PERM_FUNC')
    import io
    elf = ELFFile(io.BytesIO(data))
    code = None
    for sym in elf.get_section_by_name('.symtab').iter_symbols():
        if sym['st_info']['type'] == 'STT_FUNC' and (sym.name == func or (func is None)):
            start = sym['st_value'] & ~1
            sec = elf.get_section(sym['st_shndx'])
            code = sec.data()[start:start + sym['st_size']]
            relocated = set()
            for rs in elf.iter_sections():
                if rs.header['sh_type'] in ('SHT_REL', 'SHT_RELA') and rs.header['sh_info'] == sym['st_shndx']:
                    for r in rs.iter_relocations():
                        o = r['r_offset'] - start
                        if 0 <= o < len(code) and r['r_info_type'] == 2:
                            relocated.add(o)
            break
    base = 0
    if code is None:
        code = b''; relocated = set()
print("\nDisassembly of section .text:\n\n00000000 <f>:")
off = 0
while off < len(code):
    w = struct.unpack_from('<I', code, off)[0]
    if off in relocated:
        print(f"{off:x}:\t{0:08x} \t.word\treloc"); off += 4; continue
    ins = next(md.disasm(code[off:off+4], base + off, 1), None)
    if ins is None:
        print(f"{off:x}:\t{w:08x} \t.word\t{w:#x}"); off += 4; continue
    m, a = ins.mnemonic, ins.op_str
    if m.rstrip('sw.') in ('bl', 'blx', 'b') and a.startswith('#'):
        if m.startswith('bl'):
            a = 'X'
        else:
            a = hex(int(a[1:], 16) - base)
    print(f"{off:x}:\t{w:08x} \t{m}\t{a}")
    off += 4
