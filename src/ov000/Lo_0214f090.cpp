#include "ov000/LoCommon.h"
#include "Main/Sys/FieldState.h"
#include "ov000/ObjLayouts.h"

extern "C" {

void func_ov000_02172f7c(Task *self, void *arg);
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

void func_ov000_0214f090(Lo021caa44 *self, void *arg) {
    BOOL ok = TRUE;
    void *q;
    if (self->unk_50 && !LoIsState5(self->unk_50)) {
        ok = FALSE;
    }
    q = self->unk_4c;
    if (q && !LoIsState5(q)) {
        ok = FALSE;
    }
    if ((void *)self->unk_5c && !LoIsState5(self->unk_5c)) {
        ok = FALSE;
    }
    if ((void *)self->unk_60 && !LoIsState5(self->unk_60)) {
        ok = FALSE;
    }
    if (ok) {
        func_ov000_02172f7c(self, arg);
        return;
    }
    if (q) {
        LBIT(q, 0xc).b1 = 1;
    }
    if (self->unk_50) {
        self->unk_50->hidden = 1;
    }
    if (self->unk_5c) {
        LBIT(self->unk_5c, 0xc).b1 = 1;
    }
    if (self->unk_60) {
        self->unk_60->hidden = 1;
    }
}

}
