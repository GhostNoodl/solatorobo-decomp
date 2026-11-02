#include "ov006/Model.h"

typedef struct ov006_Unk021e26b4 {
    void *vtbl;
    u8 unk4[0x5c];
    ov006_Model *unk60;
} ov006_Unk021e26b4;

extern "C" {

extern u8 data_ov006_021ec2ac[];

static inline void ov006_Unk021e26b4_dtor(ov006_Unk021e26b4 *self) {
    self->vtbl = data_ov006_021ec2ac;
    OV006_DELETE_MODEL(self->unk60);
}

ov006_Unk021e26b4 *Ov006Vt_021ec2ac_Dtor(ov006_Unk021e26b4 *self) {
    ov006_Unk021e26b4_dtor(self);
    return self;
}

ov006_Unk021e26b4 *Ov006Vt_021ec2ac_DtorDelete(ov006_Unk021e26b4 *self) {
    ov006_Unk021e26b4_dtor(self);
    Heap_Free(self);
    return self;
}

}
