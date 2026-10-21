#ifndef MAIN_HIT_HITTRIITCM_H
#define MAIN_HIT_HITTRIITCM_H

#include "types.h"
#include "nitro/fx.h"

// Triangle hit mesh records and the ray test shared by the ITCM mesh walks

#ifdef __cplusplus
extern "C" {
#endif

typedef struct HitTri {
    /* 0x00 */ s16 min[3];
    /* 0x06 */ s16 max[3];
    /* 0x0c */ u32 attr;
    /* 0x10 */ fx32 d;
    /* 0x14 */ s16 v[3][3];
    /* 0x26 */ s16 n[3];
    /* 0x2c */ s16 e[3][3];
    /* 0x3e */ u8 unk_3e[2];
    /* 0x40 */ fx32 elen[3]; // length of each edge along its unit vector e[i]
} HitTri; // size 0x4c

typedef struct HitTriBlock {
    /* 0x00 */ s16 min[3];
    /* 0x06 */ s16 max[3];
    /* 0x0c */ u32 flags;
    /* 0x10 */ u32 unk_10;
    /* 0x14 */ MtxFx43 mtx;
    /* 0x44 */ MtxFx43 invMtx;
    /* 0x74 */ u32 triCount;
    /* 0x78 */ HitTri tris[1];
} HitTriBlock;

typedef struct HitTriRes {
    /* 0x00 */ u8 unk_00[0x10];
    /* 0x10 */ VecFx32 min;
    /* 0x1c */ VecFx32 max;
    /* 0x28 */ u8 unk_28[8];
    /* 0x30 */ u32 blockCount;
    /* 0x34 */ HitTriBlock blocks[1];
} HitTriRes;

typedef struct HitTriOwner {
    /* 0x00 */ fx32 scale;
    /* 0x04 */ fx32 invScale;
    /* 0x08 */ MtxFx43 mtx;
    /* 0x38 */ MtxFx43 invMtx;
    /* 0x68 */ u8 unk_68[0x1c];
    /* 0x84 */ u16 unk_84_0 : 1;
    /* 0x84 */ u16 unk_84_1 : 1;
    /* 0x84 */ u16 unk_84_2 : 14;
    /* 0x88 */ HitTriRes *res;
    /* 0x8c */ u8 unk_8c[4];
    /* 0x90 */ void **tables;
} HitTriOwner;

typedef struct HitTriRay {
    /* 0x00 */ HitTriOwner *owner;
    /* 0x04 */ VecFx32 origin;
    /* 0x10 */ VecFx32 end;
    /* 0x1c */ VecFx32 min;
    /* 0x28 */ VecFx32 max;
    /* 0x34 */ VecFx32 worldFrom;
    /* 0x40 */ VecFx32 worldTo;
    /* 0x4c */ VecFx32 from;
    /* 0x58 */ VecFx32 to;
    /* 0x64 */ VecFx32 dir;
    /* 0x70 */ u8 unk_70[0x3c];
    /* 0xac */ s32 mode1;
    /* 0xb0 */ s32 mode2;
    /* 0xb4 */ u32 mask1;
    /* 0xb8 */ u32 mask2;
    /* 0xbc */ fx32 best;
} HitTriRay;

typedef struct HitTriSphere {
    /* 0x00 */ HitTriOwner *owner;
    /* 0x04 */ u8 unk_04[0x6c];
    /* 0x70 */ VecFx32 min;
    /* 0x7c */ VecFx32 max;
    /* 0x88 */ fx32 localRadius;
    /* 0x8c */ fx32 radius;
    /* 0x90 */ fx32 radiusSq;
    /* 0x94 */ VecFx32 local;
    /* 0xa0 */ VecFx32 center;
    /* 0xac */ s32 mode1;
    /* 0xb0 */ s32 mode2;
    /* 0xb4 */ u32 mask1;
    /* 0xb8 */ u32 mask2;
    /* 0xbc */ fx32 best;
} HitTriSphere;

typedef struct HitTriInfo {
    /* 0x00 */ VecFx32 pos;
    /* 0x0c */ VecFx32 normal;
    /* 0x18 */ fx32 distSq;
    /* 0x1c */ s32 unk_1c;
    /* 0x20 */ HitTriOwner *owner;
    /* 0x24 */ HitTriBlock *block;
    /* 0x28 */ HitTri *tri;
    /* 0x2c */ u32 attr;
    /* 0x30 */ s32 n[3];
} HitTriInfo; // size 0x3c

typedef struct HitTriNode {
    /* 0x00 */ s16 min[2];
    /* 0x04 */ s16 max[2];
    /* 0x08 */ u32 unk_08;
    /* 0x0c */ u32 triCount;
    /* 0x10 */ HitTriBlock *block;
    /* 0x14 */ struct HitTriNode *child[4];
    /* 0x24 */ u32 isBranch;
    /* 0x28 */ HitTri *tris[1];
} HitTriNode;

extern s32 data_02fe0efc;
extern HitTriInfo *data_02fe0ef8;
extern HitTriInfo data_02fe0f50[];

extern void func_01ff8330(HitTriRay *ray);
extern void func_01ff8464(VecFx32 *box, HitTriBlock *block);

#define HIT_ATTR_CHECK(mode, mask, attr, fail, ok) \
    if ((mode) == 0) { \
        if ((mask) & (attr)) { \
            goto ok; \
        } \
        goto fail; \
    } else if ((mode) == 1) { \
        if (((mask) & (attr)) == (mask)) { \
            goto ok; \
        } \
        goto fail; \
    } else if ((mode) == 2) { \
        if (((mask) & (attr)) != (mask)) { \
            goto ok; \
        } \
        goto fail; \
    } else if ((mode) == 3) { \
        if (((mask) ^ (attr)) != 0) { \
            goto ok; \
        } \
        goto fail; \
    } \
    ok:

static inline void HitMulVec33(const VecFx32 *v, const MtxFx43 *m, VecFx32 *out) {
    fx32 x = v->x;
    fx32 y = v->y;
    fx32 z = v->z;
    out->x = (fx32)(((s64)x * m->_00 + (s64)y * m->_10 + (s64)z * m->_20) >> 12);
    out->y = (fx32)(((s64)x * m->_01 + (s64)y * m->_11 + (s64)z * m->_21) >> 12);
    out->z = (fx32)(((s64)x * m->_02 + (s64)y * m->_12 + (s64)z * m->_22) >> 12);
}

static inline void HitVecScale(const VecFx32 *v, fx32 s, VecFx32 *out) {
    out->x = FX_Mul(v->x, s);
    out->y = FX_Mul(v->y, s);
    out->z = FX_Mul(v->z, s);
}

static inline void HitVecSubS16(const VecFx32 *a, const s16 *b, VecFx32 *out) {
    out->x = a->x - b[0];
    out->y = a->y - b[1];
    out->z = a->z - b[2];
}

#define HIT_EDGE(i, fail) \
    { \
        fx32 cx, cy, cz; \
        HitVecSubS16(&p, tri->v[i], &e); \
        cx = (fx32)(((s64)tri->e[i][1] * e.z - (s64)tri->e[i][2] * e.y + 0x800) >> 12); \
        cy = (fx32)(((s64)tri->e[i][2] * e.x - (s64)tri->e[i][0] * e.z + 0x800) >> 12); \
        cz = (fx32)(((s64)tri->e[i][0] * e.y - (s64)tri->e[i][1] * e.x + 0x800) >> 12); \
        e.x = cx; \
        e.y = cy; \
        e.z = cz; \
        if ((fx32)(((s64)e.x * tri->n[0] + (s64)e.y * tri->n[1] + (s64)e.z * tri->n[2] + 0x800) >> 12) < -5) { \
            goto fail; \
        } \
    }

#ifdef __cplusplus
}
#endif

#endif
