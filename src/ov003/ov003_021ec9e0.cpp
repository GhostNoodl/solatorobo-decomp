#include "types.h"
#include "Main/Snd/SndMgr.h"
#include "Main/Effect/Effect.h"
#include "ov000/ActorParts.h"
#include "ov003/ActEx.h"
#include "ov003/ActorApi.h"


struct Ov003GmGlobal {
    u8 unk_00[0xac];
    u8 unk_ac;
};

struct Ov003GmPlayer {
    u8 unk_00[0xc];
    u16 unk_0c;
    u8 unk_0e[0x36];
    void *unk_44;
    u8 unk_48[0xad6];
    u16 target;
};

struct Ov003GmArg {
    u8 a;
    u8 b;
};

struct Ov003GmTable {
    void *res[4];
};

extern "C" {

extern char data_ov003_021f99d8[];
extern BOOL Model0218fe1c_SetAnim(void *model, const char *name, s32 a, s32 b);
extern void Model0218fe1c_SetAnimSpeed(void *model, s32 v);
extern void Model0218fe1c_ClearLoop(void *model);
extern void *Model0218fe1c_SetAnimFrame(void *model, s32 v);
extern void Model0218fe1c_ResumeAnim(void *model);
extern void Model0218fe1c_PauseAnim(void *model);
extern BOOL Model0218fe1c_IsAnimDone(void *model);
extern BOOL History_SetState(ActorSub40 *p, u8 a, BOOL b);
extern Ov003GmPlayer *ActorMgr_FindPlayer(void);
extern BOOL Hit_Apply(void *a, void *b, void *c, s32 d, s32 e, VecFx32 *f, s32 g, s32 h, s32 i);
extern void ActorMgr_SendToKindOthers(s32 id, u16 a, s32 b, s32 c, s32 d, Ov003GmArg *arg);
extern void *Tbl_FindEntry_0206fef8(u16 id);
extern void Model0218fe1c_Setup(void *model, void *p, void *info);
extern void HitSphere_Link(ActorSub48 *ctl);
extern void Body_Update(ActorSub48 *ctl, s32 a, s32 b, s32 c);
extern void Model0218fe1c_SetLoop(void *model);
extern void Field_ShakeCamera(u8 a, u8 b);

void func_ov003_021ec9e0(Ov003Gimmick *self) {
    ActorSub40 *w = self->fsm;
    switch (w->st) {
    case 0:
        Model0218fe1c_SetAnim(self->model, data_ov003_021f99d8, 0x1000, 0);
        Model0218fe1c_SetAnimSpeed(self->model, 0x800);
        Model0218fe1c_ClearLoop(self->model);
        Model0218fe1c_SetAnimFrame(self->model, 0);
        Model0218fe1c_ResumeAnim(self->model);
        self->fsm->st++;
        break;
    case 1:
        w->timer++;
        if (w->timer >= 0xf && w->timer <= 0x64) {
            Ov003GmPlayer *pl = ActorMgr_FindPlayer();
            u16 id;
            Hit_ApplyInArea(self, self, 0x78, 0x11, (u16)(1 << (pl->unk_0c >> 12)), NULL, NULL,
                                self->radius + (self->radius >> 1), self->height, 0x6d, 0xccd);
            id = pl->target;
            if (id != 0xffff && id == self->id) {
                Hit_Apply(pl->unk_44, self, self, 0xa, 0x11, &self->pos, 0x6d, 0xccd, 0x1000);
            }
        }
        if (!Model0218fe1c_IsAnimDone(self->model)) {
            return;
        }
        History_SetState(self->fsm, 1, 1);
        break;
    }
}

void Ov003ActVt_021f99e8_StateHeld(Ov003Gimmick *self) {
    if (self->fsm->st == 0) {
        if (self->kind == 0x4064) {
            if (self->unk_cf_u != 1) {
                self->unk_cf_u = 0;
            }
            self->rotOfs.y = 0;
            self->rotOfs.z = 0;
            self->rotOfs.x = 0x4000;
            if (self->unk_bc != NULL) {
                Ov003GmArg arg;
                EffectMgr_Kill(gEffectMgr, self->unk_bc);
                self->unk_bc = NULL;
                arg.a = self->unk_1c;
                arg.b = 0;
                ActorMgr_SendToKindOthers(0x4064, self->id, 0xe, 1, 2, &arg);
            }
        } else if (self->kind == 0x4065 && self->unk_cf_u == 0) {
            Model0218fe1c_SetAnim(self->model, data_ov003_021f99d8, 0x1000, 0);
            Model0218fe1c_PauseAnim(self->model);
            Model0218fe1c_SetAnimFrame(self->model, 0);
        }
    }
    ActorEx_StateHeld(self);
}

void Ov003ActVt_021f99e8_StateDie(Ov003Gimmick *self) {
    Ov003GmArg arg;
    ActorSub40 *w = self->fsm;
    if (w->st == 0 && w->history[0] != 10 && self->unk_ce_u != 0) {
        self->unk_ce_u--;
    }
    if (self->unk_ce_u == 0 && self->unk_cf_u == 1) {
        if (self->unk_bc != NULL) {
            EffectMgr_Kill(gEffectMgr, self->unk_bc);
            self->unk_bc = NULL;
        }
        ActorEx_StateDie(self);
        return;
    }
    switch (self->fsm->st) {
    case 0:
        if (self->unk_ce_u == 0) {
            EffectObj *e;
            if (self->unk_bc != NULL) {
                EffectMgr_Kill(gEffectMgr, self->unk_bc);
                self->unk_bc = NULL;
                if (self->kind == 0x4064) {
                    arg.a = self->unk_1c;
                    arg.b = 0;
                    ActorMgr_SendToKindOthers(0x4064, self->id, 0xe, 1, 2, &arg);
                }
            }
            self->unk_cf_u = 1;
            self->unk_ce_u = self->unk_1a;
            if (self->unk_ce_u == 0) {
                self->unk_ce_u = 1;
            }
            Model0218fe1c_Setup(self->model, &self->res, Tbl_FindEntry_0206fef8(self->kind));
            e = Effect_SpawnId(0x6d, &self->pos);
            e->SetScaleXYZ(self->radius + (self->radius >> 3), self->radius + (self->radius >> 3), self->radius + (self->radius >> 3));
            e = Effect_SpawnId(4, &self->pos);
            e->SetScaleXYZ(self->radius + (self->radius >> 3), self->radius + (self->radius >> 3), self->radius + (self->radius >> 3));
            e->AddPosXYZ(0, self->centerY, 0);
            SndMgr_PlayAt(gSndMgr, 0x16, &self->pos, 0);
            SndMgr_PlayAt(gSndMgr, 0x19, &self->pos, 0);
        }
        {
            ActorSub48 *c = self->hit;
            c->unk_9a_0 = 1;
            c->unk_9a_3 = 1;
            HitSphere_Link(c);
            self->hit->unk_9a |= 0x12;
        }
        self->velY = 0x2cd;
        self->gravity = 0x52;
        self->fsm->st++;
    case 1:
        func_ov000_02197ad0(self, 0);
        Actor_Move(self, 0);
        Body_Update(self->hit, 1, 0, 0);
        if (self->hit->unk_50 & 0x20000000) {
            ActorSub44 *s = self->unk_44;
            s->unk_22_0 = 1;
            s->unk_22_1 = 1;
            Model0218fe1c_SetAnim(self->model, data_ov003_021f99d8, 0x1000, 0);
            Model0218fe1c_SetLoop(self->model);
            SndMgr_PlayAt(gSndMgr, 0x17, &self->pos, 0);
            Field_ShakeCamera(0xf, 0x14);
            self->velY = 0;
            self->fsm->st++;
            self->fsm->timer = 0;
            return;
        }
        if (self->velY >= 0) {
            return;
        }
        w = self->fsm;
        w->timer++;
        if (w->timer <= 0x46) {
            return;
        }
        self->fsm->timer = 0x46;
        if (self->hit->unk_54 & 0x20000000) {
            return;
        }
        History_SetState(self->fsm, 0x15, 1);
        break;
    case 2:
        self->hit->unk_9a |= 0x20;
        w = self->fsm;
        w->timer++;
        if (w->timer < 6) {
            return;
        }
        self->fsm->timer = 6;
        if (!Model0218fe1c_IsAnimDone(self->model) && self->fsm->flags == 0) {
            return;
        }
        self->targetObj->target = 0xffff;
        History_SetState(self->fsm, 1, 0);
        break;
    }
}
}
