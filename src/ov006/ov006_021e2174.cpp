#include "ov006/SlotManager.h"
#include "ov006/Marker.h"

extern "C" {

extern u8 Ov006Vt_021ec2cc_vtbl[];

ov006_MarkerSet *Ov006Vt_021ec2cc_Ctor(ov006_MarkerSet *self) {
    self->vtbl = Ov006Vt_021ec2cc_vtbl;
    __cxa_vec_ctor(self->markers, 4, sizeof(ov006_Marker), (void *)Ov006Vt_021ec2ec_Ctor, (void *)ov006_Marker_Dtor);
    self->unk4 = 0;
    self->unk8 = 0;
    self->unkC = 0;
    return self;
}

}
