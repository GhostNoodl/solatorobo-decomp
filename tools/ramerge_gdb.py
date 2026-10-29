# tools/ramerge_gdb.py: gdb script for mwccarm dsi/1.3 (run through tools/ramerge.sh). At each colouring
# pass it writes the interference graph: node number, colour (c=), flags, cost, neighbours and object name.
import gdb,os
inf=None
def rd(addr,size):
    m=gdb.selected_inferior().read_memory(addr,size)
    return bytes(m)
import struct
def u32(a): return struct.unpack('<I',rd(a,4))[0]
def s32(a): return struct.unpack('<i',rd(a,4))[0]
def u16(a): return struct.unpack('<H',rd(a,2))[0]
def s16(a): return struct.unpack('<h',rd(a,2))[0]
def s8(a): return struct.unpack('<b',rd(a,1))[0]
OUT=open(os.environ.get('RAOUT','build/ramerge/ra.out'),'w')
state={'n':0}
def neighbors(base,i):
    node=base+i*0x3c
    e=u32(node+0x38); res=[]
    me=s32(node+0x28)
    while e:
        b=s32(e+0x10)
        if me < b: res.append(b); e=u32(e+4)
        else: res.append(s32(e+0xc)); e=u32(e+8)
    return res
class BEntry(gdb.Breakpoint):
    def stop(self):
        esp=int(gdb.parse_and_eval('$esp'))
        top=u32(esp+4)
        cls=s8(0x6684c8)
        base=u32(0x65cfe4)
        first=s32(0x652168+4*cls); cnt=s32(0x65b860+4*cls)
        order=[]
        p=top
        while p:
            order.append((p-base)//0x3c); p=u32(p)
        state['order']=order; state['base']=base; state['cls']=cls; state['first']=first; state['cnt']=cnt
        return False
class BExit(gdb.Breakpoint):
    def stop(self):
        base=state['base']; cls=state['cls']
        state['n']+=1
        OUT.write('=== colorgraph #%d class %d first %d count %d\n'%(state['n'],cls,state['first'],state['cnt']))
        OUT.write('order '+' '.join(map(str,state['order']))+'\n')
        for i in range(state['first'],state['cnt']):
            node=base+i*0x3c
            obj=u32(node+4); nm='-'
            if obj:
                try:
                    hn=u32(obj+8)
                    nm=rd(hn+0xa,40).split(b'\0')[0].decode('latin1') if hn else '?'
                except Exception as e: nm='err'
            OUT.write('%d c=%d fl=%x deg=%d cost=%d nb=%s obj=%s\n'%(i,s16(node+0x2c),u16(node+0x2e),s16(node+0x30),s32(node+0xc),','.join(map(str,neighbors(base,i))),nm))
        OUT.flush()
        return False
gdb.execute('set pagination off'); gdb.execute('set confirm off')
for sig in ['SIGSEGV','SIGILL','SIGUSR1']: gdb.execute('handle %s nostop noprint pass'%sig)
gdb.execute('break _ZN4wibo10Executable6loadPEEP8_IO_FILEb')
gdb.execute('run')
gdb.execute('finish')
gdb.execute('delete')
gdb.execute('set $fctrl = 0x27f')
BEntry('*0x526f30'); BExit('*0x527042')
gdb.execute('continue')
