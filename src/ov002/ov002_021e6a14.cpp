#include "ov002/ov002.h"

extern "C" {

void func_ov002_021e6a14(void *self) {
    FIELD(self, 4, s32) = 5;
    FIELD(self, 0x20, s32) = -0x29;
    MI_CpuFill8((u8 *)self + 0x4c, 0, 0x20);
    MI_CpuFill8((u8 *)self + 0x6c, 0, 0x20);
    func_ov002_021ebfd0((u8 *)self + 0x8c);
    FIELD(self, 0xb4, s32) = 0;
    FIELD(self, 0xb8, s32) = 0;
    FIELD(self, 0xbc, s16) = 0;
    FIELD(self, 0xc0, s32) = 0;
    MI_CpuFill8((u8 *)self + 0xc4, 0, 0x80);
    FIELD(self, 0x144, void *) = (u8 *)self + 0xc4;
    FIELD(self, 0x148, s32) = 0xff;
    FIELD(self, 0x150, s32) = 6;
    FIELD(self, 0x14c, s32) = 0;
    FIELD(self, 0x154, s32) = 2;
    FIELD(self, 0x158, s32) = 0;
    FIELD(self, 0x15c, s32) = 0;
}

BOOL func_ov002_021e6aac(void *self) {
    BOOL r = FALSE;
    switch (FIELD(self, 0x10, s32)) {
    case 0:
        if (FIELD(self, 0x4c, s8) != 0 && FIELD(self, 0x6c, s8) != 0) {
            func_020359fc((u8 *)self + 0x4c, (u8 *)self + 0x6c, 0, 0);
            FIELD(self, 0x14, s32) = 1;
            FIELD(self, 0x10, s32)++;
        } else {
            FIELD(self, 0x10, s32) = 2;
            r = TRUE;
            break;
        }
    case 1:
        if (func_02035bd4((u8 *)self + 0x4c, (u8 *)self + 0x6c, 0) == 0) {
            break;
        }
        FIELD(self, 0x10, s32)++;
    case 2:
        r = TRUE;
        break;
    }
    return r;
}

BOOL func_ov002_021e6b54(void *self) {
    s8 **r;
    if (FIELD(self, 0x14, s32) != 0) {
        void *t = func_02035fe8((u8 *)self + 0x4c, (u8 *)self + 0x6c);
        if (t == NULL) {
            FIELD(self, 8, s32) = 0;
        } else {
            func_ov002_021ec010((u8 *)self + 0x8c, t);
            FIELD(self, 8, s32) = 2;
        }
    }
    switch (FIELD(self, 8, s32)) {
    case 1:
        FIELD(self, 0x150, s32) = 5;
        FIELD(self, 0x154, s32) = 1;
        break;
    case 2:
        FIELD(self, 0x150, s32) = 6;
        FIELD(self, 0x154, s32) = 2;
        break;
    }
    FIELD(data_02097ce0, 4, s32) = FIELD(self, 0x150, s32);
    r = func_0203a4c0(data_02097ce0);
    FIELD(self, 0x158, s8 **) = r;
    FIELD(self, 0x15c, s8 *) = r[1];
    FIELD(data_ov002_021f0f98[1], 0x128, s32) = FIELD(self, 8, s32);
    return TRUE;
}

}
