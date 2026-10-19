#include "ov006/Tasks.h"
#include "ov006/SlotManager.h"

extern "C" {

void func_ov006_021d0f44(void) {
}

BOOL func_ov006_021d0f48(void) {
    return TRUE;
}

extern void *data_02149ef8;
extern void *data_ov000_021cac60;
extern void *data_ov000_021cad50;
extern void *data_ov000_021caec8;
extern void *data_ov000_021cb4a8;
extern void *data_ov000_021cadcc;
extern char data_ov006_021ebc02[];
extern u8 *data_02097e40;

void *func_0204c0e8(void *a, int id);
void func_ov000_0215c1bc(void *a, int b, const void *c);
void func_ov000_0215bb14(void *a, const void *b);
void func_ov000_02157c90(void *a, const void *b);
void func_ov000_02157d2c(void *a, const void *b);
void func_ov000_02173648(void *self);
void func_ov006_021daea0(ov006_SlotManager *a);
BOOL func_ov006_021db0a8(ov006_SlotManager *a, int b);
void func_ov006_021e60b4(void *a, int b);
void func_ov006_021e4a80(ov006_Unk021ec888 *self, u16 a, int b, const void *src, u32 size);

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

static inline void ov006_SlotPacked_Clear(ov006_SlotPacked *self) {
    self->active = 0;
    self->isType1 = 0;
    self->unkC = 0;
    self->unk10 = 0;
    self->unk0_8 = 0;
    MI_CpuFill8(self->name, 0, sizeof(self->name));
}

static inline void *ov006_GetRes(void) {
    return data_02149ef8;
}

void func_ov006_021d0f50(ov006_TaskD0C *self) {
    u16 i;
    void *res;
    if (VCALL(self, 28)) {
        return;
    }
    res = ov006_GetRes();
    self->unk11C = ov006_NewWindow_cb4a8();
    VCALL(self->unk11C, 10, func_0204c0e8(res, 0x133));
    VCALL(self->unk11C, 14, func_0204c0e8(res, 0x134));
    func_ov000_02157c90(self->unk11C, func_0204c0e8(res, 0x135));
    func_ov000_02157d2c(self->unk11C, func_0204c0e8(res, 0x136));
    self->unk11C->unk4A = 0x2c00;
    self->unk11C->unk20 = 4;
    ov006_Window_SetRot(self->unk11C, 0, 0x2c, -0x1ccd);
    ov006_Window_SetPos(self->unk11C, -0x100, 0, -0x1ccd);
    self->unk11C->flags |= 0x400000;
    self->unk11C->flags &= ~0x800000;
    self->unk11C->unkC0 = 0x8c;
    self->unk11C->unkC1 = 1;
    self->unk11C->flags &= ~0x20000;
    self->unk11C->flags &= ~0x40000;
    self->unk11C->flags &= ~0x10000;
    self->unk11C->flags |= 4;
    for (i = 0; i < 4; i++) {
        VCALL(self->unk11C, 74, data_ov006_021ebc02, i, 0xffff, 0xffff);
    }
    self->unk11C->flags &= ~0x2000000;
    VCALL(self->unk11C, A8, 0);
    VCALL(self->unk11C, 08);
    self->unk11C->flags &= ~2;
    self->unk120 = ov006_NewWindow_cadcc();
    self->unk120->unk24 = 0xf8;
    self->unk120->unk20 = 2;
    ov006_Window_SetRot(self->unk120, 4, 0x95, -0x199a);
    ov006_Window_SetPos(self->unk120, -0x100, 0, -0x199a);
    self->unk120->unk2C = 1;
    VCALL(self->unk120, 08);
    func_ov000_0215bb14(self->unk120, func_0204c0e8(res, 0x138));
    VCALL(self->unk120, 70);
    self->unk124 = ov006_NewWindow_cad50();
    self->unk124->flags |= 0x10000;
    self->unk124->flags |= 0x20000;
    self->unk124->flags |= 2;
    func_ov000_0215c1bc(self->unk124, 0x8000, func_0204c0e8(res, 0x198));
    func_ov006_021daea0(data_ov006_021ec884);
    data_ov006_021ec860->unk1C = 1;
    MI_CpuFill8(data_02097e40 + 0x18e0, 0, 0x200);
    ov006_SlotPacked_Clear(&self->unk102);
    func_ov006_021e60b4(self->unk102.name, sizeof(self->unk102.name));
    self->unk102.active = 1;
    self->unk102.isType1 = 1;
    self->unk102.unkC = 0;
    self->unk102.unk10 = 0;
    if (func_ov006_021db0a8(data_ov006_021ec884, 9)) {
        self->unk102.unk10 = 1;
    } else if (func_ov006_021db0a8(data_ov006_021ec884, 10)) {
        self->unk102.unk10 = 2;
    }
    func_ov006_021e4a80(data_ov006_021ec888, self->unk101, 1, &self->unk102, 0x18);
    if (self->unkC == 1) {
        self->unk101 = 0;
    } else {
        self->unk101 = 1;
    }
    *(int *)&self->unk10[0x10] = self->unk11C->unk34;
    self->flags &= ~2;
    func_ov000_02173648(self);
}

}
