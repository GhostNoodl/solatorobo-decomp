// Built at a lower optimization level than the rest of the overlay.
#pragma optimization_level 2
#include "ov006/Label.h"
#include "Main/Gfx/GfxMgr.h"

extern "C" {

BOOL func_02054f10(void *a, int b);
u8 Gfx3DState_NextPolyId(void *a);

static inline void ov006_Model_SetPolyId(Model *m, int id) {
    MODEL_FLAGS(m)->polygon_id = id;
}

static inline void ov006_Model_SetAlpha(Model *m, u8 a) {
    MODEL_FLAGS(m)->alpha = a;
}

void func_ov006_021dc578(ov006_Label *self) {
    int alpha;
    int x;
    int y;
    if (self->model == NULL) {
        return;
    }
    if (!func_02054f10(self->model, 0xffff)) {
        return;
    }
    alpha = (u8)self->alpha;
    x = (self->pos.x + (self->origin.x - 0x80000)) & ~0xfff;
    y = (self->origin.y - 0x60000) & ~0xfff;
    if (alpha <= 0) {
        return;
    }
    ov006_Model_SetPolyId(self->model, Gfx3DState_NextPolyId(data_02097d48->unk_8b0));
    ov006_Model_SetAlpha(self->model, alpha);
    { int i = self->unkE0; Model *m = self->model; m->pos[i].x = x; m->pos[i].y = y; }
    self->model->unk_150 = self->origin.z;
    Model_PlayPart(self->model, self->part);
}

}
