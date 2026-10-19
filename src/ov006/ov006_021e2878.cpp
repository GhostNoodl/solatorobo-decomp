#include "ov006/Model.h"

typedef struct ov006_Unk021e2878 {
    u8 unk0[4];
    u8 unk4;
    u8 unk5[0x5b];
    void *unk60;
} ov006_Unk021e2878;

typedef struct ov006_MarkEnt {
    s32 x;
    s32 unk4;
    s32 z;
    u8 on;
    u8 unkD[3];
} ov006_MarkEnt;

typedef struct ov006_Marks {
    void *vtbl;
    u8 unk4;
    u8 unk5[3];
    s32 unk8;
    s32 unkC;
    ov006_MarkEnt ents[4];
    s32 unk50;
    s32 unk54;
    s32 unk58;
    s32 unk5C;
    ov006_Model *unk60;
} ov006_Marks;

extern "C" {

BOOL func_02054f10(void *a, int b);
s32 FX_Div(s32 numer, s32 denom);

void func_ov006_021e2878(ov006_Unk021e2878 *self) {
    if (self->unk4) {
        return;
    }
    if (self->unk60 == NULL) {
        return;
    }
    if (func_02054f10(self->unk60, 0xffff)) {
        self->unk4 = 1;
    }
}

void func_ov006_021e28b4(ov006_Marks *self) {
    s32 bx;
    s32 by;
    int i;
    s32 dx;
    s32 dz;
    ov006_MarkEnt *e;
    u16 idx;
    if (!self->unk4) {
        return;
    }
    bx = self->unk8;
    by = self->unkC;
    for (i = 0; i < 4; i++) {
        if (!self->ents[i].on) {
            continue;
        }
        e = &self->ents[i];
        {
            s32 tx = e->x - self->unk54;
            s32 tz = e->z - self->unk5C;
            dx = FX_Div(tx, self->unk50);
            dz = FX_Div(tz, self->unk50);
        }
        dx = bx + (dx >> 12);
        dz = by + (dz >> 12);
        ov006_Model_SetPos(self->unk60, 2, dx << 12, dz << 12);
        idx = i + 0xc;
        ov006_Model_PlayPart(self->unk60, idx);
    }
}

}
