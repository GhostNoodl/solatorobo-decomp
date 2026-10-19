# Shared settings for the permuter helper scripts. Override any of these in the environment.
#   DECOMP_ROOT  repository root (default: two levels above this directory)
#   PERM_WORK    where permuter directories (p_<addr>/) are created (default: $DECOMP_ROOT/build/permuter)
#   PERMUTER     decomp-permuter checkout containing permuter.py (default: $PERM_WORK/decomp-permuter)
#   PERM_MODULE  overlay module, e.g. ov000 (default: ov000)
PERM_TOOLS=$(cd "$(dirname "${BASH_SOURCE[0]}")" && pwd)
DECOMP_ROOT=${DECOMP_ROOT:-$(cd "$PERM_TOOLS/../.." && pwd)}
PERM_WORK=${PERM_WORK:-$DECOMP_ROOT/build/permuter}
PERMUTER=${PERMUTER:-$PERM_WORK/decomp-permuter}
PERM_MODULE=${PERM_MODULE:-ov000}
export DECOMP_ROOT PERM_WORK PERMUTER PERM_MODULE PERM_TOOLS
