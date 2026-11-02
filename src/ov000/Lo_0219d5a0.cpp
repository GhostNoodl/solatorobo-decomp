#include "types.h"
#include "Main/Sys/FieldState.h"
#include "ov000/ObjLayouts.h"
#define LFLD(type, obj, off) (*(type *)((u8 *)(obj) + (off)))

extern "C" {

typedef struct {
    u8 c[3];
} Rgb0219d5a0;

typedef struct {
    u8 pad_00[3];
    Rgb0219d5a0 rgb;
} Def0219d5a0;

extern Def0219d5a0 data_ov000_021c9fe8;

static inline BOOL RgbEq0219d5a0(Rgb0219d5a0 *a, Rgb0219d5a0 b) {
    BOOL r = FALSE;
    if (a->c[0] == b.c[0] && a->c[1] == b.c[1] && a->c[2] == b.c[2]) {
        r = TRUE;
    }
    return r;
}

s32 func_ov000_0219d5a0(Robo021ca458 *self) {
    s32 result = 0;
    BOOL busy = FALSE;
    u8 t = ((u8 *)self->fsm)[0x13];
    u32 st;
    if (t != 1 && t != 2) {
        busy = TRUE;
        if (t == 0x1f && self->unk_b22_9 < 2 && (u16)(self->unk_b22_6 + 0xfffe) <= 1) {
            busy = FALSE;
        }
    }
    st = self->hit->unk_50;
    if (st & 0x400) {
        busy = TRUE;
    }
    if (!self->unk_b24_1) {
        if (self->unk_b29_4 || busy) {
            result = 2;
        } else if (!RgbEq0219d5a0((Rgb0219d5a0 *)((u8 *)data_ov000_021ccd54 + 0xca), data_ov000_021c9fe8.rgb)) {
            if (!(st & 0x20000000) || !self->unk_b24_4) {
                result = 1;
            }
        }
    } else {
        if (busy || self->unk_b29_4 || self->unk_b22_3 || self->unk_b24_12 ||
            self->unk_b24_5 || self->unk_b22_6 == 5 ||
            (self->unk_b22_0 != 0 && self->unk_b22_0 != 1)) {
            result = 2;
        }
    }
    return result;
}
}
