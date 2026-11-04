#include "ov015/ov015.h"

extern "C" {

s32 Interp_SinLerp(s32 t, s32 a, s32 b);
void Ov015FishState2c_UpdateWake(Ov015FishState2c *self);
void Ov015FishState2c_UpdateSwim(Ov015FishState2c *self);

BOOL Ov015FishState2c_Exit(Ov015FishState2c *self, Ov015Fish *a) {
    EffectObj *o;
    void *saved;
    self->fish = a;
    o = Effect_Find_020657b0(gEffectMgr, self->unk_24);
    if (o != NULL) {
        HEAP_PUSH(saved);
        if (o != NULL) {
            if (o != NULL) {
                o->Delete();
            }
        }
        HEAP_POP(saved);
    }
    o = Effect_Find_020657b0(gEffectMgr, self->unk_28);
    if (o != NULL) {
        HEAP_PUSH(saved);
        if (o != NULL) {
            if (o != NULL) {
                o->Delete();
            }
        }
        HEAP_POP(saved);
    }
    return TRUE;
}

void func_ov015_0220ac40(Ov015FishState2c *self, Ov015Fish *p) {
    Ov015Vec pos(*(Ov015Vec *)&p->pos);
    Ov015Vec dir(*(Ov015Vec *)&p->dir);
    s32 m[9];
    s32 t = FX_Div(self->unk_06 << 12, 0x14000);
    s32 b = FX_Mul((self->fish)->info.unk_0a << 4, 0x19a) + 0x800;
    s32 d = FX_Mul(Interp_SinLerp(FX_Mul(self->unk_18, self->unk_18), b / 5, b), t);
    p->unk_a8 = d;
    p->pos.x = pos.x + d;
    p->pos.y = pos.y;
    p->pos.z = pos.z;
    MTX_RotY33_((MtxFx33 *)m, FX_SinCosTable_[0xfbb * 2], FX_SinCosTable_[0xfbb * 2 + 1]);
    MTX_MultVec33(&dir, (MtxFx33 *)m, &dir);
    VEC_Normalize(&dir, (&p->dir));
    Ov015FishState2c_UpdateWake(self);
    Ov015FishState2c_UpdateSwim(self);
}

void func_ov015_0220ad68(Ov015FishState2c *self, Ov015Fish *p) {
    Ov015Vec pos(*(Ov015Vec *)&p->pos);
    Ov015Vec dir(*(Ov015Vec *)&p->dir);
    s32 m[9];
    s32 t = FX_Div(self->unk_06 << 12, 0x14000);
    s32 b = FX_Mul((self->fish)->info.unk_0a << 4, 0x19a) + 0x800;
    s32 d = FX_Mul(Interp_SinLerp(FX_Mul(self->unk_18, self->unk_18), b / 5, b), t);
    p->unk_a8 = d;
    p->pos.x = pos.x - d;
    p->pos.y = pos.y;
    p->pos.z = pos.z;
    MTX_RotY33_((MtxFx33 *)m, FX_SinCosTable_[0x44 * 2], FX_SinCosTable_[0x44 * 2 + 1]);
    MTX_MultVec33(&dir, (MtxFx33 *)m, &dir);
    VEC_Normalize(&dir, (&p->dir));
    Ov015FishState2c_UpdateWake(self);
    Ov015FishState2c_UpdateSwim(self);
}

BOOL func_ov015_0220ae90(Ov015FishState2c *self);

#ifdef NONMATCHING
// Status (round auA): demoted in the honesty audit. The match needed the pointer-bit trick (a second, never-taken
// definition of a local under if ((u32)self & 3)); this is the honest code without it. The score is in
// docs/UNMATCHED.md;
// the default build takes this function from the dsd gap. History: docs/MATCHING.md round auA.
BOOL func_ov015_0220ae90(Ov015FishState2c *self) {
    Ov015Fish *p = self->fish;
    s32 acc = p->info.unk_12;
    s32 dec = p->info.unk_20;
    Ov015Stat *st = &data_ov015_0221332c;
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
    v = p->info.unk_10 << 12;
    sp = p->info.unk_28;
    if (sp < 0xe10000) {
        lim = FX_Mul(v, 0x1000);
    } else if (sp < 0x1c20000) {
        lim = FX_Mul(v, 0xccd);
    } else {
        lim = FX_Mul(v, 0xb33);
    }
    if (self->unk_0c > lim) {
        self->unk_0c = lim;
    }
    p->info.unk_1c = self->unk_0c;
    return self->unk_0c <= 0;
}
#endif

}
