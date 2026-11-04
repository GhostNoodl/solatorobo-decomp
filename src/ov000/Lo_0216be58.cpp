#include "ov000/LoCommon.h"
#include "ov000/LoTicker.h"
#include "Main/Sys/FieldState.h"
#include "ov000/ObjLayouts.h"
#include "nnsys/g3d.h"
#include "Main/Gfx/GfxMgr.h"

extern "C" {

Robo021ca458 *ActorMgr_FindPlayer(void);
BOOL PauseNode_IsDrawPaused(void *a, s32 b);
s32 Gfx3DState_NextPolyIdB(void *a);

void LoTicker_Update(LoTicker *self) {
    if (PauseNode_IsDrawPaused(gSceneCmd->pause, 1)) {
        return;
    }
    LoTicker_AddPending(self);
    LoTicker_UpdateItems(self);
}

void LoTicker_Draw(LoTicker *self) {
    if (PauseNode_IsDrawPaused(gSceneCmd->pause, 1)) {
        return;
    }
    LoTicker_DrawItems(self);
}

// Material callback of the effect slots (installed by LoTicker_RSInit): caps the polygon alpha at
// 30, sets the polygon ID from Gfx3DState_NextPolyIdB and turns on translucent depth update.
void LoTicker_MatCallback(NNSG3dRS *rs) {
    NNSG3dMatAnmResult *mat = rs->pMatAnmResult;
    GfxSys *g = gGfxSys;
    u32 w = mat->prmPolygonAttr;
    u32 alpha = (w & 0x1f0000) >> 16;
    if (alpha > 0x1e) {
        alpha = 0x1e;
    }
    mat->prmPolygonAttr = (w & 0xc0e0f7ff) | (alpha << 16) | (Gfx3DState_NextPolyIdB(g->unk_8b0) << 24) | 0x800;
}

}
