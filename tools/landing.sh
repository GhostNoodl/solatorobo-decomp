#!/bin/bash
# tools/landing.sh SRC [OUT] : compile SRC (with -d NONMATCHING) under gdb and, for each backend function
# (FN=n for one), print every loop preheader's predecessor block in the front-end CFG and at
# move-constant-loads step 4, marking it EMPTY when it holds nothing at step 4 (see docs/MATCHING.md round hzV).
# Needs gdb. Default OUT: build/landing.out.
cd "$(dirname "$0")/.." || exit 1
f=$(readlink -f "$1"); out=$(readlink -f "${2:-build/landing.out}")
case $f in *.cpp) L=c++;; *) L=c;; esac
mkdir -p build/landing_tmp
LANDING_OUT=$out TMPDIR=$PWD/build/landing_tmp gdb --batch -x tools/landing.py --args ./wibo ./tools/mwccarm/dsi/1.3/mwccarm.exe -O4,p -enum int -char signed -str noreuse -proc arm946e -gccext,on -fp soft -inline noauto -Cpp_exceptions off -RTTI off -interworking -w off -sym on -gccinc -nolink -msgstyle gcc -i include -d usa -d NONMATCHING -lang=$L -c "$f" -o build/landing_tmp/out.o > build/landing_tmp/gdb.log 2>&1
cat "$out"
