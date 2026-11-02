#include "types.h"
#include "Main/Gfx/GfxMgr.h"
#include "Main/Gfx/Model.h"
#include "ov000/ModelPart.h"


extern "C" {

extern void *data_0208b3d0;
extern const u32 data_020828f8;
void NNS_G3dGeBufferOP_N(int cmd, const void *data, int count);
void NNS_G3dGeSendDL(const void *dl, u32 size);
u8 Gfx3DState_NextPolyId(void *p);

static inline void G3Vec021ba338(int cmd, s32 x, s32 y, s32 z) {
    s32 v[3];
    v[0] = x;
    v[1] = y;
    v[2] = z;
    NNS_G3dGeBufferOP_N(cmd, v, 3);
}

static inline void G3Cmd1_021ba338(int cmd, u32 value) {
    u32 v = value;
    NNS_G3dGeBufferOP_N(cmd, &v, 1);
}

struct Obj021ba338 {
    u8 unk_00[0x8];
    s32 unk_08;
    u8 unk_0c[0x14];
    Model *unk_20;
    u8 unk_24[0x8];
    s32 unk_2c;
    s32 unk_30;
    s32 unk_34;
    s32 unk_38;
};

void func_ov000_021ba338(Obj021ba338 *self) {
    GfxSys *g = data_02097d48;
    s32 a = self->unk_2c;
    s32 b;
    s32 h;
    s32 w;
    s32 r;
    if (self->unk_08 != 0xd) {
        h = (s32)(((s64)a * (s64)0x18000 + 0x800) >> 12) >> 12;
        b = self->unk_30;
    } else {
        a = 0x1000 - a;
        h = (s32)(((s64)a * (s64)0x18000 + 0x800) >> 12) >> 12;
        b = 0x1000 - self->unk_30;
    }
    if (h != 0) {
        G3Cmd1_021ba338(0x29, 0x1f00d0 | (Gfx3DState_NextPolyId(g->unk_8b0) << 24));
        NNS_G3dGeBufferOP_N(0x11, NULL, 0);
        G3Vec021ba338(0x1c, 0x80000, 0x60000, -0x79a);
        G3Vec021ba338(0x1b, a, b, 0x1000);
        G3Cmd1_021ba338(0x20, 0x7bff);
        G3Cmd1_021ba338(0x2a, 0x20000000);
        G3Vec021ba338(0x1b, 0x100000, 0x18000, 0x1000);
        NNS_G3dGeSendDL(data_0208b3d0, data_020828f8);
        G3Cmd1_021ba338(0x12, 1);
    }
    {
        s32 c = self->unk_34;
        if (self->unk_08 != 0xd) {
            w = (s32)(((s64)(0x1000 - c) * 0x100000 + 0x800) >> 12);
        } else {
            w = (s32)(((s64)c * 0x100000 + 0x800) >> 12);
        }
    }
    G3Cmd1_021ba338(0x29, 0x1e08d0 | (g->unk_8b0[1] << 24));
    NNS_G3dGeBufferOP_N(0x11, NULL, 0);
    G3Vec021ba338(0x1c, w + 0x80000, 0x55000, -0x77a);
    G3Cmd1_021ba338(0x20, 0x68);
    G3Cmd1_021ba338(0x2a, 0x20000000);
    G3Vec021ba338(0x1b, 0x100000, 0x2000, 0x1000);
    NNS_G3dGeSendDL(data_0208b3d0, data_020828f8);
    G3Cmd1_021ba338(0x12, 1);
    NNS_G3dGeBufferOP_N(0x11, NULL, 0);
    G3Vec021ba338(0x1c, 0x80000 - w, 0x6b000, -0x77a);
    G3Cmd1_021ba338(0x20, 0x68);
    G3Cmd1_021ba338(0x2a, 0x20000000);
    G3Vec021ba338(0x1b, 0x100000, 0x2000, 0x1000);
    NNS_G3dGeSendDL(data_0208b3d0, data_020828f8);
    G3Cmd1_021ba338(0x12, 1);
    {
        s32 d = self->unk_38;
        s32 sq = (s32)(((s64)d * d + 0x800) >> 12);
        if (self->unk_08 != 0xd) {
            r = (s32)(((s64)(0x1000 - sq) * (s64)0x180000 + 0x800) >> 12) >> 12;
        } else {
            r = -((s32)(((s64)sq * (s64)0x180000 + 0x800) >> 12) >> 12);
        }
    }
    if ((r < 0 ? -r : r) < 0x100) {
        self->unk_20->unk_150 = -0x71a;
        MODEL_FLAGS(self->unk_20)->unk_19 = 1;
        MODEL_FLAGS(self->unk_20)->unk_21 = 1;
        MODEL_FLAGS(self->unk_20)->alpha = 0x1e;
        MODEL_FLAGS(self->unk_20)->polygon_id = Gfx3DState_NextPolyId(g->unk_8b0);
        {
            Model *o = self->unk_20;
            o->x = r << 12;
            o->y = 0;
        }
        Model_PlayPart(self->unk_20, 0);
        MODEL_FLAGS(self->unk_20)->unk_21 = 0;
    }
    Gfx3DState_NextPolyId(g->unk_8b0);
}

}
