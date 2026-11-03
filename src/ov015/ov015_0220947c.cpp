#include "ov015/ov015.h"

extern "C" {

s32 ResSet_UpdateLoad(void *a);
s32 Shadow_UpdateLoad(void *a);
extern const Ov015ShipCfg data_ov015_02212db0;
extern u8 data_ov015_02212e0d[];
extern char data_ov015_02212e14[];
extern char data_ov015_02212e15[];
s32 Model_FindResIdxByName(void *a, const void *b, const void *c);
// The object record Tbl_FindEntry_0206fef8 returns (Main/Lang/TblEntry.cpp; Main/Res/Stage.cpp reads height).
typedef struct Ov015ObjInfo {
    u8 unk_00[0x10];
    s16 scale; // 0x10 fx scale of the model
    u16 unk_12_0 : 5;
    u16 unk_12_5 : 3; // nonzero: the second model plays data_ov015_02212db0's animation
    u16 unk_12_8 : 8;
    s16 unk_14;
    s16 height; // 0x16
} Ov015ObjInfo;

Ov015ObjInfo *Tbl_FindEntry_0206fef8(u16 id);
BOOL Model0218fe1c_SetRes(void *a, void *b, s32 c, s32 d);
BOOL Model0218fe1c_SetAnim(void *a, const void *b, s32 c, s32 d);
void Model0218fe1c_SetLoop(void *a);
void Model0218fe1c_ClearLoop(void *a);
void Model0218fe1c_PauseAnim(void *a);
void *Model0218fe1c_SetAnimFrame(void *a, s32 b);
void HitSphere_Unlink_0203f364(void *a);
void *Ov015FishState2c_Ctor(Ov015FishState2c *self);
void Model0218fe1c_UpdateAnim(void *a, s32 b);
void func_ov015_02209a50(Ov015Fish *self);
int func_0203f3d0(void *a);
extern u32 gHitSphereGroups;
s32 Interp_SinLerp(s32 t, s32 a, s32 b);
void func_ov015_02209c90(Ov015Fish *self);
void Ov015Shadow_DrawAt(Ov015Shadow *a, Ov015Vec *pos, s32 b, s32 c, s32 ang, s32 d);
BOOL Model021903b4_Draw(void *a);
s32 Hit_DiffInCylinder(void *a, void *b, s32 c, s32 d);
extern u8 Ov015FishState2c_vtbl[];
extern u8 Ov015FishState_vtbl[];

static inline BOOL Ov015_IsIdle567(Ov015Fish *self) {
    BOOL r = TRUE;
    if (self->shadow.state != 3 && self->shadow.state != 0) r = FALSE;
    return r;
}
BOOL func_ov015_0220947c(Ov015Fish *self) {
    BOOL r = TRUE;
    if (self->res.unk_00 >= 0) {
        if (ResSet_UpdateLoad(&self->res) == 0) r = FALSE;
    }
    if (self->res2.unk_00 >= 0) {
        if (ResSet_UpdateLoad(&self->res2) == 0) r = FALSE;
    }
    if (!Ov015_IsIdle567(self)) {
        if (Shadow_UpdateLoad(&self->shadow) == 0) r = FALSE;
    }
    return r;
}

BOOL func_ov015_02209500(Ov015Fish *self) {
    u8 *p;
    u32 n;
    VObj *m;
    Model0218fe1c_SetRes(&self->model, &self->res, 0, 1);
    Model0218fe1c_SetAnim(&self->model, data_ov015_02212e0d, 0x1000, 0);
    p = NULL;
    if (self->res.evHandle != NULL) p = FLD(u8 *, self->res.evHandle, 0) + 8;
    self->model.evTable = p;
    if (p != NULL && FLD(u16, p, 2) == 0) {
        self->model.evData = p + 4 + FLD(u16, p, 0) * 12;
    }
    self->model.flags.boxTest = 0;
    Model0218fe1c_SetLoop(&self->model);
    self->model.flags.visible = 1;
    NNS_G3dRenderObjSetInitFunc((NNSG3dRenderObj *)(&self->model.renderObj), func_ov015_022090fc);
    self->model.flags.clearInit = 0;
    self->model.flags.flushVP = 1;
    self->model.renderObj.ptrUser = &self->rot2[0].x;
    self->unk_3c = Model_FindResIdxByName(&self->model, data_ov015_02212e14, data_ov015_02212e15);
    Model0218fe1c_SetRes(&self->model2, &self->res2, 0, 1);
    n = Tbl_FindEntry_0206fef8(self->id)->unk_12_5;
    if (n != 0) {
        Model0218fe1c_SetAnim(&self->model2, data_ov015_02212db0.name, 0x1000, 0);
        Model0218fe1c_ClearLoop(&self->model2);
        Model0218fe1c_PauseAnim(&self->model2);
        Model0218fe1c_SetAnimFrame(&self->model2, n << 12);
    }
    self->model2.flags.boxTest = 0;
    self->model2.flags.visible = 1;
    self->shadow.prev = self->shadow.type;
    self->shadow.type = 3;
    self->pos.z = (0x800 - 0x37800) - FX_Mul(FX_Div(data_ov015_0221332c.unk_00, 0x3e8000), 0x73000);
    { s32 v = Tbl_FindEntry_0206fef8(self->info.id)->scale; self->scale.x = v; self->scale.y = v; self->scale.z = v; }
    if (self->hit.active != 0) HitSphere_Unlink_0203f364(&self->hit);
    self->hit.group = 0x100;
    self->hit.mask = 0x100;
    self->unk_94 = Tbl_FindEntry_0206fef8(self->info.id)->height << 4;
    self->unk_98 = Tbl_FindEntry_0206fef8(self->info.id)->unk_14 << 4;
    m = (VObj *)Heap_Alloc(0x2c);
    if (m != NULL) m = (VObj *)Ov015FishState2c_Ctor((Ov015FishState2c *)m);
    self->state = m;
    self->stateId = 2;
    m->vfunc_08(self);
    return TRUE;
}

BOOL func_ov015_02209790(Ov015Fish *self, BOOL b) {
    Model0218fe1c_UpdateAnim(&self->model, self->animSpeed);
    Model0218fe1c_UpdateAnim(&self->model2, 0);
    if (!b) {
        return TRUE;
    }
    if (self->nextState != NULL) {
        void *saved;
        HEAP_PUSH(saved);
        DELETE_V(self->prevState);
        HEAP_POP(saved);
        self->state->vfunc_10(self);
        self->prevState = self->state;
        self->prevStateId = self->stateId;
        self->nextState->vfunc_08(self);
        self->state = self->nextState;
        self->stateId = self->nextStateId;
        self->nextState = NULL;
        self->nextStateId = 0;
    }
    if (self->state != NULL && !self->state->vfunc_0c(self)) {
        void *saved;
        VObj *o;
        self->state->vfunc_10(self);
        HEAP_PUSH(saved);
        DELETE_V(self->state);
        HEAP_POP(saved);
        o = self->prevState;
        self->state = o;
        self->stateId = self->prevStateId;
        o->vfunc_08(self);
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
    self->hit.unk_44 = gHitSphereGroups;
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
    f = FX_Mul(self->unk_8c, Tbl_FindEntry_0206fef8(self->info.id)->scale);
    self->unk_8c = f;
    self->radius = 0x28000;
    self->unk_84 = 0x1000;
    self->unk_88 = 0x32000;
    self->radius = FX_Mul(self->radius, f);
    self->unk_84 = FX_Mul(self->unk_84, f);
    self->unk_88 = FX_Mul(self->unk_88, f);
}

void Ov015Fish_SetNextState(Ov015Fish *self, s32 a, s32 b) {
    self->nextState = (VObj *)a;
    self->nextStateId = b;
}

static inline void Ov015_UpdateMove(Ov015Fish *self) {
    u16 ang = FX_Atan2(self->dir.x, self->dir.z);
    Ov015Vec v;
    v = self->pos;
    v.y = 0;
    self->shadow.unk_10 = -0x1666;
    Ov015Shadow_DrawAt(&self->shadow, &v, self->radius, self->unk_88, ang, 0);
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
    s32 sx = FX_Mul(self->scale.x, k);
    s32 sy = FX_Mul(self->scale.y, k);
    s32 sz = FX_Mul(self->scale.z, k);
    if (self->dir.x != 0 || self->dir.y != 0 || self->dir.z == 0) {
        *(Ov015Blk09c90 *)&up = data_ov015_02212644;
        VEC_Normalize((&self->dir), &z);
        Ov015_Cross09c90(&up, &z, &x);
        VEC_Normalize(&x, &x);
        Ov015_Cross09c90(&z, &x, &up);
        VEC_Normalize(&up, &up);
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
    self->model.trans = *(Ov015Vec *)&self->pos;
    MI_Copy36B(&self->rot[0].x, &self->model.rot[0].x);
    self->model.scale.x = sx;
    self->model.scale.y = sy;
    self->model.scale.z = sz;
    Model021903b4_Draw(&self->model);
    self->model2.trans = *(Ov015Vec *)&self->pos2;
    MI_Copy36B(&self->rot2[0].x, &self->model2.rot[0].x);
    Model021903b4_Draw(&self->model2);
    NNS_G3dGeFlushBuffer();
}

s32 func_ov015_02209fb8(s32 x) {
    s32 t = FX_Div(x + 0x37000, -0x73000);
    return (s32)(((s64)t * 0x3e8000 + 0x800) >> 12);
}

BOOL func_ov015_02209ff0(Ov015Fish *self, void *a) {
    BOOL r = FALSE;
    if (Hit_DiffInCylinder(a, &self->pos, self->unk_98 + 0x4cd, self->unk_94)) r = TRUE;
    return r;
}

BOOL func_ov015_0220a028(Ov015Fish *self, void *a) {
    BOOL r = FALSE;
    if (Hit_DiffInCylinder(a, &self->pos, self->unk_98, self->unk_94)) r = TRUE;
    return r;
}

void Ov015Fish_GetFrontPos(Ov015Fish *self, void *out) {
    s32 z = FX_Mul(self->scale.x, 0xa000);
    Ov015Vec v;
    v.x = 0;
    v.y = 0;
    v.z = z;
    MTX_MultVec33(&v, (MtxFx33 *)(&self->rot2[0].x), &v);
    VEC_Add((VecFx32 *)&v, (VecFx32 *)(&self->pos2), (VecFx32 *)out);
}

void *Ov015FishState2c_Ctor(Ov015FishState2c *self) {
    SET_VT(self, Ov015FishState2c_vtbl);
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

void *Ov015FishState2c_Dtor(Ov015FishState2c *self) {
    SET_VT(self, Ov015FishState2c_vtbl);
    self->vfunc_10(0);
    SET_VT(self, Ov015FishState_vtbl);
    return self;
}

void *Ov015FishState2c_DtorDelete(Ov015FishState2c *self) {
    SET_VT(self, Ov015FishState2c_vtbl);
    self->vfunc_10(0);
    SET_VT(self, Ov015FishState_vtbl);
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
    Model0218fe1c_SetAnim(&p->model, data_ov015_02212e0d, 0x19a, 0);
    p->animSpeed = 0x800;
    Model0218fe1c_SetLoop(&p->model);
    self->step = 0;
    return TRUE;
}

}
