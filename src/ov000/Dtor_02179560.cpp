#include "ov000/VObj.h"

extern "C" {

extern u8 data_ov000_021cac60[];
extern u8 data_ov000_021ccbe0[];
void func_0203de1c(void *ptr);
void func_ov000_021c3bb0(void *ptr);

VObj *func_ov000_02179560(VObj *self) {
    VOBJ_SET_VTABLE(self, data_ov000_021ccbe0);
    func_ov000_021c3bb0(self);
    VOBJ_SET_VTABLE(self, data_ov000_021cac60);
    self->vfunc_2c();
    func_0203de1c(self);
    return self;
}

}
