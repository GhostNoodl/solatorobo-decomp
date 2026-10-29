#include "types.h"

#include "Main/Res/ResMgr.h"
#include "Main/Gfx/GfxMgr.h"
#include "Main/Gfx/PlttRes.h"

extern "C" {

typedef struct TexObjEntry {
    /* 0x00 */ u16 index;
    /* 0x04 */ void *anim;
    /* 0x08 */ int unk_08;
    /* 0x0c */ int unk_0c;
    /* 0x10 */ u32 transfers[3];
    /* 0x1c */ int key;
    /* 0x20 */ int slot0;
    /* 0x24 */ int slot1;
} TexObjEntry; // size 0x28

typedef struct TexObjVec {
    int v[4];
} TexObjVec;

typedef struct TexObjPair {
    int a;
    int b;
} TexObjPair;

typedef struct TexObj {
    /* 0x000 */ u8 unk_000[0xc];
    /* 0x00c */ int unk_00c;
    /* 0x010 */ int unk_010;
    /* 0x014 */ int unk_014;
    /* 0x018 */ int unk_018;
    /* 0x01c */ int unk_01c;
    /* 0x020 */ int unk_020;
    /* 0x024 */ u8 owned;
    /* 0x028 */ void *res;
    /* 0x02c */ char arcName[0x20];
    /* 0x04c */ char name[0x20];
    /* 0x06c */ u32 unk_06c;
    /* 0x070 */ int unk_070;
    /* 0x074 */ int unk_074;
    /* 0x078 */ TexObjEntry *entries;
    /* 0x07c */ int unk_07c;
    /* 0x080 */ int count;
    /* 0x084 */ u8 unk_084;
    /* 0x085 */ u8 unk_085;
    /* 0x088 */ PlttRes pltt;
    /* 0x0ec */ PlttRes *plttPtr;
    /* 0x0f0 */ u8 unk_0f0[8];
    /* 0x0f8 */ u32 texKey;
    /* 0x0fc */ TexObjPair pairs[3];
    /* 0x114 */ TexObjVec vecs[3];
    /* 0x144 */ int unk_144;
    /* 0x148 */ int unk_148;
    /* 0x14c */ int unk_14c;
    /* 0x150 */ int unk_150;
    /* 0x154 */ u16 unk_154;
    /* 0x158 */ int unk_158;
    /* 0x15c */ int unk_15c;
} TexObj;

extern void MTX_Identity22_(TexObjVec *v);
extern void NNS_G2dInitImageProxy(TexObj *obj);
extern int NNS_G2dGetImageLocation(TexObj *obj, int idx);
extern void func_0203bd40(GfxSys *sys, u32 offset, BOOL sub);
extern void (*NNS_GfdDefaultFuncFreeTexVram)(u32 key);
extern void func_0203e58c(u32 id);
extern void func_02035acc(char *arc, char *name, int mode);
extern void func_02036838(ResMgr *mgr, char *name, int mode, int opt);


void func_020416b4(TexObj *obj, int i);

void func_02041440(TexObj *obj, const char *name, u8 owned) {
    int i;
    obj->owned = owned;
    obj->unk_06c = 0;
    obj->unk_070 = 0;
    obj->entries = NULL;
    obj->unk_07c = 0;
    obj->count = 0;
    obj->res = NULL;
    obj->unk_074 = 0x1000;
    obj->unk_084 = 0;
    obj->unk_085 = 0;
    PlttRes_Init(&obj->pltt);
    obj->plttPtr = NULL;
    obj->texKey = 0;
    for (i = 0; i < 3; i++) {
        obj->pairs[i].a = 0;
        obj->pairs[i].b = 0;
        MTX_Identity22_(&obj->vecs[i]);
    }
    NNS_G2dInitImageProxy(obj);
    obj->unk_150 = 0;
    obj->unk_144 = 0x800;
    obj->unk_148 = 0x800;
    obj->unk_14c = 0x800;
    obj->unk_154 = 0x7fff;
    obj->unk_158 = 0;
    obj->unk_15c = 0;
    obj->arcName[0] = 0;
    if (name == NULL) {
        obj->name[0] = 0;
        return;
    }
    STD_GetStringLength(name);
    STD_CopyString(obj->name, name);
}

void func_02041558(TexObj *obj) {
    u16 i;
    int slot;
    slot = NNS_G2dGetImageLocation(obj, 1);
    if (slot != -1 && !(obj->unk_084 & 2)) {
        func_0203bd40(data_02097d48, slot, 0);
    }
    slot = NNS_G2dGetImageLocation(obj, 2);
    if (slot != -1 && !(obj->unk_084 & 4)) {
        func_0203bd40(data_02097d48, slot, 1);
    }
    if (obj->texKey != 0) {
        NNS_GfdDefaultFuncFreeTexVram(obj->texKey);
    }
    NNS_G2dInitImageProxy(obj);
    obj->texKey = 0;
    func_02041278(&obj->pltt);
    for (i = 0; i < obj->count; i++) {
        func_020416b4(obj, i);
    }
    if (obj->entries != NULL) {
        func_0203df0c(obj->entries);
        obj->entries = NULL;
    }
    if (obj->owned && obj->name[0] != 0) {
        if (obj->arcName[0] != 0) {
            func_02035acc(obj->arcName, obj->name, 2);
        } else {
            func_02036838(data_02097cdc, obj->name, 2, 0);
        }
    }
    func_02041440(obj, NULL, 0);
}

void func_020416b4(TexObj *obj, int i) {
    TexObjEntry *e;
    u16 j;
    if (obj->entries == NULL) {
        return;
    }
    e = &obj->entries[i];
    if (e->slot0 != -1) {
        func_0203bd40(data_02097d48, e->slot0, 0);
    }
    if (e->slot1 != -1) {
        func_0203bd40(data_02097d48, e->slot1, 1);
    }
    if (e->key != -1) {
        NNS_GfdDefaultFuncFreeTexVram(e->key);
    }
    e->slot0 = -1;
    e->slot1 = -1;
    e->key = -1;
    for (j = 0; j < 3; j++) {
        func_0203e58c(e->transfers[j]);
        e->transfers[j] = 0;
    }
    e->unk_08 = 0;
    e->unk_0c = 0;
}


void func_02041774(TexObj *obj, int idx) {
    u32 attr = (u16)obj->unk_06c;
    attr = (attr & ~0x7c) | 0x7c;
    attr = (attr & ~0x1f80) | 0x80;
    obj->unk_150 = 0;
    obj->unk_154 = 0x7fff;
    obj->unk_06c = attr;
    if (idx == 0xffff) {
        return;
    }
    obj->entries[idx].unk_0c = 0;
    obj->entries[idx].unk_08 = 0;
}


typedef struct TexObjRes {
    /* 0x00 */ u32 unk_00;
    /* 0x04 */ void *unk_04;
    /* 0x08 */ u32 unk_08;
    /* 0x0c */ u16 *dict;
} TexObjRes;

typedef struct TexObjAnim {
    /* 0x00 */ u8 unk_00[0xc];
    /* 0x0c */ int unk_0c;
} TexObjAnim;

extern u16 *NNS_G2dGetAnimSequenceByIdx(u16 *dict, int idx);
extern void NNS_G2dInitCellAnimation(TexObjAnim *anim, u16 *data, void *res);
extern void NNS_G2dSetCellAnimationSequence(TexObjAnim *anim, u16 *data);
extern void NNS_G2dSetAnimCtrlCallBackFunctor(TexObjAnim *anim, int type, TexObj *obj, void (*cb)(TexObj *));
extern void NNS_G2dTickCellAnimation(TexObjAnim *anim, int frame);
extern void func_020435e8(GfxPltt *pltt, void *src, u32 size);
void func_02041c90(TexObj *obj);


typedef struct OamAttrs {
    u16 attr0;
    u16 attr1;
    u16 attr2;
} OamAttrs;

typedef struct OamList {
    /* 0x0 */ u16 count;
    /* 0x4 */ OamAttrs *attrs;
} OamList;

typedef struct OamRes {
    /* 0x0 */ u32 unk_0;
    /* 0x4 */ OamAttrs *attrs;
} OamRes;

typedef int OamShape;

extern int data_02082898[][4];
extern int data_020828c8[][4];

static inline OamShape Oam_GetShape(const OamAttrs *attr) {
    return (OamShape)(*(u32 *)attr & 0xc000c000);
}

static inline int Oam_GetWidth(const OamShape *shape) {
    const u16 shapeBit = (u16)((*shape & 0xc000) >> 14);
    const u16 sizeBit = (u16)((*shape & 0xc0000000) >> 30);
    return 8 << data_02082898[shapeBit][sizeBit];
}

static inline int Oam_GetHeight(const OamShape *shape) {
    const u16 shapeBit = (u16)((*shape & 0xc000) >> 14);
    const u16 sizeBit = (u16)((*shape & 0xc0000000) >> 30);
    return 8 << data_020828c8[shapeBit][sizeBit];
}

extern void func_0204205c(TexObj *obj, int idx, int value);

static inline TexObjEntry *TexObj_GetEntry(TexObj *obj, int idx) {
    return idx >= obj->count ? NULL : &obj->entries[idx];
}

extern void func_02039518(void *res);


typedef struct TexObjImage {
    /* 0x0 */ u16 unk_0;
    /* 0x2 */ u16 unk_2;
    /* 0x4 */ int unk_4;
    /* 0x8 */ int unk_8;
} TexObjImage;

typedef struct TexObjRes2 {
    /* 0x00 */ u8 unk_00[0x14];
    /* 0x14 */ TexObjImage *image;
    /* 0x18 */ u32 unk_18;
    /* 0x1c */ TexObjImage *image0;
} TexObjRes2;

extern void func_02040dd8(PlttRes *res, int idx, int load);
void func_02041e74(TexObj *obj, int idx);


typedef struct TexObjImageInfo {
    /* 0x00 */ u8 unk_00[0x10];
    /* 0x10 */ u32 size;
    /* 0x14 */ u32 data;
} TexObjImageInfo;

typedef struct TexObjRes3 {
    /* 0x00 */ u8 unk_00[0x4];
    /* 0x04 */ u32 *info;
    /* 0x08 */ u8 unk_08[0xc];
    /* 0x14 */ TexObjImageInfo *image;
    /* 0x18 */ u32 unk_18;
    /* 0x1c */ TexObjImageInfo *image0;
} TexObjRes3;

extern u32 func_0203bc20(GfxSys *sys, u32 size, BOOL sub, GfxVramNode *cur, GfxVramNode *node);
extern u32 func_0203e458(int type, u32 src, u32 dst, u32 size, u32 chunk);
extern void NNS_G2dSetImageLocation(TexObj *obj, int idx, u32 addr);
extern void NNS_G2dLoadImage1DMapping(TexObjImageInfo *img, u32 addr, int idx, TexObj *obj);
extern void func_0203e098(const char *name, u32 value);
extern u32 (*NNS_GfdDefaultFuncAllocTexVram)(u32 size, int is4x4, int opt);

}

#ifdef NONMATCHING
// func_020417e0: 11 raw / 4 register-masked (was 26 / 4). Round mcA: InitAnim's `anim` is declared before
// `data`, which numbers it below `data` (inline locals are numbered in their own declaration order) and gives
// the ROM's sb/r8 in the entry loop. Left: (1) the ROM sets the NULL arm's zero (`mov fp, sl`) in the second
// loop's preheader, ours hoists it to the entry with the count loop's zero; (2) in the inlined SetData/Upload the
// ROM needs `data` numbered below Upload's reloaded `size`, which no order of the header inlines' parameters gives
// (the front end merges the parameter copies into SetData's `data`, created before Upload's `size`).
// Round hzS: (1) is exactly the move-constant-loads step 34 -> 5 (preheader -> allocation block): refusing that
// one step under gdb (hzR's mclf.sh, FORCE=34:5) leaves only the r7/r8 swap of (2). The walk has a single
// predecessor, so it reads block 5's pressure alone (6, the ROM needs 11) and block 5 is not empty; no loop
// form, alloc inline or SetData/Upload spelling changes it. (2) the sim says Upload's reloaded size fixes the
// swap at any node number above `data` (a named local or temp); every object of the Upload expansion (its size
// parameter, or a SetData local holding res->size) is newer than SetData's `data` parameter, so it is numbered below.
extern "C" {
typedef struct TexObjBank {
    u16 numSeq;
} TexObjBank;

typedef struct TexObjResB {
    /* 0x00 */ u32 unk_00;
    /* 0x04 */ void *unk_04;
    /* 0x08 */ u32 unk_08;
    /* 0x0c */ TexObjBank *bank;
} TexObjResB;

static inline void TexObj_InitAnim(TexObj *obj, int idx) {
    TexObjAnim *anim;
    u16 *data = NNS_G2dGetAnimSequenceByIdx(((TexObjRes *)obj->res)->dict, idx);
    TexObjEntry *e = TexObj_GetEntry(obj, idx);
    if (e == NULL || (anim = (TexObjAnim *)e->anim) == NULL) {
        return;
    }
    NNS_G2dInitCellAnimation(anim, data, ((TexObjRes *)obj->res)->unk_04);
    NNS_G2dSetCellAnimationSequence((TexObjAnim *)e->anim, data);
    anim->unk_0c = 1;
    NNS_G2dSetAnimCtrlCallBackFunctor(anim, 3, obj, func_02041c90);
    NNS_G2dTickCellAnimation((TexObjAnim *)e->anim, 0);
}

static inline void TexObj_SetEntryAnim(TexObj *obj, int idx, void *anim) {
    obj->entries[idx].anim = anim;
}

static inline void TexObj_ClearEntry(TexObj *obj, int idx) {
    u16 j;
    for (j = 0; j < 3; j++) {
        obj->entries[idx].transfers[j] = 0;
        (&obj->entries[idx].key)[j] = -1;
    }
}

static inline void TexObj_SetupAnim(TexObj *obj, int idx) {
    if (obj->entries[idx].anim != NULL) {
        TexObj_InitAnim(obj, idx);
    }
}

static inline int TexObj_CountAnims(const TexObjRes *res) {
    u16 i;
    int n = 0;
    for (i = 0; i < ((const TexObjResB *)res)->bank->numSeq; i++) {
        if (*NNS_G2dGetAnimSequenceByIdx(res->dict, i) > 1) {
            n++;
        }
    }
    return n;
}

static inline void TexObj_ResetEntry(TexObj *obj, const u16 &idx) {
    obj->entries[idx].index = idx;
    obj->entries[idx].unk_08 = 0;
    obj->entries[idx].unk_0c = 0;
}

void func_020417e0(TexObj *obj, const TexObjRes *res) {
    int n;
    u16 count;
    u8 *anims;
    GfxPltt *pltt;
    obj->res = (void *)res;
    n = TexObj_CountAnims(res);
    count = *res->dict;
    obj->count = count;
    obj->entries = (TexObjEntry *)func_0203de84(count * sizeof(TexObjEntry) + n * 0x58, 4);
    anims = (u8 *)obj->entries + count * sizeof(TexObjEntry);
    {
    u16 i;
    for (i = 0; i < ((const TexObjResB *)res)->bank->numSeq; i++) {
        if (*NNS_G2dGetAnimSequenceByIdx(res->dict, i) > 1) {
            TexObj_SetEntryAnim(obj, i, anims);
            anims += 0x58;
        } else {
            TexObj_SetEntryAnim(obj, i, NULL);
        }
        TexObj_ResetEntry(obj, i);
        TexObj_ClearEntry(obj, i);
        TexObj_SetupAnim(obj, i);
    }
    }
    pltt = &data_02097d48->pltt;
    if (pltt->id == -1) {
        PlttRes_SetSrc(&obj->pltt, (PlttResSrc *)obj);
    } else {
        PlttRes_SetSrc(&obj->pltt, (PlttResSrc *)obj);
        PlttRes_SetData(&obj->pltt, ((PlttResSrc *)obj)->info->header->data, obj->pltt.size);
        func_020435e8(pltt, obj->pltt.buf, obj->pltt.size);
    }
    obj->plttPtr = &obj->pltt;
}
}
#endif
