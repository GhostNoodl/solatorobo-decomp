#!/bin/sh
# usage: tools/asm2mw/mkfile.sh OUT.c "header comment" MODULE START END [asm2mw options...]
# Writes OUT.c = header + "#pragma force_active on" + verified asm2mw output.
set -e
out=$1; hdr=$2; shift 2
dir=$(dirname "$0")
tmp=$(mktemp)
python3 "$dir/asm2mw.py" "$@" --verify > "$tmp"
{ printf '%s\n' "$hdr" | sed 's#^#// #'; printf '\n#pragma force_active on\n\n'; cat "$tmp"; } > "$out"
rm -f "$tmp"
