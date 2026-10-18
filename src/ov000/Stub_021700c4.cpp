#include "ov000/VObj.h"

extern "C" {

BOOL func_ov000_021700c4(void *self) {
    return *(s32 *)((u8 *)self + 0x24) == 0x4;
}

BOOL func_ov000_021700d8(void *self) {
    return *(s32 *)((u8 *)self + 0x24) == 0x5;
}

BOOL func_ov000_021700ec(void *self) {
    return *(s32 *)((u8 *)self + 0x24) == 0x6;
}

}
