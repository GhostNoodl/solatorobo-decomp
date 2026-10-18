#include "ov002/ov002.h"

extern "C" {

void func_ov002_021e3b0c(s32 *out, s32 *pos, s32 *origin) {
    s32 x = pos[0];
    s32 z = pos[1];
    s32 dz = (z - origin[1]) * 0x28f;
    out[0] = (x - origin[0]) * 0x28f;
    out[2] = dz;
}

void func_ov002_021e3b40(s32 *out, s32 x, s32 z, s32 *origin) {
    s32 ox = origin[0];
    s32 oz = origin[1];
    s32 dz = (z - oz) * 0x28f;
    out[0] = (x - ox) * 0x28f;
    out[2] = dz;
}

}
