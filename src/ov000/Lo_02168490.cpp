#include "ov000/LoCommon.h"
#include "ov000/ObjLayouts.h"

extern "C" {

extern u8 data_ov000_021cacd8[];
extern u8 data_ov000_021cac60[];
extern u8 data_ov000_021c9b28[];
extern u8 data_ov000_021c9b2e[];
void func_ov000_0215fe1c(ObjBase021cac0c_021cb6f0 *self, s32 a, s32 b);


void func_ov000_02168490(Lo021cb894 *self, s32 a, s32 b, VecFx32 *p, VecFx32 *q) {
    self->unk_a0 = p->x;
    self->unk_a4 = p->y;
    self->unk_a8 = p->z;
    self->unk_ac = q->x;
    self->unk_b0 = q->y;
    self->unk_b4 = q->z;
    if (a > b) {
        a = b;
    }
    func_ov000_0215fe1c(self, a, b);
    self->unk_0c = (self->unk_0c & ~2) | 0x10000;
}

}
