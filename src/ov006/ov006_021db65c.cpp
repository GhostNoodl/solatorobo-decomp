#include "ov006/SlotManager.h"

extern "C" {

static inline void ov006_Slot_Setup(ov006_Slot *self, int unk8, const char *name, u16 unkC) {
    ov006_Slot_Clear(self);
    self->active = 1;
    self->unk8 = unk8;
    MI_CpuCopy8(name, self->name, sizeof(self->name));
    self->unk12 = 0xff;
    self->unkC = unkC;
}

void func_ov006_021db65c(void) {
    ov006_SlotManager *mgr;
    int i;
    data_ov006_021ec884->unk5 = 0;
    ov006_Slot_Setup(&data_ov006_021ec884->slots[0], 1, "PL", 0x7000);
    ov006_Slot_Setup(&data_ov006_021ec884->slots[1], 0, "CPU1", 0x700a);
    ov006_Slot_Setup(&data_ov006_021ec884->slots[2], 0, "CPU2", 0x7009);
    ov006_Slot_Setup(&data_ov006_021ec884->slots[3], 0, "CPU3", 0x7008);
    mgr = data_ov006_021ec884;
    mgr->numActive = 0;
    for (i = 0; i < 4; i++) {
        if (mgr->slots[i].active) {
            mgr->numActive++;
        }
    }
}

}
