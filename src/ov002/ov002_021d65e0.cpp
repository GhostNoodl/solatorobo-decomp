#include "ov002/ov002.h"
#include "ov000/ModelPart.h"

extern "C" {

void func_ov002_021d65e0(Task021efc24 *self) {
    if (!self->vfunc_28()) {
        return;
    }
    Model_PlayPart(self->unk_3c, 0);
    self->unk_4c->vfunc_20();
    self->unk_50->vfunc_20();
    self->unk_54->vfunc_20();
    func_ov000_02162a58(self->unk_58);
    if (self->unk_5c != NULL) {
        func_ov000_02163594(self->unk_5c);
    }
}

}
