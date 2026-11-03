#include "ov006/Model.h"

typedef struct ov006_Unk021e07ec {
    void *vtbl;
    u8 unk4[0x20];
    Model *unk24;
    VObj *unk28;
} ov006_Unk021e07ec;

extern "C" {

extern u8 ov006_Caption_vtbl[];

static inline void ov006_Unk021e07ec_dtor(ov006_Unk021e07ec *self) {
    self->vtbl = ov006_Caption_vtbl;
    OV006_DELETE_MODEL(self->unk24);
    OV006_DELETE_OBJECT(self->unk28);
}

ov006_Unk021e07ec *ov006_Caption_Dtor(ov006_Unk021e07ec *self) {
    ov006_Unk021e07ec_dtor(self);
    return self;
}

ov006_Unk021e07ec *ov006_Caption_DtorDelete(ov006_Unk021e07ec *self) {
    ov006_Unk021e07ec_dtor(self);
    Heap_Free(self);
    return self;
}

}
