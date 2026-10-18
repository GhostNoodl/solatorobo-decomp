#include "ov000/TaskList.h"

extern "C" {

void func_ov000_02173528(void) {
}

BOOL func_ov000_0217352c(Task *self) {
    if (self->vfunc_54()) {
        if (data_ov000_021ccd34.unk_0c != NULL) {
            data_ov000_021ccd34.unk_04 = data_ov000_021ccd34.unk_0c->id;
        } else {
            data_ov000_021ccd34.unk_04 = 0;
        }
        data_ov000_021ccd34.unk_0c = NULL;
    }
    return TRUE;
}

void func_ov000_02173574(void) {
}

void func_ov000_02173578(void) {
}

void func_ov000_0217357c(Task *self) {
    VecFx32 scale;
    func_02043d20(data_02097d48 + 0x8b0, 0);
    scale.x = 0x1000;
    scale.y = 0x1000;
    scale.z = 0x1000;
    NNS_G3dGeBufferOP_N(0x1b, &scale, 3);
    self->unk_28 = FX_SinCosTable_[((self->unk_24 << 14) >> 16) * 2];
}

}
