#include "ov002/ov002.h"

extern "C" {

extern VFunc data_ov000_021cb5a8[];
extern VFunc data_ov000_021cca10[];
void func_ov000_021c3af4(void *self);
void func_ov000_021c22d8(void *self);
void func_ov000_021c2334(void *self);
void func_ov000_021c2a88(void *self, void *a);
void func_ov000_021c3fd4(void *list, void *item);
void func_ov000_021c403c(void *list, s32 a);
BOOL func_ov002_021d0a80(void *self, void *arg);

typedef struct {
    u16 a;
    u16 b;
} Pair021d0b98;

void func_ov002_021d0b98(Task50 *self) {
    void *g = data_02149ef8;
    VObject *p;
    {
        p = (VObject *)func_0203dd9c(0xf4);
        if (p != NULL) {
            *(VFunc **)p = data_ov000_021cac60;
            p->v0x28();
            *(VFunc **)p = data_ov000_021ccbe0;
            func_ov000_021c3af4(p);
        }
        FIELD(self, 0x3c, VObject *) = p;
        FIELD(p, 0x20, s32) = 7;
    }
    FIELD(FIELD(self, 0x3c, void *), 0x24, s32) = 0xf9;
    {
        u8 *s = FIELD(self, 0x3c, u8 *);
        FIELD(s, 0x64, s16) = 4;
        FIELD(s, 0x66, s16) = 0x23;
        FIELD(s, 0x68, s16) = -0x199a;
    }
    FIELD(self, 0x3c, VObject *)->v0x10(func_0204c0e8(g, 0xeb));
    FIELD(self, 0x3c, VObject *)->v0x14(func_0204c0e8(g, 0xed));
    FIELD(FIELD(self, 0x3c, void *), 0xe4, void *) = (void *)func_ov002_021d0a80;
    {
        u16 i;
        u8 *base;
        void *tbl;
        u16 id;
        u8 *q;
        u32 count;
        base = FIELD(data_02fe152c, 0x4c, u8 *) + 0x10 + 9 * 0x20;
        tbl = func_0205976c(data_02fe152c, 9);
        count = func_0205975c(data_02fe152c, 9);
        for (i = 0; i < count; i++) {
            if (func_02059544(data_02fe152c, base, tbl, 0x101, i)) {
                q = (u8 *)func_0203dd9c(0x48);
                if (q != NULL) {
                    *(VFunc **)q = data_ov002_021ef684;
                    func_ov000_021c22d8(q);
                    *(VFunc **)q = data_ov000_021cca10;
                    func_ov000_021c2334(q);
                }
                FIELD(q, 0x4, s32) = i;
                FIELD(q, 0x3c, s32) = (u16)(i + 1);
                id = ((Pair021d0b98 *)func_0205976c(data_02fe152c, 9))[i].b | 0x5000;
                func_ov000_021c2a88(q, func_0206ec48(id));
                FIELD(q, 0x8, s32) = id;
                func_ov000_021c3fd4(FIELD(self, 0x3c, void *), q);
            }
        }
    }
    FIELD(FIELD(self, 0x3c, void *), 0x8, void *) = self;
    FIELD(self, 0x3c, VObject *)->v0x8();
    func_ov000_021c403c(FIELD(self, 0x3c, void *), data_ov002_021f0f84[1]);
    FIELD(FIELD(self, 0x3c, void *), 0xc, u32) &= ~2;
    {
        p = (VObject *)func_0203dd9c(0xe0);
        if (p != NULL) {
            *(VFunc **)p = data_ov000_021cac60;
            p->v0x28();
            *(VFunc **)p = data_ov000_021caec8;
            p->v0x28();
            *(VFunc **)p = data_ov000_021cb5a8;
            p->v0x28();
        }
        FIELD(self, 0x40, VObject *) = p;
        FIELD(p, 0xc, u32) |= 0x4000000;
    }
    FIELD(FIELD(self, 0x40, void *), 0x2c, s32) = 1;
    {
        u8 *s = FIELD(self, 0x40, u8 *);
        FIELD(s, 0x58, s32) = -0x200;
        FIELD(s, 0x5c, s32) = 0;
        FIELD(s, 0x60, s32) = -0x199a;
    }
    FIELD(FIELD(self, 0x40, void *), 0xc, u32) |= 0x20000000;
    FIELD(FIELD(self, 0x40, void *), 0xc, u32) |= 0x80000000;
    FIELD(self, 0x40, VObject *)->v0xf4(1, func_0204c0e8(g, 0x39));
    FIELD(self, 0x40, VObject *)->v0xf4(2, func_0204c0e8(g, 0x33));
    FIELD(self, 0x40, VObject *)->v0x8();
    FIELD(FIELD(self, 0x40, void *), 0xc, u32) &= ~2;
}

}
