#ifndef OV000_MODELPART_H
#define OV000_MODELPART_H

#include "Main/Gfx/Model.h"

// Bit layout of Model.flags as used by the overlay 0 HUD models.
typedef struct {
    u32 unk_0 : 2;
    u32 alpha : 5;
    u32 polygon_id : 6;
    u32 unk_13 : 6;
    u32 unk_19 : 1;
    u32 unk_20 : 1;
    u32 unk_21 : 1;
    u32 unk_22 : 10;
} ModelFlags;

#define MODEL_FLAGS(m) ((ModelFlags *)&(m)->flags)

static inline ModelPart *Model_GetPart(Model *model, s32 idx) {
    if (idx >= model->numParts) {
        return NULL;
    }
    return &model->parts[idx];
}

// Applies the animation of part idx, falling back to the texture named by the model resource.
static inline void Model_PlayPart(Model *model, s32 idx) {
    ModelRes *res = model->res;
    ModelPart *part;
    void *anim;
    if (res == NULL) {
        return;
    }
    part = Model_GetPart(model, idx);
    if (part != NULL && part->res != NULL) {
        anim = part->res->tex;
    } else {
        anim = NNS_G2dGetCellDataByIdx(res->texRes, ***(u16 ***)((u8 *)NNS_G2dGetAnimSequenceByIdx(res->mdlRes, idx) + 0xc));
    }
    func_02042628(model, anim, part, 0);
}

static inline void Model_SetPos(Model *model, s32 x, s32 y) {
    model->x = x;
    model->y = y;
}

#endif
