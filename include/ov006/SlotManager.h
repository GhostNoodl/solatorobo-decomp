#ifndef OV006_SLOTMANAGER_H
#define OV006_SLOTMANAGER_H

#include "ov006/ov006.h"
#include "nitro/mi.h"
#include "nitro/std.h"

typedef struct ov006_SlotSub {
    u16 unk0;
    u8 unk2;
    u8 unk3;
    int unk4;
    int unk8;
    int unkC;
} ov006_SlotSub;

typedef struct ov006_Slot {
    void *vtbl;
    u8 active;
    int type;
    u16 unkC;
    u16 actorId;
    u8 unk10;
    u16 aid;
    char name[0x16];
    ov006_SlotSub sub2C;
    ov006_SlotSub sub3C;
} ov006_Slot;

typedef struct ov006_SlotPacked {
    u16 active : 1;
    u16 isType1 : 1;
    u16 unkC : 4;
    u16 unk10 : 2;
    u16 unk0_8 : 8;
    char name[0x16];
} ov006_SlotPacked;

typedef struct ov006_SlotManagerInfo {
    u8 unk0[0xb];
    u8 unkB;
} ov006_SlotManagerInfo;

typedef struct ov006_SlotManager {
    void *vtbl;
    u8 numActive;
    u8 unk5;
    u16 unk6;
    ov006_SlotManagerInfo *info;
    ov006_Slot slots[4];
    u8 unk13C;
    u8 unk13D;
    u8 lap;
    int time;
    int unk144;
    u8 unk148;
    u8 unk149;
    u8 items[3];
    u8 unk14D[3];
} ov006_SlotManager;

#ifdef __cplusplus
extern "C" {
#endif

extern void *ov006_Slot_vtbl;
extern void *Ov006Vt_021ec068_vtbl;
extern ov006_SlotManager *gOv006SlotManager;

void __cxa_vec_ctor(void *arr, int count, u32 size, void *ctor, void *dtor);
void __cxa_vec_cleanup(void *arr, int count, u32 size, void *dtor);

void ov006_Slot_Dtor(ov006_Slot *self);
ov006_Slot *Ov006Vt_021ec078_Ctor(ov006_Slot *self);

#ifdef __cplusplus
}
#endif

static inline void ov006_Slot_Clear(ov006_Slot *self) {
    self->active = 0;
    self->type = 0;
    self->actorId = 0xffff;
    self->unk10 = 0;
    self->aid = 0xff;
    MI_CpuFill8(self->name, 0, sizeof(self->name));
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

static inline void ov006_SlotManager_ClearState(ov006_SlotManager *self) {
    self->info = NULL;
    self->unk13C = 0;
    self->unk13D = 0;
    self->lap = 0;
    self->time = 0;
    self->unk144 = 0;
}

static inline void ov006_SlotManager_Reset(ov006_SlotManager *self) {
    u16 i;
    self->numActive = 0;
    self->unk5 = 0xff;
    for (i = 0; i < 4; i++) {
        ov006_Slot_Clear(&self->slots[i]);
    }
    ov006_SlotManager_ClearState(self);
}

#endif
