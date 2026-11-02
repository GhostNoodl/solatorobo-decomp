#include "ov000/ObjLayouts.h"

extern "C" {

void func_ov000_02168ea4(Lo021cb840 *self) {
    self->unk_a8 = 0x0;
    self->unk_9c = 0x0;
    self->unk_a0 = 0x0;
    self->unk_a4 = 0x0;
}

s32 func_ov000_02168ebc(VObj *self) {
    return self->vfunc_14();
}

void func_ov000_02168ed0(Lo021cb840 *self) {
    self->unk_0c &= ~0x8;
}

}
