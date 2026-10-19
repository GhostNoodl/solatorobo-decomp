#include "ov000/LoCommon.h"

typedef struct {
    u32 b0 : 1;
    u32 b1 : 1;
    u32 b2 : 3;
    u32 b5 : 2;
    u32 b7 : 5;
    u32 b12 : 2;
    u32 b14 : 11;
    u32 b25 : 1;
    u32 b26 : 6;
} B24_021a16b0;

typedef struct {
    u16 b0 : 3;
    u16 b3 : 1;
    u16 b4 : 12;
} B22_021a16b0;

typedef struct {
    u8 b0 : 1;
    u8 b1 : 1;
    u8 b2 : 1;
    u8 b3 : 5;
} B8_021a16b0;

extern "C" {

extern char data_ov000_021cc5e3[];
extern char data_ov000_021cc618[];
extern char *data_ov000_021ca040[];
extern void *data_02097e4c;
extern u8 *data_ov000_021ccd54;
void func_ov000_02190cb0(void *a, void *b, s32 c, s32 d);
void func_ov000_021915a0(void *a);
void func_ov000_02191008(void *a);
void func_02049bb4(void *a, s32 b);
void func_ov000_021987b8(void *a, s32 b, s32 c, s32 d);
void func_ov000_021b209c(u8 *self);
void func_ov000_021b2b08(u8 *self);

static inline BOOL PlayerIdle021a16b0(void) {
    u8 *pl = data_ov000_021ccd54;
    if (pl != NULL) {
        if (LFLD(s32, pl, 0x90) != LFLD(s32, pl, 0x94) ? TRUE : FALSE) {
            return FALSE;
        }
        if (LFLD(s32, pl, 0) != 3) {
            return FALSE;
        }
        return TRUE;
    }
    return TRUE;
}

void func_ov000_021a16b0(u8 *self) {
    switch (*LFLD(u16 *, self, 0x40)) {
    case 0:
        LFLD(u16 *, self, 0x40)[1] = 0;
        (*LFLD(u16 *, self, 0x40))++;
        if (LFLD(B22_021a16b0, self, 0xb22).b0 > 1) {
            if (LFLD(void *, self, 0x998) != NULL) {
                func_ov000_02191008(LFLD(void *, self, 0x998));
            }
            if (LFLD(s16, self, 0xb64) >= 0) {
                func_02049bb4(data_02097e4c, LFLD(s16, self, 0xb64));
                LFLD(s16, self, 0xb64) = -1;
            }
            if (LFLD(B22_021a16b0, self, 0xb22).b0 > 1) {
                LFLD(B22_021a16b0, self, 0xb22).b0 = 1;
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
    case 1: {
        char *name = data_ov000_021cc5e3;
        s32 rate = 0x2ab;
        s32 d = 0;
        if (LFLD(B24_021a16b0, self, 0xb24).b1) {
            if (!LFLD(B22_021a16b0, self, 0xb22).b3) {
                name = data_ov000_021ca040[LFLD(B24_021a16b0, self, 0xb24).b5];
            } else {
                if (LFLD(B24_021a16b0, self, 0xb24).b5 != 0) {
                    name = data_ov000_021cc618;
                }
                rate = 0xa4;
            }
        } else if (LFLD(u32, LFLD(u8 *, self, 0x48), 0x50) & 0x400) {
            name = data_ov000_021cc618;
        }
        if (LFLD(B24_021a16b0, self, 0xb24).b25) {
            LFLD(B24_021a16b0, self, 0xb24).b25 = 0;
            rate = 0x1000;
            d = 1;
        }
        func_ov000_02190cb0(LFLD(void *, self, 0x38), name, rate, d);
        func_ov000_021915a0(LFLD(void *, self, 0x38));
        if (LFLD(B24_021a16b0, self, 0xb24).b12 != 0) {
            (*LFLD(u16 *, self, 0x40))++;
            if (LFLD(u8, self, 0xb2f) == 0) {
                LFLD(u8, self, 0xb2f) = 1;
            }
            return;
        }
        if (LFLD(u16 *, self, 0x40)[1] >= 0x5a) {
            if (LFLD(u16, self, 0xb32) == 0) {
                LFLD(u16, self, 0xb32) = 1;
            }
        } else if (PlayerIdle021a16b0() && LFLD(u8, self, 0x15) == 1 && !LFLD(B8_021a16b0, self, 0xb29).b1 &&
                   !LFLD(B8_021a16b0, self, 0xb28).b2 && LFLD(u8, self, 0xb2e) == 0 &&
                   LFLD(B22_021a16b0, self, 0xb22).b0 == 0) {
            LFLD(u16 *, self, 0x40)[1]++;
        } else {
            LFLD(u16 *, self, 0x40)[1] = 0;
        }
        LFLD(s32, self, 0x9c) = 0;
        LFLD(s32, self, 0xa0) = 0;
        LFLD(s32, self, 0xa4) = 0;
        LFLD(s32, self, 0xa8) = 0;
        LFLD(u16, LFLD(u8 *, self, 0x48), 0x9a) |= 0x20;
        if (LFLD(u32, self, 0x30) & 0x80) {
            func_ov000_021987b8(LFLD(void *, self, 0x48), 1, 0, 0);
        }
        return;
    }
    case 2:
        if (LFLD(B24_021a16b0, self, 0xb24).b12 == 0) {
            return;
        }
        if (LFLD(B24_021a16b0, self, 0xb24).b12 != 3) {
            func_ov000_021b209c(self);
        } else {
            func_ov000_021b2b08(self);
        }
        return;
    }
}

}
