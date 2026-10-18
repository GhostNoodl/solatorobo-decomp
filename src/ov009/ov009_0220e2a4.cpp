#include "ov009/ov009.h"

extern "C" {

extern Ov009Actor *func_ov000_0219bf90(void);

void func_ov009_0220e2a4(Ov009Actor *self) {
    u8 k;
    if (!Ov009_GameIdle()) {
        return;
    }
    k = self->unk_40->unk_13;
    if (k == 1) {
        if (self->unk_b6 != 0) {
            self->unk_b6--;
        }
        self->unk_93_4 = 1;
        if (self->unk_b6 == 0) {
            Ov009Actor *a;
            s32 r;
            if (FLD(u8, self, 0x108) != 0) {
                if (func_02013068(&self->pos, &FLD(Ov009Vec, self, 0xf0)) < 0x5000) {
                    FLD(u8, self, 0x108) = 0;
                } else {
                    self->unk_b6 = 0x1e;
                    return;
                }
            }
            self->unk_90 = 0xffff;
            a = func_ov000_0219bf90();
            if (a != NULL) {
                self->unk_90 = a->id;
            }
            r = func_02040498(10);
            if (FLD(u8, self, 0x109) == 2 || r % 3 == 0) {
                self->unk_40->flags |= 0x4000;
                FLD(u8, self, 0x109) = 0;
            } else {
                self->unk_40->flags |= 0x8000;
                FLD(u8, self, 0x109)++;
            }
            self->unk_b6 = func_02040498(0x1e) + 0x96;
        }
    }
    if (k != 0x15 && k != 0x20 && self->pos.y < -0x1000) {
        self->pos.y = -0x1000;
        FLD(s32, self, 0x100) = -0x1000;
    }
}

}
