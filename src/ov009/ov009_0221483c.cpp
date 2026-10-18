#include "ov009/ov009.h"

extern "C" {

extern void *data_02097e4c;
extern Ov009V *func_02065f88(s32 id, const Ov009Vec *pos);
extern void func_02049f44(void *mgr, s32 id, const Ov009Vec *pos, s32 a);

void func_ov009_0221483c(Ov009Actor *self) {
    if (FLD(u16, self, 0xce) != 0) {
        FLD(u16, self, 0xce)--;
        if (FLD(u16, self, 0xce) <= FLD(u16, self, 0xd0)) {
            Ov009Sub38 *m = self->unk_38;
            FLD(u16, m, 0xb6) = 0x14bf;
            FLD(u16, m, 0xb8) = 0x73ff;
            FLD(u16, m, 0xba) = 9;
            FLD(u16, m, 0xbc) = 8;
            if (FLD(u16, self, 0xd0) >= 0x46) {
                FLD(u16, self, 0xd0) -= 0x14;
            } else if (FLD(u16, self, 0xd0) >= 0x28) {
                FLD(u16, self, 0xd0) -= 10;
            }
        }
        if (FLD(u16, self, 0xce) <= 0x14) {
            if (FLD(u16, self, 0xce) == 0x14) {
                Ov009V *e = func_02065f88(0x196, &self->pos);
                FLD(s32, e, 0x30) = 0x2a000;
                e->v0c(0xe66);
                self->unk_b8.y = FLD(s32, e, 0x24);
                func_02049f44(data_02097e4c, 0x44, &self->pos, 0);
            }
        }
        if (FLD(u16, self, 0xce) <= 0x10) {
            self->unk_a0 >>= 1;
            self->unk_a4 = 0xc7b;
        }
    } else {
        if (self->unk_40->unk_13 == 9) {
            FLD(u16, FLD(u8 *, self, 0x4c), 0x1c) = 0xffff;
            FLD(u16, self, 0xd2) = 0xffff;
        }
        func_ov000_02198360(self->unk_40, 0x15, 0);
    }
}

}
