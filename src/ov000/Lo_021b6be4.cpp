#include "types.h"
#include "Main/Sys/FieldState.h"
#include "ov000/VObj.h"
#include "ov000/FieldMgr.h"

extern "C" {
void func_0204b924(Camera *cam, s32 speed);

static inline BOOL IsBusy021b6be4(FieldState *m) {
    return m->head != m->tail ? TRUE : FALSE;
}

static inline BOOL IsIdle021b6be4(FieldState *m) {
    BOOL r;
    if (m != NULL) {
        if (IsBusy021b6be4(m)) {
            r = FALSE;
        } else if (m->state != 3) {
            r = FALSE;
        } else {
            r = TRUE;
        }

    } else {
        r = TRUE;
    }
    return r;
}

void FieldMgr_StepCameraAnim(FieldMgr *self) {
    FieldState *m;
    Camera *s;
    if (self->unk_1f2 == 0) {
        return;
    }
    m = gSceneCmd;
    s = &m->cam.base;
    if (s == NULL) {
        return;
    }
    {
        s32 v = 0x1000;
        if (!IsIdle021b6be4(m)) {
            v = 0;
        }
        func_0204b924(s, v);
    }
}
}
