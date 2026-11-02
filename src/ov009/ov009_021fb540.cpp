#include "ov009/ov009.h"

extern "C" {

extern char data_ov009_02216ab6[];

void Ov009ActVt_022166a4_Update(Ov009ActVt_022166a4 *self) {
    if (self->unk_1a != 0 || (self->kind != 0x540a && self->kind != 0x540b)) {
        self->unk_c8 = 0xf000;
        Ov003Actor_Update(self);
    }
    if (!self->unk_93_4) {
        self->unk_b8 = self->unk_f4;
    }
}

void Ov009ActVt_022166a4_State20(Ov009ActVt_022166a4 *self) {
    VecFx32 d;
    ActorSub40 *st;
    switch (self->fsm->st) {
    case 0:
        func_ov000_02190cb0(self->model, data_ov009_02216ab6, 0x1000, 0);
        func_ov000_021915a0(self->model);
        self->fsm->st++;
    case 1:
        st = self->fsm;
        st->timer++;
        if (st->timer > 0x1e) {
            ActorSub44 *s44 = self->unk_44;
            s44->unk_22_0 = 1;
            s44->unk_22_1 = 1;
            func_ov000_02198360(self->fsm, 1, 0);
        }
        break;
    }
    d.x = self->unk_100.x - self->pos.x;
    d.y = self->unk_100.y - self->pos.y;
    d.z = self->unk_100.z - self->pos.z;
    VEC_MultAdd(0xcd, &d, &self->pos, &self->pos);
    func_ov000_021987b8(self->hit, 0, 0, 0);
}

void Ov009ActVt_022166a4_StateIdle(Ov009ActVt_022166a4 *self) {
    VecFx32 d;
    ActorSub40 *st;
    switch (self->fsm->st) {
    case 0:
        func_ov000_02190cb0(self->model, data_ov009_02216ab6, 0x200, 0);
        func_ov000_021915a0(self->model);
        self->fsm->st++;
    case 1:
        st = self->fsm;
        if (st->timer != 0) {
            st->timer--;
        }
        if (st->timer == 0) {
            self->fsm->timer = 0x3c;
            self->unk_100 = self->unk_b8;
            self->unk_100.x += Rand_PlusMinus(0x8cd);
            self->unk_100.z += Rand_PlusMinus(0x8cd);
            self->unk_100.y += Rand_PlusMinus(0x8cd);
            if (self->unk_1a != 0) {
                self->unk_100.y += 0x1c00;
            } else {
                self->unk_100.y += 0x1400;
            }
        }
        break;
    }
    d.x = self->unk_100.x - self->pos.x;
    d.y = self->unk_100.y - self->pos.y;
    d.z = self->unk_100.z - self->pos.z;
    d.x = FX_Mul(d.x, 0x33);
    d.y = FX_Mul(d.y, 0x33);
    d.z = FX_Mul(d.z, 0x33);
    d.y *= 3;
    VEC_Add(&self->pos, &d, &self->pos);
    if (self->pos.y - self->unk_100.y > 0x3000) {
        self->hit->unk_30 = 0x80000000;
    }
    func_ov000_021987b8(self->hit, 1, 0, 0);
    self->hit->unk_30 = 0xc0000000;
}

}
