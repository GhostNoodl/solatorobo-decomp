#include "ov002/ov002.h"

extern "C" {

VObject *func_ov002_021d5860(VObject *self) {
    *(VFunc **)self = data_ov000_021caec8;
    self->v0x2c();
    *(VFunc **)self = data_ov000_021cac60;
    self->v0x2c();
    func_0203de1c(self);
    return self;
}

void func_ov002_021d58ac(void) {
}

BOOL func_ov002_021d58b0(void) {
    return TRUE;
}

}

extern "C" {
extern VFunc data_ov000_021cadcc[];
extern VFunc data_ov002_021efca4[];
extern char *data_0208cb7c;
extern char *data_0208ccc0;
extern char data_ov002_021efaf1[];
extern u8 data_ov002_021eef54[];
void *func_02035de0(void *a, void *b);
void func_02041c20(void *a, int b, void *c);
void func_ov000_021547e8(void *a, void *b, void *c, int d);
void *func_ov000_02162124(void *p);
void func_ov000_021627ac(void *p);
void func_ov000_021c95fc(void *p);
BOOL func_ov002_021d5444(void *self, void *ev);
BOOL func_ov002_021d5350(void *self, void *ev);
void func_ov002_021d66b0(void);

static inline u8 *ov002_021d58b8_sel(void *g) {
    u8 *p = FIELD(g, 0x98, u8 *);
    if (p == NULL) {
        p = NULL;
    } else {
        s32 n = FIELD(g, 0xb1, s8);
        while (n-- != 0) {
            p = FIELD(p, 0x2c, u8 *);
        }
    }
    return p;
}

static inline void ov002_021d58b8_setName(void *self, u16 id) {
    if (FIELD(self, 0x54, void *) != NULL) {
        func_ov000_0215bb14(FIELD(self, 0x54, void *), func_0206ec8c(id));
        FIELD(self, 0x54, VObject *)->v0x70();
    }
}

static inline void ov002_021d58b8_setInfo(void *self, u16 id) {
    if (FIELD(self, 0x58, void *) != NULL) {
        u8 *info = func_0206ef10(id);
        func_ov000_02162b40(FIELD(self, 0x58, void *), FIELD(info, 0xc, s32), FIELD(info, 0x10, s32), data_ov002_021efae1,
                            FIELD(info, 0x28, s32), data_ov002_021efaeb, info[0x24], 0x1000);
    }
}

static inline void ov002_021d58b8_setId(void *x, u16 id) {
    if (x != NULL) {
        func_ov002_021e2754(x, id);
    }
}

void func_ov002_021d58b8(Task50 *self) {
    void *res;
    void *m;
    VObject *o;
    void *g = data_02149ef8;
    u8 *base;
    void *tbl;
    u16 i;
    u16 id;
    u32 count;
    u8 *e;
    FIELD(self, 0x74, u16) = FIELD(data_0214a424, 0x18, Bits021d9e38).id + 0x8000;
    res = func_02035de0(data_ov002_021efaf1, data_0208ccc0);
    m = func_0203dd9c(0x160);
    if (m != NULL) {
        func_02041218((u8 *)m + 0x88);
        func_02041440(m, NULL, 0);
    }
    FIELD(self, 0x3c, void *) = m;
    func_020417e0(m, res);
    FIELD(FIELD(self, 0x3c, void *), 0x6c, u32) |= 2;
    func_02041d9c(FIELD(self, 0x3c, void *), 0, 0);
    FIELD(FIELD(self, 0x3c, void *), 0x150, s32) = -0x1fe66;
    FIELD(FIELD(self, 0x3c, void *), 0x158, void *) = (void *)func_ov002_021d66b0;
    func_02041c20(FIELD(self, 0x3c, void *), 0, (u8 *)self + 0x40);
    o = (VObject *)func_0203dd9c(0x8c);
    if (o != NULL) {
        *(VFunc **)o = data_ov000_021cac60;
        o->v0x28();
        *(VFunc **)o = data_ov000_021cadcc;
        o->v0x28();
    }
    FIELD(self, 0x4c, VObject *) = o;
    FIELD(o, 0x20, s32) = 1;
    {
        u8 *s = FIELD(self, 0x4c, u8 *);
        FIELD(s, 0x64, s16) = 0;
        FIELD(s, 0x66, s16) = 0x12;
        FIELD(s, 0x68, s16) = -0x199a;
    }
    FIELD(FIELD(self, 0x4c, void *), 0x24, s32) = 0x5a;
    FIELD(FIELD(self, 0x4c, void *), 0x68, s16) = -0x199a;
    {
        u8 *s = FIELD(self, 0x4c, u8 *);
        FIELD(s, 0x58, s32) = -0xff;
        FIELD(s, 0x5c, s32) = 0;
        FIELD(s, 0x60, s32) = -0x199a;
    }
    FIELD(FIELD(self, 0x4c, void *), 0x2c, s32) = 1;
    {
        u8 *s = FIELD(self, 0x4c, u8 *);
        FIELD(s, 0x6c, void *) = data_ov002_021eef54;
        FIELD(s, 0x70, s32) = 5;
    }
    FIELD(FIELD(self, 0x4c, void *), 0xc, u32) |= 0x80000;
    FIELD(self, 0x4c, VObject *)->v0x8();
    func_ov000_0215bb14(FIELD(self, 0x4c, void *), func_0206ec48(FIELD(self, 0x74, u16)));
    FIELD(self, 0x4c, VObject *)->v0x70();
    o = (VObject *)func_0203dd9c(0xd4);
    if (o != NULL) {
        *(VFunc **)o = data_ov000_021cac60;
        o->v0x28();
        *(VFunc **)o = data_ov000_021caec8;
        o->v0x28();
        *(VFunc **)o = data_ov002_021efca4;
    }
    FIELD(self, 0x50, VObject *) = o;
    FIELD(self, 0x50, VObject *)->v0x10(func_0204c0e8(g, 0xbe));
    FIELD(self, 0x50, VObject *)->v0x14(func_0204c0e8(g, 0xbf));
    FIELD(FIELD(self, 0x50, void *), 0x20, s32) = 2;
    FIELD(FIELD(self, 0x50, void *), 0x24, s32) = 0x74;
    {
        u8 *s = FIELD(self, 0x50, u8 *);
        FIELD(s, 0x64, s16) = 0;
        FIELD(s, 0x66, s16) = 0x30;
        FIELD(s, 0x68, s16) = -0x199a;
    }
    FIELD(FIELD(self, 0x50, void *), 0x68, s16) = -0x199a;
    {
        u8 *s = FIELD(self, 0x50, u8 *);
        FIELD(s, 0x58, s32) = -0xff;
        FIELD(s, 0x5c, s32) = 0;
        FIELD(s, 0x60, s32) = -0x199a;
    }
    func_ov000_021547e8(FIELD(self, 0x50, void *), data_0214b105, data_0208cb7c, 0xb);
    FIELD(FIELD(self, 0x50, void *), 0xc, u32) &= ~0x400000;
    FIELD(FIELD(self, 0x50, void *), 0xc, u32) &= ~0x80000;
    FIELD(FIELD(self, 0x50, void *), 0xc, u32) |= 0x40000;
    FIELD(FIELD(self, 0x50, void *), 0xc, u32) &= ~0x800000;
    FIELD(FIELD(self, 0x50, void *), 0xc, u32) |= 0x10000;
    FIELD(self, 0x50, VObject *)->v0x8();
    base = FIELD(data_02fe152c, 0x4c, u8 *);
    tbl = func_0205976c(data_02fe152c, 12);
    count = func_0205975c(data_02fe152c, 12);
    for (i = 0; i < count; i++) {
        if (func_02059544(data_02fe152c, base + 0x190, tbl, 1, i)) {
            id = i + 0x8000;
            e = (u8 *)FIELD(self, 0x50, VObject *)->v0x74(func_0206ec48(id), id, 0xffff, 0xffff);
            if (FIELD(self, 0x74, u16) == id) {
                FIELD(e, 0x24, s32) = 4;
            }
        }
    }
    FIELD(FIELD(self, 0x50, void *), 0x84, void *) = (void *)func_ov002_021d5444;
    FIELD(FIELD(self, 0x50, void *), 0x88, void *) = (void *)func_ov002_021d5350;
    FIELD(FIELD(self, 0x50, void *), 0x8, void *) = self;
    {
        VObject *mm = FIELD(self, 0x50, VObject *);
        mm->v0xa8(func_ov000_02154b58(mm, (void *)(u32)FIELD(self, 0x74, u16)));
    }
    o = (VObject *)func_0203dd9c(0x8c);
    if (o != NULL) {
        *(VFunc **)o = data_ov000_021cac60;
        o->v0x28();
        *(VFunc **)o = data_ov000_021cadcc;
        o->v0x28();
    }
    FIELD(self, 0x54, VObject *) = o;
    FIELD(o, 0x24, s32) = 0xf8;
    FIELD(FIELD(self, 0x54, void *), 0x20, s32) = 3;
    {
        u8 *s = FIELD(self, 0x54, u8 *);
        FIELD(s, 0x64, s16) = 4;
        FIELD(s, 0x66, s16) = 0x87;
        FIELD(s, 0x68, s16) = -0x199a;
    }
    {
        u8 *s = FIELD(self, 0x54, u8 *);
        FIELD(s, 0x58, s32) = -0x100;
        FIELD(s, 0x5c, s32) = 0;
        FIELD(s, 0x60, s32) = -0x199a;
    }
    FIELD(FIELD(self, 0x54, void *), 0x2c, s32) = 1;
    FIELD(self, 0x54, VObject *)->v0x8();
    {
        u8 *p = NULL;
        u8 *it = FIELD(FIELD(self, 0x50, void *), 0x98, u8 *);
        if (it != NULL) {
            s32 n = FIELD(FIELD(self, 0x50, void *), 0xb1, s8);
            while (n-- != 0) {
                it = FIELD(it, 0x2c, u8 *);
            }
            p = it;
        }
        if (p != NULL) {
            ov002_021d58b8_setName(self, FIELD(p, 0x6, u16));
        }
    }
    {
        void *q = func_0203dd9c(0x708);
        if (q != NULL) {
            q = func_ov000_02162124(q);
        }
        FIELD(self, 0x58, void *) = q;
        func_ov000_021627ac(q);
    }
    {
        u8 *p = ov002_021d58b8_sel(FIELD(self, 0x50, void *));
        if (p != NULL) {
            ov002_021d58b8_setInfo(self, FIELD(p, 0x6, u16));
        }
    }
    {
        void *t = func_ov000_02173610(0x1b);
        if (t != NULL) {
            if (FIELD(t, 0x3c, void *) != NULL) {
                func_ov002_021e2690(FIELD(t, 0x3c, void *), 9, 0);
            }
            func_ov000_021c95fc((u8 *)self + 0x60);
            if (FIELD(t, 0x3c, u8 *) != NULL) {
                MI_CpuCopy8((u8 *)self + 0x60, FIELD(t, 0x3c, u8 *) + 0x2c, 0x14);
            }
            ov002_021d58b8_setId(FIELD(t, 0x3c, void *), FIELD(self, 0x74, u16));
        }
    }
    if (func_ov002_isMode4()) {
        func_0203cb78(0x14000, 0, -1);
    }
    func_ov000_02173648(self);
}
}
