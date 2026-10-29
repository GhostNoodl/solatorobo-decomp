#include "ov000/LoCommon.h"

extern "C" {

extern const s16 FX_SinCosTable_[];
extern u8 *data_ov000_021ccd54;
void MTX_Identity43_(void *m);
void MTX_RotY43_(void *m, s32 s, s32 c);
void func_020627fc(s32 a);
void func_ov000_02182590(void *p);
void func_ov000_02188140(void *p, s32 a, s32 b, s32 c);

void func_ov000_0216d9dc(void *self, s32 unused, u16 *msg) {
    u16 type = msg[0];
    void *p = LFLD(void *, msg, 8);
    u16 ang;
    if (type != 0x1e) {
        return;
    }
    ang = LFLD(u16, p, 0x44);
    MTX_Identity43_(self);
    MTX_RotY43_(self, FX_SinCosTable_[(ang >> 4) * 2], FX_SinCosTable_[(ang >> 4) * 2 + 1]);
}

void func_ov000_0216da2c(void *self, s32 a, s32 b, s32 c) {
    LFLD(s32, self, 8) = a;
    LFLD(s32, self, 0x24) = b;
    LFLD(s32, self, 0x28) = c;
    switch (a) {
    case 1:
        LFLD(s32, self, 0x20) = 0;
        LFLD(s32, self, 0x1c) = 0;
        if (b == 0) {
            LFLD(s32, self, 0x24) = 0x7fffffff;
        }
        break;
    case 2:
        LFLD(s32, self, 0x20) = b;
        LFLD(s32, self, 0x1c) = b;
        break;
    }
    LBIT(self, 0).b7 = 0;
}

void func_ov000_0216da78(void *self) {
    s32 v = LFLD(s32, self, 0x1c);
    LBIT(self, 0).b9 = 1;
    LBIT(self, 0).b16 = 0;
    LBIT(self, 0).b5 = 1;
    LBIT(self, 0).b8 = 1;
    LFLD(s32, self, 0x20) = v;
    if (LBIT(self, 0).b6 == 1) {
        u8 *d;
        func_020627fc(4);
        d = data_ov000_021ccd54;
        d[0xac] = 1;
        func_ov000_02182590(d + 0xac);
        func_ov000_02188140(data_ov000_021ccd54, 0xffff, 0, 0);
    }
}

}


typedef struct {
    u32 b0 : 1;
    u32 b1 : 1;
    u32 b2 : 1;
    u32 b3 : 1;
    u32 b4 : 1;
    u32 b5 : 1;
    u32 b6 : 1;
    u32 b7 : 1;
    u32 b8 : 1;
    u32 b9 : 1;
    u32 b10 : 4;
    u32 b14 : 1;
    u32 b15 : 1;
    u32 b16 : 1;
    u32 b17 : 1;
    u32 f18 : 4;
    u32 b22 : 1;
    u32 rest : 9;
} Bits0216dae4;

extern "C" {
extern const s16 FX_SinCosTable_[];
extern int data_02097d78[];
extern u8 *data_ov000_021ccd54;
bool func_ov000_021735e8(void);
void func_ov000_0216e67c(void *self);
void func_ov000_0216eaf8(void *self);
void func_ov000_0216e968(void *self);
BOOL func_02054f10(void *a, s32 b);
s32 FX_Div(s32 a, s32 b);
void func_020627fc(s32 a);
void func_ov000_02182590(void *p);
void func_ov000_02188140(void *p, s32 a, s32 b, s32 c);

#define B(self) LFLD(Bits0216dae4, self, 0)

static inline BOOL GBusy0216dae4(u8 *g) {
    return LFLD(s32, g, 0x90) != LFLD(s32, g, 0x94) ? TRUE : FALSE;
}

static inline BOOL GIdle0216dae4(void) {
    u8 *g = data_ov000_021ccd54;
    if (g != NULL) {
        if (GBusy0216dae4(g)) {
            return FALSE;
        }
        if (LFLD(s32, g, 0) != 3) {
            return FALSE;
        }
        return TRUE;
    }
    return TRUE;
}

static inline BOOL FadeIdle0216dae4(void) {
    return (data_02097d78[3] == 0 && data_02097d78[0] == 0) ? TRUE : FALSE;
}

static inline BOOL Ready0216dae4(u8 *self) {
    if (!func_02054f10(LFLD(void *, self, 0x10), 0xffff) || !func_02054f10(LFLD(void *, self, 0x14), 0xffff)) {
        return FALSE;
    }
    return TRUE;
}

static inline void Done0216dae4(void *self) {
    s32 v = LFLD(s32, self, 0x1c);
    LFLD(s32, self, 0x20) = v;
    LBIT(self, 0).b9 = 1;
    LBIT(self, 0).b16 = 0;
    LBIT(self, 0).b5 = 1;
    LBIT(self, 0).b8 = 1;
    if (LBIT(self, 0).b6 == 1) {
        u8 *d;
        func_020627fc(4);
        d = data_ov000_021ccd54;
        d[0xac] = 1;
        func_ov000_02182590(d + 0xac);
        func_ov000_02188140(data_ov000_021ccd54, 0xffff, 0, 0);
    }
}

BOOL func_ov000_0216dae4(u8 *self) {
    if (B(self).b2 == 1) {
        if (!B(self).b0 && !func_ov000_021735e8()) {
            B(self).b4 = 1;
        } else if (LFLD(s32, self, 4) == 7 || LFLD(s32, self, 4) == 9) {
            B(self).b4 = 0;
            B(self).f18 = 0;
        }
    }
    switch (LFLD(s32, self, 4)) {
    case 3:
        return FALSE;
    case 0:
        LFLD(s32, self, 4) = 1;
    case 1:
        LFLD(s32, self, 4) = 4;
    case 4:
        if (B(self).b2 && B(self).b4) {
            B(self).b3 = 1;
            LFLD(s32, self, 4) = 5;
        } else {
            if (B(self).b0) {
                LFLD(s32, self, 4) = 3;
            }
            break;
        }
    case 5:
        func_ov000_0216e67c(self);
        LFLD(s32, self, 4) = 6;
    case 6:
        if (!Ready0216dae4(self)) {
            break;
        }
        B(self).b5 = 1;
        LFLD(s32, self, 0x2c) = 0;
        LFLD(s32, self, 0x30) = 0x1000;
        LFLD(s32, self, 4) = 8;
    case 8: {
        s32 t;
        LFLD(s32, self, 0x2c) += 0x1000;
        t = FX_Div(LFLD(s32, self, 0x2c), 0x1e000);
        if (t >= 0x1000) {
            LFLD(s32, self, 0x2c) = 0;
            B(self).b5 = 0;
            t = 0x1000;
            if (B(self).b3) {
                LFLD(s32, self, 4) = 7;
            } else {
                LFLD(s32, self, 4) = 4;
                break;
            }
        }
        LFLD(s32, self, 0x30) = FX_SinCosTable_[(((t * 0x4000) >> 12) >> 4) * 2];
        if (B(self).b3) {
            LFLD(s32, self, 0x30) = 0x1000 - LFLD(s32, self, 0x30);
        }
    }
    case 7:
        if (B(self).b9 == 1) {
            func_ov000_0216eaf8(self);
        } else if ((B(self).b22 || FadeIdle0216dae4()) && (!B(self).b6 || GIdle0216dae4()) && B(self).b7 == 1) {
            if (LFLD(s32, self, 8) == 2) {
                LFLD(s32, self, 0x1c) -= LFLD(s32, self, 0x18);
                if (LFLD(s32, self, 0x1c) <= 0) {
                    LFLD(s32, self, 0x1c) = 0;
                    B(self).b14 = 1;
                    if (B(self).b6 == 1) {
                        Done0216dae4(self);
                    }
                }
            } else {
                LFLD(s32, self, 0x1c) += LFLD(s32, self, 0x18);
                if (LFLD(s32, self, 0x1c) >= 0x57e40) {
                    LFLD(s32, self, 0x1c) = 0x57e40;
                }
                if (LFLD(s32, self, 0x1c) > LFLD(s32, self, 0x24)) {
                    LFLD(s32, self, 0x1c) = LFLD(s32, self, 0x24);
                    B(self).b14 = 1;
                    if (B(self).b6 == 1) {
                        Done0216dae4(self);
                    }
                }
            }
        }
        if (B(self).b8 != 1) {
            LFLD(s32, self, 0x20) = LFLD(s32, self, 0x1c);
        } else {
            func_ov000_0216e968(self);
        }
    case 9:
        if (!B(self).b2 || !B(self).b4) {
            B(self).b5 = 1;
            B(self).b3 = 0;
            LFLD(s32, self, 4) = 8;
        }
        break;
    }
    return TRUE;
}
}
