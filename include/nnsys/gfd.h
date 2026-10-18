#ifndef NNSYS_GFD_H
#define NNSYS_GFD_H

#include "types.h"

#ifdef __cplusplus
extern "C" {
#endif

// Texture keys: size/16 in bits 16-30, addr/8 in bits 0-15, 4x4 flag in bit 31.
typedef u32 NNSGfdTexKey;
// Palette keys: size/8 in bits 16-31, addr/8 in bits 0-15.
typedef u32 NNSGfdPlttKey;

#define NNS_GFD_TEXSIZE_MIN 0x10
#define NNS_GFD_TEXSIZE_MAX (0x7fff << 4)
#define NNS_GFD_PLTTSIZE_MIN 0x8
#define NNS_GFD_PLTTSIZE_MAX (0xffff << 3)
#define NNS_GFD_ALLOC_ERROR_TEXKEY ((u32)0)
#define NNS_GFD_ALLOC_ERROR_PLTTKEY ((u32)0)
#define NNS_GFD_4PLTT_MAX_ADDR 0x10000

typedef NNSGfdTexKey (*NNSGfdFuncAllocTexVram)(u32 szByte, BOOL is4x4comp, u32 opt);
typedef int (*NNSGfdFuncFreeTexVram)(NNSGfdTexKey key);
typedef NNSGfdPlttKey (*NNSGfdFuncAllocPlttVram)(u32 szByte, BOOL is4pltt, u32 opt);
typedef int (*NNSGfdFuncFreePlttVram)(NNSGfdPlttKey key);

extern NNSGfdFuncAllocTexVram NNS_GfdDefaultFuncAllocTexVram;
extern NNSGfdFuncFreeTexVram NNS_GfdDefaultFuncFreeTexVram;
extern NNSGfdFuncAllocPlttVram NNS_GfdDefaultFuncAllocPlttVram;
extern NNSGfdFuncFreePlttVram NNS_GfdDefaultFuncFreePlttVram;

static inline u32 NNSi_GfdGetTexKeyRoundupSize(u32 size) {
    if (size == 0) {
        return NNS_GFD_TEXSIZE_MIN;
    } else {
        return (size + (NNS_GFD_TEXSIZE_MIN - 1)) & ~(NNS_GFD_TEXSIZE_MIN - 1);
    }
}

static inline NNSGfdTexKey NNS_GfdMakeTexKey(u32 addr, u32 size, BOOL b4x4Comp) {
    return ((size >> 4) << 16) | (0xffff & (addr >> 3)) | b4x4Comp << 31;
}

static inline u32 NNS_GfdGetTexKeyAddr(NNSGfdTexKey key) {
    return (u32)((0x0000ffff & key) << 3);
}

static inline u32 NNS_GfdGetTexKeySize(NNSGfdTexKey key) {
    return (u32)(((0x7fff0000 & key) >> 16) << 4);
}

static inline BOOL NNS_GfdGetTexKey4x4Flag(NNSGfdTexKey key) {
    return (BOOL)((0x80000000 & key) >> 31);
}

static inline u32 NNSi_GfdGetPlttKeyRoundupSize(u32 size) {
    if (size == 0) {
        return NNS_GFD_PLTTSIZE_MIN;
    } else {
        return (size + (NNS_GFD_PLTTSIZE_MIN - 1)) & ~(NNS_GFD_PLTTSIZE_MIN - 1);
    }
}

static inline NNSGfdPlttKey NNS_GfdMakePlttKey(u32 addr, u32 size) {
    return ((size >> 3) << 16) | (0xffff & (addr >> 3));
}

static inline u32 NNS_GfdGetPlttKeyAddr(NNSGfdPlttKey key) {
    return (u32)((0x0000ffff & key) << 3);
}

static inline u32 NNS_GfdGetPlttKeySize(NNSGfdPlttKey key) {
    return (u32)(((0xffff0000 & key) >> 16) << 3);
}

// Linked-list VRAM managers
typedef struct NNSiGfdLnkVramBlock NNSiGfdLnkVramBlock;

struct NNSiGfdLnkVramBlock {
    u32 addr;                      // 0x00
    u32 szByte;                    // 0x04
    NNSiGfdLnkVramBlock *pBlkPrev; // 0x08
    NNSiGfdLnkVramBlock *pBlkNext; // 0x0c
};

typedef struct NNSiGfdLnkMemRegion {
    u32 start;
    u32 end;
} NNSiGfdLnkMemRegion;

typedef struct NNSiGfdLnkVramMan {
    NNSiGfdLnkVramBlock *pFreeList;
} NNSiGfdLnkVramMan;

void NNSi_GfdInitLnkVramMan(NNSiGfdLnkVramMan *pMgr);
NNSiGfdLnkVramBlock *NNSi_GfdInitLnkVramBlockPool(NNSiGfdLnkVramBlock *pArrayHead, u32 lengthOfArray);
BOOL NNSi_GfdAddNewFreeBlock(NNSiGfdLnkVramMan *pMan, NNSiGfdLnkVramBlock **ppBlockPoolList, u32 baseAddr, u32 szByte);
BOOL NNSi_GfdAllocLnkVram(NNSiGfdLnkVramMan *pMan, NNSiGfdLnkVramBlock **ppBlockPoolList, u32 *pRetAddr, u32 szByte);
BOOL NNSi_GfdAllocLnkVramAligned(NNSiGfdLnkVramMan *pMan, NNSiGfdLnkVramBlock **ppBlockPoolList, u32 *pRetAddr, u32 szByte, u32 alignment);
void NNSi_GfdMergeAllFreeBlocks(NNSiGfdLnkVramMan *pMan, NNSiGfdLnkVramBlock **ppBlockPoolList);
BOOL NNSi_GfdFreeLnkVram(NNSiGfdLnkVramMan *pMan, NNSiGfdLnkVramBlock **ppBlockPoolList, u32 addr, u32 szByte);

u32 NNS_GfdGetLnkTexVramManagerWorkSize(u32 numMemBlk);
void NNS_GfdInitLnkTexVramManager(u32 szByte, u32 szByteFor4x4, void *pManagementWork, u32 szByteManagementWork, BOOL useAsDefault);
NNSGfdTexKey NNS_GfdAllocLnkTexVram(u32 szByte, BOOL is4x4comp, u32 opt);
int NNS_GfdFreeLnkTexVram(NNSGfdTexKey memKey);
void NNS_GfdResetLnkTexVramState(void);

u32 NNS_GfdGetLnkPlttVramManagerWorkSize(u32 numMemBlk);
void NNS_GfdInitLnkPlttVramManager(u32 szByte, void *pManagementWork, u32 szByteManagementWork, BOOL useAsDefault);
NNSGfdPlttKey NNS_GfdAllocLnkPlttVram(u32 szByte, BOOL b4Pltt, u32 opt);
int NNS_GfdFreeLnkPlttVram(NNSGfdPlttKey plttKey);
void NNS_GfdResetLnkPlttVramState(void);

#ifdef __cplusplus
}
#endif

#endif
