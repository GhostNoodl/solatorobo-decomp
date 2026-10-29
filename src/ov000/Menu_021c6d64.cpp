#include "ov000/ModelPart.h"
#include "nitro/fx.h"

#define LFLD(type, obj, off) (*(type *)((u8 *)(obj) + (off)))

typedef struct {
    u32 b0 : 1;
    u32 rest : 31;
} Bits021c6d64;

typedef struct {
    u8 pad_00[0x10];
    Model *model;
    u8 pad_14[0x7c];
    s32 count;
    s32 cur;
    u8 pad_98[0x18];
    s32 unk_b0;
    s32 unk_b4;
    u8 pad_b8[8];
    s32 unk_c0;
    Bits021c6d64 unk_c4;
} Obj021c6d64;

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
    func_02042628(model, anim, part, flag);
}

void func_ov000_021c6d64(Obj021c6d64 *self, void *unused, VecFx32 *pos, s32 arg) {
    s32 z = pos->z + 0x20;
    if (self->count > 1 && (self->unk_c4.b0 || self->cur > 0)) {
        MtxFx22 m;
        Model *mdl;
        s32 x = (pos->x >> 12) - self->unk_b4 / 2 - self->unk_b0;
        s32 y;
        x -= self->unk_c0 * 6;
        y = pos->y >> 12;
        Model_SetPos(self->model, x << 12, y << 12);
        self->model->unk_150 = z;
        MTX_Identity22((MtxFx22 *)((u8 *)self->model + 0x114));
        mdl = self->model;
        MTX_Rot22(&m, FX_SinCosTable_[0x7fe], FX_SinCosTable_[0x7ff]);
        MTX_Concat22(&m, (MtxFx22 *)((u8 *)mdl + 0x114), (MtxFx22 *)((u8 *)mdl + 0x114));
        LFLD(void *, self->model, 0x158) = (void *)func_ov000_021c8408;
        Model_PlayPartEx(self->model, 4, 1);
        LFLD(void *, self->model, 0x158) = NULL;
    }
    if (self->count > 1 && (self->unk_c4.b0 || self->cur < self->count - 1)) {
        MtxFx22 m;
        Model *mdl;
        s32 cx = pos->x >> 12;
        s32 x;
        s32 y;
        cx += self->unk_b4 / 2;
        x = cx + self->unk_b0;
        x += self->unk_c0 * 6;
        y = pos->y >> 12;
        Model_SetPos(self->model, x << 12, y << 12);
        self->model->unk_150 = z;
        MTX_Identity22((MtxFx22 *)((u8 *)self->model + 0x114));
        mdl = self->model;
        MTX_Rot22(&m, FX_SinCosTable_[0x17fe], FX_SinCosTable_[0x17ff]);
        MTX_Concat22(&m, (MtxFx22 *)((u8 *)mdl + 0x114), (MtxFx22 *)((u8 *)mdl + 0x114));
        LFLD(void *, self->model, 0x158) = (void *)func_ov000_021c8408;
        Model_PlayPartEx(self->model, 4, 1);
        LFLD(void *, self->model, 0x158) = NULL;
    }
}
}
