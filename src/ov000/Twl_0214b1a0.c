#include "types.h"

/* Draws a textured, scaled quad at pos with the given alpha and texture address. */

void func_02043d20(void *obj, int a);
s32 func_02043d48(void *p);
void NNS_G3dGeBufferOP_N(int cmd, const void *data, int count);
extern u8 *data_02097d48;

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

static inline void G3_Cmd2(int cmd, u32 a, u32 b) {
    u32 v[2];
    v[0] = a;
    v[1] = b;
    NNS_G3dGeBufferOP_N(cmd, v, 2);
}

void func_ov000_0214b1a0(const s32 *pos, const s32 *scale, s32 alpha, u32 tex) {
    func_02043d20(data_02097d48 + 0x8b0, 0);
    G3_Cmd1(0x30, 0xffff);
    G3_Cmd1(0x31, 0);
    G3_Cmd1(0x2a, 0x5e400000 | (tex >> 3));
    G3_Cmd1(0x29, (u32)((1 << 4) | (3 << 6) | (func_02043d48(data_02097d48 + 0x8b0) << 24) | (alpha << 16)));
    NNS_G3dGeBufferOP_N(0x11, 0, 0);
    G3_Cmd1(0x10, 3);
    NNS_G3dGeBufferOP_N(0x15, 0, 0);
    G3_Cmd1(0x10, 2);
    NNS_G3dGeBufferOP_N(0x15, 0, 0);
    G3_Vec(0x1c, pos[0], pos[1], pos[2]);
    G3_Vec(0x1b, scale[0], scale[1], scale[2]);
    G3_Cmd1(0x40, 1);
    G3_Cmd1(0x21, 0x1ff00000);
    G3_Cmd1(0x22, 0);
    G3_Cmd2(0x23, 0xf800f800, 0);
    G3_Cmd1(0x22, 0x6000000);
    G3_Cmd2(0x23, 0x0800f800, 0);
    G3_Cmd1(0x22, 0x6000600);
    G3_Cmd2(0x23, 0x08000800, 0);
    G3_Cmd1(0x22, 0x600);
    G3_Cmd2(0x23, 0xf8000800, 0);
    NNS_G3dGeBufferOP_N(0x41, 0, 0);
    G3_Cmd1(0x12, 1);
}
