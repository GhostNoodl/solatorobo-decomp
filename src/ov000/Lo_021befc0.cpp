#include "ov000/ModelPart.h"
#include "nitro/fx.h"

#define LFLD(type, obj, off) (*(type *)((u8 *)(obj) + (off)))
#define LO_FX_MUL(a, b) ((s32)(((s64)(a) * (b) + 0x800) >> 12))

extern "C" {
extern u8 *data_02097d48;
extern const s16 FX_SinCosTable_[];
u8 func_02043d48(void *p);

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

void func_ov000_021befc0(u8 *self) {
    u8 *g;
    s32 x;
    s32 y;
    s32 id;
    u8 a;
    s32 ang;
    s32 s;
    s32 al;
    if (LFLD(s32, self, 0x68) != 10) {
        return;
    }
    g = data_02097d48;
    x = (LFLD(s32, self, 0x78) >> 12) - 0x80;
    y = (LFLD(s32, self, 0x7c) >> 12) - 0x60;
    LFLD(Model *, self, 0x8c)->unk_150 = LFLD(s32, self, 0x80);
    Model_SetPos(LFLD(Model *, self, 0x8c), x << 12, y << 12);
    LFLD(Model *, self, 0x90)->unk_150 = LFLD(s32, self, 0x80) + 0x20;
    Model_SetPos(LFLD(Model *, self, 0x90), x << 12, y << 12);
    LFLD(Model *, self, 0x94)->unk_150 = LFLD(s32, self, 0x80) + 0x20;
    Model_SetPos(LFLD(Model *, self, 0x94), x << 12, y << 12);
    id = func_02043d48(g + 0x8b0);
    id &= 0x3f;
    a = LO_FX_MUL(LFLD(s32, self, 0x88), 0x1e000) >> 12;
    ang = LO_FX_MUL(LFLD(s32, self, 0x88) - 0x333, 0x1400);
    if (ang < 0) {
        ang = 0;
    }
    al = a & 0x1f;
    s = LO_FX_MUL(FX_SinCosTable_[((ang << 15) >> 16) * 2], 0x666);
    MODEL_FLAGS(LFLD(Model *, self, 0x90))->polygon_id = id;
    MODEL_FLAGS(LFLD(Model *, self, 0x90))->alpha = al;
    Model_PlayPart(LFLD(Model *, self, 0x90), 2);
    MODEL_FLAGS(LFLD(Model *, self, 0x8c))->polygon_id = func_02043d48(g + 0x8b0);
    MODEL_FLAGS(LFLD(Model *, self, 0x8c))->alpha = al;
    MTX_Identity22((MtxFx22 *)((u8 *)LFLD(Model *, self, 0x8c) + 0x114));
    MTX_ScaleApply22((MtxFx22 *)((u8 *)LFLD(Model *, self, 0x8c) + 0x114), (MtxFx22 *)((u8 *)LFLD(Model *, self, 0x8c) + 0x114), s + 0x1000, s + 0x1000);
    Model_PlayPartEx(LFLD(Model *, self, 0x8c), 2, 1);
    MODEL_FLAGS(LFLD(Model *, self, 0x94))->polygon_id = id;
    MODEL_FLAGS(LFLD(Model *, self, 0x94))->alpha = al;
    Model_PlayPartEx(LFLD(Model *, self, 0x94), 7, 1);
}

}
