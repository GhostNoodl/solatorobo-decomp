#include "ov002/ov002.h"

extern "C" {

static inline void *ov002_Model_GetPart(void *self, int idx) {
    if (idx >= FIELD(self, 0x80, s32)) {
        return NULL;
    }
    return (u8 *)FIELD(self, 0x78, void *) + idx * 0x28;
}

static inline void ov002_Model_PlayPart(void *model, int idx) {
    void *res = FIELD(model, 0x28, void *);
    void *part;
    void *anim;
    if (res == NULL) {
        return;
    }
    part = ov002_Model_GetPart(model, idx);
    if (part != NULL && FIELD(part, 0x4, void *) != NULL) {
        anim = FIELD(FIELD(part, 0x4, void *), 0x30, void *);
    } else {
        anim = NNS_G2dGetCellDataByIdx(FIELD(res, 0x4, void *), **(u16 **)FIELD(NNS_G2dGetAnimSequenceByIdx(FIELD(res, 0xc, void *), idx), 0xc, void *));
    }
    func_02042628((Model *)model, anim, (ModelPart *)part, 0);
}

void func_ov002_021cdf58(Task021ef530 *self) {
    if (self->unk_3c != NULL && func_02054f10(self->unk_3c, 0xffff)) {
        self->unk_3c->unk_150 = -0x1fe66;
        ov002_Model_PlayPart(self->unk_3c, 0);
    }
    if (self->fadeRatio == 0) {
        return;
    }
    func_ov000_0217357c(self);
    self->unk_40->vfunc_20();
    self->unk_44->vfunc_20();
}

}
