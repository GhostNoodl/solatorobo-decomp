#include "ov000/VObj.h"

extern "C" {

void func_ov000_0215dacc(void *self) {
    if (*(s32 *)((u8 *)self + 4) == 0) {
        *(s32 *)((u8 *)self + 0x88) = *(s32 *)((u8 *)self + 0x8c);
    }
}

}
