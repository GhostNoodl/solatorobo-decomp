#include "ov000/LoCommon.h"
#include "ov000/ObjLayouts.h"

extern "C" {

typedef struct {
    s32 v[3];
} Lo3W;

extern u8 Lo021cacd8_vtbl[];
extern u8 UiObj_vtbl[];
extern u8 data_ov000_021c9b28[];
extern u8 data_ov000_021c9b2e[];
void Obj0215fdfc_SetEntry(ObjBase021cac0c_021cb6f0 *self, s32 a, const void *b);

void Lo021cb840_Setup(Lo021cb840 *self) {
    self->unk_28 = 0;
    self->unk_30 = 0xc000;
    self->unk_50 = 0x30;
    self->unk_54 = 4;
    self->unk_0c |= 0x240;
    self->unk_58 = 1;
    self->unk_74 = 0;
    self->unk_78 = 0;
    self->unk_7c = -0x2000;
    Obj0215fdfc_SetEntry(self, 1, data_ov000_021c9b28);
    Obj0215fdfc_SetEntry(self, 2, data_ov000_021c9b2e);
}

}
