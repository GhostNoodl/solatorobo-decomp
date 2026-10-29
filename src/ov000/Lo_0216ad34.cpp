#include "ov000/LoCommon.h"

extern "C" {

void func_ov000_0215fe1c(void *self, s32 a, s32 b, ...);
u32 func_0204045c(void);

void func_ov000_0216ad34(void *self) {
    LO_FREE_M(self, 0xc);
    LFLD(s32, self, 0x0) = 0;
    LFLD(s32, self, 0x4) = 2;
    LFLD(s32, self, 0x8) = -1;
    LFLD(s32, self, 0xc) = 0;
    LFLD(s32, self, 0x10) = 0;
    LFLD(u16, self, 0x14) = 0;
    LFLD(s32, self, 0x18) = 0;
    LFLD(s32, self, 0x1c) = 0;
}

}
