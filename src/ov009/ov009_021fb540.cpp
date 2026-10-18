#include "ov009/ov009.h"

extern "C" {

extern u8 data_ov009_02216ab6[];

void func_ov009_021fb540(Ov009Actor *self) {
    if (self->unk_1a != 0 || (self->kind != 0x540a && self->kind != 0x540b)) {
        self->unk_c8 = 0xf000;
        func_ov003_021d1e8c(self);
    }
    if (!self->unk_93_4) {
        self->unk_b8 = FLD(Ov009Vec, self, 0xf4);
    }
}

void func_ov009_021fb5ac(Ov009Actor *self) {
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
    d.x = FLD(s32, self, 0x100) - self->pos.x;
    d.y = FLD(s32, self, 0x104) - self->pos.y;
    d.z = FLD(s32, self, 0x108) - self->pos.z;
    VEC_MultAdd(0xcd, &d, &self->pos, &self->pos);
    func_ov000_021987b8(self->unk_48, 0, 0, 0);
}

}
