#include "ov006/SlotManager.h"
#include "ov006/ov006.h"
#include "nitro/fx.h"
#include "Main/Effect/Effect.h"
#include "Main/Gfx/SlidePanel.h"
#include "Main/Snd/SndMgr.h"
#include "ov006/Racer.h"


extern "C" {


void Field_ShakeCamera(u8 a, u8 b);
BOOL History_SetState(ActorSub40 *a, s32 b, s32 c);
void Model0218fe1c_SetAnimSpeed(void *a, s32 b);
s32 Rand_PlusMinus(s32 range);
u16 Angle_Approach(u16 target, u16 cur, s32 rate, u32 minStep, u16 maxStep);
void Ov006Racer_Move(Ov006Racer *self);

void Ov006Racer_StateCrash(Ov006Racer *self) {
    self->unk_44->unk_22_1 = 0;
    switch (self->fsm->st) {
    case 0: {
        EffectObj *eff;
        self->runSpeed >>= 1;
        self->turnMode = 0;
        eff = Effect_SpawnId(0x322, &self->pos);
        if (eff != NULL) {
            EffectObj *old = Effect_Find_020657b0(gEffectMgr, self->unk_1e0);
            if (old != NULL) {
                EffectObj_StopLoop(old);
                old->state = 4;
            }
            self->unk_1e0 = eff->id;
            eff->speed = 0x1800;
        }
        SndMgr_PlayAt(gSndMgr, 0x79, &self->pos, 0);
        if (self->idx == gOv006SlotManager->unk5) {
            Field_ShakeCamera(8, (u8)(self->unk_1f5 - 10));
        }
        self->fsm->st++;
        break;
    }
    case 1:
        if (self->unk_1f5 <= 10) {
            History_SetState(self->fsm, 2, 0);
        }
        self->runSpeed -= 0x28;
        if (self->runSpeed < 0xcd) {
            self->runSpeed = 0xcd;
        }
        if (self->unk_1f5 % 25 == 0) {
            VecFx32 at;
            EffectObj *eff;
            at = self->pos;
            at.x += Rand_PlusMinus(0x1000);
            at.z += Rand_PlusMinus(0x1000);
            eff = Effect_SpawnId(0x325, &at);
            if (eff != NULL) {
                ((VObj *)eff)->vfunc_0c(0xc00);
                ((VObj *)eff)->vfunc_30(&self->rot);
            }
        }
        break;
    }
    self->rot.x = Angle_Approach(0, self->rot.x, 0x200, 1, 0x8000);
    self->rot.z = Angle_Approach(0, self->rot.z, 0x200, 1, 0x8000);
    self->look.x = Angle_Approach(self->rot.x, self->look.x, 0x466, 1, 0x8000);
    self->look2.x = Angle_Approach(self->rot.x, self->look2.x, 0x466, 1, 0x8000);
    self->look.y = Angle_Approach(self->look2.y, self->look.y, 0x466, 1, 0x8000);
    self->rot.y = Angle_Approach(self->look2.y, self->rot.y, 0x466, 1, 0x8000);
    Ov006Racer_Move(self);
    Model0218fe1c_SetAnimSpeed(self->model, (s16)(self->runSpeed + 0x333));
}

}
