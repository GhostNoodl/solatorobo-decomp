#!/bin/bash
# pdiff.sh <permdir> [source.c]: diff a permuter source (default base.c) against the target, as the scorer sees it
. "$(dirname "$0")/env.sh"
d=$1; s=${2:-$d/base.c}
f=$(sed -n 's/func_name = "\(.*\)"/\1/p' "$d/settings.toml")
o=$(mktemp -p "${TMPDIR:-/tmp}" --suffix=.o)
"$PERM_TOOLS/cc.sh" "$s" "$o" || { echo "compile failed"; exit 1; }
PERM_FUNC=$f python3 "$PERM_TOOLS/fakeobjdump.py" "$o" | cut -f3- > "$o.a"
python3 "$PERM_TOOLS/fakeobjdump.py" "$d/target.o" | cut -f3- > "$o.t"
diff "$o.t" "$o.a"; rm -f "$o" "$o.a" "$o.t"
