#include "Main/Gfx/Camera.h"
#include "Main/Gfx/GfxMgr.h"

extern "C" {

extern void func_02043548(CamVec *eye);
extern void func_020434e0(s32 *proj);
extern void func_0203de1c(void *ptr);
extern void func_0204bcb0(Camera *cam);
extern 
void func_0204bac8(Camera *cam);
extern s32 func_01ffbd6c(CamVec *a, CamVec *b, u32 mask, s32 c, s32 d, s32 e);
extern u16 FX_Atan2(s32 y, s32 x);
extern void func_02011ff0(CamVec *eye, CamVec *up, CamVec *at, void *out);
extern void func_02012758(s32 fovy, s32 aspect, s32 n, s32 fovSin, s32 fovCos, s32 scale, void *out);
extern const s16 FX_SinCosTable_[];
extern void *data_0208b000[];
extern s32 func_02040498(s32 max);
extern void *data_02092a5c;
extern u32 data_0208b078;
extern void MIi_CpuClearFast(u32 value, void *dst, u32 size);
extern void func_02011340(void *mtx);
extern void func_020117a4(const CamVec *v, const void *mtx, CamVec *out);

typedef struct CamAnimResult {
    /* 0x00 */ u32 flags;
    /* 0x04 */ u8 unk_04[0x24];
    /* 0x28 */ s32 rot[9];
    /* 0x4c */ CamVec trans;
} CamAnimResult;

typedef struct CamAnimWork {
    /* 0x000 */ u8 unk_000[0xe8];
    /* 0x0e8 */ u32 unk_0e8;
    /* 0x0ec */ u8 unk_0ec[0x9c];
} CamAnimWork;

typedef void (*CamAnimFunc)(CamAnimResult *out, s32 *frame, s32 arg);
extern s32 func_02040528(s32 amp);
extern void VEC_MultAdd(s32 scale, const CamVec *dir, const CamVec *base, CamVec *out);
extern s32 VEC_Distance(const CamVec *a, const CamVec *b);
extern u16 func_01ffc128(u16 target, u16 cur, s32 rate, s32 a, s32 b);
extern void VEC_Add(const CamVec *a, const CamVec *b, CamVec *out);
typedef struct CamState {
    /* 0x000 */ u8 unk_000[0xfc];
    /* 0x0fc */ u32 dirty;
    /* 0x100 */ u8 unk_100[0x140];
    /* 0x240 */ CamVec eye;
    /* 0x24c */ CamVec up;
    /* 0x258 */ CamVec at;
} CamState;

extern CamState data_020927f8;
extern u8 data_02092800[];
extern u8 data_02092844[];

static inline void Cam_VecSet(CamVec *v, s32 x, s32 y, s32 z) {
    v->x = x;
    v->y = y;
    v->z = z;
}

static inline s32 Cam_FxMul(s32 a, s32 b) {
    return (s32)(((s64)a * b + 0x800) >> 12);
}

static inline void Camera_Init(Camera *cam) {
    cam->vtable = data_0208b8c0;
    func_02043548(&cam->eye);
    func_020434e0(&cam->fovSin);
    cam->mode = 1;
    cam->dist = 0xa000;
    cam->pitch = 0x1000;
    cam->yaw = 0;
    cam->roll = 0;
    cam->distTarget = 0;
    cam->distRate = 0;
    cam->pitchTarget = 0;
    cam->yawTarget = 0;
    cam->rollTarget = 0;
    cam->pitchRate = 0;
    cam->yawRate = 0;
    cam->rollRate = 0;
    cam->eyeTarget.x = 0;
    cam->eyeTarget.y = 0;
    cam->eyeTarget.z = 0;
    cam->eyeRate = 0;
    cam->atTarget.x = 0;
    cam->atTarget.y = 0;
    cam->atTarget.z = 0;
    cam->atRate = 0;
    cam->upTarget.x = 0;
    cam->upTarget.y = 0;
    cam->upTarget.z = 0;
    cam->upRate = 0;
    cam->shakeRandom = 0;
    cam->shakeTime = 0;
    *(u8 *)((u8 *)cam + 0x9c) = 0;
    cam->speed = 0x1000;
}

Camera *func_0204b2c0(Camera *cam) {
    Camera_Init(cam);
    return cam;
}

Camera *func_0204b370(Camera *cam) {
    Camera_Init(cam);
    return cam;
}

void func_0204b420(Camera *cam) {
}

Camera *func_0204b424(Camera *cam) {
    func_0203de1c(cam);
    return cam;
}

void func_0204b438(Camera *cam) {
}

void func_0204b43c(Camera *cam);

void func_0204b8e8(Camera *cam, void *anim);

void func_0204b924(Camera *cam, s32 speed);

void func_0204bac8(Camera *cam);

void func_0204bcb0(Camera *cam);

u16 func_0204bfa8(Camera *cam);

}
