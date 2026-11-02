#include "ov000/LoCommon.h"
#include "ov000/ObjLayouts.h"
#include "ov000/UiObj.h"
#include "Main/Gfx/Model.h"
#include "ov000/ModelPart.h"


extern "C" {

void func_ov000_021570f0(BOOL alt, s32 x, s32 y, s32 z, s32 unused, const void *oam, const void *img, u32 charBase, u32 plttBase, s32 unused2, const void *ctx);

static inline void LoSetScrPos(void *m, s32 px, s32 y) {
    LFLD(s32, m, 0xfc) = (px - 0x80) << 12;
    LFLD(s32, m, 0x100) = (y - 0x60) << 12;
}

static inline void LoDrawPart(UiList *self, s32 px, s32 y, BOOL flip, u32 f, int idx) {
    if (flip) {
        self->model->flags |= 0x40000;
    } else {
        self->model->flags &= ~0x40000;
    }
    MODEL_FLAGS(self->model)->alpha = f;
    LoSetScrPos(self->model, px, y);
    Model_PlayPart(self->model, idx);
}

void func_ov000_02156d48(UiList *self, s32 unused, s32 *pos) {
    s16 z = self->posZ - 0x80;
    s32 py;
    s32 c8;
    s32 h;
    s32 px;
    s32 y;
    self->model->unk_158 = (void *)func_ov000_021570f0;
    self->model->flags |= 0x80000;
    self->model->flags |= 0x200000;
    MODEL_FLAGS(self->model)->alpha = 0x1e;
    {
        s32 k;
        u8 *o;
        px = pos[0];
        py = pos[1];
        k = self->vfunc_90();
        o = (u8 *)self->model;
        LFLD(s32, o, 0xfc) = px + (k << 12);
        LFLD(s32, o, 0x100) = py;
    }
    self->model->unk_150 = z;
    Model_PlayPart(self->model, 6);
    self->model->unk_158 = NULL;
    if (self->items == NULL) {
        return;
    }
    px = (self->width >> 1) + (pos[0] >> 12) + 4;
    if (self->unk_c2 > 0) {
        y = pos[1];
        c8 = self->unk_c8;
        self->model->flags |= 0x40000;
        y = (y >> 12) - 2 - (c8 >> 12);
        MODEL_FLAGS(self->model)->alpha = (u8)self->unk_c2;
        LoSetScrPos(self->model, px, y);
        Model_PlayPart(self->model, 10);
    }
    if (self->unk_c3 > 0) {
        h = self->height;
        py = pos[1];
        c8 = self->unk_c8;
        self->model->flags &= ~0x40000;
        MODEL_FLAGS(self->model)->alpha = (u8)self->unk_c3;
        LoSetScrPos(self->model, px, h + (py >> 12) - 2 + (c8 >> 12));
        Model_PlayPart(self->model, 10);
    }
    if (self->flags & 0x10000) {
        px = self->width + (pos[0] >> 12) - 0x10;
        LoDrawPart(self, px, pos[1] >> 12, FALSE, 0x1e, 2);
    }
}

}
