#include "ov015/ov015.h"

extern "C" {

extern void *data_ov000_021ccd44;
u8 *func_ov000_0218084c(void *a, s32 b, s32 c);
extern void *data_ov000_021ccd40;
extern void *data_ov000_021ccd38;
extern void *data_02149ef8;
void *MsgRes_GetString(void *a, s32 b);
void func_ov000_0215bb14(void *a, void *b);
void *func_ov015_02207738(Ov015Ship *p);
extern u8 data_ov015_022129c0[];
void func_ov000_02163254(void *p);
void *func_ov000_02191b04(void *p);
extern u8 data_ov015_022129d0[];
void *func_ov015_0220765c(Ov015Ship *p);
void func_ov015_02207858(Ov015Ship *p);
void *func_ov000_0219196c(void *p);
void func_ov000_02191b70(void *p);
extern Ov015Shared *data_ov015_02213368;
BOOL func_ov015_022078bc(Ov015Ship *p);
BOOL func_ov000_02191b9c(void *p);

static inline bool Ov015Task_Flag4(Ov015Task *t) {
    return t->flag4;
}

bool Ov015Task_GetFlag4(Ov015Task *self) {
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

void func_ov015_02202e9c(Ov015Scene2a88 *self) {
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

void func_ov015_02202ec8(Ov015Scene2a88 *self) {
    u8 *model = self->unk_3c;
    u8 *res;
    u8 *anim;
    u8 *t;
    void *arg;
    if (model == NULL || self->unk_40 == 0 || (res = FLD(u8 *, model, 0x28)) == NULL) {
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
    func_02042628((Model *)model, arg, (ModelPart *)anim, 0);
}

BOOL func_ov015_02202f44(Ov015Menu *self, Ov015MenuItem *ev) {
    if (ev != NULL) {
        if (ev->unk_10 != -1) {
            FLD(u8, self->unk_08, 0xa4) = 1;
            func_02049a48(data_02097e4c, 0x1e, -1, -1, -1);
        } else {
            func_02049a48(data_02097e4c, 0x20, -1, -1, -1);
        }
    }
    return TRUE;
}

BOOL func_ov015_02202fa8(Ov015Menu *self, Ov015MenuItem *ev) {
    Ov015Scene2a08 *o = (Ov015Scene2a08 *)self->unk_08;
    void *d = data_02149ef8;
    void *m;
    switch (ev->unk_06) {
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
        func_ov000_0215bb14(o->unk_84, m);
        VCALL(o->unk_84)->v70();
    }
    return TRUE;
}

void func_ov015_02203020(Ov015Scene2a08 *self) {
    void *saved;
    HEAP_PUSH(saved);
    {
    Ov015Ship *o = self->unk_3c;
    if (o != NULL) {
        if (o != NULL) {
            func_ov015_02207738(o);
            Heap_Free(o);
        }
        self->unk_3c = NULL;
    }
    }
    HEAP_POP(saved);
    HEAP_PUSH(saved);
    DELETE_V(self->unk_40);
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

void *func_ov015_0220318c(void *self) {
    SET_VT(self, data_ov015_022129c0);
    func_ov000_02163254(self);
    Heap_Free(self);
    return self;
}

void *func_ov015_022031b4(void *self) {
    func_ov000_02191b04(self);
    Heap_Free(self);
    return self;
}

void func_ov015_022031d0(Ov015Scene2a08 *self) {
    Ov015Ship *p;
    void *q;
    p = (Ov015Ship *)Heap_Alloc(0xd58);
    if (p != NULL) {
        p = (Ov015Ship *)func_ov015_0220765c(p);
    }
    self->unk_3c = p;
    func_ov015_02207858(p);
    ((Ov015Ship *)self->unk_3c)->unk_d48 = data_ov015_02213368->unk_2c;
    q = Heap_Alloc(0x1c);
    if (q != NULL) {
        func_ov000_0219196c(q);
        SET_VT(q, data_ov015_022129d0);
    }
    self->unk_40 = (Ov015Shadow *)q;
    func_ov000_02191b70(q);
}

BOOL func_ov015_02203244(Ov015Scene2a08 *self) {
    BOOL r = func_ov015_022078bc(self->unk_3c) & 1 ? TRUE : FALSE;
    u8 st = self->unk_40->state;
    BOOL idle = TRUE;
    if (st != 3 && st != 0) {
        idle = FALSE;
    }
    if (!idle) {
        r = r & func_ov000_02191b9c(self->unk_40) ? TRUE : FALSE;
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

void func_ov015_02203298(Ov015Scene2a08 *self) {
    u8 *p;
    void *res;
    if (VCALL(self)->v28()) {
        return;
    }
    res = data_02149ef8;
    self->unk_3c->unk_d3c = 2;
    func_ov015_02207adc(self->unk_3c);
    {
        Ov015Ship *o = self->unk_3c;
        FLD(s16, o, 0xd20) = 0;
        FLD(s16, o, 0xd22) = 0;
        FLD(s16, o, 0xd24) = 0;
    }
    self->unk_3c->unk_d40 = 0;
    self->unk_3c->unk_d41 = 0;
    {
        Ov015Nib *n = &FLD(Ov015Nib, self->unk_40, 0x18);
        n->hi = n->lo;
        n->lo = 3;
    }
    self->unk_40->unk_10 = 0;
    self->unk_40->unk_0c = 0;
    self->unk_40->alpha = 0x14;
    self->unk_44.eye.x = 0x27d7;
    self->unk_44.eye.y = 0x4ee1;
    self->unk_44.eye.z = 0x6052;
    self->unk_44.at.x = -0x130a;
    self->unk_44.at.y = 0x14cd;
    self->unk_44.at.z = -0x452;
    self->unk_44.up.x = 0;
    self->unk_44.up.y = 0x1000;
    self->unk_44.up.z = 0;
    func_020434e0(&self->unk_44.fovSin);
    p = (u8 *)Heap_Alloc(0xe0);
    if (p != NULL) {
        SET_VT(p, data_ov000_021cac60);
        VCALL(p)->v28();
        SET_VT(p, data_ov000_021caec8);
        VCALL(p)->v28();
        SET_VT(p, data_ov000_021cb5a8);
        VCALL(p)->v28();
    }
    self->unk_88 = (Ov015Menu *)p;
    self->unk_88->unk_0c |= 0x4000000;
    self->unk_88->unk_2c = 1;
    Ov015_SetXYZ16(self->unk_88, 0x91, 0x12, -0x333);
    Ov015_SetXYZ32(self->unk_88, 0x100, 0, -0x333);
    self->unk_88->unk_0c |= 0x20000000;
    VCALL(self->unk_88)->vf4(1, MsgRes_GetString(res, 0x32));
    VCALL(self->unk_88)->v08();
    p = (u8 *)Heap_Alloc(0xd4);
    if (p != NULL) {
        SET_VT(p, data_ov000_021cac60);
        VCALL(p)->v28();
        SET_VT(p, data_ov000_021caec8);
        VCALL(p)->v28();
    }
    self->unk_80 = (Ov015Menu *)p;
    VCALL(self->unk_80)->v10(MsgRes_GetString(res, 0xc4));
    VCALL(self->unk_80)->v14(MsgRes_GetString(res, 0xc5));
    self->unk_80->unk_24 = 0x88;
    self->unk_80->unk_20 = 4;
    Ov015_SetXYZ16(self->unk_80, 0, 0x1e, -0xccd);
    Ov015_SetXYZ32(self->unk_80, 0, -0x100, -0xccd);
    self->unk_80->unk_2c = 1;
    self->unk_80->unk_0c &= ~0x400000;
    self->unk_80->unk_0c &= ~0x800000;
    self->unk_80->unk_0c &= ~0x20000;
    self->unk_80->unk_0c &= ~0x80000;
    self->unk_80->unk_0c &= ~0x40000;
    self->unk_80->unk_0c &= ~0x10000;
    VCALL(self->unk_80)->v74(MsgRes_GetString(res, 0xc6), 0, 0xffff, 0xffff);
    VCALL(self->unk_80)->v74(MsgRes_GetString(res, 0xca), 1, 0xffff, 0xffff);
    VCALL(self->unk_80)->v74(MsgRes_GetString(res, 0xd4), 2, 0xffff, 0xffff);
    {
        Ov015Menu *o = self->unk_80;
        VCALL(o)->va8(func_ov000_02154b58(o, 0));
    }
    self->unk_80->unk_84 = (void *)func_ov015_02202f44;
    self->unk_80->unk_88 = (void *)func_ov015_02202fa8;
    self->unk_80->unk_08 = (u8 *)self;
    VCALL(self->unk_80)->v08();
    p = (u8 *)Heap_Alloc(0x8c);
    if (p != NULL) {
        SET_VT(p, data_ov000_021cac60);
        VCALL(p)->v28();
        SET_VT(p, data_ov000_021cadcc);
        VCALL(p)->v28();
    }
    self->unk_84 = (Ov015UiLabel *)p;
    self->unk_84->unk_24 = 0xf8;
    self->unk_84->unk_20 = 2;
    Ov015_SetXYZ16(self->unk_84, 4, 0x95, -0xccd);
    Ov015_SetXYZ32(self->unk_84, -0x100, 0, -0xccd);
    self->unk_84->unk_2c = 1;
    func_ov000_0215bb14(self->unk_84, MsgRes_GetString(res, 0xc7));
    VCALL(self->unk_84)->v70();
    VCALL(self->unk_84)->v08();
    switch (self->unk_0c) {
    case 1:
        if (data_ov015_02213360 == 0) {
            p = (u8 *)Heap_Alloc(0x2c);
            if (p != NULL) {
                SET_VT(p, data_ov015_022129c0);
                func_ov000_02163224(p);
            }
            FLD(u8 *, self, 0x8c) = p;
            func_ov000_021632f0(self->unk_8c, 5, data_ov015_02212990, data_ov015_0221299d, 0);
            self->unk_80->unk_0c |= 4;
            self->unk_84->unk_0c |= 4;
            self->unk_88->unk_0c |= 2;
            self->unk_84->unk_0c |= 2;
        }
    case 2: {
        u8 *o = (u8 *)func_ov000_02154b58(self->unk_80, 1);
        FLD(s32, o, 0x24) = 0xe;
        FLD(s32, o, 0x10) = -1;
        o = (u8 *)func_ov000_02154b58(self->unk_80, 2);
        FLD(s32, o, 0x24) = 0xe;
        FLD(s32, o, 0x10) = -1;
        break;
    }
    }
    {
        GfxSys *g = data_02097d48;
        func_02043904(g->unk_8b0);
        g->unk_8b0[0] |= 0x30;
        REG16(0x4000060) = (REG16(0x4000060) & ~0x3000) | 0x20;
        func_02043b20(g->unk_8b0);
    }
    func_ov000_02173648(self);
    if (++data_ov015_02213360 > 100) {
        data_ov015_02213360 = 100;
    }
}

}
