#include "ov006/Model.h"

typedef struct ov006_Unk021dd2e8 {
    void *vtbl;
    u8 unk4[0x14];
    VObj *unk18;
    Model *unk1C;
} ov006_Unk021dd2e8;

extern "C" {

extern u8 Ov006Vt_021ec21c_vtbl[];

static inline void ov006_Unk021dd2e8_dtor(ov006_Unk021dd2e8 *self) {
    self->vtbl = Ov006Vt_021ec21c_vtbl;
    OV006_DELETE_OBJECT(self->unk18);
    OV006_DELETE_MODEL(self->unk1C);
}

ov006_Unk021dd2e8 *Ov006Vt_021ec21c_Dtor(ov006_Unk021dd2e8 *self) {
    ov006_Unk021dd2e8_dtor(self);
    return self;
}

ov006_Unk021dd2e8 *Ov006Vt_021ec21c_DtorDelete(ov006_Unk021dd2e8 *self) {
    ov006_Unk021dd2e8_dtor(self);
    Heap_Free(self);
    return self;
}

}
