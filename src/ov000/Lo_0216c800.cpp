#include "types.h"
#define LFLD(type, obj, off) (*(type *)((u8 *)(obj) + (off)))

typedef struct {
    u32 a : 8;
    u32 b : 8;
    u32 x : 9;
    u32 c : 7;
    u32 chr : 10;
    u32 d : 22;
} Glyph0216c800;

extern "C" {

Glyph0216c800 *func_ov000_0216c800(u8 *self, u16 *cmd, Glyph0216c800 *arr, u16 *count) {
    u16 n = *count;
    Glyph0216c800 *last = &arr[n - 1];
    if (*cmd == 6) {
        u8 *o = LFLD(u8 *, cmd, 0x8);
        u32 base = last->chr;
        s32 a = LFLD(s32, o, 0x20);
        s32 b = LFLD(s32, o, 0x24);
        arr[0].chr = base - a / 10;
        arr[0].x = 0x52;
        arr[0].a = 0x53;
        arr[1].chr = base - a % 10;
        arr[1].x = 0x5b;
        arr[1].a = 0x53;
        arr[2].chr = base - b / 10;
        arr[2].x = 0x6d;
        arr[2].a = 0x53;
        arr[3].chr = base - b % 10;
        arr[3].x = 0x76;
        arr[3].a = 0x53;
        n = 4;
    }
    *count = n;
    return arr;
}

}
