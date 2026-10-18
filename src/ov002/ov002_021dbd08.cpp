#include "ov002/ov002.h"

extern "C" {

void func_ov002_021dbd08(void *self, s32 a, s32 b) {
    FIELD(self, 0x10, s32) = a;
    FIELD(self, 0xc, s32) = b;
}

void *func_ov002_021dbd14(void *self) {
    *(VFunc **)self = data_ov002_021eff10;
    FIELD(self, 0x4, s32) = 0;
    FIELD(self, 0x8, s32) = 0;
    FIELD(self, 0xc, s32) = 0;
    FIELD(self, 0x10, s32) = 0;
    FIELD(self, 0x14, s32) = 0;
    FIELD(self, 0x18, s32) = 0;
    FIELD(self, 0x1c, s32) = -1;
    FIELD(self, 0x20, u8) = 0;
    FIELD(self, 0x24, s32) = 0;
    FIELD(self, 0x28, s32) = 0;
    FIELD(self, 0x2c, s32) = 0;
    FIELD(self, 0x30, s32) = 0;
    FIELD(self, 0x34, u8) = 0;
    return self;
}

void func_ov002_021dbd60(void *self) {
    if (FIELD(self, 0x20, VObject *) != NULL) {
        FIELD(self, 0x20, VObject *)->v0x20();
    }
    if (FIELD(self, 0x24, VObject *) != NULL) {
        FIELD(self, 0x24, VObject *)->v0x20();
    }
    if (FIELD(self, 0x18, VObject *) != NULL) {
        FIELD(self, 0x18, VObject *)->v0x14(self);
    }
}

}
