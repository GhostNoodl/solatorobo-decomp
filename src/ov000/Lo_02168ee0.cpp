#include "ov000/LoCommon.h"
#include "ov000/ObjLayouts.h"

extern "C" {

typedef struct {
    s32 v[3];
} Lo3W;

extern u8 data_ov000_021cacd8[];
extern u8 data_ov000_021cac60[];
extern u8 data_ov000_021c9b28[];
extern u8 data_ov000_021c9b2e[];
void func_ov000_0215fdfc(ObjBase021cac0c_021cb6f0 *self, s32 a, const void *b);

void func_ov000_02168ee0(Lo021cb840 *self) {
    self->unk_28 = 0;
    self->unk_30 = 0xc000;
    self->unk_50 = 0x30;
    self->unk_54 = 4;
    self->unk_0c |= 0x240;
    self->unk_58 = 1;
    self->unk_74 = 0;
    self->unk_78 = 0;
    self->unk_7c = -0x2000;
    func_ov000_0215fdfc(self, 1, data_ov000_021c9b28);
    func_ov000_0215fdfc(self, 2, data_ov000_021c9b2e);
}

}
