#pragma pool_strings on
#pragma dont_reuse_strings off
#include "ov006/SlotManager.h"

extern "C" {

static inline void ov006_Slot_Setup(ov006_Slot *self, int unk8, const char *name, u16 unkC) {
    ov006_Slot_Clear(self);
    self->active = 1;
    self->type = unk8;
    MI_CpuCopy8(name, self->name, sizeof(self->name));
    self->aid = 0xff;
    self->unkC = unkC;
}

void ov006_SetupDefaultSlots(void) {
    ov006_SlotManager *mgr;
    int i;
    gOv006SlotManager->unk5 = 0;
    ov006_Slot_Setup(&gOv006SlotManager->slots[0], 1, "PL", 0x7000);
    ov006_Slot_Setup(&gOv006SlotManager->slots[1], 0, "CPU1", 0x700a);
    ov006_Slot_Setup(&gOv006SlotManager->slots[2], 0, "CPU2", 0x7009);
    ov006_Slot_Setup(&gOv006SlotManager->slots[3], 0, "CPU3", 0x7008);
    mgr = gOv006SlotManager;
    mgr->numActive = 0;
    for (i = 0; i < 4; i++) {
        if (mgr->slots[i].active) {
            mgr->numActive++;
        }
    }
}

}
