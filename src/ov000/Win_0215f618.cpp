#include "ov000/LoCommon.h"

typedef struct {
    u16 id;
    u16 col0;
    u16 col1;
    u8 pad_06[0xa];
    s32 ofsX;
    s32 ofsY;
} Entry0215f618;

typedef struct {
    u32 b0 : 2;
    u32 f2 : 5;
    u32 f7 : 6;
    u32 pad13 : 6;
    u32 b19 : 1;
    u32 b20 : 1;
    u32 b21 : 1;
    u32 rest : 10;
} MdlFlags0215f618;

#define MF(m) LFLD(MdlFlags0215f618, m, 0x6c)

extern "C" {

extern Entry0215f618 data_02fe0188[];
extern u8 *data_02097d48;
extern u8 data_0208b3d0[];
extern u8 data_020828f8[];
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

static inline void G3_Cmd2(int cmd, u32 a, u32 b) {
    u32 v[2];
    v[0] = a;
    v[1] = b;
    NNS_G3dGeBufferOP_N(cmd, v, 2);
}

struct Obj0215f618 {
    u8 unk_00[0x4];
    s32 unk_04;
    u8 unk_08[0xc];
    s32 unk_14;
    s32 unk_18;
    u8 unk_1c[0xc];
    void *unk_28;
};

void func_ov000_0215f618(Obj0215f618 *self, s32 *pos) {
    u32 cmd;
    s32 sx;
    s32 sy;
    u8 shadow;
    u8 *g = data_02097d48;
    u32 misc = 0;
    u32 alpha;
    s32 sw;
    BOOL useAlpha;
    s32 sh;
    Entry0215f618 *e;
    G3_Cmd1(0x2a, 0x20000000);
    useAlpha = TRUE;
    if (!MF(self->unk_28).b19) {
        useAlpha = FALSE;
    }
    if (useAlpha) {
        alpha = (u8)MF(self->unk_28).f2;
    } else {
        alpha = 0x1e;
    }
    if (MF(self->unk_28).b20 ? TRUE : FALSE) {
        misc |= 0x4000;
    }
    e = &data_02fe0188[self->unk_04];
    if (self->unk_04 == 0) {
        sx = e->ofsX + (pos[0] << 12);
        sy = e->ofsY + (pos[1] << 12);
        sw = (self->unk_14 << 12) - (e->ofsX << 1);
        sh = ((self->unk_18 - 2) << 12) - (e->ofsY << 1);
    }
    cmd = misc | 0xd0 | (func_02043d48(g + 0x8b0) << 24);
    shadow = TRUE;
    G3_Cmd1(0x29, cmd | (alpha << 16));
    NNS_G3dGeBufferOP_N(0x11, NULL, 0);
    G3_Vec(0x1c, sx, sy, pos[2]);
    G3_Vec(0x1b, sw, sh + 0x2000, 0x1000);
    G3_Cmd1(0x20, 0);
    NNS_G3dGeSendDL(LFLD(void *, data_0208b3d0, 4), LFLD(u32, data_020828f8, 4));
    G3_Cmd1(0x12, 1);
    if (!MF(self->unk_28).b21) {
        shadow = FALSE;
    }
    if (shadow) {
        misc |= 0x800;
    }
    G3_Cmd1(0x29, (g[0x8b1] << 24) | (misc | 0xd0) | (alpha << 16));
    NNS_G3dGeBufferOP_N(0x11, NULL, 0);
    G3_Vec(0x1c, sx, sy + 0x1000, pos[2]);
    G3_Vec(0x1b, sw, sh, 0x1000);
    G3_Cmd1(0x40, 1);
    G3_Cmd1(0x20, e->col0);
    G3_Cmd2(0x23, 0x1000, 0);
    G3_Cmd1(0x25, 0);
    G3_Cmd1(0x20, e->col1);
    G3_Cmd1(0x25, 0x10000000);
    G3_Cmd1(0x25, 0x10001000);
    NNS_G3dGeBufferOP_N(0x41, NULL, 0);
    G3_Cmd1(0x12, 1);
    MF(self->unk_28).f7 = func_02043d48(g + 0x8b0);
}

}
