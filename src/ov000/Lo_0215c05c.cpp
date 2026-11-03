#include "ov000/LoCommon.h"
#include "ov000/ObjLayouts.h"
#include "ov000/UiObj.h"
#include "Main/Gfx/GfxMgr.h"
#include "Main/Gfx/PlttRes.h"

extern "C" {

extern void *data_02097e4c;
extern void *data_02149ef8;
void *SndMgr_PlayVolume(void *p, s32 a, s32 b, s32 c, s32 d);
BOOL Model_IsReady(void *p, s32 a);
u16 func_02061d54(u16 a);
s32 MsgRes_GetString(void *p, s32 a);
s32 Text_Measure(s32 a, s32 b, s32 c, void *d, void *e, s32 f);

typedef struct {
    u8 pad[0x98];
    VObj *arr[12];
} LoArr98;

void Lo021cadcc_PostUpdate(Lo021cadcc *self) {
    if (self->state != 2) {
        return;
    }
    if (self->hidden == 1) {
        self->state = 1;
    }
    self->openTime = self->openLen;
    self->openRatio = 0x1000;
    if (self->unk_84 != NULL && !self->unk_84->vfunc_8c()) {
        self->flags |= 0x40000;
    }
}

}
