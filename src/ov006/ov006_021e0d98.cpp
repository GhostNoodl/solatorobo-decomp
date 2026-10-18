#include "ov006/Model.h"

typedef struct ov006_Unk021e0d98 {
    void *vtbl;
    u8 unk4[0x18];
    ov006_Model *unk1C;
    Object *unk20;
} ov006_Unk021e0d98;

extern "C" {

extern u8 data_ov006_021ec20c[];

static inline void ov006_Unk021e0d98_dtor(ov006_Unk021e0d98 *self) {
    self->vtbl = data_ov006_021ec20c;
    OV006_DELETE_MODEL(self->unk1C);
    OV006_DELETE_OBJECT(self->unk20);
}

ov006_Unk021e0d98 *func_ov006_021e0d98(ov006_Unk021e0d98 *self) {
    ov006_Unk021e0d98_dtor(self);
    return self;
}

ov006_Unk021e0d98 *func_ov006_021e0e48(ov006_Unk021e0d98 *self) {
    ov006_Unk021e0d98_dtor(self);
    func_0203de1c(self);
    return self;
}

}
