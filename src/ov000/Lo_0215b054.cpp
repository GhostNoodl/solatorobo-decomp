#include "ov000/LoCommon.h"

typedef struct {
    u32 b0 : 2;
    u32 scale : 5;
    u32 alpha : 6;
    u32 rest : 19;
} LoAttr0215b054;

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
    u8 *model;
    Win0215b054 *win;
    u8 pad18[0xc];
    s32 width;
    u8 pad28[0x40];
    s16 z;
    u8 pad6a[0x6a];
    Win0215b054 *win2;
} Obj0215b054;

extern "C" {

extern u8 *data_02097d48;
void *NNS_G2dGetCellDataByIdx(void *a, int b);
void *NNS_G2dGetAnimSequenceByIdx(void *a, int b);
void func_02042628(void *a, void *b, void *c, int d);
u8 func_02043d48(void *p);

static inline void *LoModelGetPart(void *self, int idx) {
    if (idx >= LFLD(s32, self, 0x80)) {
        return NULL;
    }
    return (u8 *)LFLD(void *, self, 0x78) + idx * 0x28;
}

static inline void LoModelPlayPart(void *model, int idx) {
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
    func_02042628(model, anim, part, 0);
}

static inline BOOL IsHidden0215b054(Obj0215b054 *self) {
    return self->flags.b3 ? TRUE : FALSE;
}

void func_ov000_0215b054(Obj0215b054 *self, s32 fade, s32 *pos) {
    u8 *g = data_02097d48;
    s32 x = (self->width >> 1) + (pos[0] >> 12);
    s32 y = (pos[1] >> 12) + 4;
    u8 a;
    s32 a5;
    if (self->win == NULL) {
        return;
    }
    a = LO_FX_MUL(fade, 0x1e000) >> 12;
    if (!IsHidden0215b054(self)) {
        LFLD(u32, self->model, 0x6c) |= 0x80000;
        LFLD(LoAttr0215b054, self->model, 0x6c).alpha = func_02043d48(g + 0x8b0);
        LFLD(u32, self->model, 0x6c) |= 0x200000;
        LFLD(LoAttr0215b054, self->model, 0x6c).scale = a;
        {
            u8 *m = self->model;
            LFLD(s32, m, 0xfc) = (x - 0xbc) << 12;
            LFLD(s32, m, 0x100) = (y - 0x6e) << 12;
        }
        LFLD(s32, self->model, 0x150) = self->z - 0xe0;
        LoModelPlayPart(self->model, 7);
    }
    {
        Win0215b054 *w = self->win;
        s32 wh = w->width;
        w->vfunc_14();
        self->win->attr.bright = func_02043d48(g + 0x8b0);
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
        self->win2->attr.bright = func_02043d48(g + 0x8b0);
        self->win2->attr.alpha = a5;
        self->win2->unk_70 = self->z - 0xc0;
        self->win2->vfunc_20(x - (wh >> 1), y + 4);
        self->win2->vfunc_90();
    }
}

}
