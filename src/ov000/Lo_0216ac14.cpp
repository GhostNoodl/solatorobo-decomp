#include "ov000/LoCommon.h"

typedef struct {
    u32 a : 8;
    u32 b : 8;
    u32 c : 9;
    u32 d : 7;
    u32 f : 10;
    u32 rest : 22;
} LoGlyphEnt;

extern "C" {

LoGlyphEnt *func_ov000_0216ac14(void *self, u16 *msg, LoGlyphEnt *arr, u16 *cnt) {
    u16 n = *cnt;
    LoGlyphEnt *e = &arr[n - 1];
    if (*msg == 6) {
        u32 f = e->f;
        s32 v = LFLD(s32, LFLD(void *, msg, 8), 0x10);
        if (v >= 10) {
            e[-1].f = f - v % 10;
            e[0].f = f - v / 10;
            arr = e - 1;
            n = 2;
        } else {
            e[-1].f = f - v % 10;
            arr = e - 1;
            n = 1;
        }
    }
    *cnt = n;
    return arr;
}

}
