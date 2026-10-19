#include "ov002/ov002.h"

extern "C" {

extern VFunc data_ov000_021cb5a8[];
extern VFunc data_ov000_021ccadc[];
extern VFunc data_ov000_021cca58[];
void *func_02035d8c(void *a, void *b);
void func_ov002_021e4814(void *self, u8 *src);
void func_ov002_021e4a78(void *self, u8 *src);
s32 func_ov002_021e4bd0(void *self, u32 idx);
s32 func_ov002_021e4c00(void *self, u32 idx);
void func_ov000_021c22d8(void *self);
void func_ov000_021c37bc(void *self);
void func_ov000_021c6140(void *self);
void func_ov000_021c6474(void *list, void *item);

static inline bool ov002_IsActive(void *p) {
    return FIELD(p, 0x28, s32) != 1 ? 0 : FIELD(p, 0x30, s32);
}

static inline bool ov002_HasActive(void *t) {
    void *p = FIELD(t, 0x118, void *);
    if (p == NULL) {
        return false;
    }
    return ov002_IsActive(p) != 0;
}

void func_ov002_021d2fdc(void *self) {
    VObject *p;
    void *g;
    u32 i;
    FIELD(self, 0x4, u32) &= ~2;
    if (((VObject *)self)->v0x28()) {
        return;
    }
    g = data_02149ef8;
    func_ov002_021e4814((u8 *)self + 0x94, *(u8 **)func_02035d8c((u8 *)self + 0x44, (u8 *)self + 0x7c));
    func_ov002_021e4a78((u8 *)self + 0xac, *(u8 **)func_02035d8c((u8 *)self + 0x44, (u8 *)self + 0x64));
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
        FIELD(s, 0x58, s32) = 0x100;
        FIELD(s, 0x5c, s32) = 0;
        FIELD(s, 0x60, s32) = 0;
    }
    {
        u8 *s = FIELD(self, 0x40, u8 *);
        FIELD(s, 0x64, s16) = 0;
        FIELD(s, 0x66, s16) = 0;
        FIELD(s, 0x68, s16) = -0x199a;
    }
    FIELD(FIELD(self, 0x40, void *), 0xc, u32) |= 0x20000000;
    FIELD(FIELD(self, 0x40, void *), 0xc, u32) |= 0x80000000;
    FIELD(self, 0x40, VObject *)->v0xf4(2, func_0204c0e8(g, 0x33));
    FIELD(self, 0x40, VObject *)->v0x8();
    {
        p = (VObject *)func_0203dd9c(0xd4);
        if (p != NULL) {
            *(VFunc **)p = data_ov000_021cac60;
            p->v0x28();
            *(VFunc **)p = data_ov000_021ccadc;
            func_ov000_021c6140(p);
        }
        FIELD(self, 0x3c, VObject *) = p;
        p->v0x10(FIELD(self, 0xa4, void *));
    }
    FIELD(self, 0x3c, VObject *)->v0x14(FIELD(self, 0xa8, void *));
    FIELD(FIELD(self, 0x3c, void *), 0x68, s16) = -0x199a;
    FIELD(FIELD(self, 0x3c, void *), 0xc4, u32) &= ~2;
    FIELD(FIELD(self, 0x3c, void *), 0xc4, u32) &= ~1;
    for (i = 0; i < FIELD(self, 0xc0, u32); i++) {
        u8 *q = (u8 *)func_0203dd9c(0x44);
        if (q != NULL) {
            *(VFunc **)q = data_ov002_021ef684;
            func_ov000_021c22d8(q);
            *(VFunc **)q = data_ov000_021cca58;
            func_ov000_021c37bc(q);
        }
        FIELD(q, 0x38, s32) = func_ov002_021e4bd0((u8 *)self + 0xac, i);
        FIELD(q, 0x34, s32) = func_ov002_021e4c00((u8 *)self + 0xac, i);
        func_ov000_021c6474(FIELD(self, 0x3c, void *), q);
    }
    FIELD(self, 0x3c, VObject *)->v0x8();
    func_ov000_02173648(self);
    {
        void *t = data_ov000_021ccd30;
        if (t != NULL) {
            if (ov002_HasActive(t) && FIELD(t, 0x118, void *) != NULL) {
                func_ov000_0216f844((void *)*(volatile u32 *)((u8 *)t + 0x118), 0);
            }
        }
    }
}

}
