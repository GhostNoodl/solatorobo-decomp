#include "ov006/Tasks.h"

extern "C" {

extern const char data_ov006_021ebb91[];
extern const char data_ov006_021ebb94[];
extern const char data_ov006_021ebb9b[];
extern const char data_ov006_021ebba0[];

void ov006_SetupDefaultSlots(void);
ov006_SlotManagerInfo *ov006_GetCourseInfo(u32 id);
void ov006_SlotManager_CountActive(ov006_SlotManager *self);
ov006_Slot *ov006_SlotManager_InitSlot(ov006_SlotManager *self, int idx, int type, const char *name, u8 unk12);
void ov006_Slot_SetSub2C(ov006_Slot *self, const ov006_SlotSub *src);
void ov006_Slot_SetSub3C(ov006_Slot *self, const ov006_SlotSub *src);
u16 DataRes_ReadEntry(void *res, int a, int b, u32 idx);
void DataRes_WriteEntry(void *res, int a, int b, u32 idx, u16 v);
void func_020627fc(u8 v);
void func_0206280c(u16 v);
void func_ov000_02182590(u8 *p);

static inline void ov006_SetInfo(u16 id) {
    ov006_SlotManagerInfo *info = ov006_GetCourseInfo(id);
    ov006_SlotManager *m = gOv006SlotManager;
    m->unk6 = id;
    m->info = info;
}

static inline u32 ov006_RecordIdx(void) {
    u32 idx = 0xffff;
    switch (gOv006Manager->unk14) {
    case 2:
        idx = 3;
        break;
    case 4:
    case 5:
        idx = 2;
        break;
    case 6:
        idx = 5;
        break;
    case 7:
        idx = 6;
        break;
    }
    return idx;
}

void ov006_Manager_Mode01to07(int type, void *obj, int arg) {
    ov006_Slot *slot;
    switch (type) {
    case 1:
        gOv006Manager->taskType = 1;
        switch (gOv006Manager->unk14) {
        case 0:
        case 1:
        default:
            ov006_SetupDefaultSlots();
            ov006_SetInfo(0xb005);
            break;
        case 2:
            ov006_SlotManager_InitSlot(gOv006SlotManager, 0, 1, data_ov006_021ebb91, 0xff)->unkC = 0x7002;
            gOv006SlotManager->unk5 = 0;
            ov006_SlotManager_CountActive(gOv006SlotManager);
            ov006_SetInfo(0xb006);
            break;
        case 3:
            ov006_SlotManager_InitSlot(gOv006SlotManager, 0, 1, data_ov006_021ebb91, 0xff)->unkC = 0x7000;
            ov006_SlotManager_InitSlot(gOv006SlotManager, 1, 0, data_ov006_021ebb94, 0xff)->unkC = 0x7005;
            gOv006SlotManager->unk5 = 0;
            ov006_SlotManager_CountActive(gOv006SlotManager);
            ov006_SetInfo(0xb007);
            break;
        case 4:
        case 5:
            ov006_SetupDefaultSlots();
            slot = ov006_SlotManager_InitSlot(gOv006SlotManager, 0, 1, data_ov006_021ebb91, 0xff);
            slot->unkC = gOv006Manager->unk14 == 4 ? 0x7003 : 0x7001;
            slot = ov006_SlotManager_InitSlot(gOv006SlotManager, 1, 0, data_ov006_021ebb9b, 0xff);
            slot->unkC = gOv006Manager->unk14 == 4 ? 0x700d : 0x700e;
            ov006_SetInfo(0xb008);
            break;
        case 6:
            ov006_SlotManager_InitSlot(gOv006SlotManager, 0, 1, data_ov006_021ebb91, 0xff)->unkC = 0x7000;
            ov006_SlotManager_InitSlot(gOv006SlotManager, 1, 0, data_ov006_021ebba0, 0xff)->unkC = 0x700c;
            gOv006SlotManager->unk5 = 0;
            ov006_SlotManager_CountActive(gOv006SlotManager);
            ov006_SetInfo(0xb009);
            break;
        case 7:
            ov006_SetupDefaultSlots();
            ov006_SetInfo(0xb00a);
            break;
        }
        break;
    case 7: {
        u32 idx = 0xffff;
        u16 v = 0x2a30;
        switch (gOv006Manager->unk14) {
        case 2:
            idx = 3;
            gOv006SlotManager->unk13C = 0;
            gOv006SlotManager->time = 0;
            break;
        case 4:
        case 5:
            idx = 2;
            gOv006SlotManager->unk13C = 0;
            gOv006SlotManager->time = 0;
            break;
        case 6:
            idx = 5;
            gOv006SlotManager->unk13C = 0;
            gOv006SlotManager->time = 0;
            break;
        case 7:
            idx = 6;
            gOv006SlotManager->unk13C = 0;
            gOv006SlotManager->time = 0;
            break;
        default:
            gOv006SlotManager->unk13C = 0;
            gOv006SlotManager->time = 0;
            break;
        }
        if (idx != 0xffff) {
            v = DataRes_ReadEntry(gDataRes, 4, 0x10, idx);
        }
        gOv006SlotManager->unk144 = v;
        break;
    }
    case 8:
        if (arg == 2) {
            ov006_SlotSub sub;
            u8 i;
            gOv006Manager->taskType = 1;
            gOv006Manager->unk20 = 0;
            gOv006SlotManager->unk13D = 0;
            sub.unk0 = 0;
            sub.unk2 = 0;
            sub.unk3 = 0;
            sub.unk4 = 0;
            sub.unk8 = 0;
            sub.unkC = 0;
            for (i = 0; i < 4; i++) {
                ov006_Slot_SetSub2C(ov006_SlotManager_GetSlot_021db060(gOv006SlotManager, i), &sub);
                ov006_Slot_SetSub3C(ov006_SlotManager_GetSlot_021db060(gOv006SlotManager, i), &sub);
            }
        } else {
            u8 b;
            u32 n;
            u8 c;
            u16 n16;
            ov006_SlotManager *m;
            gOv006Manager->taskType = 3;
            m = gOv006SlotManager;
            n = m->time;
            b = m->unk148;
            c = m->lap;
            if (n > 0xffff) {
                n = 0xffff;
            }
            n16 = n;
            if (b == 2) {
                u32 idx = ov006_RecordIdx();
                if (idx != 0xffff) {
                    DataRes_WriteEntry(gDataRes, 4, 0x10, idx, n16);
                }
            }
            func_020627fc(c);
            func_0206280c(n16);
            {
                u8 *p = (u8 *)gSceneCmd + 0xac;
                *p = 1;
                func_ov000_02182590(p);
            }
        }
        break;
    }
}

}
