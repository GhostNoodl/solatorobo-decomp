#include "ov002/ov002.h"

extern "C" {

void func_ov002_021dbd08(void *self, s32 a, s32 b) {
    FIELD(self, 0x10, s32) = a;
    FIELD(self, 0xc, s32) = b;
}

void *Ov002Vt_021eff10_Ctor(void *self) {
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

void func_ov002_021dbd60(Obj021eff50 *self) {
    if (self->unk_20 != NULL) {
        self->unk_20->vfunc_20();
    }
    if (self->unk_24 != NULL) {
        self->unk_24->vfunc_20();
    }
    if (self->unk_18 != NULL) {
        self->unk_18->vfunc_14(self);
    }
}

}
