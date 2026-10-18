#include "ov002/ov002.h"

extern "C" {

void func_ov002_021e0420(void *self) {
    u8 *obj = FIELD(self, 0xb0, u8 *);
    s32 w = FIELD(obj, 0xc, s32);
    s32 v = (s32)(((s64)*FIELD(FIELD(self, 0x4, u8 *), 0x2c, s32 *) * (((w & 0x1f0000) >> 16) << 12) + 0x800) >> 12) >> 12;
    FIELD(obj, 0xc, s32) = (w & ~0x1f0000) | ((u8)v << 16);
}

BOOL func_ov002_021e046c(void *self, void *ev) {
    s32 *out = FIELD(self, 0x8, s32 *);
    if (ev != NULL) {
        *out = FIELD(ev, 0x6, u16);
    } else {
        *out = -1;
    }
    return FALSE;
}

}
