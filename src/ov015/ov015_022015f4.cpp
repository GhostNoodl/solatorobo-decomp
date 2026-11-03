#include "ov015/ov015.h"

namespace Dup { extern "C" Ov015Stat data_ov015_0221332c; }

extern "C" {

extern char data_ov015_022128c1[];
extern Ov015Globals gOv015Globals;
extern u8 Ov015Vt_0221291c_vtbl[];
extern u8 Ov015MsgMgr_vtbl[];
extern u8 Ov015List_vtbl[];
extern u8 Ov015Node_vtbl[];
void *Camera_Ctor(void *p);
u8 *func_02070744(u16 id);
void Ov015CamPair_Init(Ov015CamPair *self);
void func_ov015_02210b3c(Ov015MsgMgr *self);
void func_ov015_02211890(Ov015Info38 *self, u16 id, s32 mode);
void func_ov015_02209024(Ov015FishInfo *self, u16 a, const void *src);
void *Ov015Fish_Ctor(Ov015Fish *self);
void func_ov015_02209364(Ov015Fish *self);

BOOL Ov015Game_Load(void) {
    return ResMgr_IsLoaded(data_ov015_022128c1, 7) != 0 ? TRUE : FALSE;
}

BOOL Ov015Game_Setup(Ov015Game *self) {
    u16 ids[4];
    Ov015CamPair *o;
    Ov015List *l;
    u32 n;
    u32 i;
    o = (Ov015CamPair *)Heap_Alloc(0x1a0);
    if (o != NULL) {
        SET_VT(o, Ov015Vt_0221291c_vtbl);
        Camera_Ctor(&o->cam0);
        Camera_Ctor(&o->cam1);
        o->mode = 1;
        o->target.x = 0;
        o->target.y = 0;
        o->target.z = 0;
        o->unk_18c.x = 0;
        o->unk_18c.y = 0;
        o->unk_18c.z = 0;
        o->unk_198 = 0;
        o->timer = 0;
    }
    self->cam = o;
    Ov015CamPair_Init(o);
    if ((u32)(gOv015Globals.mainSeq->unk_04 - 1) <= 1) {
        Ov015MsgMgr *p = (Ov015MsgMgr *)Heap_Alloc(sizeof(Ov015MsgMgr));
        if (p != NULL) {
            SET_VT(p, Ov015MsgMgr_vtbl);
            func_ov015_02210b3c(p);
        }
        self->unk_90 = p;
    }
    l = (Ov015List *)Heap_Alloc(0x10);
    if (l != NULL) {
        SET_VT(l, Ov015List_vtbl);
        l->head = NULL;
        l->tail = NULL;
        l->count = 0;
    }
    self->fishList = l;
    n = func_ov015_02211160(gOv015Shared, ids, 3);
    func_ov015_02211890(&self->info, gOv015Shared->unk_08, self->ship->modelIdx);
    for (i = 0; i < n; i++) {
        u16 id = ids[i];
        u8 *def = func_02070744(id);
        Ov015Fish *e = (Ov015Fish *)Heap_Alloc(0x5b0);
        Ov015List *L;
        Ov015Node *nd;
        if (e != NULL) e = (Ov015Fish *)Ov015Fish_Ctor(e);
        e->id = id;
        func_ov015_02209024(&e->info, e->id, def);
        e->info.unk_20 = self->info.unk_20;
        e->info.unk_24 = self->info.unk_24;
        func_ov015_02209364(e);
        L = self->fishList;
        nd = (Ov015Node *)Heap_Alloc(0x10);
        if (nd != NULL) {
            SET_VT(nd, Ov015Node_vtbl);
            nd->fish = e;
            nd->prev = NULL;
            nd->next = NULL;
        }
        if (L->head == NULL) {
            L->head = nd;
            L->tail = nd;
        } else {
            L->head->prev = nd;
            nd->next = L->head;
            L->head = nd;
        }
        L->count++;
    }
    self->step = 10;
    {
        SndQueue *pad = gSndQueue.queue;
        if (pad->flag3) {
            pad->unk_06 = 0x8000;
            pad->unk_08 = 0x1e;
            pad->unk_02 = 0;
        }
    }
    return TRUE;
}

extern char data_ov015_022128ab[];
extern char data_ov015_02212899[];
extern char data_ov015_0221289f[];
extern char data_ov015_022128a5[];
extern s32 data_ov015_02213328;
void GfxSys_StartFadeIn(s32 a, s32 b, s32 c);
Ov015Fade *Ov015_GetFade(void);
void Ov015Fade_ToClear(Ov015Fade *self, s32 c, u16 d);
void Ov015Fade_ToOpaque(Ov015Fade *self, s32 c, u16 d);
BOOL Ov015Ship_Load(Ov015Ship *p);
s32 ResSet_UpdateLoad(void *a);
BOOL Ov015Fish_IsLoaded(Ov015Fish *self);
void LangData_LocalizePath(char *buf, const char *name);
int func_ov015_02210bd8(Ov015MsgMgr *self);
BOOL Ov015Ship_Setup(Ov015Ship *self);
BOOL Model0218fe1c_SetRes(void *a, void *b, s32 c, s32 d);
BOOL Model0218fe1c_SetAnim(void *a, const void *b, s32 c, s32 d);
void Model0218fe1c_SetLoop(void *a);
BOOL func_ov015_02209500(Ov015Fish *self);
BOOL func_ov015_02210c28(void);
void Model0218fe1c_UpdateAnim(void *a, s32 b);
s32 func_ov015_02210c30(Ov015MsgMgr *self, Ov015Stat *a, s32 b);
BOOL func_ov015_021ff4a0(Ov015Obj30 *self, Ov015Ship *a, Ov015CamPair *b, Ov015List *c, Ov015Info38 *d);
BOOL func_ov015_02200204(Ov015Obj34 *self, Ov015Ship *a, Ov015Fish *b, Ov015CamPair *c, Ov015Info38 *d);
void func_ov015_0220101c(Ov015Game *self);

static inline BOOL Ov015_SysB4(void) {
    return gGfxSys->unk_a30_4 ? TRUE : FALSE;
}

static inline void Ov015_CamFovy(Ov015Cam *c) {
    u16 idx;
    c->fovy = (u16)(((s64)c->fovyDeg * 0xb60b60b60bLL + 0x80000000000LL) >> 44);
    idx = (u16)(c->fovy >> 1);
    c->fovySin = FX_SinCosTable_[(idx >> 4) * 2];
    c->fovyCos = FX_SinCosTable_[(idx >> 4) * 2 + 1];
    c->dirty = 1;
}

static inline void Ov015_CamUpdate(Ov015Game *self) {
    if (Ov015_SysB4()) {
        Ov015CamPair *cp = self->cam;
        Ov015_CamFovy(&cp->cam0);
        (&cp->cam0)->vfunc_00();
    } else {
        Ov015CamPair *cp = self->cam;
        Ov015_CamFovy(&cp->cam1);
        (&cp->cam1)->vfunc_00();
    }
}

static inline void Ov015_BgmFadeTo(u16 id) {
    SndQueue *p = gSndQueue.queue;
    if (p->flag0) {
        if (p->unk_06 != 0xffff || p->unk_04 != id) {
            if (p->unk_02 != 10 && p->unk_02 != 0) {
                if (p->unk_06 != 0xffff) {
                    SndQueue_Push_0204aab0(p, p->unk_06);
                }
                p->unk_02 = 1;
            } else {
                p->unk_02 = 0;
            }
            p->unk_06 = id;
            p->unk_08 = 10;
        }
    }
}

static inline void Ov015_ModelsReset(Ov015MdlSet *p) {
    p->p[0].mdl.trans.x = 0;
    p->p[0].mdl.trans.y = 0;
    p->p[0].mdl.trans.z = 0;
    Model0218fe1c_UpdateAnim(&p->p[0].mdl, 0x800);
    p->p[1].mdl.trans.x = 0;
    p->p[1].mdl.trans.y = 0x1000;
    p->p[1].mdl.trans.z = 0;
    Model0218fe1c_UpdateAnim(&p->p[1].mdl, 0x800);
    p->p[2].mdl.trans.x = 0;
    p->p[2].mdl.trans.y = 0x23333;
    p->p[2].mdl.trans.z = 0x4cd;
    Model0218fe1c_UpdateAnim(&p->p[2].mdl, 0x400);
}

typedef enum { OV015_SYS_MODE_2 = 2 } Ov015SysMode;

BOOL Ov015Game_Update(Ov015Game *self) {
    BOOL ret = TRUE;
    bool a = true;
    switch (self->step) {
    case 0:
        self->step = 10;
    case 10: {
        GfxSys *sys = gGfxSys;
        if (sys->state == 1) {
            Ov015SysMode v = OV015_SYS_MODE_2;
            sys->nextState = v;
            GfxSys_StartFadeIn(0x1000, 0, v - 3);
        }
        Ov015Fade_ToOpaque(Ov015_GetFade(), 0x1000, 0);
        self->step = 0x14;
        break;
    }
    case 0x14: {
        Ov015Node *n;
        bool a;
        Ov015Hud *q;
        Ov015MdlSet *p;
        bool d;
        bool c;
        bool b;
        char buf[0x20];
        if (!(Ov015Ship_Load(self->ship) & 1)) {
            a = false;
        } else {
            a = true;
        }
        p = self->unk_20;
        b = true;
        if (p->p[0].res.unk_00 >= 0 && !ResSet_UpdateLoad(&p->p[0].res)) {
            b = false;
        }
        if (p->p[1].res.unk_00 >= 0 && !ResSet_UpdateLoad(&p->p[1].res)) {
            b = false;
        }
        if (p->p[2].res.unk_00 >= 0 && !ResSet_UpdateLoad(&p->p[2].res)) {
            b = false;
        }
        b = a & b;
        c = true;
        for (n = self->fishList->head; n != NULL; n = n->next) {
            c &= Ov015Fish_IsLoaded(n->fish);
        }
        c = b & c;
        q = self->hud;
        d = false;
        LangData_LocalizePath(buf, data_ov015_022128ab);
        switch (q->unk_04) {
        case 0:
            ResMgr_Load(buf, 7, 0);
            q->unk_04 = 10;
        case 10:
            if (ResMgr_IsLoaded(buf, 7) == 0) {
                break;
            }
            q->unk_04 = 0x1e;
        case 0x1e:
            q->unk_04 = 0x1e;
            d = true;
            break;
        }
        d = c & d;
        if (self->unk_90 != NULL) {
            d &= func_ov015_02210bd8(self->unk_90);
        }
        if (d) {
            self->step = 0x1e;
        }
        break;
    }
    case 0x1e: {
        Ov015MdlSet *p;
        Ov015Node *n;
        Ov015Ship_Setup(self->ship);
        p = self->unk_20;
        Model0218fe1c_SetRes(&p->p[0].mdl, &p->p[0].res, 0, 1);
        Model0218fe1c_SetAnim(&p->p[0].mdl, data_ov015_02212899, 0x1000, 0);
        Model0218fe1c_SetLoop(&p->p[0].mdl);
        p->p[0].mdl.flags.visible = 1;
        Model0218fe1c_SetRes(&p->p[1].mdl, &p->p[1].res, 0, 1);
        Model0218fe1c_SetAnim(&p->p[1].mdl, data_ov015_0221289f, 0x1000, 0);
        Model0218fe1c_SetLoop(&p->p[1].mdl);
        p->p[1].mdl.flags.visible = 1;
        Model0218fe1c_SetRes(&p->p[2].mdl, &p->p[2].res, 0, 1);
        Model0218fe1c_SetAnim(&p->p[2].mdl, data_ov015_022128a5, 0x1000, 0);
        Model0218fe1c_SetLoop(&p->p[2].mdl);
        p->p[2].mdl.flags.visible = 1;
        for (n = self->fishList->head; n != NULL; n = n->next) {
            func_ov015_02209500(n->fish);
        }
        func_ov015_021fb474(self->hud);
        if (self->unk_90 != NULL) {
            func_ov015_02210c28();
        }
        gEffectMgr->drawFilter = 1;
        Ov015Fade_ToClear(Ov015_GetFade(), 0x1e000, 0);
        self->step = 0x28;
        SndMgr_PlayVolume(gSndMgr, 0x4f, -1, -1, -1);
        Ov015_BgmFadeTo(0x23);
        break;
    }
    case 0x28:
        Ov015_ModelsReset(self->unk_20);
        if (data_ov015_02213328 == 0) {
            SndMgr_PlayVolume(gSndMgr, 0x3e, -1, -1, -1);
        }
        {
        Ov015MsgMgr *m = self->unk_90;
        data_ov015_02213328 = (data_ov015_02213328 + 1) & 0xff;
        if (m != NULL) {
            if (func_ov015_02210c30(m, &data_ov015_0221332c, 0x28)) {
                self->phase1.unk_0c = 1;
            } else {
                self->phase1.unk_0c = 0;
            }
        }
        }
        if (!func_ov015_021ff4a0(&self->phase1, self->ship, self->cam, self->fishList, &self->info)) {
            self->step = 0x32;
            SndMgr_Stop(gSndMgr, 0x4f);
        }
        {
        Ov015CamPair *cp = self->cam;
        if (Ov015_SysB4()) {
            Ov015_CamFovy(&cp->cam0);
            (&cp->cam0)->vfunc_00();
        } else {
            Ov015_CamFovy(&cp->cam1);
            (&cp->cam1)->vfunc_00();
        }
        }
        break;
    case 0x32:
        Ov015_ModelsReset(self->unk_20);
        if (self->unk_90 == NULL || self->phase2.step < 2 ||
            !func_ov015_02210c30(self->unk_90, &data_ov015_0221332c, 0x32)) {
            func_ov015_021fb5d4(self->hud);
            if (!func_ov015_02200204((Ov015Obj34 *)&self->phase2, self->ship, self->fishList->head->fish,
                                     self->cam, &self->info)) {
                self->step = 0x3c;
                Ov015Fade_ToOpaque(Ov015_GetFade(), 0x1e000, 0x7fff);
                gOv015Globals.mainSeq->unk_08 = Dup::data_ov015_0221332c.unk_30;
                if (Dup::data_ov015_0221332c.unk_30 == 2) {
                    Ov015Fade_ToClear(Ov015_GetFade(), 0x1000, 0x7fff);
                    self->step = 0x50;
                }
            }
        }
        Ov015_CamUpdate(self);
        break;
    case 0x3c: {
        Ov015Fade *f;
        Ov015_CamUpdate(self);
        f = Ov015_GetFade();
        if (f->time < f->duration) {
            break;
        }
        self->step = 0x46;
        {
            SndQueue *pad = gSndQueue.queue;
            if (pad->flag3) {
                pad->unk_06 = 0x8000;
                pad->unk_08 = 0x1e;
                pad->unk_02 = 0;
            }
        }
        func_ov015_0220101c(self);
        EffectMgr_FreeAll(gEffectMgr);
        Ov015Fade_ToClear(Ov015_GetFade(), 0x1000, 0x7fff);
        {
            u32 v = gStageFlags->unk_61c + 1;
            if (v >= 1000) {
                v = 1000;
            }
            gStageFlags->unk_61c = v;
        }
        break;
    }
    case 0x46:
        if (!Ov015Result_Update(self->result)) {
            self->step = 0x50;
        }
        break;
    case 0x50:
        self->step = -1;
        ret = FALSE;
        break;
    default:
        ret = FALSE;
        break;
    }
    return ret;
}

}
