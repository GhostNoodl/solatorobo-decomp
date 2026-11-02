#include "ov000/ObjLayouts.h"

extern "C" {

void func_ov000_0215fe1c(ObjBase021cac0c_021cb6f0 *self, s32 a, s32 b);

void func_ov000_02167fac(Lo021cb6f0 *self, s32 a, s32 b) {
    func_ov000_0215fe1c(self, a, b);
    self->unk_0c = (self->unk_0c & ~2) | 0x10000;
}

void func_ov000_02167fcc(Lo021cb6f0 *self) {
    self->unk_9c = NULL;
}

}
