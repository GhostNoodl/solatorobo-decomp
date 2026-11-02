#include "ov015/ov015.h"

extern "C" {

extern void **data_0214a420;
Ov015V *func_020657b0(void *a, void *b);
s32 FX_Div(s32 a, s32 b);
s32 Interp_SinLerp(s32 t, s32 a, s32 b);
void MTX_RotY33_(void *m, s32 s, s32 c);
void MTX_MultVec33(void *a, void *b, void *c);
void VEC_Normalize(void *src, void *dst);
void func_ov015_0220afcc(Ov015FishState2c *self);
void func_ov015_0220b1b8(Ov015FishState2c *self);

BOOL Ov015FishState2c_Exit(Ov015FishState2c *self, Ov015Fish *a) {
    Ov015V *o;
    u32 saved;
    self->unk_20 = a;
    o = func_020657b0(data_0214a420, self->unk_24);
    if (o != NULL) {
        HEAP_PUSH(saved);
        if (o != NULL) {
            if (o != NULL) {
                o->v04();
            }
        }
        HEAP_POP(saved);
    }
    o = func_020657b0(data_0214a420, self->unk_28);
    if (o != NULL) {
        HEAP_PUSH(saved);
        if (o != NULL) {
            if (o != NULL) {
                o->v04();
            }
        }
        HEAP_POP(saved);
    }
    return TRUE;
}

void func_ov015_0220ac40(Ov015FishState2c *self, Ov015Fish *p) {
    Ov015VecC pos(*(Ov015VecC *)&p->unk_40);
    Ov015VecC dir(*(Ov015VecC *)&p->unk_9c);
    s32 m[9];
    s32 t = FX_Div(self->unk_06 << 12, 0x14000);
    s32 b = Ov015_FxMul((self->unk_20)->unk_c0.unk_0a << 4, 0x19a) + 0x800;
    s32 d = Ov015_FxMul(Interp_SinLerp(Ov015_FxMul(self->unk_18, self->unk_18), b / 5, b), t);
    p->unk_a8 = d;
    p->unk_40.x = pos.x + d;
    p->unk_40.y = pos.y;
    p->unk_40.z = pos.z;
    MTX_RotY33_(m, FX_SinCosTable_[0xfbb * 2], FX_SinCosTable_[0xfbb * 2 + 1]);
    MTX_MultVec33(&dir, m, &dir);
    VEC_Normalize(&dir, &p->unk_9c);
    func_ov015_0220afcc(self);
    func_ov015_0220b1b8(self);
}

void func_ov015_0220ad68(Ov015FishState2c *self, Ov015Fish *p) {
    Ov015VecC pos(*(Ov015VecC *)&p->unk_40);
    Ov015VecC dir(*(Ov015VecC *)&p->unk_9c);
    s32 m[9];
    s32 t = FX_Div(self->unk_06 << 12, 0x14000);
    s32 b = Ov015_FxMul((self->unk_20)->unk_c0.unk_0a << 4, 0x19a) + 0x800;
    s32 d = Ov015_FxMul(Interp_SinLerp(Ov015_FxMul(self->unk_18, self->unk_18), b / 5, b), t);
    p->unk_a8 = d;
    p->unk_40.x = pos.x - d;
    p->unk_40.y = pos.y;
    p->unk_40.z = pos.z;
    MTX_RotY33_(m, FX_SinCosTable_[0x44 * 2], FX_SinCosTable_[0x44 * 2 + 1]);
    MTX_MultVec33(&dir, m, &dir);
    VEC_Normalize(&dir, &p->unk_9c);
    func_ov015_0220afcc(self);
    func_ov015_0220b1b8(self);
}

BOOL func_ov015_0220ae90(Ov015FishState2c *self) {
    Ov015Fish *p = self->unk_20;
    s32 acc = p->unk_c0.unk_12;
    s32 dec = p->unk_c0.unk_20;
    Ov015Stat *st = &data_ov015_0221332c;
    if ((u32)self & 3) {
        dec = p->unk_c0.unk_20;
    }
    s32 lim;
    s32 sp;
    s32 v;
    self->unk_10 = self->unk_0c;
    if (st->unk_1c != 0 && st->unk_28 != 3) {
        self->unk_0c -= dec;
        self->unk_0a = 10;
        self->unk_1c = 6;
    } else {
        if (self->unk_0a <= 0) {
            self->unk_0c += acc << 4;
        } else {
            self->unk_0a--;
        }
        self->unk_1c--;
        if (self->unk_1c <= 0) {
            self->unk_1c = 0;
        }
    }
    v = p->unk_c0.unk_10 << 12;
    sp = p->unk_c0.unk_28;
    if (sp < 0xe10000) {
        lim = Ov015_FxMul(v, 0x1000);
    } else if (sp < 0x1c20000) {
        lim = Ov015_FxMul(v, 0xccd);
    } else {
        lim = Ov015_FxMul(v, 0xb33);
    }
    if (self->unk_0c > lim) {
        self->unk_0c = lim;
    }
    p->unk_c0.unk_1c = self->unk_0c;
    return self->unk_0c <= 0;
}

}
