#include "ov000/LoCommon.h"

extern "C" {

typedef struct {
    s32 v[3];
} Lo3W;

extern u8 Lo021cacd8_vtbl[];
extern u8 UiObj_vtbl[];
extern u8 data_ov000_021c9b28[];
extern u8 data_ov000_021c9b2e[];

void Lo021cb7ec_Release(VObj *self) {
    LO_FREE_M(self, 0x9c);
    self->vfunc_14();
}

}
