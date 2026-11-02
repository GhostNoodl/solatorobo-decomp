#include "ov000/LoCommon.h"
#include "ov000/Vec.h"
#include "nitro/mi.h"

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
void func_ov000_02190758(void *m, void *p, s32 a);
BOOL func_ov000_021903b4(void *m);

struct Obj02162a58 {
    u8 unk_00[0x5d4];
    VecFx32 unk_5d4;
    u8 unk_5e0[0x64];
    VecFx32 unk_644;
    VecFx32 unk_650;
    VecFx32 unk_65c;
    u8 unk_668[0x70];
    VecFx32 unk_6d8;
};

void func_ov000_02162a58(Obj02162a58 *self) {
    NNS_G3dGlb.camPos = self->unk_644;
    NNS_G3dGlb.camUp = self->unk_65c;
    NNS_G3dGlb.camTarget = self->unk_650;
    MTX_LookAt(&self->unk_644, &self->unk_65c, &self->unk_650, (MtxFx43 *)data_02092844);
    NNS_G3dGlb.flag &= ~0xe8;
    MIi_CpuCopyFast((u8 *)self + 0x668, data_02092800, 0x40);
    NNS_G3dGlb.flag &= ~0x50;
    self->unk_5d4 = self->unk_6d8;
    func_ov000_02190758((u8 *)self + 0x55c, (u8 *)self + 0x6e4, 0);
    func_ov000_021903b4((u8 *)self + 0x55c);
}
}
