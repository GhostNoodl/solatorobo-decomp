#include "ov015/ov015.h"

extern "C" {

extern u8 gTaskSwitchPending;
void GfxSys_StartFadeOut(int a, int b, int c);
extern void *gMsgRes;
void *MsgRes_GetString(void *a, int id);
void Obj0215bb14_SetText(void *a, void *b);
void func_ov015_02203ee0(Ov015Scene2a08 *self);
void func_ov015_02207c30(Ov015Ship *p);
BOOL MsgBox_Update(void *p);
extern Ov015Vec data_ov015_02212614;
extern Ov015Vec data_ov015_02212620;
void MsgBox_Render(void *p);
void Ov015Shadow_DrawAt(void *a, Ov015Vec *pos, s32 b, s32 c, s32 ang, s32 d);
void func_ov015_02208070(Ov015Ship *p);
void *func_0206ec8c(u16 id);

static inline UiListItem *Ov015_ListNth2(UiList *o) {
    UiListItem *p = o->topItem;
    s32 n;
    if (p == NULL) return NULL;
    n = o->cursor;
    while (n-- != 0) {
        p = p->next;
    }
    return p;

}
void Ov015Scene2a08_UpdateActive(Ov015Scene2a08 *self) {
    u16 keys;
    if (self->unk_8c != NULL) return;
    keys = gPad->trig;
    if (self->unk_a4 != 0) {
        UiListItem *item = Ov015_ListNth2(self->unk_80);
        switch (item->id) {
        case 0:
            self->unk_94 = 1;
            TaskHost_RequestSwitch(gTaskHost, 0x20, self->param);
            self->parent = 0;
            self->unk_04 |= 6;
            self->unk_80->flags |= 2;
            self->unk_84->flags |= 2;
            self->unk_88->flags |= 2;
            break;
        case 1:
            self->unk_94 = 3;
            TaskHost_RequestSwitch(gTaskHost, 0x22, self->param);
            self->parent = 0;
            self->unk_04 |= 6;
            self->unk_80->flags |= 2;
            self->unk_84->flags |= 2;
            self->unk_88->flags |= 2;
            break;
        case 2:
            self->unk_94 = 5;
            gTaskSwitchPending = 1;
            gTaskHost->unk_00_0 = 1;
            self->parent = 0;
            self->unk_04 |= 6;
            self->unk_80->flags |= 2;
            self->unk_84->flags |= 2;
            self->unk_88->flags |= 2;
            GfxSys_StartFadeOut(self->unk_80->openLen, 2, -1);
            break;
        }
    } else if (keys & 2) {
        UiList *o;
        SndMgr_PlayVolume(gSndMgr, 0x1f, -1, -1, -1);
        o = self->unk_80;
        o->vfunc_a8(UiList_GetItemById(o, 2));
    }
    self->unk_a4 = 0;
}

static inline UiListItem *Ov015_ListNth3(UiList *o) {
    UiListItem *p = o->topItem;
    s32 n;
    if (p == NULL) return NULL;
    n = o->cursor;
    while (n-- != 0) {
        p = p->next;
    }
    return p;
}
void Ov015Scene2a08_PreUpdate(Ov015Scene2a08 *self) {
    Ov015Vec out;
    Ov015Vec v;
    s32 k;
    switch (self->state) {
    case 8:
        SndMgr_PlayVolume(gSndMgr, 0x27, -1, -1, -1);
        break;
    case 10:
        SndMgr_PlayVolume(gSndMgr, 0x27, -1, -1, -1);
        break;
    case 13:
        func_ov015_02203ee0(self);
        break;
    }
    k = FX_Mul(0x1000 - self->unk_80->openRatio, 0x3000);
    v.x = -0x64a4;
    v.y = 0;
    v.z = 0x3ae1;
    VEC_Normalize(&v, &v);
    VEC_MultAdd(k, &v, &data_ov015_02212614, &out);
    self->camView.eye = out;
    VEC_MultAdd(k, &v, &data_ov015_02212620, &out);
    self->camView.at = out;
    if (self->unk_8c != NULL && !MsgBox_Update(self->unk_8c)) {
        void *saved;
        UiList *o;
        Ov015Scene2a08 *t;
        void *s;
        HEAP_PUSH(saved);
        DELETE_V(self->unk_8c);
        HEAP_POP(saved);
        self->unk_80->flags &= ~4;
        self->unk_84->flags &= ~4;
        self->unk_88->flags &= ~2;
        self->unk_84->flags &= ~2;
        self->unk_84->state = 0;
        o = self->unk_80;
        {
            UiListItem *item = Ov015_ListNth3(o);
            u16 n = item->id;
            void *d = gMsgRes;
            s32 id;
            t = (Ov015Scene2a08 *)o->owner;
            switch (n) {
            case 0:
                id = 0xc7;
                break;
            case 1:
                id = 0xcb;
                break;
            case 2:
                id = 0xd5;
                break;
            default:
                goto skip;
            }
            s = MsgRes_GetString(d, id);
        }
    skip:
        if (t->unk_84 != NULL) {
            Obj0215bb14_SetText(t->unk_84, s);
            t->unk_84->vfunc_70();
        }
    }
    func_ov015_02207c30(self->ship);
    self->unk_80->vfunc_1c();
    self->unk_84->vfunc_1c();
    self->unk_88->vfunc_1c();
}

void Ov015Scene2a08_PostUpdate(void) {
}

static inline void Ov015_02203d64_Cam(Ov015Scene2a08 *self) {
    NNS_G3dGlb.camPos = *&self->camView.eye;
    NNS_G3dGlb.camUp = *&self->camView.up;
    NNS_G3dGlb.camTarget = *&self->camView.at;
    MTX_LookAt((&self->camView.eye), (&self->camView.up), (&self->camView.at), (MtxFx43 *)data_02092844);
    NNS_G3dGlb.flag &= ~0xe8;
    if (self->camView.projDirty == 1) {
        MTX_PerspectiveW(self->camView.aspect, self->camView.nearClip, self->camView.farClip, self->camView.fovSin,
                      self->camView.fovCos, 0x1000, (MtxFx44 *)data_02092800);
        NNS_G3dGlb.flag &= ~0x50;
        self->camView.projDirty = 0;
    }
}
void Ov015Scene2a08_Draw(Ov015Scene2a08 *self) {
    Ov015Ship *o;
    if (self->fadeRatio == NULL) return;
    Task_Draw(self);
    Ov015_02203d64_Cam(self);
    func_ov015_02208070(self->ship);
    o = self->ship;
    {
        Ov015Vec v = o->pos;
        Ov015Shadow_DrawAt(self->shadow, &v, 0x2000, 0x2000, o->rotY, o->rotX);
    }
    self->unk_80->vfunc_20();
    self->unk_84->vfunc_20();
    self->unk_88->vfunc_20();
    if (self->unk_8c != NULL) MsgBox_Render(self->unk_8c);
}

void func_ov015_02203ee0(Ov015Scene2a08 *self) {
    Ov015Ship *o = self->ship;
    u16 pad;
    if (o == NULL) {
        return;
    }
    {
    u16 a = (self->frame % 1200) * 0xffff / 1200;
    o->rotX = 0;
    o->rotY = a;
    o->rotZ = 0;
    }
    pad = gPad->cur;
    if (pad & 0x20) {
        self->ship->unk_d3a = 2;
        self->unk_ac = 0x3c;
    } else if (pad & 0x10) {
        self->ship->unk_d3a = 1;
        self->unk_ac = 0x3c;
    } else if (pad & 0x800) {
        self->ship->unk_d3a = 3;
        self->unk_ac = 0x3c;
    }
    if (self->unk_ac == 0) {
        self->ship->unk_d3a = 0;
        self->unk_ac = 0x3c;
    }
    if (++self->frame > 60000) {
        self->frame = 0;
    }
    if (--self->unk_ac < 0) {
        self->unk_ac = 0;
    }
}

BOOL Ov015Scene2c08_List3cOnCursor(UiList *self, UiListItem *ev) {
    Ov015Scene2c08 *o;
    u16 id;
    id = ev->id;
    o = (Ov015Scene2c08 *)self->owner;
    void *m = func_0206ec8c(id);
    if (o->unk_40 != NULL) {
        Obj0215bb14_SetText(o->unk_40, m);
        o->unk_40->vfunc_70();
    }
    o->unk_68 = id;
    return TRUE;
}

BOOL Ov015Scene2c08_List3cOnDecide(UiList *self, UiListItem *item) {
    BOOL r = TRUE;
    Ov015Scene2c08 *o = (Ov015Scene2c08 *)self->owner;
    if (item != NULL) {
        if (item->unk_10 == -1) {
            SndMgr_PlayVolume(gSndMgr, 0x20, -1, -1, -1);
        } else if (item->unk_0c > gStageFlags->unk_020) {
            void *s = MsgRes_GetString(gMsgRes, 0x9b);
            if (o->unk_40 != NULL) {
                Obj0215bb14_SetText(o->unk_40, s);
                o->unk_40->vfunc_70();
            }
            SndMgr_PlayVolume(gSndMgr, 0x20, -1, -1, -1);
        } else {
            SndMgr_PlayVolume(gSndMgr, 0x1e, -1, -1, -1);
            o->unk_6a = 1;
            o->unk_68 = item->id;
            r = FALSE;
        }
    }
    return r;
}

void func_ov015_02204110(Ov015Scene2c08 *self) {
    void *saved;
    HEAP_PUSH(saved);
    DELETE_V(self->unk_3c);
    HEAP_POP(saved);
    HEAP_PUSH(saved);
    DELETE_V(self->unk_40);
    HEAP_POP(saved);
    HEAP_PUSH(saved);
    DELETE_V(self->unk_44);
    HEAP_POP(saved);
    HEAP_PUSH(saved);
    DELETE_V(self->unk_48);
    HEAP_POP(saved);
    HEAP_PUSH(saved);
    DELETE_V(self->unk_4c);
    HEAP_POP(saved);
    HEAP_PUSH(saved);
    DELETE_V(self->unk_50);
    HEAP_POP(saved);
}

void Ov015Scene2c08_Load(void) {
}

s32 Ov015Scene2c08_IsLoaded(void) {
    return 1;
}

extern u8 UiObj_vtbl[];
extern u8 UiList_vtbl[];
extern u8 UiList021cb4a8_vtbl[];
extern u8 Lo021cb5a8_vtbl[];
extern u8 Lo021cadcc_vtbl[];
extern u8 Lo021cae48_vtbl[];
extern u8 Ov015MsgBox_vtbl[];
extern u8 data_ov015_02212990[];
extern u8 data_ov015_0221299d[];
extern u8 data_ov015_02213360[];
void UiList021cb4a8_SetLabel(void *a, void *b);
void UiList021cb4a8_SetCenteredLabel(void *a, void *b);
u16 *func_0206ef88(u16 id);
void *Param_Get(u16 id);
void MsgBox_Init(void *p);
void MsgBox_Open(void *p, s32 a, void *b, void *c, s32 d);

static inline void Ov015_SetUiPos(UiObj *o, s16 x, s16 y, s16 z) {
    o->posX = x;
    o->posY = y;
    o->posZ = z;
}

static inline void Ov015_SetUiSlide(UiObj *o, s32 x, s32 y, s32 z) {
    o->slideX = x;
    o->slideY = y;
    o->slideZ = z;
}

void Ov015Scene2c08_Start(Ov015Scene2c08 *self) {
    VObj *p;
    void *res;
    s32 i;
    u16 id;
    UiListItem *o;
    if (self->vfunc_28()) {
        return;
    }
    res = gMsgRes;
    p = (VObj *)Heap_Alloc(0xe0);
    if (p != NULL) {
        SET_VT(p, UiObj_vtbl);
        p->vfunc_28();
        SET_VT(p, UiList_vtbl);
        p->vfunc_28();
        SET_VT(p, UiList021cb4a8_vtbl);
        p->vfunc_28();
    }
    self->unk_3c = (UiList *)p;
    self->unk_3c->vfunc_10(MsgRes_GetString(res, 0xc6));
    self->unk_3c->vfunc_14(MsgRes_GetString(res, 0xc7));
    self->unk_3c->rows = 5;
    self->unk_3c->width = 0xf8;
    Ov015_SetUiPos(self->unk_3c, 0, 0x2c, -0xccd);
    Ov015_SetUiSlide(self->unk_3c, -0x100, 0, -0xccd);
    self->unk_3c->slideMode = 1;
    self->unk_3c->flags |= 0x400000;
    self->unk_3c->unk_c0 = 0x78;
    self->unk_3c->flags &= ~0x800000;
    self->unk_3c->unk_c1 = 5;
    switch (self->param) {
    case 1:
    case 2:
        for (i = 0; i < 8; i++) {
            u16 *e;
            id = i | 0xa000;
            e = func_0206ef88(id);
            o = (UiListItem *)self->unk_3c->vfunc_74(Param_Get(id), id, 0xffff, *e);
            if (i > 0) {
                o->unk_24 = 0xe;
                o->unk_10 = -1;
            }
        }
        break;
    default:
        for (i = 1; i < 8; i++) {
            u16 *e;
            id = i | 0xa000;
            e = func_0206ef88(id);
            self->unk_3c->vfunc_74(Param_Get(id), id, 0xffff, *e);
        }
        break;
    }
    UiList021cb4a8_SetLabel(self->unk_3c, MsgRes_GetString(res, 0xa4));
    UiList021cb4a8_SetCenteredLabel(self->unk_3c, MsgRes_GetString(res, 0x3e));
    {
        UiList *o = self->unk_3c;
        o->vfunc_a8(UiList_GetItemById(o, 0));
    }
    self->unk_3c->onDecide = Ov015Scene2c08_List3cOnDecide;
    self->unk_3c->onCursor = Ov015Scene2c08_List3cOnCursor;
    self->unk_3c->owner = self;
    self->unk_3c->vfunc_08();
    p = (VObj *)Heap_Alloc(0x8c);
    if (p != NULL) {
        SET_VT(p, UiObj_vtbl);
        p->vfunc_28();
        SET_VT(p, Lo021cadcc_vtbl);
        p->vfunc_28();
    }
    self->unk_40 = (Lo021cadcc *)p;
    self->unk_40->width = 0xf8;
    self->unk_40->rows = 2;
    Ov015_SetUiPos(self->unk_40, 4, 0x95, -0xccd);
    Ov015_SetUiSlide(self->unk_40, -0x100, 0, -0xccd);
    self->unk_40->slideMode = 1;
    {
        void *s = func_0206ec8c(self->unk_3c->items->id);
        if (self->unk_40 != NULL) {
            Obj0215bb14_SetText(self->unk_40, s);
            self->unk_40->vfunc_70();
        }
    }
    self->unk_40->vfunc_08();
    p = (VObj *)Heap_Alloc(0xe0);
    if (p != NULL) {
        SET_VT(p, UiObj_vtbl);
        p->vfunc_28();
        SET_VT(p, UiList_vtbl);
        p->vfunc_28();
        SET_VT(p, Lo021cb5a8_vtbl);
        p->vfunc_28();
    }
    self->unk_44 = (UiList *)p;
    self->unk_44->flags |= 0x4000000;
    self->unk_44->slideMode = 1;
    Ov015_SetUiPos(self->unk_44, 0x91, 0x12, -0x333);
    Ov015_SetUiSlide(self->unk_44, 0x100, 0, -0x333);
    self->unk_44->flags |= 0x20000000;
    self->unk_44->vfunc_f4(1, MsgRes_GetString(res, 0x32));
    self->unk_44->vfunc_f4(2, MsgRes_GetString(res, 0x33));
    self->unk_44->vfunc_08();
    p = (VObj *)Heap_Alloc(0x98);
    if (p != NULL) {
        SET_VT(p, UiObj_vtbl);
        p->vfunc_28();
        SET_VT(p, Lo021cae48_vtbl);
        p->vfunc_28();
    }
    self->unk_48 = (Ov015UiNum *)p;
    Ov015_SetUiPos(self->unk_48, 0x86, 0x87, -0xccd);
    Ov015_SetUiSlide(self->unk_48, 0x100, 0, -0xccd);
    self->unk_48->slideMode = 1;
    Lo021cae48_SetValue(self->unk_48, gStageFlags->unk_020, 0);
    self->unk_48->vfunc_08();
    if (self->param == 1 && data_ov015_02213360[1] == 0) {
        p = (VObj *)Heap_Alloc(0x2c);
        if (p != NULL) {
            SET_VT(p, Ov015MsgBox_vtbl);
            MsgBox_Init(p);
        }
        self->unk_50 = (Ov015MsgBox *)p;
        MsgBox_Open(self->unk_50, 6, data_ov015_02212990, data_ov015_0221299d, 0);
        self->unk_3c->flags |= 4;
        self->unk_44->flags |= 2;
        self->unk_40->flags |= 2;
    }
    self->fadeLen = self->unk_3c->openLen;
    TaskList_Insert(self);
    if (++data_ov015_02213360[1] > 100) {
        data_ov015_02213360[1] = 100;
    }
}

}
