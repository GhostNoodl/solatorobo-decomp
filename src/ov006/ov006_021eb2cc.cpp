#pragma pool_strings on
#pragma dont_reuse_strings off
#include "ov006/ov006.h"
#include "Main/Effect/Effect.h"
#include "ov000/ObjLayouts.h"

extern "C" {

extern void *data_02097e4c;
extern void *data_ov000_021ccd64;
BOOL Model0218fe1c_SetAnim(Model0218fe1c *model, const char *name, s32 blend, s32 force);
void Model0218fe1c_SetAnimSpeed(Model0218fe1c *model, s16 b);
void Model0218fe1c_SetLoop(Model0218fe1c *model);
void *SndMgr_PlayAt(void *a, s32 b, VecFx32 *c, s32 d);
BOOL Hit_ApplyInArea(Actor *a, Actor *b, u16 c, u8 d, u16 mask, const VecFx32 *ofs, Rot16 *rot,
                         s32 r, s32 rr, s16 h, s32 i);
void func_ov000_0218bed8(void *a, s32 b, Actor *actor);

void Ov006ActVt_021ec714_StateIdle(ActorEx *self) {
    BOOL any;
    int i;
    Rot16 rot;
    EffectObj *p;
    ActorSub40 *state = self->fsm;
    switch (state->st) {
    case 0:
        Model0218fe1c_SetAnim(self->model, "act00", 0x1000, 0);
        self->unk_ce_u = 0;
        self->rot.y += 0x8000;
        self->fsm->st++;
        break;
    case 1:
        state->timer++;
        if (state->timer <= 30) {
            return;
        }
        Model0218fe1c_SetAnim(self->model, "act01", 0x1000, 0);
        Model0218fe1c_SetAnimSpeed(self->model, 0x2800);
        Model0218fe1c_SetLoop(self->model);
        self->fsm->timer = 0;
        self->fsm->st++;
        break;
    case 2:
        state->timer++;
        if (state->timer > 0xa8c || self->unk_ce_u >= 3) {
            p = Effect_SpawnId(5, &self->pos);
            if (p != NULL) {
                p->SetScaleAll(0x5000);
            }
            SndMgr_PlayAt(data_02097e4c, 0x56, &self->pos, 0);
            Hit_ApplyInArea(self, self, 1, 0x11, 0x80, NULL, NULL, 0x7800, 0, -1, 0x1000);
            func_ov000_0218bed8(data_ov000_021ccd64, 0, self);
            self->vfunc_08();
            return;
        }
        any = FALSE;
        rot = self->rot;
        for (i = 0; i < 3; i++) {
            rot.z += 0x2aab;
            if (Hit_ApplyInArea(self, self, 1, 0x10, 0x80, NULL, &rot, 0x4400, 0x3c000, -1, 0x1000)) {
                any = TRUE;
            }
            rot.z += 0x2aab;
        }
        if (any) {
            self->unk_ce_u++;
        }
        break;
    }
}

}
