#include "ov009/ov009.h"

extern "C" {

extern u8 data_ov009_022179b4[];
extern void func_020627a0(u16 kind, u16 id);
extern void func_020627dc(s32 a);
extern void VEC_Normalize(const Ov009Vec *in, Ov009Vec *out);

void func_ov009_02211138(Ov009Actor *self) {
    Ov009Vec d;
    if (self->unk_40->state == 0) {
        func_ov000_02190cb0(self->unk_38, data_ov009_022179b4, 0x1000, 0);
        func_ov000_021915a0(self->unk_38);
        FLD(Ov009Vec, self, 0xf0) = self->pos;
        self->pos.y += 0xa000;
        self->unk_40->state++;
        self->unk_40->timer = 0;
    }
    if (VEC_Distance(&self->pos, &FLD(Ov009Vec, self, 0xf0)) <= 0xf6) {
        self->pos = FLD(Ov009Vec, self, 0xf0);
        func_020627a0(self->kind, self->id);
        func_020627dc(4);
        FLD(u8, data_ov000_021ccd54, 0xac) = 1;
        func_ov000_02198360(self->unk_40, 1, 0);
    }
    d.x = FLD(Ov009Vec, self, 0xf0).x - self->pos.x;
    d.y = FLD(Ov009Vec, self, 0xf0).y - self->pos.y;
    d.z = FLD(Ov009Vec, self, 0xf0).z - self->pos.z;
    VEC_Normalize(&d, &d);
    VEC_MultAdd(0xf6, &d, &self->pos, &self->pos);
}

}
