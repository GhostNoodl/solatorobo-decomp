#include "ov000/LoCommon.h"
#include "ov000/ObjLayouts.h"

extern "C" {

extern u8 data_ov000_021cc678[];
BOOL func_ov000_02190cb0(void *a, void *b, s32 c, s32 d);
void func_ov000_021915a0(void *a);
BOOL func_ov000_02198360(ActorSub40 *st, s32 state, s32 x);
void func_ov000_021b1fac(Robo021ca458 *self, BOOL a, s32 b);
u16 FX_Atan2(s32 y, s32 x);

void func_ov000_021a5b50(Robo021ca458 *self) {
    switch (self->fsm->st) {
    case 0:
        func_ov000_02190cb0(self->model, data_ov000_021cc678, 0x200, 0);
        func_ov000_021915a0(self->model);
        self->friction = 0x800;
        self->unk_93_5 = 1;
        if (self->gravity == 0) {
            self->gravity = 0x52;
        }
        self->fsm->st++;
    case 1:
        if (self->unk_b36 == 0) {
            self->unk_93_5 = 0;
            func_ov000_02198360((ActorSub40 *)self->fsm, 1, 0);
            return;
        }
        if (self->hit->unk_50 & 0x20000000) {
            self->hit->unk_9a |= 0x20;
            self->speed = 0;
            self->friction = 0;
        } else {
            ActorSub40 *st = (ActorSub40 *)self->fsm;
            st->timer++;
            if (st->timer > 0x3c) {
                self->unk_93_5 = 0;
                self->unk_b36 = 0;
                func_ov000_02198360((ActorSub40 *)self->fsm, 4, 0);
            }
        }
        func_ov000_021b1fac(self, FALSE, 1);
        if (!LBIT(self, 0xb24).b1) {
            return;
        }
        if (!(self->hit->unk_54 & 0x400)) {
            return;
        }
        self->moveYaw = FX_Atan2(self->unk_af0.x - self->pos.x,
                                         self->unk_af0.z - self->pos.z);
        self->speed = 0x66;
        self->friction = 0;
        if (!LBIT(self, 0xb24).b17 || (self->hit->unk_50 & 0x40000000)) {
            self->velY = 0x200;
        }
        self->gravity = 0x52;
        LBIT(self, 0xb24).b17 = 1;
        break;
    }
}

}
