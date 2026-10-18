#include "ov002/ov002.h"

extern "C" {

void func_ov002_021d7424(int se) {
    func_02049a48(data_02097e4c, se, -1, -1, -1);
}

void *func_ov002_021d744c(void *self) {
    *(VFunc **)self = data_ov002_021efe3c;
    FIELD(self, 0x4, s32) = 0;
    FIELD(self, 0x8, s32) = 0;
    FIELD(self, 0xc, s32) = 0;
    FIELD(self, 0x10, s32) = 0;
    FIELD(self, 0x14, s32) = 0;
    FIELD(self, 0x18, s32) = 0;
    FIELD(self, 0x1c, s32) = 0;
    FIELD(self, 0x20, s32) = 0;
    FIELD(self, 0x24, s32) = 0;
    FIELD(self, 0x28, s32) = 0;
    FIELD(self, 0x2c, s32) = 0;
    FIELD(self, 0x30, s32) = 0;
    FIELD(self, 0x34, s32) = 0;
    FIELD(self, 0x38, s32) = 0;
    FIELD(self, 0x3c, s32) = 0;
    FIELD(self, 0x40, s32) = 0x1000;
    FIELD(self, 0x44, s32) = 0x1000;
    FIELD(self, 0x48, s32) = 0x1000;
    MTX_Identity33_((u8 *)self + 0x4c);
    return self;
}

void *func_ov002_021d74c0(void *self) {
    *(VFunc **)self = data_ov002_021efe3c;
    {
        u32 saved;
        HEAP_PUSH(saved);
        if (FIELD(self, 0x18, void *) != NULL) {
            func_0203de1c(FIELD(self, 0x18, void *));
            FIELD(self, 0x18, void *) = NULL;
        }
        HEAP_POP(saved);
    }
    if (FIELD(self, 0x20, void *) != NULL) {
        func_0203df0c(FIELD(self, 0x20, void *));
        FIELD(self, 0x20, void *) = NULL;
    }
    if (FIELD(self, 0x24, void *) != NULL) {
        func_0203df0c(FIELD(self, 0x24, void *));
        FIELD(self, 0x24, void *) = NULL;
    }
    if (FIELD(self, 0x28, void *) != NULL) {
        func_0203df0c(FIELD(self, 0x28, void *));
        FIELD(self, 0x28, void *) = NULL;
    }
    func_0203f0b4(*FIELD(self, 0x10, void **));
    return self;
}

void *func_ov002_021d756c(void *self) {
    *(VFunc **)self = data_ov002_021efe3c;
    {
        u32 saved;
        HEAP_PUSH(saved);
        if (FIELD(self, 0x18, void *) != NULL) {
            func_0203de1c(FIELD(self, 0x18, void *));
            FIELD(self, 0x18, void *) = NULL;
        }
        HEAP_POP(saved);
    }
    if (FIELD(self, 0x20, void *) != NULL) {
        func_0203df0c(FIELD(self, 0x20, void *));
        FIELD(self, 0x20, void *) = NULL;
    }
    if (FIELD(self, 0x24, void *) != NULL) {
        func_0203df0c(FIELD(self, 0x24, void *));
        FIELD(self, 0x24, void *) = NULL;
    }
    if (FIELD(self, 0x28, void *) != NULL) {
        func_0203df0c(FIELD(self, 0x28, void *));
        FIELD(self, 0x28, void *) = NULL;
    }
    func_0203f0b4(*FIELD(self, 0x10, void **));
    func_0203de1c(self);
    return self;
}

}
