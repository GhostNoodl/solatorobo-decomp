#include "ov000/LoCommon.h"

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

static inline void G3_Vtx(s16 x, s16 y, s16 z) {
    u32 v[2];
    v[0] = (u16)x | ((u16)y << 16);
    v[1] = (u16)z;
    NNS_G3dGeBufferOP_N(0x23, v, 2);
}

static inline void G3_VtxXY(s16 x, s16 y) {
    u32 v = (u16)x | ((u16)y << 16);
    NNS_G3dGeBufferOP_N(0x25, &v, 1);
}

static inline void G3_TexCoord(s32 s, s32 t) {
    u32 v = (u16)s | ((u16)t << 16);
    NNS_G3dGeBufferOP_N(0x22, &v, 1);
}

static inline void Quad(s32 x, s32 y, s32 z, s32 s0, s32 s1) {
    NNS_G3dGeBufferOP_N(0x11, NULL, 0);
    G3_Vec(0x1c, x, y, z);
    G3_Vec(0x1b, 0x5000, 0x6000, 0x1000);
    G3_Cmd1(0x40, 1);
    G3_TexCoord(s0, 0x60);
    G3_Vtx(0, 0x1000, 0);
    G3_TexCoord(s1, 0x60);
    G3_VtxXY(0x1000, 0x1000);
    G3_TexCoord(s1, 0);
    G3_VtxXY(0x1000, 0);
    G3_TexCoord(s0, 0);
    G3_VtxXY(0, 0);
    NNS_G3dGeBufferOP_N(0x41, NULL, 0);
    G3_Cmd1(0x12, 1);
}

void func_ov000_021c8120(void *self, s32 x, s32 y, s32 z) {
    s32 h = LFLD(s32, self, 0);
    G3_Cmd1(0x20, 0x7fff);
    Quad(x, y, z, 0, 0x50);
    Quad(x, y + h - 0x6000, z, 0x80, 0xd0);
}

}
