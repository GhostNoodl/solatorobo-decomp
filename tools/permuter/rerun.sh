#!/bin/bash
# rerun.sh <addr> <secs> [jobs]: continue permuting p_<addr> from its best output so far, in q_<addr>
. "$(dirname "$0")/env.sh"
a=$1; src=$PERM_WORK/p_$a; d=$PERM_WORK/q_$a
rm -rf "$d"; mkdir -p "$d"
cp "$src/target.o" "$src/compile.sh" "$src/settings.toml" "$d/"
best=$(ls -d "$src"/output-* 2>/dev/null | sed 's/.*output-\([0-9]*\)-.*/\1 &/' | sort -n | head -1 | cut -d' ' -f2)
if [ -n "$best" ]; then cp "$best/source.c" "$d/base.c"; else cp "$src/base.c" "$d/base.c"; fi
PERM_FUNC=func_${PERM_MODULE}_$a timeout "$2" python3 "$PERMUTER/permuter.py" "$d" -j"${3:-1}" --stop-on-zero > "$d/perm.log" 2>&1
echo "$a $(grep -ao 'base score = [0-9]*' "$d/perm.log" | head -1) $(grep -ao 'new best score! ([0-9]* vs [0-9]*)' "$d/perm.log" | tail -1)"
