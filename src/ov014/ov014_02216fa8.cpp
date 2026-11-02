#include "ov014/ov014.h"
#include "nitro/mi.h"


// A header's zero rotation and vector, plus copies made at startup, next to this TU's name,
// scale and offsets. The pointer to the name and two offsets are read by other functions.
// The functions of 0x021fc220..0x021fcf00 (ov014_021fc220.cpp, merged in round dtB in its own
// namespace) are part of this TU: they read the name pointer and the zero vector through the
// .rodata base plus an offset, and name them (data_ov014_022164a0, data_ov014_022164d0) instead of
// an VecFx32 array view of data_ov014_022164a0.
// ov014_021fcf00.cpp (0x021fcf00..0x021fd2bc, which reads the name pointer) joined in round dtD.
extern const char *const data_ov014_022164a0;
extern const VecFx32 data_ov014_022164b8;
extern const VecFx32 data_ov014_022164c4;
extern char data_ov014_022171be[];
const char *const data_ov014_022164a0 = data_ov014_022171be;
static const VecFx16 data_ov014_022164a4 = {0, 0, 0};
const VecFx32 data_ov014_022164b8 = {0, FX32_ONE, 0};
static const VecFx32 data_ov014_022164ac = {FX32_ONE, FX32_ONE, FX32_ONE};
const VecFx32 data_ov014_022164c4 = {2 * FX32_ONE, 0, 0};
static const VecFx32 data_ov014_022164d0 = {0, 0, 0};
static const VecFx16 data_ov014_022171b8 = data_ov014_022164a4;
char data_ov014_022171be[] = "nut00";
static const VecFx32 data_ov014_022171c4 = data_ov014_022164d0;

// ---- merged from ov014_021fc220.cpp
namespace m_021fc220 {
extern "C" {

extern u8 data_ov014_0221722c[];
extern void HitSphere_Unlink_0203f364(ActorSub48 *p);

void Ov014ActEx_021fbd64_StateDie(Ov014ActEx_021fbd64 *self) {
    if (self->fsm->st == 0) {
        Ov003FxList_KillAll(self->unk_d0);
    }
    ActorEx_StateDie(self);
}

#pragma force_active on
Ov014ActEx_021fc24c *Ov014ActEx_021fc24c_Ctor(Ov014ActEx_021fc24c *self) {
    ActorEx_Ctor(self);
    *(void **)self = data_ov014_0221722c;
    self->unk_f8 = 0;
    self->unk_100 = NULL;
    self->unk_f4 = 0;
    self->unk_fd = 0;
    return self;
}
#pragma force_active reset

static inline void Ov014_Free100(Ov014ActEx_021fc24c *self) {
    void *saved = data_02097dd0->cur;
    data_02097dd0->cur = data_02097dd0->heapHi;
    if (self->unk_100 != NULL) {
        Ov003FxList *p = self->unk_100;
        if (p != NULL) {
            Ov003FxList_Dtor(p);
            Heap_Free(p);
        }
        self->unk_100 = NULL;
    }
    data_02097dd0->cur = saved;
}

Ov014ActEx_021fc24c *Ov014ActEx_021fc24c_Dtor(Ov014ActEx_021fc24c *self) {
    *(void **)self = data_ov014_0221722c;
    Ov014_Free100(self);
    ActorEx_DtorBase(self);
    return self;
}

Ov014ActEx_021fc24c *Ov014ActEx_021fc24c_DtorDelete(Ov014ActEx_021fc24c *self) {
    *(void **)self = data_ov014_0221722c;
    Ov014_Free100(self);
    ActorEx_DtorBase(self);
    Heap_Free(self);
    return self;
}

void Ov014ActEx_021fc24c_Start(Ov014ActEx_021fc24c *self) {
    Model0218fe1c *m;
    ActorEx_Start(self);
    self->unk_fc = self->unk_18;
    self->unk_dc = 0x1000;
    self->unk_e0 = 0x1000;
    self->unk_e4 = 0x1000;
    self->hit->unk_30 = 0;
    {
        ActorSub48 *s48 = self->hit;
        s48->unk_9a_0 = 0;
        s48->unk_9a_3 = 0;
        HitSphere_Unlink_0203f364(s48);
    }
    {
        ActorSub48 *s48 = self->hit;
        s48->unk_9a_2 = 0;
        s48->unk_9a_5 = 0;
    }
    self->unk_44->unk_1c = FX_Mul(self->radius, 0x2800);
    self->unk_100 = Ov014_NewFx();
    m = self->model;
    {
        s32 y = m->scale.y;
        s32 z = m->scale.z;
        self->unk_e8.x = m->scale.x;
        self->unk_e8.y = y;
        self->unk_e8.z = z;
    }
    Ov014_VecCopy(&m->scale, &data_ov014_022164d0);
    History_SetState(self->fsm, 1, 0);
}

extern VecFx32 data_ov014_022164dc;
extern Ov003Actor *ActorMgr_FindKind(void *mgr, u16 a, u16 b);
extern void *SndMgr_PlayAt(void *a, s32 b, VecFx32 *c, s32 d);

#define OV014_SQRTCNT (*(volatile u16 *)0x40002b0)
#define OV014_SQRT_RESULT (*(volatile u32 *)0x40002b4)
#define OV014_SQRT_PARAM (*(volatile u64 *)0x40002b8)

static inline s32 Ov014f_FxMul64(s32 a, s64 b) {
    return (a * b + 0x800) >> 12;
}

void Ov014ActEx_021fc24c_StateIdle(Ov014ActEx_021fc24c *self) {
    switch (self->unk_fc) {
    case 0: {
        ActorSub40 *s = self->fsm;
        switch (s->st) {
        case 0: {
            EffectObj *e;
            s32 r;
            s32 dx;
            s32 dz;
            u16 a;
            e = Effect_SpawnId(0x322, &self->pos);
            e->speed = 0x2000;
            Ov003FxList_Add(self->unk_100, 0, e);
            {
                VecFx32 v = {0, 0, 0};
                v.x = Rand_PlusMinus(0x9000);
                v.z = Rand_PlusMinus(0x259a);
                VEC_Add(&v, &data_ov014_022164dc, &self->unk_d0);
            }
            {
                s64 sq;
                dx = self->pos.x - self->unk_d0.x;
                dz = self->pos.z - self->unk_d0.z;
                sq = (s64)dx * dx;
                sq += (s64)dz * dz;
                OV014_SQRTCNT = 1;
                OV014_SQRT_PARAM = (u64)(sq * 4);
            }
            while (OV014_SQRTCNT & 0x8000) {
            }
            r = (s32)(OV014_SQRT_RESULT + 1) >> 1;
            a = FX_Atan2(r, self->unk_d0.y - self->pos.y);
            self->speed = Ov014f_FxMul64(OV014_SIN(a), 0x4cd);
            self->velY = Ov014f_FxMul64(OV014_COS(a), 0x4cd);
            self->rot_x = FX_Atan2(self->pos.y - self->unk_d0.y, r);
            self->fsm->st++;
            break;
        }
        case 1:
            self->unk_f4 += 0xcd;
            if (self->unk_f4 >= self->unk_e8.x) {
                self->unk_f4 = self->unk_e8.x;
                s->st++;
            }
            {
                Model0218fe1c *m = self->model;
                s32 f = self->unk_f4;
                m->scale.x = f;
                m->scale.y = f;
                m->scale.z = f;
            }
            break;
        case 2:
            if (!Ov003FxList_Has(self->unk_100, 0)) {
                ActorSub44 *n = self->unk_44;
                n->unk_22_0 = true;
                n->unk_22_1 = true;
                History_SetState(self->fsm, 0xb, 0);
            }
            break;
        }
        break;
    }
    case 1: {
        ActorSub40 *s = self->fsm;
        switch (s->st) {
        case 0: {
            EffectObj *e;
            Ov003Actor *t;
            s32 r;
            s32 dx;
            s32 dz;
            u16 a;
            VEC_Add(&self->pos, &data_ov014_022164b8, &self->pos);
            e = Effect_SpawnId(0x322, &self->pos);
            e->SetScaleAll(0x2000);
            e->loopCount = -1;
            Ov003FxList_Add(self->unk_100, 0xff, e);
            {
                ActorSub44 *n = self->unk_44;
                n->unk_22_0 = 0;
                n->unk_22_1 = 0;
            }
            t = data_ov000_021ccd68 != NULL ? ActorMgr_FindKind(data_ov000_021ccd68, 0x1000, 0x1000) : NULL;
            self->unk_d0.x = t->pos.x;
            self->unk_d0.y = t->pos.y;
            self->unk_d0.z = t->pos.z;
            {
                s64 sq;
                dx = self->pos.x - self->unk_d0.x;
                dz = self->pos.z - self->unk_d0.z;
                sq = (s64)dx * dx;
                sq += (s64)dz * dz;
                OV014_SQRTCNT = 1;
                OV014_SQRT_PARAM = (u64)(sq * 4);
            }
            while (OV014_SQRTCNT & 0x8000) {
            }
            r = (s32)(OV014_SQRT_RESULT + 1) >> 1;
            a = FX_Atan2(r, self->unk_d0.y - self->pos.y);
            self->speed = Ov014f_FxMul64(OV014_SIN(a), 0x4cd);
            self->velY = Ov014f_FxMul64(OV014_COS(a), 0x4cd);
            self->rot_x = FX_Atan2(self->pos.y - self->unk_d0.y, r);
            SndMgr_PlayAt(data_02097e4c, 0x5b, &self->pos, 0);
            SndMgr_PlayAt(data_02097e4c, 0x77, &self->pos, 0);
            self->fsm->st++;
            break;
        }
        case 1:
            self->unk_f4 += 0x52;
            if (self->unk_f4 >= self->unk_e8.x + 0x1000) {
                s->timer = 0;
                self->fsm->st++;
            }
            {
                Model0218fe1c *m = self->model;
                s32 f = self->unk_f4;
                m->scale.x = f;
                m->scale.y = f;
                m->scale.z = f;
            }
            {
                ActorSub40 *w = self->fsm;
                w->timer++;
                if (w->timer % 15 == 0) {
                    Model0218fe1c *m = self->model;
                    m->color = 0x7c1f;
                    m->color2 = 0x7c1f;
                    m->blend = 6;
                    m->blendMax = 5;
                }
            }
            break;
        case 2: {
            u16 t;
            s->timer++;
            t = s->timer;
            if (t > 100) {
                ActorSub44 *n = self->unk_44;
                n->unk_22_0 = true;
                n->unk_22_1 = true;
                self->fsm->timer = 0;
                History_SetState(self->fsm, 0xb, 0);
            }
            if (t % 15 == 0) {
                Model0218fe1c *m = self->model;
                m->color = 0x7c1f;
                m->color2 = 0x7c1f;
                m->blend = 6;
                m->blendMax = 5;
            }
            break;
        }
        }
        break;
    }
    }
    Ov003FxList_Prune(self->unk_100);
}


extern char data_ov014_02217209[];
extern char data_ov014_02217218[];
extern Ov003Actor *Target_Get(void *p);
extern void func_ov014_021fcf00(Ov014ActEx_021fc24c *self);
extern void *SndMgr_PlayAtPitch(void *a, s32 b, VecFx32 *c, s32 d);
extern s32 Actor_FindInRadius(Actor *self, u16 mask, VecFx32 *pos, s32 r, s32 a, Ov003Actor **list);
extern Ov003Actor *Obj021984c8_GetActor(Ov003Actor *p);
extern void Ov003Pickup_Update(Actor *self, s32 a);
extern void func_ov000_0218996c(s32 a, s32 b);
extern BOOL func_ov000_0219aca8(Actor *a, Actor *b, u16 c, u8 d, s32 e, s32 f, s32 g, s32 h, s32 i, s32 j);
extern Ov003Actor *Actor_GetTarget(Actor *self);

void Ov014ActEx_021fc24c_StateThrown(Ov014ActEx_021fc24c *self) {
    Ov003Actor *list[0x20];
    Ov003Actor *o = Target_Get(self->targetObj);
    if (o != NULL) {
        {
            ActorSub48 *m = o->hit;
            if (m != NULL && m->unk_9a_3) {
                m->unk_9a_3 = 0;
                HitSphere_Unlink_0203f364(m);
            }
        }
        if (o->kind == 0x1000) {
            func_ov014_021fcf00(self);
        } else {
            switch (self->fsm->st) {
            case 0: {
                ActorSub48 *m;
                Model0218fe1c_SetAnim(self->model, data_ov014_022164a0, 0x1000, 0);
                Model0218fe1c_SetLoop(self->model);
                m = self->hit;
                m->unk_50 = 0;
                m->unk_54 = 0;
                m->unk_58 = 0;
                if (self->unk_fc != 0) {
                    SndMgr_PlayAtPitch(data_02097e4c, 0x79, &self->pos, -10);
                }
                SndMgr_PlayAt(data_02097e4c, 0x32, &self->pos, 0);
                self->unk_fe = 0;
                self->fsm->st++;
            }
            case 1: {
                s32 rad;
                u16 team;
                s32 i;
                s32 n;
                if (self->unk_fc != 0) {
                    ActorSub40 *w;
                    Ov003FxList_Place(self->unk_100, 0xff, &self->pos, NULL, 0, 0, 0);
                    w = self->fsm;
                    w->timer++;
                    if (w->timer % 15 == 0) {
                        Model0218fe1c *m = self->model;
                        m->color = 0x7c1f;
                        m->color2 = 0x7c1f;
                        m->blend = 6;
                        m->blendMax = 5;
                    }
                }
                Actor_TurnToPos(self, &self->unk_d0, 0xcd);
                self->moveYaw = self->rot_y;
                Actor_Move(self, 0);
                self->unk_fe++;
                rad = self->radius;
                team = Target_Get(self->targetObj)->id & 0xf000;
                n = Actor_FindInRadius(self, (u16)~(1 << (team >> 12)), &self->pos, rad, 0, list);
                if (n != 0) {
                    for (i = 0; i < n; i++) {
                        Ov003Actor *a;
                        if (list[i] != NULL && (a = Obj021984c8_GetActor(list[i])) != NULL) {
                            if (a->targetObj == NULL || (u16)(a->targetObj->target & 0xf000) != team ||
                                self->unk_fe >= 200) {
                                if (self->unk_fc == 0) {
                                    Ov003Pickup_Update(self, 0);
                                }
                                History_SetState(self->fsm, 0x15, 0);
                                break;
                            }
                        }
                    }
                }
                Body_Update(self->hit, 1, 0, 0);
                if (self->hit->unk_50 & 0x20000000) {
                    ActorSub44 *q = self->unk_44;
                    ActorSub48 *m;
                    q->unk_22_0 = 0;
                    q->unk_22_1 = 0;
                    m = self->hit;
                    m->unk_9a_1 = 0;
                    m->unk_9a_4 = 0;
                    self->model->visible = 0;
                    func_ov000_0218996c(0x1e, 0x32);
                    self->unk_f8 |= 0x100000;
                    self->fsm->st++;
                }
                break;
            }
            case 2: {
                EffectObj *e;
                u8 k;
                e = Effect3D_Create(data_ov014_02217209, data_ov014_02217218, 0, &self->pos);
                e->SetScaleAll(0x8800);
                e->unk_28 = 0;
                MIi_CpuClear32(-1, (u8 *)e + 0x84, 0x40);
                Ov003FxList_Add(self->unk_100, 0xfe, e);
                SndMgr_PlayAt(data_02097e4c, 0x56, &self->pos, 0);
                SndMgr_PlayAt(data_02097e4c, 0x5a, &self->pos, 0);
                {
                    VecFx32 b2 = data_ov014_022164c4;
                    VecFx32 lv;
                    for (k = 0; k < 2; k++) {
                        Ov014_VecCopy(&lv, &b2);
                        if (k != 0) {
                            lv.x = -lv.x;
                        }
                        VEC_Add(&lv, &self->pos, &lv);
                        e = Effect_SpawnId(0x1f9, &lv);
                        e->SetScaleAll(0xb33);
                        MIi_CpuClear32(-1, (u8 *)e + 0x84, 0x40);
                    }
                }
                if (func_ov000_0219aca8(self, self, self->targetObj->unk_08, self->targetObj->unk_0a, 0, 0, 0x5ccd, 0, 0x6b, 0x1000)) {
                    Ov003Actor *t = Actor_GetTarget(self);
                    VecFx32 pp;
                    if (t != NULL) {
                        pp = t->pos;
                        SndMgr_PlayAt(data_02097e4c, 0x10, &pp, 0);
                    }
                }
                self->fsm->st++;
                break;
            }
            case 3:
                if (!Ov003FxList_Has(self->unk_100, 0xfe)) {
                    History_SetState(self->fsm, 0x15, 0);
                }
                break;
            }
        }
    } else {
        History_SetState(self->fsm, 0x15, 0);
        return;
    }
    Ov003FxList_Prune(self->unk_100);
}
}
}  // namespace m_021fc220

// ---- merged from ov014_021fcf00.cpp
namespace m_021fcf00 {
extern "C" {

extern Ov003Actor *Target_Get(void *p);
extern s32 Actor_FindInRadius(Actor *self, u16 mask, VecFx32 *pos, s32 r, s32 a, Ov003Actor **list);
extern Ov003Actor *Obj021984c8_GetActor(Ov003Actor *p);
extern void Ov003Pickup_Update(Actor *self, s32 a);

#define OV014_SQRTCNT (*(volatile u16 *)0x40002b0)
#define OV014_SQRT_RESULT (*(volatile u32 *)0x40002b4)
#define OV014_SQRT_PARAM (*(volatile u64 *)0x40002b8)

void func_ov014_021fcf00(Ov014ActEx_021fc24c *self) {
    VecFx32 d;
    Ov003Actor *list[0x20];
    switch (self->fsm->st) {
    case 0: {
        VecFx32 *p;
        s32 r;
        s32 dx;
        s32 dz;
        Model0218fe1c_SetAnim(self->model, data_ov014_022164a0, 0x1000, 0);
        Model0218fe1c_SetLoop(self->model);
        self->speed = 0;
        self->velY = 0;
        self->friction = 0;
        self->gravity = 0;
        p = Actor_GetTargetSub44(self);
        d = *p;
        self->unk_d0.x = d.x;
        self->unk_d0.y = d.y;
        self->unk_d0.z = d.z;
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
        d.x = FX_Mul(r, OV014_SIN(self->rot_y)) - 0x2000;
        d.z = FX_Mul(r, OV014_COS(self->rot_y));
        VEC_Normalize(&d, &d);
        self->speed = FX_Mul(d.x, 0x400);
        self->velY = FX_Mul(d.y, 0x400);
        self->friction = FX_Mul(d.z, 0x400);
        FX_Atan2(r, self->unk_d0.y - self->pos.y);
        self->rot_x = FX_Atan2(self->pos.y - self->unk_d0.y, r);
        {
            ActorSub48 *m = self->hit;
            m->unk_50 = 0;
            m->unk_54 = 0;
            m->unk_58 = 0;
        }
        self->unk_fe = 0;
        self->fsm->st++;
        break;
    }
    case 1: {
        s32 rad;
        s32 n;
        u16 team;
        s32 i;
        d = self->unk_d0;
        d.x -= 0x2000;
        Actor_TurnToPos(self, &d, 0xcd);
        VEC_Add(&self->pos, (VecFx32 *)&self->speed, &self->pos);
        self->unk_fe++;
        rad = self->radius + 0x4cd;
        if (rad < 0xccd) {
            rad = 0xccd;
        }
        self->hit->unk_44 = rad;
        team = Target_Get(self->targetObj)->id & 0xf000;
        n = Actor_FindInRadius(self, (u16)~(1 << (team >> 12)), &self->pos, rad, 0, list);
        if (n != 0) {
            for (i = 0; i < n; i++) {
                Ov003Actor *a;
                if (list[i] != NULL && (a = Obj021984c8_GetActor(list[i])) != NULL) {
                    if (a->targetObj == NULL || (u16)(a->targetObj->target & 0xf000) != team ||
                        ++self->unk_fe >= 200) {
                        Ov003Pickup_Update(self, 0);
                        History_SetState(self->fsm, 0x15, 0);
                        break;
                    }
                }
            }
        }
        Body_Update(self->hit, 1, 0, 0);
        if (self->hit->unk_50 & 1) {
            History_SetState(self->fsm, 0x15, 0);
        }
        break;
    }
    }
}

}
}  // namespace m_021fcf00
