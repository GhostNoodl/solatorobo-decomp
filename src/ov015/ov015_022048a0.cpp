#include "ov015/ov015.h"

extern "C" {

extern u8 *data_02097dc8;
extern void *data_02097e4c;
extern u8 *data_ov000_021ccd44;
extern Ov015Shared *data_ov015_02213368;
void *func_02049a48(void *a, int b, int c, int d, int e);
void *func_ov000_0218084c(void *a, s32 b, s32 c);
BOOL func_ov000_021633ac(void *p);
void *func_0206ec8c(u16 id);
void func_ov000_0215bb14(void *a, void *b);
void func_ov000_0217357c(void *self);
void func_ov000_02163594(void *p);
void *func_ov000_02154b58(void *a, s32 b);
void func_ov015_0220566c(void *self, s32 id);
extern u8 data_ov015_02212b88[];

void func_ov015_022048a0(Ov015Scene2c08 *self) {
    if (((s32)self->unk_50) != 0) {
        return;
    }
    if (FLD(u16, data_02097dc8, 0x12) & 2) {
        func_02049a48(data_02097e4c, 0x1f, -1, -1, -1);
        self->unk_3c->unk_0c |= 2;
        self->unk_40->unk_0c |= 2;
        self->unk_44->unk_0c |= 2;
        self->unk_48->unk_0c |= 2;
        func_ov000_0218084c(data_ov000_021ccd44, 0x1f, self->unk_0c);
        self->unk_58 = 0;
        FLD(u32, self, 0x4) |= 6;
        self->unk_2c = 0;
    } else if (self->unk_6a != 0) {
        self->unk_3c->unk_0c |= 2;
        self->unk_40->unk_0c |= 2;
        self->unk_44->unk_0c |= 2;
        self->unk_48->unk_0c |= 2;
        FLD(u16, data_ov015_02213368, 0x8) = self->unk_68;
        func_ov000_0218084c(data_ov000_021ccd44, 0x21, self->unk_0c);
        self->unk_58 = 2;
        FLD(u32, self, 0x4) |= 6;
        self->unk_2c = 0;
    }
}

static inline Ov015MenuItem *Ov015_ListNth(Ov015Menu *o) {
    Ov015MenuItem *r = NULL;
    Ov015MenuItem *p = o->unk_98;
    if (p != NULL) {
        s32 n = o->unk_b1;
        while (n-- != 0) {
            p = p->unk_2c;
        }
        r = p;
    }
    return r;
}
void func_ov015_022049f8(Ov015Scene2c08 *self) {
    u32 saved;
    Ov015MenuItem *item;
    u8 *o2;
    u16 id;
    switch (self->unk_08) {
    case 8:
        func_02049a48(data_02097e4c, 0x27, -1, -1, -1);
        break;
    case 0xa:
        func_02049a48(data_02097e4c, 0x27, -1, -1, -1);
        break;
    }
    VCALL(self->unk_3c)->v1c();
    VCALL(self->unk_40)->v1c();
    VCALL(self->unk_44)->v1c();
    VCALL(self->unk_48)->v1c();
    if (self->unk_50 == NULL) {
        return;
    }
    if (func_ov000_021633ac(self->unk_50)) {
        return;
    }
    HEAP_PUSH(saved);
    DELETE_V(self->unk_50);
    HEAP_POP(saved);
    self->unk_3c->unk_0c &= ~4;
    self->unk_44->unk_0c &= ~2;
    self->unk_40->unk_0c &= ~2;
    self->unk_40->unk_04 = 0;
    item = Ov015_ListNth(self->unk_3c);
    id = item->unk_06;
    o2 = self->unk_3c->unk_08;
    {
        void *s = func_0206ec8c(id);
        if (FLD(void *, o2, 0x40) != NULL) {
            func_ov000_0215bb14(FLD(void *, o2, 0x40), s);
            VCALL(FLD(void *, o2, 0x40))->v70();
        }
    }
    FLD(u16, o2, 0x68) = id;
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
    if (self->unk_24 == NULL) {
        return;
    }
    func_ov000_0217357c(self);
    VCALL(self->unk_3c)->v20();
    VCALL(self->unk_40)->v20();
    VCALL(self->unk_44)->v20();
    VCALL(self->unk_48)->v20();
    if (self->unk_50 == NULL) {
        return;
    }
    func_ov000_02163594(self->unk_50);
}

static inline BOOL Ov015_IsState5b(Ov015Ui *o) {
    return o->unk_04 == 5 ? TRUE : FALSE;
}
BOOL func_ov015_02204c20(Ov015Menu *self, Ov015MenuItem *item) {
    if (item != NULL) {
        if (item->unk_10 < 0) {
            func_02049a48(data_02097e4c, 0x20, -1, -1, -1);
        } else {
            Ov015Scene2b88 *o;
            Ov015Dialog *p;
            func_02049a48(data_02097e4c, 0x1e, -1, -1, -1);
            o = (Ov015Scene2b88 *)self->unk_08;
            o->unk_54 = item->unk_06;
            p = o->unk_48;
            if (p != NULL && Ov015_IsState5b(p)) {
                p->unk_0c &= ~2;
                o->unk_48->unk_0c &= ~4;
                p = o->unk_48;
                VCALL(p)->va8(func_ov000_02154b58(p, 1));
                o->unk_3c->unk_0c |= 4;
            }
        }
    }
    return TRUE;
}

BOOL func_ov015_02204d00(Ov015Menu *self, Ov015MenuItem *ev) {
    if (ev != NULL) {
        Ov015Scene2b88 *o = (Ov015Scene2b88 *)self->unk_08;
        void *m = func_0206ec8c(ev->unk_06);
        if (o->unk_40 != NULL && m != NULL) {
            func_ov000_0215bb14(o->unk_40, m);
            VCALL(o->unk_40)->v70();
        }
    }
    return TRUE;
}

BOOL func_ov015_02204d48(Ov015Menu *self, Ov015MenuItem *ev) {
    func_ov015_0220566c(self->unk_08, ev != NULL ? ev->unk_06 : -1);
    return TRUE;
}

void *Ov015Scene2b88_Dtor(Ov015Scene2b88 *self) {
    u32 saved;
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
    u32 saved;
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
void func_ov000_02173648(void *self);

static inline void Ov015_SetXYZ16(Ov015Ui *o, s16 x, s16 y, s16 z) {
    o->unk_64 = x;
    o->unk_66 = y;
    o->unk_68 = z;
}

static inline void Ov015_SetXYZ32(Ov015Ui *o, s32 x, s32 y, s32 z) {
    o->unk_58 = x;
    o->unk_5c = y;
    o->unk_60 = z;
}

void func_ov015_02205034(Ov015Scene2b88 *self) {
    BOOL f;
    u16 i;
    u16 id;
    u8 *p;
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
    }
    self->unk_3c = (Ov015Menu *)p;
    VCALL(self->unk_3c)->v10(MsgRes_GetString(res, 0xc8));
    VCALL(self->unk_3c)->v14(MsgRes_GetString(res, 0xc9));
    self->unk_3c->unk_20 = 4;
    self->unk_3c->unk_24 = 0xf8;
    Ov015_SetXYZ16(self->unk_3c, 0, 0x2c, -0xccd);
    Ov015_SetXYZ32(self->unk_3c, -0x100, 0, -0xccd);
    self->unk_3c->unk_2c = 1;
    self->unk_3c->unk_0c &= ~0x400000;
    self->unk_3c->unk_0c &= ~0x800000;
    self->unk_3c->unk_0c &= ~0x20000;
    self->unk_3c->unk_0c &= ~0x10000;
    f = self->unk_0c == 1 || self->unk_0c == 2;
    for (i = 0; i < 4; i++) {
        u8 *o;
        id = i | 0xd000;
        o = (u8 *)VCALL(self->unk_3c)->v74(func_0206ec48(id), id, 0xffff, 0xffff);
        if (f && i >= 1) {
            FLD(s32, o, 0x24) = 0xe;
            FLD(s32, o, 0x10) = -1;
        }
    }
    func_ov000_02157c90(self->unk_3c, MsgRes_GetString(res, 0xa5));
    {
        Ov015Menu *o = self->unk_3c;
        VCALL(o)->va8(func_ov000_02154b58(o, 0));
    }
    self->unk_3c->unk_84 = (void *)func_ov015_02204c20;
    self->unk_3c->unk_88 = (void *)func_ov015_02204d00;
    self->unk_3c->unk_08 = (u8 *)self;
    VCALL(self->unk_3c)->v08();
    p = (u8 *)Heap_Alloc(0x8c);
    if (p != NULL) {
        SET_VT(p, data_ov000_021cac60);
        VCALL(p)->v28();
        SET_VT(p, data_ov000_021cadcc);
        VCALL(p)->v28();
    }
    self->unk_40 = (Ov015UiLabel *)p;
    self->unk_40->unk_20 = 2;
    Ov015_SetXYZ16(self->unk_40, 4, 0x95, -0xccd);
    self->unk_40->unk_24 = 0xf8;
    Ov015_SetXYZ32(self->unk_40, -0x100, 0, -0xccd);
    self->unk_40->unk_2c = 1;
    VCALL(self->unk_40)->v08();
    {
        void *m = func_0206ec8c(FLD(u16, Ov015_ListNth(self->unk_3c), 0x6));
        if (self->unk_40 != NULL && m != NULL) {
            func_ov000_0215bb14(self->unk_40, m);
            VCALL(self->unk_40)->v70();
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
    self->unk_44 = (Ov015Menu *)p;
    self->unk_44->unk_0c |= 0x4000000;
    self->unk_44->unk_2c = 1;
    Ov015_SetXYZ16(self->unk_44, 0x91, 0x12, -0x666);
    Ov015_SetXYZ32(self->unk_44, 0x100, 0, -0x666);
    self->unk_44->unk_0c |= 0x20000000;
    VCALL(self->unk_44)->vf4(1, MsgRes_GetString(res, 0x32));
    VCALL(self->unk_44)->vf4(2, MsgRes_GetString(res, 0x33));
    VCALL(self->unk_44)->v08();
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
    }
    self->unk_48 = (Ov015Dialog *)p;
    FLD(u16, p, 0x1d8) = 0x8d;
    self->unk_48->unk_1dc = MsgRes_GetString(res, 0x24);
    self->unk_48->unk_1e0 = 1;
    self->unk_48->unk_84 = (void *)func_ov015_02204d48;
    self->unk_48->unk_08 = (u8 *)self;
    VCALL(self->unk_48)->v08();
    self->unk_48->unk_68 = -0x333;
    self->unk_48->unk_0c |= 2;
    if (self->unk_0c == 1 && data_ov015_02213360[2] == 0) {
        p = (u8 *)Heap_Alloc(0x2c);
        if (p != NULL) {
            SET_VT(p, data_ov015_022129c0);
            func_ov000_02163224(p);
        }
        self->unk_4c = p;
        func_ov000_021632f0(self->unk_4c, 7, data_ov015_02212990, data_ov015_0221299d, 0);
        self->unk_3c->unk_0c |= 4;
        self->unk_40->unk_0c |= 4;
        self->unk_44->unk_0c |= 2;
        self->unk_40->unk_0c |= 2;
    }
    self->unk_20 = self->unk_3c->unk_34;
    func_ov000_02173648(self);
    if (++data_ov015_02213360[2] > 100) {
        data_ov015_02213360[2] = 100;
    }
}

}
