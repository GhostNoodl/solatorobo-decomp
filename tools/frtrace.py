# tools/frtrace.py: gdb script for mwccarm dsi/1.3 (run through tools/frtrace.sh).
# Logs, per function: REG (a local or temp gets a virtual register at 0x507830, in local-list order),
# LOCAL (a memory local gets its frame offset at 0x507880), FRAME (locals/spill sizes at 0x509a50) and
# SPILL (a spilled node gets a spill slot at 0x5099d0; node = vreg index). NOREG="name or ordinal ..."
# skips the register assignment for those locals (what-if: force them to memory).
import gdb,struct,os
inf=lambda: gdb.selected_inferior()
def u32(a): return struct.unpack('<I',bytes(inf().read_memory(a,4)))[0]
def u16(a): return struct.unpack('<H',bytes(inf().read_memory(a,2)))[0]
def u8(a): return bytes(inf().read_memory(a,1))[0]
def cstr(a,n=40):
    b=bytes(inf().read_memory(a,n)); return b.split(b'\0')[0].decode('latin1')
gdb.execute('set pagination off'); gdb.execute('set confirm off')
for sig in ['SIGSEGV','SIGILL','SIGUSR1']: gdb.execute('handle %s nostop noprint pass'%sig)
gdb.execute('break _ZN4wibo10Executable6loadPEEP8_IO_FILEb')
gdb.execute('run'); gdb.execute('finish'); gdb.execute('delete')
gdb.execute('set $fctrl = 0x27f')
out=open(os.environ.get('FROUT','/tmp/fr.out'),'w')
def name(obj):
    try:
        n=u32(obj+8)
        for off in (0xa,0xc,0x8,0x6):
            s=cstr(n+off)
            if s and all(32<=ord(c)<127 for c in s): return s
    except Exception: pass
    return '?'
class Sp(gdb.Breakpoint):
    def stop(self):
        esp=int(gdb.parse_and_eval('$esp')); obj=u32(esp+4); ret=u32(esp)
        idx=u32(esp+8) if 0x5b1ab0<=ret<0x5b1c40 else -1
        out.write("SPILL round=%d node=%d obj=%x %s size=%d at=%d ret=%x\n"%(u32(0x65b9c0),idx,obj,name(obj),u32(u32(obj+0xc)+2),u32(0x65b9ac),ret)); out.flush()
        return False
class Lo(gdb.Breakpoint):
    def stop(self):
        esp=int(gdb.parse_and_eval('$esp')); obj=u32(esp+4)
        out.write("LOCAL obj=%x %s size=%d cnt=%d\n"%(obj,name(obj),u32(u32(obj+0xc)+2),u32(0x65ba18))); out.flush()
        return False
class Fs(gdb.Breakpoint):
    def stop(self):
        out.write("FRAME locals=%d spills=%d\n"%(u32(0x65ba18),u32(0x65b9ac))); out.flush()
        return False
class Rg(gdb.Breakpoint):
    def stop(self):
        esp=int(gdb.parse_and_eval('$esp')); obj=u32(esp+4)
        nm=name(obj)
        out.write("REG obj=%x %s size=%d vreg=%d\n"%(obj,nm,u32(u32(obj+0xc)+2),u32(0x65b860))); out.flush()
        skip=os.environ.get('NOREG','').split()
        if nm in skip or str(REGN[0]) in skip:
            out.write("  -> forced to memory\n")
            gdb.execute('set $eip=*(int*)$esp'); gdb.execute('set $esp=$esp+4')
        REGN[0]+=1
        return False
REGN=[0]
Rg('*0x507830')
Sp('*0x5099d0'); Lo('*0x507880'); Fs('*0x509a50')
gdb.execute('continue')
