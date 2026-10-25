// SNDi_DecibelTable[i] = 20 * log10(i / 127) in 0.1 dB, with -32768 for i = 0: the attenuation of
// a 0-127 volume. Computed by tools/gen_tables.py at build time and written as an asm block so it
// lands in main's .text with the other read-only data (see libs/msl/ctype.c). snd_util.c's other
// table, sVolumeTable (the channel volume for each 0.1 dB step), is still in the gap: the formula
// round(128 * 10^(dB / 200) * 2^shift) clamped to 127 gives it except for three entries.

#pragma force_active on

// const s16 SNDi_DecibelTable[128]
void SNDi_DecibelTable(void);

asm void SNDi_DecibelTable(void) {
#include "snd_decibel.inc"
}

#pragma force_active reset
