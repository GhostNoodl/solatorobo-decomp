// Shadow box drawn straight into the G3 geometry buffer; the twin of G3_0215b2e4.cpp.
// The colour is halved channel by channel, and each channel re-reads the field.
#include "ov000/LoCommon.h"
#include "nitro/fx.h"

extern "C" {
extern u8 *data_02097d48;
s32 func_02043d48(void *p);
void NNS_G3dGeBufferOP_N(int cmd, const void *data, int count);

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

static inline void G3_Vtx(s16 x, s16 y, s16 z) {
    u32 v[2];
    v[0] = (u16)x | ((u16)y << 16);
    v[1] = (u16)z;
    NNS_G3dGeBufferOP_N(0x23, v, 2);
}

static inline void G3_VtxXY(s16 x, s16 y) {
    u32 v = (u16)x | ((u16)y << 16);
    NNS_G3dGeBufferOP_N(0x25, &v, 1);
}

// Identity 3x3 with a translation row (the same asm as G3_0215b2e4.cpp).
static inline void Box_SetMtx(MtxFx43 *m, s32 x, s32 y, s32 z) {
    asm {
        str x, [m, #0x24]
        mov r1, #0x1000
        str y, [m, #0x28]
        mov r2, #0
        str z, [m, #0x2c]
        mov r3, #0
        stmia m!, {r1, r2}
        stmia m!, {r2, r3}
        stmia m!, {r1, r2}
        stmia m!, {r2, r3}
        stmia m!, {r1}
    }
}

void func_ov000_0215b598(u8 *self, s32 a1, s32 *pos, s32 a3) {
    s16 z;
    u8 *g;
    s32 sx;
    s32 sy;
    s16 t;
    MtxFx43 m;
    MtxFx43 tr;
    z = LFLD(s16, self, 0x68) - 0x100;
    g = data_02097d48;
    G3_Cmd1(0x2a, 0x20000000);
    {
        s32 a = LFLD(s32, self, 0x54);
        G3_Cmd1(0x29, (func_02043d48(g + 0x8b0) << 24) | 0x8d0 | (a << 16));
    }
    {
        s32 k = LFLD(s32, self, 0xd4) ? 0x10000 : 0;
        sx = LFLD(s32, self, 0x24) << 12;
        sy = (LFLD(s32, self, 0x28) << 12) + 0xb000;
        t = FX_Div(k + 0x10000, sy);
    }
    NNS_G3dGeBufferOP_N(0x11, NULL, 0);
    MTX_Scale43_(&m, 0x1000, a3, 0x1000);
    Box_SetMtx(&tr, 0x800, 0x800, 0);
    MTX_Concat43(&m, &tr, &m);
    MTX_TransApply43(&m, &m, -0x800, -0x800, 0);
    G3_Vec(0x1c, pos[0], pos[1] - 0xb000, z);
    G3_Vec(0x1b, sx, sy, 0x1000);
    NNS_G3dGeBufferOP_N(0x19, &m, 12);
    G3_Cmd1(0x40, 3);
    {
        u16 b = (LFLD(u16, self, 0x48) >> 10) & 0x1f;
        u16 g = (LFLD(u16, self, 0x48) >> 5) & 0x1f;
        u16 r = LFLD(u16, self, 0x48) & 0x1f;
        G3_Cmd1(0x20, (u16)(((u8)(g >> 1) << 5) | (u8)(r >> 1) | ((u8)(b >> 1) << 10)));
    }
    G3_Vtx(0x1000, 0, 0);
    G3_VtxXY(0, 0);
    G3_VtxXY(0x1000, t);
    G3_VtxXY(0, t);
    G3_Cmd1(0x20, LFLD(u16, self, 0x48));
    G3_VtxXY(0x1000, t);
    G3_VtxXY(0, t);
    G3_VtxXY(0x1000, 0x1000);
    G3_VtxXY(0, 0x1000);
    NNS_G3dGeBufferOP_N(0x41, NULL, 0);
    G3_Cmd1(0x12, 1);
}
}
