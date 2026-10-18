#include "ov006/ov006.h"

typedef struct ov006_Sub021dbbac {
    void *vtbl;
    s8 unk4;
    u8 unk5[0x1f];
    s8 unk24;
    u8 unk25[0x1f];
    int unk44;
    u8 unk48[4];
    u8 unk4C[0x20];
    s8 unk6C;
} ov006_Sub021dbbac;

typedef struct ov006_Unk021dbbac {
    void *vtbl;
    u8 unk4;
    u8 unk5[3];
    ov006_Sub021dbbac sub;
    u8 unk78[0x1c];
    u8 unk94;
} ov006_Unk021dbbac;

extern "C" {

static inline void ov006_Sub021dbbac_Stop(ov006_Sub021dbbac *sub) {
    if (sub->unk24 != 0 || sub->unk4 != 0) {
        VCALL(sub, 0C);
    }
    VCALL(sub, 08);
}

void func_ov006_021dbbac(ov006_Unk021dbbac *self) {
    switch (self->unk4) {
    case 0:
        if (!self->unk94) {
            return;
        }
        ov006_Sub021dbbac_Stop(&self->sub);
        self->sub.unk44 = 2;
        if (self->sub.unk6C != 0) {
            VCALL(&self->sub, 24, self->sub.unk4C, &self->sub.unk6C);
        } else {
            VCALL(&self->sub, 1C, self->sub.unk4C);
        }
        self->unk94 = 0;
        self->unk4++;
        break;
    case 1:
        if (VCALL(&self->sub, 2C)) {
            self->unk4++;
        }
        break;
    case 2:
        if (!self->unk94) {
            VCALL(&self->sub, 30);
        }
        self->unk4 = 0;
        break;
    }
}

}
