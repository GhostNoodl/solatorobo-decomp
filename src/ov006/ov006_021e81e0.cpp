#include "ov006/SlotManager.h"
#include "ov006/Racer.h"


extern "C" {

extern char data_ov006_021ec4a7[];
extern void *data_02097e4c;
u8 func_ov006_021d8cb8(void);
BOOL func_ov000_02190cb0(void *a, const void *b, int c, int d);
void func_ov000_021915a0(void *a);
void func_ov000_021911c8(void *a, s16 b);
void func_ov006_021e9c5c(Ov006Racer *self);
void func_ov006_021e86dc(Ov006Racer *self);
void func_ov006_021e8ef8(Ov006Racer *self);
void func_ov006_021e96cc(Ov006Racer *self);
s32 func_02049afc(void *a, s16 b);
void SndMgr_StopSeqArc(void *a);
void func_0204a094(void *a, s16 b, int c);

void func_ov006_021e81e0(Ov006Racer *self) {
    if (Ov006Racer_IsOver(self) || func_ov006_021d8cb8() <= 1) {
        self->unk_44->unk_22_1 = 0;
    }
    func_ov000_02190cb0(self->model, data_ov006_021ec4a7, 0x1000, 0);
    func_ov000_021915a0(self->model);
    self->unk_1cc++;
    func_ov006_021e9c5c(self);
    func_ov006_021e86dc(self);
    func_ov006_021e8ef8(self);
    func_ov006_021e96cc(self);
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
