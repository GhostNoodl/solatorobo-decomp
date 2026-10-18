#include "ov002/ov002.h"

extern "C" {

void func_ov002_021e3b6c(s32 *out, s32 *v, void *mp) {
    s32 *m = (s32 *)mp;
    s32 x = FX_MUL(v[0], m[0]) + FX_MUL(v[1], m[4]) + FX_MUL(v[2], m[8]) + m[12];
    s32 y = FX_MUL(v[0], m[1]) + FX_MUL(v[1], m[5]) + FX_MUL(v[2], m[9]) + m[13];
    s32 z = FX_MUL(v[0], m[2]) + FX_MUL(v[1], m[6]) + FX_MUL(v[2], m[10]) + m[14];
    s32 w = FX_MUL(v[0], m[3]) + FX_MUL(v[1], m[7]) + FX_MUL(v[2], m[11]) + m[15];
    x = FX_Div(x, w);
    y = FX_Div(y, w);
    z = FX_Div(z, w);
    out[0] = FX_MUL(x, 0x7f800) >> 12;
    out[1] = FX_MUL(-y, 0x60000) >> 12;
}

}
