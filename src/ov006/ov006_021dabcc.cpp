#include "ov006/SlotManager.h"

extern "C" {

void func_ov006_021dabcc(const ov006_Slot *self, ov006_SlotPacked *dst) {
    dst->active = self->active;
    dst->isType1 = (self->unk8 == 1);
    dst->unkC = (self->unkC & 0xf);
    dst->unk10 = self->unk10;
    STD_CopyLString(dst->name, self->name, sizeof(dst->name));
}

}
