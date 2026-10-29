#include "ov015/ov015.h"

extern "C" {

extern void *data_ov000_021ccd44;
u8 *func_ov000_0218084c(void *a, s32 b, s32 c);
extern void *data_ov000_021ccd40;
extern void *data_ov000_021ccd38;
void *NNS_G2dGetAnimSequenceByIdx(void *a, int b);
void *NNS_G2dGetCellDataByIdx(void *a, int b);
void func_02042628(void *a, void *b, void *c, int d);
extern void *data_02097e4c;
void *func_02049a48(void *a, s32 b, s32 c, s32 d, s32 e);
extern void *data_02149ef8;
void *func_0204c0e8(void *a, s32 b);
void func_ov000_0215bb14(void *a, void *b);
void *func_ov015_02207738(void *p);
extern u8 data_ov015_022129c0[];
void func_ov000_02163254(void *p);
void *func_ov000_02191b04(void *p);
extern u8 data_ov015_022129d0[];
void *func_ov015_0220765c(void *p);
void func_ov015_02207858(void *p);
void *func_ov000_0219196c(void *p);
void func_ov000_02191b70(void *p);
extern Ov015Shared *data_ov015_02213368;
BOOL func_ov015_022078bc(void *p);
BOOL func_ov000_02191b9c(void *p);

static inline bool Ov015Task_Flag4(Ov015Task *t) {
    return t->flag4;
}

bool func_ov015_02202dac(Ov015Task *self) {
    BOOL r = Ov015Task_Flag4(self);
    return r;
}

void func_ov015_02202dd0(Ov015Task *self) {
    u8 *o;
    if (self->unk_08 == 8) {
        return;
    }
    if (self->unk_08 != 0xc) {
        return;
    }
    o = func_ov000_0218084c(data_ov000_021ccd44, 0x1f, 0);
    FLD(s32, o, 0xc) = self->unk_0c;
    VCALL(self)->v4c();
}

BOOL func_ov015_02202e20(Ov015Task *self) {
    if (VCALL(self)->v54()) {
        if (data_ov000_021ccd40 != NULL) {
            data_ov000_021ccd38 = FLD(void *, data_ov000_021ccd40, 0x14);
        } else {
            data_ov000_021ccd38 = NULL;
        }
        data_ov000_021ccd40 = NULL;
    }
    return TRUE;
}

static inline bool Ov015_IsCurrent(void *p) {
    return data_ov000_021ccd40 == p;
}

bool func_ov015_02202e74(void *self) {
    BOOL r = Ov015_IsCurrent(self);
    return r;
}

void func_ov015_02202e9c(u8 *self) {
    s32 a = FLD(s32, self, 0x44);
    s32 r = 0;
    if (a < 0x1000000) {
        r = a + 0x8000;
    }
    FLD(s32, self, 0x44) = r;
    if (FLD(s32, self, 0x48) >= 0x1000000) {
        FLD(s32, self, 0x48) = 0;
    } else {
        FLD(s32, self, 0x48) += 0x8000;
    }
}

void func_ov015_02202ec8(u8 *self) {
    u8 *model = FLD(u8 *, self, 0x3c);
    u8 *res;
    u8 *anim;
    u8 *t;
    void *arg;
    if (model == NULL || FLD(u8, self, 0x40) == 0 || (res = FLD(u8 *, model, 0x28)) == NULL) {
        return;
    }
    anim = NULL;
    if (FLD(s32, model, 0x80) > 0) {
        anim = FLD(u8 *, model, 0x78);
    }
    if (anim != NULL && (t = FLD(u8 *, anim, 0x4)) != NULL) {
        arg = FLD(void *, t, 0x30);
    } else {
        void *e = NNS_G2dGetAnimSequenceByIdx(FLD(void *, res, 0xc), 0);
        arg = NNS_G2dGetCellDataByIdx(FLD(void *, res, 0x4), **(u16 **)FLD(void *, e, 0xc));
    }
    func_02042628(model, arg, anim, 0);
}

BOOL func_ov015_02202f44(u8 *self, u8 *ev) {
    if (ev != NULL) {
        if (FLD(s32, ev, 0x10) != -1) {
            FLD(u8, FLD(u8 *, self, 0x8), 0xa4) = 1;
            func_02049a48(data_02097e4c, 0x1e, -1, -1, -1);
        } else {
            func_02049a48(data_02097e4c, 0x20, -1, -1, -1);
        }
    }
    return TRUE;
}

BOOL func_ov015_02202fa8(u8 *self, u8 *ev) {
    u8 *o = FLD(u8 *, self, 0x8);
    void *d = data_02149ef8;
    void *m;
    switch (FLD(u16, ev, 0x6)) {
    case 0:
        m = func_0204c0e8(d, 0xc7);
        break;
    case 1:
        m = func_0204c0e8(d, 0xcb);
        break;
    case 2:
        m = func_0204c0e8(d, 0xd5);
        break;
    }
    if (FLD(void *, o, 0x84) != NULL) {
        func_ov000_0215bb14(FLD(void *, o, 0x84), m);
        VCALL(FLD(void *, o, 0x84))->v70();
    }
    return TRUE;
}

void func_ov015_02203020(u8 *self) {
    u32 saved;
    HEAP_PUSH(saved);
    {
    u8 *o = FLD(u8 *, self, 0x3c);
    if (o != NULL) {
        if (o != NULL) {
            func_ov015_02207738(o);
            func_0203de1c(o);
        }
        FLD(void *, self, 0x3c) = NULL;
    }
    }
    HEAP_POP(saved);
    HEAP_PUSH(saved);
    DELETE_V(FLD(void *, self, 0x40));
    HEAP_POP(saved);
    HEAP_PUSH(saved);
    DELETE_V(FLD(void *, self, 0x80));
    HEAP_POP(saved);
    HEAP_PUSH(saved);
    DELETE_V(FLD(void *, self, 0x84));
    HEAP_POP(saved);
    HEAP_PUSH(saved);
    DELETE_V(FLD(void *, self, 0x88));
    HEAP_POP(saved);
    HEAP_PUSH(saved);
    DELETE_V(FLD(void *, self, 0x8c));
    HEAP_POP(saved);
}

void *func_ov015_0220318c(void *self) {
    SET_VT(self, data_ov015_022129c0);
    func_ov000_02163254(self);
    func_0203de1c(self);
    return self;
}

void *func_ov015_022031b4(void *self) {
    func_ov000_02191b04(self);
    func_0203de1c(self);
    return self;
}

void func_ov015_022031d0(u8 *self) {
    void *p;
    void *q;
    p = func_0203dd9c(0xd58);
    if (p != NULL) {
        p = func_ov015_0220765c(p);
    }
    FLD(void *, self, 0x3c) = p;
    func_ov015_02207858(p);
    FLD(u16, FLD(u8 *, self, 0x3c), 0xd48) = data_ov015_02213368->unk_2c;
    q = func_0203dd9c(0x1c);
    if (q != NULL) {
        func_ov000_0219196c(q);
        SET_VT(q, data_ov015_022129d0);
    }
    FLD(void *, self, 0x40) = q;
    func_ov000_02191b70(q);
}

BOOL func_ov015_02203244(u8 *self) {
    BOOL r = func_ov015_022078bc(FLD(void *, self, 0x3c)) & 1 ? TRUE : FALSE;
    u8 st = FLD(u8, FLD(u8 *, self, 0x40), 0x1b);
    BOOL idle = TRUE;
    if (st != 3 && st != 0) {
        idle = FALSE;
    }
    if (!idle) {
        r = r & func_ov000_02191b9c(FLD(void *, self, 0x40)) ? TRUE : FALSE;
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
extern u8 *data_02097d48;
BOOL func_ov015_02207adc(void *p);
void func_020434e0(void *p, s32 a);
void *func_ov000_02154b58(void *a, s32 b);
void func_ov000_02163224(void *p);
void func_ov000_021632f0(void *p, s32 a, void *b, void *c, s32 d);
void func_02043904(void *p);
void func_02043b20(void *p);
void func_ov000_02173648(void *self);

struct Ov015Nib {
    u8 lo : 4;
    u8 hi : 4;
};

static inline void Ov015_SetXYZ16(u8 *o, s16 x, s16 y, s16 z) {
    FLD(s16, o, 0x64) = x;
    FLD(s16, o, 0x66) = y;
    FLD(s16, o, 0x68) = z;
}

static inline void Ov015_SetXYZ32(u8 *o, s32 x, s32 y, s32 z) {
    FLD(s32, o, 0x58) = x;
    FLD(s32, o, 0x5c) = y;
    FLD(s32, o, 0x60) = z;
}

void func_ov015_02203298(u8 *self) {
    u8 *p;
    void *res;
    if (VCALL(self)->v28()) {
        return;
    }
    res = data_02149ef8;
    FLD(s16, FLD(u8 *, self, 0x3c), 0xd3c) = 2;
    func_ov015_02207adc(FLD(u8 *, self, 0x3c));
    {
        u8 *o = FLD(u8 *, self, 0x3c);
        FLD(s16, o, 0xd20) = 0;
        FLD(s16, o, 0xd22) = 0;
        FLD(s16, o, 0xd24) = 0;
    }
    FLD(u8, FLD(u8 *, self, 0x3c), 0xd40) = 0;
    FLD(u8, FLD(u8 *, self, 0x3c), 0xd41) = 0;
    {
        Ov015Nib *n = &FLD(Ov015Nib, FLD(u8 *, self, 0x40), 0x18);
        n->hi = n->lo;
        n->lo = 3;
    }
    FLD(s32, FLD(u8 *, self, 0x40), 0x10) = 0;
    FLD(s32, FLD(u8 *, self, 0x40), 0xc) = 0;
    FLD(u8, FLD(u8 *, self, 0x40), 0x19) = 0x14;
    FLD(s32, self, 0x44) = 0x27d7;
    FLD(s32, self, 0x48) = 0x4ee1;
    FLD(s32, self, 0x4c) = 0x6052;
    FLD(s32, self, 0x50) = -0x130a;
    FLD(s32, self, 0x54) = 0x14cd;
    FLD(s32, self, 0x58) = -0x452;
    FLD(s32, self, 0x5c) = 0;
    FLD(s32, self, 0x60) = 0x1000;
    FLD(s32, self, 0x64) = 0;
    func_020434e0(self + 0x68, 0x1000);
    p = (u8 *)func_0203dd9c(0xe0);
    if (p != NULL) {
        SET_VT(p, data_ov000_021cac60);
        VCALL(p)->v28();
        SET_VT(p, data_ov000_021caec8);
        VCALL(p)->v28();
        SET_VT(p, data_ov000_021cb5a8);
        VCALL(p)->v28();
    }
    FLD(u8 *, self, 0x88) = p;
    FLD(u32, FLD(u8 *, self, 0x88), 0xc) |= 0x4000000;
    FLD(s32, FLD(u8 *, self, 0x88), 0x2c) = 1;
    Ov015_SetXYZ16(FLD(u8 *, self, 0x88), 0x91, 0x12, -0x333);
    Ov015_SetXYZ32(FLD(u8 *, self, 0x88), 0x100, 0, -0x333);
    FLD(u32, FLD(u8 *, self, 0x88), 0xc) |= 0x20000000;
    VCALL(FLD(u8 *, self, 0x88))->vf4(1, func_0204c0e8(res, 0x32));
    VCALL(FLD(u8 *, self, 0x88))->v08();
    p = (u8 *)func_0203dd9c(0xd4);
    if (p != NULL) {
        SET_VT(p, data_ov000_021cac60);
        VCALL(p)->v28();
        SET_VT(p, data_ov000_021caec8);
        VCALL(p)->v28();
    }
    FLD(u8 *, self, 0x80) = p;
    VCALL(FLD(u8 *, self, 0x80))->v10(func_0204c0e8(res, 0xc4));
    VCALL(FLD(u8 *, self, 0x80))->v14(func_0204c0e8(res, 0xc5));
    FLD(s32, FLD(u8 *, self, 0x80), 0x24) = 0x88;
    FLD(s32, FLD(u8 *, self, 0x80), 0x20) = 4;
    Ov015_SetXYZ16(FLD(u8 *, self, 0x80), 0, 0x1e, -0xccd);
    Ov015_SetXYZ32(FLD(u8 *, self, 0x80), 0, -0x100, -0xccd);
    FLD(s32, FLD(u8 *, self, 0x80), 0x2c) = 1;
    FLD(u32, FLD(u8 *, self, 0x80), 0xc) &= ~0x400000;
    FLD(u32, FLD(u8 *, self, 0x80), 0xc) &= ~0x800000;
    FLD(u32, FLD(u8 *, self, 0x80), 0xc) &= ~0x20000;
    FLD(u32, FLD(u8 *, self, 0x80), 0xc) &= ~0x80000;
    FLD(u32, FLD(u8 *, self, 0x80), 0xc) &= ~0x40000;
    FLD(u32, FLD(u8 *, self, 0x80), 0xc) &= ~0x10000;
    VCALL(FLD(u8 *, self, 0x80))->v74(func_0204c0e8(res, 0xc6), 0, 0xffff, 0xffff);
    VCALL(FLD(u8 *, self, 0x80))->v74(func_0204c0e8(res, 0xca), 1, 0xffff, 0xffff);
    VCALL(FLD(u8 *, self, 0x80))->v74(func_0204c0e8(res, 0xd4), 2, 0xffff, 0xffff);
    {
        u8 *o = FLD(u8 *, self, 0x80);
        VCALL(o)->va8(func_ov000_02154b58(o, 0));
    }
    FLD(void *, FLD(u8 *, self, 0x80), 0x84) = (void *)func_ov015_02202f44;
    FLD(void *, FLD(u8 *, self, 0x80), 0x88) = (void *)func_ov015_02202fa8;
    FLD(u8 *, FLD(u8 *, self, 0x80), 0x8) = self;
    VCALL(FLD(u8 *, self, 0x80))->v08();
    p = (u8 *)func_0203dd9c(0x8c);
    if (p != NULL) {
        SET_VT(p, data_ov000_021cac60);
        VCALL(p)->v28();
        SET_VT(p, data_ov000_021cadcc);
        VCALL(p)->v28();
    }
    FLD(u8 *, self, 0x84) = p;
    FLD(s32, FLD(u8 *, self, 0x84), 0x24) = 0xf8;
    FLD(s32, FLD(u8 *, self, 0x84), 0x20) = 2;
    Ov015_SetXYZ16(FLD(u8 *, self, 0x84), 4, 0x95, -0xccd);
    Ov015_SetXYZ32(FLD(u8 *, self, 0x84), -0x100, 0, -0xccd);
    FLD(s32, FLD(u8 *, self, 0x84), 0x2c) = 1;
    func_ov000_0215bb14(FLD(u8 *, self, 0x84), func_0204c0e8(res, 0xc7));
    VCALL(FLD(u8 *, self, 0x84))->v70();
    VCALL(FLD(u8 *, self, 0x84))->v08();
    switch (FLD(s32, self, 0xc)) {
    case 1:
        if (data_ov015_02213360 == 0) {
            p = (u8 *)func_0203dd9c(0x2c);
            if (p != NULL) {
                SET_VT(p, data_ov015_022129c0);
                func_ov000_02163224(p);
            }
            FLD(u8 *, self, 0x8c) = p;
            func_ov000_021632f0(FLD(u8 *, self, 0x8c), 5, data_ov015_02212990, data_ov015_0221299d, 0);
            FLD(u32, FLD(u8 *, self, 0x80), 0xc) |= 4;
            FLD(u32, FLD(u8 *, self, 0x84), 0xc) |= 4;
            FLD(u32, FLD(u8 *, self, 0x88), 0xc) |= 2;
            FLD(u32, FLD(u8 *, self, 0x84), 0xc) |= 2;
        }
    case 2: {
        u8 *o = (u8 *)func_ov000_02154b58(FLD(u8 *, self, 0x80), 1);
        FLD(s32, o, 0x24) = 0xe;
        FLD(s32, o, 0x10) = -1;
        o = (u8 *)func_ov000_02154b58(FLD(u8 *, self, 0x80), 2);
        FLD(s32, o, 0x24) = 0xe;
        FLD(s32, o, 0x10) = -1;
        break;
    }
    }
    {
        u8 *g = data_02097d48;
        func_02043904(g + 0x8b0);
        FLD(u8, g, 0x8b0) |= 0x30;
        REG16(0x4000060) = (REG16(0x4000060) & ~0x3000) | 0x20;
        func_02043b20(g + 0x8b0);
    }
    func_ov000_02173648(self);
    if (++data_ov015_02213360 > 100) {
        data_ov015_02213360 = 100;
    }
}

}
