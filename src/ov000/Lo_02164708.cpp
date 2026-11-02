#include "ov000/LoCommon.h"
#include "ov000/Vec.h"
#include "ov000/ObjLayouts.h"
#include "Main/Gfx/Model.h"
#include "ov000/ModelPart.h"
#include "ov000/MapCtx.h"

extern "C" {

extern s32 data_02097d78[5];
BOOL func_ov000_02190a30(void *p, s32 a);
void func_ov000_02190a80(void *p, s32 a);
void func_0203cb78(s32 a, s32 b, s32 c);

static inline BOOL LoIsMode4(void) {
    if (data_02097d78[3] == 4) {
        return TRUE;
    }
    return data_02097d78[1] == 4 ? TRUE : FALSE;
}

void func_ov000_02164708(void) {
    if (LoIsMode4()) {
        func_0203cb78(0x10000, 0, 1);
    }
}

void func_02041c20(void *a, int b, int c);
void func_ov000_0216715c(Lo021cb6b0 *self, Ctx0216607c *p);
void func_ov000_021675ec(Lo021cb6b0 *self, Ctx0216607c *p);

static inline void LoPlayIf(Model *m, int idx) {
    if (m != NULL) {
        Model_PlayPart(m, idx);
    }
}

static inline void LoTail(Lo021cb6b0 *self, Ctx0216607c *p) {
    Node0216607c *q;
    if (p == NULL || p->cur == NULL || (q = p->sel) == NULL) {
        return;
    }
    if (p->oamUsed < 2) {
        return;
    }
    if (!q->f3) {
        func_ov000_0216715c(self, p);
    } else {
        func_ov000_021675ec(self, p);
    }
}

void func_ov000_02164750(Lo021cb6b0 *self) {
    Model *m;
    VObj *o;
    if (self->unk_20 != 7) {
        return;
    }
    LoPlayIf(self->unk_28, 0);
    m = self->unk_24;
    if (m != NULL) {
        m->unk_10c = 0;
        m->unk_110 = 0;
        Model_PlayPart(self->unk_24, 0);
        func_02041c20(self->unk_24, 1, 0);
        Model_PlayPart(self->unk_24, 1);
        func_02041c20(self->unk_24, 1, 1);
        Model_PlayPart(self->unk_24, 1);
    }
    LoPlayIf(self->unk_2c, 0);
    o = self->unk_40;
    if (o != NULL && self->unk_4c != 0) {
        s32 y = LO_FX_MUL(FX_SinCosTable_[(((0x1000 - self->unk_4c) << 14) >> 16) * 2], 0x80000) >> 12;
        o->vfunc_20(y + 0xcc - (LFLD(s32, o, 0x44) >> 1), 1);
        self->unk_40->vfunc_90();
        self->unk_40->vfunc_94();
    }
    if (self->unk_34 == 10) {
        return;
    }
    LoTail(self, self->unk_30);
}

}
