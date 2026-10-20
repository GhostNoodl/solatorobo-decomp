#include "ov015/ov015.h"

extern "C" {

static inline u8 *Src(u8 *s) {
    if (FLD(s32, s, 0x80) <= 15) {
        return NULL;
    }
    return FLD(u8 *, s, 0x78) + 0x258;
}

Ov015Glyph *func_ov015_021fb25c(u8 *self, u16 *ctx, Ov015Glyph *e, u16 *count) {
    Ov015Glyph *last;
    s32 val;
    u16 i;
    s32 n;
    s32 v;
    s32 x;
    s32 w;
    s32 idx;
    i = *count;
    idx = i - 1;
    last = &e[idx];
    w = last->w;
    val = FLD(s32, FLD(u8 *, Src(self), 8), 0) >> 12;
    n = 0;
    v = val;
    do {
        n++;
        v /= 10;
    } while (v != 0);
    switch (*ctx) {
    case 0xf:
        x = ((n + 1) * 12 >> 1) - 12;
        i = 0;
        for (; n > 0; n--) {
            x -= 12;
            e[i].x = (u16)x;
            e[i].code = 0xf4;
            e[i].w = w - (val % 10) * 2;
            i++;
            val /= 10;
            if (val == 0) {
                break;
            }
        }
        break;
    case 0xe:
        e[0].x = (u16)(((n + 1) * 12 >> 1) - 12);
        e[0].code = 0xf2;
        e[0].w = last->w;
        i = 1;
        break;
    }
    *count = i;
    return e;
}

}
