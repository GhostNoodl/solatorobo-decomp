#include "ov000/LoCommon.h"
#include "nitro/fx.h"
#include "ov000/ModelViewer.h"

extern "C" {

extern u8 data_ov000_021c985c[];

static inline void SetFrustum021627ac(ModelViewer *self, s32 x, s32 y, s32 z, s32 s) {
    self->projOfs.x = x;
    self->projOfs.y = y;
    self->projOfs.z = z;
    self->projScale = s;
    MTX_FrustumW(LO_FX_MUL(self->projOfs.y + 0xf5c, s), LO_FX_MUL(self->projOfs.y - 0xf5c, s), LO_FX_MUL(self->projOfs.x - 0x147b, s), LO_FX_MUL(self->projOfs.x + 0x147b, s), 0x1000, 0x1e000, 0x1000, &self->proj);
}

void ModelViewer_InitCamera(ModelViewer *self) {
    self->eye.x = 0x20cd;
    self->eye.y = 0;
    self->eye.z = 0x7ca4;
    self->at.x = LFLD(s32, data_ov000_021c985c, 0x50);
    self->at.y = LFLD(s32, data_ov000_021c985c, 0x54);
    self->at.z = LFLD(s32, data_ov000_021c985c, 0x58);
    self->up.x = 0;
    self->up.y = 0x1000;
    self->up.z = 0;
    SetFrustum021627ac(self, -0x8f6, 0x785, 0, 0x3d7);
    self->unk_6ec.x = 0x99a;
    self->unk_6ec.y = 0;
    self->unk_6ec.z = 0;
    self->unk_6f8.x = -0x99a;
    self->unk_6f8.y = 0;
    self->unk_6f8.z = 0;
}

void ModelViewer_SetCamera(ModelViewer *self, const VecFx32 *eye, const VecFx32 *at, const VecFx32 *up) {
    s32 ex = eye->x;
    s32 ey = eye->y;
    s32 ez = eye->z;
    s32 ax = at->x;
    s32 ay = at->y;
    s32 az = at->z;
    s32 ux = up->x;
    s32 uy = up->y;
    s32 uz = up->z;
    // Storing at.y once ahead of the rest gives the original load order
    // (at is read first, with ldmib).
    self->at.y = ay;
    self->eye.x = ex;
    self->eye.y = ey;
    self->eye.z = ez;
    self->at.x = ax;
    self->at.y = ay;
    self->at.z = az;
    self->up.x = ux;
    self->up.y = uy;
    self->up.z = uz;
}

}
