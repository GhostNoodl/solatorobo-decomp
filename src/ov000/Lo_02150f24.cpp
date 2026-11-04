#include "ov000/LoCommon.h"
#include "ov000/ObjLayouts.h"
#include "Main/Sys/Pad.h"

extern "C" {

BOOL Model_IsReady(void *a, s32 b);
extern void *SndMgr_PlayVolume(void *mgr, s32 id, s32 a, s32 b, s32 c);
extern void *gSndMgr;
void UiObj_OpenChoice(UiList *self, s32 a, s32 b, void *cb);
BOOL QuestWin_AcceptOnDecide(UiList *p, UiListItem *msg);

void QuestWin_UpdateActive(Lo021ca9c4 *self) {
    u16 k;
    Lo021caac8 *p;
    if (self->unk_58) {
        return;
    }
    if ((void *)self->unk_50 == NULL) {
        return;
    }
    self->unk_50->flag2 = 0;
    p = self->unk_50;
    if (!(p->busy ? FALSE : TRUE)) {
        return;
    }
    k = gPad->trig;
    if (k & 1) {
        if (self->unk_42 == 0xffff) {
            return;
        }
        UiObj_OpenChoice(p, 0x8e, 0x18, (void *)QuestWin_AcceptOnDecide);
        return;
    }
    if (!(k & 2)) {
        return;
    }
    SndMgr_PlayVolume(gSndMgr, 0x1f, -1, -1, -1);
    self->vfunc_0c(0);
}

}
