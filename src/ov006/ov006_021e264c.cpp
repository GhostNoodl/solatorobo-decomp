#include "ov006/ov006.h"

typedef struct ov006_Vec021e264c {
    int x;
    int y;
    int z;
} ov006_Vec021e264c;

static inline void ov006_Vec021e264c_Set(ov006_Vec021e264c *v, int x, int y, int z) {
    v->x = x;
    v->y = y;
    v->z = z;
}

typedef struct ov006_Elem021e264c {
    ov006_Vec021e264c pos;
    u8 unkC;
} ov006_Elem021e264c;

typedef struct ov006_Unk021e264c {
    void *vtbl;
    u8 unk4;
    int unk8;
    int unkC;
    ov006_Elem021e264c elems[4];
    int unk50;
    int unk54;
    int unk58;
    int unk5C;
    int unk60;
} ov006_Unk021e264c;

extern "C" {

extern u8 data_ov006_021ec2ac[];

ov006_Unk021e264c *func_ov006_021e264c(ov006_Unk021e264c *self) {
    int i;
    self->vtbl = data_ov006_021ec2ac;
    self->unk4 = 0;
    self->unk8 = 0;
    self->unkC = 0;
    for (i = 0; i < 4; i++) {
        ov006_Vec021e264c_Set(&self->elems[i].pos, 0, 0, 0);
        self->elems[i].unkC = 0;
    }
    self->unk50 = 0xa000;
    self->unk54 = 0;
    self->unk58 = 0;
    self->unk5C = 0;
    self->unk60 = 0;
    return self;
}

}
