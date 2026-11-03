#include "ov006/SlotManager.h"

extern "C" {

void *func_0206efc0(u32 id);

void *ov006_GetCourseInfo(u32 id) {
    void *result = NULL;
    if (id >= 0xb000 && id < 0xb00b) {
        result = func_0206efc0(id);
    }
    return result;
}

ov006_Slot *Ov006Vt_021ec078_Ctor(ov006_Slot *self) {
    self->vtbl = &data_ov006_021ec078;
    ov006_Slot_Clear(self);
    self->unkC = 0xffff;
    return self;
}

void ov006_Slot_Dtor(ov006_Slot *self) {
}

ov006_Slot *ov006_Slot_DtorDelete(ov006_Slot *self) {
    Heap_Free(self);
    return self;
}

void ov006_Slot_SetSub2C(ov006_Slot *self, const ov006_SlotSub *src) {
    if (src != NULL) {
        MI_CpuCopy8(src, &self->sub2C, sizeof(ov006_SlotSub));
    }
}

ov006_SlotSub *ov006_Slot_GetSub2C(ov006_Slot *self) {
    return &self->sub2C;
}

void ov006_Slot_SetSub3C(ov006_Slot *self, const ov006_SlotSub *src) {
    if (src != NULL) {
        MI_CpuCopy8(src, &self->sub3C, sizeof(ov006_SlotSub));
    }
}

ov006_SlotSub *ov006_Slot_GetSub3C(ov006_Slot *self) {
    return &self->sub3C;
}

}
