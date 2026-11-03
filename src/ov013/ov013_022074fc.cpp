#include "ov013/ov013.h"

extern "C" {

extern void *data_02097e4c;
extern char data_ov013_0220be94[];
extern void Model0218fe1c_SetAnimDelay(Model0218fe1c *a, u16 b, BOOL c);
extern void *SndMgr_PlayAtPitch(void *a, s32 b, VecFx32 *c, s32 d);

void Ov013ActVt_0220bdd8_StateHurt(Ov013ActVt_0220bdd8 *self) {
    switch (self->fsm->st) {
    case 0:
        Model0218fe1c_SetAnim(self->model, data_ov013_0220be94, 0x2ab, 0);
        Model0218fe1c_SetAnimDelay(self->model, 5, 1);
        self->unk_b4 = 0;
        self->unk_b6 = 0;
        SndMgr_PlayAtPitch(data_02097e4c, 0x6a, &self->pos, -3);
        self->fsm->st = 10;
        self->fsm->timer = 0;
        break;
    case 10:
        if (Model0218fe1c_IsAnimDone(self->model)) {
            History_SetState(self->fsm, 1, 0);
            self->unk_b6 = 0x3c;
        }
        break;
    }
}

extern char data_ov013_0220be7c[];
extern char data_ov013_0220be9a[];
extern void ActorMgr_BroadcastKind(void *mgr, u16 id, s32 c);
extern void HitSphere_Unlink_0203f364(void *p);
extern void Model0218fe1c_SetAnimSpeed(Model0218fe1c *a, s16 b);
extern void *SndMgr_PlayVolume(void *p, s32 a, s32 b, s32 c, s32 d);
extern EffectObj *Spawn_ScatterEffect(VecFx32 *pos, VecFx32 *v, s32 a, s32 b, s32 c, u8 d);
extern void Field_ShakeCamera(u8 a, u8 b);
extern void *SndMgr_PlayAt(void *a, s32 b, VecFx32 *c, s32 d);

void Ov013ActVt_0220bdd8_StateDie(Ov013ActVt_0220bdd8 *self) {
    ActorSub40 *st = self->fsm;
    switch (st->st) {
    case 0: {
        EffectObj *e;
        ActorMgr_BroadcastKind(data_ov000_021ccd68, 0x540c, 0x15);
        ActorMgr_BroadcastKind(data_ov000_021ccd68, 0x4811, 10);
        ActorMgr_BroadcastKind(data_ov000_021ccd68, 0x4813, 10);
        Model0218fe1c_SetAnim(self->model, data_ov013_0220be94, 0x19a, 0);
        self->hp[0] = 0;
        {
            ActorSub48 *c = self->hit;
            c->unk_9a_0 = 0;
            c->unk_9a_3 = 0;
            HitSphere_Unlink_0203f364(c);
        }
        {
            ActorSub44 *n = self->unk_44;
            n->unk_22_0 = 0;
            n->unk_22_1 = 0;
        }
        self->targetObj->target = 0xffff;
        SndMgr_PlayAtPitch(data_02097e4c, 0x6a, &self->pos, -3);
        e = Effect_SpawnId(0x69, &self->pos);
        if (e != NULL) {
            e->SetScaleAll(0x5800);
            e->AddPosXYZ(0, self->centerY, 0);
        }
        self->fsm->timer = 0;
        self->fsm->st = 1;
    }
    case 1:
        if (!Model0218fe1c_IsAnimDone(self->model)) {
            return;
        }
        self->fsm->st = 9;
        self->fsm->timer = 0;
        Model0218fe1c_SetAnim(self->model, data_ov013_0220be7c, 0x89, 0);
        Model0218fe1c_SetLoop(self->model);
        Model0218fe1c_SetAnimSpeed(self->model, 0xccd);
        break;
    case 9:
        st->timer++;
        if (st->timer > 0xb4) {
            SndMgr_PlayVolume(data_02097e4c, 0x53, -1, -1, -1);
            Model0218fe1c_SetAnim(self->model, data_ov013_0220be9a, 0x19a, 0);
            Model0218fe1c_SetAnimSpeed(self->model, 0xccd);
            self->fsm->st = 8;
            self->fsm->timer = 0;
        }
        if (self->fsm->timer % 20 == 0) {
            VecFx32 v;
            VecFx32 r;
            v = self->pos;
            v.y -= self->height >> 1;
            r.x = self->radius + (self->radius >> 1);
            r.y = self->height >> 2;
            r.z = self->radius;
            Spawn_ScatterEffect(&v, &r, 0xccd, 0x1666, 0x38b, 0x32);
            Field_ShakeCamera(10, 0xf);
            SndMgr_PlayAt(data_02097e4c, 0x35, &self->pos, 0);
        }
        break;
    case 8:
        if (!Model0218fe1c_IsAnimDone(self->model)) {
            return;
        }
        SndMgr_PlayAtPitch(data_02097e4c, 0x42, &self->pos, -2);
        Field_ShakeCamera(10, 0x3c);
        self->fsm->st = 10;
        self->fsm->timer = 0;
        break;
    case 10:
        st->timer++;
        if (st->timer > 0x50) {
            Ov003Actor_Defeat(self, 1, 1, 1);
            return;
        }
        Ov003Actor_SetAlpha(self, 0x1f - (self->fsm->timer >> 1));
        break;
    case 2:
    case 3:
    case 4:
    case 5:
    case 6:
    case 7:
        break;
    }
}

}
