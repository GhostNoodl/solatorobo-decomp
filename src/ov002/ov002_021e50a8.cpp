#include "ov002/ov002.h"

extern "C" {

void func_ov002_021e50a8(void *self, void *src) {
    MIi_CpuCopy32(src, (u8 *)self + 0xc0 + FIELD(self, 0x1a0, s32) * 0x1c, 0x1c);
    FIELD(self, 0x1a0, s32)++;
}

}
