#ifndef NNSYS_FND_EXPHEAP_INTERNAL_H
#define NNSYS_FND_EXPHEAP_INTERNAL_H

// Shared by expheap.c and expheap_2.c. The SDK keeps all of this in one file with static helpers;
// it is split around AllocUsedBlockFromFreeBlock, which does not match yet.

#include "nnsys/fnd/expheap.h"

#define NNSI_EXPHEAP_SIGNATURE ('EXPH')
#define MBLOCK_FREE_SIGNATURE ('FR')
#define MBLOCK_USED_SIGNATURE ('UD')
#define DEFAULT_GROUPID 0
#define MIN_ALIGNMENT 4
#define MIN_FREE_BLOCK_SIZE 4

typedef struct NNSiMemRegion {
    void *start;
    void *end;
} NNSiMemRegion;

static inline void *AddU32ToPtr(void *ptr, u32 val) {
    return (void *)(NNSiGetUIntPtr(ptr) + val);
}

static inline const void *AddU32ToCPtr(const void *ptr, u32 val) {
    return (const void *)((u32)ptr + val);
}

static inline void *SubU32ToPtr(void *ptr, u32 val) {
    return (void *)((u32)ptr - val);
}

static inline u32 GetOffsetFromPtr(const void *start, const void *end) {
    return (u32)end - (u32)start;
}

static inline s32 ComparePtr(const void *a, const void *b) {
    return (s32)((u32)a - (u32)b);
}

static inline u16 GetSignatureForMBlock(const NNSiFndExpHeapMBlockHead *pMBHead) {
    return (u16)pMBHead->signature;
}

static inline NNSiFndExpHeapHead *GetExpHeapHeadPtrFromHeapHead(NNSiFndHeapHead *pHHead) {
    return AddU32ToPtr(pHHead, sizeof(NNSiFndHeapHead));
}

static inline NNSiFndHeapHead *GetHeapHeadPtrFromExpHeapHead(NNSiFndExpHeapHead *pEHHead) {
    return SubU32ToPtr(pEHHead, sizeof(NNSiFndHeapHead));
}

static inline void SetAllocMode(NNSiFndExpHeapHead *pEHHead, u16 mode) {
    NNSi_FndSetBitValue(pEHHead->feature, 0, 1, mode);
}

static inline u16 GetAllocMode(NNSiFndExpHeapHead *pEHHead) {
    return (u16)NNSi_FndGetBitValue(pEHHead->feature, 0, 1);
}

static inline void *GetMemPtrForMBlock(NNSiFndExpHeapMBlockHead *pMBlkHd) {
    return AddU32ToPtr(pMBlkHd, sizeof(NNSiFndExpHeapMBlockHead));
}

static inline NNSiFndExpHeapMBlockHead *GetMBlockHeadPtr(void *memBlock) {
    return SubU32ToPtr(memBlock, sizeof(NNSiFndExpHeapMBlockHead));
}

static inline void *GetMBlockEndAddr(NNSiFndExpHeapMBlockHead *pMBHead) {
    return AddU32ToPtr(GetMemPtrForMBlock(pMBHead), pMBHead->blkSize);
}

static inline u16 GetAlignmentForMBlock(const NNSiFndExpHeapMBlockHead *pMBlkHd) {
    return (u16)NNSi_FndGetBitValue(pMBlkHd->attribute, 8, 7);
}

static inline void SetAlignmentForMBlock(NNSiFndExpHeapMBlockHead *pMBlkHd, u16 alignment) {
    NNSi_FndSetBitValue(pMBlkHd->attribute, 8, 7, alignment);
}

static inline void SetGroupIDForMBlock(NNSiFndExpHeapMBlockHead *pMBlkHd, u16 id) {
    NNSi_FndSetBitValue(pMBlkHd->attribute, 0, 8, id);
}

static inline void SetAllocDirForMBlock(NNSiFndExpHeapMBlockHead *pMBlkHd, u16 mode) {
    NNSi_FndSetBitValue(pMBlkHd->attribute, 15, 1, mode);
}

static inline u16 GetOptForHeap(const NNSiFndHeapHead *pHeapHd) {
    return (u16)NNSi_FndGetBitValue(pHeapHd->attribute, 0, 8);
}

static inline void FillAllocMemory(NNSiFndHeapHead *pHeapHd, void *address, u32 size) {
    if (GetOptForHeap(pHeapHd) & NNS_FND_HEAP_OPT_0_CLEAR) {
        MIi_CpuClear32(0, address, size);
    }
}

void GetRegionOfMBlock(NNSiMemRegion *region, NNSiFndExpHeapMBlockHead *block);
NNSiFndExpHeapMBlockHead *RemoveMBlock(NNSiFndExpMBlockList *list, NNSiFndExpHeapMBlockHead *block);
NNSiFndExpHeapMBlockHead *InsertMBlock(NNSiFndExpMBlockList *list, NNSiFndExpHeapMBlockHead *target,
                                       NNSiFndExpHeapMBlockHead *prev);
NNSiFndExpHeapMBlockHead *InitMBlock(const NNSiMemRegion *pRegion, u16 signature);
NNSiFndHeapHead *InitExpHeap(void *startAddress, void *endAddress, u16 optFlag);
void *AllocUsedBlockFromFreeBlock(NNSiFndExpHeapHead *pEHHead, NNSiFndExpHeapMBlockHead *pMBHeadFree,
                                         void *mblock, u32 size, u16 direction);

static inline NNSiFndExpHeapMBlockHead *InitFreeMBlock(const NNSiMemRegion *pRegion) {
    return InitMBlock(pRegion, MBLOCK_FREE_SIGNATURE);
}

static inline NNSiFndExpHeapMBlockHead *InitUsedMBlock(const NNSiMemRegion *pRegion) {
    return InitMBlock(pRegion, MBLOCK_USED_SIGNATURE);
}

static inline void AppendMBlock(NNSiFndExpMBlockList *list, NNSiFndExpHeapMBlockHead *block) {
    (void)InsertMBlock(list, block, list->tail);
}

#endif
