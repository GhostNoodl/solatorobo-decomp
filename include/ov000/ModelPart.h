#ifndef OV000_MODELPART_H
#define OV000_MODELPART_H

#include "Main/Gfx/Model.h"

#ifdef __cplusplus
extern "C" {
#endif
void *Heap_Alloc(u32 size);
#ifdef __cplusplus
}
#endif

// Allocates a Model, builds it with func_02041440 (name NAME) and copies the archive name ARC.
#define MODEL_NEW(out, NAME, ARC)                       \
    do {                                                \
        Model *m_ = (Model *)Heap_Alloc(sizeof(Model)); \
        if (m_) {                                       \
            const char *arc_;                           \
            const char *name_;                          \
            name_ = NAME;                               \
            arc_ = ARC;                                 \
            func_02041218(&m_->pltt);                   \
            func_02041440(m_, name_, 0);                \
            STD_CopyString(m_->name, arc_);             \
        }                                               \
        out = m_;                                       \
    } while (0)

#ifdef __cplusplus
// The same as MODEL_NEW, written as a new-expression (operator new on the main heap, then the constructor).
struct ModelObj : Model {
    static void *operator new(unsigned long size) { return Heap_Alloc(size); }
    ModelObj(const char *nm, const char *arc) {
        func_02041218(&pltt);
        func_02041440(this, nm, 0);
        STD_CopyString(name, arc);
    }
};
#endif

// Bit layout of Model.flags as used by the overlay 0 HUD models.
typedef struct {
    u32 unk_0 : 2;
    u32 alpha : 5;
    u32 polygon_id : 6;
    u32 unk_13 : 4;
    u32 unk_17 : 1;
    u32 unk_18 : 1;
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

// Model_PlayPart with the last argument of func_02042628 given.
static inline void Model_PlayPartF(Model *model, s32 idx, s32 f) {
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
    func_02042628(model, anim, part, f);
}

#endif
