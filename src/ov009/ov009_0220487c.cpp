#include "ov009/ov009.h"

extern "C" {

extern void *data_ov009_02215d0c[];
extern void func_ov000_0218ddd4(Ov009Actor *self, Ov009Vec *v, s32 a);

void func_ov009_0220487c(Ov009Actor *self) {
    Ov009Vec v;
    Ov009Vec p;
    if (FLD(u8, self, 0xf2) == 0) {
        func_ov003_021d3600(self);
        return;
    }
    if (self->unk_40->state == 0) {
        func_ov000_02190cb0(self->unk_38, data_ov009_02215d0c[9], 0x1000, 0);
        func_ov000_021915a0(self->unk_38);
        self->unk_9c = 0;
        self->unk_a0 = 0;
        self->unk_a4 = 0;
        self->unk_a8 = 0;
        self->unk_40->state++;
    }
    v = self->unk_b8;
    self->unk_9c = self->unk_b0->unk_00;
    func_ov000_0218ddd4(self, &v, self->unk_b0->unk_02);
    p = self->pos;
    if (func_ov000_0219a2f4(&p, 0x3800, -0xa000) != -0x1000) {
        if (p.y < v.y) {
            p.y = v.y;
        }
        p.y += 0x2000;
    }
    {
        s32 y = self->pos.y;
        self->pos.y = y + Ov009_FxMul(p.y - y, 0x19a);
    }
    VEC_Distance(&self->pos, &p);
    func_ov000_021987b8(self->unk_48, 1, 0, 0);
}

}
