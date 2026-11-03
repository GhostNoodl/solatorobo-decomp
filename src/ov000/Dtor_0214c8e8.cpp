#include "ov000/VObj.h"

extern "C" {

extern u8 UiObj_vtbl[];
extern u8 Lo021cad50_vtbl[];
void Heap_Free(void *ptr);

VObj *Lo021cad50_DtorDelete(VObj *self) {
    VOBJ_SET_VTABLE(self, Lo021cad50_vtbl);
    self->vfunc_2c();
    VOBJ_SET_VTABLE(self, UiObj_vtbl);
    self->vfunc_2c();
    Heap_Free(self);
    return self;
}

}
