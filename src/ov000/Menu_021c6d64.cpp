#include "ov000/ModelPart.h"
#include "nitro/fx.h"
#include "ov000/TextList.h"

extern "C" {
extern const s16 FX_SinCosTable_[];
void func_ov000_021c8408(void *self, int x, int y, int z, u16 color, const void *oam, const void *tex, u32 texBase, u32 plttBase, const void *mtx, u32 arg);

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

void TextList_DrawBody(TextList *self, void *unused, VecFx32 *pos, s32 arg) {
    s32 z = pos->z + 0x20;
    if (self->count > 1 && (self->listFlags.wrap || self->index > 0)) {
        MtxFx22 m;
        Model *mdl;
        s32 x = (pos->x >> 12) - self->rowWidth / 2 - self->bounce;
        s32 y;
        x -= self->lift * 6;
        y = pos->y >> 12;
        Model_SetPos(self->model, x << 12, y << 12);
        self->model->unk_150 = z;
        MTX_Identity22(self->model->mtx);
        mdl = self->model;
        MTX_Rot22(&m, FX_SinCosTable_[0x7fe], FX_SinCosTable_[0x7ff]);
        MTX_Concat22(&m, mdl->mtx, mdl->mtx);
        self->model->unk_158 = (void *)func_ov000_021c8408;
        Model_PlayPartEx(self->model, 4, 1);
        self->model->unk_158 = NULL;
    }
    if (self->count > 1 && (self->listFlags.wrap || self->index < self->count - 1)) {
        MtxFx22 m;
        Model *mdl;
        s32 cx = pos->x >> 12;
        s32 x;
        s32 y;
        cx += self->rowWidth / 2;
        x = cx + self->bounce;
        x += self->lift * 6;
        y = pos->y >> 12;
        Model_SetPos(self->model, x << 12, y << 12);
        self->model->unk_150 = z;
        MTX_Identity22(self->model->mtx);
        mdl = self->model;
        MTX_Rot22(&m, FX_SinCosTable_[0x17fe], FX_SinCosTable_[0x17ff]);
        MTX_Concat22(&m, mdl->mtx, mdl->mtx);
        self->model->unk_158 = (void *)func_ov000_021c8408;
        Model_PlayPartEx(self->model, 4, 1);
        self->model->unk_158 = NULL;
    }
}
}
