#include "ov000/LoCommon.h"
#include "Main/Sys/FieldState.h"
#include "ov000/ObjLayouts.h"

extern "C" {

extern s32 data_02097d78[5];
extern void *func_02049a48(void *mgr, s32 id, s32 a, s32 b, s32 c);
extern void *data_02097e4c;
extern void *data_ov000_021ccd44;
void *func_ov000_0218084c(void *a, s32 b, s32 c);

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

static inline s32 LoApproach(s32 cur, s32 target, s32 rate) {
    return cur + (s32)(((s64)(target - cur) * rate + 0x800) >> 12);
}
BOOL func_02054f10(void *a, s32 b);

BOOL func_ov000_0216a7dc(Lo021cb744 *self) {
    if (!LoGIdle() || !LoD78Idle()) {
        LBIT(self, 0xc).b1 = 1;
    }
    switch (self->unk_04) {
    case 6:
        self->unk_a4 = 0;
        if (!LBIT(self, 0xc).b1 ? TRUE : FALSE) {
            self->unk_04 = 0;
            return TRUE;
        }
        return FALSE;
    case 1:
        if (!func_02054f10(self->unk_9c, 0xffff) || !func_02054f10(self->unk_a0, 0xffff)) {
            return FALSE;
        }
        self->unk_a6 = 0;
        self->unk_a8 = 0;
        LBIT(self, 0xc).b3 = 1;
        LBIT(self, 0xc).b10 = 1;
        break;
    }
    return TRUE;
}

}
