#include "ov006/Tasks.h"

typedef struct ov006_DataRes {
    u8 unk0[0x4c];
    u8 *unk4C;
} ov006_DataRes;

extern "C" {


void *Param_Get(u32 id);
void *func_0206ffa0(s32 id);
void *DataRes_GetTable(ov006_DataRes *res, u32 idx);
u32 DataRes_GetCount(ov006_DataRes *res, u32 idx);
u16 DataRes_ReadBitsAt_02059544(ov006_DataRes *res, void *block, void *entries, int packed, u32 id);
void ov006_SlotManager_ClearState_021daf60(ov006_SlotManager *self);

static inline u16 ov006_SlotId(ov006_SlotManager *m) {
    return m->unk6 & 0xfff;
}

void func_ov006_021cd5a8(int type, UiList *obj, int arg) {
    switch (type) {
    case 0:
        break;
    case 1:
        data_ov006_021ec860->taskType = 0;
        break;
    case 2:
        if (data_ov006_021ec860->unk18 == 0) {
            TaskHost_RequestSwitch(data_ov000_021ccd44, 0x26, 0);
            break;
        }
        switch (data_ov006_021ec860->unk20) {
        case 2:
            if (data_ov006_021ec860->unk1C) {
                TaskHost_RequestSwitch(data_ov000_021ccd44, 0x29,
                                    ov006_SlotManager_GetSlot_021db060(data_ov006_021ec884, data_ov006_021ec884->unk5)->aid == 0 ? 1 : 2);
            } else {
                TaskHost_RequestSwitch(data_ov000_021ccd44, 0x29, 0);
            }
            ov006_SlotManager_ClearState_021daf60(data_ov006_021ec884);
            break;
        case 1:
        default:
            TaskHost_RequestSwitch(data_ov000_021ccd44, 0x26, 0);
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
        res = (ov006_DataRes *)data_02fe152c;
        base = res->unk4C;
        tbl = DataRes_GetTable(res, 14);
        n = DataRes_GetCount((ov006_DataRes *)data_02fe152c, 14);
        for (i = 0; i < n; i++) {
            id = i | 0x7000;
            if (DataRes_ReadBitsAt_02059544((ov006_DataRes *)data_02fe152c, base + 0x1d0, tbl, 1, i)) {
                obj->vfunc_74(func_0206ffa0(id), id, 0xffff, 0xffff);
            }
        }
        break;
    }
    case 4:
        if (obj != NULL) {
            TaskHost_RequestSwitch(data_ov000_021ccd44, 0x2a, arg);
        } else {
            TaskHost_RequestSwitch(data_ov000_021ccd44, 0x26, arg);
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
            data_ov006_021ec860->taskType = 1;
        } else {
            TaskHost_RequestSwitch(data_ov000_021ccd44, 0x29, arg);
        }
        break;
    case 7: {
        u8 idx;
        u32 v = 0;
        u8 *g;
        data_ov006_021ec884->unk13C = 0;
        data_ov006_021ec884->time = 0;
        idx = ov006_SlotId(data_ov006_021ec884);
        g = (u8 *)data_0214a424;
        if (idx < 5) {
            v = ((u32 *)(g + 0x624))[idx];
        }
        data_ov006_021ec884->unk144 = v;
        break;
    }
    case 8:
        if (arg == 2) {
            data_ov006_021ec860->taskType = 0;
        } else if (arg == 1) {
            data_ov006_021ec860->taskType = 0;
        } else if (arg == 3) {
            data_ov006_021ec860->taskType = 2;
        } else {
            data_ov006_021ec860->taskType = 0;
        }
        data_ov006_021ec860->unk20 = arg;
        break;
    }
}

}
