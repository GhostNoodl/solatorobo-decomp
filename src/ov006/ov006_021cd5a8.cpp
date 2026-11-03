#include "ov006/Tasks.h"

typedef struct ov006_DataRes {
    u8 unk0[0x4c];
    u8 *unk4C;
} ov006_DataRes;

extern "C" {


void *Param_Get(u32 id);
void *Tbl_GetText(s32 id);
void *DataRes_GetTable(ov006_DataRes *res, u32 idx);
u32 DataRes_GetCount(ov006_DataRes *res, u32 idx);
u16 DataRes_ReadBitsAt_02059544(ov006_DataRes *res, void *block, void *entries, int packed, u32 id);
void ov006_SlotManager_ClearState_021daf60(ov006_SlotManager *self);

static inline u16 ov006_SlotId(ov006_SlotManager *m) {
    return m->unk6 & 0xfff;
}

void ov006_Manager_Mode00(int type, UiList *obj, int arg) {
    switch (type) {
    case 0:
        break;
    case 1:
        gOv006Manager->taskType = 0;
        break;
    case 2:
        if (gOv006Manager->unk18 == 0) {
            TaskHost_RequestSwitch(gTaskHost, 0x26, 0);
            break;
        }
        switch (gOv006Manager->unk20) {
        case 2:
            if (gOv006Manager->unk1C) {
                TaskHost_RequestSwitch(gTaskHost, 0x29,
                                    ov006_SlotManager_GetSlot_021db060(gOv006SlotManager, gOv006SlotManager->unk5)->aid == 0 ? 1 : 2);
            } else {
                TaskHost_RequestSwitch(gTaskHost, 0x29, 0);
            }
            ov006_SlotManager_ClearState_021daf60(gOv006SlotManager);
            break;
        case 1:
        default:
            TaskHost_RequestSwitch(gTaskHost, 0x26, 0);
            break;
        }
        break;
    case 3: {
        ov006_DataRes *res;
        u8 *base;
        u16 n;
        u16 i;
        u16 id;
        void *tbl;
        res = (ov006_DataRes *)gDataRes;
        base = res->unk4C;
        tbl = DataRes_GetTable(res, 14);
        n = DataRes_GetCount((ov006_DataRes *)gDataRes, 14);
        for (i = 0; i < n; i++) {
            id = i | 0x7000;
            if (DataRes_ReadBitsAt_02059544((ov006_DataRes *)gDataRes, base + 0x1d0, tbl, 1, i)) {
                obj->vfunc_74(Tbl_GetText(id), id, 0xffff, 0xffff);
            }
        }
        break;
    }
    case 4:
        if (obj != NULL) {
            TaskHost_RequestSwitch(gTaskHost, 0x2a, arg);
        } else {
            TaskHost_RequestSwitch(gTaskHost, 0x26, arg);
        }
        break;
    case 5:
        obj->vfunc_74(Param_Get(0xb000), 0xb000, 0xffff, 0xffff);
        obj->vfunc_74(Param_Get(0xb001), 0xb001, 0xffff, 0xffff);
        obj->vfunc_74(Param_Get(0xb002), 0xb002, 0xffff, 0xffff);
        obj->vfunc_74(Param_Get(0xb003), 0xb003, 0xffff, 0xffff);
        obj->vfunc_74(Param_Get(0xb004), 0xb004, 0xffff, 0xffff);
        break;
    case 6:
        if (obj != NULL) {
            gOv006Manager->taskType = 1;
        } else {
            TaskHost_RequestSwitch(gTaskHost, 0x29, arg);
        }
        break;
    case 7: {
        u8 idx;
        u32 v = 0;
        u8 *g;
        gOv006SlotManager->unk13C = 0;
        gOv006SlotManager->time = 0;
        idx = ov006_SlotId(gOv006SlotManager);
        g = (u8 *)gStageFlags;
        if (idx < 5) {
            v = ((u32 *)(g + 0x624))[idx];
        }
        gOv006SlotManager->unk144 = v;
        break;
    }
    case 8:
        if (arg == 2) {
            gOv006Manager->taskType = 0;
        } else if (arg == 1) {
            gOv006Manager->taskType = 0;
        } else if (arg == 3) {
            gOv006Manager->taskType = 2;
        } else {
            gOv006Manager->taskType = 0;
        }
        gOv006Manager->unk20 = arg;
        break;
    }
}

}
