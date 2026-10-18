#include "ov000/VObj.h"

extern "C" {

void func_ov000_02157ddc(void *self) {
    *(s32 *)((u8 *)self + 0xd4) = 0;
    *(s32 *)((u8 *)self + 0xd8) = 0;
    *(u8 *)((u8 *)self + 0xdc) = 0;
}

}
