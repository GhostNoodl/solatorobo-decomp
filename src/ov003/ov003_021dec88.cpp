#include "types.h"
#include "Main/Snd/SndMgr.h"
#include "Main/Effect/Effect.h"
#include "ov003/ActorApi.h"
#include "ov000/ActorMgr.h"


extern "C" {

extern const char data_ov003_021f8510[];
extern char data_ov003_021f8516[];
extern BOOL Model0218fe1c_SetAnim(Model0218fe1c *model, const char *name, s32 a, s32 b);
extern void Model0218fe1c_SetAnimSpeed(Model0218fe1c *model, s32 v);
extern void Model0218fe1c_SetLoop(Model0218fe1c *model);
extern BOOL Model0218fe1c_SetRes(Model0218fe1c *model, void *res, s32 a, s32 b);
extern void ActorMgr_BroadcastKind(ActorMgr *mgr, u16 a, s32 b);
extern void SndMgr_StopSeqArc(SndMgr *mgr, s32 id);
extern void func_ov000_0218996c(u8 a, u8 b);
extern BOOL History_SetState(ActorSub40 *w, s32 a, s32 b);
extern void *ActorMgr_FindPlayer(void);
extern BOOL func_ov000_021b4738(void);

static inline void Ov003LpModel_SetMode(Model0218fe1c *m, s32 mode) {
    if (m->unk_c0 != mode) {
        Model0218fe1c_SetRes(m, m->res, mode, m->unk_c2_1 ? TRUE : FALSE);
    }
}

void Ov003ActVt_021f83e8_State06(Ov003ActExSeq *self) {
    ActorSub40 *w;
    switch (self->fsm->st) {
    case 0: {
        s16 n = self->unk_18 + 1;
        if (n >= 3) {
            EffectObj *fx;
            Model0218fe1c_SetAnim(self->model, data_ov003_021f8510, 0x1000, 0);
            Model0218fe1c_SetAnimSpeed(self->model, 0x333);
            ActorMgr_BroadcastKind(data_ov000_021ccd68, 0x5011, 0x15);
            ActorMgr_BroadcastKind(data_ov000_021ccd68, 0x4801, 0x15);
            ActorMgr_BroadcastKind(data_ov000_021ccd68, 0x5013, 0x15);
            ActorMgr_BroadcastKind(data_ov000_021ccd68, 0x400c, 0x15);
            SndMgr_StopSeqArc(data_02097e4c, self->seq);
            func_ov000_0218996c(0x19, 0x3c);
            SndMgr_PlayAt(data_02097e4c, 0x56, &self->pos, 0);
            SndMgr_PlayAt(data_02097e4c, 0x44, &self->pos, 0);
            fx = Effect_SpawnId(5, &self->pos);
            if (fx != NULL) {
                fx->SetScaleAll(0x7800);
                fx->speed = 0x800;
            }
            self->fsm->st = 10;
            return;
        }
        Ov003LpModel_SetMode(self->model, 1);
        Model0218fe1c_SetAnim(self->model, data_ov003_021f8516, 0x1000, 0);
        Model0218fe1c_SetLoop(self->model);
        {
            Model0218fe1c *m = self->model;
            m->color = 0x5adf;
            m->color2 = 0x739f;
            m->blend = 0xb;
            m->blendMax = 10;
        }
        self->unk_18 = n;
        func_ov000_02197dec(self, n, -1);
        self->fsm->st++;
        break;
    }
    case 1:
        w = self->fsm;
        w->timer++;
        if (w->timer < 10) {
            return;
        }
        Ov003LpModel_SetMode(self->model, 0);
        Model0218fe1c_SetAnim(self->model, data_ov003_021f8516, 0x1000, 0);
        Model0218fe1c_SetLoop(self->model);
        History_SetState(self->fsm, 1, 0);
        break;
    case 10:
        w = self->fsm;
        w->timer++;
        if (w->timer < 0x2d) {
            return;
        }
        self->fsm->timer = 0x2d;
        if (ActorMgr_FindPlayer() == NULL) {
            return;
        }
        if (func_ov000_021b4738()) {
            return;
        }
        self->unk_18 = 3;
        func_ov000_02197dec(self, 3, 2);
        History_SetState(self->fsm, 1, 0);
        break;
    }
}

}
