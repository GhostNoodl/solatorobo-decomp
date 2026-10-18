#include "ov006/ov006.h"

typedef struct ov006_Unk021e29c4 {
    void *vtbl;
    u8 unk4;
    int unk8;
    int unkC;
    int unk10;
    int unk14;
    int unk18[3];
} ov006_Unk021e29c4;

extern "C" {

extern u8 data_ov006_021ec29c[];

ov006_Unk021e29c4 *func_ov006_021e29c4(ov006_Unk021e29c4 *self) {
    int i;
    self->vtbl = data_ov006_021ec29c;
    self->unk4 = 0;
    self->unk8 = 0;
    self->unkC = 0;
    self->unk10 = 0;
    self->unk14 = 0;
    for (i = 0; i < 3; i++) {
        self->unk18[i] = 0;
    }
    return self;
}

}
