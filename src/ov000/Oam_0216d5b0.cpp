#include "types.h"
#define LFLD(type, obj, off) (*(type *)((u8 *)(obj) + (off)))

typedef struct {
    u32 a : 8;
    u32 b : 8;
    u32 x : 9;
    u32 c : 7;
    u32 chr : 10;
    u32 d : 22;
} Glyph0216d5b0;

extern "C" {

Glyph0216d5b0 *func_ov000_0216d5b0(u8 *self, u16 *cmd, Glyph0216d5b0 *arr, u16 *count) {
    u16 n = *count;
    Glyph0216d5b0 *last = &arr[n - 1];
    s16 x = 0;
    switch (*cmd) {
    case 0x1e: {
        s32 t = LFLD(s32, self, 0x70);
        s32 hh = t / 3600;
        u32 base = last->chr;
        s32 rem = t % 3600;
        s32 mm;
        s32 ms;
        if (hh >= 100) {
            hh = 99;
            mm = 59;
            ms = 990;
        } else {
            mm = rem / 60;
            ms = (rem % 60) * 100 / 6;
        }
        ms /= 10;
        n = 0;
        arr[n].x = (u16)x;
        arr[n].a = 0;
        arr[n].chr = base - ms % 10;
        n++;
        x -= 6;
        arr[n].x = (u16)x;
        arr[n].a = 0;
        arr[n].chr = base - ms / 10;
        n++;
        x -= 12;
        arr[n].x = (u16)x;
        arr[n].a = 0;
        arr[n].chr = base - mm % 10;
        n++;
        x -= 6;
        arr[n].x = (u16)x;
        arr[n].a = 0;
        arr[n].chr = base - mm / 10;
        n++;
        x -= 12;
        arr[n].x = (u16)x;
        arr[n].a = 0;
        arr[n].chr = base - hh % 10;
        n++;
        x -= 6;
        arr[n].x = (u16)x;
        arr[n].a = 0;
        arr[n].chr = base - hh / 10;
        n++;
        break;
    }
    case 0x1f:
        n = 0;
        x -= 12;
        arr[n].x = (u16)x;
        arr[n].a = 0;
        n++;
        {
            Glyph0216d5b0 *dst = &arr[n];
            *dst = arr[n - 1];
        }
        x -= 18;
        arr[n].x = (u16)x;
        arr[n].a = 0;
        n++;
        break;
    }
    *count = n;
    return arr;
}

}
