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

void func_ov002_021d65e0(Task021efc24 *self) {
    if (!self->vfunc_28()) {
        return;
    }
    ov002_Model_PlayPart(self->unk_3c, 0);
    self->unk_4c->vfunc_20();
    self->unk_50->vfunc_20();
    self->unk_54->vfunc_20();
    func_ov000_02162a58(self->unk_58);
    if (self->unk_5c != NULL) {
        func_ov000_02163594(self->unk_5c);
    }
}

}
