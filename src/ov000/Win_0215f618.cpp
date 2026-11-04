#include "ov000/LoCommon.h"
#include "ov000/ModelPart.h"
#include "Main/Gfx/GfxMgr.h"
#include "ov000/UiObj.h"

extern "C" {

extern UiLabelStyle UiLabel_StyleTable[];
extern u8 Gfx3D_PrimDLs[];
extern u8 Gfx3D_PrimDLSizes[];
u8 Gfx3DState_NextPolyId(void *p);
void NNS_G3dGeBufferOP_N(int cmd, const void *data, int count);
void NNS_G3dGeSendDL(const void *dl, u32 size);

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

void UiLabel_DrawBox(UiLabel *self, s32 *pos) {
    u32 cmd;
    s32 sx;
    s32 sy;
    u8 shadow;
    GfxSys *g = gGfxSys;
    u32 misc = 0;
    u32 alpha;
    s32 sw;
    BOOL useAlpha;
    s32 sh;
    UiLabelStyle *e;
    G3_Cmd1(0x2a, 0x20000000);
    useAlpha = TRUE;
    if (!MODEL_FLAGS(self->model)->unk_19) {
        useAlpha = FALSE;
    }
    if (useAlpha) {
        alpha = (u8)MODEL_FLAGS(self->model)->alpha;
    } else {
        alpha = 0x1e;
    }
    if (MODEL_FLAGS(self->model)->unk_20 ? TRUE : FALSE) {
        misc |= 0x4000;
    }
    e = &UiLabel_StyleTable[self->style];
    if (self->style == 0) {
        sx = e->ofsX + (pos[0] << 12);
        sy = e->ofsY + (pos[1] << 12);
        sw = (self->width << 12) - (e->ofsX << 1);
        sh = ((self->height - 2) << 12) - (e->ofsY << 1);
    }
    cmd = misc | 0xd0 | (Gfx3DState_NextPolyId(g->unk_8b0) << 24);
    shadow = TRUE;
    G3_Cmd1(0x29, cmd | (alpha << 16));
    NNS_G3dGeBufferOP_N(0x11, NULL, 0);
    G3_Vec(0x1c, sx, sy, pos[2]);
    G3_Vec(0x1b, sw, sh + 0x2000, 0x1000);
    G3_Cmd1(0x20, 0);
    NNS_G3dGeSendDL(LFLD(void *, Gfx3D_PrimDLs, 4), LFLD(u32, Gfx3D_PrimDLSizes, 4));
    G3_Cmd1(0x12, 1);
    if (!MODEL_FLAGS(self->model)->unk_21) {
        shadow = FALSE;
    }
    if (shadow) {
        misc |= 0x800;
    }
    G3_Cmd1(0x29, (g->unk_8b0[1] << 24) | (misc | 0xd0) | (alpha << 16));
    NNS_G3dGeBufferOP_N(0x11, NULL, 0);
    G3_Vec(0x1c, sx, sy + 0x1000, pos[2]);
    G3_Vec(0x1b, sw, sh, 0x1000);
    G3_Cmd1(0x40, 1);
    G3_Cmd1(0x20, e->color0);
    G3_Cmd2(0x23, 0x1000, 0);
    G3_Cmd1(0x25, 0);
    G3_Cmd1(0x20, e->color1);
    G3_Cmd1(0x25, 0x10000000);
    G3_Cmd1(0x25, 0x10001000);
    NNS_G3dGeBufferOP_N(0x41, NULL, 0);
    G3_Cmd1(0x12, 1);
    MODEL_FLAGS(self->model)->polygon_id = Gfx3DState_NextPolyId(g->unk_8b0);
}

}
