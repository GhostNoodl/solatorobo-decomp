#include "ov000/LoCommon.h"
#include "ov000/Vec.h"

typedef struct {
    u32 b0 : 1;
    u32 b1 : 1;
    u32 b2 : 2;
    u32 rest : 28;
} Bits021ac080;

typedef struct {
    u16 b0 : 8;
    u16 b8 : 1;
    u16 b9 : 1;
    u16 rest : 6;
} Bits0214a424_ac;

typedef struct {
    u16 b0 : 1;
    u16 b1 : 1;
    u16 rest : 14;
} Bits16_ac;

typedef struct {
    u8 c[3];
} Rgb021ac080;

extern "C" {
extern u8 data_ov000_021cc5e9[];
extern u8 data_ov000_021cc6c0[];
extern u8 data_ov000_021cc636[];
extern u8 *data_0214a424;
extern u8 *data_ov000_021ccd54;
extern void *data_02097e4c;
BOOL func_ov000_02190cb0(void *a, void *b, s32 c, s32 d);
void func_02062764(s32 a, s32 b);
u16 func_ov000_0219a36c(VecFx32 *pos, s32 radius, u16 angle, s32 n, u8 flag, u32 mask);
void *func_02049f44(void *a, s32 b, void *c, s32 d);
u16 func_01ffc128(u16 target, u16 cur, s32 rate, s32 a, s32 b);
void func_ov000_021b1fac(void *self, BOOL a, s32 b);
BOOL func_ov000_02198360(void *p, s32 a, s32 b);

static inline void SetRgb021ac080(u8 *g, u8 r, u8 gr, u8 b) {
    LFLD(u8, g, 0x134) = r;
    LFLD(u8, g, 0x135) = gr;
    LFLD(u8, g, 0x136) = b;
}

static inline BOOL GBusy021ac080(u8 *g) {
    return LFLD(s32, g, 0x90) != LFLD(s32, g, 0x94) ? TRUE : FALSE;
}

static inline BOOL GIdle021ac080(void) {
    u8 *g = data_ov000_021ccd54;
    if (g != NULL) {
        if (GBusy021ac080(g)) {
            return FALSE;
        }
        if (LFLD(s32, g, 0) != 3) {
            return FALSE;
        }
        return TRUE;
    }
    return TRUE;
}

void func_ov000_021ac080(u8 *self) {
    if (LFLD(u8, self, 0xb2f) == 0) {
        LFLD(u8, self, 0xb2f)++;
    }
    LFLD(Bits16_ac, LFLD(u8 *, self, 0x44), 0x22).b1 = 0;
    switch (LFLD(u16, LFLD(u8 *, self, 0x40), 0)) {
    case 0:
        LFLD(Bits021ac080, self, 0xb24).b2 = 2;
        LFLD(Bits021ac080, self, 0xb24).b1 = 0;
        LFLD(u16, self, 0x90) = 0xffff;
        LFLD(Rgb021ac080, self, 0x772) = LFLD(Rgb021ac080, data_ov000_021ccd54, 0xca);
        LFLD(Bits0214a424_ac, data_0214a424, 0x18).b8 = 1;
        LFLD(VecFx32, data_0214a424, 0x148) = LFLD(VecFx32, self, 0x75c);
        LFLD(u16, data_0214a424, 0x156) = LFLD(u16, self, 0x76e);
        SetRgb021ac080(data_0214a424, LFLD(u8, self, 0x772), LFLD(u8, self, 0x773), LFLD(u8, self, 0x774));
        func_02062764(3, 2);
        LFLD(u8, data_ov000_021ccd54, 0xac) = 1;
        LFLD(s32, self, 0x74) += 0x119a;
        func_ov000_02190cb0(self + 0x368, data_ov000_021cc5e9, 0x155, 0);
        func_ov000_02190cb0(self + 0xac, data_ov000_021cc6c0, 0x400, 0);
        LFLD(u16, self, 0x178) = 0x320;
        LFLD(u16, LFLD(u8 *, self, 0x40), 0)++;
        break;
    case 1: {
        VecFx32 v;
        LFLD(s32, self, 0x9c) = 0x133;
        LFLD(s32, self, 0xa0) = 0x2cd;
        LFLD(s32, self, 0xa8) = 0x52;
        LFLD(s32, self, 0xa4) = 0;
        v = LFLD(VecFx32, self, 0x70);
        v.y += LFLD(s32, self, 0x6c) - 0x119a;
        LFLD(u16, self, 0x98) = func_ov000_0219a36c(&v, 0x2000, LFLD(u16, self, 0x7e), 4, 0, 0xffffffff);
        func_02049f44(data_02097e4c, 0xf, self + 0x70, 0);
        LFLD(u16, LFLD(u8 *, self, 0x40), 0)++;
        break;
    }
    case 2: {
        s32 d;
        u16 t;
        u16 *s;
        LFLD(u16, self, 0x7e) = func_01ffc128(LFLD(u16, self, 0x98), LFLD(u16, self, 0x7e), 0x400, 1, 0x8000);
        func_ov000_021b1fac(self, FALSE, 1);
        d = LFLD(s32, self, 0x74) - LFLD(s32, self, 0x760);
        if (d < 0x1800) {
            LFLD(s32, self, 0x74) += (LFLD(s32, self, 0x760) + 0x1800 - LFLD(s32, self, 0x74)) >> 2;
        } else if (d > 0x1ccd) {
            LFLD(s32, self, 0x74) += (LFLD(s32, self, 0x760) + 0x1ccd - LFLD(s32, self, 0x74)) >> 2;
        }
        s = LFLD(u16 *, self, 0x40);
        s[1]++;
        t = s[1];
        if (t == 10) {
            func_ov000_02190cb0(LFLD(void *, self, 0x38), data_ov000_021cc636, 0x2ab, 0);
        }
        if (t < 0x16 && GIdle021ac080() && LFLD(u8, self, 0x15) != 3) {
            return;
        }
        func_ov000_02190cb0(LFLD(void *, self, 0x38), data_ov000_021cc636, 0x2ab, 0);
        LFLD(Bits021ac080, self, 0xb24).b2 = 0;
        func_ov000_02198360(LFLD(void *, self, 0x40), 4, 0);
        break;
    }
    }
}
}


typedef struct {
    u32 b0 : 1;
    u32 b1 : 1;
    u32 b2 : 3;
    u32 b5 : 2;
    u32 b7 : 2;
    u32 b9 : 1;
    u32 b10 : 7;
    u32 b17 : 1;
    u32 b18 : 3;
    u32 b21 : 1;
    u32 rest : 10;
} B24_021ac3ec;

typedef struct {
    u16 a : 3;
    u16 rest : 13;
} B22_021ac3ec;

typedef struct {
    u8 b0 : 5;
    u8 f5 : 2;
    u8 b7 : 1;
} B93_021ac3ec;

typedef struct {
    u8 b0 : 1;
    u8 rest : 7;
} C1_021ac3ec;

typedef struct {
    VecFx32 pos;
    u16 rot[3];
    s32 z;
} Msg021ac3ec;

extern "C" {
extern void *data_ov000_021ccd68;
extern void *data_02097e4c;
extern char data_ov000_021cc6c6[];
extern char data_ov000_021cc6cc[];
BOOL func_ov000_02190cb0(void *a, void *b, s32 c, s32 d);
void func_ov000_02191008(void *p);
void func_02049bb4(void *mgr, s32 id);
void func_ov000_0218996c(s32 a, s32 b);
u8 *func_ov000_0218e640(void *mgr, u16 id);
void func_ov000_0218d398(void *p, u16 a, s32 b, s32 c, s32 d, void *e);
void func_ov000_0218d46c(void *o, u16 id, s32 c);
u8 *func_ov000_02199f60(void *p);
void func_ov000_02199f88(void *t, void *self);
void func_ov000_02191418(void *a, s32 b, s32 c);
BOOL func_ov000_02191120(void *a);
BOOL func_ov000_02191508(void *m);
void func_ov000_021b1fac(void *self, BOOL a, s32 b);
BOOL func_ov000_02198360(void *s, s32 a, s32 b);
u16 FX_Atan2(s32 x, s32 z);
u16 func_01ffc128(u16 target, u16 cur, s32 rate, s32 a, s32 b);

static inline u8 *GetObj021ac3ec(u16 id) {
    if (data_ov000_021ccd68 == NULL) {
        return NULL;
    }
    return func_ov000_0218e640(data_ov000_021ccd68, id);
}

static inline void Reset021ac3ec(u8 *self) {
    LFLD(u16, self, 0xb1c) = 0xffff;
    LFLD(u16, self, 0xb1e) = 0xffff;
    LFLD(B24_021ac3ec, self, 0xb24).b5 = 0;
    LFLD(B24_021ac3ec, self, 0xb24).b7 = LFLD(B24_021ac3ec, self, 0xb24).b9;
}

void func_ov000_021ac3ec(u8 *self) {
    BOOL go;
    switch (LFLD(u16, LFLD(u8 *, self, 0x40), 0)) {
    case 0: {
        u8 *o;
        char *anm = data_ov000_021cc6c6;
        if (LFLD(B93_021ac3ec, self, 0x93).f5 != 0) {
            anm = data_ov000_021cc6cc;
        }
        func_ov000_02190cb0(LFLD(void *, self, 0x38), anm, 0x800, 1);
        if (LFLD(B22_021ac3ec, self, 0xb22).a != 0) {
            if (LFLD(void *, self, 0x998) != NULL) {
                func_ov000_02191008(LFLD(void *, self, 0x998));
            }
            if (LFLD(s16, self, 0xb64) >= 0) {
                func_02049bb4(data_02097e4c, LFLD(s16, self, 0xb64));
                LFLD(s16, self, 0xb64) = -1;
            }
            if (LFLD(B22_021ac3ec, self, 0xb22).a > 1) {
                LFLD(B22_021ac3ec, self, 0xb22).a = 1;
                LFLD(u16, self, 0x7c) = 0;
                LFLD(u16, self, 0x80) = 0;
                LFLD(u16, self, 0x9a6) = 0;
                LFLD(u16, self, 0x9a8) = 0;
                LFLD(u16, self, 0x9aa) = 0;
                LFLD(u16, self, 0x9a0) = 0;
                LFLD(u16, self, 0x9a2) = 0;
                LFLD(u16, self, 0x9a4) = 0;
            }
        }
        LFLD(u16, LFLD(u8 *, self, 0x50), 0xa) = 0x5a;
        func_ov000_0218996c(6, 10);
        o = GetObj021ac3ec(LFLD(u16, self, 0xb1c));
        if (o != NULL) {
            Msg021ac3ec m;
            m.pos = LFLD(VecFx32, self, 0x70);
            m.pos.y += LFLD(s32, self, 0x6c);
            m.rot[0] = LFLD(u16, o, 0x7c);
            m.rot[1] = LFLD(u16, o, 0x7e);
            m.rot[2] = LFLD(u16, o, 0x80);
            m.z = 0;
            func_ov000_0218d398(o, LFLD(u16, self, 0xc), 7, 1, 0x18, &m);
            func_ov000_0218d46c(o, LFLD(u16, self, 0xc), 10);
            if (LFLD(u8 *, o, 0x4c) != NULL) {
                LFLD(C1_021ac3ec, LFLD(u8 *, o, 0x4c), 0x18).b0 = 0;
            }
        }
        Reset021ac3ec(self);
        LFLD(u16, self, 0x90) = 0xffff;
        LFLD(B24_021ac3ec, self, 0xb24).b21 = 0;
        if (LFLD(B93_021ac3ec, self, 0x93).f5 == 0) {
            LFLD(u16, self, 0xb36) = 0;
        } else if (LFLD(B93_021ac3ec, self, 0x93).f5 == 1) {
            LFLD(B93_021ac3ec, self, 0x93).f5 = 2;
        }
        {
            u8 *t = func_ov000_02199f60(LFLD(void *, self, 0x50));
            u16 ang;
            if (t == NULL || t == self) {
                ang = LFLD(u16, self, 0x7e);
            } else {
                ang = FX_Atan2(LFLD(s32, t, 0x70) - LFLD(s32, self, 0x70), LFLD(s32, t, 0x78) - LFLD(s32, self, 0x78));
            }
            LFLD(u16, self, 0x96) = ang;
        }
        LFLD(s32, self, 0x9c) = 0;
        LFLD(u16, self, 0x98) = LFLD(u16, self, 0x96) + 0x8000;
        LFLD(s32, self, 0xa0) = 0;
        LFLD(s32, self, 0xa4) = 0;
        LFLD(s32, self, 0xa8) = 0;
        LFLD(u16, LFLD(u8 *, self, 0x40), 0)++;
        break;
    }
    case 1: {
        u8 f = LFLD(B93_021ac3ec, self, 0x93).f5;
        if (f != 0) {
            LFLD(s32, self, 0x9c) = 0x371;
            LFLD(s32, self, 0xa0) = 0;
            LFLD(s32, self, 0xa4) = 0xccd;
            LFLD(s32, self, 0xa8) = 0x52;
            if (f == 2) {
                LFLD(B93_021ac3ec, self, 0x93).f5 = 1;
            }
        } else {
            func_ov000_02199f88(LFLD(void *, self, 0x50), self);
        }
        func_ov000_02191418(LFLD(void *, self, 0x38), 5, 0);
        LFLD(u16, LFLD(u8 *, self, 0x40), 0)++;
        break;
    }
    case 2:
        if (func_ov000_02191120(LFLD(void *, self, 0x38))) {
            if (LFLD(B93_021ac3ec, self, 0x93).f5 != 0) {
                func_ov000_02198360(LFLD(void *, self, 0x40), 0x1c, 0);
            } else {
                func_ov000_02198360(LFLD(void *, self, 0x40), 1, 0);
            }
        }
        if (!func_ov000_02191508(LFLD(void *, self, 0x38))) {
            func_ov000_021b1fac(self, TRUE, 1);
            if (!LFLD(B24_021ac3ec, self, 0xb24).b1 && (LFLD(u32, LFLD(u8 *, self, 0x48), 0x50) & 0x400)) {
                func_ov000_02198360(LFLD(void *, self, 0x40), 4, 0);
            }
        }
        break;
    }
    go = FALSE;
    if (LFLD(B24_021ac3ec, self, 0xb24).b1 && (LFLD(u32, LFLD(u8 *, self, 0x48), 0x54) & 0x400)) {
        LFLD(u16, self, 0x98) = FX_Atan2(LFLD(s32, self, 0xaf0) - LFLD(s32, self, 0x70), LFLD(s32, self, 0xaf8) - LFLD(s32, self, 0x78));
        LFLD(s32, self, 0x9c) = 0x66;
        LFLD(s32, self, 0xa4) = 0;
        if (!LFLD(B24_021ac3ec, self, 0xb24).b17 || (LFLD(u32, LFLD(u8 *, self, 0x48), 0x50) & 0x40000000)) {
            LFLD(s32, self, 0xa0) = 0x200;
        }
        LFLD(s32, self, 0xa8) = 0x52;
        LFLD(B24_021ac3ec, self, 0xb24).b17 = 1;
        go = TRUE;
    }
    if (go) {
        func_ov000_02198360(LFLD(void *, self, 0x40), 4, 0);
    }
    LFLD(u16, self, 0x7e) = func_01ffc128(LFLD(u16, self, 0x96), LFLD(u16, self, 0x7e), 0x8cd, 1, 0x8000);
}
}
