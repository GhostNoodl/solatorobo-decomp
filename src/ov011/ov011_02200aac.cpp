#include "ov011/ov011.h"

extern "C" {

s32 func_ov003_021d7e58(void *p);
void func_ov000_021984f4(void *p, s32 a, s32 b);
void func_ov000_0219864c(void *p, s32 a, s32 b);
s32 func_0206fef8(u32 id);
void *func_ov000_0218fe1c(void *p);
void func_ov000_0218ffdc(void *a, void *b, s32 c, s32 d);
void func_ov000_0219badc(void *a, void *b, s32 c);

s32 func_ov011_02200aac(void *p, s32 b) {
    return Ov011_FxMul(func_ov003_021d7e58(p), b);
}

void func_ov011_02200ad0(void *self) {
    if (FLD(void *, self, 0x44) != NULL) {
        func_ov000_021984f4(FLD(void *, self, 0x44), 0, 0);
    }
}

void func_ov011_02200af0(void *self) {
    if (FLD(void *, self, 0x48) != NULL) {
        func_ov000_0219864c(FLD(void *, self, 0x48), 0, 0);
    }
}

void func_ov011_02200b10(void *self) {
}

void func_ov011_02200b14(void *self) {
}

void func_ov011_02200b18(void *self) {
}

void func_ov011_02200b1c(void *self) {
}

void func_ov011_02200b20(void *self) {
}

void func_ov011_02200b24(void *self) {
}

void func_ov011_02200b28(void *self) {
}

void func_ov011_02200b2c(void *self) {
}

void func_ov011_02200b30(Ov011V *self) {
    self->v54();
}

struct Ov011EeBits {
    u16 b0 : 2;
    u16 b2 : 2;
    u16 b4 : 1;
    u16 b5 : 1;
    u16 b6 : 10;
};

void func_ov011_02200b44(Ov011V *self) {
    FLD(Ov011EeBits, self, 0xee).b5 = 1;
    self->v70();
}

void func_ov011_02200b64(Ov011V *self) {
    FLD(Ov011EeBits, self, 0xee).b2 = 2;
    self->v64();
}

struct Ov011Model {
    u8 b0 : 1;
    u8 b1 : 1;
    u8 b2 : 1;
    u8 b3 : 5;
    u8 unk_01;
    u16 unk_02;
    u16 unk_04;
    u8 unk_06[0x2];
    void *model;
};

BOOL func_ov011_02200b88(Ov011Model *self, void *a, void *b) {
    s32 r;
    void *p;
    self->b0 = 1;
    self->b1 = 0;
    self->b2 = 0;
    self->unk_02 = 0;
    self->unk_04 = 0;
    r = func_0206fef8((u32)b);
    p = func_0203dd9c(0xe8);
    if (p != NULL) {
        p = func_ov000_0218fe1c(p);
    }
    self->model = p;
    func_ov000_0218ffdc(p, a, 0, 1);
    FLD(u16, self->model, 0xb4) = 0xffff;
    func_ov000_0219badc(self->model, a, r);
    FLD(Ov011Flags, self->model, 0xc2).b0 = 1;
    return TRUE;
}

}


extern "C" {

extern const Ov011Vec data_ov011_02207450;
extern const Ov011Vec data_ov011_0220745c;
s32 func_02013068(const Ov011Vec *a, const Ov011Vec *b);
s32 func_02012ab8(s32 a, s32 b);

static inline void Ov011Tw_InitA(Ov011Tw *t, const Ov011Vec *from, const Ov011Vec *to) {
    s32 x;
    s32 y;
    s32 z;
    t->b0 = 1;
    t->b1 = 0;
    t->unk_04 = 0;
    x = from->x;
    t->v08.x = x;
    y = from->y;
    t->v08.y = y;
    z = from->z;
    t->v08.z = z;
    t->v14.x = to->x;
    t->v14.y = to->y;
    t->v14.z = to->z;
    t->v20.x = x;
    t->v20.y = y;
    t->v20.z = z;
    t->unk_02 = func_02012ab8(0x1000, func_02013068(to, from));
}

static inline void Ov011Tw_InitB(Ov011Tw *t, s32 from, s32 to, u16 speed, s32 mul) {
    t->b0 = 1;
    t->unk_02 = speed;
    t->v08.x = from;
    t->v08.y = from;
    t->v08.z = from;
    t->v14.x = to;
    t->v14.y = to;
    t->v14.z = to;
    t->unk_04 = Ov011_FxMul(func_02013068(&t->v14, &t->v08), mul);
}

void func_ov011_02200c30(Ov011Model2 *self) {
    Ov011Vec a;
    Ov011Vec b;
    s16 v2;
    s16 v4;
    if (!self->b0) {
        return;
    }
    if (self->b1) {
        OV011_BLKCPY(&a, &data_ov011_02207450);
        OV011_BLKCPY(&b, &data_ov011_0220745c);
        self->b1 = 0;
        self->b2 = 1;
        v2 = self->unk_02;
        v4 = self->unk_04;
        OV011_TWV(self->m0c)->v08();
        OV011_TWV(self->m3c)->v08();
        Ov011Tw_InitA(OV011_TW(self->m0c), &a, &b);
        Ov011Tw_InitB(OV011_TW(self->m3c), v2, v4, 0x333, 0x14);
    } else if (self->b2) {
        if (OV011_TWV(self->m0c)->v14() && OV011_TWV(self->m3c)->v14()) {
            self->b1 = 0;
            self->b2 = 0;
            OV011_TWV(self->m0c)->v08();
            OV011_TWV(self->m3c)->v08();
        } else {
            FLD(u8, self->model, 0xbe) = *(s32 *)OV011_TWV(self->m0c)->v10() >> 12;
            FLD(Ov011Vec, self->model, 0xa8) = *(Ov011Vec *)OV011_TWV(self->m3c)->v10();
        }
    }
    OV011_TWV(self->m0c)->v0c();
    OV011_TWV(self->m3c)->v0c();
}

}

struct Ov011CeBits {
    u8 b0 : 1;
    u8 b1 : 1;
    u8 b2 : 6;
};

#define OV011_CE(p) FLD(Ov011CeBits, p, 0xce)

extern "C" {

extern u8 data_ov011_022079f0[];
void func_ov000_02194074(void *p);
void func_ov000_0219429c(void *p);
void func_ov003_021d7ca8(void *p);
void func_ov003_021d7d8c(void *p);
void func_ov003_021d7ce0(void *p);

void *func_ov011_02200e84(void *self) {
    func_ov000_02194074(self);
    FLD(void *, self, 0) = data_ov011_022079f0;
    func_ov003_021d7ca8((u8 *)self + 0xd8);
    func_ov003_021d7ca8((u8 *)self + 0xe4);
    func_ov003_021d7ca8((u8 *)self + 0xf0);
    OV011_CE(self).b0 = 0;
    OV011_CE(self).b1 = 0;
    FLD(u16, self, 0xd0) = 0xffff;
    FLD(void *, self, 0xd4) = NULL;
    return self;
}

void *func_ov011_02200ee4(void *self) {
    FLD(void *, self, 0) = data_ov011_022079f0;
    func_ov003_021d7d8c((u8 *)self + 0xd8);
    func_ov003_021d7d8c((u8 *)self + 0xe4);
    func_ov003_021d7d8c((u8 *)self + 0xf0);
    OV011_CE(self).b0 = 0;
    OV011_CE(self).b1 = 0;
    FLD(u16, self, 0xd0) = 0xffff;
    FLD(void *, self, 0xd4) = NULL;
    func_ov003_021d7ce0((u8 *)self + 0xf0);
    func_ov003_021d7ce0((u8 *)self + 0xe4);
    func_ov003_021d7ce0((u8 *)self + 0xd8);
    func_ov000_0219429c(self);
    return self;
}

void *func_ov011_02200f60(void *self) {
    FLD(void *, self, 0) = data_ov011_022079f0;
    func_ov003_021d7d8c((u8 *)self + 0xd8);
    func_ov003_021d7d8c((u8 *)self + 0xe4);
    func_ov003_021d7d8c((u8 *)self + 0xf0);
    OV011_CE(self).b0 = 0;
    OV011_CE(self).b1 = 0;
    FLD(u16, self, 0xd0) = 0xffff;
    FLD(void *, self, 0xd4) = NULL;
    func_ov003_021d7ce0((u8 *)self + 0xf0);
    func_ov003_021d7ce0((u8 *)self + 0xe4);
    func_ov003_021d7ce0((u8 *)self + 0xd8);
    func_ov000_0219429c(self);
    func_0203de1c(self);
    return self;
}

extern u16 data_ov011_02207f00;
s32 func_ov011_02200aac(void *p, s32 b);
s32 func_ov000_02194c08(void *p);

#define OV011_ABS(x) ((x) < 0 ? -(x) : (x))

static inline void Ov011_ScaleV(Ov011Vec *v, s32 x, s32 y, s32 z, s32 s) {
    v->x = Ov011_FxMul(x, s);
    v->y = Ov011_FxMul(y, s);
    v->z = Ov011_FxMul(z, s);
}

s32 func_ov011_02200fe4(void *self) {
    s32 r;
    Ov011Vec saved;
    Ov011Vec v;
    void *m;
    u8 be;
    s32 a8;
    s32 ac;
    s32 b0;
    s32 old;
    OV011_BLKCPY(&saved, (u8 *)self + 0x70);
    m = FLD(void *, self, 0x38);
    be = FLD(u8, m, 0xbe);
    a8 = FLD(s32, m, 0xa8);
    ac = FLD(s32, m, 0xac);
    b0 = FLD(s32, m, 0xb0);
    if (OV011_CE(self).b1) {
        OV011_BLKCPY(&v, &saved);
        v.x += func_ov011_02200aac((u8 *)self + 0xe4, 0x266);
        v.y += func_ov011_02200aac((u8 *)self + 0xf0, 0x266);
        FLD(Ov011Vec, self, 0x70) = v;
    }
    if (OV011_CE(self).b0) {
        Ov011_ScaleV((Ov011Vec *)((u8 *)FLD(void *, self, 0x38) + 0xa8), a8, ac, b0, Ov011_FxMul(OV011_ABS(OV011_COS(data_ov011_02207f00)), 0xa00) + 0xd00);
    }
    old = FLD(s32, FLD(void *, self, 0x3c), 0x14);
    FLD(s32, FLD(void *, self, 0x3c), 0x14) = Ov011_FxMul(old, 0x2800);
    FLD(Ov011Vec, FLD(void *, self, 0x38), 0x78) = FLD(Ov011Vec, self, 0x70);
    r = func_ov000_02194c08(self);
    FLD(s32, FLD(void *, self, 0x3c), 0x14) = old;
    FLD(Ov011Vec, self, 0x70) = saved;
    m = FLD(void *, self, 0x38);
    FLD(s32, m, 0xa8) = a8;
    FLD(s32, m, 0xac) = ac;
    FLD(s32, m, 0xb0) = b0;
    FLD(u8, FLD(void *, self, 0x38), 0xbe) = be;
    return r;
}

void func_ov011_022011c0(void *self, u16 v) {
    FLD(u16, self, 0xd0) = v;
}

void func_ov011_022011c8(void *self, BOOL on) {
    if (on) {
        OV011_CE(self).b0 = 1;
        FLD(u16, FLD(void *, self, 0x4c), 0x1c) = FLD(u16, self, 0xd0);
    } else {
        OV011_CE(self).b0 = 0;
        FLD(u16, FLD(void *, self, 0x4c), 0x1c) = 0xffff;
    }
}

void func_ov011_022011fc(void *self, u8 on) {
    OV011_CE(self).b1 = on;
}

void func_ov011_02201214(void *self, void *p) {
    FLD(void *, self, 0xd4) = p;
}

void func_ov011_0220121c(void *self, BOOL on) {
    void *m = FLD(void *, self, 0x38);
    if (m == NULL) {
        return;
    }
    if (on) {
        FLD(Ov011Flags, m, 0xc2).b0 = 1;
    } else {
        FLD(Ov011Flags, m, 0xc2).b0 = 0;
    }
}

u32 func_ov011_02201244(void *self) {
    return OV011_CE(self).b0;
}

void *func_ov011_02201254(void *self) {
    return FLD(void *, self, 0xd4);
}

}

struct Ov011Fx {
    u8 b0 : 1;
    u8 b1 : 1;
    u8 b2 : 1;
    u8 b3 : 5;
    u8 unk_01;
    s16 unk_02;
    void *anim;
    void *model;
    Ov011Vec v0c;
    Ov011Vec v18;
    u8 mtx[0x24];
    u16 state;
    u16 timer;
    u8 unk_4c[0x10];
    u8 s5c[0xc];
    u8 s68[0xc];
    u8 s74[0xc];
};

struct Ov011CVec {
    s32 x;
    s32 y;
    s32 z;
    Ov011CVec(s32 a, s32 b, s32 c) {
        x = a;
        y = b;
        z = c;
    }
};

struct Ov011Bits94 {
    u8 b0 : 1;
    u8 b1 : 2;
    u8 b3 : 5;
};

extern "C" {

void func_ov000_02194758(void *p);
void func_ov003_021d7d24(void *p, s32 a, s32 b, s32 c, s32 d);
void func_ov000_021953b4(void *p);
void func_ov003_021d7dd0(void *p);
void func_ov000_02195848(void *p);
void *func_ov000_02199ba0(void *p);
void *func_ov000_0218d240(void *p);
void func_ov000_0219aae8(void *a, void *b, u16 c, u8 d, u16 mask, Ov011Vec *v, s32 e, s32 f, s32 g, s32 h, s32 i);
void func_ov000_02196c40(void *p);
void func_ov000_02196060(void *p);
void func_ov000_0219763c(void *p);
void func_ov000_02198328(void *p);
void func_ov011_02201688(Ov011Fx *p);

void func_ov011_0220125c(void *self) {
    void *p;
    func_ov000_02194758(self);
    func_ov003_021d7d24((u8 *)self + 0xd8, 0, 0, 1, 1);
    func_ov003_021d7d24((u8 *)self + 0xe4, 0, 0, 1, 1);
    func_ov003_021d7d24((u8 *)self + 0xf0, 0, 0, 1, 1);
    FLD(Ov011Flags, self, 0xcc).b4 = 0;
    FLD(Ov011Flags, FLD(void *, self, 0x48), 0x9a).b7 = 1;
    FLD(s32, FLD(void *, self, 0x48), 0x38) = 0x800;
    p = FLD(void *, self, 0x44);
    FLD(s32, p, 0x1c) = Ov011_FxMul(FLD(s32, p, 0x1c), 0x1a00);
}

void func_ov011_02201318(void *self) {
    func_ov000_021953b4(self);
    if (OV011_CE(self).b0) {
        FLD(u64, FLD(void *, self, 0x40), 4) |= 2;
        FLD(Ov011Flags, FLD(void *, self, 0x44), 0x22).b1 = 0;
        FLD(Ov011Bits94, self, 0x94).b1 = 1;
    } else if (OV011_CE(self).b1) {
        FLD(Ov011Bits94, self, 0x94).b1 = 1;
    } else {
        FLD(Ov011Bits94, self, 0x94).b1 = 0;
    }
    func_ov003_021d7dd0((u8 *)self + 0xd8);
    func_ov003_021d7dd0((u8 *)self + 0xe4);
    func_ov003_021d7dd0((u8 *)self + 0xf0);
}

void func_ov011_022013a8(void *self) {
    u16 mask;
    void *a;
    if (!OV011_CE(self).b0) {
        func_ov000_02195848(self);
    }
    mask = 0;
    a = func_ov000_02199ba0(FLD(void *, self, 0x4c));
    if (a != NULL) {
        void *b = func_ov000_0218d240(a);
        if (b != NULL) {
            mask |= (u16)(1 << (FLD(u16, b, 0xc) >> 12));
        }
        b = func_ov000_0218d240(self);
        if (b != NULL) {
            mask |= (u16)(1 << (FLD(u16, b, 0xc) >> 12));
        }
    }
    Ov011Vec v = {0, 0, 0};
    v.y = -FLD(s32, self, 0x68) / 2;
    if (mask == 0) {
        return;
    }
    func_ov000_0219aae8(self, self, FLD(u16, FLD(void *, self, 0x4c), 0x8), FLD(u16, FLD(void *, self, 0x4c), 0xa), mask, (Ov011Vec *)&v, 0,
                        FLD(s32, self, 0x64), FLD(s32, self, 0x68), 100, 0x1000);
}

void func_ov011_022014ac(void *self) {
    if (FLD(u16, FLD(void *, self, 0x40), 0) == 1) {
        FLD(s32, self, 0xa4) = 0;
        FLD(s32, self, 0xa8) = 0;
        FLD(s32, self, 0xa0) = 0;
        func_ov000_02196c40(self);
    } else {
        func_ov000_02196060(self);
    }
}

void func_ov011_022014e0(void *self) {
    if (FLD(u16, FLD(void *, self, 0x40), 0) == 0) {
        OV011_CE(self).b0 = 0;
        FLD(s32, self, 0x64) = 0xb33;
    }
    func_ov000_0219763c(self);
}

void *func_ov011_02201510(void *self) {
    func_ov000_02198328((u8 *)self + 0x48);
    func_ov003_021d7ca8((u8 *)self + 0x5c);
    func_ov003_021d7ca8((u8 *)self + 0x68);
    func_ov003_021d7ca8((u8 *)self + 0x74);
    FLD(Ov011Flags8, self, 0).b0 = 0;
    return self;
}

void *func_ov011_0220154c(void *self) {
    func_ov011_02201688((Ov011Fx *)self);
    func_ov003_021d7ce0((u8 *)self + 0x74);
    func_ov003_021d7ce0((u8 *)self + 0x68);
    func_ov003_021d7ce0((u8 *)self + 0x5c);
    return self;
}

}


extern "C" {

extern u8 data_ov011_02207418[];
extern const Ov011Vec data_ov011_02207420;
void *func_ov000_0218e9c4(void *p);
void func_ov000_0218ea20(void *p);
void func_ov000_0218fee4(void *p);
void func_02011340(void *m);
void func_ov000_02193e5c(void *p, s32 a);
void func_ov000_0218f110(void *p);
void func_020117a4(const Ov011Vec *v, const void *m, Ov011Vec *out);
void func_02012be8(const Ov011Vec *a, const Ov011Vec *b, Ov011Vec *out);
Ov011V *func_02065f88(s32 id, Ov011Vec *v);

BOOL func_ov011_02201578(Ov011Fx *self) {
    void *p;
    self->b0 = 1;
    self->b1 = 0;
    self->b2 = 0;
    self->unk_02 = 0;
    p = func_0203dd9c(0x138);
    if (p != NULL) {
        p = func_ov000_0218e9c4(p);
    }
    self->anim = p;
    p = func_0203dd9c(0xe8);
    if (p != NULL) {
        p = func_ov000_0218fe1c(p);
    }
    self->model = p;
    {
        Ov011Vec *src = &FLD(Ov011Vec, data_ov011_02207418, 0x20);
        s32 x;
        s32 y;
        s32 z;
        x = src->x;
        self->v0c.x = x;
        y = src->y;
        self->v0c.y = y;
        z = src->z;
        self->v0c.z = z;
        self->v18.x = x;
        self->v18.y = y;
        self->v18.z = z;
    }
    func_02011340(self->mtx);
    func_ov003_021da48c(&self->state, 0);
    func_ov000_02193e5c(self->anim, 0x4812);
    func_ov003_021d7d24(self->s5c, 0, 0, 1, 0);
    func_ov003_021d7d24(self->s68, 0, 0, 1, 0);
    func_ov003_021d7d24(self->s74, 0, 0, 1, 0);
    return TRUE;
}

static inline void Ov011_FreeAnim(Ov011Fx *self) {
    u32 saved = data_02097dd0->cur;
    data_02097dd0->cur = data_02097dd0->def;
    if (self->anim != NULL) {
        void *p = self->anim;
        if (p != NULL) {
            func_ov000_0218ea20(p);
            func_0203de1c(p);
        }
        self->anim = NULL;
    }
    data_02097dd0->cur = saved;
}

static inline void Ov011_FreeModel(Ov011Fx *self) {
    u32 saved = data_02097dd0->cur;
    data_02097dd0->cur = data_02097dd0->def;
    if (self->model != NULL) {
        void *p = self->model;
        if (p != NULL) {
            func_ov000_0218fee4(p);
            func_0203de1c(p);
        }
        self->model = NULL;
    }
    data_02097dd0->cur = saved;
}

void func_ov011_02201688(Ov011Fx *self) {
    if (!self->b0) {
        return;
    }
    Ov011_FreeAnim(self);
    Ov011_FreeModel(self);
    func_ov003_021d7d8c(self->s5c);
    func_ov003_021d7d8c(self->s68);
    func_ov003_021d7d8c(self->s74);
    self->b0 = 0;
}

void func_ov011_02201758(Ov011Fx *self) {
    Ov011Vec a;
    Ov011Vec b;
    if (!self->b0) {
        return;
    }
    if (!self->b1) {
        if (FLD(s16, self->anim, 0) < 0) {
            s32 r;
            self->b1 = 1;
            r = func_0206fef8(0x4812);
            FLD(u16, self->model, 0xb4) = 0xffff;
            func_ov000_0219badc(self->model, self->anim, r);
        } else {
            func_ov000_0218f110(self->anim);
        }
    } else if (self->b2) {
        switch (self->state) {
        case 0:
            self->unk_02 = 0x4cd;
            self->state = 1;
            OV011_BLKCPY(&a, &data_ov011_02207420);
            func_020117a4(&self->v0c, self->mtx, &b);
            func_02012be8(&b, &self->v18, &b);
            func_02065f88(0x648, &b)->v10(&a);
            break;
        case 1:
            self->timer++;
            if (self->timer > 30) {
                self->timer = 0;
                self->state = 2;
            }
            break;
        case 2:
            self->unk_02 += 0x1ae;
            self->timer++;
            if (self->timer > 10) {
                self->unk_02 = 0x159a;
                self->timer = 0;
                self->state = 3;
            }
            break;
        case 3:
            self->timer++;
            if (self->timer > 25) {
                self->timer = 0;
                self->b2 = 0;
            }
            break;
        }
        func_ov003_021da40c(&self->state);
    }
    func_ov003_021d7dd0(self->s5c);
    func_ov003_021d7dd0(self->s68);
    func_ov003_021d7dd0(self->s74);
}

}

extern "C" {

extern u8 data_ov011_02207468[];
void func_ov000_021903b4(void *p);
void func_02011488(void *m, s32 s, s32 c);
void func_02016dbc(const void *src, void *dst);

void func_ov011_0220192c(Ov011Fx *self) {
    Ov011Vec p;
    Ov011Vec q;
    Ov011Vec s;
    s32 a8;
    s32 ac;
    s32 b0;
    if (!self->b0) {
        return;
    }
    if (!self->b1) {
        return;
    }
    if (!self->b2) {
        return;
    }
    func_020117a4(&self->v0c, self->mtx, &p);
    func_02012be8(&p, &self->v18, &p);
    a8 = FLD(s32, self->model, 0xa8);
    ac = FLD(s32, self->model, 0xac);
    b0 = FLD(s32, self->model, 0xb0);
    OV011_BLKCPY(&q, &p);
    OV011_BLKCPY(&s, data_ov011_02207468);
    s.x = self->unk_02;
    s.y = self->unk_02;
    q.x += func_ov011_02200aac(self->s68, 0x266);
    q.y += func_ov011_02200aac(self->s74, 0x266);
    s.x += func_ov011_02200aac(self->s5c, 0x333);
    s.y = s.x;
    if (s.x < 0) {
        s.x = 0;
    }
    if (s.y < 0) {
        s.y = 0;
    }
    FLD(Ov011Vec, self->model, 0x78) = q;
    FLD(Ov011Vec, self->model, 0xa8) = s;
    func_ov000_021903b4(self->model);
    FLD(Ov011Vec, self->model, 0x78) = p;
    {
        void *m = self->model;
        FLD(s32, m, 0xa8) = a8;
        FLD(s32, m, 0xac) = ac;
        FLD(s32, m, 0xb0) = b0;
    }
}

void func_ov011_02201aac(Ov011Fx *self, const Ov011Vec *pos) {
    if (!self->b0) {
        return;
    }
    if (self->b2) {
        return;
    }
    self->b2 = 1;
    self->v0c = *pos;
    self->v18 = FLD(Ov011Vec, data_ov011_02207418, 0x20);
    func_02011340(self->mtx);
    func_ov003_021da48c(&self->state, 0);
}

void func_ov011_02201b28(Ov011Fx *self) {
    if (self->b0) {
        self->b2 = 0;
    }
}

BOOL func_ov011_02201b40(Ov011Fx *self) {
    BOOL r = FALSE;
    if (!self->b0) {
        return r;
    }
    if (!self->b2) {
        r = TRUE;
    }
    return r;
}

u32 func_ov011_02201b64(Ov011Fx *self) {
    u32 r = 0;
    if (self->b0) {
        r = self->b1;
    }
    return r;
}

void func_ov011_02201b80(Ov011Fx *self, const Ov011Vec *v) {
    if (!self->b0) {
        return;
    }
    self->v18 = *v;
}

void func_ov011_02201bac(Ov011Fx *self, u16 ang) {
    u8 m[0x24];
    if (self == NULL) {
        return;
    }
    func_02011488(m, OV011_SIN(ang), OV011_COS(ang));
    if (!self->b0) {
        return;
    }
    func_02016dbc(m, self->mtx);
}

}
