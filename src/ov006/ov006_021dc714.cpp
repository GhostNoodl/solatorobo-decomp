#include "ov006/ov006.h"

typedef struct ov006_Unk021dc714 {
    void *vtbl;
    u8 b0 : 1;
    u8 b1 : 1;
    u8 b2 : 1;
    u8 b3 : 5;
    u8 unk5;
    int unk8[8];
    int unk28;
    int unk2C;
    int unk30;
} ov006_Unk021dc714;

extern "C" {

extern u8 data_ov006_021ec28c[];

ov006_Unk021dc714 *func_ov006_021dc714(ov006_Unk021dc714 *self) {
    self->vtbl = data_ov006_021ec28c;
    self->b0 = 0;
    self->b1 = 0;
    self->b2 = 0;
    self->unk5 = 0;
    self->unk8[0] = 0;
    self->unk8[1] = 0;
    self->unk8[2] = 0;
    self->unk8[3] = 0;
    self->unk8[4] = 0;
    self->unk8[5] = 0;
    self->unk8[6] = 0;
    self->unk8[7] = 0;
    self->unk28 = -0x3000;
    self->unk2C = 0;
    self->unk30 = 0;
    return self;
}

}
