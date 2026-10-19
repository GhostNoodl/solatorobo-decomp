#include "ov006/Model.h"
#include "nitro/fx.h"

typedef struct ov006_Unk021dd0e4 {
    u8 unk0[4];
    u8 state;
    s8 unk5;
    s8 unk6;
    u8 unk7;
    u16 timer;
    u8 flag0 : 1;
    u8 flag1 : 1;
    u8 flag2 : 6;
    u8 unkB;
    ov006_Model *unkC;
    ov006_Model *unk10;
} ov006_Unk021dd0e4;

extern "C" {

BOOL func_02054f10(void *a, int b);

static inline MtxFx22 *ov006_Model_Mtx22(ov006_Model *m) {
    return (MtxFx22 *)((u8 *)m + 0x114);
}

void func_ov006_021dd0e4(ov006_Unk021dd0e4 *self) {
    if (self->state == 0) {
        if (self->unkC == NULL) {
            return;
        }
        if (!func_02054f10(self->unkC, 0xffff) || self->unk10 == NULL) {
            return;
        }
        if (func_02054f10(self->unk10, 0xffff)) {
            self->state = 4;
        }
        return;
    }
    switch (self->state) {
    case 0:
        break;
    case 1:
        self->timer = 0;
        self->unk5 = 0;
        MTX_Identity22_(ov006_Model_Mtx22(self->unk10));
        self->flag1 = 0;
        self->state = 2;
    case 2:
        self->timer++;
        self->timer = self->timer % 3;
        if (self->flag1) {
            self->timer = 0;
            self->flag1 = 0;
            self->state = 3;
        }
        if (self->timer == 0) {
            self->unk5++;
            self->unk5 = self->unk5 % self->unk6;
        }
        break;
    case 3: {
        fx32 t;
        fx32 s;
        self->timer++;
        t = FX_Div(self->timer << 12, 0xa000);
        s = FX_Mul(FX_SinCosTable_[(FX_Mul(t, 0x7fff000) >> 16) * 2], 0x1000);
        MTX_Identity22_(ov006_Model_Mtx22(self->unk10));
        MTX_ScaleApply22(ov006_Model_Mtx22(self->unk10), ov006_Model_Mtx22(self->unk10), s + 0x1000, s + 0x1000);
        if ((s32)self->timer >= 10) {
            self->timer = 0;
            self->state = 4;
        }
        break;
    }
    case 4:
        if (self->flag0) {
            self->flag0 = 0;
            self->state = 1;
        }
        break;
    }
}

}
