#include "ov000/LoCommon.h"
#include "ov000/Vec.h"
#include "ov000/UiObj.h"
#include "Main/Gfx/TextWin.h"
#include "Main/Gfx/GfxMgr.h"
#include "Main/Gfx/Model.h"
#include "ov000/ModelPart.h"


extern "C" {

extern u8 data_0208b3d0[];
extern u8 data_020828f8[];
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


void UiObj_DrawTitle(UiObj *self, s32 ratio, VecFx32 *pos, s32 arg3) {
    s32 x;
    s32 h;
    GfxSys *g;
    s16 z;
    u8 *gp;
    s32 k;
    if ((void *)self->model == NULL) {
        return;
    }
    ratio = 0x1000 - ratio;
    if ((void *)self->title != NULL) {
        k = LO_FX_MUL(ratio, 0x78000) >> 12;
        MODEL_FLAGS(self->model)->unk_17 = 0;
        MODEL_FLAGS(self->model)->unk_18 = 0;
        MODEL_FLAGS(self->model)->alpha = 30;
        {
            Model *m = self->model;
            m->x = (-0x88 - k) << 12;
            m->y = -0x61000;
        }
        self->model->unk_150 = self->posZ - 0x50;
        Model_PlayPart(self->model, 7);
        {
            TextWin *o = self->title;
            h = o->width;
            o->posZ = self->posZ - 0x40;
        }
        self->title->unk_vf20(0x31 - (h >> 1) - k, 1);
        self->title->Render();
    }
    if ((void *)self->caption == NULL) {
        return;
    }
    ratio = LO_FX_MUL(ratio, 0x20000);
    g = gGfxSys;
    k = ratio >> 12;
    gp = g->unk_8b0;
    z = self->posZ - 0x70;
    G3_Cmd1(0x2a, 0x20000000);
    G3_Cmd1(0x29, 0x1408d0 | (Gfx3DState_NextPolyId(gp) << 24));
    NNS_G3dGeBufferOP_N(0x11, NULL, 0);
    G3_Vec(0x1c, 0, -ratio, z);
    G3_Vec(0x1b, 0x100000, 0xe000, 0x1000);
    G3_Cmd1(0x20, ((u16)self->unk_4a));
    NNS_G3dGeSendDL(LFLD(void *, data_0208b3d0, 4), LFLD(u32, data_020828f8, 4));
    G3_Cmd1(0x12, 1);
    x = 0xe4 - (self->scrollPos >> 12);
    h = self->caption->width;
    self->caption->posZ = self->posZ - 0x60;
    if (x < 0x100 && x + h > 0x68) {
        self->caption->unk_vf20(x, 2 - k);
        self->caption->Render();
    }
    x += self->scrollLen;
    if (x < 0x100 && x + h > 0x68) {
        self->caption->unk_vf20(x, 2 - k);
        self->caption->Render();
    }
}

}
