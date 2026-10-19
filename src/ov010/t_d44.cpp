#include "ov010/ov010.h"

struct Ov010Mtx33 {
    s32 m[9];
};

struct Ov010Flags111 {
    u8 b0 : 1;
    u8 b1 : 1;
    u8 b2 : 1;
    u8 b3 : 1;
    u8 rest : 4;
};

extern "C" {
extern void *data_02097e4c;
extern void *const data_ov010_0220f024[];
extern void func_ov010_0220d77c(void);
extern void func_ov010_0220d918(void *p, void *fn);
extern s32 func_ov010_0220d9a4(void *p);
extern void func_ov000_02190cb0(void *a, const void *b, s32 c, s32 d);
extern void func_ov000_021915a0(void *a);
extern BOOL func_ov000_02191120(void *p);
extern u8 *func_ov000_0219bf90(void);
extern void func_ov010_02209578(void *a, s32 b, s32 c, s32 d, u16 e, u16 f);
extern void func_ov010_0220d9c0(void *p, void *h);
extern BOOL func_ov010_0220da4c(void *p);
extern Ov010Vec func_ov010_02204030(void *c, const Ov010Vec *target, s32 n, u16 ang);
extern u16 func_ov003_021d9c38(Ov010Vec *v);
extern u32 func_02040420(void);
extern s32 func_02040528(s32 max);
extern void MTX_RotY33_(Ov010Mtx33 *m, s32 s, s32 c);
extern void MTX_MultVec33(const Ov010Vec *v, const Ov010Mtx33 *m, Ov010Vec *o);
extern void VEC_Add(const Ov010Vec *a, const Ov010Vec *b, Ov010Vec *o);
extern void VEC_Normalize(const Ov010Vec *a, Ov010Vec *o);
extern u16 FX_Atan2(s32 y, s32 x);
extern Ov010V *func_ov010_0220eaf0(void *self, Ov010Vec *pos, Ov010Vec *p);
extern void func_02049f44(void *a, s32 b, Ov010Vec *c, s32 d);
extern void func_ov010_02207828(void *self);
extern void func_ov000_0218d918(void *self, void *t, s32 a);
extern u8 *func_ov000_02190a30(void *p, s32 a);
extern void func_ov000_021911c8(void *a, s32 b);
extern void func_ov010_0220984c(void *a, u16 b);
extern void func_ov003_021d969c(void *p, s32 a);

static inline s32 Ov010d_Mul64(s32 a, s64 b) {
    return (s32)((a * b + 0x800) >> 12);
}

static inline void Ov010d_Orb(Ov010Vec *v, u16 a, s32 r) {
    Ov010Mtx33 m;
    v->x = 0;
    v->y = 0;
    v->z = r;
    MTX_RotY33_(&m, OV010_SIN(a), OV010_COS(a));
    MTX_MultVec33(v, &m, v);
}
static inline void Ov010d_Orb2(Ov010Vec *v, u16 a, s32 r) {
    Ov010Mtx33 m;
    MTX_RotY33_(&m, OV010_SIN(a), OV010_COS(a));
    v->x = 0;
    v->y = 0;
    v->z = r;
    MTX_MultVec33(v, &m, v);
}
static inline void Ov010d_RotY(Ov010Vec *v, u16 a) {
    Ov010Mtx33 m;
    MTX_RotY33_(&m, OV010_SIN(a), OV010_COS(a));
    MTX_MultVec33(v, &m, v);
}

void func_ov010_02204d44(u8 *self) {
    BOOL flag = FALSE;
    switch (FLD(u16, FLD(u8 *, self, 0x40), 0)) {
    case 0:
        func_ov010_0220d918(self + 0x174, (void *)func_ov010_0220d77c);
        if (func_ov010_0220d9a4(self + 0x174) >= 5) {
            FLD(u16, FLD(u8 *, self, 0x40), 0) = 0x32;
            break;
        }
        FLD(u16, FLD(u8 *, self, 0x40), 0) = 10;
    case 10:
        FLD(s32, self, 0x9c) = 0;
        FLD(s32, self, 0xa0) = 0;
        FLD(s32, self, 0xa4) = 0;
        FLD(s32, self, 0xa8) = 0;
        func_ov000_02190cb0(FLD(void *, self, 0x38), data_ov010_0220f024[7], 0x800, 1);
        func_ov010_02209578(FLD(void *, self, 0x104), FLD(s32, self, 0x15c), FLD(s32, self, 0xfc), FLD(s32, self, 0x100),
                            FLD(u16, self, 0xc), FLD(u16, func_ov000_0219bf90(), 0xc));
        func_ov010_0220d9c0(self + 0x174, FLD(void *, self, 0x104));
        FLD(u16, FLD(u8 *, self, 0x40), 0) = 0xb;
    case 0xb:
        flag = TRUE;
        FLD(u16, FLD(u8 *, self, 0x40), 2)++;
        if (FLD(u16, FLD(u8 *, self, 0x40), 2) > 0x1e) {
            FLD(u16, FLD(u8 *, self, 0x40), 2) = 0;
            FLD(u16, FLD(u8 *, self, 0x40), 0) = 0x14;
        }
        break;
    case 0x14:
        flag = TRUE;
        {
        Ov010Vec p = func_ov010_02204030(FLD(void *, self, 0xf8), &FLD(Ov010Vec, self, 0x70), 4, 0);
        Ov010Vec d;
        Ov010Vec off;
        u16 ang;
        u16 a;
        s32 y;
        u8 *c;
        d.x = p.x - FLD(s32, FLD(u8 *, self, 0xf8), 0);
        d.y = p.y - FLD(s32, FLD(u8 *, self, 0xf8), 4);
        d.z = p.z - FLD(s32, FLD(u8 *, self, 0xf8), 8);
        ang = func_ov003_021d9c38(&d);
        if ((func_02040420() & 1) == 0) {
            a = ang + 0x3fff;
        } else {
            a = ang + 0xc000;
        }
        c = FLD(u8 *, self, 0xf8);
        y = FLD(s32, c, 4);
        Ov010d_Orb(&off, a, Ov010d_Mul64(FLD(s32, c, 0x10), 0x1000));
        VEC_Add(&off, (Ov010Vec *)c, &off);
        off.y = y;
        off.y += func_02040528(0x1000);
        FLD(Ov010Vec, self, 0xb8) = off;
        FLD(s32, self, 0x150) = off.x - FLD(s32, self, 0x70);
        FLD(s32, self, 0x154) = off.y - FLD(s32, self, 0x74);
        FLD(s32, self, 0x158) = off.z - FLD(s32, self, 0x78);
        VEC_Normalize(&FLD(Ov010Vec, self, 0x150), &FLD(Ov010Vec, self, 0x150));
        FLD(u16, self, 0x98) = FX_Atan2(FLD(s32, self, 0x150), FLD(s32, self, 0x158));
        FLD(s32, self, 0x9c) = 0;
        FLD(s32, self, 0xa0) = 0;
        FLD(s32, self, 0xa4) = 0;
        FLD(s32, self, 0xa8) = 0;
        func_ov010_0220eaf0(self, &FLD(Ov010Vec, self, 0x70), &off)->v0c(0x2000);
        FLD(u16, FLD(u8 *, self, 0x40), 0) = 0x15;
        if (FLD(u8, self, 0xf1)) {
            FLD(u8, self, 0xf1) = 0;
            func_02049f44(data_02097e4c, FLD(s32, self, 0x138), &FLD(Ov010Vec, self, 0x70), 0);
        }
        func_02049f44(data_02097e4c, 0x29, &FLD(Ov010Vec, self, 0x70), 0);
        }
        break;
    case 0x15:
        flag = TRUE;
        if (func_ov010_0220da4c(self + 0x174)) {
            FLD(u16, FLD(u8 *, self, 0x40), 0) = 0x1e;
        }
        func_ov010_02207828(self);
        func_ov000_0218d918(self, FLD(void *, self, 0xf8), 0x400);
        break;
    case 0x1e:
        func_ov010_02207828(self);
        func_ov000_0218d918(self, FLD(void *, self, 0xf8), 0x400);
        FLD(Ov010Flags111, func_ov000_02190a30(FLD(void *, self, 0x38), flag), 0x111).b3 = 0;
        func_ov000_021911c8(FLD(void *, self, 0x38), 0x2000);
        FLD(u16, FLD(u8 *, self, 0x40), 0) = 0x1f;
        break;
    case 0x1f:
        if (FLD(s16, FLD(u8 *, self, 0x38), 0xc4) == 1) {
            func_ov010_0220984c(FLD(void *, self, 0x108), FLD(u16, self, 0xc));
            func_ov010_0220d9c0(self + 0x174, FLD(void *, self, 0x108));
            FLD(u16, FLD(u8 *, self, 0x40), 0) = 0x28;
            func_02049f44(data_02097e4c, FLD(s32, self, 0x13c), &FLD(Ov010Vec, self, 0x70), flag);
        }
        func_ov010_02207828(self);
        func_ov000_0218d918(self, FLD(void *, self, 0xf8), 0x400);
        break;
    case 0x28:
        if (func_ov010_0220da4c(self + 0x174) && func_ov000_02191120(FLD(void *, self, 0x38))) {
            func_ov000_02190cb0(FLD(void *, self, 0x38), data_ov010_0220f024[0xb], 0x266, 1);
            func_ov000_021915a0(FLD(void *, self, 0x38));
            FLD(u16, FLD(u8 *, self, 0x40), 0) = 0x32;
        }
        func_ov010_02207828(self);
        func_ov000_0218d918(self, FLD(void *, self, 0xf8), 0x400);
        break;
    case 0x32:
        func_ov003_021d969c(self + 0x160, 1);
        break;
    }
    if (flag && FLD(s16, FLD(u8 *, self, 0x38), 0xc4) == 2) {
        FLD(Ov010Flags111, func_ov000_02190a30(FLD(void *, self, 0x38), 0), 0x111).b3 = 1;
    }
}
}
