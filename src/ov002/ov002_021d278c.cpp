#include "ov002/ov002.h"

extern "C" {

extern void *data_ov002_021ef634[];
extern VFunc data_ov000_021cc9f8[];
extern VFunc data_ov000_021cadcc[];
extern VFunc data_ov000_021cb5a8[];
void *func_02035d8c(void *a, void *b);
void func_ov002_021e4814(void *self, u8 *src);
u32 func_ov002_021e4c30(int which);
u32 func_ov002_021e4960(void *self, s32 val);
void func_ov000_021c3af4(void *self);
void func_ov000_021c22d8(void *self);
void func_ov000_021c2bb0(void *self);
void func_ov000_021c2c0c(void *self, void *a);
void func_ov000_021c3fd4(void *list, void *item);
BOOL func_ov002_021d2390(void *self, void *arg);
BOOL func_ov002_021d2410(void *self, void *ev);

typedef struct Ent021d278c {
    u8 pad0[8];
    u32 n;
    s32 *arr;
    void *p10;
    u8 pad14[4];
} Ent021d278c;

typedef struct Self021d278c {
    u8 pad[0x4c];
    Ent021d278c ent[7];
} Self021d278c;

static inline s32 ov002_Thresh(Ent021d278c *e, s32 idx) {
    s32 *arr = e->arr;
    if (arr == NULL) {
        return -1;
    }
    if ((u32)idx < e->n) {
        return arr[idx];
    }
    return -1;
}

void func_ov002_021d278c(void *self) {
    void *g;
    u16 i;
    u8 buf[0x18];
    FIELD(self, 0x4, u32) &= ~2;
    if (((VObject *)self)->v0x28()) {
        return;
    }
    g = data_02149ef8;
    for (i = 0; i < 7; i++) {
        func_ov002_021d4540(buf, 0x18, data_ov002_021ef634[i], data_ov002_021ef5ac[0], ((int (*)(void))func_0206e8f0)());
        func_ov002_021e4814((u8 *)self + 0x4c + i * 0x18, *(u8 **)func_02035d8c((u8 *)self + 0xf4, buf));
    }
    {
        VObject *p = (VObject *)func_0203dd9c(0xf4);
        if (p != NULL) {
            *(VFunc **)p = data_ov000_021cac60;
            p->v0x28();
            *(VFunc **)p = data_ov000_021ccbe0;
            func_ov000_021c3af4(p);
        }
        FIELD(self, 0x3c, VObject *) = p;
        FIELD(p, 0x24, s32) = 0xdb;
    }
    FIELD(FIELD(self, 0x3c, void *), 0x20, s32) = 7;
    {
        u8 *s = FIELD(self, 0x3c, u8 *);
        FIELD(s, 0x64, s16) = 0x12;
        FIELD(s, 0x66, s16) = 0x14;
        FIELD(s, 0x68, s16) = -0x199a;
    }
    FIELD(self, 0x3c, VObject *)->v0x10(func_0204c0e8(g, 0xe5));
    FIELD(self, 0x3c, VObject *)->v0x14(func_0204c0e8(g, 0xe7));
    FIELD(FIELD(self, 0x3c, void *), 0xc, u32) &= ~0x40000;
    for (i = 0; i < 7; i++) {
        u32 val;
        u32 lvl;
        u8 *q;
        q = (u8 *)func_0203dd9c(0x44);
        if (q != NULL) {
            *(VFunc **)q = data_ov002_021ef684;
            func_ov000_021c22d8(q);
            *(VFunc **)q = data_ov000_021cc9f8;
            func_ov000_021c2bb0(q);
        }
        FIELD(q, 0x4, s32) = i;
        func_ov000_021c2c0c(q, ((Self021d278c *)self)->ent[i].p10);
        val = func_ov002_021e4c30(i);
        lvl = func_ov002_021e4960(&((Self021d278c *)self)->ent[i], val);
        if (lvl != 3) {
            s32 lo = 0;
            s32 hi;
            if (lvl != 0) {
                lo = ov002_Thresh(&((Self021d278c *)self)->ent[i], lvl - 1);
            }
            hi = ov002_Thresh(&((Self021d278c *)self)->ent[i], lvl);
            FIELD(q, 0x3c, s32) = (s32)((val - lo) * 100) / (hi - lo) + lvl * 100;
        } else {
            FIELD(q, 0x3c, s32) = 300;
        }
        FIELD(q, 0x38, s32) = 300;
        func_ov000_021c3fd4(FIELD(self, 0x3c, void *), q);
    }
    FIELD(FIELD(self, 0x3c, void *), 0x8, void *) = self;
    FIELD(FIELD(self, 0x3c, void *), 0xe8, void *) = (void *)func_ov002_021d2390;
    FIELD(FIELD(self, 0x3c, void *), 0xe4, void *) = (void *)func_ov002_021d2410;
    FIELD(self, 0x3c, VObject *)->v0x8();
    {
        VObject *p = (VObject *)func_0203dd9c(0x8c);
        if (p != NULL) {
            *(VFunc **)p = data_ov000_021cac60;
            p->v0x28();
            *(VFunc **)p = data_ov000_021cadcc;
            p->v0x28();
        }
        FIELD(self, 0x40, VObject *) = p;
        FIELD(p, 0x24, s32) = 0xf5;
    }
    FIELD(FIELD(self, 0x40, void *), 0x20, s32) = 1;
    {
        u8 *s = FIELD(self, 0x40, u8 *);
        FIELD(s, 0x64, s16) = 4;
        FIELD(s, 0x66, s16) = 0x8e;
        FIELD(s, 0x68, s16) = -0x199a;
    }
    {
        u8 *s = FIELD(self, 0x40, u8 *);
        FIELD(s, 0x58, s32) = -0x100;
        FIELD(s, 0x5c, s32) = 0;
        FIELD(s, 0x60, s32) = -0x199a;
    }
    FIELD(FIELD(self, 0x40, void *), 0x2c, s32) = 1;
    FIELD(FIELD(self, 0x40, void *), 0xc, u32) |= 0x10000;
    FIELD(FIELD(self, 0x40, void *), 0x48, u16) = 0xb;
    FIELD(self, 0x40, VObject *)->v0x8();
    {
        VObject *p = (VObject *)func_0203dd9c(0xe0);
        if (p != NULL) {
            *(VFunc **)p = data_ov000_021cac60;
            p->v0x28();
            *(VFunc **)p = data_ov000_021caec8;
            p->v0x28();
            *(VFunc **)p = data_ov000_021cb5a8;
            p->v0x28();
        }
        FIELD(self, 0x44, VObject *) = p;
        FIELD(p, 0xc, u32) |= 0x4000000;
    }
    FIELD(FIELD(self, 0x44, void *), 0x2c, s32) = 1;
    {
        u8 *s = FIELD(self, 0x44, u8 *);
        FIELD(s, 0x58, s32) = -0x100;
        FIELD(s, 0x5c, s32) = 0;
        FIELD(s, 0x60, s32) = -0x199a;
    }
    FIELD(FIELD(self, 0x44, void *), 0xc, u32) |= 0x20000000;
    FIELD(FIELD(self, 0x44, void *), 0xc, u32) |= 0x80000000;
    FIELD(self, 0x44, VObject *)->v0xf4(1, func_0204c0e8(g, 0x34));
    FIELD(self, 0x44, VObject *)->v0xf4(2, func_0204c0e8(g, 0x33));
    FIELD(self, 0x44, VObject *)->v0x8();
    func_ov000_02173648(self);
}

}
