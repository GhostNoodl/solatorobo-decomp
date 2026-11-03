#include "ov014/ov014.h"

struct Ov014Mtx33 {
    s32 m[9];
};

static inline s32 Ov014_FxMul64(s32 a, s32 b) {
    return (s32)(((s64)a * b + 0x800) >> 12);
}

static inline void Ov014_VecScale(VecFx32 *v, s32 s) {
    v->x = FX_Mul(v->x, s);
    v->y = FX_Mul(v->y, s);
    v->z = FX_Mul(v->z, s);
}

static inline s32 Ov014_Approach(s32 cur, s32 target) {
    s32 d = target - cur;
    if ((d < 0 ? -d : d) > 0x29) {
        return cur + (s32)(((s64)d * 0x7b + 0x800) >> 12);
    }
    return cur;
}
extern "C" {

extern u8 data_ov014_02217fb0[];
extern void HitSphere_Unlink_0203f364(ActorSub48 *p);
extern Ov003Actor *Target_Get(void *p);
extern Ov003Actor *ActorMgr_FindPlayer(void);
extern s32 Actor_FindInRadius(Actor *self, u16 mask, VecFx32 *pos, s32 r, s32 a, Ov003Actor **list);
extern Ov003Actor *Obj021984c8_GetActor(Ov003Actor *p);

#pragma force_active on
Ov014ActEx_022142fc *Ov014ActEx_022142fc_Ctor(Ov014ActEx_022142fc *self) {
    ActorEx_Ctor(self);
    *(void **)self = data_ov014_02217fb0;
    self->unk_d0.x = 0;
    self->unk_d0.y = 0;
    self->unk_d0.z = 0;
    self->unk_dc = 0;
    self->unk_e0 = 0;
    return self;
}
#pragma force_active reset

Ov014ActEx_022142fc *Ov014ActEx_022142fc_Dtor(Ov014ActEx_022142fc *self) {
    ActorEx_DtorBase(self);
    return self;
}

Ov014ActEx_022142fc *Ov014ActEx_022142fc_DtorDelete(Ov014ActEx_022142fc *self) {
    ActorEx_DtorBase(self);
    Heap_Free(self);
    return self;
}

void Ov014ActEx_022142fc_Start(Ov014ActEx_022142fc *self) {
    ActorSub44 *n;
    ActorSub48 *m;
    ActorEx_Start(self);
    n = self->unk_44;
    n->unk_22_0 = 0;
    n->unk_22_1 = 0;
    self->unk_44->unk_1c = 0x4000;
    self->unk_44->unk_0c.y = 0x4cd;
    m = self->hit;
    m->unk_9a_0 = 0;
    m->unk_9a_3 = 0;
    HitSphere_Unlink_0203f364(m);
    self->hit->unk_4c = 0x28000;
    History_SetState(self->fsm, 0xb, 0);
}

void Ov014ActEx_022142fc_Draw(Ov014ActEx_022142fc *self) {
    ActorEx_Draw(self);
}

BOOL func_ov014_022143f4(Actor *self) {
    Ov003Actor *list[0x20];
    BOOL r = FALSE;
    Ov003Actor *o;
    Ov003Actor *p;
    u16 k;
    s32 i;
    u16 mask;
    s32 rad;
    s32 n;
    o = Target_Get(self->targetObj);
    p = ActorMgr_FindPlayer();
    k = o->id & 0xf000;
    mask = ~(1 << (k >> 12));
    rad = self->radius;
    if (o->kind == 0x1000) {
        rad = rad + 0x4cd;
    } else if (p != NULL && ((Robo021ca458 *)p)->unk_b1e == self->id) {
        rad >>= 1;
    }
    n = Actor_FindInRadius(self, mask, &self->pos, rad, 0, list);
    if (n != 0) {
        for (i = 0; i < n; i++) {
            Ov003Actor *q;
            if (list[i] != NULL && (q = Obj021984c8_GetActor(list[i])) != NULL && q->kind != self->kind) {
                ActorSub4c *s = q->targetObj;
                if (s == NULL || k != (u16)(s->target & 0xf000)) {
                    r = TRUE;
                    break;
                }
            }
        }
    }
    return r;
}

extern char data_ov014_02218040[];
extern char data_ov014_0221804f[];
extern char data_ov014_0221805b[];
extern Actor *Actor_GetTarget(Actor *self);
extern void func_ov014_02214f10(Actor *self);
extern void HitSphere_Link(ActorSub48 *p);
extern BOOL Hit_ApplyInArea(void *a, void *b, u16 c, u8 d, u16 e, VecFx32 *v, s32 f, s32 g, s32 h, s32 i, s32 j);
extern void Field_ShakeCamera(u8 a, u8 b);

void Ov014ActEx_022142fc_StateThrown(Ov014ActEx_022142fc *self) {
    Ov014Mtx33 m;
    VecFx32 q;
    VecFx32 w;
    Ov014Mtx33 t;
    VecFx32 v;
    VecFx32 v2;
    Ov003Actor *o;
    ActorSub40 *st;
    o = Target_Get(self->targetObj);
    Actor_GetTarget(self);
    if (o == NULL) {
        History_SetState(self->fsm, 0x15, 0);
        return;
    }
    if (o->kind == 0x1000) {
        func_ov014_02214f10(self);
        return;
    }
    st = self->fsm;
    switch (st->st) {
    case 0: {
        BOOL set;
        u16 rz;
        u16 ry;
        u16 rx;
        Ov014_VecCopy(&self->unk_d0, &self->unk_84);
        self->unk_d0.x += Rand_PlusMinus(0x800);
        self->unk_d0.y += 0x14000;
        self->unk_d0.z += Rand_PlusMinus(0x800);
        ry = self->rot_y;
        rz = self->rot_z;
        rx = self->rot_x;
        set = FALSE;
        MTX_Identity33_((MtxFx33 *)&m);
        if (ry != 0) {
            MTX_RotY33_((MtxFx33 *)&m, OV014_SIN(ry), OV014_COS(ry));
            set = TRUE;
        }
        if (rx != 0) {
            if (set) {
                MTX_RotX33_((MtxFx33 *)&t, OV014_SIN(rx), OV014_COS(rx));
                MTX_Concat33((MtxFx33 *)&t, (MtxFx33 *)&m, (MtxFx33 *)&m);
            } else {
                MTX_RotX33_((MtxFx33 *)&m, OV014_SIN(rx), OV014_COS(rx));
                set = TRUE;
            }
        }
        if (rz != 0) {
            if (set) {
                MTX_RotZ33_((MtxFx33 *)&t, OV014_SIN(rz), OV014_COS(rz));
                MTX_Concat33((MtxFx33 *)&t, (MtxFx33 *)&m, (MtxFx33 *)&m);
            } else {
                MTX_RotZ33_((MtxFx33 *)&m, OV014_SIN(rz), OV014_COS(rz));
                set = TRUE;
            }
        }
        self->friction = 0x1000;
        self->speed = 0;
        self->velY = 0;
        MTX_MultVec33((VecFx32 *)&self->speed, (MtxFx33 *)&m, (VecFx32 *)&self->speed);
        self->unk_dc = 0x333;
        self->speed = FX_Mul(self->speed, self->unk_dc);
        self->velY = FX_Mul(self->velY, self->unk_dc);
        self->friction = FX_Mul(self->friction, self->unk_dc);
        SndMgr_PlayAt(data_02097e4c, 0x2b, &self->pos, 0);
        self->fsm->st++;
        self->fsm->timer = 0x14;
        break;
    }
    case 1:
        if (st->timer != 0) {
            FX_Div(st->timer << 12, 0x14000);
            VEC_Add((VecFx32 *)&self->speed, &self->pos, &self->pos);
            st = self->fsm;
            if (st->timer != 0) {
                st->timer--;
            }
            break;
        }
        SndMgr_PlayAt(data_02097e4c, 0x50, &self->pos, 0);
        self->fsm->st = 10;
        self->fsm->timer = 0;
        break;
    case 10:
        if (self->pos.y < self->unk_d0.y) {
            s32 s = self->unk_dc;
            self->velY += Ov014_FxMul64(s, 0x19a);
            self->unk_dc = Ov014_Approach(s, 0x666);
            VEC_Normalize((VecFx32 *)&self->speed, (VecFx32 *)&self->speed);
            Ov014_VecScale((VecFx32 *)&self->speed, self->unk_dc);
            VEC_Add((VecFx32 *)&self->speed, &self->pos, &self->pos);
            break;
        }
        st->st = 0x14;
    case 0x14: {
        s32 x = self->unk_d0.x;
        s32 y = self->unk_d0.y;
        s32 z = self->unk_d0.z;
        EffectObj *e;
        ActorSub44 *q4;
        ActorSub48 *q8;
        self->pos.x = x;
        self->pos.y = y;
        self->pos.z = z;
        self->speed = self->unk_84.x - x;
        self->velY = self->unk_84.y - y;
        self->friction = self->unk_84.z - z;
        self->unk_dc = 0;
        q4 = self->unk_44;
        q4->unk_22_0 = 1;
        q4->unk_22_1 = 1;
        q8 = self->hit;
        q8->unk_9a_0 = 1;
        q8->unk_9a_3 = 1;
        HitSphere_Link(q8);
        q.x = self->unk_84.x;
        q.y = self->unk_84.y;
        q.z = self->unk_84.z;
        q.y += 0xd9a;
        e = Effect3D_Create(data_ov014_02218040, data_ov014_0221804f, 0, &q);
        e->SetScaleXYZ(0x1ccd, 0xccd, 0x1ccd);
        e->speed = 0x1400;
        self->fsm->st++;
        break;
    }
    case 0x15: {
        s32 oldy;
        self->unk_dc = Ov014_Approach(self->unk_dc, 0x4cd);
        VEC_Normalize((VecFx32 *)&self->speed, (VecFx32 *)&self->speed);
        Ov014_VecScale((VecFx32 *)&self->speed, self->unk_dc);
        oldy = self->pos.y;
        VEC_Add((VecFx32 *)&self->speed, &self->pos, &self->pos);
        if (self->pos.y < 0xa000 && oldy >= 0xa000) {
            SndMgr_PlayAt(data_02097e4c, 0x32, &self->pos, 0);
            EffectObj *e = Effect_SpawnId(0x4b0, &self->pos);
            e->SetScaleXYZ(0x59a, 0x1333, 0x59a);
            e->SetRotXYZ(0x3fff, 0, 0);
            self->unk_e0 = e->id;
        }
        {
            EffectObj *e2 = Effect_Find_020657b0(data_0214a420, self->unk_e0);
            if (e2 != NULL) {
                e2->SetPos(&self->pos);
            }
        }
        if (self->hit->unk_50 & 0xe0000000) {
            self->fsm->st = 0x1e;
            self->fsm->timer = 0;
            break;
        }
        if (!func_ov014_022143f4(self)) {
            break;
        }
        {
            u16 mask;
            s32 r;
            Ov003Actor *a;
            r = self->radius + 0xccd;
            v.y = self->centerY;
            v.x = 0;
            v.z = 0;
            mask = 0;
            a = Target_Get(self->targetObj);
            if (a != NULL) {
                mask = ~(1 << ((u16)(a->id & 0xf000) >> 12));
            }
            mask &= (u16)~(1 << ((u16)(self->id & 0xf000) >> 12));
            Hit_ApplyInArea(self, a, self->targetObj->unk_08, self->targetObj->unk_0a, mask, &v, 0,
                                r, 0, 0x64, 0x1000);
        }
        self->targetObj->target = 0xffff;
        {
            s32 sc = self->radius;
            EffectObj *f = EffectGroup_Create(data_ov014_02218040, data_ov014_0221805b, &self->pos);
            f->SetScaleXYZ(sc, sc, sc);
        }
        History_SetState(self->fsm, 0x15, 0);
        break;
    }
    case 0x1e: {
        EffectObj *e;
        ActorSub44 *q4;
        self->model->visible = 0;
        q4 = self->unk_44;
        q4->unk_22_0 = 0;
        q4->unk_22_1 = 0;
        w.x = self->pos.x;
        w.y = self->pos.y;
        w.z = self->pos.z;
        w.y = self->hit->check.y;
        e = Effect3D_Create(data_ov014_02218040, data_ov014_0221804f, 0, &w);
        e->SetScaleXYZ(0x24cd, 0x299a, 0x24cd);
        SndMgr_PlayAt(data_02097e4c, 0x56, &w, 0);
        Field_ShakeCamera(0xc, 0x19);
        self->fsm->st++;
        self->fsm->timer = 0x14;
    }
    case 0x1f:
        if (!(self->fsm->timer & 3)) {
            u16 mask;
            Ov003Actor *a;
            a = Target_Get(self->targetObj);
            mask = 0xffff;
            if (a != NULL) {
                mask &= (u16)~(1 << ((u16)(a->id & 0xf000) >> 12));
            }
            mask &= (u16)~(1 << ((u16)(self->id & 0xf000) >> 12));
            v2.y = self->hit->check.y - self->pos.y;
            v2.x = 0;
            v2.z = 0;
            Hit_ApplyInArea(self, a, self->targetObj->unk_08, self->targetObj->unk_0a, mask, &v2, 0,
                                self->radius + 0xccd, 0x3000, 0x64, 0x1000);
        }
        st = self->fsm;
        if (st->timer != 0) {
            st->timer--;
        }
        if (st->timer != 0) {
            break;
        }
        History_SetState(self->fsm, 0x15, 0);
        break;
    }
}


#define OV014_SQRTCNT (*(volatile u16 *)0x40002b0)
#define OV014_SQRT_RESULT (*(volatile u32 *)0x40002b4)
#define OV014_SQRT_PARAM (*(volatile u64 *)0x40002b8)

static inline s32 Ov014k_FxMul64(s32 a, s64 b) {
    return (a * b + 0x800) >> 12;
}

void func_ov014_02214f10(Actor *self) {
    VecFx32 d;
    VecFx32 v;
    switch (self->fsm->st) {
    case 0: {
        VecFx32 *p;
        {
            ActorSub4c *q = self->targetObj;
            q->unk_50 = 0x1000;
            q->unk_54 = 0x29;
            q->unk_58 = 0;
        }
        self->hit->unk_30 = 0;
        p = Actor_GetTargetSub44(self);
        if (p != NULL) {
            s32 r;
            s32 dx;
            s32 dz;
            d = *p;
            d.y = d.y - self->pos.y;
            {
                s64 sq;
                dx = self->pos.x - d.x;
                dz = self->pos.z - d.z;
                sq = (s64)dx * dx;
                sq += (s64)dz * dz;
                OV014_SQRTCNT = 1;
                OV014_SQRT_PARAM = (u64)(sq * 4);
            }
            while (OV014_SQRTCNT & 0x8000) {
            }
            r = (s32)(OV014_SQRT_RESULT + 1) >> 1;
            d.x = FX_Mul(r, OV014_SIN(self->rot_y));
            d.z = FX_Mul(r, OV014_COS(self->rot_y));
            VEC_Normalize(&d, &d);
            self->speed = Ov014k_FxMul64(d.x, 0x39a);
            self->velY = Ov014k_FxMul64(d.y, 0x39a);
            self->friction = Ov014k_FxMul64(d.z, 0x39a);
        } else {
            self->speed = OV014_SIN(self->rot_y);
            self->friction = OV014_COS(self->rot_y);
            self->speed = Ov014k_FxMul64(self->speed, 0x39a);
            self->velY = Ov014k_FxMul64(self->velY, 0x39a);
            self->friction = Ov014k_FxMul64(self->friction, 0x39a);
        }
        {
            ActorSub48 *m = self->hit;
            m->unk_50 = 0;
            m->unk_54 = 0;
            m->unk_58 = 0;
        }
        self->fsm->st++;
        break;
    }
    case 1:
        VEC_Add(&self->pos, (VecFx32 *)&self->speed, &self->pos);
        if (!(self->hit->unk_50 & 0xe0000000)) {
            if (!func_ov014_022143f4(self)) {
                break;
            }
        }
        {
            u16 mask;
            s32 r;
            Ov003Actor *a;
            r = self->radius + 0xccd;
            v.y = self->centerY;
            v.x = 0;
            v.z = 0;
            mask = 0;
            a = Target_Get(self->targetObj);
            if (a != NULL) {
                mask = ~(1 << ((u16)(a->id & 0xf000) >> 12));
            }
            mask &= (u16)~(1 << ((u16)(self->id & 0xf000) >> 12));
            Hit_ApplyInArea(self, a, self->targetObj->unk_08, self->targetObj->unk_0a, mask, &v, 0,
                                r, 0, 0x64, 0x1000);
        }
        self->targetObj->target = 0xffff;
        {
            s32 sc = self->radius;
            EffectObj *f = EffectGroup_Create(data_ov014_02218040, data_ov014_0221805b, &self->pos);
            f->SetScaleXYZ(sc, sc, sc);
        }
        History_SetState(self->fsm, 0x15, 0);
        break;
    }
}

}
