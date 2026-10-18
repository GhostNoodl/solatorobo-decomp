#include "ov002/ov002.h"

extern "C" {

void func_ov002_021d35d4(Task50 *self) {
    void *model;
    void *res;
    void *anim;
    void *arg;
    void *t;
    if (self->unk_24 == 0 || self->unk_08 == 0) {
        return;
    }
    if (self->unk_08 != 0xc && self->unk_08 != 0xd) {
        return;
    }
    if (self->unk_3c != NULL) {
        ((VObject *)self->unk_3c)->v0x20();
    }
    if (self->unk_40 != NULL) {
        self->unk_40->v0x20();
    }
    if (FIELD(self, 0xc4, void *) == NULL) {
        return;
    }
    if (func_02054f10(FIELD(self, 0xc4, void *), 0xffff) == 0) {
        return;
    }
    model = FIELD(self, 0xc4, void *);
    if ((res = FIELD(model, 0x28, void *)) == NULL) {
        return;
    }
    anim = NULL;
    if (FIELD(model, 0x80, s32) > 0) {
        anim = FIELD(model, 0x78, void *);
    }
    if (anim != NULL && (t = FIELD(anim, 0x4, void *)) != NULL) {
        arg = FIELD(t, 0x30, void *);
    } else {
        void *e = NNS_G2dGetAnimSequenceByIdx(FIELD(res, 0xc, void *), 0);
        arg = NNS_G2dGetCellDataByIdx(FIELD(res, 0x4, void *), **(u16 **)FIELD(e, 0xc, void *));
    }
    func_02042628(model, arg, anim, 0);
}

}
