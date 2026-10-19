# classconv.py file: flatten C++ classes into C structs (post-preprocess)
import sys,re
p=sys.argv[1]; s=open(p).read()
fields={}
declared=set()
def repl_fwd(m):
    n=m[1]
    if n in declared: return ''
    declared.add(n); return 'typedef struct %s %s;'%(n,n)
out=[];pos=0
pat=re.compile(r'\bclass\s+(\w+)\s*;|\bclass\s+(\w+)\s*(?::\s*public\s+(\w+))?\s*\{')
while True:
    m=pat.search(s,pos)
    if not m: out.append(s[pos:]); break
    out.append(s[pos:m.start()])
    if m[1]:
        n=m[1]
        if n not in declared:
            declared.add(n); out.append('typedef struct %s %s;'%(n,n))
        pos=m.end(); continue
    n,base=m[2],m[3]
    # find body end
    i=m.end();d=1
    while d:
        if s[i]=='{': d+=1
        elif s[i]=='}': d-=1
        i+=1
    body=s[m.end():i-1]
    j=s.index(';',i)
    lines=[]
    virt=False
    # split body into statements at top-level ';' or method bodies
    stmts=[];cur='';d=0
    for c in body:
        cur+=c
        if c=='{': d+=1
        elif c=='}':
            d-=1
            if d==0: stmts.append(cur); cur=''
        elif c==';' and d==0: stmts.append(cur); cur=''
    for st in stmts:
        t=re.sub(r'\b(public|private|protected)\s*:','',st).strip()
        if not t: continue
        if t.startswith('virtual'): virt=True; continue
        if '(' in t and not re.search(r'\(\s*\*',t): continue
        lines.append(t)
    pre=[]
    if base=='VObj' or (base is None and virt): pre=['void *__vt;']
    elif base: pre=list(fields.get(base,[]))
    fl=pre+lines
    fields[n]=fl
    td='' if n in declared else 'typedef struct %s %s;\n'%(n,n)
    declared.add(n)
    out.append(td+'struct %s {\n    %s\n};'%(n,'\n    '.join(fl)))
    pos=j+1
open(p,'w').write(''.join(out))
