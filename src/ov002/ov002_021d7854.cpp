#include "ov002/ov002.h"

extern "C" {

void *func_ov002_021d7854(void *self) {
    func_ov002_021d74c0((u8 *)self + 0x4);
    return self;
}

void *func_ov002_021d786c(void *self) {
    func_ov002_021d74c0((u8 *)self + 0x4);
    func_0203de1c(self);
    return self;
}

void func_ov002_021d788c(void *self) {
    s32 v = FIELD(self, 0x30, s32);
    if (FIELD(self, 0x24, s32 *) != NULL) {
        *FIELD(self, 0x24, s32 *) = v;
    }
    if (FIELD(self, 0x28, s32 *) != NULL) {
        *FIELD(self, 0x28, s32 *) = v;
    }
    if (FIELD(self, 0x2c, s32 *) != NULL) {
        *FIELD(self, 0x2c, s32 *) = v;
    }
    FIELD(self, 0x30, s32) = S32_MOD(FIELD(self, 0x30, s32) + 0x1000, FIELD(self, 0x34, s32));
}

void *func_ov002_021d78d4(void *self) {
    func_02041558((u8 *)self + 0x74);
    func_02041278((u8 *)self + 0xfc);
    func_ov002_021d74c0((u8 *)self + 0x4);
    return self;
}

void *func_ov002_021d78fc(void *self) {
    func_02041558((u8 *)self + 0x74);
    func_02041278((u8 *)self + 0xfc);
    func_ov002_021d74c0((u8 *)self + 0x4);
    func_0203de1c(self);
    return self;
}

void func_ov002_021d792c(void *self) {
    s32 v = FIELD(self, 0x30, s32);
    if (FIELD(self, 0x24, s32 *) != NULL) {
        *FIELD(self, 0x24, s32 *) = v;
    }
    if (FIELD(self, 0x28, s32 *) != NULL) {
        *FIELD(self, 0x28, s32 *) = v;
    }
    if (FIELD(self, 0x2c, s32 *) != NULL) {
        *FIELD(self, 0x2c, s32 *) = v;
    }
    FIELD(self, 0x30, s32) = S32_MOD(FIELD(self, 0x30, s32) + 0x1000, FIELD(self, 0x34, s32));
    FIELD(self, 0x1d8, u32) = (u16)(FIELD(self, 0x1d8, u32) + 1);
}

}
