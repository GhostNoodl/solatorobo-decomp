#include "ov006/Window.h"

typedef struct ov006_Unk0203a4c0 {
    s8 *unk0;
} ov006_Unk0203a4c0;

typedef struct ov006_Unk02097ce0 {
    u8 unk0[4];
    int unk4;
} ov006_Unk02097ce0;

extern "C" {

extern ov006_Unk02097ce0 *data_02097ce0;
extern void *data_ov006_021ec424;
extern char data_ov006_021ec44c[];
extern char data_ov006_021ec455[];
extern void *data_ov006_021ec404;
extern void *data_ov006_021ec444;
extern u16 data_ov006_021eb840[];

void MI_CpuFill8(void *dst, int value, u32 size);
void MIi_CpuClear16(int value, void *dst, u32 size);

ov006_Unk0203a4c0 *func_0203a4c0(ov006_Unk02097ce0 *a);
BOOL func_0203e63c(void *a);
BOOL func_02054f10(int a, int b);
BOOL func_ov006_021e3be0(ov006_Window *self);
BOOL func_ov006_021e3c18(ov006_Window *self);

void func_ov006_021e3934(ov006_Window *self, int arg, int arg2) {
    if (self->unk80 != NULL) {
        self->unk80(arg, self, arg2);
    }
}

int func_ov006_021e3958(ov006_Window *self) {
    s8 base;
    data_02097ce0->unk4 = self->unk1C;
    base = func_0203a4c0(data_02097ce0)->unk0[1];
    return base + VCALL(self, 3C);
}

int func_ov006_021e399c(ov006_Window *self, int a, int b, int c) {
    return VCALL(self, 60, a, b, c);
}

BOOL func_ov006_021e39b0(ov006_Window *self) {
    BOOL result;
    if (self->unk90 == NULL) {
        return TRUE;
    }
    result = self->unk90(self, ov006_Window_GetSelected(self));
    self->unk90 = NULL;
    return result;
}

BOOL func_ov006_021e3a0c(ov006_Window *self, ov006_ListNode *node) {
    if (self->unk8C == NULL) {
        return TRUE;
    }
    return self->unk8C(self, node);
}

BOOL func_ov006_021e3a28(ov006_Window *self, ov006_ListNode *node) {
    if (self->unk88 == NULL) {
        return TRUE;
    }
    return self->unk88(self, node);
}

static inline int ov006_Window_CalcSize(ov006_Window *self) {
    int rows = self->unk20 * VCALL(self, 40);
    int top = VCALL(self, 34);
    return rows + top + VCALL(self, 38);
}

int func_ov006_021e3a44(ov006_Window *self) {
    if (self->flags & 0x20000) {
        int size;
        self->unk20 += 2;
        size = ov006_Window_CalcSize(self);
        self->unk20 -= 2;
        return size;
    }
    return ov006_Window_CalcSize(self);
}

int func_ov006_021e3af8(ov006_Window *self) {
    return VCALL(self, 30) + self->unkC0 + 0x12;
}

int func_ov006_021e3b1c(void) {
    return 0;
}

int func_ov006_021e3b24(ov006_Window *self) {
    return self->unkB8 != NULL ? 0x12 : 0;
}

int func_ov006_021e3b38(ov006_Window *self) {
    return self->unkC1 * 8;
}

int func_ov006_021e3b44(void) {
    return 4;
}

int func_ov006_021e3b4c(void) {
    return 4;
}

int func_ov006_021e3b54(ov006_Window *self) {
    return (self->unkD4 != NULL ? 0x10 : 0) + 10;
}

int func_ov006_021e3b6c(void) {
    return 0;
}

static inline BOOL ov006_Widget_IsReady(ov006_Widget *self) {
    if (self->unk6C == NULL) {
        return TRUE;
    }
    if (func_0203e63c(self->unk6C)) {
        self->unk6C = NULL;
    } else {
        return !self->busy;
    }
    return TRUE;
}

BOOL func_ov006_021e3b74(ov006_Window *self) {
    BOOL result = func_ov006_021e3be0(self);
    ov006_Widget *widget = self->unkD4;
    if (widget != NULL && !ov006_Widget_IsReady(widget)) {
        result = FALSE;
    }
    return result;
}

BOOL func_ov006_021e3be0(ov006_Window *self) {
    BOOL result = func_ov006_021e3c18(self);
    if (self->unkB4 != 0 && !func_02054f10(self->unkB4, 0xffff)) {
        result = FALSE;
    }
    return result;
}

BOOL func_ov006_021e3c18(ov006_Window *self) {
    BOOL result = TRUE;
    if (self->unk10 != 0 && !func_02054f10(self->unk10, 0xffff)) {
        result = FALSE;
    }
    if (self->unk14 != NULL && !ov006_Widget_IsReady(self->unk14)) {
        result = FALSE;
    }
    if (self->unk18 != NULL && !ov006_Widget_IsReady(self->unk18)) {
        result = FALSE;
    }
    return result;
}

static inline void ov006_ModelHolder_Dtor(ov006_ModelHolder *self) {
    self->vtbl = &data_ov006_021ec424;
    OV006_DELETE_MODEL(self->model);
}

ov006_ModelHolder *func_ov006_021e3cec(ov006_ModelHolder *self) {
    ov006_ModelHolder_Dtor(self);
    return self;
}

ov006_ModelHolder *func_ov006_021e3d5c(ov006_ModelHolder *self) {
    ov006_ModelHolder_Dtor(self);
    func_0203de1c(self);
    return self;
}

void func_ov006_021e3dd4(ov006_ModelHolder *self, int a) {
    const char *file = data_ov006_021ec44c;
    const char *name = data_ov006_021ec455;
    ov006_Model *model;
    OV006_DELETE_MODEL(self->model);
    model = (ov006_Model *)func_0203dd9c(sizeof(ov006_Model));
    if (model != NULL) {
        func_02041218(model->unk88);
        func_02041440(model, name, 0);
        STD_CopyString(model->unk2C, file);
    }
    self->model = model;
    func_020417e0(self->model, func_02035de0(file, name));
    self->model->unk6C |= 2;
    self->model->unk6C |= 0x80000;
    self->model->unk6C |= 0x400000;
    func_02041d9c(self->model, a, 0);
    func_02041d9c(self->model, a, 1);
    func_02041d9c(self->model, a, 2);
    func_02041d9c(self->model, a, 3);
    self->unk8 = a;
}

void func_ov006_021e3f0c(void) {
}

}
