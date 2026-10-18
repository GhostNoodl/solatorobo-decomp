#include "ov000/VObj.h"

#define LFLD(type, obj, off) (*(type *)((u8 *)(obj) + (off)))

extern "C" {

void func_ov000_02158ed4(VObj *self, s32 dmg, s32 arg) {
    LFLD(s8, self, 0xb0) = LFLD(s8, self, 0xb1);
    if (LFLD(u32, self, 0xc) & 0x20000) {
        LFLD(s8, self, 0xb1) -= (s8)dmg;
    }
    if (LFLD(s8, self, 0xb1) < 0) {
        LFLD(s8, self, 0xb1) = 0;
    }
    self->vfunc_bc(LFLD(s8, self, 0xb1) - LFLD(s8, self, 0xb0), arg);
    LFLD(s16, self, 0xa2) = 8;
}
}
