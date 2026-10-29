#!/bin/bash
# tools/ramerge.sh SRC [OUT] : compile SRC (with -d NONMATCHING) under gdb and dump every colour graph
# (tools/ramerge_gdb.py) to OUT (default build/ramerge/ra.out). Then run tools/ramerge.py on it.
cd "$(dirname "$0")/.." || exit 1
f=$(readlink -f "$1"); out=$(readlink -f -m "${2:-build/ramerge/ra.out}")
case $f in *.cpp) L=c++;; *) L=c;; esac
mkdir -p build/ramerge "$(dirname "$out")"
RAOUT=$out TMPDIR=$PWD/build/ramerge gdb --batch -x tools/ramerge_gdb.py --args ./wibo ./tools/mwccarm/dsi/1.3/mwccarm.exe -O4,p -enum int -char signed -str noreuse -proc arm946e -gccext,on -fp soft -inline noauto -Cpp_exceptions off -RTTI off -interworking -w off -sym on -gccinc -nolink -msgstyle gcc -i include -d usa -d NONMATCHING -lang=$L -c "$f" -o build/ramerge/out.o > build/ramerge/gdb.log 2>&1
grep -c '^=== ' "$out"
