#include "ov002/ov002.h"

extern "C" {

void func_ov002_021dfc44(void *self, u16 v) {
    FIELD(self, 0x18, u16) = v;
}

void func_ov002_021dfc4c(Obj021eff30 *self, void *dst) {
    FIELD(dst, 0x28, s32) = self->unk_1c;
    FIELD(dst, 0x2c, s32) = self->unk_20;
    func_ov002_021df1c4(self);
}

void func_ov002_021dfc68(Obj021eff30 *self, s32 arg) {
    FIELD(self, 0x4, s32) = arg;
    if (self->unk_10 != NULL) {
        self->unk_10->vfunc_10();
    }
    func_ov002_021e0280(self);
    FIELD(self->unk_0c, 0x1d4, u8) = self->unk_18 == 0xa;
    func_ov002_021d7988(self->unk_0c);
    self->unk_04 = NULL;
}

}
