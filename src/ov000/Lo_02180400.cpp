#include "ov000/LoCommon.h"

extern "C" {

void func_ov000_02180400(VObj *self) {
    switch (LFLD(s32, self, 0x8)) {
    case 8:
        LFLD(u8, self, 0x5e) = 0;
        break;
    case 0xd: {
        bool ok;
        LFLD(VObj *, self, 0x44)->vfunc_1c();
        ok = true;
        ok = ok & (LFLD(VObj *, self, 0x3c)->vfunc_1c() == 0);
        ok = ok & (LFLD(VObj *, self, 0x40)->vfunc_1c() == 0);
        ok = ok & (LFLD(VObj *, self, 0x48)->vfunc_1c() == 0);
        if (ok) {
            self->vfunc_0c(0);
        }
        break;
    }
    }
    LFLD(s32, self, 0x50) += 0x8000;
    LFLD(s32, self, 0x54) += 0x8000;
    LFLD(s32, self, 0x50) = LFLD(s32, self, 0x50) < 0 ? 0x1000000 : LFLD(s32, self, 0x50);
    LFLD(s32, self, 0x54) = LFLD(s32, self, 0x54) < 0 ? 0x1000000 : LFLD(s32, self, 0x54);
    LFLD(s32, self, 0x50) %= 0x1000000;
    LFLD(s32, self, 0x54) %= 0x1000000;
}
}
