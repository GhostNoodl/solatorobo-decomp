#include "ov000/VObj.h"
#include "nnsys/g3d.h"
#include "Main/Gfx/GfxMgr.h"
#include "ov000/Bss021ccd74.h"

extern "C" {

u8 Gfx3DState_NextPolyId(void *p);

void ActorMarker_MatCallback0b(NNSG3dRS *rs) {
    u32 flags;
    u32 v;
    NNSG3dMatAnmResult *sub = rs->pMatAnmResult;
    GfxSys *p;
    flags = sub->prmPolygonAttr;
    v = (flags & 0x1f0000) >> 16;
    p = gGfxSys;
    if ((u32)data_ov000_021ccd74.alpha < v) {
        v = data_ov000_021ccd74.alpha;
    }
    if (v >= 0x1e) {
        v = 0x1f;
    }
    sub->prmPolygonAttr = (flags & 0xc0e0ffbf) | 0xc0 | (v << 16) | (Gfx3DState_NextPolyId(p->unk_8b0) << 24);
}

}
