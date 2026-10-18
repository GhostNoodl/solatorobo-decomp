#include "ov006/ov006.h"

typedef struct ov006_Unk021e07b0 {
    void *vtbl;
    u8 unk4;
    int unk8[9];
} ov006_Unk021e07b0;

extern "C" {

extern void *data_ov006_021ec22c;

ov006_Unk021e07b0 *func_ov006_021e07b0(ov006_Unk021e07b0 *self) {
    self->vtbl = &data_ov006_021ec22c;
    self->unk4 = 0;
    self->unk8[0] = 0;
    self->unk8[1] = 0;
    self->unk8[2] = 0;
    self->unk8[3] = 0;
    self->unk8[4] = 0;
    self->unk8[5] = 0;
    self->unk8[6] = 0;
    self->unk8[7] = 0;
    self->unk8[8] = 0;
    return self;
}

}
