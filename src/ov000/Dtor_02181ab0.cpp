#include "ov000/VObj.h"

extern "C" {

extern u8 data_0208b318[];
extern u8 data_0208bf54[];
void func_0203de1c(void *ptr);
void func_0205a6e8(void *ptr);

VObj *func_ov000_02181ab0(VObj *self) {
    VOBJ_SET_VTABLE(self, data_0208bf54);
    func_0205a6e8(self);
    VOBJ_SET_VTABLE(self, data_0208b318);
    self->vfunc_0c();
    func_0203de1c(self);
    return self;
}

}
