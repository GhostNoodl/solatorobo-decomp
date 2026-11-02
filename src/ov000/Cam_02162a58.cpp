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
void Obj02190758_SetRot(void *m, void *p, s32 a);
BOOL Model021903b4_Draw(void *m);

void ModelViewer_Draw(ModelViewer *self) {
    NNS_G3dGlb.camPos = self->eye;
    NNS_G3dGlb.camUp = self->up;
    NNS_G3dGlb.camTarget = self->at;
    MTX_LookAt(&self->eye, &self->up, &self->at, (MtxFx43 *)data_02092844);
    NNS_G3dGlb.flag &= ~0xe8;
    MIi_CpuCopyFast(&self->proj, data_02092800, 0x40);
    NNS_G3dGlb.flag &= ~0x50;
    self->model.trans = self->pos;
    Obj02190758_SetRot(&self->model, self->rot, 0);
    Model021903b4_Draw(&self->model);
}
}
