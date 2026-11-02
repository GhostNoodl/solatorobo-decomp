#include "ov011/ov011.h"
#include "Main/Gfx/SlidePanel.h"

extern "C" {

extern const VecFx32 data_02092a50;
void func_ov000_0218996c(u8 a, u8 b);

#pragma force_active on
void func_ov011_02204a8c(Ov011Act7c4c *self) {
    VecFx32 v;
    if (self->fsm->st == 0) {
        func_ov000_0218996c(0xf, 0x3c);
        func_02049a48(data_02097e4c, 0x56, -1, -1, -1);
        func_02065f88(4, &self->pos)->SetScaleAll(0x3800);
    }
    func_ov003_021d6054(self);
    Ov011_MulVec33(&self->unk_f0, NNS_G3dGlbGetInvV(), &v);
    VEC_Add(&v, &data_02092a50, &self->pos);
}
#pragma force_active reset
}
