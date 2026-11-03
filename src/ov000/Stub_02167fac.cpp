#include "ov000/ObjLayouts.h"

extern "C" {

void Obj0215fdfc_SetRange(ObjBase021cac0c_021cb6f0 *self, s32 a, s32 b);

void func_ov000_02167fac(Lo021cb6f0 *self, s32 a, s32 b) {
    Obj0215fdfc_SetRange(self, a, b);
    self->unk_0c = (self->unk_0c & ~2) | 0x10000;
}

void Lo021cb6f0_Init(Lo021cb6f0 *self) {
    self->unk_9c = NULL;
}

}
