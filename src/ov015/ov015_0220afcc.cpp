#include "ov015/ov015.h"

extern "C" {

extern char data_ov015_02212e20[];
extern char data_ov015_02212e34[];
struct Ov015Blk0afcc { s32 w[3]; };
extern const Ov015Blk0afcc data_ov015_02212650;

#define Ov015_Dot0afcc(a, b) ((s32)(((s64)(a)->x * (b)->x + (s64)(a)->y * (b)->y + (s64)(a)->z * (b)->z + 0x800) >> 12))
void func_ov015_0220afcc(Ov015FishState2c *self) {
    Ov015Vec v;
    Ov015Vec dir;
    Ov015Vec base;
    Ov015Vec sc;
    u16 ang;
    EffectObj *e = Effect_Find_020657b0(gEffectMgr, self->unk_24);
    if (e == NULL) {
        e = Effect3D_Create(data_ov015_02212e20, data_ov015_02212e34, 0, &self->fish->pos);
        e->unk_d4 = 1;
        e->unk_28 = 0;
        e->loopCount = -1;
        e->unk_50 = -0xc8000;
        self->unk_24 = e->id;
    }
    {
        Ov015Fish *o = self->fish;
        v.x = o->pos.x;
        v.y = o->pos.y > 0 ? 0 : o->pos.y;
        v.z = o->pos.z;
        v.y = v.y < -0x2000 ? -0x2000 : v.y;
    }
    e->SetPos(&v);
    *(Ov015Blk0afcc *)&base = data_ov015_02212650;
    dir = (self->fish)->dir;
    dir.y = 0;
    VEC_Normalize(&dir, &dir);
    ang = FX_AcosIdx(Ov015_Dot0afcc(&dir, &base));
    if (dir.x < 0) ang = 0xffff - ang;
    e->SetRotXYZ(0, ang, 0);
    {
        Ov015Fish *o = self->fish;
        s32 s = o->scaleMul;
        sc.x = FX_Mul(o->scale.x, s);
        sc.y = FX_Mul(o->scale.y, s);
        sc.z = FX_Mul(o->scale.z, s);
        e->SetScale(&sc);
    }
}

s32 Rand_PlusMinus(s32 n);
BOOL Model0218fe1c_SetAnim(void *a, const void *b, s32 c, s32 d);
void Model0218fe1c_SetLoop(void *a);
extern u8 data_ov015_02212e40[];
extern u8 data_ov015_02212e0d[];

static inline void Ov015_Spark(Ov015Vec *a, Ov015Vec *s) {
    EffectObj *e = Effect_SpawnId(0x44d, a);
    u16 rr;
    e->SetScale(s);
    e->unk_50 = -0xa000;
    e->unk_d4 = 1;
    e->unk_28 = 3;
    rr = Rand_PlusMinus(0xfff);
    e->SetRotXYZ(0, 0, rr);
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
        a.z += FX_Mul(o->scale.x, 0xc000);
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
        EffectObj *e;
        Ov015Fish *o = self->fish;
        b = o->pos;
        b.y += 0x8000;
        b.z += FX_Mul(o->scale.x, 0xc000);
        e = Effect_Find_020657b0(gEffectMgr, self->unk_28);
        if (e == NULL) {
            e = Effect_SpawnId(0x325, &b);
            e->unk_d4 = 1;
            e->loopCount = -2;
            e->SetRotXYZ(0xbffd, 0, 0);
            e->SetScaleAll(0x5000);
            e->unk_50 = -0xc8000;
            self->unk_28 = e->id;
        }
        e->SetPos(&b);
    } else {
        EffectMgr_StopLoop(gEffectMgr, self->unk_28);
    }
    if (((u8)self->unk_14)) {
        Model0218fe1c_SetAnim(&self->fish->model, data_ov015_02212e40, 0x19a, 0);
        Model0218fe1c_SetLoop(&self->fish->model);
        (self->fish)->animSpeed = FX_Mul(r, 0x4cc) + 0x19a;
    } else {
        Model0218fe1c_SetAnim(&self->fish->model, data_ov015_02212e0d, 0x19a, 0);
        Model0218fe1c_SetLoop(&self->fish->model);
        (self->fish)->animSpeed = 0x99a;
    }
}

}
