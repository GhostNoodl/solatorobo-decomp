#include "types.h"
#define LFLD(type, obj, off) (*(type *)((u8 *)(obj) + (off)))

typedef struct {
    u32 a : 8;
    u32 b : 8;
    u32 x : 9;
    u32 c : 7;
    u32 chr : 10;
    u32 d : 22;
} Glyph02160e28;

extern "C" {

Glyph02160e28 *func_ov000_021c7608(u8 *self, u16 *cmd, Glyph02160e28 *arr, u16 *count) {
    u16 n = *count;
    u32 base = arr[n - 1].chr;
    s32 v;
    s32 digits;
    s32 t;
    s32 x;
    switch (*cmd) {
    case 6:
        v = LFLD(s32, cmd, 0x8);
        digits = 0;
        t = v;
        for (; t != 0; t /= 10) {
            digits++;
        }

        x = (digits - 1) * 8;
        if (x < 0) {
            x = 0;
        }
        n = 0;
        if (v == 0) {
            arr[0].x = (u16)x;
            arr[0].a = 0;
            arr[0].chr = base;
            n++;
        } else {
            for (; digits != 0; digits--) {
                arr[n].x = (u16)x;
                arr[n].a = 0;
                arr[n].chr = base - v % 10;
                n++;
                v /= 10;
                x -= 8;
            }
        }
        break;
    case 8:
        arr[0].x = 0;
        arr[0].a = 0;
        arr[0].chr = base;
        break;
    }
    *count = n;
    return arr;
}

}
