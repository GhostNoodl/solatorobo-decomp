#include "ov000/LoCommon.h"

typedef struct {
    u8 pad_00[0x10];
    u16 *cols[4];
} Pal021609ec;

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

void func_ov000_02160c7c(void *self, s32 x, s32 y, s32 z, s32 sx, s32 sy, s32 idx) {
    u16 *col = ((Pal021609ec *)self)->cols[idx];
    NNS_G3dGeBufferOP_N(0x11, NULL, 0);
    G3_Vec(0x1c, x, y, 0);
    G3_Vec(0x1b, sx, sy, 0x1000);
    G3_Cmd1(0x40, 3);
    G3_Cmd1(0x20, col[0]);
    G3_Vtx(0x1000, 0, z);
    G3_VtxXY(0, 0);
    G3_Cmd1(0x20, col[1]);
    G3_VtxXY(0x1000, 0x800);
    G3_VtxXY(0, 0x800);
    G3_Cmd1(0x20, col[2]);
    G3_VtxXY(0x1000, 0x1000);
    G3_VtxXY(0, 0x1000);
    NNS_G3dGeBufferOP_N(0x41, NULL, 0);
    G3_Cmd1(0x12, 1);
}

}
