#include "types.h"
#define LFLD(type, obj, off) (*(type *)((u8 *)(obj) + (off)))

typedef struct {
    u32 a : 8;
    u32 b : 8;
    u32 x : 9;
    u32 c : 7;
    u32 chr : 10;
    u32 d : 22;
} Glyph0214c084;

extern "C" {

Glyph0214c084 *func_ov000_0214c084(u8 *self, u16 *cmd, Glyph0214c084 *arr, u16 *count) {
    u16 n = *count;
    Glyph0214c084 *last = &arr[n - 1];
    if (*cmd == 6) {
        u32 base;
        BOOL started;
        s32 digits;
        s32 x;
        u32 div;
        u32 v;
        s32 i;
        u32 d;
        base = last->chr;
        v = LFLD(u32, cmd, 0x8);
        started = FALSE;
        x = started;
        n = started;
        if (v == 0) {
            v = 1;
        }
        if (v >= 100) {
            v = 99;
        }

        div = 1;
        for (i = 0; i < 1; i++) {
            div *= 10;
        }
        for (digits = 2; digits > 0; digits--) {
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
            x += 8;
        }
    }
    *count = n;
    return arr;
}

}
