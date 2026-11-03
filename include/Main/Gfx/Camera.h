#ifndef MAIN_GFX_CAMERA_H
#define MAIN_GFX_CAMERA_H

#include "types.h"
#include "nitro/fx.h"

#ifdef __cplusplus
extern "C" {
#endif

// Camera with an orbit (pitch/yaw/roll/distance) mode, shakes and animated paths.
typedef struct Camera {
    /* 0x00 */ const void *vtable; // Camera_vtbl
    /* 0x04 */ VecFx32 eye;
    /* 0x10 */ VecFx32 at;
    /* 0x1c */ VecFx32 up;
    // projection, in MTX_PerspectiveW / NNS_G3dGlbPerspectiveW argument order
    /* 0x28 */ s32 nearClip;
    /* 0x2c */ s32 farClip;
    /* 0x30 */ s16 fovySin;
    /* 0x32 */ s16 fovyCos;
    /* 0x34 */ s16 aspect;
    /* 0x36 */ u16 fovyIdx;
    /* 0x38 */ s32 fovyDeg;
    /* 0x3c */ u8 unk_3c[2];
    /* 0x3e */ u8 projDirty;
    /* 0x40 */ u16 mode;
    /* 0x42 */ u16 pitch;
    /* 0x44 */ u16 yaw;
    /* 0x46 */ u16 roll;
    /* 0x48 */ s32 dist;
    /* 0x4c */ s32 distTarget;
    /* 0x50 */ s32 distRate;
    /* 0x54 */ u16 pitchTarget;
    /* 0x56 */ u16 yawTarget;
    /* 0x58 */ u16 rollTarget;
    /* 0x5c */ s32 pitchRate;
    /* 0x60 */ s32 yawRate;
    /* 0x64 */ s32 rollRate;
    /* 0x68 */ VecFx32 eyeTarget;
    /* 0x74 */ s32 eyeRate;
    /* 0x78 */ VecFx32 atTarget;
    /* 0x84 */ s32 atRate;
    /* 0x88 */ VecFx32 upTarget;
    /* 0x94 */ s32 upRate;
    /* 0x98 */ u8 shakeRandom;
    /* 0x99 */ u8 shakeTime;
    /* 0x9a */ u8 shakeLen;
    /* 0x9b */ u8 shakeCur;
    /* 0x9c */ union {
        u8 flags; // the bits below as one byte (shakeX | shakeY | shakeZ is 0x1c)
        struct {
            u8 smooth : 1;     // ease eye/at/up/angles toward their targets (func_0204bcb0)
            u8 animated : 1;   // set by the path animation step (func_0204b924), skips the easing once
            u8 shakeX : 1;
            u8 shakeY : 1;
            u8 shakeZ : 1;
            u8 groundClip : 1; // ray-cast down from above the eye and keep it over the map
            u8 wallClip : 1;   // ray-cast at -> eye and pull the eye in front of the map
            u8 flag7 : 1;
        };
    };
    /* 0x9e */ s16 speed;
    /* 0xa0 */ s32 animFrame;
    /* 0xa4 */ s32 animSpeed;
    /* 0xa8 */ void *anim;
    /* 0xac */ void *animFunc;
    /* 0xb0 */ s32 unk_b0;
    /* 0xb4 */ s32 unk_b4;
    /* 0xb8 */ u8 unk_b8;
    /* 0xb9 */ u8 unk_b9;
} Camera;

extern const u32 Camera_vtbl[];

#ifdef __cplusplus
}
#endif

#endif
