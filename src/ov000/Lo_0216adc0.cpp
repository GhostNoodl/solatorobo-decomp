#include "ov000/LoCommon.h"
#include "ov000/MessageQueue.h"
#include "ov000/ModelPart.h"
#include "Main/Gfx/GfxMgr.h"
#include "Main/Gfx/Model.h"
#include "Main/Res/ResArc.h"
#include "Main/Sys/FieldState.h"

extern "C" {

void *func_ov000_0219bf90(void);
BOOL PauseNode_IsDrawPaused(void *a, s32 b);
s32 func_02043d84(void *a);

struct Obj0216adc0 {
    u32 unk_00;
    u8 unk_04[0x4];
    s32 unk_08;
    u8 unk_0c[0x4];
    s32 unk_10;
};

void func_ov000_0216adc0(Obj0216adc0 *self, s32 a, s32 b) {
    if (self->unk_08 == a) {
        self->unk_00 |= 6;
    } else {
        self->unk_00 &= ~2;
    }
    if (b < 0) {
        b = 0;
    } else if (b > 0x63) {
        b = 0x63;
    }
    self->unk_08 = a;
    self->unk_10 = b;
}

}

extern "C" {
extern MessageQueue021cb980 *data_ov000_021ccd30;
extern s32 data_02097d78[5];
extern const char *data_0208cc94;
extern const char *data_0208cc88;
BOOL func_02054f10(void *m, s32 id);
s32 FX_Div(s32 a, s32 b);

typedef struct {
    u32 b0 : 1;
    u32 b1 : 1;
    u32 b2 : 1;
    u32 rest : 29;
} Flags0216adf8;


static inline void *GetObj0216adf8(void) {
    ListBuffer021cb940 *o = data_ov000_021ccd30->unk_11c;
    return o != NULL ? o->unk_58 : NULL;
}

static inline BOOL Busy0216adf8(FieldState *p) {
    return p->head != p->tail ? TRUE : FALSE;
}

static inline BOOL Ready0216adf8(FieldState *p) {
    if (p != NULL) {
        if (Busy0216adf8(p)) {
            return FALSE;
        }
        if (p->state != 3) {
            return FALSE;
        }
        return TRUE;
    }
    return TRUE;
}

static inline BOOL Idle0216adf8(void) {
    return data_02097d78[3] == 0 && data_02097d78[0] == 0 ? TRUE : FALSE;
}

static inline BOOL SubFlag0216adf8(void *o) {
    return LFLD(Flags0216adf8, o, 0xc).b1 ? TRUE : FALSE;
}

struct Obj0216adf8 {
    Flags0216adf8 unk_00;
    s32 unk_04;
    u8 unk_08[0x4];
    Model *unk_0c;
    u8 unk_10[0x4];
    u16 unk_14;
    u8 unk_16[0x2];
    s32 unk_18;
    s32 unk_1c;
};

void func_ov000_0216adf8(Obj0216adf8 *self) {
    void *o = GetObj0216adf8();
    if (o == NULL) {
        return;
    }
    if (!Ready0216adf8(data_ov000_021ccd54) || !Idle0216adf8()) {
        self->unk_00.b1 = 0;
    }
    switch (self->unk_04) {
    case 0:
    case 1:
        break;
    case 2:
        self->unk_04 = 4;
        break;
    case 3:
        LO_FREE_M(self, 0xc);
        self->unk_04 = 4;
        break;
    case 4:
        if (SubFlag0216adf8(o)) {
            return;
        }
        if (self->unk_00.b1) {
            self->unk_00.b0 = TRUE;
            self->unk_04 = 5;
        }
        break;
    case 5: {
        void *res;
        Model *m;
        self->unk_14 = 0xc;
        res = func_02034d88(func_02035d5c(data_0208cc94), data_0208cc88);
        m = (Model *)Heap_Alloc(sizeof(Model));
        if (m != NULL) {
            const char *nm = data_0208cc88;
            func_02041218((struct PlttRes *)((u8 *)m + 0x88));
            func_02041440(m, nm, 0);
        }
        self->unk_0c = m;
        func_020417e0(m, res);
        self->unk_0c->flags |= 2;
        func_02041d9c(self->unk_0c, 0, 0xb);
        func_02041d9c(self->unk_0c, 0, self->unk_14);
        func_02041d9c(self->unk_0c, 0, 7);
        func_02041d9c(self->unk_0c, 0, 6);
        self->unk_0c->flags |= 0x80000;
        self->unk_0c->flags |= 0x200000;
        MODEL_FLAGS(self->unk_0c)->alpha = 0x1e;
        self->unk_04 = 6;
        break;
    }
    case 6:
        if (func_02054f10(self->unk_0c, 0xffff)) {
            self->unk_18 = 0;
            self->unk_1c = 0x1000;
            self->unk_04 = 8;
        }
        break;
    case 7:
        if (SubFlag0216adf8(o) || !self->unk_00.b2) {
            self->unk_00.b1 = 0;
        }
        self->unk_00.b2 = 0;
    case 8:
        if (!self->unk_00.b1) {
            self->unk_00.b0 = 0;
            self->unk_04 = 8;
        }
        if (self->unk_04 == 7) {
            return;
        }
        if (self->unk_00.b0) {
            self->unk_18++;
            self->unk_1c = FX_Div(self->unk_18 << 12, 0xc000);
            if (self->unk_1c >= 0x1000) {
                self->unk_1c = 0x1000;
                self->unk_04 = 7;
            }
        } else {
            self->unk_18--;
            self->unk_1c = FX_Div(self->unk_18 << 12, 0xc000);
            if (self->unk_1c <= 0) {
                self->unk_1c = 0;
                self->unk_04 = 3;
            }
        }
        self->unk_1c = 0x1000 - FX_SinCosTable_[((self->unk_1c << 14) >> 16) * 2];
        break;
    }
}

}
