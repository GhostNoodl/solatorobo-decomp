#include "ov015/ov015.h"

extern "C" {

u8 *func_02066774(void *a, void *b, int c, void *d);
extern u8 data_ov015_02212e20[];
extern u8 data_ov015_02212e34[];
struct Ov015Blk0afcc { s32 w[3]; };
extern const Ov015Blk0afcc data_ov015_02212650;

#define Ov015_Dot0afcc(a, b) ((s32)(((s64)(a)->x * (b)->x + (s64)(a)->y * (b)->y + (s64)(a)->z * (b)->z + 0x800) >> 12))
void func_ov015_0220afcc(Ov015FishState2c *self) {
    Ov015Vec v;
    Ov015Vec dir;
    Ov015Vec base;
    Ov015Vec sc;
    u16 ang;
    Ov015V *e = func_020657b0(data_0214a420, self->unk_24);
    if (e == NULL) {
        e = (Ov015V *)func_02066774(data_ov015_02212e20, data_ov015_02212e34, 0, &self->fish->pos);
        FLD(s32, e, 0xd4) = 1;
        FLD(u8, e, 0x28) = 0;
        FLD(s32, e, 0xc8) = -1;
        FLD(s32, e, 0x50) = -0xc8000;
        self->unk_24 = FLD(void *, e, 0x24);
    }
    {
        Ov015Fish *o = self->fish;
        v.x = o->pos.x;
        v.y = o->pos.y > 0 ? 0 : o->pos.y;
        v.z = o->pos.z;
        v.y = v.y < -0x2000 ? -0x2000 : v.y;
    }
    e->v18(&v);
    *(Ov015Blk0afcc *)&base = data_ov015_02212650;
    dir = (self->fish)->dir;
    dir.y = 0;
    VEC_Normalize((VecFx32 *)&dir, (VecFx32 *)&dir);
    ang = FX_AcosIdx(Ov015_Dot0afcc(&dir, &base));
    if (dir.x < 0) ang = 0xffff - ang;
    e->v34(0, ang, 0);
    {
        Ov015Fish *o = self->fish;
        s32 s = o->scaleMul;
        sc.x = FX_Mul(o->scaleX, s);
        sc.y = FX_Mul(o->scaleY, s);
        sc.z = FX_Mul(o->scaleZ, s);
        e->v10(&sc);
    }
}

Ov015V *func_02065f88(s32 id, void *pos);
void func_02065860(void *a, void *b);
s32 Rand_PlusMinus(s32 n);
BOOL func_ov000_02190cb0(void *a, const void *b, s32 c, s32 d);
void func_ov000_021915a0(void *a);
extern u8 data_ov015_02212e40[];
extern u8 data_ov015_02212e0d[];

static inline void Ov015_Spark(Ov015Vec *a, Ov015Vec *s) {
    Ov015V *e = func_02065f88(0x44d, a);
    u16 rr;
    e->v10(s);
    FLD(s32, e, 0x50) = -0xa000;
    FLD(s32, e, 0xd4) = 1;
    FLD(u8, e, 0x28) = 3;
    rr = Rand_PlusMinus(0xfff);
    e->v34(0, 0, rr);
}

void func_ov015_0220b1b8(Ov015FishState2c *self) {
    s32 r;
    s32 lim;
    s32 v;
    s32 tgt;
    s32 d;
    s32 ad;
    s32 px;
    s32 pz;
    s32 py;
    Ov015Fish *p = self->fish;
    v = p->info.unk_10 << 12;
    if (p->info.unk_28 < 0xe10000) {
        lim = FX_Mul(v, 0x1000);
    } else if (p->info.unk_28 < 0x1c20000) {
        lim = FX_Mul(v, 0xccd);
    } else {
        lim = FX_Mul(v, 0xb33);
    }
    if (lim > 0) {
        r = FX_Div(self->unk_0c, lim);
    } else {
        r = 0;
    }
    {
        Ov015Fish *o = self->fish;
        px = o->pos.x;
        py = o->pos.y;
        pz = o->pos.z;
    }
    if (r > 0x99a) {
        FX_Div(r - 0x99a, 0x666);
        tgt = FX_Mul(r, -0x13ccd) + 0x1ccd;
    } else {
        tgt = 0x1ccd;
    }
    d = tgt - py;
    ad = d < 0 ? -d : d;
    py = ad > 0x4cd ? py + (s32)(((s64)d * 0x4cdLL + 0x800LL) >> 12) : py;

    {
        Ov015Fish *o = self->fish;
        o->pos.x = px;
        o->pos.y = py;
        o->pos.z = pz;
    }
    if (r < 0x99a) {
        Ov015Vec a;
        Ov015Vec s;
        Ov015Fish *o = self->fish;
        a = o->pos;
        a.z += FX_Mul(o->scaleX, 0xc000);
        a.y -= 0x4000;
        s.x = 0x1333;
        s.y = 0x1333;
        s.z = 0x1333;
        if (r > 0x4cd) {
            if (self->unk_06 % 30 == 0) {
                Ov015_Spark(&a, &s);
            }
        } else {
            if (self->unk_06 % 10 == 0) {
                Ov015_Spark(&a, &s);
            }
        }
    }
    if (r < 0x4cd) {
        Ov015Vec b;
        Ov015V *e;
        Ov015Fish *o = self->fish;
        b = o->pos;
        b.y += 0x8000;
        b.z += FX_Mul(o->scaleX, 0xc000);
        e = func_020657b0(data_0214a420, self->unk_28);
        if (e == NULL) {
            e = func_02065f88(0x325, &b);
            FLD(s32, e, 0xd4) = 1;
            FLD(s32, e, 0xc8) = -2;
            e->v34(0xbffd, 0, 0);
            e->v0c(0x5000);
            FLD(s32, e, 0x50) = -0xc8000;
            self->unk_28 = FLD(void *, e, 0x24);
        }
        e->v18(&b);
    } else {
        func_02065860(data_0214a420, self->unk_28);
    }
    if (((u8)self->unk_14)) {
        func_ov000_02190cb0(&self->fish->model, data_ov015_02212e40, 0x19a, 0);
        func_ov000_021915a0(&self->fish->model);
        (self->fish)->animSpeed = FX_Mul(r, 0x4cc) + 0x19a;
    } else {
        func_ov000_02190cb0(&self->fish->model, data_ov015_02212e0d, 0x19a, 0);
        func_ov000_021915a0(&self->fish->model);
        (self->fish)->animSpeed = 0x99a;
    }
}

}
