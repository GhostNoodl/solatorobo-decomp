#include "ov000/VObj.h"
#include "ov000/ModelPart.h"
#include "ov000/ObjLayouts.h"

#define LFLD(type, obj, off) (*(type *)((u8 *)(obj) + (off)))

extern "C" {
void func_02041c18(Model *m, s32 a);

void func_ov000_0215a358(Lo021cb5a8 *self, s32 enable, s32 *pos) {
    s16 z;
    u8 *item;
    s32 ox;
    s32 oy;
    s32 x;
    s32 y;
    if (enable == 0) {
        return;
    }
    z = self->posZ - 0x80;
    item = self->unk_94;
    ox = self->vfunc_30();
    oy = self->vfunc_34();
    if (item == NULL) {
        return;
    }
    do {
        x = LFLD(s32, item, 0x14) + (ox + (pos[0] >> 12));
        y = LFLD(s32, item, 0x18) + (oy + (pos[1] >> 12));
        if (LFLD(u16, item, 0x6) != 0) {
            MODEL_FLAGS(self->unk_10)->unk_19 = 0;
            self->unk_10->unk_150 = z;
            Model_SetPos(self->unk_10, (x - 0x84) << 12, (y - 0x61) << 12);
            func_02041c18(self->unk_10, LFLD(u16, item, 0x6));
            Model_PlayPart(self->unk_10, 2);
        }
        if (LFLD(VObj *, item, 0x1c) != NULL) {
            LFLD(s32, LFLD(VObj *, item, 0x1c), 0x70) = z;
            LFLD(VObj *, item, 0x1c)->vfunc_20(x + 0xc, y);
            LFLD(VObj *, item, 0x1c)->vfunc_90();
        }
        item = LFLD(u8 *, item, 0x2c);
    } while (item != NULL);
}

}
