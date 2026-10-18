#include "ov006/Model.h"

typedef struct ov006_Unk021dcdfc {
    void *vtbl;
    u8 unk4[0x8];
    ov006_Model *unkC;
    ov006_Model *unk10;
} ov006_Unk021dcdfc;

extern "C" {

extern u8 data_ov006_021ec24c[];

static inline void ov006_Unk021dcdfc_dtor(ov006_Unk021dcdfc *self) {
    self->vtbl = data_ov006_021ec24c;
    OV006_DELETE_MODEL(self->unkC);
    OV006_DELETE_MODEL(self->unk10);
}

ov006_Unk021dcdfc *func_ov006_021dcdfc(ov006_Unk021dcdfc *self) {
    ov006_Unk021dcdfc_dtor(self);
    return self;
}

ov006_Unk021dcdfc *func_ov006_021dceb8(ov006_Unk021dcdfc *self) {
    ov006_Unk021dcdfc_dtor(self);
    func_0203de1c(self);
    return self;
}

}
