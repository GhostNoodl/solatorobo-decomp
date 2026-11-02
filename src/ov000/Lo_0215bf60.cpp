#include "ov000/LoCommon.h"
#include "Main/Sys/FieldState.h"
#include "ov000/ObjLayouts.h"
#include "ov000/UiObj.h"

extern "C" {

extern void *func_02049a48(void *mgr, s32 id, s32 a, s32 b, s32 c);
extern void *data_02097e4c;
extern s32 data_02097d78[5];

typedef struct {
    u8 pad[0x98];
    VObj *o[12];
} LoArr98;

static inline BOOL LoGBusy(FieldState *g) {
    return g->head != g->tail ? TRUE : FALSE;
}

static inline BOOL LoGIdle(void) {
    FieldState *g = data_ov000_021ccd54;
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
    return (data_02097d78[3] == 0 && data_02097d78[0] == 0) ? TRUE : FALSE;
}

void func_ov000_0215bf60(Lo021cadcc *self) {
    switch (self->state) {
    case 5:
        if (self->hidden == 1) {
            LO_FREE_V(self, 0x84);
        }
        break;
    case 0:
        if (self->flag4 ? TRUE : FALSE) {
            func_02049a48(data_02097e4c, 0x27, -1, -1, -1);
        }
        break;
    case 1:
        if (self->flag4 ? TRUE : FALSE) {
            func_02049a48(data_02097e4c, 0x27, -1, -1, -1);
        }
        break;
    }
}

}
