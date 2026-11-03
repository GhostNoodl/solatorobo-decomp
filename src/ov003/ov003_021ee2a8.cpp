#include "types.h"
#include "Main/Snd/SndMgr.h"
#include "Main/Effect/Effect.h"
#include "Main/Sys/FieldState.h"
#include "ov000/ActorParts.h"
#include "ov003/ActEx.h"
#include "ov003/ActorApi.h"


struct Ov003LvPlayer {
    u8 unk_00[0x64];
    s32 radius;
    u8 unk_68[8];
    VecFx32 pos;
};

extern "C" {

extern char data_ov003_021f9fd6[];
extern char data_ov003_021f9fd0[];
extern BOOL Model0218fe1c_SetAnim(void *p, const char *name, s32 a, s32 b);
extern void Model0218fe1c_SetLoop(void *p);
extern void Model0218fe1c_SetAnimSpeed(void *p, s32 a);
extern void func_020627b4(void);
extern void *Target_Get(void *p);
extern void Actor_SendMsg(void *p, u16 a, s32 b, s32 c, s32 d, s32 e);
extern BOOL Model0218fe1c_IsAnimDone(void *p);
extern BOOL History_SetState(ActorSub40 *p, u8 a, BOOL b);
extern Ov003LvPlayer *ActorMgr_FindPlayer(void);
extern BOOL Hit_DiffInSphere(VecFx32 *a, VecFx32 *b, s32 r);
extern u32 Rand_UpTo(u32 max);

void Ov003Lever_SetState(Ov003Lever *self, s16 kind, BOOL notify, s32 sound);

void Ov003ActVt_021f9ea8_Start(Ov003Lever *self) {
    ActorEx_Start(self);
    Obj02197d80_LoadValue(self);
    Ov003Lever_SetState(self, self->unk_18, 0, -1);
    if (self->unk_18 == 1 && self->unk_1a != 0) {
        ActorSub44 *p = self->unk_44;
        p->unk_22_0 = 0;
        p->unk_22_1 = 0;
    }
    self->unk_ce = 0;
}

void Ov003ActVt_021f9ea8_StateIdle(Ov003Lever *self) {
    ActorSub40 *w = self->fsm;
    switch (w->st) {
    case 0:
        Obj02197d80_LoadValue(self);
        if (self->unk_18 == 1) {
            self->unk_93_1 = 1;
            if (self->param->unk_01 != 1) {
                return;
            }
            self->fsm->timer = 2;
            self->fsm->st++;
        } else if (self->unk_18 == 0) {
            self->unk_93_1 = 0;
        }
        break;
    case 1:
        if (w->timer != 0) {
            w->timer--;
        }
        if (w->timer != 0) {
            return;
        }
        Ov003Lever_SetState(self, 0, 1, -1);
        self->fsm->st--;
        break;
    }
}

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
    return true;
}

static inline BOOL Ov003Work_Tick(ActorSub40 *w) {
    if (w->timer != 0) {
        w->timer--;
    }
    return w->timer == 0;
}

void Ov003ActVt_021f9ea8_State06(Ov003Lever *self) {
    void *sp = Target_Get(self->targetObj);
    ActorSub40 *w = self->fsm;
    switch (w->st) {
    case 0: {
        s32 snd = 0x18;
        if (self->unk_1c != 0) {
            self->unk_ce = 2;
            snd = 0x84;
        }
        if (self->unk_18 == 0) {
            Ov003Lever_SetState(self, 1, 1, snd);
        } else {
            Ov003Lever_SetState(self, 0, 1, snd);
        }
        self->fsm->timer = 2;
        self->fsm->st++;
        break;
    }
    case 1:
        if (w->timer != 0) {
            w->timer--;
        }
        if (w->timer != 0) {
            return;
        }
        if (self->param->unk_01 != 1) {
            self->fsm->timer = 0x78;
        } else {
            Ov003Lever_SetState(self, 0, 1, -1);
            self->fsm->timer = 0x3c;
        }
        self->fsm->st++;
        break;
    case 2:
        if (self->unk_1c != 0 && self->unk_ce < 0x41) {
            if (!(self->unk_ce & 0x1f)) {
                SndMgr_PlayAt(gSndMgr, 0x84, &self->pos, 0);
            }
            self->unk_ce++;
        }
        if (!Ov003_GameIdle()) {
            return;
        }
        w = self->fsm;
        if (w->timer != 0) {
            w->timer--;
        }
        if (w->timer != 0) {
            return;
        }
        if (self->model != NULL && !Model0218fe1c_IsAnimDone(self->model)) {
            return;
        }
        if (sp != NULL) {
            Actor_SendMsg(sp, self->id, 3, 1, 0, 0);
        }
        self->targetObj->target = 0xffff;
        if (self->unk_1a != 0 && self->unk_18 == 1) {
            ActorSub44 *p;
            self->fsm->st = 10;
            p = self->unk_44;
            p->unk_22_0 = 0;
            p->unk_22_1 = 0;
        } else {
            History_SetState(self->fsm, 1, 0);
        }
        break;
    case 10:
        break;
    }
}

void Ov003Lever_SetState(Ov003Lever *self, s16 kind, BOOL notify, s32 sound) {
    const char *name;
    if (kind == 1) {
        self->unk_93_1 = 1;
        name = data_ov003_021f9fd6;
    } else {
        self->unk_93_1 = 0;
        name = data_ov003_021f9fd0;
    }
    if (self->model != NULL && name != NULL) {
        Model0218fe1c_SetAnim(self->model, name, 0x1000, 0);
        Model0218fe1c_SetLoop(self->model);
        Model0218fe1c_SetAnimSpeed(self->model, 0x4cd);
    }
    if (sound >= 0) {
        SndMgr_PlayAt(gSndMgr, sound, &self->pos, 0);
    }
    self->unk_18 = kind;
    if (notify) {
        s16 k = self->unk_18;
        func_020627b4();
        func_ov000_02197dec(self, k, k);
    }
}

void Ov003ActVt_021f9ce0_StateIdle(Ov003Lever *self) {
    ActorSub40 *w;
    if (self->unk_18 == 1) {
        ActorSub44 *p;
        self->unk_93_1 = 1;
        p = self->unk_44;
        p->unk_22_0 = 0;
        p->unk_22_1 = 0;
        return;
    }
    self->unk_93_1 = 0;
    w = self->fsm;
    switch (w->st) {
    case 0:
        if (!(w->timer & 0x7f)) {
            Ov003LvPlayer *pl = ActorMgr_FindPlayer();
            if (pl != NULL && Hit_DiffInSphere(&pl->pos, &self->pos, pl->radius + 0xf000)) {
                EffectObj *e = Effect_SpawnId(0x322, &self->pos);
                e->SetScaleXYZ(0xe66, 0xe66, 0xe66);
                SndMgr_PlayAt(gSndMgr, Rand_UpTo(1) + 0x79, &self->pos, 0);
                self->fsm->st++;
                self->fsm->timer = 0;
                return;
            }
        }
        self->fsm->timer++;
        break;
    case 1:
        w->timer++;
        w = self->fsm;
        if (w->timer < 0x37) {
            Hit_ApplyInArea(self, self, 0x32, 0x20, 2, NULL, NULL, 0x1800, 0, 0x322, 0x800);
            return;
        }
        if (w->timer >= 0x87 - (self->unk_1a << 4)) {
            w->st--;
            self->fsm->timer = 0;
        }
        break;
    }
}

void Ov003ActVt_021f9ce0_State06(Ov003Lever *self) {
    ActorSub40 *w = self->fsm;
    switch (w->st) {
    case 0: {
        s16 k;
        ActorSub44 *p;
        self->unk_18 = 1;
        k = self->unk_18;
        self->unk_93_1 = 1;
        func_020627b4();
        func_ov000_02197dec(self, k, k);
        p = self->unk_44;
        p->unk_22_0 = 0;
        p->unk_22_1 = 0;
        SndMgr_PlayAt(gSndMgr, 0x6e, &self->pos, 0);
        self->fsm->timer = 0x78;
        self->fsm->st++;
        break;
    }
    case 1: {
        void *sp;
        if (w->timer != 0) {
            w->timer--;
        }
        if (w->timer != 0) {
            return;
        }
        sp = Target_Get(self->targetObj);
        if (sp != NULL) {
            Actor_SendMsg(sp, self->id, 3, 1, 0, 0);
        }
        if (!Ov003_GameIdle()) {
            self->fsm->st++;
            return;
        }
        History_SetState(self->fsm, 0x15, 0);
        break;
    }
    case 2:
        if (!Ov003_GameIdle()) {
            return;
        }
        History_SetState(w, 0x15, 0);
        break;
    }
}
}
