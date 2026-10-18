#include "ov009/ov009.h"

extern "C" {

extern void *data_ov009_02215d0c[];
void func_ov009_022046cc(Ov009Actor *self) {
    Ov009Vec p;
    Ov009Sub40 *st;
    if (self->unk_40->state == 0) {
        FLD(u8, self, 0xf0) = 0;
        self->unk_48->unk_30 = 0x40000000;
    }
    if (FLD(u8, self, 0xf2) == 0) {
        func_ov003_021d3524(self);
        return;
    }
    if (self->unk_40->state == 0) {
        func_ov000_02190cb0(self->unk_38, data_ov009_02215d0c[9], 0x1000, 0);
        func_ov000_021915a0(self->unk_38);
        self->unk_9c = 0;
        self->unk_a0 = 0;
        self->unk_a4 = 0;
        self->unk_a8 = 0;
        self->unk_40->timer = 0;
        self->unk_40->state++;
    }
    func_ov000_021987b8(self->unk_48, 1, 0, 0);
    p = self->pos;
    if (func_ov000_0219a2f4(&p, 0x3800, -0xa000) != -0x1000) {
        p.y += 0x2000;
    }
    {
        s32 y = self->pos.y;
        self->pos.y = y + Ov009_FxMul(p.y - y, 0x19a);
    }
    VEC_Distance(&self->pos, &p);
    if (self->unk_48->unk_50 & 0x20000000) {
        return;
    }
    st = self->unk_40;
    st->timer++;
    if (st->timer > 0x46) {
        self->unk_40->timer = 0x46;
        if (!(self->unk_48->unk_54 & 0x20000000)) {
            func_ov000_02198360(self->unk_40, 0x15, 0);
        }
    }
}

}
