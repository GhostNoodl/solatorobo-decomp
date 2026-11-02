#ifndef OV000_FIELDCAM_H
#define OV000_FIELDCAM_H

#include "Main/Sys/FieldState.h"

#ifdef __cplusplus
extern "C" {
#endif

u16 Camera_GetYaw(Camera *cam);

#ifdef __cplusplus
}
#endif

// Yaw of the field camera: the stored orbit yaw while an orbit mode is set, else the yaw of
// the eye -> target direction (Camera_GetYaw).
static inline u16 FieldCam_GetYaw(FieldCam *cam) {
    if (cam->base.mode != 0) {
        return cam->base.yaw;
    }
    return Camera_GetYaw(&cam->base);
}

#endif
