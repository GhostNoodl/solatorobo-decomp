#include "ov006/Tasks.h"

#define F(p, off, T) (*(T *)((u8 *)(p) + (off)))

typedef struct ov006_Info021daaa8 {
    int unk0;
    int unk4;
} ov006_Info021daaa8;

typedef struct ov006_Unk020706a0 {
    s16 unk0;
} ov006_Unk020706a0;

typedef struct ov006_Rot021d4118 {
    u16 x;
    u16 y;
    u16 z;
} ov006_Rot021d4118;

extern "C" {

extern void *data_02149ef8;
extern void *data_ov000_021cac60;
extern void *data_ov000_021caec8;
extern void *data_ov000_021cadcc;
extern void *data_ov000_021cb1b0;
extern void *data_ov000_021cb0b8;
extern const u16 data_ov006_021eb6fc;
extern const u8 data_ov006_021eb6fe[4];
extern const ov006_Rot021d4118 data_ov006_021eb702;
extern const ov006_Vec32 data_ov006_021eb764;
extern const ov006_Vec32 data_ov006_021eb734;
extern char data_ov006_021ebc58[];
extern char data_ov006_021ebc04[];
extern char data_ov006_021ebc0a[];
extern char data_ov006_021ebc1c[];

const u16 data_ov006_021eb6fc = 0x1000;
const u8 data_ov006_021eb6fe[4] = {0, 1, 3, 2};
const ov006_Rot021d4118 data_ov006_021eb702 = {0xfa80, 0x8200, 0};

void *func_0204c0e8(void *a, int id);
void func_ov006_021cd580(int a, void *b, int c);
void func_ov000_021548cc(void *a, int b);
void *func_ov000_02154b80(void *a, int b);
BOOL func_ov006_021d37d0(ov006_Window *window, ov006_ListNode *node);
BOOL func_ov006_021d1f00(ov006_Window *window, ov006_ListNode *node);
void func_ov000_0215bb14(void *a, const void *b);
ov006_Obj58 *func_ov006_021dbcb8(void *p);
ov006_Model64 *func_ov000_0218fe1c(void *p);
void func_ov000_0218ffdc(ov006_Model64 *a, ov006_Model60 *b, int c, int d);
void func_ov000_02190cb0(void *a, const void *b, int c, int d);
void func_ov000_021915a0(void *a);
void *func_ov000_02190a30(void *a, int b);
void func_ov000_021911c8(void *a, int b);
ov006_Unk020706a0 *func_020706a0(u16 id);
void func_ov006_021d526c(ov006_TaskD37 *self, const char *name, s16 speed, u8 loop);
void *func_ov006_021e07b0(void *p);
void func_ov006_021e0954(void *p);
void func_ov006_021e0ca8(void *p, void *a, int b);
ov006_Obj13C *func_ov006_021e1484(void *p);
void func_ov006_021e16b0(ov006_Obj13C *p);
ov006_Info021daaa8 *func_ov006_021daaa8(u16 id);
const void *func_0206ec8c(u16 id);
const void *func_0206ec48(u16 id);
void func_ov006_021dbfb8(ov006_Obj58 *a, const char *b, int c, int d);
void func_ov006_021e1ddc(ov006_Obj13C *a, const char *b, int c, int d);
void func_ov006_021e1e6c(ov006_Obj13C *a, const void *b);
void func_ov006_021e4b90(ov006_Unk021ec888 *self);
void func_ov000_02173648(void *self);

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

static inline ov006_Model64 *ov006_NewModel64(void) {
    void *p = func_0203dd9c(0xe8);
    if (p != NULL) {
        p = func_ov000_0218fe1c(p);
    }
    return (ov006_Model64 *)p;
}

static inline void ov006_SetPos3(void *p, int x, int y, int z) {
    F(p, 0xb0, int) = x;
    F(p, 0xb4, int) = y;
    F(p, 0xb8, int) = z;
}

static inline void ov006_SetPair(void *p, int off, int x, int y) {
    F(p, off, int) = x;
    F(p, off + 4, int) = y;
}

static inline void ov006_SetPair2(void *p, int x, int y) {
    F(p, 0x10, int) = x;
    F(p, 0x14, int) = y;
}

static inline void ov006_TaskD37_Select(ov006_TaskD37 *self, u16 id) {
    ov006_Info021daaa8 *info;
    self->unk4A = id;
    info = func_ov006_021daaa8(id);
    if (self->head.unkC != 2) {
        func_ov000_0215bb14(self->unk54, func_0206ec8c(id));
        VCALL(self->unk54, 70);
    }
    func_ov006_021dbfb8(self->unk58, data_ov006_021ebc0a, info->unk0, 0);
    func_ov006_021e1ddc(self->unk13C, data_ov006_021ebc1c, info->unk4, 0);
    func_ov006_021e1e6c(self->unk13C, func_0206ec48(id));
}

static inline void ov006_SetCam(void *self, const ov006_Vec32 *at, const ov006_Vec32 *up, const ov006_Rot021d4118 *rot, int fovy) {
    F(self, 0x8c, ov006_Vec32) = *at;
    F(self, 0x98, ov006_Vec32) = *up;
    F(self, 0xbe, ov006_Rot021d4118) = *rot;
    F(self, 0xc4, int) = fovy;
    F(self, 0xbc, u16) = 1;
}

static inline void ov006_SetCam2(void *self, ov006_Vec32 at, ov006_Vec32 up, ov006_Rot021d4118 rot, int fovy) {
    F(self, 0x8c, ov006_Vec32) = at;
    F(self, 0x98, ov006_Vec32) = up;
    F(self, 0xbe, ov006_Rot021d4118) = rot;
    F(self, 0xc4, int) = fovy;
    F(self, 0xbc, u16) = 1;
}

void func_ov006_021d4118(ov006_TaskD37 *self) {
    s32 kq;
    void *res;
    ov006_Info021daaa8 *info;
    u16 id;
    if (VCALL(self, 28)) {
        return;
    }
    res = data_02149ef8;
    self->unk50 = ov006_NewWindow_caec8();
    VCALL(self->unk50, 10, func_0204c0e8(res, 0x12a));
    VCALL(self->unk50, 14, func_0204c0e8(res, 0x12b));
    self->unk50->unk4A = 0x2c00;
    self->unk50->unk20 = 5;
    self->unk50->unk24 = 0x9c;
    ov006_Window_SetRot(self->unk50, 0, 0x1e, -0x199a);
    self->unk50->unk68 = -0x199a;
    ov006_Window_SetPos(self->unk50, -0xff, 0, -0x199a);
    self->unk50->flags &= ~0x400000;
    self->unk50->flags &= ~0x800000;
    self->unk50->flags &= ~0x80000;
    self->unk50->flags &= ~0x20000;
    self->unk50->flags &= ~0x40000;
    self->unk50->flags &= ~0x10000;
    func_ov006_021cd580(5, self->unk50, 0);
    kq = 0xffff;
    if ((u32)self & 3) {
        kq = 0xffff;
    }
    VCALL(self->unk50, 08);
    func_ov000_021548cc(self->unk50, data_ov006_021eb6fe[data_ov006_021ec884->unk5]);
    if (self->unk4A != kq && self->head.unkC == 0) {
        ov006_Window *w = self->unk50;
        VCALL(w, A8, func_ov000_02154b58(w, self->unk4A));
    } else {
        ov006_Window *w = self->unk50;
        VCALL(w, A8, func_ov000_02154b80(w, 0));
    }
    self->unk50->owner = self;
    self->unk50->unk88 = func_ov006_021d37d0;
    self->unk50->flags |= 4;
    self->unk54 = ov006_NewWindow_cadcc();
    self->unk54->unk24 = 0xf8;
    self->unk54->unk20 = 2;
    ov006_Window_SetRot(self->unk54, 4, 0x95, -0x199a);
    ov006_Window_SetPos(self->unk54, -0x100, 0, -0x199a);
    self->unk54->unk2C = 1;
    VCALL(self->unk54, 08);
    if (self->head.unkC == 2) {
        func_ov000_0215bb14(self->unk54, func_0204c0e8(res, 0x13f));
        VCALL(self->unk54, 70);
    }
    {
        void *p = func_0203dd9c(0xec);
        if (p != NULL) {
            p = func_ov006_021dbcb8(p);
        }
        self->unk58 = (ov006_Obj58 *)p;
    }
    ov006_SetPos3(self->unk58, 0xbf000, 0x50000, F(self->unk58, 0xb8, int));
    F(self->unk58, 0xb8, int) = -0x1fccd;
    self->unk64 = ov006_NewModel64();
    func_ov000_0218ffdc(self->unk64, self->unk60, 0, 1);
    func_ov000_02190cb0(self->unk64, data_ov006_021ebc58, 0, 1);
    F(self->unk64, 0xb4, s16) = 0;
    func_ov000_021915a0(self->unk64);
    F(func_ov000_02190a30(self->unk64, 0), 0x112, s16) = 0x400;
    self->unk6C = ov006_NewModel64();
    func_ov000_0218ffdc(self->unk6C, self->unk68, 0, 1);
    func_ov000_02190cb0(self->unk6C, data_ov006_021ebc04, 0, 1);
    F(self->unk6C, 0xb4, s16) = 0;
    func_ov000_021915a0(self->unk6C);
    func_ov000_021911c8(self->unk6C, func_020706a0(func_ov006_021db060(data_ov006_021ec884, data_ov006_021ec884->unk5)->unkC)->unk0);
    func_ov006_021d526c(self, data_ov006_021ebc58, 0x400, 1);
    {
        ov006_Vec32 at = data_ov006_021eb764;
        ov006_Vec32 up = data_ov006_021eb734;
        ov006_Rot021d4118 rot = data_ov006_021eb702;
        ov006_SetCam(self, &at, &up, &rot, 0x4400);
    }
    {
        void *p = func_0203dd9c(0x2c);
        if (p != NULL) {
            p = func_ov006_021e07b0(p);
        }
        self->unk138 = (ov006_Unk68 *)p;
    }
    F(self->unk138, 0x20, int) = 1;
    func_ov006_021e0954(self->unk138);
    ov006_SetPair(self->unk138, 0x8, -0xa0, -0x61);
    ov006_SetPair2(self->unk138, 0x11, 0);
    func_ov006_021e0ca8(self->unk138, func_0204c0e8(res, 0x12a), 4);
    F(self->unk138, 0x1c, int) = -0x1e;
    {
        void *p = func_0203dd9c(0x30);
        if (p != NULL) {
            p = func_ov006_021e1484(p);
        }
        self->unk13C = (ov006_Obj13C *)p;
    }
    ov006_SetPair(self->unk13C, 0x8, 0, 0xc);
    func_ov006_021e16b0(self->unk13C);
    self->unk5C = ov006_NewWindow_cb0b8();
    F(self->unk5C, 0x1d8, u16) = 0x12c;
    F(self->unk5C, 0x1dc, void *) = func_0204c0e8(res, 0x18);
    F(self->unk5C, 0x1e0, u16) = 1;
    self->unk5C->unk84 = func_ov006_021d1f00;
    self->unk5C->owner = (u8 *)self + 0x40;
    VCALL(self->unk5C, 08);
    self->unk5C->unk68 = -0x1666;
    self->unk5C->flags |= 2;
    if (self->head.unkC != 0) {
        self->unk3D = 0;
    }
    id = ov006_Window_GetSelected(self->unk50)->id;
    self->unk4A = id;
    info = func_ov006_021daaa8(id);
    if (self->head.unkC != 2) {
        func_ov000_0215bb14(self->unk54, func_0206ec8c(id));
        VCALL(self->unk54, 70);
    }
    func_ov006_021dbfb8(self->unk58, data_ov006_021ebc0a, info->unk0, 0);
    func_ov006_021e1ddc(self->unk13C, data_ov006_021ebc1c, info->unk4, 0);
    func_ov006_021e1e6c(self->unk13C, func_0206ec48(id));
    self->unk4C = self->unk4A;
    func_ov006_021e4b90(data_ov006_021ec888);
    self->unk44 = 4;
    self->unk48 = self->unk4A;
    func_ov000_02173648(self);
    self->head.flags &= ~2;
}

}
