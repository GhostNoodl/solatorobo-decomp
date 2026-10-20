#include "ov015/ov015.h"

extern "C" {

s32 FX_Div(s32 a, s32 b);
s32 func_02049130(s32 t, s32 a, s32 b);
void VEC_Normalize(void *src, void *dst);
void func_ov015_0220afcc(u8 *self);
void func_ov015_0220b1b8(u8 *self);
void func_ov015_0220ac40(u8 *self, u8 *p);
void func_ov015_0220ad68(u8 *self, u8 *p);
BOOL func_ov015_0220ae90(u8 *self);
s32 func_02040498(s32 max);
void func_02049a48(void *a, s32 b, s32 c, s32 d, s32 e);
extern void *data_02097e4c;
extern u8 data_ov015_02212f20[];
extern u8 data_ov015_02212f04[];

static inline s32 Ov015_FxMul64(s32 a, s64 b) {
    return (s32)((a * b + 0x800) >> 12);
}

static inline void *Ov015_NewTask18(void) {
    void *t = func_0203dd9c(0x18);
    if (t != NULL) {
        SET_VT(t, data_ov015_02212f20);
        FLD(s32, t, 0x4) = 0;
        FLD(s32, t, 0x8) = 0;
        FLD(s32, t, 0xc) = 0;
        FLD(s32, t, 0x10) = 0;
        FLD(s32, t, 0x14) = 0;
    }
    return t;
}

static inline void *Ov015_NewTask1c(void) {
    void *t = func_0203dd9c(0x1c);
    if (t != NULL) {
        SET_VT(t, data_ov015_02212f04);
        FLD(s32, t, 0x4) = 0;
        FLD(s32, t, 0x8) = 0;
        FLD(s32, t, 0xc) = 0;
        FLD(s32, t, 0x10) = 0;
        FLD(s32, t, 0x18) = 0;
    }
    return t;
}

static inline void Ov015_Sounds(void) {
    func_02049a48(data_02097e4c, 0x55, -1, -1, -1);
    func_02049a48(data_02097e4c, 0x3e, -1, -1, -1);
}

static inline s32 Ov015_Speed(u8 *self) {
    s32 b = Ov015_FxMul64(FLD(s16, FLD(u8 *, self, 0x20), 0xca) << 4, 0x19a) + 0x800;
    return func_02049130(Ov015_FxMul(FLD(s32, self, 0x18), FLD(s32, self, 0x18)), b / 5, b);
}

static inline s32 Ov015_Wait(u8 *self) {
    s32 c = FLD(s16, FLD(u8 *, self, 0x20), 0xca) << 4;
    BOOL in;
    s32 b;
    s32 n;
    BOOL inX;
    BOOL inZ;
    u8 *q;
    s32 a;
    a = 0xf0000 - Ov015_FxMul64(c, 0xf000);
    if (a < 0xb4000) {
        a = 0xb4000;
    }
    b = 0x78000 - Ov015_FxMul64(c, 0x1e000);
    if (b < 0) {
        b = 0;
    }
    n = (s16)((b + func_02040498(a - b)) >> 12);
    q = FLD(u8 *, self, 0x20);
    in = FALSE;
    inZ = FALSE;
    inX = FALSE;
    if (FLD(s32, q, 0x40) >= FLD(s32, q, 0xac) && FLD(s32, q, 0x40) <= FLD(s32, q, 0xb0)) {
        inX = TRUE;
    }
    if (inX && FLD(s32, q, 0x48) <= FLD(s32, q, 0xb4)) {
        inZ = TRUE;
    }
    if (inZ && FLD(s32, q, 0x48) >= FLD(s32, q, 0xb8)) {
        in = TRUE;
    }
    if (!in && n > 200) {
        n = 200;
    }
    return n;
}

BOOL func_ov015_0220a1f8(u8 *self, u8 *p) {
    Ov015Stat *g = &data_ov015_0221332c;
    FLD(u8 *, self, 0x20) = p;
    FLD(bool, self, 0x14) = FALSE;
    if (g->unk_28 != 3) {
        FLD(bool, self, 0x14) |= g->unk_14 == 3 && FLD(s32, p, 0xbc) == 2;
        FLD(bool, self, 0x14) |= g->unk_14 == 2 && FLD(s32, FLD(u8 *, self, 0x20), 0xbc) == 3;
        if (FLD(bool, self, 0x14)) {
            FLD(s16, self, 0x16)--;
            if (FLD(s16, self, 0x16) <= 0) {
                FLD(s16, self, 0x16) = 0;
            }
        } else {
            FLD(s16, self, 0x16) = 0x5a;
        }
        FLD(s32, self, 0x18) = FX_Div(FLD(s16, self, 0x16) << 12, 0x5a000);
    }
    if (func_ov015_0220ae90(self)) {
        FLD(void *, p, 0xf0) = Ov015_NewTask18();
        FLD(s32, p, 0xec) = 3;
        return TRUE;
    }
    if (g->unk_00 < 0xfa000) {
        FLD(s32, p, 0xac) = -0x21555;
        FLD(s32, p, 0xb0) = 0x21555;
    } else {
        FLD(s32, p, 0xac) = -0x32000;
        FLD(s32, p, 0xb0) = 0x32000;
    }
    switch (FLD(s16, self, 0x4)) {
    case 0:
        if (FLD(s16, self, 0x6) <= 0) {
            FLD(s16, self, 0x4) = func_02040498(1) != 0 ? 5 : 6;
            FLD(s16, self, 0x6) = 0x1e;
        }
        break;
    case 1: {
        Ov015VecC pos(*(Ov015VecC *)(p + 0x40));
        Ov015VecC dir(*(Ov015VecC *)(p + 0x9c));
        s32 d = Ov015_Speed(self);
        FLD(s32, p, 0x40) = pos.x - d;
        FLD(s32, p, 0xa8) = d;
        FLD(s32, p, 0x44) = pos.y;
        FLD(s32, p, 0x48) = pos.z;
        dir.x -= d;
        VEC_Normalize(&dir, p + 0x9c);
        func_ov015_0220afcc(self);
        func_ov015_0220b1b8(self);
        if (FLD(s16, self, 0x6) <= 0 || FLD(s32, p, 0x40) < FLD(s32, p, 0xac)) {
            FLD(s32, p, 0xbc) = 3;
            FLD(s16, self, 0x4) = 4;
            FLD(s16, self, 0x6) = 0x14;
            Ov015_Sounds();
        }
        break;
    }
    case 2: {
        Ov015VecC pos(*(Ov015VecC *)(p + 0x40));
        Ov015VecC dir(*(Ov015VecC *)(p + 0x9c));
        s32 d = Ov015_Speed(self);
        FLD(s32, p, 0x40) = pos.x + d;
        FLD(s32, p, 0xa8) = d;
        FLD(s32, p, 0x44) = pos.y;
        FLD(s32, p, 0x48) = pos.z;
        dir.x += d;
        VEC_Normalize(&dir, p + 0x9c);
        func_ov015_0220afcc(self);
        func_ov015_0220b1b8(self);
        if (FLD(s16, self, 0x6) <= 0 || FLD(s32, p, 0x40) > FLD(s32, p, 0xb0)) {
            FLD(s32, p, 0xbc) = 2;
            FLD(s16, self, 0x4) = 3;
            FLD(s16, self, 0x6) = 0x14;
            Ov015_Sounds();
        }
        break;
    }
    case 3:
        func_ov015_0220ac40(self, p);
        if (FLD(s16, self, 0x6) <= 0) {
            FLD(s32, p, 0xbc) = 3;
            FLD(s16, self, 0x4) = 5;
            FLD(s16, self, 0x6) = 0x1e;
        }
        break;
    case 4:
        func_ov015_0220ad68(self, p);
        if (FLD(s16, self, 0x6) <= 0) {
            FLD(s32, p, 0xbc) = 2;
            FLD(s16, self, 0x4) = 6;
            FLD(s16, self, 0x6) = 0x1e;
        }
        break;
    case 5: {
        Ov015VecC pos(*(Ov015VecC *)(p + 0x40));
        Ov015VecC dir(*(Ov015VecC *)(p + 0x9c));
        s32 t = FX_Div((0x1e - FLD(s16, self, 0x6)) << 12, 0x1e000);
        s32 d = Ov015_FxMul(Ov015_Speed(self), t);
        BOOL spawn;
        FLD(s32, p, 0x40) = pos.x - d;
        FLD(s32, p, 0x44) = pos.y;
        FLD(s32, p, 0x48) = pos.z;
        FLD(s32, p, 0xa8) = d;
        dir.z = Ov015_FxMul(dir.z, 0xfae);
        dir.x -= 0x29;
        VEC_Normalize(&dir, p + 0x9c);
        func_ov015_0220afcc(self);
        func_ov015_0220b1b8(self);
        if (FLD(s16, self, 0x6) > 0) {
            break;
        }
        FLD(s32, p, 0xbc) = 3;
        spawn = FALSE;
        if (FLD(s16, self, 0x8) != 0) {
            FLD(s16, self, 0x8)--;
            if (FLD(s16, self, 0x8) <= 0) {
                FLD(s16, self, 0x8) = 0;
            }
        } else {
            u8 *q = FLD(u8 *, self, 0x20);
            if (FLD(s16, q, 0xd8) != 0 && func_02040498(0x1000) < FLD(s16, q, 0xd8) << 4) {
                spawn = TRUE;
            }
        }
        if (spawn) {
            FLD(void *, p, 0xf0) = Ov015_NewTask1c();
            FLD(s32, p, 0xec) = 4;
        }
        FLD(s16, self, 0x4) = 1;
        FLD(s16, self, 0x6) = Ov015_Wait(self);
        break;
    }
    case 6: {
        Ov015VecC pos(*(Ov015VecC *)(p + 0x40));
        Ov015VecC dir(*(Ov015VecC *)(p + 0x9c));
        s32 t = FX_Div((0x1e - FLD(s16, self, 0x6)) << 12, 0x1e000);
        s32 d = Ov015_FxMul(Ov015_Speed(self), t);
        BOOL spawn;
        FLD(s32, p, 0x40) = pos.x + d;
        FLD(s32, p, 0x44) = pos.y;
        FLD(s32, p, 0x48) = pos.z;
        FLD(s32, p, 0xa8) = d;
        dir.z = Ov015_FxMul(dir.z, 0xfae);
        dir.x += 0x29;
        VEC_Normalize(&dir, p + 0x9c);
        func_ov015_0220afcc(self);
        func_ov015_0220b1b8(self);
        if (FLD(s16, self, 0x6) > 0) {
            break;
        }
        FLD(s32, p, 0xbc) = 2;
        spawn = FALSE;
        if (FLD(s16, self, 0x8) != 0) {
            FLD(s16, self, 0x8)--;
            if (FLD(s16, self, 0x8) <= 0) {
                FLD(s16, self, 0x8) = 0;
            }
        } else {
            u8 *q = FLD(u8 *, self, 0x20);
            if (FLD(s16, q, 0xd8) != 0 && func_02040498(0x1000) < FLD(s16, q, 0xd8) << 4) {
                spawn = TRUE;
            }
        }
        if (spawn) {
            FLD(void *, p, 0xf0) = Ov015_NewTask1c();
            FLD(s32, p, 0xec) = 4;
        }
        FLD(s16, self, 0x4) = 2;
        FLD(s16, self, 0x6) = Ov015_Wait(self);
        break;
    }
    }
    FLD(s16, self, 0x6)--;
    if (FLD(s16, self, 0x6) <= 0) {
        FLD(s16, self, 0x6) = 0;
    }
    return TRUE;
}

}
