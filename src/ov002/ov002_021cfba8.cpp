#include "ov002/ov002.h"

extern "C" {

extern VFunc data_ov000_021cadcc[];

void func_ov002_021cfba8(void *self) {
    VObject *o;
    VObject *o2;
    u8 *s;
    VObject *m;
    void *g;
    FIELD(self, 0x4, u32) &= ~2;
    if (((VObject *)self)->v0x28()) {
        FIELD(FIELD(self, 0x3c, void *), 0xc, u32) &= ~2;
        FIELD(FIELD(self, 0x40, void *), 0xc, u32) &= ~2;
        FIELD(self, 0x44, u16) = 0;
        return;
    }
    g = data_02149ef8;
    o = (VObject *)func_0203dd9c(0xd4);
    if (o != NULL) {
        *(VFunc **)o = data_ov000_021cac60;
        o->v0x28();
        *(VFunc **)o = data_ov000_021caec8;
        o->v0x28();
    }
    FIELD(self, 0x3c, VObject *) = o;
    FIELD(o, 0x20, s32) = 2;
    FIELD(FIELD(self, 0x3c, void *), 0x24, s32) = 0x92;
    s = FIELD(self, 0x3c, u8 *);
    FIELD(s, 0x64, s16) = 0;
    FIELD(s, 0x66, s16) = 0x23;
    FIELD(s, 0x68, s16) = -0x199a;
    FIELD(self, 0x3c, VObject *)->v0x10(func_0204c0e8(g, 0xe8));
    FIELD(self, 0x3c, VObject *)->v0x14(func_0204c0e8(g, 0xea));
    FIELD(FIELD(self, 0x3c, void *), 0xc, u32) &= ~0x10000;
    FIELD(FIELD(self, 0x3c, void *), 0xc, u32) &= ~0x40000;
    FIELD(FIELD(self, 0x3c, void *), 0xc, u32) &= ~0x20000;
    FIELD(self, 0x3c, VObject *)->v0x74(func_0204c0e8(g, 0xf1), 0xb, 0xffff, 0xffff);
    FIELD(self, 0x3c, VObject *)->v0x74(func_0204c0e8(g, 0xf2), 0x14, 0xffff, 0xffff);
    FIELD(self, 0x3c, VObject *)->v0x8();
    m = FIELD(self, 0x3c, VObject *);
    m->v0xa8(func_ov000_02154b58(m, (void *)0xb));
    o2 = (VObject *)func_0203dd9c(0x8c);
    if (o2 != NULL) {
        *(VFunc **)o2 = data_ov000_021cac60;
        o2->v0x28();
        *(VFunc **)o2 = data_ov000_021cadcc;
        o2->v0x28();
    }
    FIELD(self, 0x40, VObject *) = o2;
    FIELD(o2, 0x24, s32) = 0xf8;
    FIELD(FIELD(self, 0x40, void *), 0x20, s32) = 2;
    s = FIELD(self, 0x40, u8 *);
    FIELD(s, 0x64, s16) = 4;
    FIELD(s, 0x66, s16) = 0x95;
    FIELD(s, 0x68, s16) = -0x199a;
    s = FIELD(self, 0x40, u8 *);
    FIELD(s, 0x58, s32) = -0x100;
    FIELD(s, 0x5c, s32) = 0;
    FIELD(s, 0x60, s32) = -0x199a;
    FIELD(FIELD(self, 0x40, void *), 0x2c, s32) = 1;
    FIELD(self, 0x40, VObject *)->v0x8();
    func_ov000_02173648(self);
}

BOOL func_ov002_021cf314(int idx, u32 arg);

void func_ov002_021cfe48(void *self) {
    u8 *e;
    void *mgr;
    u32 s1;
    u32 s2;
    u8 *e2;
    if (FIELD(self, 0x8, s32) == 8) {
        mgr = data_02149ef8;
        e = (u8 *)func_ov000_02154b58(FIELD(self, 0x3c, void *), (void *)0xb);
        FIELD(e, 0x0, void *) = NULL;
        {
            HEAP_PUSH(s1);
            DELETE_VOBJ(FIELD(e, 0x1c, VObject *));
            HEAP_POP(s1);
        }
        FIELD(e, 0x0, void *) = func_0204c0e8(mgr, 0xf1);
        if (func_ov002_021cf314(8, 1)) {
            FIELD(e, 0x24, s32) = 0xe;
            FIELD(e, 0x10, s32) = -1;
        } else {
            FIELD(e, 0x24, s32) = 0;
            FIELD(e, 0x10, s32) = 0;
        }
        func_ov000_02153c48(e, 8, 0, 0, 0);
        e2 = (u8 *)func_ov000_02154b58(FIELD(self, 0x3c, void *), (void *)0x14);
        FIELD(e2, 0x0, void *) = NULL;
        {
            HEAP_PUSH(s2);
            DELETE_VOBJ(FIELD(e2, 0x1c, VObject *));
            HEAP_POP(s2);
        }
        FIELD(e2, 0x0, void *) = func_0204c0e8(mgr, 0xf2);
        if (func_ov002_021cf314(8, 0x101)) {
            FIELD(e2, 0x24, s32) = 0xe;
            FIELD(e2, 0x10, s32) = -1;
        } else {
            FIELD(e2, 0x24, s32) = 0;
            FIELD(e2, 0x10, s32) = 0;
        }
        func_ov000_02153c48(e2, 8, 0, 0, 0);
    }
    FIELD(self, 0x3c, VObject *)->v0x1c();
    FIELD(self, 0x40, VObject *)->v0x1c();
}

}
