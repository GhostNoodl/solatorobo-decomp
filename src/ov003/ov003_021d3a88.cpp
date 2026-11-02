#include "types.h"
#include "ov003/ActorApi.h"
#include "Main/Snd/SndMgr.h"
#include "Main/Effect/Effect.h"
#include "ov003/Actor.h"

extern "C" {

extern s32 Rand_PlusMinus(s32 max);
extern BOOL func_ov000_02198360(ActorSub40 *p, u8 a, BOOL b);

extern void HitSphere_Link(ActorSub48 *ctl);
extern void func_ov000_02199dc0(ActorSub4c *p, void *out);
extern void func_ov000_021987b8(ActorSub48 *ctl, s32 a, s32 b, s32 c);
extern s32 FX_Div(s32 a, s32 b);


void Ov003Actor_StateThrown(Ov003Actor *self) {
    ActorSub40 *w = self->fsm;
    switch (w->st) {
    case 0: {
        ActorSub48 *ctl;
        ActorSub44 *s;
        self->unk_b4 = 0;
        self->unk_b6 = 0;
        ctl = self->hit;
        ctl->unk_9a_0 = 1;
        ctl->unk_9a_3 = 1;
        HitSphere_Link(ctl);
        s = self->unk_44;
        s->unk_22_0 = 1;
        s->unk_22_1 = 1;
        self->fsm->st++;
        self->fsm->timer = 0;
        if (self->hp[0] == 0 || self->targetObj->unk_19 != 0) {
            func_02049f44(data_02097e4c, 0x32, &self->pos, 0);
        } else {
            func_02049f44(data_02097e4c, 0xb, &self->pos, 0);
        }
        func_ov000_02199dc0(self->targetObj, self);
        self->moveYaw = self->rot_y;
        if (self->targetObj->unk_1b == 0) {
            return;
        }
        if (self->unk_e4 != NULL) {
            EffectMgr_Kill(data_0214a420, self->unk_e4);
            self->unk_e4 = NULL;
        }
        if (self->unk_e4 == NULL) {
            EffectObj *fx = func_02065f88(0x321, &self->pos);
            s32 r;
            s32 t;
            self->unk_e4 = fx->id;
            r = self->radius;
            t = (r >> 2) + (r >> 3);
            fx->SetScaleXYZ(r + t, r + t, r + t);
            fx->alpha = FX_Div(0x10000, 0x1f000);
        }
        break;
    }
    case 1:
        w->timer++;
        if (w->timer > 2) {
            func_ov000_02198360(self->fsm, 4, 0);
        }
        Actor_Move(self, 0);
        func_ov000_021987b8(self->hit, 0, 0, 0);
        if (self->velY > 0 && (self->hit->unk_50 & 0x80000000)) {
            self->velY = -0xcd;
        }
        break;
    }
}

void Ov003Actor_StateBounce(Ov003Actor *self) {
    switch (self->fsm->st) {
    case 0:
        self->unk_b4 = 0;
        self->unk_b6 = 0;
        self->speed = Rand_PlusMinus(0x7b) + 0xf6;
        self->velY = 0x35c - 0x7b;
        self->friction = 0;
        self->gravity = 0x52;
        self->moveYaw = self->rot_y;
        self->targetObj->target = 0xffff;
        self->fsm->st++;
        break;
    case 1:
        if (self->hp[0] == 0) {
            func_ov000_02198360(self->fsm, 0x14, 0);
        } else {
            func_ov000_02198360(self->fsm, 4, 0);
        }
        break;
    }
}

}
