#include "ov000/LoCommon.h"
#include "ov000/LoTicker.h"
#include "Main/Sys/FieldState.h"
#include "ov000/ObjLayouts.h"
#include "nnsys/g3d.h"
#include "Main/Gfx/GfxMgr.h"

extern "C" {

Robo021ca458 *func_ov000_0219bf90(void);
BOOL PauseNode_IsDrawPaused(void *a, s32 b);
s32 func_02043d84(void *a);

void func_ov000_0216be58(LoTicker *self) {
    if (PauseNode_IsDrawPaused(data_ov000_021ccd54->pause, 1)) {
        return;
    }
    func_ov000_0216c018(self);
    func_ov000_0216c310(self);
}

void func_ov000_0216be94(LoTicker *self) {
    if (PauseNode_IsDrawPaused(data_ov000_021ccd54->pause, 1)) {
        return;
    }
    func_ov000_0216c6fc(self);
}

// Material callback of the effect slots (installed by func_ov000_0216bf18): caps the polygon alpha at
// 30, sets the polygon ID from func_02043d84 and turns on translucent depth update.
void func_ov000_0216bec8(NNSG3dRS *rs) {
    NNSG3dMatAnmResult *mat = rs->pMatAnmResult;
    GfxSys *g = data_02097d48;
    u32 w = mat->prmPolygonAttr;
    u32 alpha = (w & 0x1f0000) >> 16;
    if (alpha > 0x1e) {
        alpha = 0x1e;
    }
    mat->prmPolygonAttr = (w & 0xc0e0f7ff) | (alpha << 16) | (func_02043d84(g->unk_8b0) << 24) | 0x800;
}

}
