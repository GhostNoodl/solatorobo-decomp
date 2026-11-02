#include "ov000/LoCommon.h"
#include "nitro/fx.h"
#include "Main/Gfx/GfxMgr.h"
#include "Main/Gfx/Model.h"
#include "ov000/ModelPart.h"


typedef struct {
    u32 b0 : 8;
    u32 alpha : 5;
    u32 bright : 8;
    u32 rest : 11;
} WinAttr0214fa8c;

class Win0214fa8c : public VObj {
public:
    WinAttr0214fa8c attr;
    u8 pad08[0x3c];
    s32 width;
};

typedef struct {
    u8 pad[0x38];
    s32 scale;
} Src0214fa8c;

typedef struct {
    u8 pad[0x40];
    Model *model;
    Win0214fa8c *win;
    Win0214fa8c *win2;
    u8 pad4c[4];
    Src0214fa8c *src;
} Obj0214fa8c;

extern "C" {

u8 Gfx3DState_NextPolyId(void *p);

void func_ov000_0214fa8c(Obj0214fa8c *self) {
    GfxSys *g;
    s64 scale;
    s32 width;
    s32 alpha;
    if (self->src == NULL || self->model == NULL) {
        return;
    }
    g = data_02097d48;
    scale = self->src->scale;
    self->model->flags |= 0x200000;
    MODEL_FLAGS(self->model)->polygon_id = Gfx3DState_NextPolyId(g->unk_8b0);
    MODEL_FLAGS(self->model)->alpha = (u8)(LO_FX_MUL(scale, 0x17000) >> 12);
    {
        Model *m = self->model;
        m->x = 0;
        m->y = 0x7e000;
    }
    MTX_Identity22_(&self->model->mtx[0]);
    {
        Model *m = self->model;
        MTX_ScaleApply22(&m->mtx[0], &m->mtx[0], 0x1000, (fx32)scale);
    }
    Model_PlayPartF(self->model, 1, 1);
    {
        Win0214fa8c *w = self->win;
        width = w->width;
        LFLD(u32, w, 4) |= 0x200000;
    }
    self->win->attr.bright = Gfx3DState_NextPolyId(g->unk_8b0);
    alpha = (u8)(LO_FX_MUL(scale, 0x1e000) >> 12) & 0x1f;
    self->win->attr.alpha = alpha;
    self->win->vfunc_20(8, 0x81);
    self->win->vfunc_90();
    if (self->win2 == NULL) {
        return;
    }
    {
        Win0214fa8c *w = self->win2;
        s32 x;
        x = width + ((0xf8 - width) >> 1) + 8 - (w->width >> 1);
        LFLD(u32, w, 4) |= 0x200000;
        self->win2->attr.bright = Gfx3DState_NextPolyId(g->unk_8b0);
        self->win2->attr.alpha = alpha;
        self->win2->vfunc_20(x, 0x81);
        self->win2->vfunc_90();
    }
}

}
