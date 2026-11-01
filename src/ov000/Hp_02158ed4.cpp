#include "ov000/VObj.h"
#include "ov000/ObjLayouts.h"

#define LFLD(type, obj, off) (*(type *)((u8 *)(obj) + (off)))

extern "C" {

void func_ov000_02158ed4(Lo021cb3a8 *self, s32 dmg, s32 arg) {
    self->unk_b0 = self->unk_b1;
    if (self->unk_0c & 0x20000) {
        self->unk_b1 -= (s8)dmg;
    }
    if (self->unk_b1 < 0) {
        self->unk_b1 = 0;
    }
    self->vfunc_bc(self->unk_b1 - self->unk_b0, arg);
    self->unk_a2 = 8;
}
}
