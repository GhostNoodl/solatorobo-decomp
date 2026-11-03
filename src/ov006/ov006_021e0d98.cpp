#include "ov006/Gauge.h"

extern "C" {

extern u8 Ov006Vt_021ec20c_vtbl[];

static inline void ov006_Gauge_dtor(ov006_Gauge *self) {
    self->vtbl = Ov006Vt_021ec20c_vtbl;
    OV006_DELETE_MODEL(self->model);
    OV006_DELETE_OBJECT(self->text);
}

ov006_Gauge *Ov006Vt_021ec20c_Dtor(ov006_Gauge *self) {
    ov006_Gauge_dtor(self);
    return self;
}

ov006_Gauge *Ov006Vt_021ec20c_DtorDelete(ov006_Gauge *self) {
    ov006_Gauge_dtor(self);
    Heap_Free(self);
    return self;
}

}
