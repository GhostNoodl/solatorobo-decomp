#include "ov000/LoCommon.h"
#include "ov000/Vec.h"

typedef struct {
    u16 b0 : 10;
    u16 b10 : 1;
    u16 rest : 5;
} Bits0214a424_021b0db0;

extern "C" {
extern u8 *data_ov000_021ccd54;
extern void *data_02097dc8;
extern u8 *data_0214a424;
extern const VecFx32 data_02092a50;
extern u8 data_ov000_021cc5e3[];
extern u8 data_ov000_021cc751[];
extern u8 data_ov000_021cc757[];
extern u8 data_ov000_021cc75d[];
extern u8 data_ov000_021cc763[];
u16 func_0204bfa8(void *cam);
u16 func_0203d434(void *rng, s32 range);
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
    return LFLD(Bits0214a424_021b0db0, data_0214a424, 0x18).b10 ? TRUE : FALSE;
}

void func_ov000_021b0db0(VObj *self, s32 spd) {
    u16 yaw;
    u16 tilt;
    u8 *cam = data_ov000_021ccd54 + 0xf4;
    if (LFLD(u16, cam, 0x40) != 0) {
        yaw = LFLD(u16, cam, 0x44);
    } else {
        yaw = func_0204bfa8(cam);
    }
    tilt = 0;
    if (spd > 0) {
        u16 ang = func_0203d434(data_02097dc8, 0) + 0x8000;
        s32 idx = ang >> 4;
        s32 z;
        u16 keys;
        u8 *anim;
        LFLD(s32, self, 0xaf0) += (s32)(((s64)spd * FX_SinCosTable_[idx * 2] + 0x800) >> 12);
        if (LFLD(s32, self, 0xaf0) > 0x6000) {
            LFLD(s32, self, 0xaf0) = 0x6000;
        } else if (LFLD(s32, self, 0xaf0) < -0x6000) {
            LFLD(s32, self, 0xaf0) = -0x6000;
        }
        z = (s32)(((s64)spd * FX_SinCosTable_[idx * 2 + 1] + 0x800) >> 12);
        if (LFLD(Bits0214a424_021b0db0, data_0214a424, 0x18).b10) {
            z = -z;
        }
        LFLD(s32, self, 0xaf4) += z;
        if (LFLD(s32, self, 0xaf4) > 0x1a66) {
            LFLD(s32, self, 0xaf4) = 0x1a66;
        } else if (LFLD(s32, self, 0xaf4) < -0x6800) {
            LFLD(s32, self, 0xaf4) = -0x6800;
        }
        LFLD(s32, self, 0xaf8) = 0;
        keys = LFLD(u16, self, 0xb68);
        anim = data_ov000_021cc5e3;
        if (keys & 0x20) {
            tilt = 0xf800;
            anim = data_ov000_021cc751;
        } else if (keys & 0x10) {
            tilt = 0x800;
            anim = data_ov000_021cc757;
        } else if (((keys & 0x40) && !Flip021b0db0()) || ((keys & 0x80) && LFLD(Bits0214a424_021b0db0, data_0214a424, 0x18).b10)) {
            anim = data_ov000_021cc75d;
        } else if (((keys & 0x80) && !Flip021b0db0()) || ((keys & 0x40) && LFLD(Bits0214a424_021b0db0, data_0214a424, 0x18).b10)) {
            anim = data_ov000_021cc763;
        }
        func_ov000_02190cb0(LFLD(void *, self, 0x38), anim, 0xcd, 0);
    } else if (spd == 0) {
        func_ov000_02190cb0(LFLD(void *, self, 0x38), data_ov000_021cc5e3, 0xcd, tilt);
        func_ov000_021915a0(LFLD(void *, self, 0x38));
    }
    MulVec33_021b0db0((VecFx32 *)((u8 *)self + 0xaf0), NNS_G3dGlbGetInvV(), (VecFx32 *)((u8 *)self + 0x9c));
    VEC_Add((VecFx32 *)((u8 *)self + 0x9c), &data_02092a50, (VecFx32 *)((u8 *)self + 0x70));
    LFLD(u16, self, 0x7e) = func_01ffc128(yaw, LFLD(u16, self, 0x7e), 0x133, 1, 0x8000);
    LFLD(u16, self, 0x80) = func_01ffc128(tilt, LFLD(u16, self, 0x80), 0x133, 1, 0x8000);
    LFLD(VecFx32, self, 0x75c) = LFLD(VecFx32, self, 0x70);
    LFLD(u16, self, 0x76c) = LFLD(u16, self, 0x7c);
    LFLD(u16, self, 0x76e) = LFLD(u16, self, 0x7e);
    LFLD(u16, self, 0x770) = LFLD(u16, self, 0x80);
}
}
