#include "ov010/ov010.h"

extern "C" {

extern void *data_ov000_021ccd68;
extern const Ov010Vec data_ov010_0220f54c;
extern u8 *func_ov000_0218e640(void *mgr, u16 id);
extern void VEC_MultAdd(s32 s, const Ov010Vec *a, const Ov010Vec *b, Ov010Vec *out);
extern BOOL func_ov010_022090b4(s32 type, s32 *a, Ov010Vec *b, Ov010Vec *pos);
extern u16 func_ov010_02209190(s32 type, s32 *a, Ov010Vec *b, Ov010Vec *pos, u16 rot);
extern void func_ov000_0219a2f4(Ov010Vec *p, s32 a, s32 b);

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

}
