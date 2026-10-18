#include "types.h"
#define LFLD(type, obj, off) (*(type *)((u8 *)(obj) + (off)))

typedef struct {
    u32 a : 8;
    u32 b : 8;
    u32 x : 9;
    u32 c : 7;
    u32 chr : 10;
    u32 d : 2;
    u32 pal : 4;
    u32 e : 16;
} Glyph021c0d50;

extern "C" {

static inline s32 GlyphX(Glyph021c0d50 *g) {
    s32 x = g->x;
    if (x > 0xff) {
        x |= ~0xff;
    }
    return x;
}


Glyph021c0d50 *func_ov000_021c0d50(u8 *self, u16 *cmd, Glyph021c0d50 *arr, u16 *count) {
    u16 n = *count;
    Glyph021c0d50 *last = &arr[n - 1];
    s32 off = 0;
    s32 x;
    s32 c;
    u32 pal;
    s32 i;
    switch (*cmd) {
    case 0:
        break;
    case 1:
        off -= 0x14;
        break;
    default:
        goto end;
    }
    pal = last->pal;
    c = off + 0x40 + GlyphX(&arr[0]);
    for (i = 0; i < n; i++) {
        arr[i].pal = pal + 1;
        arr[i].x = (u16)(GlyphX(&arr[i]) - c);
        arr[i].a = 0xe2;
    }
end:
    *count = n;
    return arr;
}

}
