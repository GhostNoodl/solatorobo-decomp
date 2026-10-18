#include "ov006/Model.h"

typedef struct ov006_Unk021ded00 {
    void *vtbl;
    u8 unk4[0x10];
    ov006_Model *unk14;
    Object *unk18;
} ov006_Unk021ded00;

extern "C" {

extern u8 data_ov006_021ec27c[];

static inline void ov006_Unk021ded00_dtor(ov006_Unk021ded00 *self) {
    self->vtbl = data_ov006_021ec27c;
    OV006_DELETE_MODEL(self->unk14);
    OV006_DELETE_OBJECT(self->unk18);
}

ov006_Unk021ded00 *func_ov006_021ded00(ov006_Unk021ded00 *self) {
    ov006_Unk021ded00_dtor(self);
    return self;
}

ov006_Unk021ded00 *func_ov006_021dedb0(ov006_Unk021ded00 *self) {
    ov006_Unk021ded00_dtor(self);
    func_0203de1c(self);
    return self;
}

}
