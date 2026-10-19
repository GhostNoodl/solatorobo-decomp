#include "Main/Math/MathItcm.h"

// World-space bounding box update, placed in ITCM

extern "C" {

typedef struct HitBoxOwner {
    /* 0x00 */ u8 unk_00[4];
    /* 0x04 */ fx32 scale;
    /* 0x08 */ u8 unk_08[0x30];
    /* 0x38 */ MtxFx43 mtx;
} HitBoxOwner;

typedef struct HitBox {
    /* 0x00 */ HitBoxOwner *owner;
    /* 0x04 */ VecFx32 localA;
    /* 0x10 */ VecFx32 localB;
    /* 0x1c */ VecFx32 min;
    /* 0x28 */ VecFx32 max;
    /* 0x34 */ VecFx32 worldA;
    /* 0x40 */ VecFx32 worldB;
} HitBox;

static inline void HitBox_ScaleVec(VecFx32 *v, fx32 s) {
    fx32 x, y, z;
    z = FX_Mul(v->z, s);
    x = FX_Mul(v->x, s);
    y = FX_Mul(v->y, s);
    v->z = z;
    v->y = y;
    v->x = x;
}

typedef struct HitAabb {
    /* 0x00 */ VecFx32 min;
    /* 0x0c */ VecFx32 max;
} HitAabb;

typedef struct HitSegQuery {
    /* 0x00 */ HitAabb box;
    /* 0x18 */ u8 unk_18[0x18];
    /* 0x30 */ VecFx32 from;
    /* 0x3c */ VecFx32 to;
} HitSegQuery;

static inline void HitAabb_FromSeg(HitAabb *box, VecFx32 *a, VecFx32 *b) {
    if (b->x > a->x) {
        box->min.x = a->x;
        box->max.x = b->x;
    } else {
        box->min.x = b->x;
        box->max.x = a->x;
    }
    if (b->y > a->y) {
        box->min.y = a->y;
        box->max.y = b->y;
    } else {
        box->min.y = b->y;
        box->max.y = a->y;
    }
    if (b->z > a->z) {
        box->min.z = a->z;
        box->max.z = b->z;
    } else {
        box->min.z = b->z;
        box->max.z = a->z;
    }
}

void func_01ff82d8(HitSegQuery *q) {
    HitAabb_FromSeg(&q->box, &q->from, &q->to);
}

void func_01ff8330(HitBox *box) {
    HitBoxOwner *owner = box->owner;
    MTX_MultVec43(&box->localA, &owner->mtx, &box->worldA);
    HitBox_ScaleVec(&box->worldA, owner->scale);
    owner = box->owner;
    MTX_MultVec43(&box->localB, &owner->mtx, &box->worldB);
    HitBox_ScaleVec(&box->worldB, owner->scale);
    if (box->worldB.x > box->worldA.x) {
        box->max.x = box->worldB.x;
        box->min.x = box->worldA.x;
    } else {
        box->max.x = box->worldA.x;
        box->min.x = box->worldB.x;
    }
    if (box->worldB.y > box->worldA.y) {
        box->min.y = box->worldA.y;
        box->max.y = box->worldB.y;
    } else {
        box->max.y = box->worldA.y;
        box->min.y = box->worldB.y;
    }
    if (box->worldB.z > box->worldA.z) {
        box->min.z = box->worldA.z;
        box->max.z = box->worldB.z;
    } else {
        box->min.z = box->worldB.z;
        box->max.z = box->worldA.z;
    }
}

typedef struct HitMeshBlockXf {
    /* 0x00 */ s16 min[3];
    /* 0x06 */ s16 max[3];
    /* 0x0c */ u32 flags; // bit1: uniform scale + translation only
    /* 0x10 */ u8 unk_10[0x34];
    /* 0x44 */ MtxFx43 mtx;
} HitMeshBlockXf;

typedef struct HitSegLocal {
    /* 0x00 */ HitAabb box;
    /* 0x18 */ VecFx32 from;
    /* 0x24 */ VecFx32 to;
    /* 0x30 */ VecFx32 localFrom;
    /* 0x3c */ VecFx32 localTo;
} HitSegLocal;

static inline void HitMeshBlockXf_Apply(HitMeshBlockXf *block, VecFx32 *src, VecFx32 *dst) {
    if (block->flags & 2) {
        VEC_MultAdd(block->mtx._00, src, (VecFx32 *)block->mtx.m[3], dst);
    } else {
        MTX_MultVec43(src, &block->mtx, dst);
    }
}

void func_01ff8464(HitSegLocal *seg, HitMeshBlockXf *block) {
    if (block->flags & 2) {
        VEC_MultAdd(block->mtx._00, &seg->from, (VecFx32 *)block->mtx.m[3], &seg->localFrom);
        VEC_MultAdd(block->mtx._00, &seg->to, (VecFx32 *)block->mtx.m[3], &seg->localTo);
    } else {
        MTX_MultVec43(&seg->from, &block->mtx, &seg->localFrom);
        MTX_MultVec43(&seg->to, &block->mtx, &seg->localTo);
    }
    HitAabb_FromSeg(&seg->box, &seg->localFrom, &seg->localTo);
}

typedef struct HitSphereOwner {
    /* 0x00 */ s32 unk_00;
    /* 0x04 */ fx32 invScale;
    /* 0x08 */ u8 unk_08[0x30];
    /* 0x38 */ MtxFx43 invMtx;
} HitSphereOwner;

typedef struct HitSphereMeshQuery {
    /* 0x00 */ HitSphereOwner *owner;
    /* 0x04 */ u8 unk_04[0x6c];
    /* 0x70 */ HitAabb box;
    /* 0x88 */ fx32 localRadius;
    /* 0x8c */ fx32 radius;
    /* 0x90 */ s32 unk_90;
    /* 0x94 */ VecFx32 local;
    /* 0xa0 */ VecFx32 world;
} HitSphereMeshQuery;

static inline void HitAabb_FromSphere(HitAabb *box, VecFx32 *c, fx32 r) {
    box->min.x = c->x - r;
    box->max.x = c->x + r;
    box->min.y = c->y - r;
    box->max.y = c->y + r;
    box->min.z = c->z - r;
    box->max.z = c->z + r;
}

static inline void HitVec_Scale(VecFx32 *v, fx32 s) {
    v->x = FX_Mul(v->x, s);
    v->y = FX_Mul(v->y, s);
    v->z = FX_Mul(v->z, s);
}

void func_01ff8520(HitSphereMeshQuery *q) {
    HitSphereOwner *owner = q->owner;
    fx32 r;
    MTX_MultVec43(&q->world, &owner->invMtx, &q->local);
    HitVec_Scale(&q->local, owner->invScale);
    r = FX_Mul(q->radius, q->owner->invScale);
    q->localRadius = r;
    HitAabb_FromSphere(&q->box, &q->local, r);
}

typedef struct HitSphereLocal {
    /* 0x00 */ HitAabb box;
    /* 0x18 */ fx32 radius;
    /* 0x1c */ fx32 localRadius;
    /* 0x20 */ u8 unk_20[4];
    /* 0x24 */ VecFx32 center;
    /* 0x30 */ VecFx32 localCenter;
} HitSphereLocal;

void func_01ff85ec(HitSphereLocal *sp, HitMeshBlockXf *block) {
    fx32 r;
    HitMeshBlockXf_Apply(block, &sp->center, &sp->localCenter);
    r = FX_Mul(sp->radius, block->mtx._00);
    sp->localRadius = r;
    HitAabb_FromSphere(&sp->box, &sp->localCenter, r);
}

}
