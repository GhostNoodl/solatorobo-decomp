#include "ov000/LoCommon.h"
#include "Main/Sys/FieldState.h"
#include "ov000/ObjLayouts.h"
#include "Main/Gfx/GfxMgr.h"
#include "nitro/mi.h"
#include "ov000/MapCtx.h"

extern "C" {

Robo021ca458 *func_ov000_0219bf90(void);
BOOL PauseNode_IsDrawPaused(void *a, s32 b);
s32 func_02043d84(void *a);

void func_ov000_02165da0(Lo021cb6b0 *self) {
    Ctx0216607c *o = self->unk_30;
    LoAnimC *q;
    if (o == NULL || (q = o->anim) == NULL) {
        return;
    }
    if (q->state != 0) {
        return;
    }
    q->state = 1;
    o->anim->idx = o->anim->cnt - 1;
    o->anim->timer = 0;
}

BOOL func_ov000_02165df4(Lo021cb6b0 *self) {
    Ctx0216607c *o = self->unk_30;
    LoAnimC *q;
    if (o == NULL || (q = o->anim) == NULL) {
        return TRUE;
    }
    return q->state == 0xffff ? TRUE : FALSE;
}

}
