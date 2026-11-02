#include "ov015/ov015.h"

extern "C" {

extern u8 *data_ov000_021ccd44;
extern u8 data_ov000_021ccd34;
extern u8 *data_0214a424;
u8 *func_0206ef88(u16 id);
void func_0203cc58(int a, int b, int c);
extern u8 *data_02097dc8;
void *func_ov000_0218084c(void *a, s32 b, s32 c);
BOOL func_ov000_021633ac(void *p);
void *func_0206ec8c(u16 id);
void func_ov000_0215bb14(void *a, void *b);
void func_ov000_02163594(void *p);
extern void *data_02149ef8;
void *MsgRes_GetString(void *a, s32 b);
void func_0206ecd4(s32 n, void *buf, u16 id);
void *func_ov000_02154b58(void *a, s32 b);
BOOL func_ov015_02206888(Ov015Scene2b08 *o);

void func_ov015_0220566c(Ov015Scene2b88 *self, s32 a) {
    if (a == 1 || a == -1) {
        self->unk_54 = 0xffff;
        self->unk_3c->flags &= ~4;
        func_02049a48(data_02097e4c, 0x1f, -1, -1, -1);
    } else {
        u32 r;
        u16 price;
        self->unk_50 = 4;
        self->unk_3c->flags |= 2;
        self->unk_40->flags |= 2;
        self->unk_44->flags |= 2;
        self->unk_48->flags |= 2;
        func_02049a48(data_02097e4c, 0x1e, -1, -1, -1);
        data_ov000_021ccd34 = 1;
        ((Ov015ObjFlags *)data_ov000_021ccd44)->b0 = 1;
        self->parent = 0;
        self->unk_04 |= 6;
        data_ov015_02213368->unk_0a = self->unk_54;
        price = FLD(u16, func_0206ef88(data_ov015_02213368->unk_08), 0x0);
        r = 0;
        if (FLD(u32, data_0214a424, 0x20) > price) {
            r = FLD(u32, data_0214a424, 0x20) - price;
        }
        FLD(u32, data_0214a424, 0x20) = r;
        func_0203cc58(self->unk_3c->openLen, 2, -1);
    }
    self->unk_48->flags |= 2;
    self->unk_48->flags |= 4;
}

static inline BOOL Ov015_IsState5c(UiObj *o) {
    return o->state == 5 ? TRUE : FALSE;
}
void func_ov015_022057dc(Ov015Scene2b88 *self) {
    if (((s32)self->unk_4c) != 0) {
        return;
    }
    if (!Ov015_IsState5c(self->unk_48)) {
        return;
    }
    if (FLD(u16, data_02097dc8, 0x12) != 2) {
        return;
    }
    func_02049a48(data_02097e4c, 0x1f, -1, -1, -1);
    self->unk_3c->flags |= 2;
    self->unk_40->flags |= 2;
    self->unk_44->flags |= 2;
    self->unk_48->flags |= 2;
    func_ov000_0218084c(data_ov000_021ccd44, 0x20, self->param);
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
void func_ov015_022058d0(Ov015Scene2b88 *self) {
    void *saved;
    void *s;
    switch (self->state) {
    case 8:
        break;
    case 0xa:
        func_02049a48(data_02097e4c, 0x27, -1, -1, -1);
        break;
    }
    VCALL(self->unk_3c)->v1c();
    VCALL(self->unk_40)->v1c();
    VCALL(self->unk_44)->v1c();
    VCALL(self->unk_48)->v1c();
    if (self->unk_4c == NULL) {
        return;
    }
    if (func_ov000_021633ac(self->unk_4c)) {
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
        func_ov000_0215bb14(self->unk_40, s);
        VCALL(self->unk_40)->v70();
    }
}

void func_ov015_02205a60(void) {
}

void func_ov015_02205a64(Ov015Scene2b88 *self) {
    if (VCALL(self)->v28() == 0) {
        return;
    }
    VCALL(self->unk_3c)->v20();
    VCALL(self->unk_40)->v20();
    VCALL(self->unk_44)->v20();
    VCALL(self->unk_48)->v20();
    if (self->unk_4c == NULL) {
        return;
    }
    func_ov000_02163594(self->unk_4c);
}

BOOL func_ov015_02205ad4(UiList *self, UiListItem *ev) {
    Ov015Scene2b08 *o = (Ov015Scene2b08 *)self->owner;
    if (ev != NULL) {
        func_0206ecd4(0x100, o->textBuf, ev->id);
        if (o->unk_44 != NULL) {
            func_ov000_0215bb14(o->unk_44, o->textBuf);
            VCALL(o->unk_44)->v70();
        }
    } else {
        void *m = MsgRes_GetString(data_02149ef8, 0x9d);
        if (o->unk_44 != NULL) {
            func_ov000_0215bb14(o->unk_44, m);
            VCALL(o->unk_44)->v70();
        }
    }
    return TRUE;
}

BOOL func_ov015_02205b48(UiList *self, UiListItem *ev) {
    if (ev != NULL) {
        Ov015Scene2b08 *o = (Ov015Scene2b08 *)self->owner;
        u8 *t;
        o->unk_4c->flags &= ~2;
        o->unk_4c->flags &= ~4;
        t = ((u8 *)o->unk_4c);
        VCALL(t)->va8(func_ov000_02154b58(t, 1));
        func_02049a48(data_02097e4c, 0x1e, -1, -1, -1);
    }
    return TRUE;
}

BOOL func_ov015_02205bc8(UiList *self, UiListItem *item) {
    Ov015Scene2b08 *o = (Ov015Scene2b08 *)self->owner;
    if (item != NULL) {
        switch (item->id) {
        case 0:
            if (func_ov015_02206888(o)) {
                func_02049a48(data_02097e4c, 0x30, -1, -1, -1);
            } else {
                func_02049a48(data_02097e4c, 0x20, -1, -1, -1);
            }
            break;
        default:
            func_02049a48(data_02097e4c, 0x1f, -1, -1, -1);
            break;
        }
    } else {
        func_02049a48(data_02097e4c, 0x1f, -1, -1, -1);
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

void func_ov015_02205de4(void) {
}

s32 func_ov015_02205de8(void) {
    return 1;
}

extern u8 data_ov000_021cac60[];
extern u8 data_ov000_021caec8[];
extern u8 data_ov000_021cb4a8[];
extern u8 data_ov000_021cb2a8[];
extern u8 data_ov000_021cae48[];
extern u8 data_ov000_021cadcc[];
extern u8 data_ov000_021cb5a8[];
extern u8 data_ov000_021cb1b0[];
extern u8 data_ov000_021cb0b8[];
extern u8 data_ov000_021cafc0[];
extern u8 data_ov000_021cad50[];
extern void *data_0208ccc8;
extern u8 data_ov015_022129ac[];
void func_ov000_02157c90(void *a, void *b);
void func_ov000_02157d2c(void *a, void *b);
void func_ov000_021546ec(void *a, void *b, void *c, u16 d);
BOOL func_0206f66c(u16 id);
u8 *func_0206f000(u16 id);
void *func_0206ec48(u16 id);
s32 func_0206f080(u16 id);
void func_ov000_0215d980(void *a, void *b, s32 c);
void func_ov000_02173648(void *self);

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

void func_ov015_02205df0(Ov015Scene2b08 *self) {
    u8 *p;
    s32 i;
    u16 id;
    void *res;
    if (VCALL(self)->v28()) {
        return;
    }
    res = data_02149ef8;
    p = (u8 *)Heap_Alloc(0xe0);
    if (p != NULL) {
        SET_VT(p, data_ov000_021cac60);
        VCALL(p)->v28();
        SET_VT(p, data_ov000_021caec8);
        VCALL(p)->v28();
        SET_VT(p, data_ov000_021cb4a8);
        VCALL(p)->v28();
        SET_VT(p, data_ov000_021cb2a8);
    }
    FLD(u8 *, self, 0x3c) = p;
    VCALL(self->unk_3c)->v10(MsgRes_GetString(res, 0xca));
    VCALL(self->unk_3c)->v14(MsgRes_GetString(res, 0xcb));
    func_ov000_02157c90(self->unk_3c, MsgRes_GetString(res, 0xa1));
    func_ov000_02157d2c(self->unk_3c, MsgRes_GetString(res, 0x3f));
    self->unk_3c->rows = 5;
    self->unk_3c->width = 0xf8;
    Ov015_SetUiPos(self->unk_3c, 0, 0x2c, -0xccd);
    Ov015_SetUiSlide(self->unk_3c, -0x100, 0, -0xccd);
    self->unk_3c->slideMode = 1;
    self->unk_3c->flags |= 0x400000;
    self->unk_3c->unk_c0 = 0x78;
    self->unk_3c->unk_c1 = 5;
    self->unk_3c->flags |= 0x40000;
    func_ov000_021546ec(self->unk_3c, data_0208ccc8, data_ov015_022129ac, 0xffff);
    for (i = 0; i < 13; i++) {
        id = i | 0xc000;
        if (!func_0206f66c(id)) {
            u8 *e = func_0206f000(id);
            switch (e[0]) {
            case 0: {
                u16 k = FLD(u16, e, 2);
                void *a = func_0206ec48(k);
                FLD(s32, VCALL(self->unk_3c)->v74(a, k, (u16)func_0206f080(k), FLD(u16, e, 4)), 0x10) = id;
                break;
            }
            case 1: {
                void *a = func_0206ec48(id);
                FLD(s32, VCALL(self->unk_3c)->v74(a, id, (u16)func_0206f080(id), FLD(u16, e, 4)), 0x10) = id;
                break;
            }
            }
        }
    }
    {
        UiList *o = self->unk_3c;
        VCALL(o)->va8(func_ov000_02154b58(o, 0));
    }
    self->unk_3c->owner = self;
    self->unk_3c->onDecide = func_ov015_02205b48;
    self->unk_3c->onCursor = func_ov015_02205ad4;
    VCALL(self->unk_3c)->v08();
    p = (u8 *)Heap_Alloc(0x98);
    if (p != NULL) {
        SET_VT(p, data_ov000_021cac60);
        VCALL(p)->v28();
        SET_VT(p, data_ov000_021cae48);
        VCALL(p)->v28();
    }
    FLD(u8 *, self, 0x40) = p;
    Ov015_SetUiPos(self->unk_40, 0x86, 0x87, -0xccd);
    Ov015_SetUiSlide(self->unk_40, 0x100, 0, -0xccd);
    self->unk_40->slideMode = 1;
    FLD(s32, self->unk_40, 0x84) = 1;
    func_ov000_0215d980(self->unk_40, FLD(void *, data_0214a424, 0x618), 0);
    VCALL(self->unk_40)->v08();
    p = (u8 *)Heap_Alloc(0x8c);
    if (p != NULL) {
        SET_VT(p, data_ov000_021cac60);
        VCALL(p)->v28();
        SET_VT(p, data_ov000_021cadcc);
        VCALL(p)->v28();
    }
    FLD(u8 *, self, 0x44) = p;
    self->unk_44->width = 0xf8;
    self->unk_44->rows = 2;
    Ov015_SetUiPos(self->unk_44, 4, 0x95, -0x99a);
    Ov015_SetUiSlide(self->unk_44, -0x100, 0, -0x99a);
    self->unk_44->slideMode = 1;
    VCALL(self->unk_44)->v08();
    if (self->unk_3c->itemCount != 0) {
        func_0206ecd4(0x100, self->textBuf, Ov015_ListNthB(self->unk_3c)->id);
        if (self->unk_44 != NULL) {
            func_ov000_0215bb14(self->unk_44, self->textBuf);
            VCALL(self->unk_44)->v70();
        }
    } else {
        void *s = MsgRes_GetString(data_02149ef8, 0x9d);
        if (self->unk_44 != NULL) {
            func_ov000_0215bb14(self->unk_44, s);
            VCALL(self->unk_44)->v70();
        }
    }
    p = (u8 *)Heap_Alloc(0xe0);
    if (p != NULL) {
        SET_VT(p, data_ov000_021cac60);
        VCALL(p)->v28();
        SET_VT(p, data_ov000_021caec8);
        VCALL(p)->v28();
        SET_VT(p, data_ov000_021cb5a8);
        VCALL(p)->v28();
    }
    FLD(u8 *, self, 0x48) = p;
    self->unk_48->flags |= 0x4000000;
    self->unk_48->slideMode = 1;
    Ov015_SetUiPos(self->unk_48, 0x91, 0x12, -0x333);
    Ov015_SetUiSlide(self->unk_48, 0x100, 0, -0x333);
    self->unk_48->flags |= 0x20000000;
    VCALL(self->unk_48)->vf4(1, MsgRes_GetString(res, 0x32));
    VCALL(self->unk_48)->vf4(2, MsgRes_GetString(res, 0x33));
    VCALL(self->unk_48)->v08();
    p = (u8 *)Heap_Alloc(0x1e4);
    if (p != NULL) {
        SET_VT(p, data_ov000_021cac60);
        VCALL(p)->v28();
        SET_VT(p, data_ov000_021caec8);
        VCALL(p)->v28();
        SET_VT(p, data_ov000_021cb1b0);
        VCALL(p)->v28();
        SET_VT(p, data_ov000_021cb0b8);
        VCALL(p)->v28();
        SET_VT(p, data_ov000_021cafc0);
        VCALL(p)->v28();
    }
    FLD(u8 *, self, 0x4c) = p;
    VCALL(self->unk_4c)->v10(MsgRes_GetString(res, 0xd6));
    self->unk_4c->onDecide = func_ov015_02205bc8;
    self->unk_4c->posZ = -0x666;
    VCALL(self->unk_4c)->v08();
    self->unk_4c->owner = self;
    self->unk_4c->flags |= 2;
    self->unk_4c->flags |= 4;
    p = (u8 *)Heap_Alloc(0xe8);
    if (p != NULL) {
        SET_VT(p, data_ov000_021cac60);
        VCALL(p)->v28();
        SET_VT(p, data_ov000_021cad50);
        VCALL(p)->v28();
    }
    FLD(u8 *, self, 0x50) = p;
    self->unk_50->font = 4;
    VCALL(self->unk_50)->v08();
    self->unk_50->flags |= 0x20000;
    self->unk_50->posZ = -0x333;
    self->unk_50->flags |= 2;
    self->fadeLen = self->unk_3c->openLen;
    func_ov000_02173648(self);
}

}
