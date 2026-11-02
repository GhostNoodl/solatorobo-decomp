#include "ov006/SlotManager.h"
#include "Main/Net/Wh.h"

typedef struct ov006_Save02046a50 {
    u8 unk0[2];
    u8 unk2[0x10];
} ov006_Save02046a50;

extern "C" {

ov006_Save02046a50 *Wh_GetSharedData(void *a, int idx);

static inline ov006_Slot *ov006_SlotManager_GetSlot(ov006_SlotManager *self, u32 idx) {
    if (idx >= 4) {
        return NULL;
    }
    return &self->slots[idx];
}

static inline void ov006_SlotSub_Copy(ov006_SlotSub *dst, const ov006_SlotSub *src) {
    if (src != NULL) {
        MI_CpuCopy8(src, dst, sizeof(ov006_SlotSub));
    }
}

void func_ov006_021db0d8(void) {
    u8 i;
    if (data_ov006_021ec860->unk1C) {
        if (data_ov006_021ec888 == NULL) {
            return;
        }
        if (data_ov006_021ec888->state != 5 && data_ov006_021ec888->state != 6) {
            return;
        }
    }
    for (i = 0; i < 4; i++) {
        ov006_Slot *slot = ov006_SlotManager_GetSlot(data_ov006_021ec884, i);
        if (slot != NULL && slot->active) {
            if (slot->aid != 0xff) {
                ov006_Save02046a50 *p = Wh_GetSharedData(data_02097e40, slot->aid);
                if (p != NULL) {
                    ov006_SlotSub_Copy(&slot->sub2C, (ov006_SlotSub *)p->unk2);
                }
            } else {
                ov006_SlotSub_Copy(&slot->sub2C, &slot->sub3C);
            }
        }
    }
}

}
