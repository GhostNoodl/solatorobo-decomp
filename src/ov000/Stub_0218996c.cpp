#include "ov000/VObj.h"
#include "ov000/SceneCmdPool.h"
#include "ov000/FieldCam.h"

extern "C" {


void Field_ShakeCamera(u8 a, u8 b) {
    FieldCam *s = &data_ov000_021ccd50.scene->cam;
    if (s == NULL) {
        return;
    }
    s->base.shakeX = 1;
    s->base.shakeY = 1;
    s->base.shakeZ = 1;
    s->base.shakeTime = a;
    s->base.shakeLen = b;
    s->base.shakeCur = b;
}

void Field_ShakeCameraY(u8 a, u8 b) {
    FieldCam *s = &data_ov000_021ccd50.scene->cam;
    if (s == NULL) {
        return;
    }
    s->base.shakeX = 0;
    s->base.shakeY = 1;
    s->base.shakeZ = 0;
    s->base.shakeTime = a;
    s->base.shakeLen = b;
    s->base.shakeCur = b;
}

void Field_SetCamTarget(const VecFx32 *pos, const Rot16 *rot, s32 dist, u8 clamp, s16 a6, s16 a7) {
    FieldCam *s = &data_ov000_021ccd50.scene->cam;
    if (s == NULL) {
        return;
    }
    FieldCam_SetTarget(s, pos, rot, dist, clamp, a6, a7, 1);
}

}
