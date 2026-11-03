#include "ov006/Marker.h"

extern "C" {

extern void *data_ov006_021ec2ec;

ov006_Marker *Ov006Vt_021ec2ec_Ctor(ov006_Marker *self) {
    self->vtbl = &data_ov006_021ec2ec;
    self->state = 0;
    self->unk6 = 0;
    self->timer = 0;
    self->unkA = 1;
    self->unkB = 1;
    self->unkC = 1;
    self->unk10 = 0;
    self->unk14 = 0;
    self->pos.x = 0;
    self->pos.y = 0;
    return self;
}

void ov006_Marker_Dtor(ov006_Marker *self) {
}

ov006_Marker *ov006_Marker_DtorDelete(ov006_Marker *self) {
    Heap_Free(self);
    return self;
}

}
