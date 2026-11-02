#include "ov015/ov015.h"

extern "C" {

BOOL func_ov000_021633ac(void *p);
void *func_0206ec8c(u16 id);
void func_ov000_0215bb14(void *a, void *b);
void func_ov000_02163594(void *p);
extern u8 data_ov015_02212b88[];

void func_ov015_022048a0(Ov015Scene2c08 *self) {
    if (self->unk_50 != NULL) {
        return;
    }
    if (data_02097dc8->trig & 2) {
        func_02049a48(data_02097e4c, 0x1f, -1, -1, -1);
        self->unk_3c->flags |= 2;
        self->unk_40->flags |= 2;
        self->unk_44->flags |= 2;
        self->unk_48->flags |= 2;
        func_ov000_0218084c(data_ov000_021ccd44, 0x1f, self->param);
        self->unk_58 = 0;
        self->unk_04 |= 6;
        self->parent = 0;
    } else if (self->unk_6a != 0) {
        self->unk_3c->flags |= 2;
        self->unk_40->flags |= 2;
        self->unk_44->flags |= 2;
        self->unk_48->flags |= 2;
        data_ov015_02213368->unk_08 = self->unk_68;
        func_ov000_0218084c(data_ov000_021ccd44, 0x21, self->param);
        self->unk_58 = 2;
        self->unk_04 |= 6;
        self->parent = 0;
    }
}

static inline UiListItem *Ov015_ListNth(UiList *o) {
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
void func_ov015_022049f8(Ov015Scene2c08 *self) {
    void *saved;
    UiListItem *item;
    Ov015Scene2c08 *o2;
    u16 id;
    switch (self->state) {
    case 8:
        func_02049a48(data_02097e4c, 0x27, -1, -1, -1);
        break;
    case 0xa:
        func_02049a48(data_02097e4c, 0x27, -1, -1, -1);
        break;
    }
    self->unk_3c->vfunc_1c();
    self->unk_40->vfunc_1c();
    self->unk_44->vfunc_1c();
    self->unk_48->vfunc_1c();
    if (self->unk_50 == NULL) {
        return;
    }
    if (func_ov000_021633ac(self->unk_50)) {
        return;
    }
    HEAP_PUSH(saved);
    DELETE_V(self->unk_50);
    HEAP_POP(saved);
    self->unk_3c->flags &= ~4;
    self->unk_44->flags &= ~2;
    self->unk_40->flags &= ~2;
    self->unk_40->state = 0;
    item = Ov015_ListNth(self->unk_3c);
    id = item->id;
    o2 = (Ov015Scene2c08 *)self->unk_3c->owner;
    {
        void *s = func_0206ec8c(id);
        if (o2->unk_40 != NULL) {
            func_ov000_0215bb14(o2->unk_40, s);
            o2->unk_40->vfunc_70();
        }
    }
    o2->unk_68 = id;
}

void func_ov015_02204b88(Ov015Scene2c08 *self) {
    s32 a = self->unk_5c;
    s32 r = 0x1000000;
    if (a > 0) {
        r = a - 0x8000;
    }
    self->unk_5c = r;
    if (self->unk_60 >= 0x1000000) {
        self->unk_60 = 0;
    } else {
        self->unk_60 += 0x8000;
    }
}

void func_ov015_02204bb4(Ov015Scene2c08 *self) {
    if (self->fadeRatio == NULL) {
        return;
    }
    func_ov000_0217357c(self);
    self->unk_3c->vfunc_20();
    self->unk_40->vfunc_20();
    self->unk_44->vfunc_20();
    self->unk_48->vfunc_20();
    if (self->unk_50 == NULL) {
        return;
    }
    func_ov000_02163594(self->unk_50);
}

static inline BOOL Ov015_IsState5b(UiObj *o) {
    return o->state == 5 ? TRUE : FALSE;
}
BOOL func_ov015_02204c20(UiList *self, UiListItem *item) {
    if (item != NULL) {
        if ((s32)item->unk_10 < 0) {
            func_02049a48(data_02097e4c, 0x20, -1, -1, -1);
        } else {
            Ov015Scene2b88 *o;
            Lo021cb0b8 *p;
            func_02049a48(data_02097e4c, 0x1e, -1, -1, -1);
            o = (Ov015Scene2b88 *)self->owner;
            o->unk_54 = item->id;
            p = o->unk_48;
            if (p != NULL && Ov015_IsState5b(p)) {
                p->flags &= ~2;
                o->unk_48->flags &= ~4;
                p = o->unk_48;
                p->vfunc_a8(func_ov000_02154b58(p, 1));
                o->unk_3c->flags |= 4;
            }
        }
    }
    return TRUE;
}

BOOL func_ov015_02204d00(UiList *self, UiListItem *ev) {
    if (ev != NULL) {
        Ov015Scene2b88 *o = (Ov015Scene2b88 *)self->owner;
        void *m = func_0206ec8c(ev->id);
        if (o->unk_40 != NULL && m != NULL) {
            func_ov000_0215bb14(o->unk_40, m);
            o->unk_40->vfunc_70();
        }
    }
    return TRUE;
}

BOOL func_ov015_02204d48(UiList *self, UiListItem *ev) {
    func_ov015_0220566c((Ov015Scene2b88 *)self->owner, ev != NULL ? ev->id : -1);
    return TRUE;
}

void *Ov015Scene2b88_Dtor(Ov015Scene2b88 *self) {
    void *saved;
    SET_VT(self, data_ov015_02212b88);
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
    Ov015TaskBase_Dtor(self);
    return self;
}

void *Ov015Scene2b88_DtorDelete(Ov015Scene2b88 *self) {
    void *saved;
    SET_VT(self, data_ov015_02212b88);
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
    Ov015TaskBase_Dtor(self);
    Heap_Free(self);
    return self;
}

void func_ov015_02205028(void) {
}

s32 func_ov015_0220502c(void) {
    return 1;
}

extern void *data_02149ef8;
void *MsgRes_GetString(void *a, s32 b);
extern u8 data_ov000_021cac60[];
extern u8 data_ov000_021caec8[];
extern u8 data_ov000_021cb4a8[];
extern u8 data_ov000_021cadcc[];
extern u8 data_ov000_021cb5a8[];
extern u8 data_ov000_021cb1b0[];
extern u8 data_ov000_021cb0b8[];
extern u8 data_ov015_022129c0[];
extern u8 data_ov015_02212990[];
extern u8 data_ov015_0221299d[];
extern u8 data_ov015_02213360[];
void func_ov000_02157c90(void *a, void *b);
void *func_0206ec48(u16 id);
void func_ov000_02163224(void *p);
void func_ov000_021632f0(void *p, s32 a, void *b, void *c, s32 d);

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

void func_ov015_02205034(Ov015Scene2b88 *self) {
    BOOL f;
    u16 i;
    u16 id;
    VObj *p;
    void *res;
    if (self->vfunc_28()) {
        return;
    }
    res = data_02149ef8;
    p = (VObj *)Heap_Alloc(0xe0);
    if (p != NULL) {
        SET_VT(p, data_ov000_021cac60);
        p->vfunc_28();
        SET_VT(p, data_ov000_021caec8);
        p->vfunc_28();
        SET_VT(p, data_ov000_021cb4a8);
        p->vfunc_28();
    }
    self->unk_3c = (UiList *)p;
    self->unk_3c->vfunc_10(MsgRes_GetString(res, 0xc8));
    self->unk_3c->vfunc_14(MsgRes_GetString(res, 0xc9));
    self->unk_3c->rows = 4;
    self->unk_3c->width = 0xf8;
    Ov015_SetUiPos(self->unk_3c, 0, 0x2c, -0xccd);
    Ov015_SetUiSlide(self->unk_3c, -0x100, 0, -0xccd);
    self->unk_3c->slideMode = 1;
    self->unk_3c->flags &= ~0x400000;
    self->unk_3c->flags &= ~0x800000;
    self->unk_3c->flags &= ~0x20000;
    self->unk_3c->flags &= ~0x10000;
    f = self->param == 1 || self->param == 2;
    for (i = 0; i < 4; i++) {
        UiListItem *o;
        id = i | 0xd000;
        o = (UiListItem *)self->unk_3c->vfunc_74(func_0206ec48(id), id, 0xffff, 0xffff);
        if (f && i >= 1) {
            o->unk_24 = 0xe;
            o->unk_10 = -1;
        }
    }
    func_ov000_02157c90(self->unk_3c, MsgRes_GetString(res, 0xa5));
    {
        UiList *o = self->unk_3c;
        o->vfunc_a8(func_ov000_02154b58(o, 0));
    }
    self->unk_3c->onDecide = func_ov015_02204c20;
    self->unk_3c->onCursor = func_ov015_02204d00;
    self->unk_3c->owner = self;
    self->unk_3c->vfunc_08();
    p = (VObj *)Heap_Alloc(0x8c);
    if (p != NULL) {
        SET_VT(p, data_ov000_021cac60);
        p->vfunc_28();
        SET_VT(p, data_ov000_021cadcc);
        p->vfunc_28();
    }
    self->unk_40 = (Lo021cadcc *)p;
    self->unk_40->rows = 2;
    Ov015_SetUiPos(self->unk_40, 4, 0x95, -0xccd);
    self->unk_40->width = 0xf8;
    Ov015_SetUiSlide(self->unk_40, -0x100, 0, -0xccd);
    self->unk_40->slideMode = 1;
    self->unk_40->vfunc_08();
    {
        void *m = func_0206ec8c(Ov015_ListNth(self->unk_3c)->id);
        if (self->unk_40 != NULL && m != NULL) {
            func_ov000_0215bb14(self->unk_40, m);
            self->unk_40->vfunc_70();
        }
    }
    p = (VObj *)Heap_Alloc(0xe0);
    if (p != NULL) {
        SET_VT(p, data_ov000_021cac60);
        p->vfunc_28();
        SET_VT(p, data_ov000_021caec8);
        p->vfunc_28();
        SET_VT(p, data_ov000_021cb5a8);
        p->vfunc_28();
    }
    self->unk_44 = (UiList *)p;
    self->unk_44->flags |= 0x4000000;
    self->unk_44->slideMode = 1;
    Ov015_SetUiPos(self->unk_44, 0x91, 0x12, -0x666);
    Ov015_SetUiSlide(self->unk_44, 0x100, 0, -0x666);
    self->unk_44->flags |= 0x20000000;
    self->unk_44->vfunc_f4(1, MsgRes_GetString(res, 0x32));
    self->unk_44->vfunc_f4(2, MsgRes_GetString(res, 0x33));
    self->unk_44->vfunc_08();
    p = (VObj *)Heap_Alloc(0x1e4);
    if (p != NULL) {
        SET_VT(p, data_ov000_021cac60);
        p->vfunc_28();
        SET_VT(p, data_ov000_021caec8);
        p->vfunc_28();
        SET_VT(p, data_ov000_021cb1b0);
        p->vfunc_28();
        SET_VT(p, data_ov000_021cb0b8);
        p->vfunc_28();
    }
    self->unk_48 = (Lo021cb0b8 *)p;
    self->unk_48->msgId = 0x8d;
    self->unk_48->text = (char *)MsgRes_GetString(res, 0x24);
    self->unk_48->key = 1;
    self->unk_48->onDecide = func_ov015_02204d48;
    self->unk_48->owner = self;
    self->unk_48->vfunc_08();
    self->unk_48->posZ = -0x333;
    self->unk_48->flags |= 2;
    if (self->param == 1 && data_ov015_02213360[2] == 0) {
        p = (VObj *)Heap_Alloc(0x2c);
        if (p != NULL) {
            SET_VT(p, data_ov015_022129c0);
            func_ov000_02163224(p);
        }
        self->unk_4c = (Ov015MsgBox *)p;
        func_ov000_021632f0(self->unk_4c, 7, data_ov015_02212990, data_ov015_0221299d, 0);
        self->unk_3c->flags |= 4;
        self->unk_40->flags |= 4;
        self->unk_44->flags |= 2;
        self->unk_40->flags |= 2;
    }
    self->fadeLen = self->unk_3c->openLen;
    func_ov000_02173648(self);
    if (++data_ov015_02213360[2] > 100) {
        data_ov015_02213360[2] = 100;
    }
}

}
