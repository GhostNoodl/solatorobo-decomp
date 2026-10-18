#include "ov006/SlotManager.h"

typedef struct ov006_Prop {
    void *vtbl;
    u8 unk4[0x20];
    u8 unk24[0x14];
    void *unk38;
    u8 unk3C[0x8];
    void *unk44;
    void *unk48;
    u8 unk4C[0x24];
    s32 posX;
    s32 posY;
    s32 posZ;
    u16 rotX;
    u16 rotY;
    u16 rotZ;
    u8 unk82[0x11c];
    u8 unk19E;
    u8 unk19F;
    u8 unk1A0[0x88];
} ov006_Prop;

typedef struct ov006_Pos {
    s32 x;
    s32 y;
    s32 z;
} ov006_Pos;

extern "C" {

ov006_Prop *func_ov006_021e63c8(ov006_Prop *self);
void *func_0206ffa0(u32 id);
void func_ov000_0218d1c0(ov006_Prop *self, u16 type, u32 id, void *res);
void func_ov000_021984f4(void *a, int b, int c);
void func_ov000_0219864c(void *a, int b, int c);
void *func_0203db40(void *a);
void func_ov000_02190a80(void *a, void *b);

BOOL func_ov006_021ea3e8(ov006_Prop *self) {
    BOOL result = FALSE;
    if (self->unk19F > data_ov006_021ec884->unk8->unkB) {
        result = TRUE;
    }
    return result;
}

void func_ov006_021ea410(ov006_Prop *self) {
    self->unk19F = data_ov006_021ec884->unk8->unkB + 1;
}

ov006_Prop *func_ov006_021ea430(u32 id, u8 a, const ov006_Pos *pos, const u16 *rot) {
    ov006_Prop *prop = (ov006_Prop *)func_0203dd9c(sizeof(ov006_Prop));
    if (prop != NULL) {
        prop = func_ov006_021e63c8(prop);
    }
    if (prop != NULL) {
        func_ov000_0218d1c0(prop, id & 0xf000, id, func_0206ffa0(id));
        prop->unk19E = a;
        prop->posX = pos->x;
        prop->posY = pos->y;
        prop->posZ = pos->z;
        prop->rotX = rot[0];
        prop->rotY = rot[1];
        prop->rotZ = rot[2];
        VCALL(prop, 04);
    }
    return prop;
}

void func_ov006_021ea4d4(ov006_Prop *self) {
    if (self->unk44 != NULL) {
        func_ov000_021984f4(self->unk44, 0, 0);
    }
}

void func_ov006_021ea4f4(ov006_Prop *self) {
    if (self->unk48 != NULL) {
        func_ov000_0219864c(self->unk48, 0, 0);
    }
}

void func_ov006_021ea514(ov006_Prop *self) {
    if (self->unk38 != NULL) {
        func_ov000_02190a80(self->unk38, func_0203db40(self->unk24));
    }
}

void func_ov006_021ea540(void) {
}

void func_ov006_021ea544(void) {
}

}
