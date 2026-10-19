#include "ov000/LoCommon.h"
#include "ov000/Vec.h"

typedef struct {
    u32 b0 : 1;
    u32 b1 : 1;
    u32 b2 : 2;
    u32 b4 : 1;
    u32 b5 : 2;
    u32 b7 : 5;
    u32 b12 : 2;
    u32 b14 : 10;
    u32 b24 : 1;
    u32 rest : 7;
} B24_0219e498;

typedef struct {
    u16 b0 : 3;
    u16 b3 : 1;
    u16 rest : 12;
} B22_0219e498;

typedef struct {
    u16 b0 : 1;
    u16 b1 : 1;
    u16 b2 : 1;
    u16 b3 : 1;
    u16 b4 : 1;
    u16 b5 : 1;
    u16 rest : 10;
} Body_0219e498;

typedef struct {
    u16 b0 : 9;
    u16 b9 : 1;
    u16 rest : 6;
} G18_0219e498;

typedef struct {
    u8 c[3];
} Rgb0219e498;

extern "C" {
extern u8 *data_0214a424;
extern u8 *data_ov000_021ccd54;
void func_0203f324(void *a);
void func_0203f364(void *a);
void func_ov000_0219864c(void *a, void *b, void *c);
void func_ov000_021987b8(void *a, s32 b, void *c, void *d);

#define BODY(s, off) LFLD(Body_0219e498, s, (off) + 0x9a)

static inline BOOL On0219e498(u8 *s, u32 off) {
    return (!BODY(s, off).b3 && BODY(s, off).b0) ? TRUE : FALSE;
}

static inline BOOL On2_0219e498(u8 *s, u32 off) {
    return (!BODY(s, off).b4 && BODY(s, off).b1) ? TRUE : FALSE;
}

static inline void Show0219e498(u8 *s, u32 off) {
    BODY(s, off).b0 = 1;
    BODY(s, off).b3 = 1;
    func_0203f324(s + off);
}

static inline void Hide0219e498(u8 *s, u32 off) {
    BODY(s, off).b0 = 0;
    BODY(s, off).b3 = 0;
    func_0203f364(s + off);
}

static inline void Hide2_0219e498(u8 *s, u32 off) {
    BODY(s, off).b1 = 0;
    BODY(s, off).b4 = 0;
}

static inline BOOL G9_0219e498(void) {
    return LFLD(G18_0219e498, data_0214a424, 0x18).b9 ? TRUE : FALSE;
}

static inline BOOL RgbEq0219e498(Rgb0219e498 *a, Rgb0219e498 *b) {
    BOOL r = FALSE;
    if (a->c[0] == b->c[0] && a->c[1] == b->c[1] && a->c[2] == b->c[2]) {
        r = TRUE;
    }
    return r;
}

void func_ov000_0219e498(u8 *self) {
    if (LFLD(B24_0219e498, self, 0xb24).b1) {
        s32 a = 0;
        s32 b = 0x266;
        if (LFLD(B22_0219e498, self, 0xb22).b3) {
            if (LFLD(B24_0219e498, self, 0xb24).b5) {
                b += 0x4f6;
                a += 0x4cd;
            } else {
                b += 0x29;
                a += 0x400;
                b += 0x400;
            }
        } else if (LFLD(B24_0219e498, self, 0xb24).b5) {
            if (LFLD(B24_0219e498, self, 0xb24).b12 == 0) {
                a += 0x333;
                b += 0x35c;
            }
        }
        LFLD(s32, self, 0x6f8) = a + LFLD(s32, self, 0x64);
        LFLD(s32, self, 0x720) = b + LFLD(s32, self, 0x6c);
        if (!On0219e498(self, 0x6c0)) {
            Show0219e498(self, 0x6c0);
        }
        if (!On2_0219e498(self, 0x6c0)) {
            LFLD(u16, self, 0x75a) |= 0x12;
        }
        func_ov000_0219864c(self + 0x6c0, NULL, NULL);
        LFLD(VecFx32, self, 0x75c) = LFLD(VecFx32, self, 0x70);
        Hide0219e498(self, 0x2cc);
        Hide2_0219e498(self, 0x2cc);
        func_ov000_0219864c(self + 0x2cc, NULL, NULL);
        return;
    }
    if (!G9_0219e498() && RgbEq0219e498(&LFLD(Rgb0219e498, data_ov000_021ccd54, 0xca), &LFLD(Rgb0219e498, self, 0x772))) {
        LFLD(s32, self, 0x6f8) = LFLD(s32, self, 0x64) >> 1;
        LFLD(s32, self, 0x720) = LFLD(s32, self, 0x6c) >> 1;
        Show0219e498(self, 0x6c0);
        LFLD(u16, self, 0x75a) |= 0x12;
        if ((LFLD(u32, self, 0x710) & 0x20000000) || !(LFLD(u32, self, 0x714) & 0x20000000)) {
            LFLD(s32, self, 0x768) = 0;
            BODY(self, 0x6c0).b5 = 1;
        } else {
            LFLD(s32, self, 0x768) -= 0x52;
            if (LFLD(s32, self, 0x768) > -0x148) {
                LFLD(s32, self, 0x768) = -0x148;
            }
            LFLD(s32, self, 0x760) += LFLD(s32, self, 0x768);
        }
        if (LFLD(B24_0219e498, self, 0xb24).b24 || LFLD(s32, self, 0x768) != 0) {
            LFLD(B24_0219e498, self, 0xb24).b24 = 0;
            func_ov000_021987b8(self + 0x6c0, 0, self + 0x75c, self + 0x76c);
        }
    } else {
        Hide0219e498(self, 0x6c0);
        Hide2_0219e498(self, 0x6c0);
    }
    func_ov000_0219864c(self + 0x6c0, self + 0x75c, self + 0x76c);
    if (LFLD(B24_0219e498, self, 0xb24).b2 != 1) {
        if (LFLD(u32, self, 0x31c) & 0x400) {
            LFLD(s32, self, 0x304) = (LFLD(s32, self, 0x64) >> 1) + (LFLD(s32, self, 0x64) >> 2);
        } else {
            LFLD(s32, self, 0x304) = (LFLD(s32, self, 0x64) >> 1) + (LFLD(s32, self, 0x64) >> 3);
        }
        Show0219e498(self, 0x2cc);
        LFLD(u16, self, 0x366) |= 0x12;
    } else {
        Hide0219e498(self, 0x2cc);
        LFLD(s32, self, 0x31c) = 0;
        LFLD(s32, self, 0x320) = 0;
        LFLD(s32, self, 0x324) = 0;
        Hide2_0219e498(self, 0x2cc);
    }
    func_ov000_0219864c(self + 0x2cc, NULL, NULL);
}
}
