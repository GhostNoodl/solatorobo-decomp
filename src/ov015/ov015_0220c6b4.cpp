#include "ov015/ov015.h"

extern "C" {

extern void *data_02097e4c;
extern u8 data_ov015_02212e20[];
extern u8 data_ov015_02212e68[];
void *func_02049a48(void *a, int b, int c, int d, int e);
s32 FX_Div(s32 a, s32 b);
u8 *func_02066774(void *a, void *b, int c, void *d);

BOOL Ov015FishState1c_Exit(Ov015FishState1c *self, Ov015Fish *p) {
    self->unk_18 = p;
    p->unk_108 = 0;
    return TRUE;
}

void func_ov015_0220c6c8(Ov015FishState1c *self, Ov015Fish *p) {
    Ov015VecC pos(*(Ov015VecC *)&p->unk_40);
    if (pos.y >= 0) {
        pos.y = 0;
    } else {
        pos.y += FX_Div(0x28000, 0x5a000);
    }
    *(Ov015VecC *)&p->unk_40 = pos;
    if (self->unk_08 == 0x5a) {
        u8 *o;
        Ov015Vec v;
        func_02049a48(data_02097e4c, 0x19, -1, -1, -1);
        func_02049a48(data_02097e4c, 0x3e, -1, -1, -1);
        o = func_02066774(data_ov015_02212e20, data_ov015_02212e68, 0, &self->unk_18->unk_40);
        FLD(s32, o, 0xd4) = 1;
        FLD(u8, o, 0x28) = 1;
        FLD(s32, o, 0x50) = -0xc8000;
        v = self->unk_18->unk_40;
        v.y = 0;
        VCALL(o)->v18(&v);
        VCALL(o)->v10(&self->unk_18->unk_70);
    } else if (self->unk_08 == 1) {
        func_02049a48(data_02097e4c, 0x56, -1, -1, -1);
    }
}

BOOL func_ov015_0220c810(Ov015FishState1c *self) {
    Ov015Stat *g = &data_ov015_0221332c;
    s32 max = (self->unk_18)->unk_c0.unk_24;
    u8 *p;
    BOOL r = TRUE;
    if (g->unk_14 == 4) {
        if (g->unk_1c != 0) {
            self->unk_10 = self->unk_10 + max / 24;
        } else {
            self->unk_10 = 0;
        }
    } else {
        self->unk_10 = self->unk_10 - 0x19;
    }
    if (self->unk_10 < -0x19a) {
        self->unk_10 = -0x19a;
    } else if (self->unk_10 > max) {
        self->unk_10 = max;
    }
    {
        Ov015VecC pos(*(Ov015VecC *)&(self->unk_18)->unk_40);
        pos.y += self->unk_10;
        if (pos.y < -0x32000) {
            pos.y = -0x32000;
        } else if (pos.y > -0xa000) {
            pos.y = -0xa000;
        }
        *(Ov015VecC *)&(self->unk_18)->unk_40 = pos;
    }
    s32 c = --self->unk_0c;
    s32 y = (self->unk_18)->unk_40.y;
    if (c < 0 || y >= -0xa000) {
        s32 t = FX_Div(0x4b0000 - (self->unk_0c << 12), 0x4b0000);
        Ov015Fish *o = self->unk_18;
        o->unk_c0.unk_1c = Ov015_FxMul(t, o->unk_c0.unk_1c);
        r = FALSE;
    }
    return r;
}

}
