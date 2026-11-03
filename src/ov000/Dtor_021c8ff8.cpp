#include "ov000/VObj.h"

extern "C" {

extern u8 Ov000Vt_021cac0c_vtbl[];

VObj *Ov000Vt_021cca88_Dtor(VObj *self) {
    VOBJ_SET_VTABLE(self, Ov000Vt_021cac0c_vtbl);
    self->vfunc_18();
    return self;
}

}
