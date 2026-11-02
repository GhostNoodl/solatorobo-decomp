#include "ov000/LoCommon.h"
#include "Main/Gfx/GfxMgr.h"
#include "Main/Gfx/Model.h"
#include "ov000/ModelPart.h"


typedef struct {
    u32 b0 : 8;
    u32 alpha : 5;
    u32 bright : 8;
    u32 rest : 11;
} WinAttr0215b054;

class Win0215b054 : public VObj {
public:
    WinAttr0215b054 attr;
    u8 pad08[0x3c];
    s32 width;
    u8 pad48[0x28];
    s32 unk_70;
};

typedef struct {
    u32 b0 : 3;
    u32 b3 : 1;
    u32 rest : 28;
} Flags0215b054;

typedef struct {
    u8 pad[0xc];
    Flags0215b054 flags;
    Model *model;
    Win0215b054 *win;
    u8 pad18[0xc];
    s32 width;
    u8 pad28[0x40];
    s16 z;
    u8 pad6a[0x6a];
    Win0215b054 *win2;
} Obj0215b054;

extern "C" {

u8 Gfx3DState_NextPolyId(void *p);

static inline BOOL IsHidden0215b054(Obj0215b054 *self) {
    return self->flags.b3 ? TRUE : FALSE;
}

void func_ov000_0215b054(Obj0215b054 *self, s32 fade, s32 *pos) {
    GfxSys *g = data_02097d48;
    s32 x = (self->width >> 1) + (pos[0] >> 12);
    s32 y = (pos[1] >> 12) + 4;
    u8 a;
    s32 a5;
    if (self->win == NULL) {
        return;
    }
    a = LO_FX_MUL(fade, 0x1e000) >> 12;
    if (!IsHidden0215b054(self)) {
        self->model->flags |= 0x80000;
        MODEL_FLAGS(self->model)->polygon_id = Gfx3DState_NextPolyId(g->unk_8b0);
        self->model->flags |= 0x200000;
        MODEL_FLAGS(self->model)->alpha = a;
        {
            Model *m = self->model;
            m->x = (x - 0xbc) << 12;
            m->y = (y - 0x6e) << 12;
        }
        self->model->unk_150 = self->z - 0xe0;
        Model_PlayPart(self->model, 7);
    }
    {
        Win0215b054 *w = self->win;
        s32 wh = w->width;
        w->vfunc_14();
        self->win->attr.bright = Gfx3DState_NextPolyId(g->unk_8b0);
        a5 = a & 0x1f;
        self->win->attr.alpha = a5;
        self->win->unk_70 = self->z - 0xc0;
        self->win->vfunc_20(x - (wh >> 1), y - 0xc);
        self->win->vfunc_90();
    }
    if (self->win2 == NULL) {
        return;
    }
    {
        Win0215b054 *w = self->win2;
        s32 wh = w->width;
        w->vfunc_14();
        self->win2->attr.bright = Gfx3DState_NextPolyId(g->unk_8b0);
        self->win2->attr.alpha = a5;
        self->win2->unk_70 = self->z - 0xc0;
        self->win2->vfunc_20(x - (wh >> 1), y + 4);
        self->win2->vfunc_90();
    }
}

}
