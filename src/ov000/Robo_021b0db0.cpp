#include "ov000/LoCommon.h"
#include "Main/Res/StageCmd.h"
#include "Main/Sys/FieldState.h"
#include "ov000/Vec.h"
#include "ov000/ObjLayouts.h"

extern "C" {
extern void *data_02097dc8;
extern const VecFx32 data_02092a50;
extern u8 data_ov000_021cc5e3[];
extern u8 data_ov000_021cc751[];
extern u8 data_ov000_021cc757[];
extern u8 data_ov000_021cc75d[];
extern u8 data_ov000_021cc763[];
u16 Camera_GetYaw(void *cam);
u16 Pad_LookupDir(void *rng, s32 range);
BOOL func_ov000_02190cb0(void *a, void *b, s32 c, s32 d);
void func_ov000_021915a0(void *a);
s32 *NNS_G3dGlbGetInvV(void);
void VEC_Add(const VecFx32 *a, const VecFx32 *b, VecFx32 *ab);
u16 func_01ffc128(u16 target, u16 cur, s32 step, s32 a, s32 b);

static inline void MulVec33_021b0db0(const VecFx32 *v, const s32 *m, VecFx32 *out) {
    s32 x = v->x;
    s32 y = v->y;
    s32 z = v->z;
    out->x = (s32)(((s64)x * m[0] + (s64)y * m[3] + (s64)z * m[6]) >> 12);
    out->y = (s32)(((s64)x * m[1] + (s64)y * m[4] + (s64)z * m[7]) >> 12);
    out->z = (s32)(((s64)x * m[2] + (s64)y * m[5] + (s64)z * m[8]) >> 12);
}

static inline BOOL Flip021b0db0(void) {
    return data_0214a424->bits18.flag10 ? TRUE : FALSE;
}

void func_ov000_021b0db0(Robo021ca458 *self, s32 spd) {
    u16 yaw;
    u16 tilt;
    u8 *cam = (u8 *)data_ov000_021ccd54 + 0xf4;
    if (LFLD(u16, cam, 0x40) != 0) {
        yaw = LFLD(u16, cam, 0x44);
    } else {
        yaw = Camera_GetYaw(cam);
    }
    tilt = 0;
    if (spd > 0) {
        u16 ang = Pad_LookupDir(data_02097dc8, 0) + 0x8000;
        s32 idx = ang >> 4;
        s32 z;
        u16 keys;
        u8 *anim;
        self->unk_af0.x += (s32)(((s64)spd * FX_SinCosTable_[idx * 2] + 0x800) >> 12);
        if (self->unk_af0.x > 0x6000) {
            self->unk_af0.x = 0x6000;
        } else if (self->unk_af0.x < -0x6000) {
            self->unk_af0.x = -0x6000;
        }
        z = (s32)(((s64)spd * FX_SinCosTable_[idx * 2 + 1] + 0x800) >> 12);
        if (data_0214a424->bits18.flag10) {
            z = -z;
        }
        self->unk_af0.y += z;
        if (self->unk_af0.y > 0x1a66) {
            self->unk_af0.y = 0x1a66;
        } else if (self->unk_af0.y < -0x6800) {
            self->unk_af0.y = -0x6800;
        }
        self->unk_af0.z = 0;
        keys = self->padCur;
        anim = data_ov000_021cc5e3;
        if (keys & 0x20) {
            tilt = 0xf800;
            anim = data_ov000_021cc751;
        } else if (keys & 0x10) {
            tilt = 0x800;
            anim = data_ov000_021cc757;
        } else if (((keys & 0x40) && !Flip021b0db0()) || ((keys & 0x80) && data_0214a424->bits18.flag10)) {
            anim = data_ov000_021cc75d;
        } else if (((keys & 0x80) && !Flip021b0db0()) || ((keys & 0x40) && data_0214a424->bits18.flag10)) {
            anim = data_ov000_021cc763;
        }
        func_ov000_02190cb0(self->model, anim, 0xcd, 0);
    } else if (spd == 0) {
        func_ov000_02190cb0(self->model, data_ov000_021cc5e3, 0xcd, tilt);
        func_ov000_021915a0(self->model);
    }
    MulVec33_021b0db0((VecFx32 *)((u8 *)self + 0xaf0), NNS_G3dGlbGetInvV(), (VecFx32 *)((u8 *)self + 0x9c));
    VEC_Add((VecFx32 *)((u8 *)self + 0x9c), &data_02092a50, (VecFx32 *)((u8 *)self + 0x70));
    self->rot_y = func_01ffc128(yaw, self->rot_y, 0x133, 1, 0x8000);
    self->rot_z = func_01ffc128(tilt, self->rot_z, 0x133, 1, 0x8000);
    self->unk_75c = self->pos;
    self->unk_76c = self->rot_x;
    self->unk_76e = self->rot_y;
    self->unk_770 = self->rot_z;
}
}
