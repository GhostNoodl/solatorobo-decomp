#include "ov011/ov011.h"
#include "Main/Gfx/SlidePanel.h"

extern "C" {

extern const VecFx32 data_02092a50;
void Field_ShakeCamera(u8 a, u8 b);

#pragma force_active on
void Ov011Act7c4c_StateDie(Ov011Act7c4c *self) {
    VecFx32 v;
    if (self->fsm->st == 0) {
        Field_ShakeCamera(0xf, 0x3c);
        SndMgr_PlayVolume(data_02097e4c, 0x56, -1, -1, -1);
        Effect_SpawnId(4, &self->pos)->SetScaleAll(0x3800);
    }
    Ov003Actor_StateDie(self);
    Ov011_MulVec33(&self->unk_f0, NNS_G3dGlbGetInvV(), &v);
    VEC_Add(&v, &data_02092a50, &self->pos);
}
#pragma force_active reset
}
