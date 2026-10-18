#include "ov006/Model.h"

typedef struct ov006_Unk021dc778 {
    void *vtbl;
    u8 unk4[0x28];
    ov006_Model *unk2C;
    ov006_Model *unk30;
} ov006_Unk021dc778;

extern "C" {

extern u8 data_ov006_021ec28c[];

static inline void ov006_Unk021dc778_dtor(ov006_Unk021dc778 *self) {
    self->vtbl = data_ov006_021ec28c;
    OV006_DELETE_MODEL(self->unk2C);
    OV006_DELETE_MODEL(self->unk30);
}

ov006_Unk021dc778 *func_ov006_021dc778(ov006_Unk021dc778 *self) {
    ov006_Unk021dc778_dtor(self);
    return self;
}

ov006_Unk021dc778 *func_ov006_021dc834(ov006_Unk021dc778 *self) {
    ov006_Unk021dc778_dtor(self);
    func_0203de1c(self);
    return self;
}

}
