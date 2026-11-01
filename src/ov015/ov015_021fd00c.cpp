// func_ov015_021fd900 inlines three full camera bodies. With the default inline size limit,
// MWCC stops inlining the Ov015Vec constructors and copies inside them.
#pragma inline_max_size(512)

#include "ov015/ov015.h"

extern "C" {

void func_ov015_021fb240(Ov015VecC *dst, const Ov015VecC *src);
void func_ov015_021fd288(Ov015CamPair *self);
void func_ov015_021fd634(Ov015CamPair *self);
void func_ov015_021fd900(Ov015CamPair *self);
void func_ov015_021fe218(Ov015CamPair *self);
void func_ov015_021fe548(Ov015CamPair *self);
void func_ov015_021fe814(Ov015CamPair *self);
void func_ov015_021feb34(Ov015CamPair *self);
void func_ov015_021fee54(Ov015CamPair *self);
void func_ov015_021ff044(Ov015CamPair *self);
s32 FX_Div(s32 a, s32 b);
extern u8 data_ov015_0221253c[];
s32 VEC_Mag(const Ov015Vec *v);
void VEC_MultAdd(s32 scale, const Ov015Vec *dir, const Ov015Vec *base, Ov015Vec *out);
void VEC_Add(const void *a, const void *b, void *out);
void VEC_Normalize(void *src, void *dst);

void func_ov015_021fd00c(Ov015CamPair *self, s32 mode, const Ov015VecC *v) {
    if (self->unk_17c != mode) {
        if (mode == 2) {
            self->unk_19c = 0x78;
        } else if (mode == 3) {
            self->unk_19c = 0xf0;
        } else {
            self->unk_19c = 0;
        }
    }
    self->unk_17c = mode;
    func_ov015_021fb240((Ov015VecC *)&self->unk_180, v);
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

void func_ov015_021fd0f4(Ov015CamPair *self, Ov015Vec *out) {
    Ov015Vec a = self->cam0.pos;
    Ov015Vec b = self->cam0.at;
    s32 lim = FX_SinCosTable_[0x71];
    Ov015Vec e;
    Ov015Vec c;
    Ov015Vec d;

    Ov015Vec f;
    s32 ld, le, dot, r;
    VEC_Add(&self->unk_180, data_ov015_0221253c, &c);
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


BOOL func_02049244(Ov015Vec *a, s32 b, Ov015Vec *c, Ov015Vec *d, s32 e);
void MTX_RotAxis33(Ov015Mtx33 *m, const Ov015Vec *v, s32 s, s32 c);
void MTX_MultVec33(const Ov015Vec *v, const Ov015Mtx33 *m, Ov015Vec *o);

static inline void Ov015SetFovy(Ov015Cam *p, s32 deg) {
    u16 idx;
    p->fovyDeg = deg;
    p->fovy = (u16)(((s64)p->fovyDeg * 0xb60b60b60bLL + 0x80000000000LL) >> 44);
    idx = (u16)(p->fovy >> 1);
    p->fovySin = FX_SinCosTable_[(idx >> 4) * 2];
    p->fovyCos = FX_SinCosTable_[(idx >> 4) * 2 + 1];
    p->dirty = 1;
}

extern Ov015Vec data_ov015_022125cc;
extern Ov015Vec data_ov015_02212530;
extern Ov015Vec data_ov015_022125e4;

static inline s32 Ov015Cam_Approach(s32 cur, s32 tgt, s32 eps, s32 k) {
    s32 df = tgt - cur;
    if ((df < 0 ? -df : df) > eps) {
        return cur + (s32)(((s64)df * k + 0x800) >> 12);
    }
    return cur;
}

void func_ov015_021fd288(Ov015CamPair *self) {
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
    cam = self->cam0.pos;
    tgt = self->cam0.at;
    a = self->unk_180;
    VEC_Add(data_ov015_0221253c, &a, &a);
    d.x = self->unk_18c.x - a.x;
    d.y = self->unk_18c.y - a.y;
    d.z = self->unk_18c.z - a.z;
    VEC_Normalize(&d, &d);
    VEC_MultAdd(self->unk_198, &d, &self->unk_18c, &res);
    dd.x = res.x - cam.x;
    dd.y = res.y - cam.y;
    dd.z = res.z - cam.z;
    VEC_MultAdd(0xa4, &dd, &cam, &cam);
    dd.x = a.x - tgt.x;
    dd.y = a.y - tgt.y;
    dd.z = a.z - tgt.z;
    VEC_MultAdd(0xa4, &dd, &tgt, &tgt);
    self->cam0.pos = cam;
    up = self->cam0.up;
    self->cam0.at = tgt;
    self->cam1.up = up;
    q = self->cam1.pos;
    func_02049244(&q, 0x148, &q, &res, 0);
    self->cam1.pos = q;
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
    w = self->cam1.at;
    func_02049244(&w, 0x148, &w, &r, 0);
    self->cam1.at = w;
    Ov015SetFovy(&self->cam1, 0x1e000);
}

void func_ov015_021fd634(Ov015CamPair *self) {
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
    func_02049244(&self->unk_18c, 0x29, &self->unk_18c, &data_ov015_022125e4, 0x29);
    self->unk_198 = Ov015Cam_Approach(self->unk_198, 0x5a3d, 0x29, 0x7b);
    func_ov015_021fd0f4(self, &o);
    self->cam0.at = o;
    d.x = self->unk_18c.x - o.x;
    d.y = self->unk_18c.y - o.y;
    d.z = self->unk_18c.z - o.z;
    VEC_Normalize(&d, &d);
    VEC_MultAdd(self->unk_198, &d, &self->unk_18c, &res);
    self->cam0.pos = res;
    p = self->cam0.pos;
    t = self->cam0.at;
    up = self->cam0.up;
    self->cam1.pos = p;
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
    self->cam1.at = r;
    Ov015SetFovy(&self->cam1, 0x1e000);
}

static inline void Ov015Cam_ZoomOut(Ov015CamPair *self) {
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
    a = self->unk_180;
    o = self->cam0.at;
    func_02049244(&o, 0x19a, &o, &a, 0x29);
    self->cam0.at = o;
    d.x = self->unk_18c.x - o.x;
    d.y = self->unk_18c.y - o.y;
    d.z = self->unk_18c.z - o.z;
    VEC_Normalize(&d, &d);
    VEC_MultAdd(self->unk_198, &d, &self->unk_18c, &res);
    self->cam0.pos = res;
    {
        s32 deg = self->cam0.fovyDeg;
        Ov015SetFovy(&self->cam0, deg > 0xf000 ? deg - 0xc00 : 0xf000);
    }
    p = self->cam0.pos;
    t = self->cam0.at;
    up = self->cam0.up;
    self->cam1.pos = p;
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
    self->cam1.at = r;
    Ov015SetFovy(&self->cam1, 0x1e000);
}

static inline void Ov015Cam_Follow(Ov015CamPair *self) {
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
    func_02049244(&self->unk_18c, 0x29, &self->unk_18c, &data_ov015_022125e4, 0x29);
    self->unk_198 = Ov015Cam_Approach(self->unk_198, 0x5a3d, 0x29, 0x7b);
    func_ov015_021fd0f4(self, &o);
    self->cam0.at = o;
    d.x = self->unk_18c.x - o.x;
    d.y = self->unk_18c.y - o.y;
    d.z = self->unk_18c.z - o.z;
    VEC_Normalize(&d, &d);
    VEC_MultAdd(self->unk_198, &d, &self->unk_18c, &res);
    self->cam0.pos = res;
    p = self->cam0.pos;
    t = self->cam0.at;
    up = self->cam0.up;
    self->cam1.pos = p;
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
    self->cam1.at = r;
    Ov015SetFovy(&self->cam1, 0x1e000);
}

static inline void Ov015Cam_ZoomIn(Ov015CamPair *self) {
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
    a = self->unk_180;
    o = self->cam0.at;
    func_02049244(&o, 0x19a, &o, &a, 0x29);
    self->cam0.at = o;
    d.x = self->unk_18c.x - o.x;
    d.y = self->unk_18c.y - o.y;
    d.z = self->unk_18c.z - o.z;
    VEC_Normalize(&d, &d);
    VEC_MultAdd(self->unk_198, &d, &self->unk_18c, &res);
    self->cam0.pos = res;
    {
        s32 deg = self->cam0.fovyDeg;
        Ov015SetFovy(&self->cam0, deg < 0x1e000 ? deg + 0xc00 : 0x1e000);
    }
    p = self->cam0.pos;
    t = self->cam0.at;
    up = self->cam0.up;
    self->cam1.pos = p;
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
    self->cam1.at = r;
    Ov015SetFovy(&self->cam1, 0x1e000);
}

void func_ov015_021fd900(Ov015CamPair *self) {
    if (self->unk_19c > 0x1e) {
        if (data_ov015_0221332c.unk_00 > 0xfa000) {
            Ov015Cam_ZoomOut(self);
        } else {
            Ov015Cam_Follow(self);
        }
    } else {
        Ov015Cam_ZoomIn(self);
    }
    self->unk_19c--;
    if (self->unk_19c < 0) {
        self->unk_19c = 0;
    }
}

void func_ov015_021fe218(Ov015CamPair *self) {
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
    func_02049244(&self->unk_18c, 0x29, &self->unk_18c, &data_ov015_02212530, 0x29);
    self->unk_198 = Ov015Cam_Approach(self->unk_198, 0x4cd, 0x29, 0x7b);
    func_02049244(&self->unk_18c, 0x29, &self->unk_18c, &data_ov015_022125e4, 0x29);
    self->unk_198 = Ov015Cam_Approach(self->unk_198, 0x5a3d, 0x29, 0x7b);
    func_ov015_021fd0f4(self, &o);
    self->cam0.at = o;
    d.x = self->unk_18c.x - o.x;
    d.y = self->unk_18c.y - o.y;
    d.z = self->unk_18c.z - o.z;
    VEC_Normalize(&d, &d);
    VEC_MultAdd(self->unk_198, &d, &self->unk_18c, &res);
    self->cam0.pos = res;
    p = self->cam0.pos;
    t = self->cam0.at;
    up = self->cam0.up;
    self->cam1.pos = p;
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
    self->cam1.at = r;
    Ov015SetFovy(&self->cam1, 0x1e000);
}

void func_ov015_021fe548(Ov015CamPair *self) {
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
    func_02049244(&self->unk_18c, 0x29, &self->unk_18c, &data_ov015_022125cc, 0x29);
    self->unk_198 = Ov015Cam_Approach(self->unk_198, 0x5a3d, 0x29, 0x7b);
    func_ov015_021fd0f4(self, &o);
    self->cam0.at = o;
    d.x = self->unk_18c.x - o.x;
    d.y = self->unk_18c.y - o.y;
    d.z = self->unk_18c.z - o.z;
    VEC_Normalize(&d, &d);
    VEC_MultAdd(self->unk_198, &d, &self->unk_18c, &res);
    self->cam0.pos = res;
    p = self->cam0.pos;
    t = self->cam0.at;
    up = self->cam0.up;
    self->cam1.pos = p;
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
    self->cam1.at = r;
    Ov015SetFovy(&self->cam1, 0x1e000);
}


void func_ov015_021fe814(Ov015CamPair *self) {
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
    a = self->unk_180;
    o = self->cam0.at;
    func_02049244(&o, 0x19a, &o, &a, 0x29);
    self->cam0.at = o;
    d.x = self->unk_18c.x - o.x;
    d.y = self->unk_18c.y - o.y;
    d.z = self->unk_18c.z - o.z;
    VEC_Normalize(&d, &d);
    VEC_MultAdd(self->unk_198, &d, &self->unk_18c, &res);
    self->cam0.pos = res;
    {
        s32 deg = self->cam0.fovyDeg;
        Ov015SetFovy(&self->cam0, deg > 0xf000 ? deg - 0xc00 : 0xf000);
    }
    p = self->cam0.pos;
    t = self->cam0.at;
    up = self->cam0.up;
    self->cam1.pos = p;
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
    self->cam1.at = r;
    Ov015SetFovy(&self->cam1, 0x1e000);
}

void func_ov015_021feb34(Ov015CamPair *self) {
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
    a = self->unk_180;
    o = self->cam0.at;
    func_02049244(&o, 0x19a, &o, &a, 0x29);
    self->cam0.at = o;
    d.x = self->unk_18c.x - o.x;
    d.y = self->unk_18c.y - o.y;
    d.z = self->unk_18c.z - o.z;
    VEC_Normalize(&d, &d);
    VEC_MultAdd(self->unk_198, &d, &self->unk_18c, &res);
    self->cam0.pos = res;
    {
        s32 deg = self->cam0.fovyDeg;
        Ov015SetFovy(&self->cam0, deg < 0x1e000 ? deg + 0xc00 : 0x1e000);
    }
    p = self->cam0.pos;
    t = self->cam0.at;
    up = self->cam0.up;
    self->cam1.pos = p;
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
    self->cam1.at = r;
    Ov015SetFovy(&self->cam1, 0x1e000);
}

}
