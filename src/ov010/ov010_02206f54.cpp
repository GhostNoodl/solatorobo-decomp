#include "ov010/ov010.h"

extern "C" {

extern void *data_02097e4c;
extern void func_ov003_021d8a7c(void *p, s32 a);
extern void func_ov003_021d8afc(void *p);
extern void func_ov003_021d969c(void *p, s32 a);
extern void *func_02049f44(void *a, s32 b, void *c, s32 d);
extern void func_ov010_0220d9c0(void *p, void *h);
extern BOOL func_ov010_0220da4c(void *p);
extern Ov010V *func_02065f88(s32 a, Ov010Vec *b);

static inline Ov010Vec Ov010_Center(void *self) {
    Ov010Vec p;
    p.x = FLD(s32, self, 0x70);
    p.y = FLD(s32, self, 0x74) + FLD(s32, self, 0x68) / 2;
    p.z = FLD(s32, self, 0x78);
    return p;
}

void func_ov010_02206f54(void *self) {
    FLD(u8, self, 0xf2) = 1;
    FLD(u8, self, 0xf1) = 1;
}

void func_ov010_02206f64(void *self) {
    FLD(u8, self, 0xf2) = 1;
    if (FLD(u16, FLD(void *, self, 0x40), 0) != 0) {
        return;
    }
    func_ov003_021d8a7c(FLD(void *, self, 0x118), 0);
    func_ov003_021d969c((u8 *)self + 0x160, 1);
    FLD(u16, FLD(void *, self, 0x40), 0)++;
    func_02049f44(data_02097e4c, FLD(s32, self, 0x144), (u8 *)self + 0x70, 0);
}

// Reads the state word through a const view (a const getter is not merged with the later
// plain read of the same field, so the increment reloads it as in the target).
static inline u16 Ov010_GetState(const u16 *state) {
    return *state;
}

void func_ov010_02206fd0(void *self) {
    u16 *m = FLD(u16 *, self, 0x40);
    FLD(u8, self, 0xf2) = 1;
    if (Ov010_GetState(m) != 0) {
        return;
    }
    m[0]++;
    func_ov003_021d8afc(FLD(void *, self, 0x118));
}

void func_ov010_02207004(void *self) {
    FLD(u8, self, 0xf2) = 1;
    if (FLD(u16, FLD(void *, self, 0x40), 0) == 0) {
        func_ov010_0220d9c0((u8 *)self + 0x174, FLD(void *, self, 0x114));
        FLD(u16, FLD(void *, self, 0x40), 0)++;
        return;
    }
    if (func_ov010_0220da4c((u8 *)self + 0x174)) {
        func_ov003_021d969c((u8 *)self + 0x160, 1);
    }
}

void func_ov010_02207064(void *self) {
    u16 *m = FLD(u16 *, self, 0x40);
    switch (m[0]) {
    case 0: {
        s32 sc = Ov010_FxMul(FLD(s32, self, 0x64), 0x1800);
        Ov010Vec q = Ov010_Center(self);
        Ov010V *fx = func_02065f88(0x196, &q);
        fx->v0c(sc);
        FLD(s32, fx, 0x3c) = 0x1000;
        func_02049f44(data_02097e4c, 0x44, (u8 *)self + 0x70, 0);
        FLD(u16, FLD(void *, self, 0x40), 0) = 1;
        break;
    }
    case 1:
        m[1]++;
        if (FLD(u16, FLD(void *, self, 0x40), 2) > 0x32) {
            FLD(u16, FLD(void *, self, 0x40), 2) = 0;
            FLD(u16, FLD(void *, self, 0x40), 0) = 2;
        }
        break;
    case 2:
        func_ov003_021d969c((u8 *)self + 0x160, 1);
        break;
    }
}


struct Ov010Mtx33e {
    s32 m[9];
};

extern void *data_ov010_0220f024[];
extern BOOL func_ov000_02190cb0(void *a, const void *b, s32 c, s32 d);
extern void func_ov000_021915a0(void *a);
extern BOOL func_ov010_0220794c(void *self);
extern u16 FX_Atan2(s32 y, s32 x);
extern u16 func_ov010_02208e90(s32 a, s32 b);
extern s32 func_0204045c(void);
extern void MTX_RotY33_(Ov010Mtx33e *m, s32 s, s32 c);
extern void MTX_MultVec33(const Ov010Vec *v, const Ov010Mtx33e *m, Ov010Vec *o);
extern void VEC_Add(const Ov010Vec *a, const Ov010Vec *b, Ov010Vec *o);
extern s32 VEC_Distance(const Ov010Vec *a, const Ov010Vec *b);
extern void func_ov000_0218d918(void *self, void *t, s32 a);
extern void func_ov000_0218dbe0(void *self, s32 a);
extern Ov010V *func_ov010_0220eaf0(void *self, Ov010Vec *pos, Ov010Vec *p);

static inline s32 Ov010e_FxMul(s32 a, s64 b) {
    return (s32)((a * b + 0x800) >> 12);
}

static inline void Ov010e_SetRot(Ov010Vec *v, s32 r, u16 ang) {
    Ov010Mtx33e m;
    v->x = 0;
    v->y = 0;
    v->z = Ov010e_FxMul(r, 0x1000);
    MTX_RotY33_(&m, OV010_SIN(ang), OV010_COS(ang));
    MTX_MultVec33(v, &m, v);
}

void func_ov010_022071a0(void *self) {
    switch (FLD(u16, FLD(void *, self, 0x40), 0)) {
    case 0:
        FLD(u16, FLD(void *, self, 0x40), 0) = 0x10;
        break;
    case 0x30:
        break;
    case 0x10:
        func_ov000_02190cb0(FLD(void *, self, 0x38), data_ov010_0220f024[0xb], 0x266, 0);
        func_ov000_021915a0(FLD(void *, self, 0x38));
        FLD(s32, self, 0x9c) = 0;
        FLD(s32, self, 0xa0) = 0;
        FLD(s32, self, 0xa4) = 0;
        FLD(s32, self, 0xa8) = 0;
        FLD(u16, FLD(void *, self, 0x40), 0) = 0x11;
        break;
    case 0x11:
        if (!func_ov010_0220794c(self)) {
            break;
        }
        FLD(u16, FLD(void *, self, 0x40), 0) = 0x20;
    case 0x20: {
        Ov010Vec v;
        u8 *c = FLD(u8 *, self, 0xf8);
        u16 ang = FX_Atan2(FLD(s32, c, 0) - FLD(s32, self, 0x70), FLD(s32, c, 8) - FLD(s32, self, 0x78)) + 0x7fff;
        u16 d = func_ov010_02208e90(FLD(s32, FLD(u8 *, self, 0xf8), 0x10), 0x3000);
        s32 y;
        Ov010V *e;
        u16 diff;
        if (func_0204045c() % 2 == 0) {
            ang += d;
        } else {
            ang -= d;
        }
        c = FLD(u8 *, self, 0xf8);
        y = FLD(s32, c, 4);
        Ov010e_SetRot(&v, FLD(s32, c, 0x10), ang);
        VEC_Add(&v, (Ov010Vec *)c, &v);
        v.y = y;
        FLD(Ov010Vec, self, 0xb8) = v;
        FLD(u16, self, 0x98) = FX_Atan2(v.x - FLD(s32, self, 0x70), v.z - FLD(s32, self, 0x78));
        FLD(s32, self, 0x9c) = 0x2800;
        func_ov000_0218d918(self, FLD(void *, self, 0xf8), 0x400);
        func_ov000_0218dbe0(self, 0);
        FLD(s32, self, 0x9c) = 0x400;
        e = func_ov010_0220eaf0(self, &FLD(Ov010Vec, self, 0x70), &v);
        e->v0c(0x2000);
        diff = FLD(u16, e, 0x66) - FLD(u16, self, 0x7e);
        if (diff >= 0x1400 && diff <= 0x6c00) {
            func_ov000_02190cb0(FLD(void *, self, 0x38), data_ov010_0220f024[9], 0x800, 0);
        } else if (diff >= 0x9400 && diff <= 0xec00) {
            func_ov000_02190cb0(FLD(void *, self, 0x38), data_ov010_0220f024[8], 0x800, 0);
        }
        func_02049f44(data_02097e4c, FLD(s32, self, 0x14c), (u8 *)self + 0x70, 0);
        func_02049f44(data_02097e4c, 0x29, (u8 *)self + 0x70, 0);
        FLD(u16, FLD(void *, self, 0x40), 0) = 0x21;
        break;
    }
    case 0x21:
        if (VEC_Distance(&FLD(Ov010Vec, self, 0x70), &FLD(Ov010Vec, self, 0xb8)) < 0x3000) {
            FLD(s32, self, 0xa4) = 0xf00;
        }
        if (FLD(s32, self, 0x9c) < 0x100) {
            func_ov000_02190cb0(FLD(void *, self, 0x38), data_ov010_0220f024[0xb], 0xcd, 0);
        }
        func_ov000_0218dbe0(self, 0);
        func_ov000_0218d918(self, FLD(void *, self, 0xf8), 0x400);
        if (FLD(s32, self, 0x9c) < 4) {
            FLD(u16, FLD(void *, self, 0x40), 0) = 0x30;
        }
        break;
    }
}

}
