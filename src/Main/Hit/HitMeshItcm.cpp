#include "types.h"

// Hit mesh block traversal, placed in ITCM

extern "C" {

typedef struct HitMeshItcmRes {
    /* 0x00 */ u8 unk_00[0x10];
    /* 0x10 */ s32 min[3];
    /* 0x1c */ s32 max[3];
    /* 0x28 */ u8 unk_28[8];
    /* 0x30 */ u32 blockCount;
    /* 0x34 */ u8 blocks[1];
} HitMeshItcmRes;

typedef struct HitMeshItcmVec {
    s32 x;
    s32 y;
    s32 z;
} HitMeshItcmVec;

typedef struct HitMeshItcmMtx {
    /* 0x00 */ s32 m[3][3];
    /* 0x24 */ HitMeshItcmVec trans;
} HitMeshItcmMtx;

typedef struct HitMeshItcmBlock {
    /* 0x00 */ s16 min[3];
    /* 0x06 */ s16 max[3];
    /* 0x0c */ u32 flags;
    /* 0x10 */ u8 unk_10[0x34];
    /* 0x44 */ HitMeshItcmMtx mtx;
    /* 0x74 */ u32 triCount;
    /* 0x78 */ u8 tris[1];
} HitMeshItcmBlock;

typedef struct HitMeshQuery {
    /* 0x00 */ void *mesh;
    /* 0x04 */ u8 unk_04[0x6c];
    /* 0x70 */ s32 min[3];
    /* 0x7c */ s32 max[3];
    /* 0x88 */ s32 unk_88;
    /* 0x8c */ s32 unk_8c;
    /* 0x90 */ s32 unk_90;
    /* 0x94 */ HitMeshItcmVec local;
    /* 0xa0 */ HitMeshItcmVec world;
} HitMeshQuery;

typedef struct HitMeshItcmOwner {
    /* 0x00 */ s32 unk_00;
    /* 0x04 */ s32 invScale;
    /* 0x08 */ u8 unk_08[0x30];
    /* 0x38 */ HitMeshItcmMtx invMtx;
    /* 0x68 */ u8 unk_68[0x1c];
    /* 0x84 */ u16 unk_84_0 : 1;
    /* 0x84 */ u16 unk_84_1 : 1;
    /* 0x84 */ u16 unk_84_2 : 14;
    /* 0x88 */ HitMeshItcmRes *res;
    /* 0x8c */ u8 unk_8c[4];
    /* 0x90 */ void **tables;
} HitMeshItcmOwner;

typedef struct HitMeshRay {
    /* 0x00 */ HitMeshItcmOwner *owner;
    /* 0x04 */ u8 unk_04[0x18];
    /* 0x1c */ s32 min[3];
    /* 0x28 */ s32 max[3];
    /* 0x34 */ u8 unk_34[0x18];
    /* 0x4c */ HitMeshItcmVec from;
    /* 0x58 */ HitMeshItcmVec to;
    /* 0x64 */ HitMeshItcmVec dir;
} HitMeshRay;

extern void func_01ff8330(HitMeshRay *ray);
extern void func_01ff8464(s32 *box, HitMeshItcmBlock *block);
extern void func_01ff868c(HitMeshRay *ray, void *table);
extern void VEC_Normalize(const HitMeshItcmVec *src, HitMeshItcmVec *dst);
extern HitMeshItcmRes *func_0203fc58(void *mesh);
extern BOOL func_0203fc60(void *mesh);
extern s32 func_0203f248(s32 a, s32 b);
extern void func_01ff8520(HitMeshQuery *q);
extern void func_01ff85ec(s32 *box, HitMeshItcmBlock *block);
extern void func_01ff9f9c(HitMeshQuery *q, HitMeshItcmBlock *block, void *tri);
extern void MTX_MultVec43(const HitMeshItcmVec *v, const HitMeshItcmMtx *m, HitMeshItcmVec *out);
extern void VEC_MultAdd(s32 a, const HitMeshItcmVec *v1, const HitMeshItcmVec *v2, HitMeshItcmVec *out);
extern void func_01ff9060(HitMeshQuery *q, void *table);

static inline s32 HitMeshItcm_FxMul(s32 a, s32 b) {
    return (s32)(((s64)a * b + 0x800) >> 12);
}

void func_01ffb83c(HitMeshRay *ray) {
    HitMeshItcmRes *res;
    void **table;
    HitMeshItcmBlock *block;
    u32 n;
    table = ray->owner->tables;
    res = ray->owner->res;
    func_01ff8330(ray);
    if (ray->owner->unk_84_1) {
        if (ray->min[0] > res->max[0]) {
            return;
        }
        if (ray->max[0] < res->min[0]) {
            return;
        }
        if (ray->min[1] > res->max[1]) {
            return;
        }
        if (ray->max[1] < res->min[1]) {
            return;
        }
        if (ray->min[2] > res->max[2]) {
            return;
        }
        if (ray->max[2] < res->min[2]) {
            return;
        }
    }
    n = res->blockCount;
    block = (HitMeshItcmBlock *)res->blocks;
    while (n != 0) {
        func_01ff8464(ray->min, block);
        if (ray->min[0] <= block->max[0] && ray->max[0] >= block->min[0] && ray->min[1] <= block->max[1] &&
            ray->max[1] >= block->min[1] && ray->min[2] <= block->max[2] && ray->max[2] >= block->min[2]) {
            ray->dir.x = ray->to.x - ray->from.x;
            ray->dir.y = ray->to.y - ray->from.y;
            ray->dir.z = ray->to.z - ray->from.z;
            VEC_Normalize(&ray->dir, &ray->dir);
            func_01ff868c(ray, *table);
        }
        n--;
        block = (HitMeshItcmBlock *)((u8 *)block + (block->triCount * 0x4c + 0x78));
        table++;
    }
}

void func_01ffb9b0(HitMeshQuery *q) {
    HitMeshItcmRes *res = func_0203fc58(q->mesh);
    HitMeshItcmBlock *block;
    u32 n;
    func_01ff8520(q);
    if (func_0203fc60(q->mesh)) {
        if (q->min[0] > res->max[0]) {
            return;
        }
        if (q->max[0] < res->min[0]) {
            return;
        }
        if (q->min[1] > res->max[1]) {
            return;
        }
        if (q->max[1] < res->min[1]) {
            return;
        }
        if (q->min[2] > res->max[2]) {
            return;
        }
        if (q->max[2] < res->min[2]) {
            return;
        }
    }
    n = res->blockCount;
    block = (HitMeshItcmBlock *)res->blocks;
    while (n != 0) {
        func_01ff85ec(q->min, block);
        if (q->min[0] <= block->max[0] && q->max[0] >= block->min[0] && q->min[1] <= block->max[1] &&
            q->max[1] >= block->min[1] && q->min[2] <= block->max[2] && q->max[2] >= block->min[2]) {
            u8 *tri;
            u32 cnt;
            q->unk_90 = func_0203f248(q->unk_8c, q->unk_8c);
            cnt = block->triCount;
            tri = block->tris;
            while (cnt != 0) {
                func_01ff9f9c(q, block, tri);
                cnt--;
                tri += 0x4c;
            }
        }
        n--;
        block = (HitMeshItcmBlock *)((u8 *)block + (block->triCount * 0x4c + 0x78));
    }
}

void func_01ffbb14(HitMeshQuery *q) {
    HitMeshItcmOwner *owner = (HitMeshItcmOwner *)q->mesh;
    HitMeshItcmRes *res;
    void **table;
    HitMeshItcmBlock *block;
    u32 n;
    s32 r;
    table = owner->tables;
    res = owner->res;
    MTX_MultVec43(&q->world, &owner->invMtx, &q->local);
    {
        s32 sc = owner->invScale;
        q->local.x = HitMeshItcm_FxMul(q->local.x, sc);
        q->local.y = HitMeshItcm_FxMul(q->local.y, sc);
        q->local.z = HitMeshItcm_FxMul(q->local.z, sc);
    }
    r = HitMeshItcm_FxMul(q->unk_8c, ((HitMeshItcmOwner *)q->mesh)->invScale);
    q->unk_88 = r;
    q->min[0] = q->local.x - r;
    q->max[0] = q->local.x + r;
    q->min[1] = q->local.y - r;
    q->max[1] = q->local.y + r;
    q->min[2] = q->local.z - r;
    q->max[2] = q->local.z + r;
    if (((HitMeshItcmOwner *)q->mesh)->unk_84_1) {
        if (q->min[0] > res->max[0]) {
            return;
        }
        if (q->max[0] < res->min[0]) {
            return;
        }
        if (q->min[1] > res->max[1]) {
            return;
        }
        if (q->max[1] < res->min[1]) {
            return;
        }
        if (q->min[2] > res->max[2]) {
            return;
        }
        if (q->max[2] < res->min[2]) {
            return;
        }
    }
    n = res->blockCount;
    block = (HitMeshItcmBlock *)res->blocks;
    while (n != 0) {
        if (block->flags & 2) {
            VEC_MultAdd(block->mtx.m[0][0], &q->local, &block->mtx.trans, &q->world);
        } else {
            MTX_MultVec43(&q->local, &block->mtx, &q->world);
        }
        r = HitMeshItcm_FxMul(q->unk_88, block->mtx.m[0][0]);
        q->unk_8c = r;
        q->min[0] = q->world.x - r;
        q->max[0] = q->world.x + r;
        q->min[1] = q->world.y - r;
        q->max[1] = q->world.y + r;
        q->min[2] = q->world.z - r;
        q->max[2] = q->world.z + r;
        if (q->min[0] <= block->max[0] && q->max[0] >= block->min[0] && q->min[1] <= block->max[1] &&
            q->max[1] >= block->min[1] && q->min[2] <= block->max[2] && q->max[2] >= block->min[2]) {
            q->unk_90 = HitMeshItcm_FxMul(r, r);
            func_01ff9060(q, *table);
        }
        n--;
        block = (HitMeshItcmBlock *)((u8 *)block + (block->triCount * 0x4c + 0x78));
        table++;
    }
}

}
