#include "ov000/LoCommon.h"
#include "ov000/ObjLayouts.h"
#include "ov000/UiObj.h"
#include "Main/Gfx/GfxMgr.h"

#define GX_PACK_POLYGONATTR_PARAM(light, polyMode, cullMode, polygonID, alpha, misc) \
    ((u32)(((light) << 0) | ((polyMode) << 4) | ((cullMode) << 6) | (misc) | ((polygonID) << 24) | ((alpha) << 16)))

typedef struct {
    u16 x;
    u16 y;
    u16 z;
} V6;

extern "C" {
u8 Gfx3DState_NextPolyId(void *p);
void Gfx3D_SendDL(void *p, int a);
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

//@ Menu021ca94c_DrawFrame
void Menu021ca94c_DrawFrame(Menu021ca94c *self, s32 a1, s32 *pos) {
    s16 z;
    s32 sy;
    u8 *g;
    g = gGfxSys->unk_8b0;
    z = self->posZ - 0x110;
    Gfx3D_SendDL(g, 0);
    G3_Cmd1(0x2a, 0x20000000);
    sy = self->height << 12;
    G3_Cmd1(0x29, GX_PACK_POLYGONATTR_PARAM(0, 1, 3, Gfx3DState_NextPolyId(g), 0x1e, 0x800));
    NNS_G3dGeBufferOP_N(0x11, NULL, 0);
    G3_Vec(0x1c, pos[0], pos[1], self->posZ);
    G3_Vec(0x1b, 0x100000, 0x1000, 0x1000);
    G3_Cmd1(0x40, 0);
    G3_Cmd1(0x20, 0);
    G3_Cmd2(0x23, 0, 0);
    G3_Cmd1(0x25, 0x1000);
    G3_Cmd1(0x25, 0x1000);
    NNS_G3dGeBufferOP_N(0x41, NULL, 0);
    G3_Cmd1(0x12, 1);
    G3_Cmd1(0x29, GX_PACK_POLYGONATTR_PARAM(0, 1, 3, Gfx3DState_NextPolyId(g), 0x12, 0x800));
    NNS_G3dGeBufferOP_N(0x11, NULL, 0);
    G3_Vec(0x1c, pos[0], pos[1], z);
    G3_Vec(0x1b, 0x100000, sy, 0x1000);
    G3_Cmd1(0x40, 3);
    G3_Cmd1(0x20, 0x842);
    G3_Cmd2(0x23, 0x1000, 0);
    G3_Cmd1(0x25, 0);
    G3_Cmd1(0x25, 0x8001000);
    G3_Cmd1(0x25, 0x8000000);
    G3_Cmd1(0x20, 0x739c);
    G3_Cmd1(0x25, 0x8001000);
    G3_Cmd1(0x25, 0x8000000);
    G3_Cmd1(0x25, 0x10001000);
    G3_Cmd1(0x25, 0x10000000);
    NNS_G3dGeBufferOP_N(0x41, NULL, 0);
    G3_Cmd1(0x12, 1);
}

//@end
}
