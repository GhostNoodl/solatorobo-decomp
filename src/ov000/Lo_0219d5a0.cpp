#include "types.h"
#define LFLD(type, obj, off) (*(type *)((u8 *)(obj) + (off)))

extern "C" {

typedef struct {
    u8 c[3];
} Rgb0219d5a0;

typedef struct {
    u8 pad_00[3];
    Rgb0219d5a0 rgb;
} Def0219d5a0;

extern u8 *data_ov000_021ccd54;
extern Def0219d5a0 data_ov000_021c9fe8;

typedef struct {
    u16 a : 3;
    u16 b : 1;
    u16 pad4 : 2;
    u16 c : 3;
    u16 d : 2;
    u16 rest : 5;
} B22_0219d5a0;

typedef struct {
    u32 b0 : 1;
    u32 e : 1;
    u32 b2 : 2;
    u32 f : 1;
    u32 g : 2;
    u32 b7 : 5;
    u32 h : 2;
    u32 rest : 18;
} B24_0219d5a0;

typedef struct {
    u8 b0 : 4;
    u8 i : 1;
    u8 rest : 3;
} B29_0219d5a0;

static inline BOOL RgbEq0219d5a0(Rgb0219d5a0 *a, Rgb0219d5a0 b) {
    BOOL r = FALSE;
    if (a->c[0] == b.c[0] && a->c[1] == b.c[1] && a->c[2] == b.c[2]) {
        r = TRUE;
    }
    return r;
}

s32 func_ov000_0219d5a0(u8 *self) {
    s32 result = 0;
    BOOL busy = FALSE;
    u8 t = LFLD(u8 *, self, 0x40)[0x13];
    u32 st;
    if (t != 1 && t != 2) {
        busy = TRUE;
        if (t == 0x1f && LFLD(B22_0219d5a0, self, 0xb22).d < 2 && (u16)(LFLD(B22_0219d5a0, self, 0xb22).c + 0xfffe) <= 1) {
            busy = FALSE;
        }
    }
    st = LFLD(u32, LFLD(u8 *, self, 0x48), 0x50);
    if (st & 0x400) {
        busy = TRUE;
    }
    if (!LFLD(B24_0219d5a0, self, 0xb24).e) {
        if (LFLD(B29_0219d5a0, self, 0xb29).i || busy) {
            result = 2;
        } else if (!RgbEq0219d5a0((Rgb0219d5a0 *)(data_ov000_021ccd54 + 0xca), data_ov000_021c9fe8.rgb)) {
            if (!(st & 0x20000000) || !LFLD(B24_0219d5a0, self, 0xb24).f) {
                result = 1;
            }
        }
    } else {
        if (busy || LFLD(B29_0219d5a0, self, 0xb29).i || LFLD(B22_0219d5a0, self, 0xb22).b || LFLD(B24_0219d5a0, self, 0xb24).h ||
            LFLD(B24_0219d5a0, self, 0xb24).g || LFLD(B22_0219d5a0, self, 0xb22).c == 5 ||
            (LFLD(B22_0219d5a0, self, 0xb22).a != 0 && LFLD(B22_0219d5a0, self, 0xb22).a != 1)) {
            result = 2;
        }
    }
    return result;
}
}
