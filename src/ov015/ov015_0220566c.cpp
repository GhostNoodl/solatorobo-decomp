#include "ov015/ov015.h"

extern "C" {

extern u8 gTaskSwitchPending;
u8 *func_0206ef88(u16 id);
void GfxSys_StartFadeOut(int a, int b, int c);
BOOL MsgBox_Update(void *p);
void *func_0206ec8c(u16 id);
void Obj0215bb14_SetText(void *a, void *b);
void MsgBox_Render(void *p);
extern void *gMsgRes;
void *MsgRes_GetString(void *a, s32 b);
void func_0206ecd4(s32 n, void *buf, u16 id);
BOOL func_ov015_02206888(Ov015Scene2b08 *o);

void func_ov015_0220566c(Ov015Scene2b88 *self, s32 a) {
    if (a == 1 || a == -1) {
        self->unk_54 = 0xffff;
        self->unk_3c->flags &= ~4;
        SndMgr_PlayVolume(gSndMgr, 0x1f, -1, -1, -1);
    } else {
        u32 r;
        u16 price;
        self->unk_50 = 4;
        self->unk_3c->flags |= 2;
        self->unk_40->flags |= 2;
        self->unk_44->flags |= 2;
        self->unk_48->flags |= 2;
        SndMgr_PlayVolume(gSndMgr, 0x1e, -1, -1, -1);
        gTaskSwitchPending = 1;
        gTaskHost->unk_00_0 = 1;
        self->parent = 0;
        self->unk_04 |= 6;
        gOv015Shared->unk_0a = self->unk_54;
        price = FLD(u16, func_0206ef88(gOv015Shared->unk_08), 0x0);
        r = 0;
        if (gStageFlags->unk_020 > price) {
            r = gStageFlags->unk_020 - price;
        }
        gStageFlags->unk_020 = r;
        GfxSys_StartFadeOut(self->unk_3c->openLen, 2, -1);
    }
    self->unk_48->flags |= 2;
    self->unk_48->flags |= 4;
}

static inline BOOL Ov015_IsState5c(UiObj *o) {
    return o->state == 5 ? TRUE : FALSE;
}
void Ov015Scene2b88_UpdateActive(Ov015Scene2b88 *self) {
    if (((s32)self->unk_4c) != 0) {
        return;
    }
    if (!Ov015_IsState5c(self->unk_48)) {
        return;
    }
    if (gPad->trig != 2) {
        return;
    }
    SndMgr_PlayVolume(gSndMgr, 0x1f, -1, -1, -1);
    self->unk_3c->flags |= 2;
    self->unk_40->flags |= 2;
    self->unk_44->flags |= 2;
    self->unk_48->flags |= 2;
    TaskHost_RequestSwitch(gTaskHost, 0x20, self->param);
    self->unk_04 |= 6;
    self->parent = 0;
    self->unk_50 = 1;
}

static inline UiListItem *Ov015_ListNthB(UiList *o) {
    UiListItem *r = NULL;
    UiListItem *p = o->topItem;
    if (p != NULL) {
        s32 n = o->cursor;
        while (n-- != 0) {
            p = p->next;
        }
        r = p;
    }
    return r;
}
void Ov015Scene2b88_PreUpdate(Ov015Scene2b88 *self) {
    void *saved;
    void *s;
    switch (self->state) {
    case 8:
        break;
    case 0xa:
        SndMgr_PlayVolume(gSndMgr, 0x27, -1, -1, -1);
        break;
    }
    self->unk_3c->vfunc_1c();
    self->unk_40->vfunc_1c();
    self->unk_44->vfunc_1c();
    self->unk_48->vfunc_1c();
    if (self->unk_4c == NULL) {
        return;
    }
    if (MsgBox_Update(self->unk_4c)) {
        return;
    }
    HEAP_PUSH(saved);
    DELETE_V(self->unk_4c);
    HEAP_POP(saved);
    self->unk_3c->flags &= ~4;
    self->unk_40->flags &= ~4;
    self->unk_44->flags &= ~2;
    self->unk_40->flags &= ~2;
    self->unk_40->state = 0;
    s = func_0206ec8c(Ov015_ListNthB(self->unk_3c)->id);
    if (self->unk_40 != NULL && s != NULL) {
        Obj0215bb14_SetText(self->unk_40, s);
        self->unk_40->vfunc_70();
    }
}

void Ov015Scene2b88_PostUpdate(void) {
}

void Ov015Scene2b88_Draw(Ov015Scene2b88 *self) {
    if (self->vfunc_28() == 0) {
        return;
    }
    self->unk_3c->vfunc_20();
    self->unk_40->vfunc_20();
    self->unk_44->vfunc_20();
    self->unk_48->vfunc_20();
    if (self->unk_4c == NULL) {
        return;
    }
    MsgBox_Render(self->unk_4c);
}

BOOL Ov015Scene2b08_List3cOnCursor(UiList *self, UiListItem *ev) {
    Ov015Scene2b08 *o = (Ov015Scene2b08 *)self->owner;
    if (ev != NULL) {
        func_0206ecd4(0x100, o->textBuf, ev->id);
        if (o->unk_44 != NULL) {
            Obj0215bb14_SetText(o->unk_44, o->textBuf);
            o->unk_44->vfunc_70();
        }
    } else {
        void *m = MsgRes_GetString(gMsgRes, 0x9d);
        if (o->unk_44 != NULL) {
            Obj0215bb14_SetText(o->unk_44, m);
            o->unk_44->vfunc_70();
        }
    }
    return TRUE;
}

BOOL Ov015Scene2b08_List3cOnDecide(UiList *self, UiListItem *ev) {
    if (ev != NULL) {
        Ov015Scene2b08 *o = (Ov015Scene2b08 *)self->owner;
        Lo021cb0b8 *t;
        o->unk_4c->flags &= ~2;
        o->unk_4c->flags &= ~4;
        t = o->unk_4c;
        t->vfunc_a8(UiList_GetItemById(t, 1));
        SndMgr_PlayVolume(gSndMgr, 0x1e, -1, -1, -1);
    }
    return TRUE;
}

BOOL Ov015Scene2b08_List4cOnDecide(UiList *self, UiListItem *item) {
    Ov015Scene2b08 *o = (Ov015Scene2b08 *)self->owner;
    if (item != NULL) {
        switch (item->id) {
        case 0:
            if (func_ov015_02206888(o)) {
                SndMgr_PlayVolume(gSndMgr, 0x30, -1, -1, -1);
            } else {
                SndMgr_PlayVolume(gSndMgr, 0x20, -1, -1, -1);
            }
            break;
        default:
            SndMgr_PlayVolume(gSndMgr, 0x1f, -1, -1, -1);
            break;
        }
    } else {
        SndMgr_PlayVolume(gSndMgr, 0x1f, -1, -1, -1);
    }
    o->unk_4c->flags |= 2;
    o->unk_4c->flags |= 4;
    return FALSE;
}

void func_ov015_02205c7c(Ov015Scene2b08 *self) {
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

void Ov015Scene2b08_Load(void) {
}

s32 Ov015Scene2b08_IsLoaded(void) {
    return 1;
}

extern u8 UiObj_vtbl[];
extern u8 UiList_vtbl[];
extern u8 UiList021cb4a8_vtbl[];
extern u8 Ov000Vt_021cb2a8_vtbl[];
extern u8 Lo021cae48_vtbl[];
extern u8 Lo021cadcc_vtbl[];
extern u8 Lo021cb5a8_vtbl[];
extern u8 Ov000Vt_021cb1b0_vtbl[];
extern u8 Ov000Vt_021cb0b8_vtbl[];
extern u8 Ov000Vt_021cafc0_vtbl[];
extern u8 Lo021cad50_vtbl[];
extern void *data_0208ccc8;
extern u8 data_ov015_022129ac[];
void UiList021cb4a8_SetLabel(void *a, void *b);
void UiList021cb4a8_SetCenteredLabel(void *a, void *b);
void UiList_SetIconModel(void *a, void *b, void *c, u16 d);
BOOL func_0206f66c(u16 id);
u8 *func_0206f000(u16 id);
void *Param_Get(u16 id);
s32 func_0206f080(u16 id);

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

void Ov015Scene2b08_Start(Ov015Scene2b08 *self) {
    VObj *p;
    s32 i;
    u16 id;
    void *res;
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
        SET_VT(p, Ov000Vt_021cb2a8_vtbl);
    }
    self->unk_3c = (UiList *)p;
    self->unk_3c->vfunc_10(MsgRes_GetString(res, 0xca));
    self->unk_3c->vfunc_14(MsgRes_GetString(res, 0xcb));
    UiList021cb4a8_SetLabel(self->unk_3c, MsgRes_GetString(res, 0xa1));
    UiList021cb4a8_SetCenteredLabel(self->unk_3c, MsgRes_GetString(res, 0x3f));
    self->unk_3c->rows = 5;
    self->unk_3c->width = 0xf8;
    Ov015_SetUiPos(self->unk_3c, 0, 0x2c, -0xccd);
    Ov015_SetUiSlide(self->unk_3c, -0x100, 0, -0xccd);
    self->unk_3c->slideMode = 1;
    self->unk_3c->flags |= 0x400000;
    self->unk_3c->unk_c0 = 0x78;
    self->unk_3c->unk_c1 = 5;
    self->unk_3c->flags |= 0x40000;
    UiList_SetIconModel(self->unk_3c, data_0208ccc8, data_ov015_022129ac, 0xffff);
    for (i = 0; i < 13; i++) {
        id = i | 0xc000;
        if (!func_0206f66c(id)) {
            u8 *e = func_0206f000(id);
            switch (e[0]) {
            case 0: {
                u16 k = FLD(u16, e, 2);
                void *a = Param_Get(k);
                ((UiListItem *)self->unk_3c->vfunc_74(a, k, (u16)func_0206f080(k), FLD(u16, e, 4)))->unk_10 = id;
                break;
            }
            case 1: {
                void *a = Param_Get(id);
                ((UiListItem *)self->unk_3c->vfunc_74(a, id, (u16)func_0206f080(id), FLD(u16, e, 4)))->unk_10 = id;
                break;
            }
            }
        }
    }
    {
        UiList *o = self->unk_3c;
        o->vfunc_a8(UiList_GetItemById(o, 0));
    }
    self->unk_3c->owner = self;
    self->unk_3c->onDecide = Ov015Scene2b08_List3cOnDecide;
    self->unk_3c->onCursor = Ov015Scene2b08_List3cOnCursor;
    self->unk_3c->vfunc_08();
    p = (VObj *)Heap_Alloc(0x98);
    if (p != NULL) {
        SET_VT(p, UiObj_vtbl);
        p->vfunc_28();
        SET_VT(p, Lo021cae48_vtbl);
        p->vfunc_28();
    }
    self->unk_40 = (Ov015UiNum *)p;
    Ov015_SetUiPos(self->unk_40, 0x86, 0x87, -0xccd);
    Ov015_SetUiSlide(self->unk_40, 0x100, 0, -0xccd);
    self->unk_40->slideMode = 1;
    self->unk_40->unk_84 = 1;
    Lo021cae48_SetValue(self->unk_40, gStageFlags->unk_618, 0);
    self->unk_40->vfunc_08();
    p = (VObj *)Heap_Alloc(0x8c);
    if (p != NULL) {
        SET_VT(p, UiObj_vtbl);
        p->vfunc_28();
        SET_VT(p, Lo021cadcc_vtbl);
        p->vfunc_28();
    }
    self->unk_44 = (Lo021cadcc *)p;
    self->unk_44->width = 0xf8;
    self->unk_44->rows = 2;
    Ov015_SetUiPos(self->unk_44, 4, 0x95, -0x99a);
    Ov015_SetUiSlide(self->unk_44, -0x100, 0, -0x99a);
    self->unk_44->slideMode = 1;
    self->unk_44->vfunc_08();
    if (self->unk_3c->itemCount != 0) {
        func_0206ecd4(0x100, self->textBuf, Ov015_ListNthB(self->unk_3c)->id);
        if (self->unk_44 != NULL) {
            Obj0215bb14_SetText(self->unk_44, self->textBuf);
            self->unk_44->vfunc_70();
        }
    } else {
        void *s = MsgRes_GetString(gMsgRes, 0x9d);
        if (self->unk_44 != NULL) {
            Obj0215bb14_SetText(self->unk_44, s);
            self->unk_44->vfunc_70();
        }
    }
    p = (VObj *)Heap_Alloc(0xe0);
    if (p != NULL) {
        SET_VT(p, UiObj_vtbl);
        p->vfunc_28();
        SET_VT(p, UiList_vtbl);
        p->vfunc_28();
        SET_VT(p, Lo021cb5a8_vtbl);
        p->vfunc_28();
    }
    self->unk_48 = (UiList *)p;
    self->unk_48->flags |= 0x4000000;
    self->unk_48->slideMode = 1;
    Ov015_SetUiPos(self->unk_48, 0x91, 0x12, -0x333);
    Ov015_SetUiSlide(self->unk_48, 0x100, 0, -0x333);
    self->unk_48->flags |= 0x20000000;
    self->unk_48->vfunc_f4(1, MsgRes_GetString(res, 0x32));
    self->unk_48->vfunc_f4(2, MsgRes_GetString(res, 0x33));
    self->unk_48->vfunc_08();
    p = (VObj *)Heap_Alloc(0x1e4);
    if (p != NULL) {
        SET_VT(p, UiObj_vtbl);
        p->vfunc_28();
        SET_VT(p, UiList_vtbl);
        p->vfunc_28();
        SET_VT(p, Ov000Vt_021cb1b0_vtbl);
        p->vfunc_28();
        SET_VT(p, Ov000Vt_021cb0b8_vtbl);
        p->vfunc_28();
        SET_VT(p, Ov000Vt_021cafc0_vtbl);
        p->vfunc_28();
    }
    self->unk_4c = (Lo021cb0b8 *)p;
    self->unk_4c->vfunc_10(MsgRes_GetString(res, 0xd6));
    self->unk_4c->onDecide = Ov015Scene2b08_List4cOnDecide;
    self->unk_4c->posZ = -0x666;
    self->unk_4c->vfunc_08();
    self->unk_4c->owner = self;
    self->unk_4c->flags |= 2;
    self->unk_4c->flags |= 4;
    p = (VObj *)Heap_Alloc(0xe8);
    if (p != NULL) {
        SET_VT(p, UiObj_vtbl);
        p->vfunc_28();
        SET_VT(p, Lo021cad50_vtbl);
        p->vfunc_28();
    }
    self->unk_50 = (UiObj *)p;
    self->unk_50->font = 4;
    self->unk_50->vfunc_08();
    self->unk_50->flags |= 0x20000;
    self->unk_50->posZ = -0x333;
    self->unk_50->flags |= 2;
    self->fadeLen = self->unk_3c->openLen;
    TaskList_Insert(self);
}

}
