#include "ov000/VObj.h"

extern "C" {

extern u8 data_ov000_021cac60[];
extern u8 data_ov000_021ccb54[];
extern u8 data_ov000_021ccbe0[];
void Heap_Free(void *ptr);
void LoBase021ccb54_021ccbe0_Release(void *ptr);
void Lo021ccb54_FreeLabels(void *ptr);

VObj *Ov000Vt_021ccb54_DtorDelete(VObj *self) {
    VOBJ_SET_VTABLE(self, data_ov000_021ccb54);
    Lo021ccb54_FreeLabels(self);
    VOBJ_SET_VTABLE(self, data_ov000_021ccbe0);
    LoBase021ccb54_021ccbe0_Release(self);
    VOBJ_SET_VTABLE(self, data_ov000_021cac60);
    self->vfunc_2c();
    Heap_Free(self);
    return self;
}

VObj *Ov000Vt_021ccb54_Dtor(VObj *self) {
    VOBJ_SET_VTABLE(self, data_ov000_021ccb54);
    Lo021ccb54_FreeLabels(self);
    VOBJ_SET_VTABLE(self, data_ov000_021ccbe0);
    LoBase021ccb54_021ccbe0_Release(self);
    VOBJ_SET_VTABLE(self, data_ov000_021cac60);
    self->vfunc_2c();
    return self;
}

VObj *Ov000Vt_021ccbe0_Dtor(VObj *self) {
    VOBJ_SET_VTABLE(self, data_ov000_021ccbe0);
    LoBase021ccb54_021ccbe0_Release(self);
    VOBJ_SET_VTABLE(self, data_ov000_021cac60);
    self->vfunc_2c();
    return self;
}

}
