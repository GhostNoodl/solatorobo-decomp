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
void func_ov000_02190cb0(void *a, void *b, s32 c, s32 d);
void func_02062764(s32 a, s32 b);
u16 func_ov000_0219a36c(VecFx32 *pos, s32 radius, u16 angle, s32 n, u8 flag, u32 mask);
void func_02049f44(void *a, s32 b, void *c, s32 d);
u16 func_01ffc128(u16 target, u16 cur, s32 rate, s32 a, s32 b);
void func_ov000_021b1fac(void *self, BOOL a, s32 b);
void func_ov000_02198360(void *p, s32 a, s32 b);

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
