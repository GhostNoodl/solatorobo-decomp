#include "ov000/ObjLayouts.h"

extern "C" {

void Lo021cb840_Init(Lo021cb840 *self) {
    self->unk_a8 = 0x0;
    self->unk_9c = 0x0;
    self->unk_a0 = 0x0;
    self->unk_a4 = 0x0;
}

s32 Lo021cb840_Release(VObj *self) {
    return self->vfunc_14();
}

void Lo021cb840_Unload(Lo021cb840 *self) {
    self->unk_0c &= ~0x8;
}

}
