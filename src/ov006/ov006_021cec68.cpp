#include "ov006/Tasks.h"

#define F(p, off, T) (*(T *)((u8 *)(p) + (off)))

typedef struct ov006_Entry021cec68 {
    u16 name;
} ov006_Entry021cec68;

typedef struct ov006_Bits8b0 {
    u8 b0 : 1;
    u8 b1 : 1;
    u8 b2 : 1;
    u8 b3 : 1;
    u8 b4 : 1;
    u8 b5 : 1;
    u8 b6 : 1;
    u8 b7 : 1;
} ov006_Bits8b0;
extern "C" {

extern void *data_02149ef8;
extern u8 *data_02097d48;
extern void *data_ov000_021cac60;
extern void *data_ov000_021caec8;
extern void *data_ov000_021cadcc;
extern void *data_ov000_021ccbe0;
extern void *data_ov000_021ccb54;
extern void *data_ov000_021cca28;
extern void *data_ov006_021ebc80;

void *func_0204c0e8(void *a, int id);
void func_02043904(void *p);
void func_02043b20(void *p);
void func_ov000_02173648(void *self);
void func_ov006_021daea0(ov006_SlotManager *a);
u8 func_ov006_021db078(ov006_SlotManager *self);
void func_ov006_021d8f44(void);
ov006_Entry021cec68 *func_ov006_021d8f20(u32 id);
void func_ov000_021546ec(void *w, const char *a, const char *b, int c);
void func_ov000_021c3af4(void *self);
void func_ov000_021c54f4(void *self);
void func_ov000_021c55e8(void *self, const void *s);
void func_ov000_021c22d8(void *self);
void func_ov000_021c5fc4(void *self);
void func_ov000_021c5fd0(void *self, const void *s);
void func_ov000_021c3fd4(void *list, void *item);
void *func_ov006_021e29c4(void *self);
void func_ov006_021e2c14(void *self);
void func_ov006_021e341c(void *self, const void *s);
void func_ov006_021e34d8(void *self, const void *s, int idx);
BOOL func_ov006_021ce734(ov006_TaskOwner *owner, ov006_ListNode *arg);
BOOL func_ov006_021ce954(ov006_TaskOwner *owner, ov006_ListNode *arg);
}

extern "C" const char data_ov006_021ebbec[];
extern "C" const char data_ov006_021ebbf5[];

extern "C" {

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

static inline void *ov006_NewList_ccb54(void) {
    void *w = func_0203dd9c(0x100);
    if (w != NULL) {
        *(void **)w = &data_ov000_021cac60;
        VCALL(w, 28);
        *(void **)w = &data_ov000_021ccbe0;
        func_ov000_021c3af4(w);
        *(void **)w = &data_ov000_021ccb54;
        func_ov000_021c54f4(w);
    }
    return w;
}

static inline void *ov006_NewItem_cca28(void) {
    void *w = func_0203dd9c(0x34);
    if (w != NULL) {
        *(void **)w = &data_ov006_021ebc80;
        func_ov000_021c22d8(w);
        *(void **)w = &data_ov000_021cca28;
        func_ov000_021c5fc4(w);
    }
    return w;
}

static inline u8 ov006_SlotManager_Get14A(ov006_SlotManager *self, u8 i) {
    if (i < 3) {
        return self->unk14A[i];
    }
    return 0;
}

// n and res are locals. Declaring them as parameters gives the target register allocation.
void func_ov006_021cec68(ov006_TaskCE *self, u8 n, void *res) {
    u8 i;
    u8 k;
    ov006_Entry021cec68 *e;
    void *item;
    u8 *g;
    if (VCALL(self, 28)) {
        return;
    }
    {
        g = data_02097d48;
        func_02043904(g + 0x8b0);
        ((ov006_Bits8b0 *)(g + 0x8b0))->b4 = 1;
        ((ov006_Bits8b0 *)(g + 0x8b0))->b5 = 1;
        *(vu16 *)0x4000060 = (*(vu16 *)0x4000060 & ~0x3000) | 0x20;
        func_02043b20(g + 0x8b0);
    }
    self->base.flags &= ~2;
    func_ov006_021daea0(data_ov006_021ec884);
    self->base.unk20 = 0x19000;
    VCALL(self, 3C);
    res = data_02149ef8;
    self->unk44 = ov006_NewWindow_caec8();
    VCALL(self->unk44, 10, func_0204c0e8(res, 0x122));
    VCALL(self->unk44, 14, func_0204c0e8(res, 0x123));
    self->unk44->unk4A = 0x2c00;
    self->unk44->unk24 = 0xac;
    self->unk44->unk20 = 4;
    ov006_Window_SetRot(self->unk44, 0, 0x1e, -0x2000);
    ov006_Window_SetPos(self->unk44, 0, -0x100, -0x2000);
    self->unk44->unk2C = 1;
    self->unk44->flags &= ~0x400000;
    self->unk44->flags &= ~0x800000;
    self->unk44->flags &= ~0x20000;
    self->unk44->flags &= ~0x80000;
    self->unk44->flags &= ~0x40000;
    self->unk44->flags &= ~0x10000;
    func_ov000_021546ec(self->unk44, (char *)data_ov006_021ebbec, (char *)data_ov006_021ebbf5, 0xffff);
    VCALL(self->unk44, 74, func_0204c0e8(res, 0x124), 0, 0xffff, 0xffff);
    VCALL(self->unk44, 74, func_0204c0e8(res, 0x126), 1, 0, 0xffff);
    VCALL(self->unk44, 74, func_0204c0e8(res, 0x140), 2, 0xffff, 0xffff);
    VCALL(self->unk44, 74, func_0204c0e8(res, 0x142), 3, 0xffff, 0xffff);
    VCALL(self->unk44, 74, func_0204c0e8(res, 0x144), 4, 0xffff, 0xffff);
    VCALL(self->unk44, 74, func_0204c0e8(res, 0x146), 5, 0xffff, 0xffff);
    {
        ov006_Window *w = self->unk44;
        VCALL(w, A8, func_ov000_02154b58(w, 0));
    }
    self->unk44->unk84 = (ov006_WindowFunc)func_ov006_021ce734;
    self->unk44->unk88 = (ov006_WindowFunc)func_ov006_021ce954;
    self->unk44->owner = self;
    VCALL(self->unk44, 08);
    self->unk48 = ov006_NewWindow_cadcc();
    self->unk48->unk24 = 0xf8;
    self->unk48->unk20 = 2;
    ov006_Window_SetRot(self->unk48, 4, 0x95, -0x2000);
    ov006_Window_SetPos(self->unk48, -0x100, 0, -0x2000);
    self->unk48->unk2C = 1;
    VCALL(self->unk48, 08);
    self->unk48->flags |= 4;
    ov006_TaskCE_ShowMenus(self);
    func_ov006_021d8f44();
    n = func_ov006_021db078(data_ov006_021ec884);
    if (n != 0) {
        if (data_ov006_021ec884->unk149 == 0) {
            self->unk50 = (ov006_Window *)ov006_NewList_ccb54();
            func_ov000_021c55e8(self->unk50, func_0204c0e8(res, 0x183));
            if (n == 1) {
                n = 2;
            }
            self->unk50->unk20 = n;
            self->unk50->unk24 = 0xc0;
            ov006_Window_SetRot(self->unk50, 0x20, 0x3c, -0x1ccd);
            for (i = 0; i < 3; i++) {
                e = func_ov006_021d8f20(ov006_SlotManager_Get14A(data_ov006_021ec884, i));
                if (e != NULL) {
                    item = ov006_NewItem_cca28();
                    func_ov000_021c5fd0(item, func_0204c0e8(res, e->name));
                    func_ov000_021c3fd4(self->unk50, item);
                }
            }
            self->unk50->flags &= ~0x40000;
            F(self->unk50, 0xf0, u8) = 0;
            self->unk50->flags |= 4;
            VCALL(self->unk50, 08);
            self->unk50->flags |= 2;
        }
        {
            void *p = func_0203dd9c(0x24);
            if (p != NULL) {
                p = func_ov006_021e29c4(p);
            }
            self->unk54 = (Object *)p;
        }
        func_ov006_021e2c14(self->unk54);
        func_ov006_021e341c(self->unk54, func_0204c0e8(res, 0x183));
        {
            k = 0;
            for (i = 0; i < 3; i++) {
                e = func_ov006_021d8f20(ov006_SlotManager_Get14A(data_ov006_021ec884, i));
                if (e != NULL) {
                    func_ov006_021e34d8(self->unk54, func_0204c0e8(res, e->name), k);
                    k++;
                }
            }
        }
    }
    data_ov006_021ec884->unk149 = 1;
    self->base.state = 0;
    self->base.subState = 0;
    func_0203cb78(0x14000, 0, 0);
    func_0203cb78(0x14000, 0, 1);
    func_ov000_02173648(self);
}

}
