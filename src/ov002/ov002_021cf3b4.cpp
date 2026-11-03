#include "ov002/ov002.h"

extern "C" {

void Ov002Task_ReleaseCurrent(Task *self) {
    if (self->vfunc_54() != 0) {
        func_ov002_setCurrent021ccd40(NULL);
    }
}

bool Ov002Task_TestFlags(Task *self, u32 mask) {
    BOOL r = Task_testFlags(self, mask);
    return r;
}

void Ov002Task_ClearFlag7(Task *self) {
    self->unk_04_7 = 0;
}

bool Ov002Task_GetFlag6(Task *self) {
    BOOL r = Task_getFlag6(self);
    return r;
}

void Ov002Task_SetFlag6(Task *self) {
    self->unk_04_6 = 1;
}

bool Ov002Task_GetFlag5(Task *self) {
    BOOL r = Task_getFlag5(self);
    return r;
}

void Ov002Task_SetFlag5(Task *self) {
    self->unk_04_5 = 1;
}

void Ov002Task_ClearFlag4(Task *self) {
    self->unk_04_4 = 0;
}

void Ov002Task_SetFlag4(Task *self) {
    self->unk_04_4 = 1;
}

BOOL Ov002Task_IsReady(void) {
    return TRUE;
}

Task021ef4b0 *Ov002TaskVt_021ef4b0_DtorDelete(Task021ef4b0 *self) {
    void *saved;
    *(VFunc **)self = data_ov002_021ef4b0;
    HEAP_PUSH(saved);
    DELETE_VOBJ(self->unk_3c);
    HEAP_POP(saved);
    HEAP_PUSH(saved);
    DELETE_VOBJ(self->unk_40);
    HEAP_POP(saved);
    {
        u8 *gfx = (u8 *)data_02097e48.queue;
        *(u16 *)(gfx + 0x80) = 0x8000;
        *(u16 *)(gfx + 0x7c) = 0;
    }
    TaskBase_dtor(self);
    Heap_Free(self);
    return self;
}

BOOL Task021ef4b0_IsLoaded(void) {
    return TRUE;
}

void Task021ef4b0_Load(void) {
}

Task021ef4b0 *Ov002TaskVt_021ef4b0_Dtor(Task021ef4b0 *self) {
    void *saved;
    *(VFunc **)self = data_ov002_021ef4b0;
    HEAP_PUSH(saved);
    DELETE_VOBJ(self->unk_3c);
    HEAP_POP(saved);
    HEAP_PUSH(saved);
    DELETE_VOBJ(self->unk_40);
    HEAP_POP(saved);
    {
        u8 *gfx = (u8 *)data_02097e48.queue;
        *(u16 *)(gfx + 0x80) = 0x8000;
        *(u16 *)(gfx + 0x7c) = 0;
    }
    TaskBase_dtor(self);
    return self;
}

void Ov002Task_UpdateActive(void) {
}

Task021ef430 *Ov002TaskVt_021ef430_DtorDelete(Task021ef430 *self) {
    void *saved;
    *(VFunc **)self = data_ov002_021ef430;
    HEAP_PUSH(saved);
    Task_deleteModel(self);
    HEAP_POP(saved);
    if (self->unk_4f) {
        ResMgr_ReleaseArchive(data_ov002_021ef3e4, data_ov002_021ef3f9, 2);
    }
    self->unk_4f = 0;
    TaskBase_dtor(self);
    Heap_Free(self);
    return self;
}

Task021ef430 *Ov002TaskVt_021ef430_Dtor(Task021ef430 *self) {
    void *saved;
    *(VFunc **)self = data_ov002_021ef430;
    HEAP_PUSH(saved);
    Task_deleteModel(self);
    HEAP_POP(saved);
    if (self->unk_4f) {
        ResMgr_ReleaseArchive(data_ov002_021ef3e4, data_ov002_021ef3f9, 2);
    }
    self->unk_4f = 0;
    TaskBase_dtor(self);
    return self;
}

Task021ef530 *Ov002TaskVt_021ef530_DtorDelete(Task021ef530 *self) {
    *(VFunc **)self = data_ov002_021ef530;
    self->vfunc_5c();
    TaskBase_dtor(self);
    Heap_Free(self);
    return self;
}

BOOL Task021ef530_TryReleaseCurrent(Task021ef530 *self) {
    if (self->vfunc_54() != 0) {
        func_ov002_setCurrent021ccd40(NULL);
    }
    return TRUE;
}

Task021ef530 *Ov002TaskVt_021ef530_Dtor(Task021ef530 *self) {
    *(VFunc **)self = data_ov002_021ef530;
    self->vfunc_5c();
    TaskBase_dtor(self);
    return self;
}

void *Ov002Vt_021ef410_DtorDelete(void *self) {
    *(VFunc **)self = data_ov002_021ef410;
    Buffer0216f144_Free(self);
    Heap_Free(self);
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
        GfxSys_StartFadeIn(0xa000, 0, 1);
    }
}

BOOL func_ov002_021cf990(void) {
    return FALSE;
}

void *Ov002Vt_021ef410_Dtor(void *self) {
    *(VFunc **)self = data_ov002_021ef410;
    Buffer0216f144_Free(self);
    return self;
}

Task021ef79c *Task021ef79c_New(void) {
    Task021ef79c *p = (Task021ef79c *)Heap_Alloc(0x48);
    if (p != NULL) {
        TaskBase_ctor(p);
        *(VFunc **)p = data_ov002_021ef79c;
        p->unk_3c = NULL;
        p->unk_40 = NULL;
        p->unk_44 = 0;
    }
    p->vfunc_08(0x13, 0x64);
    return p;
}

Task021ef79c *Ov002TaskVt_021ef79c_Dtor(Task021ef79c *self) {
    void *saved;
    *(VFunc **)self = data_ov002_021ef79c;
    HEAP_PUSH(saved);
    DELETE_VOBJ(self->unk_3c);
    HEAP_POP(saved);
    HEAP_PUSH(saved);
    DELETE_VOBJ(self->unk_40);
    HEAP_POP(saved);
    TaskBase_dtor(self);
    return self;
}

Task021ef79c *Ov002TaskVt_021ef79c_DtorDelete(Task021ef79c *self) {
    void *saved;
    *(VFunc **)self = data_ov002_021ef79c;
    HEAP_PUSH(saved);
    DELETE_VOBJ(self->unk_3c);
    HEAP_POP(saved);
    HEAP_PUSH(saved);
    DELETE_VOBJ(self->unk_40);
    HEAP_POP(saved);
    TaskBase_dtor(self);
    Heap_Free(self);
    return self;
}

}
