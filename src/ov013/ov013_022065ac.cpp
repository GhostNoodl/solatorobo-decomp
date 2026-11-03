#include "ov013/ov013.h"

extern "C" {

extern void *Ov013ActEx_022065ac_vtbl;
extern char data_ov013_0220b360[];
extern Ov003Actor *ActorMgr_FindPlayer(void);
extern BOOL Stage_UseScaledStats(void);

Ov013ActEx_022065ac *Ov013ActEx_022065ac_Ctor(Ov013ActEx_022065ac *self) {
    ActorEx_Ctor(self);
    *(void **)self = &Ov013ActEx_022065ac_vtbl;
    self->unk_f4 = 0;
    self->unk_f6 = 0;
    return self;
}

void Ov013ActEx_022065ac_SetF6(Ov013ActEx_022065ac *self, u16 a) {
    self->unk_f6 = a;
}

void Ov013ActEx_022065ac_SetF4(Ov013ActEx_022065ac *self, u8 a) {
    self->unk_f4 = a;
}

void Ov013ActEx_022065ac_StateThrown(Ov013ActEx_022065ac *self) {
    Ov003Shot_StateThrown(self);
    if (self->unk_f6 != 0) {
        self->rot_y += self->unk_f6;
    } else {
        self->rot_y = FX_Atan2(self->vel.x, self->vel.z);
    }
    if (self->unk_f4 != 0 && ((s32)self->unk_bc) != 0) {
        EffectObj *p = Effect_Find_020657b0(gEffectMgr, ((s32)self->unk_bc));
        if (p != NULL) {
            p->loopCount = -1;
        }
    }
}

Ov013ActEx_022065ac *Ov013ActEx_022065ac_Dtor(Ov013ActEx_022065ac *self) {
    Ov003ActorEx_Ctor(self);
    return self;
}

Ov013ActEx_022065ac *Ov013ActEx_022065ac_DtorDelete(Ov013ActEx_022065ac *self) {
    Ov003ActorEx_Ctor(self);
    Heap_Free(self);
    return self;
}

void Ov013ActVt_0220bdd8_Start(Ov013ActVt_0220bdd8 *self) {
    ActorSub48 *m;
    Ov003Actor *p;
    Ov003Actor_Start(self);
    self->pos.x = -0x3000;
    self->pos.y = 0x5333;
    self->pos.z = -0xe000;
    Ov013_VecSet(&self->hit->offset, 0, -0x1800, 0x5800);
    m = self->hit;
    m->unk_9a_1 = 0;
    m->unk_9a_4 = 0;
    self->hit->unk_9a_5 = 0;
    self->hit->unk_30 = 0;
    Ov013_VecSet(&self->unk_44->unk_0c, 0, -0x1800, 0x5800);
    self->target = 0xffff;
    p = ActorMgr_FindPlayer();
    if (p != NULL) {
        self->target = p->id;
    }
    self->unk_93_4 = 1;
    self->unk_b6 = 0x5a;
    self->unk_fe = 0x1000;
    if (Stage_UseScaledStats()) {
        Ov003Actor_ScaleStats(self, data_ov013_0220b360);
        self->unk_fe = 0x1800;
    }
}

extern Ov003Actor *ActorMgr_GetGroup(void *mgr, u16 id);
extern u16 ActorGroup_CountKind(Ov003Actor *a, u16 id);
extern BOOL History_HasState(ActorSub40 *a, u8 b, s32 c, BOOL d);
extern Ov003Actor *Actor_GetTarget(Actor *self);

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

void Ov013ActVt_0220bdd8_Update(Ov013ActVt_0220bdd8 *self);

#ifdef NONMATCHING
// Status (round auA): demoted in the honesty audit. The match wrote the local b as an unused trailing parameter and
// declared t `volatile` (register-allocation and scheduling levers). The score is in docs/UNMATCHED.md;
// the default build takes this function from the dsd gap. History: docs/MATCHING.md round auA.
void Ov013ActVt_0220bdd8_Update(Ov013ActVt_0220bdd8 *self) {
    Ov003Actor *b;
    BOOL ok;
    s32 n;
    s32 m;
    Ov003Actor *a;
    Ov003Actor *t;
    if (!Ov013_GameIdle()) {
        return;
    }
    if (self->fsm->current != 1) {
        return;
    }
    if (self->unk_b6 != 0) {
        self->unk_b6--;
    }
    if (self->unk_b6 != 0) {
        return;
    }
    a = ActorMgr_GetGroup(gActorMgr, 0x5000);
    b = ActorMgr_GetGroup(gActorMgr, 0x4000);
    ok = TRUE;
    if (a != NULL) {
        n = Rand_UpTo(9);
        m = 4;
        if (self->hp[0] < (self->hp[1] >> 1)) {
            m = 5;
        }
        if (ActorGroup_CountKind(a, 0x540c) >= 2 || History_HasState(self->fsm, 0x10, m, 1) || n == 0) {
            ok = FALSE;
        }
    }
    if (ok) {
        self->fsm->flags |= 0x10000;
    } else {
        ok = TRUE;
        n = (u16)(self->hp[0] * 100 / self->hp[1]);
        m = 0;
        t = Actor_GetTarget(self);
        if (t != NULL) {
            s32 dz = self->pos.z - t->pos.z;
            s32 dx = self->pos.x - t->pos.x;
            s64 sq = (s64)dx * dx;
            sq += (s64)dz * dz;
            m = Ov013_Sqrt2(sq);
            if (m < 0xd000) {
                ok = FALSE;
            }
        }
        if (ok && b != NULL) {
            s32 th = 0x1e;
            if (m > 0x11000) {
                th += 10;
            }
            if ((u32)n > 0x50) {
                th -= 0xf;
            }
            m = th;
            n = Rand_UpTo(n);
            if (ActorGroup_CountKind(b, 0x4813) >= 2 || n > m || History_HasState(self->fsm, 0xe, 2, 1)) {
                ok = FALSE;
            }
        }
        if (ok) {
            self->fsm->flags |= 0x4000;
        } else {
            self->fsm->flags |= 0x8000;
        }
    }
    self->unk_b6 = 0x5a;
}
#endif

}
