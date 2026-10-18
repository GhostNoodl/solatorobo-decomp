#define LFLD(type, obj, off) (*(type *)((u8 *)(obj) + (off)))
#define LO_FX_MUL(a, b) ((s32)(((s64)(a) * (b) + 0x800) >> 12))
#include "types.h"

extern "C" {

void func_ov000_02155d8c(u8 *self) {
    s32 n = ++LFLD(s32, self, 0xcc);
    s32 v;
    if (n < 0x14) {
        LFLD(s32, self, 0xd0) += LO_FX_MUL(0x6000 - LFLD(s32, self, 0xd0), 0x19a);
    } else if (n < 0x32) {
        LFLD(s32, self, 0xd0) += LO_FX_MUL(0 - LFLD(s32, self, 0xd0), 0xcd);
    } else {
        LFLD(s32, self, 0xcc) = 0;
        LFLD(s32, self, 0xd0) = 0;
    }

}

}
