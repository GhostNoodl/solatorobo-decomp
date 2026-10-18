#include "ov000/VObj.h"

extern "C" {

extern u8 data_ov000_021cac60[];
extern u8 data_ov000_021caec8[];
extern u8 data_ov000_021cb0b8[];
extern u8 data_ov000_021cb1b0[];
void func_0203de1c(void *ptr);

VObj *func_ov000_02152b2c(VObj *self) {
    VOBJ_SET_VTABLE(self, data_ov000_021cb0b8);
    self->vfunc_2c();
    VOBJ_SET_VTABLE(self, data_ov000_021cb1b0);
    self->vfunc_2c();
    VOBJ_SET_VTABLE(self, data_ov000_021caec8);
    self->vfunc_2c();
    VOBJ_SET_VTABLE(self, data_ov000_021cac60);
    self->vfunc_2c();
    func_0203de1c(self);
    return self;
}

}
