#include "ov015/ov015.h"

extern "C" {

extern u8 *data_ov015_02213364;
void NNS_G3dGetCurrentMtx(void *p, s32 a);
void func_ov015_02208424(u8 *self);
void MIi_CpuClearFast(u32 val, void *dst, u32 size);
extern void *data_0208cb74;
extern void *data_0208cca0;
void func_02041218(void *p);
void func_02041440(void *p, void *name, int c);
void func_0201e520(void *p, void *name);
void *func_02035f30(void *a, void *b, int c);
void *func_02034d88(void *a, void *b);
void func_020417e0(void *a, void *b);
void func_02041d9c(void *a, int b, int c);
void func_02041c34(void *a, int b, void *cb, void *arg);
Ov015Glyph *func_ov015_0220848c(void *self, u16 *ctx, Ov015Glyph *e, u16 *count);
void func_ov015_02208bac(char *out, s32 *outId, u32 n, const char *src);
void func_ov015_02208a28(u8 *self, void *p);
s32 FX_Div(s32 a, s32 b);
void *NNS_G2dGetAnimSequenceByIdx(void *a, int b);
void *NNS_G2dGetCellDataByIdx(void *a, u16 b);
void func_02042628(void *model, void *a, void *part, int b);
s32 func_02041b10(void *m, void *anim);
s32 func_02041bb0(void *m, void *anim);
void func_02041c20(void *m, s32 a, s32 b);
extern u8 *data_02097ce0;
extern u8 *data_02097d48;
extern u8 data_0208ba70[];
void func_0204c7d0(void *p);
s32 func_0204c4fc(s32 a, s32 b, void *c, void *d, void *e, BOOL f);
s32 func_02043d48(void *p);
const char *func_0206ffa0(u16 id);
s32 func_0201e708(const void *s);
s32 func_0201e950(const void *s, const void *t, s32 n);
s8 **func_0203a4c0(void *p);
void func_0204cc18(void *p, const char **s);
void func_0201e5a0(void *dst, const void *src, u32 size);
int func_02054f10(void *a, int b);
s32 func_0203e63c(void *p);
extern u8 data_ov015_02212d3c[];
extern u8 data_ov000_021cac60[];
s32 FX_Inv(s32 a);
void MTX_Scale33_(void *m, s32 x, s32 y, s32 z);
void MTX_Concat33(void *a, void *b, void *out);
void func_02016fa0(const void *src, void *dst, s32 n);
void func_ov015_02208f7c(u8 *self);
extern u8 data_ov015_022128fc[];
extern u8 data_ov015_02212e84[];
extern u8 data_ov015_022129d0[];
void func_ov000_0218e9c4(void *a);
void func_ov000_0218fe1c(void *a);
void func_ov000_0219196c(void *a);
void func_0203f260(void *a);
void MTX_Identity33_(void *a);
extern u8 data_ov015_02212eb0[];

void func_ov015_02208424(u8 *self) {
    u8 *t = data_ov015_02213364 + 0xcd4;
    s32 id = (FLD(u32, self, 0x8) & 0x10) ? FLD(u8, self, 0xae) : -1;
    if (id != t[0x30]) {
        return;
    }
    NNS_G3dGetCurrentMtx(t, 0);
    FLD(void *, self, 0x24) = NULL;
    FLD(u8, self, 0x92) = 0;
}

void func_ov015_02208474(u8 *self) {
    FLD(void *, self, 0x24) = (void *)func_ov015_02208424;
    FLD(u8, self, 0x92) = 3;
}

Ov015Glyph *func_ov015_0220848c(void *self, u16 *ctx, Ov015Glyph *e, u16 *count) {
    u16 n = *count;
    if (ctx[0] == 0) {
        u32 x0 = e[0].x;
        u32 c0 = e[0].code;
        u32 p0 = e[0].pal;
        u32 v = FLD(u32, ctx, 0x8) & 0xff;
        s32 i;
        for (i = 0; i < n; i++) {
            e[i].x = e[i].x - (x0 + 0x80);
            e[i].code = e[i].code - (c0 + 0x60);
            e[i].pal = v + p0;
        }
    }
    *count = n;
    return e;
}

void func_ov015_02208544(u8 *self) {
    FLD(u32, self, 0xc) |= 0x10000;
    FLD(s32, self, 0x84) = 0;
    MIi_CpuClearFast(0, self + 0x88, 0x20);
    FLD(s32, self, 0xa8) = -1;
    FLD(s32, self, 0xb0) = 0;
}

static inline void Ov015Label_Ctor(u8 *l, void *name, void *dict) {
    func_02041218(l + 0x88);
    func_02041440(l, dict, 0);
    func_0201e520(l + 0x2c, name);
}

void func_ov015_02208584(u8 *self) {
    u8 *l = (u8 *)func_0203dd9c(0x160);
    void *r;
    if (l != NULL) {
        Ov015Label_Ctor(l, data_0208cca0, data_0208cb74);
    }
    FLD(u8 *, self, 0x10) = l;
    r = func_02034d88(func_02035f30(l + 0x2c, l + 0x4c, 2), FLD(u8 *, self, 0x10) + 0x4c);
    func_020417e0(FLD(void *, self, 0x10), r);
    FLD(u32, FLD(u8 *, self, 0x10), 0x6c) |= 2;
    func_02041c34(FLD(void *, self, 0x10), 0, (void *)func_ov015_0220848c, NULL);
    if (FLD(s32, self, 0x14) != 0) {
        func_02041d9c(FLD(void *, self, 0x10), 0, 7);
    }
    func_02041d9c(FLD(void *, self, 0x10), 0, 0);
    FLD(u32, self, 0xc) &= ~2;
}

void func_ov015_0220866c(u8 *self, void *msg) {
    if (msg == NULL) {
        return;
    }
    func_ov015_02208bac((char *)(self + 0x88), (s32 *)(self + 0xa8), 0x20, (const char *)msg);
    if (FLD(s8, self, 0x88) == 0 && FLD(s32, self, 0xa8) < 0) {
        return;
    }
    if ((FLD(u32, self, 0xc) & 0x10000) && FLD(void *, self, 0x84) != NULL) {
        FLD(s32, self, 0xb0) = 0xf;
        return;
    }
    func_ov015_02208a28(self, self + 0x88);
}

struct Ov015Bits0c {
    u32 b0 : 1;
    u32 b1 : 1;
    u32 rest : 30;
};

void func_ov015_022086d0(u8 *self) {
    if (FLD(s32, self, 0x4) != 2) {
        return;
    }
    if (FLD(void *, self, 0x84) != NULL) {
        VCALL(FLD(void *, self, 0x84))->v8c();
    }
    if (FLD(u32, self, 0xc) & 0x10000) {
        if (--FLD(s32, self, 0xb0) < 0) {
            FLD(s32, self, 0xb0) = 0;
        }
        if (FLD(s32, self, 0xb0) == 7) {
            func_ov015_02208a28(self, self + 0x88);
        }
    }
    if (((Ov015Bits0c *)(self + 0xc))->b1 == 1) {
        FLD(s32, self, 0x4) = 1;
    }
}

void func_ov015_02208750(void *self, s32 a, s32 b, s32 c) {
    VCALL(self)->v60(a, b, c);
    VCALL(self)->v70(a, b, c);
}

static inline u8 *Ov015_MdlPart0(u8 *m) {
    if (0 >= FLD(s32, m, 0x80)) {
        return NULL;
    }
    return FLD(u8 *, m, 0x78);
}
static inline void *Ov015_MdlAnim0(u8 *m) {
    u8 *res = FLD(u8 *, m, 0x28);
    u8 *part = Ov015_MdlPart0(m);
    if (part != NULL && FLD(u8 *, part, 0x4) != NULL) {
        return FLD(void *, FLD(u8 *, part, 0x4), 0x30);
    }
    return NNS_G2dGetCellDataByIdx(FLD(void *, res, 0x4), **FLD(u16 **, NNS_G2dGetAnimSequenceByIdx(FLD(void *, res, 0xc), 0), 0xc));
}
static inline void Ov015_MdlPlay0(u8 *m) {
    u8 *res = FLD(u8 *, m, 0x28);
    u8 *part;
    void *anim;
    if (res == NULL) {
        return;
    }
    part = Ov015_MdlPart0(m);
    if (part != NULL && FLD(u8 *, part, 0x4) != NULL) {
        anim = FLD(void *, FLD(u8 *, part, 0x4), 0x30);
    } else {
        anim = NNS_G2dGetCellDataByIdx(FLD(void *, res, 0x4), **FLD(u16 **, NNS_G2dGetAnimSequenceByIdx(FLD(void *, res, 0xc), 0), 0xc));
    }
    func_02042628(m, anim, part, 0);
}
void func_ov015_02208790(u8 *self, s32 b, u8 *p) {
    s32 x;
    s32 w;
    s32 h;
    Ov015V *o;
    if (FLD(u8 *, self, 0x10) == NULL || FLD(u8 *, self, 0x84) == NULL) {
        return;
    }
    x = Ov015_FxMul(0x1000 - b, FLD(s32, self, 0x58) << 12);
    if (FLD(u32, self, 0xc) & 0x10000) {
        s32 t = FX_Div(FLD(s32, self, 0xb0) << 12, 0xf000);
        t = (s32)(((s64)t * 0xffff000 + 0x800) >> 12);
        x += Ov015_FxMul(FX_SinCosTable_[(t >> 16) * 2 + 1], 0x80000) - 0x80000;
    }
    { u8 *m = FLD(u8 *, self, 0x10); w = func_02041b10(m, Ov015_MdlAnim0(m)); }
    { u8 *m = FLD(u8 *, self, 0x10); h = func_02041bb0(m, Ov015_MdlAnim0(m)); }
    { s32 py = FLD(s32, p, 0x4) >> 12; u8 *m = FLD(u8 *, self, 0x10);
    FLD(s32, m, 0xfc) = (x - 0x20000) & -0x1000;
    FLD(s32, m, 0x100) = py << 12; }
    FLD(s32, FLD(u8 *, self, 0x10), 0x150) = FLD(s16, self, 0x68);
    func_02041c20(FLD(u8 *, self, 0x10), 0, FLD(s32, self, 0xac));
    Ov015_MdlPlay0(FLD(u8 *, self, 0x10));
    o = FLD(Ov015V *, self, 0x84);
    {
        s32 ax = (((w - 0x20) - FLD(s32, o, 0x44)) >> 1) + (x >> 12);
        s32 ay = ((h - FLD(s32, o, 0x48)) >> 1) + (FLD(s32, p, 0x4) >> 12) - 1;
        if (o == NULL) return;
        o->v20(ax, ay);
    }
    FLD(s32, FLD(u8 *, self, 0x84), 0x70) = FLD(s16, self, 0x68) + 0x20;
    FLD(Ov015V *, self, 0x84)->v90();
}

struct Ov015Bits08a28 {
    u32 b0 : 2;
    u32 b2 : 1;
    u32 b3 : 3;
    u32 b6 : 1;
    u32 b7 : 6;
    u32 f13 : 8;
    u32 b21 : 3;
    u32 b24 : 1;
    u32 rest : 7;
};
void func_ov015_02208a28(u8 *self, void *name) {
    u32 saved;
    u8 *o;
    u8 *p;
    const char *id;
    if (name == NULL) return;
    HEAP_PUSH(saved);
    DELETE_V(FLD(void *, self, 0x84));
    HEAP_POP(saved);
    o = (u8 *)func_0203dd9c(0xb8);
    if (o != NULL) {
        SET_VT(o, data_0208ba70);
        func_0204c7d0(o);
    }
    FLD(u8 *, self, 0x84) = o;
    FLD(s32, FLD(u8 *, self, 0x84), 0x28) = 4;
    FLD(s32, FLD(u8 *, self, 0x84), 0x2c) = 0;
    p = FLD(u8 *, self, 0x84);
    FLD(void *, p, 0x24) = name;
    FLD(s32, p, 0x4c) = func_0204c4fc(FLD(s32, p, 0x28), FLD(s32, p, 0x38), FLD(void *, p, 0x24), p + 0x44, p + 0x48,
                                      FLD(s8, p, 0x37) != 0);
    FLD(s32, data_02097ce0, 0x4) = FLD(s32, p, 0x28);
    FLD(Ov015Bits08a28, FLD(u8 *, self, 0x84), 0x4).f13 = func_02043d48(data_02097d48 + 0x8b0);
    FLD(Ov015Bits08a28, FLD(u8 *, self, 0x84), 0x4).b24 = 1;
    FLD(Ov015Bits08a28, FLD(u8 *, self, 0x84), 0x4).b6 = 1;
    FLD(Ov015Bits08a28, FLD(u8 *, self, 0x84), 0x4).b2 = 1;
    id = func_0206ffa0(0x1000);
    if (func_0201e950(name, id, func_0201e708(name)) == 0) {
        FLD(s32, self, 0xac) = 0;
    } else {
        FLD(s32, self, 0xac) = 1;
    }
}

struct Ov015TagRes {
    s32 type;
    s32 value;
};
struct Ov015TagParser {
    void *vt;
    u8 pad[0x7c];
    Ov015TagRes res;
    u8 pad2[0x10];
    char str[0x20];
};
typedef s32 (*Ov015CharFn)(const char **s);
void func_ov015_02208bac(char *out, s32 *outId, u32 n, const char *src) {
    Ov015CharFn fn = *(Ov015CharFn *)((u8 *)func_0203a4c0(data_02097ce0) + 4);
    const char *s;
    Ov015TagParser p;
    s = src;
    SET_VT(&p, data_0208ba70);
    func_0204c7d0(&p);
    out[0] = 0;
    *outId = -1;
    while (*s != 0) {
        if (fn(&s) == '<') {
            func_0204cc18(&p, &s);
            Ov015TagRes *r = &p.res;
            if (r->type == 0) {
                *outId = r->value;
                func_0201e5a0(out, func_0206ffa0(*outId), n);
            } else if (r->type == 1) {
                func_0201e5a0(out, p.str, n);
            }
        }
    }
    SET_VT(&p, data_0208ba70);
    VCALL(&p)->v08();
}

s32 func_ov015_02208cb0(void) {
    return 1;
}

static inline BOOL Ov015Res_Ready(u8 *t) {
    if (FLD(void *, t, 0x6c) == NULL) {
        return TRUE;
    }
    if (func_0203e63c(FLD(void *, t, 0x6c)) != 0) {
        FLD(void *, t, 0x6c) = NULL;
    } else {
        return !((Ov015Task *)t)->flag6;
    }
    return TRUE;
}

BOOL func_ov015_02208cb8(u8 *self) {
    BOOL r = TRUE;
    u8 *t;
    if (FLD(void *, self, 0x10) != NULL && func_02054f10(FLD(void *, self, 0x10), 0xffff) == 0) {
        r = FALSE;
    }
    t = FLD(u8 *, self, 0x14);
    if (t != NULL && !Ov015Res_Ready(t)) {
        r = FALSE;
    }
    t = FLD(u8 *, self, 0x18);
    if (t != NULL && !Ov015Res_Ready(t)) {
        r = FALSE;
    }
    return r;
}

typedef void (*Ov015Cb3)(void *arg, void *self, s32 c);

void func_ov015_02208d8c(u8 *self, void *arg, s32 c) {
    Ov015Cb3 cb = FLD(Ov015Cb3, self, 0x80);
    if (cb == NULL) {
        return;
    }
    cb(arg, self, c);
}

s32 func_ov015_02208db0(u8 *self) {
    s32 a = VCALL(self)->v40() * FLD(s32, self, 0x20);
    s32 b = VCALL(self)->v34();
    s32 c = VCALL(self)->v38();
    s32 d = a + b;
    return d + c;
}

s32 func_ov015_02208dfc(u8 *self) {
    s32 a;
    FLD(s32, data_02097ce0, 0x4) = FLD(s32, self, 0x1c);
    a = (*func_0203a4c0(data_02097ce0))[1];
    return a + VCALL(self)->v3c();
}

s32 func_ov015_02208e40(void) {
    return 0;
}

s32 func_ov015_02208e48(void) {
    return 0;
}

s32 func_ov015_02208e50(void) {
    return 0;
}

s32 func_ov015_02208e58(void) {
    return 0;
}

s32 func_ov015_02208e60(void *self, s32 a, s32 b, s32 c) {
    return VCALL(self)->v60(a, b, c);
}

void *func_ov015_02208e74(u8 *self) {
    u32 saved;
    SET_VT(self, data_ov015_02212d3c);
    HEAP_PUSH(saved);
    DELETE_V(FLD(Ov015V *, self, 0x84));
    HEAP_POP(saved);
    SET_VT(self, data_ov000_021cac60);
    VCALL(self)->v2c();
    func_0203de1c(self);
    return self;
}

void *func_ov015_02208efc(u8 *self) {
    u32 saved;
    SET_VT(self, data_ov015_02212d3c);
    HEAP_PUSH(saved);
    DELETE_V(FLD(Ov015V *, self, 0x84));
    HEAP_POP(saved);
    SET_VT(self, data_ov000_021cac60);
    VCALL(self)->v2c();
    return self;
}

void func_ov015_02208f7c(u8 *self) {
    u8 m[0x24];
    s32 id = (FLD(u32, self, 0x8) & 0x10) ? FLD(u8, self, 0xae) : -1;
    u8 *t = FLD(u8 *, FLD(u8 *, self, 0x4), 0x2c);
    if (id != FLD(s32, t, 0x30)) {
        return;
    }
    NNS_G3dGetCurrentMtx(t, 0);
    MTX_Scale33_(m, FX_Inv(0xa000), FX_Inv(0xa000), FX_Inv(0xa000));
    MTX_Concat33(t, m, t);
}

void func_ov015_0220900c(void) {
}

void *func_ov015_02209010(void *self) {
    func_0203de1c(self);
    return self;
}

#define OV015_MUL64(a, b) ((s32)(((s64)(a) * (b) + 0x800) >> 12))

void func_ov015_02209024(u8 *self, u16 a, const void *src) {
    s32 v;
    FLD(u16, self, 0x4) = a;
    func_02016fa0(src, self + 0x6, 0x14);
    v = FLD(u16, self, 0x10) << 12;
    s32 lim;
    if (FLD(s32, self, 0x28) < 0xe10000) {
        lim = Ov015_FxMul(v, 0x1000);
    } else if (FLD(s32, self, 0x28) < 0x1c20000) {
        lim = Ov015_FxMul(v, 0xccd);
    } else {
        lim = Ov015_FxMul(v, 0xb33);
    }
    FLD(s32, self, 0x1c) = lim;

}

s32 func_ov015_022090bc(u8 *self) {
    return (s32)(((s64)(FLD(s16, self, 0xa) << 4) * 0x2000 + 0x800) >> 12) + 0x19a;
}

s32 func_ov015_022090f0(u8 *self) {
    return FLD(s16, self, 0x16) << 4;
}

void func_ov015_022090fc(u8 *self) {
    FLD(void *, self, 0x24) = (void *)func_ov015_02208f7c;
    FLD(u8, self, 0x92) = 3;
}

void *func_ov015_02209114(u8 *self) {
    SET_VT(self, data_ov015_022128fc);
    SET_VT(self + 0xc0, data_ov015_02212e84);
    FLD(u16, self, 0xc4) = 0xffff;
    MIi_CpuClearFast(0, self + 0xc6, 0x14);
    FLD(s32, self, 0xdc) = 0;
    FLD(s32, self, 0xe0) = 0;
    FLD(s32, self, 0xe4) = 0;
    FLD(s32, self, 0xe8) = 0;
    func_ov000_0218e9c4(self + 0x10c);
    func_ov000_0218fe1c(self + 0x244);
    func_ov000_0218e9c4(self + 0x32c);
    func_ov000_0218fe1c(self + 0x464);
    func_ov000_0219196c(self + 0x54c);
    SET_VT(self + 0x54c, data_ov015_022129d0);
    func_0203f260(self + 0x568);
    FLD(u16, self, 0x4) = 0xffff;
    FLD(s32, self, 0x8) = 0;
    MIi_CpuClearFast(0, self + 0xc, 0x34);
    FLD(s32, self, 0x40) = 0;
    FLD(s32, self, 0x44) = 0;
    FLD(s32, self, 0x48) = 0;
    MTX_Identity33_(self + 0x4c);
    FLD(s32, self, 0x80) = 0;
    FLD(s32, self, 0x84) = 0;
    FLD(s32, self, 0x88) = 0;
    FLD(u8, self, 0x90) = 0;
    FLD(s32, self, 0x94) = 0;
    FLD(s32, self, 0x98) = 0;
    FLD(s32, self, 0xa0) = 0;
    FLD(s32, self, 0xa4) = 0;
    FLD(s32, self, 0xa8) = 0;
    FLD(s32, self, 0xbc) = 0;
    FLD(s32, self, 0xf0) = 0;
    FLD(s32, self, 0xf8) = 0;
    FLD(s32, self, 0x100) = 0;
    FLD(s32, self, 0x108) = 0;
    FLD(s32, self, 0x70) = 0x1000;
    FLD(s32, self, 0x74) = 0x1000;
    FLD(s32, self, 0x78) = 0x1000;
    FLD(s32, self, 0x7c) = 0x1000;
    FLD(s32, self, 0x8c) = 0x1000;
    FLD(s32, self, 0x9c) = 0x1000;
    FLD(s32, self, 0xac) = -0x32000;
    FLD(s32, self, 0xb0) = 0x32000;
    FLD(s32, self, 0xb4) = -0x37000;
    FLD(s32, self, 0xb8) = -0xaa000;
    FLD(s32, self, 0xec) = 1;
    FLD(s32, self, 0xf4) = 1;
    FLD(s32, self, 0xfc) = 1;
    FLD(u16, self, 0x104) = 0x800;
    return self;
}

void func_ov015_02209270(u8 *self) {
    u32 saved;
    HEAP_PUSH(saved);
    DELETE_V(FLD(void *, self, 0xf0));
    HEAP_POP(saved);
    HEAP_PUSH(saved);
    DELETE_V(FLD(void *, self, 0x100));
    HEAP_POP(saved);
    HEAP_PUSH(saved);
    DELETE_V(FLD(void *, self, 0xf8));
    HEAP_POP(saved);
}

void *func_ov015_02209344(void *self) {
    SET_VT(self, data_ov015_02212eb0);
    func_0203de1c(self);
    return self;
}

}
