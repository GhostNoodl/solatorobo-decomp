#!/bin/bash
# tools/vnum.sh SRC [FUNC] : compile SRC (with -d NONMATCHING) under gdb (tools/vnum_gdb.py) and print, for
# FUNC (default: the last function in SRC), every object vreg in number order with the band that made it
# (param/user, inline, scalarized struct field, CSE, LICM, split web of VAR, backend call/?: temp) and its
# final colour. Round rgA. The raw log is build/vnum/vn.out.
cd "$(dirname "$0")/.." || exit 1
f=$(readlink -f "$1"); case $f in *.cpp) L=c++;; *) L=c;; esac
mkdir -p build/vnum
VNOUT=$PWD/build/vnum/vn.out TMPDIR=$PWD/build/vnum gdb --batch -x tools/vnum_gdb.py --args ./wibo ./tools/mwccarm/dsi/1.3/mwccarm.exe -O4,p -enum int -char signed -str noreuse -proc arm946e -gccext,on -fp soft -inline noauto -Cpp_exceptions off -RTTI off -interworking -w off -sym on -gccinc -nolink -msgstyle gcc -i include -d usa -d NONMATCHING -lang=$L -c "$f" -o build/vnum/out.o > build/vnum/gdb.log 2>&1
python3 tools/vnum.py build/vnum/vn.out "$2"
