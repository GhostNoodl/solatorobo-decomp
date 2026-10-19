#include "ov002/ov002.h"

extern "C" {

void VEC_Normalize(Vec3 *src, Vec3 *dst);
void VEC_Add(Vec3 *a, Vec3 *b, Vec3 *ab);
void MTX_RotAxis33(void *m, Vec3 *axis, s32 s, s32 c);
void MTX_PerspectiveW(s32 s, s32 c, s32 aspect, s32 n, s32 f, s32 scale, void *mtx);

typedef struct Mtx33_021e7390 {
    s32 m[3][3];
} Mtx33_021e7390;

static inline void ov002_Cross(const Vec3 *a, const Vec3 *b, Vec3 *axb) {
    s32 x = (s32)(((s64)a->y * b->z - (s64)a->z * b->y + 0x800) >> 12);
    s32 y = (s32)(((s64)a->z * b->x - (s64)a->x * b->z + 0x800) >> 12);
    s32 z = (s32)(((s64)a->x * b->y - (s64)a->y * b->x + 0x800) >> 12);
    axb->x = x;
    axb->y = y;
    axb->z = z;
}

void func_ov002_021e7390(void *self) {
    void *obj = FIELD(self, 0x48, void *);
    if (obj != NULL && FIELD(obj, 0x4, s32) == 7) {
        Vec3 pos;
        Vec3 at;
        Vec3 dir;
        Vec3 axis;
        Mtx33_021e7390 m;
        Vec3 up;
        u16 ang;
        pos = FIELD(obj, 0x50, Vec3);
        at = FIELD(obj, 0x5c, Vec3);
        up = FIELD(obj, 0x68, Vec3);
        ang = FIELD(obj, 0xb8, u16) + 0x3e9;
        dir.x = at.x - pos.x;
        dir.y = at.y - pos.y;
        dir.z = at.z - pos.z;
        ov002_Cross(&dir, &up, &axis);
        VEC_Normalize(&axis, &axis);
        MTX_RotAxis33(&m, &axis, FX_SINCOS((ang >> 4) * 2), FX_SINCOS((ang >> 4) * 2 + 1));
        MTX_MultVec33(&dir, &m, &dir);
        VEC_Add(&dir, &pos, &at);
        FIELD(self, 0x5c, Vec3) = at;
        FIELD(self, 0x50, Vec3) = pos;
        FIELD(self, 0x68, Vec3) = up;
    }
    NNS_G3dGlb.v240 = FIELD(self, 0x50, Vec3);
    NNS_G3dGlb.v24c = FIELD(self, 0x68, Vec3);
    NNS_G3dGlb.v258 = FIELD(self, 0x5c, Vec3);
    MTX_LookAt((u8 *)self + 0x50, (u8 *)self + 0x68, (u8 *)self + 0x5c, data_02092844);
    NNS_G3dGlb.fc &= ~0xe8;
    MTX_PerspectiveW(FIELD(self, 0xba, s16), FIELD(self, 0xbc, s16), FIELD(self, 0xbe, s16), FIELD(self, 0xc0, s32),
                     FIELD(self, 0xc4, s32), 0x1000, (u8 *)self + 0x74);
    MIi_CpuCopyFast((u8 *)self + 0x74, data_02092800, 0x40);
    NNS_G3dGlb.fc &= ~0x50;
}

}
