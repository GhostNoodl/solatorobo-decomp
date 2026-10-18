#include "ov002/ov002.h"

extern "C" {

BOOL func_ov002_021e4dd4(VObject *self) {
    BOOL r = TRUE;
    switch (FIELD(self, 0xc, s32)) {
    case 0:
        if (!self->v0xc()) {
            break;
        }
        FIELD(self, 0xc, s32) = 1;
    case 1:
        if (!self->v0x10()) {
            break;
        }
        FIELD(self, 0xc, s32) = 2;
    case 2:
        if (!self->v0x14()) {
            break;
        }
        FIELD(self, 0xc, s32) = 3;
    case 3: {
        u8 *g = (u8 *)data_ov002_021f0f98[1];
        s32 m;
        if (FIELD(g, 0x10, u8)) {
            break;
        }
        m = FIELD(self, 0x8, s32);
        if (m == 3) {
            m = 2;
        }
        if (m != FIELD(g, 0xc, s32)) {
            break;
        }
        if (self->v0x18()) {
            break;
        }
        FIELD(self, 0xc, s32) = 4;
    }
    case 4:
    default:
        FIELD(self, 0xc, s32) = 4;
        r = FALSE;
        break;
    }
    return r;
}

}
