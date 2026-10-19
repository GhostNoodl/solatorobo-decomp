# conv.py file : rewrite C++ vfunc calls into VC_xx(obj, args) for C parsing
import sys,re
p=sys.argv[1]; s=open(p).read()
offs=set()
def find_obj_start(s,i):
    # i: index of '->' ; walk back over a primary expression
    j=i
    depth=0
    while j>0:
        c=s[j-1]
        if c in ')]':
            depth+=1
        elif c in '([':
            if depth==0: break
            depth-=1
        elif depth==0 and not (c.isalnum() or c in '_.' or (c=='>' and s[j-2]=='-') or (c=='-' and s[j]=='>')):
            break
        j-=1
    # include a preceding identifier for calls like LFLD(...)
    return j
while True:
    m=re.search(r'(->|\.)vfunc_([0-9a-f]+)\(',s)
    if not m: break
    off=m[2]; offs.add(off)
    st=find_obj_start(s,m.start())
    obj=s[st:m.start()]
    if m[1]=='.': obj='&'+obj
    rest=s[m.end():]
    if rest.lstrip().startswith(')'):
        new='VC_%s(%s'%(off,obj)
    else:
        new='VC_%s(%s, '%(off,obj)
    s=s[:st]+new+s[m.end():]
decl=''.join('int VC_%s(VObj *o, ...);\n'%o for o in sorted(offs))
s=re.sub(r'^typedef struct VObj VObj;[ \t]*$','',s,flags=re.M)
decl='typedef struct VObj VObj;\n'+decl
s=decl+s
open(p,'w').write(s)
