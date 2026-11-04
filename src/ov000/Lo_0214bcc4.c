#include "types.h"

typedef struct {
    u16 a;
    u16 b;
} Ent0214bcc4;

extern void *gDataRes;
Ent0214bcc4 *DataRes_GetTable(void *a, s32 b);
s32 StageTbl_GetQuestOpt(u16 id);
u32 Quest_GetOptFlags(u16 a);
u16 DataRes_ReadEntry(void *a, int b, int c, int d);
u16 DataRes_ReadBitsAt_02059544(void *a, void *b, void *c, s32 d, s32 e);

u16 Quest_GetAvailable(s32 kind, s32 idx) {
    u8 *base;
    u16 ret;
    s32 x;
    BOOL got;
    s32 id;
    u32 fl;
    Ent0214bcc4 *tbl;

    base = *(u8 **)((u8 *)gDataRes + 0x4c);
    tbl = DataRes_GetTable(gDataRes, 1);
    ret = 0xffff;
    x = StageTbl_GetQuestOpt(tbl[idx].b);
    fl = Quest_GetOptFlags(tbl[idx].b);
    {
        s32 hidden = fl;
        hidden &= 0x100;
        if (hidden) {
            return ret;
        }
    }
    if (fl & 0x80) {
        if (DataRes_ReadEntry(gDataRes, 5, 1, 0x29)) {
            return ret;
        }
    }
    got = fl;
    if (got & 0x20) {
        got = 0;
    } else {
        s32 slot = 0x30;
        slot += (s32)base;
        got = DataRes_ReadBitsAt_02059544(gDataRes, (void *)slot, tbl, 0x301, idx);
    }
    if (DataRes_ReadBitsAt_02059544(gDataRes, base + 0x30, tbl, 1, idx) == 1 && got == 0) {
        id = 0x100e;
        if (x != 0) {
            if (fl & 2) {
                id = 0x1008;
            } else if (fl & 4) {
                id = 0x2f01;
            } else if (fl & 8) {
                id = 0x2f02;
            }
        }
        switch (kind) {
        case 0x1008:
            if (id == 0x1008) {
                ret = tbl[idx].b;
            }
            break;
        case 0x2f01:
            if (id == 0x2f01) {
                ret = tbl[idx].b;
            }
            break;
        case 0x2f02:
        default:
            if (id == 0x100e || id == 0x2f02) {
                ret = tbl[idx].b;
            }
            break;
        }
    }
    return ret;
}
