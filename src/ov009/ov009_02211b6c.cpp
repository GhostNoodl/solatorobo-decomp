#include "ov009/ov009.h"

extern "C" {

extern char data_ov009_022179b4[];
extern Ov003Actor *func_ov000_0219bf90(void);
extern void Actor_TurnToPos(Ov003Actor *self, const VecFx32 *v, s32 a);
extern void func_ov000_021911c8(Model0218fe1c *m, s16 a);
extern void func_020627a0(u16 kind, u16 id);
extern void func_020627dc(s32 a);
static inline void Ov009_NextState(Ov009ActVt_02217aac *self) {
    self->fsm->st++;
    self->fsm->timer = 0;
}

void func_ov009_02211b6c(Ov009ActVt_02217aac *self) {
    VecFx32 d;
    ActorSub40 *st;
    switch (self->fsm->st) {
    case 0:
        func_ov000_02190cb0(self->model, data_ov009_022179b4, 0x1000, 0);
        func_ov000_021915a0(self->model);
        Ov009_NextState(self);
        break;
    case 1: {
        Ov003Actor *t = func_ov000_0219bf90();
        s32 tx = t->pos.x;
        s32 ty = t->pos.y;
        s32 tz = t->pos.z;
        d.x = self->pos.x - tx;
        d.y = self->pos.y - ty;
        d.z = self->pos.z - tz;
        VEC_Normalize(&d, &d);
        VEC_Add(&d, &self->pos, &d);
        Actor_TurnToPos(self, &d, 0x400);
        st = self->fsm;
        st->timer++;
        if (st->timer > 10) {
            func_ov000_021911c8(self->model, 0x1800);
            self->moveYaw = self->rot_y;
            self->velY = 0;
            self->gravity = 0;
            self->speed = 0x7b;
            self->friction = 0x1052;
            Ov009_NextState(self);
        }
        break;
    }
    case 2:
        Actor_Move(self, 0);
        st = self->fsm;
        st->timer++;
        if (st->timer > 0x3c) {
            Ov009_NextState(self);
        }
        break;
    case 3: {
        u8 h;
        u8 a;
        Actor_Move(self, 0);
        h = self->fsm->timer >> 1;
        if (h > 0x1d) {
            a = 2;
        } else {
            a = 0x1f - h;
        }
        func_ov003_021d6954(self, a);
        st = self->fsm;
        st->timer++;
        if (st->timer > 0x3c) {
            func_020627a0(self->kind, self->id);
            func_020627dc(4);
            data_ov000_021ccd54->stageFlags = 1;
            func_ov000_0218bed8(data_ov000_021ccd64, 0, self);
            self->vfunc_08();
        }
        break;
    }
    }
}

}
