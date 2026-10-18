#include "ov002/ov002.h"

extern "C" {

void func_ov002_021df7b4(void *self, u32 *ev) {
    u16 y = ev[1];
    u16 x = ev[0];
    FIELD(self, 0x54, s32) = x;
    FIELD(self, 0x58, s32) = y;
    func_ov002_021e3b0c((s32 *)((u8 *)self + 0x4), (s32 *)((u8 *)self + 0x54), (s32 *)((u8 *)self + 0x64));
}

}
