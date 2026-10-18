#include "ov002/ov002.h"

extern "C" {

void func_ov002_021d7d5c(void *self, int a);

void func_ov002_021d8c34(void *self, s32 d, int arg) {
    s32 n;
    s32 r;
    if (FIELD(self, 0xa4, s32) != 0 && FIELD(self, 0xac, s32) != 1) {
        return;
    }
    n = FIELD(self, 0x52, Bits021d8b48).mode;
    FIELD(self, 0xcc, u8) = n;
    n += d;
    r = (n < 0 ? -n : n) % 4;
    if (n < 0) {
        r = 4 - r;
    }
    FIELD(self, 0x52, Bits021d8b48).mode = (u8)r;
    func_ov002_021d7d5c(self, arg);
    func_ov002_021e3b0c((s32 *)((u8 *)self + 0x4), (s32 *)((u8 *)self + 0x54), (s32 *)((u8 *)self + 0x64));
    FIELD(self, 0xc8, s32) = ((d < 0 ? -d : d) % 4) * 0x3fff;
    if (d < 0) {
        FIELD(self, 0xc8, s32) = -FIELD(self, 0xc8, s32);
    }
    FIELD(self, 0xa4, s32) = 4;
    FIELD(self, 0xa8, s32) = 4;
    FIELD(self, 0xac, s32) = 5;
}

}
