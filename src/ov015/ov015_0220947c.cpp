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
    if (self->shadow.state != 3 && self->shadow.state != 0) r = FALSE;
    return r;
}
BOOL func_ov015_0220947c(Ov015Fish *self) {
    BOOL r = TRUE;
    if (self->res.unk_00 >= 0) {
        if (func_ov000_0218f110(&self->res) == 0) r = FALSE;
    }
    if (self->res2.unk_00 >= 0) {
        if (func_ov000_0218f110(&self->res2) == 0) r = FALSE;
    }
    if (!Ov015_IsIdle567(self)) {
        if (func_ov000_02191b9c(&self->shadow) == 0) r = FALSE;
    }
    return r;
}

struct Ov015Bits09500 { u16 b0 : 5; u16 b5 : 3; u16 b8 : 8; };
BOOL func_ov015_02209500(Ov015Fish *self) {
    u8 *p;
    u32 n;
    Ov015V *m;
    func_ov000_0218ffdc(&self->model, &self->res, 0, 1);
    func_ov000_02190cb0(&self->model, data_ov015_02212e0d, 0x1000, 0);
    p = NULL;
    if (self->res.evHandle != NULL) p = FLD(u8 *, self->res.evHandle, 0) + 8;
    self->model.evTable = p;
    if (p != NULL && FLD(u16, p, 2) == 0) {
        self->model.evData = p + 4 + FLD(u16, p, 0) * 12;
    }
    self->model.flags.boxTest = 0;
    func_ov000_021915a0(&self->model);
    self->model.flags.visible = 1;
    NNS_G3dRenderObjSetInitFunc((NNSG3dRenderObj *)(&self->model.renderObj), (NNSG3dSbcCallBackFunc)func_ov015_022090fc);
    self->model.flags.clearInit = 0;
    self->model.flags.flushVP = 1;
    self->model.renderObj.ptrUser = &self->rot2[0].x;
    self->unk_3c = func_ov000_021909a8(&self->model, data_ov015_02212e14, data_ov015_02212e15);
    func_ov000_0218ffdc(&self->model2, &self->res2, 0, 1);
    n = FLD(Ov015Bits09500, func_0206fef8(self->id), 0x12).b5;
    if (n != 0) {
        func_ov000_02190cb0(&self->model2, data_ov015_02212db0.name, 0x1000, 0);
        func_ov000_02191618(&self->model2);
        func_ov000_02191690(&self->model2);
        func_ov000_02191318(&self->model2, n << 12);
    }
    self->model2.flags.boxTest = 0;
    self->model2.flags.visible = 1;
    self->shadow.prev = self->shadow.type;
    self->shadow.type = 3;
    self->pos.z = (0x800 - 0x37800) - FX_Mul(FX_Div(data_ov015_0221332c.unk_00, 0x3e8000), 0x73000);
    { s32 v = FLD(s16, func_0206fef8(self->info.id), 0x10); self->scaleX = v; self->scaleY = v; self->scaleZ = v; }
    if (self->hit.active != 0) func_0203f364(&self->hit);
    self->hit.group = 0x100;
    self->hit.mask = 0x100;
    self->unk_94 = FLD(s16, func_0206fef8(self->info.id), 0x16) << 4;
    self->unk_98 = FLD(s16, func_0206fef8(self->info.id), 0x14) << 4;
    m = (Ov015V *)Heap_Alloc(0x2c);
    if (m != NULL) m = (Ov015V *)Ov015FishState2c_Ctor((Ov015FishState2c *)m);
    self->state = m;
    self->stateId = 2;
    m->v08(self);
    return TRUE;
}

BOOL func_ov015_02209790(Ov015Fish *self, BOOL b) {
    func_ov000_02190a80(&self->model, self->animSpeed);
    func_ov000_02190a80(&self->model2, 0);
    if (!b) {
        return TRUE;
    }
    if (self->nextState != NULL) {
        void *saved;
        HEAP_PUSH(saved);
        DELETE_V(self->prevState);
        HEAP_POP(saved);
        self->state->v10(self);
        self->prevState = self->state;
        self->prevStateId = self->stateId;
        self->nextState->v08(self);
        self->state = self->nextState;
        self->stateId = self->nextStateId;
        self->nextState = NULL;
        self->nextStateId = 0;
    }
    if (self->state != NULL && !self->state->v0c(self)) {
        void *saved;
        Ov015V *o;
        self->state->v10(self);
        HEAP_PUSH(saved);
        DELETE_V(self->state);
        HEAP_POP(saved);
        o = self->prevState;
        self->state = o;
        self->stateId = self->prevStateId;
        o->v08(self);
        self->prevState = NULL;
        self->prevStateId = 0;
    }
    if (self->stateId != 5 && self->stateId != 6) {
        self->pos.z = (0x800 - 0x37800) - FX_Mul(FX_Div(data_ov015_0221332c.unk_00, 0x3e8000), 0x73000);
    }
    {
        s32 t = FX_Mul(FX_Div(self->pos.z + 0x37000, -0x73000), 0x3e8000);
        if (t <= 0x1f4000) {
            self->scaleMul = 0x1000;
        } else {
            self->scaleMul = FX_Mul(FX_Div(0x3e8000 - t, 0x1f4000), 0x666) + 0x99a;
        }
    }
    func_ov015_02209a50(self);
    self->hit.prev = self->hit.pos;
    self->hit.pos = self->pos;
    self->hit.radius = self->radius;
    func_0203f3d0(&self->hit);
    self->hit.unk_44 = data_02fe0f04;
    return TRUE;
}

void func_ov015_02209a50(Ov015Fish *self) {
    s32 f;
    if (self->pos.y > -0xa000) {
        self->unk_8c = 0x1000;
        if (self->shadowAlpha > 8) {
            self->shadowAlpha--;
        }
    } else if (self->pos.y > -0x32000) {
        s32 t = FX_Div(self->pos.y + 0x32000, 0x28000);
        s32 k;
        self->unk_8c = Interp_SinLerp(t, 0x666, 0x1000);
        k = (Interp_SinLerp(t, 0xa000, 0x16000) >> 12) & 0xff;
        if (self->shadowAlpha > k) {
            self->shadowAlpha--;
        } else if (self->shadowAlpha < k) {
            self->shadowAlpha++;
        }
    } else {
        self->unk_8c = 0x666;
        self->shadowAlpha = 10;
    }
    f = FX_Mul(self->unk_8c, FLD(s16, func_0206fef8(self->info.id), 0x10));
    self->unk_8c = f;
    self->radius = 0x28000;
    self->unk_84 = 0x1000;
    self->unk_88 = 0x32000;
    self->radius = FX_Mul(self->radius, f);
    self->unk_84 = FX_Mul(self->unk_84, f);
    self->unk_88 = FX_Mul(self->unk_88, f);
}

void func_ov015_02209b80(Ov015Fish *self, s32 a, s32 b) {
    self->nextState = (Ov015V *)a;
    self->nextStateId = b;
}

static inline void Ov015_UpdateMove(Ov015Fish *self) {
    u16 ang = FX_Atan2(self->dir.x, self->dir.z);
    Ov015Vec v;
    v = self->pos;
    v.y = 0;
    self->shadow.unk_10 = -0x1666;
    func_ov015_0220daf4(&self->shadow, &v, self->radius, self->unk_88, ang, 0);
    self->shadow.alpha = self->shadowAlpha;
}
void func_ov015_02209b8c(Ov015Fish *self) {
    switch (self->drawMode) {
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
    s32 k = self->scaleMul;
    s32 sx = FX_Mul(self->scaleX, k);
    s32 sy = FX_Mul(self->scaleY, k);
    s32 sz = FX_Mul(self->scaleZ, k);
    if (self->dir.x != 0 || self->dir.y != 0 || self->dir.z == 0) {
        *(Ov015Blk09c90 *)&up = data_ov015_02212644;
        VEC_Normalize((VecFx32 *)(&self->dir), (VecFx32 *)&z);
        Ov015_Cross09c90(&up, &z, &x);
        VEC_Normalize((VecFx32 *)&x, (VecFx32 *)&x);
        Ov015_Cross09c90(&z, &x, &up);
        VEC_Normalize((VecFx32 *)&up, (VecFx32 *)&up);
        self->rot[0] = x;
        self->rot[1] = up;
        self->rot[2] = z;
    }
    if (data_ov015_0221332c.unk_1d != 0 && self->stateId == 2) {
        self->model.color = 0x14bf;
        self->model.color2 = 0x5ad6;
        self->model.blend = 0xb;
        self->model.blendMax = 0xa;
        self->model2.color = 0x14bf;
        self->model2.color2 = 0x5ad6;
        self->model2.blend = 0xb;
        self->model2.blendMax = 0xa;
    }
    self->model.trans = *(Ov015VecC *)&self->pos;
    MI_Copy36B(&self->rot[0].x, &self->model.rot[0].x);
    self->model.scaleX = sx;
    self->model.scaleY = sy;
    self->model.scaleZ = sz;
    func_ov000_021903b4(&self->model);
    self->model2.trans = *(Ov015VecC *)&self->pos2;
    MI_Copy36B(&self->rot2[0].x, &self->model2.rot[0].x);
    func_ov000_021903b4(&self->model2);
    NNS_G3dGeFlushBuffer();
}

s32 func_ov015_02209fb8(s32 x) {
    s32 t = FX_Div(x + 0x37000, -0x73000);
    return (s32)(((s64)t * 0x3e8000 + 0x800) >> 12);
}

BOOL func_ov015_02209ff0(Ov015Fish *self, void *a) {
    BOOL r = FALSE;
    if (func_01ffc584(a, &self->pos, self->unk_98 + 0x4cd, self->unk_94)) r = TRUE;
    return r;
}

BOOL func_ov015_0220a028(Ov015Fish *self, void *a) {
    BOOL r = FALSE;
    if (func_01ffc584(a, &self->pos, self->unk_98, self->unk_94)) r = TRUE;
    return r;
}

void func_ov015_0220a058(Ov015Fish *self, void *out) {
    s32 z = FX_Mul(self->scaleX, 0xa000);
    Ov015Vec v;
    v.x = 0;
    v.y = 0;
    v.z = z;
    MTX_MultVec33((VecFx32 *)&v, (MtxFx33 *)(&self->rot2[0].x), (VecFx32 *)&v);
    VEC_Add((VecFx32 *)&v, (VecFx32 *)(&self->pos2), (VecFx32 *)out);
}

void *Ov015FishState2c_Ctor(Ov015FishState2c *self) {
    SET_VT(self, data_ov015_02212e94);
    self->step = 0;
    self->unk_06 = 0;
    self->unk_08 = 0;
    self->unk_0a = 0;
    self->unk_0c = 0;
    self->unk_10 = 0;
    self->unk_14 = 0;
    self->unk_16 = 0;
    self->unk_18 = 0;
    self->unk_1c = 0;
    self->fish = 0;
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
    self->fish = p;
    self->unk_06 = 0;
    self->unk_08 = 2;
    self->unk_0a = 0;
    self->unk_0c = p->info.unk_1c;
    p->unk_a8 = 0;
    p->unk_bc = 1;
    func_ov000_02190cb0(&p->model, data_ov015_02212e0d, 0x19a, 0);
    p->animSpeed = 0x800;
    func_ov000_021915a0(&p->model);
    self->step = 0;
    return TRUE;
}

}
