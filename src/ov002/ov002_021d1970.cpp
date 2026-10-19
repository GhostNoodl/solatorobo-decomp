#include "ov002/ov002.h"

extern "C" {

extern VFunc data_ov000_021cb5a8[];
extern VFunc data_ov000_021ccadc[];
extern VFunc data_ov000_021cca70[];
extern VFunc data_ov002_021ef674[];
void func_ov000_021c6140(void *self);
void func_ov000_021c22d8(void *self);
void func_ov000_021c2208(void *self);
void func_ov000_021c2f10(void *self);
void func_ov000_021c308c(void *self, u16 id);
void func_ov000_021c6474(void *list, void *item);
void func_ov000_021c65e0(void *list, s32 a);
BOOL func_0206f788(u16 id);
void func_0206eed0(u16 id);
BOOL func_ov002_021d18d4(void *self, void *arg);
BOOL func_ov002_021d18e8(void *self, void *ev);

typedef struct {
    u16 a;
    u16 b;
} Pair021d1970;

void func_ov002_021d1970(void *self) {
    void *g;
    VObject *p;
    FIELD(self, 0x4, u32) &= ~2;
    if (((VObject *)self)->v0x28()) {
        return;
    }
    g = data_02149ef8;
    p = (VObject *)func_0203dd9c(0xd4);
    if (p != NULL) {
        *(VFunc **)p = data_ov000_021cac60;
        p->v0x28();
        *(VFunc **)p = data_ov000_021ccadc;
        func_ov000_021c6140(p);
    }
    FIELD(self, 0x3c, VObject *) = p;
    FIELD(self, 0x3c, VObject *)->v0x10(func_0204c0e8(g, 0xee));
    FIELD(self, 0x3c, VObject *)->v0x14(func_0204c0e8(g, 0xf0));
    FIELD(FIELD(self, 0x3c, void *), 0x68, s16) = -0x199a;
    FIELD(FIELD(self, 0x3c, void *), 0xc4, u32) |= 2;
    FIELD(FIELD(self, 0x3c, void *), 0xc4, BitWord).flag0 = 1;
    FIELD(FIELD(self, 0x3c, void *), 0xa4, s32) = 0xf0;
    {
        u16 i;
        u16 id;
        u8 *q;
        Pair021d1970 *tbl;
        u32 count;
        tbl = (Pair021d1970 *)func_0205976c(data_02fe152c, 11);
        count = func_0205975c(data_02fe152c, 11);
        for (i = 0; i < count; i++) {
            id = tbl[i].b;
            if (func_0206f788(id)) {
                func_0206eed0(id);
                q = (u8 *)func_0203dd9c(0x7c);
                if (q != NULL) {
                    *(VFunc **)q = data_ov002_021ef684;
                    func_ov000_021c22d8(q);
                    *(VFunc **)q = data_ov000_021cca70;
                    *(VFunc **)(q + 0x48) = data_ov002_021ef674;
                    func_ov000_021c2208(q + 0x48);
                    func_ov000_021c2f10(q);
                }
                FIELD(q, 0x4, s32) = ((u32)tbl[i].b << 4) >> 16;
                func_ov000_021c308c(q, id);
                FIELD(q, 0x44, s32) = i + 1;
                FIELD(q, 0x40, void *) = func_0206ec48(id);
                func_ov000_021c6474(FIELD(self, 0x3c, void *), q);
            }
        }
    }
    FIELD(FIELD(self, 0x3c, void *), 0xcc, void *) = (void *)func_ov002_021d18d4;
    FIELD(FIELD(self, 0x3c, void *), 0xc8, void *) = (void *)func_ov002_021d18e8;
    FIELD(FIELD(self, 0x3c, void *), 0x8, void *) = self;
    FIELD(self, 0x3c, VObject *)->v0x8();
    func_ov000_021c65e0(FIELD(self, 0x3c, void *), data_ov002_021f0f84[2]);
    func_ov000_021c64b4(FIELD(self, 0x3c, void *), FIELD(FIELD(FIELD(self, 0x3c, void *), 0x88, void *), 0x40, void *));
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
    FIELD(FIELD(self, 0x40, void *), 0x2c, s32) = 1;
    FIELD(FIELD(self, 0x40, void *), 0x68, s16) = -0x199a;
    {
        u8 *s = FIELD(self, 0x40, u8 *);
        FIELD(s, 0x58, s32) = 0x100;
        FIELD(s, 0x5c, s32) = 0;
        FIELD(s, 0x60, s32) = -0x199a;
    }
    FIELD(FIELD(self, 0x40, void *), 0xc, u32) |= 0x20000000;
    FIELD(FIELD(self, 0x40, void *), 0xc, u32) |= 0x80000000;
    FIELD(self, 0x40, VObject *)->v0xf4(1, func_0204c0e8(g, 0x34));
    FIELD(self, 0x40, VObject *)->v0xf4(2, func_0204c0e8(g, 0x33));
    FIELD(self, 0x40, VObject *)->v0x8();
    FIELD(self, 0x5c, s32) = -0x100;
    FIELD(self, 0x50, s32) = 0;
    FIELD(self, 0x54, s32) = 0;
    FIELD(self, 0x60, s32) = 0;
    FIELD(self, 0x58, s32) = -0x199a;
    FIELD(self, 0x64, s32) = -0x199a;
    func_ov000_02173648(self);
}

}
