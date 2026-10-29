#include "ov000/LoCommon.h"

extern "C" {

void func_ov000_0215fe1c(void *self, s32 a, s32 b, ...);
u32 func_0204045c(void);

void func_ov000_0216b490(void *self) {
    LO_FREE_M(self, 0x8);
    LFLD(s32, self, 0x0) = 0;
    LFLD(s32, self, 0x4) = 2;
    LFLD(s32, self, 0x8) = 0;
    LFLD(s32, self, 0x14) = 0;
    LFLD(s32, self, 0x18) = 0;
}

void func_ov000_0216b508(void *self, s32 a, s32 b) {
    LBIT(self, 0).b1 = a != 0 ? 1 : 0;
    LBIT(self, 0).b3 = b != 0 ? 1 : 0;
    LBIT(self, 0).b2 = 1;
}

}
