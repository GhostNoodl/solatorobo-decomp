#include "ov014/ov014.h"

extern "C" {

extern char data_ov014_02217d7c[];
extern char data_ov014_02217d82[];
extern s16 *Model0218fe1c_SetAnimFrame(Model0218fe1c *a, s32 b);
extern void Model0218fe1c_ClearLoop(Model0218fe1c *a);

void Ov014Act_0220f9d0_StateHurt(Ov014Act_0220f9d0 *self) {
    switch (self->fsm->st) {
    case 0: {
        ActorSub44 *n;
        if (self->unk_150 == 0x4806) {
            Model0218fe1c_SetAnim(self->model, data_ov014_02217d7c, 0x1000, 0);
        } else {
            Model0218fe1c_SetAnim(self->model, data_ov014_02217d82, 0x1000, 0);
        }
        Model0218fe1c_SetAnimFrame(self->model, 0);
        Model0218fe1c_ClearLoop(self->model);
        self->fsm->st++;
        n = self->unk_44;
        n->unk_22_0 = 0;
        n->unk_22_1 = 0;
        self->unk_44->unk_22_4 = 0;
        break;
    }
    case 1: {
        ActorSub44 *n;
        if (!Model0218fe1c_IsAnimDone(self->model)) {
            return;
        }
        self->fsm->st = 0xffff;
        n = self->unk_44;
        n->unk_22_0 = 1;
        n->unk_22_1 = 1;
        self->unk_44->unk_22_4 = 1;
        break;
    }
    default: {
        ActorSub44 *n;
        self->fsm->st = 0xffff;
        n = self->unk_44;
        n->unk_22_0 = 1;
        n->unk_22_1 = 1;
        self->unk_44->unk_22_4 = 1;
        break;
    }
    }
}

extern char data_ov014_02217d88[];
extern void Shared_SetEventActor(u16 a, u16 b);
extern void func_020627dc(s32 a);
extern void func_ov000_02182590(void *p);
extern void Model0218fe1c_SetAnimSpeed(Model0218fe1c *a, s16 b);
extern AnimCtrl *Model0218fe1c_GetAnimCtrl(Model0218fe1c *self, u32 i);
extern void ActorMgr_SendToKindOthers(s32 a, u16 b, s32 c, s32 d, s32 e, u8 *f);
extern void Field_ShakeCamera(u8 a, u8 b);

// *(&gSndMgr) keeps the global's address in a saved register (r7) across the
// switch, as in the target; a plain gSndMgr reloads it from the pool each time.
void Ov014Act_0220f9d0_StateDie(Ov014Act_0220f9d0 *self) {
    u16 t;
    VecFx32 v1;
    VecFx32 v3;
    u8 b;
    switch (ActorSub40_State(self->fsm)) {
    case 0: {
        FieldState *g;
        ActorSub44 *n;
        EffectObj *e;
        Shared_SetEventActor(self->kind, self->id);
        func_020627dc(5);
        g = gSceneCmd;
        g->stageFlags = 1;
        func_ov000_02182590((u8 *)g + 0xac);
        Model0218fe1c_SetAnim(self->model, data_ov014_02217d88, 0x19a, 0);
        Model0218fe1c_SetAnimSpeed(self->model, 0x400);
        Model0218fe1c_ClearLoop(self->model);
        n = self->unk_44;
        n->unk_22_0 = 0;
        n->unk_22_1 = 0;
        self->targetObj->target = 0xffff;
        b = 0x15;
        ActorMgr_SendToKindOthers(0x5c16, self->id, 2, 1, 1, &b);
        ActorMgr_SendToKindOthers(0x4806, self->id, 2, 1, 1, &b);
        ActorMgr_SendToKindOthers(0x4814, self->id, 2, 1, 1, &b);
        ActorMgr_SendToKindOthers(0x4815, self->id, 2, 1, 1, &b);
        ActorMgr_SendToKindOthers(0x4816, self->id, 2, 1, 1, &b);
        ActorMgr_SendToKindOthers(0x4838, self->id, 2, 1, 1, &b);
        ActorMgr_SendToKindOthers(0x4839, self->id, 2, 1, 1, &b);
        e = Effect_SpawnId(0x69, &self->pos);
        if (e != NULL) {
            e->AddPosXYZ(0, 0x6000, 0x4000);
            e->SetScaleAll(0x6000);
        }
        SndMgr_PlayAt(gSndMgr, 0x56, &self->pos, 0);
        Field_ShakeCamera(0xc, 0x5a);
        self->fsm->timer = 0x258;
        self->fsm->st++;
        break;
    }
    case 1: {
        t = self->fsm->timer;
        if (t != 0) {
        if (t == 0x21c) {
            EffectObj *e = Effect_SpawnId(0x390, &self->pos);
            e->AddPosXYZ(0, 0x6000, 0x2000);
            e->SetScaleAll(0x3000);
            self->unk_158 = e->id;
            SndMgr_PlayAt(*(&gSndMgr), 0x44, &self->pos, 0);
        }
        if (t == 0x1fe || t == 0x1e0 || t == 0x1c2 || t == 0x1a4) {
            SndMgr_PlayAt(*(&gSndMgr), 0x44, &self->pos, 0);
        }
        if (t == 0x12c) {
            EffectMgr_StopLoop(gEffectMgr, self->unk_158);
        }
        if (t == 0x140) {
            FieldState *g = gSceneCmd;
            SndQueue *h;
            g->cam.base.shakeX = 1;
            g->cam.base.shakeY = 0;
            g->cam.base.shakeZ = 0;
            g->cam.base.shakeTime = 0x10;
            g->cam.base.shakeLen = 0x1e;
            g->cam.base.shakeCur = 0x1e;
            g->cam.base.shakeRandom = 1;
            h = gSndQueue.queue;
            if (h->flag0 != 1 || h->unk_74 != 0xffff || h->unk_72 != 0x38) {
                h->unk_74 = 0x38;
                h->unk_70 = 0;
            }
        }
        if (t <= 0xc8 && t % 30 == 0) {
            EffectObj *e;
            s32 r;
            v1 = self->pos;
            v1.x += Rand_PlusMinus(0x4000);
            v1.y = Rand_PlusMinus(0x3000) + 0x5000;
            v1.z += Rand_PlusMinus(0x1000) + 0x5000;
            e = Effect_SpawnId(0x38f, &v1);
            r = Rand_UpTo(0x1000);
            e->SetScaleXYZ(r + 0x2800, r + 0x2800, r + 0x2800);
            SndMgr_PlayAt(*(&gSndMgr), 0x35, &v1, 0);
            SndMgr_PlayAt(*(&gSndMgr), 0x56, &v1, 0);
        }
        if (t > 0xfa) {
            s32 a = 0;
            AnimCtrl *q = Model0218fe1c_GetAnimCtrl(self->model, 0);
            if (q->cur != NULL) {
                a = q->cur->frame;
            }
            if (a >= 0x8000) {
                Model0218fe1c_SetAnimFrame(self->model, 0);
            }
        }
        if (t == 0xfa) {
            Model0218fe1c_SetAnimSpeed(self->model, 0x1000);
        }
        {
            ActorSub40 *s = self->fsm;
            if (s->timer != 0) {
                s->timer--;
            }
        }
        } else {
            FieldState *g;
            self->fsm->st++;
            g = gSceneCmd;
            g->cam.base.shakeRandom = 0;
            g->cam.base.shakeTime = 0;
            g->cam.base.shakeLen = 0;
            g->cam.base.shakeCur = 0;
        }
        break;
    }
    case 2:
        Ov003Actor_Defeat(self, 0, 1, 1);
        Model0218fe1c_SetAnim(self->model, data_ov014_02217d88, 0x19a, 0);
        Model0218fe1c_ClearLoop(self->model);
        Model0218fe1c_SetAnimSpeed(self->model, 0x1000);
        self->fsm->st++;
        self->fsm->timer = 0;
        break;
    case 3: {
        ActorSub40 *s = self->fsm;
        s->timer++;
        if (s->timer % 48 != 0) {
            break;
        }
        v3 = self->pos;
        v3.x += Rand_PlusMinus(0xa000);
        v3.y = Rand_PlusMinus(0x3000) + 0x5000;
        v3.z += Rand_PlusMinus(0x1000) + 0x5000;
        Effect_SpawnId(0x38f, &v3)->SetScaleXYZ(0x2ccd, 0x2ccd, 0x2ccd);
        SndMgr_PlayAtPitch(*(&gSndMgr), 0x35, &v3, -(Rand_UpTo(5) + 2));
        SndMgr_PlayAt(*(&gSndMgr), 0x56, &v3, 0);
        Field_ShakeCamera(10, 0x1e);
        break;
    }
    }
}

}
