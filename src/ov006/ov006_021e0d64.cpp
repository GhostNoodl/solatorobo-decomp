#include "ov006/ov006.h"
#include "ov006/Tasks.h"


extern "C" {

extern void *Ov006Vt_021ec20c_vtbl;

ov006_Gauge *Ov006Vt_021ec20c_Ctor(ov006_Gauge *self) {
    self->vtbl = &Ov006Vt_021ec20c_vtbl;
    self->unk4 = 0;
    self->unk8 = 0;
    self->unkC = 0;
    self->unk5 = 0;
    self->x = 0;
    self->y = 0;
    self->model = NULL;
    self->text = NULL;
    return self;
}

}
