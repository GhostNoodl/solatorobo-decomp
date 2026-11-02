#include "Main/Gfx/Camera.h"
#include "Main/Gfx/GfxMgr.h"
#include "nitro/mi.h"

extern "C" {

extern void *GfxCamPos_Init(VecFx32 *eye);
extern void func_020434e0(s32 *proj);
extern void Heap_Free(void *ptr);
extern void func_0204bcb0(Camera *cam);
extern 
void func_0204bac8(Camera *cam);
extern s32 func_01ffbd6c(VecFx32 *a, VecFx32 *b, u32 mask, s32 c, s32 d, s32 e);
extern void *NNS_G3dFuncAnmJntNsBcaDefault[];
extern u32 Rand_UpTo(u32 max);
extern void *NNS_G3dRS;
extern u32 NNS_G3dGetJointScale_FuncArray;

typedef struct CamAnimResult {
    /* 0x00 */ u32 flags;
    /* 0x04 */ u8 unk_04[0x24];
    /* 0x28 */ s32 rot[9];
    /* 0x4c */ VecFx32 trans;
} CamAnimResult;

typedef struct CamAnimWork {
    /* 0x000 */ u8 unk_000[0xe8];
    /* 0x0e8 */ u32 unk_0e8;
    /* 0x0ec */ u8 unk_0ec[0x9c];
} CamAnimWork;

typedef void (*CamAnimFunc)(CamAnimResult *out, s32 *frame, s32 arg);
extern s32 Rand_PlusMinus(s32 amp);
extern u16 func_01ffc128(u16 target, u16 cur, s32 rate, u32 a, u16 b);
typedef struct CamState {
    /* 0x000 */ u8 unk_000[0xfc];
    /* 0x0fc */ u32 dirty;
    /* 0x100 */ u8 unk_100[0x140];
    /* 0x240 */ VecFx32 eye;
    /* 0x24c */ VecFx32 up;
    /* 0x258 */ VecFx32 at;
} CamState;

extern CamState NNS_G3dGlb;
extern u8 data_02092800[];
extern u8 data_02092844[];

static inline void Cam_VecSet(VecFx32 *v, s32 x, s32 y, s32 z) {
    v->x = x;
    v->y = y;
    v->z = z;
}

static inline s32 Cam_FxMul(s32 a, s32 b) {
    return (s32)(((s64)a * b + 0x800) >> 12);
}

static inline void Camera_Init(Camera *cam) {
    cam->vtable = data_0208b8c0;
    GfxCamPos_Init(&cam->eye);
    func_020434e0(&cam->nearClip);
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

Camera *func_0204b2c0(Camera *cam);

Camera *Camera_Ctor(Camera *cam);

void func_0204b420(Camera *cam);

Camera *Camera_DtorDelete(Camera *cam);

void func_0204b438(Camera *cam);

void Camera_Apply(Camera *cam);

void Camera_SetAnim(Camera *cam, void *anim) {
    cam->anim = anim;
    cam->animFrame = 0;
    cam->animSpeed = 0x1000;
    cam->animFunc = NNS_G3dFuncAnmJntNsBcaDefault[0];
    cam->unk_b0 = 0;
    cam->unk_b4 = 0;
    cam->unk_b8 = 0x7f;
    cam->unk_b9 = 0;
}

void func_0204b924(Camera *cam, s32 speed) {
    VecFx32 vec;
    CamAnimWork work;
    CamAnimResult res;
    s32 max;
    s32 ex;
    s32 ey;
    s32 ez;
    if (cam->anim == NULL) {
        return;
    }
    cam->animated = TRUE;
    if (speed == 0x1000) {
        speed = cam->speed;
    } else if (cam->speed != 0x1000) {
        speed = (s16)Cam_FxMul(cam->speed, speed);
    }
    max = (*(u16 *)((u8 *)cam->anim + 4) << 12) - 1;
    if (cam->animFrame >= max) {
        return;
    }
    cam->animFrame += speed;
    if (cam->animFrame > max) {
        cam->animFrame = max;
    }
    NNS_G3dRS = &work;
    MIi_CpuClearFast(0, &work, sizeof(work));
    work.unk_0e8 = NNS_G3dGetJointScale_FuncArray;
    MTX_Identity33_((MtxFx33 *)res.rot);
    res.trans.x = 0;
    res.trans.y = 0;
    res.trans.z = 0;
    ((CamAnimFunc)NNS_G3dFuncAnmJntNsBcaDefault[0])(&res, &cam->animFrame, 0);
    NNS_G3dRS = NULL;
    cam->mode = 0;
    ex = cam->eye.x;
    ey = cam->eye.y;
    ez = cam->eye.z;
    cam->eye.x = res.trans.x;
    cam->eye.y = res.trans.y;
    cam->eye.z = res.trans.z;
    if (res.flags & 2) {
        vec.x = cam->at.x;
        vec.y = cam->at.y;
        vec.z = cam->at.z;
        vec.x = vec.x - ex;
        vec.y = vec.y - ey;
        vec.z = vec.z - ez;
    } else {
        Cam_VecSet(&vec, 0, 0, cam->dist);
        MTX_MultVec33(&vec, (const MtxFx33 *)res.rot, &vec);
    }
    VEC_Add(&vec, &res.trans, &vec);
    cam->at.x = vec.x;
    cam->at.y = vec.y;
    cam->at.z = vec.z;
}

void func_0204bac8(Camera *cam) {
    VecFx32 eye;
    VecFx32 at;
    VecFx32 ofs;
    VecFx32 newEye;
    VecFx32 newAt;
    s32 amp;
    eye.x = cam->eye.x;
    eye.y = cam->eye.y;
    eye.z = cam->eye.z;
    at.x = cam->at.x;
    at.y = cam->at.y;
    at.z = cam->at.z;
    ofs.x = 0;
    ofs.y = 0;
    ofs.z = 0;
    if (cam->shakeRandom) {
        cam->shakeCur = Rand_UpTo(cam->shakeLen - 1) + 1;
    }
    amp = (cam->shakeTime << 7) * cam->shakeCur / cam->shakeLen;
    if (cam->shakeX) {
        ofs.x = Rand_PlusMinus(amp);
    }
    if (cam->shakeY) {
        ofs.y = Rand_PlusMinus(amp);
    }
    if (cam->shakeZ) {
        ofs.z = Rand_PlusMinus(amp);
    }
    VEC_Add(&eye, &ofs, &newEye);
    VEC_Add(&at, &ofs, &newAt);
    cam->eye.x = newEye.x;
    cam->eye.y = newEye.y;
    cam->eye.z = newEye.z;
    cam->at.x = newAt.x;
    cam->at.y = newAt.y;
    cam->at.z = newAt.z;
    NNS_G3dGlb.eye.x = cam->eye.x;
    NNS_G3dGlb.eye.y = cam->eye.y;
    NNS_G3dGlb.eye.z = cam->eye.z;
    NNS_G3dGlb.up.x = cam->up.x;
    NNS_G3dGlb.up.y = cam->up.y;
    NNS_G3dGlb.up.z = cam->up.z;
    NNS_G3dGlb.at.x = cam->at.x;
    NNS_G3dGlb.at.y = cam->at.y;
    NNS_G3dGlb.at.z = cam->at.z;
    MTX_LookAt(&cam->eye, &cam->up, &cam->at, (MtxFx43 *)data_02092844);
    NNS_G3dGlb.dirty &= ~0xe8;
    cam->eye.x = eye.x;
    cam->eye.y = eye.y;
    cam->eye.z = eye.z;
    cam->at.x = at.x;
    cam->at.y = at.y;
    cam->at.z = at.z;
    if (cam->shakeRandom) {
        return;
    }
    if (cam->shakeCur > 1) {
        cam->shakeCur--;
    } else {
        cam->shakeTime = 0;
    }
}

void func_0204bcb0(Camera *cam) {
    VecFx32 eye;
    VecFx32 at;
    VecFx32 up;
    eye.x = cam->eye.x;
    eye.y = cam->eye.y;
    eye.z = cam->eye.z;
    at.x = cam->at.x;
    at.y = cam->at.y;
    at.z = cam->at.z;
    switch (cam->mode) {
        case 0:
            if (cam->eyeRate != 0) {
                VecFx32 d;
                d.x = cam->eyeTarget.x - eye.x;
                d.y = cam->eyeTarget.y - eye.y;
                d.z = cam->eyeTarget.z - eye.z;
                VEC_MultAdd(cam->eyeRate, &d, &eye, &eye);
            }
            if (cam->atRate != 0) {
                VecFx32 d;
                d.x = cam->atTarget.x - at.x;
                d.y = cam->atTarget.y - at.y;
                d.z = cam->atTarget.z - at.z;
                VEC_MultAdd(cam->atRate, &d, &at, &at);
            }
            if (cam->upRate != 0) {
                VecFx32 d;
                up.x = cam->up.x;
                up.y = cam->up.y;
                up.z = cam->up.z;
                d.x = cam->upTarget.x - up.x;
                d.y = cam->upTarget.y - up.y;
                d.z = cam->upTarget.z - up.z;
                VEC_MultAdd(cam->upRate, &d, &up, &up);
                cam->up.x = up.x;
                cam->up.y = up.y;
                cam->up.z = up.z;
            }
            break;
        case 1:
            if (cam->atRate != 0) {
                VecFx32 d;
                d.x = cam->atTarget.x - at.x;
                d.y = cam->atTarget.y - at.y;
                d.z = cam->atTarget.z - at.z;
                VEC_MultAdd(cam->atRate, &d, &at, &at);
            }
            break;
        case 2:
            if (cam->eyeRate != 0) {
                VecFx32 d;
                d.x = cam->eyeTarget.x - eye.x;
                d.y = cam->eyeTarget.y - eye.y;
                d.z = cam->eyeTarget.z - eye.z;
                VEC_MultAdd(cam->eyeRate, &d, &eye, &eye);
            }
            break;
    }
    cam->eye.x = eye.x;
    cam->eye.y = eye.y;
    cam->eye.z = eye.z;
    cam->at.x = at.x;
    cam->at.y = at.y;
    cam->at.z = at.z;
    if (cam->mode == 0) {
        return;
    }
    if (cam->distRate != 0) {
        s32 dist = VEC_Distance(&eye, &at);
        cam->dist = dist;
        if (cam->distTarget != dist) {
            cam->dist = dist + Cam_FxMul(cam->distRate, cam->distTarget - dist);
        }
    }
    if (cam->pitchRate != 0 && cam->pitchTarget != cam->pitch) {
        cam->pitch = func_01ffc128(cam->pitchTarget, cam->pitch, cam->pitchRate, 1, 0x8000);
    }
    if (cam->yawRate != 0 && cam->yawTarget != cam->yaw) {
        cam->yaw = func_01ffc128(cam->yawTarget, cam->yaw, cam->yawRate, 1, 0x8000);
    }
    if (cam->rollRate != 0 && cam->rollTarget != cam->roll) {
        cam->roll = func_01ffc128(cam->rollTarget, cam->roll, cam->rollRate, 1, 0x8000);
    }
}

u16 Camera_GetYaw(Camera *cam) {
    return FX_Atan2(cam->at.x - cam->eye.x, cam->at.z - cam->eye.z);
}

}
