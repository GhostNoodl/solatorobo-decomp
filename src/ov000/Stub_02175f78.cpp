#include "ov000/VObj.h"

extern "C" {

void func_ov000_02175f78(void *self) {
    *(s32 *)((u8 *)self + 0x20) = 0x1000;
    *(s32 *)((u8 *)self + 0x3c) = 0;
    *(s32 *)((u8 *)self + 0x40) = 0;
    *(s16 *)((u8 *)self + 0x44) = 0;
}

}
