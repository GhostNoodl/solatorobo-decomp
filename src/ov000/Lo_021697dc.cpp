#include "ov000/LoCommon.h"

extern "C" {

void func_ov000_0215fe1c(void *self, s32 a, s32 b, ...);
u32 func_0204045c(void);

void func_ov000_021697dc(void *self, s32 a, s32 b) {
    if (a < (LFLD(s32, self, 0x64) >> 12)) {
        LFLD(s32, self, 0xac) = 9;
        LFLD(s32, self, 0xb0) = LFLD(s32, self, 0x5c);
        LFLD(u16, self, 0xaa) = func_0204045c();
        LFLD(s32, self, 0xb4) = -1;
    }
    if (LFLD(s32, self, 0x60) == 0) {
        LFLD(s32, self, 0x5c) = b << 12;
    }
    func_ov000_0215fe1c(self, a, b);
    LFLD(u32, self, 0xc) = (LFLD(u32, self, 0xc) & ~2) | 0x10000;
}

}
