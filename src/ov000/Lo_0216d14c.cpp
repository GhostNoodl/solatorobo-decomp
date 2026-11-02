#include "ov000/ModelPart.h"
#include "Main/Sys/FieldState.h"

#define LO_FX_MUL(a, b) ((s32)(((s64)(a) * (b) + 0x800) >> 12))

extern "C" {
BOOL PauseNode_IsDrawPaused(void *p, s32 a);
void func_ov000_021c1e78(void *p);

struct Obj0216d14c {
    u8 unk_00[0x4];
    s32 unk_04;
    u8 unk_08[0x4];
    Model *unk_0c;
    void *unk_10;
    u8 unk_14[0x14];
    u16 unk_28;
    u8 unk_2a[0x6];
    s32 unk_30;
    u8 unk_34[0x4];
    s32 unk_38;
};

void func_ov000_0216d14c(Obj0216d14c *self) {
    Model *m;
    s32 x;
    if (PauseNode_IsDrawPaused((u8 *)data_ov000_021ccd54 + 8, 1)) {
        return;
    }
    switch (self->unk_04) {
    case 7:
    case 8:
        x = LO_FX_MUL(self->unk_30, 0x80000) & ~0xfff;
        if (self->unk_0c != NULL) {
            MODEL_FLAGS(self->unk_0c)->unk_19 = 1;
            MODEL_FLAGS(self->unk_0c)->unk_21 = 1;
            MODEL_FLAGS(self->unk_0c)->alpha = 0x1e;
            Model_SetPos(self->unk_0c, x, 0);
            ((Model *)(void *)self->unk_0c)->unk_150 = -0x2000;
            Model_PlayPart(self->unk_0c, 6);
            Model_PlayPart(self->unk_0c, 8);
            self->unk_0c->unk_150 = -0x2000;
            m = self->unk_0c;
            Model_PlayPart(m, 13);
            Model_SetPos(self->unk_0c, x, self->unk_38 & ~0xfff);
            Model_PlayPart(self->unk_0c, self->unk_28);
            Model_SetPos(self->unk_0c, x, 0);
            Model_PlayPart(self->unk_0c, 14);
        }
        break;
    }
    if (self->unk_10 != NULL) {
        func_ov000_021c1e78(self->unk_10);
    }
}

}
