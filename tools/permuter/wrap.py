import sys,re
s=open(sys.argv[1]).read()
s=re.sub(r'^(static )?inline [^;{]*\);\s*$','',s,flags=re.M)
s=re.sub(r'^typedef struct VObj VObj;\s*$','',s,flags=re.M)
s=re.sub(r'^.*\bVC_[0-9a-f]+\s*\(VObj \*[^;]*\);\s*$','',s,flags=re.M)
while True:
    m=re.search(r'\bVC_([0-9a-f]+)\(',s)
    if not m: break
    i=m.end(); d=1; comma=None
    while d:
        c=s[i]
        if c in '([': d+=1
        elif c in ')]': d-=1
        elif c==',' and d==1 and comma is None: comma=i
        i+=1
    end=i-1
    if comma is None: obj=s[m.end():end]; rest=''
    else: obj=s[m.end():comma]; rest=s[comma+1:end]
    s=s[:m.start()]+'(((VObj *)(%s))->vfunc_%s(%s))'%(obj,m[1],rest)+s[i:]
print('#include "ov000/VObj.h"\nextern "C" {\n'+s+'\n}')
