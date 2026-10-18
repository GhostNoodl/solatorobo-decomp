#include "ov002/ov002.h"

extern "C" {

void func_ov002_021cf3b4(Task50 *self) {
    if (self->v0x54() != 0) {
        func_ov002_setCurrent021ccd40(NULL);
    }
}

bool func_ov002_021cf404(Task50 *self, u32 mask) {
    BOOL r = Task50_testFlags(self, mask);
    return r;
}

void func_ov002_021cf424(Task50 *self) {
    self->flag7 = 0;
}

bool func_ov002_021cf434(Task50 *self) {
    BOOL r = Task50_getFlag6(self);
    return r;
}

void func_ov002_021cf458(Task50 *self) {
    self->flag6 = 1;
}

bool func_ov002_021cf468(Task50 *self) {
    BOOL r = Task50_getFlag5(self);
    return r;
}

void func_ov002_021cf48c(Task50 *self) {
    self->flag5 = 1;
}

void func_ov002_021cf49c(Task50 *self) {
    self->flag4 = 0;
}

void func_ov002_021cf4ac(Task50 *self) {
    self->flag4 = 1;
}

BOOL func_ov002_021cf4bc(void) {
    return TRUE;
}

Task50 *func_ov002_021cf4c4(Task50 *self) {
    u32 saved;
    *(VFunc **)self = data_ov002_021ef4b0;
    HEAP_PUSH(saved);
    DELETE_VOBJ(TASK_VOBJ(self, 0x3c));
    HEAP_POP(saved);
    HEAP_PUSH(saved);
    DELETE_VOBJ(self->unk_40);
    HEAP_POP(saved);
    {
        u8 *gfx = data_02097e48;
        *(u16 *)(gfx + 0x80) = 0x8000;
        *(u16 *)(gfx + 0x7c) = 0;
    }
    TaskBase_dtor(self);
    func_0203de1c(self);
    return self;
}

BOOL func_ov002_021cf5a8(void) {
    return TRUE;
}

void func_ov002_021cf5b0(void) {
}

Task50 *func_ov002_021cf5b4(Task50 *self) {
    u32 saved;
    *(VFunc **)self = data_ov002_021ef4b0;
    HEAP_PUSH(saved);
    DELETE_VOBJ(TASK_VOBJ(self, 0x3c));
    HEAP_POP(saved);
    HEAP_PUSH(saved);
    DELETE_VOBJ(self->unk_40);
    HEAP_POP(saved);
    {
        u8 *gfx = data_02097e48;
        *(u16 *)(gfx + 0x80) = 0x8000;
        *(u16 *)(gfx + 0x7c) = 0;
    }
    TaskBase_dtor(self);
    return self;
}

void func_ov002_021cf690(void) {
}

Task50 *func_ov002_021cf694(Task50 *self) {
    u32 saved;
    *(VFunc **)self = data_ov002_021ef430;
    HEAP_PUSH(saved);
    Task_deleteModel(self);
    HEAP_POP(saved);
    if (self->unk_4f) {
        func_02035acc(data_ov002_021ef3e4, data_ov002_021ef3f9, 2);
    }
    self->unk_4f = 0;
    TaskBase_dtor(self);
    func_0203de1c(self);
    return self;
}

Task50 *func_ov002_021cf754(Task50 *self) {
    u32 saved;
    *(VFunc **)self = data_ov002_021ef430;
    HEAP_PUSH(saved);
    Task_deleteModel(self);
    HEAP_POP(saved);
    if (self->unk_4f) {
        func_02035acc(data_ov002_021ef3e4, data_ov002_021ef3f9, 2);
    }
    self->unk_4f = 0;
    TaskBase_dtor(self);
    return self;
}

Task50 *func_ov002_021cf80c(Task50 *self) {
    *(VFunc **)self = data_ov002_021ef530;
    self->v0x5c();
    TaskBase_dtor(self);
    func_0203de1c(self);
    return self;
}

BOOL func_ov002_021cf858(Task50 *self) {
    if (self->v0x54() != 0) {
        func_ov002_setCurrent021ccd40(NULL);
    }
    return TRUE;
}

Task50 *func_ov002_021cf8ac(Task50 *self) {
    *(VFunc **)self = data_ov002_021ef530;
    self->v0x5c();
    TaskBase_dtor(self);
    return self;
}

void *func_ov002_021cf8f0(void *self) {
    *(VFunc **)self = data_ov002_021ef410;
    func_ov000_0216f168(self);
    func_0203de1c(self);
    return self;
}

void func_ov002_021cf918(void *self) {
    Callback cb = FIELD(self, 0x14, Callback);
    if (cb != NULL) {
        cb(self);
    }
}

void func_ov002_021cf930(void *self) {
    Callback cb = FIELD(self, 0x10, Callback);
    if (cb != NULL) {
        cb(self);
    }
}

void func_ov002_021cf948(void) {
    if (func_ov002_isMode4b()) {
        func_0203cb78(0xa000, 0, 1);
    }
}

BOOL func_ov002_021cf990(void) {
    return FALSE;
}

void *func_ov002_021cf998(void *self) {
    *(VFunc **)self = data_ov002_021ef410;
    func_ov000_0216f168(self);
    return self;
}

Task50 *func_ov002_021cf9b8(void) {
    Task50 *p = (Task50 *)func_0203dd9c(0x48);
    if (p != NULL) {
        TaskBase_ctor(p);
        *(VFunc **)p = data_ov002_021ef79c;
        p->unk_3c = NULL;
        p->unk_40 = NULL;
        FIELD(p, 0x44, u16) = 0;
    }
    p->v0x8(0x13, 0x64);
    return p;
}

Task50 *func_ov002_021cfa20(Task50 *self) {
    u32 saved;
    *(VFunc **)self = data_ov002_021ef79c;
    HEAP_PUSH(saved);
    DELETE_VOBJ(TASK_VOBJ(self, 0x3c));
    HEAP_POP(saved);
    HEAP_PUSH(saved);
    DELETE_VOBJ(self->unk_40);
    HEAP_POP(saved);
    TaskBase_dtor(self);
    return self;
}

Task50 *func_ov002_021cfae0(Task50 *self) {
    u32 saved;
    *(VFunc **)self = data_ov002_021ef79c;
    HEAP_PUSH(saved);
    DELETE_VOBJ(TASK_VOBJ(self, 0x3c));
    HEAP_POP(saved);
    HEAP_PUSH(saved);
    DELETE_VOBJ(self->unk_40);
    HEAP_POP(saved);
    TaskBase_dtor(self);
    func_0203de1c(self);
    return self;
}

}
