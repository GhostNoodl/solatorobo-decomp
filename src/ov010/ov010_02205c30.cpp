#include "ov010/ov010.h"

struct Ov010Bits3 {
    u16 lo : 3;
    u16 rest : 13;
};

struct Ov010Rank {
    u16 pad : 7;
    u16 rank : 3;
    u16 rest : 6;
};

extern "C" {

extern void *data_02097e4c;
extern void *data_ov000_021ccd68;
extern void *data_ov010_0220f024[];
extern u8 *func_ov000_0218e640(void *mgr, u16 id);
extern void func_ov000_02190cb0(void *a, const void *b, s32 c, s32 d);
extern void func_ov000_021915a0(void *a);
extern BOOL func_ov000_02191120(void *p);
extern void func_ov000_0218d988(void *self, void *target, s32 a);
extern void func_ov000_0218d46c(void *a, u16 b, s32 c);
extern void func_ov000_02198360(void *a, s32 b, s32 c);
extern void func_ov003_021d969c(void *p, s32 a);
extern u8 *func_02070558(u16 id);
extern void func_01ffc9fc(Ov010Vec *src, Ov010Vec *dst, u16 angle);
extern void VEC_Add(const Ov010Vec *a, const Ov010Vec *b, Ov010Vec *o);
extern u8 *func_ov003_021d69f0(void *self, u16 kind, const Ov010Vec *pos, const void *rot, void *t);
extern void func_ov010_0220de4c(void *p, u8 a);
extern Ov010V *func_02065f88(s32 a, Ov010Vec *b);
extern void func_02049f44(void *a, s32 b, void *c, s32 d);

void func_ov010_02205c30(u8 *self) {
    u8 *tgt;
    s32 r = FLD(s16, FLD(u8 *, self, 0xb0), 2) * 2;
    {
        u16 id = FLD(u16, self, 0x90);
        tgt = data_ov000_021ccd68 == NULL ? NULL : func_ov000_0218e640(data_ov000_021ccd68, id);
    }
    switch (FLD(u16, FLD(u8 *, self, 0x40), 0)) {
    case 0:
        func_ov000_02190cb0(FLD(void *, self, 0x38), data_ov010_0220f024[6], 0x800, 0);
        FLD(s32, self, 0x9c) = 0;
        FLD(s32, self, 0xa0) = 0;
        FLD(s32, self, 0xa4) = 0;
        FLD(s32, self, 0xa8) = 0;
        FLD(u16, FLD(u8 *, self, 0x40), 0) = 1;
        return;
    case 1:
        func_ov000_0218d988(self, tgt, r);
        if (FLD(s16, FLD(u8 *, self, 0x38), 0xc4) == 1) {
            FLD(u16, FLD(u8 *, self, 0x40), 0) = 2;
        }
        return;
    case 2: {
        u8 *res;
        u8 *ent;
        if (FLD(s16, FLD(u8 *, self, 0x38), 0xc4) != 3) {
            return;
        }
        res = func_02070558(FLD(u16, self, 0xe));
        ent = res != NULL ? res + 0x3a : NULL;
        if (ent == NULL || FLD(u16, ent, 0) == 0xffff) {
            FLD(u16, FLD(u8 *, self, 0x40), 0) = 4;
        } else {
            Ov010Vec v;
            u8 *m = FLD(u8 *, self, 0x38);
            u8 *o;
            v.x = FLD(s16, m, 0xc6) << 4;
            v.y = FLD(s16, m, 0xc8) << 4;
            v.z = FLD(s16, m, 0xca) << 4;
            func_01ffc9fc(&v, &v, FLD(u16, self, 0x7e));
            VEC_Add(&v, &FLD(Ov010Vec, self, 0x70), &v);
            o = func_ov003_021d69f0(self, 0x4818, &v, self + 0x7c, tgt);
            if (o != NULL) {
                FLD(s16, o, 0x18) = FLD(s8, ent, 2);
                func_ov010_0220de4c(o, FLD(u8, self, 0x171));
            }
            FLD(u16, FLD(u8 *, self, 0x40), 0) = 3;
            func_02065f88(0x12c, &v)->v0c(0x2000);
            func_02049f44(data_02097e4c, 0x65, self + 0x70, 0);
            func_02049f44(data_02097e4c, 0x82, self + 0x70, 0);
        }
        if (FLD(u8, self, 0xf1) != 0) {
            FLD(u8, self, 0xf1) = 0;
            func_02049f44(data_02097e4c, FLD(s32, self, 0x140), self + 0x70, 0);
        }
    }
    case 3: {
        u8 *a;
        u16 id = FLD(u16, self, 0xde);
        a = data_ov000_021ccd68 == NULL ? NULL : func_ov000_0218e640(data_ov000_021ccd68, id);
        if (a == NULL) {
            FLD(u16, FLD(u8 *, self, 0x40), 0) = 4;
            return;
        }
        func_ov000_0218d46c(a, FLD(u16, self, 0xc), 0xb);
        FLD(u16, self, 0xde) = 0xffff;
        FLD(u16, FLD(u8 *, self, 0x40), 0) = 4;
        return;
    }
    case 4:
        if (!func_ov000_02191120(FLD(void *, self, 0x38))) {
            return;
        }
        func_ov000_02190cb0(FLD(void *, self, 0x38), data_ov010_0220f024[0xb], 0xcd, 0);
        func_ov000_021915a0(FLD(void *, self, 0x38));
        FLD(Ov010Bits3, self, 0xea).lo = FLD(Ov010Rank, FLD(u8 *, self, 0xb0), 0xa).rank;
        FLD(Ov010Flags8, self, 0xec).b0 = 1;
        func_ov000_02198360(FLD(void *, self, 0x40), 1, 0);
        func_ov003_021d969c(self + 0x160, 1);
        break;
    }
}


extern void *data_02097e4c;
extern void *data_ov010_0220f024[];
extern void *data_ov010_0220fefc[];
extern Ov010Vec data_ov010_0220f0b4;
extern void func_ov000_02190cb0(void *a, const void *b, s32 c, s32 d);
extern BOOL func_ov000_02191120(void *p);
extern void func_ov000_02198360(void *a, s32 b, s32 c);
extern void func_ov003_021d969c(void *p, s32 a);
extern void func_02049f44(void *a, s32 b, void *c, s32 d);
extern void func_ov003_021d982c(void *p, s32 a);
extern void func_ov000_02191418(void *a, s32 b, s32 c);
extern void func_ov000_02191618(void *a);
extern u8 *func_ov000_02199f60(void *p);
extern u16 FX_Atan2(s32 y, s32 x);
extern s32 func_02040528(s32 max);
extern void func_ov003_021d8afc(void *p);
extern void func_ov010_0220da14(void *p);
extern void func_ov003_021d9e90(Ov010Vec *a, Ov010Vec *b, Ov010Vec *c, s32 d, s32 e);
extern void func_ov003_021da2c8(void *self, s32 a, s32 b, s32 c, s32 d);
extern void func_ov000_0218dbe0(void *self, s32 a);
extern s32 func_ov003_021d9a80(const Ov010Vec *a, const Ov010Vec *b);
extern void func_ov003_021d9dbc(Ov010Vec *out, const Ov010Vec *a, const Ov010Vec *b, s32 dist, s32 yoff);
extern void func_ov000_0218d918(void *self, void *t, s32 a);

static inline BOOL Ov010f_Arrived(const Ov010Vec *a, const Ov010Vec *b) {
    return func_ov003_021d9a80(a, b) == 0 ? TRUE : FALSE;
}

void func_ov010_02205f40(u8 *self) {
    func_ov003_021d982c(self + 0x160, 1);
    FLD(u8, self, 0xf1) = 0;
    switch (FLD(u16, FLD(u8 *, self, 0x40), 0)) {
    case 0: {
        u16 ang;
        void *t;
        func_ov000_02190cb0(FLD(void *, self, 0x38), data_ov010_0220f024[5], 0x1000, 1);
        func_ov000_02191418(FLD(void *, self, 0x38), 5, 1);
        func_ov000_02191618(FLD(void *, self, 0x38));
        FLD(u8, self, 0x92) = 0;
        FLD(s32, self, 0x9c) = 0;
        FLD(s32, self, 0xa0) = 0;
        FLD(s32, self, 0xa4) = 0;
        FLD(s32, self, 0xa8) = 0;
        FLD(u16, self, 0xb4) = 0;
        FLD(u16, self, 0xb6) = 0;
        FLD(u16, FLD(u8 *, self, 0x4c), 0x1c) = 0xffff;
        if (FLD(void *, self, 0x50) != NULL) {
            t = func_ov000_02199f60(FLD(void *, self, 0x50));
            if (t == NULL || t == self) {
                ang = FLD(u16, self, 0x7e);
            } else {
                ang = FX_Atan2(FLD(s32, t, 0x70) - FLD(s32, self, 0x70), FLD(s32, t, 0x78) - FLD(s32, self, 0x78));
            }
        } else {
            ang = FLD(u16, self, 0x7e);
        }
        FLD(u16, self, 0x96) = ang;
        FLD(u16, self, 0x98) = FLD(u16, self, 0x96) + 0x8000 + func_02040528(0x2000);
        func_ov003_021d8afc(FLD(void *, self, 0x118));
        func_ov010_0220da14(self + 0x174);
        func_ov003_021d969c(self + 0x160, 0);
        switch (FLD(u8, self, 0x171)) {
        case 1:
            FLD(u16, FLD(u8 *, self, 0x40), 0) = 0x10;
            break;
        case 2:
            FLD(u16, FLD(u8 *, self, 0x40), 0) = 0x20;
            break;
        }
        break;
    }
    case 0x10:
        FLD(s32, self, 0x9c) = 0x1000;
        FLD(s32, self, 0xa4) = 0x400;
        FLD(u16, FLD(u8 *, self, 0x40), 0) = 0x11;
        func_02049f44(data_02097e4c, FLD(s32, self, 0x130), self + 0x70, 0);
    case 0x11: {
        Ov010Vec v = data_ov010_0220f0b4;
        func_ov003_021d9980(&v, FLD(u16, self, 0x98), &v);
        func_ov003_021d9e90(&FLD(Ov010Vec, self, 0x70), &v, &FLD(Ov010Vec, self, 0x70), FLD(s32, self, 0x9c), FLD(s32, self, 0xa0));
        func_ov003_021da2c8(self, FLD(s32, self, 0x9c), FLD(s32, self, 0xa0), FLD(s32, self, 0xa4), FLD(s32, self, 0xa8));
        if (FLD(s32, self, 0x9c) < 0x40) {
            FLD(s32, self, 0x9c) = 0;
            FLD(s32, self, 0xa0) = 0;
            FLD(s32, self, 0xa4) = 0;
            FLD(s32, self, 0xa8) = 0;
        }
        if (!func_ov000_02191120(FLD(void *, self, 0x38))) {
            return;
        }
        if (FLD(s32, self, 0x9c) == 0) {
            FLD(u16, FLD(u8 *, self, 0x40), 0) = 0x50;
        }
        break;
    }
    case 0x20:
        FLD(Ov010Vec, self, 0xb8) = FLD(Ov010Vec, self, 0x70);
        FLD(s32, self, 0x9c) = 0x500;
        FLD(s32, self, 0xa0) = 0x200;
        FLD(s32, self, 0xa8) = 0x18;
        FLD(s32, self, 0xa4) = 0xf00;
        FLD(u16, FLD(u8 *, self, 0x40), 0) = 0x21;
        func_02049f44(data_02097e4c, FLD(s32, self, 0x130), self + 0x70, 0);
    case 0x21:
        FLD(u16, FLD(u8 *, self, 0x40), 2)++;
        if (FLD(u16, FLD(u8 *, self, 0x40), 2) >= 0x14) {
            FLD(u16, FLD(u8 *, self, 0x40), 2) = 0;
            FLD(u16, FLD(u8 *, self, 0x40), 0) = 0x30;
        }
        func_ov000_0218dbe0(self, 0);
        break;
    case 0x30:
        func_ov000_02190cb0(FLD(void *, self, 0x38), data_ov010_0220fefc[0], 0x266, 1);
        func_ov000_02191418(FLD(void *, self, 0x38), 5, 1);
        func_ov000_02191618(FLD(void *, self, 0x38));
        FLD(s32, self, 0xa8) -= 2;
        FLD(u16, FLD(u8 *, self, 0x40), 0) = 0x31;
        break;
    case 0x31:
        if (FLD(s16, FLD(u8 *, self, 0x38), 0xc4) == 1) {
            FLD(u16, FLD(u8 *, self, 0x40), 0) = 0x40;
            FLD(s32, self, 0xa0) = 0;
            FLD(s32, self, 0xa4) = 0;
            FLD(s32, self, 0xa8) = 0;
            FLD(s32, self, 0x9c) = 0x666;
        }
        func_ov000_0218dbe0(self, 0);
        break;
    case 0x40: {
        Ov010Vec t;
        t.x = FLD(s32, self, 0xb8);
        t.y = FLD(s32, self, 0xbc);
        t.z = FLD(s32, self, 0xc0);
        if (func_ov003_021d9a80(&t, &FLD(Ov010Vec, self, 0x70)) < 0x9000) {
            FLD(s32, self, 0xa4) = 0x1000;
        }
        func_ov003_021d9dbc(&FLD(Ov010Vec, self, 0x70), &t, &FLD(Ov010Vec, self, 0x70), FLD(s32, self, 0x9c), FLD(s32, self, 0xa0));
        func_ov003_021da2c8(self, FLD(s32, self, 0x9c), FLD(s32, self, 0xa0), FLD(s32, self, 0xa4), FLD(s32, self, 0xa8));
        FLD(u16, self, 0x98) = FX_Atan2(t.x - FLD(s32, self, 0x70), t.z - FLD(s32, self, 0x78));
        func_ov000_0218d918(self, FLD(void *, self, 0xf8), 0x400);
        if (Ov010f_Arrived(&t, &FLD(Ov010Vec, self, 0x70))) {
            FLD(u16, FLD(u8 *, self, 0x40), 0) = 0x50;
        }
        break;
    }
    case 0x50:
        ((Ov010V *)self)->va4();
        func_ov000_02198360(FLD(void *, self, 0x40), 1, 0);
        break;
    }
}


struct Ov010Sub48 {
    u8 unk_00[0x9a];
    u16 b9a_0 : 1;
    u16 b9a_1 : 2;
    u16 b9a_3 : 1;
    u16 b9a_4 : 12;
};

struct Ov010Sub44 {
    u8 unk_00[0x22];
    u16 b22_0 : 1;
    u16 b22_1 : 1;
    u16 b22_2 : 14;
};

struct Ov010Sub40 {
    u16 state;
    u16 timer;
};

struct Ov010G54b {
    u8 unk_000[0x1cc];
    u8 b0 : 1;
    u8 b1 : 7;
};

extern Ov010G54b *data_ov000_021ccd54;
extern void func_ov003_021d97fc(void *p, s32 a);
extern void func_0203f364(Ov010Sub48 *p);
extern void func_0203cb78(s32 a, s32 b, s32 c);
extern void func_ov000_0218e8ec(void *mgr, s32 a, s32 b);
extern void func_ov003_021d8eac(void *a, void *b, s32 c, s32 d);
extern BOOL func_ov003_021d8efc(void *a);
extern u8 *func_ov000_02190a30(void *p, s32 a);
extern void func_ov003_021d6a3c(void *self, s32 a, s32 b, s32 c);

static inline s32 Ov010g_Mul(s32 a, s64 b) {
    return (s32)((a * b + 0x800) >> 12);
}

// The screen argument of func_0203cb78 (its callers pass 0, 1 or -1).
// As an enum local it is not propagated, so its `mov #0` is listed before
// the jump's loads, as in the ROM (round o4B).
typedef enum { OV010_FADE_SCREEN_MAIN = 0, OV010_FADE_SCREEN_SUB = 1 } Ov010FadeScreen;

static inline void Ov010_Jump640c(u8 *self) {
    FLD(u16, self, 0x98) = FLD(u16, self, 0x98) + (u16)(FLD(u16, self, 0x7e) + 0x7fff);
    FLD(s32, self, 0x9c) = 0x280;
    FLD(s32, self, 0xa0) = 0x180;
    FLD(s32, self, 0xa8) = 0xb;
    FLD(s32, self, 0xa4) = 0xf00;
}

void func_ov010_0220640c(u8 *self) {
    switch (FLD(Ov010Sub40 *, self, 0x40)->state) {
    case 0: {
        Ov010Sub48 *m48;
        Ov010Sub44 *n;
        Ov010V *o;
        Ov010FadeScreen scr;
        func_ov003_021d97fc(self + 0x160, 1);
        m48 = FLD(Ov010Sub48 *, self, 0x48);
        m48->b9a_0 = 0;
        m48->b9a_3 = 0;
        func_0203f364(m48);
        n = FLD(Ov010Sub44 *, self, 0x44);
        n->b22_0 = 0;
        n->b22_1 = 0;
        FLD(u16, FLD(void *, self, 0x4c), 0x1c) = 0xffff;
        func_ov003_021d8afc(FLD(void *, self, 0x118));
        func_ov000_02190cb0(FLD(void *, self, 0x38), data_ov010_0220f024[5], 0x800, 1);
        func_ov000_02191418(FLD(void *, self, 0x38), 5, 1);
        scr = OV010_FADE_SCREEN_MAIN;
        Ov010_Jump640c(self);
        func_0203cb78(0x1e000, 1, scr);
        func_ov000_0218e8ec(data_ov000_021ccd68, 0x4817, 0x15);
        o = func_02065f88(0x69, &FLD(Ov010Vec, self, 0x70));
        if (o != NULL) {
            o->v0c(0x5000);
        }
        func_02049f44(data_02097e4c, FLD(s32, self, 0x130), self + 0x70, 0);
        FLD(Ov010Sub40 *, self, 0x40)->state = 1;
        return;
    }
    case 1:
        FLD(Ov010Sub40 *, self, 0x40)->timer++;
        if (FLD(Ov010Sub40 *, self, 0x40)->timer == 0x1e) {
            func_ov003_021d8eac(self + 0x1dc, self, 0x1000, 0);
            FLD(s32, self, 0xa8) >>= 1;
            FLD(s32, self, 0xa0) -= FLD(s32, self, 0xa0) >> 2;
        }
        if (FLD(Ov010Sub40 *, self, 0x40)->timer >= 0x5a) {
            FLD(s32, self, 0xa8) = 0;
            FLD(s32, self, 0xa0) = Ov010g_Mul(FLD(s32, self, 0xa0), 0xf80);
        }
        if (FLD(Ov010Sub40 *, self, 0x40)->timer >= 0x5a && func_ov003_021d8efc(self + 0x1dc)) {
            Ov010V *o = func_02065f88(0x69, &FLD(Ov010Vec, self, 0x70));
            if (o != NULL) {
                o->v0c(0x5000);
            }
            FLD(Ov010Sub40 *, self, 0x40)->timer = 0;
            FLD(Ov010Sub40 *, self, 0x40)->state = 2;
        }
        func_ov000_0218dbe0(self, 0);
        return;
    case 2:
        func_ov000_02190cb0(FLD(void *, self, 0x38), data_ov010_0220f024[1], 0x266, 0);
        func_ov000_021915a0(FLD(void *, self, 0x38));
        FLD(u16, func_ov000_02190a30(FLD(void *, self, 0x38), 0), 0x112) = 0x800;
        FLD(s32, self, 0xa8) = 0;
        FLD(s32, self, 0xa0) = Ov010g_Mul(FLD(s32, self, 0xa0), 0xf80);
        FLD(Ov010Sub40 *, self, 0x40)->timer++;
        if (FLD(Ov010Sub40 *, self, 0x40)->timer > 0x78) {
            FLD(Ov010Sub40 *, self, 0x40)->timer = 0;
            FLD(Ov010Sub40 *, self, 0x40)->state = 3;
        }
        func_ov000_0218dbe0(self, 0);
        return;
    case 3:
        data_ov000_021ccd54->b0 = 1;
        func_ov003_021d6a3c(self, FLD(u8, self, 0xf3), 1, 1);
        FLD(Ov010Sub40 *, self, 0x40)->state = 4;
        return;
    case 4:
        return;
    }
}

}
