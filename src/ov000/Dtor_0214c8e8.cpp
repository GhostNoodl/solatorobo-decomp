#include "ov000/VObj.h"

extern "C" {

extern u8 data_ov000_021cac60[];
extern u8 data_ov000_021cad50[];
void func_0203de1c(void *ptr);

VObj *func_ov000_0214c8e8(VObj *self) {
    VOBJ_SET_VTABLE(self, data_ov000_021cad50);
    self->vfunc_2c();
    VOBJ_SET_VTABLE(self, data_ov000_021cac60);
    self->vfunc_2c();
    func_0203de1c(self);
    return self;
}

}
