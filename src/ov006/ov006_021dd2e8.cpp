#include "ov006/Model.h"

typedef struct ov006_Unk021dd2e8 {
    void *vtbl;
    u8 unk4[0x14];
    Object *unk18;
    ov006_Model *unk1C;
} ov006_Unk021dd2e8;

extern "C" {

extern u8 data_ov006_021ec21c[];

static inline void ov006_Unk021dd2e8_dtor(ov006_Unk021dd2e8 *self) {
    self->vtbl = data_ov006_021ec21c;
    OV006_DELETE_OBJECT(self->unk18);
    OV006_DELETE_MODEL(self->unk1C);
}

ov006_Unk021dd2e8 *func_ov006_021dd2e8(ov006_Unk021dd2e8 *self) {
    ov006_Unk021dd2e8_dtor(self);
    return self;
}

ov006_Unk021dd2e8 *func_ov006_021dd398(ov006_Unk021dd2e8 *self) {
    ov006_Unk021dd2e8_dtor(self);
    func_0203de1c(self);
    return self;
}

}
