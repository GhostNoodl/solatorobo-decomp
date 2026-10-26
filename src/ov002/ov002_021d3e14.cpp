#include "ov002/ov002.h"

extern "C" {

extern VFunc data_ov000_021cadcc[];
extern VFunc data_ov000_021cae48[];
extern VFunc data_ov000_021cb5a8[];
extern VFunc data_ov000_021cb4a8[];
void func_ov000_02176560(void);
void func_ov000_02176590(u16 v);
void func_ov000_0215d980(void *a, s32 b, s32 c);
void func_ov000_02157c90(void *a, void *b);
void func_ov000_02157d2c(void *a, void *b);
void *func_0206ee58(u16 id);
BOOL func_ov002_021d3b10(void *self, void *ev);
BOOL func_ov002_021d3c30(void *self, void *ev);

static inline bool Ov002_Avail(u8 *blk, void *tbl, u16 i) {
    bool a = func_02059544(data_02fe152c, blk, tbl, 1, i) & 1;
    return a & (func_02059544(data_02fe152c, blk, tbl, 0x101, i) == 0);
}

void func_ov002_021d3e14(Task50 *self) {
    void *g;
    u8 *blk;
    u32 count;
    VObject *p;
    u16 i;
    u16 id;
    void *tbl;
    if (self->v0x28()) {
        return;
    }
    g = data_02149ef8;
    func_ov000_02176560();

    p = (VObject *)func_0203dd9c(0x8c);
    if (p != NULL) {
        *(VFunc **)p = data_ov000_021cac60;
        p->v0x28();
        *(VFunc **)p = data_ov000_021cadcc;
        p->v0x28();
    }
    FIELD(self, 0x40, VObject *) = p;
    FIELD(p, 0x24, s32) = 0xf8;
    FIELD(FIELD(self, 0x40, void *), 0x20, s32) = 2;
    {
        u8 *s = FIELD(self, 0x40, u8 *);
        FIELD(s, 0x64, s16) = 4;
        FIELD(s, 0x66, s16) = 0x95;
        FIELD(s, 0x68, s16) = -0x199a;
    }
    {
        u8 *s = FIELD(self, 0x40, u8 *);
        FIELD(s, 0x58, s32) = 0;
        FIELD(s, 0x5c, s32) = 0x54;
        FIELD(s, 0x60, s32) = -0x199a;
    }
    FIELD(FIELD(self, 0x40, void *), 0x2c, s32) = 1;
    FIELD(FIELD(self, 0x40, void *), 0x48, s16) = 0xb;
    func_ov000_0215bb14(FIELD(self, 0x40, void *), func_0204c0e8(g, 0xf3));
    FIELD(self, 0x40, VObject *)->v0x70();
    self->unk_4c = 1;
    FIELD(self, 0x40, VObject *)->v0x8();

    p = (VObject *)func_0203dd9c(0x98);
    if (p != NULL) {
        *(VFunc **)p = data_ov000_021cac60;
        p->v0x28();
        *(VFunc **)p = data_ov000_021cae48;
        p->v0x28();
    }
    FIELD(self, 0x44, VObject *) = p;
    FIELD(p, 0x64, s16) = 0x86;
    FIELD(p, 0x66, s16) = 0x78;
    FIELD(p, 0x68, s16) = -0x199a;
    {
        u8 *s = FIELD(self, 0x44, u8 *);
        FIELD(s, 0x58, s32) = 0x100;
        FIELD(s, 0x5c, s32) = 0;
        FIELD(s, 0x60, s32) = -0x199a;
    }
    FIELD(FIELD(self, 0x44, void *), 0x2c, s32) = 1;
    FIELD(FIELD(self, 0x44, void *), 0x84, s32) = 2;
    func_ov000_0215d980(FIELD(self, 0x44, void *), FIELD(data_0214a424, 0x614, s32), 0);
    FIELD(self, 0x44, VObject *)->v0x8();

    p = (VObject *)func_0203dd9c(0xe0);
    if (p != NULL) {
        *(VFunc **)p = data_ov000_021cac60;
        p->v0x28();
        *(VFunc **)p = data_ov000_021caec8;
        p->v0x28();
        *(VFunc **)p = data_ov000_021cb5a8;
        p->v0x28();
    }
    FIELD(self, 0x48, VObject *) = p;
    FIELD(p, 0xc, u32) |= 0x4000000;
    FIELD(FIELD(self, 0x48, void *), 0x2c, s32) = 1;
    {
        u8 *s = FIELD(self, 0x48, u8 *);
        FIELD(s, 0x64, s16) = 0;
        FIELD(s, 0x66, s16) = 0x11;
        FIELD(s, 0x68, s16) = -0x199a;
    }
    {
        u8 *s = FIELD(self, 0x48, u8 *);
        FIELD(s, 0x58, s32) = 0x100;
        FIELD(s, 0x5c, s32) = 0;
        FIELD(s, 0x60, s32) = -0x199a;
    }
    FIELD(FIELD(self, 0x48, void *), 0xc, u32) |= 0x20000000;
    FIELD(self, 0x48, VObject *)->v0xf4(1, func_0204c0e8(g, 0x32));
    FIELD(self, 0x48, VObject *)->v0xf4(2, func_0204c0e8(g, 0x33));
    FIELD(self, 0x48, VObject *)->v0x8();

    p = (VObject *)func_0203dd9c(0xe0);
    if (p != NULL) {
        *(VFunc **)p = data_ov000_021cac60;
        p->v0x28();
        *(VFunc **)p = data_ov000_021caec8;
        p->v0x28();
        *(VFunc **)p = data_ov000_021cb4a8;
        p->v0x28();
    }
    FIELD(self, 0x3c, VObject *) = p;
    FIELD(self, 0x3c, VObject *)->v0x10(func_0204c0e8(g, 0xf1));
    FIELD(self, 0x3c, VObject *)->v0x14(func_0204c0e8(g, 0xf3));
    FIELD(FIELD(self, 0x3c, void *), 0x20, s32) = 4;
    FIELD(FIELD(self, 0x3c, void *), 0x24, s32) = 0xf8;
    {
        u8 *s = FIELD(self, 0x3c, u8 *);
        FIELD(s, 0x64, s16) = 0;
        FIELD(s, 0x66, s16) = 0x2c;
        FIELD(s, 0x68, s16) = -0x199a;
    }
    {
        u8 *s = FIELD(self, 0x3c, u8 *);
        FIELD(s, 0x58, s32) = 0x100;
        FIELD(s, 0x5c, s32) = 0;
        FIELD(s, 0x60, s32) = -0x199a;
    }
    FIELD(FIELD(self, 0x3c, void *), 0x2c, s32) = 1;
    FIELD(FIELD(self, 0x3c, void *), 0xc, u32) |= 0x400000;
    FIELD(FIELD(self, 0x3c, void *), 0xc, u32) &= ~0x800000;
    FIELD(FIELD(self, 0x3c, void *), 0xc1, u8) = 5;
    FIELD(FIELD(self, 0x3c, void *), 0xc0, u8) = 0x78;
    func_ov000_02157c90(FIELD(self, 0x3c, void *), func_0204c0e8(g, 0xa2));
    func_ov000_02157d2c(FIELD(self, 0x3c, void *), func_0204c0e8(g, 0x40));
    FIELD(FIELD(self, 0x3c, void *), 0x84, void *) = (void *)func_ov002_021d3b10;
    FIELD(FIELD(self, 0x3c, void *), 0x88, void *) = (void *)func_ov002_021d3c30;
    FIELD(FIELD(self, 0x3c, void *), 0x8, void *) = self;
    func_ov000_02176590(FIELD(self, 0xc, u32));

    blk = FIELD(data_02fe152c, 0x4c, u8 *) + 0x110;
    tbl = func_0205976c(data_02fe152c, 8);
    count = func_0205975c(data_02fe152c, 8);
    for (i = 0; i < count; i++) {
        if (Ov002_Avail(blk, tbl, i)) {
            id = i | 0x4000;
            FIELD(self, 0x3c, VObject *)->v0x74(func_0206ec48(id), id, 0xffff, FIELD(func_0206ee58(id), 2, u16));
        }
    }
    {
        VObject *m = FIELD(self, 0x3c, VObject *);
        if (FIELD(m, 0x9c, s16) == 0) {
            func_ov000_0215bb14(FIELD(self, 0x40, void *), func_0204c0e8(data_02149ef8, 0x9d));
            FIELD(self, 0x40, VObject *)->v0x70();
        } else {
            m->v0xa8(func_ov000_02154b58(m, 0));
        }
    }
    FIELD(self, 0x3c, VObject *)->v0x8();
    func_ov000_02173648(self);
}

}
