#include "ov000/LoCommon.h"

typedef struct {
    u32 unk_00;
    void *unk_04;
} DLRef02155e24;

extern "C" {
extern u8 *data_02097d48;
extern DLRef02155e24 data_0208b3d0;
extern DLRef02155e24 data_020828f8;
u8 func_02043d48(void *p);
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

void func_ov000_02155e24(void *self, s32 t) {
    u8 *g = data_02097d48;
    s16 z = LFLD(s16, self, 0x68) - 0x180;
    s32 alpha = (s32)(((s64)t * 0x14000 + 0x800) >> 12) >> 12 & 0xff;
    if (alpha == 0) {
        return;
    }
    G3_Cmd1(0x2a, 0x20000000);
    G3_Cmd1(0x29, 0 | (1 << 4) | (3 << 6) | (func_02043d48(g + 0x8b0) << 24) | (alpha << 16));
    NNS_G3dGeBufferOP_N(0x11, NULL, 0);
    G3_Vec(0x1c, 0, 0, z);
    G3_Vec(0x1b, 0x100000, 0xc0000, 0x1000);
    G3_Cmd1(0x20, 0x7fff);
    NNS_G3dGeSendDL(data_0208b3d0.unk_04, (u32)data_020828f8.unk_04);
    G3_Cmd1(0x12, 1);
}

}
