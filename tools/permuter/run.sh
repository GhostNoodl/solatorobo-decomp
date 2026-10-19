#!/bin/bash
# run.sh <draft.cpp> <addr> <secs> [jobs]: set up p_<addr> from a draft and permute it for <secs> seconds
. "$(dirname "$0")/env.sh"
d=$PERM_WORK/p_$2
rm -rf "$d"
"$PERM_TOOLS/setup.sh" "$1" "$2" "$d" > /dev/null || { echo "setup failed for $2"; exit 1; }
PERM_FUNC=func_${PERM_MODULE}_$2 timeout "$3" python3 "$PERMUTER/permuter.py" "$d" -j"${4:-1}" --stop-on-zero > "$d/perm.log" 2>&1
grep -ao "base score = [0-9]*" "$d/perm.log" | head -1
grep -ao "new best score! ([0-9]* vs [0-9]*)" "$d/perm.log" | tail -1
