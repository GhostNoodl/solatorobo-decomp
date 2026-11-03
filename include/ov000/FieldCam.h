#ifndef OV000_FIELDCAM_H
#define OV000_FIELDCAM_H

#include "Main/Sys/FieldState.h"

#ifdef __cplusplus
extern "C" {
#endif

// What the zone commands produce (func_ov000_0218a670), filled by func_ov000_02189b44.
typedef struct FieldCamZoneResult {
    /* 0x00 */ VecFx32 pos;
    /* 0x0c */ VecFx32 ofs;
    /* 0x18 */ s32 dist;
    /* 0x1c */ Rot16 ang;
    /* 0x22 */ union {
        u16 all; // cleared as one halfword
        struct {
            u8 aimPitch : 1; // pitch toward the point, at once (commands 8, 9 and 10 set these)
            u8 aimYaw : 1;   // yaw along the point's motion, at once, with a 4x faster point
            u8 snapRoll : 1; // roll at once
        };
    } flags;
} FieldCamZoneResult;

u16 Camera_GetYaw(Camera *cam);
void func_ov000_02189b44(FieldCam *self);
void func_ov000_021899d8(const VecFx32 *pos, const Rot16 *rot, s32 dist, u8 clamp, s16 a6, s16 a7);
void func_ov000_0218a358(FieldCam *self, const VecFx32 *pos, const Rot16 *rot, s32 dist, u8 clamp, s16 a6, s16 a7, u8 a8);
BOOL func_ov000_0218a670(FieldCam *self, const FieldCamZone *zone, const u32 *code, FieldCamZoneResult *st);

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
