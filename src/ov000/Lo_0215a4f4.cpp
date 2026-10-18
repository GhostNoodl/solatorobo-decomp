#include "ov000/LoCommon.h"

#define GX_PACK_POLYGONATTR_PARAM(light, polyMode, cullMode, polygonID, alpha, misc) \
    ((u32)(((light) << 0) | ((polyMode) << 4) | ((cullMode) << 6) | (misc) | ((polygonID) << 24) | ((alpha) << 16)))

typedef struct {
    u16 x;
    u16 y;
    u16 z;
} V6;

extern "C" {
extern u8 *data_02097d48;
s32 func_02043d48(void *p);
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

static inline void G3_PolygonAttr(s32 light, s32 polyMode, s32 cullMode, s32 polygonID, s32 alpha, s32 misc) {
    G3_Cmd1(0x29, light | (polyMode << 4) | (cullMode << 6) | (polygonID << 24) | (alpha << 16) | misc);
}

static inline void G3_Cmd2(int cmd, u32 a, u32 b) {
    u32 v[2];
    v[0] = a;
    v[1] = b;
    NNS_G3dGeBufferOP_N(cmd, v, 2);
}

void func_ov000_0215a4f4(u8 *self, s32 enable, s32 *pos) {
    s16 z;
    u8 *g;
    s32 sx;
    s32 sy;
    s32 x;
    s32 y;
    if (enable == 0) {
        return;
    }
    z = LFLD(s16, self, 0x68) - 0x100;
    g = data_02097d48;
    G3_Cmd1(0x2a, 0x20000000);
    G3_Cmd1(0x29, GX_PACK_POLYGONATTR_PARAM(0, 1, 3, func_02043d48(g + 0x8b0), 0x1e, 0x800));
    sx = (LFLD(s32, self, 0x24) - 4) << 12;
    sy = (LFLD(s32, self, 0x28) - 0xe) << 12;
    NNS_G3dGeBufferOP_N(0x11, NULL, 0);
    if (LBIT(self, 0xc).b6 ? TRUE : FALSE) {
        G3_Vec(0x1c, pos[0] + 0x4000, pos[1] + 0x7000, z);
        G3_Vec(0x1b, sx - 0x4000, sy, 0x1000);
        G3_Cmd1(0x40, 1);
        G3_Cmd1(0x20, 0x12ff);
        G3_Cmd2(0x23, 0x1000, 0);
        G3_Cmd1(0x25, 0);
        G3_Cmd1(0x25, 0x10000000);
        G3_Cmd1(0x25, 0x10001000);
        NNS_G3dGeBufferOP_N(0x41, NULL, 0);
    } else {
        G3_Vec(0x1c, pos[0] + 0x2000, pos[1] + 0x7000, z);
        G3_Vec(0x1b, sx, sy, 0x1000);
        G3_Cmd1(0x40, 1);
        G3_Cmd1(0x20, 0x25d6);
        G3_Cmd2(0x23, 0x1000, 0);
        G3_Cmd1(0x25, 0);
        G3_Cmd1(0x20, 0x42b9);
        G3_Cmd1(0x25, 0x10000000);
        G3_Cmd1(0x25, 0x10001000);
        NNS_G3dGeBufferOP_N(0x41, NULL, 0);
    }
    G3_Cmd1(0x12, 1);
}

}
