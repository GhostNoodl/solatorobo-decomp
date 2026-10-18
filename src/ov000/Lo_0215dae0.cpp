#define LFLD(type, obj, off) (*(type *)((u8 *)(obj) + (off)))
#define LO_FX_MUL(a, b) ((s32)(((s64)(a) * (b) + 0x800) >> 12))
#include "types.h"

extern "C" {

void func_ov000_0215dae0(u8 *self) {
    s32 st = LFLD(s32, self, 0x4);
    s32 d;
    s32 a;
    if (st == 0) {
        return;
    }
    if (st != 2) {
        return;
    }
    LFLD(s32, self, 0x30) = LFLD(s32, self, 0x34);
    LFLD(s32, self, 0x38) = 0x1000;
    d = LO_FX_MUL((LFLD(s32, self, 0x8c) - LFLD(s32, self, 0x88)) << 12, 0xf6);
    a = d < 0 ? -d : d;
    if (a < 0x1000) {
        LFLD(s32, self, 0x88) = LFLD(s32, self, 0x8c);
    } else {
        LFLD(s32, self, 0x88) += d >> 12;
    }
    if (((LFLD(u32, self, 0xc) << 30) >> 31) == 1) {
        LFLD(s32, self, 0x4) = 1;
    }
}

}
