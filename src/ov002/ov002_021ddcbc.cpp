#include "ov002/ov002.h"

extern "C" {

BOOL func_ov002_021ddcbc(void *self, void *ev) {
    u8 *t;
    if (ev == NULL) {
        return FALSE;
    }
    t = FIELD(self, 8, u8 *);
    if (FIELD(ev, 0x44, u8) != 0) {
        t[1] = 1;
        func_02049a48(data_02097e4c, 0x1e, -1, -1, -1);
    } else {
        t[1] = 0;
        func_02049a48(data_02097e4c, 0x20, -1, -1, -1);
    }
    return TRUE;
}

BOOL func_ov002_021ddd30(void *self, void *ev) {
    if (ev == NULL) {
        return FALSE;
    }
    FIELD(self, 8, u8 *)[0] = 1;
    func_02049a48(data_02097e4c, 0x1d, -1, -1, -1);
    return TRUE;
}

void func_ov002_021ddd80(void *self) {
    FIELD(self, 0x4, s32) = 0;
    FIELD(self, 0x8, s32) = 0;
    FIELD(self, 0xc, s32) = 0;
    FIELD(self, 0x10, s32) = 0;
    FIELD(self, 0x14, s32) = 0;
    FIELD(self, 0x18, u16) = 0xffff;
    FIELD(self, 0x20, u8) = 0;
    FIELD(self, 0x21, u8) = 0;
    FIELD(self, 0x22, u8) = 0;
    FIELD(self, 0x23, u8) = 0;
    FIELD(self, 0x30, s32) = 0;
    FIELD(self, 0x2c, s32) = 0;
    FIELD(self, 0x24, s32) = 0;
    FIELD(self, 0x28, s32) = 0;
    FIELD(self, 0x34, s32) = 0;
    FIELD(self, 0x38, u8) = 0;
}

}
