#include "ov000/LoCommon.h"
#include "Main/Sys/FieldState.h"
#include "ov000/ObjLayouts.h"
#include "Main/Gfx/GfxMgr.h"
#include "nitro/mi.h"

extern "C" {

Robo021ca458 *ActorMgr_FindPlayer(void);
BOOL PauseNode_IsDrawPaused(void *a, s32 b);
s32 func_02043d84(void *a);

void func_ov000_021681c4(Lo021cb6f0 *self) {
    Robo021ca458 *p = ActorMgr_FindPlayer();
    if (p == NULL) {
        return;
    }
    self->unk_80.x = p->pos.x;
    self->unk_80.y = p->pos.y;
    self->unk_80.z = p->pos.z;
    self->unk_80.y -= 0x800;
}

}
