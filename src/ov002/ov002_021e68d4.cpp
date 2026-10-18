#include "ov002/ov002.h"

extern "C" {

BOOL func_ov002_021e68d4(void *self) {
    BOOL r = FALSE;
    switch (FIELD(self, 0x10, s32)) {
    case 0:
        if (FIELD(self, 0x4c, s8) != 0 && FIELD(self, 0x6c, s8) != 0) {
            func_020359fc((u8 *)self + 0x4c, (u8 *)self + 0x6c, 0, 0);
            FIELD(self, 0x10, s32)++;
            FIELD(self, 0x14, s32) = 1;
        } else {
            FIELD(self, 0x10, s32) = -1;
            r = TRUE;
            break;
        }
    case 1:
        if (func_02035bd4((u8 *)self + 0x4c, (u8 *)self + 0x6c, 0) == 0) {
            break;
        }
        FIELD(self, 0x10, s32)++;
    case 2: {
        void *t = func_02035fe8((u8 *)self + 0x4c, (u8 *)self + 0x6c);
        if (t != NULL) {
            func_ov002_021ec1e0((u8 *)self + 0x94, t);
        }
        FIELD(self, 0x10, s32) = -1;
        break;
    }
    case -1:
    default:
        r = TRUE;
        break;
    }
    return r;
}

BOOL func_ov002_021e69a8(void) {
    return TRUE;
}

}
