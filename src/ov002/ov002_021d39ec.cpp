#include "ov002/ov002.h"

extern "C" {

void func_ov000_0215d980(void *a, u32 b, int c);

void func_0206f5e4(u16 id, int b);

static inline u8 *getSelected(void *list) {
    u8 *p = FIELD(list, 0x98, u8 *);
    s32 n;
    if (p == NULL) {
        return NULL;
    }
    n = FIELD(list, 0xb1, s8);
    while (n-- != 0) {
        p = FIELD(p, 0x2c, u8 *);
    }
    return p;
}

BOOL func_ov002_021d39ec(void *self, void *ev) {
    u8 *o;
    u8 *c;
    u8 *item;
    VObject *list;
    u32 cost;
    o = FIELD(self, 0x8, u8 *);
    if (ev != NULL) {
        if (FIELD(ev, 0x6, u16) == 0) {
            list = FIELD(o, 0x3c, VObject *);
            c = FIELD(o, 0x44, u8 *);
            item = FIELD(list, 0x98, u8 *);
            if (item == NULL) {
                item = NULL;
            } else {
                s32 n = FIELD(list, 0xb1, s8);
                while (n-- != 0) {
                    item = FIELD(item, 0x2c, u8 *);
                }
            }
            cost = FIELD(c, 0x8c, u32) - FIELD(item, 0xc, u32);
            func_ov000_0215d980(c, cost, 0);
            { u8 *g = (u8 *)data_0214a424; if (cost > 9999) { cost = 9999; } FIELD(g, 0x614, u32) = cost; }
            list->v0x70(item);
            func_0206f5e4(FIELD(item, 0x6, u16), 1);
            func_02049a48(data_02097e4c, 0x31, -1, -1, -1);
        } else {
            func_02049a48(data_02097e4c, 0x1f, -1, -1, -1);
        }
        return FALSE;
    }
    func_02049a48(data_02097e4c, 0x1f, -1, -1, -1);
    return FALSE;
}

BOOL func_ov002_021d39ec(void *self, void *ev);

BOOL func_ov002_021d3b10(void *self, void *ev) {
    u8 *o = FIELD(self, 0x8, u8 *);
    void *a = FIELD(o, 0x3c, void *);
    u8 *c = FIELD(o, 0x44, u8 *);
    if (ev != NULL) {
        if (FIELD(c, 0x8c, u32) >= FIELD(ev, 0xc, u32)) {
            func_ov000_02152294(a, 0xf5, 0x18, func_ov002_021d39ec);
            func_02049a48(data_02097e4c, 0x1e, -1, -1, -1);
        } else {
            VObject *b = FIELD(o, 0x40, VObject *);
            func_ov000_0215bb14(b, func_0204c0e8(data_02149ef8, 0x9c));
            b->v0x70();
            FIELD(o, 0x4c, u8) = 0;
            func_02049a48(data_02097e4c, 0x20, -1, -1, -1);
        }
    } else {
        func_02049a48(data_02097e4c, 0x1f, -1, -1, -1);
        FIELD(FIELD(o, 0x3c, u8 *), 0xc, u32) |= 2;
        FIELD(FIELD(o, 0x40, u8 *), 0xc, u32) |= 2;
        FIELD(FIELD(o, 0x44, u8 *), 0xc, u32) |= 2;
        FIELD(FIELD(o, 0x48, u8 *), 0xc, u32) |= 2;
    }
    return TRUE;
}

}
