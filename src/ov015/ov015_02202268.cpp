#include "ov015/ov015.h"

extern "C" {

extern Ov015Globals gOv015Globals;
void Ov015Ship_Draw(Ov015Ship *p);
void Ov015Fish_Draw(Ov015Fish *self);
void Ov015MsgMgr_Draw(Ov015MsgMgr *self);
void Ov015Obj292c_Draw(Ov015Obj292c *self);
BOOL Model021903b4_Draw(void *a);
void Ov015Game_FreeAll(Ov015Game *self);
void Ov015Info38_Dtor(Ov015Info38 *p);
extern u8 Ov015Game_vtbl[];
extern u8 Ov015Child_vtbl[];
extern u8 Ov015Obj34_vtbl[];
extern u8 Ov015Obj30_vtbl[];
extern char data_ov015_022128c1[];
extern u8 Ov015Hud_vtbl[];
extern char data_ov015_022128ab[];
void LangData_LocalizePath(char *buf, const char *name);
extern u8 Ov015Vt_0221294c_vtbl[];
void *Model0218fe1c_FreeAnims(void *a);
void *ResSet_ReleaseAll(void *a);
extern u8 Ov015Result_vtbl[];
extern u8 Ov015Fish_vtbl[];
void Ov015Fish_DtorBase(Ov015Fish *p);
void HitSphere_Unlink_0203f2b8(void *p);
void *Shadow_DtorBase(void *p);
void *Model0218fe1c_FreeAnims(void *p);
void *ResSet_ReleaseAll(void *p);
void Ov015FishInfo_Dtor(Ov015FishInfo *p);
extern u8 Ov015Obj292c_vtbl[];
void Ov015Obj292c_DtorBase(Ov015Obj292c *self);
extern u8 Ov015List_vtbl[];
extern u8 Ov015Node_vtbl[];

s32 Ov015Game_GetNext(void) {
    switch (gOv015Globals.mainSeq->unk_04) {
    case 1:
    case 2:
    case 3:
    case 4:
    case 5:
        return 3;
    case 0:
    default:
        return 1;
    }
}

static inline void Ov015_022022ac_Draw(Ov015Game *self) {
    Ov015MdlSet *p;
    Ov015Node *n;
    Ov015Ship_Draw(self->ship);
    p = self->unk_20;
    Model021903b4_Draw(&p->p[0].mdl);
    Model021903b4_Draw(&p->p[1].mdl);
    Model021903b4_Draw(&p->p[2].mdl);
    NNS_G3dGeFlushBuffer();
    for (n = self->fishList->head; n != NULL; n = n->next) {
        Ov015Fish_Draw(n->fish);
    }
}
void Ov015Game_Draw(Ov015Game *self) {
    switch (self->step) {
    case 0:
        break;

    case 0x28:
        if (self->phase1.step > 2 && gGfxSys->unk_a30_4) {
            if (self->phase1.unk_10 != NULL) Ov015Obj292c_Draw(self->phase1.unk_10);
            if (self->phase1.unk_14 != NULL) self->phase1.unk_14->vfunc_1c();
        }
        if (self->phase1.step >= 3) {
            Ov015_022022ac_Draw(self);
        }
        if (self->unk_90 != NULL) Ov015MsgMgr_Draw(self->unk_90);
        break;
    case 0x32:
    case 0x3c:
        if (gGfxSys->unk_a30_4) {
            Ov015Hud_Draw(self->hud);
        }
        Ov015_022022ac_Draw(self);
        if (self->unk_90 != NULL) Ov015MsgMgr_Draw(self->unk_90);
        NNS_G3dGeFlushBuffer();
        break;
    case 0x46:
        Ov015Result_Draw(self->result);
        break;
    }
}

void *Ov015Game_DtorDelete(Ov015Game *self) {
    void *saved;
    SET_VT(self, Ov015Game_vtbl);
    Ov015Game_FreeAll(self);
    ResMgr_ReleaseByName(gResMgr, data_ov015_022128c1, 7, 0);
    HEAP_PUSH(saved);
    DELETE_V(self->result);
    HEAP_POP(saved);
    EffectMgr_FreeAll(gEffectMgr);
    gEffectMgr->drawFilter = 0;
    gGfxSys->nextState = 1;
    Ov015Info38_Dtor(&self->info);
    SET_VT(&self->phase2, Ov015Obj34_vtbl);
    if (EffectMgr_Contains(gEffectMgr, self->phase2.fx)) {
        HEAP_PUSH(saved);
        DELETE_V(self->phase2.fx);
        HEAP_POP(saved);
    }
    SET_VT(&self->phase1, Ov015Obj30_vtbl);
    HEAP_PUSH(saved);
    DELETE_V(self->phase1.unk_10);
    HEAP_POP(saved);
    HEAP_PUSH(saved);
    DELETE_V(self->phase1.unk_14);
    HEAP_POP(saved);
    self->phase1.step = 0;
    self->phase1.timer = 0;
    self->phase1.unk_0c = 0;
    self->phase1.unk_10 = 0;
    self->phase1.unk_14 = 0;
    self->phase1.fish = 0;
    self->phase1.ship = 0;
    self->phase1.cam = 0;
    self->phase1.fishList = 0;
    self->phase1.info = 0;
    SET_VT(self, Ov015Child_vtbl);
    Ov015Child_DtorBase(self);
    Heap_Free(self);
    return self;
}

void *Ov015Game_Dtor(Ov015Game *self) {
    void *saved;
    SET_VT(self, Ov015Game_vtbl);
    Ov015Game_FreeAll(self);
    ResMgr_ReleaseByName(gResMgr, data_ov015_022128c1, 7, 0);
    HEAP_PUSH(saved);
    DELETE_V(self->result);
    HEAP_POP(saved);
    EffectMgr_FreeAll(gEffectMgr);
    gEffectMgr->drawFilter = 0;
    gGfxSys->nextState = 1;
    Ov015Info38_Dtor(&self->info);
    SET_VT(&self->phase2, Ov015Obj34_vtbl);
    if (EffectMgr_Contains(gEffectMgr, self->phase2.fx)) {
        HEAP_PUSH(saved);
        DELETE_V(self->phase2.fx);
        HEAP_POP(saved);
    }
    SET_VT(&self->phase1, Ov015Obj30_vtbl);
    HEAP_PUSH(saved);
    DELETE_V(self->phase1.unk_10);
    HEAP_POP(saved);
    HEAP_PUSH(saved);
    DELETE_V(self->phase1.unk_14);
    HEAP_POP(saved);
    self->phase1.step = 0;
    self->phase1.timer = 0;
    self->phase1.unk_0c = 0;
    self->phase1.unk_10 = 0;
    self->phase1.unk_14 = 0;
    self->phase1.fish = 0;
    self->phase1.ship = 0;
    self->phase1.cam = 0;
    self->phase1.fishList = 0;
    self->phase1.info = 0;
    SET_VT(self, Ov015Child_vtbl);
    Ov015Child_DtorBase(self);
    return self;
}

void *Ov015Hud_Dtor(Ov015Hud *self) {
    char buf[0x20];
    SET_VT(self, Ov015Hud_vtbl);
    {
        void *saved;
        HEAP_PUSH(saved);
        {
            Model *o = self->mdl0;
            if (o != NULL) {
                if (o != NULL) {
                    TexObj_Release(o);
                    PlttRes_Release(&o->pltt);
                    Heap_Free(o);
                }
                self->mdl0 = NULL;
            }
        }
        HEAP_POP(saved);
    }
    {
        void *saved;
        HEAP_PUSH(saved);
        {
            Model *o = self->mdl1;
            if (o != NULL) {
                if (o != NULL) {
                    TexObj_Release(o);
                    PlttRes_Release(&o->pltt);
                    Heap_Free(o);
                }
                self->mdl1 = NULL;
            }
        }
        HEAP_POP(saved);
    }
    LangData_LocalizePath(buf, data_ov015_022128ab);
    ResMgr_ReleaseByName(gResMgr, buf, 7, 0);

    return self;
}

void *Ov015Vt_0221294c_Dtor(u8 *self) {
    SET_VT(self, Ov015Vt_0221294c_vtbl);
    Model0218fe1c_FreeAnims(self + 0x57c);
    ResSet_ReleaseAll(self + 0x444);
    Model0218fe1c_FreeAnims(self + 0x35c);
    ResSet_ReleaseAll(self + 0x224);
    Model0218fe1c_FreeAnims(self + 0x13c);
    ResSet_ReleaseAll(self + 0x4);
    return self;
}

void *Ov015Result_Dtor(Ov015Result *self) {
    SET_VT(self, Ov015Result_vtbl);
    Ov015Result_DtorBase(self);
    return self;
}

void *Ov015Fish_Dtor(Ov015Fish *self) {
    SET_VT(self, Ov015Fish_vtbl);
    Ov015Fish_DtorBase(self);
    HitSphere_Unlink_0203f2b8(&self->hit);
    Shadow_DtorBase(&self->shadow);
    Model0218fe1c_FreeAnims(&self->model2);
    ResSet_ReleaseAll(&self->res2);
    Model0218fe1c_FreeAnims(&self->model);
    ResSet_ReleaseAll(&self->res);
    Ov015FishInfo_Dtor(&self->info);
    return self;
}

void *Ov015Obj292c_Dtor(Ov015Obj292c *self) {
    SET_VT(self, Ov015Obj292c_vtbl);
    Ov015Obj292c_DtorBase(self);
    return self;
}

void Ov015List_Remove(Ov015List *self, Ov015Fish *fish) {
    Ov015Node *n;
    void *saved;
    if (self->head == NULL) {
        return;
    }
    for (n = self->head; n != NULL; n = n->next) {
        if (n->fish == fish) {
            break;
        }
    }
    if (n == NULL) {
        return;
    }
    if (n == self->head) {
        self->head = n->next;
    }
    if (n == self->tail) {
        self->tail = n->prev;
    }
    HEAP_PUSH(saved);
    DELETE_V(n);
    HEAP_POP(saved);
    self->count--;
}

Ov015List *Ov015List_DtorDelete(Ov015List *self) {
    Ov015Node *n;
    SET_VT(self, Ov015List_vtbl);
    n = self->head;
    while (n != NULL) {
        Ov015Node *next = n->next;
        void *saved;
        HEAP_PUSH(saved);
        DELETE_V(n);
        HEAP_POP(saved);
        n = next;
    }
    self->count = 0;
    Heap_Free(self);
    return self;
}

Ov015Node *Ov015Node_DtorDelete(Ov015Node *self) {
    SET_VT(self, Ov015Node_vtbl);
    if (self->prev != NULL) {
        self->prev->next = self->next;
    }
    if (self->next != NULL) {
        self->next->prev = self->prev;
    }
    Heap_Free(self);
    return self;
}

Ov015List *Ov015List_Dtor(Ov015List *self) {
    Ov015Node *n;
    SET_VT(self, Ov015List_vtbl);
    n = self->head;
    while (n != NULL) {
        Ov015Node *next = n->next;
        void *saved;
        HEAP_PUSH(saved);
        DELETE_V(n);
        HEAP_POP(saved);
        n = next;
    }
    self->count = 0;
    return self;
}

Ov015Node *Ov015Node_Dtor(Ov015Node *self) {
    SET_VT(self, Ov015Node_vtbl);
    if (self->prev != NULL) {
        self->prev->next = self->next;
    }
    if (self->next != NULL) {
        self->next->prev = self->prev;
    }
    return self;
}

void Ov015Scene2a88_Load(void) {
}

s32 Ov015Scene2a88_IsLoaded(void) {
    return 1;
}

void GfxSys_StartFadeIn(s32 a, s32 b, s32 c);
void func_ov015_02206bf0(s32 idx, s32 x, s32 y, s32 z, s32 unused, void *oam, const void *img, u32 charBase, u32 plttBase, s32 unused2, const s32 *ofs);
void Ov015Scene2a88_Start(Ov015Scene2a88 *self) {
    SndQueue *p = gSndQueue.queue;
    void *name;
    void *file;
    Model *l;
    if (p->flag0) {
        if (p->unk_06 != 0xffff || p->unk_04 != 0x25) {
            u16 v;
            if (p->unk_02 != 10 && p->unk_02 != 0) {
                if (p->unk_06 != 0xffff) {
                    SndQueue_Push_0204aab0(p, p->unk_06);
                }
                v = 1;
            } else {
                v = 0;
            }
            p->unk_02 = v;
            p->unk_06 = 0x25;
            p->unk_08 = 10;
        }
    }
    self->unk_04 &= ~2;
    if (self->vfunc_28()) return;
    l = (Model *)Heap_Alloc(sizeof(Model));
    if (l != NULL) {
        file = (void *)ArcPath_Menu;
        name = ResName_CommonModel2;
        PlttRes_Init_02041218(&l->pltt);
        TexObj_Init(l, (char *)name, 0);
        STD_CopyString(l->name, (char *)file);
    }
    self->model = l;
    TexObj_SetRes(self->model, ResList_FindType2(ResMgr_GetArcList(ArcPath_Menu), ResName_CommonModel2));
    self->model->flags |= 2;
    TexObj_SelectImage(self->model, 0, 0);
    {
        Model *p = self->model;
        p->x = 0;
        p->y = 0;
    }
    self->model->unk_150 = 0xfffe019a;
    self->model->unk_158 = (void *)func_ov015_02206bf0;
    TexObj_SetOamFuncArg(self->model, 0, &self->unk_44);
    self->parent = NULL;
    self->unk_40 = 1;
    TaskList_Insert(self);
    GfxSys_StartFadeIn(0x14000, 0, 1);
    GfxSys_StartFadeIn(0x14000, 0, 0);
}

}
