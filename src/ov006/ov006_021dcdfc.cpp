#include "ov006/Model.h"

typedef struct ov006_Unk021dcdfc {
    void *vtbl;
    u8 unk4[0x8];
    Model *unkC;
    Model *unk10;
} ov006_Unk021dcdfc;

extern "C" {

extern u8 Ov006Vt_021ec24c_vtbl[];

static inline void ov006_Unk021dcdfc_dtor(ov006_Unk021dcdfc *self) {
    self->vtbl = Ov006Vt_021ec24c_vtbl;
    OV006_DELETE_MODEL(self->unkC);
    OV006_DELETE_MODEL(self->unk10);
}

ov006_Unk021dcdfc *Ov006Vt_021ec24c_Dtor(ov006_Unk021dcdfc *self) {
    ov006_Unk021dcdfc_dtor(self);
    return self;
}

ov006_Unk021dcdfc *Ov006Vt_021ec24c_DtorDelete(ov006_Unk021dcdfc *self) {
    ov006_Unk021dcdfc_dtor(self);
    Heap_Free(self);
    return self;
}

}
