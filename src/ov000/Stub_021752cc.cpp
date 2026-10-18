#include "ov000/VObj.h"

extern "C" {

void func_ov000_021752cc(void *self) {
    if (*(s32 *)((u8 *)self + 0x4c) == -1) {
        u8 *p = *(u8 **)((u8 *)self + 0x40);
        if (p != NULL) {
            *(u32 *)(p + 0xc) &= ~4;
        }
    }
}

}
