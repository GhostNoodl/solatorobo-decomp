#include "ov009/ov009.h"

extern "C" {

extern u8 data_ov009_02216aaa[];
extern u8 data_ov009_02216abc[];
extern void Actor_MoveToPos(Ov003Actor *self, VecFx32 *v, s32 a);

void Ov009ActVt_022166a4_StateMove(Ov009ActVt_022166a4 *self) {
    VecFx32 v;
    Ov003Param *p;
    if (self->fsm->st == 0) {
        u8 *anim = data_ov009_02216aaa;
        if (self->unk_ee_0) {
            anim = data_ov009_02216abc;
        }
        Model0218fe1c_SetAnim(self->model, (char *)anim, 0x2ab, 0);
        Model0218fe1c_SetLoop(self->model);
        self->fsm->st++;
        self->velY = 0;
        self->friction = 0;
        self->gravity = 0;
    }
    p = self->unk_b0;
    self->speed = p->unk_00;
    v = self->unk_b8;
    Actor_MoveToPos(self, &v, p->unk_02);
    self->pos.y += FX_Mul(v.y + 0x1400 - self->pos.y, 0xcd);
    if (self->pos.y - v.y > 0x3000) {
        self->hit->unk_30 = 0x80000000;
    }
    Body_Update(self->hit, 1, 0, 0);
    self->hit->unk_30 = 0xc0000000;
}

extern char data_ov009_02216aa4[];
extern char data_ov009_02216ab6[];
extern Ov003Actor *ActorMgr_GetActor(void *mgr, u16 id);
extern void Actor_TurnToActor(Ov003Actor *self, Ov003Actor *other, s32 a);
static inline Ov003Actor *Ov009_FindActor(u16 id) {
    if (data_ov000_021ccd68 == NULL) {
        return NULL;
    }
    return ActorMgr_GetActor(data_ov000_021ccd68, id);
}

void Ov009ActVt_022166a4_StateAttack(Ov009ActVt_022166a4 *self) {
    ActorSub40 *st;
    s32 g;
    if (!Ov009_GameIdle()) {
        History_SetState(self->fsm, 1, 0);
        return;
    }
    st = self->fsm;
    switch (st->st) {
    case 0:
        Model0218fe1c_SetAnim(self->model, data_ov009_02216aa4, 0x200, 1);
        self->fsm->st++;
        self->speed = 0;
        self->velY = 0;
        self->friction = 0;
        self->gravity = 0;
        break;
    case 1:
        Actor_TurnToActor(self, Ov009_FindActor(self->target), self->unk_b0->unk_02);
        if (self->model->anim_state == 1) {
            self->fsm->st++;
        }
        break;
    case 2:
        g = self->hit->check.y;
        st->timer++;
        if (st->timer > 0x2d || self->pos.y < g + 0xc00) {
            Model0218fe1c_SetAnim(self->model, data_ov009_02216ab6, 0x200, 0);
            Model0218fe1c_SetLoop(self->model);
            self->fsm->timer = 0;
            self->fsm->st++;
            if (self->pos.y < g + 0xc00) {
                self->velY >>= 1;
            }
        }
        break;
    case 3:
        self->speed -= self->speed >> 3;
        self->velY -= self->velY >> 2;
        g = self->unk_1c;
        st->timer++;
        if (st->timer > g) {
            History_SetState(self->fsm, 1, 0);
            self->speed = 0;
            self->velY = 0;
            self->friction = 0;
            self->gravity = 0;
        }
        break;
    }
    Actor_Move(self, 0);
    Body_Update(self->hit, 0, 0, 0);
}

}
