#include "ov006/ov006.h"

typedef struct ov006_Sub021dbacc {
    void *vtbl;
    s8 unk4;
    u8 unk5[0x1f];
    s8 unk24;
} ov006_Sub021dbacc;

typedef struct ov006_Unk021dbacc {
    void *vtbl;
    u8 unk4[4];
    ov006_Sub021dbacc sub;
} ov006_Unk021dbacc;

extern "C" {

extern u8 data_ov006_021ec25c[];
extern u8 data_0208b318[];

ov006_Unk021dbacc *Ov006Vt_021ec25c_Dtor(ov006_Unk021dbacc *self) {
    self->vtbl = data_ov006_021ec25c;
    if (self->sub.unk24 != 0 || self->sub.unk4 != 0) {
        VCALL(&self->sub, 0c);
    }
    VCALL(&self->sub, 08);
    self->sub.vtbl = data_0208b318;
    VCALL(&self->sub, 0c);
    return self;
}

}
