#include "ov002/ov002.h"

extern "C" {

VObj *Ov002Vt_021f0044_DtorDelete(VObj *self) {
    *(VFunc **)self = data_ov000_021ccbe0;
    LoBase021ccb54_021ccbe0_Release(self);
    *(VFunc **)self = data_ov000_021cac60;
    self->vfunc_2c();
    Heap_Free(self);
    return self;
}

}
