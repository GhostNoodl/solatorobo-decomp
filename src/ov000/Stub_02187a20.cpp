#include "ov000/VObj.h"

extern "C" {

void func_ov000_02187a20(void *self, s32 arg) {
    s32 *index = (s32 *)((u8 *)self + 0x94);
    ((s32 *)((u8 *)self + 0x10))[*index] = 0x25;
    ((s32 *)((u8 *)self + 0x50))[*index] = arg;
    if (++*index >= 0x10) {
        *index = 0;
    }
}

}
