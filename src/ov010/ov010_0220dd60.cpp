#include "ov010/ov010.h"

extern "C" {

extern u8 data_ov010_022102e0[];
extern void *data_0214a420;
extern const Ov010Vec data_ov010_0220f57c;
extern u8 data_ov010_0220f534[];
extern void func_ov000_02194074(void *self);
extern void func_ov000_0219429c(void *self);
extern void func_ov000_02194758(void *self);
extern void MTX_Identity33_(void *m);
extern void func_02065860(void *a, s32 b);
extern void MTX_RotZ33_(void *m, s32 s, s32 c);
extern void MTX_RotY33_(void *m, s32 s, s32 c);
extern void MTX_Concat33(void *a, void *b, void *c);
extern void MI_Copy36B(void *m, void *b);
extern s32 func_ov000_021903b4(void *p);
extern void func_ov000_02190cb0(void *p, s32 a, s32 b, s32 c);
extern void func_ov000_021915a0(void *p);
extern void func_0203f364(void *p);
extern void func_ov000_02198360(void *a, s32 b, s32 c);

static inline void Ov010_0220dd60_Reset(void *self) {
    FLD(s32, self, 0xd0) = -1;
    FLD(s32, self, 0xd4) = 0;
    FLD(s32, self, 0xd8) = 0;
    MTX_Identity33_((u8 *)self + 0xdc);
}

void *func_ov010_0220dd60(void *self) {
    func_ov000_02194074(self);
    FLD(void *, self, 0) = data_ov010_022102e0;
    Ov010_0220dd60_Reset(self);
    return self;
}

static inline void Ov010_0220dd60_Dtor(void *self) {
    FLD(void *, self, 0) = data_ov010_022102e0;
    func_02065860(data_0214a420, FLD(s32, self, 0xd4));
    Ov010_0220dd60_Reset(self);
    func_ov000_0219429c(self);
}

void *func_ov010_0220dd9c(void *self) {
    Ov010_0220dd60_Dtor(self);
    return self;
}

void *func_ov010_0220ddf0(void *self) {
    Ov010_0220dd60_Dtor(self);
    func_0203de1c(self);
    return self;
}

void func_ov010_0220de4c(void *self, s32 a) {
    if (FLD(u8, self, 0x14) == 1) {
        FLD(s32, self, 0xd0) = a;
    }
}

s32 func_ov010_0220de5c(void *self) {
    u8 m[0x24];
    s32 r = 0;
    if (FLD(void *, self, 0x38) != NULL && FLD(s32, self, 0xd0) != -1) {
        switch (FLD(s32, self, 0xd0)) {
        case 0:
            MTX_RotY33_((u8 *)self + 0xdc, OV010_SIN(FLD(u16, self, 0x7e)), OV010_COS(FLD(u16, self, 0x7e)));
            break;
        case 1:
            MTX_RotZ33_(m, OV010_SIN(0x4000), OV010_COS(0x4000));
            MTX_RotY33_((u8 *)self + 0xdc, OV010_SIN(FLD(u16, self, 0x7e)), OV010_COS(FLD(u16, self, 0x7e)));
            MTX_Concat33(m, (u8 *)self + 0xdc, (u8 *)self + 0xdc);
            break;
        }
        FLD(Ov010Vec, FLD(u8 *, self, 0x38), 0x78) = FLD(Ov010Vec, self, 0x70);
        MI_Copy36B((u8 *)self + 0xdc, FLD(u8 *, self, 0x38) + 0x84);
        r = func_ov000_021903b4(FLD(void *, self, 0x38));
    }
    return r;
}

void func_ov010_0220df64(void *self) {
    func_ov000_02194758(self);
    Ov010Vec v = data_ov010_0220f57c;
    FLD(Ov010Vec, FLD(u8 *, self, 0x38), 0xa8) = v;
}

void func_ov010_0220dfac(void *self) {
    void *m;
    if (FLD(u16, FLD(void *, self, 0x40), 0) != 0) {
        return;
    }
    if (FLD(s32, self, 0xd0) == -1) {
        FLD(s32, self, 0xd0) = 0;
    }
    func_ov000_02190cb0(FLD(void *, self, 0x38), FLD(s32, data_ov010_0220f534, 0xc), 0x1000, 0);
    func_ov000_021915a0(FLD(void *, self, 0x38));
    m = FLD(void *, self, 0x48);
    if (m != NULL) {
        FLD(Ov010Flags, m, 0x9a).b0 = 0;
        FLD(Ov010Flags, m, 0x9a).b3 = 0;
        func_0203f364(m);
        m = FLD(void *, self, 0x48);
        FLD(Ov010Flags, m, 0x9a).b1 = 0;
        FLD(Ov010Flags, m, 0x9a).b4 = 0;
        m = FLD(void *, self, 0x48);
        FLD(Ov010Flags, m, 0x9a).b2 = 0;
        FLD(Ov010Flags, m, 0x9a).b5 = 0;
    }
    func_ov000_02198360(FLD(void *, self, 0x40), 4, 0);
}


struct Ov010Rot16 {
    u16 x;
    u16 y;
    u16 z;
};

extern u8 data_ov010_0220f594[];
extern void func_ov000_0218dbe0(void *self, s32 a);
extern s32 func_ov000_0219a2f4(Ov010Vec *p, s32 a, s32 b);
extern Ov010V *func_020657b0(void *a, s32 b);
extern Ov010V *func_02065f88(s32 a, Ov010Vec *b);
extern void func_02063a14(Ov010V *p);
extern BOOL func_ov000_0219aae8(void *a, void *b, u16 c, u8 d, u16 e, void *f, void *g, s32 h, s32 i, s32 j, s32 k);

void func_ov010_0220e06c(u8 *self) {
    Ov010Vec p;
    Ov010Rot16 ra;
    Ov010Rot16 rb;
    s32 scale;
    switch (FLD(u16, FLD(u8 *, self, 0x40), 0)) {
    case 0:
        FLD(s32, self, 0xa0) = 0;
        FLD(s32, self, 0xa4) = 0;
        FLD(s32, self, 0xa8) = 0;
        FLD(s32, self, 0x9c) = 0x733;
        FLD(u16, self, 0x98) = FLD(u16, self, 0x7e);
        FLD(u16, FLD(u8 *, self, 0x40), 0) = 1;
        break;
    case 1:
        if (FLD(s32, self, 0xd8) > 0x28000) {
            func_ov000_02198360(FLD(u8 *, self, 0x40), 0x15, 0);
        }
        break;
    }
    FLD(s32, self, 0x9c) = Ov010_FxMul(FLD(s32, self, 0x9c), 0x1029);
    FLD(s32, self, 0xd8) += FLD(s32, self, 0x9c);
    func_ov000_0218dbe0(self, 0);
    if (FLD(void *, self, 0x48) == NULL) {
        return;
    }
    scale = Ov010_FxMul(FLD(s32, FLD(u8 *, self, 0x38), 0xa8), FLD(s32, self, 0x64));
    switch (FLD(s32, self, 0xd0)) {
    case 0: {
        u16 a = FLD(u16, self, 0x7e) + 0x4000;
        ra.x = 0x4000;
        ra.y = a;
        ra.z = 0;
        rb.x = 0xbfff;
        rb.y = a;
        rb.z = 0;
        break;
    }
    case 1: {
        s32 h;
        Ov010V *o;
        BOOL near;
        rb.x = 0x7fff;
        ra.x = 0;
        ra.y = 0;
        ra.z = 0;
        rb.y = 0;
        rb.z = 0;
        *(Ov010Blk12 *)&p = FLD(Ov010Blk12, self, 0x70);
        h = func_ov000_0219a2f4(&p, 0x1000, -0x3000);
        near = FALSE;
        if (FLD(s32, self, 0x74) - p.y < scale) {
            near = TRUE;
        }
        o = func_020657b0(data_0214a420, FLD(s32, self, 0xd4));
        if (h != -0x1000 && near) {
            p.y += 0x800;
            if (o != NULL) {
                o->v18(&p);
                o->v34(0, (u16)(FLD(u16, self, 0x7e) + 0x7fff), 0);
            } else {
                Ov010V *n = func_02065f88(0x25e, &p);
                n->v34(0, (u16)(FLD(u16, self, 0x7e) + 0x7fff), 0);
                n->v14(0x1800, 0x1800, 0x1800);
                FLD(s32, self, 0xd4) = FLD(s32, n, 0x24);
            }
        } else if (o != NULL) {
            func_02063a14(o);
            FLD(s32, self, 0xd4) = 0;
        }
        break;
    }
    }
    func_ov000_0219aae8(self, self, FLD(u16, FLD(u8 *, self, 0x4c), 8), FLD(u16, FLD(u8 *, self, 0x4c), 0xa), 2, data_ov010_0220f594, &ra, 0x800, scale, 100, 0x1000);
    func_ov000_0219aae8(self, self, FLD(u16, FLD(u8 *, self, 0x4c), 8), FLD(u16, FLD(u8 *, self, 0x4c), 0xa), 2, data_ov010_0220f594, &rb, 0x800, scale, 100, 0x1000);
}


struct Ov010Trail {
    u8 b0 : 1;
    u8 b1 : 1;
    u8 b2 : 1;
    u8 rest : 5;
    u8 pad_01;
    u16 life;
    s32 key;
    Ov010Vec pos;
    u16 state;
    u16 timer;
};

extern void *data_02097e4c;
extern s32 FX_Div(s32 a, s32 b);
extern void func_02065804(void *a, s32 b);
extern Ov010V *func_02066774(const void *a, const void *b, s32 c, Ov010Vec *pos);
extern void func_02049f44(void *a, s32 b, Ov010Vec *c, s32 d);

static inline void Ov010_TrailApply(Ov010V *o, s16 s, u32 n) {
    o->v14(s, s, s);
    if (n > 0x1f) {
        n = 0x1f;
    }
    FLD(s32, o, 0x7c) = FX_Div((u8)n << 12, 0x1f000);
}

void func_ov010_0220e38c(Ov010Trail *self) {
    Ov010V *o;
    s32 s;
    s32 n;
    s16 sc;
    if (!self->b0) {
        return;
    }
    if (!self->b1) {
        return;
    }
    self->b2 = 0;
    switch (self->state) {
    case 0:
        o = func_02066774(FLD(void *, data_ov010_0220f534, 4), FLD(void *, data_ov010_0220f534, 8), 0, &self->pos);
        FLD(u8, o, 0x28) = 0;
        FLD(s32, o, 0xc8) = -1;
        self->key = FLD(s32, o, 0x24);
        o->v14(0x6000, 0x6000, 0x6000);
        FLD(s32, o, 0x7c) = FX_Div(0xa000, 0x1f000);
        func_02049f44(data_02097e4c, 0x72, &self->pos, 0);
        self->state = 1;
        break;
    case 1: {
        BOOL early = self->life < 0xc;
        o = func_020657b0(data_0214a420, self->key);
        if (self->timer > 6 || early) {
            self->state = 10;
        } else if (o == NULL) {
            self->state = 30;
        } else {
            s = FLD(s32, o, 0x40) - 0xaaa;
            if (s > 0x6000) {
                s = 0x6000;
            } else if (s < 0x2000) {
                s = 0x2000;
            }
            sc = s;
        n = (u8)(Ov010_FxMul(FLD(s32, o, 0x7c), 0x1f000) >> 12) + 6;
            if (n > 0x1e) {
                n = 0x1e;
            } else if (n < 1) {
                n = 1;
            }
            Ov010_TrailApply(o, sc, (u8)n);
        }
        break;
    }
    case 10:
        o = func_020657b0(data_0214a420, self->key);
        if (o == NULL) {
            self->state = 30;
            break;
        }
        o->v14(0x2000, 0x2000, 0x2000);
        FLD(s32, o, 0x7c) = FX_Div(0x1e000, 0x1f000);
        if (self->life - self->timer <= 6) {
            self->state = 20;
        }
        break;
    case 20:
        self->b2 = 1;
        o = func_020657b0(data_0214a420, self->key);
        if (o == NULL) {
            self->state = 30;
            break;
        }
        o->v14(0x2000, 0x2000, 0x2000);
        FLD(s32, o, 0x7c) = FX_Div(0x1e000, 0x1f000);
        self->state = 21;
        break;
    case 21:
        o = func_020657b0(data_0214a420, self->key);
        if (self->timer > self->life) {
            self->state = 30;
            break;
        }
        if (o == NULL) {
            break;
        }
        s = FLD(s32, o, 0x40) + 0xaaa;
        if (s > 0x6000) {
            s = 0x6000;
        } else if (s < 0x2000) {
            s = 0x2000;
        }
        sc = s;
        n = (u8)(Ov010_FxMul(FLD(s32, o, 0x7c), 0x1f000) >> 12) - 6;
        if (n > 0x1e) {
            n = 0x1e;
        } else if (n < 1) {
            n = 1;
        }
        Ov010_TrailApply(o, sc, (u8)n);
        break;
    case 30:
        func_02065804(data_0214a420, self->key);
        self->key = 0;
        self->b1 = 0;
        break;
    }
    self->timer++;
    o = func_020657b0(data_0214a420, self->key);
    if (o != NULL) {
        o->v1c(self->pos.x, self->pos.y + 0x200, self->pos.z);
    }
}

}
