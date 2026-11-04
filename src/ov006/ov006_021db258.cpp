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

extern ov006_WhState *gWhMgr;
ov006_NetSlot *Wh_GetSharedData(ov006_WhState *a, int idx);
u16 func_02046ab4(ov006_WhState *a);

static inline void ov006_Slot_Unpack(ov006_Slot *self, const ov006_SlotPacked *src) {
    self->active = src->active ? 1 : 0;
    self->type = src->isType1 ? 1 : 0;
    self->unkC = src->unkC | 0x7000;
    self->unk10 = src->unk10;
    STD_CopyLString(self->name, src->name, sizeof(self->name));
}

void ov006_UpdateNetSlots(void);

#ifdef NONMATCHING
// Status (round auA): demoted in the honesty audit. The match wrote slot->aid through a C++ reference alias
// `ov006_Slot *&slotRef = slot` (a permuter result) for the register assignment of i and slot; through slot itself
// the registers differ. This file is the function's whole .text, so it has no delinks entry. The score is in
// docs/UNMATCHED.md;
// the default build takes this function from the dsd gap. History: docs/MATCHING.md round auA.
void ov006_UpdateNetSlots(void) {
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
    if (!gOv006Manager->unk1C || gOv006Menu == NULL) {
        return;
    }
    if (gWhMgr->state != 5) {
        return;
    }
    mgr = gOv006SlotManager;
    mgr->numActive = 0;
    mgr->unk5 = 0xff;
    for (j = 0; j < 4; j++) {
        ov006_Slot_Clear(&mgr->slots[j]);
    }
    n = 0;
    for (i = 0; i < 4; i++) {
        p = Wh_GetSharedData(gWhMgr, i);
        if (p != NULL && p->kind == 1 && p->packed.active && p->packed.isType1 == 1) {
            slot = &gOv006SlotManager->slots[n];
            ov006_Slot_Clear(slot);
            slot->active = 1;
            slot->type = 1;
            MI_CpuCopy8(p->packed.name, slot->name, sizeof(slot->name));
            slot->aid = i;
            ov006_Slot_Unpack(slot, &p->packed);
            if (i == func_02046ab4(gWhMgr)) {
                gOv006SlotManager->unk5 = n;
            }
            n++;
        }
    }
    for (i2 = 0; i2 < 4; i2++) {
        p2 = Wh_GetSharedData(gWhMgr, i2);
        if (p2 != NULL && p2->kind == 1 && p2->packed.active && p2->packed.isType1 == 0) {
            slot2 = &gOv006SlotManager->slots[n++];
            ov006_Slot_Clear(slot2);
            slot2->active = 1;
            slot2->type = 0;
            MI_CpuCopy8(p2->packed.name, slot2->name, sizeof(slot2->name));
            slot2->aid = i2;
            ov006_Slot_Unpack(slot2, &p2->packed);
        }
    }
    mgr = gOv006SlotManager;
    mgr->numActive = 0;
    for (k = 0; k < 4; k++) {
        if (mgr->slots[k].active) {
            mgr->numActive++;
        }
    }
}
#else
// Round fkA fakematch (docs/FAKEMATCHES.md). The honest draft is the NONMATCHING branch above.
void ov006_UpdateNetSlots(void) {
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
    if (!gOv006Manager->unk1C || gOv006Menu == NULL) {
        return;
    }
    if (gWhMgr->state != 5) {
        return;
    }
    // FAKEMATCH: permuter alias. slot->aid is written through this C++ reference to slot, which gives the ROM's
    // registers for i and slot in the first loop.
    ov006_Slot *&slotRef = slot;
    mgr = gOv006SlotManager;
    mgr->numActive = 0;
    mgr->unk5 = 0xff;
    for (j = 0; j < 4; j++) {
        ov006_Slot_Clear(&mgr->slots[j]);
    }
    n = 0;
    for (i = 0; i < 4; i++) {
        p = Wh_GetSharedData(gWhMgr, i);
        if (p != NULL && p->kind == 1 && p->packed.active && p->packed.isType1 == 1) {
            slot = &gOv006SlotManager->slots[n];
            ov006_Slot_Clear(slot);
            slot->active = 1;
            slot->type = 1;
            MI_CpuCopy8(p->packed.name, slot->name, sizeof(slot->name));
            slotRef->aid = i;
            ov006_Slot_Unpack(slot, &p->packed);
            if (i == func_02046ab4(gWhMgr)) {
                gOv006SlotManager->unk5 = n;
            }
            n++;
        }
    }
    for (i2 = 0; i2 < 4; i2++) {
        p2 = Wh_GetSharedData(gWhMgr, i2);
        if (p2 != NULL && p2->kind == 1 && p2->packed.active && p2->packed.isType1 == 0) {
            slot2 = &gOv006SlotManager->slots[n++];
            ov006_Slot_Clear(slot2);
            slot2->active = 1;
            slot2->type = 0;
            MI_CpuCopy8(p2->packed.name, slot2->name, sizeof(slot2->name));
            slot2->aid = i2;
            ov006_Slot_Unpack(slot2, &p2->packed);
        }
    }
    mgr = gOv006SlotManager;
    mgr->numActive = 0;
    for (k = 0; k < 4; k++) {
        if (mgr->slots[k].active) {
            mgr->numActive++;
        }
    }
}
#endif

}
