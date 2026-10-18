#include "ov002/ov002.h"

extern "C" {

void func_ov002_021d7b80(void *self) {
    FIELD(self, 0x4, s32) = 0;
    FIELD(self, 0xc, s32) = 0;
    FIELD(self, 0x8, s32) = -0x3000;
    FIELD(self, 0x10, s16) = 0;
    FIELD(self, 0x12, s16) = 0;
    FIELD(self, 0x14, s16) = 0;
    MTX_Identity33_((u8 *)self + 0x18);
    FIELD(self, 0x3c, s32) = 0x1000;
    FIELD(self, 0x40, s32) = 0x1000;
    FIELD(self, 0x44, s32) = 0x1000;
    FIELD(self, 0x48, s16) = 0;
    FIELD(self, 0x4a, u8) = 0;
    FIELD(self, 0x4b, u8) = 0;
    MI_CpuFill8((u8 *)self + 0x4c, 0, 8);
    FIELD(self, 0x54, s32) = 0;
    FIELD(self, 0x58, s32) = 0;
    FIELD(self, 0x5c, s32) = 0;
    FIELD(self, 0x60, s32) = 0;
    FIELD(self, 0x64, s32) = 0;
    FIELD(self, 0x68, s32) = 0;
    FIELD(self, 0x6c, u8) = 0;
    FIELD(self, 0x70, s32) = 0;
    FIELD(self, 0x74, s32) = 0;
}

void func_ov002_021d7c04(void *self) {
    u8 *info = func_0206ede8(FIELD(self, 0x48, u16));
    void *v;
    FIELD(self, 0x4a, u8) = info[0] == 0x80 ? 2 : 1;
    v = func_02070dcc(FIELD(self, 0x4b, u8) = info[1]);
    MI_CpuCopy8(v, (u8 *)self + 0x4c, 8);
    func_ov002_021e38f8((s32 *)((u8 *)self + 0x5c), v);
}

}
