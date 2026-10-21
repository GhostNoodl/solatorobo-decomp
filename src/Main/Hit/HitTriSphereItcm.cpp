#include "Main/Hit/HitTriItcm.h"
#include "Main/Math/MathItcm.h"

// Sphere against the triangles of a hit mesh, placed in ITCM: the quadtree walk and the single-triangle test

extern "C" {

// Edge test of the sphere centre projected onto the plane (p); cx/cy/cz are function-scope locals
#define SPH_EDGE(i, fail) \
    { \
        fx32 ex = p.x - tri->v[i][0]; \
        fx32 ey = p.y - tri->v[i][1]; \
        fx32 ez = p.z - tri->v[i][2]; \
        cx = (fx32)(((s64)tri->e[i][1] * ez - (s64)tri->e[i][2] * ey + 0x800) >> 12); \
        cy = (fx32)(((s64)tri->e[i][2] * ex - (s64)tri->e[i][0] * ez + 0x800) >> 12); \
        cz = (fx32)(((s64)tri->e[i][0] * ey - (s64)tri->e[i][1] * ex + 0x800) >> 12); \
        if ((fx32)(((s64)cx * tri->n[0] + (s64)cy * tri->n[1] + (s64)cz * tri->n[2] + 0x800) >> 12) < -5) { \
            goto fail; \
        } \
    }

void func_01ff9060(HitTriSphere *q, HitTriNode *root) {
    HitTriBlock *block;
    HitTri *tri;
    HitTri **tris;
    u32 cnt;
    s32 top;
    HitTriInfo *info;
    MtxFx43 m;
    VecFx32 e;
    VecFx32 p;
    fx32 dist;
    s32 found;
    fx32 cx, cy, cz;

    HitTriNode *stack[256];

    top = 0;
    stack[top++] = root;
    do {
        root = stack[--top];
        if (q->min.x > root->max[0] || q->max.x < root->min[0] || q->min.z > root->max[1] ||
            q->max.z < root->min[1]) {
            continue;
        }
        if (root->isBranch) {
            if (root->child[3] != NULL) {
                stack[top++] = root->child[3];
            }
            if (root->child[2] != NULL) {
                stack[top++] = root->child[2];
            }
            if (root->child[1] != NULL) {
                stack[top++] = root->child[1];
            }
            if (root->child[0] != NULL) {
                stack[top++] = root->child[0];
            }
            continue;
        }
        cnt = root->triCount;
        block = root->block;
        tris = root->tris;
        while (cnt != 0) {
            tri = *tris;
            if (q->min.x > tri->max[0] || q->max.x < tri->min[0] || q->min.y > tri->max[1] ||
                q->max.y < tri->min[1] || q->min.z > tri->max[2] || q->max.z < tri->min[2]) {
                goto next;
            }
            HIT_ATTR_CHECK(q->mode1, q->mask1, tri->attr, next, ok1)
            HIT_ATTR_CHECK(q->mode2, q->mask2, tri->attr, next, ok2)
            {
                dist = tri->d + (fx32)(((s64)q->center.x * tri->n[0] + (s64)q->center.y * tri->n[1] + (s64)q->center.z * tri->n[2] + 0x800) >> 12);
                if (dist < 0) {
                    goto next;
                }
                if (dist > q->radius) {
                    goto next;
                }
                p.x = q->center.x + (fx32)(((s64)-dist * tri->n[0]) >> 12);
                p.y = q->center.y + (fx32)(((s64)-dist * tri->n[1]) >> 12);
                p.z = q->center.z + (fx32)(((s64)-dist * tri->n[2]) >> 12);
                SPH_EDGE(0, edges)
                SPH_EDGE(1, edges)
                SPH_EDGE(2, edges)
                goto found;
            }
        edges:
            found = 0;
            {
                fx32 d = VEC_Fx16DotProduct((VecFx16 *)tri->v[0], (VecFx16 *)tri->e[0]);
                fx32 t = (fx32)(((s64)q->center.x * tri->e[0][0] + (s64)q->center.y * tri->e[0][1] + (s64)q->center.z * tri->e[0][2] + 0x800) >> 12) - d;
                if (t >= 0 && t <= tri->elen[0]) {
                    p.x = tri->v[0][0] + (fx32)(((s64)t * tri->e[0][0]) >> 12);
                    p.y = tri->v[0][1] + (fx32)(((s64)t * tri->e[0][1]) >> 12);
                    p.z = tri->v[0][2] + (fx32)(((s64)t * tri->e[0][2]) >> 12);
                    e.x = p.x - q->center.x;
                    e.y = p.y - q->center.y;
                    e.z = p.z - q->center.z;
                    if (HitMagSq(&e) <= q->radiusSq) {
                        dist = FX_Sqrt(HitMagSq(&e));
                        found = 1;
                    }
                }
            }
            {
                fx32 d = VEC_Fx16DotProduct((VecFx16 *)tri->v[1], (VecFx16 *)tri->e[1]);
                fx32 t = (fx32)(((s64)q->center.x * tri->e[1][0] + (s64)q->center.y * tri->e[1][1] + (s64)q->center.z * tri->e[1][2] + 0x800) >> 12) - d;
                if (t >= 0 && t <= tri->elen[1]) {
                    VecFx32 c;
                    c.x = tri->v[1][0] + (fx32)(((s64)t * tri->e[1][0]) >> 12);
                    c.y = tri->v[1][1] + (fx32)(((s64)t * tri->e[1][1]) >> 12);
                    c.z = tri->v[1][2] + (fx32)(((s64)t * tri->e[1][2]) >> 12);
                    e.x = c.x - q->center.x;
                    e.y = c.y - q->center.y;
                    e.z = c.z - q->center.z;
                    if (HitMagSq(&e) <= q->radiusSq) {
                        fx32 s = FX_Sqrt(HitMagSq(&e));
                        if (found == 0 || s <= dist) {
                            dist = s;
                            p = c;
                            found = 2;
                        }
                    }
                }
            }
            {
                fx32 d = VEC_Fx16DotProduct((VecFx16 *)tri->v[2], (VecFx16 *)tri->e[2]);
                fx32 t = (fx32)(((s64)q->center.x * tri->e[2][0] + (s64)q->center.y * tri->e[2][1] + (s64)q->center.z * tri->e[2][2] + 0x800) >> 12) - d;
                if (t >= 0 && t <= tri->elen[2]) {
                    VecFx32 c;
                    c.x = tri->v[2][0] + (fx32)(((s64)t * tri->e[2][0]) >> 12);
                    c.y = tri->v[2][1] + (fx32)(((s64)t * tri->e[2][1]) >> 12);
                    c.z = tri->v[2][2] + (fx32)(((s64)t * tri->e[2][2]) >> 12);
                    e.x = c.x - q->center.x;
                    e.y = c.y - q->center.y;
                    e.z = c.z - q->center.z;
                    if (HitMagSq(&e) <= q->radiusSq) {
                        fx32 s = FX_Sqrt(HitMagSq(&e));
                        if (found == 0 || s <= dist) {
                            dist = s;
                            p = c;
                        }
                        goto found;
                    }
                }
            }
            if (found == 0) {
                e.x = q->center.x - tri->v[0][0];
                e.y = q->center.y - tri->v[0][1];
                e.z = q->center.z - tri->v[0][2];
                if (HitMagSq(&e) <= q->radiusSq) {
                    dist = FX_Sqrt(HitMagSq(&e));
                    found = 1;
                    p.x = tri->v[0][0];
                    p.y = tri->v[0][1];
                    p.z = tri->v[0][2];
                }
                e.x = q->center.x - tri->v[1][0];
                e.y = q->center.y - tri->v[1][1];
                e.z = q->center.z - tri->v[1][2];
                if (HitMagSq(&e) <= q->radiusSq) {
                    fx32 s = FX_Sqrt(HitMagSq(&e));
                    if (found == 0 || s <= dist) {
                        dist = s;
                        found = 2;
                        p.x = tri->v[1][0];
                        p.y = tri->v[1][1];
                        p.z = tri->v[1][2];
                    }
                }
                e.x = q->center.x - tri->v[2][0];
                e.y = q->center.y - tri->v[2][1];
                e.z = q->center.z - tri->v[2][2];
                if (HitMagSq(&e) > q->radiusSq) {
                    goto next;
                }
                {
                    fx32 s = FX_Sqrt(HitMagSq(&e));
                    if (found == 0 || s <= dist) {
                        dist = s;
                        p.x = tri->v[2][0];
                        p.y = tri->v[2][1];
                        p.z = tri->v[2][2];
                    }
                }
            }
        found:
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
                HitTriOwner *owner = q->owner;
                fx32 s = owner->scale;
                HitVecScale(&p, s, &info->pos);
                MTX_MultVec43(&info->pos, &owner->mtx, &info->pos);
            }
            info->distSq = FX_Mul(FX_Mul(dist, block->mtx._00), q->owner->scale);
            MI_Copy48B(&q->owner->mtx, &m);
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
            info->owner = q->owner;
            info->block = block;
            info->tri = tri;
            info->attr = tri->attr;
            info->n[0] = tri->n[0];
            info->n[1] = tri->n[1];
            info->n[2] = tri->n[2];
            if (info->distSq < q->best) {
                q->best = info->distSq;
                data_02fe0ef8 = info;
            }
            data_02fe0efc++;
        next:
            cnt--;
            tris++;
        }
    } while (top != 0);
}

void func_01ff9f9c(HitTriSphere *q, HitTriBlock *block, HitTri *tri) {
    HitTriInfo *info;
    VecFx32 p;
    VecFx32 e;
    MtxFx43 m;
    fx32 dist;
    s32 found;
    fx32 cx, cy, cz;

    if (q->min.x > tri->max[0] || q->max.x < tri->min[0] || q->min.y > tri->max[1] ||
        q->max.y < tri->min[1] || q->min.z > tri->max[2] || q->max.z < tri->min[2]) {
        return;
    }
    HIT_ATTR_CHECK(q->mode1, q->mask1, tri->attr, fail, ok1)
    HIT_ATTR_CHECK(q->mode2, q->mask2, tri->attr, fail, ok2)
    {
        dist = tri->d + (fx32)(((s64)q->center.x * tri->n[0] + (s64)q->center.y * tri->n[1] + (s64)q->center.z * tri->n[2] + 0x800) >> 12);
        if (dist < 0) {
            return;
        }
        if (dist > q->radius) {
            return;
        }
        p.x = q->center.x + (fx32)(((s64)-dist * tri->n[0]) >> 12);
        p.y = q->center.y + (fx32)(((s64)-dist * tri->n[1]) >> 12);
        p.z = q->center.z + (fx32)(((s64)-dist * tri->n[2]) >> 12);
        SPH_EDGE(0, edges)
        SPH_EDGE(1, edges)
        SPH_EDGE(2, edges)
        goto found;
    }
edges:
    found = 0;
    {
        fx32 d = VEC_Fx16DotProduct((VecFx16 *)tri->v[0], (VecFx16 *)tri->e[0]);
        fx32 t = (fx32)(((s64)q->center.x * tri->e[0][0] + (s64)q->center.y * tri->e[0][1] + (s64)q->center.z * tri->e[0][2] + 0x800) >> 12) - d;
        if (t >= 0 && t <= tri->elen[0]) {
            p.x = tri->v[0][0] + (fx32)(((s64)t * tri->e[0][0]) >> 12);
            p.y = tri->v[0][1] + (fx32)(((s64)t * tri->e[0][1]) >> 12);
            p.z = tri->v[0][2] + (fx32)(((s64)t * tri->e[0][2]) >> 12);
            e.x = p.x - q->center.x;
            e.y = p.y - q->center.y;
            e.z = p.z - q->center.z;
            if (HitMagSq(&e) <= q->radiusSq) {
                dist = FX_Sqrt(HitMagSq(&e));
                found = 1;
            }
        }
    }
    {
        fx32 d = VEC_Fx16DotProduct((VecFx16 *)tri->v[1], (VecFx16 *)tri->e[1]);
        fx32 t = (fx32)(((s64)q->center.x * tri->e[1][0] + (s64)q->center.y * tri->e[1][1] + (s64)q->center.z * tri->e[1][2] + 0x800) >> 12) - d;
        if (t >= 0 && t <= tri->elen[1]) {
            VecFx32 c;
            c.x = tri->v[1][0] + (fx32)(((s64)t * tri->e[1][0]) >> 12);
            c.y = tri->v[1][1] + (fx32)(((s64)t * tri->e[1][1]) >> 12);
            c.z = tri->v[1][2] + (fx32)(((s64)t * tri->e[1][2]) >> 12);
            e.x = c.x - q->center.x;
            e.y = c.y - q->center.y;
            e.z = c.z - q->center.z;
            if (HitMagSq(&e) <= q->radiusSq) {
                fx32 s = FX_Sqrt(HitMagSq(&e));
                if (found == 0 || s <= dist) {
                    dist = s;
                    p = c;
                    found = 2;
                }
            }
        }
    }
    {
        fx32 d = VEC_Fx16DotProduct((VecFx16 *)tri->v[2], (VecFx16 *)tri->e[2]);
        fx32 t = (fx32)(((s64)q->center.x * tri->e[2][0] + (s64)q->center.y * tri->e[2][1] + (s64)q->center.z * tri->e[2][2] + 0x800) >> 12) - d;
        if (t >= 0 && t <= tri->elen[2]) {
            VecFx32 c;
            c.x = tri->v[2][0] + (fx32)(((s64)t * tri->e[2][0]) >> 12);
            c.y = tri->v[2][1] + (fx32)(((s64)t * tri->e[2][1]) >> 12);
            c.z = tri->v[2][2] + (fx32)(((s64)t * tri->e[2][2]) >> 12);
            e.x = c.x - q->center.x;
            e.y = c.y - q->center.y;
            e.z = c.z - q->center.z;
            if (HitMagSq(&e) <= q->radiusSq) {
                fx32 s = FX_Sqrt(HitMagSq(&e));
                if (found == 0 || s <= dist) {
                    dist = s;
                    p = c;
                }
                goto found;
            }
        }
    }
    if (found == 0) {
        e.x = q->center.x - tri->v[0][0];
        e.y = q->center.y - tri->v[0][1];
        e.z = q->center.z - tri->v[0][2];
        if (HitMagSq(&e) <= q->radiusSq) {
            dist = FX_Sqrt(HitMagSq(&e));
            found = 1;
            p.x = tri->v[0][0];
            p.y = tri->v[0][1];
            p.z = tri->v[0][2];
        }
        e.x = q->center.x - tri->v[1][0];
        e.y = q->center.y - tri->v[1][1];
        e.z = q->center.z - tri->v[1][2];
        if (HitMagSq(&e) <= q->radiusSq) {
            fx32 s = FX_Sqrt(HitMagSq(&e));
            if (found == 0 || s <= dist) {
                dist = s;
                found = 2;
                p.x = tri->v[1][0];
                p.y = tri->v[1][1];
                p.z = tri->v[1][2];
            }
        }
        e.x = q->center.x - tri->v[2][0];
        e.y = q->center.y - tri->v[2][1];
        e.z = q->center.z - tri->v[2][2];
        if (HitMagSq(&e) > q->radiusSq) {
            return;
        }
        {
            fx32 s = FX_Sqrt(HitMagSq(&e));
            if (found == 0 || s <= dist) {
                dist = s;
                p.x = tri->v[2][0];
                p.y = tri->v[2][1];
                p.z = tri->v[2][2];
            }
        }
    }
found:
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
        HitTriOwner *owner = q->owner;
        fx32 s = owner->scale;
        fx32 x = p.x;
        fx32 y = p.y;
        fx32 z = p.z;
        info->pos.x = FX_Mul(x, s);
        info->pos.y = FX_Mul(y, s);
        info->pos.z = FX_Mul(z, s);
        MTX_MultVec43(&info->pos, &owner->mtx, &info->pos);
    }
    info->distSq = FX_Mul(FX_Mul(dist, block->mtx._00), q->owner->scale);
    MI_Copy48B(&q->owner->mtx, &m);
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
    info->owner = q->owner;
    info->block = block;
    info->tri = tri;
    info->attr = tri->attr;
    info->n[0] = tri->n[0];
    info->n[1] = tri->n[1];
    info->n[2] = tri->n[2];
    if (info->distSq < q->best) {
        q->best = info->distSq;
        data_02fe0ef8 = info;
    }
    data_02fe0efc++;
fail:
    return;
}

}
