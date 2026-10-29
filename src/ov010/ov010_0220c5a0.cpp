#include "ov010/ov010.h"

extern "C" {

extern void *data_ov000_021ccd68;
extern const Ov010Vec data_ov010_0220f54c;
extern u8 *func_ov000_0218e640(void *mgr, u16 id);
extern void VEC_MultAdd(s32 s, const Ov010Vec *a, const Ov010Vec *b, Ov010Vec *out);
extern BOOL func_ov010_022090b4(s32 type, s32 *a, Ov010Vec *b, Ov010Vec *pos);
extern u16 func_ov010_02209190(s32 type, s32 *a, Ov010Vec *b, Ov010Vec *pos, u16 rot);
extern s32 func_ov000_0219a2f4(Ov010Vec *p, s32 a, s32 b);

static inline u8 *Ov010_FindActor(u16 id) {
    if (data_ov000_021ccd68 == NULL) {
        return NULL;
    }
    return func_ov000_0218e640(data_ov000_021ccd68, id);
}

static inline Ov010Vec Ov010_PathPoint(s32 type, s32 *a, Ov010Vec *b) {
    Ov010Vec v;
    switch (type) {
    case 0:
        v.x = a[0] + ((a[2] - a[0]) >> 1);
        v.y = a[4];
        v.z = a[1] + ((a[3] - a[1]) >> 1);
        break;
    case 1:
        v.x = b->x;
        v.y = b->y;
        v.z = b->z;
        break;
    }
    return v;
}

static inline void Ov010_VecSub(const Ov010Vec *a, const Ov010Vec *b, Ov010Vec *out) {
    s32 ax = a->x;
    s32 ay = a->y;
    s32 az = a->z;
    out->x = ax - b->x;
    out->y = ay - b->y;
    out->z = az - b->z;
}

static inline void Ov010_Approach(Ov010Vec *pos, const Ov010Vec *target, s32 rate) {
    Ov010Vec d;
    Ov010_VecSub(target, pos, &d);
    VEC_MultAdd(rate, &d, pos, pos);
}

void func_ov010_0220c5a0(void *self) {
    Ov010Vec r;
    switch (FLD(u8, self, 0x16b)) {
    case 1:
        return;
    case 2: {
        u8 *a = Ov010_FindActor(FLD(u16, self, 0xd2));
        u8 *m;
        if (a == NULL || (m = FLD(u8 *, a, 0x48)) == NULL) {
            return;
        }
        Ov010_Approach(&FLD(Ov010Vec, self, 0xf0), &FLD(Ov010Vec, m, 0x68), 0x11f);
        break;
    }
    case 3: {
        FLD(s32, self, 0xf4) = Ov010_PathPoint(FLD(s32, self, 0xdc), FLD(s32 *, self, 0xe0), FLD(Ov010Vec *, self, 0xe4)).y;
        if (func_ov010_022090b4(FLD(s32, self, 0xdc), FLD(s32 *, self, 0xe0), FLD(Ov010Vec *, self, 0xe4), &FLD(Ov010Vec, self, 0xf0))) {
            FLD(u16, self, 0xd4) = func_ov010_02209190(FLD(s32, self, 0xdc), FLD(s32 *, self, 0xe0), FLD(Ov010Vec *, self, 0xe4), &FLD(Ov010Vec, self, 0xf0), FLD(u16, self, 0xd4));
        }
        func_ov003_021d9980(&r, FLD(u16, self, 0xd4), (Ov010Vec *)&data_ov010_0220f54c);
        VEC_MultAdd(0x2b8, &r, &FLD(Ov010Vec, self, 0xf0), &FLD(Ov010Vec, self, 0xf0));
        func_ov000_0219a2f4(&FLD(Ov010Vec, self, 0xf0), 0x1000, -0x3000);
        break;
    }
    }
}

extern s32 func_020404e0(void);
extern s32 func_02040498(s32 max);
extern void func_ov003_021da48c(void *p, s32 a);

struct Ov010Mark {
    u8 b0 : 1;
    u8 b1 : 1;
    u8 b2 : 1;
    u8 rest : 5;
    u8 pad;
    u16 time;
    u8 pad4[4];
    Ov010Vec pos;
    u8 st[4];
};

static inline s32 Ov010c_FxMul(s32 a, s64 b) {
    return (s32)((a * b + 0x800) >> 12);
}

static inline Ov010Vec Ov010_RandPoint(s32 type, s32 *a, Ov010Vec *b) {
    Ov010Vec v;
    switch (type) {
    case 0: {
        s32 y;
        s32 z;
        s32 x;
        z = a[1] + Ov010c_FxMul(a[3] - a[1], func_020404e0());
        y = a[4];
        x = a[0] + Ov010c_FxMul(a[2] - a[0], func_020404e0());
        v.x = x;
        v.y = y;
        v.z = z;
        func_ov000_0219a2f4(&v, 0x1000, -0x3000);
        break;
    }
    case 1: {
        s32 r = Ov010c_FxMul(FLD(s32, b, 0xc), func_020404e0());
        func_ov003_021d9980(&v, func_02040498(0xffff), (Ov010Vec *)&data_ov010_0220f54c);
        VEC_MultAdd(r, &v, b, &v);
        func_ov000_0219a2f4(&v, 0x1000, -0x3000);
        break;
    }
    }
    return v;
}

void func_ov010_0220c758(void *self) {
    u16 t;
    s32 *ap;
    Ov010Vec *bp;
    switch (FLD(u16, self, 0x158)) {
    case 0: {
        u8 *a = Ov010_FindActor(FLD(u16, self, 0xd2));
        if (a != NULL && FLD(u8 *, a, 0x48) != NULL) {
            t = 0;
            Ov010Mark *c_0;
            switch (FLD(u8, self, 0x16b)) {
            case 2: {
                bp = FLD(Ov010Vec *, self, 0xe4);
                ap = FLD(s32 *, self, 0xe0);
                Ov010Vec p_0;
                p_0 = Ov010_RandPoint(FLD(s32, self, 0xdc), ap, bp);
                t = 0x3c;
                FLD(Ov010Vec, self, 0xf0) = p_0;
                FLD(u16, self, 0xd4) = 0;
                break;
            }
            case 3: {
                Ov010Vec p_1;
                p_1 = Ov010_RandPoint(FLD(s32, self, 0xdc), FLD(s32 *, self, 0xe0), FLD(Ov010Vec *, self, 0xe4));
                FLD(Ov010Vec, self, 0xf0) = p_1;
                FLD(u16, self, 0xd4) = func_02040498(0xffff);
                t = 0x64;
                break;
            }
            }
            c_0 = FLD(Ov010Mark *, self, 0xe8);
            if (c_0->b0) {
                c_0->b1 = 1;
                c_0->time = t;
                c_0->pos = FLD(Ov010Vec, self, 0xf0);
                func_ov003_021da48c(c_0->st, 0);
            }
        }
        FLD(u16, self, 0x158) = 1;
        break;
    }
    case 1: {
        Ov010Mark *c_1 = FLD(Ov010Mark *, self, 0xe8);
        BOOL busy;
        BOOL done_0;
        if (c_1->b0 && c_1->b1) {
            c_1->pos = FLD(Ov010Vec, self, 0xf0);
        }
        c_1 = FLD(Ov010Mark *, self, 0xe8);
        busy = FALSE;
        if (c_1->b0) {
            busy = c_1->b2;
        }
        if (!busy) {
            done_0 = FALSE;
            if (c_1->b0) {
                if (!c_1->b1) {
                    done_0 = TRUE;
                }
            }
            if (!done_0) {
                return;
            }
        }
        FLD(u16, self, 0x158) = 2;
        break;
    }
    case 2: {
        Ov010Mark *c_2 = FLD(Ov010Mark *, self, 0xe8);
        BOOL done_1 = FALSE;
        Ov010Vec *p_2;
        if (c_2->b0) {
            if (!c_2->b1) {
                done_1 = TRUE;
            }
        }
        if (!done_1) {
            return;
        }
        func_ov003_021da48c((u8 *)self + 0x158, 1);
        FLD(Ov010Mark, self, 0xce).b0 = 0;
        c_2 = FLD(Ov010Mark *, self, 0xe8);
        p_2 = c_2->b0 ? &c_2->pos : NULL;
        FLD(Ov010Vec, self, 0xf0) = *p_2;
        break;
    }
    }
}

}
