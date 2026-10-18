#ifndef MAIN_GFX_CAMERA_H
#define MAIN_GFX_CAMERA_H

#include "types.h"

#ifdef __cplusplus
extern "C" {
#endif

typedef struct CamVec {
    s32 x;
    s32 y;
    s32 z;
} CamVec;

// Camera with an orbit (pitch/yaw/roll/distance) mode, shakes and animated paths.
typedef struct Camera {
    /* 0x00 */ const void *vtable; // data_0208b8c0
    /* 0x04 */ CamVec eye;
    /* 0x10 */ CamVec at;
    /* 0x1c */ CamVec up;
    /* 0x28 */ s32 fovSin;
    /* 0x2c */ s32 fovCos;
    /* 0x30 */ s16 aspect;
    /* 0x32 */ s16 nearClip;
    /* 0x34 */ s16 farClip;
    /* 0x36 */ u8 unk_36[8];
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
    /* 0x68 */ CamVec eyeTarget;
    /* 0x74 */ s32 eyeRate;
    /* 0x78 */ CamVec atTarget;
    /* 0x84 */ s32 atRate;
    /* 0x88 */ CamVec upTarget;
    /* 0x94 */ s32 upRate;
    /* 0x98 */ u8 shakeRandom;
    /* 0x99 */ u8 shakeTime;
    /* 0x9a */ u8 shakeLen;
    /* 0x9b */ u8 shakeCur;
    /* 0x9c */ u8 flag0 : 1;
    /* 0x9c */ u8 flag1 : 1;
    /* 0x9c */ u8 shakeX : 1;
    /* 0x9c */ u8 shakeY : 1;
    /* 0x9c */ u8 shakeZ : 1;
    /* 0x9c */ u8 flag5 : 1;
    /* 0x9c */ u8 flag6 : 1;
    /* 0x9c */ u8 flag7 : 1;
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

extern const u32 data_0208b8c0[];

#ifdef __cplusplus
}
#endif

#endif
