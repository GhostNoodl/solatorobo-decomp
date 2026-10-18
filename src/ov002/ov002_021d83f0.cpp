#include "ov002/ov002.h"

extern "C" {

void func_0204918c(void *out, s32 t, void *a, void *b);
s32 func_02049130(s32 t, s32 a, s32 b);
void MTX_RotY33_(void *m, s32 s, s32 c);
void func_ov002_021d8860(void *self);

static inline s32 FX_Mul(s32 a, s32 b) {
    return (s32)(((s64)a * b + 0x800) >> 12);
}

static inline void ov002_SetState(void *self, s32 st) {
    if (FIELD(self, 0xac, s32) != st) {
        FIELD(self, 0xac, s32) = st;
        FIELD(self, 0xa4, s32) = 0;
        FIELD(self, 0xa8, s32) = 5;
    }
}

static inline s32 ov002_GetT(void *self) {
    return FX_Div(FIELD(self, 0xa4, s32) << 12, FIELD(self, 0xa8, s32) << 12);
}

void func_ov002_021d83f0(void *self) {
    switch (FIELD(self, 0xac, s32)) {
    case 1:
        FIELD(self, 0x8, s32) = 0x400;
        FIELD(self, 0x44, s32) = 0x119a;
        FIELD(self, 0x3c, s32) = 0x119a;
        break;
    case 2:
        FIELD(self, 0x8, s32) = 0x29;
        FIELD(self, 0x44, s32) = 0x1000;
        FIELD(self, 0x3c, s32) = 0x1000;
        if (FIELD(self, 0xcd, u8) == 0) {
            FIELD(self, 0x9c, s32) = 0x1000;
        } else {
            FIELD(self, 0x9c, s32) = FX_MUL(FX_SINCOS(((FIELD(self, 0xd0, s32) * 0x444) >> 4) * 2), 0xb5c) + 0x429;
        }
        break;
    case 4: {
        s32 t = ov002_GetT(self);
        func_0204918c((u8 *)self + 0x4, t, (u8 *)self + 0xb0, (u8 *)self + 0xbc);
        if (FIELD(self, 0xa4, s32) == 0) {
            ov002_SetState(self, 1);
        }
        break;
    }
    case 5: {
        s32 t = ov002_GetT(self);
        s32 to;
        s32 from;
        u16 ang;
        FIELD(self, 0x10, s16) = 0;
        to = FIELD(self, 0xcc, u8) * 0x3fff << 12;
        from = (FIELD(self, 0xc8, s32) << 12) + to;
        ang = (from + FX_Mul(to - from, t)) >> 12;
        FIELD(self, 0x12, u16) = ang;
        FIELD(self, 0x14, s16) = 0;
        MTX_Identity33_((u8 *)self + 0x18);
        if (ang != 0) {
            MTX_RotY33_((u8 *)self + 0x18, FX_SINCOS((ang >> 4) * 2), FX_SINCOS((ang >> 4) * 2 + 1));
        }
        if (FIELD(self, 0xa4, s32) == 0) {
            ov002_SetState(self, 1);
        }
        break;
    }
    case 6: {
        s32 t = ov002_GetT(self);
        s32 v;
        FIELD(self, 0x8, s32) = func_02049130(t, 0x29, 0x400);
        v = func_02049130(t, 0x1000, 0x119a);
        FIELD(self, 0x3c, s32) = v;
        FIELD(self, 0x44, s32) = v;
        FIELD(self, 0x9c, s32) = FX_Div((u8)(func_02049130(t, 0x1f000, 0xd000) >> 12) << 12, 0x1f000);
        if (FIELD(self, 0xa4, s32) == 0) {
            ov002_SetState(self, 2);
        }
        break;
    }
    case 7: {
        s32 t = ov002_GetT(self);
        s32 v;
        FIELD(self, 0x8, s32) = func_02049130(t, 0x400, 0x29);
        v = func_02049130(t, 0x119a, 0x1000);
        FIELD(self, 0x3c, s32) = v;
        FIELD(self, 0x44, s32) = v;
        FIELD(self, 0x9c, s32) = FX_Div((u8)(func_02049130(t, 0xd000, 0x1f000) >> 12) << 12, 0x1f000);
        if (FIELD(self, 0xa4, s32) == 0) {
            ov002_SetState(self, 1);
        }
        break;
    }
    case 8: {
        s32 t = ov002_GetT(self);
        s32 v;
        func_0204918c((u8 *)self + 0x4, t, (u8 *)self + 0xb0, (u8 *)self + 0xbc);
        FIELD(self, 0x8, s32) = 0x400;
        v = func_02049130(t, 0, 0x119a);
        FIELD(self, 0x3c, s32) = v;
        FIELD(self, 0x44, s32) = v;
        FIELD(self, 0x9c, s32) = FX_Div((u8)(func_02049130(t, 0x1f000, 0xd000) >> 12) << 12, 0x1f000);
        if (FIELD(self, 0xa4, s32) == 0) {
            ov002_SetState(self, 0);
        }
        break;
    }
    case 9: {
        s32 t = ov002_GetT(self);
        s32 v;
        func_0204918c((u8 *)self + 0x4, t, (u8 *)self + 0xb0, (u8 *)self + 0xbc);
        FIELD(self, 0x8, s32) = 0x400;
        v = func_02049130(t, 0x119a, 0);
        FIELD(self, 0x3c, s32) = v;
        FIELD(self, 0x44, s32) = v;
        FIELD(self, 0x9c, s32) = FX_Div((u8)(func_02049130(t, 0xd000, 0x1f000) >> 12) << 12, 0x1f000);
        if (FIELD(self, 0xa4, s32) == 0) {
            ov002_SetState(self, 1);
        }
        break;
    }
    case 10:
        func_ov002_021d8860(self);
        if (FIELD(self, 0xa4, s32) == 0) {
            ov002_SetState(self, 3);
        }
        break;
    }
    if (--FIELD(self, 0xa4, s32) < 0) {
        FIELD(self, 0xa4, s32) = 0;
    }
    if (FIELD(self, 0xcd, u8)) {
        FIELD(self, 0xd0, s32)++;
        FIELD(self, 0xd0, s32) %= 30;
    }
}

}
