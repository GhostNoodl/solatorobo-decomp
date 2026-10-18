#include "ov012/ov012.h"

extern "C" {
BOOL func_ov012_02201910(Ov012Actor *self, void *p, s32 a);
void func_ov012_02200200(Ov012Actor *self) {
    u32 f = FLD(u32, self, 0x100);
    if ((f & 0x200) || (f & 0x800) || (f & 0x400000)) {
        switch (self->unk_40->state) {
        case 0: {
            Ov012Sub48 *m;
            s32 x = 0x3000;
            if (FLD(u8, self, 0x106) == 1) {
                x = -0x3000;
            }
            Ov012_VecSet(&self->unk_b8, x, self->pos.y, 0);
            FLD(u8, self, 0x107) = 0;
            func_ov000_02190cb0(self->unk_38, data_ov012_0220a3c4[0], 0x111, 0);
            m = self->unk_48;
            m->unk_9a_0 = 0;
            m->unk_9a_3 = 0;
            func_0203f364(m);
            m = self->unk_48;
            m->unk_9a_2 = 0;
            m->unk_9a_5 = 0;
            self->unk_48->unk_30 = 0;
            self->unk_40->state++;
            break;
        }
        case 1:
            if (func_ov012_02201910(self, (u8 *)self + 0xf0, self->unk_b0->unk_00 * 2)) {
                if (FLD(u32, self, 0x100) & 0x200) {
                    FLD(u32, self, 0x100) ^= 0x200;
                }
                if (FLD(u32, self, 0x100) & 0x800) {
                    FLD(u32, self, 0x100) ^= 0x800;
                }
                if (FLD(u32, self, 0x100) & 0x400000) {
                    FLD(u32, self, 0x100) ^= 0x400000;
                }
                self->unk_40->state = 0;
            }
            break;
        }
    } else if (self->unk_40->state == 0) {
        func_ov000_02190cb0(self->unk_38, data_ov012_0220a3c4[1], 0x111, 0);
        func_ov000_021915a0(self->unk_38);
        self->unk_9c = 0;
        self->unk_a0 = 0;
        self->unk_a4 = 0;
        self->unk_a8 = 0;
        self->unk_40->state++;
    }
}
}
