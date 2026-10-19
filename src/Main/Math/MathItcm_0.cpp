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

}
