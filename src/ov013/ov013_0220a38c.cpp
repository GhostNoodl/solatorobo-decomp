#include "ov013/ov013.h"

extern "C" {

extern void *data_ov013_0220bf4c;

struct Ov013Pair89 {
    u8 a;
    u8 b;
};

struct Ov013Sub50a {
    u8 unk_00[0x4];
    u16 unk_04;
    u8 unk_06[0x2];
    Ov013Pair89 unk_08;
};

static inline void Ov013_SetPair(Ov013Pair89 *d, const Ov013Pair89 *s, u8 b) {
    d->a = s->a;
    d->b = b;
}

void Ov013ActVt_0220bc80_StateKnockBack(Ov013ActVt_0220bc80 *self) {
    ActorSub40 *q;
    if ((((Ov013Sub50a *)self->hp)->unk_04 >> 12) == 5) {
        History_SetState(self->fsm, 0x15, 0);
        return;
    }
    q = self->fsm;
    if (q->st == 0) {
        Ov013Sub50a *p;
        self->unk_b8 = self->pos;
        p = (Ov013Sub50a *)self->hp;
        if ((u8)(p->unk_08.b + 0xf0) <= 1) {
            Ov013_SetPair(&p->unk_08, &p->unk_08, 0x20);
        }
    }
    Ov003Actor_StateKnockBack(self);
    if (self->fsm->current == 4) {
        History_SetState(self->fsm, 1, 0);
    }
}

void Ov013ActVt_0220bc80_StateHurt(Ov013ActVt_0220bc80 *self) {
    self->vfunc_80();
}

Ov013Act_02207968 *Ov013Act_02207968_DtorDelete(Ov013Act_02207968 *self) {
    Ov003Actor_DtorBase(self);
    Heap_Free(self);
    return self;
}

Ov013Act_02207968 *Ov013Act_02207968_Dtor(Ov013Act_02207968 *self) {
    Ov003Actor_DtorBase(self);
    return self;
}

void Ov013ActVt_0220bdd8_StateKnockBack(Ov013ActVt_0220bdd8 *self) {
    self->vfunc_7c();
}

Ov013ActVt_0220bdd8 *Ov013ActVt_0220bdd8_Dtor(Ov013ActVt_0220bdd8 *self) {
    Ov003Actor_DtorBase(self);
    return self;
}

Ov013ActVt_0220bdd8 *Ov013ActVt_0220bdd8_DtorDelete(Ov013ActVt_0220bdd8 *self) {
    Ov003Actor_DtorBase(self);
    Heap_Free(self);
    return self;
}

Ov013ActVt_0220bc80 *Ov013ActVt_0220bc80_Dtor(Ov013ActVt_0220bc80 *self) {
    Ov003Actor_DtorBase(self);
    return self;
}

Ov013ActVt_0220bc80 *Ov013ActVt_0220bc80_DtorDelete(Ov013ActVt_0220bc80 *self) {
    Ov003Actor_DtorBase(self);
    Heap_Free(self);
    return self;
}

Ov013ActEx_0220a4e0 *Ov013ActEx_0220a4e0_Ctor(Ov013ActEx_0220a4e0 *self) {
    ActorEx_Ctor(self);
    *(void **)self = &data_ov013_0220bf4c;
    self->unk_ce = 0;
    self->unk_d0 = 0;
    self->unk_d4.x = 0;
    self->unk_d4.y = 0;
    self->unk_d4.z = 0;
    return self;
}

void Ov013ActEx_0220a4e0_Start(Ov013ActEx_0220a4e0 *self) {
    ActorEx_Start(self);
    History_SetState(self->fsm, 0xb, 0);
    self->hit->offset.y = -0x800;
    self->hit->unk_48 = self->radius;
}

extern void *data_02097e4c;
extern char data_ov013_0220bfdc[];
extern Ov003Actor *ActorMgr_GetActor(void *mgr, u16 id);
extern void HitSphere_Link(void *p);
extern Ov003Actor *ActorMgr_FindPlayer(void);
extern BOOL func_ov000_021b4738(Ov003Actor *a);
extern Ov003Actor *Actor_SpawnKind(s32 kind, VecFx32 *pos, u16 *rot, u16 id, u16 owner);
extern void *SndMgr_PlayAt(void *a, s32 b, VecFx32 *c, s32 d);
extern BOOL Hit_ApplyInArea(void *a, void *b, u16 c, u8 d, u16 mask, VecFx32 *v, s32 e, s32 f, s32 g, s32 h, s32 i);

#define OV013_SQRTCNT (*(volatile u16 *)0x40002b0)
#define OV013_SQRT_RESULT (*(volatile u32 *)0x40002b4)
#define OV013_SQRT_PARAM (*(volatile u64 *)0x40002b8)

static inline s32 Ov013_Sqrt2(s64 sq) {
    OV013_SQRTCNT = 1;
    OV013_SQRT_PARAM = (u64)(sq << 2);
    while (OV013_SQRTCNT & 0x8000) {
    }
    return (s32)(OV013_SQRT_RESULT + 1) >> 1;
}

static inline s32 Ov013_DistXZ3(const VecFx32 *a, const VecFx32 *b) {
    s32 dz = a->z - b->z;
    s32 dx = a->x - b->x;
    s64 sq = (s64)dx * dx;
    sq += (s64)dz * dz;
    return Ov013_Sqrt2(sq);
}

static inline Ov003Actor *Ov013_GetActor(u16 id) {
    if (data_ov000_021ccd68 == NULL) {
        return NULL;
    }
    return ActorMgr_GetActor(data_ov000_021ccd68, id);
}

void Ov013ActEx_0220a4e0_StateThrown(Ov013ActEx_0220a4e0 *self) {
    if (Ov013_GetActor(self->target) == NULL) {
        return;
    }
    switch (self->fsm->st) {
    case 0: {
        s32 d;
        u16 ang;
        Model0218fe1c_SetAnim(self->model, data_ov013_0220bfdc, 0x1000, 0);
        Model0218fe1c_SetLoop(self->model);
        self->speed = 0;
        self->velY = 0;
        self->friction = 0;
        self->gravity = 0;
        d = Ov013_DistXZ3(&self->pos, &self->unk_d4);
        ang = FX_Atan2(d, self->unk_d4.y - self->pos.y);
        self->speed = FX_Mul(OV013_SIN(ang), 0x214);
        self->velY = FX_Mul(OV013_COS(ang), 0x214);
        self->rot_x = FX_Atan2(self->pos.y - self->unk_d4.y, d);
        self->moveYaw = self->rot_y;
        self->unk_ce = 0x12c;
        if (self->hit != NULL) {
            ActorSub48 *m;
            self->hit->unk_30 = 0;
            m = self->hit;
            m->unk_9a_0 = 1;
            m->unk_9a_3 = 1;
            HitSphere_Link(m);
            if (self->unk_d0 != 0) {
                self->hit->radius = FX_Mul(self->unk_d0, self->radius);
            }
        }
        if (self->unk_44 != NULL) {
            ActorSub44 *n = self->unk_44;
            n->unk_22_0 = 1;
            n->unk_22_1 = 1;
        }
        self->fsm->st++;
    }
    case 1: {
        ActorSub48 *m;
        Actor_Move(self, 0);
        if (self->unk_ce-- == 0) {
            History_SetState(self->fsm, 10, 0);
            return;
        }
        m = self->hit;
        if (m == NULL) {
            return;
        }
        m->unk_9a_0 = 1;
        m->unk_9a_3 = 1;
        HitSphere_Link(m);
        Body_Update(self->hit, 1, 0, 0);
        if (self->hit->unk_50 & 0x20000000) {
            EffectObj *e = Effect_SpawnId(0x130, &self->pos);
            Ov003Actor *pl;
            e->SetScaleAll(self->unk_d0);
            pl = ActorMgr_FindPlayer();
            if (pl != NULL && !func_ov000_021b4738(pl)) {
                Ov013ActEx_0220a9a8 *a = (Ov013ActEx_0220a9a8 *)Actor_SpawnKind(0x4813, &self->pos, &self->rot_x, self->targetObj->target, self->target);
                if (a != NULL) {
                    a->unk_d4 = self->unk_d0;
                }
            }
            SndMgr_PlayAt(data_02097e4c, 0x35, &self->pos, 0);
            History_SetState(self->fsm, 10, 0);
            m = self->hit;
            m->unk_9a_1 = 0;
            m->unk_9a_4 = 0;
            self->speed = 0;
            return;
        }
        if (Hit_ApplyInArea(self, self, self->targetObj->unk_08, self->targetObj->unk_0a, 2, NULL, 0, self->radius, 0, 0x130, self->unk_d0 >> 1)) {
            History_SetState(self->fsm, 0x15, 0);
        }
        break;
    }
    }
}

}
