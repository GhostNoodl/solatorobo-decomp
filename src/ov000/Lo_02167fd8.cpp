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

void func_ov000_02167fd8(VObj *self) {
    LO_FREE_M(self, 0x9c);
    self->vfunc_14();
}

void func_ov000_02168048(Lo021cb6f0 *self) {
    LO_FREE_M(self, 0x9c);
    self->unk_0c_3 = 0;
}

}
