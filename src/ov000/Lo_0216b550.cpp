#include "ov000/LoCommon.h"
#include "ov000/ModelPart.h"
#include "Main/Sys/FieldState.h"
#include "ov000/Vec.h"
#include "Main/Gfx/Model.h"
#include "Main/Res/ResArc.h"
#include "ov000/MessageQueue.h"

extern "C" {

extern s32 data_02097d78[5];
extern const char *data_0208cc94;
extern const char *data_0208cc88;
BOOL func_02054f10(void *a, s32 b);
s32 FX_Div(s32 a, s32 b);


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

void func_ov000_0216b550(Lo0216b474 *self) {
    if (!LoGIdle() || !LoD78Idle()) {
        self->want = 0;
    }
    switch (self->state) {
    case 2:
        self->state = 4;
        break;
    case 3:
        LO_FREE_M(self, 8);
        self->state = 4;
        break;
    case 4:
        if (!self->want) {
            return;
        }
        self->opening = 1;
        self->state = 5;
        break;
    case 5: {
        void *res = func_02034d88(func_02035d5c(data_0208cc94), data_0208cc88);
        Model *m = (Model *)Heap_Alloc(sizeof(Model));
        if (m) {
            const char *nm = data_0208cc88;
            func_02041218(&m->pltt);
            func_02041440(m, nm, 0);
        }
        self->model = m;
        func_020417e0(m, res);
        self->model->flags |= 2;
        func_02041d9c(self->model, 0, 0x22);
        func_02041d9c(self->model, 0, 0x23);
        self->model->flags |= 0x80000;
        self->model->flags |= 0x200000;
        MODEL_FLAGS(self->model)->alpha = 0x1e;
        self->state = 6;
        break;
    }
    case 6:
        if (!func_02054f10(self->model, 0xffff)) {
            return;
        }
        self->frame = 0;
        self->ratio = 0x1000;
        self->state = 8;
        break;
    case 7:
        if (!self->asked) {
            self->want = 0;
        }
        self->asked = 0;
    case 8:
        if (!self->want) {
            self->opening = 0;
            self->state = 8;
        }
        if (self->state == 7) {
            return;
        }
        if (self->opening) {
            self->frame++;
            self->ratio = FX_Div(self->frame << 12, 0xc000);
            if (self->ratio >= 0x1000) {
                self->ratio = 0x1000;
                self->state = 7;
            }
        } else {
            self->frame--;
            self->ratio = FX_Div(self->frame << 12, 0xc000);
            if (self->ratio <= 0) {
                self->ratio = 0;
                self->state = 3;
            }
        }
        self->ratio = 0x1000 - FX_SinCosTable_[((self->ratio << 14) >> 16) * 2];
        break;
    }
}

}
