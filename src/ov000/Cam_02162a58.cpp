#include "ov000/LoCommon.h"
#include "ov000/Vec.h"

typedef struct {
    u8 unk_00[0x8];
    u8 projMtx[0x40];
    u8 unk_48[0xb4];
    u32 flag;
    u8 unk_100[0x140];
    VecFx32 camPos;
    VecFx32 camUp;
    VecFx32 camTarget;
} Glb02162a58;

extern "C" {
extern Glb02162a58 NNS_G3dGlb;
extern u8 data_02092844[];
extern u8 data_02092800[];
void MTX_LookAt(const VecFx32 *a, const VecFx32 *b, const VecFx32 *c, void *d);
void MIi_CpuCopyFast(const void *a, void *b, u32 c);
void func_ov000_02190758(void *m, void *p, s32 a);
BOOL func_ov000_021903b4(void *m);

void func_ov000_02162a58(u8 *self) {
    NNS_G3dGlb.camPos = LFLD(VecFx32, self, 0x644);
    NNS_G3dGlb.camUp = LFLD(VecFx32, self, 0x65c);
    NNS_G3dGlb.camTarget = LFLD(VecFx32, self, 0x650);
    MTX_LookAt(&LFLD(VecFx32, self, 0x644), &LFLD(VecFx32, self, 0x65c), &LFLD(VecFx32, self, 0x650), data_02092844);
    NNS_G3dGlb.flag &= ~0xe8;
    MIi_CpuCopyFast(self + 0x668, data_02092800, 0x40);
    NNS_G3dGlb.flag &= ~0x50;
    LFLD(VecFx32, self, 0x5d4) = LFLD(VecFx32, self, 0x6d8);
    func_ov000_02190758(self + 0x55c, self + 0x6e4, 0);
    func_ov000_021903b4(self + 0x55c);
}
}
