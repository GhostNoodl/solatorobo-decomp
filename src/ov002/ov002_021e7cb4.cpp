#include "ov002/ov002.h"

extern "C" {

void MTX_OrthoW(s32 a, s32 b, s32 c, s32 d, s32 e, s32 f, s32 g, void *out);

void func_ov002_021e7cb4(void *self) {
    FIELD(self, 0x4, s32) = 0;
    FIELD(self, 0x8, s32) = 0;
    FIELD(self, 0xc, s32) = 1;
    FIELD(self, 0x10, u8) = 1;
    FIELD(self, 0x14, s32) = -1;
    FIELD(self, 0x18, s16) = 0;
    FIELD(self, 0x1a, u8) = 1;
    FIELD(self, 0x1c, s32) = -1;
    FIELD(self, 0x20, s32) = 0;
    MI_CpuFill8((u8 *)self + 0x24, 0, 0x20);
    FIELD(self, 0x44, s32) = 0;
    MI_CpuFill8((u8 *)self + 0x48, 0, 0x20);
    FIELD(self, 0x68, s32) = 0;
    FIELD(self, 0xd0, s32) = 0;
    FIELD(self, 0xd4, s32) = -1;
    FIELD(self, 0xd8, s32) = 0x1000;
    FIELD(self, 0xdc, s32) = 0;
    FIELD(self, 0xe0, s32) = 0;
    MTX_OrthoW(0, 0xc0000, 0, 0x100000, 0, 0x20000, 0x400000, (u8 *)self + 0xe4);
    FIELD(self, 0x124, s32) = 0;
    FIELD(self, 0x128, s32) = 0;
    FIELD(self, 0x130, s32) = 0;
    FIELD(self, 0x134, s32) = 0;
    FIELD(self, 0x13c, s32) = 0;
    FIELD(self, 0x140, s32) = 0;
    FIELD(self, 0x144, s32) = 0;
    FIELD(self, 0x148, u8) = 0;
    FIELD(self, 0x12c, s32) = 0xff;
    FIELD(self, 0x138, s16) = 0;
    MI_CpuFill8((u8 *)self + 0x14c, 0, 0x180);
}

void func_ov002_021e8c0c(void *self);

void func_0204ab54(void *p);

void GXx_SetMasterBrightness_(u32 reg, int v);

extern void *data_ov002_021f0104[];

void func_ov002_021e7dac(void *self) {
    func_ov002_021e8c0c(self);
    if (FIELD(self, 0x44, void *) != NULL) {
        if (FIELD(self, 0x20, void *) != NULL) {
            func_02035acc((u8 *)self + 0x24, (u8 *)self + 0x48, 0);
        } else {
            func_02036838(data_02097cdc, (u8 *)self + 0x48, 0, 0);
        }
    }
    func_02035acc(data_ov002_021f0104[1], data_ov002_021f0104[2], 2);
    func_0204ab54(data_02097e48);
    if (FIELD(self, 0x148, u8)) {
        u8 *g = data_02097d48;
        ((void (*)(void *, void *, u32))MIi_CpuCopy32)((u8 *)self + 0x14c, g + 0x8b0, 0x180);
        func_02043b20(g + 0x8b0);
        FIELD(self, 0x148, u8) = 0;
    }
    FIELD(data_02097d48, 0x4, s32) = 1;
    FIELD(data_0214a420, 0x10, u8) = 0;
    FIELD(data_0214a420, 0x34, u8) = 0;
    GXx_SetMasterBrightness_(0x400006c, 0);
    GXx_SetMasterBrightness_(0x400106c, 0);
}

}
