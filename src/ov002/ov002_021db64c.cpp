#include "ov002/ov002.h"

extern "C" {

void func_ov002_021db64c(void *self) {
    u32 saved;
    HEAP_PUSH(saved);
    DELETE_VOBJ(FIELD(self, 0x10, VObject *));
    HEAP_POP(saved);
    HEAP_PUSH(saved);
    DELETE_VOBJ(FIELD(self, 0x18, VObject *));
    HEAP_POP(saved);
    HEAP_PUSH(saved);
    DELETE_VOBJ(FIELD(self, 0x20, VObject *));
    HEAP_POP(saved);
    HEAP_PUSH(saved);
    DELETE_VOBJ(FIELD(self, 0x24, VObject *));
    HEAP_POP(saved);
}

typedef struct B750 { u16 a : 4; u16 b : 4; u16 rest : 8; } B750;

extern VFunc data_ov000_021cadcc[];

extern VFunc data_ov000_021cae48[];

extern s16 data_ov002_021ef016[];

extern u8 data_ov002_021efe30[];

void func_ov000_0215d980(void *a, u16 b, int c);

void func_ov000_021917f8(void *a);

void *func_ov000_02190a30(void *a, int b);

void func_ov002_021db750(void *self) {
    VObject *o;
    VObject *o2;
    void *g = data_02149ef8;
    u8 *s;
    s16 *e;
    u8 *p;
    o = (VObject *)func_0203dd9c(0x8c);
    if (o != NULL) {
        *(VFunc **)o = data_ov000_021cac60;
        o->v0x28();
        *(VFunc **)o = data_ov000_021cadcc;
        o->v0x28();
    }
    FIELD(self, 0x20, VObject *) = o;
    FIELD(o, 0x24, s32) = 0xf8;
    FIELD(FIELD(self, 0x20, void *), 0x20, s32) = 2;
    s = FIELD(self, 0x20, u8 *);
    FIELD(s, 0x64, s16) = 4;
    FIELD(s, 0x66, s16) = 0x97;
    FIELD(s, 0x68, s16) = -0x666;
    s = FIELD(self, 0x20, u8 *);
    FIELD(s, 0x58, s32) = -0x100;
    FIELD(s, 0x5c, s32) = 0;
    FIELD(s, 0x60, s32) = -0x666;
    FIELD(FIELD(self, 0x20, void *), 0x2c, s32) = 1;
    FIELD(self, 0x20, VObject *)->v0x10(func_0204c0e8(g, 0xbc));
    FIELD(self, 0x20, VObject *)->v0x14(func_0204c0e8(g, 0x10a));
    func_ov000_0215bb14(FIELD(self, 0x20, void *), data_ov002_021efe30);
    FIELD(self, 0x20, VObject *)->v0x8();
    FIELD(self, 0x20, VObject *)->v0x70();
    FIELD(FIELD(self, 0x20, void *), 0xc, u32) &= ~2;
    o2 = (VObject *)func_0203dd9c(0x98);
    if (o2 != NULL) {
        *(VFunc **)o2 = data_ov000_021cac60;
        o2->v0x28();
        *(VFunc **)o2 = data_ov000_021cae48;
        o2->v0x28();
    }
    FIELD(self, 0x24, VObject *) = o2;
    FIELD(o2, 0x64, s16) = 0x9c;
    FIELD(o2, 0x66, s16) = 0x88;
    FIELD(o2, 0x68, s16) = -0x1666;
    s = FIELD(self, 0x24, u8 *);
    FIELD(s, 0x58, s32) = 0x100;
    FIELD(s, 0x5c, s32) = 0;
    FIELD(s, 0x60, s32) = -0x1666;
    FIELD(FIELD(self, 0x24, void *), 0x2c, s32) = 1;
    FIELD(FIELD(self, 0x24, void *), 0x84, s32) = 3;
    func_ov000_0215d980(FIELD(self, 0x24, void *), FIELD(FIELD(self, 0x4, void *), 0x8a, u16), 0);
    FIELD(self, 0x24, VObject *)->v0x8();
    FIELD(FIELD(self, 0x24, void *), 0xc, u32) &= ~2;
    {
        B750 *b = &FIELD(FIELD(FIELD(FIELD(self, 0x4, void *), 0x4, void *), 0x6c, void *), 0x6, B750);
        s32 lo = b->a;
        s32 hi = b->b;
        FIELD(self, 0x28, s32) = lo;
        FIELD(self, 0x2c, s32) = hi;
    }
    p = FIELD(FIELD(self, 0x4, void *), 0x4, u8 *);
    if (FIELD(p, 0x5d, u8) == 0) {
        s32 val = 0;
        s32 *q;
        func_ov000_021917f8(FIELD(p, 0x10, void *));
        e = data_ov002_021ef016;
        FIELD(p, 0x60, s16 *) = e;
        q = *(s32 **)func_ov000_02190a30(FIELD(p, 0x10, void *), 0);
        if (q != NULL) {
            val = *q;
        }
        while (e[0] < (val >> 12)) {
            if (e[0] < 0) {
                break;
            }
            e += 3;
        }
        FIELD(p, 0x64, s16 *) = e;
        FIELD(p, 0x5d, u8) = 1;
        FIELD(self, 0x34, s32) = 0x3c;
    }
}

}
