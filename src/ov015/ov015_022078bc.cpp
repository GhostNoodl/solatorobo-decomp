#include "ov015/ov015.h"

#pragma pool_strings on
#pragma dont_reuse_strings off

extern "C" {

void func_ov015_02208474(u8 *self);
BOOL func_ov000_0218ffdc(void *a, void *b, s32 c, s32 d);
BOOL func_ov000_02190cb0(void *a, const void *b, s32 c, s32 d);
void func_ov000_021915a0(void *a);
void func_ov000_02190e98(void *a, s32 b, s32 c, s32 d);
void func_ov000_021911c8(void *a, s32 b);
s32 func_ov000_021909a8(void *a, const void *b, const void *c);

BOOL func_ov000_0218f110(void *p);
void Shadow_Load(void *p);
BOOL func_ov000_02191b9c(void *p);
extern const char *data_ov015_02212cac[];
extern const char *data_ov015_02212cb4[];
extern const char *data_ov015_02212cbc[];
extern const char *data_ov015_02212cc4[];

// STD_CopyString (nitro/std.h) returns its destination; this TU was built against a void-returning
// declaration, and the char * result changes the scheduling of func_ov015_022078bc, so the calls
// go through a void view of the same function.
typedef void (*Ov015CopyStringFn)(char *dst, const char *src);
#define OV015_COPY_STRING(d, s) ((Ov015CopyStringFn)STD_CopyString)(d, s)

static inline void Ov015_SetModel(Ov015Anim *o, const char *file, const char *name) {
    OV015_COPY_STRING(o->mdlDir, file);
    OV015_COPY_STRING(o->mdlName, name);
    o->ownMdl = 1;
}
static inline void Ov015_SetAnim(Ov015Anim *o, const char *file, const char *name) {
    OV015_COPY_STRING(o->anmDir, file);
    OV015_COPY_STRING(o->anmName, name);
    o->ownAnm = 1;
}

BOOL func_ov015_022078bc(Ov015Ship *self) {
    s32 kq;
    BOOL r = FALSE;
    switch (self->loadStep) {
    case 10:
        Ov015_SetModel(&self->res, data_ov015_02212cc4[self->modelIdx], data_ov015_02212cac[self->modelIdx]);
        Ov015_SetAnim(&self->res, "mc/c1rob4", "c1rob4");
        self->res.unk_00 = 0;
        Ov015_SetModel(&self->res2, data_ov015_02212cc4[self->modelIdx], data_ov015_02212cb4[self->modelIdx]);
        Ov015_SetAnim(&self->res2, "mc/c1rob4", "c1rob4cha");
        self->res2.unk_00 = 0;
        {
            const char *n = data_ov015_02212cbc[self->modelIdx];
            OV015_COPY_STRING(self->res3.mdlDir, data_ov015_02212cc4[self->modelIdx]);
            OV015_COPY_STRING(self->res3.mdlName, n);
        }
        self->res3.unk_00 = 0;
        self->res3.ownMdl = 1;
        kq = 0xcb8;
        if ((u32)self & 3) {
            kq = 0xcb8;
        }
        Shadow_Load((u8 *)self + kq);
        self->loadStep = 20;
        break;
    case 20: {
        BOOL ok = TRUE;
        BOOL t;
        u8 k;
        if (self->res.unk_00 >= 0 && !func_ov000_0218f110(self)) ok = FALSE;
        if (self->res2.unk_00 >= 0 && !func_ov000_0218f110(&self->res2)) ok = FALSE;
        if (self->res3.unk_00 >= 0 && !func_ov000_0218f110(&self->res3)) ok = FALSE;
        k = self->shadow.state;
        t = TRUE;
        if (k != 3 && k != 0) t = FALSE;
        if (!t && !func_ov000_02191b9c(&self->shadow)) ok = FALSE;
        if (ok) {
            self->loadStep = 30;
            r = TRUE;
        }
        break;
    }
    case 30:
        r = TRUE;
        break;
    }
    return r;
}

BOOL func_ov015_02207adc(Ov015Ship *self) {
    s32 i;
    func_ov000_0218ffdc(&self->model, self, 0, 1);
    func_ov000_02190cb0(&self->model, "ang00", 0x1000, 0);
    func_ov000_021915a0(&self->model);
    NNS_G3dRenderObjSetInitFunc((NNSG3dRenderObj *)(&self->model.renderObj), (NNSG3dSbcCallBackFunc)func_ov015_02208474);
    self->model.flags.clearInit = 0;
    self->model.flags.flushVP = 1;
    self->nodeMtx.id = func_ov000_021909a8(&self->model, self->res.anmName, "ang05");
    for (i = 0; i < 8; i++) {
        func_ov000_0218ffdc(&self->subModels[i], &self->res2, 0, 1);
        func_ov000_02190e98(&self->subModels[i], 0, 0x1000, 0);
        func_ov000_021915a0(&self->subModels[i]);
        func_ov000_021911c8(&self->subModels[i], 0);
        self->subModels[i].scaleX = 0x1333;
        self->subModels[i].scaleY = 0x1333;
        self->subModels[i].scaleZ = 0x1c00;
    }
    func_ov000_0218ffdc(&self->model3, &self->res3, 0, 1);
    self->shadow.prev = self->shadow.type;
    self->shadow.type = 3;
    self->shadow.scale = 0x2000;
    self->loadStep = 0x32;
    return TRUE;
}


extern const void *data_ov015_02212634[];
extern u16 data_ov015_0221262c[];
void func_ov000_02191618(void *a);
void func_ov000_02190a80(void *a, s32 b);
void func_ov000_02191780(void *a);
void func_ov000_021917f8(void *a);
u16 func_01ffc128(u16 a, u16 b, s32 c, s32 d, s32 e);
s32 Rand_PlusMinus(s32 max);
s32 Rand_UpTo(s32 max);
Ov015V *func_02065f88(s32 id, void *pos);
s32 EffectMgr_Contains(void *a, void *b);

void func_ov015_02207c30(Ov015Ship *self) {
    u16 ang = 0x8000;
    switch (self->unk_d3a) {
    case 0:
        func_ov000_02190cb0(&self->model, data_ov015_02212634[self->unk_d3a], 0x155, 0);
        func_ov000_021915a0(&self->model);
        break;
    case 1:
    case 2:
    case 3:
        func_ov000_02190cb0(&self->model, data_ov015_02212634[self->unk_d3a], 0x2ab, 0);
        func_ov000_02191618(&self->model);
        ang = data_ov015_0221262c[self->unk_d3a] + Rand_PlusMinus(0x800);
        break;
    }
    func_ov000_02190a80(&self->model, 0x1000);
    if (self->unk_d40) {
        self->rotY = func_01ffc128(ang, self->rotY, 0x19a, 1, 0x8000);
    }
    if (self->unk_d3c == 1) {
        s32 v = self->unk_d3e;
        BOOL neg = FALSE;
        s32 i;
        if (v < 0) {
            v = (s16)-v;
            neg = TRUE;
        }
        for (i = 0; i < 8; i++) {
                func_ov000_021911c8(&self->subModels[i], v);
            if (neg) {
                func_ov000_02191780(&self->subModels[i]);
            } else {
                func_ov000_021917f8(&self->subModels[i]);
            }
            func_ov000_02190a80(&self->subModels[i], 0x1000);
        }
    }
    if (self->unk_d42) {
        if (self->fx == NULL) {
            Ov015VecC p = *(Ov015VecC *)&self->nodeMtx.m[3];
            Ov015V *e = func_02065f88(0x322, &p);
            self->fx = e;
            e->v14(0x1333, 0x1333, 0x1333);
            self->fx->v34(0, 0, (u16)Rand_UpTo(0x3fff));
            FLD(s32, self->fx, 0xc8) = -1;
            self->fx->v08(3);
            FLD(s32, self->fx, 0x3c) = 0x2000;
            self->fxTimer = 0x5a;
        } else {
            if (Rand_UpTo(100) < 5) {
                Ov015VecC p = FLD(Ov015VecC, self->fx, 0x58);
                Ov015V *e = func_02065f88(0x320, &p);
                e->v14(0x800, 0x800, 0x800);
                e->v08(3);
            }
            if (--self->fxTimer < 0) {
                self->fx->v34(0, 0, (u16)Rand_UpTo(0x3fff));
                self->fxTimer = 0x5a;
            }
        }
        if (self->fx2 == NULL) {
            Ov015V *e = func_02065f88(0x322, &self->unk_d4c);
            self->fx2 = e;
            e->v34(0, 0, 0x3fff);
            FLD(s32, self->fx2, 0xc8) = -1;
            self->fx2->v08(1);
            FLD(s32, self->fx2, 0x50) = -0xaa000;
            FLD(s32, self->fx2, 0x54) = -0x37000;
            self->fxTimer2 = 10;
        } else {
            if (--self->fxTimer2 < 0) {
                self->fxTimer2 = 0;
            }
        }
    } else {
        if (EffectMgr_Contains(data_0214a420, self->fx)) {
            void *saved;
            HEAP_PUSH(saved);
            DELETE_V(self->fx);
            HEAP_POP(saved);
        }
        if (EffectMgr_Contains(data_0214a420, self->fx2)) {
            void *saved;
            HEAP_PUSH(saved);
            DELETE_V(self->fx2);
            HEAP_POP(saved);
        }
    }
}

}
