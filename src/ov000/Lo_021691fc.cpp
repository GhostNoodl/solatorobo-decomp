#include "ov000/LoCommon.h"

extern "C" {

typedef struct {
    s32 v[3];
} Lo3W;

extern u8 data_ov000_021cacd8[];
extern u8 data_ov000_021cac60[];
extern u8 data_ov000_021c9b28[];
extern u8 data_ov000_021c9b2e[];

void func_ov000_021691fc(VObj *self) {
    LO_FREE_M(self, 0x9c);
    self->vfunc_14();
}

}
