#include "ov006/Model.h"

typedef struct ov006_Marker {
    void *vtbl;
    u16 state;
    u16 unk6;
    s16 timer;
    u8 unkA;
    u8 unkB;
    u8 unkC;
    int unk10;
    int unk14;
    int unk18;
    int unk1C;
    int unk20;
} ov006_Marker;

extern "C" {

extern void *data_ov006_021ec2ec;

ov006_Marker *func_ov006_021e1f28(ov006_Marker *self) {
    self->vtbl = &data_ov006_021ec2ec;
    self->state = 0;
    self->unk6 = 0;
    self->timer = 0;
    self->unkA = 1;
    self->unkB = 1;
    self->unkC = 1;
    self->unk10 = 0;
    self->unk14 = 0;
    self->unk18 = 0;
    self->unk1C = 0;
    return self;
}

void func_ov006_021e1f68(ov006_Marker *self) {
}

ov006_Marker *func_ov006_021e1f6c(ov006_Marker *self) {
    func_0203de1c(self);
    return self;
}

}
