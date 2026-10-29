#include "ov000/LoCommon.h"

class Robo021a0d4cCls;
typedef void (Robo021a0d4cCls::*Robo021a0d4cPmf)();

typedef struct {
    s32 key;
    Robo021a0d4cPmf fn;
} Robo021a0d4cEntry;

typedef struct {
    u32 b0 : 1;
    u32 b1 : 1;
    u32 f2 : 2;
    u32 b4 : 1;
    u32 f5 : 2;
    u32 f7 : 2;
    u32 b9 : 1;
    u32 b10 : 2;
    u32 mode : 2;
    u32 f14 : 2;
    u32 b16 : 10;
    u32 b26 : 1;
    u32 rest : 5;
} B24_021a0d4c;

typedef struct {
    u16 lo : 3;
    u16 b3 : 1;
    u16 b4 : 1;
    u16 b5 : 1;
    u16 kind : 3;
    u16 f9 : 2;
    u16 rest : 5;
} B22_021a0d4c;

typedef struct {
    u8 b0 : 1;
    u8 b1 : 1;
    u8 b2 : 1;
    u8 b3 : 1;
    u8 b4 : 1;
    u8 rest : 3;
} B8_021a0d4c;

typedef struct {
    u16 b0 : 8;
    u16 b8 : 1;
    u16 rest : 7;
} B9a_021a0d4c;

typedef struct {
    u16 b0 : 1;
    u16 sel : 2;
    u16 b3 : 6;
    u16 b9 : 1;
    u16 b10 : 1;
    u16 rest : 5;
} G18_021a0d4c;

typedef struct {
    u32 b0 : 1;
    u32 b1 : 1;
    u32 rest : 30;
} Bd_021a0d4c;

typedef struct {
    u8 b0 : 4;
    u8 hi : 4;
} Bq_021a0d4c;

extern "C" {
extern Robo021a0d4cEntry data_ov000_021ca458[];
extern u8 *data_ov000_021ccd54;
extern u8 *data_ov000_021ccd30;
extern void *data_ov000_021ccd68;
extern void *data_ov000_021ccd64;
extern u8 *data_ov000_021ccd6c;
extern u8 *data_02149f0c;
extern u8 *data_0214a424;
void func_ov000_021b06dc(u8 *self);
u8 *func_ov000_0218e640(void *mgr, u16 id);
void func_ov000_0216adc0(void *p, s32 a, u16 b);
void func_ov000_021b3d78(u8 *self);
void func_ov000_0218c208(void *a, void *pos, u16 ang);
void func_ov000_0219a088(void *p);
void func_ov000_0219a0b0(void *p, u8 *self);
void func_ov000_0216b508(void *p, s32 a, BOOL b);
BOOL func_ov000_021bd314(void *p, s32 a);
void func_ov000_021bd624(void *p);
void func_ov000_021b1110(u8 *self, s32 a);
void func_ov000_021697dc(void *p, u16 a, u16 b);
void func_ov000_0216a438(void *p, u16 a, s32 b, BOOL c);

static inline u8 *GetObj021a0d4c(u16 id) {
    if (data_ov000_021ccd68 == NULL) {
        return NULL;
    }
    return func_ov000_0218e640(data_ov000_021ccd68, id);
}

static inline void Reset021a0d4c(u8 *self) {
    LFLD(B24_021a0d4c, self, 0xb24).f5 = 0;
    LFLD(u16, self, 0xb1c) = 0xffff;
    LFLD(u16, self, 0xb1e) = 0xffff;
    LFLD(B24_021a0d4c, self, 0xb24).f7 = LFLD(B24_021a0d4c, self, 0xb24).b9;
}

static inline u8 *Target021a0d4c(u8 *self) {
    u8 *o = GetObj021a0d4c(LFLD(u16, self, 0xb1c));
    u8 *p = NULL;
    if (o != NULL) {
        p = LFLD(u8 *, o, 0x4c);
    }
    if (p == NULL || LFLD(u16, p, 0x1c) != LFLD(u16, self, 0xc)) {
        Reset021a0d4c(self);
        return NULL;
    }
    return o;
}

static inline void Gauge021a0d4c(u16 v) {
    u8 *g = LFLD(u8 *, data_ov000_021ccd30, 0x11c);
    if (g != NULL && LFLD(void *, g, 0x78) != NULL) {
        func_ov000_0216adc0(LFLD(void *, g, 0x78), 1, v);
    }
}

static inline BOOL GBusy021a0d4c(u8 *g) {
    return LFLD(s32, g, 0x90) != LFLD(s32, g, 0x94) ? TRUE : FALSE;
}

static inline BOOL GIdle021a0d4c(void) {
    u8 *g = data_ov000_021ccd54;
    if (g != NULL) {
        if (GBusy021a0d4c(g)) {
            return FALSE;
        }
        if (LFLD(s32, g, 0) != 3) {
            return FALSE;
        }
        return TRUE;
    }
    return TRUE;
}

static inline BOOL RgbEq021a0d4c(u8 *a, u8 *b) {
    BOOL r = FALSE;
    if (a[0] == b[0] && a[1] == b[1] && a[2] == b[2]) {
        r = TRUE;
    }
    return r;
}

static inline BOOL NotB1_021a0d4c(u8 *self) {
    return !LFLD(B24_021a0d4c, self, 0xb24).b1 ? TRUE : FALSE;
}

static inline BOOL G9_021a0d4c(void) {
    return LFLD(G18_021a0d4c, data_0214a424, 0x18).b9 ? TRUE : FALSE;
}

static inline BOOL Ready021a0d4c(u8 *g) {
    if (GBusy021a0d4c(g)) return FALSE;
    if (LFLD(s32, g, 0) != 3) return FALSE;
    return TRUE;
}
static inline BOOL IdleG021a0d4c(u8 *g) {
    if (g != NULL) {
        return Ready021a0d4c(g);
    }
    return TRUE;
}
static inline BOOL Ok021a0d4c(u8 *self) {
    u8 *g = data_ov000_021ccd54;
    BOOL r = IdleG021a0d4c(g);
    if (r) {
        r = !LFLD(B8_021a0d4c, self, 0xb29).b1;
    }
    if (r) {
        r = LFLD(u8, self, 0xb28) == 0;
    }
    if (r) {
        r = LFLD(u8, self, 0xb2e) == 0;
    }
    if (r) {
        r = !LFLD(B24_021a0d4c, self, 0xb24).b0;
    }
    if (r) {
        r = !LFLD(B8_021a0d4c, self, 0xb29).b3;
    }
    if (r) {
        r = !NotB1_021a0d4c(self);
        if (!r) {
            BOOL t = G9_021a0d4c();
            r = !t;
            if (!t) {
                r = RgbEq021a0d4c(g + 0xca, self + 0x772);
            }
            if (r) {
                r = LFLD(B24_021a0d4c, self, 0xb24).f14 == 0;
            }
        }
    }
    return r;
}

static inline void Bar021a0d4c(u16 a, u16 b) {
    u8 *g = LFLD(u8 *, data_ov000_021ccd30, 0x11c);
    if (g != NULL && LFLD(void *, g, 0x58) != NULL) {
        func_ov000_021697dc(LFLD(void *, g, 0x58), a, b);
        LFLD(u32, LFLD(u8 *, g, 0x58), 0xc) |= 0x80;
    }
}

static inline void Mark021a0d4c(u16 a, s32 b, BOOL c) {
    u8 *g = LFLD(u8 *, data_ov000_021ccd30, 0x11c);
    if (g != NULL && LFLD(void *, g, 0x64) != NULL) {
        func_ov000_0216a438(LFLD(void *, g, 0x64), a, b, c);
    }
}

void func_ov000_021a0d4c(u8 *self) {

    s32 k;
    s32 i;

    if (LFLD(B22_021a0d4c, self, 0xb22).kind == 5) {
        func_ov000_021b06dc(self);
        return;
    }
    LFLD(u8, self, 0xb29) = 0;
    if (LFLD(u8, self, 0xb2e) != 0) {
        LFLD(u8, self, 0xb2e)--;
    }
    k = LFLD(u8, LFLD(u8 *, self, 0x40), 0x13);
    for (i = 0; i < 0x1d; i++) {
        if (k == *(s32 *)((u8 *)data_ov000_021ca458 + i * 12)) {
            (((Robo021a0d4cCls *)self)->*data_ov000_021ca458[i].fn)();
            break;
        }
    }
    if (!LFLD(B24_021a0d4c, self, 0xb24).b1) {
        LFLD(void *, self, 0x38) = self + 0xac;
        LFLD(void *, self, 0x48) = self + 0x2cc;
    } else {
        LFLD(void *, self, 0x38) = self + 0x368;
        LFLD(s32, self, 0x75c) = LFLD(s32, self, 0x70);
        LFLD(s32, self, 0x760) = LFLD(s32, self, 0x74);
        LFLD(s32, self, 0x764) = LFLD(s32, self, 0x78);
        LFLD(u16, self, 0x76c) = LFLD(u16, self, 0x7c);
        LFLD(u16, self, 0x76e) = LFLD(u16, self, 0x7e);
        LFLD(u16, self, 0x770) = LFLD(u16, self, 0x80);
        LFLD(void *, self, 0x48) = self + 0x6c0;
    }
    if (LFLD(B9a_021a0d4c, LFLD(u8 *, self, 0x48), 0x9a).b8) {
        u32 f = LFLD(u32, LFLD(u8 *, self, 0x48), 0x50);
        if ((f & 0x20000000) && !(f & 0x40400) && !(f & 0x40000000)) {
            LFLD(s32, self, 0xaf0) = LFLD(s32, self, 0x70);
            LFLD(s32, self, 0xaf4) = LFLD(s32, self, 0x74);
            LFLD(s32, self, 0xaf8) = LFLD(s32, self, 0x78);
        }
        if (LFLD(u32, LFLD(u8 *, self, 0x48), 0x54) & 0x20000000) {
            u8 *p = LFLD(u8 *, self, 0x48);
            LFLD(s32, self, 0xafc) = LFLD(s32, p, 0x68);
            LFLD(s32, self, 0xb00) = LFLD(s32, p, 0x6c);
            LFLD(s32, self, 0xb04) = LFLD(s32, p, 0x70);
        }
    }
    if (LFLD(B24_021a0d4c, self, 0xb24).f5 != 0 && !LFLD(B22_021a0d4c, self, 0xb22).b3) {
        u8 *o = Target021a0d4c(self);
        if (o != NULL) {
            u8 *p = LFLD(u8 *, o, 0x4c);
            u16 v = 0;
            if (p != NULL) {
                v = LFLD(u16, p, 0x1e);
            }
            if (v != 0) {
                Gauge021a0d4c(v);
                if (LFLD(u16, self, 0xb32) == 0) {
                    LFLD(u16, self, 0xb32)++;
                }
            }
        }
    }
    if (LFLD(B24_021a0d4c, self, 0xb24).mode == 3) {
        u8 *o = GetObj021a0d4c(LFLD(u16, self, 0xb20));
        u8 *p = NULL;
        if (o != NULL) {
            p = LFLD(u8 *, o, 0x4c);
        }
        if (p != NULL) {
            Gauge021a0d4c(LFLD(u16, p, 0x1e));
            if (LFLD(u16, self, 0xb32) == 0) {
                LFLD(u16, self, 0xb32)++;
            }
        }
    }
    func_ov000_021b3d78(self);
    func_ov000_0218c208(data_ov000_021ccd64, self + 0x70, LFLD(u16, self, 0x7e));
    if (LFLD(B24_021a0d4c, self, 0xb24).f2 != 1) {
        u8 *c = data_ov000_021ccd6c;
        LFLD(s32, c, 0x24) = LFLD(s32, self, 0x70);
        LFLD(s32, c, 0x28) = LFLD(s32, self, 0x74);
        LFLD(s32, c, 0x2c) = LFLD(s32, self, 0x78);
    }
    {
        u8 *c = data_02149f0c;
        LFLD(s32, c, 0) = LFLD(s32, self, 0x70);
        LFLD(s32, c, 4) = LFLD(s32, self, 0x74);
        LFLD(s32, c, 8) = LFLD(s32, self, 0x78);
    }
    if (LFLD(u16, LFLD(u8 *, self, 0x50), 0xa) != 0) {
        LFLD(u16, LFLD(u8 *, self, 0x50), 0xa)--;
    }
    func_ov000_0219a088(LFLD(void *, self, 0x54));
    {
        s32 a = 0;
        s32 b = 0;
        u8 *q = LFLD(u8 *, self, 0xba4);
        if (q != NULL && LFLD(B24_021a0d4c, self, 0xb24).b1 && !LFLD(B24_021a0d4c, self, 0xb24).b0) {
            b = LFLD(Bq_021a0d4c, q, 4).hi;
            if (b != 0) {
                b = b * 10;
                a = 0x2d0;
            }
        }
        LFLD(u16, self, 0xaea) = a;
        LFLD(u16, self, 0xaec) = b;
    }
    func_ov000_0219a0b0(self + 0xae8, self);
    LFLD(Bd_021a0d4c, LFLD(u8 *, self, 0x9b4), 0).b1 = 0;
    if (LFLD(B22_021a0d4c, self, 0xb22).lo != 0 && Ok021a0d4c(self)) {
        if (LFLD(B24_021a0d4c, self, 0xb24).b1) {
            BOOL f = LFLD(G18_021a0d4c, data_0214a424, 0x18).b10 ? TRUE : FALSE;
            u8 *g = LFLD(u8 *, data_ov000_021ccd30, 0x11c);
            if (g != NULL) {
                func_ov000_0216b508(LFLD(void *, g, 0x68), 1, f);
            }
        }
        if (LFLD(B22_021a0d4c, self, 0xb22).lo == 3 || LFLD(B22_021a0d4c, self, 0xb22).lo == 4) {
            func_ov000_021bd314(LFLD(void *, self, 0x9b4), 8);
            LFLD(Bd_021a0d4c, LFLD(u8 *, self, 0x9b4), 0).b1 = 1;
        } else {
            u8 *q = data_ov000_021ccd54 + 0xf4;
            if (q != NULL && LFLD(u16, q, 0xd6) - 1 == LFLD(u16, q, 0xd4)) {
                func_ov000_021bd314(LFLD(void *, self, 0x9b4), 9);
                LFLD(Bd_021a0d4c, LFLD(u8 *, self, 0x9b4), 0).b1 = 1;
            }
        }
    }
    func_ov000_021bd624(LFLD(void *, self, 0x9b4));
    func_ov000_021b1110(self, 0);
    if (LFLD(u16, self, 0xb32) != 0) {
        u16 m;
        LFLD(u16, self, 0xb32)--;
        m = LFLD(u16, LFLD(u8 *, self, 0x50), 2);
        if (LFLD(u16, self, 0xb34) < m) {
            LFLD(u16, self, 0xb34) += (u16)(m / 32);
            if (LFLD(u16, self, 0xb34) < m) {
                m = LFLD(u16, self, 0xb34);
                if (LFLD(u16, self, 0xb32) == 0) {
                    LFLD(u16, self, 0xb32)++;
                }
            } else {
                LFLD(u16, self, 0xb34) = m;
            }
        }
        if (GIdle021a0d4c() || LFLD(u16, self, 0xb34) < m) {
            Bar021a0d4c(LFLD(u16, LFLD(u8 *, self, 0x50), 0), m);
            if (LFLD(G18_021a0d4c, data_0214a424, 0x18).sel == 1 && !LFLD(B22_021a0d4c, self, 0xb22).b4) {
                BOOL on;
                if (!LFLD(B22_021a0d4c, self, 0xb22).b3 && LFLD(B22_021a0d4c, self, 0xb22).f9 == 0 &&
                    LFLD(B24_021a0d4c, self, 0xb24).b1 && LFLD(B8_021a0d4c, self, 0x93).b4 &&
                    !LFLD(B8_021a0d4c, self, 0xb29).b3 && LFLD(B22_021a0d4c, self, 0xb22).lo == 0 &&
                    LFLD(B24_021a0d4c, self, 0xb24).mode == 0 && LFLD(u8, LFLD(u8 *, self, 0x40), 0x13) != 0x11 &&
                    !(LFLD(u8, LFLD(u8 *, self, 0x40), 0x13) == 0xb && LFLD(B24_021a0d4c, self, 0xb24).b26)) {
                    on = TRUE;
                } else {
                    on = FALSE;
                }
                Mark021a0d4c(LFLD(u16, data_0214a424, 0x26), 0x2d0, on);
            }
        }
    }
    if (LFLD(B22_021a0d4c, self, 0xb22).lo != 0 && (LFLD(u32, LFLD(u8 *, self, 0x48), 0x50) & 0x20000000)) {
        LFLD(u16, self, 0x9ac) += 0x80;
        if (LFLD(u16, self, 0x9ac) > LFLD(u16, self, 0x9ae)) {
            LFLD(u16, self, 0x9ac) = LFLD(u16, self, 0x9ae);
        }
    }
    LFLD(s64, LFLD(u8 *, self, 0x40), 4) = 0;
}
}
