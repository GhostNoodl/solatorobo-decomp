#include "ov000/FieldCam.h"

extern "C" {

void FieldCam_SetTarget(FieldCam *self, const VecFx32 *pos, const Rot16 *rot, s32 dist, u8 clamp, s16 a6, s16 a7, u8 a8) {
    self->timer = a8;
    if (rot != NULL) {
        self->unk_f8 = *rot;
    } else {
        self->unk_f8 = self->base.rot;
    }
    if (dist != 0) {
        self->unk_f4 = dist;
    } else {
        self->unk_f4 = self->base.dist;
    }
    if (pos != NULL) {
        self->unk_e8 = *pos;
    } else {
        self->unk_bc = self->base.at;
    }
    self->unk_fe = a6;
    self->unk_100 = a7;
    if (!clamp) {
        return;
    }
    if (self->unk_f4 == self->clampDist) {
        if (self->unk_e8.x < self->clampMin.x) {
            self->unk_e8.x = self->clampMin.x;
        } else if (self->unk_e8.x > self->clampMax.x) {
            self->unk_e8.x = self->clampMax.x;
        }
        if (self->unk_e8.y < self->clampMin.y) {
            self->unk_e8.y = self->clampMin.y;
        } else if (self->unk_e8.y > self->clampMax.y) {
            self->unk_e8.y = self->clampMax.y;
        }
        if (self->unk_e8.z < self->clampMin.z) {
            self->unk_e8.z = self->clampMin.z;
        } else if (self->unk_e8.z > self->clampMax.z) {
            self->unk_e8.z = self->clampMax.z;
        }
    } else {
        s32 t = FX_Div(self->unk_f4, self->clampDist);
        if (t >= 0x1000) {
            t = 0x1000;
        }
        if (self->unk_e8.x < self->clampMin.x) {
            self->unk_e8.x += FX_Mul(self->clampMin.x - self->unk_e8.x, t);
        } else if (self->unk_e8.x > self->clampMax.x) {
            self->unk_e8.x += FX_Mul(self->clampMax.x - self->unk_e8.x, t);
        }
        if (self->unk_e8.y < self->clampMin.y) {
            self->unk_e8.y += FX_Mul(self->clampMin.y - self->unk_e8.y, t);
        } else if (self->unk_e8.y > self->clampMax.y) {
            self->unk_e8.y += FX_Mul(self->clampMax.y - self->unk_e8.y, t);
        }
        if (self->unk_e8.z < self->clampMin.z) {
            self->unk_e8.z += FX_Mul(self->clampMin.z - self->unk_e8.z, t);
        } else if (self->unk_e8.z > self->clampMax.z) {
            self->unk_e8.z += FX_Mul(self->clampMax.z - self->unk_e8.z, t);
        }
    }
}

}
