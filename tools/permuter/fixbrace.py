import sys,re
p=sys.argv[1]; s=open(p).read()
# remove 'extern "C" {' and its matching '}'
while True:
    m=re.search(r'extern\s+"C"\s*\{',s)
    if not m: break
    i=m.end(); depth=1
    while depth:
        c=s[i]
        if c=='{': depth+=1
        elif c=='}': depth-=1
        elif c=='/' and s[i+1]=='/': i=s.index('\n',i)-1
        elif c=='/' and s[i+1]=='*': i=s.index('*/',i)+1
        elif c in '"\'':
            j=i+1
            while s[j]!=c:
                j+= 2 if s[j]=='\\' else 1
            i=j
        i+=1
    s=s[:m.start()]+s[m.end():i-1]+s[i:]
s=re.sub(r'extern\s+"C"\s+','extern ',s)
open(p,'w').write(s)
