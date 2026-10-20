#include "Main/Gfx/ObjPool.h"
#include "nitro/fx.h"

extern "C" {

void func_0205983c(void) {
    ObjPool *pool;
    if (data_02149efc.pool != NULL) {
        return;
    }
    pool = (ObjPool *)func_0203dd9c(sizeof(ObjPool));
    if (pool != NULL) {
        ObjPool_Init(pool);
    }
    data_02149efc.pool = pool;
}

void func_020598a8(void) {
    void *saved = data_02097dd0->cur;
    data_02097dd0->cur = data_02097dd0->unk_08;
    {
        ObjPool *p = data_02149efc.pool;
        if (p != NULL) {
            if (p != NULL) {
                ObjPool_Reset(p);
                func_0203de1c(p);
            }
            data_02149efc.pool = NULL;
        }
    }
    data_02097dd0->cur = saved;
}

void func_02059974(ObjPool *pool) {
    ObjPool_Reset(pool);
}

void func_020599f4(ObjPool *pool, ObjPoolEntry *entry) {
    switch (entry->kind) {
    case 3: {
        void *saved = data_02097dd0->cur;
        data_02097dd0->cur = data_02097dd0->unk_08;
        {
            void *p = entry->obj;
            if (p != NULL) {
                if (p != NULL) {
                    func_0203f2b8(p);
                    func_0203de1c(p);
                }
                entry->obj = NULL;
            }
        }
        data_02097dd0->cur = saved;
        break;
    }
    case 4: {
        void *saved;
        if (((void **)entry->obj)[0x88 / 4] != NULL) {
            func_0203df0c(((void **)entry->obj)[0x88 / 4]);
        }
        saved = data_02097dd0->cur;
        data_02097dd0->cur = data_02097dd0->unk_08;
        {
            void *p = entry->obj;
            if (p != NULL) {
                if (p != NULL) {
                    func_0203f864(p);
                    func_0203de1c(p);
                }
                entry->obj = NULL;
            }
        }
        data_02097dd0->cur = saved;
        break;
    }
    }
    if (pool->head == entry) {
        pool->head = entry->next;
    } else {
        ObjPoolEntry *p = pool->head;
        while (p->next != entry) {
            p = p->next;
        }
        p->next = entry->next;
    }
    entry->next = NULL;
    entry->active = 0;
    entry->kind = 0;
    entry->unk_04 = 0;
    entry->unk_06 = 0xffff;
}

ObjPoolEntry *func_02059b14(ObjPool *pool, u16 id, ObjPoolParam *param) {
    ObjPoolEntry *e = pool->entries;
    int i;
    for (i = 0; i < 16; i++, e++) {
        if (e->kind == 0) {
            break;
        }
    }
    e->active = 1;
    e->id = id;
    e->unk_04 = 0;
    e->unk_06 = 0xffff;
    if (param != NULL) {
        e->x = param->x << 4;
        e->y = param->y << 4;
        e->z = param->z << 4;
        BOOL flag = FALSE;
        if (param->ry != 0 || param->rz != 0) {
            flag = TRUE;
        }
        if (flag) {
            e->kind = 2;
            e->unk_18 = ObjPool_FxMul(param->r << 4, 0x800);
            e->unk_1c = ObjPool_FxMul(param->ry << 4, 0x800);
            e->unk_20 = ObjPool_FxMul(param->rz << 4, 0x800);
        } else {
            s32 r;
            e->kind = 1;
            r = param->r << 4;
            e->unk_18 = r;
            e->unk_1c = ObjPool_FxMul(r, r);
            e->unk_20 = 0;
        }
    }
    e->r = data_02fe1534.r;
    e->g = data_02fe1534.g;
    e->b = data_02fe1534.b;
    if (pool->head == NULL) {
        e->next = NULL;
    } else {
        e->next = pool->head;
    }
    pool->head = e;
    return e;
}

typedef struct BoxVec16 {
    s16 x;
    s16 y;
    s16 z;
} BoxVec16;

typedef struct BoxTri {
    u8 data[0x4c];
} BoxTri;

typedef struct BoxBounds {
    BoxVec16 min;
    BoxVec16 max;
} BoxBounds;

typedef struct BoxMeshRes {
    /* 0x000 */ u32 magic;
    /* 0x004 */ u32 version;
    /* 0x008 */ u32 ofsHeader;
    /* 0x00c */ u32 triCount;
    /* 0x010 */ s32 ext[6];
    /* 0x028 */ s32 scale;
    /* 0x02c */ s32 invScale;
    /* 0x030 */ u32 unk_30;
    /* 0x034 */ BoxBounds bounds;
    /* 0x040 */ u32 unk_40;
    /* 0x044 */ u32 unk_44;
    /* 0x048 */ MtxFx43 mtx;
    /* 0x078 */ MtxFx43 invMtx;
    /* 0x0a8 */ u32 count;
    /* 0x0ac */ BoxTri tris[12];
} BoxMeshRes;

typedef struct BoxMesh {
    u8 unk_00[0x84];
    union {
        u16 flags;
        struct {
            u16 active : 1;
            u16 unk_84_1 : 1;
            u16 loaded : 1;
            u16 unk_84_3 : 1;
            u16 unk_84_4 : 12;
        };
    };
} BoxMesh;

typedef struct BoxFaceAttr {
    u32 v[6];
} BoxFaceAttr;

typedef struct BoxFaceIdx {
    u32 v[6][2][3];
} BoxFaceIdx;

typedef struct BoxMtx {
    s32 m[4][3];
} BoxMtx;

extern const BoxFaceAttr data_02082a10;
extern const BoxFaceIdx data_02082a78;
extern const BoxFaceIdx data_02082b08;

extern void *func_0203de84(u32 size, u32 align);
extern void func_0203ff94(BoxBounds *bounds, BoxTri *tri, u32 value, const BoxVec16 *verts, const u32 (*indices)[3]);
extern void func_0203f80c(void *mesh);
extern void func_0203f990(BoxMesh *mesh, BoxMeshRes *res);
extern void func_0203f8d8(BoxMesh *mesh);
extern void func_0203f9dc(BoxMesh *mesh, const BoxMtx *mtx);

static inline void Box_SetBit3(BoxMesh *m, u32 v) {
    m->unk_84_3 = v;
}

static inline void Box_SetBit1(BoxMesh *m, u32 v) {
    m->unk_84_1 = v;
}

// Translation plus 3x3 identity. The asm block also keeps the rest of func_02059c98 at the
// target's optimisation level (unrotated loops, bic/orr bit-field writes).
static inline void Box_SetMtx(BoxMtx *m, s32 x, s32 y, s32 z) {
    asm {
        str x, [m, #0x24]
        mov r1, #0x1000
        str y, [m, #0x28]
        mov r2, #0
        str z, [m, #0x2c]
        mov r3, #0
        stmia m!, {r1, r2}
        stmia m!, {r2, r3}
        stmia m!, {r1, r2}
        stmia m!, {r2, r3}
        stmia m!, {r1}
    }
}

ObjPoolEntry *func_02059c98(ObjPool *pool, u16 id, ObjPoolParam *param, int flip) {
    BoxVec16 verts[8];
    BoxFaceAttr attr;
    BoxMtx m;
    ObjPoolEntry *e;
    int i;
    u32 *tail;
    BoxMeshRes *res;
    BoxTri *tri;
    s32 s;
    s16 x, y, z;
    e = func_02059b14(pool, id, param);
    {
        u8 *p = (u8 *)0x10;
        BoxTri *t;
        p += 0x9c;
        t = (BoxTri *)p;
        t += 12;
        s = (s32)t;
    }
    e->kind = 4;
    res = (BoxMeshRes *)func_0203de84(s + 0x20, 4);
    tail = (u32 *)((u8 *)res + s);
    tail[0] = 0;
    tail[1] = 0;
    res->magic = 0x4c4f4354;
    res->version = 0x1000000;
    res->ofsHeader = s - 0x20;
    res->triCount = 12;
    res->ext[0] = 0x80000000;
    res->ext[1] = 0x80000000;
    res->ext[2] = 0x80000000;
    res->ext[3] = 0x7fffffff;
    res->ext[4] = 0x7fffffff;
    res->ext[5] = 0x7fffffff;
    res->scale = 0x1000;
    res->invScale = 0x1000;
    res->unk_30 = 1;
    res->bounds.min.x = 0x7fff;
    res->bounds.min.y = 0x7fff;
    res->bounds.min.z = 0x7fff;
    res->bounds.max.x = -0x8000;
    res->bounds.max.y = -0x8000;
    res->bounds.max.z = -0x8000;
    res->unk_40 = 0;
    res->count = 12;
    s = e->unk_18;
    if (s < e->unk_1c) s = e->unk_1c;
    if (s < e->unk_20) s = e->unk_20;
    tri = res->tris;
    if (s <= 0x7fff) s = 0x1000; else s = FX_Div(s, 0x7fff) + 0x19a;
    MTX_Scale43(&res->mtx, s, s, s);
    MTX_Inverse43(&res->mtx, &res->invMtx);
    x = FX_Div(e->unk_18, s);
    y = FX_Div(e->unk_1c, s);
    z = FX_Div(e->unk_20, s);
    verts[0].x = -x;
    verts[0].y = y;
    verts[0].z = z;
    verts[1].x = -x;
    verts[1].y = -y;
    verts[1].z = z;
    verts[2].x = x;
    verts[2].y = y;
    verts[2].z = z;
    verts[3].x = x;
    verts[3].y = -y;
    verts[3].z = z;
    verts[4].x = x;
    verts[4].y = y;
    verts[4].z = -z;
    verts[5].x = x;
    verts[5].y = -y;
    verts[5].z = -z;
    verts[6].x = -x;
    verts[6].y = y;
    verts[6].z = -z;
    verts[7].x = -x;
    verts[7].y = -y;
    verts[7].z = -z;
    attr = data_02082a10;
    if (flip) {
        BoxFaceIdx idx = data_02082a78;
        for (i = 0; i < 6; i++, tri += 2) {
            func_0203ff94(&res->bounds, tri, attr.v[i], verts, idx.v[i]);
        }
    } else {
        BoxFaceIdx idx = data_02082b08;
        for (i = 0; i < 6; i++, tri += 2) {
            func_0203ff94(&res->bounds, tri, attr.v[i], verts, idx.v[i]);
        }
    }
    {
        BoxMesh *mesh = (BoxMesh *)func_0203dd9c(0x98);
        if (mesh != NULL) {
            func_0203f80c(mesh);
        }
        e->obj = mesh;
    }
    func_0203f990((BoxMesh *)e->obj, res);
    if (((BoxMesh *)e->obj)->active != 1) {
        func_0203f8d8((BoxMesh *)e->obj);
    }
    Box_SetBit3((BoxMesh *)e->obj, 1);
    Box_SetMtx(&m, e->x, e->y, e->z);
    func_0203f9dc((BoxMesh *)e->obj, &m);
    Box_SetBit1((BoxMesh *)e->obj, 0);
    return e;
}

}
