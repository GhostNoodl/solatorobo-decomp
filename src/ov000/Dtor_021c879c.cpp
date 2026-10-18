#include "ov000/VObj.h"

extern "C" {

extern u8 data_ov000_021cac60[];
extern u8 data_ov000_021ccadc[];
void func_0203de1c(void *ptr);
void func_ov000_021c61a8(void *ptr);

VObj *func_ov000_021c879c(VObj *self) {
    VOBJ_SET_VTABLE(self, data_ov000_021ccadc);
    func_ov000_021c61a8(self);
    VOBJ_SET_VTABLE(self, data_ov000_021cac60);
    self->vfunc_2c();
    func_0203de1c(self);
    return self;
}

VObj *func_ov000_021c87e0(VObj *self) {
    VOBJ_SET_VTABLE(self, data_ov000_021ccadc);
    func_ov000_021c61a8(self);
    VOBJ_SET_VTABLE(self, data_ov000_021cac60);
    self->vfunc_2c();
    return self;
}

}
