#include "ov002/ov002.h"

extern "C" {

void func_ov002_021dfc44(void *self, u16 v) {
    FIELD(self, 0x18, u16) = v;
}

void func_ov002_021dfc4c(void *self, void *dst) {
    FIELD(dst, 0x28, s32) = FIELD(self, 0x1c, s32);
    FIELD(dst, 0x2c, s32) = FIELD(self, 0x20, s32);
    func_ov002_021df1c4(self);
}

void func_ov002_021dfc68(void *self, s32 arg) {
    FIELD(self, 0x4, s32) = arg;
    if (FIELD(self, 0x10, VObject *) != NULL) {
        FIELD(self, 0x10, VObject *)->v0x10();
    }
    func_ov002_021e0280(self);
    FIELD(FIELD(self, 0xc, void *), 0x1d4, u8) = FIELD(self, 0x18, s32) == 0xa;
    func_ov002_021d7988(FIELD(self, 0xc, void *));
    FIELD(self, 0x4, s32) = 0;
}

}
