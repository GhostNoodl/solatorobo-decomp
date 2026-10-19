#include "nitro/gx_vramcnt.h"

/* Static state of gx_load.c (.bss, still owned by the surrounding gap). */
typedef struct {
    u32 unk_00;
    u32 objExtPlttLCDCBlk;
    GXVRamOBJExtPltt objExtPltt;
} GXLoadObjState;

extern GXLoadObjState data_0208eb10;

void GX_BeginLoadOBJExtPltt (void)
{
    data_0208eb10.objExtPltt = GX_ResetBankForOBJExtPltt();

    switch (data_0208eb10.objExtPltt) {
    case GX_VRAM_OBJEXTPLTT_NONE:
        break;
    case GX_VRAM_OBJEXTPLTT_0_F:
        data_0208eb10.objExtPlttLCDCBlk = HW_LCDC_VRAM_F;
        break;
    case GX_VRAM_OBJEXTPLTT_0_G:
        data_0208eb10.objExtPlttLCDCBlk = HW_LCDC_VRAM_G;
        break;
    }
}
