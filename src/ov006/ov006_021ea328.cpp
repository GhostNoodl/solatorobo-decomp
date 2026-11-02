#include "ov006/SlotManager.h"
#include "Main/Effect/Effect.h"
#include "Main/Gfx/SlidePanel.h"
#include "Main/Snd/SndMgr.h"
#include "ov006/Racer.h"


extern "C" {


void Ov006Racer_AddBoost(Ov006Racer *self) {
    self->boost += 3000;
    if (self->boost > 30000) {
        self->boost = 30000;
    }
    if (data_ov006_021ec884->unk13D != 0) {
        return;
    }
    if (++self->unk_21e[1] > 99) {
        self->unk_21e[1] = 99;
    }
    if (self->unk_19c_0 & 1) {
        EffectObj *fx = Effect_SpawnId(0x195, &self->pos);
        if (fx != NULL) {
            self->unk_1d0 = fx->id;
            fx->speed = 0x2800;
        }
        SndMgr_PlayAt(data_02097e4c, 0x11, &self->pos, 0);
    }
}

}
