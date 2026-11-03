#include "ov002/ov002.h"

extern "C" {

void Task021ef81c_UpdateActive(void) {
}

void Task021ef81c_PreUpdate(Task021ef81c *self) {
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

void Task021ef81c_PostUpdate(void) {
}

void Task021ef81c_Draw(Task021ef81c *self) {
    if (self->fadeRatio != 0) {
        Task_Draw(self);
        self->unk_3c->vfunc_20();
        self->unk_40->vfunc_20();
        self->unk_44->vfunc_20();
        self->unk_48->vfunc_20();
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
    *(VFunc **)self = Ov002TaskVt_021ef81c_vtbl;
    Task021ef81c_FreeWindows(self);
    TaskBase_dtor(self);
    Heap_Free(self);
    return self;
}

Task021ef81c *Ov002TaskVt_021ef81c_Dtor(Task021ef81c *self) {
    *(VFunc **)self = Ov002TaskVt_021ef81c_vtbl;
    Task021ef81c_FreeWindows(self);
    TaskBase_dtor(self);
    return self;
}

BOOL Ov002Task_IsLoaded(void) {
    return TRUE;
}

void Ov002Task_Load(void) {
}

Task021ef91c *Ov002TaskVt_021ef91c_DtorDelete(Task021ef91c *self) {
    *(VFunc **)self = Ov002TaskVt_021ef91c_vtbl;
    self->vfunc_5c();
    Ov002Vt_021f00ec_Dtor(&self->unk_ac);
    Ov002Vt_021f00fc_Dtor(&self->unk_94);
    TaskBase_dtor(self);
    Heap_Free(self);
    return self;
}

Task021ef91c *Ov002TaskVt_021ef91c_Dtor(Task021ef91c *self) {
    *(VFunc **)self = Ov002TaskVt_021ef91c_vtbl;
    self->vfunc_5c();
    Ov002Vt_021f00ec_Dtor(&self->unk_ac);
    Ov002Vt_021f00fc_Dtor(&self->unk_94);
    TaskBase_dtor(self);
    return self;
}

Task021ef99c *Ov002TaskVt_021ef99c_DtorDelete(Task021ef99c *self) {
    *(VFunc **)self = Ov002TaskVt_021ef99c_vtbl;
    Task021ef99c_FreeWindows(self);
    __cxa_vec_cleanup(self->unk_4c, 7, 0x18, (void (*)(void *))Ov002Vt_021f00fc_Dtor);
    TaskBase_dtor(self);
    Heap_Free(self);
    return self;
}

Task021ef99c *Ov002TaskVt_021ef99c_Dtor(Task021ef99c *self) {
    *(VFunc **)self = Ov002TaskVt_021ef99c_vtbl;
    Task021ef99c_FreeWindows(self);
    __cxa_vec_cleanup(self->unk_4c, 7, 0x18, (void (*)(void *))Ov002Vt_021f00fc_Dtor);
    TaskBase_dtor(self);
    return self;
}

Task021ef69c *Ov002TaskVt_021ef69c_DtorDelete(Task021ef69c *self) {
    void *saved;
    *(VFunc **)self = Ov002TaskVt_021ef69c_vtbl;
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

Task021ef69c *Ov002TaskVt_021ef69c_Dtor(Task021ef69c *self) {
    void *saved;
    *(VFunc **)self = Ov002TaskVt_021ef69c_vtbl;
    HEAP_PUSH(saved);
    DELETE_VOBJ(self->unk_3c);
    HEAP_POP(saved);
    HEAP_PUSH(saved);
    DELETE_VOBJ(self->unk_40);
    HEAP_POP(saved);
    TaskBase_dtor(self);
    return self;
}

void Ov002Task_PostUpdate(void) {
}

Task021ef89c *Ov002TaskVt_021ef89c_DtorDelete(Task021ef89c *self) {
    void *saved;
    *(VFunc **)self = Ov002TaskVt_021ef89c_vtbl;
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

Task021ef89c *Ov002TaskVt_021ef89c_Dtor(Task021ef89c *self) {
    void *saved;
    *(VFunc **)self = Ov002TaskVt_021ef89c_vtbl;
    HEAP_PUSH(saved);
    DELETE_VOBJ(self->unk_3c);
    HEAP_POP(saved);
    HEAP_PUSH(saved);
    DELETE_VOBJ(self->unk_40);
    HEAP_POP(saved);
    TaskBase_dtor(self);
    return self;
}

Task021efa1c *Ov002TaskVt_021efa1c_DtorDelete(Task021efa1c *self) {
    void *saved;
    *(VFunc **)self = Ov002TaskVt_021efa1c_vtbl;
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

Task021efa1c *Ov002TaskVt_021efa1c_Dtor(Task021efa1c *self) {
    void *saved;
    *(VFunc **)self = Ov002TaskVt_021efa1c_vtbl;
    HEAP_PUSH(saved);
    DELETE_VOBJ(self->unk_3c);
    HEAP_POP(saved);
    HEAP_PUSH(saved);
    DELETE_VOBJ(self->unk_40);
    HEAP_POP(saved);
    TaskBase_dtor(self);
    return self;
}

void *Ov002Vt_021ef684_DtorDelete(void *self) {
    *(VFunc **)self = Ov002Vt_021ef684_vtbl;
    ListRow_Unlink(self);
    Heap_Free(self);
    return self;
}

void func_ov002_021d4cac(void) {
}

void func_ov002_021d4cb0(void) {
}

void *Ov002Vt_021ef684_Dtor(void *self) {
    *(VFunc **)self = Ov002Vt_021ef684_vtbl;
    ListRow_Unlink(self);
    return self;
}

void *Ov002Vt_021ef674_DtorDelete(void *self) {
    Heap_Free(self);
    return self;
}

Task021efba4 *Task021efba4_New(void) {
    Task021efba4 *p = (Task021efba4 *)Heap_Alloc(0x40);
    if (p != NULL) {
        TaskBase_ctor(p);
        *(VFunc **)p = Ov002TaskVt_021efba4_vtbl;
        p->hud = NULL;
    }
    p->vfunc_08(0x1b, 0x64);
    return p;
}

Task021efba4 *Ov002TaskVt_021efba4_Dtor(Task021efba4 *self) {
    void *saved;
    char buf[0x20];
    *(VFunc **)self = Ov002TaskVt_021efba4_vtbl;
    HEAP_PUSH(saved);
    DELETE_VOBJ(self->hud);
    HEAP_POP(saved);
    LangData_LocalizePath(buf, data_ov002_021efad1);
    ResMgr_ReleaseByName(gResMgr, buf, 7, 0);
    TaskBase_dtor(self);
    return self;
}

Ov002Hud *Ov002Vt_021efb14_DtorDelete(Ov002Hud *self) {
    *(VFunc **)self = Ov002Vt_021efb14_vtbl;
    Ov002Hud_Release(self);
    Heap_Free(self);
    return self;
}

Task021efba4 *Ov002TaskVt_021efba4_DtorDelete(Task021efba4 *self) {
    void *saved;
    char buf[0x20];
    *(VFunc **)self = Ov002TaskVt_021efba4_vtbl;
    HEAP_PUSH(saved);
    DELETE_VOBJ(self->hud);
    HEAP_POP(saved);
    LangData_LocalizePath(buf, data_ov002_021efad1);
    ResMgr_ReleaseByName(gResMgr, buf, 7, 0);
    TaskBase_dtor(self);
    Heap_Free(self);
    return self;
}

void Task021efba4_Load(void) {
    char buf[0x20];
    LangData_LocalizePath(buf, data_ov002_021efad1);
    ResMgr_Load(buf, 7, 0);
}

bool Task021efba4_IsLoaded(void) {
    char buf[0x20];
    LangData_LocalizePath(buf, data_ov002_021efad1);
    return ResMgr_IsLoaded(buf, 7) != 0;
}

static inline Ov002Hud *func_ov002_021d4f58_ctor(Ov002Hud *self) {
    *(VFunc **)self = Ov002Vt_021efb14_vtbl;
    Ov002Hud_Init(self);
    return self;
}

void Task021efba4_Start(Task021efba4 *self) {
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
    Ov002Hud_Load(p);
    Ov002Hud_SetRow(self->hud, 0, 0);
    self->fadeLen = 0x1000;
    TaskList_Insert(self);
}

void Task021efba4_PreUpdate(Task021efba4 *self) {
    switch (self->state) {
    case 0xc:
        TaskHost_RequestSwitch(gTaskHost, 0x1c, 0);
        self->vfunc_4c();
        break;
    case 0xd:
        if (self->vfunc_54() != 0) {
            self->unk_04_1 = 1;
            self->vfunc_0c(0);
        }
        break;
    }
    Ov002Hud_Update(self->hud);
}

void Task021efba4_PostUpdate(void) {
}

void Task021efba4_Draw(Task021efba4 *self) {
    Ov002Hud_Draw(self->hud);
}

Task021efb24 *Task021efb24_New(void) {
    Task021efb24 *p = (Task021efb24 *)Heap_Alloc(0x3c);
    if (p != NULL) {
        TaskBase_ctor(p);
        *(VFunc **)p = Ov002TaskVt_021efb24_vtbl;
    }
    p->vfunc_08(0x1c, 0x64);
    return p;
}

void Task021efb24_Load(void) {
    Obj021efe7c_Create();
    Obj021efe7c_Setup(Obj021efe7c_Get());
}

void Task021efb24_IsLoaded(void) {
    Obj021efe7c_IsLoaded(Obj021efe7c_Get());
}

void Task021efb24_Start(Task021efb24 *self) {
    BOOL clear = Task_isFlag1Clear(self);
    if (!clear) {
        self->unk_04_1 = 0;
    }
    if (self->vfunc_28() != 0) {
        return;
    }
    Obj021efe7c_Start(Obj021efe7c_Get());
    self->vfunc_40();
    TaskList_Insert(self);
}

void Task021efb24_PreUpdate(Task021efb24 *self) {
    switch (self->state) {
    case 8:
        Obj021efe7c_SetPhase(Obj021efe7c_Get(), 0);
        break;
    case 0xd:
        if (Obj021efe7c_Update(Obj021efe7c_Get()) != 0) {
            break;
        }
        if (Obj021efe7c_Get()->unk_0c == 2) {
            TaskHost_RequestSwitch(gTaskHost, 0x1d, 0);
            self->unk_04_1 = 1;
            self->unk_04_2 = 1;
            self->vfunc_4c();
        } else {
            TaskHost_RequestSwitch(gTaskHost, 0x1b, 0);
            self->unk_04_1 = 1;
            self->unk_04_2 = 1;
            self->vfunc_4c();
        }
        break;
    }
}

void Task021efb24_Draw(Task021efb24 *p) {
    if (gFinishingTask == p) {
        Obj021efe7c_Draw(Obj021efe7c_Get());
    }
}

Task021efc24 *Task021efc24_New(void) {
    Task021efc24 *p = (Task021efc24 *)Heap_Alloc(0x78);
    if (p != NULL) {
        TaskBase_ctor(p);
        *(VFunc **)p = Ov002TaskVt_021efc24_vtbl;
        p->unk_3c = NULL;
        p->unk_40 = NULL;
        p->unk_44 = NULL;
        p->unk_48 = 0;
        p->unk_4c = NULL;
        p->unk_50 = NULL;
        p->unk_54 = NULL;
        p->unk_58 = NULL;
        p->unk_5c = NULL;
        MI_CpuFill8(p->unk_60, 0, 10);
        MI_CpuFill8(p->unk_6a, 0, 10);
        p->unk_74 = 0xffff;
    }
    p->vfunc_08(0x1d, 0x64);
    return p;
}

BOOL func_ov002_021d52e0(UiList *self, UiListItem *ev) {
    Task021efba4 *t;
    if (ev != NULL) {
        if (ev->id == 0) {
            func_ov002_021d5f60((Task021efc24 *)self->owner);
        } else {
            SndMgr_PlayVolume(gSndMgr, 0x1f, -1, -1, -1);
        }
    }
    t = (Task021efba4 *)Task_FindById(0x1b);
    if (t != NULL && t->hud != NULL) {
        Ov002Hud_SetRow(t->hud, 9, 0);
    }
    return FALSE;
}

BOOL Task021efc24_List50OnCursor(UiList *self, UiListItem *ev) {
    Task021efc24 *owner = (Task021efc24 *)self->owner;
    u16 id;
    Task021efba4 *t;
    if (ev != NULL) {
        id = ev->id;
        if (owner->unk_54 != NULL) {
            Obj0215bb14_SetText(owner->unk_54, func_0206ec8c(id));
            owner->unk_54->vfunc_70();
        }
        if (owner->unk_58 != NULL) {
            Param0206ef10 *info = Param_GetRecord(id);
            ModelViewer_SetModel(owner->unk_58, info->def.name[0], info->def.name[1], data_ov002_021efae1,
                                info->def.unk_1c, data_ov002_021efaeb, info->def.unk_18, 0x1000);
        }
        Obj021c95ac_Init_021c95ac(owner->unk_60, id);
        t = (Task021efba4 *)Task_FindById(0x1b);
        if (t != NULL) {
            if (t->hud != NULL) {
                MI_CpuCopy8(owner->unk_60, t->hud->unk_2c, 0x14);
            }
            if (t->hud != NULL) {
                Ov002Hud_SetInfo(t->hud, id);
            }
        }
    }
    return TRUE;
}

BOOL Task021efc24_List50OnDecide(UiList *self, UiListItem *ev) {
    if (ev != NULL) {
        if (ev->id != ((Task021efc24 *)self->owner)->unk_74) {
            Task021efba4 *t;
            SndMgr_PlayVolume(gSndMgr, 0x1e, -1, -1, -1);
            func_ov000_02152294(self, 0x8d, 0x23, (EvCallback)func_ov002_021d52e0);
            t = (Task021efba4 *)Task_FindById(0x1b);
            if (t != NULL && t->hud != NULL) {
                Ov002Hud_SetRow(t->hud, 0, 0);
            }
        } else {
            SndMgr_PlayVolume(gSndMgr, 0x20, -1, -1, -1);
        }
    }
    return TRUE;
}

}
