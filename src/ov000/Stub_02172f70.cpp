#include "ov000/VObj.h"

extern "C" {

void func_ov000_02172f70(void *self, s32 a, s32 b) {
    *(s32 *)((u8 *)self + 0x14) = a;
    *(s32 *)((u8 *)self + 0x10) = b;
}

}
