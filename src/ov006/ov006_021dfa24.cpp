#include "ov006/ov006.h"

typedef struct ov006_Unk021dfa24 {
    void *vtbl;
    u16 unk4;
    u16 unk6;
    u8 unk8[8];
    u8 unk10;
    u8 unk11;
    int unk14;
    int unk18;
    int unk1C;
    int unk20;
} ov006_Unk021dfa24;

extern "C" {

extern void *Ov006Vt_021ec23c_vtbl;

ov006_Unk021dfa24 *Ov006Vt_021ec23c_Ctor(ov006_Unk021dfa24 *self) {
    self->vtbl = &Ov006Vt_021ec23c_vtbl;
    self->unk4 = 0;
    self->unk6 = 0;
    self->unk10 = 0;
    self->unk11 = 1;
    self->unk14 = -1;
    self->unk18 = -1;
    self->unk1C = 0;
    self->unk20 = 0;
    return self;
}

}
