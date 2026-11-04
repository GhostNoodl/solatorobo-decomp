#include "ov002/ov002.h"

extern "C" {

void func_ov002_021dfc44(Obj021efef0 *self, u16 v) {
    self->unk_18 = v;
}

void Obj021eff30_Exit(Obj021eff30 *self, Obj021eff50 *dst) {
    dst->unk_28 = self->unk_1c;
    dst->unk_2c = self->unk_20;
    Obj021eff30_Release(self);
}

void Obj021eff30_Draw(Obj021eff30 *self, Obj021eff50 *arg) {
    self->owner = arg;
    if (self->unk_10 != NULL) {
        self->unk_10->vfunc_10();
    }
    func_ov002_021e0280(self);
    self->unk_0c->unk_1d4 = self->unk_18 == 0xa;
    Obj021efe5c_Draw(self->unk_0c);
    self->owner = NULL;
}

}
