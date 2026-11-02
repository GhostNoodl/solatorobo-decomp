#include "ov006/SlotManager.h"
#include "ov006/Racer.h"


extern "C" {

extern char data_ov006_021ec4a7[];
extern void *data_02097e4c;
u8 ov006_CountFinished(void);
BOOL func_ov000_02190cb0(void *a, const void *b, int c, int d);
void func_ov000_021915a0(void *a);
void func_ov000_021911c8(void *a, s16 b);
void Ov006Racer_UseItem(Ov006Racer *self);
void Ov006Racer_UpdateSpeed(Ov006Racer *self);
void Ov006Racer_UpdateSteer(Ov006Racer *self);
void Ov006Racer_Move(Ov006Racer *self);
s32 func_02049afc(void *a, s16 b);
void SndMgr_StopSeqArc(void *a);
void func_0204a094(void *a, s16 b, int c);

void Ov006Racer_UpdateRun(Ov006Racer *self) {
    if (Ov006Racer_IsOver(self) || ov006_CountFinished() <= 1) {
        self->unk_44->unk_22_1 = 0;
    }
    func_ov000_02190cb0(self->model, data_ov006_021ec4a7, 0x1000, 0);
    func_ov000_021915a0(self->model);
    self->unk_1cc++;
    Ov006Racer_UseItem(self);
    Ov006Racer_UpdateSpeed(self);
    Ov006Racer_UpdateSteer(self);
    Ov006Racer_Move(self);
    func_ov000_021911c8(self->model, (s16)(((s64)self->prm->unk_00 * (self->runSpeed + 0x333) + 0x800) >> 12));
    if (self->idx != data_ov006_021ec884->unk5) {
        return;
    }
    if (self->seq < 0) {
        self->seq = func_02049afc(data_02097e4c, self->prm->unk_02);
        return;
    }
    if (self->trig & 3) {
        SndMgr_StopSeqArc(data_02097e4c);
        self->seq = func_02049afc(data_02097e4c, self->prm->unk_02);
    }
    func_0204a094(data_02097e4c, self->seq, (self->runSpeed - 0xe66) >> 3);
}

}
