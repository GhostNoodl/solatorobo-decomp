#include "ov000/LoCommon.h"
#include "Main/Sys/FieldState.h"
#include "ov000/ObjLayouts.h"

extern "C" {

extern void *func_02049a48(void *mgr, s32 id, s32 a, s32 b, s32 c);
extern void *data_02097e4c;
extern s32 data_02097d78[5];
BOOL func_02054f10(void *a, s32 b);

typedef struct {
    u8 pad[0x98];
    VObj *o[12];
} LoArr98;

static inline BOOL LoIsState5(void *o) {
    return LFLD(s32, o, 4) == 5 ? TRUE : FALSE;
}

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

BOOL func_ov000_021681fc(Lo021cb6f0 *self) {
    if (!LoGIdle() || !LoD78Idle()) {
        LBIT(self, 0xc).b1 = 1;
    }
    switch (self->unk_04) {
    case 6:
        if (!LBIT(self, 0xc).b1 ? TRUE : FALSE) {
            self->unk_04 = 0;
            return TRUE;
        }
        return FALSE;
    case 1:
        if (!func_02054f10(self->unk_9c, 0xffff)) {
            return FALSE;
        }
        LBIT(self, 0xc).b3 = 1;
        break;
    }
    return TRUE;
}

}
