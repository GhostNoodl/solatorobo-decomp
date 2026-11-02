// Built at a lower optimization level than the rest of the overlay.
#pragma optimization_level 2
#include "ov006/Model.h"
#include "Main/Gfx/GfxMgr.h"

typedef struct ov006_Lbl021dc578 {
    u8 unk0[0xa8];
    Model *unkA8;
    u16 unkAC;
    int unkB0;
    int unkB4;
    int unkB8;
    int unkBC;
    u8 unkC0[0x1c];
    int unkDC;
    int unkE0;
} ov006_Lbl021dc578;

extern "C" {

BOOL func_02054f10(void *a, int b);
u8 Gfx3DState_NextPolyId(void *a);

static inline void ov006_Model_SetPolyId(Model *m, int id) {
    MODEL_FLAGS(m)->polygon_id = id;
}

static inline void ov006_Model_SetAlpha(Model *m, u8 a) {
    MODEL_FLAGS(m)->alpha = a;
}

void func_ov006_021dc578(ov006_Lbl021dc578 *self) {
    int alpha;
    int x;
    int y;
    if (self->unkA8 == NULL) {
        return;
    }
    if (!func_02054f10(self->unkA8, 0xffff)) {
        return;
    }
    alpha = (u8)self->unkDC;
    x = (self->unkBC + (self->unkB0 - 0x80000)) & ~0xfff;
    y = (self->unkB4 - 0x60000) & ~0xfff;
    if (alpha <= 0) {
        return;
    }
    ov006_Model_SetPolyId(self->unkA8, Gfx3DState_NextPolyId(data_02097d48->unk_8b0));
    ov006_Model_SetAlpha(self->unkA8, alpha);
    { int i = self->unkE0; Model *m = self->unkA8; m->pos[i].x = x; m->pos[i].y = y; }
    self->unkA8->unk_150 = self->unkB8;
    Model_PlayPart(self->unkA8, self->unkAC);
}

}
