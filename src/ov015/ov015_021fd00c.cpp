#include "ov015/ov015.h"

extern "C" {

void func_ov015_021fb240(Ov015VecC *dst, const Ov015VecC *src);
void func_ov015_021fd288(u8 *self);
void func_ov015_021fd634(u8 *self);
void func_ov015_021fd900(void *self);
void func_ov015_021fe218(void *self);
void func_ov015_021fe548(void *self);
void func_ov015_021fe814(void *self);
void func_ov015_021feb34(void *self);
void func_ov015_021fee54(void *self);
void func_ov015_021ff044(void *self);
s32 FX_Div(s32 a, s32 b);
extern u8 data_ov015_0221253c[];
s32 VEC_Mag(const Ov015Vec *v);
void VEC_MultAdd(s32 scale, const Ov015Vec *dir, const Ov015Vec *base, Ov015Vec *out);
void VEC_Add(const void *a, const void *b, void *out);
void VEC_Normalize(void *src, void *dst);

void func_ov015_021fd00c(u8 *self, s32 mode, const Ov015VecC *v) {
    if (FLD(s32, self, 0x17c) != mode) {
        if (mode == 2) {
            FLD(s32, self, 0x19c) = 0x78;
        } else if (mode == 3) {
            FLD(s32, self, 0x19c) = 0xf0;
        } else {
            FLD(s32, self, 0x19c) = 0;
        }
    }
    FLD(s32, self, 0x17c) = mode;
    func_ov015_021fb240((Ov015VecC *)(self + 0x180), v);
    switch (mode) {
    case 1:
        func_ov015_021fd288(self);
        break;
    case 0:
        func_ov015_021fd634(self);
        break;
    case 2:
        func_ov015_021fd900(self);
        break;
    case 3:
        func_ov015_021fe218(self);
        break;
    case 4:
        func_ov015_021fe548(self);
        break;
    case 5:
        func_ov015_021fe814(self);
        break;
    case 6:
        func_ov015_021feb34(self);
        break;
    case 7:
        func_ov015_021fee54(self);
        break;
    case 8:
        func_ov015_021ff044(self);
        break;
    }
}

void func_ov015_021fd0f4(u8 *self, Ov015Vec *out) {
    Ov015Vec a = FLD(Ov015Vec, self, 0x8);
    Ov015Vec b = FLD(Ov015Vec, self, 0x14);
    s32 lim = FX_SinCosTable_[0x71];
    Ov015Vec e;
    Ov015Vec c;
    Ov015Vec d;

    Ov015Vec f;
    s32 ld, le, dot, r;
    VEC_Add(self + 0x180, data_ov015_0221253c, &c);
    d.x = c.x - a.x;
    d.y = c.y - a.y;
    d.z = c.z - a.z;
    ld = VEC_Mag(&d);
    e.x = b.x - a.x;
    e.y = b.y - a.y;
    e.z = b.z - a.z;
    le = VEC_Mag(&e);
    dot = (s32)(((s64)e.x * d.x + (s64)e.y * d.y + (s64)e.z * d.z + 0x800) >> 12);
    r = FX_Div(dot, Ov015_FxMul(ld, le));
    if (r < 0) r = -r;
    if (r >= lim) {
        *out = b;
        return;
    }
    f.x = d.x - e.x;
    f.y = d.y - e.y;
    f.z = d.z - e.z;
    VEC_MultAdd(0x52, &f, &e, &e);
    VEC_Normalize(&e, &e);
    VEC_MultAdd(ld, &e, &a, out);
}


void func_02049244(Ov015Vec *a, s32 b, Ov015Vec *c, Ov015Vec *d, s32 e);
struct Ov015Mtx33 {
    s32 m[3][3];
};
void MTX_RotAxis33(Ov015Mtx33 *m, const Ov015Vec *v, s32 s, s32 c);
void MTX_MultVec33(const Ov015Vec *v, const Ov015Mtx33 *m, Ov015Vec *o);

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

extern Ov015Vec data_ov015_022125e4;

static inline s32 Ov015Cam_Approach(s32 cur, s32 tgt, s32 eps, s32 k) {
    s32 df = tgt - cur;
    if ((df < 0 ? -df : df) > eps) {
        return cur + (s32)(((s64)df * k + 0x800) >> 12);
    }
    return cur;
}

void func_ov015_021fd288(u8 *self) {
    Ov015Vec cam;
    Ov015Vec tgt;
    Ov015Vec res;
    Ov015Vec a;
    Ov015Vec dd;
    Ov015Vec w;
    Ov015Vec q;
    Ov015Vec r;
    Ov015Vec d;
    Ov015Mtx33 m;
    Ov015Vec c;
    Ov015Vec d2;
    Ov015Vec up;
    cam = FLD(Ov015Vec, self, 0x8);
    tgt = FLD(Ov015Vec, self, 0x14);
    a = FLD(Ov015Vec, self, 0x180);
    VEC_Add(data_ov015_0221253c, &a, &a);
    d.x = FLD(s32, self, 0x18c) - a.x;
    d.y = FLD(s32, self, 0x190) - a.y;
    d.z = FLD(s32, self, 0x194) - a.z;
    VEC_Normalize(&d, &d);
    VEC_MultAdd(FLD(s32, self, 0x198), &d, &FLD(Ov015Vec, self, 0x18c), &res);
    dd.x = res.x - cam.x;
    dd.y = res.y - cam.y;
    dd.z = res.z - cam.z;
    VEC_MultAdd(0xa4, &dd, &cam, &cam);
    dd.x = a.x - tgt.x;
    dd.y = a.y - tgt.y;
    dd.z = a.z - tgt.z;
    VEC_MultAdd(0xa4, &dd, &tgt, &tgt);
    FLD(Ov015Vec, self, 0x8) = cam;
    up = FLD(Ov015Vec, self, 0x20);
    FLD(Ov015Vec, self, 0x14) = tgt;
    FLD(Ov015Vec, self, 0xdc) = up;
    q = FLD(Ov015Vec, self, 0xc4);
    func_02049244(&q, 0x148, &q, &res, 0);
    FLD(Ov015Vec, self, 0xc4) = q;
    d2.x = a.x - res.x;
    d2.y = a.y - res.y;
    d2.z = a.z - res.z;
    VEC_Normalize(&d2, &d2);
    c.x = (s32)(((s64)d2.y * up.z - (s64)d2.z * up.y + 0x800) >> 12);
    c.y = (s32)(((s64)d2.z * up.x - (s64)d2.x * up.z + 0x800) >> 12);
    c.z = (s32)(((s64)d2.x * up.y - (s64)d2.y * up.x + 0x800) >> 12);
    VEC_Normalize(&c, &c);
    MTX_RotAxis33(&m, &c, FX_SinCosTable_[0xdfc * 2], FX_SinCosTable_[0xdfc * 2 + 1]);
    MTX_MultVec33(&d2, &m, &r);
    VEC_Add(&r, &res, &r);
    w = FLD(Ov015Vec, self, 0xd0);
    func_02049244(&w, 0x148, &w, &r, 0);
    FLD(Ov015Vec, self, 0xd0) = w;
    Ov015SetFovy(&FLD(Ov015Persp, self, 0xe8), 0x1e000);
}

void func_ov015_021fd634(u8 *self) {
    Ov015Vec res;
    Ov015Vec o;
    Ov015Vec d;
    Ov015Vec d2;
    Ov015Vec c;
    Ov015Mtx33 m;
    Ov015Vec r;
    Ov015Vec p;
    Ov015Vec up;
    Ov015Vec t;
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

}
