#include "types.h"
#define LFLD(type, obj, off) (*(type *)((u8 *)(obj) + (off)))

typedef struct {
    u32 a : 8;
    u32 b : 8;
    u32 x : 9;
    u32 c : 7;
    u32 chr : 10;
    u32 d : 22;
} Glyph021c77bc;

static inline s32 GetWidth021c77bc(u8 *obj) {
    return LFLD(s32, obj, 0x28);
}

extern "C" {

Glyph021c77bc *func_ov000_021c77bc(u8 *self, u16 *cmd, Glyph021c77bc *arr, u16 *count) {
    u16 n = *count;
    if (*cmd == 2) {
        s32 w = GetWidth021c77bc(LFLD(u8 *, cmd, 0x8)) - 0xc;
        arr[0].x = 0;
        arr[0].a = (u16)w & 0x1ff;
        arr[1].x = 0;
        arr[1].a = 0;
        n = 2;
    }
    *count = n;
    return arr;
}

}
