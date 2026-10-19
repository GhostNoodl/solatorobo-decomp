#include "ov015/ov015.h"

extern "C" {

void VEC_MultAdd(s32 scale, const Ov015Vec *dir, const Ov015Vec *base, Ov015Vec *out);
void VEC_Normalize(void *src, void *dst);
void func_02049244(Ov015Vec *a, s32 b, Ov015Vec *c, Ov015Vec *d, s32 e);
struct Ov015Mtx33 {
    s32 m[3][3];
};
void MTX_RotAxis33(Ov015Mtx33 *m, const Ov015Vec *v, s32 s, s32 c);
void MTX_MultVec33(const Ov015Vec *v, const Ov015Mtx33 *m, Ov015Vec *o);
void VEC_Add(const Ov015Vec *a, const Ov015Vec *b, Ov015Vec *o);

struct Ov015Persp {
    s32 n;
    s32 f;
    s16 fovySin;
    s16 fovyCos;
    s16 aspect;
    u16 fovyIdx;
    s32 fovyDeg;
    u8 pad_14[2];
    u8 dirty;
};

static inline void Ov015SetFovy(Ov015Persp *p, s32 deg) {
    u16 idx;
    p->fovyDeg = deg;
    p->fovyIdx = (u16)(((s64)p->fovyDeg * 0xb60b60b60bLL + 0x80000000000LL) >> 44);
    idx = (u16)(p->fovyIdx >> 1);
    p->fovySin = FX_SinCosTable_[(idx >> 4) * 2];
    p->fovyCos = FX_SinCosTable_[(idx >> 4) * 2 + 1];
    p->dirty = 1;
}

extern Ov015Vec data_ov015_022125cc;
extern Ov015Vec data_ov015_02212530;
extern Ov015Vec data_ov015_022125e4;
void func_ov015_021fd0f4(u8 *self, Ov015Vec *out);

static inline s32 Ov015Cam_Approach(s32 cur, s32 tgt, s32 eps, s32 k) {
    s32 df = tgt - cur;
    if ((df < 0 ? -df : df) > eps) {
        return cur + (s32)(((s64)df * k + 0x800) >> 12);
    }
    return cur;
}

void func_ov015_021fe218(u8 *self) {
    Ov015Vec p;
    Ov015Vec r;
    Ov015Mtx33 m;
    Ov015Vec c;
    Ov015Vec d2;
    Ov015Vec d;
    Ov015Vec o;
    Ov015Vec res;
    Ov015Vec up;
    Ov015Vec t;
    func_02049244(&FLD(Ov015Vec, self, 0x18c), 0x29, &FLD(Ov015Vec, self, 0x18c), &data_ov015_02212530, 0x29);
    FLD(s32, self, 0x198) = Ov015Cam_Approach(FLD(s32, self, 0x198), 0x4cd, 0x29, 0x7b);
    func_02049244(&FLD(Ov015Vec, self, 0x18c), 0x29, &FLD(Ov015Vec, self, 0x18c), &data_ov015_022125e4, 0x29);
    FLD(s32, self, 0x198) = Ov015Cam_Approach(FLD(s32, self, 0x198), 0x5a3d, 0x29, 0x7b);
    func_ov015_021fd0f4(self, &o);
    FLD(Ov015Vec, self, 0x14) = o;
    d.x = FLD(s32, self, 0x18c) - o.x;
    d.y = FLD(s32, self, 0x190) - o.y;
    d.z = FLD(s32, self, 0x194) - o.z;
    VEC_Normalize(&d, &d);
    VEC_MultAdd(FLD(s32, self, 0x198), &d, &FLD(Ov015Vec, self, 0x18c), &res);
    FLD(Ov015Vec, self, 0x8) = res;
    p = FLD(Ov015Vec, self, 0x8);
    t = FLD(Ov015Vec, self, 0x14);
    up = FLD(Ov015Vec, self, 0x20);
    FLD(Ov015Vec, self, 0xc4) = p;
    d2.x = t.x - p.x;
    d2.y = t.y - p.y;
    d2.z = t.z - p.z;
    VEC_Normalize(&d2, &d2);
    c.x = (s32)(((s64)d2.y * up.z - (s64)d2.z * up.y + 0x800) >> 12);
    c.y = (s32)(((s64)d2.z * up.x - (s64)d2.x * up.z + 0x800) >> 12);
    c.z = (s32)(((s64)d2.x * up.y - (s64)d2.y * up.x + 0x800) >> 12);
    VEC_Normalize(&c, &c);
    MTX_RotAxis33(&m, &c, FX_SinCosTable_[0xdfc * 2], FX_SinCosTable_[0xdfc * 2 + 1]);
    MTX_MultVec33(&d2, &m, &r);
    VEC_Add(&r, &p, &r);
    FLD(Ov015Vec, self, 0xd0) = r;
    Ov015SetFovy(&FLD(Ov015Persp, self, 0xe8), 0x1e000);
}

void func_ov015_021fe548(u8 *self) {
    Ov015Vec o;
    Ov015Vec res;
    Ov015Vec d;
    Ov015Vec d2;
    Ov015Vec c;
    Ov015Mtx33 m;
    Ov015Vec r;
    Ov015Vec p;
    Ov015Vec up;
    Ov015Vec t;
    func_02049244(&FLD(Ov015Vec, self, 0x18c), 0x29, &FLD(Ov015Vec, self, 0x18c), &data_ov015_022125cc, 0x29);
    FLD(s32, self, 0x198) = Ov015Cam_Approach(FLD(s32, self, 0x198), 0x5a3d, 0x29, 0x7b);
    func_ov015_021fd0f4(self, &o);
    FLD(Ov015Vec, self, 0x14) = o;
    d.x = FLD(s32, self, 0x18c) - o.x;
    d.y = FLD(s32, self, 0x190) - o.y;
    d.z = FLD(s32, self, 0x194) - o.z;
    VEC_Normalize(&d, &d);
    VEC_MultAdd(FLD(s32, self, 0x198), &d, &FLD(Ov015Vec, self, 0x18c), &res);
    FLD(Ov015Vec, self, 0x8) = res;
    p = FLD(Ov015Vec, self, 0x8);
    t = FLD(Ov015Vec, self, 0x14);
    up = FLD(Ov015Vec, self, 0x20);
    FLD(Ov015Vec, self, 0xc4) = p;
    d2.x = t.x - p.x;
    d2.y = t.y - p.y;
    d2.z = t.z - p.z;
    VEC_Normalize(&d2, &d2);
    c.x = (s32)(((s64)d2.y * up.z - (s64)d2.z * up.y + 0x800) >> 12);
    c.y = (s32)(((s64)d2.z * up.x - (s64)d2.x * up.z + 0x800) >> 12);
    c.z = (s32)(((s64)d2.x * up.y - (s64)d2.y * up.x + 0x800) >> 12);
    VEC_Normalize(&c, &c);
    MTX_RotAxis33(&m, &c, FX_SinCosTable_[0xdfc * 2], FX_SinCosTable_[0xdfc * 2 + 1]);
    MTX_MultVec33(&d2, &m, &r);
    VEC_Add(&r, &p, &r);
    FLD(Ov015Vec, self, 0xd0) = r;
    Ov015SetFovy(&FLD(Ov015Persp, self, 0xe8), 0x1e000);
}


void func_ov015_021fe814(u8 *self) {
    Ov015Vec a;
    Ov015Vec o;
    Ov015Vec res;
    Ov015Vec d;
    Ov015Vec d2;
    Ov015Vec c;
    Ov015Mtx33 m;
    Ov015Vec r;
    Ov015Vec p;
    Ov015Vec up;
    Ov015Vec t;
    a = FLD(Ov015Vec, self, 0x180);
    o = FLD(Ov015Vec, self, 0x14);
    func_02049244(&o, 0x19a, &o, &a, 0x29);
    FLD(Ov015Vec, self, 0x14) = o;
    d.x = FLD(s32, self, 0x18c) - o.x;
    d.y = FLD(s32, self, 0x190) - o.y;
    d.z = FLD(s32, self, 0x194) - o.z;
    VEC_Normalize(&d, &d);
    VEC_MultAdd(FLD(s32, self, 0x198), &d, &FLD(Ov015Vec, self, 0x18c), &res);
    FLD(Ov015Vec, self, 0x8) = res;
    {
        s32 deg = FLD(s32, self, 0x3c);
        Ov015SetFovy(&FLD(Ov015Persp, self, 0x2c), deg > 0xf000 ? deg - 0xc00 : 0xf000);
    }
    p = FLD(Ov015Vec, self, 0x8);
    t = FLD(Ov015Vec, self, 0x14);
    up = FLD(Ov015Vec, self, 0x20);
    FLD(Ov015Vec, self, 0xc4) = p;
    d2.x = t.x - p.x;
    d2.y = t.y - p.y;
    d2.z = t.z - p.z;
    VEC_Normalize(&d2, &d2);
    c.x = (s32)(((s64)d2.y * up.z - (s64)d2.z * up.y + 0x800) >> 12);
    c.y = (s32)(((s64)d2.z * up.x - (s64)d2.x * up.z + 0x800) >> 12);
    c.z = (s32)(((s64)d2.x * up.y - (s64)d2.y * up.x + 0x800) >> 12);
    VEC_Normalize(&c, &c);
    MTX_RotAxis33(&m, &c, FX_SinCosTable_[0xdfc * 2], FX_SinCosTable_[0xdfc * 2 + 1]);
    MTX_MultVec33(&d2, &m, &r);
    VEC_Add(&r, &p, &r);
    FLD(Ov015Vec, self, 0xd0) = r;
    Ov015SetFovy(&FLD(Ov015Persp, self, 0xe8), 0x1e000);
}

void func_ov015_021feb34(u8 *self) {
    Ov015Vec a;
    Ov015Vec o;
    Ov015Vec res;
    Ov015Vec d;
    Ov015Vec d2;
    Ov015Vec c;
    Ov015Mtx33 m;
    Ov015Vec r;
    Ov015Vec p;
    Ov015Vec up;
    Ov015Vec t;
    a = FLD(Ov015Vec, self, 0x180);
    o = FLD(Ov015Vec, self, 0x14);
    func_02049244(&o, 0x19a, &o, &a, 0x29);
    FLD(Ov015Vec, self, 0x14) = o;
    d.x = FLD(s32, self, 0x18c) - o.x;
    d.y = FLD(s32, self, 0x190) - o.y;
    d.z = FLD(s32, self, 0x194) - o.z;
    VEC_Normalize(&d, &d);
    VEC_MultAdd(FLD(s32, self, 0x198), &d, &FLD(Ov015Vec, self, 0x18c), &res);
    FLD(Ov015Vec, self, 0x8) = res;
    {
        s32 deg = FLD(s32, self, 0x3c);
        Ov015SetFovy(&FLD(Ov015Persp, self, 0x2c), deg < 0x1e000 ? deg + 0xc00 : 0x1e000);
    }
    p = FLD(Ov015Vec, self, 0x8);
    t = FLD(Ov015Vec, self, 0x14);
    up = FLD(Ov015Vec, self, 0x20);
    FLD(Ov015Vec, self, 0xc4) = p;
    d2.x = t.x - p.x;
    d2.y = t.y - p.y;
    d2.z = t.z - p.z;
    VEC_Normalize(&d2, &d2);
    c.x = (s32)(((s64)d2.y * up.z - (s64)d2.z * up.y + 0x800) >> 12);
    c.y = (s32)(((s64)d2.z * up.x - (s64)d2.x * up.z + 0x800) >> 12);
    c.z = (s32)(((s64)d2.x * up.y - (s64)d2.y * up.x + 0x800) >> 12);
    VEC_Normalize(&c, &c);
    MTX_RotAxis33(&m, &c, FX_SinCosTable_[0xdfc * 2], FX_SinCosTable_[0xdfc * 2 + 1]);
    MTX_MultVec33(&d2, &m, &r);
    VEC_Add(&r, &p, &r);
    FLD(Ov015Vec, self, 0xd0) = r;
    Ov015SetFovy(&FLD(Ov015Persp, self, 0xe8), 0x1e000);
}

}
