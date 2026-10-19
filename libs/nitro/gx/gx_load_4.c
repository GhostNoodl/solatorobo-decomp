#include "nitro/gx_vramcnt.h"

typedef struct {
    u32 unk_00[2];
    u32 texPlttLCDCBlk;
    GXVRamTexPltt texPltt;
} GXLoadTexState;

extern GXLoadTexState data_0208eb2c;
extern const u16 data_02075164[];  /* sTexPlttStartAddrTable */

void GX_BeginLoadTexPltt (void)
{
    data_0208eb2c.texPltt = GX_ResetBankForTexPltt();
    data_0208eb2c.texPlttLCDCBlk = data_02075164[data_0208eb2c.texPltt >> 4] << 12;
}
