#include "types.h"
#define LFLD(type, obj, off) (*(type *)((u8 *)(obj) + (off)))

typedef struct {
    u32 a : 8;
    u32 b : 8;
    u32 x : 9;
    u32 c : 7;
    u32 chr : 10;
    u32 d : 22;
} Glyph02174168;

extern "C" {

Glyph02174168 *func_ov000_02174168(u8 *self, u16 *cmd, Glyph02174168 *arr, u16 *count) {
    u16 n = *count;
    Glyph02174168 *last = &arr[n - 1];
    if (*cmd == 6) {
        u32 base;
        u32 v;
        BOOL started;
        s32 x;
        u32 div;
        s32 digits;
        s32 i;
        u32 d;
        digits = LFLD(s32, cmd, 0x8);
        started = FALSE;
        x = started;
        n = started;
        base = last->chr;
        v = LFLD(u32, self, 0x70);
        div = 1;
        for (i = started; i < digits - 1; i++) {
            div *= 10;
        }
        if (v >= div * 10) {
            v = div * 10 - 1;
        }
        for (; digits != 0; digits--) {
            d = v / div;
            if ((digits == 1 && !started) || started || d != 0) {
                arr[n].x = (u16)x;
                arr[n].a = 0;
                arr[n].chr = base - d;
                n++;
                started = TRUE;
            }
            v -= d * div;
            div /= 10;
            x += 7;
        }
    }
    *count = n;
    return arr;
}

}
