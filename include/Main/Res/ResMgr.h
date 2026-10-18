#ifndef MAIN_RES_RESMGR_H
#define MAIN_RES_RESMGR_H

#include "types.h"

#ifdef __cplusplus
extern "C" {
#endif

// Resource manager: loads files from the ROM file system and keeps them in a hashed list of nodes.

typedef struct ResNode {
    /* 0x00 */ struct ResNode *prev;
    /* 0x04 */ struct ResNode *next;
    /* 0x08 */ char name[0x20];
    /* 0x28 */ u16 hash;
    /* 0x2a */ u8 refCount;
    /* 0x2b */ u8 state : 4;
    /* 0x2b */ u8 heapAllocated : 1;
    /* 0x2b */ u8 unk_2b_5 : 1;
    /* 0x2b */ u8 unk_2b_6 : 1;
    /* 0x2b */ u8 unk_2b_7 : 1;
    /* 0x2c */ int type;
    /* 0x30 */ union {
        void *data[11];
        struct {
            /* 0x30 */ struct ResList *list;
            /* 0x34 */ u32 unk_34[3];
            /* 0x40 */ char name[0x18];
            /* 0x58 */ u16 id;
        } arc;
    } u;
} ResNode; // size 0x5c

// Entry of a file table, 32 bytes.
typedef struct ResFileEntry {
    /* 0x00 */ char name[0x18];
    /* 0x18 */ u32 type : 8;
    /* 0x18 */ u32 unk_18_8 : 24;
    /* 0x1c */ u32 attr2; // bits 4-7: compression
} ResFileEntry;

typedef struct ResName {
    char str[0x18];
} ResName;

typedef struct ResRequest {
    /* 0x00 */ u32 unk_00;
    /* 0x04 */ u32 unk_04;
    /* 0x08 */ ResFileEntry *entries;
    /* 0x0c */ void *data;
    /* 0x10 */ ResName name;
    /* 0x28 */ u16 unk_28;
    /* 0x2a */ u16 index;
} ResRequest; // size 0x2c

typedef struct ResList {
    /* 0x0 */ ResNode *head;
} ResList;

// Heap selection of the game. cur is the heap that new allocations come from.
typedef struct UnkSysNode {
    /* 0x0 */ struct UnkSysNode *next;
    /* 0x4 */ s16 value;
    /* 0x6 */ u8 unk_6_0 : 2;
    /* 0x6 */ u8 unk_6_2 : 2;
    /* 0x6 */ u8 unk_6_4 : 2;
    /* 0x6 */ u8 unk_6_6 : 2;
} UnkSysNode;

typedef struct UnkSys {
    /* 0x00 */ void *cur;
    /* 0x04 */ void *unk_04;
    /* 0x08 */ void *unk_08;
    /* 0x0c */ void *unk_0c;
    /* 0x10 */ u32 align;
    /* 0x14 */ u32 frameCount;
    /* 0x18 */ void (*vblankFunc)(void);
    /* 0x1c */ u8 frameWait;
    /* 0x1d */ volatile u8 vcount;
    /* 0x1e */ u8 unk_1e;
    /* 0x1f */ u8 unk_1f;
    /* 0x20 */ u32 unk_20[4];
    /* 0x30 */ u8 unk_30;
    /* 0x31 */ u8 unk_31;
    /* 0x34 */ UnkSysNode node;
} UnkSys; // size 0x3c

extern UnkSys *data_02097dd0;

// NitroSDK FSFile
typedef struct FSFile {
    /* 0x00 */ u8 unk_00[0xc];
    /* 0x0c */ u32 stat;
    /* 0x10 */ u32 unk_10;
    /* 0x14 */ int error;
    /* 0x18 */ u8 unk_18[0x30];
} FSFile; // size 0x48

#define RES_MGR_NODE_COUNT 0x158

typedef struct ResMgr {
    /* 0x0000 */ ResNode pool[RES_MGR_NODE_COUNT];
    /* 0x7ba0 */ ResNode *head;
    /* 0x7ba4 */ ResNode *tail;
    /* 0x7ba8 */ ResNode *freeNode;
    /* 0x7bac */ u16 numNodes;
    /* 0x7bae */ s16 loadStep;
    /* 0x7bb0 */ struct ResLoader *loader;
    /* 0x7bb4 */ void *unk_7bb4;
    /* 0x7bb8 */ FSFile file;
    /* 0x7c00 */ u16 hashTable[0x100];
} ResMgr; // size 0x7e00

extern ResMgr *data_02097cdc;

#define RES_MGR_HASH_TABLE(mgr) ((mgr)->hashTable)

extern ResNode *func_0203662c(ResMgr *mgr);
extern void func_020366d0(ResMgr *mgr, ResNode *node);

// Strings
extern char *func_0201e520(char *dst, const char *src);
extern u32 func_0201e708(const char *str);
extern char *func_0201e78c(char *dst, const char *src);
extern int func_0201e7b0(const char *a, const char *b);
extern u16 MATH_CalcCRC16(u16 *table, const char *str, u32 len);

static inline u16 ResMgr_Hash(ResMgr *mgr, const char *str) {
    return MATH_CalcCRC16(RES_MGR_HASH_TABLE(mgr), str, func_0201e708(str));
}

static inline BOOL FS_IsBusy(volatile const FSFile *file) {
    return (file->stat & 1) ? TRUE : FALSE;
}

static inline BOOL FS_IsSucceeded(volatile const FSFile *file) {
    return (file->error == 0) ? TRUE : FALSE;
}

static inline BOOL FS_IsFile(volatile const FSFile *file) {
    return (file->stat & 0x10) ? TRUE : FALSE;
}

static inline ResNode *ResMgr_FindArchive(ResMgr *mgr, const char *name, const char *arcName, int id) {
    u16 hash;
    ResNode *node;
    node = mgr->tail;
    hash = 0;
    while (node != NULL) {
        if (node->unk_2b_6 && node->type == 7 && node->u.arc.id == id) {
            if (hash == 0) {
                hash = ResMgr_Hash(mgr, name);
            }
            if (node->hash == hash && func_0201e7b0(node->u.arc.name, arcName) == 0) {
                break;
            }
        }
        node = node->prev;
    }
    return node;
}

static inline ResNode *ResMgr_FindState(ResMgr *mgr, int state) {
    ResNode *node;
    for (node = mgr->head; node != NULL; node = node->next) {
        if (node->state == state) {
            break;
        }
    }
    return node;
}

#ifdef __cplusplus
}
#endif

#endif
