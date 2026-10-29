#!/bin/bash
# tools/frtrace.sh SRC [OUT] : compile SRC (with -d NONMATCHING) under gdb and print the frame trace
# of tools/frtrace.py (default OUT: build/frtrace.out). Env NOREG passes through. Needs gdb.
cd "$(dirname "$0")/.." || exit 1
f=$(readlink -f "$1"); out=$(readlink -f "${2:-build/frtrace.out}")
case $f in *.cpp) L=c++;; *) L=c;; esac
mkdir -p build/frtrace_tmp
FROUT=$out TMPDIR=$PWD/build/frtrace_tmp gdb --batch -x tools/frtrace.py --args ./wibo ./tools/mwccarm/dsi/1.3/mwccarm.exe -O4,p -enum int -char signed -str noreuse -proc arm946e -gccext,on -fp soft -inline noauto -Cpp_exceptions off -RTTI off -interworking -w off -sym on -gccinc -nolink -msgstyle gcc -i include -d usa -d NONMATCHING -lang=$L -c "$f" -o build/frtrace_tmp/out.o > build/frtrace_tmp/gdb.log 2>&1
cat "$out"
