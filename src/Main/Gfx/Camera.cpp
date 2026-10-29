#include "Main/Gfx/Camera.h"
#include "Main/Gfx/GfxMgr.h"

extern "C" {

extern void *func_02043548(CamVec *eye);
extern void func_020434e0(s32 *proj);
extern void func_0203de1c(void *ptr);
extern void func_0204bcb0(Camera *cam);
extern 
void func_0204bac8(Camera *cam);
extern s32 func_01ffbd6c(CamVec *a, CamVec *b, u32 mask, s32 c, s32 d, s32 e);
extern u16 FX_Atan2(s32 y, s32 x);
extern void MTX_LookAt(CamVec *eye, CamVec *up, CamVec *at, void *out);
extern void MTX_PerspectiveW(s32 fovy, s32 aspect, s32 n, s32 fovSin, s32 fovCos, s32 scale, void *out);
extern const s16 FX_SinCosTable_[];
extern void *NNS_G3dFuncAnmJntNsBcaDefault[];
extern s32 func_02040498(s32 max);
extern void *NNS_G3dRS;
extern u32 NNS_G3dGetJointScale_FuncArray;
extern void MIi_CpuClearFast(u32 value, void *dst, u32 size);
extern void MTX_Identity33_(void *mtx);
extern void MTX_MultVec33(const CamVec *v, const void *mtx, CamVec *out);

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

extern CamState NNS_G3dGlb;
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

#define REG_SQRTCNT (*(volatile u16 *)0x40002b0)
#define REG_SQRT_RESULT (*(volatile u32 *)0x40002b4)
#define REG_SQRT_PARAM (*(volatile u64 *)0x40002b8)

// Starts a 64-bit square root on the divider unit and waits for it.
static inline void Cam_SqrtStart(s64 v) {
    REG_SQRTCNT = 1;
    REG_SQRT_PARAM = v << 2;
    while (REG_SQRTCNT & 0x8000) {
    }
}

void func_0204b43c(Camera *cam) {
    *(s32 **)((u8 *)data_02097d48 + 0xa2c) = &cam->fovSin;
    if (cam->flag0 && !cam->flag1) {
        func_0204bcb0(cam);
    }
    if (cam->pitch < 0x8000) {
        if (cam->pitch > 0x3f00) {
            cam->pitch = 0x3f00;
        }
    } else {
        if (cam->pitch < 0xc100) {
            cam->pitch = 0xc100;
        }
    }
    if (cam->mode != 0) {
        s32 sp = FX_SinCosTable_[(cam->pitch >> 4) * 2];
        s32 cp = FX_SinCosTable_[(cam->pitch >> 4) * 2 + 1];
        s32 sy = FX_SinCosTable_[(cam->yaw >> 4) * 2];
        s32 cy = FX_SinCosTable_[(cam->yaw >> 4) * 2 + 1];
        s32 sr = FX_SinCosTable_[(cam->roll >> 4) * 2];
        s32 cr = FX_SinCosTable_[(cam->roll >> 4) * 2 + 1];
        s32 h = Cam_FxMul(cp, cam->dist);
        s32 v = Cam_FxMul(-sp, cam->dist);
        switch (cam->mode) {
        case 1: {
            // Reading y first gives the target's register order.
            s32 y = cam->at.y;
            cam->eye.x = cam->at.x - Cam_FxMul(h, sy);
            cam->eye.y = y - v;
            cam->eye.z = cam->at.z - Cam_FxMul(h, cy);
            break;
        }
        case 2: {
            s32 y = cam->eye.y;
            cam->at.x = cam->eye.x + Cam_FxMul(h, sy);
            cam->at.y = y + v;
            cam->at.z = cam->eye.z + Cam_FxMul(h, cy);
            break;
        }
        }
        cam->up.x = Cam_FxMul(-sr, cy);
        cam->up.y = cr;
        cam->up.z = -Cam_FxMul(-sr, sy);
    }
    if (cam->shakeTime) {
        func_0204bac8(cam);
    } else {
        if (cam->flag6) {
            CamVec at;
            CamVec eye;
            s32 r;
            at = cam->at;
            eye = cam->eye;
            r = func_01ffbd6c(&at, &eye, 0x60000000, 0, 0, -1);
            if (r != -0x1000) {
                if (cam->flag0) {
                    cam->distTarget = r;
                } else {
                    cam->eye = eye;
                }
            }
        } else if (cam->flag5) {
            CamVec a;
            CamVec b;
            s32 r;
            a = cam->eye;
            b = a;
            a.y += 0x5000;
            b.y -= 0x1000;
            r = func_01ffbd6c(&a, &b, 0x60000000, 0, 0, -1);
            if (r != -0x1000) {
                s32 dx;
                s32 dz;
                s64 sq;
                u16 ang;
                b.y += 0x1000;
                a = cam->at;
                dx = a.x - b.x;
                dz = a.z - b.z;
                sq = (s64)dx * dx;
                sq += (s64)dz * dz;
                {
                    s32 root;
                    s32 q;
                    s32 ay;
                    s32 by;
                    Cam_SqrtStart(sq);
                    by = b.y;
                    root = (s32)REG_SQRT_RESULT;
                    ay = a.y;
                    q = root + 1;
                    // Second definition of the same value: it keeps q out of root's register.
                    if (root & 0x40000000) {
                        q = root + 1;
                    }
                    ang = FX_Atan2(by - ay, q >> 1);
                }
                if (cam->flag0) {
                    cam->pitchTarget = ang;
                } else {
                    cam->yaw = ang;
                    cam->eye = b;
                }
            }
        }
        NNS_G3dGlb.eye.x = cam->eye.x;
        NNS_G3dGlb.eye.y = cam->eye.y;
        NNS_G3dGlb.eye.z = cam->eye.z;
        NNS_G3dGlb.up.x = cam->up.x;
        NNS_G3dGlb.up.y = cam->up.y;
        NNS_G3dGlb.up.z = cam->up.z;
        NNS_G3dGlb.at.x = cam->at.x;
        NNS_G3dGlb.at.y = cam->at.y;
        NNS_G3dGlb.at.z = cam->at.z;
        MTX_LookAt(&cam->eye, &cam->up, &cam->at, data_02092844);
        NNS_G3dGlb.dirty &= ~0xe8;
    }
    if (cam->projDirty == 1) {
        MTX_PerspectiveW(cam->aspect, cam->nearClip, cam->farClip, cam->fovSin, cam->fovCos, 0x1000, data_02092800);
        NNS_G3dGlb.dirty &= ~0x50;
        cam->projDirty = 0;
    }
    cam->flag1 = 0;
}

void func_0204b8e8(Camera *cam, void *anim);

void func_0204b924(Camera *cam, s32 speed);

void func_0204bac8(Camera *cam);

void func_0204bcb0(Camera *cam);

u16 func_0204bfa8(Camera *cam);

}
