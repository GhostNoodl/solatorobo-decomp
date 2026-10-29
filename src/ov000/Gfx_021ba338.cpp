#include "types.h"

#define LFLD(type, obj, off) (*(type *)((u8 *)(obj) + (off)))

typedef struct {
    u32 b0 : 2;
    u32 b2 : 5;
    u32 b7 : 6;
    u32 b13 : 6;
    u32 b19 : 1;
    u32 b20 : 1;
    u32 b21 : 1;
    u32 b22 : 10;
} B6c_021ba338;

extern "C" {

extern u8 *data_02097d48;
extern void *data_0208b3d0;
extern const u32 data_020828f8;
void NNS_G3dGeBufferOP_N(int cmd, const void *data, int count);
void NNS_G3dGeSendDL(const void *dl, u32 size);
u8 func_02043d48(void *p);
void *NNS_G2dGetAnimSequenceByIdx(void *p, int idx);
void *NNS_G2dGetCellDataByIdx(void *p, u16 idx);
void func_02042628(void *model, void *anim, void *part, int x);

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

static inline void *GetPart021ba338(void *self, int idx) {
    if (idx >= LFLD(s32, self, 0x80)) {
        return NULL;
    }
    return (u8 *)LFLD(void *, self, 0x78) + idx * 0x28;
}

static inline void PlayPart021ba338(void *model, int idx) {
    void *res = LFLD(void *, model, 0x28);
    void *part;
    void *anim;
    if (res == NULL) {
        return;
    }
    part = GetPart021ba338(model, idx);
    if (part != NULL && LFLD(void *, part, 0x4) != NULL) {
        anim = LFLD(void *, LFLD(void *, part, 0x4), 0x30);
    } else {
        anim = NNS_G2dGetCellDataByIdx(LFLD(void *, res, 0x4),
                                       **LFLD(u16 **, NNS_G2dGetAnimSequenceByIdx(LFLD(void *, res, 0xc), idx), 0xc));
    }
    func_02042628(model, anim, part, 0);
}

void func_ov000_021ba338(u8 *self) {
    u8 *g = data_02097d48;
    s32 a = LFLD(s32, self, 0x2c);
    s32 b;
    s32 h;
    s32 w;
    s32 r;
    if (LFLD(s32, self, 0x8) != 0xd) {
        h = (s32)(((s64)a * (s64)0x18000 + 0x800) >> 12) >> 12;
        b = LFLD(s32, self, 0x30);
    } else {
        a = 0x1000 - a;
        h = (s32)(((s64)a * (s64)0x18000 + 0x800) >> 12) >> 12;
        b = 0x1000 - LFLD(s32, self, 0x30);
    }
    if (h != 0) {
        G3Cmd1_021ba338(0x29, 0x1f00d0 | (func_02043d48(g + 0x8b0) << 24));
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
        s32 c = LFLD(s32, self, 0x34);
        if (LFLD(s32, self, 0x8) != 0xd) {
            w = (s32)(((s64)(0x1000 - c) * 0x100000 + 0x800) >> 12);
        } else {
            w = (s32)(((s64)c * 0x100000 + 0x800) >> 12);
        }
    }
    G3Cmd1_021ba338(0x29, 0x1e08d0 | (g[0x8b1] << 24));
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
        s32 d = LFLD(s32, self, 0x38);
        s32 sq = (s32)(((s64)d * d + 0x800) >> 12);
        if (LFLD(s32, self, 0x8) != 0xd) {
            r = (s32)(((s64)(0x1000 - sq) * (s64)0x180000 + 0x800) >> 12) >> 12;
        } else {
            r = -((s32)(((s64)sq * (s64)0x180000 + 0x800) >> 12) >> 12);
        }
    }
    if ((r < 0 ? -r : r) < 0x100) {
        LFLD(s32, LFLD(u8 *, self, 0x20), 0x150) = -0x71a;
        LFLD(B6c_021ba338, LFLD(u8 *, self, 0x20), 0x6c).b19 = 1;
        LFLD(B6c_021ba338, LFLD(u8 *, self, 0x20), 0x6c).b21 = 1;
        LFLD(B6c_021ba338, LFLD(u8 *, self, 0x20), 0x6c).b2 = 0x1e;
        LFLD(B6c_021ba338, LFLD(u8 *, self, 0x20), 0x6c).b7 = func_02043d48(g + 0x8b0);
        {
            u8 *o = LFLD(u8 *, self, 0x20);
            LFLD(s32, o, 0xfc) = r << 12;
            LFLD(s32, o, 0x100) = 0;
        }
        PlayPart021ba338(LFLD(u8 *, self, 0x20), 0);
        LFLD(B6c_021ba338, LFLD(u8 *, self, 0x20), 0x6c).b21 = 0;
    }
    func_02043d48(g + 0x8b0);
}

}
