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
    func_02042628(model, anim, part, flag);
}

void func_ov000_021c0268(ActorMarker2D *self) {
    GfxSys *g;
    s32 x;
    s32 y;
    u8 id;
    u8 a;
    s32 ang;
    s32 s;
    s32 al;
    if (self->work.state != 10) {
        return;
    }
    g = data_02097d48;
    x = (self->work.x >> 12) - 0x80;
    y = (self->work.y >> 12) - 0x60;
    self->unk_8c->unk_150 = self->work.z;
    Model_SetPos(self->unk_8c, x << 12, y << 12);
    id = Gfx3DState_NextPolyId(g->unk_8b0);
    a = LO_FX_MUL(self->work.alpha, 0x1e000) >> 12;
    ang = LO_FX_MUL(self->work.alpha - 0x333, 0x1400);
    if (ang < 0) {
        ang = 0;
    }
    s = LO_FX_MUL(FX_SinCosTable_[((ang << 15) >> 16) * 2], 0x666);
    MODEL_FLAGS(self->unk_8c)->polygon_id = Gfx3DState_NextPolyId(g->unk_8b0);
    al = a & 0x1f;
    MODEL_FLAGS(self->unk_8c)->alpha = al;
    MTX_Identity22(self->unk_8c->mtx);
    MTX_ScaleApply22(self->unk_8c->mtx, self->unk_8c->mtx, s + 0x1000, s + 0x1000);
    Model_PlayPartEx(self->unk_8c, 3, 1);
    self->unk_8c->unk_150 += 0x20;
    MODEL_FLAGS(self->unk_8c)->polygon_id = id;
    MODEL_FLAGS(self->unk_8c)->alpha = al;
    Model_PlayPartEx(self->unk_8c, 4, 1);
}

}
