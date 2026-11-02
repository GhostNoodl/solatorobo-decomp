#include "ov002/ov002.h"

extern "C" {

void func_ov002_021d43fc(void) {
}

void func_ov002_021d4400(Task021ef81c *self) {
    bool r;
    if (self->state == 8 || self->state == 10) {
        return;
    }
    if (self->state != 0xd) {
        return;
    }
    r = true;
    r = r & (((VObj *)self->unk_3c)->vfunc_1c() == 0);
    r = r & (self->unk_40->vfunc_1c() == 0);
    r = r & (self->unk_44->vfunc_1c() == 0);
    r = r & (self->unk_48->vfunc_1c() == 0);
    if (r) {
        self->vfunc_0c(0);
    }
}

void func_ov002_021d44e0(void) {
}

void func_ov002_021d44e4(Task021ef81c *self) {
    if (self->fadeRatio != 0) {
        func_ov000_0217357c(self);
        TASK_VOBJ(self, 0x3c)->vfunc_20();
        self->unk_40->vfunc_20();
        self->unk_44->vfunc_20();
        TASK_VOBJ(self, 0x48)->vfunc_20();
    }
}

void func_ov002_021d4540(void *dst, u32 size, const void *a, const void *b, int mode) {
    const u8 *s;
    MI_CpuFill8(dst, 0, size);
    switch (mode) {
    case 0:
        s = data_ov002_021ef650;
        break;
    case 1:
        s = data_ov002_021ef651;
        break;
    case 2:
        s = data_ov002_021ef655;
        break;
    case 3:
        s = data_ov002_021ef659;
        break;
    case 4:
        s = data_ov002_021ef65d;
        break;
    case 5:
        s = data_ov002_021ef661;
        break;
    default:
        s = data_ov002_021ef651;
        break;
    }
    STD_TSNPrintf(dst, size, data_ov002_021ef665, a, s, b);
}

Task021ef81c *Ov002TaskVt_021ef81c_DtorDelete(Task021ef81c *self) {
    *(VFunc **)self = data_ov002_021ef81c;
    func_ov002_021d3ccc(self);
    TaskBase_dtor(self);
    Heap_Free(self);
    return self;
}

Task021ef81c *Ov002TaskVt_021ef81c_Dtor(Task021ef81c *self) {
    *(VFunc **)self = data_ov002_021ef81c;
    func_ov002_021d3ccc(self);
    TaskBase_dtor(self);
    return self;
}

BOOL func_ov002_021d467c(void) {
    return TRUE;
}

void func_ov002_021d4684(void) {
}

Task021ef91c *Ov002TaskVt_021ef91c_DtorDelete(Task021ef91c *self) {
    *(VFunc **)self = data_ov002_021ef91c;
    self->vfunc_5c();
    Ov002Vt_021f00ec_Dtor(&self->unk_ac);
    Ov002Vt_021f00fc_Dtor(&self->unk_94);
    TaskBase_dtor(self);
    Heap_Free(self);
    return self;
}

Task021ef91c *Ov002TaskVt_021ef91c_Dtor(Task021ef91c *self) {
    *(VFunc **)self = data_ov002_021ef91c;
    self->vfunc_5c();
    Ov002Vt_021f00ec_Dtor(&self->unk_ac);
    Ov002Vt_021f00fc_Dtor(&self->unk_94);
    TaskBase_dtor(self);
    return self;
}

Task021ef99c *Ov002TaskVt_021ef99c_DtorDelete(Task021ef99c *self) {
    *(VFunc **)self = data_ov002_021ef99c;
    func_ov002_021d25ec(self);
    __cxa_vec_cleanup(self->unk_4c, 7, 0x18, (void (*)(void *))Ov002Vt_021f00fc_Dtor);
    TaskBase_dtor(self);
    Heap_Free(self);
    return self;
}

Task021ef99c *Ov002TaskVt_021ef99c_Dtor(Task021ef99c *self) {
    *(VFunc **)self = data_ov002_021ef99c;
    func_ov002_021d25ec(self);
    __cxa_vec_cleanup(self->unk_4c, 7, 0x18, (void (*)(void *))Ov002Vt_021f00fc_Dtor);
    TaskBase_dtor(self);
    return self;
}

Task021ef69c *Ov002TaskVt_021ef69c_DtorDelete(Task021ef69c *self) {
    void *saved;
    *(VFunc **)self = data_ov002_021ef69c;
    HEAP_PUSH(saved);
    DELETE_VOBJ(TASK_VOBJ(self, 0x3c));
    HEAP_POP(saved);
    HEAP_PUSH(saved);
    DELETE_VOBJ(self->unk_40);
    HEAP_POP(saved);
    TaskBase_dtor(self);
    Heap_Free(self);
    return self;
}

Task021ef69c *Ov002TaskVt_021ef69c_Dtor(Task021ef69c *self) {
    void *saved;
    *(VFunc **)self = data_ov002_021ef69c;
    HEAP_PUSH(saved);
    DELETE_VOBJ(TASK_VOBJ(self, 0x3c));
    HEAP_POP(saved);
    HEAP_PUSH(saved);
    DELETE_VOBJ(self->unk_40);
    HEAP_POP(saved);
    TaskBase_dtor(self);
    return self;
}

void func_ov002_021d4970(void) {
}

Task021ef89c *Ov002TaskVt_021ef89c_DtorDelete(Task021ef89c *self) {
    void *saved;
    *(VFunc **)self = data_ov002_021ef89c;
    HEAP_PUSH(saved);
    DELETE_VOBJ(TASK_VOBJ(self, 0x3c));
    HEAP_POP(saved);
    HEAP_PUSH(saved);
    DELETE_VOBJ(self->unk_40);
    HEAP_POP(saved);
    TaskBase_dtor(self);
    Heap_Free(self);
    return self;
}

Task021ef89c *Ov002TaskVt_021ef89c_Dtor(Task021ef89c *self) {
    void *saved;
    *(VFunc **)self = data_ov002_021ef89c;
    HEAP_PUSH(saved);
    DELETE_VOBJ(TASK_VOBJ(self, 0x3c));
    HEAP_POP(saved);
    HEAP_PUSH(saved);
    DELETE_VOBJ(self->unk_40);
    HEAP_POP(saved);
    TaskBase_dtor(self);
    return self;
}

Task021efa1c *Ov002TaskVt_021efa1c_DtorDelete(Task021efa1c *self) {
    void *saved;
    *(VFunc **)self = data_ov002_021efa1c;
    HEAP_PUSH(saved);
    DELETE_VOBJ(TASK_VOBJ(self, 0x3c));
    HEAP_POP(saved);
    HEAP_PUSH(saved);
    DELETE_VOBJ(self->unk_40);
    HEAP_POP(saved);
    TaskBase_dtor(self);
    Heap_Free(self);
    return self;
}

Task021efa1c *Ov002TaskVt_021efa1c_Dtor(Task021efa1c *self) {
    void *saved;
    *(VFunc **)self = data_ov002_021efa1c;
    HEAP_PUSH(saved);
    DELETE_VOBJ(TASK_VOBJ(self, 0x3c));
    HEAP_POP(saved);
    HEAP_PUSH(saved);
    DELETE_VOBJ(self->unk_40);
    HEAP_POP(saved);
    TaskBase_dtor(self);
    return self;
}

void *Ov002Vt_021ef684_DtorDelete(void *self) {
    *(VFunc **)self = data_ov002_021ef684;
    func_ov000_021c2310(self);
    Heap_Free(self);
    return self;
}

void func_ov002_021d4cac(void) {
}

void func_ov002_021d4cb0(void) {
}

void *Ov002Vt_021ef684_Dtor(void *self) {
    *(VFunc **)self = data_ov002_021ef684;
    func_ov000_021c2310(self);
    return self;
}

void *func_ov002_021d4cd4(void *self) {
    Heap_Free(self);
    return self;
}

Task021efba4 *func_ov002_021d4ce8(void) {
    Task021efba4 *p = (Task021efba4 *)Heap_Alloc(0x40);
    if (p != NULL) {
        TaskBase_ctor(p);
        *(VFunc **)p = data_ov002_021efba4;
        p->hud = NULL;
    }
    p->vfunc_08(0x1b, 0x64);
    return p;
}

Task021efba4 *Ov002TaskVt_021efba4_Dtor(Task021efba4 *self) {
    void *saved;
    char buf[0x20];
    *(VFunc **)self = data_ov002_021efba4;
    HEAP_PUSH(saved);
    DELETE_VOBJ(self->hud);
    HEAP_POP(saved);
    func_0206e900(buf, data_ov002_021efad1);
    func_02036838(data_02097cdc, buf, 7, 0);
    TaskBase_dtor(self);
    return self;
}

Ov002Hud *Ov002Vt_021efb14_DtorDelete(Ov002Hud *self) {
    *(VFunc **)self = data_ov002_021efb14;
    func_ov002_021e1d28(self);
    Heap_Free(self);
    return self;
}

Task021efba4 *Ov002TaskVt_021efba4_DtorDelete(Task021efba4 *self) {
    void *saved;
    char buf[0x20];
    *(VFunc **)self = data_ov002_021efba4;
    HEAP_PUSH(saved);
    DELETE_VOBJ(self->hud);
    HEAP_POP(saved);
    func_0206e900(buf, data_ov002_021efad1);
    func_02036838(data_02097cdc, buf, 7, 0);
    TaskBase_dtor(self);
    Heap_Free(self);
    return self;
}

void func_ov002_021d4ee8(void) {
    char buf[0x20];
    func_0206e900(buf, data_ov002_021efad1);
    func_020359d0(buf, 7, 0);
}

bool func_ov002_021d4f1c(void) {
    char buf[0x20];
    func_0206e900(buf, data_ov002_021efad1);
    return func_02035b90(buf, 7) != 0;
}

static inline Ov002Hud *func_ov002_021d4f58_ctor(Ov002Hud *self) {
    *(VFunc **)self = data_ov002_021efb14;
    func_ov002_021e1cc8(self);
    return self;
}

void func_ov002_021d4f58(Task021efba4 *self) {
    Ov002Hud *p;
    self->unk_04_1 = 0;
    if (self->vfunc_28() != 0) {
        return;
    }
    p = (Ov002Hud *)Heap_Alloc(sizeof(Ov002Hud));
    if (p != NULL) {
        func_ov002_021d4f58_ctor(p);
    }
    self->hud = p;
    func_ov002_021e1ed8(p);
    func_ov002_021e2690(self->hud, 0, 0);
    self->fadeLen = 0x1000;
    func_ov000_02173648(self);
}

void func_ov002_021d4fd0(Task021efba4 *self) {
    switch (self->state) {
    case 0xc:
        func_ov000_0218084c(data_ov000_021ccd44, 0x1c, 0);
        self->vfunc_4c();
        break;
    case 0xd:
        if (self->vfunc_54() != 0) {
            self->unk_04_1 = 1;
            self->vfunc_0c(0);
        }
        break;
    }
    func_ov002_021e23ac(self->hud);
}

void func_ov002_021d505c(void) {
}

void func_ov002_021d5060(Task021efba4 *self) {
    func_ov002_021e2528(self->hud);
}

Task021efb24 *func_ov002_021d5070(void) {
    Task021efb24 *p = (Task021efb24 *)Heap_Alloc(0x3c);
    if (p != NULL) {
        TaskBase_ctor(p);
        *(VFunc **)p = data_ov002_021efb24;
    }
    p->vfunc_08(0x1c, 0x64);
    return p;
}

void func_ov002_021d50c8(void) {
    func_ov002_021da2fc();
    func_ov002_021da5c0(func_ov002_021da420());
}

void func_ov002_021d50dc(void) {
    func_ov002_021da800(func_ov002_021da420());
}

void func_ov002_021d50ec(Task021efb24 *self) {
    BOOL clear = Task_isFlag1Clear(self);
    if (!clear) {
        self->unk_04_1 = 0;
    }
    if (self->vfunc_28() != 0) {
        return;
    }
    func_ov002_021da894(func_ov002_021da420());
    self->vfunc_40();
    func_ov000_02173648(self);
}

void func_ov002_021d5154(Task021efb24 *self) {
    switch (self->state) {
    case 8:
        func_ov002_021dab58(func_ov002_021da420(), 0);
        break;
    case 0xd:
        if (func_ov002_021da8d8(func_ov002_021da420()) != 0) {
            break;
        }
        if (func_ov002_021da420()->unk_0c == 2) {
            func_ov000_0218084c(data_ov000_021ccd44, 0x1d, 0);
            self->unk_04_1 = 1;
            self->unk_04_2 = 1;
            self->vfunc_4c();
        } else {
            func_ov000_0218084c(data_ov000_021ccd44, 0x1b, 0);
            self->unk_04_1 = 1;
            self->unk_04_2 = 1;
            self->vfunc_4c();
        }
        break;
    }
}

void func_ov002_021d520c(Task021efb24 *p) {
    if (data_ov000_021ccd40 == p) {
        func_ov002_021da960(func_ov002_021da420());
    }
}

Task021efc24 *func_ov002_021d5230(void) {
    Task021efc24 *p = (Task021efc24 *)Heap_Alloc(0x78);
    if (p != NULL) {
        TaskBase_ctor(p);
        *(VFunc **)p = data_ov002_021efc24;
        p->unk_3c = NULL;
        p->unk_40 = NULL;
        p->unk_44 = NULL;
        p->unk_48 = 0;
        p->unk_4c = NULL;
        p->unk_50 = NULL;
        p->unk_54 = NULL;
        p->unk_58 = NULL;
        p->unk_5c = NULL;
        MI_CpuFill8((u8 *)p + 0x60, 0, 10);
        MI_CpuFill8((u8 *)p + 0x6a, 0, 10);
        p->unk_74 = 0xffff;
    }
    p->vfunc_08(0x1d, 0x64);
    return p;
}

BOOL func_ov002_021d52e0(void *self, void *ev) {
    Task021efba4 *t;
    if (ev != NULL) {
        if (FIELD(ev, 0x6, u16) == 0) {
            func_ov002_021d5f60(FIELD(self, 0x8, void *));
        } else {
            func_02049a48(data_02097e4c, 0x1f, -1, -1, -1);
        }
    }
    t = (Task021efba4 *)Task_FindById(0x1b);
    if (t != NULL && t->hud != NULL) {
        func_ov002_021e2690(t->hud, 9, 0);
    }
    return FALSE;
}

BOOL func_ov002_021d5350(void *self, void *ev) {
    u8 *owner = FIELD(self, 0x8, u8 *);
    u16 id;
    Task021efba4 *t;
    if (ev != NULL) {
        id = FIELD(ev, 0x6, u16);
        if (FIELD(owner, 0x54, VObj *) != NULL) {
            func_ov000_0215bb14(FIELD(owner, 0x54, VObj *), func_0206ec8c(id));
            FIELD(owner, 0x54, VObj *)->vfunc_70();
        }
        if (FIELD(owner, 0x58, void *) != NULL) {
            u8 *info = func_0206ef10(id);
            func_ov000_02162b40(FIELD(owner, 0x58, void *), FIELD(info, 0xc, s32), FIELD(info, 0x10, s32), data_ov002_021efae1,
                                FIELD(info, 0x28, s32), data_ov002_021efaeb, info[0x24], 0x1000);
        }
        func_ov000_021c95ac(owner + 0x60, id);
        t = (Task021efba4 *)Task_FindById(0x1b);
        if (t != NULL) {
            if (t->hud != NULL) {
                MI_CpuCopy8(owner + 0x60, t->hud->unk_2c, 0x14);
            }
            if (t->hud != NULL) {
                func_ov002_021e2754(t->hud, id);
            }
        }
    }
    return TRUE;
}

BOOL func_ov002_021d5444(void *self, void *ev) {
    if (ev != NULL) {
        if (FIELD(ev, 6, u16) != FIELD(FIELD(self, 8, void *), 0x74, u16)) {
            Task021efba4 *t;
            func_02049a48(data_02097e4c, 0x1e, -1, -1, -1);
            func_ov000_02152294(self, 0x8d, 0x23, func_ov002_021d52e0);
            t = (Task021efba4 *)Task_FindById(0x1b);
            if (t != NULL && t->hud != NULL) {
                func_ov002_021e2690(t->hud, 0, 0);
            }
        } else {
            func_02049a48(data_02097e4c, 0x20, -1, -1, -1);
        }
    }
    return TRUE;
}

}
