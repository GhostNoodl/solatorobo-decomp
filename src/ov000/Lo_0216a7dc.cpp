#include "ov000/LoCommon.h"
#include "Main/Sys/FieldState.h"
#include "ov000/ObjLayouts.h"

extern "C" {

extern s32 gFadeState[5];
extern void *SndMgr_PlayVolume(void *mgr, s32 id, s32 a, s32 b, s32 c);
extern void *gSndMgr;
extern void *gTaskHost;
void *TaskHost_RequestSwitch(void *a, s32 b, s32 c);

static inline BOOL LoGBusy(FieldState *g) {
    return g->head != g->tail ? TRUE : FALSE;
}

static inline BOOL LoGIdle(void) {
    FieldState *g = gSceneCmd;
    if (g != NULL) {
        if (LoGBusy(g)) {
            return FALSE;
        }
        if (g->state != 3) {
            return FALSE;
        }
        return TRUE;
    }
    return TRUE;
}

static inline BOOL LoD78Idle(void) {
    return (gFadeState[3] == 0 && gFadeState[0] == 0) ? TRUE : FALSE;
}

static inline s32 LoApproach(s32 cur, s32 target, s32 rate) {
    return cur + (s32)(((s64)(target - cur) * rate + 0x800) >> 12);
}
BOOL Model_IsReady(void *a, s32 b);

BOOL Lo021cb744_CanUpdate(Lo021cb744 *self) {
    if (!LoGIdle() || !LoD78Idle()) {
        self->unk_0c_1 = 1;
    }
    switch (self->unk_04) {
    case 6:
        self->unk_a4 = 0;
        if (!self->unk_0c_1 ? TRUE : FALSE) {
            self->unk_04 = 0;
            return TRUE;
        }
        return FALSE;
    case 1:
        if (!Model_IsReady(self->unk_9c, 0xffff) || !Model_IsReady(self->unk_a0, 0xffff)) {
            return FALSE;
        }
        self->unk_a6 = 0;
        self->unk_a8 = 0;
        self->unk_0c_3 = 1;
        self->unk_0c_10 = 1;
        break;
    }
    return TRUE;
}

}
