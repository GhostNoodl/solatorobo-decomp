#include "ov000/LoCommon.h"

extern "C" {

void func_0201e5a0(void *dst, const void *src, s32 n);

static inline void LoInitEC44(void *self) {
    LFLD(s32, self, 0x0) = 0;
    LFLD(s32, self, 0x4) = 0;
    LFLD(s32, self, 0x8) = 0;
    LFLD(s32, self, 0xc) = 0;
    LFLD(s32, self, 0x1c) = 0;
    LFLD(s32, self, 0x18) = 0;
    LFLD(s32, self, 0x10) = 0x80000;
    LFLD(s32, self, 0x14) = 0xf000;
    LFLD(s32, self, 0x20) = 0;
    LFLD(s32, self, 0x24) = 0;
    LFLD(s32, self, 0x28) = 0;
}

void func_ov000_0215ec44(void *self) {
    LoInitEC44(self);
}

void func_ov000_0215ec80(void *self) {
    LO_FREE_M(self, 0x28);
    LoInitEC44(self);
}

}
