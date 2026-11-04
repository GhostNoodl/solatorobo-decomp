#include "ov000/LoCommon.h"
#include "ov000/ObjLayouts.h"

extern "C" {

extern u8 Lo021cacd8_vtbl[];
extern u8 UiObj_vtbl[];
extern u8 data_ov000_021c9b28[];
extern u8 data_ov000_021c9b2e[];
void Obj0215fdfc_SetRange(ObjBase021cac0c_021cb6f0 *self, s32 a, s32 b);


void Lo021cb894_SetValue(Lo021cb894 *self, s32 a, s32 b, VecFx32 *p, VecFx32 *q) {
    self->unk_a0 = p->x;
    self->unk_a4 = p->y;
    self->unk_a8 = p->z;
    self->unk_ac = q->x;
    self->unk_b0 = q->y;
    self->unk_b4 = q->z;
    if (a > b) {
        a = b;
    }
    Obj0215fdfc_SetRange(self, a, b);
    self->unk_0c = (self->unk_0c & ~2) | 0x10000;
}

}
