#include "ov006/Tasks.h"

typedef struct ov006_DataRes {
    u8 unk0[0x4c];
    u8 *unk4C;
} ov006_DataRes;

extern "C" {

extern ov006_DataRes *data_02fe152c;

void *func_0206ec48(u16 id);
void *func_0206ffa0(u32 id);
void *func_0205976c(ov006_DataRes *res, u32 idx);
u32 func_0205975c(ov006_DataRes *res, u32 idx);
u16 func_02059544(ov006_DataRes *res, void *block, void *entries, int packed, u32 id);
void func_ov006_021daf60(ov006_SlotManager *self);

static inline u16 ov006_SlotId(ov006_SlotManager *m) {
    return m->unk6 & 0xfff;
}

void func_ov006_021cd5a8(int type, void *obj, int arg) {
    switch (type) {
    case 0:
        break;
    case 1:
        data_ov006_021ec860->taskType = 0;
        break;
    case 2:
        if (data_ov006_021ec860->unk18 == 0) {
            func_ov000_0218084c(data_ov000_021ccd44, 0x26, 0);
            break;
        }
        switch (data_ov006_021ec860->unk20) {
        case 2:
            if (data_ov006_021ec860->unk1C) {
                func_ov000_0218084c(data_ov000_021ccd44, 0x29,
                                    func_ov006_021db060(data_ov006_021ec884, data_ov006_021ec884->unk5)->unk12 == 0 ? 1 : 2);
            } else {
                func_ov000_0218084c(data_ov000_021ccd44, 0x29, 0);
            }
            func_ov006_021daf60(data_ov006_021ec884);
            break;
        case 1:
        default:
            func_ov000_0218084c(data_ov000_021ccd44, 0x26, 0);
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
        res = data_02fe152c;
        base = res->unk4C;
        tbl = func_0205976c(res, 14);
        n = func_0205975c(data_02fe152c, 14);
        for (i = 0; i < n; i++) {
            id = i | 0x7000;
            if (func_02059544(data_02fe152c, base + 0x1d0, tbl, 1, i)) {
                VCALL(obj, 74, func_0206ffa0(id), id, 0xffff, 0xffff);
            }
        }
        break;
    }
    case 4:
        if (obj != NULL) {
            func_ov000_0218084c(data_ov000_021ccd44, 0x2a, arg);
        } else {
            func_ov000_0218084c(data_ov000_021ccd44, 0x26, arg);
        }
        break;
    case 5:
        VCALL(obj, 74, func_0206ec48(0xb000), 0xb000, 0xffff, 0xffff);
        VCALL(obj, 74, func_0206ec48(0xb001), 0xb001, 0xffff, 0xffff);
        VCALL(obj, 74, func_0206ec48(0xb002), 0xb002, 0xffff, 0xffff);
        VCALL(obj, 74, func_0206ec48(0xb003), 0xb003, 0xffff, 0xffff);
        VCALL(obj, 74, func_0206ec48(0xb004), 0xb004, 0xffff, 0xffff);
        break;
    case 6:
        if (obj != NULL) {
            data_ov006_021ec860->taskType = 1;
        } else {
            func_ov000_0218084c(data_ov000_021ccd44, 0x29, arg);
        }
        break;
    case 7: {
        u8 idx;
        u32 v = 0;
        u8 *g;
        data_ov006_021ec884->unk13C = 0;
        data_ov006_021ec884->unk140 = 0;
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
