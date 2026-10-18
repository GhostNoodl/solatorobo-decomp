#include "ov006/ov006.h"

typedef struct ov006_Unk021e0d64 {
    void *vtbl;
    u8 unk4;
    u8 unk5;
    int unk8;
    int unkC;
    int unk10;
    int unk14;
    int unk18;
    int unk1C;
    int unk20;
} ov006_Unk021e0d64;

extern "C" {

extern void *data_ov006_021ec20c;

ov006_Unk021e0d64 *func_ov006_021e0d64(ov006_Unk021e0d64 *self) {
    self->vtbl = &data_ov006_021ec20c;
    self->unk4 = 0;
    self->unk8 = 0;
    self->unkC = 0;
    self->unk5 = 0;
    self->unk14 = 0;
    self->unk18 = 0;
    self->unk1C = 0;
    self->unk20 = 0;
    return self;
}

}
