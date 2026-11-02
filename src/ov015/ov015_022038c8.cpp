#include "ov015/ov015.h"

extern "C" {

extern void *data_02097e4c;
void *func_02049a48(void *a, int b, int c, int d, int e);
extern u8 *data_02097dc8;
extern u8 *data_ov000_021ccd44;
extern u8 data_ov000_021ccd34;
void *func_ov000_0218084c(void *a, s32 b, s32 c);
void *func_ov000_02154b58(void *a, s32 b);
void func_0203cc58(int a, int b, int c);
extern void *data_02149ef8;
void *func_0204c0e8(void *a, int id);
void func_ov000_0215bb14(void *a, void *b);
void func_ov015_02203ee0(Ov015Scene2a08 *self);
void func_ov015_02207c30(Ov015Ship *p);
void VEC_Normalize(void *src, void *dst);
void VEC_MultAdd(s32 scale, const Ov015Vec *dir, const Ov015Vec *base, Ov015Vec *out);
BOOL func_ov000_021633ac(void *p);
extern Ov015Vec data_ov015_02212614;
extern Ov015Vec data_ov015_02212620;
void func_ov000_02163594(void *p);
void func_ov000_0217357c(void *self);
void func_ov015_0220daf4(void *a, Ov015Vec *pos, s32 b, s32 c, s32 ang, s32 d);
extern u8 data_02092844[];
extern u8 data_02092800[];
void MTX_LookAt(void *a, void *b, void *c, void *d);
void MTX_PerspectiveW(s32 a, s32 b, s32 c, s32 d, s32 e, s32 f, void *g);
void func_ov015_02208070(Ov015Ship *p);
void *func_0206ec8c(u16 id);
extern u8 *data_0214a424;

static inline Ov015MenuItem *Ov015_ListNth2(Ov015Menu *o) {
    Ov015MenuItem *p = o->unk_98;
    s32 n;
    if (p == NULL) return NULL;
    n = o->unk_b1;
    while (n-- != 0) {
        p = p->unk_2c;
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
        switch (item->unk_06) {
        case 0:
            self->unk_94 = 1;
            func_ov000_0218084c(data_ov000_021ccd44, 0x20, self->unk_0c);
            self->unk_2c = 0;
            FLD(u32, self, 0x4) |= 6;
            self->unk_80->unk_0c |= 2;
            self->unk_84->unk_0c |= 2;
            self->unk_88->unk_0c |= 2;
            break;
        case 1:
            self->unk_94 = 3;
            func_ov000_0218084c(data_ov000_021ccd44, 0x22, self->unk_0c);
            self->unk_2c = 0;
            FLD(u32, self, 0x4) |= 6;
            self->unk_80->unk_0c |= 2;
            self->unk_84->unk_0c |= 2;
            self->unk_88->unk_0c |= 2;
            break;
        case 2:
            self->unk_94 = 5;
            data_ov000_021ccd34 = 1;
            FLD(Ov015Bits32a, data_ov000_021ccd44, 0x0).b0 = 1;
            self->unk_2c = 0;
            FLD(u32, self, 0x4) |= 6;
            self->unk_80->unk_0c |= 2;
            self->unk_84->unk_0c |= 2;
            self->unk_88->unk_0c |= 2;
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
    Ov015MenuItem *p = o->unk_98;
    s32 n;
    if (p == NULL) return NULL;
    n = o->unk_b1;
    while (n-- != 0) {
        p = p->unk_2c;
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
    k = Ov015_FxMul(0x1000 - self->unk_80->unk_38, 0x3000);
    v.x = -0x64a4;
    v.y = 0;
    v.z = 0x3ae1;
    VEC_Normalize(&v, &v);
    VEC_MultAdd(k, &v, &data_ov015_02212614, &out);
    self->unk_44.eye = out;
    VEC_MultAdd(k, &v, &data_ov015_02212620, &out);
    self->unk_44.at = out;
    if (self->unk_8c != NULL && !func_ov000_021633ac(self->unk_8c)) {
        u32 saved;
        Ov015Menu *o;
        Ov015Scene2a08 *t;
        void *s;
        HEAP_PUSH(saved);
        DELETE_V(self->unk_8c);
        HEAP_POP(saved);
        self->unk_80->unk_0c &= ~4;
        self->unk_84->unk_0c &= ~4;
        self->unk_88->unk_0c &= ~2;
        self->unk_84->unk_0c &= ~2;
        self->unk_84->unk_04 = 0;
        o = self->unk_80;
        {
            Ov015MenuItem *item = Ov015_ListNth3(o);
            u16 n = item->unk_06;
            void *d = data_02149ef8;
            s32 id;
            t = (Ov015Scene2a08 *)o->unk_08;
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
            s = func_0204c0e8(d, id);
        }
    skip:
        if (t->unk_84 != NULL) {
            func_ov000_0215bb14(t->unk_84, s);
            VCALL(t->unk_84)->v70();
        }
    }
    func_ov015_02207c30(self->unk_3c);
    ((Ov015V *)self->unk_80)->v1c();
    ((Ov015V *)self->unk_84)->v1c();
    ((Ov015V *)self->unk_88)->v1c();
}

void func_ov015_02203d60(void) {
}

static inline void Ov015_02203d64_Cam(Ov015Scene2a08 *self) {
    NNS_G3dGlb.a = self->unk_44.eye;
    NNS_G3dGlb.b = self->unk_44.up;
    NNS_G3dGlb.c = self->unk_44.at;
    MTX_LookAt(&self->unk_44.eye, &self->unk_44.up, &self->unk_44.at, data_02092844);
    NNS_G3dGlb.fc &= ~0xe8;
    if (self->unk_44.projDirty == 1) {
        MTX_PerspectiveW(self->unk_44.aspect, self->unk_44.nearClip, self->unk_44.farClip, self->unk_44.fovSin,
                      self->unk_44.fovCos, 0x1000, data_02092800);
        NNS_G3dGlb.fc &= ~0x50;
        self->unk_44.projDirty = 0;
    }
}
void func_ov015_02203d64(Ov015Scene2a08 *self) {
    Ov015Ship *o;
    if (self->unk_24 == NULL) return;
    func_ov000_0217357c(self);
    Ov015_02203d64_Cam(self);
    func_ov015_02208070(self->unk_3c);
    o = self->unk_3c;
    {
        Ov015Vec v = o->unk_d14;
        func_ov015_0220daf4(self->unk_40, &v, 0x2000, 0x2000, o->unk_d22, o->unk_d20);
    }
    VCALL(self->unk_80)->v20();
    VCALL(self->unk_84)->v20();
    VCALL(self->unk_88)->v20();
    if (self->unk_8c != NULL) func_ov000_02163594(self->unk_8c);
}

void func_ov015_02203ee0(Ov015Scene2a08 *self) {
    Ov015Ship *o = self->unk_3c;
    u16 pad;
    if (o == NULL) {
        return;
    }
    {
    u16 a = (self->unk_a8 % 1200) * 0xffff / 1200;
    o->unk_d20 = 0;
    o->unk_d22 = a;
    o->unk_d24 = 0;
    }
    pad = FLD(u16, data_02097dc8, 0x10);
    if (pad & 0x20) {
        self->unk_3c->unk_d3a = 2;
        self->unk_ac = 0x3c;
    } else if (pad & 0x10) {
        self->unk_3c->unk_d3a = 1;
        self->unk_ac = 0x3c;
    } else if (pad & 0x800) {
        self->unk_3c->unk_d3a = 3;
        self->unk_ac = 0x3c;
    }
    if (self->unk_ac == 0) {
        self->unk_3c->unk_d3a = 0;
        self->unk_ac = 0x3c;
    }
    if (++self->unk_a8 > 60000) {
        self->unk_a8 = 0;
    }
    if (--self->unk_ac < 0) {
        self->unk_ac = 0;
    }
}

BOOL func_ov015_02203fec(Ov015Menu *self, Ov015MenuItem *ev) {
    Ov015Scene2c08 *o;
    u16 id;
    id = ev->unk_06;
    o = (Ov015Scene2c08 *)self->unk_08;
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
    Ov015Scene2c08 *o = (Ov015Scene2c08 *)self->unk_08;
    if (item != NULL) {
        if (item->unk_10 == -1) {
            func_02049a48(data_02097e4c, 0x20, -1, -1, -1);
        } else if (item->unk_0c > FLD(u32, data_0214a424, 0x20)) {
            void *s = func_0204c0e8(data_02149ef8, 0x9b);
            if (o->unk_40 != NULL) {
                func_ov000_0215bb14(o->unk_40, s);
                VCALL(o->unk_40)->v70();
            }
            func_02049a48(data_02097e4c, 0x20, -1, -1, -1);
        } else {
            func_02049a48(data_02097e4c, 0x1e, -1, -1, -1);
            o->unk_6a = 1;
            o->unk_68 = item->unk_06;
            r = FALSE;
        }
    }
    return r;
}

void func_ov015_02204110(Ov015Scene2c08 *self) {
    u32 saved;
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
    o->unk_64 = x;
    o->unk_66 = y;
    o->unk_68 = z;
}

static inline void Ov015_SetXYZ32(Ov015Ui *o, s32 x, s32 y, s32 z) {
    o->unk_58 = x;
    o->unk_5c = y;
    o->unk_60 = z;
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
    p = (u8 *)func_0203dd9c(0xe0);
    if (p != NULL) {
        SET_VT(p, data_ov000_021cac60);
        VCALL(p)->v28();
        SET_VT(p, data_ov000_021caec8);
        VCALL(p)->v28();
        SET_VT(p, data_ov000_021cb4a8);
        VCALL(p)->v28();
    }
    self->unk_3c = (Ov015Menu *)p;
    VCALL(self->unk_3c)->v10(func_0204c0e8(res, 0xc6));
    VCALL(self->unk_3c)->v14(func_0204c0e8(res, 0xc7));
    self->unk_3c->unk_20 = 5;
    self->unk_3c->unk_24 = 0xf8;
    Ov015_SetXYZ16(self->unk_3c, 0, 0x2c, -0xccd);
    Ov015_SetXYZ32(self->unk_3c, -0x100, 0, -0xccd);
    self->unk_3c->unk_2c = 1;
    self->unk_3c->unk_0c |= 0x400000;
    self->unk_3c->unk_c0 = 0x78;
    self->unk_3c->unk_0c &= ~0x800000;
    self->unk_3c->unk_c1 = 5;
    switch (self->unk_0c) {
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
    func_ov000_02157c90(self->unk_3c, func_0204c0e8(res, 0xa4));
    func_ov000_02157d2c(self->unk_3c, func_0204c0e8(res, 0x3e));
    {
        Ov015Menu *o = self->unk_3c;
        VCALL(o)->va8(func_ov000_02154b58(o, 0));
    }
    self->unk_3c->unk_84 = (void *)func_ov015_02204030;
    self->unk_3c->unk_88 = (void *)func_ov015_02203fec;
    self->unk_3c->unk_08 = (u8 *)self;
    VCALL(self->unk_3c)->v08();
    p = (u8 *)func_0203dd9c(0x8c);
    if (p != NULL) {
        SET_VT(p, data_ov000_021cac60);
        VCALL(p)->v28();
        SET_VT(p, data_ov000_021cadcc);
        VCALL(p)->v28();
    }
    self->unk_40 = (Ov015UiLabel *)p;
    self->unk_40->unk_24 = 0xf8;
    self->unk_40->unk_20 = 2;
    Ov015_SetXYZ16(self->unk_40, 4, 0x95, -0xccd);
    Ov015_SetXYZ32(self->unk_40, -0x100, 0, -0xccd);
    self->unk_40->unk_2c = 1;
    {
        void *s = func_0206ec8c(self->unk_3c->unk_94->unk_06);
        if (self->unk_40 != NULL) {
            func_ov000_0215bb14(self->unk_40, s);
            VCALL(self->unk_40)->v70();
        }
    }
    VCALL(self->unk_40)->v08();
    p = (u8 *)func_0203dd9c(0xe0);
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
    Ov015_SetXYZ16(self->unk_44, 0x91, 0x12, -0x333);
    Ov015_SetXYZ32(self->unk_44, 0x100, 0, -0x333);
    self->unk_44->unk_0c |= 0x20000000;
    VCALL(self->unk_44)->vf4(1, func_0204c0e8(res, 0x32));
    VCALL(self->unk_44)->vf4(2, func_0204c0e8(res, 0x33));
    VCALL(self->unk_44)->v08();
    p = (u8 *)func_0203dd9c(0x98);
    if (p != NULL) {
        SET_VT(p, data_ov000_021cac60);
        VCALL(p)->v28();
        SET_VT(p, data_ov000_021cae48);
        VCALL(p)->v28();
    }
    self->unk_48 = (Ov015UiNum *)p;
    Ov015_SetXYZ16(self->unk_48, 0x86, 0x87, -0xccd);
    Ov015_SetXYZ32(self->unk_48, 0x100, 0, -0xccd);
    self->unk_48->unk_2c = 1;
    func_ov000_0215d980(self->unk_48, FLD(void *, data_0214a424, 0x20), 0);
    VCALL(self->unk_48)->v08();
    if (self->unk_0c == 1 && data_ov015_02213360[1] == 0) {
        p = (u8 *)func_0203dd9c(0x2c);
        if (p != NULL) {
            SET_VT(p, data_ov015_022129c0);
            func_ov000_02163224(p);
        }
        self->unk_50 = p;
        func_ov000_021632f0(self->unk_50, 6, data_ov015_02212990, data_ov015_0221299d, 0);
        self->unk_3c->unk_0c |= 4;
        self->unk_44->unk_0c |= 2;
        self->unk_40->unk_0c |= 2;
    }
    self->unk_20 = self->unk_3c->unk_34;
    func_ov000_02173648(self);
    if (++data_ov015_02213360[1] > 100) {
        data_ov015_02213360[1] = 100;
    }
}

}
