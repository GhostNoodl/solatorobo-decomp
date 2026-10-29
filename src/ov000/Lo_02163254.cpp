#include "ov000/LoCommon.h"
#include "nitro/std.h"

extern "C" {


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

void func_ov000_02163254(void *self) {
    LO_FREE_V(self, 0x20);
    LO_FREE_V(self, 0x24);
    LFLD(s32, self, 0x28) = 4;
}

}
