#include "ov006/SlotManager.h"

// Same as ov006_Slot_Clear, but the name fill is guarded by its size, which keeps the slot
// address out of a register across the call (see docs/MATCHING.md, round ovmid9).
static inline void ov006_Slot_ClearGuarded(ov006_Slot *self) {
    self->active = 0;
    self->unk8 = 0;
    self->unkE = 0xffff;
    self->unk10 = 0;
    self->unk12 = 0xff;
    {
        u32 n = sizeof(self->name);
        if (n != 0) {
            MI_CpuFill8(self->name, 0, n);
        }
    }
    self->sub2C.unk0 = 0;
    self->sub2C.unk2 = 0;
    self->sub2C.unk3 = 0;
    self->sub2C.unk4 = 0;
    self->sub2C.unk8 = 0;
    self->sub2C.unkC = 0;
    self->sub3C.unk0 = 0;
    self->sub3C.unk2 = 0;
    self->sub3C.unk3 = 0;
    self->sub3C.unk4 = 0;
    self->sub3C.unk8 = 0;
    self->sub3C.unkC = 0;
}

extern "C" {

void func_ov006_021dacb0(void) {
    ov006_SlotManager *p;
    OV006_DELETE_OBJECT(data_ov006_021ec884);
    p = (ov006_SlotManager *)func_0203dd9c(0x150);
    if (p != NULL) {
        u16 j;
        int i;
        p->vtbl = &data_ov006_021ec068;
        __cxa_vec_ctor(p->slots, 4, sizeof(ov006_Slot), (void *)func_ov006_021daad8, (void *)func_ov006_021dab5c);
        p->numActive = 0;
        p->unk5 = 0xff;
        for (j = 0; j < 4; j++) {
            ov006_Slot_ClearGuarded(&p->slots[j]);
        }
        ov006_SlotManager_ClearState(p);
        p->unk149 = 0;
        for (i = 0; i < 3; i++) {
            p->unk14A[i] = 0;
            p->unk14D[i] = 0;
        }
        p->unk6 = 0xffff;
    }
    data_ov006_021ec884 = p;
}

}
