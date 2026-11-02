#include "types.h"
#include "Main/Math/Rot16.h"
#include "Main/Effect/Effect.h"
#include "Main/Sys/FieldState.h"
#include "ov000/ActorParts.h"
#include "ov003/Unit.h"
#include "ov003/ActorApi.h"
#include "ov000/ActorMgr.h"



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

extern "C" {

extern void *data_ov000_021ccd64;
extern char data_ov003_021f995c[];
extern char data_ov003_021f9967[];
extern char data_ov003_021f996d[];
extern char data_ov003_021f9978[];
extern Ov003Player *func_ov000_0219bf90(void);
extern void func_ov000_021bd7a0(void *p);
extern BOOL Hit_DiffInSphere(VecFx32 *a, VecFx32 *b, s32 r);
extern void func_ov000_0218f074(ActorRes *p, void *res, s32 a, s32 b, s32 c, s32 d);
extern BOOL func_ov000_0218f110(ActorRes *res);
extern BOOL func_ov000_0218ffdc(Model0218fe1c *anim, ActorRes *res, s32 a, s32 b);
extern BOOL func_ov000_02190cb0(void *model, const char *name, s32 a, s32 b);
extern void *Heap_Alloc(u32 size);
extern ActorSub4c *func_ov000_02199b00(void *p);
extern void *func_0203db40(void *p);
extern void func_ov000_02190a80(void *a, void *b);
extern void func_ov000_02190758(Model0218fe1c *anim, Rot16 *rot, s32 a);
extern BOOL func_ov000_021903b4(Model0218fe1c *anim);
extern Ov003Unit *Group_FindNode(void *mgr, u16 id);
extern Ov003Snd *data_02fe152c;
extern s32 func_0205976c(Ov003Snd *s, s32 a);
extern u16 func_02059544(Ov003Snd *s, u8 *p, s32 a, s32 b, u16 c);
extern AnimCtrl *func_ov000_02190a30(Model0218fe1c *m, s32 a);
extern void func_ov000_02191920(Model0218fe1c *m, s32 a, s32 b, s32 c);
extern void func_0203f364(ActorSub48 *ctl);
extern void func_ov000_021915a0(void *model);
extern void func_ov000_021911c8(void *model, s32 a);
extern s32 Rand_PlusMinus(s32 max);
extern u16 func_01ffc128(u16 target, u16 cur, s32 step, u32 a, u16 b);
extern char data_ov003_021f9983[];
extern char data_ov003_021f9989[];
extern s32 func_01ffbd6c(VecFx32 *a, VecFx32 *b, u32 c, s32 d, s32 e, s32 f);
extern void func_ov000_021987b8(ActorSub48 *ctl, s32 a, s32 b, s32 c);
extern BOOL func_ov000_02198360(ActorSub40 *p, u8 a, BOOL b);

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
    FieldState *g = data_ov000_021ccd54;
    if (g != NULL) {
        return Ov003Game_IsIdle(g);
    }
    return TRUE;
}







static inline BOOL Ov003_GameIdle2(void) {
    FieldState *g = data_ov000_021ccd54;
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

void func_ov003_021eae44(Ov003ActExHome *self) {
    if (!self->unk_cc_7) {
        return;
    }
    if (self->model != NULL) {
        func_ov000_02190a80(self->model, func_0203db40(&self->pause));
    }
    func_ov000_02190a80(&self->mdl, (void *)0x1000);
}

BOOL Ov003ActVt_021f9834_Draw(Ov003ActExHome *self) {
    BOOL r;
    BOOL done = FALSE;
    if (self->unk_cc_7) {
        if (self->targetObj->unk_03 != 11) {
            done = func_ov000_02194c08(self);
        }
        self->mdl.alpha = self->model->alpha;
    }
    self->mdl.trans.x = self->homePos.x;
    self->mdl.trans.y = self->homePos.y;
    self->mdl.trans.z = self->homePos.z;
    func_ov000_02190758(&self->mdl, &self->homeRot, 0);
    r = func_ov000_021903b4(&self->mdl);
    if (r && !done && self->unk_5c != NULL && Ov003_GameIdle2()) {
        func_ov000_021bd7a0(self->unk_5c);
    }
    return r;
}

void Ov003ActVt_021f9704_Init(Ov003ActExSway *self) {
    func_ov000_0219433c(self);
    self->hasModel = 0;
    if (self->unk_1a != 0) {
        char *name;
        self->hasModel = 1;
        name = data_ov003_021f996d;
        if (self->unk_1a == 3 || (self->unk_1a == 1 && (data_ov000_021ccd68->frame & 1))) {
            name = data_ov003_021f9978;
        }
        func_ov000_0218f074(&self->res, name, 1, 0, 0, 0);
        self->res.unk_00 = 0;
    }
    self->rotOfs.x = 0;
    self->rotOfs.y = 0;
    self->rotOfs.z = 0;
    self->rotGoal.x = 0;
    self->rotGoal.y = 0;
    self->rotGoal.z = 0;
    self->unk_30c = 0;
}

BOOL Ov003ActVt_021f9704_IsReady(Ov003ActExSway *self) {
    BOOL r = func_ov000_021946f8(self);
    Ov003Unit *u;
    if (self->hasModel && self->res.unk_00 >= 0 && !func_ov000_0218f110(&self->res)) {
        r = FALSE;
    }
    u = Group_FindNode(data_ov000_021ccd64, self->unk_20);
    if (u != NULL) {
        u->unk_a2_5 = 1;
        u->unk_a2_6 = 0;
    }
    return r;
}

void Ov003ActVt_021f9704_Start(Ov003ActExSway *self) {
    u8 *x;
    BOOL f;
    s32 v;
    func_ov000_02194758(self);
    if (self->hasModel) {
        func_ov000_0218ffdc(&self->mdl, &self->res, 0, 1);
        self->mdl.actor_id = self->id;
        self->mdl.scale.x = 0x2000;
        self->mdl.scale.y = 0x2000;
        self->mdl.scale.z = 0x2000;
        self->targetObj->type = 15;
        self->targetObj->unk_01 = 1;
        self->targetObj->unk_03 = 0;
        self->targetObj->unk_02 = 1;
        self->targetObj->unk_18_1 = 0;
        self->hit->radius = 0x1000;
    }
    v = self->unk_18;
    f = FALSE;
    if (v < 0) {
        f = TRUE;
    }
    if (v >= 0x40) {
        f = TRUE;
    }
    if (!f) {
        x = data_02fe152c->unk_4c;
        if (func_02059544(data_02fe152c, x + 0x150, func_0205976c(data_02fe152c, 10), 1, v)) {
            f = TRUE;
        }
    }
    if (!f) {
        return;
    }
    {
        AnimCtrl *a = func_ov000_02190a30(self->model, 3);
        if (a != NULL) {
            self->model->unk_c2_6 = 1;
            func_ov000_02191920(self->model, 0, 0x1000, 0);
            if (a->cur != NULL) {
                a->cur->frame = 0x1000;
            }
            a->paused = 1;
        }
    }
    self->unk_18 = -1;
}

BOOL Ov003ActVt_021f9704_Draw(Ov003ActExSway *self) {
    BOOL r = FALSE;
    if (self->hasModel) {
        Rot16 rot;
        rot.x = self->rot.x;
        rot.y = self->rot.y;
        rot.z = self->rot.z;
        if (self->fsm->current == 1) {
            rot.x += self->rotOfs.x;
            rot.y += self->rotOfs.y;
            rot.z += self->rotOfs.z;
        }
        func_ov000_02190758(&self->mdl, &rot, 0);
        self->mdl.trans.x = self->pos.x;
        self->mdl.trans.y = self->pos.y;
        self->mdl.trans.z = self->pos.z;
        r = func_ov000_021903b4(&self->mdl);
        if (r && self->unk_5c != NULL && Ov003_GameIdle2()) {
            func_ov000_021bd7a0(self->unk_5c);
        }
    } else if (Ov003_GameIdle() || self->unk_17 == 0xff) {
        r = func_ov000_02194c08(self);
    }
    return r;
}

void Ov003ActVt_021f9704_Update(Ov003ActExSway *self) {
    Ov003Player *pl;
    ActorSub48 *ctl;
    if (self->hasModel) {
        return;
    }
    if (!Ov003_GameIdle()) {
        Actor *o = Actor_GetTarget(self);
        if (o != NULL) {
            Actor_TurnToActor(self, o, 0x400);
        }
    } else {
        func_ov000_02197ee0(self, &self->ai, 0x400, 0x333, 0x6000);
    }
    pl = func_ov000_0219bf90();
    if (pl == NULL) {
        return;
    }
    if (!pl->unk_93_4) {
        return;
    }
    if (self->unk_44 != NULL) {
        self->unk_44->unk_22_1 = 0;
    }
    ctl = self->hit;
    if (ctl == NULL) {
        return;
    }
    ctl->unk_9a_3 = 0;
    func_0203f364(ctl);
}

static inline void Ov003Sub44_Clear(ActorSub44 *s) {
    if (s != NULL) {
        s->unk_22_0 = 0;
        s->unk_22_1 = 0;
    }
}

void func_ov003_021eb48c(Ov003ActExSway *self) {
    if (self->fsm->st == 0) {
        func_ov000_02190cb0(self->model, data_ov003_021f9983, 0x1000, 0);
        func_ov000_021915a0(self->model);
        func_ov000_021911c8(self->model, (s16)(Rand_PlusMinus(0x59a) + 0x1000));
    }
    func_ov000_02195848(self);
    self->unk_93_0 = 0;
    if (self->hasModel) {
        u16 n = 0x100 - (u8)data_ov000_021ccd68->frame;
        if (n < 0x60) {
            self->rotGoal.x = 0;
            self->rotGoal.z = 0;
        } else if ((n & 7) == 0) {
            self->rotGoal.x = Rand_PlusMinus(n) << 2;
            self->rotGoal.z = Rand_PlusMinus(n) << 2;
        }
        self->rotOfs.x = func_01ffc128(self->rotGoal.x, self->rotOfs.x, 0x8cd, 1, 0x8000);
        self->rotOfs.z = func_01ffc128(self->rotGoal.z, self->rotOfs.z, 0x8cd, 1, 0x8000);
    } else {
        Ov003Sub44_Clear(self->unk_44);
    }
}

static inline BOOL Ov003Player_Flag(Ov003Player *pl) {
    return pl->unk_93_4 ? TRUE : FALSE;
}

void func_ov003_021eb5ec(Ov003ActExSway *self) {
    VecFx32 a;
    VecFx32 b;
    VecFx32 v;
    switch (self->fsm->st) {
    case 0:
        func_ov000_02190cb0(self->model, data_ov003_021f9989, 0x2ab, 0);
        func_ov000_021911c8(self->model, 0x2800);
        func_ov000_021915a0(self->model);
        Ov003Sub44_Clear(self->unk_44);
        self->velY = 0;
        self->friction = 0;
        self->gravity = 0;
        self->fsm->st++;
        break;
    case 1:
        if (self->fsm->timer >= 10) {
            if (self->unk_44 == NULL) {
                break;
            }
            BOOL on = FALSE;
            Ov003Player *pl = func_ov000_0219bf90();
            ActorSub44 *s;
            if (pl != NULL && pl->unk_b24_1 && !Ov003Player_Flag(pl)) {
                a.x = self->pos.x;
                a.y = self->pos.y;
                a.z = self->pos.z;
                b.x = pl->pos.x;
                b.y = pl->pos.y;
                b.z = pl->pos.z;
                a.y += self->height;
                b.y += pl->unk_6c;
                if (func_01ffbd6c(&a, &b, -1, 0, 0, -1) == -0x1000) {
                    on = TRUE;
                }
            }
            s = self->unk_44;
            if (!on) {
                s->unk_22_0 = 0;
                s->unk_22_1 = 0;
            } else {
                s->unk_22_0 = 1;
                s->unk_22_1 = 1;
            }
        } else {
            self->fsm->timer = ((const ActorSub40 *)self->fsm)->timer + 1;
        }
        break;
    }
    self->hit->unk_9a_5 = 1;
    self->speed = 0x400;
    v.x = self->ai.pos.x;
    v.y = self->ai.pos.y;
    v.z = self->ai.pos.z;
    Actor_MoveToPos(self, &v, 0x333);
    func_ov000_021987b8(self->hit, 1, 0, 0);
    if (self->hit->unk_50 & 0x20000000) {
        return;
    }
    func_ov000_02198360(self->fsm, 4, 0);
}


}
