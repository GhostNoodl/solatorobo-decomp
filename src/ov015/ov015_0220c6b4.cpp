#include "ov015/ov015.h"

extern "C" {

extern char data_ov015_02212e20[];
extern char data_ov015_02212e68[];

BOOL Ov015FishState1c_Exit(Ov015FishState1c *self, Ov015Fish *p) {
    self->fish = p;
    p->drawMode = 0;
    return TRUE;
}

void func_ov015_0220c6c8(Ov015FishState1c *self, Ov015Fish *p) {
    Ov015Vec pos(*(Ov015Vec *)&p->pos);
    if (pos.y >= 0) {
        pos.y = 0;
    } else {
        pos.y += FX_Div(0x28000, 0x5a000);
    }
    *(Ov015Vec *)&p->pos = pos;
    if (self->timer == 0x5a) {
        EffectObj *o;
        Ov015Vec v;
        SndMgr_PlayVolume(gSndMgr, 0x19, -1, -1, -1);
        SndMgr_PlayVolume(gSndMgr, 0x3e, -1, -1, -1);
        o = Effect3D_Create(data_ov015_02212e20, data_ov015_02212e68, 0, &self->fish->pos);
        o->unk_d4 = 1;
        o->unk_28 = 1;
        o->unk_50 = -0xc8000;
        v = self->fish->pos;
        v.y = 0;
        o->SetPos(&v);
        o->SetScale(&self->fish->scale);
    } else if (self->timer == 1) {
        SndMgr_PlayVolume(gSndMgr, 0x56, -1, -1, -1);
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
        Ov015Vec pos(*(Ov015Vec *)&(self->fish)->pos);
        pos.y += self->unk_10;
        if (pos.y < -0x32000) {
            pos.y = -0x32000;
        } else if (pos.y > -0xa000) {
            pos.y = -0xa000;
        }
        *(Ov015Vec *)&(self->fish)->pos = pos;
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
