#include "ov000/VObj.h"
#include "ov000/ModelPart.h"

#define LFLD(type, obj, off) (*(type *)((u8 *)(obj) + (off)))

extern "C" {

static inline BOOL IsVisible(VObj *self, s32 y) {
    if (y < LFLD(s16, self, 0x66) + self->vfunc_34() ||
        y > LFLD(s16, self, 0x66) + LFLD(s32, self, 0x28) - self->vfunc_38() - 0xc) {
        return FALSE;
    }
    return TRUE;
}

void func_ov000_021566c0(VObj *self, u8 *info, s32 x, s32 y, u8 polyId, u8 front) {
    Model *m = LFLD(Model *, self, 0xb8);
    if (m == NULL || LFLD(u16, info, 0x8) == 0xffff) {
        return;
    }
    if (front) {
        MODEL_FLAGS(m)->unk_19 = 1;
        LFLD(Model *, self, 0xb8)->unk_150 = LFLD(s16, self, 0x68) - 0x110;
        MODEL_FLAGS(LFLD(Model *, self, 0xb8))->unk_20 = 1;
    } else {
        MODEL_FLAGS(m)->unk_19 = 1;
        LFLD(Model *, self, 0xb8)->unk_150 = LFLD(s16, self, 0x68) - 0x80;
        MODEL_FLAGS(LFLD(Model *, self, 0xb8))->unk_20 = 0;
    }
    y = y + (self->vfunc_40() >> 1) - 0x61;
    x = x + (self->vfunc_8c() >> 1) - 0x80;
    Model_SetPos(LFLD(Model *, self, 0xb8), x << 12, y << 12);
    MODEL_FLAGS(LFLD(Model *, self, 0xb8))->polygon_id = polyId;
    MODEL_FLAGS(LFLD(Model *, self, 0xb8))->alpha = 0x1e;
    MODEL_FLAGS(LFLD(Model *, self, 0xb8))->unk_21 = 1;
    Model_PlayPart(LFLD(Model *, self, 0xb8), LFLD(u16, info, 0x8));
}

void func_ov000_0215683c(VObj *self, u8 *info, s32 x, s32 y, u8 polyId) {
    Model *m = LFLD(Model *, self, 0xbc);
    if (m == NULL || LFLD(u16, info, 0xa) == 0xffff) {
        return;
    }
    if (!IsVisible(self, y)) {
        return;
    }
    MODEL_FLAGS(LFLD(Model *, self, 0xbc))->unk_19 = 1;
    LFLD(Model *, self, 0xbc)->unk_150 = LFLD(s16, self, 0x68) - 0xa0;
    MODEL_FLAGS(LFLD(Model *, self, 0xbc))->unk_20 = 0;
    y = y + (self->vfunc_40() >> 1) - 0x62;
    x = x + LFLD(s32, LFLD(u8 *, info, 0x1c), 0x44) - 0x78 - (LFLD(s32, self, 0xd0) >> 12);
    Model_SetPos(LFLD(Model *, self, 0xbc), x << 12, y << 12);
    MODEL_FLAGS(LFLD(Model *, self, 0xbc))->polygon_id = polyId;
    MODEL_FLAGS(LFLD(Model *, self, 0xbc))->alpha = 0x1e;
    MODEL_FLAGS(LFLD(Model *, self, 0xbc))->unk_21 = 1;
    Model_PlayPart(LFLD(Model *, self, 0xbc), LFLD(u16, info, 0xa));
}

}
