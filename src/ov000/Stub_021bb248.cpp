#include "ov000/VObj.h"
#include "nnsys/g3d.h"
#include "Main/Gfx/GfxMgr.h"

extern "C" {

u8 Gfx3DState_NextPolyId(void *p);

void func_ov000_021bb248(NNSG3dRS *rs) {
    NNSG3dMatAnmResult *sub = rs->pMatAnmResult;
    GfxSys *p = data_02097d48;
    u32 flags = sub->prmPolygonAttr;
    u32 v = (flags & 0x1f0000) >> 16;
    if (v > 0x1e) {
        v = 0x1e;
    }
    sub->prmPolygonAttr = (flags & 0xc0e0f7ff) | (v << 16) | (Gfx3DState_NextPolyId(p->unk_8b0) << 24) | 0x800;
}

}
