#include "Main/Res/ResMgr.h"
#include "Main/Res/ResLoader.h"
#include "Main/Gfx/PlttRes.h"
#include "Main/Res/ResArc.h"
#include "Main/Save/SysCard.h"

extern "C" {

extern void FS_CancelFile(FSFile *file);
extern BOOL FS_CloseFile(FSFile *file);
extern u32 FS_TryLoadTable(void *buf, u32 size);
extern void FS_Init(int arg);
extern void MATHi_CRC16InitTableRev(u16 *table, u32 poly);
extern ResLoader *ResLoader_Init(ResLoader *loader);
extern void ResLoader_Start(ResLoader *loader);
extern void ResLoader_Destroy(ResLoader *loader);
extern void ResMgr_Init(ResMgr *mgr);
extern void ResMgr_FreeNodeData(ResMgr *mgr, ResNode *node);
extern void *ResMgr_ReadFile(ResMgr *mgr, const char *path, u32 size, void *buf);
extern void NNS_G2dFontInitAuto(void *out, void *data);
extern void ResMgr_LoadType1(ResMgr *mgr, ResNode *node);
extern void ResMgr_LoadType2(ResMgr *mgr, ResNode *node);
extern void ResMgr_LoadType3(ResMgr *mgr, ResNode *node);
extern void ResMgr_LoadType4(ResMgr *mgr, ResNode *node);
extern void ResMgr_LoadType5(ResMgr *mgr, ResNode *node);
extern void ResMgr_LoadType6(ResMgr *mgr, ResNode *node);
extern BOOL ResMgr_LoadType7Step(ResMgr *mgr, ResNode *node);
extern const char data_0208b354[]; // ".nftr"
extern const char data_0208b35a[]; // ".ncer"
extern const char data_0208b360[]; // ".nanr"
extern const char data_0208b366[]; // ".ncgr"
extern const char data_0208b36c[]; // ".ncbr"
extern const char data_0208b372[]; // ".nclr"
extern const char data_0208b378[]; // ".nscr"
extern const char data_0208b37e[]; // ".nsbmd"
extern const char data_0208b385[]; // ".nsbtx"
extern const char data_0208b38c[]; // ".nsbca"
extern const char data_0208b393[]; // ".nsbma"
extern const char data_0208b39a[]; // ".nsbta"
extern const char data_0208b3a1[]; // ".nsbtp"
extern const char data_0208b3a8[]; // ".nsbva"
extern BOOL NNS_G2dGetUnpackedBGCharacterData(void *data, void *out);
extern BOOL NNS_G2dGetUnpackedScreenData(void *data, void *out);
extern BOOL NNS_G2dGetUnpackedCellBank(void *data, void *out);
extern BOOL NNS_G2dGetUnpackedAnimBank(void *data, void *out);
extern BOOL NNS_G2dGetUnpackedCharacterData(void *data, void *out);
extern BOOL NNS_G2dGetUnpackedPaletteData(void *data, void *out);
extern BOOL NNS_G2dGetUnpackedPaletteCompressInfo(void *data, void *out);
extern void *Heap_Alloc(u32 size);
extern void Heap_FreeLo(void *ptr);
extern BOOL SysCard_CheckLocked(void *arg);


extern ResNode *ResMgr_Find(ResMgr *mgr, const char *name, int type);
extern void ResMgr_ReleaseNode(ResMgr *mgr, ResNode *node, int arg);
extern ResNode *ResMgr_Request(ResMgr *mgr, const char *name, const char *arcName, int type, u8 toFront);
extern void ResMgr_LoadNode(ResMgr *mgr, ResNode *node);
extern void Sys_WaitVBlank(UnkSys *sys);

extern void *ResList_FindType0(ResList *list, const char *name);
extern void *ResList_FindType4(ResList *list, const char *name);
extern void *ResList_FindType5(ResList *list, const char *name);
extern void *ResList_FindType6(ResList *list, const char *name);

ResList *ResMgr_LoadArcListSync(const char *name) {
    ResList *result = NULL;
    ResNode *node = ResMgr_Request(gResMgr, name, NULL, 7, 1);
    ResMgr *mgr;
    if (node != NULL) {
        mgr = gResMgr;
        ResMgr_LoadNode(mgr, node);
        if (node->state != 7) {
            while (TRUE) {
                ResMgr_LoadNode(mgr, node);
                if (node->state == 5) {
                    break;
                }
                Sys_WaitVBlank(gSysState);
            }
        }
        if (node->state != 7) {
            result = node->u.arc.list;
        }
    }
    return result;
}

ResNode *ResMgr_Load(const char *name, int type, u8 toFront) {
    return ResMgr_Request(gResMgr, name, NULL, type, toFront);
}

void ResMgr_LoadArchive(const char *name, const char *arcName, u16 id, u8 toFront) {
    ResNode *node = ResMgr_Request(gResMgr, name, arcName, id, toFront);
    if (node == NULL) {
        return;
    }
    if (node->refCount != 1) {
        return;
    }
    if (arcName == NULL) {
        return;
    }
    if (node->unk_2b_6) {
        return;
    }
    node->unk_2b_6 = TRUE;
    node->u.arc.id = id;
    STD_CopyString(node->u.arc.name, arcName);
}

void ResMgr_ReleaseList(ResList *list) {
    ResMgr *mgr = gResMgr;
    ResNode *node;
    for (node = mgr->head; node != NULL; node = node->next) {
        if (node->type == 7 && node->u.arc.list == list) {
            break;
        }
    }
    if (node != NULL) {
        ResMgr_ReleaseNode(mgr, node, 0);
    }
}

void ResMgr_ReleaseArchive(const char *name, const char *arcName, u16 id) {
    ResNode *node = ResMgr_FindArchive(gResMgr, name, arcName, id);
    if (node != NULL) {
        ResMgr_ReleaseNode(gResMgr, node, 0);
    }
}

BOOL ResMgr_IsLoaded(const char *name, int type) {
    BOOL result = FALSE;
    ResNode *node = ResMgr_Find(gResMgr, name, type);
    if (node == NULL || node->state == 5) {
        result = TRUE;
    }
    return result;
}

BOOL ResMgr_IsArchiveLoaded(const char *name, const char *arcName, u16 id) {
    BOOL result = FALSE;
    ResNode *node = ResMgr_FindArchive(gResMgr, name, arcName, id);
    if (node == NULL || node->state == 5) {
        result = TRUE;
    }
    return result;
}

#define RES_MGR_GET_DATA(func, kind)                                \
    void *func(const char *name) {                                  \
        void *result = NULL;                                        \
        ResNode *node = ResMgr_Find(gResMgr, name, kind);   \
        if (node != NULL) {                                         \
            result = node->u.data;                                  \
        }                                                           \
        return result;                                              \
    }

RES_MGR_GET_DATA(ResMgr_GetDataType0, 0)
RES_MGR_GET_DATA(ResMgr_GetDataType4, 4)
RES_MGR_GET_DATA(ResMgr_GetDataType5, 5)
RES_MGR_GET_DATA(ResMgr_GetDataType6, 6)

ResList *ResMgr_GetArcList(const char *name) {
    ResList *result = NULL;
    ResNode *node = ResMgr_Find(gResMgr, name, 7);
    if (node != NULL) {
        result = node->u.arc.list;
    }
    return result;
}

#define RES_MGR_GET_ARC_DATA(func, findFunc)                        \
    void *func(const char *arcName, const char *name) {             \
        void *result = NULL;                                        \
        ResList *list = NULL;                                       \
        ResNode *node = ResMgr_Find(gResMgr, arcName, 7);   \
        if (node != NULL) {                                         \
            list = node->u.arc.list;                                \
        }                                                           \
        if (list != NULL) {                                         \
            result = findFunc(list, name);                          \
        }                                                           \
        return result;                                              \
    }

RES_MGR_GET_ARC_DATA(ResMgr_FindArcType0, ResList_FindType0)
RES_MGR_GET_ARC_DATA(ResMgr_FindArcType2, ResList_FindType2)
RES_MGR_GET_ARC_DATA(ResMgr_FindArcType4, ResList_FindType4)
RES_MGR_GET_ARC_DATA(ResMgr_FindArcType5, ResList_FindType5)
RES_MGR_GET_ARC_DATA(ResMgr_FindArcType6, ResList_FindType6)

ResList *ResMgr_GetArchiveList(const char *name, const char *arcName, u16 id) {
    ResList *result = NULL;
    ResNode *node = ResMgr_FindArchive(gResMgr, name, arcName, id);
    if (node != NULL) {
        result = node->u.arc.list;
    }
    return result;
}

#define RES_MGR_GET_NAMED_ARC_DATA(func, findFunc, kind) \
    void *func(const char *name, const char *arcName) { \
    ResMgr *mgr = gResMgr; \
    void *result = NULL; \
    u16 hash; \
    ResNode *node; \
    ResList *list = NULL; \
    node = mgr->tail; \
    hash = 0; \
    while (node != NULL) { \
        if (node->unk_2b_6 && node->type == 7 && node->u.arc.id == kind) { \
            if (hash == 0) { \
                hash = ResMgr_Hash(mgr, name); \
            } \
            if (node->hash == hash && STD_CompareString(node->u.arc.name, arcName) == 0) { \
                break; \
            } \
        } \
        node = node->prev; \
    } \
    if (node != NULL) { \
        list = node->u.arc.list; \
    } \
    if (list != NULL) { \
        result = findFunc(list, arcName); \
    } \
    return result; \
}

RES_MGR_GET_NAMED_ARC_DATA(ResMgr_FindNamedArcType0, ResList_FindType0, 0)
RES_MGR_GET_NAMED_ARC_DATA(ResMgr_FindNamedArcType2, ResList_FindType2, 2)
RES_MGR_GET_NAMED_ARC_DATA(ResMgr_FindNamedArcType4, ResList_FindType4, 4)
RES_MGR_GET_NAMED_ARC_DATA(ResMgr_FindNamedArcType6, ResList_FindType6, 6)

BOOL ResMgr_IsIdle(void) {
    BOOL result = FALSE;
    ResNode *node;
    ResNode *list = gResMgr->head;
    for (node = list; node != NULL; node = node->next) {
        if (node->state == 2) {
            break;
        }
    }
    if (node == NULL) {
        for (; list != NULL; list = list->next) {
            if (list->state == 4) {
                break;
            }
        }
        if (list == NULL) {
            result = TRUE;
        }
    }
    return result;
}

void ResMgr_Create(void) {
    if (gResMgr != NULL) {
        return;
    }
    gResMgr = (ResMgr *)Heap_AllocLo(sizeof(ResMgr), 4);
    ResMgr_Init(gResMgr);
}

void ResMgr_Init(ResMgr *mgr) {
    u32 size;
    int i;
    ResLoader *loader;
    FS_Init(-1);
    mgr->unk_7bb4 = NULL;
    size = FS_TryLoadTable(NULL, 0);
    mgr->unk_7bb4 = Heap_AllocLo(size, 4);
    FS_TryLoadTable(mgr->unk_7bb4, size);
    gSysState->cur = gSysState->heapLo;
    loader = (ResLoader *)Heap_Alloc(0x40c);
    if (loader != NULL) {
        loader = ResLoader_Init(loader);
    }
    mgr->loader = loader;
    gSysState->cur = gSysState->heapHi;
    ResLoader_Start(mgr->loader);
    for (i = 0; i < RES_MGR_NODE_COUNT; i++) {
        MI_CpuFill8(&mgr->pool[i], 0, sizeof(ResNode));
    }
    mgr->head = NULL;
    mgr->tail = NULL;
    mgr->freeNode = mgr->pool;
    mgr->numNodes = 0;
    mgr->loadStep = -1;
    MATHi_CRC16InitTableRev(mgr->hashTable, 0xa001);
}

void ResMgr_Update(ResMgr *mgr) {
    ResNode *node;
    if (SysCard_CheckLocked(gSysCard)) {
        return;
    }
    node = ResMgr_FindState(mgr, 4);
    if (node != NULL) {
        ResMgr_LoadNode(mgr, node);
        if (node->state == 4) {
            return;
        }
    }
    node = ResMgr_FindState(mgr, 2);
    if (node != NULL) {
        ResMgr_LoadNode(mgr, node);
    }
}

ResNode *ResMgr_Find(ResMgr *mgr, const char *name, int type) {
    u16 hash;
    ResNode *node;
    if (name == NULL) {
        return NULL;
    }
    if (name[0] == '\0') {
        return NULL;
    }
    node = mgr->head;
    hash = 0;
    while (node != NULL) {
        if (node->type == type && !node->unk_2b_6) {
            if (hash == 0) {
                hash = ResMgr_Hash(mgr, name);
            }
            if (node->hash == hash && STD_CompareString(node->name, name) == 0) {
                break;
            }
        }
        node = node->next;
    }
    return node;
}

ResNode *ResMgr_AllocNode(ResMgr *mgr) {
    ResNode *node = mgr->freeNode;
    int i;
    if (node != NULL) {
        node->state = 1;
        mgr->freeNode = NULL;
        for (i = 0; i < RES_MGR_NODE_COUNT; i++) {
            if (mgr->pool[i].state == 0) {
                mgr->freeNode = &mgr->pool[i];
                break;
            }
        }
    } else {
        node = (ResNode *)Heap_AllocLo(sizeof(ResNode), 4);
        MI_CpuFill8(node, 0, sizeof(ResNode));
        node->heapAllocated = TRUE;
    }
    mgr->numNodes++;
    return node;
}

static inline void ResMgr_FreeNode(ResMgr *mgr, ResNode *node) {
    if (!node->heapAllocated) {
        MI_CpuFill8(node, 0, sizeof(ResNode));
        mgr->freeNode = node;
    } else {
        Heap_FreeLo(node);
    }
    mgr->numNodes--;
}

void ResMgr_FreeNode_020366d0(ResMgr *mgr, ResNode *node) {
    ResMgr_FreeNode(mgr, node);
}

static inline void ResMgr_StopLoading(ResMgr *mgr) {
    if (FS_IsBusy(&mgr->file)) {
        FS_CancelFile(&mgr->file);
    }
    if (FS_IsFile(&mgr->file)) {
        FS_CloseFile(&mgr->file);
    }
    mgr->loadStep = -1;
    ResLoader_Destroy(mgr->loader);
}

void ResMgr_ReleaseNode(ResMgr *mgr, ResNode *node, BOOL force) {
    ResNode *prev;
    ResNode *next;
    if (!force) {
        if (--node->refCount != 0) {
            return;
        }
    }
    if (node->state == 4) {
        ResMgr_StopLoading(mgr);
    }
    ResMgr_FreeNodeData(mgr, node);
    prev = node->prev;
    next = node->next;
    if (prev != NULL) {
        prev->next = next;
    } else {
        mgr->head = next;
    }
    if (next != NULL) {
        next->prev = prev;
    } else {
        mgr->tail = prev;
    }
    ResMgr_FreeNode(mgr, node);
}

void ResMgr_ReleaseByName(ResMgr *mgr, const char *name, int type, BOOL force) {
    ResNode *node = ResMgr_Find(mgr, name, type);
    if (node != NULL) {
        ResMgr_ReleaseNode(mgr, node, force);
    }
}

ResNode *ResMgr_Request(ResMgr *mgr, const char *name, const char *arcName, int type, u8 toFront) {
    BOOL kick;
    ResNode *node;
    ResNode *loading;
    u16 hash;
    if (name == NULL) {
        return NULL;
    }
    if (arcName == NULL) {
        node = ResMgr_Find(mgr, name, type);
    } else {
        hash = 0;
        node = gResMgr->tail;
        while (node != NULL) {
            if (node->unk_2b_6 && node->type == 7 && node->u.arc.id == type) {
                if (hash == 0) {
                    hash = ResMgr_Hash(mgr, name);
                }
                if (node->hash == hash && STD_CompareString(node->u.arc.name, arcName) == 0) {
                    break;
                }
            }
            node = node->prev;
        }
        type = 7;
    }
    kick = FALSE;
    if (node != NULL) {
        node->refCount++;
        if (toFront) {
            if (node->state == 2) {
                kick = TRUE;
            }
            if (node->prev != NULL) {
                node->prev->next = node->next;
                if (node->next != NULL) {
                    node->next->prev = node->prev;
                }
                mgr->head->prev = node;
                node->prev = NULL;
                node->next = mgr->head;
                mgr->head = node;
            }
        }
    } else {
        node = ResMgr_AllocNode(mgr);
        node->refCount = 1;
        node->state = 2;
        node->type = type;
        STD_CopyString(node->name, name);
        node->hash = ResMgr_Hash(mgr, name);
        if (toFront) {
            kick = TRUE;
            if (mgr->head != NULL) {
                mgr->head->prev = node;
                node->next = mgr->head;
            } else {
                mgr->tail = node;
                node->next = NULL;
            }
            mgr->head = node;
            node->prev = NULL;
        } else {
            if (mgr->tail != NULL) {
                mgr->tail->next = node;
                node->prev = mgr->tail;
            } else {
                mgr->head = node;
                node->prev = NULL;
            }
            mgr->tail = node;
            node->next = NULL;
        }
    }
    if (kick) {
        loading = ResMgr_FindState(mgr, 4);
        if (loading != NULL) {
            ResMgr_StopLoading(mgr);
            ResMgr_FreeNodeData(mgr, loading);
            loading->state = 2;
        }
    }
    return node;
}

void ResMgr_LoadNode(ResMgr *mgr, ResNode *node) {
    if (node->state == 2 && mgr->loadStep <= 0) {
        mgr->loadStep = 0;
        node->state = 4;
    }
    switch (node->type) {
    case 0:
        switch (mgr->loadStep) {
        case 0:
            node->u.data[0] = ResMgr_ReadFile(mgr, node->name, 0, 0);
            if (node->u.data[0] != NULL) {
                mgr->loadStep++;
                return;
            }
            mgr->loadStep = -1;
            node->state = 7;
            break;
        case 1:
            if (!FS_IsSucceeded(&mgr->file)) {
                return;
            }
            FS_CloseFile(&mgr->file);
            mgr->loadStep = -1;
            node->state = 5;
            break;
        }
        break;
    case 1:
        ResMgr_LoadType1(mgr, node);
        break;
    case 2:
        ResMgr_LoadType2(mgr, node);
        break;
    case 3:
        ResMgr_LoadType3(mgr, node);
        break;
    case 4:
        ResMgr_LoadType4(mgr, node);
        break;
    case 5:
        ResMgr_LoadType5(mgr, node);
        break;
    case 6:
        ResMgr_LoadType6(mgr, node);
        break;
    case 7:
        while (ResMgr_LoadType7Step(mgr, node)) {
        }
        break;
    }
}

void ResMgr_LoadType1(ResMgr *mgr, ResNode *node) {
    char path[0x28];
    switch (mgr->loadStep) {
    case 0:
        STD_CopyString(path, node->name);
        STD_ConcatenateString(path, data_0208b354);
        node->u.data[0] = ResMgr_ReadFile(mgr, path, 0, 0);
        if (node->u.data[0] != NULL) {
            mgr->loadStep++;
            return;
        }
        mgr->loadStep = -1;
        node->state = 7;
        break;
    case 1:
        if (!FS_IsSucceeded(&mgr->file)) {
            return;
        }
        FS_CloseFile(&mgr->file);
        NNS_G2dFontInitAuto(&node->u.data[1], node->u.data[0]);
        mgr->loadStep = -1;
        node->state = 5;
        break;
    }
}

static inline bool ResMgr_IsReadDone(ResMgr *mgr) {
    return FS_IsSucceeded(&mgr->file) ? TRUE : FALSE;
}

#define RES_LOAD_FIRST(slot, ext)                                   \
    STD_CopyString(path, node->name);                                \
    STD_ConcatenateString(path, ext);                                       \
    node->u.data[slot] = ResMgr_ReadFile(mgr, path, 0, 0);            \
    if (node->u.data[slot] != NULL) {                               \
        mgr->loadStep++;                                            \
        return;                                                     \
    }                                                               \
    mgr->loadStep = -1;                                             \
    node->state = 7;

#define RES_LOAD_PART(slot, ext, nextStep)                          \
    STD_CopyString(path, node->name);                                \
    STD_ConcatenateString(path, ext);                                       \
    node->u.data[slot] = ResMgr_ReadFile(mgr, path, 0, 0);            \
    if (node->u.data[slot] != NULL) {                               \
        mgr->loadStep++;                                            \
    } else {                                                        \
        mgr->loadStep = nextStep;                                   \
    }

void ResMgr_LoadType2(ResMgr *mgr, ResNode *node) {
    char path[0x28];
    switch (mgr->loadStep) {
    case 0:
        node->u.data[0] = NULL;
        node->u.data[1] = NULL;
        node->u.data[2] = NULL;
        node->u.data[3] = NULL;
        node->u.data[4] = NULL;
        node->u.data[5] = NULL;
        node->u.data[6] = NULL;
        node->u.data[7] = NULL;
        node->u.data[8] = NULL;
        node->u.data[9] = NULL;
        node->u.data[10] = NULL;
        STD_CopyString(path, node->name);
        STD_ConcatenateString(path, data_0208b35a);
        node->u.data[0] = ResMgr_ReadFile(mgr, path, 0, 0);
        if (node->u.data[0] != NULL) {
            mgr->loadStep++;
            return;
        }
        mgr->loadStep = -1;
        node->state = 7;
        break;
    case 1:
        if (!ResMgr_IsReadDone(mgr)) {
            return;
        }
        FS_CloseFile(&mgr->file);
        NNS_G2dGetUnpackedCellBank(node->u.data[0], &node->u.data[1]);
        mgr->loadStep = 10;
    case 10:
        RES_LOAD_PART(2, data_0208b360, 20);
        break;
    case 11:
        if (!ResMgr_IsReadDone(mgr)) {
            return;
        }
        FS_CloseFile(&mgr->file);
        NNS_G2dGetUnpackedAnimBank(node->u.data[2], &node->u.data[3]);
        mgr->loadStep = 20;
    case 20:
        RES_LOAD_PART(4, data_0208b366, 30);
        break;
    case 21:
        if (!ResMgr_IsReadDone(mgr)) {
            return;
        }
        FS_CloseFile(&mgr->file);
        NNS_G2dGetUnpackedCharacterData(node->u.data[4], &node->u.data[5]);
        mgr->loadStep = 30;
    case 30:
        RES_LOAD_PART(6, data_0208b36c, 40);
        break;
    case 31:
        if (!ResMgr_IsReadDone(mgr)) {
            return;
        }
        FS_CloseFile(&mgr->file);
        NNS_G2dGetUnpackedCharacterData(node->u.data[6], &node->u.data[7]);
        mgr->loadStep = 40;
    case 40:
        STD_CopyString(path, node->name);
        STD_ConcatenateString(path, data_0208b372);
        node->u.data[8] = ResMgr_ReadFile(mgr, path, 0, 0);
        if (node->u.data[8] != NULL) {
            mgr->loadStep++;
            return;
        }
        mgr->loadStep = -1;
        node->state = 7;
        break;
    case 41:
        if (!FS_IsSucceeded(&mgr->file)) {
            return;
        }
        FS_CloseFile(&mgr->file);
        NNS_G2dGetUnpackedPaletteCompressInfo(node->u.data[8], &node->u.data[10]);
        NNS_G2dGetUnpackedPaletteData(node->u.data[8], &node->u.data[9]);
        mgr->loadStep = -1;
        node->state = 5;
        break;
    }
}


void ResMgr_LoadType3(ResMgr *mgr, ResNode *node) {
    char path[0x28];
    switch (mgr->loadStep) {
    case 0:
        node->u.data[0] = NULL;
        node->u.data[1] = NULL;
        node->u.data[2] = NULL;
        node->u.data[3] = NULL;
        node->u.data[4] = NULL;
        node->u.data[5] = NULL;
        node->u.data[6] = NULL;
        RES_LOAD_FIRST(0, data_0208b378);
        break;
    case 1:
        if (!ResMgr_IsReadDone(mgr)) {
            return;
        }
        FS_CloseFile(&mgr->file);
        NNS_G2dGetUnpackedScreenData(node->u.data[0], &node->u.data[1]);
        mgr->loadStep++;
    case 2:
        RES_LOAD_FIRST(2, data_0208b366);
        break;
    case 3:
        if (!ResMgr_IsReadDone(mgr)) {
            return;
        }
        FS_CloseFile(&mgr->file);
        NNS_G2dGetUnpackedBGCharacterData(node->u.data[2], &node->u.data[3]);
        mgr->loadStep++;
    case 4:
        RES_LOAD_FIRST(4, data_0208b372);
        break;
    case 5:
        if (!FS_IsSucceeded(&mgr->file)) {
            return;
        }
        FS_CloseFile(&mgr->file);
        NNS_G2dGetUnpackedPaletteCompressInfo(node->u.data[4], &node->u.data[6]);
        NNS_G2dGetUnpackedPaletteData(node->u.data[4], &node->u.data[5]);
        mgr->loadStep = -1;
        node->state = 5;
        break;
    }
}

#define RES_LOAD_SINGLE(func, ext)                                  \
    void func(ResMgr *mgr, ResNode *node) {                         \
        char path[0x28];                                            \
        switch (mgr->loadStep) {                                    \
        case 0:                                                     \
            RES_LOAD_FIRST(0, ext);                                 \
            break;                                                  \
        case 1:                                                     \
            if (!FS_IsSucceeded(&mgr->file)) {                      \
                return;                                             \
            }                                                       \
            FS_CloseFile(&mgr->file);                              \
            mgr->loadStep = -1;                                     \
            node->state = 5;                                        \
            break;                                                  \
        }                                                           \
    }

RES_LOAD_SINGLE(ResMgr_LoadType4, data_0208b37e)
RES_LOAD_SINGLE(ResMgr_LoadType5, data_0208b385)


#define RES_LOAD_OPTIONAL(slot, ext, nextStep)                      \
    STD_CopyString(path, node->name);                                \
    STD_ConcatenateString(path, ext);                                       \
    node->u.data[slot] = ResMgr_ReadFile(mgr, path, 0, 0);            \
    if (node->u.data[slot] == NULL) {                               \
        mgr->loadStep = nextStep;                                   \
        return;                                                     \
    }                                                               \
    mgr->loadStep++;                                                \
    node->unk_2b_5 = TRUE;

#define RES_LOAD_OPTIONAL_WAIT(nextStep)                            \
    if (!ResMgr_IsReadDone(mgr)) {                                  \
        return;                                                     \
    }                                                               \
    FS_CloseFile(&mgr->file);                                      \
    mgr->loadStep = nextStep;

void ResMgr_LoadType6(ResMgr *mgr, ResNode *node) {
    char path[0x28];
    switch (mgr->loadStep) {
    case 0:
        RES_LOAD_OPTIONAL(0, data_0208b38c, 10);
        break;
    case 1:
        RES_LOAD_OPTIONAL_WAIT(10);
    case 10:
        RES_LOAD_OPTIONAL(1, data_0208b393, 20);
        break;
    case 11:
        RES_LOAD_OPTIONAL_WAIT(20);
    case 20:
        RES_LOAD_OPTIONAL(2, data_0208b39a, 30);
        break;
    case 21:
        RES_LOAD_OPTIONAL_WAIT(30);
    case 30:
        RES_LOAD_OPTIONAL(3, data_0208b3a1, 40);
        break;
    case 31:
        RES_LOAD_OPTIONAL_WAIT(40);
    case 40:
        RES_LOAD_OPTIONAL(4, data_0208b3a8, 100);
        break;
    case 41:
        RES_LOAD_OPTIONAL_WAIT(100);
    case 100:
        mgr->loadStep = -1;
        if (node->unk_2b_5) {
            node->state = 5;
        } else {
            node->state = 7;
        }
        break;
    }
}

typedef struct ResArcHeader {
    /* 0x0 */ u8 unk_00[6];
    /* 0x6 */ u16 count;
} ResArcHeader;

extern const char data_0208b3af[];
extern ResList *ResList_Init(ResList *list);
extern void ResList_AddEntry(ResList *list, ResRequest *req);
extern BOOL ResLoader_Request(ResLoader *loader, ResRequest *req);
extern void ResLoader_Sleep(ResLoader *loader);
extern u8 *ResRing_GetReadPtr(ResRing *ring);
extern u32 ResRing_GetReadSize(ResRing *ring);
extern BOOL FS_SeekFile(FSFile *file, int offset, u32 whence);

static inline BOOL ResName_Match(const char *a, const char *b) {
    int i;
    for (i = 0; i < 0x20; i++) {
        if (a[i] == '.' && (b[i] == '.' || b[i] == '\0')) {
            break;
        }
        if (a[i] == '\0' && (b[i] == '.' || b[i] == '\0')) {
            break;
        }
        if (b[i] != a[i]) {
            return FALSE;
        }
    }
    return TRUE;
}

BOOL ResMgr_LoadType7Step(ResMgr *mgr, ResNode *node) {
    char path[0x28];
    BOOL again;
    ResRequest *req;
    again = FALSE;
    req = (ResRequest *)&node->u;
    switch (mgr->loadStep) {
    case 0:
        req->unk_00 = 0;
        req->unk_04 = 0;
        req->entries = NULL;
        req->data = NULL;
        req->index = 0;
        STD_CopyString(path, node->name);
        STD_ConcatenateString(path, data_0208b3af);
        req->unk_04 = (u32)Heap_AllocLo(8, 4);
        if (ResMgr_ReadFile(mgr, path, 8, (void *)req->unk_04) != NULL) {
            again = TRUE;
            mgr->loadStep = 1;
        } else {
            mgr->loadStep = 100;
        }
        break;
    case 1: {
        u32 size;
        if (!FS_IsSucceeded(&mgr->file)) {
            break;
        }
        size = ((ResArcHeader *)req->unk_04)->count << 5;
        req->entries = (ResFileEntry *)Heap_AllocHi(size, -4);
        if (ResMgr_ReadFile(mgr, NULL, size, req->entries) != NULL) {
            mgr->loadStep = 3;
            again = TRUE;
        } else {
            mgr->loadStep = 100;
        }
        break;
    }
    case 3: {
        ResList *list;
        if (!ResMgr_IsReadDone(mgr)) {
            break;
        }
        list = (ResList *)Heap_Alloc(4);
        if (list != NULL) {
            list = ResList_Init(list);
        }
        req->unk_00 = (u32)list;
        mgr->loadStep = 4;
    }
    case 4: {
        ResFileEntry *entry = NULL;
        u32 size;
        if (!node->unk_2b_6) {
            entry = &req->entries[req->index];
        } else {
            u16 i;
            u32 offset = 0;
            for (i = req->index; i < ((ResArcHeader *)req->unk_04)->count; i++) {
                entry = &req->entries[i];
                if (req->unk_28 == entry->type) {
                    BOOL found = FALSE;
                    if (req->unk_28 != 0) {
                        if (ResName_Match(req->name.str, entry->name)) {
                            found = TRUE;
                        }
                    } else if (STD_CompareString(entry->name, req->name.str) == 0) {
                        found = TRUE;
                    }
                    if (found) {
                        req->index = i;
                        break;
                    }
                }
                offset += entry->unk_18_8;
            }
            if (i >= ((ResArcHeader *)req->unk_04)->count) {
                mgr->loadStep = 50;
                again = TRUE;
                break;
            }
            if (offset != 0) {
                FS_SeekFile(&mgr->file, offset, 1);
            }
        }
        size = entry->attr2 >> 8;
        req->data = Heap_AllocHi(size, 4);
        if (entry->attr2 & 0xf0) {
            ResLoader *loader = mgr->loader;
            ResRing *ring;
            u8 *buf;
            loader->ring.total = entry->unk_18_8;
            loader->ring.readPos = 0;
            loader->ring.writePos = 0;
            ring = &loader->ring;
            buf = ResRing_GetReadPtr(ring);
            if (buf == NULL) {
                break;
            }
            ResMgr_ReadFile(mgr, NULL, ResRing_GetReadSize(ring), buf);
            if (ResLoader_Request(mgr->loader, req)) {
                mgr->loadStep = 30;
                again = TRUE;
            } else {
                mgr->loadStep = 20;
            }
        } else if (ResMgr_ReadFile(mgr, NULL, size, req->data) != NULL) {
            mgr->loadStep = 10;
            again = TRUE;
        } else {
            mgr->loadStep = 100;
        }
        break;
    }
    case 10:
        if (FS_IsSucceeded(&mgr->file)) {
            mgr->loadStep = 41;
            again = TRUE;
        }
        break;
    case 20:
        if (ResLoader_Request(mgr->loader, req)) {
            mgr->loadStep = 30;
            again = TRUE;
        }
        break;
    case 30: {
        ResLoader *loader;
        u32 size;
        u8 *buf;
        if (!FS_IsSucceeded(&mgr->file)) {
            break;
        }
        loader = mgr->loader;
        loader->ring.readPos += ResRing_GetReadSize(&loader->ring);
        size = ResRing_GetReadSize(&loader->ring);
        if (size == 0) {
            mgr->loadStep = 40;
            again = TRUE;
            break;
        }
        buf = ResRing_GetReadPtr(&loader->ring);
        if (buf == NULL) {
            mgr->loadStep = 31;
            break;
        }
        ResMgr_ReadFile(mgr, NULL, size, buf);
        break;
    }
    case 31: {
        ResLoader *loader = mgr->loader;
        u8 *buf = ResRing_GetReadPtr(&loader->ring);
        if (buf == NULL) {
            break;
        }
        ResMgr_ReadFile(mgr, NULL, ResRing_GetReadSize(&loader->ring), buf);
        mgr->loadStep = 30;
        break;
    }
    case 40:
        if (mgr->loader->state != 3) {
            break;
        }
        ResLoader_Sleep(mgr->loader);
    case 41:
        ResList_AddEntry((ResList *)req->unk_00, req);
        req->data = NULL;
        req->index++;
        if (((ResArcHeader *)req->unk_04)->count > req->index) {
            mgr->loadStep = 4;
            again = TRUE;
            break;
        }
    case 50:
        if (req->unk_04 != 0) {
            Heap_FreeLo((void *)req->unk_04);
            req->unk_04 = 0;
        }
        if (req->entries != NULL) {
            Heap_FreeHi(req->entries);
            req->entries = NULL;
        }
        FS_CloseFile(&mgr->file);
        mgr->loadStep = -1;
        node->state = 5;
        break;
    case 100:
        if (req->unk_04 != 0) {
            Heap_FreeLo((void *)req->unk_04);
            req->unk_04 = 0;
        }
        if (req->entries != NULL) {
            Heap_FreeHi(req->entries);
            req->entries = NULL;
        }
        if (req->data != NULL) {
            Heap_FreeHi(req->data);
            req->data = NULL;
        }
        FS_CloseFile(&mgr->file);
        mgr->loadStep = -1;
        node->state = 7;
        break;
    }
    return again;
}

}
