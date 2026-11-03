#include "ov000/LoCommon.h"
#include "Main/Sys/FieldState.h"
#include "ov000/ObjLayouts.h"
#include "ov000/UiObj.h"

extern "C" {

extern void *gSndMgr;
extern s32 gFadeState[5];

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

void Lo021cad50_DrawBody(Lo021cad50 *self, void *a, s32 *pos, s32 d) {
    s32 i;
    if (a == NULL) {
        return;
    }
    if (self->flag3 ? TRUE : FALSE) {
        self->vfunc_68(a, pos, d);
    } else {
        self->vfunc_64(a, pos, d);
    }
    if (self->state != 2 && d != 0x1000) {
        return;
    }
    for (i = 0; i < 12; i++) {
        VObj *o = ((LoArr98 *)self)->o[i];
        if (o) {
            s32 x0 = LFLD(s32, o, 0x3c);
            s32 y0 = LFLD(s32, o, 0x40);
            o->vfunc_20(x0 + (pos[0] >> 12), y0 + (pos[1] >> 12));
            LFLD(s32, ((LoArr98 *)self)->o[i], 0x70) = self->posZ - 0x40;
            ((LoArr98 *)self)->o[i]->vfunc_90();
            ((LoArr98 *)self)->o[i]->vfunc_20(x0, y0);
        }
    }
    self->flags |= 0x200;
}

}
