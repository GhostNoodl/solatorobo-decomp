#include "ov000/LoCommon.h"
#include "Main/Sys/FieldState.h"
#include "ov000/ObjLayouts.h"

extern "C" {

extern void *gSndMgr;
extern s32 gFadeState[5];
BOOL Model_IsReady(void *a, s32 b);

typedef struct {
    u8 pad[0x98];
    VObj *o[12];
} LoArr98;

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

BOOL Lo021cb6f0_CanUpdate(Lo021cb6f0 *self) {
    if (!LoGIdle() || !LoD78Idle()) {
        self->unk_0c_1 = 1;
    }
    switch (self->unk_04) {
    case 6:
        if (!self->unk_0c_1 ? TRUE : FALSE) {
            self->unk_04 = 0;
            return TRUE;
        }
        return FALSE;
    case 1:
        if (!Model_IsReady(self->unk_9c, 0xffff)) {
            return FALSE;
        }
        self->unk_0c_3 = 1;
        break;
    }
    return TRUE;
}

}
