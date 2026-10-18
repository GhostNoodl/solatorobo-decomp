#include "ov006/ov006.h"

typedef struct ov006_Unk021e1484 {
    void *vtbl;
    u8 unk4;
    int unk8;
    int unkC;
    int unk10;
    int unk14;
    u16 unk18;
    int unk1C;
    int unk20;
    int unk24;
    int unk28;
    int unk2C;
} ov006_Unk021e1484;

extern "C" {

extern u8 data_ov006_021ec1fc[];

ov006_Unk021e1484 *func_ov006_021e1484(ov006_Unk021e1484 *self) {
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
