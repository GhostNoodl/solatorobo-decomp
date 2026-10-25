#include "ov000/LoCommon.h"

typedef struct {
    s16 x;
    s16 y;
    s16 z;
} V6_02153804;

#define VERTS LFLD(V6_02153804 *, self, 0x6c)

extern "C" {
s32 FX_Div(s32 numer, s32 denom);
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

void func_ov000_02153804(u8 *self, s32 on, s32 *pos, s32 scale) {
    s16 z;
    u16 c;
    s32 sx;
    s32 sy;
    s16 t;
    s16 q;
    V6_02153804 *v;
    s32 n;
    if (on == 0) {
        return;
    }
    sy = LFLD(s16, self, 0x68) - 0x100;
    z = sy;
    sx = LFLD(s32, self, 0x24) << 12;
    sy = LFLD(s32, self, 0x28) << 12;
    t = FX_Div(0x5000, sy);
    q = t / 5 / 2;
    NNS_G3dGeBufferOP_N(0x11, NULL, 0);
    G3_Vec(0x1c, pos[0], pos[1], z);
    G3_Vec(0x1b, scale, scale, 0x1000);
    G3_Vec(0x1b, sx, sy, 0x1000);
    G3_Cmd1(0x40, 1);
    c = LFLD(u16, self, 0x48);
    {
        u8 r = (c & 0x1f) >> 1;
        u8 g = ((c >> 5) & 0x1f) >> 1;
        u8 b = ((c >> 10) & 0x1f) >> 1;
        G3_Cmd1(0x20, (u16)(r | (g << 5) | (b << 10)));
    }
    v = LFLD(V6_02153804 *, self, 0x6c);
    if (v != NULL) {
        n = LFLD(s32, self, 0x70) - 1;
        G3_Vtx(VERTS[0].x, VERTS[0].y, 0);
        G3_VtxXY(VERTS[2].x, VERTS[2].y);
        G3_VtxXY(VERTS[2].x, -t);
        G3_VtxXY(VERTS[0].x, -t);
        G3_Vtx(VERTS[1].x, VERTS[1].y, 0);
        G3_VtxXY(VERTS[1].x, VERTS[1].y + t + q);
        G3_VtxXY(VERTS[n].x, t + VERTS[n].y + q);
        G3_VtxXY(VERTS[n].x, VERTS[n].y);
    } else {
        G3_Vtx(0xf8, 0, 0);
        G3_VtxXY(0xf17, 0);
        G3_VtxXY(0xf17, -t);
        G3_VtxXY(0xf8, -t);
        G3_Vtx(0x84, 0x1000, 0);
        G3_VtxXY(0x84, t + 0x1000 + q);
        G3_VtxXY(0xf9c, t + 0xf9c + q);
        G3_VtxXY(0xf9c, 0x1000);
    }
    NNS_G3dGeBufferOP_N(0x41, NULL, 0);
    G3_Cmd1(0x12, 1);
}
}
