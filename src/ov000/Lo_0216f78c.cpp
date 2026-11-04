#include "ov000/LoCommon.h"

extern "C" {

extern void *gSndMgr;
void *SndMgr_PlayVolume(void *p, s32 a, s32 b, s32 c, s32 d);
void BufferList_Run(void *p, s32 a);

void MessageQueue_Update(VObj *self) {
    u8 buf[0x10];
    self->vfunc_1c();
    while (self->vfunc_14(buf, 1)) {
        self->vfunc_10(buf);
    }
    BufferList_Run((u8 *)self + 8, 0);
}

}
