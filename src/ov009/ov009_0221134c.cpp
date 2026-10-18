#include "ov009/ov009.h"

extern "C" {

extern u8 data_ov009_022179b4[];
extern void func_ov000_0218ddd4(Ov009Actor *self, const Ov009Vec *v, s32 a);

void func_ov009_0221134c(Ov009Actor *self) {
    Ov009Vec v;
    if (self->unk_40->state == 0) {
        func_ov000_02190cb0(self->unk_38, data_ov009_022179b4, 0x155, 0);
        func_ov000_021915a0(self->unk_38);
        self->unk_9c = 0;
        self->unk_a0 = 0;
        self->unk_a4 = 0;
        self->unk_a8 = 0;
        self->unk_40->state++;
    }
    self->unk_9c = self->unk_b0->unk_00;
    if (FLD(u8, self, 0xff) != 0) {
        self->unk_9c = self->unk_9c + (self->unk_9c >> 3);
    }
    v = self->unk_b8;
    if (self->pos.y > v.y) {
        self->unk_a0 = -self->unk_b0->unk_00 >> 2;
    } else if (self->pos.y < v.y) {
        self->unk_a0 = self->unk_b0->unk_00 >> 2;
    } else {
        self->unk_a0 = 0;
    }
    func_ov000_0218ddd4(self, &v, self->unk_b0->unk_02);
    if ((self->unk_a0 > 0 && self->pos.y > v.y) || (self->unk_a0 < 0 && self->pos.y < v.y)) {
        self->pos.y = v.y;
    }
}

}
