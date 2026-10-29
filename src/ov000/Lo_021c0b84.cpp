#include "ov000/ModelPart.h"

#define LFLD(type, obj, off) (*(type *)((u8 *)(obj) + (off)))
#define LO_FX_MUL(a, b) ((s32)(((s64)(a) * (b) + 0x800) >> 12))

extern "C" {
extern u8 *data_02097d48;
int func_02043d48(void *p);

static inline void SetOfs(Model *m, s32 x, s32 y) {
    Model_SetPos(m, x << 12, (y - 0x58) << 12);
}

void func_ov000_021c0b84(u8 *self) {
    u8 *g;
    s32 x;
    s32 id;
    if (LFLD(s32, self, 0x68) != 10) {
        return;
    }
    g = data_02097d48;
    x = ((LO_FX_MUL(0x1000 - LFLD(s32, self, 0x88), 0x40000) + 0xce000) >> 12) - 0x80;
    LFLD(Model *, self, 0x90)->unk_150 = LFLD(s32, self, 0x80);
    SetOfs(LFLD(Model *, self, 0x90), x, 0);
    LFLD(Model *, self, 0x8c)->unk_150 = LFLD(s32, self, 0x80);
    SetOfs(LFLD(Model *, self, 0x8c), x, 0);
    id = func_02043d48(g + 0x8b0) & 0x3f;

    MODEL_FLAGS(LFLD(Model *, self, 0x90))->polygon_id = id;
    MODEL_FLAGS(LFLD(Model *, self, 0x90))->alpha = 0x1e;
    Model_PlayPart(LFLD(Model *, self, 0x90), 2);
    MODEL_FLAGS(LFLD(Model *, self, 0x8c))->polygon_id = id;
    MODEL_FLAGS(LFLD(Model *, self, 0x8c))->alpha = 0x1e;
    Model_PlayPart(LFLD(Model *, self, 0x8c), 9);
}

}
