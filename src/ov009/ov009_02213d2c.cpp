#include "ov009/ov009.h"
#include "Main/Gfx/SlidePanel.h"
#include "Main/Snd/SndMgr.h"

extern "C" {

extern char data_ov009_022179f1[];
extern char data_ov009_022179b4[];
extern Ov003Actor *ActorMgr_GetActor(void *mgr, u16 id);
extern void Model0218fe1c_SetAnimSpeed(Model0218fe1c *model, s16 a);
extern s16 *Model0218fe1c_SetAnimFrame(Model0218fe1c *m, s32 a);
extern void Actor_MoveToPos(Ov003Actor *self, VecFx32 *v, s32 a);

static inline Ov003Actor *Ov009_FindActor3(u16 id) {
    if (gActorMgr == NULL) {
        return NULL;
    }
    return ActorMgr_GetActor(gActorMgr, id);
}

void Ov009ActVt_02217cb0_StateAttack2(Ov009ActVt_02217cb0 *self) {
    Ov003Actor *t = Ov009_FindActor3(self->target);
    ActorSub40 *st;
    if (t == NULL) {
        return;
    }
    switch (self->fsm->st) {
    case 0:
        Model0218fe1c_SetAnim(self->model, data_ov009_022179f1, 0x2ab, 0);
        Model0218fe1c_SetAnimSpeed(self->model, 0x800);
        self->fsm->st = 10;
        self->fsm->timer = 3;
        break;
    case 10:
        if (self->model->anim_state != 1) {
            return;
        }
        st = self->fsm;
        if (st->timer != 0) {
            st->timer--;
        }
        if (st->timer == 0) {
            Model0218fe1c_SetAnimSpeed(self->model, 0x1000);
            self->speed = 0;
            self->velY = 0;
            self->friction = 0;
            self->gravity = 0;
            self->speed = self->unk_b0->unk_00 << 1;
            self->gravity = 0x52;
            self->fsm->st = 0x14;
            if (self->unk_1a == 0) {
                SndMgr_PlayAt(gSndMgr, 0xd02, &self->pos, 0);
                self->fsm->timer = 200;
            } else {
                SndMgr_PlayAt(gSndMgr, 0xe02, &self->pos, 0);
                self->fsm->timer = 0x96;
            }
        } else {
            Model0218fe1c_SetAnimFrame(self->model, 0);
        }
        break;
    case 0x14:
        self->unk_f0.x = t->pos.x;
        self->unk_f0.y = t->pos.y;
        self->unk_f0.z = t->pos.z;
        Actor_MoveToPos(self, &self->unk_f0, -0xcd);
        self->speed = self->unk_b0->unk_00 << 1;
        if (self->hit != NULL) {
            Body_Update(self->hit, 1, 0, 0);
        }
        st = self->fsm;
        if (st->timer != 0) {
            st->timer--;
        }
        if (st->timer == 0) {
            Model0218fe1c_SetAnim(self->model, data_ov009_022179b4, 0x1000, 0);
            Model0218fe1c_SetLoop(self->model);
            self->fsm->st = 0x15;
            self->fsm->timer = Rand_UpTo(0xf) + 0x32;
        }
        break;
    case 0x15:
        st = self->fsm;
        if (st->timer != 0) {
            st->timer--;
        }
        if (st->timer == 0) {
            History_SetState(self->fsm, 1, 0);
        }
        break;
    }
}

}
