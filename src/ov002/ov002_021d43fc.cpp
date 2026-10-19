#include "ov002/ov002.h"

extern "C" {

void func_ov002_021d43fc(void) {
}

void func_ov002_021d4400(Task50 *self) {
    bool r;
    if (self->unk_08 == 8 || self->unk_08 == 10) {
        return;
    }
    if (self->unk_08 != 0xd) {
        return;
    }
    r = true;
    r = r & (((VObject *)self->unk_3c)->v0x1c() == 0);
    r = r & (self->unk_40->v0x1c() == 0);
    r = r & (self->unk_44->v0x1c() == 0);
    r = r & (FIELD(self, 0x48, VObject *)->v0x1c() == 0);
    if (r) {
        self->v0xc(0);
    }
}

void func_ov002_021d44e0(void) {
}

void func_ov002_021d44e4(Task50 *self) {
    if (self->unk_24 != 0) {
        func_ov000_0217357c(self);
        TASK_VOBJ(self, 0x3c)->v0x20();
        self->unk_40->v0x20();
        self->unk_44->v0x20();
        TASK_VOBJ(self, 0x48)->v0x20();
    }
}

void func_ov002_021d4540(void *dst, u32 size, void *a, void *b, int mode) {
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

Task50 *func_ov002_021d45fc(Task50 *self) {
    *(VFunc **)self = data_ov002_021ef81c;
    func_ov002_021d3ccc(self);
    TaskBase_dtor(self);
    func_0203de1c(self);
    return self;
}

Task50 *func_ov002_021d4640(Task50 *self) {
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

Task50 *func_ov002_021d4688(Task50 *self) {
    *(VFunc **)self = data_ov002_021ef91c;
    self->v0x5c();
    func_ov002_021e49c0((u8 *)self + 0xac);
    func_ov002_021e473c((u8 *)self + 0x94);
    TaskBase_dtor(self);
    func_0203de1c(self);
    return self;
}

Task50 *func_ov002_021d46e4(Task50 *self) {
    *(VFunc **)self = data_ov002_021ef91c;
    self->v0x5c();
    func_ov002_021e49c0((u8 *)self + 0xac);
    func_ov002_021e473c((u8 *)self + 0x94);
    TaskBase_dtor(self);
    return self;
}

Task50 *func_ov002_021d4738(Task50 *self) {
    *(VFunc **)self = data_ov002_021ef99c;
    func_ov002_021d25ec(self);
    __cxa_vec_cleanup((u8 *)self + 0x4c, 7, 0x18, (void (*)(void *))func_ov002_021e473c);
    TaskBase_dtor(self);
    func_0203de1c(self);
    return self;
}

Task50 *func_ov002_021d4794(Task50 *self) {
    *(VFunc **)self = data_ov002_021ef99c;
    func_ov002_021d25ec(self);
    __cxa_vec_cleanup((u8 *)self + 0x4c, 7, 0x18, (void (*)(void *))func_ov002_021e473c);
    TaskBase_dtor(self);
    return self;
}

Task50 *func_ov002_021d47e8(Task50 *self) {
    u32 saved;
    *(VFunc **)self = data_ov002_021ef69c;
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

Task50 *func_ov002_021d48b0(Task50 *self) {
    u32 saved;
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

Task50 *func_ov002_021d4974(Task50 *self) {
    u32 saved;
    *(VFunc **)self = data_ov002_021ef89c;
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

Task50 *func_ov002_021d4a3c(Task50 *self) {
    u32 saved;
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

Task50 *func_ov002_021d4afc(Task50 *self) {
    u32 saved;
    *(VFunc **)self = data_ov002_021efa1c;
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

Task50 *func_ov002_021d4bc4(Task50 *self) {
    u32 saved;
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

void *func_ov002_021d4c84(void *self) {
    *(VFunc **)self = data_ov002_021ef684;
    func_ov000_021c2310(self);
    func_0203de1c(self);
    return self;
}

void func_ov002_021d4cac(void) {
}

void func_ov002_021d4cb0(void) {
}

void *func_ov002_021d4cb4(void *self) {
    *(VFunc **)self = data_ov002_021ef684;
    func_ov000_021c2310(self);
    return self;
}

void *func_ov002_021d4cd4(void *self) {
    func_0203de1c(self);
    return self;
}

Task50 *func_ov002_021d4ce8(void) {
    Task50 *p = (Task50 *)func_0203dd9c(0x40);
    if (p != NULL) {
        TaskBase_ctor(p);
        *(VFunc **)p = data_ov002_021efba4;
        p->unk_3c = NULL;
    }
    p->v0x8(0x1b, 0x64);
    return p;
}

Task50 *func_ov002_021d4d48(Task50 *self) {
    u32 saved;
    char buf[0x20];
    *(VFunc **)self = data_ov002_021efba4;
    HEAP_PUSH(saved);
    DELETE_VOBJ(TASK_VOBJ(self, 0x3c));
    HEAP_POP(saved);
    func_0206e900(buf, data_ov002_021efad1);
    func_02036838(data_02097cdc, buf, 7, 0);
    TaskBase_dtor(self);
    return self;
}

void *func_ov002_021d4e00(void *self) {
    *(VFunc **)self = data_ov002_021efb14;
    func_ov002_021e1d28(self);
    func_0203de1c(self);
    return self;
}

Task50 *func_ov002_021d4e28(Task50 *self) {
    u32 saved;
    char buf[0x20];
    *(VFunc **)self = data_ov002_021efba4;
    HEAP_PUSH(saved);
    DELETE_VOBJ(TASK_VOBJ(self, 0x3c));
    HEAP_POP(saved);
    func_0206e900(buf, data_ov002_021efad1);
    func_02036838(data_02097cdc, buf, 7, 0);
    TaskBase_dtor(self);
    func_0203de1c(self);
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

static inline void *func_ov002_021d4f58_ctor(void *self) {
    *(VFunc **)self = data_ov002_021efb14;
    func_ov002_021e1cc8(self);
    return self;
}

void func_ov002_021d4f58(Task50 *self) {
    void *p;
    self->flag1 = 0;
    if (self->v0x28() != 0) {
        return;
    }
    p = func_0203dd9c(0x44);
    if (p != NULL) {
        func_ov002_021d4f58_ctor(p);
    }
    self->unk_3c = p;
    func_ov002_021e1ed8(p);
    func_ov002_021e2690(self->unk_3c, 0, 0);
    self->unk_20 = 0x1000;
    func_ov000_02173648(self);
}

void func_ov002_021d4fd0(Task50 *self) {
    switch (self->unk_08) {
    case 0xc:
        func_ov000_0218084c(data_ov000_021ccd44, 0x1c, 0);
        self->v0x4c();
        break;
    case 0xd:
        if (self->v0x54() != 0) {
            self->flag1 = 1;
            self->v0xc(0);
        }
        break;
    }
    func_ov002_021e23ac(self->unk_3c);
}

void func_ov002_021d505c(void) {
}

void func_ov002_021d5060(Task50 *self) {
    func_ov002_021e2528(self->unk_3c);
}

Task50 *func_ov002_021d5070(void) {
    Task50 *p = (Task50 *)func_0203dd9c(0x3c);
    if (p != NULL) {
        TaskBase_ctor(p);
        *(VFunc **)p = data_ov002_021efb24;
    }
    p->v0x8(0x1c, 0x64);
    return p;
}

void func_ov002_021d50c8(void) {
    func_ov002_021da2fc();
    func_ov002_021da5c0(func_ov002_021da420());
}

void func_ov002_021d50dc(void) {
    func_ov002_021da800(func_ov002_021da420());
}

void func_ov002_021d50ec(Task50 *self) {
    BOOL clear = Task50_isFlag1Clear(self);
    if (!clear) {
        self->flag1 = 0;
    }
    if (self->v0x28() != 0) {
        return;
    }
    func_ov002_021da894(func_ov002_021da420());
    self->v0x40();
    func_ov000_02173648(self);
}

void func_ov002_021d5154(Task50 *self) {
    switch (self->unk_08) {
    case 8:
        func_ov002_021dab58(func_ov002_021da420(), 0);
        break;
    case 0xd:
        if (func_ov002_021da8d8(func_ov002_021da420()) != 0) {
            break;
        }
        if (FIELD(func_ov002_021da420(), 0xc, s32) == 2) {
            func_ov000_0218084c(data_ov000_021ccd44, 0x1d, 0);
            self->flag1 = 1;
            self->flag2 = 1;
            self->v0x4c();
        } else {
            func_ov000_0218084c(data_ov000_021ccd44, 0x1b, 0);
            self->flag1 = 1;
            self->flag2 = 1;
            self->v0x4c();
        }
        break;
    }
}

void func_ov002_021d520c(void *p) {
    if (data_ov000_021ccd40 == p) {
        func_ov002_021da960(func_ov002_021da420());
    }
}

Task50 *func_ov002_021d5230(void) {
    Task50 *p = (Task50 *)func_0203dd9c(0x78);
    if (p != NULL) {
        TaskBase_ctor(p);
        *(VFunc **)p = data_ov002_021efc24;
        FIELD(p, 0x3c, s32) = 0;
        FIELD(p, 0x40, s32) = 0;
        FIELD(p, 0x44, s32) = 0;
        FIELD(p, 0x48, s32) = 0;
        FIELD(p, 0x4c, s32) = 0;
        FIELD(p, 0x50, s32) = 0;
        FIELD(p, 0x54, s32) = 0;
        FIELD(p, 0x58, s32) = 0;
        FIELD(p, 0x5c, s32) = 0;
        MI_CpuFill8((u8 *)p + 0x60, 0, 10);
        MI_CpuFill8((u8 *)p + 0x6a, 0, 10);
        FIELD(p, 0x74, u16) = 0xffff;
    }
    p->v0x8(0x1d, 0x64);
    return p;
}

BOOL func_ov002_021d52e0(void *self, void *ev) {
    void *t;
    if (ev != NULL) {
        if (FIELD(ev, 0x6, u16) == 0) {
            func_ov002_021d5f60(FIELD(self, 0x8, void *));
        } else {
            func_02049a48(data_02097e4c, 0x1f, -1, -1, -1);
        }
    }
    t = func_ov000_02173610(0x1b);
    if (t != NULL && FIELD(t, 0x3c, void *) != NULL) {
        func_ov002_021e2690(FIELD(t, 0x3c, void *), 9, 0);
    }
    return FALSE;
}

BOOL func_ov002_021d5350(void *self, void *ev) {
    u8 *owner = FIELD(self, 0x8, u8 *);
    u16 id;
    void *t;
    if (ev != NULL) {
        id = FIELD(ev, 0x6, u16);
        if (FIELD(owner, 0x54, VObject *) != NULL) {
            func_ov000_0215bb14(FIELD(owner, 0x54, VObject *), func_0206ec8c(id));
            FIELD(owner, 0x54, VObject *)->v0x70();
        }
        if (FIELD(owner, 0x58, void *) != NULL) {
            u8 *info = func_0206ef10(id);
            func_ov000_02162b40(FIELD(owner, 0x58, void *), FIELD(info, 0xc, s32), FIELD(info, 0x10, s32), data_ov002_021efae1,
                                FIELD(info, 0x28, s32), data_ov002_021efaeb, info[0x24], 0x1000);
        }
        func_ov000_021c95ac(owner + 0x60, id);
        t = func_ov000_02173610(0x1b);
        if (t != NULL) {
            if (FIELD(t, 0x3c, u8 *) != NULL) {
                MI_CpuCopy8(owner + 0x60, FIELD(t, 0x3c, u8 *) + 0x2c, 0x14);
            }
            if (FIELD(t, 0x3c, void *) != NULL) {
                func_ov002_021e2754(FIELD(t, 0x3c, void *), id);
            }
        }
    }
    return TRUE;
}

BOOL func_ov002_021d5444(void *self, void *ev) {
    if (ev != NULL) {
        if (FIELD(ev, 6, u16) != FIELD(FIELD(self, 8, void *), 0x74, u16)) {
            void *t;
            func_02049a48(data_02097e4c, 0x1e, -1, -1, -1);
            func_ov000_02152294(self, 0x8d, 0x23, func_ov002_021d52e0);
            t = func_ov000_02173610(0x1b);
            if (t != NULL && FIELD(t, 0x3c, void *) != NULL) {
                func_ov002_021e2690(FIELD(t, 0x3c, void *), 0, 0);
            }
        } else {
            func_02049a48(data_02097e4c, 0x20, -1, -1, -1);
        }
    }
    return TRUE;
}

}
