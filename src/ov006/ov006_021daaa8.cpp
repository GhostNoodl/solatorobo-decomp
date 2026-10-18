#include "ov006/SlotManager.h"

extern "C" {

void *func_0206efc0(u32 id);

void *func_ov006_021daaa8(u32 id) {
    void *result = NULL;
    if (id >= 0xb000 && id < 0xb00b) {
        result = func_0206efc0(id);
    }
    return result;
}

ov006_Slot *func_ov006_021daad8(ov006_Slot *self) {
    self->vtbl = &data_ov006_021ec078;
    ov006_Slot_Clear(self);
    self->unkC = 0xffff;
    return self;
}

void func_ov006_021dab5c(ov006_Slot *self) {
}

ov006_Slot *func_ov006_021dab60(ov006_Slot *self) {
    func_0203de1c(self);
    return self;
}

void func_ov006_021dab74(ov006_Slot *self, const ov006_SlotSub *src) {
    if (src != NULL) {
        MI_CpuCopy8(src, &self->sub2C, sizeof(ov006_SlotSub));
    }
}

ov006_SlotSub *func_ov006_021dab98(ov006_Slot *self) {
    return &self->sub2C;
}

void func_ov006_021daba0(ov006_Slot *self, const ov006_SlotSub *src) {
    if (src != NULL) {
        MI_CpuCopy8(src, &self->sub3C, sizeof(ov006_SlotSub));
    }
}

ov006_SlotSub *func_ov006_021dabc4(ov006_Slot *self) {
    return &self->sub3C;
}

}
