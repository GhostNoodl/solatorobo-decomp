#include "types.h"

typedef struct {
    u16 a;
    u16 b;
} Ent0214bcc4;

extern void *data_02fe152c;
Ent0214bcc4 *func_0205976c(void *a, s32 b);
s32 func_02061f08(u16 id);
u32 func_ov000_0214bf2c(u16 a);
BOOL func_020594bc(void *a, int b, int c, int d);
BOOL func_02059544(void *a, void *b, void *c, s32 d, s32 e);

u16 func_ov000_0214bcc4(s32 kind, s32 idx) {
    u8 *base;
    u16 ret;
    s32 x;
    BOOL got;
    s32 id;
    u32 fl;
    Ent0214bcc4 *tbl;

    base = *(u8 **)((u8 *)data_02fe152c + 0x4c);
    tbl = func_0205976c(data_02fe152c, 1);
    ret = 0xffff;
    x = func_02061f08(tbl[idx].b);
    fl = func_ov000_0214bf2c(tbl[idx].b);
    {
        s32 hidden = fl;
        hidden &= 0x100;
        if (hidden) {
            return ret;
        }
    }
    if (fl & 0x80) {
        if (func_020594bc(data_02fe152c, 5, 1, 0x29)) {
            return ret;
        }
    }
    got = fl;
    if (got & 0x20) {
        got = 0;
    } else {
        s32 slot = 0x30;
        slot += (s32)base;
        got = func_02059544(data_02fe152c, (void *)slot, tbl, 0x301, idx);
    }
    if (func_02059544(data_02fe152c, base + 0x30, tbl, 1, idx) == 1 && got == 0) {
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
