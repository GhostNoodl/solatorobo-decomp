#!/usr/bin/env python3
# mktarget.py <addr> <out>: write a fake target object holding the function's bytes from the
# extracted overlay (read at run time from extract/, never stored here), for fakeobjdump.py.
import sys, re, json, os, yaml
a = int(sys.argv[1], 16); out = sys.argv[2]
R = os.environ.get('DECOMP_ROOT', os.path.join(os.path.dirname(__file__), '..', '..'))
mod = os.environ.get('PERM_MODULE', 'ov000')
ovid = int(mod[2:])
cfg = os.path.join(R, 'config/usa/arm9/overlays', mod)
size = None
for l in open(os.path.join(cfg, 'symbols.txt')):
    m = re.match(r'\S+ kind:function\(arm,size=0x([0-9a-f]+)\) addr:0x([0-9a-f]+)', l)
    if m and int(m[2], 16) == a:
        size = int(m[1], 16)
if size is None:
    sys.exit('function %x not found in symbols.txt' % a)
ovs = yaml.safe_load(open(os.path.join(R, 'extract/usa/arm9_overlays/overlays.yaml')))['overlays']
ov = next(o for o in ovs if o['id'] == ovid)
b = open(os.path.join(R, 'extract/usa/arm9_overlays', ov['file_name']), 'rb').read()
code = b[a - ov['base_address']:a - ov['base_address'] + size]
rel = []
for l in open(os.path.join(cfg, 'relocs.txt')):
    m = re.match(r'from:0x([0-9a-f]+) kind:load', l)
    if m and a <= int(m[1], 16) < a + size:
        rel.append(int(m[1], 16) - a)
hdr = bytearray(20); hdr[0:4] = b'\x7fELF'; hdr[5] = 1; hdr[18] = 40
open(out, 'wb').write(bytes(hdr) + b'FAKETGT' + json.dumps({'code': code.hex(), 'relocated': rel, 'base': 0}).encode())
