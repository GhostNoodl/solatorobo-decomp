#include "ov006/SlotManager.h"
#include "Main/Effect/Effect.h"
#include "Main/Gfx/SlidePanel.h"
#include "Main/Snd/SndMgr.h"
#include "ov006/Racer.h"


extern "C" {

extern const u8 data_ov006_021eb918[][6];

void Ov006Racer_UpdateCpuItem(Ov006Racer *self) {
    if (self->unk_1aa == 0 && self->unk_1ab == 0) {
        self->unk_1ab = data_ov006_021eb918[self->rank][self->unk_1ac];
        self->unk_1ac++;
        if (self->unk_1ac > 6) {
            self->unk_1ac = 0;
        }
    }
    if (data_ov006_021ec884->unk13D != 0) {
        return;
    }
    if (++self->unk_21e[2] > 99) {
        self->unk_21e[2] = 99;
    }
    if (self->unk_19c_0 & 1) {
        EffectObj *fx = Effect_SpawnId(0x196, &self->pos);
        if (fx != NULL) {
            self->unk_1d0 = fx->id;
            fx->speed = 0x2800;
        }
        SndMgr_PlayAt(data_02097e4c, 0x85, &self->pos, 0);
    }
}

}
