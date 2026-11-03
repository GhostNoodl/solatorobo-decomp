#include "ov000/VObj.h"
#include "ov000/ObjLayouts.h"
#include "nitro/mi.h"

extern "C" {


void Lo021cb0b8_Init(Lo021cb0b8 *self) {
    MI_CpuFill8(self->buf, 0, sizeof(self->buf));
    self->text = NULL;
    self->msgId = 0xffff;
    self->key = 0;
}

s32 Lo021cb0b8_Release(VObj *self) {
    return self->vfunc_28();
}

}
