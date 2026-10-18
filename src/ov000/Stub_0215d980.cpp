#include "ov000/VObj.h"

extern "C" {

void func_ov000_0215d980(void *self, s32 value, BOOL both) {
    if (both) {
        *(s32 *)((u8 *)self + 0x88) = value;
    }
    *(s32 *)((u8 *)self + 0x8c) = value;
}

}
