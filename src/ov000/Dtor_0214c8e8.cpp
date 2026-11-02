#include "ov000/VObj.h"

extern "C" {

extern u8 data_ov000_021cac60[];
extern u8 data_ov000_021cad50[];
void Heap_Free(void *ptr);

VObj *Lo021cad50_DtorDelete(VObj *self) {
    VOBJ_SET_VTABLE(self, data_ov000_021cad50);
    self->vfunc_2c();
    VOBJ_SET_VTABLE(self, data_ov000_021cac60);
    self->vfunc_2c();
    Heap_Free(self);
    return self;
}

}
