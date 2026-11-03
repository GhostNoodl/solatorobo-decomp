#include "types.h"
#include "Main/Math/Rot16.h"
#include "Main/Snd/SndMgr.h"
#include "Main/Effect/Effect.h"
#include "Main/Sys/FieldState.h"
#include "ov000/ActorParts.h"
#include "ov003/Unit.h"
#include "ov003/ActorApi.h"
#include "ov000/ActorMgr.h"
#include "Main/Res/StageRes.h"



struct Ov003Pair {
    u16 x;
    u16 y;
    Ov003Pair() {}
};

typedef struct {
    u8 unk_00;
    u8 unk_01;
    u8 unk_02;
    u8 unk_03;
    u16 unk_04;
    u16 unk_06;
    Ov003Pair unk_08;
    s32 unk_0c;
} Ov003PartA;

typedef struct {
    Ov003Pair unk_00;
    Ov003Pair unk_04;
} Ov003PartB;

typedef struct {
    Ov003PartA a;
    Ov003PartB b;
} Ov003PartSrc;

// The Target object (Actor::targetObj, ActorSub4c) as Ov003ActExSway_StateDie refills it from the spawn
// info record of Tbl_Elem_020704b4: the first 0x18 bytes are copied as two records.
typedef struct {
    Ov003PartA a;
    Ov003PartB b;
    u8 unk_18_0 : 1;
    u8 unk_18_1 : 1;
    u8 unk_19[3];
    u16 unk_1c;
} Ov003Part;

typedef struct {
    u8 unk_00[0x4c];
    u8 *unk_4c;
} Ov003Snd;

typedef struct {
    u8 unk_00[0x16];
    u8 unk_16_0 : 2;
    u8 unk_16_2 : 1;
    u8 unk_17[0x4d];
    s32 radius;
    u8 unk_68[4];
    s32 unk_6c;
    VecFx32 pos;
    u8 unk_7c[0x14];
    u16 unk_90;
    u8 unk_92;
    u8 unk_93_0 : 4;
    u8 unk_93_4 : 1;
    u8 unk_94[0xa90];
    u32 unk_b24_0 : 1;
    u32 unk_b24_1 : 1;
} Ov003Player;

typedef struct {
    s32 v[3];
} Ov003Ids;

extern "C" {

extern void *gGroup;
extern char data_ov003_021f995c[];
extern char data_ov003_021f9967[];
extern char data_ov003_021f996d[];
extern char data_ov003_021f9978[];
extern Ov003Player *ActorMgr_FindPlayer(void);
extern void ActorMarker_Draw(void *p);
extern BOOL Hit_DiffInSphere(VecFx32 *a, VecFx32 *b, s32 r);
extern u32 Rand_UpTo(u32 max);
extern void ResSet_SetFile(ActorRes *p, void *res, s32 a, s32 b, s32 c, s32 d);
extern BOOL ResSet_UpdateLoad(ActorRes *res);
extern BOOL Model0218fe1c_SetRes(Model0218fe1c *anim, ActorRes *res, s32 a, s32 b);
extern BOOL Model0218fe1c_SetAnim(void *model, const char *name, s32 a, s32 b);
extern void *Heap_Alloc(u32 size);
extern ActorSub4c *Target_Init(void *p);
extern void *func_0203db40(void *p);
extern void Model0218fe1c_UpdateAnim(void *a, void *b);
extern void Obj02190758_SetRot(Model0218fe1c *anim, Rot16 *rot, s32 a);
extern BOOL Model021903b4_Draw(Model0218fe1c *anim);
extern Ov003Unit *Group_FindNode(void *mgr, u16 id);
extern s32 DataRes_GetTable(Ov003Snd *s, s32 a);
extern u16 DataRes_ReadBitsAt_02059544(Ov003Snd *s, u8 *p, s32 a, s32 b, u16 c);
extern AnimCtrl *Model0218fe1c_GetAnimCtrl(Model0218fe1c *m, s32 a);
extern void Model0218fe1c_SetAnim3(Model0218fe1c *m, s32 a, s32 b, s32 c);
extern void HitSphere_Unlink_0203f364(ActorSub48 *ctl);
extern void Model0218fe1c_SetLoop(void *model);
extern void Model0218fe1c_SetAnimSpeed(void *model, s32 a);
extern s32 Rand_PlusMinus(s32 max);
extern u16 Angle_Approach(u16 target, u16 cur, s32 step, u32 a, u16 b);
extern char data_ov003_021f9983[];
extern char data_ov003_021f9989[];
extern s32 Hit_CastSegment(VecFx32 *a, VecFx32 *b, u32 c, s32 d, s32 e, s32 f);
extern void Body_Update(ActorSub48 *ctl, s32 a, s32 b, s32 c);
extern BOOL History_SetState(ActorSub40 *p, u8 a, BOOL b);

static inline BOOL Ov003Game_IsBusy(FieldState *g) {
    return g->head != g->tail;
}

static inline BOOL Ov003Game_IsIdle(FieldState *g) {
    if (Ov003Game_IsBusy(g)) {
        return FALSE;
    }
    if (g->state != 3) {
        return FALSE;
    }
    return TRUE;
}

static inline BOOL Ov003_GameIdle(void) {
    FieldState *g = gSceneCmd;
    if (g != NULL) {
        return Ov003Game_IsIdle(g);
    }
    return TRUE;
}







static inline BOOL Ov003_GameIdle2(void) {
    FieldState *g = gSceneCmd;
    if (g != NULL) {
        BOOL busy = FALSE;
        if (g->head != g->tail) {
            busy = TRUE;
        }
        if (busy) {
            return FALSE;
        }
        if (g->state != 3) {
            return FALSE;
        }
        return TRUE;
    }
    return TRUE;
}

extern void HitSphere_Link(ActorSub48 *ctl);
extern void Ov003Pickup_Update(ActorEx *self, s32 a);
extern const Ov003Ids data_ov003_021f6bcc;
extern void Group_UpdateActor(void *mgr, s32 a, void *obj);
extern Ov003PartSrc *Tbl_Elem_020704b4(u16 id);
extern void func_020627b4(void);
extern void Shared_SetEventActor(u16 a, u16 b);
extern void func_020627dc(s32 a);

static inline void Ov003Sub44_Clear(ActorSub44 *s) {
    if (s != NULL) {
        s->unk_22_0 = 0;
        s->unk_22_1 = 0;
    }
}

static inline void ActorSub48_Enable(Ov003ActExSway *self) {
    ActorSub48 *c = self->hit;
    if (c != NULL) {
        c->unk_9a_0 = 1;
        c->unk_9a_3 = 1;
        HitSphere_Link(c);
        self->hit->unk_9a |= 0x12;
    }
}

static inline void Ov003PartA_Copy(Ov003PartA *d, const Ov003PartA *s) {
    if (s != NULL) {
        d->unk_00 = s->unk_00;
        d->unk_01 = s->unk_01;
        d->unk_02 = s->unk_02;
        d->unk_03 = s->unk_03;
        d->unk_04 = s->unk_04;
        d->unk_06 = s->unk_06;
        d->unk_08 = s->unk_08;
        d->unk_0c = s->unk_0c;
    }
}

static inline void Ov003PartB_Copy(Ov003PartB *d, const Ov003PartB *s) {
    if (s != NULL) {
        d->unk_00 = s->unk_00;
        d->unk_04 = s->unk_04;
    }
}

static inline BOOL Ov003Game_HasEvent(FieldState *g, const s32 *ids) {
    s32 i = g->head;
    while (i != g->tail) {
        const s32 *p = ids;
        while (*p != 0) {
            if (*p++ == g->queue[i]) {
                return TRUE;
            }
        }
        i++;
        if (i >= 16) {
            i = 0;
        }
    }
    return FALSE;
}

static inline void Ov003PartA_Assign(Ov003PartA *d, const Ov003PartA *s) {
    if (s != NULL) {
        *d = *s;
    }
}

static inline void Ov003PartB_Assign(Ov003PartB *d, const Ov003PartB *s) {
    if (s != NULL) {
        *d = *s;
    }
}

void Ov003ActExSway_StateDie(Ov003ActExSway *self);

#ifdef NONMATCHING
// Status (round auA): demoted in the honesty audit. The match needed the pointer-bit trick (a second, never-taken
// definition of a local under if ((u32)self & 3)); this is the honest code without it. The score is in
// docs/UNMATCHED.md;
// the default build takes this function from the dsd gap. History: docs/MATCHING.md round auA.
void Ov003ActExSway_StateDie(Ov003ActExSway *self) {
    s32 sfxOn;
    if (self->hasModel) {
        EffectObj *fx;
        Ov003PartSrc *src;
        Ov003Part *p;
        ActorSub48 *c;
        self->hasModel = 0;
        fx = Effect_SpawnId(0x1f4, &self->pos);
        fx->SetScaleXYZ(0x1800, 0x1800, 0x1800);
        fx->AddPosXYZ(0, 0xccd, 0);
        Effect_SpawnId(0x44c, &self->pos)->AddPosXYZ(0, 0x2000, 0);
        SndMgr_PlayStrm(gSndMgr, Rand_UpTo(1) + 0x7c);
        src = Tbl_Elem_020704b4(self->kind);
        p = (Ov003Part *)self->targetObj;
        Ov003PartA_Assign(&p->a, &src->a);
        Ov003PartB_Assign(&p->b, &src->b);
        self->targetObj->unk_18_1 = 1;
        p = (Ov003Part *)self->targetObj;
        self->target = p->unk_1c;
        p->unk_1c = 0xffff;
        self->speed = 0x66;
        self->velY = 0x400;
        self->friction = 0;
        self->gravity = 0x52;
        c = self->hit;
        c->unk_50 = 0;
        c->unk_54 = 0;
        c->unk_58 = 0;
        History_SetState(self->fsm, 4, 1);
        c = self->hit;
        c->unk_9a_0 = 1;
        c->unk_9a_3 = 1;
        HitSphere_Link(c);
        self->hit->unk_9a |= 0x12;
        self->hit->radius = self->radius;
        func_020627b4();
        Shared_SetEventActor(self->kind, self->id);
        func_020627dc(0x8001);
        sfxOn = 1;
        gSceneCmd->stageFlags = sfxOn;
    } else {
        History_SetState(self->fsm, 4, 0);
    }
    Ov003Sub44_Clear(self->unk_44);
}
#endif

void Ov003ActExSway_State0a(Ov003ActExSway *self) {
    if (self->hasModel) {
        ActorSub48_Enable(self);
        History_SetState(self->fsm, 4, 0);
    } else {
        ActorEx_State0a(self);
    }
    Ov003Sub44_Clear(self->unk_44);
}

void Ov003ActExSway_StateHeld(Ov003ActExSway *self) {
    if (!self->hasModel && ++self->unk_30c == 30) {
        Ov003Ids ids = data_ov003_021f6bcc;
        if (!Ov003Game_HasEvent(gSceneCmd, ids.v)) {
            if (self->unk_18 >= 0) {
                Ov003Pickup_Update(self, 0);
            }
            func_ov000_02197dec(self, 0xf, 5);
            SndMgr_PlayStrm(gSndMgr, 0x7e);
            Effect_SpawnId(0x12f, &self->pos)->SetScaleAll(0x800);
            Group_UpdateActor(gGroup, 0, self);
            self->vfunc_08();
        } else {
            self->unk_30c--;
        }
    }
    ActorEx_StateHeld(self);
}

}
