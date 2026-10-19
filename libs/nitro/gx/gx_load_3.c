#include "nitro/gx_vramcnt.h"

typedef struct {
    u16 blk1;
    u16 blk2;
    u16 szBlk1;
} GXTexStartAddr;

typedef struct {
    u32 unk_00;
    u32 texLCDCBlk1;
    u32 unk_08[3];
    GXVRamTex tex;
    u32 texLCDCBlk2;
    u32 szTexBlk1;
} GXLoadTexState;

extern GXLoadTexState data_0208eb2c;
extern const GXTexStartAddr data_02075174[];  /* sTexStartAddrTable */

void GX_BeginLoadTex (void)
{
    data_0208eb2c.tex = GX_ResetBankForTex();
    data_0208eb2c.texLCDCBlk1 = data_02075174[data_0208eb2c.tex].blk1 << 12;
    data_0208eb2c.texLCDCBlk2 = data_02075174[data_0208eb2c.tex].blk2 << 12;
    data_0208eb2c.szTexBlk1 = data_02075174[data_0208eb2c.tex].szBlk1 << 12;
}
