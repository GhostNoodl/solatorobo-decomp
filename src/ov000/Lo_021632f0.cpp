#include "ov000/LoCommon.h"

extern "C" {

void func_ov000_02172f7c(void *self, void *arg);

static inline BOOL LoIsState5(void *o) {
    return LFLD(s32, o, 4) == 5 ? TRUE : FALSE;
}

void func_ov000_021632f0(void *self, s32 a, s32 b, s32 c, u8 d) {
    LO_FREE_V(self, 0x20);
    LO_FREE_V(self, 0x24);
    LFLD(s32, self, 0x14) = a;
    LFLD(s32, self, 0x8) = b;
    LFLD(s32, self, 0xc) = c;
    LFLD(u8, self, 0x10) = d;
    LFLD(s32, self, 0x28) = 0;
}

}
