#include "ov002/ov002.h"

extern "C" {

BOOL Ov002Shape_GetOrigin(s32 *out, Ov002Shape *shape) {
    u16 v = FIELD(shape, 0x6, u16);
    out[0] = (u32)(v << 28) >> 28;
    out[1] = (u32)(v << 24) >> 28;
    return TRUE;
}

}
