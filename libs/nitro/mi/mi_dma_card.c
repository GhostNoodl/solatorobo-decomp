#include "nitro/ioreg.h"

#define MI_DMA_ENABLE        0x80000000
#define MI_DMA_TIMING_CARD   0x28000000
#define MI_DMA_CONTINUOUS_ON 0x02000000
#define MI_DMA_SRC_FIX       0x01000000
#define MI_DMA_32BIT_BUS     0x04000000
#define MIi_DMA_TIMING_ANY   ((u32)~0)

#define MI_CNT_CARDRECV32(size) (MI_DMA_ENABLE | MI_DMA_TIMING_CARD | MI_DMA_SRC_FIX | MI_DMA_32BIT_BUS | ((size) / 4))

// MIi_DmaSetParameters lives in ITCM (mi_dma_itcm.c)
void MIi_DmaSetParameters(u32 dmaNo, u32 src, u32 dest, u32 ctrl, u32 mode);
#define MIi_DmaSetParams(dmaNo, src, dest, ctrl) MIi_DmaSetParameters(dmaNo, src, dest, ctrl, 0)

void MIi_CheckAnotherAutoDMA(u32 dmaNo, u32 dmaType);
void MIi_CheckDma0SourceAddress(u32 dmaNo, u32 src, u32 size, u32 dir);

#define MIi_Wait_BeforeDMA(dmaCntp, dmaNo)                    \
    do {                                                      \
        dmaCntp = &((vu32 *)REG_DMA0SAD_ADDR)[dmaNo * 3 + 2]; \
        while (*dmaCntp & REG_MI_DMA0CNT_E_MASK) {}           \
    } while (0)

void MIi_CardDmaCopy32(u32 dmaNo, const void *src, void *dest, u32 size) {
    vu32 *dmaCntp;

    MIi_CheckAnotherAutoDMA(dmaNo, MIi_DMA_TIMING_ANY);
    MIi_CheckDma0SourceAddress(dmaNo, (u32)src, size, MI_DMA_SRC_FIX);

    if (size == 0) {
        return;
    }

    MIi_Wait_BeforeDMA(dmaCntp, dmaNo);
    MIi_DmaSetParams(dmaNo, (u32)src, (u32)dest, (u32)(MI_CNT_CARDRECV32(4) | MI_DMA_CONTINUOUS_ON));
}
