#include "ov006/SlotManager.h"

typedef struct ov006_NetSlot {
    u16 unk0_0 : 4;
    u16 kind : 4;
    u16 unk0_8 : 8;
    ov006_SlotPacked packed;
} ov006_NetSlot;

typedef struct ov006_WhState {
    u8 unk0[0x2c];
    int state;
} ov006_WhState;

extern "C" {

extern ov006_WhState *data_02097e40;
ov006_NetSlot *func_02046a50(ov006_WhState *a, int idx);
u16 func_02046ab4(ov006_WhState *a);

static inline void ov006_Slot_Unpack(ov006_Slot *self, const ov006_SlotPacked *src) {
    self->active = src->active ? 1 : 0;
    self->unk8 = src->isType1 ? 1 : 0;
    self->unkC = src->unkC | 0x7000;
    self->unk10 = src->unk10;
    STD_CopyLString(self->name, src->name, sizeof(self->name));
}

void func_ov006_021db258(void) {
    u16 j;
    ov006_SlotManager *mgr;
    ov006_NetSlot *p;
    u8 n;
    ov006_NetSlot *p2;
    ov006_Slot *slot;
    ov006_Slot *slot2;
    int k;
    u8 i2;
    u8 i;
    if (!data_ov006_021ec860->unk1C || data_ov006_021ec888 == NULL) {
        return;
    }
    if (data_02097e40->state != 5) {
        return;
    }
    // Writing unk12 through a reference to `slot` gives the target's
    // register assignment for `i` and `slot` in the first loop (permuter).
    ov006_Slot *&slotRef = slot;
    mgr = data_ov006_021ec884;
    mgr->numActive = 0;
    mgr->unk5 = 0xff;
    for (j = 0; j < 4; j++) {
        ov006_Slot_Clear(&mgr->slots[j]);
    }
    n = 0;
    for (i = 0; i < 4; i++) {
        p = func_02046a50(data_02097e40, i);
        if (p != NULL && p->kind == 1 && p->packed.active && p->packed.isType1 == 1) {
            slot = &data_ov006_021ec884->slots[n];
            ov006_Slot_Clear(slot);
            slot->active = 1;
            slot->unk8 = 1;
            MI_CpuCopy8(p->packed.name, slot->name, sizeof(slot->name));
            slotRef->unk12 = i;
            ov006_Slot_Unpack(slot, &p->packed);
            if (i == func_02046ab4(data_02097e40)) {
                data_ov006_021ec884->unk5 = n;
            }
            n++;
        }
    }
    for (i2 = 0; i2 < 4; i2++) {
        p2 = func_02046a50(data_02097e40, i2);
        if (p2 != NULL && p2->kind == 1 && p2->packed.active && p2->packed.isType1 == 0) {
            slot2 = &data_ov006_021ec884->slots[n++];
            ov006_Slot_Clear(slot2);
            slot2->active = 1;
            slot2->unk8 = 0;
            MI_CpuCopy8(p2->packed.name, slot2->name, sizeof(slot2->name));
            slot2->unk12 = i2;
            ov006_Slot_Unpack(slot2, &p2->packed);
        }
    }
    mgr = data_ov006_021ec884;
    mgr->numActive = 0;
    for (k = 0; k < 4; k++) {
        if (mgr->slots[k].active) {
            mgr->numActive++;
        }
    }
}

}
