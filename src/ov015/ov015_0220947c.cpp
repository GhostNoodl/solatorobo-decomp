#include "ov015/ov015.h"

extern "C" {

s32 func_ov000_0218f110(void *a);
s32 func_ov000_02191b9c(void *a);
extern const Ov015ShipCfg data_ov015_02212db0;
extern u8 data_ov015_02212e0d[];
extern char data_ov015_02212e14[];
extern char data_ov015_02212e15[];
s32 func_ov000_021909a8(void *a, const void *b, const void *c);
u8 *func_0206fef8(u16 id);
BOOL func_ov000_0218ffdc(void *a, void *b, s32 c, s32 d);
void func_ov015_022090fc(u8 *self);
BOOL func_ov000_02190cb0(void *a, const void *b, s32 c, s32 d);
void func_ov000_021915a0(void *a);
void func_ov000_02191618(void *a);
void func_ov000_02191690(void *a);
void *func_ov000_02191318(void *a, s32 b);
void func_0203f364(void *a);
void *Ov015FishState2c_Ctor(Ov015FishState2c *self);
void func_ov000_02190a80(void *a, s32 b);
void func_ov015_02209a50(Ov015Fish *self);
int func_0203f3d0(void *a);
extern u32 data_02fe0f04;
s32 Interp_SinLerp(s32 t, s32 a, s32 b);
void func_ov015_02209c90(Ov015Fish *self);
void func_ov015_0220daf4(Ov015Shadow *a, Ov015Vec *pos, s32 b, s32 c, s32 ang, s32 d);
BOOL func_ov000_021903b4(void *a);
s32 func_01ffc584(void *a, void *b, s32 c, s32 d);
extern u8 data_ov015_02212e94[];
extern u8 data_ov015_02212eb0[];

static inline BOOL Ov015_IsIdle567(Ov015Fish *self) {
    BOOL r = TRUE;
    if (self->unk_54c.state != 3 && self->unk_54c.state != 0) r = FALSE;
    return r;
}
BOOL func_ov015_0220947c(Ov015Fish *self) {
    BOOL r = TRUE;
    if (self->unk_10c.unk_00 >= 0) {
        if (func_ov000_0218f110(&self->unk_10c) == 0) r = FALSE;
    }
    if (self->unk_32c.unk_00 >= 0) {
        if (func_ov000_0218f110(&self->unk_32c) == 0) r = FALSE;
    }
    if (!Ov015_IsIdle567(self)) {
        if (func_ov000_02191b9c(&self->unk_54c) == 0) r = FALSE;
    }
    return r;
}

struct Ov015Bits09500 { u16 b0 : 5; u16 b5 : 3; u16 b8 : 8; };
BOOL func_ov015_02209500(Ov015Fish *self) {
    u8 *p;
    u32 n;
    Ov015V *m;
    func_ov000_0218ffdc(&self->unk_244, &self->unk_10c, 0, 1);
    func_ov000_02190cb0(&self->unk_244, data_ov015_02212e0d, 0x1000, 0);
    p = NULL;
    if (self->unk_10c.unk_c0 != NULL) p = FLD(u8 *, self->unk_10c.unk_c0, 0) + 8;
    self->unk_244.unk_d0 = p;
    if (p != NULL && FLD(u16, p, 2) == 0) {
        self->unk_244.unk_d4 = p + 4 + FLD(u16, p, 0) * 12;
    }
    self->unk_244.unk_c2.b4 = 0;
    func_ov000_021915a0(&self->unk_244);
    self->unk_244.unk_c2.b0 = 1;
    NNS_G3dRenderObjSetInitFunc((NNSG3dRenderObj *)(&self->unk_244.unk_24), (NNSG3dSbcCallBackFunc)func_ov015_022090fc);
    self->unk_244.unk_c2.b5 = 0;
    self->unk_244.unk_c2.b8 = 1;
    self->unk_244.unk_24.ptrUser = &self->unk_0c[0].x;
    self->unk_3c = func_ov000_021909a8(&self->unk_244, data_ov015_02212e14, data_ov015_02212e15);
    func_ov000_0218ffdc(&self->unk_464, &self->unk_32c, 0, 1);
    n = FLD(Ov015Bits09500, func_0206fef8(self->unk_04), 0x12).b5;
    if (n != 0) {
        func_ov000_02190cb0(&self->unk_464, data_ov015_02212db0.name, 0x1000, 0);
        func_ov000_02191618(&self->unk_464);
        func_ov000_02191690(&self->unk_464);
        func_ov000_02191318(&self->unk_464, n << 12);
    }
    self->unk_464.unk_c2.b4 = 0;
    self->unk_464.unk_c2.b0 = 1;
    self->unk_54c.prev = self->unk_54c.type;
    self->unk_54c.type = 3;
    self->unk_40.z = (0x800 - 0x37800) - FX_Mul(FX_Div(data_ov015_0221332c.unk_00, 0x3e8000), 0x73000);
    { s32 v = FLD(s16, func_0206fef8(self->unk_c0.unk_04), 0x10); self->unk_70 = v; self->unk_74 = v; self->unk_78 = v; }
    if (self->unk_568.unk_24 != 0) func_0203f364(&self->unk_568);
    self->unk_568.unk_28 = 0x100;
    self->unk_568.unk_2c = 0x100;
    self->unk_94 = FLD(s16, func_0206fef8(self->unk_c0.unk_04), 0x16) << 4;
    self->unk_98 = FLD(s16, func_0206fef8(self->unk_c0.unk_04), 0x14) << 4;
    m = (Ov015V *)Heap_Alloc(0x2c);
    if (m != NULL) m = (Ov015V *)Ov015FishState2c_Ctor((Ov015FishState2c *)m);
    self->unk_f8 = m;
    self->unk_f4 = 2;
    m->v08(self);
    return TRUE;
}

BOOL func_ov015_02209790(Ov015Fish *self, BOOL b) {
    func_ov000_02190a80(&self->unk_244, self->unk_104);
    func_ov000_02190a80(&self->unk_464, 0);
    if (!b) {
        return TRUE;
    }
    if (self->unk_f0 != NULL) {
        void *saved;
        HEAP_PUSH(saved);
        DELETE_V(self->unk_100);
        HEAP_POP(saved);
        self->unk_f8->v10(self);
        self->unk_100 = self->unk_f8;
        self->unk_fc = self->unk_f4;
        self->unk_f0->v08(self);
        self->unk_f8 = self->unk_f0;
        self->unk_f4 = self->unk_ec;
        self->unk_f0 = NULL;
        self->unk_ec = 0;
    }
    if (self->unk_f8 != NULL && !self->unk_f8->v0c(self)) {
        void *saved;
        Ov015V *o;
        self->unk_f8->v10(self);
        HEAP_PUSH(saved);
        DELETE_V(self->unk_f8);
        HEAP_POP(saved);
        o = self->unk_100;
        self->unk_f8 = o;
        self->unk_f4 = self->unk_fc;
        o->v08(self);
        self->unk_100 = NULL;
        self->unk_fc = 0;
    }
    if (self->unk_f4 != 5 && self->unk_f4 != 6) {
        self->unk_40.z = (0x800 - 0x37800) - FX_Mul(FX_Div(data_ov015_0221332c.unk_00, 0x3e8000), 0x73000);
    }
    {
        s32 t = FX_Mul(FX_Div(self->unk_40.z + 0x37000, -0x73000), 0x3e8000);
        if (t <= 0x1f4000) {
            self->unk_7c = 0x1000;
        } else {
            self->unk_7c = FX_Mul(FX_Div(0x3e8000 - t, 0x1f4000), 0x666) + 0x99a;
        }
    }
    func_ov015_02209a50(self);
    self->unk_568.unk_0c = self->unk_568.unk_00;
    self->unk_568.unk_00 = self->unk_40;
    self->unk_568.unk_38 = self->unk_80;
    func_0203f3d0(&self->unk_568);
    self->unk_568.unk_44 = data_02fe0f04;
    return TRUE;
}

void func_ov015_02209a50(Ov015Fish *self) {
    s32 f;
    if (self->unk_40.y > -0xa000) {
        self->unk_8c = 0x1000;
        if (self->unk_90 > 8) {
            self->unk_90--;
        }
    } else if (self->unk_40.y > -0x32000) {
        s32 t = FX_Div(self->unk_40.y + 0x32000, 0x28000);
        s32 k;
        self->unk_8c = Interp_SinLerp(t, 0x666, 0x1000);
        k = (Interp_SinLerp(t, 0xa000, 0x16000) >> 12) & 0xff;
        if (self->unk_90 > k) {
            self->unk_90--;
        } else if (self->unk_90 < k) {
            self->unk_90++;
        }
    } else {
        self->unk_8c = 0x666;
        self->unk_90 = 10;
    }
    f = FX_Mul(self->unk_8c, FLD(s16, func_0206fef8(self->unk_c0.unk_04), 0x10));
    self->unk_8c = f;
    self->unk_80 = 0x28000;
    self->unk_84 = 0x1000;
    self->unk_88 = 0x32000;
    self->unk_80 = FX_Mul(self->unk_80, f);
    self->unk_84 = FX_Mul(self->unk_84, f);
    self->unk_88 = FX_Mul(self->unk_88, f);
}

void func_ov015_02209b80(Ov015Fish *self, s32 a, s32 b) {
    self->unk_f0 = (Ov015V *)a;
    self->unk_ec = b;
}

static inline void Ov015_UpdateMove(Ov015Fish *self) {
    u16 ang = FX_Atan2(self->unk_9c.x, self->unk_9c.z);
    Ov015Vec v;
    v = self->unk_40;
    v.y = 0;
    self->unk_54c.unk_10 = -0x1666;
    func_ov015_0220daf4(&self->unk_54c, &v, self->unk_80, self->unk_88, ang, 0);
    self->unk_54c.alpha = self->unk_90;
}
void func_ov015_02209b8c(Ov015Fish *self) {
    switch (self->unk_108) {
    case 0:
        func_ov015_02209c90(self);
        break;
    case 1:
        Ov015_UpdateMove(self);
        break;
    case 2:
        func_ov015_02209c90(self);
        Ov015_UpdateMove(self);
        break;
    }
}

struct Ov015Blk09c90 { s32 w[3]; };
extern const Ov015Blk09c90 data_ov015_02212644;
static inline void Ov015_Cross09c90(const Ov015Vec *a, const Ov015Vec *b, Ov015Vec *o) {
    o->x = (s32)(((s64)a->y * b->z - (s64)a->z * b->y + 0x800) >> 12);
    o->y = (s32)(((s64)a->z * b->x - (s64)a->x * b->z + 0x800) >> 12);
    o->z = (s32)(((s64)a->x * b->y - (s64)a->y * b->x + 0x800) >> 12);
}
void func_ov015_02209c90(Ov015Fish *self) {
    Ov015Vec up;
    Ov015Vec x;
    Ov015Vec z;
    s32 k = self->unk_7c;
    s32 sx = FX_Mul(self->unk_70, k);
    s32 sy = FX_Mul(self->unk_74, k);
    s32 sz = FX_Mul(self->unk_78, k);
    if (self->unk_9c.x != 0 || self->unk_9c.y != 0 || self->unk_9c.z == 0) {
        *(Ov015Blk09c90 *)&up = data_ov015_02212644;
        VEC_Normalize((VecFx32 *)(&self->unk_9c), (VecFx32 *)&z);
        Ov015_Cross09c90(&up, &z, &x);
        VEC_Normalize((VecFx32 *)&x, (VecFx32 *)&x);
        Ov015_Cross09c90(&z, &x, &up);
        VEC_Normalize((VecFx32 *)&up, (VecFx32 *)&up);
        self->unk_4c[0] = x;
        self->unk_4c[1] = up;
        self->unk_4c[2] = z;
    }
    if (data_ov015_0221332c.unk_1d != 0 && self->unk_f4 == 2) {
        self->unk_244.unk_b6 = 0x14bf;
        self->unk_244.unk_b8 = 0x5ad6;
        self->unk_244.unk_ba = 0xb;
        self->unk_244.unk_bc = 0xa;
        self->unk_464.unk_b6 = 0x14bf;
        self->unk_464.unk_b8 = 0x5ad6;
        self->unk_464.unk_ba = 0xb;
        self->unk_464.unk_bc = 0xa;
    }
    self->unk_244.unk_78 = *(Ov015VecC *)&self->unk_40;
    MI_Copy36B(&self->unk_4c[0].x, &self->unk_244.unk_84[0].x);
    self->unk_244.unk_a8 = sx;
    self->unk_244.unk_ac = sy;
    self->unk_244.unk_b0 = sz;
    func_ov000_021903b4(&self->unk_244);
    self->unk_464.unk_78 = *(Ov015VecC *)&self->unk_30;
    MI_Copy36B(&self->unk_0c[0].x, &self->unk_464.unk_84[0].x);
    func_ov000_021903b4(&self->unk_464);
    NNS_G3dGeFlushBuffer();
}

s32 func_ov015_02209fb8(s32 x) {
    s32 t = FX_Div(x + 0x37000, -0x73000);
    return (s32)(((s64)t * 0x3e8000 + 0x800) >> 12);
}

BOOL func_ov015_02209ff0(Ov015Fish *self, void *a) {
    BOOL r = FALSE;
    if (func_01ffc584(a, &self->unk_40, self->unk_98 + 0x4cd, self->unk_94)) r = TRUE;
    return r;
}

BOOL func_ov015_0220a028(Ov015Fish *self, void *a) {
    BOOL r = FALSE;
    if (func_01ffc584(a, &self->unk_40, self->unk_98, self->unk_94)) r = TRUE;
    return r;
}

void func_ov015_0220a058(Ov015Fish *self, void *out) {
    s32 z = FX_Mul(self->unk_70, 0xa000);
    Ov015Vec v;
    v.x = 0;
    v.y = 0;
    v.z = z;
    MTX_MultVec33((VecFx32 *)&v, (MtxFx33 *)(&self->unk_0c[0].x), (VecFx32 *)&v);
    VEC_Add((VecFx32 *)&v, (VecFx32 *)(&self->unk_30), (VecFx32 *)out);
}

void *Ov015FishState2c_Ctor(Ov015FishState2c *self) {
    SET_VT(self, data_ov015_02212e94);
    self->unk_04 = 0;
    self->unk_06 = 0;
    self->unk_08 = 0;
    self->unk_0a = 0;
    self->unk_0c = 0;
    self->unk_10 = 0;
    self->unk_14 = 0;
    self->unk_16 = 0;
    self->unk_18 = 0;
    self->unk_1c = 0;
    self->unk_20 = 0;
    self->unk_24 = 0;
    self->unk_28 = 0;
    return self;
}

void *Ov015FishState2c_Dtor(void *self) {
    SET_VT(self, data_ov015_02212e94);
    VCALL(self)->v10(0);
    SET_VT(self, data_ov015_02212eb0);
    return self;
}

void *Ov015FishState2c_DtorDelete(void *self) {
    SET_VT(self, data_ov015_02212e94);
    VCALL(self)->v10(0);
    SET_VT(self, data_ov015_02212eb0);
    Heap_Free(self);
    return self;
}

BOOL Ov015FishState2c_Enter(Ov015FishState2c *self, Ov015Fish *p) {
    self->unk_20 = p;
    self->unk_06 = 0;
    self->unk_08 = 2;
    self->unk_0a = 0;
    self->unk_0c = p->unk_c0.unk_1c;
    p->unk_a8 = 0;
    p->unk_bc = 1;
    func_ov000_02190cb0(&p->unk_244, data_ov015_02212e0d, 0x19a, 0);
    p->unk_104 = 0x800;
    func_ov000_021915a0(&p->unk_244);
    self->unk_04 = 0;
    return TRUE;
}

}
