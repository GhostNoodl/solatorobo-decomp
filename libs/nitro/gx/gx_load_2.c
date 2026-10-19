#include "nitro/gx_vramcnt.h"

typedef struct {
    u32 unk_00[6];
    GXVRamSubOBJExtPltt subObjExtPltt;
} GXLoadObjState;

extern GXLoadObjState data_0208eb10;

void GXS_BeginLoadOBJExtPltt (void)
{
    data_0208eb10.subObjExtPltt = GX_ResetBankForSubOBJExtPltt();
}
