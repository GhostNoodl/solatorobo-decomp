#include "ov006/SlotManager.h"
#include "ov006/ov006.h"
#include "nitro/fx.h"
#include "Main/Effect/Effect.h"
#include "Main/Gfx/SlidePanel.h"
#include "Main/Snd/SndMgr.h"
#include "ov006/Racer.h"


extern "C" {


void func_ov000_0218996c(u8 a, u8 b);
BOOL func_ov000_02198360(ActorSub40 *a, s32 b, s32 c);
void func_ov000_021911c8(void *a, s32 b);
s32 Rand_PlusMinus(s32 range);
u16 func_01ffc128(u16 target, u16 cur, s32 rate, u32 minStep, u16 maxStep);
void Ov006Racer_Move(Ov006Racer *self);

void Ov006Racer_StateCrash(Ov006Racer *self) {
    self->unk_44->unk_22_1 = 0;
    switch (self->fsm->st) {
    case 0: {
        EffectObj *eff;
        self->runSpeed >>= 1;
        self->turnMode = 0;
        eff = func_02065f88(0x322, &self->pos);
        if (eff != NULL) {
            EffectObj *old = func_020657b0(data_0214a420, self->unk_1e0);
            if (old != NULL) {
                EffectObj_StopLoop(old);
                old->state = 4;
            }
            self->unk_1e0 = eff->id;
            eff->speed = 0x1800;
        }
        func_02049f44(data_02097e4c, 0x79, &self->pos, 0);
        if (self->idx == data_ov006_021ec884->unk5) {
            func_ov000_0218996c(8, (u8)(self->unk_1f5 - 10));
        }
        self->fsm->st++;
        break;
    }
    case 1:
        if (self->unk_1f5 <= 10) {
            func_ov000_02198360(self->fsm, 2, 0);
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
            eff = func_02065f88(0x325, &at);
            if (eff != NULL) {
                ((VObj *)eff)->vfunc_0c(0xc00);
                ((VObj *)eff)->vfunc_30(&self->rot);
            }
        }
        break;
    }
    self->rot.x = func_01ffc128(0, self->rot.x, 0x200, 1, 0x8000);
    self->rot.z = func_01ffc128(0, self->rot.z, 0x200, 1, 0x8000);
    self->look.x = func_01ffc128(self->rot.x, self->look.x, 0x466, 1, 0x8000);
    self->look2.x = func_01ffc128(self->rot.x, self->look2.x, 0x466, 1, 0x8000);
    self->look.y = func_01ffc128(self->look2.y, self->look.y, 0x466, 1, 0x8000);
    self->rot.y = func_01ffc128(self->look2.y, self->rot.y, 0x466, 1, 0x8000);
    Ov006Racer_Move(self);
    func_ov000_021911c8(self->model, (s16)(self->runSpeed + 0x333));
}

}
