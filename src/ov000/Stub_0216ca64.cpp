#include "ov000/VObj.h"

extern "C" {

void func_ov000_0216ca64(void *self, s32 a, s32 b) {
    *(s32 *)((u8 *)self + 0x20) = a;
    *(s32 *)((u8 *)self + 0x24) = b;
}

}
