#include "ov000/LoCommon.h"
#include "ov000/ObjLayouts.h"

extern "C" {

void func_ov000_0215fe1c(ObjBase021cac0c_021cb6f0 *self, s32 a, s32 b);
u32 func_0204045c(void);


void func_ov000_021697dc(Lo021cb798 *self, s32 a, s32 b) {
    if (a < (self->unk_64 >> 12)) {
        self->unk_ac = 9;
        self->unk_b0 = self->unk_5c;
        self->unk_aa = func_0204045c();
        self->unk_b4 = -1;
    }
    if (self->unk_60 == 0) {
        self->unk_5c = b << 12;
    }
    func_ov000_0215fe1c(self, a, b);
    self->unk_0c = (self->unk_0c & ~2) | 0x10000;
}

}
