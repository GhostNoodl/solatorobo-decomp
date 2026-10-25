// The FX trigonometry tables. Both are computed by tools/gen_tables.py at build time:
//   FX_SinCosTable_[i * 2], [i * 2 + 1] = sin, cos of 2*pi*i/4096 in fx16 (4096 = 1.0), i < 4096
//   FX_AtanTable_[i] = atan(i / 128) in the 65536-per-turn angle unit, i <= 128
// Written as asm blocks so they land in main's .text with the other read-only data (see
// libs/msl/ctype.c).

#pragma force_active on

// const fx16 FX_SinCosTable_[4096 * 2]
void FX_SinCosTable_(void);
// const fx16 FX_AtanTable_[128 + 1]
void FX_AtanTable_(void);

asm void FX_SinCosTable_(void) {
#include "fx_sincos.inc"
}

asm void FX_AtanTable_(void) {
#include "fx_atan.inc"
}

#pragma force_active reset
