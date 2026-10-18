#include "ov000/VObj.h"

extern "C" {

void func_ov000_0215ad9c(void *self) {
    *(u32 *)((u8 *)self + 0xc) &= ~0x20000;
    *(s32 *)((u8 *)self + 0x24) = -1;
    *(s32 *)((u8 *)self + 0xd4) = 0;
}

}
