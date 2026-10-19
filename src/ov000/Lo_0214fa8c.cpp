#include "ov000/LoCommon.h"
#include "nitro/fx.h"

typedef struct {
    u32 b0 : 2;
    u32 scale : 5;
    u32 alpha : 6;
    u32 rest : 19;
} LoAttr0214fa8c;

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
    u8 *model;
    Win0214fa8c *win;
    Win0214fa8c *win2;
    u8 pad4c[4];
    Src0214fa8c *src;
} Obj0214fa8c;

extern "C" {

extern u8 *data_02097d48;
void *NNS_G2dGetCellDataByIdx(void *a, int b);
void *NNS_G2dGetAnimSequenceByIdx(void *a, int b);
void func_02042628(void *a, void *b, void *c, int d);
s32 func_02043d48(void *p);

static inline void *LoModelGetPart(void *self, int idx) {
    if (idx >= LFLD(s32, self, 0x80)) {
        return NULL;
    }
    return (u8 *)LFLD(void *, self, 0x78) + idx * 0x28;
}

static inline void LoModelPlayPartD(void *model, int idx, int d) {
    void *res = LFLD(void *, model, 0x28);
    void *part;
    void *anim;
    if (res == NULL) {
        return;
    }
    part = LoModelGetPart(model, idx);
    if (part != NULL && LFLD(void *, part, 0x4) != NULL) {
        anim = LFLD(void *, LFLD(void *, part, 0x4), 0x30);
    } else {
        anim = NNS_G2dGetCellDataByIdx(LFLD(void *, res, 0x4), **(u16 **)LFLD(void *, NNS_G2dGetAnimSequenceByIdx(LFLD(void *, res, 0xc), idx), 0xc));
    }
    func_02042628(model, anim, part, d);
}

void func_ov000_0214fa8c(Obj0214fa8c *self) {
    u8 *g;
    s64 scale;
    s32 width;
    s32 alpha;
    if (self->src == NULL || self->model == NULL) {
        return;
    }
    g = data_02097d48;
    scale = self->src->scale;
    LFLD(u32, self->model, 0x6c) |= 0x200000;
    LFLD(LoAttr0214fa8c, self->model, 0x6c).alpha = func_02043d48(g + 0x8b0);
    LFLD(LoAttr0214fa8c, self->model, 0x6c).scale = (u8)(LO_FX_MUL(scale, 0x17000) >> 12);
    {
        u8 *m = self->model;
        LFLD(s32, m, 0xfc) = 0;
        LFLD(s32, m, 0x100) = 0x7e000;
    }
    MTX_Identity22_((MtxFx22 *)(self->model + 0x114));
    {
        u8 *m = self->model;
        MTX_ScaleApply22((MtxFx22 *)(m + 0x114), (MtxFx22 *)(m + 0x114), 0x1000, (fx32)scale);
    }
    LoModelPlayPartD(self->model, 1, 1);
    {
        Win0214fa8c *w = self->win;
        width = w->width;
        LFLD(u32, w, 4) |= 0x200000;
    }
    self->win->attr.bright = func_02043d48(g + 0x8b0);
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
        self->win2->attr.bright = func_02043d48(g + 0x8b0);
        self->win2->attr.alpha = alpha;
        self->win2->vfunc_20(x, 0x81);
        self->win2->vfunc_90();
    }
}

}
