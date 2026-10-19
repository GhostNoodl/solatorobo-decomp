#include "ov000/ModelPart.h"
#include "nitro/fx.h"

#define LO_FX_MUL(a, b) ((s32)(((s64)(a) * (b) + 0x800) >> 12))

typedef struct {
    u8 pad[0x50];
    s32 unk_50;
    u8 pad54[0xc];
    s32 unk_60;
    u8 pad64[0x38];
    Model *m0;
    u8 padA0[4];
    u16 unk_a4;
    u8 padA6[2];
    s32 unk_a8;
    s32 unk_ac;
} Obj02169588;

extern "C" {

extern u8 *data_02097d48;
extern const s16 FX_SinCosTable_[];
s32 func_02043d84(void *a);
void func_ov000_02160534(Obj02169588 *self, s32 a, VecFx32 *pos, s32 c, s32 d);

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

void func_ov000_02169588(Obj02169588 *self, s32 a, VecFx32 *pos, s32 c, s32 d) {
    s32 off;
    u8 *g;
    Model *m;
    s32 scl;
    s32 y;
    s64 sin;
    s32 z;
    MtxFx22 mtx;
    s32 r;
    s32 x;
    s64 dd;
    func_ov000_02160534(self, a, pos, c, d);
    g = data_02097d48;
    dd = d;
    if (self->unk_a8 == 0) {
        return;
    }
    r = FX_Div(self->unk_ac, self->unk_60);
    if (r >= 0x1000) {
        r = 0x1000;
    } else if (r < 0) {
        r = 0;
    }
    off = LO_FX_MUL(self->unk_50 << 12, r);
    z = pos->z;
    x = pos->x - 0x80000 + off;
    y = pos->y - 0x60000;
    self->m0->unk_150 = z + 0x40;
    Model_SetPos(self->m0, x, y);
    FX_Div(self->unk_a8, 0xa000);
    sin = FX_SinCosTable_[((a << 14) >> 16) * 2];
    scl = LO_FX_MUL(sin, 0x800);
    MTX_Identity22_((MtxFx22 *)((u8 *)self->m0 + 0x114));
    m = self->m0;
    MTX_Rot22(&mtx, FX_SinCosTable_[(self->unk_a4 >> 4) * 2], FX_SinCosTable_[(self->unk_a4 >> 4) * 2 + 1]);
    MTX_Concat22(&mtx, (MtxFx22 *)((u8 *)m + 0x114), (MtxFx22 *)((u8 *)m + 0x114));
    MTX_ScaleApply22((MtxFx22 *)((u8 *)self->m0 + 0x114), (MtxFx22 *)((u8 *)self->m0 + 0x114), scl, scl);
    MODEL_FLAGS(self->m0)->alpha = (u8)(LO_FX_MUL(LO_FX_MUL(sin, dd), 0x1e000) >> 12);
    MODEL_FLAGS(self->m0)->polygon_id = func_02043d84(g + 0x8b0);
    Model_PlayPartEx(self->m0, 1, 1);
}

}
