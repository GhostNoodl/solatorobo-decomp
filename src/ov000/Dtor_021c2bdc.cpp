#include "ov000/VObj.h"

extern "C" {

extern u8 data_ov000_021cac0c[];
void func_0203de1c(void *ptr);

VObj *func_ov000_021c2bdc(VObj *self) {
    VOBJ_SET_VTABLE(self, data_ov000_021cac0c);
    self->vfunc_18();
    func_0203de1c(self);
    return self;
}

}
