#include "ov002/ov002.h"

extern "C" {

BOOL func_ov002_021e7118(void) {
    return TRUE;
}

BOOL func_ov002_021e7120(void *self) {
    switch (FIELD(self, 0x4c, s32)) {
    case 0:
        FIELD(self, 0x54, s32) = 0x1f;
        FIELD(self, 0x58, s32) = 0;
        break;
    case 1:
        FIELD(self, 0x54, s32) = 0;
        FIELD(self, 0x58, s32) = 0x1f;
        break;
    }
    return TRUE;
}

BOOL func_ov002_021e715c(void *self) {
    u8 *ctx = (u8 *)data_ov002_021f0f98[1];
    s32 v = FIELD(ctx, 0xd0, s32);
    if (v <= FIELD(self, 0x18, s32)) {
        return TRUE;
    }
    if (v > FIELD(self, 0x1c, s32)) {
        return FALSE;
    }
    FIELD(ctx, 0x138, u16) = FIELD(self, 0x50, u16);
    return TRUE;
}

}
