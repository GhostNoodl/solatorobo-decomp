#include "types.h"


#include "Main/Res/ResMgr.h"
#include "Main/Gfx/GfxMgr.h"

extern "C" {

typedef struct NameNode {
    /* 0x00 */ char name[0x20];
    /* 0x20 */ u32 unk_20;
    /* 0x24 */ u32 hash;
    /* 0x28 */ u32 value;
    /* 0x2c */ u32 key;
    /* 0x30 */ int refCount;
    /* 0x34 */ struct NameNode *prev;
    /* 0x38 */ struct NameNode *next;
} NameNode; // size 0x3c

typedef struct NamePool {
    /* 0x00 */ char name[0x20];
    /* 0x20 */ u32 value;
    /* 0x24 */ u32 hash;
    /* 0x28 */ NameNode *nodes;
    /* 0x2c */ NameNode *freeList;
    /* 0x30 */ NameNode *usedList;
} NamePool; // size 0x34

typedef struct NamePools {
    /* 0x00 */ u32 unk_00;
    /* 0x04 */ NamePool *pool1;
    /* 0x08 */ u32 unk_08;
    /* 0x0c */ u32 unk_0c;
    /* 0x10 */ NamePool *pool0;
} NamePools;

// mwcc lays out .bss in the order x(n-1) .. x1, xn of the definitions.
u32 data_02097de0;
u32 data_02097ddc;
NamePool *data_02097dd8;
u32 data_02097dd4;
NamePool *data_02097de4;
extern u32 OS_DisableInterrupts(void);
extern u32 OS_RestoreInterrupts(u32 state);
extern void *NNS_FndAllocFromExpHeapEx(void *heap, u32 size, u32 align);
extern void MI_CpuFill8(void *dst, u32 value, u32 size);
void func_0203e300(NamePool *pool, int count);

static inline void *Sys_Alloc(u32 size) {
    u32 irq = OS_DisableInterrupts();
    void *p = NNS_FndAllocFromExpHeapEx(data_02097dd0->cur, size, data_02097dd0->align);
    OS_RestoreInterrupts(irq);
    return p;
}

static inline void *Sys_Alloc04(u32 size, u32 align) {
    u32 irq = OS_DisableInterrupts();
    void *p = NNS_FndAllocFromExpHeapEx(data_02097dd0->unk_04, size, align);
    OS_RestoreInterrupts(irq);
    return p;
}

void func_0203dfb0(void) {
    NamePool *pool;
    data_02097dd0->cur = data_02097dd0->unk_04;
    pool = (NamePool *)Sys_Alloc(sizeof(NamePool));
    if (pool != NULL) {
        func_0203e300(pool, 0x60);
    }
    data_02097de4 = pool;
    data_02097dd0->cur = data_02097dd0->unk_08;
}

void func_0203e024(void) {
    NamePool *pool;
    data_02097dd0->cur = data_02097dd0->unk_04;
    pool = (NamePool *)Sys_Alloc(sizeof(NamePool));
    if (pool != NULL) {
        func_0203e300(pool, 0x60);
    }
    data_02097dd8 = pool;
    data_02097dd0->cur = data_02097dd0->unk_08;
}

static inline int NamePool_Hash(const char *name) {
    int len = (int)STD_GetStringLength(name);
    int hash;
    int i;
    if (len > 16) {
        len = 16;
    }
    hash = 0;
    for (i = 0; i < len; i++) {
        hash = hash * 37 + name[i];
    }
    if (hash < 0) {
        hash = -hash;
    }
    return hash % 6007;
}

void func_0203e098(const char *name, u32 value) {
    NamePool *pool = data_02097de4;
    if (pool == NULL) {
        return;
    }
    STD_CopyString(pool->name, name);
    pool->value = value;
    pool->hash = NamePool_Hash(name);
}

void func_0203e134(const char *name, u32 value) {
    NamePool *pool = data_02097dd8;
    if (pool == NULL) {
        return;
    }
    STD_CopyString(pool->name, name);
    pool->value = value;
    pool->hash = NamePool_Hash(name);
}

NameNode *func_0203e1d0(NamePool *pool, u32 key) {
    NameNode *node = pool->freeList;
    NameNode *next = node->next;
    pool->freeList = next;
    if (next != NULL) {
        next->prev = NULL;
    }
    STD_CopyString(node->name, pool->name);
    node->unk_20 = 0;
    node->hash = pool->hash;
    node->value = pool->value;
    node->key = key;
    node->refCount = 1;
    node->prev = NULL;
    next = pool->usedList;
    node->next = next;
    if (next != NULL) {
        next->prev = node;
    }
    pool->usedList = node;
    pool->name[0] = 0;
    pool->value = 0x87654321;
    pool->hash = 0;
    return node;
}

static inline NameNode *NamePool_Find(NamePool *pool, u32 key) {
    NameNode *node = pool->usedList;
    if (node == NULL) {
        return NULL;
    }
    for (; node != NULL; node = node->next) {
        if (node->key == key) {
            return node;
        }
    }
    return NULL;
}

NameNode *func_0203e25c(NamePool *pool, u32 key) {
    NameNode *node = NamePool_Find(pool, key);
    NameNode *next;
    if (--node->refCount != 0) {
        return node;
    }
    if (node->prev != NULL) {
        node->prev->next = node->next;
    } else {
        pool->usedList = node->next;
    }
    if (node->next != NULL) {
        node->next->prev = node->prev;
    }
    node->name[0] = 0;
    node->unk_20 = 0;
    node->hash = 0;
    node->value = 0;
    node->key = 0;
    node->refCount = 0;
    node->prev = NULL;
    next = pool->freeList;
    node->next = next;
    if (next != NULL) {
        next->prev = node;
    }
    pool->freeList = node;
    return NULL;
}

void func_0203e300(NamePool *pool, int count) {
    NameNode *nodes;
    int i;
    pool->nodes = (NameNode *)Sys_Alloc04(count * sizeof(NameNode), 4);
    MI_CpuFill8(pool->nodes, 0, 4);
    nodes = pool->nodes;
    nodes[0].prev = NULL;
    nodes[0].next = &nodes[1];
    for (i = 1; i < count - 1; i++) {
        int off = i * sizeof(NameNode);
        ((NameNode *)((u8 *)nodes + off))->prev = (NameNode *)((u8 *)nodes + (off - sizeof(NameNode)));
        ((NameNode *)((u8 *)nodes + off))->next = (NameNode *)((u8 *)nodes + (off + sizeof(NameNode)));
    }
    nodes[i].prev = &nodes[i - 1];
    nodes[i].next = NULL;
    pool->freeList = nodes;
    pool->usedList = NULL;
    pool->name[0] = 0;
    pool->value = 0x87654321;
    pool->hash = 0;
}

typedef struct VramTransfer {
    /* 0x00 */ u32 linked : 1;
    /* 0x00 */ u32 used : 1;
    /* 0x00 */ u32 unk_0_2 : 30;
    /* 0x04 */ u32 src;
    /* 0x08 */ u32 dst;
    /* 0x0c */ u32 size;
    /* 0x10 */ u32 chunk;
    /* 0x14 */ u32 progress;
    /* 0x18 */ u32 id;
    /* 0x1c */ int type;
    /* 0x20 */ struct VramTransfer *prev;
    /* 0x24 */ struct VramTransfer *next;
} VramTransfer; // size 0x28

extern u8 data_02fe04ec;
extern VramTransfer *data_02fe04f0;
extern VramTransfer data_02fe04f4[64];
extern u32 data_02fe00e4;
extern void DC_FlushRange(u32 addr, u32 size);
extern void GX_BeginLoadTex(void);
extern void GX_LoadTex(u32 src, u32 dst, u32 size);
extern void GX_EndLoadTex(void);
extern void GX_BeginLoadTexPltt(void);
extern void GX_LoadTexPltt(u32 src, u32 dst, u32 size);
extern void GX_EndLoadTexPltt(void);
extern void GX_LoadOBJ(u32 src, u32 dst, u32 size);
extern void GX_LoadOBJPltt(u32 src, u32 dst, u32 size);
extern void GX_BeginLoadOBJExtPltt(void);
extern void GX_LoadOBJExtPltt(u32 src, u32 dst, u32 size);
extern void GX_EndLoadOBJExtPltt(void);
extern void GXS_LoadOBJ(u32 src, u32 dst, u32 size);
extern void GXS_LoadOBJPltt(u32 src, u32 dst, u32 size);
extern void GXS_BeginLoadOBJExtPltt(void);
extern void GXS_LoadOBJExtPltt(u32 src, u32 dst, u32 size);
extern void GXS_EndLoadOBJExtPltt(void);

void func_0203e3e8(void) {
    int i;
    for (i = 0; i < 64; i++) {
        *(u32 *)&data_02fe04f4[i] = 0;
        data_02fe04f4[i].type = -1;
        data_02fe04f4[i].src = 0;
        data_02fe04f4[i].dst = 0;
        data_02fe04f4[i].size = 0;
        data_02fe04f4[i].chunk = 0;
        data_02fe04f4[i].progress = 0;
        data_02fe04f4[i].id = 0;
    }
    data_02fe04f0 = NULL;
    data_02fe00e4 = 1;
}

u32 func_0203e458(int type, u32 src, u32 dst, u32 size, u32 chunk) {
    VramTransfer *t;
    int i;
    VramTransfer *last;
    for (i = 0, t = data_02fe04f4; i < 64; i++, t++) {
        if (t->src == src && t->dst == dst && t->size == size) {
            return 0;
        }
    }
    for (i = 0, t = data_02fe04f4; i < 64; i++, t++) {
        if (!t->linked) {
            break;
        }
    }
    t->type = type;
    t->src = src;
    t->dst = dst;
    if (chunk == 0) {
        chunk = size;
    }
    t->size = size;
    if (chunk == 0) {
        chunk = size;
    }
    t->chunk = chunk;
    t->progress = 0;
    t->id = data_02fe00e4;
    *(u32 *)t |= 2;
    t->prev = NULL;
    data_02fe00e4++;
    t->next = NULL;
    if (data_02fe04f0 == NULL) {
        data_02fe04f0 = t;
    } else {
        last = data_02fe04f0;
        while (last->next != NULL) {
            last = last->next;
        }
        last->next = t;
        t->prev = last;
    }
    t->linked = 1;
    DC_FlushRange(t->src, t->size);
    if (data_02fe00e4 == 0) {
        data_02fe00e4 = 1;
    }
    return t->id;
}

static inline void VramTransfer_Unlink(VramTransfer *t) {
    if (t->prev != NULL) {
        t->prev->next = t->next;
    } else {
        data_02fe04f0 = t->next;
    }
    if (t->next != NULL) {
        t->next->prev = t->prev;
    }
    t->linked = 0;
}

static inline void VramTransfer_Release(VramTransfer *t) {
    if (t->linked == 1) {
        VramTransfer_Unlink(t);
    }
    t->src = 0;
    t->dst = 0;
    t->id = 0;
    t->used = 0;
}

void func_0203e58c(u32 id) {
    VramTransfer *t;
    int i;
    if (id == 0) {
        return;
    }
    for (i = 0, t = data_02fe04f4; i < 64; i++, t++) {
        if (t->src != 0 && t->id == id) {
            VramTransfer_Release(t);
            return;
        }
    }
}

BOOL func_0203e63c(u32 id) {
    VramTransfer *t;
    int i;
    if (id == 0) {
        return TRUE;
    }
    for (i = 0, t = data_02fe04f4; i < 64; i++, t++) {
        if (t->src != 0 && t->id == id) {
            return FALSE;
        }
    }
    return TRUE;
}

BOOL func_0203e688(void) {
    VramTransfer *t;
    int i;
    for (i = 0, t = data_02fe04f4; i < 64; i++, t++) {
        if (t->src != 0) {
            return FALSE;
        }
    }
    return TRUE;
}

void func_0203e6bc(void) {
    VramTransfer *t;
    u32 dst;
    u32 src;
    u32 off;
    VramTransfer *next;
    u32 n;
    int budget;
    int type;
    if (data_02fe04ec) {
        data_02fe04ec = 0;
        return;
    }
    t = data_02fe04f0;
    if (t == NULL) {
        return;
    }
    budget = 0x3000;
    for (; t != NULL; t = next) {
        n = t->chunk;
        next = t->next;
        type = t->type;
        off = t->progress;
        if (n > budget) {
            n = budget;
        }
        src = t->src;
        dst = t->dst;
        t->progress += n;
        if (t->progress >= t->size) {
            n += t->size - t->progress;
            VramTransfer_Unlink(t);
            if (t->used == 1) {
                VramTransfer_Release(t);
            }
        }
        switch (type) {
        case 0:
            GX_BeginLoadTex();
            GX_LoadTex(src + off, dst + off, n);
            GX_EndLoadTex();
            break;
        case 1:
            GX_BeginLoadTexPltt();
            GX_LoadTexPltt(src + off, dst + off, n);
            GX_EndLoadTexPltt();
            break;
        case 2:
            GX_LoadOBJ(src + off, dst + off, n);
            break;
        case 3:
            GX_LoadOBJPltt(src + off, dst + off, n);
            break;
        case 4:
            GX_BeginLoadOBJExtPltt();
            GX_LoadOBJExtPltt(src + off, dst + off, n);
            GX_EndLoadOBJExtPltt();
            break;
        case 5:
            GXS_LoadOBJ(src + off, dst + off, n);
            break;
        case 6:
            GXS_LoadOBJPltt(src + off, dst + off, n);
            break;
        case 7:
            GXS_BeginLoadOBJExtPltt();
            GXS_LoadOBJExtPltt(src + off, dst + off, n);
            GXS_EndLoadOBJExtPltt();
            break;
        }
        budget -= n;
        if (budget <= 0) {
            return;
        }
    }
}


extern u32 NNS_GfdAllocLnkTexVram(u32 size, int is4x4, int opt);
extern int NNS_GfdFreeLnkTexVram(u32 key);
extern u32 NNS_GfdAllocLnkPlttVram(u32 size, int is4pltt, int opt);
extern int NNS_GfdFreeLnkPlttVram(u32 key);

static inline NameNode *NamePool_Lookup(NamePool *pool) {
    NameNode *node = pool->usedList;
    if (node == NULL) {
        return NULL;
    }
    if (pool->value == 0x87654321) {
        return NULL;
    }
    for (; node != NULL; node = node->next) {
        if (node->hash == pool->hash && node->value == pool->value && STD_CompareString(node->name, pool->name) == 0) {
            node->refCount++;
            pool->name[0] = 0;
            pool->value = 0x87654321;
            pool->hash = 0;
            return node;
        }
    }
    return NULL;
}

u32 func_0203e8e0(u32 size, int is4x4, int opt) {
    NamePool *pool = data_02097de4;
    u32 key;
    if (pool != NULL) {
        NameNode *node = NamePool_Lookup(pool);
        if (node != NULL) {
            return node->key;
        }
    }
    key = NNS_GfdAllocLnkTexVram(size, is4x4, opt);
    if (key != 0) {
        data_02097d48->unk_024 += ((key & 0x7fff0000) >> 16) << 4;
        if (pool != NULL) {
            func_0203e1d0(pool, key);
        }
    }
    return key;
}

int func_0203ea00(u32 key) {
    int r;
    if (data_02097de4 != NULL && func_0203e25c(data_02097de4, key) != NULL) {
        return 0;
    }
    r = NNS_GfdFreeLnkTexVram(key);
    if (r != 0) {
        return r;
    }
    data_02097d48->unk_024 -= ((key & 0x7fff0000) >> 16) << 4;
    return r;
}

u32 func_0203ea6c(u32 size, int is4pltt, int opt) {
    NamePool *pool = data_02097dd8;
    u32 key;
    if (pool != NULL) {
        NameNode *node = NamePool_Lookup(pool);
        if (node != NULL) {
            return node->key;
        }
    }
    key = NNS_GfdAllocLnkPlttVram(size, is4pltt, opt);
    if (key != 0) {
        data_02097d48->unk_028 += ((key & 0xffff0000) >> 16) << 3;
        if (pool != NULL) {
            func_0203e1d0(pool, key);
        }
    }
    return key;
}

int func_0203eb8c(u32 key) {
    int r;
    if (data_02097dd8 != NULL && func_0203e25c(data_02097dd8, key) != NULL) {
        return 0;
    }
    r = NNS_GfdFreeLnkPlttVram(key);
    if (r != 0) {
        return r;
    }
    data_02097d48->unk_028 -= ((key & 0xffff0000) >> 16) << 3;
    return r;
}

u32 func_0203ebf8(void) {
    return data_02097ddc;
}

typedef struct ResTexInfo {
    /* 0x00 */ u32 vramKey;
    /* 0x04 */ u16 sizeTex;
    /* 0x06 */ u16 ofsDict;
    /* 0x08 */ u16 flag;
    /* 0x0a */ u16 pad;
    /* 0x0c */ u32 ofsTex;
} ResTexInfo;

typedef struct ResTex4x4Info {
    /* 0x00 */ u32 vramKey;
    /* 0x04 */ u16 sizeTex;
    /* 0x06 */ u16 ofsDict;
    /* 0x08 */ u16 flag;
    /* 0x0a */ u16 pad;
    /* 0x0c */ u32 ofsTex;
    /* 0x10 */ u32 ofsTexPlttIdx;
} ResTex4x4Info;

typedef struct ResTex {
    /* 0x00 */ u32 header[2];
    /* 0x08 */ ResTexInfo texInfo;
    /* 0x18 */ ResTex4x4Info tex4x4Info;
} ResTex;

void func_0203ec08(ResTex *tex) {
    u32 ofsPltt;
    u32 key;
    u32 size;
    u32 sz;
    u32 addr;
    u32 type;
    if (!(tex->texInfo.flag & 1)) {
        size = (u32)tex->texInfo.sizeTex << 3;
        if (size != 0) {
            data_02097ddc = func_0203e458(0, (u32)tex + tex->texInfo.ofsTex, (tex->texInfo.vramKey & 0xffff) << 3, size, 0);
            tex->texInfo.flag |= 1;
        }
    }
    if (tex->tex4x4Info.flag & 1) {
        return;
    }
    sz = (u32)tex->tex4x4Info.sizeTex << 3;
    if (sz == 0) {
        return;
    }
    ofsPltt = tex->tex4x4Info.ofsTexPlttIdx;
    key = tex->tex4x4Info.vramKey;
    type = 0;
    addr = (key & 0xffff) << 3;
    data_02097ddc = func_0203e458(type, (u32)tex + tex->tex4x4Info.ofsTex, addr, sz, type);
    data_02097de0 = func_0203e458(type, (u32)tex + ofsPltt, ((addr & 0x1ffff) >> 1) + 0x20000 + ((addr & 0x40000) >> 2), sz >> 1, type);
    tex->tex4x4Info.flag |= 1;
}


typedef struct ResTexFull {
    /* 0x00 */ u32 header[2];
    /* 0x08 */ ResTexInfo texInfo;
    /* 0x18 */ ResTex4x4Info tex4x4Info;
    /* 0x2c */ u32 plttKey;
    /* 0x30 */ u16 sizePltt;
    /* 0x32 */ u16 plttFlag;
    /* 0x34 */ u32 plttOfsDict;
    /* 0x38 */ u32 ofsPlttData;
} ResTexFull;

extern ResTexFull *NNS_G3dGetTex(void *res);
extern void *NNS_G3dGetMdlSet(void *res);
extern u32 NNS_G3dTexGetRequiredSize(ResTexFull *tex);
extern u32 NNS_G3dTex4x4GetRequiredSize(ResTexFull *tex);
extern u32 NNS_G3dPlttGetRequiredSize(ResTexFull *tex);
extern BOOL NNS_G3dBindMdlSet(void *mdl, ResTexFull *tex);
extern void func_020435e8(GfxPltt *pltt, void *src, u32 size);
extern u32 (*NNS_GfdDefaultFuncAllocTexVram)(u32 size, int is4x4, int opt);
extern u32 (*NNS_GfdDefaultFuncAllocPlttVram)(u32 size, int is4pltt, int opt);

static inline void NamePool_SetName(NamePool *pool, const char *name, u32 value) {
    if (pool == NULL) {
        return;
    }
    STD_CopyString(pool->name, name);
    pool->value = value;
    pool->hash = NamePool_Hash(name);
}

BOOL func_0203ed04(const char *name, u32 *res) {
    NamePool *pool = data_02097de4;
    if (pool != NULL) {
        NamePool_SetName(pool, name, 0);
        if (NamePool_Lookup(pool) != NULL) {
            return TRUE;
        }
    }
    switch (*res) {
    case 0x30444d42:
    case 0x30585442: {
        ResTexFull *tex = NNS_G3dGetTex(res);
        if (tex != NULL) {
            u32 texSize = NNS_G3dTexGetRequiredSize(tex);
            u32 tex4x4Size = NNS_G3dTex4x4GetRequiredSize(tex);
            u32 plttSize = NNS_G3dPlttGetRequiredSize(tex);
            if (texSize != 0) {
                tex->texInfo.vramKey = NNS_GfdDefaultFuncAllocTexVram(texSize, 0, 0);
            } else if (tex4x4Size != 0) {
                tex->tex4x4Info.vramKey = NNS_GfdDefaultFuncAllocTexVram(tex4x4Size, 1, 0);
            }
            if (plttSize != 0) {
                NamePool_SetName(data_02097dd8, name, 0);
                tex->plttKey = NNS_GfdDefaultFuncAllocPlttVram(plttSize, tex->tex4x4Info.flag & 0x8000, 0);
            }
            func_0203ec08((ResTex *)tex);
            if (!(tex->plttFlag & 1)) {
                u32 ofs;
                u32 size = (u32)tex->sizePltt << 3;
                if (size != 0) {
                    u32 key = tex->plttKey;
                    ofs = tex->ofsPlttData;
                    u32 addr = (key & 0xffff) << 3;
                    func_020435e8(&data_02097d48->pltt, (u8 *)tex + ofs, size);
                    data_02097dd4 = func_0203e458(1, (u32)tex + ofs, addr, size, 0);
                    tex->plttFlag |= 1;
                }
            }
            if (*res == 0x30444d42) {
                NNS_G3dBindMdlSet(NNS_G3dGetMdlSet(res), tex);
            }
        }
        return TRUE;
    }
    case 0x30414342:
    case 0x30414d42:
    case 0x30415442:
    case 0x30415642:
    case 0x30505442:
        return TRUE;
    default:
        return FALSE;
    }
}


extern void NNS_G3dReleaseMdlSet(void *mdl);
extern void (*NNS_GfdDefaultFuncFreeTexVram)(u32 key);
extern void (*NNS_GfdDefaultFuncFreePlttVram)(u32 key);

void func_0203f0b4(u32 *res) {
    switch (*res) {
    case 0x30444d42:
    case 0x30585442: {
        ResTexFull *tex = NNS_G3dGetTex(res);
        u32 plttKey;
        u32 tex4x4Key;
        u32 texKey;
        if (tex == NULL) {
            return;
        }
        texKey = tex->texInfo.vramKey;
        tex4x4Key = tex->tex4x4Info.vramKey;
        plttKey = tex->plttKey;
        if (data_02097de4 != NULL) {
            NameNode *node = NamePool_Find(data_02097de4, texKey);
            if (node != NULL) {
                if ((u32)node->refCount > 1) {
                    node->refCount--;
                    return;
                }
            }
        }
        if (*res == 0x30444d42) {
            NNS_G3dReleaseMdlSet(NNS_G3dGetMdlSet(res));
        }
        if (plttKey != 0) {
            tex->plttFlag &= ~1;
            tex->plttKey = 0;
            NNS_GfdDefaultFuncFreePlttVram(plttKey);
        }
        if (tex4x4Key != 0) {
            tex->tex4x4Info.flag &= ~1;
            tex->tex4x4Info.vramKey = 0;
            NNS_GfdDefaultFuncFreeTexVram(tex4x4Key);
        } else if (texKey != 0) {
            tex->texInfo.flag &= ~1;
            tex->texInfo.vramKey = 0;
            NNS_GfdDefaultFuncFreeTexVram(texKey);
        }
        break;
    }
    case 0x30414342:
    case 0x30414d42:
    case 0x30415442:
    case 0x30415642:
    case 0x30505442:
        break;
    }
}

}
