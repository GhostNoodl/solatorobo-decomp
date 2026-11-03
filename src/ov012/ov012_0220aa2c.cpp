#include "ov012/ov012.h"
#include "Main/Math/Rot16.h"


// A header's zero rotation and vector, plus copies made at startup, around this TU's offsets
// and scale. Two of the offsets are read by the functions of 0x02206374..0x02207a38 (four files,
// merged in round dtD, each in its own namespace).
extern const VecFx32 data_ov012_0220a810;
extern const VecFx32 data_ov012_0220a81c;
static const VecFx16 data_ov012_0220a808 = {0, 0, 0};
static const VecFx32 data_ov012_0220a828 = {FX32_ONE, FX32_ONE, FX32_ONE};
const VecFx32 data_ov012_0220a81c = {0, 0, 9 * FX32_ONE};
static const VecFx32 data_ov012_0220a834 = {0, 0, 0};
const VecFx32 data_ov012_0220a810 = {0, 0, 2 * FX32_ONE};
static const VecFx16 data_ov012_0220b088 = data_ov012_0220a808;
static const VecFx32 data_ov012_0220b090 = data_ov012_0220a834;

// ---- merged from ov012_02206374.cpp
namespace m_02206374 {
extern "C" {
void Ov012ActExVt_0220b1e8_StateHeld(Ov012ActExVt_0220b1e8 *self) {
    if (Target_Get(self->targetObj)->kind == 0x1000 && self->fsm->st == 0 &&
        !(self->unk_d0 & 0x100000)) {
        u8 b = 2;
        ActorMgr_SendToKindOthers(0x5c03, self->kind, 6, 1, 1, &b);
    }
    ActorEx_StateHeld(self);
}
}

extern "C" {
void Ov012ActExVt_0220b1e8_StateFly(Ov012ActExVt_0220b1e8 *self) {
    History_SetState(self->fsm, 0x15, 0);
}
}

extern "C" {
void Ov012ActExVt_0220b1e8_StateDie(Ov012ActExVt_0220b1e8 *self) {
    EffectObj *e;
    if (self->unk_d0 & 0x100000) {
        if (self->unk_1a != 0) {
            return;
        }
        self->model->visible = 0;
        SndMgr_Stop(gSndMgr, 0x4f);
        e = Effect_SpawnId(4, &self->pos);
        e->SetScaleAll(0xe66);
        EffectObj_AddSndCue(e, 0x56, 0);
        Effect_SpawnId(0x6b, &self->pos);
        e = Effect_SpawnId(0x57c, &self->pos);
        e->SetScaleAll(0x1b33);
        EffectObj_AddSndCue(e, 0x79, 0);
        Field_ShakeCamera(10, 10);
        Group_UpdateActor(gGroup, 0, self);
        self->vfunc_08();
        self->unk_1a = 1;
    } else {
        ActorEx_StateDie(self);
    }
}
}

extern "C" {
void func_ov012_02206508(Ov012ActExVt_0220b1e8 *self) {
    u8 i;
    for (i = 1; i < 3; i++) {
        Ov012SpawnDesc d;
        Ov003Actor *o;
        Ov012Spawn_Init(&d, 0x4824);
        o = Group_SpawnActor(gGroup, &d, &self->pos, &self->rot_x, 0xffff);
        if (o != NULL) {
            void *p;
            o->flags_0 = 1;
            o->unk_18 = i;
            o->rot_y = self->rot_y;
            o->target = self->target;
            p = o->targetObj;
            if (p != NULL) {
                Target_Set(p, Target_Get(self->targetObj));
            }
        }
    }
}
}

extern "C" {
void Ov012ActExVt_0220b1e8_HitNearby(Ov012ActExVt_0220b1e8 *self) {
    void *list[0x20];
    s32 r = self->radius + 0x4cd;
    u16 k;
    s32 n;
    s32 i;
    if (r < 0xccd) {
        r = 0xccd;
    }
    self->hit->unk_44 = r;
    k = Target_Get(self->targetObj)->id & 0xf000;
    n = Actor_FindInRadius(self, ~(1 << (k >> 12)), &self->pos, r, 0, list);
    if (n == 0) {
        return;
    }
    for (i = 0; i < n; i++) {
        if (list[i] != NULL) {
            Actor *o = (Actor *)Obj021984c8_GetActor(list[i]);
            if (o != NULL) {
                ActorSub4c *p = o->targetObj;
                if (p == NULL || k != (u16)(p->target & 0xf000)) {
                    Ov003Pickup_Update(self, 0);
                    History_SetState(self->fsm, 0x15, 0);
                    return;
                }
            }
        }
    }
}
}

extern "C" {
void Ov012ActExVt_0220b150_Start(Ov012ActExVt_0220b150 *self) {
    ActorEx_Start(self);
    self->unk_dc = 0;
    self->unk_e0 = 0;
    self->unk_d0 = 0x1000;
    self->unk_d4 = 0x1000;
    self->unk_d8 = 0x1000;
    self->hit->unk_30 = 0;
    History_SetState(self->fsm, 0xb, 0);
}
}

extern "C" {
extern void func_ov012_02206bb0(Ov012ActExVt_0220b150 *self);
extern void Ov012ActExVt_0220b150_HitNearby(Ov012ActExVt_0220b150 *self);
extern BOOL func_ov000_0219aca8(Actor *a, Actor *b, u16 c, u8 d, s32 e, s32 f, s32 g, s32 h, s32 i, s32 j);

#define OV012U_SQRTCNT (*(volatile u16 *)0x40002b0)
#define OV012U_SQRT_RESULT (*(volatile u32 *)0x40002b4)
#define OV012U_SQRT_PARAM (*(volatile u64 *)0x40002b8)


static inline s32 Ov012_FxMul64(s32 a, s64 b) {
    return (s32)((a * b + 0x800) >> 12);
}

void Ov012ActExVt_0220b150_StateThrown(Ov012ActExVt_0220b150 *self) {
    Actor *m = Target_Get(self->targetObj);
    if (m == NULL) {
        return;
    }
    {
        ActorSub48 *q = m->hit;
        if (q != NULL && q->unk_9a_3) {
            q->unk_9a_3 = 0;
            HitSphere_Unlink_0203f364(q);
        }
    }
    if (m->kind == 0x1000) {
        func_ov012_02206bb0(self);
        return;
    }
    switch (self->fsm->st) {
    case 0: {
        VecFx32 v;
        s32 r;
        u16 a;
        Actor_GetTarget(self);
        Vec_RotateY(&v, &data_ov012_0220a810, self->rot_y);
        VEC_Add(&self->pos, &v, &self->unk_84);
        self->unk_84.y = 0;
        {
            s64 sq;
            s32 dx = self->pos.x - self->unk_84.x;
            s32 dz = self->pos.z - self->unk_84.z;
            sq = (s64)dx * dx;
            sq += (s64)dz * dz;
            OV012U_SQRTCNT = 1;
            OV012U_SQRT_PARAM = (u64)(sq * 4);
        }
        while (OV012U_SQRTCNT & 0x8000) {
        }
        r = (s32)(OV012U_SQRT_RESULT + 1) >> 1;
        a = FX_Atan2(r, self->unk_84.y - self->pos.y);
        self->speed = Ov012_FxMul64(FX_SinCosTable_[(a >> 4) * 2], 0x266);
        self->velY = Ov012_FxMul64(FX_SinCosTable_[(a >> 4) * 2 + 1], 0x266);
        self->rot_x = FX_Atan2(self->pos.y - self->unk_84.y, r);
        {
            ActorSub48 *q = self->hit;
            q->unk_50 = 0;
            q->unk_54 = 0;
            q->unk_58 = 0;
        }
        self->unk_e0 = 0;
        self->fsm->st++;
        return;
    }
    case 1:
        Actor_TurnToPos(self, &self->unk_84, 0x1000);
        self->moveYaw = self->rot_y;
        Actor_Move(self, 0);
        Ov012ActExVt_0220b150_HitNearby(self);
        Body_Update(self->hit, 1, 0, 0);
        if (self->hit->unk_50 & 0x20000000) {
            EffectObj *e;
            self->unk_dc |= 0x200000;
            {
                ActorSub44 *q = self->unk_44;
                q->unk_22_0 = 0;
                q->unk_22_1 = 0;
            }
            {
                ActorSub48 *q = self->hit;
                q->unk_9a_1 = 0;
                q->unk_9a_4 = 0;
            }
            self->model->visible = 0;
            Field_ShakeCamera(0x14, 0x1e);
            e = Effect_SpawnId(0x65, &self->pos);
            e->SetScaleAll(0x1800);
            EffectObj_AddSndCue(e, 0x56, 0);
            EffectObj_AddSndCue(e, 0x32, 5);
            self->fsm->st = 10;
        }
        if (++self->unk_e0 < 100) {
            return;
        }
        History_SetState(self->fsm, 0x15, 0);
        return;
    case 10: {
        EffectObj *e;
        self->pos.y = 0;
        e = Effect_SpawnId(0x66, &self->pos);
        e->speed = 0x800;
        self->unk_e4 = e->id;
        self->fsm->st++;
        return;
    }
    case 11: {
        EffectObj *e = Effect_Find_020657b0(gEffectMgr, self->unk_e4);
        ActorSub4c *p;
        if (e != NULL) {
            Rot16 r;
            self->unk_d0 += 0x19a;
            self->unk_d8 += 0x19a;
            e->SetScale((const VecFx32 *)&self->unk_d0); // unk_d0/d4/d8 are the scale x/y/z
            r = e->rot;
            r.y += 0xb6;
            e->SetRot(&r);
        }
        if (self->unk_d0 >= 0x4000 || e == NULL) {
            History_SetState(self->fsm, 0x15, 0);
        }
        p = self->targetObj;
        func_ov000_0219aca8(self, self, p->unk_08, p->unk_0a, 0, 0, Ov012_FxMul64(self->unk_d0, 0x1666), 0x1000, 100, 0x1000);
        return;
    }
    }
}
}
}  // namespace m_02206374

// ---- merged from ov012_02206bb0.cpp
namespace m_02206bb0 {
extern "C" {

extern void Ov012ActExVt_0220b150_HitNearby(Ov012ActExVt_0220b150 *self);

void func_ov012_02206bb0(Ov012ActExVt_0220b150 *self) {
    VecFx32 d;
    switch (self->fsm->st) {
    case 0: {
        VecFx32 *p;
        self->speed = 0;
        self->velY = 0;
        self->friction = 0;
        self->gravity = 0;
        p = Actor_GetTargetSub44(self);
        if (p != NULL) {
            s32 r;
            s32 dx;
            s32 dz;
            d = *p;
            self->unk_84.x = d.x;
            self->unk_84.y = d.y;
            self->unk_84.z = d.z;
            d.y = d.y - self->pos.y;
            {
                s64 sq;
                dx = self->pos.x - d.x;
                dz = self->pos.z - d.z;
                sq = (s64)dx * dx;
                sq += (s64)dz * dz;
                OV012_SQRTCNT = 1;
                OV012_SQRT_PARAM = (u64)(sq * 4);
            }
            while (OV012_SQRTCNT & 0x8000) {
            }
            r = (s32)(OV012_SQRT_RESULT + 1) >> 1;
            d.x = FX_Mul(r, OV012_SIN(self->rot_y));
            d.z = FX_Mul(r, OV012_COS(self->rot_y));
            VEC_Normalize(&d, &d);
            self->speed = FX_Mul(d.x, 0x4cd);
            self->velY = FX_Mul(d.y, 0x4cd);
            self->friction = FX_Mul(d.z, 0x4cd);
            FX_Atan2(r, self->unk_84.y - self->pos.y);
            self->rot_x = FX_Atan2(self->pos.y - self->unk_84.y, r);
            self->unk_dc |= 0x400000;
        } else {
            self->speed = 0x4cd;
            self->moveYaw = self->rot_y;
        }
        {
            ActorSub48 *m = self->hit;
            m->unk_50 = 0;
            m->unk_54 = 0;
            m->unk_58 = 0;
        }
        self->unk_e0 = 0;
        self->fsm->st++;
        break;
    }
    case 1:
        if (self->unk_dc & 0x400000) {
            Actor_TurnToPos(self, &self->unk_84, 0x1000);
            VEC_Add(&self->pos, (VecFx32 *)&self->speed, &self->pos);
        } else {
            Actor_Move(self, 0);
        }
        Ov012ActExVt_0220b150_HitNearby(self);
        Body_Update(self->hit, 1, 0, 0);
        if (self->hit->unk_50 & 1) {
            History_SetState(self->fsm, 0x15, 0);
        }
        if (++self->unk_e0 >= 100) {
            History_SetState(self->fsm, 0x15, 0);
        }
        break;
    }
}

}
}  // namespace m_02206bb0

// ---- merged from ov012_02206e9c.cpp
namespace m_02206e9c {
extern "C" {
void Ov012ActExVt_0220b150_StateFly(Ov012ActExVt_0220b150 *self) {
    History_SetState(self->fsm, 0x15, 0);
}
}

extern "C" {
void Ov012ActExVt_0220b150_StateDie(Ov012ActExVt_0220b150 *self) {
    if (self->unk_dc & 0x200000) {
        if (Effect_Find_020657b0(gEffectMgr, self->unk_e4) != NULL) {
            return;
        }
        Group_UpdateActor(gGroup, 0, self);
        self->vfunc_08();
    } else {
        ActorEx_StateDie(self);
    }
}
}

extern "C" {
void Ov012ActExVt_0220b150_HitNearby(Ov012ActExVt_0220b150 *self) {
    void *list[0x20];
    s32 r = self->radius + 0x4cd;
    u16 k;
    s32 n;
    s32 i;
    if (r < 0xccd) {
        r = 0xccd;
    }
    self->hit->unk_44 = r;
    k = Target_Get(self->targetObj)->id & 0xf000;
    n = Actor_FindInRadius(self, ~(1 << (k >> 12)), &self->pos, r, 0, list);
    if (n == 0) {
        return;
    }
    for (i = 0; i < n; i++) {
        if (list[i] != NULL) {
            Actor *o = (Actor *)Obj021984c8_GetActor(list[i]);
            if (o != NULL) {
                ActorSub4c *p = o->targetObj;
                if (p == NULL || k != (u16)(p->target & 0xf000)) {
                    Ov003Pickup_Update(self, 0);
                    History_SetState(self->fsm, 0x15, 0);
                    return;
                }
            }
        }
    }
}
}

extern "C" {
extern u8 Ov012ActEx_02207018_vtbl[];
#pragma force_active on
Ov012ActEx_02207018 *Ov012ActEx_02207018_Ctor(Ov012ActEx_02207018 *self) {
    ActorEx_Ctor(self);
    *(void **)self = Ov012ActEx_02207018_vtbl;
    self->unk_d0 = 0;
    self->fxList = NULL;
    return self;
}
#pragma force_active reset
}

extern "C" {
extern u8 Ov012ActEx_02207018_vtbl[];
Ov012ActEx_02207018 *Ov012ActEx_02207018_Dtor(Ov012ActEx_02207018 *self) {
    *(void **)self = Ov012ActEx_02207018_vtbl;
    Ov012_FreeFx(&self->fxList);
    ActorEx_DtorBase(self);
    return self;
}
}

extern "C" {
extern u8 Ov012ActEx_02207018_vtbl[];
Ov012ActEx_02207018 *Ov012ActEx_02207018_DtorDelete(Ov012ActEx_02207018 *self) {
    *(void **)self = Ov012ActEx_02207018_vtbl;
    Ov012_FreeFx(&self->fxList);
    ActorEx_DtorBase(self);
    Heap_Free(self);
    return self;
}
}

extern "C" {
void Ov012ActEx_02207018_Start(Ov012ActEx_02207018 *self) {
    ActorEx_Start(self);
    self->fxList = Ov012_NewFx();
    History_SetState(self->fsm, 0xb, 0);
}
}

extern "C" {
void Ov012ActEx_02207018_Update(Ov012ActEx_02207018 *self) {
    ActorEx_Update(self);
    Ov003FxList_Prune(self->fxList);
}
}
}  // namespace m_02206e9c

// ---- merged from ov012_0220717c.cpp
namespace m_0220717c {
extern "C" {

extern BOOL func_ov000_0219aca8(Actor *a, Actor *b, u16 c, u8 d, VecFx32 *e, s32 f, s32 g, s32 h, s32 i, s32 j);
extern const VecFx32 data_ov012_0220a840;


void Ov012ActEx_02207018_StateThrown(Ov012ActEx_02207018 *self) {
    void *list[0x20];
    VecFx32 off;
    VecFx32 d;
    VecFx32 v;
    switch (self->fsm->st) {
    case 0: {
        Model0218fe1c *g = self->model;
        EffectObj *e;
        Rot16 rr;
        s32 r;
        g->color = 0x1f;
        g->color2 = 0x1f;
        g->blend = 0x12d;
        g->blendMax = 0x12c;
        Vec_RotateY(&off, &data_ov012_0220a81c, self->rot_y);
        VEC_Add(&self->pos, &off, &d);
        d.y = 0;
        if (VEC_Distance(&self->pos, &d) < VEC_Distance(&self->pos, &self->unk_84)) {
            d.x = self->unk_84.x;
            d.y = self->unk_84.y;
            d.z = self->unk_84.z;
        }
        d.y = d.y - self->pos.y;
        {
            s32 dx;
            s32 dz;
            s64 sq;
            dx = self->pos.x - d.x;
            dz = self->pos.z - d.z;
            sq = (s64)dx * dx;
            sq += (s64)dz * dz;
            OV012_SQRTCNT = 1;
            OV012_SQRT_PARAM = (u64)(sq * 4);
        }
        while (OV012_SQRTCNT & 0x8000) {
        }
        r = (s32)(OV012_SQRT_RESULT + 1) >> 1;
        d.x = FX_Mul(r, OV012_SIN(self->rot_y));
        d.z = FX_Mul(r, OV012_COS(self->rot_y));
        VEC_Normalize(&d, &d);
        self->speed = FX_Mul(d.x, 0x400);
        self->velY = FX_Mul(d.y, 0x400);
        self->friction = FX_Mul(d.z, 0x400);
        self->rot_x = FX_Atan2(self->pos.y - self->unk_84.y, r);
        e = Effect_SpawnId(0x4b0, &self->pos);
        e->SetScaleAll(0x800);
        e->SetRot(&self->rot);
        e->alpha = FX_Div(0x1e000, 0x1f000);
        Ov003FxList_Add(self->fxList, 0xfa, e);
        e = Effect_SpawnId(0x25d, &self->pos);
        rr.x = self->rot_x + 0x7fff;
        rr.y = self->rot_y;
        rr.z = self->rot_z;
        e->SetRot(&rr);
        e->SetOffsetXYZ(0, 0, -0x800);
        e->SetScaleAll(0x2000);
        Ov003FxList_Add(self->fxList, 0xfa, e);
        {
            ActorSub48 *m = self->hit;
            m->unk_50 = 0;
            m->unk_54 = 0;
            m->unk_58 = 0;
        }
        self->fsm->st++;
        break;
    }
    case 1: {
        s32 r;
        u16 k;
        s32 n;
        s32 i;
        VEC_Add(&self->pos, (VecFx32 *)(&self->speed), &self->pos);
        r = self->radius + 0x4cd;
        if (r < 0xccd) {
            r = 0xccd;
        }
        self->hit->unk_44 = r;
        k = Target_Get(self->targetObj)->id & 0xf000;
        n = Actor_FindInRadius(self, ~(1 << (k >> 12)), &self->pos, r, 0, list);
        if (n != 0) {
            for (i = 0; i < n; i++) {
                Ov003Actor *q;
                if (list[i] != NULL && (q = (Ov003Actor *)Obj021984c8_GetActor(list[i])) != NULL) {
                    ActorSub4c *s = q->targetObj;
                    if (s == NULL || k != (u16)(s->target & 0xf000)) {
                        Ov003Pickup_Update(self, 0);
                        History_SetState(self->fsm, 0x15, 0);
                        break;
                    }
                }
            }
        }
        Ov003FxList_Place(self->fxList, 0xfa, &self->pos, 0, 0, 0, 0);
        Body_Update(self->hit, 1, 0, 0);
        if (self->hit->unk_50 & 0x60000000) {
            self->unk_d0 |= 0x200000;
            Ov003FxList_Kill(self->fxList, 0xfa);
            self->fsm->st = 10;
        }
        break;
    }
    case 10: {
        EffectObj *e;
        u8 i;
        self->pos.y = 0;
        self->model->visible = 0;
        SndMgr_PlayAt(gSndMgr, 0x1b, &self->pos, 0);
        Field_ShakeCamera(0x1e, 0x28);
        if (self->unk_18 == 0) {
            e = Effect_SpawnId(0x1f7, &self->pos);
            e->SetScaleAll(0xb33);
            MIi_CpuClear32(-1, (u8 *)e + 0x84, 0x40);
        }
        e = Effect_SpawnId(0x66, &self->pos);
        e->speed = 0x800;
        EffectObj_AddSndCue(e, 0x3e, 0);
        Ov003FxList_Add(self->fxList, 0xff, e);
        for (i = 0; i < 3; i++) {
            s32 a;
            s32 b;
            e = Effect_SpawnId(0x68, &self->pos);
            e->speed = 0x800;
            e->AddPosXYZ(0, 0x800, 0);
            e->SetScaleAll(0x1b33);
            a = Rand_UpTo(0xffff);
            b = Rand_UpTo(0xffff);
            e->SetRotXYZ((u16)a, (u16)b, 0);
            Ov003FxList_Add(self->fxList, (u8)(0xfd - i), e);
        }
        self->fsm->st++;
    }
    case 11: {
        EffectObj *e = Effect_SpawnId(5, &self->pos);
        e->AddPosXYZ(0, 0x800, 0);
        e->SetScaleAll(0x4000);
        e->alpha = FX_Div(0x1e000, 0x1f000);
        Ov003FxList_Add(self->fxList, 0xfe, e);
        self->fsm->st++;
        break;
    }
    case 12: {
        ActorSub40 *s = self->fsm;
        s->timer++;
        if (s->timer > 11) {
            self->fsm->timer = 0;
            self->fsm->st = 11;
        }
        break;
    }
    }
    if (self->fsm->st >= 11) {
        VecFx32 c = data_ov012_0220a840;
        EffectObj *o;
        u8 i;
        Rot16 rr;
        func_ov000_0219aca8(self, self, self->targetObj->unk_08, self->targetObj->unk_0a, &c, 0, 0x4000, 0, 100, 0x1000);
        o = Effect_Find_020657b0(gEffectMgr, Ov003FxList_Get(self->fxList, 0xff));
        if (o != NULL) {
            v = o->scale;
            v.x += 0x266;
            v.z += 0x266;
            o->SetScale(&v);
            func_ov000_0219aca8(self, self, self->targetObj->unk_08, self->targetObj->unk_0a, 0, 0, FX_Mul(v.x, 0x1666), 0x1000, 100, 0x1000);
            if (v.x >= 0x7800) {
                History_SetState(self->fsm, 0x15, 0);
            }
        } else {
            History_SetState(self->fsm, 0x15, 0);
        }
        for (i = 0; i < 3; i++) {
            o = Effect_Find_020657b0(gEffectMgr, Ov003FxList_Get(self->fxList, (u8)(0xfd - i)));
            if (o != NULL) {
                v = o->scale;
                v.x += 0xcd;
                o->SetScaleAll(v.x);
                rr.x = o->rot.x;
                rr.y = o->rot.y;
                rr.z = o->rot.z;
                rr.x += 0x38e;
                rr.y += 0x38e;
                o->SetRot(&rr);
            }
        }
    }
}

}
}  // namespace m_0220717c
