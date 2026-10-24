// Shadow quad drawn straight into the G3 geometry buffer (the func_ov000_021535a8 pattern).
// The asm translation-matrix inline makes MWCC load the constants around it from the
// literal pool, without CSE between the calls.
#pragma short_enums on
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

static inline void G3_Cmd2(int cmd, u32 a, u32 b) {
    u32 v[2];
    v[0] = a;
    v[1] = b;
    NNS_G3dGeBufferOP_N(cmd, v, 2);
}

// Identity 3x3 with a translation row.
static inline void G3_SetTransMtx(MtxFx43 *m, s32 x, s32 y, s32 z) {
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

void func_ov000_0215d4b4(u8 *self, s32 a1, s32 *pos, s32 sc) {
    MtxFx43 m;
    MtxFx43 t;
    s16 z;
    u8 *g;
    s32 sx;
    s32 sy;
    if (a1 == 0) {
        return;
    }
    z = LFLD(s16, self, 0x68) - 0x100;
    g = data_02097d48;
    G3_Cmd1(0x2a, 0x20000000);
    G3_Cmd1(0x29, (func_02043d48(g + 0x8b0) << 24) | 0x8d0 | (0x18 << 16));
    sx = LFLD(s32, self, 0x24) << 12;
    sy = LFLD(s32, self, 0x28) << 12;
    NNS_G3dGeBufferOP_N(0x11, NULL, 0);
    G3_Vec(0x1c, pos[0], pos[1], z);
    G3_Vec(0x1b, sx, sy, 0x1000);
    MTX_Scale43_(&m, sc, sc, 0x1000);
    G3_SetTransMtx(&t, 0x800, 0x800, 0);
    MTX_Concat43(&m, &t, &m);
    MTX_TransApply43(&m, &m, -0x800, -0x800, 0);
    NNS_G3dGeBufferOP_N(0x19, &m, 12);
    G3_Cmd1(0x40, 2);
    G3_Cmd1(0x20, LFLD(u16, self, 0x48));
    G3_Cmd2(0x23, 0x58d0052, 0);
    G3_Cmd1(0x25, 0x1000017e);
    G3_Cmd1(0x25, 0x130);
    G3_Cmd1(0x25, 0xe0b0f7f);
    G3_Cmd1(0x25, 0x1f50f44);
    G3_Cmd1(0x25, 0xb1a1000);
    NNS_G3dGeBufferOP_N(0x41, NULL, 0);
    G3_Cmd1(0x12, 1);
}

}
