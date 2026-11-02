#include "ov015/ov015.h"

extern "C" {

extern u8 *data_02097dc8;
extern u8 *data_ov000_021ccd44;
extern u8 data_ov000_021ccd34;
void *func_ov000_0218084c(void *a, s32 b, s32 c);
void *func_ov000_02154b58(void *a, s32 b);
void func_0203cc58(int a, int b, int c);
extern void *data_02149ef8;
void *MsgRes_GetString(void *a, int id);
void func_ov000_0215bb14(void *a, void *b);
void func_ov015_02203ee0(Ov015Scene2a08 *self);
void func_ov015_02207c30(Ov015Ship *p);
BOOL func_ov000_021633ac(void *p);
extern Ov015Vec data_ov015_02212614;
extern Ov015Vec data_ov015_02212620;
void func_ov000_02163594(void *p);
void func_ov000_0217357c(void *self);
void func_ov015_0220daf4(void *a, Ov015Vec *pos, s32 b, s32 c, s32 ang, s32 d);
void func_ov015_02208070(Ov015Ship *p);
void *func_0206ec8c(u16 id);
extern u8 *data_0214a424;

static inline Ov015MenuItem *Ov015_ListNth2(Ov015Menu *o) {
    Ov015MenuItem *p = o->topItem;
    s32 n;
    if (p == NULL) return NULL;
    n = o->cursor;
    while (n-- != 0) {
        p = p->next;
    }
    return p;

}
struct Ov015Bits32a {
    u32 b0 : 1;
    u32 rest : 31;
};
void func_ov015_022038c8(Ov015Scene2a08 *self) {
    u16 keys;
    if (self->unk_8c != NULL) return;
    keys = FLD(u16, data_02097dc8, 0x12);
    if (self->unk_a4 != 0) {
        Ov015MenuItem *item = Ov015_ListNth2(self->unk_80);
        switch (item->id) {
        case 0:
            self->unk_94 = 1;
            func_ov000_0218084c(data_ov000_021ccd44, 0x20, self->param);
            self->parent = 0;
            FLD(u32, self, 0x4) |= 6;
            self->unk_80->flags |= 2;
            self->unk_84->flags |= 2;
            self->unk_88->flags |= 2;
            break;
        case 1:
            self->unk_94 = 3;
            func_ov000_0218084c(data_ov000_021ccd44, 0x22, self->param);
            self->parent = 0;
            FLD(u32, self, 0x4) |= 6;
            self->unk_80->flags |= 2;
            self->unk_84->flags |= 2;
            self->unk_88->flags |= 2;
            break;
        case 2:
            self->unk_94 = 5;
            data_ov000_021ccd34 = 1;
            FLD(Ov015Bits32a, data_ov000_021ccd44, 0x0).b0 = 1;
            self->parent = 0;
            FLD(u32, self, 0x4) |= 6;
            self->unk_80->flags |= 2;
            self->unk_84->flags |= 2;
            self->unk_88->flags |= 2;
            func_0203cc58(self->unk_80->unk_34, 2, -1);
            break;
        }
    } else if (keys & 2) {
        Ov015Menu *o;
        func_02049a48(data_02097e4c, 0x1f, -1, -1, -1);
        o = self->unk_80;
        VCALL(o)->va8(func_ov000_02154b58(o, 2));
    }
    self->unk_a4 = 0;
}

static inline Ov015MenuItem *Ov015_ListNth3(Ov015Menu *o) {
    Ov015MenuItem *p = o->topItem;
    s32 n;
    if (p == NULL) return NULL;
    n = o->cursor;
    while (n-- != 0) {
        p = p->next;
    }
    return p;
}
void func_ov015_02203ab8(Ov015Scene2a08 *self) {
    Ov015Vec out;
    Ov015Vec v;
    s32 k;
    switch (self->unk_08) {
    case 8:
        func_02049a48(data_02097e4c, 0x27, -1, -1, -1);
        break;
    case 10:
        func_02049a48(data_02097e4c, 0x27, -1, -1, -1);
        break;
    case 13:
        func_ov015_02203ee0(self);
        break;
    }
    k = FX_Mul(0x1000 - self->unk_80->unk_38, 0x3000);
    v.x = -0x64a4;
    v.y = 0;
    v.z = 0x3ae1;
    VEC_Normalize((VecFx32 *)&v, (VecFx32 *)&v);
    VEC_MultAdd(k, (VecFx32 *)&v, (VecFx32 *)&data_ov015_02212614, (VecFx32 *)&out);
    self->camView.eye = out;
    VEC_MultAdd(k, (VecFx32 *)&v, (VecFx32 *)&data_ov015_02212620, (VecFx32 *)&out);
    self->camView.at = out;
    if (self->unk_8c != NULL && !func_ov000_021633ac(self->unk_8c)) {
        void *saved;
        Ov015Menu *o;
        Ov015Scene2a08 *t;
        void *s;
        HEAP_PUSH(saved);
        DELETE_V(self->unk_8c);
        HEAP_POP(saved);
        self->unk_80->flags &= ~4;
        self->unk_84->flags &= ~4;
        self->unk_88->flags &= ~2;
        self->unk_84->flags &= ~2;
        self->unk_84->unk_04 = 0;
        o = self->unk_80;
        {
            Ov015MenuItem *item = Ov015_ListNth3(o);
            u16 n = item->id;
            void *d = data_02149ef8;
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
            func_ov000_0215bb14(t->unk_84, s);
            VCALL(t->unk_84)->v70();
        }
    }
    func_ov015_02207c30(self->ship);
    ((Ov015V *)self->unk_80)->v1c();
    ((Ov015V *)self->unk_84)->v1c();
    ((Ov015V *)self->unk_88)->v1c();
}

void func_ov015_02203d60(void) {
}

static inline void Ov015_02203d64_Cam(Ov015Scene2a08 *self) {
    NNS_G3dGlb.camPos = *(VecFx32 *)&self->camView.eye;
    NNS_G3dGlb.camUp = *(VecFx32 *)&self->camView.up;
    NNS_G3dGlb.camTarget = *(VecFx32 *)&self->camView.at;
    MTX_LookAt((VecFx32 *)(&self->camView.eye), (VecFx32 *)(&self->camView.up), (VecFx32 *)(&self->camView.at), (MtxFx43 *)data_02092844);
    NNS_G3dGlb.flag &= ~0xe8;
    if (self->camView.projDirty == 1) {
        MTX_PerspectiveW(self->camView.aspect, self->camView.nearClip, self->camView.farClip, self->camView.fovSin,
                      self->camView.fovCos, 0x1000, (MtxFx44 *)data_02092800);
        NNS_G3dGlb.flag &= ~0x50;
        self->camView.projDirty = 0;
    }
}
void func_ov015_02203d64(Ov015Scene2a08 *self) {
    Ov015Ship *o;
    if (self->unk_24 == NULL) return;
    func_ov000_0217357c(self);
    Ov015_02203d64_Cam(self);
    func_ov015_02208070(self->ship);
    o = self->ship;
    {
        Ov015Vec v = o->pos;
        func_ov015_0220daf4(self->shadow, &v, 0x2000, 0x2000, o->rotY, o->rotX);
    }
    VCALL(self->unk_80)->v20();
    VCALL(self->unk_84)->v20();
    VCALL(self->unk_88)->v20();
    if (self->unk_8c != NULL) func_ov000_02163594(self->unk_8c);
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
    pad = FLD(u16, data_02097dc8, 0x10);
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

BOOL func_ov015_02203fec(Ov015Menu *self, Ov015MenuItem *ev) {
    Ov015Scene2c08 *o;
    u16 id;
    id = ev->id;
    o = (Ov015Scene2c08 *)self->owner;
    void *m = func_0206ec8c(id);
    if (o->unk_40 != NULL) {
        func_ov000_0215bb14(o->unk_40, m);
        VCALL(o->unk_40)->v70();
    }
    o->unk_68 = id;
    return TRUE;
}

BOOL func_ov015_02204030(Ov015Menu *self, Ov015MenuItem *item) {
    BOOL r = TRUE;
    Ov015Scene2c08 *o = (Ov015Scene2c08 *)self->owner;
    if (item != NULL) {
        if (item->unk_10 == -1) {
            func_02049a48(data_02097e4c, 0x20, -1, -1, -1);
        } else if (item->price > FLD(u32, data_0214a424, 0x20)) {
            void *s = MsgRes_GetString(data_02149ef8, 0x9b);
            if (o->unk_40 != NULL) {
                func_ov000_0215bb14(o->unk_40, s);
                VCALL(o->unk_40)->v70();
            }
            func_02049a48(data_02097e4c, 0x20, -1, -1, -1);
        } else {
            func_02049a48(data_02097e4c, 0x1e, -1, -1, -1);
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

void func_ov015_02204278(void) {
}

s32 func_ov015_0220427c(void) {
    return 1;
}

extern u8 data_ov000_021cac60[];
extern u8 data_ov000_021caec8[];
extern u8 data_ov000_021cb4a8[];
extern u8 data_ov000_021cb5a8[];
extern u8 data_ov000_021cadcc[];
extern u8 data_ov000_021cae48[];
extern u8 data_ov015_022129c0[];
extern u8 data_ov015_02212990[];
extern u8 data_ov015_0221299d[];
extern u8 data_ov015_02213360[];
void func_ov000_02157c90(void *a, void *b);
void func_ov000_02157d2c(void *a, void *b);
u16 *func_0206ef88(u16 id);
void *func_0206ec48(u16 id);
void func_ov000_0215d980(void *a, void *b, s32 c);
void func_ov000_02163224(void *p);
void func_ov000_021632f0(void *p, s32 a, void *b, void *c, s32 d);
void func_ov000_02173648(void *self);

static inline void Ov015_SetXYZ16(Ov015Ui *o, s16 x, s16 y, s16 z) {
    o->posX = x;
    o->posY = y;
    o->posZ = z;
}

static inline void Ov015_SetXYZ32(Ov015Ui *o, s32 x, s32 y, s32 z) {
    o->slideX = x;
    o->slideY = y;
    o->slideZ = z;
}

void func_ov015_02204284(Ov015Scene2c08 *self) {
    u8 *p;
    void *res;
    s32 i;
    u16 id;
    u8 *o;
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
    VCALL(self->unk_3c)->v10(MsgRes_GetString(res, 0xc6));
    VCALL(self->unk_3c)->v14(MsgRes_GetString(res, 0xc7));
    self->unk_3c->rows = 5;
    self->unk_3c->width = 0xf8;
    Ov015_SetXYZ16(self->unk_3c, 0, 0x2c, -0xccd);
    Ov015_SetXYZ32(self->unk_3c, -0x100, 0, -0xccd);
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
            o = (u8 *)VCALL(self->unk_3c)->v74(func_0206ec48(id), id, 0xffff, *e);
            if (i > 0) {
                FLD(s32, o, 0x24) = 0xe;
                FLD(s32, o, 0x10) = -1;
            }
        }
        break;
    default:
        for (i = 1; i < 8; i++) {
            u16 *e;
            id = i | 0xa000;
            e = func_0206ef88(id);
            VCALL(self->unk_3c)->v74(func_0206ec48(id), id, 0xffff, *e);
        }
        break;
    }
    func_ov000_02157c90(self->unk_3c, MsgRes_GetString(res, 0xa4));
    func_ov000_02157d2c(self->unk_3c, MsgRes_GetString(res, 0x3e));
    {
        Ov015Menu *o = self->unk_3c;
        VCALL(o)->va8(func_ov000_02154b58(o, 0));
    }
    self->unk_3c->onDecide = (void *)func_ov015_02204030;
    self->unk_3c->onCursor = (void *)func_ov015_02203fec;
    self->unk_3c->owner = (u8 *)self;
    VCALL(self->unk_3c)->v08();
    p = (u8 *)Heap_Alloc(0x8c);
    if (p != NULL) {
        SET_VT(p, data_ov000_021cac60);
        VCALL(p)->v28();
        SET_VT(p, data_ov000_021cadcc);
        VCALL(p)->v28();
    }
    self->unk_40 = (Ov015UiLabel *)p;
    self->unk_40->width = 0xf8;
    self->unk_40->rows = 2;
    Ov015_SetXYZ16(self->unk_40, 4, 0x95, -0xccd);
    Ov015_SetXYZ32(self->unk_40, -0x100, 0, -0xccd);
    self->unk_40->slideMode = 1;
    {
        void *s = func_0206ec8c(self->unk_3c->items->id);
        if (self->unk_40 != NULL) {
            func_ov000_0215bb14(self->unk_40, s);
            VCALL(self->unk_40)->v70();
        }
    }
    VCALL(self->unk_40)->v08();
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
    self->unk_44->flags |= 0x4000000;
    self->unk_44->slideMode = 1;
    Ov015_SetXYZ16(self->unk_44, 0x91, 0x12, -0x333);
    Ov015_SetXYZ32(self->unk_44, 0x100, 0, -0x333);
    self->unk_44->flags |= 0x20000000;
    VCALL(self->unk_44)->vf4(1, MsgRes_GetString(res, 0x32));
    VCALL(self->unk_44)->vf4(2, MsgRes_GetString(res, 0x33));
    VCALL(self->unk_44)->v08();
    p = (u8 *)Heap_Alloc(0x98);
    if (p != NULL) {
        SET_VT(p, data_ov000_021cac60);
        VCALL(p)->v28();
        SET_VT(p, data_ov000_021cae48);
        VCALL(p)->v28();
    }
    self->unk_48 = (Ov015UiNum *)p;
    Ov015_SetXYZ16(self->unk_48, 0x86, 0x87, -0xccd);
    Ov015_SetXYZ32(self->unk_48, 0x100, 0, -0xccd);
    self->unk_48->slideMode = 1;
    func_ov000_0215d980(self->unk_48, FLD(void *, data_0214a424, 0x20), 0);
    VCALL(self->unk_48)->v08();
    if (self->param == 1 && data_ov015_02213360[1] == 0) {
        p = (u8 *)Heap_Alloc(0x2c);
        if (p != NULL) {
            SET_VT(p, data_ov015_022129c0);
            func_ov000_02163224(p);
        }
        self->unk_50 = p;
        func_ov000_021632f0(self->unk_50, 6, data_ov015_02212990, data_ov015_0221299d, 0);
        self->unk_3c->flags |= 4;
        self->unk_44->flags |= 2;
        self->unk_40->flags |= 2;
    }
    self->unk_20 = self->unk_3c->unk_34;
    func_ov000_02173648(self);
    if (++data_ov015_02213360[1] > 100) {
        data_ov015_02213360[1] = 100;
    }
}

}
