#include "ov000/ModelPart.h"
#include "nitro/fx.h"
#include "ov000/ObjLayouts.h"
#include "ov000/ActorMarker.h"
#include "Main/Gfx/GfxMgr.h"

#define LO_FX_MUL(a, b) ((s32)(((s64)(a) * (b) + 0x800) >> 12))

extern "C" {
extern const s16 FX_SinCosTable_[];
u8 Gfx3DState_NextPolyId(void *p);

static inline void Model_PlayPartEx(Model *model, s32 idx, s32 flag) {
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
    TexObj_DrawCell(model, anim, part, flag);
}

void ActorMarker_DrawKind06(ActorMarker2D *self) {
    GfxSys *g;
    s32 x;
    s32 y;
    s32 id;
    u8 a;
    s32 ang;
    s32 s;
    s32 al;
    if (self->work.state != 10) {
        return;
    }
    g = gGfxSys;
    x = (self->work.x >> 12) - 0x80;
    y = (self->work.y >> 12) - 0x60;
    self->unk_8c->unk_150 = self->work.z;
    Model_SetPos(self->unk_8c, x << 12, y << 12);
    self->unk_90->unk_150 = self->work.z + 0x20;
    Model_SetPos(self->unk_90, x << 12, y << 12);
    self->unk_94->unk_150 = self->work.z + 0x20;
    Model_SetPos(self->unk_94, x << 12, y << 12);
    id = Gfx3DState_NextPolyId(g->unk_8b0);
    id &= 0x3f;
    a = LO_FX_MUL(self->work.alpha, 0x1e000) >> 12;
    ang = LO_FX_MUL(self->work.alpha - 0x333, 0x1400);
    if (ang < 0) {
        ang = 0;
    }
    al = a & 0x1f;
    s = LO_FX_MUL(FX_SinCosTable_[((ang << 15) >> 16) * 2], 0x666);
    MODEL_FLAGS(self->unk_90)->polygon_id = id;
    MODEL_FLAGS(self->unk_90)->alpha = al;
    Model_PlayPart(self->unk_90, 2);
    MODEL_FLAGS(self->unk_8c)->polygon_id = Gfx3DState_NextPolyId(g->unk_8b0);
    MODEL_FLAGS(self->unk_8c)->alpha = al;
    MTX_Identity22(self->unk_8c->mtx);
    MTX_ScaleApply22(self->unk_8c->mtx, self->unk_8c->mtx, s + 0x1000, s + 0x1000);
    Model_PlayPartEx(self->unk_8c, 2, 1);
    MODEL_FLAGS(self->unk_94)->polygon_id = id;
    MODEL_FLAGS(self->unk_94)->alpha = al;
    Model_PlayPartEx(self->unk_94, 6, 0);
}

}
