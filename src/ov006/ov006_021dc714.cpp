#include "ov006/ov006.h"
#include "ov006/Racer.h"

extern "C" {

extern u8 data_ov006_021ec28c[];

Ov006Marker *Ov006Vt_021ec28c_Ctor(Ov006Marker *self) {
    self->vtbl = data_ov006_021ec28c;
    self->active = 0;
    self->smooth = 0;
    self->alt = 0;
    self->frame = 0;
    self->target.x = 0;
    self->target.y = 0;
    self->target.z = 0;
    self->cur.x = 0;
    self->cur.y = 0;
    self->cur.z = 0;
    self->ofs.x = 0;
    self->ofs.y = 0;
    self->ofs.z = -0x3000;
    self->model = NULL;
    self->unk_30 = NULL;
    return self;
}

}
