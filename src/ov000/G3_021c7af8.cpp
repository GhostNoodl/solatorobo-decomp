#include "ov000/LoCommon.h"
#include "nitro/fx.h"

extern "C" {
void NNS_G3dGeBufferOP_N(int cmd, const void *data, int count);

static inline void G3_Vec(int cmd, int x, int y, int z) {
    int v[3];
    v[0] = x;
    v[1] = y;
    v[2] = z;
    NNS_G3dGeBufferOP_N(cmd, v, 3);
}

static inline void G3_Cmd1(int cmd, u32 value) {
    u32 v = value;
    NNS_G3dGeBufferOP_N(cmd, &v, 1);
}

static inline void G3_Cmd2(int cmd, u32 a, u32 b) {
    u32 v[2];
    v[0] = a;
    v[1] = b;
    NNS_G3dGeBufferOP_N(cmd, v, 2);
}

void func_ov000_021c7af8(const VecFx32 *size, s32 x, s32 y, s32 z) {
    s32 w = size->x - 0xc000;
    s32 h = FX_Mul(w, size->z);
    y = y + 0x6000 + FX_Mul(w, size->y);
    G3_Cmd1(0x20, 0x7fff);
    NNS_G3dGeBufferOP_N(0x11, NULL, 0);
    G3_Vec(0x1c, x + 0x1000, y, z + 0x20);
    G3_Vec(0x1b, 0x3000, 0x1000, 0x1000);
    G3_Cmd1(0x40, 1);
    G3_Cmd1(0x22, 0x500000);
    G3_Cmd2(0x23, 0x10000000, 0);
    G3_Cmd1(0x22, 0x500030);
    G3_Cmd1(0x25, 0x10001000);
    G3_Cmd1(0x22, 0x400030);
    G3_Cmd1(0x25, 0x1000);
    G3_Cmd1(0x22, 0x400000);
    G3_Cmd1(0x25, 0);
    NNS_G3dGeBufferOP_N(0x41, NULL, 0);
    G3_Cmd1(0x12, 1);
    NNS_G3dGeBufferOP_N(0x11, NULL, 0);
    G3_Vec(0x1c, x + 0x1000, y + 0x1000, z + 0x20);
    G3_Vec(0x1b, 0x3000, h - 0x2000, 0x1000);
    G3_Cmd1(0x40, 1);
    G3_Cmd1(0x22, 0x600000);
    G3_Cmd2(0x23, 0x10000000, 0);
    G3_Cmd1(0x22, 0x600030);
    G3_Cmd1(0x25, 0x10001000);
    G3_Cmd1(0x22, 0x500030);
    G3_Cmd1(0x25, 0x1000);
    G3_Cmd1(0x22, 0x500000);
    G3_Cmd1(0x25, 0);
    NNS_G3dGeBufferOP_N(0x41, NULL, 0);
    G3_Cmd1(0x12, 1);
    NNS_G3dGeBufferOP_N(0x11, NULL, 0);
    G3_Vec(0x1c, x + 0x1000, y + h - 0x1000, z + 0x20);
    G3_Vec(0x1b, 0x3000, 0x1000, 0x1000);
    G3_Cmd1(0x40, 1);
    G3_Cmd1(0x22, 0x700000);
    G3_Cmd2(0x23, 0x10000000, 0);
    G3_Cmd1(0x22, 0x700030);
    G3_Cmd1(0x25, 0x10001000);
    G3_Cmd1(0x22, 0x600030);
    G3_Cmd1(0x25, 0x1000);
    G3_Cmd1(0x22, 0x600000);
    G3_Cmd1(0x25, 0);
    NNS_G3dGeBufferOP_N(0x41, NULL, 0);
    G3_Cmd1(0x12, 1);
}
}
