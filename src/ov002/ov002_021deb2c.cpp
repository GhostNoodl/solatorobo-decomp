#include "ov002/ov002.h"

extern "C" {

void func_ov002_021deb2c(void *self, void *dst) {
    void *node = FIELD(self, 0x24, void *);
    u16 id;
    if (node != NULL) {
        id = FIELD(node, 0x38, u16);
    } else {
        id = 0xffff;
    }
    FIELD(dst, 0x28, s32) = FIELD(self, 0x2c, s32);
    FIELD(dst, 0x2c, s32) = FIELD(self, 0x30, s32);
    FIELD(dst, 0x30, u16) = id;
    func_ov002_021dddd0(self);
}

}
