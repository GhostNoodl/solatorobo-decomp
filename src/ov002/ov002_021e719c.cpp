#include "ov002/ov002.h"

extern "C" {

s32 func_02049130(s32 t, s32 a, s32 b);

void NNS_G3dGlbFlushP(void);

void NNS_G3dGeBufferOP_N(int cmd, void *data, int n);

void func_02043db4(int a, s32 b, s32 c, u16 d);

extern Vec3 data_ov002_021ef104;

extern Vec3 data_ov002_021ef0bc;

void func_ov002_021e719c(void *self) {
    s32 now = FIELD(data_ov002_021f0f98[1], 0xd0, s32);
    s32 a;
    if (now < FIELD(self, 0x18, s32)) {
        return;
    }
    if (now - FIELD(self, 0x18, s32) >= FIELD(self, 0x5c, s32)) {
        a = FIELD(self, 0x58, s32);
    } else {
        a = func_02049130(FX_Div(now - FIELD(self, 0x18, s32), FIELD(self, 0x5c, s32)), FIELD(self, 0x54, s32) << 12, FIELD(self, 0x58, s32) << 12) >> 12;
    }
    {
        Vec3 zero = {0, 0, 0};
        Vec3 up = data_ov002_021ef104;
        Vec3 at = data_ov002_021ef0bc;
        Vec3 w;
        s32 t;
        u32 c;
        s32 t2;
        s32 t3;
        u8 *g2 = (u8 *)data_ov002_021f0f98[1];
        NNS_G3dGlb.v240 = zero;
        NNS_G3dGlb.v24c = up;
        NNS_G3dGlb.v258 = at;
        MTX_LookAt(&zero, &up, &at, data_02092844);
        NNS_G3dGlb.fc &= ~0xe8;
        MIi_CpuCopyFast(g2 + 0xe4, data_02092800, 0x40);
        NNS_G3dGlb.fc &= ~0x50;
        NNS_G3dGlbFlushP();
        t = 2;
        NNS_G3dGeBufferOP_N(0x10, &t, 1);
        NNS_G3dGeBufferOP_N(0x11, NULL, 0);
        NNS_G3dGeBufferOP_N(0x15, NULL, 0);
        c = 0x3f0000c0 | (a << 16);
        NNS_G3dGeBufferOP_N(0x29, &c, 1);
        w.z = FIELD(self, 0x20, s32);
        w.x = 0x80000;
        w.y = 0x60000;
        NNS_G3dGeBufferOP_N(0x1c, &w, 3);
        func_02043db4(0, 0x100000, 0xc0000, FIELD(self, 0x50, u16));
        t2 = 2;
        NNS_G3dGeBufferOP_N(0x10, &t2, 1);
        t3 = 1;
        NNS_G3dGeBufferOP_N(0x12, &t3, 1);
    }
}

}
