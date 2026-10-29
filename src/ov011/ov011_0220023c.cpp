#include "ov011/ov011.h"

struct Ov011Tw108 {
    u8 b0 : 1;
    u8 b1 : 1;
    u8 rest : 6;
    u8 pad;
    s16 unk_02;
    s16 unk_04;
};

struct Ov011Ea {
    u16 lo : 3;
    u16 rest : 13;
};

struct Ov011B0a {
    u16 lo : 7;
    u16 mid : 3;
    u16 rest : 6;
};

extern "C" {

void func_ov000_0218d988(void *self, void *target, s32 c);
void func_ov000_02191690(void *a);
void func_ov000_02191708(void *a);
void func_ov000_021911c8(void *a, s32 b);

#pragma force_active on
void func_ov011_0220023c(void *self) {
    void *pl;
    void *q;
    s32 s;
    if (FLD(Ov011Tw108 *, self, 0x108) == NULL) {
        return;
    }
    pl = func_ov000_0219bf90();
    q = FLD(void *, self, 0xb0);
    if (q != NULL && pl != NULL && (s = FLD(Ov011Tw108 *, self, 0x108)->unk_02) != 0) {
        func_ov000_0218d988(self, pl, Ov011_FxMul(FLD(s16, q, 2), s));
    }
    if (FLD(Ov011Tw108 *, self, 0x108)->b1) {
        FLD(Ov011Ea, self, 0xea).lo = 2;
    } else {
        FLD(Ov011Ea, self, 0xea).lo = FLD(Ov011B0a, FLD(void *, self, 0xb0), 0xa).mid;
    }
    if (FLD(Ov011Tw108 *, self, 0x108)->b0) {
        func_ov000_02191690(FLD(void *, self, 0x38));
    } else {
        func_ov000_02191708(FLD(void *, self, 0x38));
    }
    func_ov000_021911c8(FLD(void *, self, 0x38), FLD(Ov011Tw108 *, self, 0x108)->unk_04);
}
#pragma force_active reset

struct Ov011Tw10c {
    u8 b0 : 1;
    u8 b1 : 1;
    u8 b2 : 1;
    u8 rest : 5;
    u8 pad;
    u16 timer;
};

struct Ov011Tbl6 {
    s32 v[6];
};

extern const Ov011Tbl6 data_ov011_022072c0;
extern void *const data_ov011_02207258[];
extern void *data_02097e4c;
BOOL func_ov000_02190cb0(void *a, const void *b, s32 c, s32 d);
void func_ov000_02191618(void *a);
void func_ov000_021915a0(void *a);
u16 func_ov003_021d9c50(Ov011Vec *a, Ov011Vec *b);
Ov011V *func_02065f88(s32 id, Ov011Vec *pos);
void *func_02049f44(void *mgr, s32 id, const Ov011Vec *pos, s32 a);
s32 VEC_Distance(const Ov011Vec *a, const Ov011Vec *b);
void func_ov000_0218dbe0(void *self, s32 a);
void func_ov000_021987b8(void *a, s32 b, s32 c, s32 d);
u16 FX_Atan2(s32 y, s32 x);

static inline void Ov011_SetTw(Ov011Tw108 *q, s16 a, s16 b) {
    q->b0 = 0;
    q->b1 = 0;
    q->unk_02 = a;
    q->unk_04 = b;
}

void func_ov011_02200310(void *self) {
    Ov011Tbl6 tbl = data_ov011_022072c0;
    Ov011Vec v;
    BOOL ok;
    u32 i;
    u8 st;
    Ov011Tw10c *p;
    st = FLD(u8, FLD(void *, self, 0x40), 0x13);
    ok = TRUE;
    for (i = 0; i < 6; i++) {
        s32 *e = &tbl.v[i];
        if (*e == st) {
            ok = FALSE;
            break;
        }
    }
    p = FLD(Ov011Tw10c *, self, 0x10c);
    if (p == NULL || !ok) {
        return;
    }
    if (p->b0) {
        if (p->timer == 0) {
            Ov011V *e;
            s32 r;
            if (!p->b1) {
                Ov011_SetTw(FLD(Ov011Tw108 *, self, 0x108), 0, 0x1000);
                p = FLD(Ov011Tw10c *, self, 0x10c);
                p->b0 = 1;
                p->b1 = 1;
                p->b2 = 1;
                p->timer = 0x78;
                func_ov000_02190cb0(FLD(void *, self, 0x38), data_ov011_02207258[3], 0x1000, 0);
                func_ov000_02191618(FLD(void *, self, 0x38));
                FLD(s32, self, 0x9c) = 0;
                FLD(s32, self, 0xa0) = 0;
                FLD(s32, self, 0xa4) = 0;
                FLD(s32, self, 0xa8) = 0;
            } else {
                Ov011_SetTw(FLD(Ov011Tw108 *, self, 0x108), 0x1000, 0x1000);
                p = FLD(Ov011Tw10c *, self, 0x10c);
                p->b0 = 1;
                p->b1 = 0;
                p->b2 = 1;
                p->timer = 1;
                func_ov000_02190cb0(FLD(void *, self, 0x38), data_ov011_02207258[0], 0x1000, 0);
                func_ov000_021915a0(FLD(void *, self, 0x38));
            }
            v = FLD(Ov011Vec, self, 0xb8);
            r = func_ov003_021d9c50(&v, &FLD(Ov011Vec, self, 0x70));
            e = func_02065f88(0x192, &FLD(Ov011Vec, self, 0x70));
            e->v34(0, r, 0);
            e->v14(0x4000, 0x4000, 0x4000);
            func_02049f44(data_02097e4c, 0x32, &FLD(Ov011Vec, self, 0x70), 0);
        } else if (p->b1 == 1) {
            FLD(Ov011Flags, FLD(void *, self, 0x48), 0x9a).b5 = 1;
            FLD(Ov011Tw10c *, self, 0x10c)->b2 = 0;
            if (VEC_Distance(&FLD(Ov011Vec, self, 0x70), &FLD(Ov011Vec, self, 0xb8)) < 0x4000) {
                if (FLD(s32, self, 0x9c) >= 0x200) {
                    FLD(s32, self, 0x9c) = 0x200;
                }
                FLD(s32, self, 0xa4) = 0xf60;
            } else {
                FLD(s32, self, 0x9c) += Ov011_FxMul(FLD(s16, FLD(void *, self, 0xb0), 0), 0xcd);
                FLD(s32, self, 0x9c) = FLD(s32, self, 0x9c) > FLD(s16, FLD(void *, self, 0xb0), 0) ? FLD(s16, FLD(void *, self, 0xb0), 0) : (FLD(s32, self, 0x9c) < 0 ? 0 : FLD(s32, self, 0x9c));
            }
            func_ov000_0218dbe0(self, 0);
            func_ov000_021987b8(FLD(void *, self, 0x48), 1, 0, 0);
            if (FLD(u32, FLD(void *, self, 0x48), 0x50) & 0x40000000) {
                FLD(s32, self, 0x9c) = 0;
                FLD(s32, self, 0xa0) = 0;
                FLD(s32, self, 0xa4) = 0;
                FLD(s32, self, 0xa8) = 0;
                FLD(Ov011Tw10c *, self, 0x10c)->b0 = 0;
            }
        }
        FLD(Ov011Tw10c *, self, 0x10c)->timer--;
    }
    if (!FLD(Ov011Tw10c *, self, 0x10c)->b2) {
        return;
    }
    if (func_ov000_0219bf90() == NULL) {
        return;
    }
    {
        void *pl = func_ov000_0219bf90();
        Ov011Vec t;
        t = FLD(Ov011Vec, pl, 0x70);
        FLD(Ov011Vec, self, 0xb8) = t;
        FLD(u16, self, 0x98) = FX_Atan2(t.x - FLD(s32, self, 0x70), t.z - FLD(s32, self, 0x78));
    }
}
}
