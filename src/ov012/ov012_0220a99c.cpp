#include "ov012/ov012.h"


// A header's zero rotation and vector, plus copies made at startup, next to this TU's name and
// offsets. The pointer to the name and the two offsets are read by the functions of
// 0x02201c70..0x02202994 (ov012_02201c70.cpp, merged in round dtD in its own namespace).
extern const char *const data_ov012_0220a510;
extern const VecFx32 data_ov012_0220a51c;
extern const VecFx32 data_ov012_0220a528;
extern char data_ov012_0220aef6[];
const char *const data_ov012_0220a510 = data_ov012_0220aef6;
static const VecFx16 data_ov012_0220a514 = {0, 0, 0};
const VecFx32 data_ov012_0220a51c = {0, 0, 4 * FX32_ONE};
const VecFx32 data_ov012_0220a528 = {0, -2 * FX32_ONE, 4 * FX32_ONE};
static const VecFx32 data_ov012_0220a534 = {0, 0, 0};
static const VecFx16 data_ov012_0220aef0 = data_ov012_0220a514;
char data_ov012_0220aef6[] =
#include "romdata/ov012/0220aef6.inc"
;
static const VecFx32 data_ov012_0220aefc = data_ov012_0220a534;

// ---- merged from ov012_02201c70.cpp
namespace m_02201c70 {
extern "C" {
void Ov012ActorBase_UpdateSub44(Ov003Actor *self) {
    if (self->unk_44 != NULL) {
        Obj021984c8_UpdatePos(self->unk_44, 0, 0);
    }
}
}

extern "C" {
void Ov012Actor_UpdateHit(Ov003Actor *self) {
    if (self->hit != NULL) {
        ActorSub48_UpdatePos(self->hit, 0, 0);
    }
}
}

extern "C" {
void Ov012ActorBase_UpdateMode1(void) {
}
}

extern "C" {
void Ov012ActorBase_UpdateMode3(void) {
}
}

extern "C" {
void func_ov012_02201cb8(void) {
}
}

extern "C" {
void Ov012Actor_State25(void) {
}
}

extern "C" {
void Ov012Actor_State24(void) {
}
}

extern "C" {
void Ov012Actor_State23(void) {
}
}

extern "C" {
void Ov012Actor_State22(void) {
}
}

extern "C" {
void Ov012Actor_State21(void) {
}
}

extern "C" {
void Ov012Actor_State16(Ov003Actor *self) {
    self->vfunc_54();
}
}

extern "C" {
void Ov012Actor_Shoot2(Ov003Actor *self) {
    self->unk_ee_5 = 1;
    self->vfunc_70();
}
}

extern "C" {
void Ov012Actor_StateAttack3(Ov003Actor *self) {
    self->unk_ee_2 = 2;
    self->vfunc_64();
}
}

extern "C" {
void Ov012Act_021fee1c_StateAttack2(Ov003Actor *self) {
    self->unk_ee_2 = 1;
    self->vfunc_64();
}
}

extern "C" {
Ov012Act_021fee1c *Ov012Act_021fee1c_DtorDelete(Ov012Act_021fee1c *self) {
    Ov003Actor_DtorBase(self);
    Heap_Free(self);
    return self;
}
}

extern "C" {
Ov012Act_021fee1c *Ov012Act_021fee1c_Dtor(Ov012Act_021fee1c *self) {
    Ov003Actor_DtorBase(self);
    return self;
}
}

extern "C" {
extern const VecFx32 data_ov012_0220a54c[];
void Ov012ActExVt_0220af10_Start(Ov012ActExVt_0220af10 *self) {
    s16 t;
    Actor *p;
    ActorSub48 *m;
    ActorSub44 *n;
    ActorEx_Start(self);
    self->unk_e2 = self->unk_18;
    self->unk_bc = NULL;
    self->unk_de = 0;
    self->unk_e3 = 1;
    self->unk_dc = 10;
    self->unk_1a = Rand_UpTo(0x32) + 0x82;
    self->unk_1c = 0xb4;
    t = 0;
    if (self->unk_e2) {
        t = self->unk_e2 - Rand_UpTo(1);
    }
    self->unk_1e = t;
    p = Target_Get(self->targetObj);
    if (p != NULL) {
        self->unk_e0 = p->id;
    }
    VEC_Add(&self->pos, &data_ov012_0220a54c[self->unk_e2], &self->unk_84);
    {
        self->unk_d0 = self->unk_84;
    }
    self->hit->unk_30 = 0;
    m = self->hit;
    m->unk_9a_0 = 0;
    m->unk_9a_3 = 0;
    HitSphere_Unlink_0203f364(m);
    m = self->hit;
    m->unk_9a_1 = 0;
    m->unk_9a_4 = 0;
    m = self->hit;
    m->unk_9a_2 = 0;
    m->unk_9a_5 = 0;
    n = self->unk_44;
    n->unk_22_0 = 0;
    n->unk_22_1 = 0;
    History_SetState(self->fsm, 0xb, 0);
}
}

extern "C" {
void Ov012ActExVt_0220af10_Update(Ov012ActExVt_0220af10 *self) {
    Ov003Actor *o;
    ActorEx_Update(self);
    if (!(self->hit->unk_50 & 0x20000000)) {
        return;
    }
    if (self->fsm->current != 1) {
        return;
    }
    self->unk_e3 |= 4;
    self->target = 0xffff;
    o = (Ov003Actor *)ActorMgr_FindPlayer();
    if (o != NULL) {
        self->target = o->id;
    }
    self->targetObj->target = self->unk_e0;
    self->fsm->flags |= 0x800;
}
}

extern "C" {
extern const VecFx32 data_ov012_0220a540;
s32 Rand_Fx(void);
void ActorEx_StateThrown(ActorEx *self);
void Actor_PitchToPos(Actor *self, VecFx32 *target, s32 step);
BOOL Hit_ApplyInArea(void *a, void *b, u16 c, u8 d, s32 e, void *f, s32 g, s32 h, s32 i, s32 j, s32 k);

#define OV012_FXMUL_K(a, k) ((s32)(((s64)(a) * (k) + 0x800) >> 12))

static inline void Ov012_MoveTo(Ov012ActExVt_0220af10 *self, const VecFx32 *t, s32 k) {
    VecFx32 d;
    d.x = t->x - self->pos.x;
    d.y = t->y - self->pos.y;
    d.z = t->z - self->pos.z;
    VEC_MultAdd(k, &d, &self->pos, &self->pos);
}

static inline void Ov012_FxMid(Ov012ActExVt_0220af10 *self) {
    VecFx32 v;
    v.x = self->pos.x;
    v.y = self->pos.y;
    v.z = self->pos.z;
    v.y = v.y + (self->height >> 1);
    EffectObj *e = Effect_SpawnId(1, &v);
    e->SetScaleAll(self->radius + (self->radius >> 2));
}

void Ov012ActExVt_0220af10_StateThrown(Ov012ActExVt_0220af10 *self) {
    Ov003Actor *o;
    VecFx32 w;
    VecFx32 tp;
    s32 dist;
    ActorSub40 *s;
    o = (Ov003Actor *)Target_Get(self->targetObj);
    if (o == NULL) {
        return;
    }
    if (o->kind == 0x1000) {
        ActorSub4c *p = self->targetObj;
        p->unk_50 = 0x1000;
        p->unk_54 = 0x29;
        p->unk_58 = 0;
        self->hit->unk_30 = 0;
        ActorEx_StateThrown(self);
        return;
    }
    tp = Actor_GetTarget(self)->pos;
    dist = VEC_Distance(&self->pos, &tp);
    s = self->fsm;
    switch (s->st) {
    case 0:
        Model0218fe1c_SetAnim(self->model, data_ov012_0220a510, 0x1000, 0);
        Model0218fe1c_SetLoop(self->model);
        if (self->unk_e3 & 4) {
            self->unk_e3 ^= 4;
            self->hit->unk_30 = 0;
            self->unk_1c = 0xb4;
            self->fsm->timer = 0xb4;
            self->fsm->st = 6;
            return;
        }
        self->fsm->st++;
        self->fsm->timer = 0;
        break;
    case 1: {
        u16 t;
        Ov012_MoveTo(self, &self->unk_84, 0x19a);
        {
            ActorSub40 *q = self->fsm;
            q->timer++;
            t = q->timer;
        }
        if (t == 5) {
            EffectObj *e = Effect_SpawnId(0x68, &self->pos);
            e->SetRotXYZ(0x3fff, 0, 0);
            e->SetScaleAll(0xccd);
        }
        if (t >= 0x28) {
            self->fsm->st++;
        }
        break;
    }
    case 2: {
        if (s->timer != 0) {
            s->timer--;
        }
        if (s->timer == 0) {
            self->fsm->timer = 0x1e;
            self->unk_d0 = self->unk_84;
            self->unk_d0.x += Rand_Fx();
            self->unk_d0.y += Rand_Fx();
            self->unk_d0.z += Rand_Fx();
        }
        Ov012_MoveTo(self, &(self->unk_d0), 0xa4);
        if (self->unk_e3 & 2) {
            s16 b = self->unk_1e;
            s16 a = self->unk_1a;
            u16 c = self->unk_de++;
            u16 d = self->unk_dc;
            if (c == d + a * b) {
                ActorSub44 *n = self->unk_44;
                n->unk_22_0 = 1;
                n->unk_22_1 = 1;
                self->fsm->st = 4;
            }
            {
                VecFx32 v2 = data_ov012_0220a51c;
                Vec_RotateY(&v2, &v2, self->rot_y);
                VEC_Add(&self->pos, &v2, &v2);
                Actor_PitchToPos(self, &v2, 0x11f);
            }
        }
        if (self->unk_e3 & 2) {
            return;
        }
        {
            s16 b = self->unk_1e;
            s16 a = self->unk_1a;
            u16 c = self->unk_de++;
            u16 d = self->unk_dc;
            if (c != d + a * b) {
                return;
            }
        }
        self->unk_e3 |= 2;
        {
            const VecFx32 *b = &data_ov012_0220a54c[self->unk_e2];
            self->unk_84.x = self->unk_84.x - b->x;
            self->unk_84.y = self->unk_84.y - b->y;
            self->unk_84.z = self->unk_84.z - b->z;
            VecFx32 r2 = {Rand_PlusMinus(0x4000), Rand_PlusMinus(0x800), Rand_PlusMinus(0x4000)};
            VEC_Add(&r2, &data_ov012_0220a540, &r2);
            VEC_Add(&self->unk_84, &r2, &self->unk_84);
        }
        self->hit->unk_9a |= 0x12;
        SndMgr_PlayAt(gSndMgr, 0x50, &self->pos, 0);
        self->fsm->st++;
        break;
    }
    case 3: {
        s32 k;
        w.x = self->unk_84.x - self->pos.x;
        w.y = self->unk_84.y - self->pos.y;
        w.z = self->unk_84.z - self->pos.z;
        VEC_Normalize(&w, &w);
        w.x = OV012_FXMUL_K(w.x, 0x4cd);
        w.y = OV012_FXMUL_K(w.y, 0x4cd);
        w.z = OV012_FXMUL_K(w.z, 0x4cd);
        k = OV012_FXMUL_K(OV012_SINCOS[0x4e], 0xccd);
        if (self->unk_e2 % 2 == 0) {
            w.x = w.x - k;
        } else {
            w.x = w.x + k;
        }
        w.y = w.y + k;
        VEC_Add(&self->pos, &w, &self->pos);
        Actor_TurnToPos(self, &self->unk_84, 0x11f);
        if (VEC_Distance(&self->pos, &self->unk_84) < 0x800) {
            ActorSub48 *m = self->hit;
            m->unk_9a_0 = 1;
            m->unk_9a_3 = 1;
            HitSphere_Link((HitSphere *)m);
            self->unk_dc = 0x28;
            self->fsm->timer = 0;
            self->fsm->st = 2;
        }
        {
            VecFx32 v3 = data_ov012_0220a528;
            Vec_RotateY(&v3, &v3, self->rot_y);
            VEC_Add(&self->pos, &v3, &v3);
            Actor_PitchToPos(self, &v3, 0x11f);
        }
        break;
    }
    case 4: {
        Ov012_MoveTo(self, &tp, 0x3d);
        if (dist < 0x5000) {
            self->fsm->st++;
        }
        break;
    }
    case 5: {
        w.x = self->pos.x;
        w.y = self->pos.y;
        w.z = self->pos.z;
        w.y = -0x1000;
        Ov012_MoveTo(self, &w, 0x66);
        Body_Update(self->hit, 1, 0, 0);
        w.y = 0x333;
        if (VEC_Distance(&self->pos, &w) >= 0xcd) {
            return;
        }
        {
            ActorSub48 *m = self->hit;
            m->unk_9a_1 = 0;
            m->unk_9a_4 = 0;
        }
        self->fsm->st++;
        break;
    }
    case 6:
        if (dist >= 0x3000) {
            s->timer++;
            if (s->timer < 0xaa) {
                return;
            }
        }
        self->fsm->timer = 0xb4;
        Effect_SpawnId(4, &self->pos);
        SndMgr_PlayAt(gSndMgr, 0x78, &self->pos, 0);
        self->fsm->st++;
        break;
    case 7: {
        u16 t;
        if (s->timer != 0) {
            s->timer--;
        }
        t = s->timer;
        if (t <= 0x38) {
            self->unk_94_1 = 1;
        }
        if (t <= self->unk_1c) {
            Model0218fe1c *g = self->model;
            g->color = 0x14bf;
            g->color2 = 0x14bf;
            g->blend = 9;
            g->blendMax = 8;
            self->unk_1c = (self->unk_1c >> 3) * 7;
        }
        if (t == 0x38) {
            EffectObj *e = Effect_SpawnId(0x196, &self->pos);
            e->SetScaleAll(0x800);
            e->AddPosXYZ(0, 0x800, 0);
            SndMgr_PlayAt(gSndMgr, 0x44, &self->pos, 0);
        }
        if (t == 0) {
            self->fsm->st++;
        }
        break;
    }
    case 8: {
        Field_ShakeCamera(10, 0x14);
        Effect_SpawnId(5, &self->pos)->SetScaleAll(0x4000);
        Effect_SpawnId(0x6d, &self->pos)->SetScaleAll(0x2000);
        Ov012_FxMid(self);
        SndMgr_PlayAt(gSndMgr, 0x1a, &self->pos, 0);
        self->fsm->timer = 0;
        self->fsm->st++;
    }
    case 9: {
        ActorSub4c *p = self->targetObj;
        BOOL r = Hit_ApplyInArea(self, self, p->unk_08, p->unk_0a, 2, NULL, 0, 0x4000, 0, 100, 0x1000);
        self->model->alpha = 0;
        {
            ActorSub40 *q = self->fsm;
            q->timer++;
            if ((s32)q->timer < 0x14 && r == 0) {
                return;
            }
        }
        self->targetObj->target = 0xffff;
        Group_UpdateActor(gGroup, 0, self);
        self->vfunc_08();
        break;
    }
    }
}
}
}  // namespace m_02201c70
