#include "ov006/Tasks.h"
#include "ov006/SlotManager.h"

typedef struct ov006_Price021da208 {
    u16 unk0;
    u16 unk2;
} ov006_Price021da208;

typedef struct ov006_Entry021da208 {
    void *vtbl;
    u8 unk4[0x10];
    int unk14;
    u8 unk18[0x20];
    void *unk38;
    u16 unk3C;
    int unk40;
} ov006_Entry021da208;

typedef struct ov006_List021da208 {
    void *vtbl;
    int state;
    void *owner;
    u32 flags;
    u8 unk10[0x10];
    int unk20;
    int unk24;
    u8 unk28[0x30];
    int unk58;
    int unk5C;
    int unk60;
    s16 unk64;
    s16 unk66;
    s16 unk68;
    u8 unk6A[0x86];
    u8 unkF0;
} ov006_List021da208;

typedef struct ov006_Menu021da208 {
    void *vtbl;
    int state;
    void *owner;
    u32 flags;
    u8 unk10[0x58];
    s16 unk68;
    u8 unk6A[0x1a];
    void *unk84;
    u8 unk88[0x150];
    s16 unk1D8;
    u8 unk1DA[2];
    void *unk1DC;
    s16 unk1E0;
} ov006_Menu021da208;

typedef struct ov006_Task021da208 {
    void *vtbl;
    u32 flags;
    int unk8;
    int unkC;
    ov006_Window *unk10;
    ov006_List021da208 *unk14;
    ov006_Window *unk18;
    ov006_Window *unk1C;
    ov006_Window *unk20;
    ov006_Window *unk24;
    ov006_Menu021da208 *unk28;
    u8 unk2C[0xc];
    int unk38;
} ov006_Task021da208;

extern "C" {

extern void *data_02149ef8;
extern void *data_ov000_021cac60;
extern void *data_ov000_021cad50;
extern void *data_ov000_021cae48;
extern void *data_ov000_021caec8;
extern void *data_ov000_021cb4a8;
extern void *data_ov000_021cb5a8;
extern void *data_ov000_021cb1b0;
extern void *data_ov000_021cb0b8;
extern void *data_ov000_021ccbe0;
extern void *data_ov000_021ccb54;
extern void *data_ov000_021cca40;
extern void *data_ov006_021ebc80;
extern const ov006_Price021da208 data_ov006_021eb7b4[];
extern const ov006_Price021da208 data_ov006_021eb7c4[];
extern const ov006_Price021da208 data_ov006_021eb7e4;

void *func_0204c0e8(void *a, int id);
void func_ov000_02157c90(void *a, const void *b);
void func_ov000_02157d2c(void *a, const void *b);
int func_ov000_02154b58(void *a, int b);
void func_ov000_021c3af4(void *self);
void func_ov000_021c54f4(void *self);
void func_ov000_021c55e8(void *self, const void *a);
void func_ov000_021c5630(void *self, const void *a);
void func_ov000_021c5678(void *self, const void *a);
void func_ov000_021c22d8(void *self);
void func_ov000_021c5bac(void *self);
void func_ov000_021c3fd4(void *list, void *item);
void func_ov000_0215d980(void *a, s32 b, BOOL c);
void func_ov000_0215c1bc(void *a, int b, const void *c);
BOOL func_ov006_021da19c(void *ctx, void *item);

static inline u8 ov006_SlotManager_GetItem(ov006_SlotManager *self, u8 i) {
    if (i < 3) {
        return self->unk14A[i];
    }
    return 0;
}

static inline u8 ov006_SlotManager_GetItemCount(ov006_SlotManager *self, u8 i) {
    if (i < 3) {
        return self->unk14D[i];
    }
    return 0;
}

static inline const ov006_Price021da208 *ov006_GetItemPrice(u8 item) {
    const ov006_Price021da208 *p = NULL;
    if (item != 0 && item < 11) {
        p = &data_ov006_021eb7c4[item];
    }
    return p;
}

static inline void *ov006_GetRes(void) {
    return data_02149ef8;
}

static inline ov006_Window *ov006_NewWindow_cb4a8(void) {
    ov006_Window *w = (ov006_Window *)func_0203dd9c(0xe0);
    if (w != NULL) {
        w->vtbl = &data_ov000_021cac60;
        VCALL(w, 28);
        w->vtbl = &data_ov000_021caec8;
        VCALL(w, 28);
        w->vtbl = &data_ov000_021cb4a8;
        VCALL(w, 28);
    }
    return w;
}

static inline ov006_Window *ov006_NewWindow_cb5a8(void) {
    ov006_Window *w = (ov006_Window *)func_0203dd9c(0xe0);
    if (w != NULL) {
        w->vtbl = &data_ov000_021cac60;
        VCALL(w, 28);
        w->vtbl = &data_ov000_021caec8;
        VCALL(w, 28);
        w->vtbl = &data_ov000_021cb5a8;
        VCALL(w, 28);
    }
    return w;
}

static inline ov006_Window *ov006_NewWindow_cae48(void) {
    ov006_Window *w = (ov006_Window *)func_0203dd9c(0x98);
    if (w != NULL) {
        w->vtbl = &data_ov000_021cac60;
        VCALL(w, 28);
        w->vtbl = &data_ov000_021cae48;
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

static inline ov006_Menu021da208 *ov006_NewMenu(void) {
    ov006_Menu021da208 *w = (ov006_Menu021da208 *)func_0203dd9c(0x1e4);
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

static inline ov006_List021da208 *ov006_NewList(void) {
    ov006_List021da208 *w = (ov006_List021da208 *)func_0203dd9c(0x100);
    if (w != NULL) {
        w->vtbl = &data_ov000_021cac60;
        VCALL(w, 28);
        w->vtbl = &data_ov000_021ccbe0;
        func_ov000_021c3af4(w);
        w->vtbl = &data_ov000_021ccb54;
        func_ov000_021c54f4(w);
    }
    return w;
}

static inline ov006_Entry021da208 *ov006_NewEntry(void) {
    ov006_Entry021da208 *e = (ov006_Entry021da208 *)func_0203dd9c(0x48);
    if (e != NULL) {
        e->vtbl = &data_ov006_021ebc80;
        func_ov000_021c22d8(e);
        e->vtbl = &data_ov000_021cca40;
        func_ov000_021c5bac(e);
    }
    return e;
}

static inline void ov006_SetRot(void *p, s16 x, s16 y, s16 z) {
    ov006_Window *self = (ov006_Window *)p;
    self->unk64 = x;
    self->unk66 = y;
    self->unk68 = z;
}

static inline void ov006_SetPos(void *p, int x, int y, int z) {
    ov006_Window *self = (ov006_Window *)p;
    self->unk58 = x;
    self->unk5C = y;
    self->unk60 = z;
}

static inline void ov006_Entry_Set(ov006_Entry021da208 *e, void *res, const ov006_Price021da208 *p, int cnt) {
    u16 price = p->unk2;
    e->unk38 = func_0204c0e8(res, p->unk0);
    e->unk3C = cnt;
    e->unk40 = price * cnt;
}

void func_ov006_021da208(ov006_Task021da208 *self) {
    void *res = ov006_GetRes();
    u8 n = data_ov006_021ec884->unk13E;
    const ov006_Price021da208 *base;
    u8 i;
    if (n < 1) {
        n = 1;
    } else if (n > 4) {
        n = 4;
    }
    base = &data_ov006_021eb7b4[(u8)(n - 1)];
    self->unk10 = ov006_NewWindow_cb4a8();
    VCALL(self->unk10, 10, func_0204c0e8(res, 0x18e));
    VCALL(self->unk10, 14, func_0204c0e8(res, 0x18f));
    self->unk10->unk4A = 0x2c00;
    func_ov000_02157c90(self->unk10, func_0204c0e8(res, 0x190));
    func_ov000_02157d2c(self->unk10, func_0204c0e8(res, 0x3e));
    self->unk10->unk24 = 0xf8;
    self->unk10->unk20 = 1;
    ov006_SetRot(self->unk10, 0, 0x19, -0x199a);
    ov006_SetPos(self->unk10, -0x100, 0, 0);
    self->unk10->flags |= 0x400000;
    self->unk10->flags &= ~0x800000;
    self->unk10->unkC0 = 0x8c;
    self->unk10->unkC1 = 4;
    VCALL(self->unk10, 74, func_0204c0e8(res, base->unk0), 0, 0xffff, base->unk2);
    self->unk10->flags &= ~0x40000;
    self->unk10->flags &= ~0x20000;
    self->unk10->flags &= ~0x10000;
    self->unk10->flags &= ~0x2000000;
    {
        ov006_Window *w = self->unk10;
        VCALL(w, A8, func_ov000_02154b58(w, 0));
    }
    self->unk10->flags |= 4;
    VCALL(self->unk10, 08);
    self->unk10->flags &= ~2;

    self->unk14 = ov006_NewList();
    func_ov000_021c55e8(self->unk14, func_0204c0e8(res, 0x191));
    func_ov000_021c5630(self->unk14, func_0204c0e8(res, 0x192));
    func_ov000_021c5678(self->unk14, func_0204c0e8(res, 0x3e));
    self->unk14->unk24 = 0xf8;
    self->unk14->unk20 = 4;
    ov006_SetRot(self->unk14, 2, 0x3b, -0x199a);
    ov006_SetPos(self->unk14, -0x100, 0, 0);
    if (data_ov006_021ec860->unk1C) {
        const ov006_Price021da208 *p = &data_ov006_021eb7e4;
        ov006_Entry021da208 *e = ov006_NewEntry();
        ov006_Entry_Set(e, res, p, data_ov006_021ec884->numActive);
        e->unk14 = -0x199a;
        func_ov000_021c3fd4(self->unk14, e);
    }
    for (i = 0; i < 3; i++) {
        u8 item = ov006_SlotManager_GetItem(data_ov006_021ec884, i);
        const ov006_Price021da208 *p = ov006_GetItemPrice(item);
        if (p != NULL) {
            int cnt = 1;
            ov006_Entry021da208 *e;
            if (item < 8) {
                cnt = ov006_SlotManager_GetItemCount(data_ov006_021ec884, i);
            }
            e = ov006_NewEntry();
            ov006_Entry_Set(e, res, p, cnt);
            func_ov000_021c3fd4(self->unk14, e);
        }
    }
    self->unk14->flags &= ~0x40000;
    self->unk14->unkF0 = 0;
    self->unk14->flags |= 4;
    VCALL(self->unk14, 08);
    self->unk14->flags &= ~2;

    self->unk18 = ov006_NewWindow_cae48();
    ov006_SetRot(self->unk18, 0x92, 0x86, -0x199a);
    ov006_SetPos(self->unk18, 0x100, 0, 0);
    self->unk18->unk2C = 1;
    VCALL(self->unk18, 08);
    func_ov000_0215d980(self->unk18, self->unk38, 1);

    self->unk1C = ov006_NewWindow_cae48();
    ov006_SetRot(self->unk1C, 0x92, 0x96, -0x199a);
    ov006_SetPos(self->unk1C, 0x100, 0, 0);
    self->unk1C->unk2C = 1;
    VCALL(self->unk1C, 08);
    func_ov000_0215d980(self->unk1C, *(s32 *)((u8 *)data_0214a424 + 0x20), 1);

    self->unk20 = ov006_NewWindow_cb5a8();
    self->unk20->flags |= 0x4000000;
    self->unk20->unk2C = 1;
    self->unk20->flags |= 0x20000000;
    self->unk20->flags |= 0x80000000;
    ov006_SetPos(self->unk20, 0x100, 0, -0xcd);
    VCALL(self->unk20, F4, 1, func_0204c0e8(res, 0x36));
    VCALL(self->unk20, 08);
    self->unk20->flags |= 2;

    self->unk24 = ov006_NewWindow_cad50();
    func_ov000_0215c1bc(self->unk24, 0x74, func_0204c0e8(res, 0x197));
    self->unk24->flags |= 0x10000;
    self->unk24->flags &= ~0x20000;
    self->unk24->flags |= 2;

    self->unk28 = ov006_NewMenu();
    self->unk28->unk1D8 = 0x8d;
    self->unk28->unk1DC = func_0204c0e8(ov006_GetRes(), 0x26);
    self->unk28->unk1E0 = 0;
    self->unk28->unk84 = (void *)func_ov006_021da19c;
    self->unk28->owner = self->unk2C;
    VCALL(self->unk28, 08);
    self->unk28->unk68 = -0x1666;
    self->unk28->flags |= 2;
}

}
