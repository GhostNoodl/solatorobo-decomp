#include "ov010/ov010.h"

struct Ov010Heap {
    u32 cur;
    u32 unk_04;
    u32 def;
};

struct Ov010PlFlags {
    u32 b0 : 12;
    u32 b12 : 2;
    u32 b14 : 18;
};

extern "C" {

extern void *data_0214a420;
extern Ov010Heap *data_02097dd0;
extern void func_02065804(void *a, s32 b);
extern void func_ov003_021da48c(void *p, s32 a);
extern BOOL func_ov000_02198360(void *a, s32 b, s32 c);
extern void func_ov010_02200a00(u8 *o);
extern u8 *func_ov000_0219bf90(void);
extern s32 func_ov003_021d9a80(const Ov010Vec *a, const Ov010Vec *b);

static inline void Ov010Fx_Free(u8 *s) {
    if (FLD(Ov010Flags8, s, 0).b0) {
        FLD(Ov010Flags8, s, 0).b0 = 0;
        func_02065804(data_0214a420, FLD(s32, s, 0x14));
        func_02065804(data_0214a420, FLD(s32, s, 0x18));
        func_02065804(data_0214a420, FLD(s32, s, 0x1c));
        FLD(s32, s, 0x14) = 0;
        FLD(s32, s, 0x18) = 0;
        FLD(s32, s, 0x1c) = 0;
    }
}

static inline void Ov010Beam_Reset(u8 *b) {
    if (FLD(u8, b, 0) != 0) {
        Ov010Fx_Free(b + 0x28);
        FLD(u8, b, 0) = 0;
    }
}

void func_ov010_02200ee0(u8 *o) {
    u8 *next;
    u8 *n;
    if (!FLD(Ov010Flags8, o, 0).b0) {
        return;
    }
    for (n = FLD(u8 *, o, 0x10); n != NULL; n = next) {
        u32 saved;
        next = FLD(u8 *, n, 8);
        Ov010Beam_Reset(n + 0xc);
        saved = data_02097dd0->cur;
        data_02097dd0->cur = data_02097dd0->def;
        if (n != NULL) {
            if (n != NULL) {
                Ov010Beam_Reset(n + 0xc);
                Ov010Fx_Free(n + 0x34);
                func_0203de1c(n);
            }
        }
        data_02097dd0->cur = saved;
    }
    FLD(u8 *, o, 0x10) = NULL;
    FLD(Ov010Flags8, o, 0).b0 = 0;
}

}

// func_ov010_02201064 (round raD). Ov010Beam_Idle sets its flag from the mode compare (`r = b[0x7f] == 5`)
// rather than clearing it under an && test: the compare's value is a late temporary, numbered below the CSE'd
// state-byte reads, which is the colouring the ROM has in the beam walks. Each beam register update reads the
// old value into `cur` first, which puts GetB's value first in the add.
extern "C" {

extern const Ov010Vec data_ov010_0220ef80;
extern s32 func_02040498(s32 max);
extern s32 func_02040528(s32 n);
extern s32 func_020404e0(void);
extern void func_ov003_021d9a00(Ov010Vec *out, s32 angle, const Ov010Vec *in);
extern u16 func_ov003_021d9c50(Ov010Vec *a, Ov010Vec *b);
extern u16 func_ov003_021d9c74(Ov010Vec *v);
extern u16 func_ov003_021d9c38(Ov010Vec *v);
extern void VEC_Add(const Ov010Vec *a, const Ov010Vec *b, Ov010Vec *c);
extern void VEC_Normalize(const Ov010Vec *a, Ov010Vec *b);
extern void func_ov010_0220078c(void *p);

static inline s32 Ov010k_Mul(s32 a, s64 b) {
    return (s32)((a * b + 0x800) >> 12);
}

static inline BOOL Ov010Beam_Idle(u8 *b) {
    BOOL r = TRUE;
    if (FLD(u8, b, 0) != 0) {
        r = FLD(u8, b, 0x7f) == 5;
    }
    return r;
}

static inline s32 Ov010Beam_Mode(u8 *b) {
    s32 r = 0;
    if (FLD(u8, b, 0) != 0) {
        r = FLD(s32, b, 0x18);
    }
    return r;
}

static inline u16 Ov010Beam_GetA(u8 *b) {
    u16 r = 0;
    if (FLD(u8, b, 0) != 0 && !Ov010Beam_Idle(b)) {
        r = FLD(u16, b, 0x10);
    }
    return r;
}

static inline void Ov010Beam_SetA(u8 *b, u16 v) {
    if (*b != 0 && !Ov010Beam_Idle(b)) {
        FLD(u16, b, 0x10) = v;
        if (FLD(Ov010Flags8, b, 0x28).b0) {
            FLD(u16, b, 0x36) = v;
        }
    }
}

static inline u16 Ov010Beam_GetB(u8 *b) {
    u16 r = 0;
    if (FLD(u8, b, 0) != 0 && !Ov010Beam_Idle(b)) {
        r = FLD(u16, b, 0x12);
    }
    return r;
}

static inline void Ov010Beam_SetB(u8 *b, u16 v) {
    if (*b != 0 && !Ov010Beam_Idle(b)) {
        FLD(u16, b, 0x12) = v;
        if (FLD(Ov010Flags8, b, 0x28).b0) {
            FLD(u16, b, 0x38) = v;
        }
    }
}

void func_ov010_02201064(u8 *self) {
    BOOL all;
    u16 ang;
    u8 *n;
    u8 *n1;
    u8 *n2;
    Ov010Vec tmp;
    Ov010Vec res;
    Ov010Vec d;
    Ov010Vec v;
    if (!FLD(Ov010Flags8, self, 0).b0) {
        return;
    }
    switch (FLD(u16, self, 0x2c)) {
    case 0:
        FLD(u16, self, 0xa) = 0;
        FLD(u16, self, 0xc) = 0;
        FLD(u16, self, 0x2c) = 10;
        break;
    case 10: {
        u8 *last = NULL;
        for (n1 = FLD(u8 *, self, 0x10); n1 != NULL; n1 = FLD(u8 *, n1, 8)) {
            if (Ov010Beam_Idle(n1 + 0xc)) {
                last = n1;
            }
        }
        if (last != NULL) {
            BOOL flag = FLD(u16, self, 0x2e) % 3 == 0;
            s32 len;
            u16 ry;
            u16 rx;
            u16 t;
            if ((s32)FLD(u16, self, 0xa) >= 3) {
                u16 r = func_02040498(2);
                FLD(u16, self, 0xa) = 0;
                FLD(u16, self, 0xc) = r;
                FLD(u16, self, 0xa)++;
            } else {
                FLD(u16, self, 0xc)++;
                if ((s32)FLD(u16, self, 0xc) >= 3) {
                    FLD(u16, self, 0xc) = 0;
                }
                FLD(u16, self, 0xa)++;
            }
            {
                u16 c = FLD(u16, self, 0xc);
                ang = c * 0x5555 + func_02040498(0x5555);
            }
            if (flag) {
                len = Ov010k_Mul(func_020404e0(), 0x2cd);
            } else {
                len = Ov010k_Mul(func_020404e0(), 0xb33) + 0x4cd;
            }
            if (len > 0x1000) {
                len = 0x1000;
            } else if (len < 0) {
                len = 0;
            }
            func_ov003_021d9a00(&v, ang, &data_ov010_0220ef80);
            len = Ov010k_Mul(len, 0xc000);
            v.x = Ov010_FxMul(v.x, len);
            v.y = Ov010_FxMul(v.y, len);
            v.z = Ov010_FxMul(v.z, len);
            v.y = Ov010k_Mul(v.y, 0x980);
            func_ov003_021d9980(&v, func_ov003_021d9c50(&FLD(Ov010Vec, self, 0x14), &FLD(Ov010Vec, self, 0x20)), &v);
            OV010_BLKCPY(&tmp, &v);
            VEC_Add(&FLD(Ov010Vec, self, 0x14), &tmp, &res);
            d.x = res.x - FLD(s32, self, 0x20);
            d.y = res.y - FLD(s32, self, 0x24);
            d.z = res.z - FLD(s32, self, 0x28);
            VEC_Normalize(&d, &d);
            ry = func_ov003_021d9c74(&d);
            rx = func_ov003_021d9c38(&d);
            t = func_02040498(10) + 10;
            {
                s32 s = func_02040528(2);
                s = s > 0 ? s + 0x16 : s - 0x16;
                FLD(u8, last, 0) = 0;
                FLD(u16, last, 2) = 0;
                FLD(u16, last, 4) = 0;
                FLD(u16, last, 6) = s;
            }
            if (FLD(u8, last, 0xc) != 0 && FLD(u8, last, 0x8b) == 5) {
                FLD(u16, last, 0x7a) = 0;
                func_ov000_02198360(last + 0x78, 0, 0);
                FLD(s32, last, 0x28) = FLD(s32, self, 0x20);
                FLD(s32, last, 0x2c) = FLD(s32, self, 0x24);
                FLD(s32, last, 0x30) = FLD(s32, self, 0x28);
                FLD(u16, last, 0x1c) = ry;
                FLD(u16, last, 0x1e) = rx;
                FLD(u16, last, 0x18) = 0xc20;
                FLD(u16, last, 0x1a) = 0x4000;
                FLD(u16, last, 0x16) = t;
            }
        }
        for (n2 = FLD(u8 *, self, 0x10); n2 != NULL; n2 = FLD(u8 *, n2, 8)) {
            u8 *b = n2 + 0xc;
            if (Ov010Beam_Idle(b)) {
                continue;
            }
            if (Ov010Beam_Mode(b) == 1) {
                FLD(u8, n2, 0) = 1;
            } else if (Ov010Beam_Mode(b) == 2) {
                FLD(u8, n2, 0) = 0;
            }
            if (FLD(u8, n2, 0) != 0) {
                FLD(u16, n2, 2) += 4;
                FLD(u16, n2, 2) = FLD(u16, n2, 2) > 0x24 ? 0x24 : FLD(u16, n2, 2);
                FLD(u16, n2, 4) = FLD(u16, n2, 6);
            } else {
                FLD(u16, n2, 2) = Ov010k_Mul(FLD(u16, n2, 2) << 12, 0x1000) >> 12;
                FLD(u16, n2, 4) = 0;
            }
            {
                u16 dd = 0xffff - FLD(u16, n2, 2);
                u16 cur = Ov010Beam_GetA(b);
                Ov010Beam_SetA(b, cur + dd);
            }
            {
                u16 dd = FLD(u16, n2, 4);
                u16 cur = Ov010Beam_GetB(b);
                Ov010Beam_SetB(b, cur + dd);
            }
        }
        if (FLD(u16, self, 8) < CFLD(u16, self, 0x2e)) {
            FLD(u16, self, 0x2e) = 0;
            FLD(u16, self, 0x2c) = 100;
        } else {
            FLD(u16, self, 0x2e)++;
        }
        break;
    }
    case 100: {
        all = TRUE;
        for (n = FLD(u8 *, self, 0x10); n != NULL; n = FLD(u8 *, n, 8)) {
            if (!Ov010Beam_Idle(n + 0xc)) {
                all = FALSE;
            }
        }
        if (all) {
            FLD(u16, self, 0x2c) = 101;
        }
        break;
    }
    case 101:
        break;
    }
    for (n = FLD(u8 *, self, 0x10); n != NULL; n = FLD(u8 *, n, 8)) {
        func_ov010_0220078c(n + 0xc);
    }
}


}
