#include "ov000/VObj.h"

extern "C" {

void func_ov000_02182ad4(void *self) {
    s32 *index = (s32 *)((u8 *)self + 0x94);
    ((s32 *)((u8 *)self + 0x10))[*index] = 0x3;
    ((s32 *)((u8 *)self + 0x50))[*index] = 0;
    if (++*index >= 0x10) {
        *index = 0;
    }
}

}
