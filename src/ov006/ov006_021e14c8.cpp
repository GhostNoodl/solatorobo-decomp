#include "ov006/Model.h"

typedef struct ov006_Unk021e14c8 {
    void *vtbl;
    u8 unk4[0x20];
    Object *unk24;
    ov006_Model *unk28;
    Object *unk2C;
} ov006_Unk021e14c8;

extern "C" {

extern u8 data_ov006_021ec1fc[];

static inline void ov006_Unk021e14c8_dtor(ov006_Unk021e14c8 *self) {
    self->vtbl = data_ov006_021ec1fc;
    OV006_DELETE_OBJECT(self->unk24);
    OV006_DELETE_MODEL(self->unk28);
    OV006_DELETE_OBJECT(self->unk2C);
}

ov006_Unk021e14c8 *func_ov006_021e14c8(ov006_Unk021e14c8 *self) {
    ov006_Unk021e14c8_dtor(self);
    return self;
}

ov006_Unk021e14c8 *func_ov006_021e15b8(ov006_Unk021e14c8 *self) {
    ov006_Unk021e14c8_dtor(self);
    func_0203de1c(self);
    return self;
}

}
