#ifndef OV006_SLOTMANAGER_H
#define OV006_SLOTMANAGER_H

#include "ov006/ov006.h"

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
    int unk8;
    u16 unkC;
    u16 unkE;
    u8 unk10;
    u16 unk12;
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
    ov006_SlotManagerInfo *unk8;
    ov006_Slot slots[4];
    u8 unk13C;
    u8 unk13D;
    u8 unk13E;
    int unk140;
    int unk144;
    u8 unk148;
    u8 unk149;
    u8 unk14A[3];
    u8 unk14D[3];
} ov006_SlotManager;

#ifdef __cplusplus
extern "C" {
#endif

extern void *data_ov006_021ec078;
extern void *data_ov006_021ec068;
extern ov006_SlotManager *data_ov006_021ec884;

void MI_CpuFill8(void *dst, u8 value, u32 size);
void MI_CpuCopy8(const void *src, void *dst, u32 size);
void STD_CopyLString(void *dst, const void *src, u32 size);
void __cxa_vec_ctor(void *arr, int count, u32 size, void *ctor, void *dtor);
void __cxa_vec_cleanup(void *arr, int count, u32 size, void *dtor);

void func_ov006_021dab5c(ov006_Slot *self);
ov006_Slot *func_ov006_021daad8(ov006_Slot *self);

#ifdef __cplusplus
}
#endif

static inline void ov006_Slot_Clear(ov006_Slot *self) {
    self->active = 0;
    self->unk8 = 0;
    self->unkE = 0xffff;
    self->unk10 = 0;
    self->unk12 = 0xff;
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
    self->unk8 = NULL;
    self->unk13C = 0;
    self->unk13D = 0;
    self->unk13E = 0;
    self->unk140 = 0;
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
