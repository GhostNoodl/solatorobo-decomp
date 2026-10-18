#include "ov002/ov002.h"

extern "C" {

void func_ov002_021e3480(void *self) {
    func_ov000_021c3d20(self);
    FIELD(self, 0x28, s32) = FIELD(self, 0x20, s32) * 15 + 0xc;
    FIELD(self, 0x6c, void *) = data_ov002_021ef038;
    FIELD(self, 0x70, s32) = 5;
    FIELD(self, 0xb4, s32) -= 0xc000;
    FIELD(self, 0xb0, s32) = FIELD(self, 0x24, s32) - (FIELD(self, 0xb4, s32) >> 12) + 0xc;
    FIELD(FIELD(self, 0x90, void *), 0x10, s32) = FIELD(self, 0xb0, s32) << 12;
    FIELD(self, 0xb8, s32) = 0x6000;
    FIELD(self, 0xc0, s32) = (FIELD(self, 0x28, s32) - 8) << 12;
    func_ov000_021c4ab8(self);
}

}
