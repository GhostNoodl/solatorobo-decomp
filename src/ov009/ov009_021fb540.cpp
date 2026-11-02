#include "ov009/ov009.h"

extern "C" {

extern u8 data_ov009_02216ab6[];

void Ov009ActVt_022166a4_Update(Ov009ActVt_022166a4 *self) {
    if (self->unk_1a != 0 || (self->kind != 0x540a && self->kind != 0x540b)) {
        self->unk_c8 = 0xf000;
        func_ov003_021d1e8c(self);
    }
    if (!self->unk_93_4) {
        self->unk_b8 = self->unk_f4;
    }
}

void func_ov009_021fb5ac(Ov009ActVt_022166a4 *self) {
    Ov009Vec d;
    Ov009Sub40 *st;
    switch (self->unk_40->state) {
    case 0:
        func_ov000_02190cb0(self->unk_38, data_ov009_02216ab6, 0x1000, 0);
        func_ov000_021915a0(self->unk_38);
        self->unk_40->state++;
    case 1:
        st = self->unk_40;
        st->timer++;
        if (st->timer > 0x1e) {
            Ov009Sub44 *s44 = self->unk_44;
            s44->unk_22_0 = 1;
            s44->unk_22_1 = 1;
            func_ov000_02198360(self->unk_40, 1, 0);
        }
        break;
    }
    d.x = self->unk_100.x - self->pos.x;
    d.y = self->unk_100.y - self->pos.y;
    d.z = self->unk_100.z - self->pos.z;
    VEC_MultAdd(0xcd, &d, &self->pos, &self->pos);
    func_ov000_021987b8(self->unk_48, 0, 0, 0);
}

extern s32 Rand_PlusMinus(s32 range);
extern void VEC_Add(const Ov009Vec *a, const Ov009Vec *b, Ov009Vec *out);
void func_ov009_021fb6b0(Ov009ActVt_022166a4 *self) {
    Ov009Vec d;
    Ov009Sub40 *st;
    switch (self->unk_40->state) {
    case 0:
        func_ov000_02190cb0(self->unk_38, data_ov009_02216ab6, 0x200, 0);
        func_ov000_021915a0(self->unk_38);
        self->unk_40->state++;
    case 1:
        st = self->unk_40;
        if (st->timer != 0) {
            st->timer--;
        }
        if (st->timer == 0) {
            self->unk_40->timer = 0x3c;
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
    d.x = Ov009_FxMul(d.x, 0x33);
    d.y = Ov009_FxMul(d.y, 0x33);
    d.z = Ov009_FxMul(d.z, 0x33);
    d.y *= 3;
    VEC_Add(&self->pos, &d, &self->pos);
    if (self->pos.y - self->unk_100.y > 0x3000) {
        self->unk_48->unk_30 = 0x80000000;
    }
    func_ov000_021987b8(self->unk_48, 1, 0, 0);
    self->unk_48->unk_30 = 0xc0000000;
}

}
