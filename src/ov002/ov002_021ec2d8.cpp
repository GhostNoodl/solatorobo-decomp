#include "ov002/ov002.h"

extern "C" {

void func_ov002_021ec2d8(void *self) {
    u8 *p = *(u8 **)VC(self, 0x10)();
    u8 *base;
    u16 i;
    FIELD(self, 0x4c, u8 *) = p;
    base = p + FIELD(p, 0x8, u16);
    for (i = 0; i < FIELD(p, 0xa, u16); i++) {
        s32 v;
        p += i * 0x14;
        v = FIELD(p, 0x14, s32);
        if (v != -1) {
            if (v & 0x80000000) {
                FIELD(p, 0x14, s32) = v & ~0x80000000;
            } else {
                FIELD(p, 0x14, s32) = (s32)(base + v);
            }
        } else {
            FIELD(p, 0x14, s32) = 0;
        }
        p = FIELD(self, 0x4c, u8 *) + i * 0x14;
        FIELD(p, 0x10, s32) <<= 12;
        p = FIELD(self, 0x4c, u8 *);
    }
}

}
