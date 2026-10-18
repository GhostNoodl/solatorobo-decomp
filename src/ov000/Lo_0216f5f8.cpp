#include "types.h"

#define LFLD(type, obj, off) (*(type *)((u8 *)(obj) + (off)))

extern "C" {

typedef struct {
    s32 c, d;
} Pair0216f5f8;

// The 8-byte tail is copied as its own unit (ldr, ldr, str, str).
typedef struct {
    s32 a, b;
    Pair0216f5f8 cd;
} Ent0216f5f8;

BOOL func_ov000_0216f5f8(u8 *self, Ent0216f5f8 *out, BOOL pop) {
    Ent0216f5f8 *e;
    if (((Ent0216f5f8 *)(self + 0xc))[LFLD(u32, self, 0x10c)].b == -1) {
        out->b = -1;
        return FALSE;
    }
    e = &((Ent0216f5f8 *)(self + 0xc))[LFLD(u32, self, 0x10c)];
    *out = *e;
    if (pop) {
        ((Ent0216f5f8 *)(self + 0xc))[LFLD(u32, self, 0x10c)].b = -1;
        if (++LFLD(u32, self, 0x10c) >= 0x10) {
            LFLD(u32, self, 0x10c) = 0;
        }
    }
    return TRUE;
}

}
