#include "ov000/LoCommon.h"
#include "Main/Sys/FieldState.h"
#include "ov000/ObjLayouts.h"
#include "Main/Gfx/GfxMgr.h"
#include "nitro/mi.h"

extern "C" {

Robo021ca458 *ActorMgr_FindPlayer(void);
BOOL PauseNode_IsDrawPaused(void *a, s32 b);
s32 Gfx3DState_NextPolyIdB(void *a);

void Lo021cb894_UpdateTarget(Lo021cb894 *self) {
    Robo021ca458 *p = ActorMgr_FindPlayer();
    if (p == NULL) {
        return;
    }
    self->unk_80.x = p->pos.x;
    self->unk_80.y = p->pos.y;
    self->unk_80.z = p->pos.z;
    VEC_Add((VecFx32 *)((u8 *)self + 0x80), (VecFx32 *)((u8 *)self + 0xa0), (VecFx32 *)((u8 *)self + 0x80));
}

}
