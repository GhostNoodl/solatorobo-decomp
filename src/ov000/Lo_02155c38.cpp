#include "types.h"
#define LFLD(type, obj, off) (*(type *)((u8 *)(obj) + (off)))

extern "C" {

static inline BOOL Cond1_02155c38(u8 *self) {
    u8 *p = LFLD(u8 *, self, 0x98);
    if (p == NULL) {
        return TRUE;
    }
    return LFLD(s16, p, 4) == 0;
}

static inline BOOL Cond2_02155c38(u8 *self) {
    u8 *p = LFLD(u8 *, self, 0x98);
    if (p == NULL) {
        return TRUE;
    }
    if (LFLD(s16, p, 4) == LFLD(s16, self, 0x9c) - LFLD(s32, self, 0x20) || LFLD(s16, self, 0x9c) < LFLD(s32, self, 0x20)) {
        return TRUE;
    }
    return FALSE;
}

void func_ov000_02155c38(u8 *self) {
    if (++LFLD(s32, self, 0xc4) < 0x18) {
        LFLD(s32, self, 0xc8) += (s32)(((s64)(0x3000 - LFLD(s32, self, 0xc8)) * (s64)0x148 + 0x800) >> 12);
    } else if (LFLD(s32, self, 0xc4) < 0x40) {
        LFLD(s32, self, 0xc8) += (s32)(((s64)(-LFLD(s32, self, 0xc8)) * (s64)0xcd + 0x800) >> 12);
    } else {
        LFLD(s32, self, 0xc4) = 0;
        LFLD(s32, self, 0xc8) = 0;
    }
    if (Cond1_02155c38(self)) {
        LFLD(s8, self, 0xc2) -= 4;
    } else {
        LFLD(s8, self, 0xc2) += 4;
    }
    if (LFLD(s8, self, 0xc2) < 0) {
        LFLD(s8, self, 0xc2) = 0;
    } else if (LFLD(s8, self, 0xc2) > 30) {
        LFLD(s8, self, 0xc2) = 30;
    }
    if (Cond2_02155c38(self)) {
        LFLD(s8, self, 0xc3) -= 4;
    } else {
        LFLD(s8, self, 0xc3) += 4;
    }
    if (LFLD(s8, self, 0xc3) < 0) {
        LFLD(s8, self, 0xc3) = 0;
    } else if (LFLD(s8, self, 0xc3) > 30) {
        LFLD(s8, self, 0xc3) = 30;
    }
}
}
