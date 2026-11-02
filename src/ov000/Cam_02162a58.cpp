#include "ov000/LoCommon.h"
#include "ov000/Vec.h"
#include "nitro/mi.h"
#include "ov000/ModelViewer.h"

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

void func_ov000_02162a58(ModelViewer *self) {
    NNS_G3dGlb.camPos = self->eye;
    NNS_G3dGlb.camUp = self->up;
    NNS_G3dGlb.camTarget = self->at;
    MTX_LookAt(&self->eye, &self->up, &self->at, (MtxFx43 *)data_02092844);
    NNS_G3dGlb.flag &= ~0xe8;
    MIi_CpuCopyFast(&self->proj, data_02092800, 0x40);
    NNS_G3dGlb.flag &= ~0x50;
    self->model.trans = self->pos;
    func_ov000_02190758(&self->model, self->rot, 0);
    func_ov000_021903b4(&self->model);
}
}
