#include "ov000/VObj.h"

extern "C" {

BOOL func_ov000_0214b640(void *self) {
    return *(s32 *)((u8 *)self + 0x4) == 0x2;
}

/* Nothing references this one, so keep the linker from stripping it. */
#pragma force_active on
BOOL func_ov000_0214b654(void *self) {
    return *(s32 *)((u8 *)self + 0x4) == 0x2 && *(s32 *)((u8 *)self + 0x8) == -1 ? TRUE : FALSE;
}
#pragma force_active reset

}
