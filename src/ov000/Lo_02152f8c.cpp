#include "ov000/LoCommon.h"
#include "ov000/Vec.h"

typedef struct {
    u32 b0 : 2;
    u32 f2 : 5;
    u32 b7 : 10;
    u32 b17 : 1;
    u32 b18 : 1;
    u32 rest : 13;
} LoModelFlags;

extern "C" {

extern u8 *data_02097d48;
extern u8 data_0208b3d0[];
extern u8 data_020828f8[];
void *NNS_G2dGetCellDataByIdx(void *a, int b);
void *NNS_G2dGetAnimSequenceByIdx(void *a, int b);
void func_02042628(void *a, void *b, void *c, int d);
u8 func_02043d48(void *p);
void NNS_G3dGeBufferOP_N(int cmd, const void *data, int count);
void NNS_G3dGeSendDL(const void *dl, u32 size);

static inline void *LoModelGetPart(void *self, int idx) {
    if (idx >= LFLD(s32, self, 0x80)) {
        return NULL;
    }
    return (u8 *)LFLD(void *, self, 0x78) + idx * 0x28;
}

static inline void LoModelPlayPart(void *model, int idx) {
    void *res = LFLD(void *, model, 0x28);
    void *part;
    void *anim;
    if (res == NULL) {
        return;
    }
    part = LoModelGetPart(model, idx);
    if (part != NULL && LFLD(void *, part, 0x4) != NULL) {
        anim = LFLD(void *, LFLD(void *, part, 0x4), 0x30);
    } else {
        anim = NNS_G2dGetCellDataByIdx(LFLD(void *, res, 0x4), **(u16 **)LFLD(void *, NNS_G2dGetAnimSequenceByIdx(LFLD(void *, res, 0xc), idx), 0xc));
    }
    func_02042628(model, anim, part, 0);
}

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

void func_ov000_02152f8c(void *self, s32 ratio, VecFx32 *pos, s32 arg3) {
    s32 x;
    s32 h;
    u8 *g;
    s16 z;
    u8 *gp;
    s32 k;
    if (LFLD(void *, self, 0x10) == NULL) {
        return;
    }
    ratio = 0x1000 - ratio;
    if (LFLD(void *, self, 0x14) != NULL) {
        k = LO_FX_MUL(ratio, 0x78000) >> 12;
        LFLD(LoModelFlags, LFLD(u8 *, self, 0x10), 0x6c).b17 = 0;
        LFLD(LoModelFlags, LFLD(u8 *, self, 0x10), 0x6c).b18 = 0;
        LFLD(LoModelFlags, LFLD(u8 *, self, 0x10), 0x6c).f2 = 30;
        {
            u8 *m = LFLD(u8 *, self, 0x10);
            LFLD(s32, m, 0xfc) = (-0x88 - k) << 12;
            LFLD(s32, m, 0x100) = -0x61000;
        }
        LFLD(s32, LFLD(u8 *, self, 0x10), 0x150) = LFLD(s16, self, 0x68) - 0x50;
        LoModelPlayPart(LFLD(void *, self, 0x10), 7);
        {
            u8 *o = LFLD(u8 *, self, 0x14);
            h = LFLD(s32, o, 0x44);
            LFLD(s32, o, 0x70) = LFLD(s16, self, 0x68) - 0x40;
        }
        LFLD(VObj *, self, 0x14)->vfunc_20(0x31 - (h >> 1) - k, 1);
        LFLD(VObj *, self, 0x14)->vfunc_90();
    }
    if (LFLD(void *, self, 0x18) == NULL) {
        return;
    }
    ratio = LO_FX_MUL(ratio, 0x20000);
    g = data_02097d48;
    k = ratio >> 12;
    gp = g + 0x8b0;
    z = LFLD(s16, self, 0x68) - 0x70;
    G3_Cmd1(0x2a, 0x20000000);
    G3_Cmd1(0x29, 0x1408d0 | (func_02043d48(gp) << 24));
    NNS_G3dGeBufferOP_N(0x11, NULL, 0);
    G3_Vec(0x1c, 0, -ratio, z);
    G3_Vec(0x1b, 0x100000, 0xe000, 0x1000);
    G3_Cmd1(0x20, LFLD(u16, self, 0x4a));
    NNS_G3dGeSendDL(LFLD(void *, data_0208b3d0, 4), LFLD(u32, data_020828f8, 4));
    G3_Cmd1(0x12, 1);
    x = 0xe4 - (LFLD(s32, self, 0x4c) >> 12);
    h = LFLD(s32, LFLD(u8 *, self, 0x18), 0x44);
    LFLD(s32, LFLD(u8 *, self, 0x18), 0x70) = LFLD(s16, self, 0x68) - 0x60;
    if (x < 0x100 && x + h > 0x68) {
        LFLD(VObj *, self, 0x18)->vfunc_20(x, 2 - k);
        LFLD(VObj *, self, 0x18)->vfunc_90();
    }
    x += LFLD(s32, self, 0x50);
    if (x < 0x100 && x + h > 0x68) {
        LFLD(VObj *, self, 0x18)->vfunc_20(x, 2 - k);
        LFLD(VObj *, self, 0x18)->vfunc_90();
    }
}

}
