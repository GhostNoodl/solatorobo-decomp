#include "ov011/ov011.h"

extern "C" {

extern void *data_02097e4c;
extern VecFx32 data_02092a50;
void func_ov000_0218996c(s32 a, s32 b);
void *func_02049a48(void *a, s32 b, s32 c, s32 d, s32 e);
Ov011V *func_02065f88(s32 id, VecFx32 *v);

#pragma force_active on
void func_ov011_02204a8c(Ov011Act7c4c *self) {
    VecFx32 v;
    if (self->fsm->st == 0) {
        func_ov000_0218996c(0xf, 0x3c);
        func_02049a48(data_02097e4c, 0x56, -1, -1, -1);
        func_02065f88(4, &self->pos)->v0c(0x3800);
    }
    func_ov003_021d6054(self);
    Ov011_MulVec33(&self->unk_f0, NNS_G3dGlbGetInvV(), &v);
    VEC_Add(&v, &data_02092a50, &self->pos);
}
#pragma force_active reset
}
