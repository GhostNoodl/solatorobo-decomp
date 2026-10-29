#include "ov000/LoCommon.h"

extern "C" {

void func_ov000_0215fe1c(void *self, s32 a, s32 b);
u32 func_0204045c(void);

void func_ov000_0216926c(void *self) {
    LFLD(s32, self, 0xa0) = -1;
    LO_FREE_M(self, 0x9c);
    LBIT(self, 0xc).b3 = 0;
}

}
