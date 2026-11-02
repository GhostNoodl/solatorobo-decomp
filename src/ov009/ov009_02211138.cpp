#include "ov009/ov009.h"

extern "C" {

extern char data_ov009_022179b4[];
extern void func_020627a0(u16 kind, u16 id);
extern void func_020627dc(s32 a);

void Ov009ActVt_02217aac_State20(Ov009ActVt_02217aac *self) {
    VecFx32 d;
    if (self->fsm->st == 0) {
        func_ov000_02190cb0(self->model, data_ov009_022179b4, 0x1000, 0);
        func_ov000_021915a0(self->model);
        self->unk_f0 = self->pos;
        self->pos.y += 0xa000;
        self->fsm->st++;
        self->fsm->timer = 0;
    }
    if (VEC_Distance(&self->pos, &self->unk_f0) <= 0xf6) {
        self->pos = self->unk_f0;
        func_020627a0(self->kind, self->id);
        func_020627dc(4);
        data_ov000_021ccd54->stageFlags = 1;
        func_ov000_02198360(self->fsm, 1, 0);
    }
    d.x = self->unk_f0.x - self->pos.x;
    d.y = self->unk_f0.y - self->pos.y;
    d.z = self->unk_f0.z - self->pos.z;
    VEC_Normalize(&d, &d);
    VEC_MultAdd(0xf6, &d, &self->pos, &self->pos);
}

}
