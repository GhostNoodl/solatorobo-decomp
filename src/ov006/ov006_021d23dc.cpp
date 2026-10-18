#include "ov006/Tasks.h"

#define F(p, off, T) (*(T *)((u8 *)(p) + (off)))

typedef struct ov006_Unk020706a0 {
    u8 unk0[4];
    s8 unk4;
    s8 unk5;
    s8 unk6;
    s8 unk7;
} ov006_Unk020706a0;

extern "C" {

extern void *data_02149ef8;
extern u8 *data_02097d48;
extern void *data_ov000_021cac60;
extern void *data_ov000_021caec8;
extern void *data_ov000_021cadcc;
extern void *data_ov000_021cb1b0;
extern void *data_ov000_021cb0b8;
extern void *data_ov000_021cad50;
extern const u8 data_ov006_021eb6fe[];
extern const u16 data_ov006_021eb78c[];
extern const u8 data_ov006_021eb71c[];
extern const u8 data_ov006_021eb728[];
extern const u8 data_ov006_021eb770[];
extern const u8 data_ov006_021eb740[];

void *func_0204c0e8(void *a, int id);
void func_ov006_021cd580(int a, void *b, int c);
void func_ov000_021548cc(void *a, int b);
void *func_ov000_02154b80(void *a, int b);
void *func_ov000_02162124(void *p);
void func_ov000_021627ac(void *p);
void func_ov000_02162910(void *p, const void *a, const void *b, const void *c);
void func_ov000_0216295c(void *p, const void *v, int s);
void func_ov000_0215c1bc(void *a, int b, const void *c);
void func_ov000_0215bb14(void *a, const void *b);
void *func_ov006_021e07b0(void *p);
void func_ov006_021e0954(void *p);
void func_ov006_021e0ca8(void *p, void *a, int b);
void *func_ov006_021e0d64(void *p);
void func_ov006_021e0f00(void *p);
void func_ov006_021e13c8(void *p, void *s);
void func_ov006_021e139c(ov006_Unk021e139c *self, int a, int b, u8 c);
void func_ov006_021dabcc(ov006_Slot *self, void *buf);
void func_ov006_021e4a80(ov006_Unk021ec888 *self, u16 a, int b, const void *src, u32 size);
void func_ov006_021d3498(ov006_TaskD1F *self, u16 id, BOOL dir);
ov006_Unk020706a0 *func_020706a0(u16 id);
void func_02043904(void *p);
void func_02043b20(void *p);
void func_ov000_02173648(void *self);
BOOL func_ov006_021d1df8(ov006_Window *window, ov006_ListNode *node);
BOOL func_ov006_021d1f00(ov006_Window *window, ov006_ListNode *node);

static inline ov006_Window *ov006_NewWindow_caec8(void) {
    ov006_Window *w = (ov006_Window *)func_0203dd9c(0xd4);
    if (w != NULL) {
        w->vtbl = &data_ov000_021cac60;
        VCALL(w, 28);
        w->vtbl = &data_ov000_021caec8;
        VCALL(w, 28);
    }
    return w;
}

static inline ov006_Window *ov006_NewWindow_cadcc(void) {
    ov006_Window *w = (ov006_Window *)func_0203dd9c(0x8c);
    if (w != NULL) {
        w->vtbl = &data_ov000_021cac60;
        VCALL(w, 28);
        w->vtbl = &data_ov000_021cadcc;
        VCALL(w, 28);
    }
    return w;
}

static inline ov006_Window *ov006_NewWindow_cb0b8(void) {
    ov006_Window *w = (ov006_Window *)func_0203dd9c(0x1e4);
    if (w != NULL) {
        w->vtbl = &data_ov000_021cac60;
        VCALL(w, 28);
        w->vtbl = &data_ov000_021caec8;
        VCALL(w, 28);
        w->vtbl = &data_ov000_021cb1b0;
        VCALL(w, 28);
        w->vtbl = &data_ov000_021cb0b8;
        VCALL(w, 28);
    }
    return w;
}

static inline ov006_Window *ov006_NewWindow_cad50(void) {
    ov006_Window *w = (ov006_Window *)func_0203dd9c(0xe8);
    if (w != NULL) {
        w->vtbl = &data_ov000_021cac60;
        VCALL(w, 28);
        w->vtbl = &data_ov000_021cad50;
        VCALL(w, 28);
    }
    return w;
}

static inline void ov006_SetPair(void *p, int off, int x, int y) {
    F(p, off, int) = x;
    F(p, off + 4, int) = y;
}

static inline void ov006_SetPair2(void *p, int x, int y) {
    F(p, 0x10, int) = x;
    F(p, 0x14, int) = y;
}

static inline void ov006_Gauge_SetPos(void *g, int x, int y) {
    F(g, 0x14, int) = x;
    F(g, 0x18, int) = y;
}

void func_ov006_021d23dc(ov006_TaskD1F *self) {
    int y;
    int i;
    void *res;
    if (VCALL(self, 28)) {
        return;
    }
    res = data_02149ef8;
    self->unk54 = ov006_NewWindow_caec8();
    VCALL(self->unk54, 10, func_0204c0e8(res, 0x128));
    VCALL(self->unk54, 14, func_0204c0e8(res, 0x129));
    self->unk54->unk4A = 0x2c00;
    self->unk54->unk20 = 4;
    self->unk54->unk24 = 0x8c;
    ov006_Window_SetRot(self->unk54, 0, 0x1e, -0x199a);
    self->unk54->unk68 = -0x199a;
    ov006_Window_SetPos(self->unk54, -0xff, 0, -0x199a);
    self->unk54->flags &= ~0x400000;
    self->unk54->flags &= ~0x80000;
    self->unk54->flags |= 0x40000;
    self->unk54->flags &= ~0x800000;
    self->unk54->flags |= 0x10000;
    func_ov006_021cd580(3, self->unk54, 0);
    VCALL(self->unk54, 08);
    func_ov000_021548cc(self->unk54, data_ov006_021eb6fe[data_ov006_021ec884->unk5]);
    if (self->unk4A != 0xffff) {
        ov006_Window *w = self->unk54;
        VCALL(w, A8, func_ov000_02154b58(w, self->unk4A));
    } else {
        VCALL(self->unk54, A8, func_ov000_02154b80(self->unk54, 0));
    }
    self->unk54->owner = self;
    self->unk54->unk88 = func_ov006_021d1df8;
    {
        void *p = func_0203dd9c(0x708);
        if (p != NULL) {
            p = func_ov000_02162124(p);
        }
        self->unk58 = (ov006_Actor58 *)p;
    }
    func_ov000_021627ac(self->unk58);
    func_ov000_02162910(self->unk58, data_ov006_021eb71c, data_ov006_021eb728, data_ov006_021eb770);
    func_ov000_0216295c(self->unk58, data_ov006_021eb740, 0x3d7);
    self->unk5C = ov006_NewWindow_cadcc();
    self->unk5C->unk24 = 0xf8;
    self->unk5C->unk20 = 2;
    ov006_Window_SetRot(self->unk5C, 4, 0x95, -0x199a);
    ov006_Window_SetPos(self->unk5C, -0x100, 0, -0x199a);
    self->unk5C->unk2C = 1;
    VCALL(self->unk5C, 08);
    self->unk60 = ov006_NewWindow_cb0b8();
    F(self->unk60, 0x1d8, u16) = 0x12c;
    F(self->unk60, 0x1dc, void *) = func_0204c0e8(res, 0x18);
    F(self->unk60, 0x1e0, u16) = 1;
    self->unk60->unk84 = func_ov006_021d1f00;
    self->unk60->owner = &self->unk4C;
    VCALL(self->unk60, 08);
    self->unk60->unk68 = -0x1666;
    self->unk60->flags |= 2;
    self->unk64 = ov006_NewWindow_cad50();
    func_ov000_0215c1bc(self->unk64, 0x74, func_0204c0e8(res, 0x139));
    self->unk64->flags |= 0x10000;
    self->unk64->flags &= ~0x20000;
    self->unk64->flags |= 2;
    {
        void *p = func_0203dd9c(0x2c);
        if (p != NULL) {
            p = func_ov006_021e07b0(p);
        }
        self->unk68 = (ov006_Unk68 *)p;
    }
    F(self->unk68, 0x20, int) = 1;
    func_ov006_021e0954(self->unk68);
    func_ov006_021e0ca8(self->unk68, func_0204c0e8(res, 0x128), 4);
    ov006_SetPair(self->unk68, 0x8, -0xa0, -0x61);
    ov006_SetPair2(self->unk68, 0xf, 0);
    F(self->unk68, 0x1c, int) = -0x1e;
    y = -0x3e;
    for (i = 0; i < 4; i++) {
        void *p = func_0203dd9c(0x24);
        if (p != NULL) {
            p = func_ov006_021e0d64(p);
        }
        self->gauges[i] = (ov006_Unk021e139c *)p;
        func_ov006_021e0f00(self->gauges[i]);
        ov006_Gauge_SetPos(self->gauges[i], -0x50, y);
        y += 0x20;
        F(self->gauges[i], 0x10, int) = i;
    }
    func_ov006_021e13c8(self->gauges[0], func_0204c0e8(res, 0x13a));
    func_ov006_021e13c8(self->gauges[1], func_0204c0e8(res, 0x13b));
    func_ov006_021e13c8(self->gauges[2], func_0204c0e8(res, 0x13c));
    func_ov006_021e13c8(self->gauges[3], func_0204c0e8(res, 0x13e));
    {
        u8 buf[0x18];
        func_ov006_021dabcc(func_ov006_021db060(data_ov006_021ec884, data_ov006_021ec884->unk5), buf);
        func_ov006_021e4a80(data_ov006_021ec888, self->unk49, 1, buf, 0x18);
    }
    if (self->base.unkC != 0) {
        self->unk48 = 0;
    }
    {
        u8 *g = data_02097d48;
        func_02043904(g + 0x8b0);
        g[0x8b0] |= 0x30;
        *(vu16 *)0x4000060 = (*(vu16 *)0x4000060 & ~0x3000) | 0x20;
        func_02043b20(g + 0x8b0);
    }
    if (F(self->unk54, 0x94, void *) != NULL) {
        ov006_ListNode *node = ov006_Window_GetSelected(self->unk54);
        u16 id = node->id;
        const void *str;
        ov006_Unk020706a0 *p;
        self->unk4A = id;
        str = func_0204c0e8(data_02149ef8, data_ov006_021eb78c[(u16)(id & 0xfff)]);
        if (self->unk5C != NULL && str != NULL) {
            func_ov000_0215bb14(self->unk5C, str);
            VCALL(self->unk5C, 70);
        }
        func_ov006_021d3498(self, id, FALSE);
        p = func_020706a0(id);
        func_ov006_021e139c(self->gauges[0], p->unk4 << 12, 0xa000, 1);
        func_ov006_021e139c(self->gauges[1], p->unk5 << 12, 0xa000, 1);
        func_ov006_021e139c(self->gauges[2], p->unk6 << 12, 0xa000, 1);
        func_ov006_021e139c(self->gauges[3], p->unk7 << 12, 0xa000, 1);
    }
    self->base.unk20 += self->unk54->unk34;
    self->base.flags &= ~2;
    func_ov000_02173648(self);
    func_0203cb78(0x14000, 0, 0);
    func_0203cb78(0x14000, 0, 1);
}

}
