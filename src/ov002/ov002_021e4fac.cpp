#include "ov002/ov002.h"

extern "C" {

void func_02011610(void *a, void *b, void *c);

void func_ov002_021e4fac(void *self) {
    u8 *o = FIELD(data_ov002_021f0f98[0], 0x1ec, u8 *);
    u8 *m = FIELD(self, 0xb4, u8 *);
    s32 a = FIELD(o, 0xdc, s32);
    s32 b = FIELD(o, 0xe0, s32);
    s32 c = FIELD(o, 0xe4, s32);
    s32 sx = FIELD(o, 0x94, s32);
    s32 sy = FIELD(o, 0x98, s32);
    s32 sz = FIELD(o, 0x9c, s32);
    if (FIELD(m, 0x0, u32) & 1) {
        FIELD(m, 0x4, s32) = 0x1000;
        FIELD(m, 0x8, s32) = 0x1000;
        FIELD(m, 0xc, s32) = 0x1000;
        FIELD(m, 0x0, u32) &= ~1;
    }
    FIELD(m, 0x4, s32) = FX_MUL(sx, FIELD(m, 0x4, s32));
    FIELD(m, 0x8, s32) = FX_MUL(sy, FIELD(m, 0x8, s32));
    FIELD(m, 0xc, s32) = FX_MUL(sz, FIELD(m, 0xc, s32));
    if (FIELD(m, 0x0, u32) & 2) {
        func_02011340(m + 0x28);
        FIELD(m, 0x0, u32) &= ~2;
    }
    func_02011610(m + 0x28, o + 0xb8, m + 0x28);
    if (FIELD(m, 0x0, u32) & 4) {
        FIELD(m, 0x0, u32) &= ~4;
    }
    FIELD(m, 0x4c, s32) = a;
    FIELD(m, 0x50, s32) = b;
    FIELD(m, 0x54, s32) = c;
}

}
