#include "ov000/ObjLayouts.h"

extern "C" {

void Obj0215fdfc_SetRange(ObjBase021cac0c_021cb6f0 *self, s32 lo, s32 hi);

void func_ov000_0216a438(Lo021cb744 *self, s32 lo, s32 hi, u8 v) {
    if (self->unk_60 == 0) {
        self->unk_5c = hi << 12;
    }
    Obj0215fdfc_SetRange(self, lo, hi);
    self->unk_ac = v;
    self->unk_0c = (self->unk_0c & ~2) | 0x10000;
}

void Lo021cb744_Init(Lo021cb744 *self) {
    self->unk_9c = NULL;
    self->unk_a0 = NULL;
    self->unk_a4 = 0;
    self->unk_a6 = 0;
    self->unk_a8 = 0;
    self->unk_ac = 0;
}

}
