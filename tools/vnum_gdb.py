# tools/vnum_gdb.py: gdb script for mwccarm dsi/1.3 (run through tools/vnum.sh, round rgA). Logs every
# temp object creation (U name stack), each IRO pass name (P), each IRO_SplitLifetimes web (S var temp),
# each function start (FUNC), each object vreg assignment (V num cls name) and the final colour graphs (N).
import gdb,os,struct
def rd(a,n): return bytes(gdb.selected_inferior().read_memory(a,n))
def u32(a): return struct.unpack('<I',rd(a,4))[0]
def s32(a): return struct.unpack('<i',rd(a,4))[0]
def u16(a): return struct.unpack('<H',rd(a,2))[0]
def s16(a): return struct.unpack('<h',rd(a,2))[0]
def s8(a): return struct.unpack('<b',rd(a,1))[0]
OUT=open(os.environ['VNOUT'],'w')
def name(obj):
    try:
        hn=u32(obj+8)
        return rd(hn+0xa,40).split(b'\0')[0].decode('latin1') if hn else '?'
    except Exception: return 'err'
class BV(gdb.Breakpoint):
    def stop(self):
        esp=int(gdb.parse_and_eval('$esp'))
        obj=u32(esp+0xc); ret=u32(esp+8)
        bx=int(gdb.parse_and_eval('$ebx'))&0xffff
        cls=int(gdb.parse_and_eval('$eax'))
        OUT.write('V %d cls=%d %s\n'%(bx,cls,name(obj)))
        OUT.flush(); return False
class BU(gdb.Breakpoint):
    def stop(self):
        esp=int(gdb.parse_and_eval('$esp')); hn=int(gdb.parse_and_eval('$eax'))
        nm=rd(hn+0xa,20).split(b'\0')[0].decode('latin1')
        st=[]
        for k in range(0x20,0x200,4):
            v=u32(esp+k)
            if 0x401000<=v<0x5b8000: st.append('%x'%v)
            if len(st)>=8: break
        OUT.write('U %s %s\n'%(nm,' '.join(st))); OUT.flush(); return False
class BP(gdb.Breakpoint):
    def stop(self):
        esp=int(gdb.parse_and_eval('$esp'))
        nm=rd(u32(esp+4),40).split(b'\0')[0].decode('latin1')
        OUT.write('P %s\n'%nm); OUT.flush(); return False
class BS(gdb.Breakpoint):
    def stop(self):
        esi=int(gdb.parse_and_eval('$esi')); eax=int(gdb.parse_and_eval('$eax'))
        OUT.write('S %s %s\n'%(name(u32(esi+4)),name(eax))); OUT.flush(); return False
class BEntry(gdb.Breakpoint):
    def stop(self):
        OUT.write('FUNC\n'); OUT.flush(); return False
class BG(gdb.Breakpoint):
    def stop(self):
        cls=s8(0x6684c8); base=u32(0x65cfe4)
        first=s32(0x652168+4*cls); cnt=s32(0x65b860+4*cls)
        OUT.write('=== graph class %d first %d count %d\n'%(cls,first,cnt))
        for i in range(first,cnt):
            node=base+i*0x3c; obj=u32(node+4)
            OUT.write('N %d c=%d obj=%s\n'%(i,s16(node+0x2c),name(obj) if obj else '-'))
        OUT.flush(); return False
gdb.execute('set pagination off'); gdb.execute('set confirm off')
for sig in ['SIGSEGV','SIGILL','SIGUSR1']: gdb.execute('handle %s nostop noprint pass'%sig)
gdb.execute('break _ZN4wibo10Executable6loadPEEP8_IO_FILEb')
gdb.execute('run'); gdb.execute('finish'); gdb.execute('delete')
gdb.execute('set $fctrl = 0x27f')
BV('*0x507855'); BP('*0x57c420'); BS('*0x59d3ff'); BU('*0x44598b'); BEntry('*0x508800'); BG('*0x527042')
gdb.execute('continue')
