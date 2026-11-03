#include "ov006/SlotManager.h"
#include "ov006/Racer.h"


extern "C" {

extern char data_ov006_021ec4a7[];
extern void *gSndMgr;
u8 ov006_CountFinished(void);
BOOL Model0218fe1c_SetAnim(void *a, const void *b, int c, int d);
void Model0218fe1c_SetLoop(void *a);
void Model0218fe1c_SetAnimSpeed(void *a, s16 b);
void Ov006Racer_UseItem(Ov006Racer *self);
void Ov006Racer_UpdateSpeed(Ov006Racer *self);
void Ov006Racer_UpdateSteer(Ov006Racer *self);
void Ov006Racer_Move(Ov006Racer *self);
s32 SndMgr_StartSeqArc(void *a, s16 b);
void SndMgr_StopSeqArc(void *a);
void SndMgr_SetSlotPitch(void *a, s16 b, int c);

void Ov006Racer_UpdateRun(Ov006Racer *self) {
    if (Ov006Racer_IsOver(self) || ov006_CountFinished() <= 1) {
        self->unk_44->unk_22_1 = 0;
    }
    Model0218fe1c_SetAnim(self->model, data_ov006_021ec4a7, 0x1000, 0);
    Model0218fe1c_SetLoop(self->model);
    self->unk_1cc++;
    Ov006Racer_UseItem(self);
    Ov006Racer_UpdateSpeed(self);
    Ov006Racer_UpdateSteer(self);
    Ov006Racer_Move(self);
    Model0218fe1c_SetAnimSpeed(self->model, (s16)(((s64)self->prm->unk_00 * (self->runSpeed + 0x333) + 0x800) >> 12));
    if (self->idx != gOv006SlotManager->unk5) {
        return;
    }
    if (self->seq < 0) {
        self->seq = SndMgr_StartSeqArc(gSndMgr, self->prm->unk_02);
        return;
    }
    if (self->trig & 3) {
        SndMgr_StopSeqArc(gSndMgr);
        self->seq = SndMgr_StartSeqArc(gSndMgr, self->prm->unk_02);
    }
    SndMgr_SetSlotPitch(gSndMgr, self->seq, (self->runSpeed - 0xe66) >> 3);
}

}
