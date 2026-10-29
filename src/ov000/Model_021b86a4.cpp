#include "ov000/ModelPart.h"

#define LFLD(type, obj, off) (*(type *)((u8 *)(obj) + (off)))
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
    func_02042628(model, anim, part, 0);
}

void func_ov000_021b86a4(u8 *self) {
    s32 st = LFLD(s32, self, 0x44);
    u16 i;
    s32 y;
    if (st != 7 && st != 0xb && st != 0xd) {
        return;
    }
    y = LO_FX_MUL(0x1000 - LFLD(s32, self, 0x54), -0x100000LL);
    MODEL_FLAGS(LFLD(Model *, self, 0x4c))->unk_19 = 1;
    LFLD(Model *, self, 0x4c)->unk_150 = -0xccd;
    MODEL_FLAGS(LFLD(Model *, self, 0x4c))->alpha = 0x1f;
    Model_SetPos(LFLD(Model *, self, 0x4c), 0, y);
    for (i = 0; i < LFLD(u16, self, 0x58); i++) {
        PlayPart021b86a4(LFLD(Model *, self, 0x4c), i);
    }
}

}
