#include "ov000/LoCommon.h"
#include "ov000/ObjLayouts.h"

extern "C" {

extern u8 Lo021cacd8_vtbl[];
extern u8 UiObj_vtbl[];
extern u8 data_ov000_021c9b28[];
extern u8 data_ov000_021c9b2e[];
void Obj0215fdfc_SetRange(ObjBase021cac0c_021cb6f0 *self, s32 a, s32 b);


void func_ov000_02168e18(Lo021cb840 *self, s32 a, s32 b, VecFx32 *p) {
    self->unk_9c = p->x;
    self->unk_a0 = p->y;
    self->unk_a4 = p->z;
    if (a > b) {
        s32 q = a / b;
        self->unk_a8 = q;
        if (q >= 3) {
            a = b;
        } else {
            a = a % b;
        }
    } else {
        self->unk_a8 = 0;
    }
    Obj0215fdfc_SetRange(self, a, b);
    self->unk_0c = (self->unk_0c & ~2) | 0x10000;
}

}
