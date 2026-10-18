#include "ov000/VObj.h"

extern "C" {

void func_ov000_021c7000(void *self) {
    *(u32 *)((u8 *)self + 0xc) |= 4;
    *(u32 *)((u8 *)self + 0xc4) |= 4;
}

void func_ov000_021c701c(void *self) {
    *(u32 *)((u8 *)self + 0xc4) &= ~4;
    *(u32 *)((u8 *)self + 0xc) &= ~4;
}

}
