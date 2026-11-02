#include "ov000/VObj.h"
#include "ov000/ObjLayouts.h"
#include "ov000/UiObj.h"


extern "C" {

void func_ov000_02158ed4(Lo021cb3a8 *self, s32 dmg, s32 arg) {
    self->unk_b0 = self->cursor;
    if (self->flags & 0x20000) {
        self->cursor -= (s8)dmg;
    }
    if (self->cursor < 0) {
        self->cursor = 0;
    }
    self->vfunc_bc(self->cursor - self->unk_b0, arg);
    self->unk_a2 = 8;
}
}
