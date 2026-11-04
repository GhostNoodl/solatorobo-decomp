#include "ov000/ModelPart.h"

#define LO_FX_MUL(a, b) ((s32)(((s64)(a) * (b) + 0x800) >> 12))

extern "C" {

// Model_PlayPart, with the index read through a const view for Model_GetPart: that read is
// not merged with the plain one, which only changes the loop counter's register allocation.
static inline void PlayPart021b86a4(Model *model, u32 idx) {
    ModelRes *res = model->res;
    ModelPart *part;
    void *anim;
    if (res == NULL) {
        return;
    }
    part = Model_GetPart(model, *(const u32 *)&idx);
    if (part != NULL && part->res != NULL) {
        anim = part->res->tex;
    } else {
        anim = NNS_G2dGetCellDataByIdx(res->texRes, ***(u16 ***)((u8 *)NNS_G2dGetAnimSequenceByIdx(res->mdlRes, idx) + 0xc));
    }
    TexObj_DrawCell(model, anim, part, 0);
}

struct Obj021b86a4 {
    u8 unk_00[0x44];
    s32 unk_44;
    u8 unk_48[0x4];
    Model *unk_4c;
    u8 unk_50[0x4];
    s32 unk_54;
    u16 unk_58;
};

void ImageCard_Draw(Obj021b86a4 *self) {
    s32 st = self->unk_44;
    u16 i;
    s32 y;
    if (st != 7 && st != 0xb && st != 0xd) {
        return;
    }
    y = LO_FX_MUL(0x1000 - self->unk_54, -0x100000LL);
    MODEL_FLAGS(self->unk_4c)->unk_19 = 1;
    self->unk_4c->unk_150 = -0xccd;
    MODEL_FLAGS(self->unk_4c)->alpha = 0x1f;
    Model_SetPos(self->unk_4c, 0, y);
    for (i = 0; i < self->unk_58; i++) {
        PlayPart021b86a4(self->unk_4c, i);
    }
}

}
