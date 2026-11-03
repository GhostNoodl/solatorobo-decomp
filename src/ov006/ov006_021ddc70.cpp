#include "ov006/ov006.h"

typedef struct ov006_Unk021ddc70 {
    void *vtbl;
    u8 unk4;
    u8 unk5[7];
    int unkC;
    u8 unk10, unk11, unk12, unk13;
    int unk14[9];
} ov006_Unk021ddc70;

extern "C" {

extern u8 Ov006Vt_021ec2bc_vtbl[];

ov006_Unk021ddc70 *Ov006Vt_021ec2bc_Ctor(ov006_Unk021ddc70 *self) {
    self->vtbl = Ov006Vt_021ec2bc_vtbl;
    self->unk4 = 0;
    self->unkC = 0;
    self->unk10 = 0;
    self->unk11 = 0;
    self->unk12 = 0;
    self->unk13 = 0;
    self->unk14[0] = 0;
    self->unk14[1] = 0;
    self->unk14[2] = 0;
    self->unk14[3] = 0;
    self->unk14[4] = 0;
    self->unk14[5] = 0;
    self->unk14[6] = 0;
    self->unk14[7] = 0;
    self->unk14[8] = 0;
    return self;
}

}
