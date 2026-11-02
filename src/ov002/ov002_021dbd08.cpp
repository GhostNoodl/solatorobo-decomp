#include "ov002/ov002.h"

extern "C" {

void func_ov002_021dbd08(Obj021eff50 *self, VObj *a, s32 b) {
    self->unk_10 = a;
    self->unk_0c = b;
}

Obj021eff10 *Ov002Vt_021eff10_Ctor(Obj021eff10 *self) {
    *(VFunc **)self = data_ov002_021eff10;
    self->owner = NULL;
    self->unk_08 = NULL;
    self->unk_0c = NULL;
    self->unk_10 = NULL;
    self->unk_14 = NULL;
    self->unk_18 = 0;
    self->unk_1c = -1;
    self->unk_20 = 0;
    self->unk_24 = 0;
    self->unk_28 = 0;
    self->unk_2c = NULL;
    self->unk_30 = NULL;
    FIELD(self, 0x34, u8) = 0;
    return self;
}

void func_ov002_021dbd60(Obj021eff50 *self) {
    if (self->unk_20 != NULL) {
        self->unk_20->vfunc_20();
    }
    if (self->unk_24 != NULL) {
        self->unk_24->vfunc_20();
    }
    if (self->unk_18 != NULL) {
        self->unk_18->vfunc_14(self);
    }
}

}
