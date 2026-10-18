#include "ov006/SlotManager.h"

extern "C" {

void func_ov006_021dae34(void) {
    OV006_DELETE_OBJECT(data_ov006_021ec884);
}

ov006_SlotManager *func_ov006_021dae90(void) {
    return data_ov006_021ec884;
}

void func_ov006_021daea0(ov006_SlotManager *self) {
    ov006_SlotManager_Reset(self);
}

void func_ov006_021daf60(ov006_SlotManager *self) {
    ov006_SlotManager_ClearState(self);
}

void func_ov006_021daf80(ov006_SlotManager *self) {
    int i;
    self->numActive = 0;
    for (i = 0; i < 4; i++) {
        if (self->slots[i].active) {
            self->numActive++;
        }
    }
}

ov006_Slot *func_ov006_021dafb4(ov006_SlotManager *self, int idx, int type, const char *name, u8 unk12) {
    ov006_Slot *slot = &self->slots[idx];
    ov006_Slot_Clear(slot);
    slot->active = 1;
    slot->unk8 = type;
    func_02016fa0(name, slot->name, sizeof(slot->name));
    slot->unk12 = unk12;
    return slot;
}

ov006_Slot *func_ov006_021db060(ov006_SlotManager *self, u32 idx) {
    if (idx >= 4) {
        return NULL;
    }
    return &self->slots[idx];
}

u8 func_ov006_021db078(ov006_SlotManager *self) {
    u8 count = 0;
    int i;
    for (i = 0; i < 3; i++) {
        if (self->unk14A[i] != 0) {
            count++;
        }
    }
    return count;
}

BOOL func_ov006_021db0a8(ov006_SlotManager *self, u8 value) {
    BOOL found = FALSE;
    int i;
    for (i = 0; i < 3; i++) {
        if (value == self->unk14A[i]) {
            found = TRUE;
            break;
        }
    }
    return found;
}

}
