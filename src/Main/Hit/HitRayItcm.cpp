#include "types.h"
#include "nitro/fx.h"

// Ray cast against the registered hit meshes, placed in ITCM

extern "C" {

typedef struct HitRayInfo {
    /* 0x00 */ VecFx32 pos;
    /* 0x0c */ VecFx32 normal;
    /* 0x18 */ s32 distSq;
    /* 0x1c */ s32 unk_1c;
    /* 0x20 */ s32 unk_20;
    /* 0x24 */ s32 unk_24[6];
} HitRayInfo; // size 0x3c

typedef struct HitRayMesh {
    /* 0x00 */ u8 unk_00[0x6c];
    /* 0x6c */ VecFx32 min;
    /* 0x78 */ VecFx32 max;
    /* 0x84 */ u16 unk_84_0 : 1;
    /* 0x84 */ u16 unk_84_1 : 1;
    /* 0x84 */ u16 unk_84_2 : 1;
    /* 0x84 */ u16 unk_84_3 : 13;
    /* 0x88 */ u8 unk_88[0xc];
    /* 0x94 */ struct HitRayMesh *next;
} HitRayMesh;

typedef struct HitRayQuery {
    /* 0x000 */ VecFx32 boxMin;
    /* 0x00c */ VecFx32 boxMax;
    /* 0x018 */ u8 unk_18[0x18];
    /* 0x030 */ VecFx32 from;
    /* 0x03c */ VecFx32 to;
    /* 0x048 */ u8 unk_48[0xc];
    /* 0x054 */ HitRayMesh *mesh;
    /* 0x058 */ VecFx32 from2;
    /* 0x064 */ VecFx32 to2;
    /* 0x070 */ u8 unk_70[0x90];
    /* 0x100 */ s32 arg3;
    /* 0x104 */ s32 arg5;
    /* 0x108 */ u32 mask;
    /* 0x10c */ s32 arg4;
    /* 0x110 */ s32 best;
} HitRayQuery; // size 0x114

typedef struct HitSphereQuery {
    /* 0x000 */ VecFx32 boxMin;
    /* 0x00c */ VecFx32 boxMax;
    /* 0x018 */ u8 unk_18[4];
    /* 0x01c */ s32 radius;
    /* 0x020 */ u8 unk_20[0x10];
    /* 0x030 */ VecFx32 center;
    /* 0x03c */ HitRayMesh *mesh;
    /* 0x040 */ u8 unk_40[0x88];
    /* 0x0c8 */ s32 radius2;
    /* 0x0cc */ u8 unk_cc[0x10];
    /* 0x0dc */ VecFx32 center2;
    /* 0x0e8 */ s32 arg3;
    /* 0x0ec */ s32 arg5;
    /* 0x0f0 */ u32 mask;
    /* 0x0f4 */ s32 arg4;
    /* 0x0f8 */ s32 best;
} HitSphereQuery; // size 0xfc

extern s32 data_02fe0efc;
extern HitRayInfo *data_02fe0ef8;
extern HitRayMesh *data_02fe0f08;
extern HitRayInfo data_02fe0f14;
extern void HitSegQuery_CalcBox(HitRayQuery *q);
extern BOOL HitAabb_Overlap(VecFx32 *aMin, VecFx32 *aMax, VecFx32 *bMin, VecFx32 *bMax);
extern void HitTriRay_TestTreeMesh(HitRayMesh **ray);
extern void HitTriRay_TestMesh(HitRayMesh **ray);
extern void HitTriSphere_TestTreeMesh(HitRayMesh **q);
extern void HitTriSphere_TestMesh(HitRayMesh **q);

s32 Hit_CastSegment(VecFx32 *from, VecFx32 *to, u32 mask, s32 a, s32 b, s32 c) {
    HitRayQuery q;
    HitRayMesh *mesh;
    HitRayInfo *hit;
    data_02fe0efc = 0;
    data_02fe0ef8 = NULL;
    q.from2 = *from;
    q.to2 = *to;
    mesh = data_02fe0f08;
    q.mask = mask;
    q.arg4 = b;
    q.arg3 = a;
    q.arg5 = c;
    q.best = 0x7fffffff;
    q.from = q.from2;
    q.to = q.to2;
    HitSegQuery_CalcBox(&q);
    for (; mesh != NULL; mesh = mesh->next) {
        if (mesh->unk_84_1 ? TRUE : FALSE) {
            if (!HitAabb_Overlap(&q.boxMin, &q.boxMax, &mesh->min, &mesh->max)) {
                continue;
            }
        }
        q.mesh = mesh;
        if (mesh->unk_84_2 ? TRUE : FALSE) {
            HitTriRay_TestTreeMesh(&q.mesh);
        } else {
            HitTriRay_TestMesh(&q.mesh);
        }
    }
    hit = data_02fe0ef8;
    if (hit == NULL) {
        return -0x1000;
    }
    data_02fe0f14 = *hit;
    *to = data_02fe0f14.pos;
    return FX_Sqrt(data_02fe0f14.distSq);
}

s32 Hit_CastSphere(VecFx32 *pos, s32 radius, u32 mask, s32 a, s32 b, s32 c) {
    HitSphereQuery q;
    HitRayMesh *mesh;
    HitRayInfo *hit;
    data_02fe0efc = 0;
    data_02fe0ef8 = NULL;
    mesh = data_02fe0f08;
    q.mask = mask;
    q.arg4 = b;
    q.arg3 = a;
    q.arg5 = c;
    q.best = 0x7fffffff;
    q.center = *pos;
    q.radius = radius;
    q.boxMin.x = q.center.x - radius;
    q.boxMax.x = q.center.x + radius;
    q.boxMin.y = q.center.y - radius;
    q.boxMax.y = q.center.y + radius;
    q.boxMin.z = q.center.z - radius;
    q.boxMax.z = q.center.z + radius;
    for (; mesh != NULL; mesh = mesh->next) {
        if (mesh->unk_84_1 ? TRUE : FALSE) {
            if (!HitAabb_Overlap(&q.boxMin, &q.boxMax, &mesh->min, &mesh->max)) {
                continue;
            }
        }
        q.mesh = mesh;
        q.center2 = *pos;
        q.radius2 = radius;
        if (mesh->unk_84_2 ? TRUE : FALSE) {
            HitTriSphere_TestTreeMesh(&q.mesh);
        } else {
            HitTriSphere_TestMesh(&q.mesh);
        }
    }
    hit = data_02fe0ef8;
    if (hit == NULL) {
        return -0x1000;
    }
    data_02fe0f14 = *hit;
    *pos = data_02fe0f14.pos;
    return data_02fe0f14.distSq;
}

}
