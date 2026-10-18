#include "ov000/VObj.h"

extern "C" {

extern u8 data_ov000_021cac0c[];

VObj *func_ov000_021c8ff8(VObj *self) {
    VOBJ_SET_VTABLE(self, data_ov000_021cac0c);
    self->vfunc_18();
    return self;
}

}
