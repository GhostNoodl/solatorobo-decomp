#include "ov015/ov015.h"

extern "C" {

u8 *func_02066774(void *a, void *b, int c, void *d);
extern u8 data_ov015_02212e20[];
extern u8 data_ov015_02212e34[];
struct Ov015Blk0afcc { s32 w[3]; };
extern const Ov015Blk0afcc data_ov015_02212650;
void VEC_Normalize(void *src, void *dst);
u16 FX_AcosIdx(s32 x);

#define Ov015_Dot0afcc(a, b) ((s32)(((s64)(a)->x * (b)->x + (s64)(a)->y * (b)->y + (s64)(a)->z * (b)->z + 0x800) >> 12))
void func_ov015_0220afcc(u8 *self) {
    Ov015Vec v;
    Ov015Vec dir;
    Ov015Vec base;
    Ov015Vec sc;
    u16 ang;
    Ov015V *e = func_020657b0(data_0214a420, FLD(void *, self, 0x24));
    if (e == NULL) {
        e = (Ov015V *)func_02066774(data_ov015_02212e20, data_ov015_02212e34, 0, &FLD(Ov015Fish *, self, 0x20)->unk_40);
        FLD(s32, e, 0xd4) = 1;
        FLD(u8, e, 0x28) = 0;
        FLD(s32, e, 0xc8) = -1;
        FLD(s32, e, 0x50) = -0xc8000;
        FLD(void *, self, 0x24) = FLD(void *, e, 0x24);
    }
    {
        Ov015Fish *o = FLD(Ov015Fish *, self, 0x20);
        v.x = o->unk_40.x;
        v.y = o->unk_40.y > 0 ? 0 : o->unk_40.y;
        v.z = o->unk_40.z;
        v.y = v.y < -0x2000 ? -0x2000 : v.y;
    }
    e->v18(&v);
    *(Ov015Blk0afcc *)&base = data_ov015_02212650;
    dir = (FLD(Ov015Fish *, self, 0x20))->unk_9c;
    dir.y = 0;
    VEC_Normalize(&dir, &dir);
    ang = FX_AcosIdx(Ov015_Dot0afcc(&dir, &base));
    if (dir.x < 0) ang = 0xffff - ang;
    e->v34(0, ang, 0);
    {
        Ov015Fish *o = FLD(Ov015Fish *, self, 0x20);
        s32 s = o->unk_7c;
        sc.x = Ov015_FxMul(o->unk_70, s);
        sc.y = Ov015_FxMul(o->unk_74, s);
        sc.z = Ov015_FxMul(o->unk_78, s);
        e->v10(&sc);
    }
}

s32 FX_Div(s32 a, s32 b);
Ov015V *func_02065f88(s32 id, void *pos);
void func_02065860(void *a, void *b);
s32 func_02040528(s32 n);
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
    rr = func_02040528(0xfff);
    e->v34(0, 0, rr);
}

void func_ov015_0220b1b8(u8 *self) {
    s32 r;
    s32 lim;
    s32 v;
    s32 tgt;
    s32 d;
    s32 ad;
    s32 px;
    s32 pz;
    s32 py;
    Ov015Fish *p = FLD(Ov015Fish *, self, 0x20);
    v = FLD(u16, p, 0xd0) << 12;
    if (FLD(s32, p, 0xe8) < 0xe10000) {
        lim = Ov015_FxMul(v, 0x1000);
    } else if (FLD(s32, p, 0xe8) < 0x1c20000) {
        lim = Ov015_FxMul(v, 0xccd);
    } else {
        lim = Ov015_FxMul(v, 0xb33);
    }
    if (lim > 0) {
        r = FX_Div(FLD(s32, self, 0xc), lim);
    } else {
        r = 0;
    }
    {
        Ov015Fish *o = FLD(Ov015Fish *, self, 0x20);
        px = o->unk_40.x;
        py = o->unk_40.y;
        pz = o->unk_40.z;
    }
    if (r > 0x99a) {
        FX_Div(r - 0x99a, 0x666);
        tgt = Ov015_FxMul(r, -0x13ccd) + 0x1ccd;
    } else {
        tgt = 0x1ccd;
    }
    d = tgt - py;
    ad = d < 0 ? -d : d;
    py = ad > 0x4cd ? py + (s32)(((s64)d * 0x4cdLL + 0x800LL) >> 12) : py;

    {
        Ov015Fish *o = FLD(Ov015Fish *, self, 0x20);
        o->unk_40.x = px;
        o->unk_40.y = py;
        o->unk_40.z = pz;
    }
    if (r < 0x99a) {
        Ov015Vec a;
        Ov015Vec s;
        Ov015Fish *o = FLD(Ov015Fish *, self, 0x20);
        a = o->unk_40;
        a.z += Ov015_FxMul(o->unk_70, 0xc000);
        a.y -= 0x4000;
        s.x = 0x1333;
        s.y = 0x1333;
        s.z = 0x1333;
        if (r > 0x4cd) {
            if (FLD(s16, self, 6) % 30 == 0) {
                Ov015_Spark(&a, &s);
            }
        } else {
            if (FLD(s16, self, 6) % 10 == 0) {
                Ov015_Spark(&a, &s);
            }
        }
    }
    if (r < 0x4cd) {
        Ov015Vec b;
        Ov015V *e;
        Ov015Fish *o = FLD(Ov015Fish *, self, 0x20);
        b = o->unk_40;
        b.y += 0x8000;
        b.z += Ov015_FxMul(o->unk_70, 0xc000);
        e = func_020657b0(data_0214a420, FLD(void *, self, 0x28));
        if (e == NULL) {
            e = func_02065f88(0x325, &b);
            FLD(s32, e, 0xd4) = 1;
            FLD(s32, e, 0xc8) = -2;
            e->v34(0xbffd, 0, 0);
            e->v0c(0x5000);
            FLD(s32, e, 0x50) = -0xc8000;
            FLD(void *, self, 0x28) = FLD(void *, e, 0x24);
        }
        e->v18(&b);
    } else {
        func_02065860(data_0214a420, FLD(void *, self, 0x28));
    }
    if (FLD(u8, self, 0x14)) {
        func_ov000_02190cb0(&FLD(Ov015Fish *, self, 0x20)->unk_244, data_ov015_02212e40, 0x19a, 0);
        func_ov000_021915a0(&FLD(Ov015Fish *, self, 0x20)->unk_244);
        (FLD(Ov015Fish *, self, 0x20))->unk_104 = Ov015_FxMul(r, 0x4cc) + 0x19a;
    } else {
        func_ov000_02190cb0(&FLD(Ov015Fish *, self, 0x20)->unk_244, data_ov015_02212e0d, 0x19a, 0);
        func_ov000_021915a0(&FLD(Ov015Fish *, self, 0x20)->unk_244);
        (FLD(Ov015Fish *, self, 0x20))->unk_104 = 0x99a;
    }
}

}
