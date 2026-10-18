#include "types.h"
#define LFLD(type, obj, off) (*(type *)((u8 *)(obj) + (off)))

typedef struct {
    u32 a : 8;
    u32 b : 8;
    u32 x : 9;
    u32 c : 7;
    u32 chr : 10;
    u32 d : 22;
} Glyph0214db04;

extern "C" {

Glyph0214db04 *func_ov000_0214db04(u8 *self, u16 *cmd, Glyph0214db04 *arr, u16 *count) {
    u16 n = *count;
    Glyph0214db04 *last = &arr[n - 1];
    u32 base;
    s32 v;
    s32 x;
    if (*cmd == 0x1e) {
        base = last->chr;
        v = LFLD(s32, self, 0x70);
        x = 0;
        n = 0;
        if (v < 10) {
            x -= 4;
        }
        arr[n].x = (u16)x;
        arr[n].a = 0;
        arr[n].chr = base - v % 10;
        n++;
        if (v > 9) {
            arr[n].x = (u16)(s16)(x - 5);
            arr[n].a = 0;
            arr[n].chr = base - v / 10;
            n++;
        }
    }
    *count = n;
    return arr;
}

}
