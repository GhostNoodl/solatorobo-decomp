#include "ov000/LoCommon.h"
#include "nitro/fx.h"
#include "Main/Gfx/Model.h"
#include "ov000/ModelPart.h"



extern "C" {

void func_02041c18(void *m, int a);
void func_ov000_0216d9dc(void *self, s32 unused, u16 *msg);

static inline void LoSetPos(void *m, s32 x, s32 y) {
    LFLD(s32, m, 0xfc) = x;
    LFLD(s32, m, 0x100) = y;
}

struct Obj0216df28 {
    u8 unk_00[0x4];
    s32 unk_04;
    u8 unk_8[0x8];
    Model *unk_10;
    Model *unk_14;
    u8 unk_18[0x8];
    s32 unk_20;
    u8 unk_24[0x4];
    s32 unk_28;
    u8 unk_2c[0x4];
    s32 unk_30;
    u8 unk_34[0x8];
    s32 unk_3c;
    u8 unk_40[0xc];
    s32 unk_4c;
};

static inline void LoPlace(Obj0216df28 *self, s32 x, s32 y) {
    MODEL_FLAGS(self->unk_10)->unk_21 = 1;
    self->unk_10->unk_150 = -0x1f80;
    LoSetPos(self->unk_10, x << 12, y << 12);
}
static inline void LoPlace2(u8 *self, s32 z, s32 x, s32 y) {
    MODEL_FLAGS(LFLD(Model *, self, 0x10))->unk_21 = 1;
    LFLD(Model *, self, 0x10)->unk_150 = z;
    LoSetPos(LFLD(Model *, self, 0x10), x << 12, y << 12);
}

void func_ov000_0216df28(Obj0216df28 *self) {
    Model *m;
    s32 st = self->unk_04;
    s32 s;
    if (st != 7 && st != 8 && st != 9) {
        return;
    }
    {
        s32 y;
        s32 x;
        x = (LO_FX_MUL(self->unk_30, 0x80000) >> 12) - 0x80;
        y = (self->unk_4c - 0x60000) >> 12;
        if (LBIT(self, 0).b10 == 1) {
            LoPlace(self, x + 0xbd, y + 0x1e + (self->unk_3c >> 12));
            Model_PlayPart(self->unk_10, 0xf);
            MODEL_FLAGS(self->unk_10)->unk_21 = 0;
        }
        MODEL_FLAGS(self->unk_10)->alpha = 0x1e;
        self->unk_10->unk_150 = -0x2000;
        LoSetPos(self->unk_10, (x + 0xff) << 12, (y + 0x18) << 12);
        Model_PlayPart(self->unk_10, 0xc);
        func_02041c18(self->unk_14, self->unk_20);
        LoSetPos(self->unk_14, (x + 0xf7) << 12, (y + 0x24) << 12);
        m = self->unk_14;
        Model_PlayPart(m, 0x1f);
        if (LBIT(self, 0).b8 == 1) {
            s = LO_FX_MUL(self->unk_3c, 0x1000);
            MTX_Identity22_(&self->unk_14->mtx[0]);
            MTX_ScaleApply22(&self->unk_14->mtx[0], &self->unk_14->mtx[0], s + 0x1000, s + 0x1000);
            self->unk_14->color = 0x1098;
            Model_PlayPartF(self->unk_14, 0x1e, 1);
        } else {
            if (LBIT(self, 0).b9 == 1) {
                self->unk_14->color = 0x1098;
            }
            Model_PlayPart(self->unk_14, 0x1e);
        }
        self->unk_14->color = 0x7fff;
        if (self->unk_28 == 0) {
            return;
        }
        LoSetPos(self->unk_14, (x + 0xc9) << 12, (y + 9) << 12);
        Model_PlayPart(self->unk_14, 0x20);
        func_02041c18(self->unk_14, self->unk_28);
        LoSetPos(self->unk_14, (x + 0xf7) << 12, (y + 0xf) << 12);
        Model_PlayPart(self->unk_14, 0x1f);
        if (LBIT(self, 0).b11 == 1) {
            LFLD(void *, self->unk_14, 0x15c) = (void *)func_ov000_0216d9dc;
            if (LBIT(self, 0).b12 == 1) {
                self->unk_14->color = 0x7792;
            }
            Model_PlayPartF(self->unk_14, 0x1e, 1);
            self->unk_14->color = 0x7fff;
            LFLD(s32, self->unk_14, 0x15c) = 0;
        } else {
            Model_PlayPart(self->unk_14, 0x1e);
        }
    }
}

}
