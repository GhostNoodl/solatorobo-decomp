#include "ov000/VObj.h"
#include "ov000/ObjLayouts.h"
#include "nitro/mi.h"

extern "C" {


void func_ov000_0215e4fc(Lo021cb0b8 *self) {
    MI_CpuFill8(self->buf, 0, sizeof(self->buf));
    self->text = NULL;
    self->msgId = 0xffff;
    self->key = 0;
}

s32 func_ov000_0215e534(VObj *self) {
    return self->vfunc_28();
}

}
