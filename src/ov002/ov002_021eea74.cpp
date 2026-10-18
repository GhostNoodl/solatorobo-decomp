#include "ov002/ov002.h"

extern "C" {

void NNS_G3dGeBufferOP_N(u32 op, const u32 *args, u32 num);
void NNS_G3dGeSendDL(const void *src, u32 szByte);
void func_02043d20(void *obj, int a);
extern void *data_0208b3d0[];
extern u32 data_020828f8[];

static inline void ov002_G3Vec(int cmd, s32 x, s32 y, s32 z) {
    s32 v[3];
    v[0] = x;
    v[1] = y;
    v[2] = z;
    NNS_G3dGeBufferOP_N(cmd, (u32 *)v, 3);
}

static inline void ov002_G3Cmd1(int cmd, u32 value) {
    u32 v = value;
    NNS_G3dGeBufferOP_N(cmd, &v, 1);
}

void func_ov002_021eea74(void *self) {
    s32 t = FX_Div(FIELD(self, 0x14, s32), 0x78000);
    u8 alpha;
    if (t >= 0x1000) {
        t = 0x1000;
    }
    alpha = (s32)(((s64)FX_SinCosTable_[((s32)(t << 14) >> 16) * 2] * 0x1f000 + 0x800) >> 12) >> 12;
    if (alpha == 0) {
        return;
    }
    func_02043d20(data_02097d48 + 0x8b0, 0);
    ov002_G3Vec(0x1b, 0x1000, 0x1000, 0x1000);
    ov002_G3Cmd1(0x2a, 0x20000000);
    ov002_G3Cmd1(0x29, ((u32)func_02043d48(data_02097d48 + 0x8b0) << 24) | 0xd0 | (alpha << 16));
    NNS_G3dGeBufferOP_N(0x11, NULL, 0);
    NNS_G3dGeBufferOP_N(0x15, NULL, 0);
    ov002_G3Vec(0x1c, 0, 0, -0x333);
    ov002_G3Vec(0x1b, 0x100000, 0xc0000, 0x1000);
    ov002_G3Cmd1(0x20, 0);
    NNS_G3dGeSendDL(data_0208b3d0[1], data_020828f8[1]);
    ov002_G3Cmd1(0x12, 1);
}

}
