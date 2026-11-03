#include "ov006/Model.h"

typedef struct ov006_Unk021ddb88 {
    void *vtbl;
    u8 unk4[0x18];
    Model *unk1C;
} ov006_Unk021ddb88;

extern "C" {

extern u8 Ov006Vt_021ec2dc_vtbl[];

static inline void ov006_Unk021ddb88_dtor(ov006_Unk021ddb88 *self) {
    self->vtbl = Ov006Vt_021ec2dc_vtbl;
    OV006_DELETE_MODEL(self->unk1C);
}

ov006_Unk021ddb88 *Ov006Vt_021ec2dc_Dtor(ov006_Unk021ddb88 *self) {
    ov006_Unk021ddb88_dtor(self);
    return self;
}

ov006_Unk021ddb88 *Ov006Vt_021ec2dc_DtorDelete(ov006_Unk021ddb88 *self) {
    ov006_Unk021ddb88_dtor(self);
    Heap_Free(self);
    return self;
}

}
