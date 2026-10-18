#include "ov000/VObj.h"
#include "ov000/ModelPart.h"

#define LFLD(type, obj, off) (*(type *)((u8 *)(obj) + (off)))

extern "C" {
void func_02041c18(Model *m, s32 a);

void func_ov000_0214e074(VObj *self, u8 *info, s32 x, s32 y, u8 polyId, u8 front) {
    s32 id;
    u16 n;
    if (LFLD(Model *, self, 0xb4) == NULL || LFLD(Model *, self, 0xb8) == NULL || LFLD(u16, info, 0x8) == 0xffff) {
        return;
    }
    if (front) {
        MODEL_FLAGS(LFLD(Model *, self, 0xb8))->unk_19 = 1;
        LFLD(Model *, self, 0xb8)->unk_150 = LFLD(s16, self, 0x68) - 0x110;
        MODEL_FLAGS(LFLD(Model *, self, 0xb8))->unk_20 = 1;
        MODEL_FLAGS(LFLD(Model *, self, 0xb4))->unk_19 = 1;
        LFLD(Model *, self, 0xb4)->unk_150 = LFLD(s16, self, 0x68) - 0x110;
        MODEL_FLAGS(LFLD(Model *, self, 0xb4))->unk_20 = 1;
    } else {
        MODEL_FLAGS(LFLD(Model *, self, 0xb8))->unk_19 = 1;
        LFLD(Model *, self, 0xb8)->unk_150 = LFLD(s16, self, 0x68) - 0x80;
        MODEL_FLAGS(LFLD(Model *, self, 0xb8))->unk_20 = 0;
        MODEL_FLAGS(LFLD(Model *, self, 0xb4))->unk_19 = 1;
        LFLD(Model *, self, 0xb4)->unk_150 = LFLD(s16, self, 0x68) - 0x80;
        MODEL_FLAGS(LFLD(Model *, self, 0xb4))->unk_20 = 0;
    }
    x -= 3;
    x += (self->vfunc_8c() >> 1) - 0x80;
    y += (self->vfunc_40() >> 1) - 0x61;
    id = polyId & 0x3f;
    MODEL_FLAGS(LFLD(Model *, self, 0xb4))->polygon_id = id;
    MODEL_FLAGS(LFLD(Model *, self, 0xb4))->alpha = 0x1e;
    MODEL_FLAGS(LFLD(Model *, self, 0xb4))->unk_21 = 1;
    n = LFLD(u16, info, 0x34);
    if (LFLD(u16, info, 0x8) == 0xb) {
        Model_SetPos(LFLD(Model *, self, 0xb4), (x + 6) << 12, (y - 2) << 12);
        if (n == 0) {
            n = 1;
        }
        func_02041c18(LFLD(Model *, self, 0xb4), n);
        Model_PlayPart(LFLD(Model *, self, 0xb4), 0x1e);
    }
    Model_SetPos(LFLD(Model *, self, 0xb8), (x - 1) << 12, (y - 1) << 12);
    MODEL_FLAGS(LFLD(Model *, self, 0xb8))->polygon_id = id;
    MODEL_FLAGS(LFLD(Model *, self, 0xb8))->alpha = 0x1e;
    MODEL_FLAGS(LFLD(Model *, self, 0xb8))->unk_21 = 1;
    Model_PlayPart(LFLD(Model *, self, 0xb8), LFLD(u16, info, 0x8));
}

}
