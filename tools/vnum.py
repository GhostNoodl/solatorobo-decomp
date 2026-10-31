#!/usr/bin/env python3
"""tools/vnum.py LOG [FUNC]: report of tools/vnum.sh (round rgA). See docs/MATCHING.md, round rgA.

Object vregs are numbered at function start: parameters first, then the function's object list newest
first. The list is prepended to as objects are created, so the creation phase decides the band:
user locals (parse order) > inline temps > ScalarizeClassDataMembers > LICM/CSE > SplitLifetimes webs >
backend call-result / ?: temps > parameters. FUNC picks the function by the name of any of its objects
(default: the last function in the log)."""
import sys
L=open(sys.argv[1],encoding='latin1').read().split('\n')
want=sys.argv[2] if len(sys.argv)>2 and sys.argv[2] else None
idx=[i for i,l in enumerate(L) if l=='FUNC']
segs=[]
for k,i in enumerate(idx):
    lo=idx[k-1] if k else 0
    hi=idx[k+1] if k+1<len(idx) else len(L)
    segs.append((lo,i,hi))
SITE={'59e159':'backend call result','59dd21':'backend ?:/value temp','59eddb':'backend'}
def report(lo,i,hi):
    pend=[];site={};sp={}
    for l in L[lo:i]:
        w=l.split()
        if not w: continue
        if w[0]=='U': pend.append(w[1]); site[w[1]]=w[2:]
        elif w[0]=='P':
            nm=' '.join(w[1:])
            for n in pend: site[n]=('pre-IRO (frontend/inline)' if nm=='IRO_BuildflowGraph' else nm)
            pend=[]
        elif w[0]=='S': sp[w[2]]=w[1]
    for n in pend:
        st=site[n]; d='post-IRO'
        for a in st[:3]:
            if a in SITE: d=SITE[a]; break
        site[n]=d
    col={}
    g=[j for j in range(i,hi) if L[j].startswith('=== graph')]
    if g:
        for l in L[g[-1]+1:hi]:
            w=l.split()
            if not w or w[0]!='N': break
            col[int(w[1])]=w[2]
    out=[]
    for l in L[i:hi]:
        w=l.split()
        if w and w[0]=='V':
            n=w[3]
            if n in sp: d='SplitLifetimes web of '+sp[n]
            elif n.startswith('@'): d=site.get(n,'?')
            else: d='param/user'
            out.append('%s %s %s %s'%(w[1],n,d,col.get(int(w[1]),'')))
    return out
for lo,i,hi in (segs if want else segs[-1:]):
    r=report(lo,i,hi)
    if want and not any((' %s '%want) in x for x in r): continue
    print('\n'.join(r)); print()
