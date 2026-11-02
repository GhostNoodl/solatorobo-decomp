#include "ov000/LoCommon.h"
#include "ov000/ModelPart.h"
#include "Main/Sys/FieldState.h"
#include "ov000/Vec.h"
#include "Main/Gfx/Model.h"
#include "Main/Res/ResArc.h"

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

struct Obj0216b550 {
    u8 unk_00[0x4];
    s32 unk_04;
    Model *unk_08;
    u8 unk_0c[0x8];
    s32 unk_14;
    s32 unk_18;
};

void func_ov000_0216b550(Obj0216b550 *self) {
    if (!LoGIdle() || !LoD78Idle()) {
        LBIT(self, 0).b1 = 0;
    }
    switch (self->unk_04) {
    case 2:
        self->unk_04 = 4;
        break;
    case 3:
        LO_FREE_M(self, 8);
        self->unk_04 = 4;
        break;
    case 4:
        if (!LBIT(self, 0).b1) {
            return;
        }
        LBIT(self, 0).b0 = 1;
        self->unk_04 = 5;
        break;
    case 5: {
        void *res = func_02034d88(func_02035d5c(data_0208cc94), data_0208cc88);
        Model *m = (Model *)Heap_Alloc(sizeof(Model));
        if (m) {
            const char *nm = data_0208cc88;
            func_02041218(&m->pltt);
            func_02041440(m, nm, 0);
        }
        self->unk_08 = m;
        func_020417e0(m, res);
        self->unk_08->flags |= 2;
        func_02041d9c(self->unk_08, 0, 0x22);
        func_02041d9c(self->unk_08, 0, 0x23);
        self->unk_08->flags |= 0x80000;
        self->unk_08->flags |= 0x200000;
        MODEL_FLAGS(self->unk_08)->alpha = 0x1e;
        self->unk_04 = 6;
        break;
    }
    case 6:
        if (!func_02054f10(self->unk_08, 0xffff)) {
            return;
        }
        self->unk_14 = 0;
        self->unk_18 = 0x1000;
        self->unk_04 = 8;
        break;
    case 7:
        if (!LBIT(self, 0).b2) {
            LBIT(self, 0).b1 = 0;
        }
        LBIT(self, 0).b2 = 0;
    case 8:
        if (!LBIT(self, 0).b1) {
            LBIT(self, 0).b0 = 0;
            self->unk_04 = 8;
        }
        if (self->unk_04 == 7) {
            return;
        }
        if (LBIT(self, 0).b0) {
            self->unk_14++;
            self->unk_18 = FX_Div(self->unk_14 << 12, 0xc000);
            if (self->unk_18 >= 0x1000) {
                self->unk_18 = 0x1000;
                self->unk_04 = 7;
            }
        } else {
            self->unk_14--;
            self->unk_18 = FX_Div(self->unk_14 << 12, 0xc000);
            if (self->unk_18 <= 0) {
                self->unk_18 = 0;
                self->unk_04 = 3;
            }
        }
        self->unk_18 = 0x1000 - FX_SinCosTable_[((self->unk_18 << 14) >> 16) * 2];
        break;
    }
}

}
