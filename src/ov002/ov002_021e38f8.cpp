#include "ov002/ov002.h"

extern "C" {

BOOL func_ov002_021e38f8(s32 *out, void *ev) {
    u16 v = FIELD(ev, 0x6, u16);
    out[0] = (u32)(v << 28) >> 28;
    out[1] = (u32)(v << 24) >> 28;
    return TRUE;
}

}
