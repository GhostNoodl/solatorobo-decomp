#include "ov000/ModelPart.h"
#include "Main/Sys/FieldState.h"
#include "ov000/Obj0216c954.h"

#define LO_FX_MUL(a, b) ((s32)(((s64)(a) * (b) + 0x800) >> 12))

extern "C" {
BOOL PauseNode_IsDrawPaused(void *p, s32 a);

void Obj0216c954_Draw(Obj0216c954 *self) {
    Model *m;
    s32 x;
    if (PauseNode_IsDrawPaused(gSceneCmd->pause, 1)) {
        return;
    }
    switch (self->state) {
    case 7:
    case 8:
        x = LO_FX_MUL(self->ratio, 0x80000) & ~0xfff;
        if (self->model != NULL) {
            MODEL_FLAGS(self->model)->unk_19 = 1;
            MODEL_FLAGS(self->model)->unk_21 = 1;
            MODEL_FLAGS(self->model)->alpha = 0x1e;
            Model_SetPos(self->model, x, 0);
            self->model->unk_150 = -0x2000;
            Model_PlayPart(self->model, 6);
            Model_PlayPart(self->model, 8);
            self->model->unk_150 = -0x2000;
            m = self->model;
            Model_PlayPart(m, 13);
            Model_SetPos(self->model, x, self->bounce & ~0xfff);
            Model_PlayPart(self->model, self->part);
            Model_SetPos(self->model, x, 0);
            Model_PlayPart(self->model, 14);
        }
        break;
    }
    if (self->effect != NULL) {
        Obj021c2114_Draw(self->effect);
    }
}

}
