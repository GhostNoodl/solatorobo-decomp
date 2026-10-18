#include "ov002/ov002.h"

extern "C" {

void func_ov002_021e4714(void *self) {
    *(VFunc **)self = data_ov002_021f00fc;
    FIELD(self, 0x4, s32) = 0;
    FIELD(self, 0x8, s32) = 0;
    FIELD(self, 0xc, s32) = 0;
    FIELD(self, 0x10, s32) = 0;
    FIELD(self, 0x14, s32) = 0;
}

void *func_ov002_021e473c(void *self) {
    *(VFunc **)self = data_ov002_021f00fc;
    func_ov002_021e4904_inline(self);
    return self;
}

void *func_ov002_021e47a4(void *self) {
    *(VFunc **)self = data_ov002_021f00fc;
    func_ov002_021e4904_inline(self);
    func_0203de1c(self);
    return self;
}

}
