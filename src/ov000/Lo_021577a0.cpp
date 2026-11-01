#include "ov000/LoCommon.h"

extern "C" {
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

static inline void G3_TexCoord(s32 s, s32 t) {
    u32 v = (u16)s | ((u16)t << 16);
    NNS_G3dGeBufferOP_N(0x22, &v, 1);
}

s32 FX_Div(s32 a, s32 b);
static inline s32 FxMulS64(s32 a, s64 b) { return (s32)((a * b + 0x800) >> 12); }

struct Obj0215724c {
    u8 unk_00[0x20];
    s32 unk_20;
    u8 unk_24[0x4];
    s32 unk_28;
    u8 unk_2c[0x6c];
    void *unk_98;
    s16 unk_9c;
};

void func_ov000_0215724c(Obj0215724c *self, s32 x, s32 y, s32 z) {
    s32 off;
    s32 k;
    BOOL flag;
    s32 len;
    s32 h;
    s32 r;
    s32 n;
    h = self->unk_28 << 12;
    n = self->unk_9c << 12;
    if (n == 0) {
        n = 1;
    }
    r = FX_Div(self->unk_20 << 12, n);
    if (r >= 0x1000) {
        r = 0x1000;
    }
    len = LO_FX_MUL(h - 0x1c000, r);
    k = FX_Div(0x1000, n);
    n = 0;
    if (self->unk_98 != NULL) {
        n = LFLD(s16, self->unk_98, 4);
    }
    off = FxMulS64(LO_FX_MUL(k, n << 12), h - 0x1c000);
    flag = FALSE;
    if (self->unk_98 == NULL) {
        flag = TRUE;
    } else if (LFLD(s16, self->unk_98, 4) == self->unk_9c - self->unk_20 ||
               self->unk_9c < self->unk_20) {
        flag = TRUE;
    }
    if (flag) {
        len = h - 0x1c000 - off;
    }
    y = y + 0xe000 + off;
    G3_Cmd1(0x20, 0x7fff);
    NNS_G3dGeBufferOP_N(0x11, NULL, 0);
    G3_Vec(0x1c, x + 0x1000, y, z + 0x20);
    G3_Vec(0x1b, 0x3000, 0x1000, 0x1000);
    G3_Cmd1(0x40, 1);
    G3_TexCoord(0, 0x50);
    G3_Vtx(0, 0x1000, 0);
    G3_TexCoord(0x30, 0x50);
    G3_VtxXY(0x1000, 0x1000);
    G3_TexCoord(0x30, 0x40);
    G3_VtxXY(0x1000, 0);
    G3_TexCoord(0, 0x40);
    G3_VtxXY(0, 0);
    NNS_G3dGeBufferOP_N(0x41, NULL, 0);
    G3_Cmd1(0x12, 1);
    NNS_G3dGeBufferOP_N(0x11, NULL, 0);
    G3_Vec(0x1c, x + 0x1000, y + 0x1000, z + 0x20);
    G3_Vec(0x1b, 0x3000, len - 0x2000, 0x1000);
    G3_Cmd1(0x40, 1);
    G3_TexCoord(0, 0x60);
    G3_Vtx(0, 0x1000, 0);
    G3_TexCoord(0x30, 0x60);
    G3_VtxXY(0x1000, 0x1000);
    G3_TexCoord(0x30, 0x50);
    G3_VtxXY(0x1000, 0);
    G3_TexCoord(0, 0x50);
    G3_VtxXY(0, 0);
    NNS_G3dGeBufferOP_N(0x41, NULL, 0);
    G3_Cmd1(0x12, 1);
    NNS_G3dGeBufferOP_N(0x11, NULL, 0);
    G3_Vec(0x1c, x + 0x1000, y + len - 0x1000, z + 0x20);
    G3_Vec(0x1b, 0x3000, 0x1000, 0x1000);
    G3_Cmd1(0x40, 1);
    G3_TexCoord(0, 0x70);
    G3_Vtx(0, 0x1000, 0);
    G3_TexCoord(0x30, 0x70);
    G3_VtxXY(0x1000, 0x1000);
    G3_TexCoord(0x30, 0x60);
    G3_VtxXY(0x1000, 0);
    G3_TexCoord(0, 0x60);
    G3_VtxXY(0, 0);
    NNS_G3dGeBufferOP_N(0x41, NULL, 0);
    G3_Cmd1(0x12, 1);
}

struct Obj021577a0 {
    u8 unk_00[0x28];
    s32 unk_28;
};

void func_ov000_021577a0(Obj021577a0 *self, s32 x, s32 y, s32 z) {
    s32 h = self->unk_28 << 12;
    G3_Cmd1(0x20, 0x7fff);
    NNS_G3dGeBufferOP_N(0x11, NULL, 0);
    G3_Vec(0x1c, x, y + 0xe000, z);
    G3_Vec(0x1b, 0x5000, h - 0x1c000, 0x1000);
    G3_Cmd1(0x40, 1);
    G3_TexCoord(0, 0x20);
    G3_Vtx(0, 0x1000, 0);
    G3_TexCoord(0x50, 0x20);
    G3_VtxXY(0x1000, 0x1000);
    G3_TexCoord(0x50, 0);
    G3_VtxXY(0x1000, 0);
    G3_TexCoord(0, 0);
    G3_VtxXY(0, 0);
    NNS_G3dGeBufferOP_N(0x41, NULL, 0);
    G3_Cmd1(0x12, 1);
}

}
