#include "ov000/VObj.h"
#include "ov000/ModelPart.h"
#include "ov000/ObjLayouts.h"
#include "ov000/UiObj.h"

#define LFLD(type, obj, off) (*(type *)((u8 *)(obj) + (off)))

extern "C" {

static inline BOOL IsVisible(UiList *self, s32 y) {
    if (y < self->posY + self->vfunc_34() ||
        y > self->posY + self->height - self->vfunc_38() - 0xc) {
        return FALSE;
    }
    return TRUE;
}

struct Obj021566c0 : public VObj {
    u8 unk_04[0x64];
    s16 unk_68;
    u8 unk_6a[0x4e];
    Model *unk_b8;
};

void func_ov000_021566c0(Obj021566c0 *self, u8 *info, s32 x, s32 y, u8 polyId, u8 front) {
    Model *m = self->unk_b8;
    if (m == NULL || LFLD(u16, info, 0x8) == 0xffff) {
        return;
    }
    if (front) {
        MODEL_FLAGS(m)->unk_19 = 1;
        self->unk_b8->unk_150 = self->unk_68 - 0x110;
        MODEL_FLAGS(self->unk_b8)->unk_20 = 1;
    } else {
        MODEL_FLAGS(m)->unk_19 = 1;
        self->unk_b8->unk_150 = self->unk_68 - 0x80;
        MODEL_FLAGS(self->unk_b8)->unk_20 = 0;
    }
    y = y + (self->vfunc_40() >> 1) - 0x61;
    x = x + (self->vfunc_8c() >> 1) - 0x80;
    Model_SetPos(self->unk_b8, x << 12, y << 12);
    MODEL_FLAGS(self->unk_b8)->polygon_id = polyId;
    MODEL_FLAGS(self->unk_b8)->alpha = 0x1e;
    MODEL_FLAGS(self->unk_b8)->unk_21 = 1;
    Model_PlayPart(self->unk_b8, LFLD(u16, info, 0x8));
}

void func_ov000_0215683c(UiList *self, u8 *info, s32 x, s32 y, u8 polyId) {
    Model *m = self->unk_bc;
    if (m == NULL || LFLD(u16, info, 0xa) == 0xffff) {
        return;
    }
    if (!IsVisible(self, y)) {
        return;
    }
    MODEL_FLAGS(self->unk_bc)->unk_19 = 1;
    self->unk_bc->unk_150 = self->posZ - 0xa0;
    MODEL_FLAGS(self->unk_bc)->unk_20 = 0;
    y = y + (self->vfunc_40() >> 1) - 0x62;
    x = x + LFLD(s32, LFLD(u8 *, info, 0x1c), 0x44) - 0x78 - (self->unk_d0 >> 12);
    Model_SetPos(self->unk_bc, x << 12, y << 12);
    MODEL_FLAGS(self->unk_bc)->polygon_id = polyId;
    MODEL_FLAGS(self->unk_bc)->alpha = 0x1e;
    MODEL_FLAGS(self->unk_bc)->unk_21 = 1;
    Model_PlayPart(self->unk_bc, LFLD(u16, info, 0xa));
}

}
