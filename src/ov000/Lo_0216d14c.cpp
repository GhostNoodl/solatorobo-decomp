#include "ov000/ModelPart.h"

#define LFLD(type, obj, off) (*(type *)((u8 *)(obj) + (off)))
#define LO_FX_MUL(a, b) ((s32)(((s64)(a) * (b) + 0x800) >> 12))

extern "C" {
extern u8 *data_ov000_021ccd54;
BOOL func_0203dc9c(void *p, s32 a);
void func_ov000_021c1e78(void *p);

void func_ov000_0216d14c(u8 *self) {
    Model *m;
    s32 x;
    if (func_0203dc9c(data_ov000_021ccd54 + 8, 1)) {
        return;
    }
    switch (LFLD(s32, self, 4)) {
    case 7:
    case 8:
        x = LO_FX_MUL(LFLD(s32, self, 0x30), 0x80000) & ~0xfff;
        if (LFLD(Model *, self, 0xc) != NULL) {
            MODEL_FLAGS(LFLD(Model *, self, 0xc))->unk_19 = 1;
            MODEL_FLAGS(LFLD(Model *, self, 0xc))->unk_21 = 1;
            MODEL_FLAGS(LFLD(Model *, self, 0xc))->alpha = 0x1e;
            Model_SetPos(LFLD(Model *, self, 0xc), x, 0);
            ((Model *)LFLD(void *, self, 0xc))->unk_150 = -0x2000;
            Model_PlayPart(LFLD(Model *, self, 0xc), 6);
            Model_PlayPart(LFLD(Model *, self, 0xc), 8);
            LFLD(Model *, self, 0xc)->unk_150 = -0x2000;
            m = LFLD(Model *, self, 0xc);
            Model_PlayPart(m, 13);
            Model_SetPos(LFLD(Model *, self, 0xc), x, LFLD(s32, self, 0x38) & ~0xfff);
            Model_PlayPart(LFLD(Model *, self, 0xc), LFLD(u16, self, 0x28));
            Model_SetPos(LFLD(Model *, self, 0xc), x, 0);
            Model_PlayPart(LFLD(Model *, self, 0xc), 14);
        }
        break;
    }
    if (LFLD(void *, self, 0x10) != NULL) {
        func_ov000_021c1e78(LFLD(void *, self, 0x10));
    }
}

}
