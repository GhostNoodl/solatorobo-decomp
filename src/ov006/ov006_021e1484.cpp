#include "ov006/ov006.h"
#include "ov006/Tasks.h"


extern "C" {

extern u8 data_ov006_021ec1fc[];

ov006_Obj13C *Ov006Vt_021ec1fc_Ctor(ov006_Obj13C *self) {
    self->vtbl = data_ov006_021ec1fc;
    self->unk4 = 0;
    self->unk8 = 0;
    self->unkC = 0;
    self->unk10 = 0;
    self->unk14 = 0;
    self->unk18 = 0;
    self->unk1C = 0x14;
    self->unk20 = 0;
    self->unk24 = 0;
    self->unk28 = 0;
    self->unk2C = 0;
    return self;
}

}
