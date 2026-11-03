#include "ov006/Model.h"

typedef struct ov006_Unk021ded00 {
    void *vtbl;
    u8 unk4[0x10];
    Model *unk14;
    VObj *unk18;
} ov006_Unk021ded00;

extern "C" {

extern u8 Ov006Vt_021ec27c_vtbl[];

static inline void ov006_Unk021ded00_dtor(ov006_Unk021ded00 *self) {
    self->vtbl = Ov006Vt_021ec27c_vtbl;
    OV006_DELETE_MODEL(self->unk14);
    OV006_DELETE_OBJECT(self->unk18);
}

ov006_Unk021ded00 *Ov006Vt_021ec27c_Dtor(ov006_Unk021ded00 *self) {
    ov006_Unk021ded00_dtor(self);
    return self;
}

ov006_Unk021ded00 *Ov006Vt_021ec27c_DtorDelete(ov006_Unk021ded00 *self) {
    ov006_Unk021ded00_dtor(self);
    Heap_Free(self);
    return self;
}

}
