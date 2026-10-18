#include "ov002/ov002.h"

extern "C" {

void func_ov002_021e1cc8(void *self) {
    FIELD(self, 0x4, s32) = 0;
    FIELD(self, 0x8, s32) = 0;
    FIELD(self, 0xc, s32) = 0;
    FIELD(self, 0x10, s32) = 0;
    MIi_CpuClear32(0, (u8 *)self + 0x14, 0x14);
    FIELD(self, 0x28, s32) = 0;
    MI_CpuFill8((u8 *)self + 0x2c, 0, 10);
    MI_CpuFill8((u8 *)self + 0x36, 0, 10);
    FIELD(self, 0x40, u8) = 0;
    FIELD(self, 0x41, u8) = 0;
}

}
