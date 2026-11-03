#include "ov000/LoCommon.h"

extern "C" {

typedef struct {
    s32 v[3];
} Lo3W;

extern u8 Lo021cacd8_vtbl[];
extern u8 UiObj_vtbl[];
extern u8 data_ov000_021c9b28[];
extern u8 data_ov000_021c9b2e[];

void *Lo021cacd8_DtorDelete(VObj *self) {
    VOBJ_SET_VTABLE(self, Lo021cacd8_vtbl);
    LO_FREE_M(self, 0x84);
    VOBJ_SET_VTABLE(self, UiObj_vtbl);
    self->vfunc_2c();
    Heap_Free(self);
    return self;
}

}
