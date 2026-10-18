#include "ov006/SlotManager.h"

extern "C" {

void func_ov006_021e4b18(ov006_Unk021ec888 *self, int idx, u16 a, int b, const void *src, u32 size);

static inline ov006_Slot *ov006_SlotManager_GetSlot(ov006_SlotManager *self, u32 idx) {
    if (idx >= 4) {
        return NULL;
    }
    return &self->slots[idx];
}

void func_ov006_021db1b8(u16 a) {
    u8 i;
    if (!data_ov006_021ec860->unk1C) {
        return;
    }
    for (i = 0; i < 4; i++) {
        ov006_Slot *slot = ov006_SlotManager_GetSlot(data_ov006_021ec884, i);
        if (slot != NULL && slot->unk12 != 0xff) {
            func_ov006_021e4b18(data_ov006_021ec888, slot->unk12, a, 3, &slot->sub3C, 0x10);
        }
    }
}

}
