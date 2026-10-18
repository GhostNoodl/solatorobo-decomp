#include "ov002/ov002.h"

extern "C" {

typedef struct Fn021def98 {
    s32 (*fn)(void *, void *);
    u32 pad;
} Fn021def98;

typedef struct Id021def98 {
    u16 id;
    u8 pad[6];
} Id021def98;

extern Fn021def98 data_ov002_021eef8c[];
extern Id021def98 data_ov002_021eef90[];
extern VFunc data_ov002_021f0044[];

void func_ov000_021c3af4(void *self);
void func_ov000_021c22d8(void *self);
void func_ov002_021e2f54(void *self);
void func_ov000_021c3fd4(void *list, void *item);
BOOL func_ov002_021ddcbc(void *self, void *ev);
BOOL func_ov002_021ddd30(void *self, void *ev);
void func_ov002_021e34fc(void *self, s32 (*cmp)(void *, void *));

void *func_ov002_021def98(void *self, u32 kind) {
    u16 id;
    s32 n;
    s32 j;
    VObject *p;
    VObject *q;
    s32 i;
    u8 *counts;
    p = (VObject *)func_0203dd9c(0xf4);
    if (p != NULL) {
        *(VFunc **)p = data_ov000_021cac60;
        p->v0x28();
        *(VFunc **)p = data_ov000_021ccbe0;
        func_ov000_021c3af4(p);
        *(VFunc **)p = data_ov002_021f0044;
    }
    FIELD(p, 0x20, s32) = 6;
    FIELD(p, 0x24, s32) = 0x8c;
    FIELD(p, 0x64, s16) = 0x73;
    FIELD(p, 0x66, s16) = 0x19;
    FIELD(p, 0x68, s16) = -0x199a;
    counts = FIELD(FIELD(self, 0x4, u8 *), 0x4, u8 *) + 8;
    for (i = 0; i < 100; i++) {
        id = i | 0x2000;
        u8 t = func_0206ede8(id)[0];
        if (t == kind) {
            n = counts[i];
            for (j = 0; j < n; j++) {
                q = (VObject *)func_0203dd9c(0x4c);
                if (q != NULL) {
                    *(VFunc **)q = data_ov002_021ef684;
                    func_ov000_021c22d8(q);
                    *(VFunc **)q = data_ov002_021f002c;
                    func_ov002_021e2f54(q);
                }
                FIELD(q, 0x38, u16) = id;
                FIELD(q, 0x3c, void *) = func_0206ec48(id);
                FIELD(q, 0x45, u8) = 1;
                func_ov000_021c3fd4(p, q);
            }
        }
    }
    FIELD(p, 0x8, void *) = (u8 *)self + 0x22;
    FIELD(p, 0xe4, void *) = (void *)func_ov002_021ddcbc;
    FIELD(p, 0xe8, void *) = (void *)func_ov002_021ddd30;
    p->v0x8();
    FIELD(p, 0x58, s32) = 0x100;
    FIELD(p, 0x5c, s32) = 0;
    FIELD(p, 0x60, s32) = -0x199a;
    FIELD(p, 0x2c, s32) = 1;
    FIELD(p, 0xc, u32) = ((FIELD(p, 0xc, u32) | 2) & ~4) | 0x10;
    {
        s32 k = FIELD(self, 0x34, s32);
        void *r;
        u8 *w;
        func_ov002_021e34fc(p, data_ov002_021eef8c[k].fn);
        r = func_0204c0e8(data_02149ef8, data_ov002_021eef90[k].id);
        w = FIELD(self, 0x4, u8 *);
        func_ov000_0215bb14(FIELD(w, 0x20, void *), r);
        FIELD(w, 0x20, VObject *)->v0x70();
    }
    return p;
}

}
