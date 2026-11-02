#include "ov000/VObj.h"

extern "C" {

extern u8 data_ov000_021cac60[];
extern u8 data_ov000_021ccb54[];
extern u8 data_ov000_021ccbe0[];
void Heap_Free(void *ptr);
void func_ov000_021c3bb0(void *ptr);
void func_ov000_021c5508(void *ptr);

VObj *Ov000Vt_021ccb54_DtorDelete(VObj *self) {
    VOBJ_SET_VTABLE(self, data_ov000_021ccb54);
    func_ov000_021c5508(self);
    VOBJ_SET_VTABLE(self, data_ov000_021ccbe0);
    func_ov000_021c3bb0(self);
    VOBJ_SET_VTABLE(self, data_ov000_021cac60);
    self->vfunc_2c();
    Heap_Free(self);
    return self;
}

VObj *Ov000Vt_021ccb54_Dtor(VObj *self) {
    VOBJ_SET_VTABLE(self, data_ov000_021ccb54);
    func_ov000_021c5508(self);
    VOBJ_SET_VTABLE(self, data_ov000_021ccbe0);
    func_ov000_021c3bb0(self);
    VOBJ_SET_VTABLE(self, data_ov000_021cac60);
    self->vfunc_2c();
    return self;
}

VObj *Ov000Vt_021ccbe0_Dtor(VObj *self) {
    VOBJ_SET_VTABLE(self, data_ov000_021ccbe0);
    func_ov000_021c3bb0(self);
    VOBJ_SET_VTABLE(self, data_ov000_021cac60);
    self->vfunc_2c();
    return self;
}

}
