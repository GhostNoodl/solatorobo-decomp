// One source file for 0x02058d10..0x02062844: the data and flag resources, the object
// pool and the stage script interpreter. It is one translation unit because its string
// literals share one pool (0x0208bdec..0x0208be8c), and because the scalars at
// 0x02149efc..0x02149f14 are addressed from one .bss literal. The former files are kept
// as they were, each in its own namespace, so that their local typedefs, inlines and
// extern declarations do not clash.
#pragma pool_strings on
#pragma dont_reuse_strings off
#include "Main/Res/DataRes.h"
#include "Main/Gfx/TextWin.h"
#include "Main/Gfx/ObjPool.h"
#include "nitro/fx.h"
#include "Main/Sys/Field.h"
#include "Main/Res/StageRes.h"
#include "Main/Res/StageCmd.h"
#include "Main/Hit/HitSphere.h"
#define SND_DEFINE_GLOBALS
#include "Main/Snd/SndMgr.h"
#include "Main/Gfx/GfxMgr.h"

extern "C" {

int func_0205bef8(StageResSlot *slot);

// .data
int (*data_0208bde8)(StageResSlot *slot) = func_0205bef8;

// .bss, laid out in reverse order of definition from 0x02149efc.
s32 data_02149f14;
void *data_02149f10;
ObjPool *data_02149f0c;
u32 data_02149f08;
s32 data_02149f04;
void *data_02149f00;
u32 data_02149efc;
StageResSlot data_02149f18[0x40];

}

// ---- DataRes_2
namespace m_DataRes_2 {

extern "C" {

extern const u32 data_0208ba70[];

extern const u32 data_0208bbc8[];

extern const u32 data_0208bb1c[];

extern const u32 data_0208bf14[];

extern const u32 data_0208be94[];

extern DataRes *data_02fe1530;

extern DataRes *data_02fe152c;

int STD_TSPrintf(char *dst, const char *fmt, ...);

static inline BOOL TextWin_IsFlag29(TextWin *win) {
    return win->flag29 == 1 ? TRUE : FALSE;
}

static inline void DataRes_Reset(DataRes *res) {
    res->type = 0;
    res->data = NULL;
    res->end = NULL;
    res->unk_54 = 0;
}

static inline DataRes *DataRes_New(u32 size, const u32 *vtbl) {
    DataRes *res = (DataRes *)func_0203dd9c(size);
    if (res != NULL) {
        *(const u32 **)res = data_0208b318;
        res->Clear();
        *(const u32 **)res = vtbl;
        res->Clear();
    }
    return res;
}

static inline void DataRes_Open152c(const char *arcName, const char *name) {
    char arc[0x20];
    char file[0x20];
    func_0206e900(arc, arcName);
    func_0206e900(file, name);
    data_02fe152c->Open(arc, file);
}

static inline void DataRes_Open1530(const char *arcName, const char *name) {
    char arc[0x20];
    char file[0x20];
    func_0206e900(arc, arcName);
    func_0206e900(file, name);
    data_02fe1530->Open(arc, file);
}

static inline void DataRes_Open1530_18(const char *arcName, const char *name) {
    char arc[0x20];
    char file[0x20];
    func_0206e900(arc, arcName);
    func_0206e900(file, name);
    data_02fe1530->Open18(arc, file);
}

void func_02058d10(BOOL flag) {
    if (data_02fe1530 != NULL) {
        return;
    }
    data_02fe1530 = DataRes_New(0x54, data_0208bf14);
    if (flag) {
        DataRes_Open1530_18("script/cmninfo", "str.ccstr");
    } else {
        DataRes_Open1530("script/cmninfo", "str.ccstr");
    }
}

void func_02058e18(void) {
    void *heap = data_02097dd0->cur;
    data_02097dd0->cur = data_02097dd0->unk_08;
    if (data_02fe1530 != NULL) {
        if (data_02fe1530 != NULL) {
            data_02fe1530->DeletingDtor();
        }
        data_02fe1530 = NULL;
    }
    data_02097dd0->cur = heap;
}

DataRes *func_02058e74(DataRes *res) {
    *(const u32 **)res = data_0208bf14;
    res->Unload();
    *(const u32 **)res = data_0208b318;
    res->Unload();
    func_0203de1c(res);
    return res;
}

void func_02058ec0(DataRes *res) {
    res->type = 0;
    res->data = NULL;
    res->end = NULL;
}

void func_02058ed4(DataRes *res) {
    res->Clear();
}

BOOL func_02058ee8(DataRes *res) {
    u8 *data;
    if (res->loaded) {
        return TRUE;
    }
    data = *(u8 **)res->GetData();
    res->data = data;
    res->end = data + *(u32 *)(data + 8);
    res->loaded = TRUE;
    return TRUE;
}

// Never called, so the linker strips it, but its format string stays in the pool.
static void DataRes_FormatName(char *buf, const char *name, int idx) {
    STD_TSPrintf(buf, "%s_%.3d", name, idx);
}

void func_02058f2c(void) {
    if (data_02fe152c != NULL) {
        return;
    }
    data_02fe152c = DataRes_New(0x50, data_0208be94);
    DataRes_Open152c("script/cmninfo", "flg.ccflg");
}

}

}  // namespace m_DataRes_2

// ---- DataRes_3
namespace m_DataRes_3 {

extern "C" {

extern const u32 data_0208ba70[];

extern const u32 data_0208bbc8[];

extern const u32 data_0208bb1c[];

extern const u32 data_0208bf14[];

extern const u32 data_0208be94[];

extern DataRes *data_02fe1530;

extern DataRes *data_02fe152c;

static inline BOOL TextWin_IsFlag29(TextWin *win) {
    return win->flag29 == 1 ? TRUE : FALSE;
}

static inline void DataRes_Reset(DataRes *res) {
    res->type = 0;
    res->data = NULL;
    res->end = NULL;
    res->unk_54 = 0;
}

static inline DataRes *DataRes_New(u32 size, const u32 *vtbl) {
    DataRes *res = (DataRes *)func_0203dd9c(size);
    if (res != NULL) {
        *(const u32 **)res = data_0208b318;
        res->Clear();
        *(const u32 **)res = vtbl;
        res->Clear();
    }
    return res;
}

static inline void DataRes_Open152c(const char *arcName, const char *name) {
    char arc[0x20];
    char file[0x20];
    func_0206e900(arc, arcName);
    func_0206e900(file, name);
    data_02fe152c->Open(arc, file);
}

static inline void DataRes_Open1530(const char *arcName, const char *name) {
    char arc[0x20];
    char file[0x20];
    func_0206e900(arc, arcName);
    func_0206e900(file, name);
    data_02fe1530->Open(arc, file);
}

static inline void DataRes_Open1530_18(const char *arcName, const char *name) {
    char arc[0x20];
    char file[0x20];
    func_0206e900(arc, arcName);
    func_0206e900(file, name);
    data_02fe1530->Open18(arc, file);
}

void func_02058fe4(void) {
    void *heap = data_02097dd0->cur;
    data_02097dd0->cur = data_02097dd0->unk_08;
    if (data_02fe152c != NULL) {
        if (data_02fe152c != NULL) {
            data_02fe152c->DeletingDtor();
        }
        data_02fe152c = NULL;
    }
    data_02097dd0->cur = heap;
}

DataRes *func_02059040(DataRes *res) {
    *(const u32 **)res = data_0208be94;
    res->Unload();
    *(const u32 **)res = data_0208b318;
    res->Unload();
    func_0203de1c(res);
    return res;
}

void func_0205908c(DataRes *res) {
    res->type = 0;
    res->data = NULL;
}

void func_0205909c(DataRes *res) {
    res->Clear();
}

BOOL func_020590b0(DataRes *res) {
    if (res->loaded) {
        return TRUE;
    }
    res->data = *(u8 **)res->GetData();
    res->loaded = TRUE;
    return TRUE;
}


extern void MI_CpuFill8(void *dst, u32 value, u32 size);
extern void MI_CpuCopy8(const void *src, void *dst, u32 size);

u32 func_020590e8(DataRes *res, u8 *buf, u32 size) {
    SaveLayout *layout;
    u32 n;
    u32 pos;
    SaveBlock *b;
    u32 i;
    u8 *src;
    layout = (SaveLayout *)res->data;
    pos = 0;
    MI_CpuFill8(buf, 0, size);
    buf[pos++] = layout->count;
    for (i = 0; i < layout->count; i++) {
        b = &layout->blocks[i];
        n = ((b->bits + 7) & ~7) >> 3;
        if (pos + 2 < size) {
            buf[pos] = ((u8 *)&n)[0];
            buf[pos + 1] = ((u8 *)&n)[1];
        }
        pos += 2;
        src = (u8 *)layout->blocks + b->offset;
        if (pos + n < size) {
            MI_CpuCopy8(src, buf + pos, n);
        }
        pos += n;
    }
    return (pos + 1) & ~1;
}

u32 func_020591a4(DataRes *res, u8 *buf, BOOL keepSome) {
    SaveLayout *layout;
    u32 pos;
    u32 i;
    u32 n;
    u32 count;
    u8 stored;
    BOOL copy;
    layout = (SaveLayout *)res->data;
    pos = 0;
    count = layout->count;
    stored = buf[pos++];
    if (stored <= count) {
        count = stored;
    }
    for (i = 0; i < count; i++) {
        SaveBlock *b = &layout->blocks[i];
        u16 tmp;
        u32 bytes;
        u8 *dst;
        ((u8 *)&tmp)[0] = buf[pos];
        ((u8 *)&tmp)[1] = buf[pos + 1];
        bytes = ((b->bits + 7) & ~7) >> 3;
        pos += 2;
        n = tmp;
        if (n >= bytes) {
            n = bytes;
        }
        copy = TRUE;
        dst = (u8 *)layout->blocks + b->offset;
        if (keepSome && (i == 0 || i == 2 || i == 1 || i == 5)) {
            copy = FALSE;
        }
        if (copy) {
            MI_CpuCopy8(buf + pos, dst, n);
        }
        pos += n;
    }
    return (pos + 1) & ~1;
}

}

}  // namespace m_DataRes_3

// ---- DataRes_4
namespace m_DataRes_4 {

extern "C" {

u32 func_020591a4(DataRes *res, u8 *buf, BOOL keepSome);

u32 func_02059270(DataRes *res, u8 *buf) {
    return func_020591a4(res, buf, TRUE);
}

void func_02059280(DataRes *res, SaveRef *ref, u32 idx, u16 unk) {
    ref->idx = idx;
    ref->unk_04 = unk;
    ref->block = &((SaveLayout *)res->data)->blocks[idx];
    ref->table = (SaveEntry *)((u8 *)((SaveLayout *)res->data)->blocks + ((SaveLayout *)res->data)->blocks[idx].tableOffset);
    ref->count = ((SaveLayout *)res->data)->blocks[idx].count;
}

// Writes the low (packed & 0xff) bits of val, LSB first, starting at bit
// (packed >> 8) & 0xff past the entry's bit position in the block's data.
static inline void DataRes_WriteBitsAt(DataRes *res, SaveBlock *block, SaveEntry *entries, int packed, int sub, u16 val) {
    u8 *bytes;
    int n;
    int start;
    u16 i;
    start = ((packed >> 8) & 0xff) + entries[sub].bit;
    bytes = (u8 *)((SaveLayout *)res->data)->blocks + block->offset;
    n = packed & 0xff;
    for (i = 0; i < n; i++) {
        int pos = start + i;
        u8 v = (val >> i) & 1;
        u8 sh = pos & 7;
        u16 byte = pos >> 3;
        bytes[byte] &= ~(1 << sh);
        bytes[byte] |= v << sh;
    }
}

void func_020592c4(DataRes *res, u32 idx, int packed, int sub, u16 val) {
    SaveBlock *b = DataRes_Block(res, idx);
    SaveEntry *t = DataRes_Table(res, idx);
    DataRes_WriteBitsAt(res, b, t, packed, sub, val);
}

void func_02059360(DataRes *res, SaveBlock *block, SaveEntry *entries, int packed, u32 id, u16 val) {
    u16 i;
    int start;
    u8 *bytes;
    int n;
    for (i = 0; i < block->count; i++) {
        if (id == entries[i].id) {
            break;
        }
    }
    start = ((packed >> 8) & 0xff) + entries[i].bit;
    bytes = (u8 *)((SaveLayout *)res->data)->blocks + block->offset;
    n = packed & 0xff;
    for (i = 0; i < n; i++) {
        int pos = start + i;
        u8 v = (val >> i) & 1;
        u8 sh = pos & 7;
        u16 byte = pos >> 3;
        bytes[byte] &= ~(1 << sh);
        bytes[byte] |= v << sh;
    }
}

}

}  // namespace m_DataRes_4

// ---- DataRes_5
namespace m_DataRes_5 {

extern "C" {

void func_02059360(DataRes *res, SaveBlock *block, SaveEntry *entries, int packed, u32 id, u16 val);

void func_02059428(DataRes *res, SaveRef *ref, u32 id, u16 val) {
    func_02059360(res, ref->block, ref->table, ref->unk_04, id, val);
}

u16 func_02059454(DataRes *res, u32 idx, int n, int start) {
    u16 r;
    u16 i;
    u8 *bytes;
    bytes = (u8 *)((SaveLayout *)res->data)->blocks + ((SaveLayout *)res->data)->blocks[idx].offset;
    r = 0;
    for (i = 0; i < n; i++) {
        int pos = start + i;
        u16 byte = pos >> 3;
        u8 sh = pos & 7;
        u8 v = (bytes[byte] >> sh) & 1;
        r |= v << i;
    }
    return r;
}

// Reads (packed & 0xff) bits, LSB first, starting at bit (packed >> 8) & 0xff
// past the entry's bit position in the block's data.
static inline u16 DataRes_ReadBitsAt(DataRes *res, SaveBlock *block, SaveEntry *entries, int packed, int sub) {
    u16 r;
    int n;
    u8 *bytes;
    int start;
    u16 i;
    start = ((packed >> 8) & 0xff) + entries[sub].bit;
    bytes = (u8 *)((SaveLayout *)res->data)->blocks + block->offset;
    n = packed & 0xff;
    r = 0;
    for (i = 0; i < n; i++) {
        int pos = start + i;
        u16 byte = pos >> 3;
        u8 sh = pos & 7;
        u8 v = (bytes[byte] >> sh) & 1;
        r |= v << i;
    }
    return r;
}

// Same, for the entry whose id matches.
static inline u16 DataRes_ReadBitsById(DataRes *res, SaveBlock *block, SaveEntry *entries, int packed, u32 id) {
    u16 r;
    u16 i;
    int n;
    u8 *bytes;
    int start;
    for (i = 0; i < block->count; i++) {
        if (id == entries[i].id) {
            break;
        }
    }
    start = ((packed >> 8) & 0xff) + entries[i].bit;
    bytes = (u8 *)((SaveLayout *)res->data)->blocks + block->offset;
    n = packed & 0xff;
    r = 0;
    for (i = 0; i < n; i++) {
        int pos = start + i;
        u16 byte = pos >> 3;
        u8 sh = pos & 7;
        u8 v = (bytes[byte] >> sh) & 1;
        r |= v << i;
    }
    return r;
}

u16 func_020594bc(DataRes *res, u32 idx, int packed, int sub) {
    SaveBlock *b = DataRes_Block(res, idx);
    SaveEntry *t = DataRes_Table(res, idx);
    return DataRes_ReadBitsAt(res, b, t, packed, sub);
}

u16 func_02059544(DataRes *res, SaveBlock *block, SaveEntry *entries, int packed, u16 sub) {
    return DataRes_ReadBitsAt(res, block, entries, packed, sub);
}

u16 func_020595c4(DataRes *res, u32 idx, int packed, u32 id) {
    SaveBlock *b = DataRes_Block(res, idx);
    SaveEntry *t = DataRes_Table(res, idx);
    return DataRes_ReadBitsById(res, b, t, packed, id);
}

u16 func_02059688(DataRes *res, SaveBlock *block, SaveEntry *entries, int packed, u32 id) {
    return DataRes_ReadBitsById(res, block, entries, packed, id);
}

}

}  // namespace m_DataRes_5

// ---- DataRes_6
namespace m_DataRes_6 {

extern "C" {



u16 func_02059688(DataRes *res, SaveBlock *block, SaveEntry *entries, int packed, u32 id);

u16 func_0205973c(DataRes *res, SaveRef *ref, u32 id) {
    return func_02059688(res, ref->block, ref->table, ref->unk_04, id);
}

u32 func_0205975c(DataRes *res, u32 idx) {
    return ((SaveLayout *)res->data)->blocks[idx].count;
}

SaveEntry *func_0205976c(DataRes *res, u32 idx) {
    return (SaveEntry *)((u8 *)((SaveLayout *)res->data)->blocks + ((SaveLayout *)res->data)->blocks[idx].tableOffset);
}

typedef struct ResChunk {
    /* 0x00 */ u32 magic;
    /* 0x04 */ u32 next;
    /* 0x08 */ u32 dataOffset;
    /* 0x0c */ u32 count;
} ResChunk;

typedef struct ResFileHeader {
    /* 0x00 */ u32 magic;
    /* 0x04 */ u32 size;
    /* 0x08 */ u32 firstChunk;
} ResFileHeader;

BOOL func_02059784(PosEvRes *res) {
    ResFileHeader *hdr;
    ResChunk *chunk;
    u32 next;
    if (res->loaded) {
        return TRUE;
    }
    hdr = *(ResFileHeader **)res->GetData();
    if (hdr->size == 0) {
        return TRUE;
    }
    chunk = (ResChunk *)((u8 *)hdr + hdr->firstChunk);
    next = 0;
    res->posCount = 0;
    res->pos = NULL;
    if (chunk->magic == 0x534f5054) {
        res->posCount = chunk->count;
        res->pos = (u8 *)chunk + chunk->dataOffset;
        next = chunk->next;
    }
    res->evCount = 0;
    res->ev = NULL;
    chunk = (ResChunk *)((u8 *)chunk + next);
    if (chunk->magic == 0x50564554) {
        res->evCount = chunk->count;
        res->ev = (u8 *)chunk + chunk->dataOffset;
    }
    res->loaded = TRUE;
    return TRUE;
}

}

}  // namespace m_DataRes_6

// ---- ObjPool
namespace m_ObjPool {

extern "C" {

void func_0205983c(void) {
    ObjPool *pool;
    if (data_02149f0c != NULL) {
        return;
    }
    pool = (ObjPool *)func_0203dd9c(sizeof(ObjPool));
    if (pool != NULL) {
        ObjPool_Init(pool);
    }
    data_02149f0c = pool;
}

void func_020598a8(void) {
    void *saved = data_02097dd0->cur;
    data_02097dd0->cur = data_02097dd0->unk_08;
    {
        ObjPool *p = data_02149f0c;
        if (p != NULL) {
            if (p != NULL) {
                ObjPool_Reset(p);
                func_0203de1c(p);
            }
            data_02149f0c = NULL;
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

}  // namespace m_ObjPool

// ---- ObjPool_2
namespace m_ObjPool_2 {

typedef struct ObjPoolPlayer {
    /* 0x000 */ u8 unk_000[0xb2a];
    /* 0xb2a */ u8 flag0 : 1;
    /* 0xb2a */ u8 flag1 : 1;
    /* 0xb2a */ u8 flag2 : 1;
    /* 0xb2a */ u8 flag3 : 1;
    /* 0xb2a */ u8 flag4 : 1;
} ObjPoolPlayer;

extern "C" {

extern ObjPoolPlayer *func_ov000_0219bf90(void);
extern void func_ov000_02182590(u8 *p);

typedef struct ObjPoolVec {
    s32 x;
    s32 y;
    s32 z;
} ObjPoolVec;

extern void *data_ov000_021ccd68;
extern void *data_ov000_021ccd64;
extern void *func_ov000_0218e750(void *mgr, u16 kind, u16 id, s32 *pos, s32 r);
extern s32 func_ov000_0218c040(void *mgr, s32 max, ObjPoolVec *out, int kind, u16 id);

static inline void *ObjPool_FindObj(u16 kind, u16 id, s32 *pos, s32 r) {
    if (data_ov000_021ccd68 == NULL) {
        return NULL;
    }
    return func_ov000_0218e750(data_ov000_021ccd68, kind, id, pos, r);
}

static inline void ObjPool_Trigger(ObjPool *pool, ObjPoolEntry *entry) {
    entry->active |= 4;
    if (entry->active & 8) {
        data_02fe1534.unk_12 = entry->id;
    }
    if (entry->active & 2) {
        func_020599f4(pool, entry);
        data_02fe1534.unk_10 = entry->id;
        {
            u8 *p = &data_ov000_021ccd54->unk_0ac;
            *p = TRUE;
            func_ov000_02182590(p);
        }
        data_02fe1534.unk_10 = 0xffff;
    }
}

BOOL func_0205a028(ObjPool *pool, ObjPoolEntry *entry) {
    if (entry->unk_04 == 0) {
        ObjPoolVec *pos = (ObjPoolVec *)pool;
        s32 dy = entry->y - pos->y;
        s32 dx = entry->x - pos->x;
        s32 dz = entry->z - pos->z;
        if ((s32)(((s64)dx * dx + (s64)dy * dy + (s64)dz * dz + 0x800) >> 12) < entry->unk_1c) {
            ObjPool_Trigger(pool, entry);
            return TRUE;
        }
    } else {
        ObjPoolVec buf[16];
        BOOL found = FALSE;
        if (ObjPool_FindObj(entry->unk_04 << 12, entry->unk_06, &entry->x, entry->unk_18) != NULL) {
            found = TRUE;
        } else {
            s32 n = func_ov000_0218c040(data_ov000_021ccd64, 0x10, buf, entry->unk_04, entry->unk_06);
            s32 i;
            for (i = 0; i < n; i++) {
                s32 dx = entry->x - buf[i].x;
                s32 dy = entry->y - buf[i].y;
                s32 dz = entry->z - buf[i].z;
                if ((s32)(((s64)dx * dx + (s64)dy * dy + (s64)dz * dz + 0x800) >> 12) < entry->unk_1c) {
                    found = TRUE;
                }
            }
        }
        if (found) {
            ObjPool_Trigger(pool, entry);
            return TRUE;
        }
    }
    return FALSE;
}

BOOL func_0205a268(ObjPool *pool, ObjPoolEntry *entry) {
    ObjPoolPlayer *player = func_ov000_0219bf90();
    BOOL hit;
    if (player == NULL) {
        return FALSE;
    }
    hit = FALSE;
    if ((entry->active & 0x10) && player->flag0) {
        hit = TRUE;
    }
    if ((entry->active & 0x20) && player->flag1) {
        hit = TRUE;
    }
    if ((entry->active & 0x40) && player->flag2) {
        hit = TRUE;
    }
    if ((entry->active & 0x80) && player->flag3) {
        hit = TRUE;
    }
    if ((entry->active & 0x100) && player->flag4) {
        hit = TRUE;
    }
    if (!hit) {
        return FALSE;
    }
    func_020599f4(pool, entry);
    data_02fe1534.unk_10 = entry->id;
    {
        u8 *p = &data_ov000_021ccd54->unk_0ac;
        *p = TRUE;
        func_ov000_02182590(p);
    }
    data_02fe1534.unk_10 = 0xffff;
    return TRUE;
}

extern BOOL func_ov000_021b4738(ObjPoolPlayer *pl);

static inline BOOL ObjPool_InBox(ObjPoolEntry *e, s32 dx, s32 dy, s32 dz) {
    if (dx < 0) {
        dx = -dx;
    }
    if (dy < 0) {
        dy = -dy;
    }
    if (dz < 0) {
        dz = -dz;
    }
    return dx < e->unk_18 && dy < e->unk_1c && dz < e->unk_20;
}

static inline BOOL ObjPool_InBoxW(ObjPoolEntry *e, s32 dx, s32 dy, s32 dz, s32 w) {
    if (dx < 0) {
        dx = -dx;
    }
    if (dy < 0) {
        dy = -dy;
    }
    if (dz < 0) {
        dz = -dz;
    }
    return dx < w && dy < e->unk_1c && dz < e->unk_20;
}

static inline BOOL ObjPool_CheckBox(ObjPool *pool, ObjPoolEntry *entry) {
    if (entry->unk_04 == 0) {
        ObjPoolVec *pos = (ObjPoolVec *)pool;
        s32 dx = entry->x - pos->x;
        s32 dy = entry->y - pos->y;
        s32 dz = entry->z - pos->z;
        if (ObjPool_InBox(entry, dx, dy, dz)) {
            ObjPool_Trigger(pool, entry);
            return TRUE;
        }
    } else {
        ObjPoolVec buf[16];
        s32 n = func_ov000_0218c040(data_ov000_021ccd64, 0x10, buf, entry->unk_06 >> 12, entry->unk_06);
        s32 w;
        s32 z;
        s32 y;
        s32 x;
        s32 i;
        i = 0;
        if (i < n) {
            x = entry->x;
            y = entry->y;
            z = entry->z;
            w = entry->unk_18;
            do {
                s32 dx = x - buf[i].x;
                s32 dy = y - buf[i].y;
                s32 dz = z - buf[i].z;
                if (ObjPool_InBoxW(entry, dx, dy, dz, w)) {
                    ObjPool_Trigger(pool, entry);
                    return TRUE;
                }
            } while (++i < n);
        }
    }
    return FALSE;
}

void func_0205a358(ObjPool *pool) {
    ObjPoolEntry *next;
    ObjPoolEntry *e;
    if (*(s32 *)data_ov000_021ccd54 != 3) {
        return;
    }
    data_02fe1534.unk_10 = 0xffff;
    data_02fe1534.unk_12 = 0xffff;
    e = pool->head;
    if (e == NULL) {
        return;
    }
    do {
        next = e->next;
        if (e->b != data_02fe1534.b || e->g != data_02fe1534.g || e->r != data_02fe1534.r) {
            func_020599f4(pool, e);
        } else {
            ObjPoolPlayer *pl = func_ov000_0219bf90();
            if (pl != NULL && !func_ov000_021b4738(pl) && (e->active & 1)) {
                switch (e->kind) {
                case 1:
                    if (func_0205a028(pool, e)) {
                        return;
                    }
                    break;
                case 2:
                    if (ObjPool_CheckBox(pool, e)) {
                        return;
                    }
                    break;
                case 5:
                    if (func_0205a268(pool, e)) {
                        return;
                    }
                    break;
                }
                e->active &= ~4;
            }
        }
        e = next;
    } while (e != NULL);
}

}

}  // namespace m_ObjPool_2

// ---- StageRes
namespace m_StageRes {

extern "C" {

void func_0205a69c(void *p) {
}

void func_0205a6a0(StageRes *res) {
    res->type = 0;
    res->data = NULL;
    res->size = 0;
    res->unk_54 = 0;
    res->unk_58 = 0;
    res->unk_59 = 0;
    res->unk_5a = 0;
    res->unk_5b = 0;
    res->value = 0;
    res->condCount = 0;
    res->opCount = 0;
    res->unk_b2 = 0;
    res->varId = NULL;
    res->op = 0;
    res->sub = NULL;
    res->posEv = NULL;
}

void func_0205a6e8(StageRes *res) {
    s32 end;
    s32 i;
    i = data_02149f14;
    end = data_02149f04;
    while (i != end) {
        if (data_02149f18[i].res == res) {
            data_02149f18[i].res = NULL;
        }
        i++;
        if (i >= 0x40) {
            i = 0;
        }
    }
    func_02038520(res);
    if (res->posEv != NULL) {
        void *saved = data_02097dd0->cur;
        data_02097dd0->cur = data_02097dd0->unk_08;
        {
            PosEvRes *p = res->posEv;
            if (p != NULL) {
                if (p != NULL) {
                    p->DeletingDtor();
                }
                res->posEv = NULL;
            }
        }
        data_02097dd0->cur = saved;
    }
    if (res->sub != NULL) {
        void *saved = data_02097dd0->cur;
        data_02097dd0->cur = data_02097dd0->unk_08;
        {
            DataRes *p = res->sub;
            if (p != NULL) {
                if (p != NULL) {
                    p->DeletingDtor();
                }
                res->sub = NULL;
            }
        }
        data_02097dd0->cur = saved;
    }
    func_0205a6a0(res);
}

PosEvRes *func_0205a7f8(PosEvRes *res) {
    res->type = 0;
    res->posCount = 0;
    res->pos = NULL;
    res->evCount = 0;
    res->ev = NULL;
    *(const u32 **)res = data_0208b318;
    res->Unload();
    func_0203de1c(res);
    return res;
}

static inline void StageRes_OpenData(PosEvRes *res, const char *arcName, const char *name) {
    char arc[0x20];
    char file[0x20];
    func_0206e900(arc, arcName);
    func_0206e900(file, name);
    res->Open(arc, file);
}

void func_0205a840(StageRes *res, const char *arcName, const char *name) {
    char arc[0x20];
    char file[0x20];
    func_0206e900(arc, arcName);
    func_0206e900(file, name);
    func_02038b88(res, arc, file);
    if (res->sub == NULL) {
        DataRes *sub;
        STD_CopyString(file, name);
        STD_CopyString(STD_SearchString(file, "."), ".ccmes");
        sub = (DataRes *)func_0203dd9c(0x58);
        if (sub != NULL) {
            *(const u32 **)sub = data_0208b318;
            sub->Clear();
            *(const u32 **)sub = data_0208ba30;
            func_0204bfcc(sub);
        }
        res->sub = sub;
        func_0204bfe4(sub, arcName, file);
    }
    if (res->posEv == NULL) {
        PosEvRes *posEv;
        STD_CopyString(file, name);
        STD_CopyString(STD_SearchString(file, "."), ".cctmp");
        posEv = (PosEvRes *)func_0203dd9c(0x5c);
        if (posEv != NULL) {
            *(const u32 **)posEv = data_0208b318;
            posEv->Clear();
            *(const u32 **)posEv = data_0208bed4;
            posEv->type = 0;
            posEv->posCount = 0;
            posEv->pos = NULL;
            posEv->evCount = 0;
            posEv->ev = NULL;
        }
        res->posEv = posEv;
        StageRes_OpenData(posEv, arcName, file);
    }
}

BOOL func_0205a9c8(StageRes *res) {
    BOOL loaded = TRUE;
    if (!res->IsLoaded()) {
        loaded = FALSE;
    }
    if (res->sub != NULL && !res->sub->IsLoaded()) {
        loaded = FALSE;
    }
    if (res->posEv != NULL && !res->posEv->IsLoaded()) {
        loaded = FALSE;
    }
    return loaded;
}

BOOL func_0205aa30(StageRes *res) {
    u8 *hdr;
    if (res->loaded) {
        return TRUE;
    }
    hdr = *(u8 **)res->GetData();
    res->data = hdr + *(u32 *)(hdr + 0xc);
    res->size = *(u32 *)(hdr + 8);
    if (res->sub != NULL) {
        func_0204c030(res->sub);
    }
    if (res->posEv != NULL) {
        func_02059784(res->posEv);
    }
    res->loaded = TRUE;
    return TRUE;
}

u8 func_0205ae84(StageRes *res);
void func_0205af4c(StageRes *res, u16 val);

#define STAGE_SKIP 0x8fff

BOOL func_0205aa98(StageRes *res, BOOL force) {
    if (res->data == NULL) {
        return FALSE;
    }
    if (!force && !res->unk_58) {
        return FALSE;
    }
    res->unk_58 = 0;
    res->unk_5a = 0;
    data_02149f08 = 0;
    data_02149efc = 0;
    while (res->size > res->unk_54 * 2) {
        u16 *cmd = (u16 *)res->data + res->unk_54;
        u16 c = *cmd;
        switch (c & 0xff) {
        case 1:
            res->condCount = 0;
            res->opCount = 0;
            res->unk_54++;
            break;
        case 0x20:
            res->unk_54 += res->unk_vf3c(cmd);
            res->condStack[res->condCount++] = res->unk_5b;
            break;
        case 4:
            if (func_0205ae84(res)) {
                res->unk_54 += 2;
            } else {
                if (cmd[1] == 0) {
                    goto end;
                }
                res->unk_54 += cmd[1] >> 1;
            }
            res->varId = NULL;
            break;
        case 2:
            res->unk_54 += cmd[1] >> 1;
            break;
        case 3:
            res->unk_54++;
            break;
        case 5:
            res->unk_54 += res->Eval(cmd + 1, 0, 0);
            {
                u16 v = res->value;
                res->blockStack[res->unk_b2++] = v;
            }
            res->unk_54++;
            break;
        case 6: {
            u16 top = res->blockStack[res->unk_b2 - 1];
            u16 len = cmd[1];
            u16 skip;
            if (top == STAGE_SKIP) {
                skip = len / 2;
            } else {
                skip = res->Eval(cmd + 2, 0, 0) + 2;
                if (top == res->value) {
                    res->blockStack[res->unk_b2 - 1] = STAGE_SKIP;
                } else {
                    skip = len / 2;
                }
            }
            res->unk_54 += skip;
            break;
        }
        case 7: {
            u16 len = cmd[1];
            u16 skip = 2;
            if (res->blockStack[res->unk_b2 - 1] == STAGE_SKIP) {
                skip = len / 2;
            } else {
                res->blockStack[res->unk_b2 - 1] = STAGE_SKIP;
            }
            res->unk_54 += skip;
            break;
        }
        case 8:
            res->unk_b2--;
            res->unk_54++;
            break;
        case 0x10:
            res->opStack[res->opCount++] = c;
            res->unk_54++;
            break;
        case 0x11:
            res->opStack[res->opCount++] = c;
            res->unk_54++;
            break;
        case 0x12:
            res->opStack[res->opCount++] = c;
            res->unk_54++;
            break;
        case 0x30:
            res->condCount = 0;
            res->opCount = 0;
            res->varId = NULL;
            res->unk_59 = 0;
            res->unk_54 += res->unk_vf44(cmd);
            if (res->unk_59) {
                goto end;
            }
            if (res->unk_5a) {
                return TRUE;
            }
            break;
        case 0x40:
            res->condCount = 0;
            res->opCount = 0;
            if (res->varId == NULL) {
                res->unk_54 += res->Eval(cmd, 0, 0);
                res->varId = cmd;
            } else {
                u16 v = res->value;
                res->unk_54 += res->Eval(cmd, 0, 0);
                func_0205af4c(res, v);
                res->varId = NULL;
            }
            break;
        default:
            if (c >= 0x50 && c < 0x60) {
                res->op = c;
                res->unk_54++;
                break;
            }
            goto end;
        }
    }
end:
    res->unk_54 = 0;
    res->unk_b2 = 0;
    return TRUE;
}

}

}  // namespace m_StageRes
#undef STAGE_SKIP

// ---- StageRes_2
namespace m_StageRes_2 {

extern "C" {

static inline void StageRes_OpenData(PosEvRes *res, const char *arcName, const char *name) {
    char arc[0x20];
    char file[0x20];
    func_0206e900(arc, arcName);
    func_0206e900(file, name);
    res->Open(arc, file);
}

void func_0205ae68(void) {
    data_02149efc = 0;
}

u16 func_0205ae7c(StageRes *res) {
    return res->value;
}

u8 func_0205ae84(StageRes *res) {
    while (res->opCount != 0) {
        res->opCount--;
        switch (res->opStack[res->opCount]) {
        case 0x10:
            if (res->condCount >= 2) {
                res->condStack[res->condCount - 2] = res->condStack[res->condCount - 2] | res->condStack[res->condCount - 1];
                res->condCount--;
            }
            break;
        case 0x11:
            if (res->condCount >= 2) {
                res->condStack[res->condCount - 2] = res->condStack[res->condCount - 2] & res->condStack[res->condCount - 1];
                res->condCount--;
            }
            break;
        case 0x12:
            if (res->condCount >= 1) {
                res->condStack[res->condCount - 1] ^= 1;
            }
            break;
        }
    }
    if (res->condCount >= 2) {
        return 0;
    }
    return res->condStack[0];
}

void func_0205af4c(StageRes *res, u16 val) {
    switch (res->op) {
    case 0x50:
        val = res->value;
        break;
    case 0x51:
        val *= res->value;
        break;
    case 0x52:
        val /= res->value;
        break;
    case 0x53:
        val %= res->value;
        break;
    case 0x54:
        val += res->value;
        break;
    case 0x55:
        val -= res->value;
        break;
    case 0x56:
        val <<= res->value;
        break;
    case 0x57:
        val >>= res->value;
        break;
    case 0x58:
        val &= res->value;
        break;
    case 0x59:
        val |= res->value;
        break;
    case 0x5a:
        val ^= res->value;
        break;
    case 0x5b:
        val &= (u16)~res->value;
        break;
    default:
        return;
    }
    res->Eval(res->varId, 1, val);
}

u16 func_0205b068(StageRes *res, u16 *cmd, u16 val) {
    u16 op = cmd[0];
    BOOL result = FALSE;
    u16 len = 1;
    len += res->Eval(cmd + len, 0, 0);
    switch (op) {
    case 0x60:
        if (val == res->value) {
            result = TRUE;
        }
        break;
    case 0x61:
        if (val != res->value) {
            result = TRUE;
        }
        break;
    case 0x62:
        if (val <= res->value) {
            result = TRUE;
        }
        break;
    case 0x63:
        if (val >= res->value) {
            result = TRUE;
        }
        break;
    case 0x64:
        if (val < res->value) {
            result = TRUE;
        }
        break;
    case 0x65:
        if (val > res->value) {
            result = TRUE;
        }
        break;
    case 0x77:
        if (val & res->value) {
            result = TRUE;
        }
        break;
    case 0x78:
        if (val || res->value) {
            result = TRUE;
        }
        break;
    case 0x79:
        if (val ^ res->value) {
            result = TRUE;
        }
        break;
    case 0x7a:
        if (!(val & res->value)) {
            result = TRUE;
        }
        break;
    default:
        return len;
    }
    res->unk_5b = result;
    return len;
}

void func_0205b1b4(void) {
    data_0208bde8 = func_0205bef8;
    data_02149f14 = 0;
    data_02149f04 = 0;
    data_02149f08 = 0;
    data_02149efc = 0;
    MI_CpuFill8(data_02149f18, 0, sizeof(data_02149f18));
}

}

}  // namespace m_StageRes_2

// ---- StageRes_3
namespace m_StageRes_3 {

extern "C" {

static inline void StageRes_OpenData(PosEvRes *res, const char *arcName, const char *name) {
    char arc[0x20];
    char file[0x20];
    func_0206e900(arc, arcName);
    func_0206e900(file, name);
    res->Open(arc, file);
}

static inline BOOL StageRes_IsBusy(void) {
    return data_02149f08 != 0;
}

BOOL func_0205b1fc(void) {
    if (StageRes_IsBusy()) {
        return FALSE;
    }
    return data_02149f14 != data_02149f04;
}

StageResSlot *func_0205b23c(u16 id) {
    s32 i;
    s32 end;
    StageResSlot *slot;
    end = data_02149f04;
    i = data_02149f14;
    if (i == end) {
        return NULL;
    }
    do {
        slot = &data_02149f18[i];
        if (slot->id == id) {
            return slot;
        }
        i++;
        if (i >= 0x40) {
            i = 0;
        }
    } while (i != end);
    return NULL;
}

StageResSlot *func_0205b29c(u16 *ids) {
    StageResSlot *slot;
    s32 i;
    s32 end;
    u16 *p;
    end = data_02149f04;
    i = data_02149f14;
    if (i == data_02149f04) {
        return NULL;
    }
    do {
        slot = &data_02149f18[i];
        p = ids;
        while (*p != 0) {
            if (slot->id == *p++) {
                return slot;
            }
        }
        i++;
        if (i >= 0x40) {
            i = 0;
        }
    } while (i != end);
    return NULL;
}

}

}  // namespace m_StageRes_3

// ---- StageRes_4
namespace m_StageRes_4 {

extern "C" {

static inline void StageRes_OpenData(PosEvRes *res, const char *arcName, const char *name) {
    char arc[0x20];
    char file[0x20];
    func_0206e900(arc, arcName);
    func_0206e900(file, name);
    res->Open(arc, file);
}

static inline BOOL StageRes_IsBusy(void) {
    return data_02149f08 != 0;
}

StageResSlot *func_0205b31c(void) {
    if (data_02149f14 == data_02149f04) {
        return NULL;
    }
    return &data_02149f18[data_02149f14];
}

void func_0205b348(void) {
    if (data_02149f14 == data_02149f04) {
        return;
    }
    data_02149f14++;
    if (data_02149f14 >= 0x40) {
        data_02149f14 = 0;
    }
}

StageResSlot *func_0205b378(BOOL pop) {
    s32 end = data_02149f04;
    if (data_02149f14 == end) {
        return NULL;
    }
    if (pop) {
        end -= pop;
        if (end < 0) {
            end += 0x40;
        }
        data_02149f04 = end;
    } else {
        end -= 1;
        if (end < 0) {
            end += 0x40;
        }
    }
    return &data_02149f18[end];
}


u16 func_0205b3cc(StageRes *res, u16 id, u32 argc, u16 *cmd) {
    StageResSlot *slot = Slot_Alloc();
    u16 len;
    u16 i;
    slot->res = res;
    slot->unk_04 = 0;
    slot->id = id;
    len = 1;
    for (i = 0; i < argc; i++) {
        len += res->Eval(cmd + len, 0, 0);
        slot->args[i] = res->value;
    }
    return len;
}

BOOL func_0205b4ac(void) {
    s32 n;
    StageResSlot *slot = StageRes_Peek();
    if (slot == NULL) {
        return FALSE;
    }
    n = 1;
    while (n-- != 0) {
        if (data_0208bde8 != NULL) {
            int r = data_0208bde8(slot);
            if (r == -0x62) {
                n++;
            } else {
                if (r != -0x63) {
                    StageRes_Pop();
                }
                n += r;
            }
        }
        if (n < 1) {
            break;
        }
        slot = StageRes_Peek();
        if (slot == NULL) {
            break;
        }
    }
    return TRUE;
}

u16 func_0205b068(StageRes *res, u16 *cmd, u16 val);

// Reads n bits, LSB first, from bit `start` of block idx's data (an inlined func_02059454).
static inline u16 DataRes_ReadBits(DataRes *res, u32 idx, s32 n, u16 start) {
    u16 r;
    u16 i;
    u8 *bytes;
    bytes = (u8 *)((SaveLayout *)res->data)->blocks + ((SaveLayout *)res->data)->blocks[idx].offset;
    r = 0;
    for (i = 0; i < n; i++) {
        int pos = start + i;
        u16 byte = pos >> 3;
        u8 sh = pos & 7;
        u8 v = (bytes[byte] >> sh) & 1;
        r |= v << i;
    }
    return r;
}

u16 func_0205b588(StageRes *res, u16 *cmd) {
    u16 len = 2;
    switch (cmd[1]) {
    case 1:
        len++;
        return func_0205b068(res, cmd + len, ((u16 *)&data_02fe1534)[cmd[2]]) + len;
    case 2: {
        u16 val;
        u16 v = cmd[2];
        int n = v & 0xff;
        val = DataRes_ReadBits(data_02fe152c, (v & 0xff00) >> 8, n, cmd[3]);
        len += 2;
        return func_0205b068(res, cmd + len, val) + len;
    }
    }
    res->unk_5b = 0;
    return len;
}

// Writes n bits of val, LSB first, from bit `start` of block idx's data.
static inline void DataRes_WriteBits(DataRes *res, u32 idx, s32 n, u16 start, u16 val) {
    u8 *bytes;
    u16 i;
    bytes = (u8 *)((SaveLayout *)res->data)->blocks + ((SaveLayout *)res->data)->blocks[idx].offset;
    for (i = 0; i < n; i++) {
        int pos = start + i;
        u8 v = (val >> i) & 1;
        u16 byte = pos >> 3;
        u8 sh = pos & 7;
        bytes[byte] &= ~(1 << sh);
        bytes[byte] |= v << sh;
    }
}

#define STAGE_VARS ((u16 *)&data_02fe1534)

u16 func_0205b68c(StageRes *res, u16 *cmd, BOOL set, u16 value) {
    u16 type = cmd[1];
    u16 len = 2;
    if (!set) {
        switch (type) {
        case 1:
            res->value = STAGE_VARS[cmd[2]];
            len++;
            break;
        case 2: {
            u16 v = cmd[2];
            int n = v & 0xff;
            res->value = DataRes_ReadBits(data_02fe152c, (v & 0xff00) >> 8, n, cmd[3]);
            len += 2;
            break;
        }
        case 3:
            len++;
            res->value = cmd[2];
            break;
        }
    } else {
        switch (type) {
        case 1: {
            u16 idx = cmd[2];
            if (idx < 0x38) {
                data_02149efc++;
            }
            if (STAGE_VARS[0] != 1) {
                STAGE_VARS[idx] = value;
            } else if (idx >= 0x38 && idx <= 0x3b) {
                STAGE_VARS[cmd[2]] = value;
            }
            len++;
            break;
        }
        case 2:
            data_02149efc++;
            if (STAGE_VARS[0] != 1) {
                u16 v = cmd[2];
                int n = v & 0xff;
                DataRes_WriteBits(data_02fe152c, (v & 0xff00) >> 8, n, cmd[3], value);
            }
            len += 2;
            break;
        case 3:
            len++;
            break;
        }
    }
    return len;
}

}

}  // namespace m_StageRes_4
#undef STAGE_VARS

// ---- StageRes_5
namespace m_StageRes_5 {

extern "C" {

extern void func_0205ae68(void);
extern u16 func_0205ae7c(StageRes *res);
extern void func_0205beb0(void);
extern void func_0205bec8(u16 id);
extern void func_0205bee4(void);
extern int func_0205bf70(StageResSlot *slot);
extern int func_0205c37c(StageResSlot *slot);
extern int func_0205c490(StageResSlot *slot);
extern int func_0205c5c4(StageResSlot *slot);
extern int func_0205c624(StageResSlot *slot);
extern int func_0205de88(StageResSlot *slot);
extern int func_0205e19c(StageResSlot *slot);
extern int func_0205e29c(StageResSlot *slot);
extern int func_0205eda0(StageResSlot *slot);
extern int func_0205f354(StageResSlot *slot);
extern int func_0205f978(StageResSlot *slot);
extern int func_020616b0(StageResSlot *slot);
extern int func_02061c8c(StageResSlot *slot);
extern s32 func_02040498(s32 max);
extern u16 func_0205b3cc(StageRes *res, u16 id, u32 argc, u16 *cmd);
extern StageResSlot *func_0205b378(BOOL pop);

void func_0205b8c4(void) {
    data_02149efc++;
}

u16 func_0205b8dc(StageRes *res, u16 *cmd) {
    u16 op = cmd[1];
    u16 argc = (op & 0xff00) >> 8;
    u16 len = 1;
    if (op == 0xff) {
        res->unk_59 = 1;
        return 2;
    }
    if (op == 0xf3) {
        res->unk_5a = 1;
        return 2;
    }
    func_0205b8c4();
    if (data_02fe1534.unk_00 == 1) {
        len += func_0205b3cc(res, op, argc, cmd + 1);
        func_0205b378(TRUE);
        return len;
    }
    switch (op) {
    case 0x100:
        len++;
        len += res->Eval(cmd + 2, 0, 0);
        *(u16 *)data_02fe1534.unk_02 = func_0205ae7c(res);
        break;
    case 0x101:
        len++;
        len += res->Eval(cmd + 2, 0, 0);
        *(u16 *)&data_02fe1534.unk_08[0] = func_0205ae7c(res);
        *(u16 *)&data_02fe1534.unk_08[2] = 0;
        break;
    case 0x102:
        len += func_0205b3cc(res, op, argc, cmd + 1);
        func_0205bf70(func_0205b378(TRUE));
        break;
    case 0x209:
        len += func_0205b3cc(res, op, argc, cmd + 1);
        func_0205c37c(NULL);
        break;
    case 0x20a:
        len += func_0205b3cc(res, op, argc, cmd + 1);
        func_0205c490(NULL);
        break;
    case 0x20c:
        len += func_0205b3cc(res, op, argc, cmd + 1);
        func_0205c5c4(func_0205b378(TRUE));
        break;
    case 0x20e:
        len += func_0205b3cc(res, op, argc, cmd + 1);
        func_0205c624(func_0205b378(TRUE));
        break;
    case 0x11:
        len++;
        func_0205beb0();
        break;
    case 0x23a:
        len += func_0205b3cc(res, op, argc, cmd + 1);
        func_0205e19c(func_0205b378(TRUE));
        break;
    case 0x43b:
        len += func_0205b3cc(res, op, argc, cmd + 1);
        func_0205e29c(func_0205b378(TRUE));
        break;
    case 0x243:
        len += func_0205b3cc(res, op, argc, cmd + 1);
        func_0205eda0(func_0205b378(TRUE));
        break;
    case 0x347:
        len += func_0205b3cc(res, op, argc, cmd + 1);
        func_0205f354(func_0205b378(TRUE));
        break;
    case 0x14c:
        len += func_0205b3cc(res, op, argc, cmd + 1);
        func_0205f978(func_0205b378(TRUE));
        break;
    case 0x32:
        len += func_0205b3cc(res, op, argc, cmd + 1);
        break;
    case 0x136:
        len += func_0205b3cc(res, op, argc, cmd + 1);
        func_0205de88(func_0205b378(TRUE));
        break;
    case 0x17d:
        len += func_0205b3cc(res, op, argc, cmd + 1);
        func_0205bec8(func_0205b378(TRUE)->args[0]);
        break;
    case 0x16f:
        len += func_0205b3cc(res, op, argc, cmd + 1);
        func_020616b0(func_0205b378(TRUE));
        break;
    case 0x280:
        len += func_0205b3cc(res, op, argc, cmd + 1);
        func_02061c8c(func_0205b378(TRUE));
        break;
    case 0x1f0:
        len++;
        len += res->Eval(cmd + 2, 0, 0);
        *(u16 *)data_02fe1534.unk_7e = func_02040498(func_0205ae7c(res));
        break;
    case 0xf1:
        len++;
        func_0205bee4();
        break;
    case 0xf2:
        len++;
        func_0205ae68();
        break;
    default:
        len += func_0205b3cc(res, op, argc, cmd + 1);
        break;
    }
    if (op == 0x237 || op == 0x27f) {
        res->unk_5a = 1;
    }
    return len;
}

}

}  // namespace m_StageRes_5

// ---- StageCmd_0
namespace m_StageCmd_0 {

extern "C" {

extern void *data_ov008_021d0500;
extern void func_ov008_021cf9b8(void *m, u32 id);

void func_0205beb0(void) {
    data_ov000_021ccd54->unk_0c8 = TRUE;
}

void func_0205bec8(u16 id) {
    func_ov008_021cf9b8(data_ov008_021d0500, id);
}

}

}  // namespace m_StageCmd_0

// ---- StageCmd
namespace m_StageCmd {

extern "C" {

void func_0205bee4(void) {
    data_02149f08 = 1;
}

int func_0205bef8(StageResSlot *slot) {
    u8 cmd = slot->id;
    if (Field_HasEvent(0x15)) {
        return -0x63;
    }
    return data_0208bf9c[cmd](slot);
}

int func_0205bf70(StageResSlot *slot) {
    u16 a = slot->args[0];
    if (a == 0xffff) {
        data_0214a424->unk_518_8 = 0;
    } else {
        data_0214a424->unk_518_8 = (u16)((u16)(a & ~0x8000) + 1);
    }
    return 0;
}

int func_0205bfdc(StageResSlot *slot) {
    FieldState *state = data_ov000_021ccd54;
    if (Field_IsEventPending(state)) {
        return -0x63;
    }
    func_ov000_021865f8(state);
    return 0;
}

int func_0205c018(StageResSlot *slot) {
    FieldState *state = data_ov000_021ccd54;
    if (Field_IsEventPending(state)) {
        return -0x63;
    }
    func_ov000_02186bb0(state);
    return 0;
}

int func_0205c054(StageResSlot *slot) {
    FieldState *state = data_ov000_021ccd54;
    if (Field_IsEventPending(state)) {
        return -0x63;
    }
    {
        u16 a = slot->args[1];
        StageRes *res = slot->res;
        u16 id = a & ~0x8000;
        u16 g = (a >> 12) & 8;
        func_ov000_0218547c(state, slot->args[0], g ? data_02149ef8 : (void *)res->sub, id);
    }
    return 0;
}

int func_0205c0cc(StageResSlot *slot) {
    FieldState *state = data_ov000_021ccd54;
    if (Field_IsEventPending(state)) {
        return -0x63;
    }
    {
        u16 a = slot->args[0];
        StageRes *res = slot->res;
        u16 id = a & ~0x8000;
        u16 g = (a >> 12) & 8;
        func_ov000_021854d4(state, g ? data_02149ef8 : (void *)res->sub, id);
    }
    return 0;
}

int func_0205c140(StageResSlot *slot) {
    u32 v;
    if (Field_IsEventPending(data_ov000_021ccd54)) {
        return -0x63;
    }
    v = !slot->bits.flag9 ? data_02082a28[slot->args[0]] : slot->args[0];
    if (v & 0x8000) {
        u16 a = slot->args[1];
        StageRes *res = slot->res;
        u16 id = a & ~0x8000;
        u16 g = (a >> 12) & 8;
        func_ov000_02172264(data_ov000_021ccd30, v, id, g ? data_02149ef8 : (void *)res->sub);
    } else {
        func_ov000_02172264(data_ov000_021ccd30, v, slot->args[1], NULL);
    }
    Field_PushEvent(data_ov000_021ccd54, 0x13, 0);
    return 0;
}

void func_0205c234(u16 a, u16 b) {
    s32 end;
    StageResSlot *slot;
    end = data_02149f04;
    slot = &data_02149f18[end];
    end++;
    data_02149f04 = end;
    if (end >= 0x40) {
        end = 0;
        data_02149f04 = end;
    }
    Slot_Init(slot);
    slot->res = NULL;
    slot->unk_04 = 0;
    slot->id = 0x207;
    slot->args[0] = a;
    slot->args[1] = b;
    slot->args[2] = 0;
    slot->args[3] = 0;
    slot->args[4] = 0;
    slot->args[5] = 0;
    StageRes_Last()->bits.flag9 = 1;
}

}

}  // namespace m_StageCmd

// ---- StageCmd_2
namespace m_StageCmd_2 {

extern "C" {

int func_0205c2fc(StageResSlot *slot) {
    u16 id = slot->args[0];
    switch ((s32)(((u32)id << 4) >> 16) - 1) {
    case 0:
        return 1;
    case 1:
        if (!func_0206f21c(id, 1)) {
            func_ov000_02184ea4(data_ov000_021ccd54, id);
        }
        break;
    case 3:
    case 4:
    case 5:
        func_0206f5e4(id, 1);
        break;
    }
    return 1;
}

int func_0205c37c(StageResSlot *slot) {
    if (slot == NULL) {
        if (StageRes_Last()->args[0] == 2) {
            data_02fe1534.unk_70 = data_0214a424->unk_020;
            if (data_02149f14 != data_02149f04) {
                s32 end = data_02149f04 - 1;
                if (end < 0) {
                    end += 0x40;
                }
                data_02149f04 = end;
            }
        }
        return 1;
    }
    if (slot->args[0] == 0) {
        {
            StageFlags *f = data_0214a424;
            f->unk_020 += slot->args[1];
            if (f->unk_020 > 99999) {
                f->unk_020 = 99999;
            }
        }
        {
            u32 v;
            StageFlags *f;
            v = slot->args[1];
            f = data_0214a424;
            if (f->unk_00c + v >= 999999) {
                f->unk_00c = 999999;
            } else {
                f->unk_00c = f->unk_00c + v;
            }
        }
    } else if (slot->args[0] == 1) {
        u16 x = slot->args[1];
        StageFlags *f = data_0214a424;
        f->unk_020 = f->unk_020 > x ? f->unk_020 - x : 0;
    }
    return 1;
}

int func_0205c490(StageResSlot *slot) {
    if (slot == NULL) {
        if (StageRes_Last()->args[0] == 2) {
            data_02fe1534.unk_70 = data_0214a424->unk_024;
            if (data_02149f14 != data_02149f04) {
                s32 end = data_02149f04 - 1;
                if (end < 0) {
                    end += 0x40;
                }
                data_02149f04 = end;
            }
        }
        return 1;
    }
    if (slot->args[0] == 0) {
        StageFlags *f = data_0214a424;
        f->unk_024 += slot->args[1];
        if (f->unk_024 > 9999) {
            f->unk_024 = 9999;
        }
    } else if (slot->args[0] == 1) {
        u16 x = slot->args[1];
        StageFlags *f = data_0214a424;
        f->unk_024 = f->unk_024 > x ? f->unk_024 - x : 0;
    }
    return 1;
}

int func_0205c580(StageResSlot *slot) {
    FieldState *state = data_ov000_021ccd54;
    if (Field_IsEventPending(state)) {
        return -0x63;
    }
    func_ov000_02184bb0(state, slot->args[0]);
    return 1;
}

int func_0205c5c4(StageResSlot *slot) {
    func_ov000_021762e4(slot->args[0], slot->args[1]);
    return 1;
}

int func_0205c5e0(StageResSlot *slot) {
    FieldState *state = data_ov000_021ccd54;
    if (Field_IsEventPending(state)) {
        return -0x63;
    }
    func_ov000_02184d90(state, slot->args[0]);
    return 1;
}

int func_0205c624(StageResSlot *slot) {
    func_ov000_0214e7ac(slot->args[0]);
    return 1;
}

int func_0205c638(StageResSlot *slot) {
    u8 buf[3];
    buf[0] = slot->args[0];
    buf[1] = slot->args[1];
    buf[2] = slot->args[2];
    func_ov000_02188d28(buf);
    return 1;
}

int func_0205c664(StageResSlot *slot) {
    u8 buf[3];
    if (Field_HasEvent(0x1b) || Field_HasEvent(0x1c) || Field_HasEvent(0x16) || Field_HasEvent(4)) {
        return -0x63;
    }
    buf[0] = slot->args[0];
    buf[1] = slot->args[1];
    buf[2] = slot->args[2];
    func_ov000_02188ca0(buf, 1);
    return 1;
}

typedef struct StagePos {
    /* 0x0 */ s16 x;
    /* 0x2 */ s16 y;
    /* 0x4 */ s16 z;
} StagePos;

int func_0205c7cc(StageResSlot *slot) {
    u16 a = slot->args[0];
    StageRes *res = slot->res;
    if (a & 0x8000) {
        u16 idx = a & 0x7fff;
        StagePos *pos = &((StagePos *)res->posEv->pos)[idx];
        data_02fe1534.posFlags |= 1;
        data_02fe1534.posX = pos->x;
        data_02fe1534.posY = pos->y;
        data_02fe1534.posZ = pos->z;
    }
    return 1;
}

typedef struct StageCamera {
    virtual void Update();
    /* 0x04 */ u8 unk_04[0x98];
    /* 0x9c */ u8 active : 1;
    /* 0x9c */ u8 unk_9c_1 : 7;
    /* 0x9d */ u8 unk_9d[0x3d];
    /* 0xda */ u8 unk_da_0 : 2;
    /* 0xda */ u8 mode : 2;
    /* 0xda */ u8 axisX : 1;
    /* 0xda */ u8 axisY : 1;
    /* 0xda */ u8 axisZ : 1;
    /* 0xda */ u8 unk_da_7 : 1;
    /* 0xdb */ u8 unk_db[0x19];
    /* 0xf4 */ s32 z;
    /* 0xf8 */ u16 x;
    /* 0xfa */ u16 y;
    /* 0xfc */ u16 w;
} StageCamera;

int func_0205c83c(StageResSlot *slot) {
    u16 a = slot->args[0];
    StageRes *res = slot->res;
    u16 x;
    u16 y;
    u16 w;
    s32 z;
    if (a & 0x8000) {
        u16 idx = a & 0x7fff;
        StagePos *pos = &((StagePos *)res->posEv->pos)[idx];
        w = 0;
        x = pos->x;
        y = pos->y;
        z = pos->z;
    } else {
        x = 0;
        y = 0;
        w = 0;
        z = 0;
    }
    if (data_ov000_021ccd6c->unk_0a == 0xff) {
        StageCamera *cam = (StageCamera *)((u8 *)data_ov000_021ccd54 + 0xf4);
        cam->x = x;
        cam->y = y;
        cam->w = w;
        cam->axisX = 1;
        cam->axisY = 1;
        cam->axisZ = 1;
        cam->z = z;
        cam->mode = 1;
        cam->active = 0;
        cam->Update();
        cam->active = 1;
    } else {
        if (x != 0) {
            data_02fe1534.posFlags |= 2;
            data_02fe1534.unk_3c = x;
        }
        if (y != 0) {
            data_02fe1534.posFlags |= 4;
            data_02fe1534.unk_3e = y;
        }
        if (z != 0) {
            data_02fe1534.posFlags |= 8;
            data_02fe1534.unk_40 = z;
        }
    }
    return 1;
}

typedef struct StageCamRot {
    u16 v[3];
} StageCamRot;

typedef struct StageVecA {
    s32 v[3];
} StageVecA;

typedef struct StageFieldCam {
    virtual void Update();
    /* 0x04 */ u8 unk_04[0x98];
    /* 0x9c */ u8 active : 1;
    /* 0x9c */ u8 unk_9c_1 : 7;
    /* 0x9d */ u8 unk_9d[0x3d];
    /* 0xda */ u8 unk_da_0 : 1;
    /* 0xda */ u8 hasTarget : 1;
    /* 0xda */ u8 mode : 2;
    /* 0xda */ u8 axisX : 1;
    /* 0xda */ u8 axisY : 1;
    /* 0xda */ u8 axisZ : 1;
    /* 0xda */ u8 unk_da_7 : 1;
    /* 0xdb */ u8 unk_db[0xd];
    /* 0xe8 */ StageVec target;
    /* 0xf4 */ s32 z;
    /* 0xf8 */ u16 x;
    /* 0xfa */ u16 y;
} StageFieldCam;

typedef struct StageFieldCamState {
    /* 0x000 */ u8 unk_000[0xd3];
    /* 0x0d3 */ u8 camSet;
    /* 0x0d4 */ u8 unk_0d4[4];
    /* 0x0d8 */ StageVec camPos;
    /* 0x0e4 */ StageCamRot camRot;
    /* 0x0ec */ s32 camDist;
    /* 0x0f0 */ u16 camScale;
    /* 0x0f4 */ StageFieldCam cam;
} StageFieldCamState;

typedef struct StageFieldPlayerPos {
    /* 0x000 */ u8 unk_000[0x104];
    /* 0x104 */ StageVec pos;
} StageFieldPlayerPos;

typedef struct StageCamInfo {
    StageCamRot rot;
    StageVec pos;
} StageCamInfo;

int func_0205c968(StageResSlot *slot) {
    StageCamInfo info;
    s32 dist;
    u16 a;
    StageRes *res;
    StageFieldCamState *st;
    if (Field_IsEventPending(data_ov000_021ccd54)) {
        return -0x63;
    }
    a = slot->args[0];
    dist = 0;
    info.pos.x = 0;
    info.pos.y = 0;
    info.pos.z = 0;
    info.rot.v[0] = 0;
    info.rot.v[1] = 0;
    info.rot.v[2] = 0;
    res = slot->res;
    if (a == 0x1000) {
        StageVec *pp = &((StageFieldPlayerPos *)data_ov000_021ccd54)->pos;
        info.pos.x = pp->x;
        info.pos.y = pp->y;
        info.pos.z = pp->z;
    } else if (a & 0x8000) {
        StagePos *p = &((StagePos *)res->posEv->pos)[(u16)(a & 0x7fff)];
        info.pos.x = p->x << 4;
        info.pos.y = p->y << 4;
        info.pos.z = p->z << 4;
    } else {
        StageObj3D *obj;
        if (data_ov000_021ccd68 == NULL) {
            obj = NULL;
        } else {
            obj = (StageObj3D *)func_ov000_0218e6d0(data_ov000_021ccd68, a & 0xf000, a);
        }
        if (obj != NULL) {
            info.pos.x = obj->pos.x;
            info.pos.y = obj->pos.y;
            info.pos.z = obj->pos.z;
        } else {
            return 1;
        }
    }
    a = slot->args[1];
    if (a & 0x8000) {
        StagePos *p = &((StagePos *)res->posEv->pos)[(u16)(a & 0x7fff)];
        info.rot.v[0] = p->x;
        info.rot.v[1] = p->y;
        info.rot.v[2] = 0;
        dist = p->z << 4;
    }
    st = (StageFieldCamState *)data_ov000_021ccd54;
    st->camSet = 1;
    st->camPos.x = info.pos.x;
    st->camPos.y = info.pos.y;
    st->camPos.z = info.pos.z;
    st->camRot = info.rot;
    st->camDist = dist;
    st->camScale = 0x1000;
    st->cam.target.x = info.pos.x;
    st->cam.target.y = info.pos.y;
    st->cam.target.z = info.pos.z;
    st->cam.hasTarget = 1;
    st->cam.x = st->camRot.v[0];
    st->cam.axisX = 1;
    st->cam.y = st->camRot.v[1];
    st->cam.axisY = 1;
    st->cam.z = st->camDist;
    st->cam.mode = 1;
    st->cam.active = 0;
    st->cam.Update();
    return 1;
}

}

}  // namespace m_StageCmd_2

// ---- StageCmd_3
namespace m_StageCmd_3 {

extern "C" {

int func_0205cb9c(StageResSlot *slot) {
    FieldState *state = data_ov000_021ccd54;
    if (Field_IsEventPending(state)) {
        return -0x63;
    }
    state = data_ov000_021ccd54;
    state->unk_0d3 = 0;
    state->bits190.flag0 = 1;
    return 1;
}

}

}  // namespace m_StageCmd_3

// ---- StageCmd_4
namespace m_StageCmd_4 {

extern "C" {

extern void func_0205b348(void);

extern void func_ov000_02183858(FieldState *state, u16 a);
extern void func_ov000_0218386c(FieldState *state, u16 a);
extern void func_ov000_02186dbc(FieldState *state);
extern void func_ov000_021723b4(FieldPlayer *player, u16 a);
extern void func_ov000_021723d8(FieldPlayer *player, u16 a);
extern void func_ov000_021723fc(FieldPlayer *player, u16 a, u16 b, u16 c);
extern void func_ov000_0217242c(FieldPlayer *player, int mode, u16 a);
extern void func_ov000_02185804(FieldState *state, u16 a);
extern void func_ov000_02185918(FieldState *state, u16 a);

extern void func_ov000_02182590(u8 *p);
extern void func_ov000_021836d0(FieldState *state, u16 a, u16 b, u16 c, u16 d, u16 e);
extern void func_ov000_0218372c(FieldState *state, u16 a);
extern void func_ov000_021837c0(FieldState *state);
extern void func_ov000_021837f8(FieldState *state, u16 a, u16 b, u16 c, u16 d, u16 e, u16 f);

extern void *func_0206fef8(u32 id);
extern s32 func_ov000_0218c040(void *mgr, s32 max, StageVec *out, s32 kind, u16 id);

static inline s32 StageFx_Mul(s32 a, s32 b) {
    return (s32)(((s64)a * b + 0x800) >> 12);
}

typedef struct StageObjInfo {
    /* 0x00 */ u8 unk_00[0x16];
    /* 0x16 */ s16 height;
} StageObjInfo;

int func_0205cbf0(StageResSlot *slot) {
    StageVec list[0x20];
    StageVec pos;
    StageAng ang;
    StageRes *res;
    StageObj3D *o;
    StageLightObj *l;
    s32 dist;
    u16 id;
    u16 a;
    if (StageCam_IsActive() || Field_IsBusy()) {
        return -0x63;
    }
    id = slot->args[1];
    o = NULL;
    l = NULL;
    res = slot->res;
    if (id == 0) {
        o = Stage_FindObj3DByIdx(slot->args[3]);
        l = func_ov000_0218bd5c(data_ov000_021ccd64, slot->args[3]);
    } else if (!(id & 0x8000)) {
        o = Stage_FindObj3DPtr(id);
        l = (StageLightObj *)func_ov000_0218bd9c(data_ov000_021ccd64, slot->args[1], 0xff);
    }
    id = slot->args[1];
    if (id == 0x1000) {
        pos = ((StageCamView *)data_ov000_021ccd54)->cur.pos;
    } else if (id == 0) {
        if (o != NULL) {
            pos = o->pos;
        } else {
            return 1;
        }
    } else if (id & 0x8000) {
        s16 *p = (s16 *)(res->posEv->pos + (u16)(id & 0x7fff) * 6);
        pos.x = p[0] << 4;
        pos.y = p[1] << 4;
        pos.z = p[2] << 4;
    } else {
        StageObjInfo *info = (StageObjInfo *)func_0206fef8(id);
        s32 n = func_ov000_0218c040(data_ov000_021ccd64, 0x20, list, id >> 12, id);
        s32 hh = info->height << 4;
        s32 h;
        s32 i = 0;
        pos.x = 0;
        pos.y = 0;
        pos.z = 0;
        h = StageFx_Mul(hh, 0xaab);
        if (n != 0) {
            s32 inv;
            for (; i < n; i++) {
                VEC_Add(&pos, &list[i], &pos);
                pos.y += h;
            }
            inv = FX_Div(0x1000, n << 12);
            pos.x = StageFx_Mul(pos.x, inv);
            pos.y = StageFx_Mul(pos.y, inv);
            pos.z = StageFx_Mul(pos.z, inv);
        } else if (o != NULL) {
            pos = o->pos;
            pos.y += h;
        }
    }
    a = slot->args[2];
    if (!(a & 0x8000)) {
        dist = 0;
        ang.x = 0;
        ang.y = 0;
        ang.z = 0;
    } else {
        s16 *p;
        a &= 0x7fff;
        p = (s16 *)(res->posEv->pos + a * 6);
        ((s16 *)&ang)[0] = p[0];
        ((s16 *)&ang)[1] = p[1];
        ((s16 *)&ang)[2] = 0;
        dist = p[2] << 4;
    }
    if (!(slot->args[1] & 0x8000) && !(slot->args[2] & 0x8000)) {
        ang.x = 0;
        ang.y = 0;
        ang.z = 0;
        if (o != NULL) {
            ang = *(StageAng *)o->rot;
        } else if (l != NULL) {
            ang.y = l->rot[1];
        }
        ang.x += a;
        ang.y += 0x8000;
        dist += 0x8000;
    }
    {
        StageCamView *cam;
        s32 f = slot->args[4] != 0 ? (s16)slot->args[4] : 0x1000;
        cam = (StageCamView *)data_ov000_021ccd54;
        cam->active = slot->args[0];
        cam->pos = pos;
        cam->ang = ang;
        cam->dist = dist;
        cam->unk_f0 = f;
    }
    return 1;
}

int func_0205d000(StageResSlot *slot) {
    return func_0205cbf0(slot);
}

int func_0205d00c(StageResSlot *slot) {
    FieldState *state = data_ov000_021ccd54;
    if (Field_IsEventPending(state)) {
        return -0x63;
    }
    state->unk_d4 = 0;
    return 1;
}

typedef struct FieldStateBits {
    /* 0x000 */ u8 unk_000[0x18c];
    /* 0x18c */ u8 unk_18c;
    /* 0x18d */ u8 unk_18d;
    /* 0x18e */ u8 unk_18e;
    /* 0x18f */ u8 unk_18f;
    /* 0x190 */ u8 flag0 : 1;
    /* 0x190 */ u8 flag1 : 1;
    /* 0x190 */ u8 flag2 : 1;
    /* 0x190 */ u8 flag3 : 1;
    /* 0x190 */ u8 flag4 : 1;
    /* 0x190 */ u8 unk_190_5 : 3;
} FieldStateBits;

int func_0205d044(StageResSlot *slot) {
    FieldState *state = data_ov000_021ccd54;
    FieldStateBits *b;
    u16 v;
    u16 a0;
    if (Field_HasEvent(10)) {
        return -0x63;
    }
    v = slot->args[1];
    a0 = slot->args[0];
    b = (FieldStateBits *)state;
    b->flag2 = 1;
    b->flag3 = 1;
    b->flag4 = 1;
    b->unk_18d = a0;
    b->unk_18e = v;
    b->unk_18f = v;
    if (slot->args[2] != 0) {
        b->unk_18c = 1;
    }
    return 1;
}

}

}  // namespace m_StageCmd_4

// ---- StageCmd_5
namespace m_StageCmd_5 {

extern "C" {

extern int func_0205cbf0(StageResSlot *slot);

extern void func_0205b348(void);


extern void func_ov000_02183858(FieldState *state, u16 a);

extern void func_ov000_0218386c(FieldState *state, u16 a);

extern void func_ov000_02186dbc(FieldState *state);

extern void func_ov000_021723b4(FieldPlayer *player, u16 a);

extern void func_ov000_021723d8(FieldPlayer *player, u16 a);

extern void func_ov000_021723fc(FieldPlayer *player, u16 a, u16 b, u16 c);

extern void func_ov000_0217242c(FieldPlayer *player, int mode, u16 a);

extern void func_ov000_02185804(FieldState *state, u16 a);

extern void func_ov000_02185918(FieldState *state, u16 a);

extern void func_ov000_02182590(u8 *p);

extern void func_ov000_021836d0(FieldState *state, u16 a, u16 b, u16 c, u16 d, u16 e);

extern void func_ov000_0218372c(FieldState *state, u16 a);

extern void func_ov000_021837c0(FieldState *state);

extern void func_ov000_02172450(FieldPlayer *player, int a);

extern void func_ov000_02172518(FieldPlayer *player, u32 id, u8 *pos, BOOL flag);

extern void func_ov000_021837f8(FieldState *state, u16 a, u16 b, u16 c, u16 d, u16 e, u16 f);

int func_0205d0dc(StageResSlot *slot) {
    FieldState *state = data_ov000_021ccd54;
    if (Field_IsEventPending(state)) {
        return -0x63;
    }
    state->unk_18c = 0;
    state->unk_18d = 0;
    state->unk_18e = 0;
    state->unk_18f = 0;
    return 1;
}

int func_0205d124(StageResSlot *slot) {
    if (Field_IsEventPending(data_ov000_021ccd54)) {
        return -0x63;
    }
    data_02fe1534.unk_42 = 7;
    data_02fe1534.unk_44 = slot->args[0];
    data_02fe1534.unk_80 = slot->args[1];
    StageRes_Pop();
    {
        FieldState *state = data_ov000_021ccd54;
        state->unk_0ac = TRUE;
        func_ov000_02182590(&state->unk_0ac);
    }
    return -0x62;
}

int func_0205d1c0(StageResSlot *slot) {
    func_ov000_021836d0(data_ov000_021ccd54, slot->args[0], slot->args[1], slot->args[2], slot->args[3], slot->args[4]);
    return 1;
}

int func_0205d200(StageResSlot *slot) {
    FieldState *state = data_ov000_021ccd54;
    if (Field_IsEventPending(state)) {
        return -0x63;
    }
    func_ov000_0218372c(state, slot->args[0]);
    return 1;
}

int func_0205d244(StageResSlot *slot) {
    FieldState *state = data_ov000_021ccd54;
    if (Field_IsEventPending(state)) {
        return -0x63;
    }
    func_ov000_021837c0(state);
    return 1;
}

int func_0205d280(StageResSlot *slot) {
    func_ov000_021837f8(data_ov000_021ccd54, slot->args[0], slot->args[1], slot->args[2], slot->args[3], slot->args[4], slot->args[5]);
    return 1;
}

int func_0205d2c8(StageResSlot *slot) {
    FieldState *state = data_ov000_021ccd54;
    if (Field_IsEventPending(state)) {
        return -0x63;
    }
    func_ov000_02183858(state, slot->args[0]);
    return 1;
}

int func_0205d30c(StageResSlot *slot) {
    FieldState *state = data_ov000_021ccd54;
    if (Field_IsEventPending(state)) {
        return -0x63;
    }
    func_ov000_0218386c(state, slot->args[0]);
    return 1;
}

int func_0205d350(StageResSlot *slot) {
    FieldState *state = data_ov000_021ccd54;
    if (Field_IsEventPending(state)) {
        return -0x63;
    }
    func_ov000_02186dbc(state);
    return 1;
}

int func_0205d38c(StageResSlot *slot) {
    if (Field_IsEventPending(data_ov000_021ccd54)) {
        return -0x63;
    }
    func_ov000_021723b4(data_ov000_021ccd30, slot->args[0]);
    Field_PushEvent(data_ov000_021ccd54, 0x14, 0);
    return 1;
}

int func_0205d414(StageResSlot *slot) {
    if (Field_IsEventPending(data_ov000_021ccd54)) {
        return -0x63;
    }
    func_ov000_021723d8(data_ov000_021ccd30, slot->args[0]);
    Field_PushEvent(data_ov000_021ccd54, 0x14, 0);
    return 1;
}

int func_0205d49c(StageResSlot *slot) {
    if (Field_IsEventPending(data_ov000_021ccd54)) {
        return -0x63;
    }
    func_ov000_021723fc(data_ov000_021ccd30, slot->args[0], slot->args[1], slot->args[2]);
    Field_PushEvent(data_ov000_021ccd54, 0x14, 0);
    return 1;
}

int func_0205d52c(StageResSlot *slot) {
    if (Field_IsEventPending(data_ov000_021ccd54)) {
        return -0x63;
    }
    func_ov000_0217242c(data_ov000_021ccd30, 0, slot->args[0]);
    Field_PushEvent(data_ov000_021ccd54, 0x14, 0);
    return 1;
}

int func_0205d5b8(StageResSlot *slot) {
    if (Field_IsEventPending(data_ov000_021ccd54)) {
        return -0x63;
    }
    func_ov000_0217242c(data_ov000_021ccd30, 1, slot->args[0]);
    Field_PushEvent(data_ov000_021ccd54, 0x14, 0);
    return 1;
}

int func_0205d644(StageResSlot *slot) {
    if (Field_IsEventPending(data_ov000_021ccd54)) {
        return -0x63;
    }
    func_ov000_0217242c(data_ov000_021ccd30, 2, slot->args[0]);
    Field_PushEvent(data_ov000_021ccd54, 0x14, 0);
    return 1;
}

int func_0205d6d0(StageResSlot *slot) {
    if (Field_IsEventPending(data_ov000_021ccd54)) {
        return -0x63;
    }
    func_ov000_0217242c(data_ov000_021ccd30, 3, slot->args[0]);
    Field_PushEvent(data_ov000_021ccd54, 0x14, 0);
    return 1;
}

int func_0205d75c(StageResSlot *slot) {
    FieldState *state = data_ov000_021ccd54;
    if (Field_IsEventPending(state)) {
        return -0x63;
    }
    func_ov000_02185804(state, slot->args[0]);
    return 0;
}

int func_0205d7a0(StageResSlot *slot) {
    FieldState *state = data_ov000_021ccd54;
    if (Field_IsEventPending(state)) {
        return -0x63;
    }
    func_ov000_02185918(state, slot->args[0]);
    return 0;
}

int func_0205d7e4(StageResSlot *slot) {
    data_ov000_021ccd30->flag1 = slot->args[0];
    if (slot->args[0] != 0) {
        StagePlayer *player = func_ov000_0219bf90();
        if (player != NULL) {
            func_ov000_021b1110(player, 1);
            player->unk_b2a = 0;
        }
    }
    return 1;
}


int func_0205d83c(StageResSlot *slot) {
    if (Field_IsEventPending(data_ov000_021ccd54)) {
        return -0x63;
    }
    func_ov000_02172450(data_ov000_021ccd30, 0);
    Field_PushEvent(data_ov000_021ccd54, 0x17, 0);
    return 1;
}

int func_0205d8c4(StageResSlot *slot) {
    if (Field_IsEventPending(data_ov000_021ccd54)) {
        return -0x63;
    }
    {
        StageRes *res = slot->res;
        u8 *pos = NULL;
        BOOL flag = slot->args[2] != 0 ? TRUE : FALSE;
        u32 id;
        switch (slot->args[0]) {
        case 0:
            id = 0x2712;
            break;
        case 1:
            id = 0x2713;
            break;
        case 2:
            id = 0x2715;
            break;
        case 3:
            id = 0x2716;
            break;
        case 4:
            id = 0x2716;
            break;
        case 5:
            id = 0x2717;
            break;
        case 6:
            id = 0x44f;
            break;
        }
        if (slot->args[1] & 0x8000) {
            pos = res->posEv->pos + (u16)(slot->args[1] & ~0x8000) * 6;
        }
        func_ov000_02172518(data_ov000_021ccd30, id, pos, flag);
    }
    Field_PushEvent(data_ov000_021ccd54, 0x17, 0);
    return 1;
}


int func_0205d9fc(StageResSlot *slot) {
    if (Field_IsEventPending(data_ov000_021ccd54)) {
        return -0x63;
    }
    if (slot->args[0] != 0) {
        if (Field_IsPlayerActing()) {
            func_ov000_02172288(data_ov000_021ccd30, 0, 0);
            Field_PushEvent(data_ov000_021ccd54, 0x19, 0);
            return -0x63;
        }
        func_ov000_02172288(data_ov000_021ccd30, 1, slot->args[1]);
        Field_PushEvent(data_ov000_021ccd54, 0x18, 0);
    } else {
        func_ov000_02172288(data_ov000_021ccd30, 0, 0);
        Field_PushEvent(data_ov000_021ccd54, 0x19, 0);
    }
    return 1;
}

int func_0205db70(StageResSlot *slot) {
    if (Field_IsEventPending(data_ov000_021ccd54)) {
        return -0x63;
    }
    data_02fe1534.unk_2e = slot->args[2];
    data_02fe1534.unk_30 = slot->args[3];
    func_ov000_021722c4(data_ov000_021ccd30, 1, slot->args[0], slot->args[1], data_02fe1534.unk_2e, data_02fe1534.unk_30);
    return 1;
}

int func_0205dbfc(StageResSlot *slot) {
    if (Field_IsEventPending(data_ov000_021ccd54)) {
        return -0x63;
    }
    data_02fe1534.unk_2e = 0;
    data_02fe1534.unk_30 = 0;
    func_ov000_021722c4(data_ov000_021ccd30, 0, 0, 0, 0, 0);
    return 1;
}

int func_0205dc74(StageResSlot *slot) {
    if (Field_IsEventPending(data_ov000_021ccd54)) {
        return -0x63;
    }
    Actor_SetDir(data_ov000_021ccd30->unk_11c, data_02fe1534.unk_2e, data_02fe1534.unk_30);
    return 1;
}

int func_0205dcd8(StageResSlot *slot) {
    if (Field_IsEventPending(data_ov000_021ccd54)) {
        return -0x63;
    }
    func_ov000_02172338(data_ov000_021ccd30, 1, slot->args[0], slot->args[1] * 60, slot->args[2]);
    return 1;
}

int func_0205dd4c(StageResSlot *slot) {
    if (Field_IsEventPending(data_ov000_021ccd54)) {
        return -0x63;
    }
    func_ov000_02172338(data_ov000_021ccd30, 0, 0, 0x7fffffff, 0);
    return 1;
}

int func_0205dda4(StageResSlot *slot) {
    FieldActorState *st;
    if (!func_ov000_021705ec(data_ov000_021ccd30->unk_11c)) {
        return -0x63;
    }
    st = data_ov000_021ccd30->unk_11c->state;
    if (st->bits.flag9 == 1 ? TRUE : FALSE) {
        return 1;
    }
    if (Field_IsEventPending(data_ov000_021ccd54)) {
        return -0x63;
    }
    switch (slot->args[0]) {
    case 0:
        st->flags |= 0x80;
        break;
    case 1:
        st->flags &= ~0x80;
        break;
    case 2:
        {
            u32 f = st->flags & ~0x10000;
            st->unk_20 = st->unk_1c;
            st->flags = f | 0x120;
        }
        break;
    case 3:
        func_ov000_0216da78(st);
        break;
    }
    return 1;
}

int func_0205de88(StageResSlot *slot) {
    FieldActorState *st;
    if (slot->args[0] == 0 || slot->args[0] == 2) {
        Slot_Push(slot->res, 0x135, slot->args[0]);
        return 1;
    }
    if (!func_ov000_021705ec(data_ov000_021ccd30->unk_11c)) {
        return -0x63;
    }
    st = data_ov000_021ccd30->unk_11c->state;
    if (st->bits.flag9 == 1 ? TRUE : FALSE) {
        return 1;
    }
    switch (slot->args[0]) {
    case 1:
        st->flags &= ~0x80;
        break;
    case 3:
        st->flags &= ~0x80;
        Slot_Push(slot->res, 0x135, slot->args[0]);
        break;
    }
    return 1;
}

int func_0205e04c(StageResSlot *slot) {
    if (Field_IsEventPending(data_ov000_021ccd54)) {
        return -0x63;
    }
    {
        u16 arg = slot->args[1];
        StageRes *res = slot->res;
        u16 hi = (arg >> 12) & 8;
        u16 id = arg & ~0x8000;
        func_ov000_02172390(data_ov000_021ccd30, slot->args[0], func_0204c0e8(hi ? data_02149ef8 : (void *)res->sub, id));
    }
    Field_PushEvent(data_ov000_021ccd54, 0x1a, 0);
    return 1;
}

int func_0205e114(StageResSlot *slot) {
    FieldState *state = data_ov000_021ccd54;
    if (Field_IsEventPending(state)) {
        return -0x63;
    }
    func_ov000_02186158(state, slot->args[0]);
    return 1;
}

int func_0205e158(StageResSlot *slot) {
    FieldState *state = data_ov000_021ccd54;
    if (Field_IsEventPending(state)) {
        return -0x63;
    }
    func_ov000_02186204(state, slot->args[0]);
    return 1;
}

int func_0205e19c(StageResSlot *slot) {
    if (Field_HasEvent(0xa)) {
        return -0x63;
    }
    {
        u16 b;
        u16 id = slot->args[0];
        if (id != 0) {
            b = slot->args[1];
            Stage_FindObj(id, b);
        }
    }
    if (data_02149f10 != NULL || data_02149f00 != NULL) {
        data_02fe1534.unk_80 = 1;
    } else {
        data_02fe1534.unk_80 = 0;
    }
    return 1;
}

typedef struct StagePos {
    s32 x;
    s32 y;
    s32 z;
} StagePos;

static inline s32 StageShape_Mul(s32 a, s32 b) {
    return ((s64)a * b + 0x800) >> 12;
}

static inline BOOL StageShape_InBox(StageShape *shape, s32 dx, s32 dy, s32 dz) {
    return dx < shape->size.x && dy < shape->size.y && dz < shape->size.z;
}

static inline BOOL StageArea_IsBox(StageArea *a) {
    if (a->h == 0 && a->d == 0) {
        return FALSE;
    }
    return TRUE;
}

static inline StageArea *Stage_GetArea(StageRes *res, u16 idx) {
    return (StageArea *)(res->posEv->ev + idx * 12);
}

int func_0205e29c(StageResSlot *slot) {
    StageShape shape;
    StagePos pos;
    StageArea *area;
    if (Field_HasEvent(0xa)) {
        return -0x63;
    }
    area = Stage_GetArea(slot->res, slot->args[2]);
    data_02fe1534.unk_80 = 0;
    if (slot->args[1] == 1) {
        StagePlayer *pl = func_ov000_0219bf90();
        if (pl->color.b != slot->args[3]) {
            return 1;
        }
        *(StageVec *)&pos = pl->target;
    } else {
        {
            u16 b;
            u16 id = slot->args[0];
            if (id != 0) {
                b = slot->args[3];
                Stage_FindObj(id, b);
            }
        }
        if (data_02149f10 != NULL) {
            *(StageVec *)&pos = ((StageObj3D *)data_02149f10)->pos;
        } else if (data_02149f00 != NULL) {
            *(StageVec *)&pos = ((StageLightObj *)data_02149f00)->pos;
        } else {
            return 1;
        }
    }
    {
        s16 h;
        s16 z;
        s16 y;
        s16 x;
        h = area->h;
        x = area->x;
        y = area->y;
        z = area->z;
        if (StageArea_IsBox(area)) {
            s32 dx, dy, dz;
            ((s32 *)&shape)[2] = 2;
            shape.size.x = StageShape_Mul(area->w << 4, 0x800);
            shape.size.y = StageShape_Mul(h << 4, 0x800);
            shape.size.z = StageShape_Mul(area->d << 4, 0x800);
            dx = (x << 4) - pos.x;
            dy = (y << 4) - pos.y;
            dz = (z << 4) - pos.z;
            if (dx < 0) dx = -dx;
            if (dy < 0) dy = -dy;
            if (dz < 0) dz = -dz;
            if (StageShape_InBox(&shape, dx, dy, dz)) {
                data_02fe1534.unk_80 = 1;
            }
        } else {
            s32 r = area->w << 4;
            s32 dx, dy, dz;
            ((s32 *)&shape)[2] = 1;
            shape.size.x = r;
            shape.size.y = StageShape_Mul(r, r);
            shape.size.z = 0;
            dx = (x << 4) - pos.x;
            dy = (y << 4) - pos.y;
            dz = (z << 4) - pos.z;
            if ((s32)(((s64)dx * dx + (s64)dy * dy + (s64)dz * dz + 0x800) >> 12) < shape.size.y) {
                data_02fe1534.unk_80 = 1;
            }
        }
    }
    return 1;
}

}

}  // namespace m_StageCmd_5

// ---- StageCmd_6
namespace m_StageCmd_6 {

extern "C" {

extern void func_ov000_021847d8(FieldState *state);

int func_0205e5a8(StageResSlot *slot) {
    func_ov000_021847d8(data_ov000_021ccd54);
    return 1;
}

}

extern "C" {

typedef union StageLightKey {
    u16 raw;
    struct {
        /* 0x0 */ u16 idx : 12;
        /* 0x0 */ u16 type : 4;
    };
} StageLightKey;

typedef struct StageLightParam {
    /* 0x0 */ StageLightKey key;
    /* 0x2 */ StageLightKey mask;
    /* 0x4 */ u16 unk_04[4];
    /* 0xc */ s16 unk_0c;
} StageLightParam;

typedef struct StageRot {
    u16 x;
    u16 y;
    u16 z;
} StageRot;

typedef struct StageLight2 {
    /* 0x00 */ u8 unk_00[0x88];
    /* 0x88 */ StageVec pos;
    /* 0x94 */ StageRot rot;
} StageLight2;

extern StageLight2 *func_ov000_0218b9ec(StageLightParam *param, u8 *color, u8 *color2, int a, int b);
extern void func_ov000_0218b7c0(StageLight2 *light, u32 idx, int mode);

static inline void LightParam_Init(StageLightParam *p, u16 id) {
    int k;
    p->key.raw = id;
    p->mask.raw = id & 0xf000;
    for (k = 0; k < 4; k++) {
        p->unk_04[k] = 0;
    }
    p->unk_0c = -1;
}

int func_0205e5c4(StageResSlot *slot) {
    u8 color[3];
    StageVec pos;
    StageLightParam param;
    u8 color2[3];
    int i;
    StageLight2 *light;
    StageRes *res;
    if (Field_HasEvent(0x11)) {
        return -0x63;
    }
    {
        u16 id;
        int type;
        u32 lo;
        id = slot->args[0];
        type = (id & 0xf000) >> 12;
        res = slot->res;
        data_02149f10 = NULL;
        data_02149f00 = NULL;
        lo = id & ~0xf000;
        LightParam_Init(&param, 0xffff);
        param.key.raw = lo | ((u32)(type << 28) >> 16);
        param.mask.raw = ((u32)type << 28) >> 16;
    }
    color[0] = data_02fe1534.r;
    color[1] = data_02fe1534.g;
    color[2] = data_02fe1534.b;
    color2[1] = color[1];
    color2[0] = color[0];
    color2[2] = slot->args[3] == 1 ? 0xff : color[2];
    if (slot->args[1] & 0x8000) {
        s16 *p = (s16 *)(res->posEv->pos + (u16)(slot->args[1] & 0x7fff) * 6);
        pos.x = p[0] << 4;
        pos.y = p[1] << 4;
        pos.z = p[2] << 4;
    }
    StageRot rot = {0, 0, 0};
    if (slot->args[2] != 0xffff) {
        if (slot->args[2] & 0x8000) {
            rot.y = ((s16 *)(res->posEv->pos + (u16)(slot->args[2] & 0x7fff) * 6))[1];
        } else {
            rot.y = (s32)(((s64)FX_Div(slot->args[2] << 12, 0x168000) * 0x10000000 + 0x800) >> 12) >> 12;
        }
    }
    light = func_ov000_0218b9ec(&param, color, color2, 0, 0);
    light->pos = pos;
    light->rot = rot;
    func_ov000_0218b7c0(light, (u16)(param.key.raw >> 12), 2);
    data_02149f00 = light;
    return 1;
}

}

}  // namespace m_StageCmd_6

// ---- StageCmd_7
namespace m_StageCmd_7 {

extern "C" {

int func_0205e818(StageResSlot *slot) {
    if (!slot->bits.flag8) {
        if (Field_HasEvent(0x11) || Field_HasEvent(0x27)) {
            return -0x63;
        }
    }
    {
        void *obj = func_ov000_0218bd9c(data_ov000_021ccd64, slot->args[0], data_02fe1534.b & 0xff);
        if (obj != NULL) {
            func_ov000_0218bc9c(data_ov000_021ccd64, obj, 1);
        } else {
            StageObj3D *o = Stage_FindObj3DPtr(slot->args[0]);
            if (o != NULL) {
                o->Remove();
            }
        }
    }
    return 1;
}

void func_0205e958(StageLight *light) {
    light->state = 3;
}

int func_0205e964(StageResSlot *slot) {
    if (!slot->bits.flag8) {
        if (Field_HasEvent(0x11) || Field_HasEvent(0x27)) {
            return -0x63;
        }
    }
    {
        void *obj = func_ov000_0218bd9c(data_ov000_021ccd64, slot->args[0], slot->args[1] & 0xff);
        if (obj != NULL) {
            func_ov000_0218bc9c(data_ov000_021ccd64, obj, 1);
        } else {
            StageObj3D *o = Stage_FindObj3DPtr(slot->args[0]);
            if (o != NULL) {
                o->Remove();
            }
        }
    }
    return 1;
}

int func_0205ea9c(StageResSlot *slot) {
    if (!slot->bits.flag8) {
        if (Field_HasEvent(0x11) || Field_HasEvent(0x27)) {
            return -0x63;
        }
    }
    if (func_ov000_0218bddc(data_ov000_021ccd64, slot->args[0], slot->args[2] & 0xff) == NULL) {
        void *obj = func_ov000_0218bd9c(data_ov000_021ccd64, slot->args[0], slot->args[1] & 0xff);
        if (obj != NULL) {
            func_ov000_0218bc9c(data_ov000_021ccd64, obj, 1);
        }
    }
    return 1;
}

int func_0205ebb0(StageResSlot *slot) {
    StageObj3D *o;
    if (Field_HasEvent(0xa)) {
        return -0x63;
    }
    {
        u16 id = slot->args[0];
        u16 idx = slot->args[1];
        u16 kind = id & 0xf000;
        if (idx == 0xffff) {
            if (data_ov000_021ccd68 == NULL) {
                o = NULL;
            } else {
                o = (StageObj3D *)func_ov000_0218e6d0(data_ov000_021ccd68, kind, id);
            }
        } else {
            StageArea *area = (StageArea *)(slot->res->posEv->ev + idx * 12);
            StageVec pos;
            s32 r;
            pos.x = area->x << 4;
            pos.y = area->y << 4;
            pos.z = area->z << 4;
            r = area->w << 4;
            if (data_ov000_021ccd68 == NULL) {
                o = NULL;
            } else {
                o = func_ov000_0218e750(data_ov000_021ccd68, kind, id, &pos, r);
            }
        }
    }
    data_02fe1534.unk_26 = o->unk_0c;
    return 1;
}

int func_0205ecd8(StageResSlot *slot) {
    if (Field_HasEvent(0xa)) {
        return -0x63;
    }
    Stage_FindObj(slot->args[0], slot->args[1]);
    return 1;
}

int func_0205eda0(StageResSlot *slot) {
    if (Field_HasEvent(0xa)) {
        return -0x63;
    }
    {
        u16 id = slot->args[0];
        u16 b = slot->args[1];
        if (id != 0) {
            data_02149f10 = Stage_FindObj3D(id);
            data_02149f00 = Stage_FindLight1(id, b);
            if (data_02149f00 == NULL) {
                data_02149f00 = Stage_FindLight2(id, b);
            }
        }
    }
    if (data_02149f10 != NULL || data_02149f00 != NULL) {
        data_02fe1534.unk_80 = 1;
    } else {
        data_02fe1534.unk_80 = 0;
    }
    return 1;
}

int func_0205eeb4(StageResSlot *slot) {
    u8 color[3];
    s16 rot[3];
    StageVec pos;
    StageRes *res;
    if (data_02149f00 == NULL) {
        return 1;
    }
    res = slot->res;
    color[0] = slot->args[0];
    color[1] = slot->args[1];
    color[2] = slot->args[2];
    if (slot->args[3] & 0x8000) {
        s16 *p = (s16 *)(res->posEv->pos + (u16)(slot->args[3] & 0x7fff) * 6);
        pos.x = p[0] << 4;
        pos.y = p[1] << 4;
        pos.z = p[2] << 4;
    }
    rot[0] = 0;
    rot[1] = 0;
    rot[2] = 0;
    if (slot->args[4] != 0xffff) {
        if (slot->args[4] & 0x8000) {
            rot[1] = ((s16 *)(res->posEv->pos + (u16)(slot->args[4] & 0x7fff) * 6))[1];
        } else {
            rot[1] = (s32)(((s64)FX_Div(slot->args[4] << 12, 0x168000) * 0x10000000 + 0x800) >> 12) >> 12;
        }
    }
    func_ov000_0218b60c(data_02149f00, color, &pos, rot);
    return 1;
}

int func_0205eff8(StageResSlot *slot) {
    StageVec pos;
    StageObj3D *o;
    StageLightObj *l;
    u16 rot;
    StageRes *res = slot->res;
    if (slot->args[2] & 0x8000) {
        s16 *p = (s16 *)(res->posEv->pos + (u16)(slot->args[2] & 0x7fff) * 6);
        pos.x = p[0] << 4;
        pos.y = p[1] << 4;
        pos.z = p[2] << 4;
    }
    rot = Stage_GetAngle(res, slot->args[3], 0xffff);
    if (slot->args[0] == 0xffff) {
        o = (StageObj3D *)data_02149f10;
        l = (StageLightObj *)data_02149f00;
    } else if (slot->args[0] != 0) {
        o = Stage_FindObj3DPtr(slot->args[0]);
        l = (StageLightObj *)func_ov000_0218bd9c(data_ov000_021ccd64, slot->args[0], data_02fe1534.b & 0xff);
    } else {
        o = Stage_FindObj3DByIdx(slot->args[1]);
        l = func_ov000_0218bd5c(data_ov000_021ccd64, slot->args[1]);
    }
    if (o != NULL) {
        o->pos = pos;
        if (rot != 0xffff) {
            o->rot[0] = 0;
            o->rot[1] = rot;
            o->rot[2] = 0;
        }
        o->unk_9c = 0;
        o->unk_a0 = 0;
        o->unk_a4 = 0;
        o->unk_a8 = 0;
        if (o->unk_48 != NULL) {
            func_ov000_02198d28(o->unk_48, &pos, o->rot[1]);
        }
    }
    if (l != NULL) {
        l->pos = pos;
        if (rot != 0xffff) {
            l->rot[0] = 0;
            l->rot[1] = rot;
            l->rot[2] = 0;
        }
    }
    return 1;
}

int func_0205f22c(StageResSlot *slot) {
    StageObj3D *o;
    StageLightObj *l;
    if (slot->args[0] == 0xffff) {
        o = (StageObj3D *)data_02149f10;
        l = (StageLightObj *)data_02149f00;
    } else if (slot->args[0] != 0) {
        o = Stage_FindObj3DPtr(slot->args[0]);
        l = (StageLightObj *)func_ov000_0218bd9c(data_ov000_021ccd64, slot->args[0], data_02fe1534.b & 0xff);
    } else if (slot->args[1] == 0xffff) {
        o = Stage_FindObj3DByIdx(data_02fe1534.unk_26);
        l = func_ov000_0218bd5c(data_ov000_021ccd64, data_02fe1534.unk_26);
    } else {
        o = Stage_FindObj3DByIdx(slot->args[1]);
        l = func_ov000_0218bd5c(data_ov000_021ccd64, slot->args[1]);
    }
    if (o != NULL) {
        o->params[slot->args[2]] = slot->args[3];
    }
    if (l != NULL) {
        l->params[slot->args[2]] = slot->args[3];
    }
    return 1;
}

int func_0205f354(StageResSlot *slot) {
    StageObj3D *o;
    StageLightObj *l;
    s16 v;
    if (slot->args[0] == 0xffff) {
        o = (StageObj3D *)data_02149f10;
        l = (StageLightObj *)data_02149f00;
    } else if (slot->args[0] != 0) {
        o = Stage_FindObj3DPtr(slot->args[0]);
        l = (StageLightObj *)func_ov000_0218bd9c(data_ov000_021ccd64, slot->args[0], data_02fe1534.b & 0xff);
    } else if (slot->args[1] == 0xffff) {
        o = Stage_FindObj3DByIdx(data_02fe1534.unk_26);
        l = func_ov000_0218bd5c(data_ov000_021ccd64, data_02fe1534.unk_26);
    } else {
        o = Stage_FindObj3DByIdx(slot->args[1]);
        l = func_ov000_0218bd5c(data_ov000_021ccd64, slot->args[1]);
    }
    if (o != NULL) {
        v = o->params[slot->args[2]];
    }
    if (l != NULL) {
        v = l->params[slot->args[2]];
    }
    data_02fe1534.unk_80 = v;
    return 1;
}


int func_0205f47c(StageResSlot *slot) {
    void *o = NULL;
    StageObj3D *l = NULL;
    u16 id;
    s32 m;
    if (Field_HasEvent(0xc)) {
        return -0x63;
    }
    id = slot->args[0];
    if (id == 0xffff) {
        l = (StageObj3D *)data_02149f10;
    } else if (id != 0) {
        o = func_ov000_0218e4cc(data_ov000_021ccd68, id & 0xf000);
    } else if (slot->args[1] == 0xffff) {
        l = Stage_FindObj3DByIdx(data_02fe1534.unk_26);
    } else {
        l = Stage_FindObj3DByIdx(slot->args[1]);
    }
    m = slot->args[2] == 10 ? 6 : slot->args[2] + 0x21;
    if (o != NULL) {
        func_ov000_0218e044(o, slot->args[0], m);
    }
    if (l != NULL) {
        func_ov000_0218d46c(l, 0xffff, m);
    }
    return 1;
}


static inline s32 StageCam_Mul(s32 a, s64 b) {
    return (a * b + 0x800) >> 12;
}

int func_0205f5c4(StageRes *res, u16 id, u16 idx, u16 posIdx, u16 mode) {
    StageObj3D *o;
    StagePlayer *pl;
    StageAng ang;
    StageVec d;
    StageVec pos;
    s32 dist;
    StageCamView *cam;
    StageCamCur *cur;
    if (StageCam_IsActive() || Field_IsBusy()) {
        return -0x63;
    }
    if (id == 0xffff) {
        o = (StageObj3D *)data_02149f10;
    } else if (id != 0) {
        o = Stage_FindObj3DPtr(id);
    } else if (idx == 0xffff) {
        o = Stage_FindObj3DByIdx(data_02fe1534.unk_26);
    } else {
        o = Stage_FindObj3DByIdx(idx);
    }
    if (o != NULL && (pl = func_ov000_0219bf90()) != NULL) {
        cur = &((StageCamView *)data_ov000_021ccd54)->cur;
        if (posIdx != 0) {
            s16 *p = (s16 *)(res->posEv->pos + (u16)(posIdx & 0x7fff) * 6);
            // Written as s16 and read back as u16, which keeps ang on the stack.
            ((s16 *)&ang)[0] = p[0];
            ((s16 *)&ang)[1] = p[1];
            ((s16 *)&ang)[2] = 0;
            dist = p[2] << 4;
            {
                u16 cx = cur->ang.x;
                u16 cy = cur->ang.y;
                if (ang.x == 0xffff) {
                    ang.x = cx;
                }
                if (ang.y == 0xffff) {
                    ang.y = cy;
                }
            }
        } else {
            ang = cur->ang;
            dist = 0xa000;
        }
        if (mode == 0) {
            d = o->pos;
            pos = pl->pos;
            d.x -= pos.x;
            d.y -= pos.y;
            d.z -= pos.z;
            d.x = StageCam_Mul(d.x, 0x733);
            d.y = StageCam_Mul(d.y, 0x733);
            d.z = StageCam_Mul(d.z, 0x733);
            d.y = pl->unk_68;
            VEC_Add(&d, &pos, &pos);
        } else if (mode == 1) {
            pos = o->pos;
            pos.y += o->unk_68;
        }
        cam = (StageCamView *)data_ov000_021ccd54;
        cam->active = 0xffff;
        cam->pos = pos;
        cam->ang = ang;
        cam->dist = dist;
        cam->unk_f0 = 0x1000;
    }
    return 1;
}

}

}  // namespace m_StageCmd_7

// ---- StageCmd_8
namespace m_StageCmd_8 {

extern "C" {

int func_0205f8f8(StageResSlot *slot) {
    return func_0205f5c4(slot->res, slot->args[0], slot->args[1], 0, slot->args[2]);
}

int func_0205f91c(StageResSlot *slot) {
    return func_0205f5c4(slot->res, slot->args[0], slot->args[1], slot->args[2], slot->args[3]);
}

int func_0205f940(StageResSlot *slot) {
    FieldState *state = data_ov000_021ccd54;
    if (Field_IsEventPending(state)) {
        return -0x63;
    }
    state->unk_d4 = 0;
    return 1;
}

int func_0205f978(StageResSlot *slot) {
    StagePlayer *player = func_ov000_0219bf90();
    if (player == NULL) {
        return 1;
    }
    switch (slot->args[0]) {
    case 0:
        data_02fe1534.unk_80 = player->bitsB2a.flag0 ? 1 : 0;
        break;
    case 1:
        data_02fe1534.unk_80 = player->bitsB2a.flag1 ? 1 : 0;
        break;
    }
    return 1;
}

int func_0205f9dc(StageResSlot *slot) {
    StagePlayer *player = func_ov000_0219bf90();
    if (player == NULL || !Stage_IsWirelessReady()) {
        return -0x63;
    }
    if (slot->args[0] == 0) {
        player->bitsB28.flag3 = 1;
    } else {
        player->bitsB28.flag3 = 0;
    }
    return 1;
}

int func_0205fa48(StageResSlot *slot) {
    StageVec pos;
    StagePlayer *player;
    if (Field_HasEvent(0x11) || Field_HasEvent(0x27)) {
        return -0x63;
    }
    player = func_ov000_0219bf90();
    if (player != NULL && player->unk_b1e != 0xffff) {
        return -0x63;
    }
    {
        StageRes *res = slot->res;
        u16 arg = slot->args[0];
        if (arg & 0x8000) {
            s16 *p = (s16 *)(res->posEv->pos + (u16)(arg & 0x7fff) * 6);
            pos.x = p[0] << 4;
            pos.y = p[1] << 4;
            pos.z = p[2] << 4;
        } else if (arg == 0xff) {
            StageCamMgr *mgr = data_ov000_021ccd6c;
            u8 i = mgr->next;
            StageCamPoint *pts = mgr->points;
            StageCamPoint *pt;
            if (i != 0xff) {
                mgr->next = 0xff;
            } else {
                i = mgr->cur;
                if (i == 0xff) {
                    i = 0;
                }
            }
            pt = &pts[i];
            pos.x = pt->x << 4;
            pos.y = pt->y << 4;
            pos.z = pt->z << 4;
            VEC_Add(&pos, &pt->pos, &pos);
        }
    }
    if (player != NULL) {
        player->unk_015 = 3;
        player->bitsB28.mode = 2;
        player->unk_b10 = pos;
        player->unk_b08 = 0x252;
    }
    if (slot->args[1] != 0) {
        Field_PushEvent(data_ov000_021ccd54, 0xb, 0);
    }
    return 1;
}

void func_0205fc88(u32 flags) {
    StagePlayer *player = func_ov000_0219bf90();
    if (player != NULL) {
        if (flags & 1) {
            func_ov000_021b12c0(player, 0);
            func_ov000_021b1514(player);
        } else if (flags & 2) {
            func_ov000_021b13cc(player, 0);
        }
        if (flags & 4) {
            func_ov000_021b14e8(player);
        } else if (flags & 8) {
            func_ov000_021b1514(player);
        }
        if (flags & 0x20) {
            func_ov000_021b1540(player, 0, 0);
        } else if (flags & 0x10) {
            func_ov000_021b1740(player, 0);
        }
        if (flags & 0x800) {
            func_ov000_021b1814(player, 0, 1);
        } else if (flags & 0x400) {
            func_ov000_021b1a54(player, 0);
        }
        if (flags & 0x1000) {
            func_ov000_021b4774(player);
        }
    }
    if ((flags & 0x30) || (flags & 0xc00)) {
        Field_PushEvent(data_ov000_021ccd54, 0xb, 0);
    }
}



static inline void Stage_SetMark(const StageVec *v, u16 rot, u16 active) {
    s32 x = v->x;
    s32 y = v->y;
    s32 z = v->z;
    x += 8;
    y += 8;
    z += 8;
    data_02fe1534.unk_16 = active;
    data_02fe1534.unk_18 = x >> 4;
    data_02fe1534.unk_1a = y >> 4;
    data_02fe1534.unk_1c = z >> 4;
    data_02fe1534.unk_1e = rot;
}

int func_0205fdb0(StageResSlot *slot) {
    StagePlayer *player = func_ov000_0219bf90();
    if (player != NULL) {
        Stage_SetMark(&player->pos, player->rot[1], 1);
    }
    return 1;
}

u16 func_020600cc(StageResSlot *slot, StageVec *pos, u16 *rot, u16 *idx);
extern void func_ov000_0219cbf8(StagePlayer *player, StageVec *pos, u16 *rot);
extern void func_ov000_02184594(FieldState *state);

int func_0205fe10(StageResSlot *slot) {
    StagePlayer *player;
    u16 flags;
    u16 idx;
    u16 rot[3];
    StageVec pos;
    player = func_ov000_0219bf90();
    flags = slot->args[2];
    switch (slot->bits.unk_04_0) {
    case 0:
        if (Field_HasEvent(9)) {
            return -0x63;
        }
        func_020600cc(slot, &pos, rot, &idx);
        if (idx == 0xfe) {
            data_02fe1534.unk_16 = 1;
            data_ov000_021ccd6c->unk_0a = 0xff;
        } else if (idx == 0xffff) {
            if (data_ov000_021ccd6c->unk_0a == 0xff && player != NULL) {
                func_ov000_0219cbf8(player, &pos, rot);
                if (!(flags & 0x20)) {
                    player->unk_vf18();
                }
                {
                    StageVec *v = (StageVec *)((u8 *)data_ov000_021ccd6c + 0x24);
                    v->x = pos.x;
                    v->y = pos.y;
                    v->z = pos.z;
                }
            }
            Stage_SetMark(&pos, rot[1], 1);
            data_ov000_021ccd6c->unk_0a = 0xff;
            if (player != NULL && !Field_HasEvent(10)) {
                data_02fe1534.unk_16 = 0;
            }
        } else {
            data_ov000_021ccd6c->unk_0a = idx;
        }
        data_ov000_021ccd6c->next = 0xff;
        if (flags == 0) {
            break;
        }
        slot->bits.unk_04_0 = 1;
    case 1:
        if (!Stage_IsWirelessReady() || Field_IsEventPending(data_ov000_021ccd54)) {
            return -0x63;
        }
        if (player == NULL) {
            func_ov000_02184594(data_ov000_021ccd54);
            return -0x63;
        }
        func_0205fc88(flags);
        break;
    }
    return 1;
}

}

}  // namespace m_StageCmd_8

// ---- StageCmd_9
namespace m_StageCmd_9 {

extern "C" {

extern void func_0205fc88(u32 flags);
extern void func_ov000_02184594(FieldState *state);
extern ObjPoolEntry *func_02059b14(ObjPool *pool, u16 id, ObjPoolParam *param);
extern void *func_02059c98(ObjPool *pool, u16 id, ObjPoolParam *param, int a);
extern SndQueue *data_02097e48;
extern SndMgr *data_02097e4c;
extern void func_ov000_02187a20(FieldState *state, u16 a);
extern void func_0204aa10(SndQueue *queue);
extern void func_02049564(SndMgr *mgr, int a, int b);
extern void func_ov000_02188140(FieldState *state, int a, int b, int c);
extern void func_0204aab0(SndQueue *queue, u16 value);
extern u16 func_0204aac4(SndQueue *queue);
extern void func_0204aa90(SndQueue *queue);
int func_02060898(u16 id, u16 idx, int val);

u16 func_020600cc(StageResSlot *slot, StageVec *pos, u16 *rot, u16 *idx) {
    StageRes *res;
    u16 ang;
    func_ov000_0219bf90();
    res = slot->res;
    *idx = slot->args[0] & ~0x8000;
    ang = Stage_GetAngleOr0(res, slot->args[1]);
    if (slot->args[0] & 0x8000) {
        s16 *p = (s16 *)(res->posEv->pos + *idx * 6);
        pos->x = p[0] << 4;
        pos->y = p[1] << 4;
        pos->z = p[2] << 4;
        rot[0] = 0;
        rot[1] = ang;
        rot[2] = 0;
        *idx = 0xffff;
    }
    return slot->args[2];
}

int func_020601e0(StageResSlot *slot) {
    if (!Stage_IsWirelessReady() || Field_IsEventPending(data_ov000_021ccd54)) {
        return -0x63;
    }
    if (func_ov000_0219bf90() == NULL) {
        func_ov000_02184594(data_ov000_021ccd54);
        return -0x63;
    }
    func_0205fc88(slot->args[0]);
    return 1;
}

int func_02060278(StageResSlot *slot) {
    StagePlayer *player = func_ov000_0219bf90();
    if (player == NULL || Field_HasEvent(9) || !Stage_IsWirelessReady()) {
        return -0x63;
    }
    if (player != NULL) {
        u8 rgb[3];
        rgb[0] = slot->args[0];
        rgb[1] = slot->args[1];
        rgb[2] = slot->args[2];
        player->color = *(StageColor *)rgb;
    }
    return 1;
}

}

}  // namespace m_StageCmd_9

// ---- StageCmd_10
namespace m_StageCmd_10 {

extern "C" {

extern void func_0205fc88(u32 flags);
extern void func_ov000_02184594(FieldState *state);
extern ObjPoolEntry *func_02059b14(ObjPool *pool, u16 id, ObjPoolParam *param);
extern void *func_02059c98(ObjPool *pool, u16 id, ObjPoolParam *param, int a);
extern SndQueue *data_02097e48;
extern SndMgr *data_02097e4c;
extern void func_ov000_02187a20(FieldState *state, u16 a);
extern void func_0204aa10(SndQueue *queue);
extern void func_02049564(SndMgr *mgr, int a, int b);
extern void func_ov000_02188140(FieldState *state, int a, int b, int c);
extern void func_0204aab0(SndQueue *queue, u16 value);
extern u16 func_0204aac4(SndQueue *queue);
extern void func_0204aa90(SndQueue *queue);
int func_02060898(u16 id, u16 idx, int val);

int func_02060364(StageResSlot *slot) {
    StageRes *res;
    u16 idx;
    u16 ang;
    if (Field_HasEvent(9) || !Stage_IsWirelessReady()) {
        return -0x63;
    }
    res = slot->res;
    idx = slot->args[0] & ~0x8000;
    ang = Stage_GetAngleOr0(res, slot->args[1]);
    if (slot->args[0] & 0x8000) {
        StagePlayer *player = func_ov000_0219bf90();
        s16 *p = (s16 *)(res->posEv->pos + idx * 6);
        if (player != NULL) {
            s32 x = p[0] << 4;
            s32 y = p[1] << 4;
            s32 z = p[2] << 4;
            player->target.x = x;
            player->target.y = y;
            player->target.z = z;
            player->targetRot[0] = 0;
            player->targetRot[1] = ang;
            player->targetRot[2] = 0;
        }
    }
    return 1;
}

int func_020604f4(StageResSlot *slot) {
    ObjPoolEntry *e = func_02059b14(data_02149f0c, slot->args[0], (ObjPoolParam *)(slot->res->posEv->ev + slot->args[0] * 12));
    e->active |= 2;
    return 1;
}

int func_02060534(StageResSlot *slot) {
    u16 a;
    ObjPoolEntry *e;
    ObjPoolParam *prm = (ObjPoolParam *)(slot->res->posEv->ev + slot->args[0] * 12);
    a = slot->args[1];
    e = func_02059b14(data_02149f0c, slot->args[0], prm);
    if ((u16)(a & 0xfff) == 0xfff) {
        e->unk_06 = 0xffff;
    } else {
        e->unk_06 = a;
    }
    e->unk_04 = a >> 12;
    e->active |= 2;
    return 1;
}

int func_020605a4(StageResSlot *slot) {
    u16 id = slot->args[0];
    ObjPool *pool = data_02149f0c;
    ObjPoolEntry *e = pool->entries;
    int i;
    for (i = 0; i < 16; i++, e++) {
        if (e->kind != 0 && e->id == id) {
            break;
        }
    }
    if (i != 16) {
        func_020599f4(pool, e);
    }
    return 1;
}

static inline BOOL ObjPoolParam_HasRot(ObjPoolParam *prm) {
    if (prm->ry == 0 && prm->rz == 0) {
        return FALSE;
    }
    return TRUE;
}

int func_020605fc(StageResSlot *slot) {
    ObjPoolParam *prm = (ObjPoolParam *)(slot->res->posEv->ev + slot->args[0] * 12);
    if (slot->args[1] == 0) {
        ObjPool *pool = data_02149f0c;
        BOOL rot = ObjPoolParam_HasRot(prm);
        if (rot) {
            func_02059c98(pool, slot->args[0], prm, 0);
        } else {
            ObjPoolEntry *e = func_02059b14(pool, slot->args[0], prm);
            HitSphere *h;
            e->kind = 3;
            h = (HitSphere *)func_0203dd9c(sizeof(HitSphere));
            if (h != NULL) {
                func_0203f260(h);
            }
            e->obj = h;
            h->radius = e->unk_18;
            ((HitSphere *)e->obj)->group = -1;
            h = (HitSphere *)e->obj;
            h->unk_0c = h->pos;
            h->pos.x = e->x;
            h->pos.y = e->y;
            h->pos.z = e->z;
            if (((HitSphere *)e->obj)->active != 1) {
                func_0203f324((HitSphere *)e->obj);
            }
        }
    } else {
        ObjPool *pool = data_02149f0c;
        BOOL rot = ObjPoolParam_HasRot(prm);
        if (rot) {
            func_02059c98(pool, slot->args[0], prm, 1);
        }
    }
    return 1;
}

}

}  // namespace m_StageCmd_10

// ---- StageCmd_11
namespace m_StageCmd_11 {

extern "C" {

extern void func_0205fc88(u32 flags);
extern void func_ov000_02184594(FieldState *state);
extern ObjPoolEntry *func_02059b14(ObjPool *pool, u16 id, ObjPoolParam *param);
extern void *func_02059c98(ObjPool *pool, u16 id, ObjPoolParam *param, int a);
extern SndQueue *data_02097e48;
extern SndMgr *data_02097e4c;
extern void func_ov000_02187a20(FieldState *state, u16 a);
extern void func_0204aa10(SndQueue *queue);
extern void func_02049564(SndMgr *mgr, int a, int b);
extern void func_ov000_02188140(FieldState *state, int a, int b, int c);
extern void func_0204aab0(SndQueue *queue, u16 value);
extern u16 func_0204aac4(SndQueue *queue);
extern void func_0204aa90(SndQueue *queue);
int func_02060898(u16 id, u16 idx, int val);

int func_02060714(StageResSlot *slot) {
    u16 id = slot->args[0];
    ObjPool *pool = data_02149f0c;
    ObjPoolEntry *e = pool->entries;
    int i;
    for (i = 0; i < 16; i++, e++) {
        if (e->kind != 0 && e->id == id) {
            break;
        }
    }
    if (i != 16) {
        func_020599f4(pool, e);
    }
    return 1;
}

int func_0206076c(StageResSlot *slot) {
    u16 f = slot->args[1];
    ObjPoolEntry *e = func_02059b14(data_02149f0c, slot->args[0], NULL);
    e->kind = 5;
    e->active |= f;
    return 1;
}

int func_020607a8(StageResSlot *slot) {
    u16 id = slot->args[0];
    ObjPool *pool = data_02149f0c;
    ObjPoolEntry *e = pool->entries;
    int i;
    for (i = 0; i < 16; i++, e++) {
        if (e->kind != 0 && e->id == id) {
            break;
        }
    }
    if (i != 16) {
        func_020599f4(pool, e);
    }
    return 1;
}

int func_02060800(StageResSlot *slot) {
    ObjPoolEntry *e = func_02059b14(data_02149f0c, slot->args[0], (ObjPoolParam *)(slot->res->posEv->ev + slot->args[0] * 12));
    e->active |= 8;
    return 1;
}

int func_02060840(StageResSlot *slot) {
    u16 id = slot->args[0];
    ObjPool *pool = data_02149f0c;
    ObjPoolEntry *e = pool->entries;
    int i;
    for (i = 0; i < 16; i++, e++) {
        if (e->kind != 0 && e->id == id) {
            break;
        }
    }
    if (i != 16) {
        func_020599f4(pool, e);
    }
    return 1;
}

int func_02060898(u16 id, u16 idx, int val) {
    StageObj3D *o;
    StageLightObj *l;
    if (id == 0xffff) {
        o = (StageObj3D *)data_02149f10;
        l = (StageLightObj *)data_02149f00;
    } else if (id != 0) {
        o = Stage_FindObj3DPtr(id);
        l = (StageLightObj *)func_ov000_0218bd9c(data_ov000_021ccd64, id, data_02fe1534.b & 0xff);
    } else {
        o = Stage_FindObj3DByIdx(idx);
        l = func_ov000_0218bd5c(data_ov000_021ccd64, idx);
    }
    if (o != NULL) {
        o->params[5] = val;
    }
    if (l != NULL) {
        l->params[4] = val;
    }
    return 1;
}

int func_0206096c(StageResSlot *slot) {
    if (Field_HasEvent(0xa)) {
        return -0x63;
    }
    func_02060898(slot->args[1], slot->args[2], slot->args[0] + 0xc);
    return 1;
}

int func_020609e8(StageResSlot *slot) {
    func_02060898(slot->args[0], slot->args[1], -1);
    return 1;
}

}

}  // namespace m_StageCmd_11

// ---- Flags
namespace m_Flags {

extern "C" {

static inline u32 *Flags_FindFreeSlot(void) {
    StageFlags *flags = data_0214a424;
    u32 i;
    for (i = 0; i < 2; i++) {
        if (flags->slots[i] == 0xffffffff) {
            return &flags->slots[i];
        }
    }
    return NULL;
}

// A slot holds the key a:b:c:d, high byte first.
static inline void Flags_AddSlot(u8 d, u8 c, u8 b, u8 a) {
    u32 *p = Flags_FindFreeSlot();
    if (p != NULL) {
        *p = ((a & 0xff) << 24) | ((b & 0xff) << 16) | ((c & 0xff) << 8) | (d & 0xff);
    }
}

static inline void Flags_AddSlotArgs(StageResSlot *slot) {
    Flags_AddSlot(slot->args[0], slot->args[1], slot->args[2], slot->args[3]);
}

// Clears every slot whose key matches a:b:c, whatever its low byte.
static inline void Flags_ClearSlot(u8 c, u8 b, u8 a) {
    StageFlags *flags = data_0214a424;
    u32 i;
    u32 key = ((a & 0xff) << 24) | ((b & 0xff) << 16) | ((c & 0xff) << 8);
    for (i = 0; i < 2; i++) {
        if (key == (flags->slots[i] & ~0xff)) {
            flags->slots[i] = 0xffffffff;
        }
    }
}

int func_02060a08(StageResSlot *slot) {
    if (slot->args[0] == 2) {
        u8 hi = slot->args[1] >> 8;
        Flags_AddSlot(slot->args[0], 0, slot->args[1], hi);
    } else {
        Flags_AddSlotArgs(slot);
    }
    return 1;
}

int func_02060b18(StageResSlot *slot) {
    if (slot->args[1] == 0xff && slot->args[2] == 0xff) {
        Flags_ClearSlot(0, slot->args[0], slot->args[0] >> 8);
    } else {
        Flags_ClearSlot(slot->args[0], slot->args[1], slot->args[2]);
    }
    return 1;
}

}

}  // namespace m_Flags

// ---- StageCmd_12
namespace m_StageCmd_12 {

extern "C" {

extern void func_0205fc88(u32 flags);
extern void func_ov000_02184594(FieldState *state);
extern ObjPoolEntry *func_02059b14(ObjPool *pool, u16 id, ObjPoolParam *param);
extern void *func_02059c98(ObjPool *pool, u16 id, ObjPoolParam *param, int a);
extern SndQueue *data_02097e48;
extern SndMgr *data_02097e4c;
extern void func_ov000_02187a20(FieldState *state, u16 a);
extern void func_0204aa10(SndQueue *queue);
extern void func_02049564(SndMgr *mgr, int a, int b);
extern void func_ov000_02188140(FieldState *state, int a, int b, int c);
extern void func_0204aab0(SndQueue *queue, u16 value);
extern u16 func_0204aac4(SndQueue *queue);
extern void func_0204aa90(SndQueue *queue);
int func_02060898(u16 id, u16 idx, int val);

int func_02060be4(StageResSlot *slot) {
    FieldState *state = data_ov000_021ccd54;
    if (Field_IsEventPending(state)) {
        return -0x63;
    }
    func_ov000_02187a20(state, slot->args[0]);
    return 1;
}

int func_02060c28(StageResSlot *slot) {
    if (Field_HasEvent(0x11) || Field_HasEvent(0x18)) {
        return -0x63;
    }
    switch (slot->args[0]) {
    case 0:
        data_02097e48->flag0 = 0;
        break;
    case 1:
        data_02097e48->flag0 = 1;
        break;
    case 2:
        data_02097e48->flag2 = 0;
        break;
    case 3:
        if (Field_HasEvent(0xa)) {
            return -0x63;
        }
        func_0204aa10(data_02097e48);
        data_02097e48->flag2 = 1;
        {
            SndQueue *q = data_02097e48;
            if (q->flag3) {
                q->unk_06 = 0x8000;
                q->unk_08 = 10;
                q->unk_02 = 0;
            }
        }
        break;
    case 4:
        data_02097e48->flag3 = 0;
        break;
    case 5:
        data_02097e48->flag3 = 1;
        break;
    case 6:
        func_02049564(data_02097e4c, 1, 1);
        break;
    }
    return 1;
}

int func_02060e0c(StageResSlot *slot) {
    if (Field_HasEvent(0x27) || Field_HasEvent(0x11) || Field_HasEvent(0x18)) {
        return -0x63;
    }
    {
        SndQueue *q = data_02097e48;
        if (q->unk_06 != 0xffff ? TRUE : FALSE) {
            func_ov000_02188140(data_ov000_021ccd54, 1, 0, 0);
            return -0x63;
        }
        func_0204aab0(q, slot->args[0]);
    }
    return 1;
}

int func_02060f58(StageResSlot *slot) {
    if (Field_HasEvent(0x11) || Field_HasEvent(0x18)) {
        return -0x63;
    }
    {
        u16 id = slot->args[0];
        SndQueue *q = data_02097e48;
        if (q->flag0) {
            if (!(q->unk_06 == 0xffff && q->unk_04 == id)) {
                if (q->unk_02 != 10 && q->unk_02 != 0) {
                    if (q->unk_06 != 0xffff) {
                        func_0204aab0(q, q->unk_06);
                    }
                    q->unk_02 = 1;
                } else {
                    q->unk_02 = 0;
                }
                q->unk_06 = id;
                q->unk_08 = 10;
            }
        }
    }
    return 1;
}

int func_02061088(StageResSlot *slot) {
    if (Field_HasEvent(0x11) || Field_HasEvent(0x18)) {
        return -0x63;
    }
    {
        SndQueue *q = data_02097e48;
        if (q->flag0) {
            u16 cur = func_0204aac4(q);
            if (!(q->unk_06 == 0xffff && q->unk_04 == cur)) {
                if (cur == 0xffff) {
                    if (q->flag2 == 1 && q->flag3) {
                        q->unk_06 = 0x8000;
                        q->unk_08 = 10;
                        q->unk_02 = 0;
                    }
                } else {
                    q->unk_06 = cur;
                    q->unk_08 = 10;
                    q->unk_02 = 0;
                }
                func_0204aa90(q);
            }
        }
    }
    return 1;
}

int func_020611c8(StageResSlot *slot) {
    if (slot->args[1] == 0 && Field_IsEventPending(data_ov000_021ccd54)) {
        return -0x63;
    }
    if (slot->args[0] != 0) {
        u16 n = slot->args[0];
        SndQueue *q = data_02097e48;
        if (q->flag3) {
            q->unk_06 = 0x8000;
            q->unk_08 = n;
            q->unk_02 = 0;
        }
    } else {
        SndQueue *q = data_02097e48;
        if (q->flag3) {
            q->unk_06 = 0x8000;
            q->unk_08 = 10;
            q->unk_02 = 0;
        }
    }
    return 1;
}

int func_02061270(StageResSlot *slot) {
    if (Field_HasEvent(0x11) || Field_HasEvent(0x25)) {
        return -0x63;
    }
    {
        u16 id = slot->args[0];
        SndQueue *q = data_02097e48;
        if (!(q->flag0 == 1 && q->unk_74 == 0xffff && q->unk_72 == id)) {
            q->unk_74 = id;
            q->unk_70 = 0;
        }
    }
    return 1;
}

int func_02061360(StageResSlot *slot) {
    if (slot->args[1] == 0 && Field_IsEventPending(data_ov000_021ccd54)) {
        return -0x63;
    }
    {
        SndQueue *q = data_02097e48;
        q->unk_74 = 0x8000;
        q->unk_70 = 0;
    }
    return 1;
}

}

}  // namespace m_StageCmd_12

// ---- StageCmd_13
namespace m_StageCmd_13 {

extern "C" {

extern SndMgr *data_02097e4c;
extern SndHandle *func_02049a48(SndMgr *mgr, s32 id, s32 volume, s32 targetVolume, s32 frames);
extern void func_02049de8(SndMgr *mgr, u16 id);
extern void func_0204a284(SndMgr *mgr, int a);
extern void func_ov000_021bc3ec(FieldState *state, u16 a, s32 b);
extern void func_ov000_02188140(FieldState *state, int a, int b, int c);
extern void func_0203c9e8(int a, int b);
extern void func_0203cc58(int a, int b, int c);
extern int func_0203ca84(int a);
extern void func_0203cb78(s32 a, int b, int c);
extern void func_0203ca24(int h, int a, int b);
extern void func_ov000_02187374(FieldState *state, u16 a);
extern void func_ov000_0218348c(FieldState *state, u8 a);
extern void func_ov000_02182ad4(FieldState *state);
extern void func_ov000_02182b0c(FieldState *state);
extern void func_ov000_021b1b88(StagePlayer *player, u16 a);
extern void func_ov000_02188634(FieldState *state, u16 a, u16 b);
extern BOOL func_ov000_0214be8c(void);
extern BOOL func_ov000_021b4738(StagePlayer *player);
extern int STD_CompareString(const char *a, const char *b);
extern DataRes *data_02fe1530;
extern u16 func_020594bc(DataRes *res, u32 idx, int packed, int sub);
extern void MIi_CpuClear16(u32 value, void *dst, u32 size);

typedef struct StageTblChunk {
    /* 0x00 */ char name[0x10];
    /* 0x10 */ u32 size;
    /* 0x14 */ u8 unk_14[8];
    /* 0x1c */ u16 offsets[1];
} StageTblChunk;

typedef struct StageTblHeader {
    /* 0x00 */ u8 unk_00[0xc];
    /* 0x0c */ u32 count;
    /* 0x10 */ StageTblChunk chunks[1];
} StageTblHeader;


static inline BOOL Stage_IsWirelessIdle(void) {
    return (data_02097d78[3] == 0 && data_02097d78[0] == 0) ? TRUE : FALSE;
}

static inline void Shared_SetFog(u16 r, u16 g, u16 b) {
    data_02fe1534.unk_52 = r;
    data_02fe1534.unk_54 = g;
    data_02fe1534.unk_56 = b;
}

static inline BOOL Shared_TestFlag(u16 mask) {
    return (data_02fe1534.posFlags & mask) ? TRUE : FALSE;
}

static inline BOOL Shared_HasMark(void) {
    return data_02fe1534.unk_16 != 0 ? TRUE : FALSE;
}

int func_020613bc(StageResSlot *slot) {
    if (Field_HasEvent(0x11) || Field_HasEvent(0x25)) {
        return -0x63;
    }
    func_02049a48(data_02097e4c, slot->args[0], -1, -1, -1);
    return 1;
}

int func_0206149c(StageResSlot *slot) {
    if (slot->args[1] == 0 && Field_IsEventPending(data_ov000_021ccd54)) {
        return -0x63;
    }
    func_02049de8(data_02097e4c, slot->args[0]);
    return 1;
}

int func_020614f4(StageResSlot *slot) {
    if (Field_HasEvent(0x11) || Field_HasEvent(0x25)) {
        return -0x63;
    }
    func_0204a20c(data_02097e4c, slot->args[0]);
    return 1;
}

int func_020615bc(StageResSlot *slot) {
    if (slot->args[1] == 0 && Field_IsEventPending(data_ov000_021ccd54)) {
        return -0x63;
    }
    func_0204a284(data_02097e4c, -1);
    return 1;
}

int func_02061614(StageResSlot *slot) {
    if (Field_IsEventPending(data_ov000_021ccd54)) {
        return -0x63;
    }
    func_ov000_021bc3ec(data_ov000_021ccd70, slot->args[0], slot->args[1] << 12);
    return 1;
}

int func_02061668(StageResSlot *slot) {
    if (Field_IsEventPending(data_ov000_021ccd54)) {
        return -0x63;
    }
    func_ov000_021bc458(data_ov000_021ccd70);
    return 1;
}

int func_020616b0(StageResSlot *slot) {
    data_02097d48->pltt.id = slot->args[0];
    return 1;
}

int func_020616cc(StageResSlot *slot) {
    if (Field_IsEventPending(data_ov000_021ccd54)) {
        return -0x63;
    }
    data_02097d48->pltt.id = -1;
    return 1;
}

int func_02061710(StageResSlot *slot) {
    if (!slot->bits.flag8 && Field_IsEventPending(data_ov000_021ccd54)) {
        return -0x63;
    }
    if (Stage_IsWirelessIdle()) {
        int mode;
        switch (slot->args[2]) {
        case 0:
            mode = 0;
            break;
        case 1:
            mode = 1;
            break;
        case 3:
            mode = 3;
            break;
        default:
            mode = -1;
            break;
        }
        func_0203c9e8(0x3f, 0);
        func_0203cc58(slot->args[0] << 12, slot->args[1] != 0 ? 1 : 2, mode);
    }
    return 1;
}

int func_020617ec(StageResSlot *slot) {
    if (!slot->bits.flag8 && Field_IsEventPending(data_ov000_021ccd54)) {
        return -0x63;
    }
    if (Stage_IsWirelessReady()) {
        int h = func_0203ca84(0);
        func_0203cb78(slot->args[0] << 12, 2, 0);
        func_0203ca24(h, 0, 0);
    }
    return 1;
}

int func_0206189c(StageResSlot *slot) {
    if (Stage_IsWirelessReady()) {
        return 1;
    }
    return -0x63;
}

int func_020618d4(StageResSlot *slot) {
    if (!Stage_IsWirelessIdle()) {
        return -0x63;
    }
    return 1;
}

int func_02061904(StageResSlot *slot) {
    FieldState *state = data_ov000_021ccd54;
    if (Field_IsEventPending(state)) {
        return -0x63;
    }
    func_ov000_02188140(state, slot->args[0], slot->args[1], 0);
    return 1;
}

int func_02061950(StageResSlot *slot) {
    FieldState *state = data_ov000_021ccd54;
    if (Field_IsEventPending(state)) {
        return -0x63;
    }
    func_ov000_02188140(state, slot->args[0], slot->args[1], 1);
    return 1;
}

int func_020619a0(StageResSlot *slot) {
    FieldState *state = data_ov000_021ccd54;
    if (Field_IsEventPending(state)) {
        return -0x63;
    }
    func_ov000_02188140(state, 1, 0, 0);
    return 1;
}

int func_020619ec(StageResSlot *slot) {
    if (Field_IsEventPending(data_ov000_021ccd54)) {
        return -0x63;
    }
    return 1;
}

int func_02061a1c(StageResSlot *slot) {
    FieldState *state = data_ov000_021ccd54;
    if (Field_IsEventPending(state)) {
        return -0x63;
    }
    func_ov000_02187374(state, slot->args[0]);
    return 1;
}

int func_02061a60(StageResSlot *slot) {
    FieldState *state = data_ov000_021ccd54;
    if (Field_IsEventPending(state)) {
        return -0x63;
    }
    func_ov000_0218348c(state, slot->args[0]);
    return 1;
}

int func_02061aa8(StageResSlot *slot) {
    FieldState *state = data_ov000_021ccd54;
    if (Field_IsEventPending(state)) {
        return -0x63;
    }
    func_ov000_02182ad4(state);
    return 1;
}

int func_02061ae4(StageResSlot *slot) {
    FieldState *state = data_ov000_021ccd54;
    if (Field_IsEventPending(state)) {
        return -0x63;
    }
    func_ov000_02182b0c(state);
    return 1;
}

int func_02061b20(StageResSlot *slot) {
    if (Field_IsEventPending(data_ov000_021ccd54)) {
        return -0x63;
    }
    switch (slot->args[0]) {
    case 0:
        if (slot->args[1] == 0) {
            data_0214a424->bits18.flag7 = 0;
        } else if (slot->args[1] == 1) {
            data_0214a424->bits18.flag7 = 1;
        }
        break;
    case 1:
        if (slot->args[1] != data_0214a424->bits18.mode) {
            StagePlayer *player = func_ov000_0219bf90();
            if (player != NULL) {
                func_ov000_021b1b88(player, slot->args[1]);
                Field_PushEvent(data_ov000_021ccd54, 0xb, 0);
            } else {
                data_0214a424->bits18.mode = slot->args[1];
            }
        }
        break;
    }
    return 1;
}

int func_02061c44(StageResSlot *slot) {
    FieldState *state = data_ov000_021ccd54;
    if (Field_IsEventPending(state)) {
        return -0x63;
    }
    func_ov000_02188634(state, slot->args[0], slot->args[1]);
    return 1;
}

int func_02061c8c(StageResSlot *slot) {
    ObjPoolShared *shared = &data_02fe1534;
    switch (slot->args[0]) {
    case 0:
        shared->unk_80 = func_ov000_0214be8c();
        break;
    case 1: {
        StagePlayer *player = func_ov000_0219bf90();
        if (player != NULL) {
            StageObj3D *o = Stage_FindObj3DByIdx(player->unk_b1c);
            if (o == NULL) {
                shared->unk_80 = 0;
            } else {
                shared->unk_80 = 1;
                shared->unk_24 = o->unk_0e;
                shared->unk_26 = o->unk_0c;
            }
        }
        break;
    }
    case 2: {
        StagePlayer *player = func_ov000_0219bf90();
        if (player != NULL) {
            if (func_ov000_021b4738(player)) {
                shared->unk_80 = 1;
            } else {
                shared->unk_80 = 0;
            }
        } else {
            shared->unk_80 = 0;
        }
        break;
    }
    }
    return 1;
}

u16 func_02061d54(u16 a) {
    return a & ~0x8000;
}

void *func_02061d64(u16 idx) {
    DataRes *res = data_02fe1530;
    const char *key = "SceneCondTbl";
    u32 i = 0;
    StageTblChunk *chunk = ((StageTblHeader *)res->data)->chunks;
    for (; i < ((StageTblHeader *)res->data)->count; i++) {
        if (STD_CompareString(chunk->name, key) == 0) {
            goto found;
        }
        chunk = (StageTblChunk *)((u8 *)chunk + chunk->size);
    }
    chunk = NULL;
found:
    {
        u16 off = chunk->offsets[idx];
        if (off == 0xffff) {
            return NULL;
        }
        return res->end + off;
    }
}

void *func_02061df0(u16 idx) {
    DataRes *res = data_02fe1530;
    const char *key = "MissionNameTbl";
    u32 i = 0;
    StageTblChunk *chunk = ((StageTblHeader *)res->data)->chunks;
    for (; i < ((StageTblHeader *)res->data)->count; i++) {
        if (STD_CompareString(chunk->name, key) == 0) {
            goto found;
        }
        chunk = (StageTblChunk *)((u8 *)chunk + chunk->size);
    }
    chunk = NULL;
found:
    {
        u16 off = chunk->offsets[idx];
        if (off == 0xffff) {
            return NULL;
        }
        return res->end + off;
    }
}

void *func_02061e7c(u16 idx) {
    DataRes *res = data_02fe1530;
    const char *key = "QuestNameTbl";
    u32 i = 0;
    StageTblChunk *chunk = ((StageTblHeader *)res->data)->chunks;
    for (; i < ((StageTblHeader *)res->data)->count; i++) {
        if (STD_CompareString(chunk->name, key) == 0) {
            goto found;
        }
        chunk = (StageTblChunk *)((u8 *)chunk + chunk->size);
    }
    chunk = NULL;
found:
    {
        u16 off = chunk->offsets[idx];
        if (off == 0xffff) {
            return NULL;
        }
        return res->end + off;
    }
}

void *func_02061f08(u16 idx) {
    DataRes *res = data_02fe1530;
    const char *key = "QuestOptTbl";
    u32 i = 0;
    StageTblChunk *chunk = ((StageTblHeader *)res->data)->chunks;
    for (; i < ((StageTblHeader *)res->data)->count; i++) {
        if (STD_CompareString(chunk->name, key) == 0) {
            goto found;
        }
        chunk = (StageTblChunk *)((u8 *)chunk + chunk->size);
    }
    chunk = NULL;
found:
    {
        u16 off = chunk->offsets[idx];
        if (off == 0xffff) {
            return NULL;
        }
        return res->end + off;
    }
}

void *func_02061f94(u16 idx) {
    DataRes *res = data_02fe1530;
    const char *key = "ImageTbl";
    u32 i = 0;
    StageTblChunk *chunk = ((StageTblHeader *)res->data)->chunks;
    for (; i < ((StageTblHeader *)res->data)->count; i++) {
        if (STD_CompareString(chunk->name, key) == 0) {
            goto found;
        }
        chunk = (StageTblChunk *)((u8 *)chunk + chunk->size);
    }
    chunk = NULL;
found:
    {
        u16 off = chunk->offsets[idx];
        if (off == 0xffff) {
            return NULL;
        }
        return res->end + off;
    }
}

void *func_02062020(u16 idx) {
    DataRes *res = data_02fe1530;
    const char *key = "KeyItemNameTbl";
    u32 i = 0;
    StageTblChunk *chunk = ((StageTblHeader *)res->data)->chunks;
    for (; i < ((StageTblHeader *)res->data)->count; i++) {
        if (STD_CompareString(chunk->name, key) == 0) {
            goto found;
        }
        chunk = (StageTblChunk *)((u8 *)chunk + chunk->size);
    }
    chunk = NULL;
found:
    {
        u16 off = chunk->offsets[idx];
        if (off == 0xffff) {
            return NULL;
        }
        return res->end + off;
    }
}

void *func_020620ac(u16 idx) {
    DataRes *res = data_02fe1530;
    const char *key = "SavePosTbl";
    u32 i = 0;
    StageTblChunk *chunk = ((StageTblHeader *)res->data)->chunks;
    for (; i < ((StageTblHeader *)res->data)->count; i++) {
        if (STD_CompareString(chunk->name, key) == 0) {
            goto found;
        }
        chunk = (StageTblChunk *)((u8 *)chunk + chunk->size);
    }
    chunk = NULL;
found:
    {
        u16 off = chunk->offsets[idx];
        if (off == 0xffff) {
            return NULL;
        }
        return res->end + off;
    }
}

void *func_02062138(u16 idx) {
    DataRes *res = data_02fe1530;
    const char *key = "HelpNameTbl";
    u32 i = 0;
    StageTblChunk *chunk = ((StageTblHeader *)res->data)->chunks;
    for (; i < ((StageTblHeader *)res->data)->count; i++) {
        if (STD_CompareString(chunk->name, key) == 0) {
            goto found;
        }
        chunk = (StageTblChunk *)((u8 *)chunk + chunk->size);
    }
    chunk = NULL;
found:
    {
        u16 off = chunk->offsets[idx];
        if (off == 0xffff) {
            return NULL;
        }
        return res->end + off;
    }
}

BOOL func_020621c4(void) {
    BOOL r = TRUE;
    if (func_020594bc(data_02fe152c, 5, r, 8) == 0) {
        r = FALSE;
    }
    return r;
}

BOOL func_020621f8(void) {
    BOOL r = TRUE;
    if (func_020594bc(data_02fe152c, 5, r, 9) == 0) {
        r = FALSE;
    }
    return r;
}

void func_0206222c(void) {
    ObjPoolShared *shared = &data_02fe1534;
    MIi_CpuClear16(0, shared, 0x82);
    shared->unk_04 = 0;
    shared->r = 0xffff;
    shared->g = 0xffff;
    shared->b = 0xffff;
    shared->unk_10 = 0xffff;
    shared->unk_12 = 0xffff;
    shared->unk_4c = 0xffff;
    shared->unk_4e = 0xffff;
    shared->unk_50 = 0xffff;
    shared->unk_52 = 0x8000;
    shared->unk_54 = 0x8000;
    shared->unk_56 = 0x8000;
}

void func_0206228c(void) {
    data_02fe1534.unk_00 = 0;
    data_02fe1534.unk_42 = 0;
    data_02fe1534.unk_44 = 0;
    data_02fe1534.unk_20 = 0xffff;
    data_02fe1534.unk_24 = 0;
    data_02fe1534.unk_26 = 0;
    data_02fe1534.unk_28 = 0;
    data_02fe1534.unk_22 = 0;
    data_02fe1534.unk_2a = 0;
    data_02fe1534.unk_32 = 0;
    data_02fe1534.unk_70 = 0;
    data_02fe1534.unk_72 = 0;
    data_02fe1534.unk_74 = 0;
    data_02fe1534.unk_76 = 0;
    data_02fe1534.unk_14 &= ~0x3c0;
}

int func_020622ec(u8 *buf, u32 size) {
    MI_CpuFill8(buf, 0, size);
    buf[0] = data_02fe1534.unk_02[0];
    buf[1] = data_02fe1534.unk_02[1];
    buf[2] = data_02fe1534.unk_52_bytes[0];
    buf[3] = data_02fe1534.unk_52_bytes[1];
    buf[4] = data_02fe1534.unk_52_bytes[2];
    buf[5] = data_02fe1534.unk_52_bytes[3];
    buf[6] = data_02fe1534.unk_52_bytes[4];
    buf[7] = data_02fe1534.unk_52_bytes[5];
    buf[8] = data_02fe1534.unk_52_bytes[6];
    buf[9] = data_02fe1534.unk_52_bytes[7];
    buf[10] = data_02fe1534.unk_52_bytes[8];
    buf[11] = data_02fe1534.unk_52_bytes[9];
    return 12;
}

int func_02062370(u8 *buf) {
    data_02fe1534.unk_02[0] = buf[0];
    data_02fe1534.unk_02[1] = buf[1];
    data_02fe1534.unk_52_bytes[0] = buf[2];
    data_02fe1534.unk_52_bytes[1] = buf[3];
    data_02fe1534.unk_52_bytes[2] = buf[4];
    data_02fe1534.unk_52_bytes[3] = buf[5];
    data_02fe1534.unk_52_bytes[4] = buf[6];
    data_02fe1534.unk_52_bytes[5] = buf[7];
    data_02fe1534.unk_52_bytes[6] = buf[8];
    data_02fe1534.unk_52_bytes[7] = buf[9];
    data_02fe1534.unk_52_bytes[8] = buf[10];
    data_02fe1534.unk_52_bytes[9] = buf[11];
    return 12;
}

void func_020623e0(void) {
    data_02fe1534.unk_44 = 2;
    data_02fe1534.unk_42 = 3;
}

void func_020623fc(void) {
    data_02fe1534.unk_42 = 5;
}

void func_02062410(void) {
    data_02fe1534.unk_42 = 6;
}

void func_02062424(const StageColor *c) {
    data_02fe1534.unk_44 = 1;
    data_02fe1534.r = c->r;
    data_02fe1534.g = c->g;
    data_02fe1534.b = c->b;
    data_02fe1534.unk_68 = 0;
    data_02fe1534.unk_6a = 0;
    data_02fe1534.unk_6c = 0;
    data_02fe1534.unk_6e = 0;
    data_02fe1534.unk_80 = data_ov000_021ccd6c->unk_0a;
}

void func_02062478(const StageColor *c) {
    data_02fe1534.unk_44 = 2;
    data_02fe1534.unk_4c = c->r;
    data_02fe1534.unk_4e = c->g;
    data_02fe1534.unk_50 = c->b;
    data_02fe1534.unk_80 = data_ov000_021ccd6c->unk_0a;
}

void func_020624b8(void) {
    data_02fe1534.unk_4c = 0xffff;
    data_02fe1534.unk_4e = 0xffff;
    data_02fe1534.unk_50 = 0xffff;
}

BOOL func_020624d8(void) {
    u16 v = data_02fe1534.unk_52;
    return (v != 0xffff && v != 0x8000) ? TRUE : FALSE;
}

void func_02062500(const StageColor *c) {
    data_02fe1534.unk_52 = c->r;
    data_02fe1534.unk_54 = c->g;
    data_02fe1534.unk_56 = c->b;
}

void func_02062524(void) {
    data_02fe1534.unk_52 = 0x8000;
    data_02fe1534.unk_54 = 0x8000;
    data_02fe1534.unk_56 = 0x8000;
}

void func_02062540(StageVec *out) {
    s32 x = data_02fe1534.posX;
    s32 y = data_02fe1534.posY;
    s32 z = data_02fe1534.posZ;
    data_02fe1534.posFlags &= ~1;
    out->x = x << 4;
    out->y = y << 4;
    out->z = z << 4;
}

u16 func_02062588(void) {
    data_02fe1534.posFlags &= ~2;
    return data_02fe1534.unk_3c;
}

u16 func_020625ac(void) {
    data_02fe1534.posFlags &= ~4;
    return data_02fe1534.unk_3e;
}

s32 func_020625d0(void) {
    s16 v = data_02fe1534.unk_40;
    data_02fe1534.posFlags &= ~8;
    return v << 4;
}

BOOL func_020625f8(void) {
    return Shared_TestFlag(1) ? TRUE : FALSE;
}

BOOL func_02062620(void) {
    return Shared_TestFlag(2) ? TRUE : FALSE;
}

BOOL func_02062648(void) {
    return Shared_TestFlag(4) ? TRUE : FALSE;
}

BOOL func_02062670(void) {
    return Shared_TestFlag(8) ? TRUE : FALSE;
}

BOOL func_02062698(void) {
    return Shared_HasMark() ? TRUE : FALSE;
}

void func_020626c0(void) {
    data_02fe1534.unk_16 = 0;
}

void func_020626d4(StageVec *pos, u16 rot) {
    data_02fe1534.unk_16 = 1;
    if (pos == NULL) {
        return;
    }
    data_02fe1534.unk_18 = (pos->x + 8) >> 4;
    data_02fe1534.unk_1a = (pos->y + 8) >> 4;
    data_02fe1534.unk_1c = (pos->z + 8) >> 4;
    data_02fe1534.unk_1e = rot;
}

void func_02062724(StageVec *out) {
    out->x = data_02fe1534.unk_18 << 4;
    out->y = data_02fe1534.unk_1a << 4;
    out->z = data_02fe1534.unk_1c << 4;
}

u16 func_02062754(void) {
    return data_02fe1534.unk_1e;
}

void func_02062764(u16 clear, u16 set) {
    data_02fe1534.unk_14 &= (u16)~clear;
    data_02fe1534.unk_14 |= set;
}

void func_02062790(u16 a) {
    data_02fe1534.unk_20 = a;
}

void func_020627a0(u16 a, u16 b) {
    data_02fe1534.unk_24 = a;
    data_02fe1534.unk_26 = b;
}

void func_020627b4(void) {
    data_02fe1534.unk_22 = 1;
}

void func_020627c8(void) {
    data_02fe1534.unk_22 = 0;
}

void func_020627dc(u16 a) {
    data_02fe1534.unk_28 = a;
}

void func_020627ec(u16 a) {
    data_02fe1534.unk_2a = a;
}

void func_020627fc(u16 a) {
    data_02fe1534.unk_32 = a;
}

void func_0206280c(u16 a) {
    data_02fe1534.unk_80 = a;
}

void func_0206281c(void) {
    data_02fe1534.unk_7c = 0xffff;
}

u16 func_02062834(void) {
    return data_02fe1534.unk_7c;
}

}

}  // namespace m_StageCmd_13
