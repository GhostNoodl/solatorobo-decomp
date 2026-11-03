#include "ov000/LoCommon.h"
#include "ov000/ObjLayouts.h"
#include "ov000/UiObj.h"

extern "C" {

BOOL Model_IsReady(void *a, s32 b);
extern void *SndMgr_PlayVolume(void *mgr, s32 id, s32 a, s32 b, s32 c);
extern void *gSndMgr;
BOOL func_ov000_02151664(UiList *p, UiListItem *msg);

void LoBase021cafc0_021cb0b8_DrawBody(LoBase021cafc0_021cb0b8 *self, void *a, void *b, s32 d) {
    if (a == NULL) {
        return;
    }
    if (self->flags & 0x80000) {
        self->vfunc_d4(d, b, d);
    }
    if (self->flag3 ? TRUE : FALSE) {
        self->vfunc_68(a, b, d);
    } else {
        self->vfunc_64(a, b, d);
    }
    self->vfunc_e8(a, b, d);
    self->vfunc_d8(a, b, d);
    if (Model_IsReady(self->model, 0xffff)) {
        self->vfunc_60(a, b, d);
        self->flags |= 0x200;
    }
}

}
