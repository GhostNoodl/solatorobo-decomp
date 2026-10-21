#include "Main/Hit/HitTriItcm.h"

// Ray against every triangle of an unsorted hit mesh, placed in ITCM

extern "C" {

void func_01ffae08(HitTriRay *ray) {
    HitTriRes *res = ray->owner->res;
    HitTriBlock *block;
    HitTri *tri;
    HitTriInfo *info;
    u32 n;
    u32 cnt;
    MtxFx43 m;
    VecFx32 p;
    VecFx32 e;
    fx32 f;
    fx32 t;
    s32 i;

    func_01ff8330(ray);
    if (ray->owner->unk_84_1) {
        if (ray->min.x > res->max.x) {
            return;
        }
        if (ray->max.x < res->min.x) {
            return;
        }
        if (ray->min.y > res->max.y) {
            return;
        }
        if (ray->max.y < res->min.y) {
            return;
        }
        if (ray->min.z > res->max.z) {
            return;
        }
        if (ray->max.z < res->min.z) {
            return;
        }
    }
    n = res->blockCount;
    block = res->blocks;
    while (n != 0) {
        func_01ff8464(&ray->min, block);
        if (ray->min.x <= block->max[0] && ray->max.x >= block->min[0] && ray->min.y <= block->max[1] &&
            ray->max.y >= block->min[1] && ray->min.z <= block->max[2] && ray->max.z >= block->min[2]) {
            ray->dir.x = ray->to.x - ray->from.x;
            ray->dir.y = ray->to.y - ray->from.y;
            ray->dir.z = ray->to.z - ray->from.z;
            VEC_Normalize(&ray->dir, &ray->dir);
            cnt = block->triCount;
            tri = block->tris;
            while (cnt != 0) {
                if (ray->min.x > tri->max[0] || ray->max.x < tri->min[0] || ray->min.y > tri->max[1] ||
                    ray->max.y < tri->min[1] || ray->min.z > tri->max[2] || ray->max.z < tri->min[2]) {
                    goto next;
                }
                HIT_ATTR_CHECK(ray->mode1, ray->mask1, tri->attr, next, ok1)
                HIT_ATTR_CHECK(ray->mode2, ray->mask2, tri->attr, next, ok2)
                {
                    s64 ny = tri->n[1];
                    s64 nx = tri->n[0];
                    s64 nz = tri->n[2];
                    fx32 denom;
                    if (tri->d + (fx32)(((s64)ray->to.x * tri->n[0] + (s64)ray->to.y * tri->n[1] + (s64)ray->to.z * tri->n[2] + 0x800) >> 12) > 0) {
                        goto next;
                    }
                    f = tri->d + (fx32)(((s64)ray->from.x * nx + (s64)ray->from.y * ny + (s64)ray->from.z * nz + 0x800) >> 12);
                    if (f < 0) {
                        goto next;
                    }
                    denom = (fx32)(((s64)ray->dir.x * nx + (s64)ray->dir.y * ny + (s64)ray->dir.z * nz + 0x800) >> 12);
                    if (denom == 0) {
                        goto next;
                    }
                    t = FX_Div(-f, denom);
                }
                VEC_MultAdd(t, &ray->dir, &ray->from, &p);
                HIT_EDGE(0, next)
                HIT_EDGE(1, next)
                HIT_EDGE(2, next)
                if (data_02fe0efc >= 24) {
                    info = &data_02fe0f50[23];
                } else {
                    info = &data_02fe0f50[data_02fe0efc];
                }
                if (block->flags & 2) {
                    VEC_MultAdd(block->mtx._00, &p, (VecFx32 *)block->mtx.m[3], &p);
                } else {
                    MTX_MultVec43(&p, &block->mtx, &p);
                }
                {
                    HitTriOwner *owner = ray->owner;
                    HitVecScale(&p, owner->scale, &info->pos);
                    MTX_MultVec43(&info->pos, &owner->mtx, &info->pos);
                }
                e.x = ray->origin.x - info->pos.x;
                e.y = ray->origin.y - info->pos.y;
                e.z = ray->origin.z - info->pos.z;
                info->distSq = (fx32)(((s64)e.x * e.x + (s64)e.y * e.y + (s64)e.z * e.z + 0x800) >> 12);
                MI_Copy48B(&ray->owner->mtx, &m);
                if (block->flags & 2) {
                    fx32 s = block->mtx._00;
                    e.x = FX_Mul(tri->n[0], s);
                    e.y = FX_Mul(tri->n[1], s);
                    e.z = FX_Mul(tri->n[2], s);
                } else {
                    fx32 x = tri->n[0];
                    fx32 y = tri->n[1];
                    fx32 z = tri->n[2];
                    e.x = (fx32)(((s64)x * block->mtx._00 + (s64)y * block->mtx._10 + (s64)z * block->mtx._20) >> 12);
                    e.y = (fx32)(((s64)x * block->mtx._01 + (s64)y * block->mtx._11 + (s64)z * block->mtx._21) >> 12);
                    e.z = (fx32)(((s64)x * block->mtx._02 + (s64)y * block->mtx._12 + (s64)z * block->mtx._22) >> 12);
                }
                HitMulVec33(&e, &m, &e);
                VEC_Normalize(&e, &info->normal);
                info->owner = ray->owner;
                info->block = block;
                info->tri = tri;
                info->attr = tri->attr;
                info->n[0] = tri->n[0];
                info->n[1] = tri->n[1];
                info->n[2] = tri->n[2];
                if (info->distSq < ray->best) {
                    ray->best = info->distSq;
                    data_02fe0ef8 = info;
                }
                data_02fe0efc++;
            next:
                cnt--;
                tri++;
            }
        }
        n--;
        block = (HitTriBlock *)((u8 *)block + (block->triCount * 0x4c + 0x78));
    }
}

}
