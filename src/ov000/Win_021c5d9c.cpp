#include "ov000/VObj.h"
#include "ov000/ModelPart.h"
#define LFLD(type, obj, off) (*(type *)((u8 *)(obj) + (off)))

extern "C" {
void func_02041c18(Model *m, u32 a);

void func_ov000_021c5d9c(u8 *self) {
    s32 x;
    s32 y;
    if (LFLD(u8, self, 0x44) == 0) {
        return;
    }
    x = LFLD(s32, self, 0xc) >> 12;
    y = LFLD(s32, self, 0x10) >> 12;
    LFLD(VObj *, self, 0x30)->vfunc_20(x + 10, y + 2);
    LFLD(s32, LFLD(VObj *, self, 0x30), 0x70) = LFLD(s32, self, 0x14);
    LFLD(VObj *, self, 0x30)->vfunc_90();
    Model_SetPos(LFLD(Model *, self, 0x34), (x + 2) << 12, (y - 0x5a) << 12);
    LFLD(Model *, self, 0x34)->unk_150 = LFLD(s32, self, 0x14);
    {
        Model *m = LFLD(Model *, self, 0x34);
        Model_PlayPart(m, 7);
    }

    Model_SetPos(LFLD(Model *, self, 0x34), (x + 0x14) << 12, (y - 0x5c) << 12);
    LFLD(Model *, self, 0x34)->unk_150 = LFLD(s32, self, 0x14);
    func_02041c18(LFLD(Model *, self, 0x34), LFLD(u16, self, 0x3c));
    {
        Model *m = LFLD(Model *, self, 0x34);
        Model_PlayPart(m, 6);
    }
    Model_SetPos(LFLD(Model *, self, 0x34), (x + 0x42) << 12, (y - 0x5c) << 12);
    LFLD(Model *, self, 0x34)->unk_150 = LFLD(s32, self, 0x14);
    func_02041c18(LFLD(Model *, self, 0x34), LFLD(u32, self, 0x40));
    {
        Model *m = LFLD(Model *, self, 0x34);
        Model_PlayPart(m, 6);
    }
}
}
