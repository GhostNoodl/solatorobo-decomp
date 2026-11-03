#include "ov000/LoCommon.h"
#include "ov000/ObjLayouts.h"
#include "ov000/Vec.h"
#include "ov000/SceneCmd.h"
#include "ov000/MessageQueue.h"

typedef struct {
    u8 unk_00[4];
    SceneCmd *scene; // gSceneCmd, reached through the 0x021ccd50 pool
} Data021ccd50b;

extern "C" {
extern Data021ccd50b data_ov000_021ccd50;
extern MessageQueue021cb980 *gMessageQueue;
Robo021ca458 *ActorMgr_FindPlayer(void);
BOOL MessageQueue_GetById(MessageQueue *self, s32 id);
BOOL func_ov000_021700c4(ListBuffer021cb940 *self);
void func_ov000_0218a358(FieldCam *self, const VecFx32 *pos, const Rot16 *rot, s32 dist, u8 clamp, s16 a6, s16 a7, u8 a8);

static inline BOOL IsBusy(void) {
    MessageQueue021cb980 *c = gMessageQueue;
    if (c == NULL) {
        return FALSE;
    }
    if (MessageQueue_GetById(c, 6)) {
        return TRUE;
    }
    if (c->unk_11c == NULL) {
        return FALSE;
    }
    return func_ov000_021700c4(c->unk_11c);
}

void func_ov000_02188ed0(SceneCmd *self) {
    FieldCam *s = &data_ov000_021ccd50.scene->cam;
    if (self->unk_d3) {
        s->unk_e8 = self->unk_d8;
        s->unk_da_1 = 1;
        s->unk_f8 = self->unk_e4.x;
        s->unk_da_4 = 1;
        s->unk_fa = self->unk_e4.y;
        s->unk_da_5 = 1;
        s->unk_f4 = self->unk_ec;
        s->unk_da_2 = 1;
        s->base.smooth = 0;
        s->base.wallClip = 0;
        return;
    }
    s->base.smooth = 1;
    if ((s32)self->event > 0) {
        Robo021ca458 *p = ActorMgr_FindPlayer();
        if (p != NULL && p->unk_b28_0 == 0 && p->unk_b2e < 2) {
            p->unk_b2e = 2;
        }
        if (self->event != 0xffff && --self->event == 0) {
            if (IsBusy()) {
                self->event = 1;
            }
        }
        func_ov000_0218a358(s, &self->unk_d8, &self->unk_e4, self->unk_ec, 0, self->unk_f0, self->unk_f0, 4);
    } else {
        self->event = 0;
    }
}
}
