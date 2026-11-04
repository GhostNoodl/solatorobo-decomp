#include "ov000/LoCommon.h"
#include "ov000/ObjLayouts.h"

extern "C" {

void Obj0215fdfc_SetRange(ObjBase021cac0c_021cb6f0 *self, s32 a, s32 b);
u32 Rand_GetGlobal(void);


void Lo021cb798_SetValue(Lo021cb798 *self, s32 a, s32 b) {
    if (a < (self->unk_64 >> 12)) {
        self->unk_ac = 9;
        self->unk_b0 = self->unk_5c;
        self->unk_aa = Rand_GetGlobal();
        self->unk_b4 = -1;
    }
    if (self->unk_60 == 0) {
        self->unk_5c = b << 12;
    }
    Obj0215fdfc_SetRange(self, a, b);
    self->unk_0c = (self->unk_0c & ~2) | 0x10000;
}

}
