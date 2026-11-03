#include "ov006/SlotManager.h"

extern "C" {

void ov006_DeleteSlotManager(void) {
    OV006_DELETE_OBJECT(gOv006SlotManager);
}

ov006_SlotManager *ov006_GetSlotManager(void) {
    return gOv006SlotManager;
}

void ov006_SlotManager_Reset_021daea0(ov006_SlotManager *self) {
    ov006_SlotManager_Reset(self);
}

void ov006_SlotManager_ClearState_021daf60(ov006_SlotManager *self) {
    ov006_SlotManager_ClearState(self);
}

void ov006_SlotManager_CountActive(ov006_SlotManager *self) {
    int i;
    self->numActive = 0;
    for (i = 0; i < 4; i++) {
        if (self->slots[i].active) {
            self->numActive++;
        }
    }
}

ov006_Slot *ov006_SlotManager_InitSlot(ov006_SlotManager *self, int idx, int type, const char *name, u8 unk12) {
    ov006_Slot *slot = &self->slots[idx];
    ov006_Slot_Clear(slot);
    slot->active = 1;
    slot->type = type;
    MI_CpuCopy8(name, slot->name, sizeof(slot->name));
    slot->aid = unk12;
    return slot;
}

ov006_Slot *ov006_SlotManager_GetSlot_021db060(ov006_SlotManager *self, u32 idx) {
    if (idx >= 4) {
        return NULL;
    }
    return &self->slots[idx];
}

u8 ov006_SlotManager_CountItems(ov006_SlotManager *self) {
    u8 count = 0;
    int i;
    for (i = 0; i < 3; i++) {
        if (self->items[i] != 0) {
            count++;
        }
    }
    return count;
}

BOOL ov006_SlotManager_HasItem(ov006_SlotManager *self, u8 value) {
    BOOL found = FALSE;
    int i;
    for (i = 0; i < 3; i++) {
        if (value == self->items[i]) {
            found = TRUE;
            break;
        }
    }
    return found;
}

}
