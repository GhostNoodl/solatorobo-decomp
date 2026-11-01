#include "ov000/VObj.h"
#include "ov000/ModelPart.h"
#include "ov000/ObjLayouts.h"
#define LFLD(type, obj, off) (*(type *)((u8 *)(obj) + (off)))

extern "C" {
void func_02041c18(Model *m, u32 a);

void func_ov000_021c5d9c(Lo021cca40 *self) {
    s32 x;
    s32 y;
    if (self->unk_44 == 0) {
        return;
    }
    x = self->unk_0c >> 12;
    y = self->unk_10 >> 12;
    ((VObj *)self->unk_30)->vfunc_20(x + 10, y + 2);
    LFLD(s32, self->unk_30, 0x70) = self->unk_14;
    ((VObj *)self->unk_30)->vfunc_90();
    Model_SetPos(self->unk_34, (x + 2) << 12, (y - 0x5a) << 12);
    self->unk_34->unk_150 = self->unk_14;
    {
        Model *m = self->unk_34;
        Model_PlayPart(m, 7);
    }

    Model_SetPos(self->unk_34, (x + 0x14) << 12, (y - 0x5c) << 12);
    self->unk_34->unk_150 = self->unk_14;
    func_02041c18(self->unk_34, self->unk_3c);
    {
        Model *m = self->unk_34;
        Model_PlayPart(m, 6);
    }
    Model_SetPos(self->unk_34, (x + 0x42) << 12, (y - 0x5c) << 12);
    self->unk_34->unk_150 = self->unk_14;
    func_02041c18(self->unk_34, self->unk_40);
    {
        Model *m = self->unk_34;
        Model_PlayPart(m, 6);
    }
}
}
