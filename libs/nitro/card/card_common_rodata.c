// The ROM accessor CARDi_GetRomAccessor returns for a NITRO card: the DMA copy and stop
// functions. Written as an asm block so it lands in main's .text with the other read-only data
// (see libs/msl/ctype.c).

void MIi_CardDmaCopy32(void);
void MI_StopDma(void);

#pragma force_active on

// static const CARDRomAccessor (two function pointers)
void data_02070ee4(void);

asm void data_02070ee4(void) {
    dcd MIi_CardDmaCopy32
    dcd MI_StopDma
}

#pragma force_active reset
