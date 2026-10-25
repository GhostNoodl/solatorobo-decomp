// snd_util.c's two tables, computed by tools/gen_tables.py at build time and written as asm blocks
// so they land in main's .text with the other read-only data (see libs/msl/ctype.c).
//
// SNDi_DecibelTable[i] = 20 * log10(i / 127) in 0.1 dB, with -32768 for i = 0: the attenuation of
// a 0-127 volume.
//
// sVolumeTable[dB + 723]: the channel volume multiplier for -72.3..0 dB, with the divider
// SND_CalcChannelVolume picks for the range folded in (see volume() in tools/gen_tables.py).

#pragma force_active on

// const s16 SNDi_DecibelTable[128]
void SNDi_DecibelTable(void);

asm void SNDi_DecibelTable(void) {
#include "snd_decibel.inc"
}

// static const u8 sVolumeTable[724]
void sVolumeTable(void);

asm void sVolumeTable(void) {
#include "snd_volume.inc"
}

#pragma force_active reset
