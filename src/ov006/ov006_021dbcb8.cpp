#include "ov006/Model.h"

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

typedef struct ov006_Unk021dbdb0 {
    void *vtbl;
    int unk4;
    u16 unk8;
    ov006_Unk021dbacc base;
    u8 unk3C[0x24];
    char unk60[0x20];
    char unk80[0x20];
    u8 unkA0;
    u8 unkA1[3];
    u16 unkA4;
    ov006_Model *unkA8;
    u8 unkAC[4];
    int unkB0[6];
    int unkC8;
    int unkCC;
    int unkD0;
    int unkD4;
    int unkD8;
    int unkDC;
    int unkE0;
    int unkE4;
    u8 unkE8;
} ov006_Unk021dbdb0;

extern "C" {

extern u8 data_ov006_021ec2fc[];
extern u8 data_ov006_021ec25c[];
extern u8 data_0208b318[];
void MI_CpuFill8(void *dst, u8 value, u32 size);

static inline void ov006_Sub021dbacc_Stop(ov006_Sub021dbacc *sub) {
    if (sub->unk24 != 0 || sub->unk4 != 0) {
        VCALL(sub, 0C);
    }
    VCALL(sub, 08);
}

static inline void ov006_Unk021dbacc_dtor(ov006_Unk021dbacc *self) {
    self->vtbl = data_ov006_021ec25c;
    ov006_Sub021dbacc_Stop(&self->sub);
    self->sub.vtbl = data_0208b318;
    VCALL(&self->sub, 0C);
}

static inline void ov006_Unk021dbdb0_dtor(ov006_Unk021dbdb0 *self) {
    self->vtbl = data_ov006_021ec2fc;
    ov006_Sub021dbacc_Stop(&self->base.sub);
    OV006_DELETE_MODEL(self->unkA8);
    ov006_Unk021dbacc_dtor(&self->base);
}

ov006_Unk021dbdb0 *func_ov006_021dbcb8(ov006_Unk021dbdb0 *self) {
    self->vtbl = data_ov006_021ec2fc;
    self->base.vtbl = data_ov006_021ec25c;
    self->base.sub.vtbl = data_0208b318;
    VCALL(&self->base.sub, 08);
    self->base.unk4[0] = 0;
    VCALL(&self->base.sub, 08);
    MI_CpuFill8(self->unk60, 0, 0x20);
    MI_CpuFill8(self->unk80, 0, 0x20);
    self->unkA0 = 0;
    self->unk8 = 0;
    self->unk4 = 2;
    VCALL(&self->base.sub, 08);
    self->unkA8 = NULL;
    self->unkB0[0] = 0;
    self->unkB0[1] = 0;
    self->unkB0[2] = 0;
    self->unkB0[3] = 0;
    self->unkB0[4] = 0;
    self->unkB0[5] = 0;
    self->unkCC = 0;
    self->unkD0 = 0;
    self->unkDC = 0;
    self->unkE0 = 0;
    self->unkE4 = 0;
    self->unkE8 = 0;
    self->unkA4 = 0xffff;
    self->unkC8 = 0x1000;
    self->unkD4 = 0x20000;
    self->unkD8 = 0xc000;
    return self;
}

ov006_Unk021dbdb0 *func_ov006_021dbdb0(ov006_Unk021dbdb0 *self) {
    ov006_Unk021dbdb0_dtor(self);
    return self;
}

ov006_Unk021dbdb0 *func_ov006_021dbeb0(ov006_Unk021dbdb0 *self) {
    ov006_Unk021dbdb0_dtor(self);
    func_0203de1c(self);
    return self;
}

}
