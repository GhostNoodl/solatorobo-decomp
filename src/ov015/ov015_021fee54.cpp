#include "ov015/ov015.h"

extern "C" {

void VEC_MultAdd(s32 scale, const Ov015Vec *dir, const Ov015Vec *base, Ov015Vec *out);
void VEC_Normalize(void *src, void *dst);
void func_02049244(Ov015Vec *a, s32 b, Ov015Vec *c, Ov015Vec *d, s32 e);

void func_ov015_021fee54(u8 *self) {
    Ov015Vec res1;
    Ov015Vec tgt;
    Ov015Vec prev;
    Ov015Vec res2;
    Ov015Vec d1;
    Ov015Vec d2;
    tgt = FLD(Ov015Vec, self, 0x180);
    if (tgt.x > 0x207ec) {
        tgt.x = 0x207ec;
    } else if (tgt.x < -0x207ec) {
        tgt.x = -0x207ec;
    }
    tgt.y += 0x7000;
    tgt.z = -0x6b800;
    prev = FLD(Ov015Vec, self, 0x14);
    func_02049244(&tgt, 0x7b, &prev, &tgt, 0x1000);
    d1.x = FLD(s32, self, 0x18c) - FLD(s32, self, 0x180);
    d1.y = FLD(s32, self, 0x190) - FLD(s32, self, 0x184);
    d1.z = FLD(s32, self, 0x194) - FLD(s32, self, 0x188);
    VEC_Normalize(&d1, &d1);
    VEC_MultAdd(FLD(s32, self, 0x198), &d1, &FLD(Ov015Vec, self, 0x18c), &res1);
    res1.y += 0x1e000;
    prev = FLD(Ov015Vec, self, 0x8);
    func_02049244(&res1, 0x7b, &prev, &res1, 0x1000);
    FLD(Ov015Vec, self, 0x8) = res1;
    FLD(Ov015Vec, self, 0x14) = tgt;
    d2.x = FLD(s32, self, 0x18c) - tgt.x;
    d2.y = FLD(s32, self, 0x190) - tgt.y;
    d2.z = FLD(s32, self, 0x194) - tgt.z;
    VEC_Normalize(&d2, &d2);
    VEC_MultAdd(FLD(s32, self, 0x198), &d2, &FLD(Ov015Vec, self, 0x18c), &res2);
    res2.z -= 0x1000;
    FLD(s32, self, 0xd0) = 0;
    FLD(s32, self, 0xd4) = 0x1000;
    FLD(s32, self, 0xd8) = -0x1000;
    FLD(Ov015Vec, self, 0xc4) = res2;
}
struct Ov015Mtx33b {
    s32 m[3][3];
};
void func_ov015_021fd0f4(u8 *self, Ov015Vec *out);
void VEC_Add(const void *a, const void *b, void *out);
void MTX_RotAxis33(Ov015Mtx33b *m, const Ov015Vec *v, s32 s, s32 c);
void MTX_MultVec33(const Ov015Vec *v, const Ov015Mtx33b *m, Ov015Vec *o);

static inline Ov015Vec *Ov015_VecAt(u8 *p, u32 off) { return (Ov015Vec *)(p + off); }

void func_ov015_021ff044(u8 *self) {
    Ov015Vec o;
    Ov015Vec res;
    Ov015Vec tgt;
    Ov015Vec cam;
    Ov015Vec r;
    Ov015Vec p;
    Ov015Vec w;
    Ov015Vec d;
    Ov015Vec d2;
    Ov015Mtx33b m;
    Ov015Vec c;
    Ov015Vec e;
    Ov015Vec up;
    func_ov015_021fd0f4(self, &o);
    d.x = FLD(s32, self, 0x18c) - o.x;
    d.y = FLD(s32, self, 0x190) - o.y;
    d.z = FLD(s32, self, 0x194) - o.z;
    VEC_Normalize(&d, &d);
    VEC_MultAdd(FLD(s32, self, 0x198), &d, &FLD(Ov015Vec, self, 0x18c), &res);
    tgt = *Ov015_VecAt(self, 0x14);
    func_02049244(&tgt, 0x19a, &tgt, &o, 0);
    cam = FLD(Ov015Vec, self, 0x8);
    func_02049244(&cam, 0x29, &cam, &res, 0);
    FLD(Ov015Vec, self, 0x8) = cam;
    up = FLD(Ov015Vec, self, 0x20);
    FLD(Ov015Vec, self, 0x14) = tgt;
    d2.x = FLD(s32, self, 0x18c) - tgt.x;
    d2.y = FLD(s32, self, 0x190) - tgt.y;
    d2.z = FLD(s32, self, 0x194) - tgt.z;
    VEC_Normalize(&d2, &d2);
    VEC_MultAdd(FLD(s32, self, 0x198), &d2, &FLD(Ov015Vec, self, 0x18c), &p);
    e.x = tgt.x - p.x;
    e.y = tgt.y - p.y;
    e.z = tgt.z - p.z;
    VEC_Normalize(&e, &e);
    c.x = (s32)(((s64)e.y * up.z - (s64)e.z * up.y + 0x800) >> 12);
    c.y = (s32)(((s64)e.z * up.x - (s64)e.x * up.z + 0x800) >> 12);
    c.z = (s32)(((s64)e.x * up.y - (s64)e.y * up.x + 0x800) >> 12);
    VEC_Normalize(&c, &c);
    MTX_RotAxis33(&m, &c, FX_SinCosTable_[0xdfc * 2], FX_SinCosTable_[0xdfc * 2 + 1]);
    MTX_MultVec33(&e, &m, &r);
    VEC_Add(&r, &p, &r);
    w = *Ov015_VecAt(self, 0xd0);
    func_02049244(&w, 0x29, &w, &r, 0);
    FLD(Ov015Vec, self, 0xd0) = w;
    w = FLD(Ov015Vec, self, 0xc4);
    func_02049244(&w, 0x29, &w, &p, 0);
    FLD(Ov015Vec, self, 0xc4) = w;
}

}
