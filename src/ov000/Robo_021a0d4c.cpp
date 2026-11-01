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

struct Obj021a0d4c {
    u8 unk_00[0xc];
    u16 unk_0c;
    u8 unk_0e[0x2a];
    void *unk_38;
    u8 unk_3c[0x4];
    u8 *unk_40;
    u8 unk_44[0x4];
    u8 *unk_48;
    u8 unk_4c[0x4];
    u8 *unk_50;
    void *unk_54;
    u8 unk_58[0x18];
    s32 unk_70;
    s32 unk_74;
    s32 unk_78;
    u16 unk_7c;
    u16 unk_7e;
    u16 unk_80;
    u8 unk_82[0x11];
    B8_021a0d4c unk_93;
    u8 unk_94[0x6c8];
    s32 unk_75c;
    s32 unk_760;
    s32 unk_764;
    u8 unk_768[0x4];
    u16 unk_76c;
    u16 unk_76e;
    u16 unk_770;
    u8 unk_772[0x23a];
    u16 unk_9ac;
    u16 unk_9ae;
    u8 unk_9b0[0x4];
    u8 *unk_9b4;
    u8 unk_9b8[0x132];
    u16 unk_aea;
    u16 unk_aec;
    u8 unk_aee[0x2];
    s32 unk_af0;
    s32 unk_af4;
    s32 unk_af8;
    s32 unk_afc;
    s32 unk_b00;
    s32 unk_b04;
    u8 unk_b08[0x14];
    u16 unk_b1c;
    u16 unk_b1e;
    u16 unk_b20;
    B22_021a0d4c unk_b22;
    B24_021a0d4c unk_b24;
    u8 unk_b28;
    B8_021a0d4c unk_b29;
    u8 unk_b2a[0x4];
    u8 unk_b2e;
    u8 unk_b2f[0x3];
    u16 unk_b32;
    u16 unk_b34;
    u8 unk_b36[0x6e];
    u8 *unk_ba4;
};

static inline void Reset021a0d4c(Obj021a0d4c *self) {
    self->unk_b24.f5 = 0;
    self->unk_b1c = 0xffff;
    self->unk_b1e = 0xffff;
    self->unk_b24.f7 = self->unk_b24.b9;
}

static inline u8 *Target021a0d4c(Obj021a0d4c *self) {
    u8 *o = GetObj021a0d4c(self->unk_b1c);
    u8 *p = NULL;
    if (o != NULL) {
        p = LFLD(u8 *, o, 0x4c);
    }
    if (p == NULL || LFLD(u16, p, 0x1c) != self->unk_0c) {
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

static inline BOOL NotB1_021a0d4c(Obj021a0d4c *self) {
    return !self->unk_b24.b1 ? TRUE : FALSE;
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
static inline BOOL Ok021a0d4c(Obj021a0d4c *self) {
    u8 *g = data_ov000_021ccd54;
    BOOL r = IdleG021a0d4c(g);
    if (r) {
        r = !self->unk_b29.b1;
    }
    if (r) {
        r = self->unk_b28 == 0;
    }
    if (r) {
        r = self->unk_b2e == 0;
    }
    if (r) {
        r = !self->unk_b24.b0;
    }
    if (r) {
        r = !self->unk_b29.b3;
    }
    if (r) {
        r = !NotB1_021a0d4c(self);
        if (!r) {
            BOOL t = G9_021a0d4c();
            r = !t;
            if (!t) {
                r = RgbEq021a0d4c(g + 0xca, (u8 *)self + 0x772);
            }
            if (r) {
                r = self->unk_b24.f14 == 0;
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

void func_ov000_021a0d4c(Obj021a0d4c *self) {

    s32 k;
    s32 i;

    if (self->unk_b22.kind == 5) {
        func_ov000_021b06dc((u8 *)self);
        return;
    }
    LFLD(u8, self, 0xb29) = 0;
    if (self->unk_b2e != 0) {
        self->unk_b2e--;
    }
    k = LFLD(u8, self->unk_40, 0x13);
    for (i = 0; i < 0x1d; i++) {
        if (k == *(s32 *)((u8 *)data_ov000_021ca458 + i * 12)) {
            (((Robo021a0d4cCls *)self)->*data_ov000_021ca458[i].fn)();
            break;
        }
    }
    if (!self->unk_b24.b1) {
        self->unk_38 = (u8 *)self + 0xac;
        self->unk_48 = (u8 *)((u8 *)self + 0x2cc);
    } else {
        self->unk_38 = (u8 *)self + 0x368;
        self->unk_75c = self->unk_70;
        self->unk_760 = self->unk_74;
        self->unk_764 = self->unk_78;
        self->unk_76c = self->unk_7c;
        self->unk_76e = self->unk_7e;
        self->unk_770 = self->unk_80;
        self->unk_48 = (u8 *)((u8 *)self + 0x6c0);
    }
    if (LFLD(B9a_021a0d4c, self->unk_48, 0x9a).b8) {
        u32 f = LFLD(u32, self->unk_48, 0x50);
        if ((f & 0x20000000) && !(f & 0x40400) && !(f & 0x40000000)) {
            self->unk_af0 = self->unk_70;
            self->unk_af4 = self->unk_74;
            self->unk_af8 = self->unk_78;
        }
        if (LFLD(u32, self->unk_48, 0x54) & 0x20000000) {
            u8 *p = self->unk_48;
            self->unk_afc = LFLD(s32, p, 0x68);
            self->unk_b00 = LFLD(s32, p, 0x6c);
            self->unk_b04 = LFLD(s32, p, 0x70);
        }
    }
    if (self->unk_b24.f5 != 0 && !self->unk_b22.b3) {
        u8 *o = Target021a0d4c(self);
        if (o != NULL) {
            u8 *p = LFLD(u8 *, o, 0x4c);
            u16 v = 0;
            if (p != NULL) {
                v = LFLD(u16, p, 0x1e);
            }
            if (v != 0) {
                Gauge021a0d4c(v);
                if (self->unk_b32 == 0) {
                    self->unk_b32++;
                }
            }
        }
    }
    if (self->unk_b24.mode == 3) {
        u8 *o = GetObj021a0d4c(self->unk_b20);
        u8 *p = NULL;
        if (o != NULL) {
            p = LFLD(u8 *, o, 0x4c);
        }
        if (p != NULL) {
            Gauge021a0d4c(LFLD(u16, p, 0x1e));
            if (self->unk_b32 == 0) {
                self->unk_b32++;
            }
        }
    }
    func_ov000_021b3d78((u8 *)self);
    func_ov000_0218c208(data_ov000_021ccd64, (u8 *)self + 0x70, self->unk_7e);
    if (self->unk_b24.f2 != 1) {
        u8 *c = data_ov000_021ccd6c;
        LFLD(s32, c, 0x24) = self->unk_70;
        LFLD(s32, c, 0x28) = self->unk_74;
        LFLD(s32, c, 0x2c) = self->unk_78;
    }
    {
        u8 *c = data_02149f0c;
        LFLD(s32, c, 0) = self->unk_70;
        LFLD(s32, c, 4) = self->unk_74;
        LFLD(s32, c, 8) = self->unk_78;
    }
    if (LFLD(u16, self->unk_50, 0xa) != 0) {
        LFLD(u16, self->unk_50, 0xa)--;
    }
    func_ov000_0219a088(self->unk_54);
    {
        s32 a = 0;
        s32 b = 0;
        u8 *q = self->unk_ba4;
        if (q != NULL && self->unk_b24.b1 && !self->unk_b24.b0) {
            b = LFLD(Bq_021a0d4c, q, 4).hi;
            if (b != 0) {
                b = b * 10;
                a = 0x2d0;
            }
        }
        self->unk_aea = a;
        self->unk_aec = b;
    }
    func_ov000_0219a0b0((u8 *)self + 0xae8, (u8 *)self);
    LFLD(Bd_021a0d4c, self->unk_9b4, 0).b1 = 0;
    if (self->unk_b22.lo != 0 && Ok021a0d4c(self)) {
        if (self->unk_b24.b1) {
            BOOL f = LFLD(G18_021a0d4c, data_0214a424, 0x18).b10 ? TRUE : FALSE;
            u8 *g = LFLD(u8 *, data_ov000_021ccd30, 0x11c);
            if (g != NULL) {
                func_ov000_0216b508(LFLD(void *, g, 0x68), 1, f);
            }
        }
        if (self->unk_b22.lo == 3 || self->unk_b22.lo == 4) {
            func_ov000_021bd314(self->unk_9b4, 8);
            LFLD(Bd_021a0d4c, self->unk_9b4, 0).b1 = 1;
        } else {
            u8 *q = data_ov000_021ccd54 + 0xf4;
            if (q != NULL && LFLD(u16, q, 0xd6) - 1 == LFLD(u16, q, 0xd4)) {
                func_ov000_021bd314(self->unk_9b4, 9);
                LFLD(Bd_021a0d4c, self->unk_9b4, 0).b1 = 1;
            }
        }
    }
    func_ov000_021bd624(self->unk_9b4);
    func_ov000_021b1110((u8 *)self, 0);
    if (self->unk_b32 != 0) {
        u16 m;
        self->unk_b32--;
        m = LFLD(u16, self->unk_50, 2);
        if (self->unk_b34 < m) {
            self->unk_b34 += (u16)(m / 32);
            if (self->unk_b34 < m) {
                m = self->unk_b34;
                if (self->unk_b32 == 0) {
                    self->unk_b32++;
                }
            } else {
                self->unk_b34 = m;
            }
        }
        if (GIdle021a0d4c() || self->unk_b34 < m) {
            Bar021a0d4c(LFLD(u16, self->unk_50, 0), m);
            if (LFLD(G18_021a0d4c, data_0214a424, 0x18).sel == 1 && !self->unk_b22.b4) {
                BOOL on;
                if (!self->unk_b22.b3 && self->unk_b22.f9 == 0 &&
                    self->unk_b24.b1 && self->unk_93.b4 &&
                    !self->unk_b29.b3 && self->unk_b22.lo == 0 &&
                    self->unk_b24.mode == 0 && LFLD(u8, self->unk_40, 0x13) != 0x11 &&
                    !(LFLD(u8, self->unk_40, 0x13) == 0xb && self->unk_b24.b26)) {
                    on = TRUE;
                } else {
                    on = FALSE;
                }
                Mark021a0d4c(LFLD(u16, data_0214a424, 0x26), 0x2d0, on);
            }
        }
    }
    if (self->unk_b22.lo != 0 && (LFLD(u32, self->unk_48, 0x50) & 0x20000000)) {
        self->unk_9ac += 0x80;
        if (self->unk_9ac > self->unk_9ae) {
            self->unk_9ac = self->unk_9ae;
        }
    }
    LFLD(s64, self->unk_40, 4) = 0;
}
}
