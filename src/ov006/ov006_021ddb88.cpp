#include "ov006/Model.h"

typedef struct ov006_Unk021ddb88 {
    void *vtbl;
    u8 unk4[0x18];
    ov006_Model *unk1C;
} ov006_Unk021ddb88;

extern "C" {

extern u8 data_ov006_021ec2dc[];

static inline void ov006_Unk021ddb88_dtor(ov006_Unk021ddb88 *self) {
    self->vtbl = data_ov006_021ec2dc;
    OV006_DELETE_MODEL(self->unk1C);
}

ov006_Unk021ddb88 *func_ov006_021ddb88(ov006_Unk021ddb88 *self) {
    ov006_Unk021ddb88_dtor(self);
    return self;
}

ov006_Unk021ddb88 *func_ov006_021ddbf8(ov006_Unk021ddb88 *self) {
    ov006_Unk021ddb88_dtor(self);
    func_0203de1c(self);
    return self;
}

}
