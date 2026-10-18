#include "ov000/ModelPart.h"

#define LFLD(type, obj, off) (*(type *)((u8 *)(obj) + (off)))
#define LO_FX_MUL(a, b) ((s32)(((s64)(a) * (b) + 0x800) >> 12))

typedef struct {
    u32 unk_00;
    void *unk_04;
} DLRef021bbf78;

extern "C" {
extern u8 *data_02097d48;
extern DLRef021bbf78 data_0208b3d0;
extern DLRef021bbf78 data_020828f8;
s32 func_02043d84(void *p);
void NNS_G3dGeBufferOP_N(int cmd, const void *data, int count);
void NNS_G3dGeSendDL(const void *dl, u32 size);

static inline void G3_Vec(int cmd, int x, int y, int z) {
    int v[3];
    v[0] = x;
    v[1] = y;
    v[2] = z;
    NNS_G3dGeBufferOP_N(cmd, v, 3);
}

static inline void G3_Cmd1(int cmd, u32 value) {
    u32 v = value;
    NNS_G3dGeBufferOP_N(cmd, &v, 1);
}

static inline void SetOfs(Model *m, s32 x, s32 y, s32 dy) {
    Model_SetPos(m, x << 12, (y - dy) << 12);
}


void func_ov000_021bbf78(u8 *self) {
    u8 *g;
    s32 alpha;
    s32 t;
    u32 k;
    s32 d;
    s32 v;
    alpha = LO_FX_MUL(LFLD(s32, self, 0x68), 0x14000) >> 12;
    g = data_02097d48;
    if (alpha == 0) {
        return;
    }
    G3_Cmd1(0x29, (func_02043d84(g + 0x8b0) << 24) | 0xd0 | (alpha << 16));
    NNS_G3dGeBufferOP_N(0x11, NULL, 0);
    G3_Vec(0x1c, 0, 0, -0x91a);
    G3_Cmd1(0x20, 0);
    G3_Cmd1(0x2a, 0x20000000);
    G3_Vec(0x1b, 0x100000, 0xc0000, 0x1000);
    NNS_G3dGeSendDL(data_0208b3d0.unk_04, (u32)data_020828f8.unk_04);
    G3_Cmd1(0x12, 1);
    MODEL_FLAGS(LFLD(Model *, self, 0x58))->unk_19 = 1;
    MODEL_FLAGS(LFLD(Model *, self, 0x58))->alpha = (u8)alpha;
    MODEL_FLAGS(LFLD(Model *, self, 0x58))->polygon_id = func_02043d84(g + 0x8b0);
    LFLD(Model *, self, 0x58)->unk_150 = -0x89a;
    Model_SetPos(LFLD(Model *, self, 0x58), 0, 0);
    Model_PlayPart(LFLD(Model *, self, 0x58), 0);
    t = LFLD(s32, self, 0x60) % 0x40000;
    if (t < 0x18000) {
        LFLD(s32, self, 0x70) += LO_FX_MUL(0x8000 - LFLD(s32, self, 0x70), 0x148LL);
    } else if (t < 0x3f000) {
        LFLD(s32, self, 0x70) += LO_FX_MUL(0 - LFLD(s32, self, 0x70), 0xcdLL);
    } else {
        LFLD(s32, self, 0x70) = 0;
    }

    SetOfs(LFLD(Model *, self, 0x58), 0, -0x10, LFLD(s32, self, 0x70) >> 12);
    Model_PlayPart(LFLD(Model *, self, 0x58), 1);
}

}
