#include "ov006/Marker.h"

typedef void *(*ov006_SeqFn16)(void *res, u16 idx);

static inline ModelPart *ov006_Model_GetPart16(Model *self, u16 idx) {
    if (idx >= self->numParts) {
        return NULL;
    }
    return &self->parts[idx];
}

static inline void ov006_Model_PlayPart16(Model *model, u16 idx) {
    ModelRes *res = model->res;
    ModelPart *part;
    void *anim;
    if (res == NULL) {
        return;
    }
    part = ov006_Model_GetPart16(model, idx);
    if (part != NULL && part->res != NULL) {
        anim = part->res->tex;
    } else {
        anim = NNS_G2dGetCellDataByIdx(res->texRes, **((ov006_Unk02023390 *)((ov006_SeqFn16)NNS_G2dGetAnimSequenceByIdx)(model->res->mdlRes, idx))->unkC);
    }
    func_02042628(model, anim, part, 0);
}

extern "C" {

void func_ov006_021e2490(ov006_MarkerSet *self) {
    int i;
    u32 x;
    u32 y;
    if (!self->unk4) {
        return;
    }
    x = self->unk8;
    y = self->unkC;
    for (i = 0; i < 4; i++) {
        ov006_Model_SetPos(self->model, 2, x << 12, (y + i * 32) << 12);
        ov006_Model_PlayPart16(self->model, i + 0x10);
    }
    for (i = 0; i < 4; i++) {
        ov006_Marker *m = &self->markers[i];
        if (m->unkA) {
            m->unk10 = x + 0x1c;
            m->unk14 = y;
            ov006_Model_SetPos(self->model, 2, ((x + 0x1c) + (m->pos.x >> 12)) << 12, (y + (m->pos.y >> 12)) << 12);
            ov006_Model_PlayPart16(self->model, i + 0x14);
        }
    }
}

}
