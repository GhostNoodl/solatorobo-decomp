#include "Main/Hit/HitSphere.h"

extern "C" {


extern HitSphere *data_02fe0f10;
extern int data_02fe0ef4;

int func_0203f248(int a, int b) {
    return (int)(((s64)a * b + 0x800) >> 12);
}

void func_0203f260(HitSphere *hit) {
    hit->active = 0;
    hit->unk_25 = 0;
    hit->mask = -1;
    hit->unk_30 = -1;
    hit->unk_34 = 1;
    hit->group = 0;
    hit->next = NULL;
    hit->radius = 0x1000;
    hit->pos.x = 0;
    hit->pos.y = 0;
    hit->pos.z = 0;
    hit->unk_0c.x = 0;
    hit->unk_0c.y = 0;
    hit->unk_0c.z = 0;
    hit->push.x = 0;
    hit->push.y = 0;
    hit->push.z = 0;
}

static inline void HitSphere_Unlink(HitSphere *hit) {
    HitSphere *prev;
    HitSphere *cur;
    if (hit->active == 0) {
        return;
    }
    hit->active = 0;
    prev = data_02fe0f10;
    if (prev == hit) {
        data_02fe0f10 = prev->next;
    } else {
        for (cur = prev->next; cur != hit; cur = cur->next) {
            prev = cur;
        }
        prev->next = hit->next;
    }
    data_02fe0ef4--;
}

void func_0203f2b8(HitSphere *hit) {
    HitSphere_Unlink(hit);
}

void func_0203f324(HitSphere *hit) {
    if (hit->active != 0) {
        return;
    }
    hit->active = 1;
    hit->next = data_02fe0f10;
    data_02fe0f10 = hit;
    data_02fe0ef4++;
}

void func_0203f364(HitSphere *hit) {
    HitSphere_Unlink(hit);
}


typedef struct HitInfo {
    /* 0x00 */ HitVec a;
    /* 0x0c */ HitVec b;
    /* 0x18 */ int c0;
    /* 0x1c */ int c1;
    /* 0x20 */ int c2;
    /* 0x24 */ int d[6];
} HitInfo; // size 0x3c

extern u32 data_02fe0f04;
extern HitSphere *data_02fe0f00;
extern HitInfo data_02fe0f14;
extern int data_02fe0efc;
extern HitInfo data_02fe0f50[];

extern void VEC_Add(const HitVec *a, const HitVec *b, HitVec *out);
extern void VEC_Normalize(const HitVec *src, HitVec *dst);
extern int FX_Sqrt(int x);
int func_0203fc78(HitVec *out, HitVec *pos, HitVec *prev, int radius, int a, int b);
int func_0203fde8(HitVec *out, HitVec *pos, int radius, int a, int b);

static inline int FX_Mul(int a, int b) {
    return (int)(((s64)a * b + 0x800) >> 12);
}

int func_0203f3d0(HitSphere *self) {
    int result = 0;
    HitSphere *cur;
    int best;
    HitSphere *other;
    int r;
    int lenSq;
    u8 flag;
    HitVec d;
    HitVec min;
    HitVec max;
    HitInfo info;
    HitVec v;

    self->push.x = 0;
    self->push.y = 0;
    self->push.z = 0;
    data_02fe0f04 = 0;
    data_02fe0f00 = NULL;
    if (self->active && (cur = data_02fe0f10) != NULL) {
        min.x = 0;
        min.y = 0;
        min.z = 0;
        max.x = 0;
        max.y = 0;
        max.z = 0;
        best = 0x7fffffff;
        while (cur != NULL) {
            other = cur;
            cur = cur->next;
            if (other == self || !other->active) {
                continue;
            }
            if (!(other->group & self->mask)) {
                continue;
            }
            d.x = self->pos.x - other->pos.x;
            d.y = self->pos.y - other->pos.y;
            d.z = self->pos.z - other->pos.z;
            r = other->radius + self->radius;
            if (d.x > r || d.y > r || d.z > r) {
                continue;
            }
            {
                int nr = -r;
                int t = -d.x;
                if (t < nr) {
                    continue;
                }
                t = -d.y;
                if (t < nr) {
                    continue;
                }
                t = -d.z;
                if (t < nr) {
                    continue;
                }
            }
            lenSq = (int)(((s64)d.x * d.x + (s64)d.y * d.y + (s64)d.z * d.z + 0x800) >> 12);
            if (lenSq == 0) {
                d.x = 0x1000;
            } else {
                if (lenSq > FX_Mul(r, r)) {
                    continue;
                }
                VEC_Normalize(&d, &d);
                d.y = 0;
                r -= FX_Sqrt(lenSq);
            }
            d.x = FX_Mul(d.x, r + 0x10);
            d.y = FX_Mul(d.y, r + 0x10);
            d.z = FX_Mul(d.z, r + 0x10);
            if (min.x > d.x) {
                min.x = d.x;
            } else if (max.x < d.x) {
                max.x = d.x;
            }
            if (min.y > d.y) {
                min.y = d.y;
            } else if (max.y < d.y) {
                max.y = d.y;
            }
            if (min.z > d.z) {
                min.z = d.z;
            } else if (max.z < d.z) {
                max.z = d.z;
            }
            data_02fe0f04 |= other->group;
            if (r < best) {
                best = r;
                data_02fe0f00 = other;
            }
            result = 1;
        }
        VEC_Add(&min, &max, &d);
        VEC_Add(&self->push, &d, &self->push);
    }
    if (self->unk_30 != 0) {
        flag = self->unk_25;
        d = self->pos;
        if (data_02fe0f04 != 0) {
            VEC_Add(&d, &self->push, &d);
            flag = 1;
        }
        if (flag) {
            flag = 0;
            v.x = 0;
            v.y = 0;
            v.z = 0;
            if (func_0203fc78(&v, &d, &self->unk_0c, self->radius, self->unk_30, self->unk_34) != -0x1000) {
                VEC_Add(&self->push, &v, &self->push);
                VEC_Add(&d, &v, &d);
                info = data_02fe0f14;
                result |= 2;
                flag = 1;
            }
        }
        if (func_0203fde8(&self->push, &d, self->radius, self->unk_30, self->unk_34) != -0x1000) {
            result |= 2;
        }
        if (flag) {
            data_02fe0f50[data_02fe0efc] = info;
            data_02fe0efc++;
        }
    }
    return result;
}


typedef struct HitMtx {
    int m[4][3];
} HitMtx;

typedef struct HitMeshRes {
    /* 0x00 */ u32 unk_00;
    /* 0x04 */ u32 unk_04;
    /* 0x08 */ u32 ofsHeader;
    /* 0x0c */ u32 unk_0c;
    /* 0x10 */ int ext[6];
} HitMeshRes;

typedef struct HitMeshBlock {
    /* 0x00 */ u32 unk_00[3];
    /* 0x0c */ int count;
    /* 0x10 */ u32 data;
    /* 0x14 */ u32 refs[4];
    /* 0x24 */ u32 unk_24;
    /* 0x28 */ u32 items[1];
} HitMeshBlock;

typedef struct HitMeshHeader {
    /* 0x00 */ u32 magic;
    /* 0x04 */ u32 unk_04[3];
    /* 0x10 */ u32 tableCount;
    /* 0x14 */ u32 blockCount;
    /* 0x18 */ u32 unk_18;
    /* 0x1c */ u32 relocated;
    /* 0x20 */ u32 table[1];
} HitMeshHeader;

typedef struct HitMesh {
    /* 0x00 */ int scale;
    /* 0x04 */ int invScale;
    /* 0x08 */ HitMtx mtx;
    /* 0x38 */ HitMtx invMtx;
    /* 0x68 */ int extent;
    /* 0x6c */ HitVec min;
    /* 0x78 */ HitVec max;
    union {
        u16 flags;
        struct {
            /* 0x84 */ u16 active : 1;
            /* 0x84 */ u16 unk_84_1 : 1;
            /* 0x84 */ u16 loaded : 1;
            /* 0x84 */ u16 unk_84_3 : 1;
            /* 0x84 */ u16 unk_84_4 : 12;
        };
    };
    /* 0x88 */ HitMeshRes *res;
    /* 0x8c */ HitMeshHeader *header;
    /* 0x90 */ u32 *table;
    /* 0x94 */ struct HitMesh *next;
} HitMesh;

extern HitMesh *data_02fe0f08;
extern int data_02fe0f0c;

extern void func_02011820(HitMtx *mtx);
extern int FX_Inv(int x);
extern void MI_Copy48B(const HitMtx *src, HitMtx *dst);
extern void func_020119cc(const HitMtx *src, HitMtx *dst);
void func_0203fa0c(HitMesh *mesh);
void func_0203fb08(HitMesh *mesh);

void func_0203f80c(HitMesh *mesh) {
    mesh->flags = 0;
    mesh->active = 0;
    mesh->res = NULL;
    mesh->unk_84_1 = 1;
    mesh->loaded = 0;
    mesh->header = NULL;
    mesh->table = NULL;
    mesh->unk_84_3 = 0;
    mesh->next = NULL;
    func_02011820(&mesh->mtx);
    func_02011820(&mesh->invMtx);
    mesh->extent = 0;
}

static inline void HitMesh_Unlink(HitMesh *mesh) {
    HitMesh *prev;
    HitMesh *cur;
    if (!mesh->active) {
        return;
    }
    prev = data_02fe0f08;
    mesh->active = 0;
    if (prev == mesh) {
        data_02fe0f08 = prev->next;
    } else {
        for (cur = prev->next; cur != mesh; cur = cur->next) {
            prev = cur;
        }
        prev->next = mesh->next;
    }
    data_02fe0f0c--;
}

void func_0203f864(HitMesh *mesh) {
    if (mesh->active) {
        HitMesh_Unlink(mesh);
    }
}

void func_0203f8d8(HitMesh *mesh) {
    if (mesh->active) {
        return;
    }
    mesh->active = 1;
    mesh->next = data_02fe0f08;
    data_02fe0f08 = mesh;
    data_02fe0f0c++;
}

void func_0203f920(HitMesh *mesh) {
    HitMesh_Unlink(mesh);
}

void func_0203f990(HitMesh *mesh, HitMeshRes *res) {
    mesh->res = res;
    mesh->scale = 0x1000;
    mesh->invScale = 0x1000;
    func_0203fb08(mesh);
    func_0203fa0c(mesh);
}

void func_0203f9b8(HitMesh *mesh, int scale) {
    mesh->scale = scale;
    mesh->invScale = FX_Inv(scale);
    func_0203fa0c(mesh);
}

void func_0203f9dc(HitMesh *mesh, const HitMtx *mtx) {
    MI_Copy48B(mtx, &mesh->mtx);
    func_020119cc(mtx, &mesh->invMtx);
    func_0203fa0c(mesh);
}

#define HIT_ABS(x) ((x) < 0 ? -(x) : (x))

void func_0203fa0c(HitMesh *mesh) {
    HitVec v;
    int s;
    if (mesh->extent == 0) {
        HitMeshRes *res = mesh->res;
        int m = HIT_ABS(res->ext[3]);
        int t = HIT_ABS(res->ext[0]);
        if (m < t) {
            m = t;
        }
        t = HIT_ABS(res->ext[4]);
        if (m < t) {
            m = t;
        }
        t = HIT_ABS(res->ext[1]);
        if (m < t) {
            m = t;
        }
        t = HIT_ABS(res->ext[5]);
        if (m < t) {
            m = t;
        }
        t = HIT_ABS(res->ext[2]);
        if (m < t) {
            m = t;
        }
        mesh->extent = m;
    }
    s = FX_Mul(mesh->extent, mesh->scale);
    v.x = s;
    v.y = s;
    v.z = s;
    mesh->min.x = mesh->mtx.m[3][0] - v.x;
    mesh->min.y = mesh->mtx.m[3][1] - v.y;
    mesh->min.z = mesh->mtx.m[3][2] - v.z;
    VEC_Add((HitVec *)mesh->mtx.m[3], &v, &mesh->max);
}

void func_0203fb08(HitMesh *mesh) {
    HitMeshRes *res;
    HitMeshHeader *header;
    HitMeshBlock *block;
    u32 *items;
    u32 i;
    u32 j;
    int k;
    int n;
    res = mesh->res;
    header = (HitMeshHeader *)((u8 *)res + res->ofsHeader);
    if (header->magic != 0x54514854) {
        return;
    }
    mesh->header = header;
    mesh->table = header->table;
    mesh->loaded = 1;
    if (header->relocated != 0) {
        return;
    }
    block = (HitMeshBlock *)&header->table[header->tableCount];
    for (i = 0; i < header->tableCount; i++) {
        mesh->table[i] = (u32)((u8 *)res + mesh->table[i]);
    }
    for (j = 0; j < header->blockCount; j++) {
        block->data = (u32)((u8 *)res + block->data);
        items = block->items;
        for (k = 0; k < 4; k++) {
            if (block->refs[k] != 0) {
                block->refs[k] = (u32)((u8 *)res + block->refs[k]);
            }
        }
        for (n = 0; n < block->count; n++) {
            items[n] = (u32)((u8 *)res + items[n]);
        }
        block = (HitMeshBlock *)&items[n];
    }
    header->relocated = 1;
}

void func_0203fc1c(void) {
    data_02fe0ef4 = 0;
    data_02fe0f10 = NULL;
    data_02fe0f0c = 0;
    data_02fe0f08 = NULL;
}


void func_0203fc54(void) {
}

HitMeshRes *func_0203fc58(HitMesh *mesh) {
    return mesh->res;
}

BOOL func_0203fc60(HitMesh *mesh) {
    return mesh->unk_84_1 ? TRUE : FALSE;
}

extern void VEC_MultAdd(int fx, const HitVec *a, const HitVec *b, HitVec *out);
extern int func_01ffbd6c(HitVec *from, HitVec *to, int a, int b, int c, int d);
extern int func_01ffbf40(HitVec *pos, int radius, int a, int b, int c, int d);

static inline BOOL HitVec_Equal(const HitVec *a, const HitVec *b) {
    return (a->x == b->x && a->y == b->y && a->z == b->z) ? TRUE : FALSE;
}

static inline void HitVec_Sub(const HitVec *a, const HitVec *b, HitVec *out) {
    out->x = a->x - b->x;
    out->y = a->y - b->y;
    out->z = a->z - b->z;
}

int func_0203fc78(HitVec *out, HitVec *pos, HitVec *prev, int radius, int a, int b) {
    HitVec dir;
    HitVec p;
    int r;
    if (pos->x == prev->x && pos->y == prev->y && pos->z == prev->z) {
        return -0x1000;
    }
    HitVec_Sub(pos, prev, &dir);
    VEC_Normalize(&dir, &dir);
    VEC_MultAdd(radius, &dir, pos, &p);
    r = func_01ffbd6c(prev, &p, a, b, 0, -1);
    if (r != -0x1000) {
        if (r > radius) {
            VEC_MultAdd(-(radius + 0x10), &dir, &data_02fe0f14.a, &p);
            HitVec_Sub(&p, pos, &p);
        } else {
            HitVec_Sub(prev, pos, &p);
        }
        VEC_Add(out, &p, out);
    }
    return r;
}

int func_0203fde8(HitVec *out, HitVec *pos, int radius, int a, int b) {
    HitVec p;
    HitVec d;
    HitVec min;
    HitVec max;
    int r;
    int n;
    int i;
    int s;
    HitInfo *info;
    p.x = pos->x;
    p.y = pos->y;
    p.z = pos->z;
    r = func_01ffbf40(&p, radius, a, b, 0, -1);
    if (r != -0x1000) {
        n = data_02fe0efc;
        if (n > 24) {
            n = 24;
        }
        min.x = 0;
        min.y = 0;
        min.z = 0;
        max.x = 0;
        max.y = 0;
        max.z = 0;
        for (i = 0; i < n; i++) {
            info = &data_02fe0f50[i];
            if (info->c1 == -1) {
                continue;
            }
            s = radius - info->c0 + 0x10;
            d.x = FX_Mul(info->b.x, s);
            d.y = FX_Mul(info->b.y, s);
            d.z = FX_Mul(info->b.z, s);
            if (min.x > d.x) {
                min.x = d.x;
            } else if (max.x < d.x) {
                max.x = d.x;
            }
            if (min.y > d.y) {
                min.y = d.y;
            } else if (max.y < d.y) {
                max.y = d.y;
            }
            if (min.z > d.z) {
                min.z = d.z;
            } else if (max.z < d.z) {
                max.z = d.z;
            }
        }
        VEC_Add(&min, &max, &d);
        VEC_Add(out, &d, out);
    }
    return r;
}


typedef struct HitVec16 {
    s16 x;
    s16 y;
    s16 z;
} HitVec16;

typedef struct HitTri {
    /* 0x00 */ HitVec16 min;
    /* 0x06 */ HitVec16 max;
    /* 0x0c */ int unk_0c;
    /* 0x10 */ int d;
    /* 0x14 */ HitVec16 v[3];
    /* 0x26 */ HitVec16 normal;
    /* 0x2c */ HitVec16 edge[3];
    /* 0x3e */ u16 pad;
    /* 0x40 */ int len[3];
} HitTri; // size 0x4c

typedef struct HitBounds {
    HitVec16 min;
    HitVec16 max;
} HitBounds;

extern int VEC_Mag(const HitVec *v);
extern int VEC_Fx16DotProduct(const HitVec16 *a, const HitVec16 *b);

static inline void HitTri_SetEdge(HitTri *tri, int n, const HitVec16 *a, const HitVec16 *b, HitVec *e) {
    HitVec dir;
    e->x = b->x - a->x;
    e->y = b->y - a->y;
    e->z = b->z - a->z;
    tri->len[n] = VEC_Mag(e);
    VEC_Normalize(e, &dir);
    tri->edge[n].x = dir.x;
    tri->edge[n].y = dir.y;
    tri->edge[n].z = dir.z;
}

static inline void HitTri_SetNormal(HitTri *tri, HitVec *e) {
    HitVec n;
    int ax = tri->v[1].x - tri->v[0].x;
    int ay = tri->v[1].y - tri->v[0].y;
    int az = tri->v[1].z - tri->v[0].z;
    int bx = tri->v[2].x - tri->v[0].x;
    int by = tri->v[2].y - tri->v[0].y;
    int bz = tri->v[2].z - tri->v[0].z;
    e->x = (int)(((s64)ay * bz - (s64)az * by + 0x800) >> 12);
    e->y = (int)(((s64)az * bx - (s64)ax * bz + 0x800) >> 12);
    e->z = (int)(((s64)ax * by - (s64)ay * bx + 0x800) >> 12);
    VEC_Normalize(e, &n);
    tri->normal.x = n.x;
    tri->normal.y = n.y;
    tri->normal.z = n.z;
}

void func_0203ff94(HitBounds *bounds, HitTri *tri, int value, const HitVec16 *verts, const u32 (*indices)[3]) {
    int i;
    for (i = 0; i < 2; i++, tri++) {
        HitVec e;
        tri->unk_0c = value;
        tri->v[0] = verts[indices[i][0]];
        tri->v[1] = verts[indices[i][1]];
        tri->v[2] = verts[indices[i][2]];
        if (tri->v[0].x < tri->v[1].x) {
            tri->max.x = tri->v[1].x;
            tri->min.x = tri->v[0].x;
        } else {
            tri->max.x = tri->v[0].x;
            tri->min.x = tri->v[1].x;
        }
        if (tri->v[2].x < tri->min.x) {
            tri->min.x = tri->v[2].x;
        }
        if (tri->v[2].x > tri->max.x) {
            tri->max.x = tri->v[2].x;
        }
        if (tri->v[0].y < tri->v[1].y) {
            tri->max.y = tri->v[1].y;
            tri->min.y = tri->v[0].y;
        } else {
            tri->max.y = tri->v[0].y;
            tri->min.y = tri->v[1].y;
        }
        if (tri->v[2].y < tri->min.y) {
            tri->min.y = tri->v[2].y;
        }
        if (tri->v[2].y > tri->max.y) {
            tri->max.y = tri->v[2].y;
        }
        if (tri->v[0].z < tri->v[1].z) {
            tri->max.z = tri->v[1].z;
            tri->min.z = tri->v[0].z;
        } else {
            tri->max.z = tri->v[0].z;
            tri->min.z = tri->v[1].z;
        }
        if (tri->v[2].z < tri->min.z) {
            tri->min.z = tri->v[2].z;
        }
        if (tri->v[2].z > tri->max.z) {
            tri->max.z = tri->v[2].z;
        }
        if (tri->min.x < bounds->min.x) {
            bounds->min.x = tri->min.x;
        }
        if (tri->max.x > bounds->max.x) {
            bounds->max.x = tri->max.x;
        }
        if (tri->min.y < bounds->min.y) {
            bounds->min.y = tri->min.y;
        }
        if (tri->max.y > bounds->max.y) {
            bounds->max.y = tri->max.y;
        }
        if (tri->min.z < bounds->min.z) {
            bounds->min.z = tri->min.z;
        }
        if (tri->max.z > bounds->max.z) {
            bounds->max.z = tri->max.z;
        }
        HitTri_SetEdge(tri, 0, &tri->v[0], &tri->v[1], &e);
        HitTri_SetEdge(tri, 1, &tri->v[1], &tri->v[2], &e);
        HitTri_SetEdge(tri, 2, &tri->v[2], &tri->v[0], &e);
        HitTri_SetNormal(tri, &e);
        tri->d = -VEC_Fx16DotProduct(&tri->normal, &tri->v[0]);
    }
}

}
