#!/bin/bash
# cc.sh <in.c> <out.o>: compile permuter C back as C++ (VC_xx(obj, ...) -> obj->vfunc_xx(...))
. "$(dirname "$0")/env.sh"
tmp=$(mktemp --suffix=.cpp -p "${TMPDIR:-/tmp}")
python3 "$PERM_TOOLS/wrap.py" "$1" > "$tmp"
"$DECOMP_ROOT/wibo" "$DECOMP_ROOT/tools/mwccarm/dsi/1.3/mwccarm.exe" -O4,p -enum int -char signed -str noreuse \
    -proc arm946e -gccext,on -fp soft -inline noauto -Cpp_exceptions off -RTTI off -interworking -w off -sym on \
    -nolink -msgstyle gcc -lang=c++ -i "$DECOMP_ROOT/include" -c "$tmp" -o "$2" > "$tmp.log" 2>&1
rc=$?
[ -n "$KEEPLOG" ] && cat "$tmp.log"
rm -f "$tmp" "$tmp.log"
exit $rc
