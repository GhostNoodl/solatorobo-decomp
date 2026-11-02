#include "ov002/ov002.h"
#include "ov000/ModelPart.h"

extern "C" {

void func_ov002_021cdf58(Task021ef530 *self) {
    if (self->unk_3c != NULL && func_02054f10(self->unk_3c, 0xffff)) {
        self->unk_3c->unk_150 = -0x1fe66;
        Model_PlayPart(self->unk_3c, 0);
    }
    if (self->fadeRatio == 0) {
        return;
    }
    func_ov000_0217357c(self);
    self->unk_40->vfunc_20();
    self->unk_44->vfunc_20();
}

}
