#include "ov000/ModelPart.h"
#include "Main/Gfx/GfxMgr.h"

#define LO_FX_MUL(a, b) ((s32)(((s64)(a) * (b) + 0x800) >> 12))

typedef struct {
    u32 unk_00;
    void *unk_04;
} DLRef021bbf78;

extern "C" {
extern DLRef021bbf78 Gfx3D_PrimDLs;
extern DLRef021bbf78 Gfx3D_PrimDLSizes;
s32 Gfx3DState_NextPolyIdB(void *p);
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

static inline void SetOfs(Model *m, s32 x, s32 y, s32 dy) {
    Model_SetPos(m, x << 12, (y - dy) << 12);
}


struct Obj021bbf78 {
    u8 unk_00[0x58];
    Model *unk_58;
    u8 unk_5c[0x4];
    s32 unk_60;
    u8 unk_64[0x4];
    s32 unk_68;
    u8 unk_6c[0x4];
    s32 unk_70;
};

void Obj021bbf78_Draw(Obj021bbf78 *self) {
    GfxSys *g;
    s32 alpha;
    s32 t;
    alpha = LO_FX_MUL(self->unk_68, 0x14000) >> 12;
    g = gGfxSys;
    if (alpha == 0) {
        return;
    }
    G3_Cmd1(0x29, (Gfx3DState_NextPolyIdB(g->unk_8b0) << 24) | 0xd0 | (alpha << 16));
    NNS_G3dGeBufferOP_N(0x11, NULL, 0);
    G3_Vec(0x1c, 0, 0, -0x91a);
    G3_Cmd1(0x20, 0);
    G3_Cmd1(0x2a, 0x20000000);
    G3_Vec(0x1b, 0x100000, 0xc0000, 0x1000);
    NNS_G3dGeSendDL(Gfx3D_PrimDLs.unk_04, (u32)Gfx3D_PrimDLSizes.unk_04);
    G3_Cmd1(0x12, 1);
    MODEL_FLAGS(self->unk_58)->unk_19 = 1;
    MODEL_FLAGS(self->unk_58)->alpha = (u8)alpha;
    MODEL_FLAGS(self->unk_58)->polygon_id = Gfx3DState_NextPolyIdB(g->unk_8b0);
    self->unk_58->unk_150 = -0x89a;
    Model_SetPos(self->unk_58, 0, 0);
    Model_PlayPart(self->unk_58, 0);
    t = self->unk_60 % 0x40000;
    if (t < 0x18000) {
        self->unk_70 += LO_FX_MUL(0x8000 - self->unk_70, 0x148LL);
    } else if (t < 0x3f000) {
        self->unk_70 += LO_FX_MUL(0 - self->unk_70, 0xcdLL);
    } else {
        self->unk_70 = 0;
    }

    SetOfs(self->unk_58, 0, -0x10, self->unk_70 >> 12);
    Model_PlayPart(self->unk_58, 1);
}

}
