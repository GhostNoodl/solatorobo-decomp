# tools/landing.py: gdb script for mwccarm dsi/1.3 (run through tools/landing.sh).
# For every function (or only backend function number FN), takes two CFG snapshots with instructions:
# the first backend one (0x474a18, i.e. the front-end CFG) and the one move-constant-loads step 4 works on
# (0x526b02, after its loop analysis). For each loop preheader the loop analysis added, prints the block in
# front of it (the guard, or the front end's loop landing block) in both snapshots, and EMPTY when that block
# has no instructions at step 4 (step 4 then refuses to move constants from the preheader into it, docs round hzV).
import gdb,struct,os,re
inf=lambda: gdb.selected_inferior()
def rd(a,n): return bytes(inf().read_memory(a,n))
def u32(a): return struct.unpack('<I',rd(a,4))[0]
def u16(a): return struct.unpack('<H',rd(a,2))[0]
def s16(a): return struct.unpack('<h',rd(a,2))[0]
def s32(a): return struct.unpack('<i',rd(a,4))[0]
gdb.execute('set pagination off'); gdb.execute('set confirm off')
for sig in ['SIGSEGV','SIGILL','SIGUSR1']: gdb.execute('handle %s nostop noprint pass'%sig)
gdb.execute('break _ZN4wibo10Executable6loadPEEP8_IO_FILEb')
gdb.execute('run'); gdb.execute('finish'); gdb.execute('delete')
gdb.execute('set $fctrl = 0x27f')
OUT=open(os.environ['LANDING_OUT'],'w'); WANT=os.environ.get('FN','')
def ins(pc):
    op=u16(pc+0x28); n=s16(pc+0x2c); a=[]
    for k in range(min(n,12)):
        p=pc+0x2e+k*0xe; kind=rd(p,1)[0]; cl=rd(p+1,1)[0]; v=s32(p+4); f=u16(p+2)
        if kind==0: a.append('%sv%d%s'%('' if cl==0 else 'c%d:'%cl,v,{1:'<',2:'>',3:'<>'}.get(f&3,'')))
        else: a.append('k%d:%x'%(kind,s32(p+2)&0xffffffff))
    s='op%d %s'%(op,' '.join(a))
    return 'CALL' if op in (6,157) else s
def snap():
    b=u32(0x65bda8); D={}
    while b:
        pc=u32(b+0x14); I=[]
        while pc: I.append(ins(pc)); pc=u32(pc)
        pr=[]; e=u32(b+0xc)
        while e: pr.append(u32(u32(e+0xc)+0x1c)); e=u32(e+8)
        D[u32(b+0x1c)]=(pr,I); b=u32(b)
    return D
ST={'fn':0,'fe':None}
def report(at):
    fe=ST['fe']; mx=max(fe)
    OUT.write('== function %d\n'%ST['fn'])
    for b,(pr,I) in sorted(at.items()):
        if b>mx and len(pr)==1 and I and I[-1].startswith('op151'):
            p=pr[0]; fi=fe.get(p,([],['?']))[1]; ai=at[p][1]
            OUT.write('  preheader B%d <- B%d%s\n    front end (%d): %s\n    step 4    (%d): %s\n'%(
                b,p,'  EMPTY' if not ai else '',len(fi),' ; '.join(fi),len(ai),' ; '.join(ai)))
    OUT.flush()
class Fn(gdb.Breakpoint):
    def stop(s): ST['fn']+=1; ST['fe']=None; return False
class Fe(gdb.Breakpoint):
    def stop(s):
        if WANT in ('',str(ST['fn'])) and ST['fe'] is None: ST['fe']=snap()
        return False
class At(gdb.Breakpoint):
    def stop(s):
        try:
            if WANT in ('',str(ST['fn'])) and ST['fe'] is not None: report(snap())
        except Exception as e: OUT.write('ERR %s\n'%e)
        return False
Fn('*0x474a13'); Fe('*0x474a18'); At('*0x526b02')
gdb.execute('continue')
