#include "nitro/gx.h"
#include "nitro/os.h"

#define GX_DISPMODE_OFF      0
#define GX_DISPMODE_GRAPHICS 1

void MI_WaitDma(u32 dmaNo);
void func_0201e504(void);

// sIsDispOn and GXi_DmaId (.data), sDispMode and GXi_VRamLockId (.bss) are
// shared with GX_Init, which stays in the gap.
typedef struct {
    u16 isDispOn;
    u32 dmaId;
} GXiDataBlock;
typedef struct {
    u16 dispMode;
    vu16 vramLockId;
} GXiBssBlock;
extern GXiDataBlock data_0208af54;
extern GXiBssBlock data_0208eb0c;
#define sIsDispOn  (data_0208af54.isDispOn)
#define GXi_DmaIdX (data_0208af54.dmaId)
#define sDispMode  (data_0208eb0c.dispMode)

void GX_SetVCountEqVal(s32 val) {
    reg_GX_DISPSTAT = (u16)((reg_GX_DISPSTAT & (REG_GX_DISPSTAT_VBLK_MASK |
                                                REG_GX_DISPSTAT_HBLK_MASK |
                                                REG_GX_DISPSTAT_LYC_MASK |
                                                REG_GX_DISPSTAT_VBI_MASK |
                                                REG_GX_DISPSTAT_HBI_MASK |
                                                REG_GX_DISPSTAT_VQI_MASK)) |
                            ((val & 0xff) << 8) | ((val & 0x100) >> 1));
}

s32 GX_VBlankIntr(BOOL enable) {
    s32 rval = (reg_GX_DISPSTAT & REG_GX_DISPSTAT_VBI_MASK);

    if (enable) {
        reg_GX_DISPSTAT |= REG_GX_DISPSTAT_VBI_MASK;
    } else {
        reg_GX_DISPSTAT &= ~REG_GX_DISPSTAT_VBI_MASK;
    }

    return rval;
}

BOOL GX_IsDispOn(void) {
    return sIsDispOn;
}

void GX_DispOff(void) {
    u32 tmp = reg_GX_DISPCNT;

    sIsDispOn = FALSE;
    sDispMode = (u16)((tmp & REG_GX_DISPCNT_MODE_MASK) >> REG_GX_DISPCNT_MODE_SHIFT);

    reg_GX_DISPCNT = tmp & ~REG_GX_DISPCNT_MODE_MASK;
    func_0201e504();
}

void GX_DispOn(void) {
    sIsDispOn = TRUE;

    if (sDispMode != (u16)GX_DISPMODE_OFF) {
        reg_GX_DISPCNT = ((reg_GX_DISPCNT & ~REG_GX_DISPCNT_MODE_MASK) |
                          (sDispMode << REG_GX_DISPCNT_MODE_SHIFT));
    } else {
        reg_GX_DISPCNT = ((reg_GX_DISPCNT | (GX_DISPMODE_GRAPHICS << REG_GX_DISPCNT_MODE_SHIFT)));
    }
}

void GX_SetGraphicsMode(int dispMode, int bgMode, int bg0_2d3d) {
    u32 cnt = reg_GX_DISPCNT;

    sDispMode = (u16)dispMode;
    if (!sIsDispOn) {
        dispMode = GX_DISPMODE_OFF;
    }

    cnt &= ~(REG_GX_DISPCNT_BGMODE_MASK | REG_GX_DISPCNT_BG02D3D_MASK |
             REG_GX_DISPCNT_MODE_MASK | REG_GX_DISPCNT_VRAM_MASK);

    reg_GX_DISPCNT = (u32)(cnt | (dispMode << REG_GX_DISPCNT_MODE_SHIFT) |
                           (bgMode << REG_GX_DISPCNT_BGMODE_SHIFT) |
                           (bg0_2d3d << REG_GX_DISPCNT_BG02D3D_SHIFT));

    if (sDispMode == GX_DISPMODE_OFF) {
        sIsDispOn = FALSE;
    }
}

void GXS_SetGraphicsMode(int bgMode) {
    reg_GXS_DB_DISPCNT = ((reg_GXS_DB_DISPCNT & ~REG_GXS_DB_DISPCNT_BGMODE_MASK) |
                          (bgMode << REG_GXS_DB_DISPCNT_BGMODE_SHIFT));
}

void GXx_SetMasterBrightness_(vu16 *reg, int brightness) {
    if (brightness == 0) {
        *reg = 0;
    } else if (brightness > 0) {
        *reg = (u16)((1 << REG_GX_MASTER_BRIGHT_E_MOD_SHIFT) | brightness);
    } else {
        *reg = (u16)((2 << REG_GX_MASTER_BRIGHT_E_MOD_SHIFT) | (-brightness));
    }
}

#pragma force_active on
u32 GX_SetDefaultDMA(u32 dma_no) {
    u32 previous = GXi_DmaIdX;
    OSIntrMode enabled;

    if (previous != GX_DMA_NOT_USE) {
        MI_WaitDma(previous);
    }

    enabled = OS_DisableInterrupts();
    GXi_DmaIdX = dma_no;
    (void)OS_RestoreInterrupts(enabled);

    {
        u32 r = GX_DMA_NOT_USE;
        if (previous <= 3) {
            r = previous;
        }
        return r;
    }
}
#pragma force_active reset
