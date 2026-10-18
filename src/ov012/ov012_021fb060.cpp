#include "ov012/ov012.h"

extern "C" {
void func_ov012_021fb060(Ov012Actor *self) {
    void *o;
    s32 r;
    if (!Ov012_GameIdle()) {
        return;
    }
    if (self->unk_40->unk_13 != 1) {
        return;
    }
    o = Ov012_FindRes(0x4000, 0x480f);
    if (FLD(u32, self, 0x10c) == 0) {
        r = func_02040498(9);
        if (((r >= 0 && r < 3) || func_ov000_021983b0(self->unk_40, 0x12, 2, 1) ||
             func_ov000_021983b0(self->unk_40, 0xe, 4, 1) || o != NULL) &&
            FLD(u8, self, 0x136) < 2) {
            u16 *hp = self->unk_50;
            s32 pct = (u16)(hp[0] * 100 / hp[1]);
            FLD(u16, self, 0xde) = 0;
            if (pct > 0x4b) {
                FLD(u32, self, 0x10c) |= 0x100000;
                self->unk_40->flags |= 0x8000;
            } else if (pct > 0x32) {
                FLD(u32, self, 0x10c) |= 0x200000;
                self->unk_40->flags |= 0x8000;
            } else if (pct > 0x19) {
                FLD(u32, self, 0x10c) |= 8;
                self->unk_40->flags |= 0x10000;
            } else {
                FLD(u32, self, 0x10c) |= 0x10;
                self->unk_40->flags |= 0x20000;
            }
            FLD(u8, self, 0x136)++;
        } else if ((r >= 3 && r < 10) || FLD(u8, self, 0x136) >= 2) {
            if (o == NULL) {
                self->unk_40->flags |= 0x4000;
                FLD(u32, self, 0x10c) |= 0x20;
            }
            FLD(u8, self, 0x136) = 0;
        }
    } else if (FLD(u32, self, 0x10c) & 1) {
        if (o == NULL) {
            FLD(u8, self, 0x110)++;
            self->unk_40->timer = 0;
            if (FLD(u32, self, 0x10c) & 0x20) {
                FLD(u32, self, 0x10c) ^= 0x20;
            }
            if (FLD(u32, self, 0x10c) & 1) {
                FLD(u32, self, 0x10c) ^= 1;
            }
        } else if (func_ov003_021d9edc(0x480f) <= 1) {
            if (FLD(u8, self, 0x110)++ >= 0x64) {
                if (FLD(u32, self, 0x10c) & 0x20) {
                    FLD(u32, self, 0x10c) ^= 0x20;
                }
                if (FLD(u32, self, 0x10c) & 1) {
                    FLD(u32, self, 0x10c) ^= 1;
                }
            }
        }
    }
}
}
