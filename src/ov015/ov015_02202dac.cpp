#include "ov015/ov015.h"

extern "C" {

extern void *data_02149ef8;
void *MsgRes_GetString(void *a, s32 b);
void Obj0215bb14_SetText(void *a, void *b);
void *func_ov015_02207738(Ov015Ship *p);
extern u8 data_ov015_022129c0[];
void MsgBox_Release(void *p);
void *Shadow_DtorBase(void *p);
extern u8 data_ov015_022129d0[];
void *func_ov015_0220765c(Ov015Ship *p);
void func_ov015_02207858(Ov015Ship *p);
void *Shadow_CtorBase(void *p);
void Shadow_Load(void *p);
BOOL func_ov015_022078bc(Ov015Ship *p);
BOOL Shadow_UpdateLoad(void *p);

static inline bool Ov015Task_Flag4(Task *t) {
    return t->unk_04_4;
}

bool Ov015Task_GetFlag4(Task *self) {
    BOOL r = Ov015Task_Flag4(self);
    return r;
}

void Ov015Scene2a88_PreUpdate(Task *self) {
    Task *o;
    if (self->state == 8) {
        return;
    }
    if (self->state != 0xc) {
        return;
    }
    o = TaskHost_RequestSwitch(data_ov000_021ccd44, 0x1f, 0);
    o->param = self->param;
    self->vfunc_4c();
}

BOOL func_ov015_02202e20(Task *self) {
    if (self->vfunc_54()) {
        if (data_ov000_021ccd40 != NULL) {
            data_ov000_021ccd38 = data_ov000_021ccd40->id;
        } else {
            data_ov000_021ccd38 = 0;
        }
        data_ov000_021ccd40 = NULL;
    }
    return TRUE;
}

static inline bool Ov015_IsCurrent(void *p) {
    return data_ov000_021ccd40 == p;
}

bool func_ov015_02202e74(Task *self) {
    BOOL r = Ov015_IsCurrent(self);
    return r;
}

void Ov015Scene2a88_PostUpdate(Ov015Scene2a88 *self) {
    s32 a = self->unk_44;
    s32 r = 0;
    if (a < 0x1000000) {
        r = a + 0x8000;
    }
    self->unk_44 = r;
    if (self->unk_48 >= 0x1000000) {
        self->unk_48 = 0;
    } else {
        self->unk_48 += 0x8000;
    }
}

void Ov015Scene2a88_Draw(Ov015Scene2a88 *self) {
    Model *model = self->model;
    ModelRes *res;
    ModelPart *anim;
    ModelPartRes *t;
    void *arg;
    if (model == NULL || self->unk_40 == 0 || (res = model->res) == NULL) {
        return;
    }
    anim = NULL;
    if (model->numParts > 0) {
        anim = model->parts;
    }
    if (anim != NULL && (t = anim->res) != NULL) {
        arg = t->tex;
    } else {
        void *e = NNS_G2dGetAnimSequenceByIdx(res->mdlRes, 0);
        arg = NNS_G2dGetCellDataByIdx(res->texRes, **(u16 **)FLD(void *, e, 0xc));
    }
    TexObj_DrawCell(model, arg, anim, 0);
}

BOOL func_ov015_02202f44(UiList *self, UiListItem *ev) {
    if (ev != NULL) {
        if (ev->unk_10 != -1) {
            ((Ov015Scene2a08 *)self->owner)->unk_a4 = 1;
            SndMgr_PlayVolume(data_02097e4c, 0x1e, -1, -1, -1);
        } else {
            SndMgr_PlayVolume(data_02097e4c, 0x20, -1, -1, -1);
        }
    }
    return TRUE;
}

BOOL func_ov015_02202fa8(UiList *self, UiListItem *ev) {
    Ov015Scene2a08 *o = (Ov015Scene2a08 *)self->owner;
    void *d = data_02149ef8;
    void *m;
    switch (ev->id) {
    case 0:
        m = MsgRes_GetString(d, 0xc7);
        break;
    case 1:
        m = MsgRes_GetString(d, 0xcb);
        break;
    case 2:
        m = MsgRes_GetString(d, 0xd5);
        break;
    }
    if (o->unk_84 != NULL) {
        Obj0215bb14_SetText(o->unk_84, m);
        o->unk_84->vfunc_70();
    }
    return TRUE;
}

void func_ov015_02203020(Ov015Scene2a08 *self) {
    void *saved;
    HEAP_PUSH(saved);
    {
    Ov015Ship *o = self->ship;
    if (o != NULL) {
        if (o != NULL) {
            func_ov015_02207738(o);
            Heap_Free(o);
        }
        self->ship = NULL;
    }
    }
    HEAP_POP(saved);
    HEAP_PUSH(saved);
    DELETE_V(self->shadow);
    HEAP_POP(saved);
    HEAP_PUSH(saved);
    DELETE_V(self->unk_80);
    HEAP_POP(saved);
    HEAP_PUSH(saved);
    DELETE_V(self->unk_84);
    HEAP_POP(saved);
    HEAP_PUSH(saved);
    DELETE_V(self->unk_88);
    HEAP_POP(saved);
    HEAP_PUSH(saved);
    DELETE_V(self->unk_8c);
    HEAP_POP(saved);
}

void *func_ov015_0220318c(Ov015MsgBox *self) {
    SET_VT(self, data_ov015_022129c0);
    MsgBox_Release(self);
    Heap_Free(self);
    return self;
}

void *func_ov015_022031b4(Ov015Shadow *self) {
    Shadow_DtorBase(self);
    Heap_Free(self);
    return self;
}

void Ov015Scene2a08_Load(Ov015Scene2a08 *self) {
    Ov015Ship *p;
    void *q;
    p = (Ov015Ship *)Heap_Alloc(0xd58);
    if (p != NULL) {
        p = (Ov015Ship *)func_ov015_0220765c(p);
    }
    self->ship = p;
    func_ov015_02207858(p);
    ((Ov015Ship *)self->ship)->modelIdx = data_ov015_02213368->unk_2c;
    q = Heap_Alloc(0x1c);
    if (q != NULL) {
        Shadow_CtorBase(q);
        SET_VT(q, data_ov015_022129d0);
    }
    self->shadow = (Ov015Shadow *)q;
    Shadow_Load(q);
}

BOOL Ov015Scene2a08_IsLoaded(Ov015Scene2a08 *self) {
    BOOL r = func_ov015_022078bc(self->ship) & 1 ? TRUE : FALSE;
    u8 st = self->shadow->state;
    BOOL idle = TRUE;
    if (st != 3 && st != 0) {
        idle = FALSE;
    }
    if (!idle) {
        r = r & Shadow_UpdateLoad(self->shadow) ? TRUE : FALSE;
    }
    return r;
}

extern u8 data_ov000_021cac60[];
extern u8 data_ov000_021caec8[];
extern u8 data_ov000_021cb5a8[];
extern u8 data_ov000_021cadcc[];
extern u8 data_ov015_02212990[];
extern u8 data_ov015_0221299d[];
extern u8 data_ov015_02213360;
BOOL func_ov015_02207adc(Ov015Ship *p);
void func_020434e0(void *p);
void MsgBox_Init(void *p);
void MsgBox_Open(void *p, s32 a, void *b, void *c, s32 d);
void Gfx3DState_SetDefaults(void *p);
void Gfx3DState_Apply(void *p);


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

void Ov015Scene2a08_Start(Ov015Scene2a08 *self) {
    VObj *p;
    void *res;
    if (self->vfunc_28()) {
        return;
    }
    res = data_02149ef8;
    self->ship->unk_d3c = 2;
    func_ov015_02207adc(self->ship);
    {
        Ov015Ship *o = self->ship;
        o->rotX = 0;
        o->rotY = 0;
        o->rotZ = 0;
    }
    self->ship->unk_d40 = 0;
    self->ship->unk_d41 = 0;
    {
        Ov015Shadow *n = self->shadow;
        n->prev = n->type;
        n->type = 3;
    }
    self->shadow->unk_10 = 0;
    self->shadow->unk_0c = 0;
    self->shadow->alpha = 0x14;
    self->camView.eye.x = 0x27d7;
    self->camView.eye.y = 0x4ee1;
    self->camView.eye.z = 0x6052;
    self->camView.at.x = -0x130a;
    self->camView.at.y = 0x14cd;
    self->camView.at.z = -0x452;
    self->camView.up.x = 0;
    self->camView.up.y = 0x1000;
    self->camView.up.z = 0;
    func_020434e0(&self->camView.fovSin);
    p = (VObj *)Heap_Alloc(0xe0);
    if (p != NULL) {
        SET_VT(p, data_ov000_021cac60);
        p->vfunc_28();
        SET_VT(p, data_ov000_021caec8);
        p->vfunc_28();
        SET_VT(p, data_ov000_021cb5a8);
        p->vfunc_28();
    }
    self->unk_88 = (UiList *)p;
    self->unk_88->flags |= 0x4000000;
    self->unk_88->slideMode = 1;
    Ov015_SetUiPos(self->unk_88, 0x91, 0x12, -0x333);
    Ov015_SetUiSlide(self->unk_88, 0x100, 0, -0x333);
    self->unk_88->flags |= 0x20000000;
    self->unk_88->vfunc_f4(1, MsgRes_GetString(res, 0x32));
    self->unk_88->vfunc_08();
    p = (VObj *)Heap_Alloc(0xd4);
    if (p != NULL) {
        SET_VT(p, data_ov000_021cac60);
        p->vfunc_28();
        SET_VT(p, data_ov000_021caec8);
        p->vfunc_28();
    }
    self->unk_80 = (UiList *)p;
    self->unk_80->vfunc_10(MsgRes_GetString(res, 0xc4));
    self->unk_80->vfunc_14(MsgRes_GetString(res, 0xc5));
    self->unk_80->width = 0x88;
    self->unk_80->rows = 4;
    Ov015_SetUiPos(self->unk_80, 0, 0x1e, -0xccd);
    Ov015_SetUiSlide(self->unk_80, 0, -0x100, -0xccd);
    self->unk_80->slideMode = 1;
    self->unk_80->flags &= ~0x400000;
    self->unk_80->flags &= ~0x800000;
    self->unk_80->flags &= ~0x20000;
    self->unk_80->flags &= ~0x80000;
    self->unk_80->flags &= ~0x40000;
    self->unk_80->flags &= ~0x10000;
    self->unk_80->vfunc_74(MsgRes_GetString(res, 0xc6), 0, 0xffff, 0xffff);
    self->unk_80->vfunc_74(MsgRes_GetString(res, 0xca), 1, 0xffff, 0xffff);
    self->unk_80->vfunc_74(MsgRes_GetString(res, 0xd4), 2, 0xffff, 0xffff);
    {
        UiList *o = self->unk_80;
        o->vfunc_a8(UiList_GetItemById(o, 0));
    }
    self->unk_80->onDecide = func_ov015_02202f44;
    self->unk_80->onCursor = func_ov015_02202fa8;
    self->unk_80->owner = self;
    self->unk_80->vfunc_08();
    p = (VObj *)Heap_Alloc(0x8c);
    if (p != NULL) {
        SET_VT(p, data_ov000_021cac60);
        p->vfunc_28();
        SET_VT(p, data_ov000_021cadcc);
        p->vfunc_28();
    }
    self->unk_84 = (Lo021cadcc *)p;
    self->unk_84->width = 0xf8;
    self->unk_84->rows = 2;
    Ov015_SetUiPos(self->unk_84, 4, 0x95, -0xccd);
    Ov015_SetUiSlide(self->unk_84, -0x100, 0, -0xccd);
    self->unk_84->slideMode = 1;
    Obj0215bb14_SetText(self->unk_84, MsgRes_GetString(res, 0xc7));
    self->unk_84->vfunc_70();
    self->unk_84->vfunc_08();
    switch (self->param) {
    case 1:
        if (data_ov015_02213360 == 0) {
            p = (VObj *)Heap_Alloc(0x2c);
            if (p != NULL) {
                SET_VT(p, data_ov015_022129c0);
                MsgBox_Init(p);
            }
            self->unk_8c = (Ov015MsgBox *)p;
            MsgBox_Open(self->unk_8c, 5, data_ov015_02212990, data_ov015_0221299d, 0);
            self->unk_80->flags |= 4;
            self->unk_84->flags |= 4;
            self->unk_88->flags |= 2;
            self->unk_84->flags |= 2;
        }
    case 2: {
        UiListItem *o = UiList_GetItemById(self->unk_80, 1);
        o->unk_24 = 0xe;
        o->unk_10 = -1;
        o = UiList_GetItemById(self->unk_80, 2);
        o->unk_24 = 0xe;
        o->unk_10 = -1;
        break;
    }
    }
    {
        GfxSys *g = data_02097d48;
        Gfx3DState_SetDefaults(g->unk_8b0);
        g->unk_8b0[0] |= 0x30;
        REG16(0x4000060) = (REG16(0x4000060) & ~0x3000) | 0x20;
        Gfx3DState_Apply(g->unk_8b0);
    }
    TaskList_Insert(self);
    if (++data_ov015_02213360 > 100) {
        data_ov015_02213360 = 100;
    }
}

}
