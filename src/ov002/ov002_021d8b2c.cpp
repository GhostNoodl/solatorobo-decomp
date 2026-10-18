#include "ov002/ov002.h"

extern "C" {

void func_ov002_021d8b2c(void *self, Vec2 *out) {
    out->x = FIELD(self, 0x64, s32);
    out->y = FIELD(self, 0x68, s32);
}

void *func_ov002_021d8b40(void *self) {
    return (u8 *)self + 0x4c;
}

u8 func_ov002_021d8b48(void *self) {
    return FIELD(self, 0x52, Bits021d8b48).mode;
}

void func_ov002_021d8b5c(void *a, void *b, void *c) {
    func_020117a4(c, b, a);
}

u8 func_ov002_021d8b74(void *self) {
    return FIELD(self, 0x4a, u8);
}

void func_ov002_021d8b7c(void *self) {
    if (FIELD(self, 0xa4, s32) == 0 && FIELD(self, 0xac, s32) == 1) {
        FIELD(self, 0xa4, s32) = 5;
        FIELD(self, 0xa8, s32) = 5;
        FIELD(self, 0xac, s32) = 6;
    }
}

void func_ov002_021d8ba4(void *self) {
    if (FIELD(self, 0xa4, s32) == 0 && FIELD(self, 0xac, s32) == 2) {
        FIELD(self, 0xa4, s32) = 5;
        FIELD(self, 0xa8, s32) = 5;
        FIELD(self, 0xac, s32) = 7;
    }
}

void func_ov002_021d8bcc(void *self) {
    if (FIELD(self, 0xac, s32) == 8) {
        return;
    }
    if (FIELD(self, 0xa4, s32) != 0) {
        return;
    }
    func_ov002_021e3b0c((s32 *)((u8 *)self + 0xbc), (s32 *)((u8 *)self + 0x54), (s32 *)((u8 *)self + 0x64));
    FIELD(self, 0xc0, s32) = 0x400;
    FIELD(self, 0xb0, s32) = 0xb33;
    FIELD(self, 0xb8, s32) = 0;
    FIELD(self, 0xb4, s32) = 0x400;
    FIELD(self, 0xa4, s32) = 0x14;
    FIELD(self, 0xa8, s32) = 0x14;
    FIELD(self, 0xac, s32) = 8;
}

}
