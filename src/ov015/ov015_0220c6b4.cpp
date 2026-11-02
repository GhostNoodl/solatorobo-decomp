#include "ov015/ov015.h"

extern "C" {

extern u8 data_ov015_02212e20[];
extern u8 data_ov015_02212e68[];
u8 *func_02066774(void *a, void *b, int c, void *d);

BOOL Ov015FishState1c_Exit(Ov015FishState1c *self, Ov015Fish *p) {
    self->fish = p;
    p->drawMode = 0;
    return TRUE;
}

void func_ov015_0220c6c8(Ov015FishState1c *self, Ov015Fish *p) {
    Ov015VecC pos(*(Ov015VecC *)&p->pos);
    if (pos.y >= 0) {
        pos.y = 0;
    } else {
        pos.y += FX_Div(0x28000, 0x5a000);
    }
    *(Ov015VecC *)&p->pos = pos;
    if (self->timer == 0x5a) {
        u8 *o;
        Ov015Vec v;
        func_02049a48(data_02097e4c, 0x19, -1, -1, -1);
        func_02049a48(data_02097e4c, 0x3e, -1, -1, -1);
        o = func_02066774(data_ov015_02212e20, data_ov015_02212e68, 0, &self->fish->pos);
        FLD(s32, o, 0xd4) = 1;
        FLD(u8, o, 0x28) = 1;
        FLD(s32, o, 0x50) = -0xc8000;
        v = self->fish->pos;
        v.y = 0;
        VCALL(o)->v18(&v);
        VCALL(o)->v10(&self->fish->scaleX);
    } else if (self->timer == 1) {
        func_02049a48(data_02097e4c, 0x56, -1, -1, -1);
    }
}

BOOL func_ov015_0220c810(Ov015FishState1c *self) {
    Ov015Stat *g = &data_ov015_0221332c;
    s32 max = (self->fish)->info.unk_24;
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
        Ov015VecC pos(*(Ov015VecC *)&(self->fish)->pos);
        pos.y += self->unk_10;
        if (pos.y < -0x32000) {
            pos.y = -0x32000;
        } else if (pos.y > -0xa000) {
            pos.y = -0xa000;
        }
        *(Ov015VecC *)&(self->fish)->pos = pos;
    }
    s32 c = --self->unk_0c;
    s32 y = (self->fish)->pos.y;
    if (c < 0 || y >= -0xa000) {
        s32 t = FX_Div(0x4b0000 - (self->unk_0c << 12), 0x4b0000);
        Ov015Fish *o = self->fish;
        o->info.unk_1c = FX_Mul(t, o->info.unk_1c);
        r = FALSE;
    }
    return r;
}

}
