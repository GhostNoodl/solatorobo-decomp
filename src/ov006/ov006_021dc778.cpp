#include "ov006/Model.h"
#include "ov006/Racer.h"

extern "C" {

extern u8 Ov006Vt_021ec28c_vtbl[];

static inline void Ov006Marker_Dtor(Ov006Marker *self) {
    self->vtbl = Ov006Vt_021ec28c_vtbl;
    OV006_DELETE_MODEL(self->model);
    OV006_DELETE_MODEL(self->unk_30);
}

Ov006Marker *Ov006Vt_021ec28c_Dtor(Ov006Marker *self) {
    Ov006Marker_Dtor(self);
    return self;
}

Ov006Marker *Ov006Vt_021ec28c_DtorDelete(Ov006Marker *self) {
    Ov006Marker_Dtor(self);
    Heap_Free(self);
    return self;
}

}
