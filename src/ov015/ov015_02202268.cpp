#include "ov015/ov015.h"

extern "C" {

extern Ov015Globals data_ov015_02213320;
void func_ov015_02208070(Ov015Ship *p);
void func_ov015_02209b8c(Ov015Fish *self);
void func_ov015_02210d04(Ov015MsgMgr *self);
void func_ov015_02212264(Ov015Obj292c *self);
BOOL Model021903b4_Draw(void *a);
void func_ov015_0220101c(Ov015Game *self);
void func_ov015_02211878(Ov015Info38 *p);
extern u8 data_ov015_0221296c[];
extern u8 data_ov015_0221280c[];
extern u8 data_ov015_022127dc[];
extern u8 data_ov015_022127ec[];
extern char data_ov015_022128c1[];
extern u8 data_ov015_0221293c[];
extern char data_ov015_022128ab[];
void LangData_LocalizePath(char *buf, const char *name);
extern u8 data_ov015_0221294c[];
void *Model0218fe1c_FreeAnims(void *a);
void *ResSet_ReleaseAll(void *a);
extern u8 data_ov015_022128ec[];
extern u8 data_ov015_022128fc[];
void func_ov015_02209270(Ov015Fish *p);
void HitSphere_Unlink_0203f2b8(void *p);
void *Shadow_DtorBase(void *p);
void *Model0218fe1c_FreeAnims(void *p);
void *ResSet_ReleaseAll(void *p);
void func_ov015_0220900c(Ov015FishInfo *p);
extern u8 data_ov015_0221292c[];
void func_ov015_022120fc(Ov015Obj292c *self);
extern u8 data_ov015_0221290c[];
extern u8 data_ov015_0221295c[];

s32 func_ov015_02202268(void) {
    switch (data_ov015_02213320.mainSeq->unk_04) {
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
    func_ov015_02208070(self->ship);
    p = self->unk_20;
    Model021903b4_Draw(&p->p[0].mdl);
    Model021903b4_Draw(&p->p[1].mdl);
    Model021903b4_Draw(&p->p[2].mdl);
    NNS_G3dGeFlushBuffer();
    for (n = self->fishList->head; n != NULL; n = n->next) {
        func_ov015_02209b8c(n->fish);
    }
}
void func_ov015_022022ac(Ov015Game *self) {
    switch (self->step) {
    case 0:
        break;

    case 0x28:
        if (self->phase1.step > 2 && data_02097d48->unk_a30_4) {
            if (self->phase1.unk_10 != NULL) func_ov015_02212264(self->phase1.unk_10);
            if (self->phase1.unk_14 != NULL) self->phase1.unk_14->vfunc_1c();
        }
        if (self->phase1.step >= 3) {
            Ov015_022022ac_Draw(self);
        }
        if (self->unk_90 != NULL) func_ov015_02210d04(self->unk_90);
        break;
    case 0x32:
    case 0x3c:
        if (data_02097d48->unk_a30_4) {
            func_ov015_021fb758(self->hud);
        }
        Ov015_022022ac_Draw(self);
        if (self->unk_90 != NULL) func_ov015_02210d04(self->unk_90);
        NNS_G3dGeFlushBuffer();
        break;
    case 0x46:
        func_ov015_0220f7a8(self->result);
        break;
    }
}

void *Ov015Game_DtorDelete(Ov015Game *self) {
    void *saved;
    SET_VT(self, data_ov015_0221296c);
    func_ov015_0220101c(self);
    ResMgr_ReleaseByName(data_02097cdc, data_ov015_022128c1, 7, 0);
    HEAP_PUSH(saved);
    DELETE_V(self->result);
    HEAP_POP(saved);
    EffectMgr_FreeAll(data_0214a420);
    data_0214a420->drawFilter = 0;
    data_02097d48->nextState = 1;
    func_ov015_02211878(&self->info);
    SET_VT(&self->phase2, data_ov015_022127dc);
    if (EffectMgr_Contains(data_0214a420, self->phase2.fx)) {
        HEAP_PUSH(saved);
        DELETE_V(self->phase2.fx);
        HEAP_POP(saved);
    }
    SET_VT(&self->phase1, data_ov015_022127ec);
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
    SET_VT(self, data_ov015_0221280c);
    func_ov015_021fa6cc(self);
    Heap_Free(self);
    return self;
}

void *Ov015Game_Dtor(Ov015Game *self) {
    void *saved;
    SET_VT(self, data_ov015_0221296c);
    func_ov015_0220101c(self);
    ResMgr_ReleaseByName(data_02097cdc, data_ov015_022128c1, 7, 0);
    HEAP_PUSH(saved);
    DELETE_V(self->result);
    HEAP_POP(saved);
    EffectMgr_FreeAll(data_0214a420);
    data_0214a420->drawFilter = 0;
    data_02097d48->nextState = 1;
    func_ov015_02211878(&self->info);
    SET_VT(&self->phase2, data_ov015_022127dc);
    if (EffectMgr_Contains(data_0214a420, self->phase2.fx)) {
        HEAP_PUSH(saved);
        DELETE_V(self->phase2.fx);
        HEAP_POP(saved);
    }
    SET_VT(&self->phase1, data_ov015_022127ec);
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
    SET_VT(self, data_ov015_0221280c);
    func_ov015_021fa6cc(self);
    return self;
}

void *func_ov015_022027e8(Ov015Hud *self) {
    char buf[0x20];
    SET_VT(self, data_ov015_0221293c);
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
    ResMgr_ReleaseByName(data_02097cdc, buf, 7, 0);

    return self;
}

void *func_ov015_022028dc(u8 *self) {
    SET_VT(self, data_ov015_0221294c);
    Model0218fe1c_FreeAnims(self + 0x57c);
    ResSet_ReleaseAll(self + 0x444);
    Model0218fe1c_FreeAnims(self + 0x35c);
    ResSet_ReleaseAll(self + 0x224);
    Model0218fe1c_FreeAnims(self + 0x13c);
    ResSet_ReleaseAll(self + 0x4);
    return self;
}

void *Ov015Result_Dtor(Ov015Result *self) {
    SET_VT(self, data_ov015_022128ec);
    func_ov015_0220f4d4(self);
    return self;
}

void *Ov015Fish_Dtor(Ov015Fish *self) {
    SET_VT(self, data_ov015_022128fc);
    func_ov015_02209270(self);
    HitSphere_Unlink_0203f2b8(&self->hit);
    Shadow_DtorBase(&self->shadow);
    Model0218fe1c_FreeAnims(&self->model2);
    ResSet_ReleaseAll(&self->res2);
    Model0218fe1c_FreeAnims(&self->model);
    ResSet_ReleaseAll(&self->res);
    func_ov015_0220900c(&self->info);
    return self;
}

void *Ov015Obj292c_Dtor(Ov015Obj292c *self) {
    SET_VT(self, data_ov015_0221292c);
    func_ov015_022120fc(self);
    return self;
}

void func_ov015_022029d4(Ov015List *self, Ov015Fish *fish) {
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

Ov015List *func_ov015_02202a78(Ov015List *self) {
    Ov015Node *n;
    SET_VT(self, data_ov015_0221290c);
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

Ov015Node *func_ov015_02202af8(Ov015Node *self) {
    SET_VT(self, data_ov015_0221295c);
    if (self->prev != NULL) {
        self->prev->next = self->next;
    }
    if (self->next != NULL) {
        self->next->prev = self->prev;
    }
    Heap_Free(self);
    return self;
}

Ov015List *func_ov015_02202b3c(Ov015List *self) {
    Ov015Node *n;
    SET_VT(self, data_ov015_0221290c);
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

Ov015Node *func_ov015_02202bb4(Ov015Node *self) {
    SET_VT(self, data_ov015_0221295c);
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
    SndQueue *p = data_02097e48.queue;
    void *name;
    void *file;
    Model *l;
    if (p->flag0) {
        if (p->unk_06 != 0xffff || p->unk_04 != 0x25) {
            u16 v;
            if (p->unk_02 != 10 && p->unk_02 != 0) {
                if (p->unk_06 != 0xffff) {
                    func_0204aab0(p, p->unk_06);
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
        file = (void *)data_0208cca0;
        name = data_0208ccc0;
        PlttRes_Init_02041218(&l->pltt);
        TexObj_Init(l, (char *)name, 0);
        STD_CopyString(l->name, (char *)file);
    }
    self->model = l;
    TexObj_SetRes(self->model, ResList_FindType2(ResMgr_GetArcList(data_0208cca0), data_0208ccc0));
    self->model->flags |= 2;
    TexObj_SelectImage(self->model, 0, 0);
    {
        Model *p = self->model;
        p->x = 0;
        p->y = 0;
    }
    self->model->unk_150 = 0xfffe019a;
    self->model->unk_158 = (void *)func_ov015_02206bf0;
    func_02041c20(self->model, 0, &self->unk_44);
    self->parent = NULL;
    self->unk_40 = 1;
    TaskList_Insert(self);
    GfxSys_StartFadeIn(0x14000, 0, 1);
    GfxSys_StartFadeIn(0x14000, 0, 0);
}

}
