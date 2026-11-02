#include "ov000/ModelPart.h"
#include "ov000/ObjLayouts.h"
#include "ov000/ObjLayouts.h"
#include "ov000/UiObj.h"


typedef struct {
    s32 x;
    s32 y;
} Pos021c524c;

typedef struct {
    u32 unk_0 : 2;
    u32 alpha : 5;
    u32 polygon_id : 6;
    u32 unk_13 : 5;
    u32 unk_18 : 1;
    u32 unk_19 : 1;
    u32 unk_20 : 1;
    u32 unk_21 : 1;
    u32 unk_22 : 10;
} Flags021c524c;

#define FLAGSX(m) ((Flags021c524c *)&(m)->flags)

extern "C" {

static inline s32 PosX021c524c(Pos021c524c *p) {
    return p->x;
}

void func_ov000_021c524c(UnitBase021ccb54_021ccbe0 *self, s32 unused, Pos021c524c *pos, s32 arg) {
    s32 x = (PosX021c524c(pos) >> 12) + ((self->width << 12) - self->unk_b8 >> 12) + 6;
    s32 y = pos->y >> 12;
    Model *m;
    self->model->flags &= ~0x40000;
    self->model->flags = (self->model->flags & ~0x7c) | (0x1e << 2);
    m = self->model;
    Model_SetPos(m, (x - 0x80) << 12, (y - 0x60) << 12);
    Model_PlayPart(self->model, 2);
}

static inline void SetOfs(Model *m, s32 x, s32 y) {
    Model_SetPos(m, (x - 0x80) << 12, (y - 0x60) << 12);
}

static inline s32 GetD0(LoBase021ccb54_021ccbe0 *self) {
    return self->unk_d0;
}

void func_ov000_021c5324(LoBase021ccb54_021ccbe0 *self, s32 unused, s32 *pos) {
    Model *m;
    s32 x = (self->width >> 1) + (pos[0] >> 12) + 4;
    if (self->unk_cc > 0) {
        s32 y = (pos[1] >> 12) - 2 - (self->unk_d0 >> 12);
        FLAGSX(self->model)->unk_18 = 1;
        FLAGSX(self->model)->alpha = (u8)self->unk_cc;
        SetOfs(self->model, x, y);
        m = self->model;
        Model_PlayPart(m, 4);
    }
    if (self->unk_cd > 0) {
        s32 y = self->height + (pos[1] >> 12) + 2 + (GetD0(self) >> 12);
        FLAGSX(self->model)->unk_18 = 0;
        FLAGSX(self->model)->alpha = (u8)self->unk_cd;
        SetOfs(self->model, x, y);
        Model_PlayPart(self->model, 4);
    }
}

}
