// TwlSDK MI DMA (mi_dma.c, ITCM part): MIi_DmaSetParameters

#include "nitro/os.h"
#include "nitro/ioreg.h"

#define MIi_DMA_MODE_NOINT   0x0001
#define MIi_DMA_MODE_WAIT    0x0002
#define MIi_DMA_MODE_NOCLEAR 0x0004
#define MIi_DMA_MODE_SRC32   0x0010
#define MIi_DMA_MODE_SRC16   0x0020

// The first 0x20 bytes of ITCM are zero and nothing refers to them. As a separate gap they were
// dead-stripped at link time, so they are emitted here as zero words (andeq r0, r0, r0) and kept
// with force_active.
#pragma force_active on
void ITCMi_Pad(void);

asm void ITCMi_Pad(void) {
    andeq r0, r0, r0
    andeq r0, r0, r0
    andeq r0, r0, r0
    andeq r0, r0, r0
    andeq r0, r0, r0
    andeq r0, r0, r0
    andeq r0, r0, r0
    andeq r0, r0, r0
}
#pragma force_active reset

void MIi_DmaSetParameters(u32 dmaNo, u32 src, u32 dest, u32 ctrl, u32 mode) {
    OSIntrMode enabled;
    vu32 *p;

    if (!(mode & MIi_DMA_MODE_NOINT)) {
        enabled = OS_DisableInterrupts();
    }
    p = (vu32 *)((u32)REG_DMA0SAD_ADDR + dmaNo * 12);
    if (mode & MIi_DMA_MODE_SRC32) {
        vu32 *dmaSrc = (vu32 *)((u32)REG_DMA0_CLR_DATA_ADDR + dmaNo * 4);
        *dmaSrc = src;
        src = (u32)dmaSrc;
    } else if (mode & MIi_DMA_MODE_SRC16) {
        vu16 *dmaSrc = (vu16 *)((u32)REG_DMA0_CLR_DATA_ADDR + dmaNo * 4);
        *dmaSrc = (u16)src;
        src = (u32)dmaSrc;
    }
    *p = src;
    *(p + 1) = dest;
    *(p + 2) = ctrl;
    if (mode & MIi_DMA_MODE_WAIT) {
        u32 dummy;
        dummy = reg_MI_DMA0SAD;
        dummy = reg_MI_DMA0SAD;
        if (!(mode & MIi_DMA_MODE_NOCLEAR) && dmaNo == 0) {
            *p = 0;
            *(p + 1) = 0;
            *(p + 2) = 0x81400001;
        }
    }
    if (!(mode & MIi_DMA_MODE_NOINT)) {
        (void)OS_RestoreInterrupts(enabled);
    }
    if (mode & MIi_DMA_MODE_WAIT) {
        u32 dummy;
        dummy = reg_MI_DMA0SAD;
        dummy = reg_MI_DMA0SAD;
    }
}
