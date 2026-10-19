#include "ov002/ov002.h"

extern "C" {

void NNS_G3dGlbFlushP(void);
void NNS_G3dGeBufferOP_N(int cmd, void *data, int n);
void func_02043db4(int a, s32 b, s32 c, u16 d);
void func_02041c18(void *a, int b);
extern Vec3 data_ov002_021ef104;
extern Vec3 data_ov002_021ef0bc;

static inline void *ov002_Model_GetPart(void *self, int idx) {
    if (idx >= FIELD(self, 0x80, s32)) {
        return NULL;
    }
    return (u8 *)FIELD(self, 0x78, void *) + idx * 0x28;
}

static inline void ov002_Model_PlayPart(void *model, int idx) {
    void *res = FIELD(model, 0x28, void *);
    void *part;
    void *anim;
    if (res == NULL) {
        return;
    }
    part = ov002_Model_GetPart(model, idx);
    if (part != NULL && FIELD(part, 0x4, void *) != NULL) {
        anim = FIELD(FIELD(part, 0x4, void *), 0x30, void *);
    } else {
        anim = NNS_G2dGetCellDataByIdx(FIELD(res, 0x4, void *), **(u16 **)FIELD(NNS_G2dGetAnimSequenceByIdx(FIELD(res, 0xc, void *), idx), 0xc, void *));
    }
    func_02042628(model, anim, part, 0);
}

typedef struct Blk12 {
    s32 w[3];
} Blk12;

typedef struct Bits021e8cc4 {
    u32 lo : 7;
    u32 b7 : 6;
    u32 hi : 19;
} Bits021e8cc4;

void func_ov002_021e8cc4(void *self) {
    Vec3 at;
    Vec3 up = data_ov002_021ef104;
    Vec3 zero = {0, 0, 0};
    Vec3 w;
    s32 t;
    u32 c;
    s32 t2;
    s32 t3;
    *(Blk12 *)&at = *(Blk12 *)&data_ov002_021ef0bc;
    NNS_G3dGlb.v240 = zero;
    NNS_G3dGlb.v24c = up;
    NNS_G3dGlb.v258 = at;
    MTX_LookAt(&zero, &up, &at, data_02092844);
    NNS_G3dGlb.fc &= ~0xe8;
    MIi_CpuCopyFast((u8 *)self + 0xe4, data_02092800, 0x40);
    NNS_G3dGlb.fc &= ~0x50;
    NNS_G3dGlbFlushP();
    t = 2;
    NNS_G3dGeBufferOP_N(0x10, &t, 1);
    NNS_G3dGeBufferOP_N(0x11, NULL, 0);
    NNS_G3dGeBufferOP_N(0x15, NULL, 0);
    w.x = 0;
    w.y = 0x93000;
    w.z = -0x29;
    NNS_G3dGeBufferOP_N(0x1c, &w, 3);
    c = 0x3e1e08c0;
    NNS_G3dGeBufferOP_N(0x29, &c, 1);
    func_02043db4(1, 0x100000, 0x2d000, 0);
    t2 = 2;
    NNS_G3dGeBufferOP_N(0x10, &t2, 1);
    t3 = 1;
    NNS_G3dGeBufferOP_N(0x12, &t3, 1);
    if (FIELD(self, 0x12c, s32) == 0xff) {
        return;
    }
    FIELD(FIELD(self, 0x124, u8 *), 0x6c, Bits021e8cc4).b7 = 0x3d;
    func_02041c18(FIELD(self, 0x124, void *), FIELD(self, 0x12c, s32));
    {
        u8 *m = FIELD(self, 0x124, u8 *);
        FIELD(m, 0xfc, s32) = 0;
        FIELD(m, 0x100, s32) = 0x8a000;
    }
    ov002_Model_PlayPart(FIELD(self, 0x124, void *), 0);
}

}
