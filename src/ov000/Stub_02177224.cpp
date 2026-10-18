#include "ov000/VObj.h"

extern "C" {

void func_ov000_02177224(void *self) {
    u8 *p = *(u8 **)((u8 *)self + 0x4c);
    if (p != NULL) {
        *(u32 *)(p + 0xc) &= ~4;
    }
}

void func_ov000_0217723c(void) {
}

}
