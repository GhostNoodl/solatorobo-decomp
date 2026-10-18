#include "ov002/ov002.h"

extern "C" {

void func_ov002_021dc510(void *self, void *other) {
    u8 *o4 = FIELD(other, 4, u8 *);
    s32 row = FIELD(self, 0x28, s32);
    void *q = FIELD(o4, 4, void *);
    s32 col = FIELD(self, 0x24, s32);
    u8 *base;
    u8 *e;
    if (q == NULL || (base = FIELD(o4, 0x70, u8 *)) == NULL) {
        e = NULL;
    } else {
        e = base + (row * FIELD(FIELD(q, 0x6c, u8 *), 4, Nibbles16).n3 + col) * 0xc;
    }
    if (e[2] == 1) {
        u8 *t = FIELD(e, 8, u8 *);
        FIELD(t, 0xcd, u8) = 0;
        FIELD(t, 0x9c, s32) = 0xf85;
    }
    FIELD(other, 0x28, s32) = FIELD(self, 0x24, s32);
    FIELD(other, 0x2c, s32) = FIELD(self, 0x28, s32);
    func_ov002_021dbdb8(self);
}

}
