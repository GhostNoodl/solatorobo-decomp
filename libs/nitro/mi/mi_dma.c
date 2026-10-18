#include "nitro/mi.h"
#include "nitro/os.h"
#include "nitro/ioreg.h"

typedef void (*MIDmaCallback)(void *arg);

#define MI_DMA_ENABLE        0x80000000
#define MI_DMA_IF_ENABLE     0x40000000
#define MI_DMA_TIMING_MASK   0x38000000
#define MI_DMA_CONTINUOUS_ON 0x02000000
#define MI_DMA_SRC_FIX       0x01000000
#define MI_DMA_32BIT_BUS     0x04000000
#define MI_DMA_SRC_INC       0x00000000
#define MI_DMA_SRC_DEC       0x00800000
#define MI_DMA_MAX_NUM       3

#define MI_DMA_TIMING_V_BLANK   0x08000000
#define MI_DMA_TIMING_H_BLANK   0x10000000
#define MI_DMA_TIMING_DISP      0x18000000
#define MI_DMA_TIMING_DISP_MMEM 0x20000000
#define MI_DMA_TIMING_CARD      0x28000000
#define MI_DMA_TIMING_CARTRIDGE 0x30000000
#define MI_DMA_TIMING_GXFIFO    0x38000000

#define reg_SCFG_EXT (*(vu32 *)0x04004008)

#define MI_CNT_CLEAR32(size)  (MI_DMA_ENABLE | MI_DMA_SRC_FIX | MI_DMA_32BIT_BUS | ((size) / 4))
#define MI_CNT_COPY32(size)   (MI_DMA_ENABLE | MI_DMA_32BIT_BUS | ((size) / 4))
#define MI_CNT_COPY16(size)   (MI_DMA_ENABLE | ((size) / 2))
#define MI_CNT_SET_CLEAR32(size) (MI_DMA_SRC_FIX | MI_DMA_32BIT_BUS | ((size) / 4))
#define MI_CNT_SET_COPY32(size)  (MI_DMA_32BIT_BUS | ((size) / 4))
#define MI_CNT_SET_COPY16(size)  ((size) / 2)

// MIi_DmaSetParameters mode flags (TwlSDK)
#define MIi_DMA_MODE_NOINT  0x0002
#define MIi_DMA_MODE_WAIT   0x0004
#define MIi_DMA_MODE_SRC32  0x0010

#define MIi_DUMMY_DMA_NO 0
#define MIi_DUMMY_SRC    0
#define MIi_DUMMY_DEST   0
#define MIi_DUMMY_CNT    0x81400001

#define MIi_Wait_BeforeDMA(dmaCntp, dmaNo)                    \
    do {                                                      \
        dmaCntp = &((vu32 *)REG_DMA0SAD_ADDR)[dmaNo * 3 + 2]; \
        while (*dmaCntp & REG_MI_DMA0CNT_E_MASK) {}           \
    } while (0)

#define MIi_Wait_AfterDMA(dmaCntp)                            \
    do {                                                      \
        while (*dmaCntp & REG_MI_DMA0CNT_E_MASK) {}           \
    } while (0)

// MIi_DmaSetParameters lives in ITCM under its address name
void func_01ff8020(u32 dmaNo, u32 src, u32 dest, u32 ctrl, u32 mode);
#define MIi_DmaSetParameters func_01ff8020
void OSi_EnterDmaCallback(u32 dmaNo, void (*callback)(void *), void *arg);
void MIi_CheckDma0SourceAddress(u32 dmaNo, u32 src, u32 size, u32 dir);
void MI_WaitDma(u32 dmaNo);
BOOL OS_IsRunOnTwl(void);
void OS_Terminate(void);

static inline void MIi_CallCallback(MIDmaCallback callback, void *arg) {
    if (callback) {
        (callback)(arg);
    }
}

void MIi_DmaFill32(u32 dmaNo, void *dest, u32 data, u32 size, BOOL dmaEnable) {
    vu32 *dmaCntp;

    if (size == 0) {
        return;
    }

    MIi_Wait_BeforeDMA(dmaCntp, dmaNo);
    if (dmaEnable) {
        MIi_DmaSetParameters(dmaNo, data, (u32)dest, MI_CNT_CLEAR32(size), MIi_DMA_MODE_SRC32 | MIi_DMA_MODE_NOINT);
    } else {
        MIi_DmaSetParameters(dmaNo, data, (u32)dest, MI_CNT_SET_CLEAR32(size), MIi_DMA_MODE_SRC32 | MIi_DMA_MODE_WAIT | MIi_DMA_MODE_NOINT);
    }
    MIi_Wait_AfterDMA(dmaCntp);
}

void MIi_DmaCopy32(u32 dmaNo, const void *src, void *dest, u32 size, BOOL dmaEnable) {
    vu32 *dmaCntp;

    if (size == 0) {
        return;
    }

    MIi_CheckDma0SourceAddress(dmaNo, (u32)src, size, 0);

    MIi_Wait_BeforeDMA(dmaCntp, dmaNo);
    if (dmaEnable) {
        MIi_DmaSetParameters(dmaNo, (u32)src, (u32)dest, MI_CNT_COPY32(size), MIi_DMA_MODE_NOINT);
    } else {
        MIi_DmaSetParameters(dmaNo, (u32)src, (u32)dest, MI_CNT_SET_COPY32(size), MIi_DMA_MODE_WAIT | MIi_DMA_MODE_NOINT);
    }
    MIi_Wait_AfterDMA(dmaCntp);
}

void MIi_DmaCopy16(u32 dmaNo, const void *src, void *dest, u32 size, BOOL dmaEnable) {
    vu32 *dmaCntp;

    if (size == 0) {
        return;
    }

    MIi_CheckDma0SourceAddress(dmaNo, (u32)src, size, 0);

    MIi_Wait_BeforeDMA(dmaCntp, dmaNo);
    if (dmaEnable) {
        MIi_DmaSetParameters(dmaNo, (u32)src, (u32)dest, MI_CNT_COPY16(size), MIi_DMA_MODE_NOINT);
    } else {
        MIi_DmaSetParameters(dmaNo, (u32)src, (u32)dest, MI_CNT_SET_COPY16(size), MIi_DMA_MODE_WAIT | MIi_DMA_MODE_NOINT);
    }
    MIi_Wait_AfterDMA(dmaCntp);
}

void MIi_DmaFill32Async(u32 dmaNo, void *dest, u32 data, u32 size, MIDmaCallback callback, void *arg, BOOL dmaEnable) {
    if (size == 0) {
        MIi_CallCallback(callback, arg);
    } else {
        MI_WaitDma(dmaNo);

        if (callback) {
            OSi_EnterDmaCallback(dmaNo, callback, arg);
            if (dmaEnable) {
                MIi_DmaSetParameters(dmaNo, data, (u32)dest, MI_CNT_CLEAR32(size) | MI_DMA_IF_ENABLE, MIi_DMA_MODE_SRC32);
            } else {
                MIi_DmaSetParameters(dmaNo, data, (u32)dest, MI_CNT_SET_CLEAR32(size) | MI_DMA_IF_ENABLE, MIi_DMA_MODE_SRC32 | MIi_DMA_MODE_WAIT);
            }
        } else {
            if (dmaEnable) {
                MIi_DmaSetParameters(dmaNo, data, (u32)dest, MI_CNT_CLEAR32(size), MIi_DMA_MODE_SRC32);
            } else {
                MIi_DmaSetParameters(dmaNo, data, (u32)dest, MI_CNT_SET_CLEAR32(size), MIi_DMA_MODE_SRC32 | MIi_DMA_MODE_WAIT);
            }
        }
    }
}

void MIi_DmaCopy32Async(u32 dmaNo, const void *src, void *dest, u32 size, MIDmaCallback callback, void *arg, BOOL dmaEnable) {
    MIi_CheckDma0SourceAddress(dmaNo, (u32)src, size, 0);

    if (size == 0) {
        MIi_CallCallback(callback, arg);
    } else {
        MI_WaitDma(dmaNo);

        if (callback) {
            OSi_EnterDmaCallback(dmaNo, callback, arg);
            if (dmaEnable) {
                MIi_DmaSetParameters(dmaNo, (u32)src, (u32)dest, MI_CNT_COPY32(size) | MI_DMA_IF_ENABLE, 0);
            } else {
                MIi_DmaSetParameters(dmaNo, (u32)src, (u32)dest, MI_CNT_SET_COPY32(size) | MI_DMA_IF_ENABLE, MIi_DMA_MODE_WAIT);
            }
        } else {
            if (dmaEnable) {
                MIi_DmaSetParameters(dmaNo, (u32)src, (u32)dest, MI_CNT_COPY32(size), 0);
            } else {
                MIi_DmaSetParameters(dmaNo, (u32)src, (u32)dest, MI_CNT_SET_COPY32(size), MIi_DMA_MODE_WAIT);
            }
        }
    }
}

void MI_WaitDma(u32 dmaNo) {
    OSIntrMode enabled = OS_DisableInterrupts();
    vu32 *dmaCntp = (vu32 *)((u32)REG_DMA0CNT_ADDR + dmaNo * 12);

    while (*dmaCntp & REG_MI_DMA0CNT_E_MASK) {
    }

    if (dmaNo == MIi_DUMMY_DMA_NO) {
        vu32 *p = (vu32 *)((u32)REG_DMA0SAD_ADDR + dmaNo * 12);
        *p = (vu32)MIi_DUMMY_SRC;
        *(p + 1) = (vu32)MIi_DUMMY_DEST;
        *(p + 2) = (vu32)MIi_DUMMY_CNT;
    }

    (void)OS_RestoreInterrupts(enabled);
}

void MI_StopDma(u32 dmaNo) {
    OSIntrMode enabled = OS_DisableInterrupts();
    vu32 *dmaCntp = (vu32 *)((u32)REG_DMA0CNT_ADDR + dmaNo * 12);

    *dmaCntp &= ~(MI_DMA_TIMING_MASK | MI_DMA_CONTINUOUS_ON);
    *dmaCntp &= ~MI_DMA_ENABLE;

    {
        s32 dummy = dmaCntp[0];
    }
    {
        s32 dummy = dmaCntp[0];
    }

    if (dmaNo == MIi_DUMMY_DMA_NO) {
        vu32 *p = (vu32 *)((u32)REG_DMA0SAD_ADDR + dmaNo * 12);
        *p = (vu32)MIi_DUMMY_SRC;
        *(p + 1) = (vu32)MIi_DUMMY_DEST;
        *(p + 2) = (vu32)MIi_DUMMY_CNT;
    }

    (void)OS_RestoreInterrupts(enabled);
}

void MI_StopAllDma(void) {
    MI_StopDma(0);
    MI_StopDma(1);
    MI_StopDma(2);
    MI_StopDma(3);
}

void MIi_CheckAnotherAutoDMA(u32 dmaNo, u32 dmaType) {
    int n;
    u32 dmaCnt;
    u32 timing;

    for (n = 0; n < MI_DMA_MAX_NUM; n++) {
        if (n == dmaNo) {
            continue;
        }

        dmaCnt = *(REGType32v *)(REG_DMA0CNT_ADDR + n * 12);

        if ((dmaCnt & MI_DMA_ENABLE) == 0) {
            continue;
        }

        timing = dmaCnt & MI_DMA_TIMING_MASK;

        if (timing == dmaType
            || (timing == MI_DMA_TIMING_V_BLANK && dmaType == MI_DMA_TIMING_H_BLANK)
            || (timing == MI_DMA_TIMING_H_BLANK && dmaType == MI_DMA_TIMING_V_BLANK)) {
            continue;
        }

        if (timing == MI_DMA_TIMING_DISP
            || timing == MI_DMA_TIMING_DISP_MMEM
            || timing == MI_DMA_TIMING_CARD
            || timing == MI_DMA_TIMING_CARTRIDGE
            || timing == MI_DMA_TIMING_GXFIFO
            || timing == MI_DMA_TIMING_V_BLANK || timing == MI_DMA_TIMING_H_BLANK) {
            OS_Terminate();
        }
    }
}

static inline BOOL MIi_IsDmaRevised(void) {
    return (reg_SCFG_EXT & 1) ? TRUE : FALSE;
}

void MIi_CheckDma0SourceAddress(u32 dmaNo, u32 src, u32 size, u32 dir) {
    if (OS_IsRunOnTwl() && MIi_IsDmaRevised()) {
        return;
    }

    if (dmaNo == 0) {
        u32 addStart;
        u32 addEnd;

        addStart = src & 0xff000000;

        switch (dir) {
        case MI_DMA_SRC_INC:
            addEnd = src + size;
            break;
        case MI_DMA_SRC_DEC:
            addEnd = src - size;
            break;
        default:
            addEnd = src;
            break;
        }

        addEnd &= 0xff000000;

        if (addStart == 0x04000000 || addStart >= 0x08000000 ||
            addEnd == 0x04000000 || addEnd >= 0x08000000) {
            OS_Terminate();
        }
    }
}
