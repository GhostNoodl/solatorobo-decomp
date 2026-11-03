#include "ov002/ov002.h"

extern "C" {

VObj *Ov002Vt_021f0044_DtorDelete(VObj *self) {
    *(VFunc **)self = Ov000Vt_021ccbe0_vtbl;
    LoBase021ccb54_021ccbe0_Release(self);
    *(VFunc **)self = UiObj_vtbl;
    self->vfunc_2c();
    Heap_Free(self);
    return self;
}

}
