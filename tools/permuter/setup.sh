#!/bin/bash
# setup.sh <draft.cpp> <addr> [dir]: make a decomp-permuter directory for func_<module>_<addr>
set -e
. "$(dirname "$0")/env.sh"
src=$(realpath "$1"); a=$2; d=${3:-$PERM_WORK/p_$a}
mkdir -p "$d"; d=$(realpath "$d")
fn=func_${PERM_MODULE}_$a
cp "$src" "$d/orig.c"
gcc -E -P -I "$DECOMP_ROOT/include" -D'__attribute__(x)=' -DPERMUTER -x c "$d/orig.c" > "$d/base.c"
python3 "$PERM_TOOLS/fixbrace.py" "$d/base.c"
python3 "$PERM_TOOLS/classconv.py" "$d/base.c"
python3 "$PERM_TOOLS/conv.py" "$d/base.c"
python3 "$PERM_TOOLS/mktarget.py" "$a" "$d/target.o"
printf '#!/bin/bash\nexec %s/cc.sh "$1" "$3"\n' "$PERM_TOOLS" > "$d/compile.sh"
chmod +x "$d/compile.sh"
printf 'func_name = "%s"\ncompiler_type = "mwcc"\nobjdump_command = "python3 %s/fakeobjdump.py"\n' "$fn" "$PERM_TOOLS" > "$d/settings.toml"
echo "$d"
