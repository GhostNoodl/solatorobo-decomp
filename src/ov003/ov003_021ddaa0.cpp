#include "types.h"
#include "Main/Snd/SndMgr.h"
#include "Main/Effect/Effect.h"
#include "ov003/ActEx.h"
#include "ov003/ActorApi.h"


extern "C" {

extern void *data_ov000_021ccd64;
extern char data_ov003_021f803c[];
extern BOOL History_SetState(ActorSub40 *w, s32 a, s32 b);
extern BOOL Model0218fe1c_SetAnim(void *model, const char *name, s32 a, s32 b);
extern void Model0218fe1c_SetAnimSpeed(void *model, s32 v);
extern BOOL Model0218fe1c_IsAnimDone(void *model);
extern void HitMesh_Unlink_0203f920(void *p);
extern Actor *Target_Get(ActorSub4c *p);
extern void Actor_SendMsg(Actor *p, u16 id, s32 a, s32 b, s32 c, s32 d);
extern void func_ov000_0218bed8(void *mgr, s32 a, void *obj);

static inline void Ov003SwSub44_Clear(ActorSub44 *p) {
    p->unk_22_0 = 0;
    p->unk_22_1 = 0;
}

void Ov003ActVt_021f7fac_State06(Ov003Switch *self) {
    switch (self->fsm->st) {
    case 0:
        if (self->unk_18 == 3) {
            if (self->targetObj->unk_0a != 0xffff) {
                SndMgr_PlayAt(data_02097e4c, self->targetObj->unk_0a, &self->pos, 0);
            }
            self->targetObj->target = 0xffff;
            History_SetState(self->fsm, 1, 0);
            return;
        }
        if (self->model != NULL) {
            u8 k = self->param->unk_01;
            s32 speed = 0x1000;
            s32 frame = 0x1000;
            if (k != 1 && k != 2) {
                speed = 0x89;
            }
            if (k != 2) {
                frame = 0x800;
            }
            Model0218fe1c_SetAnim(self->model, data_ov003_021f803c, speed, 0);
            Model0218fe1c_SetAnimSpeed(self->model, frame);
        }
        if (self->targetObj->unk_08 != 0xffff) {
            SndMgr_PlayAt(data_02097e4c, self->targetObj->unk_08, &self->pos, 0);
        }
        self->fsm->st++;
        break;
    case 1:
        if (self->model != NULL && !Model0218fe1c_IsAnimDone(self->model)) {
            return;
        }
        self->unk_cc_0 = 0;
        if (self->hitMesh != NULL) {
            HitMesh_Unlink_0203f920(self->hitMesh);
        }
        Ov003SwSub44_Clear(self->unk_44);
        if (self->targetObj->unk_02 != 6) {
            Actor *p = Target_Get(self->targetObj);
            if (p != NULL) {
                Actor_SendMsg(p, self->id, 3, 1, 0, 0);
            }
            self->targetObj->target = 0xffff;
        }
        if (self->targetObj->unk_02 == 5) {
            func_ov000_02197dec(self, 0xf, -1);
            func_ov000_0218bed8(data_ov000_021ccd64, 0, self);
            self->vfunc_08();
        }
        self->fsm->st++;
        break;
    }
}

}
