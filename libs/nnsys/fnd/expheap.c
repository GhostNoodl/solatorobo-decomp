#include "expheap_internal.h"

void GetRegionOfMBlock(NNSiMemRegion *region, NNSiFndExpHeapMBlockHead *block) {
    region->start = SubU32ToPtr(block, GetAlignmentForMBlock(block));
    region->end = GetMBlockEndAddr(block);
}

NNSiFndExpHeapMBlockHead *RemoveMBlock(NNSiFndExpMBlockList *list, NNSiFndExpHeapMBlockHead *block) {
    NNSiFndExpHeapMBlockHead *const prev = block->pMBHeadPrev;
    NNSiFndExpHeapMBlockHead *const next = block->pMBHeadNext;
    if (prev) {
        prev->pMBHeadNext = next;
    } else {
        list->head = next;
    }
    if (next) {
        next->pMBHeadPrev = prev;
    } else {
        list->tail = prev;
    }
    return prev;
}

NNSiFndExpHeapMBlockHead *InsertMBlock(NNSiFndExpMBlockList *list, NNSiFndExpHeapMBlockHead *target,
                                              NNSiFndExpHeapMBlockHead *prev) {
    NNSiFndExpHeapMBlockHead *next;
    target->pMBHeadPrev = prev;
    if (prev) {
        next = prev->pMBHeadNext;
        prev->pMBHeadNext = target;
    } else {
        next = list->head;
        list->head = target;
    }
    target->pMBHeadNext = next;
    if (next) {
        next->pMBHeadPrev = target;
    } else {
        list->tail = target;
    }
    return target;
}

NNSiFndExpHeapMBlockHead *InitMBlock(const NNSiMemRegion *pRegion, u16 signature) {
    NNSiFndExpHeapMBlockHead *block = pRegion->start;
    block->signature = signature;
    block->attribute = 0;
    block->blkSize = GetOffsetFromPtr(GetMemPtrForMBlock(block), pRegion->end);
    block->pMBHeadPrev = NULL;
    block->pMBHeadNext = NULL;
    return block;
}

NNSiFndHeapHead *InitExpHeap(void *startAddress, void *endAddress, u16 optFlag) {
    NNSiFndHeapHead *pHeapHd = startAddress;
    NNSiFndExpHeapHead *pExpHeapHd = GetExpHeapHeadPtrFromHeapHead(pHeapHd);

    NNSi_FndInitHeapHead(pHeapHd, NNSI_EXPHEAP_SIGNATURE, AddU32ToPtr(pExpHeapHd, sizeof(NNSiFndExpHeapHead)),
                         endAddress, optFlag);

    pExpHeapHd->groupID = DEFAULT_GROUPID;
    pExpHeapHd->feature = 0;
    SetAllocMode(pExpHeapHd, 0);

    {
        NNSiFndExpHeapMBlockHead *pMBHead;
        NNSiMemRegion region;
        region.start = pHeapHd->heapStart;
        region.end = pHeapHd->heapEnd;
        pMBHead = InitFreeMBlock(&region);

        pExpHeapHd->mbFreeList.head = pMBHead;
        pExpHeapHd->mbFreeList.tail = pMBHead;
        pExpHeapHd->mbUsedList.head = NULL;
        pExpHeapHd->mbUsedList.tail = NULL;
    }
    return pHeapHd;
}

// This file is built with dsi/1.1 (see tools/mwcc_versions.py), so it uses the SDK's own form of the bit-field
// macro here rather than the dsi/1.3p1 workaround in heapcommon.h.
#define NNSi_FndSetBitValueSDK(data, st, bits, val)               \
    do {                                                          \
        u32 maskBits = (u32)((1 << (bits)) - 1);                  \
        u32 newVal = (val) & maskBits;                            \
        (void)(maskBits <<= st);                                  \
        data &= ~maskBits;                                        \
        data |= newVal << (st);                                   \
    } while (FALSE)

static inline void SetAllocDirForMBlockSDK(NNSiFndExpHeapMBlockHead *pMBlkHd, u16 mode) {
    NNSi_FndSetBitValueSDK(pMBlkHd->attribute, 15, 1, mode);
}

static inline void SetAlignmentForMBlockSDK(NNSiFndExpHeapMBlockHead *pMBlkHd, u16 alignment) {
    NNSi_FndSetBitValueSDK(pMBlkHd->attribute, 8, 7, alignment);
}

static inline void SetGroupIDForMBlockSDK(NNSiFndExpHeapMBlockHead *pMBlkHd, u16 id) {
    NNSi_FndSetBitValueSDK(pMBlkHd->attribute, 0, 8, id);
}

void *AllocUsedBlockFromFreeBlock(NNSiFndExpHeapHead *pEHHead, NNSiFndExpHeapMBlockHead *pMBHeadFree,
                                  void *mblock, u32 size, u16 direction) {
    NNSiMemRegion freeRgnT;
    NNSiMemRegion freeRgnB;
    NNSiFndExpHeapMBlockHead *pMBHeadFreePrev;

    GetRegionOfMBlock(&freeRgnT, pMBHeadFree);
    freeRgnB.end = freeRgnT.end;
    freeRgnB.start = AddU32ToPtr(mblock, size);
    freeRgnT.end = SubU32ToPtr(mblock, sizeof(NNSiFndExpHeapMBlockHead));

    pMBHeadFreePrev = RemoveMBlock(&pEHHead->mbFreeList, pMBHeadFree);

    if (GetOffsetFromPtr(freeRgnT.start, freeRgnT.end) < sizeof(NNSiFndExpHeapMBlockHead) + MIN_FREE_BLOCK_SIZE) {
        freeRgnT.end = freeRgnT.start;
    } else {
        pMBHeadFreePrev = InsertMBlock(&pEHHead->mbFreeList, InitFreeMBlock(&freeRgnT), pMBHeadFreePrev);
    }

    if (GetOffsetFromPtr(freeRgnB.start, freeRgnB.end) < sizeof(NNSiFndExpHeapMBlockHead) + MIN_FREE_BLOCK_SIZE) {
        freeRgnB.start = freeRgnB.end;
    } else {
        (void)InsertMBlock(&pEHHead->mbFreeList, InitFreeMBlock(&freeRgnB), pMBHeadFreePrev);
    }

    FillAllocMemory(GetHeapHeadPtrFromExpHeapHead(pEHHead), freeRgnT.end, GetOffsetFromPtr(freeRgnT.end, freeRgnB.start));

    {
        NNSiFndExpHeapMBlockHead *pMBHeadNewUsed;
        NNSiMemRegion region;

        region.start = SubU32ToPtr(mblock, sizeof(NNSiFndExpHeapMBlockHead));
        region.end = freeRgnB.start;

        pMBHeadNewUsed = InitUsedMBlock(&region);
        SetAllocDirForMBlockSDK(pMBHeadNewUsed, direction);
        SetAlignmentForMBlockSDK(pMBHeadNewUsed, (u16)GetOffsetFromPtr(freeRgnT.end, pMBHeadNewUsed));
        SetGroupIDForMBlockSDK(pMBHeadNewUsed, pEHHead->groupID);
        AppendMBlock(&pEHHead->mbUsedList, pMBHeadNewUsed);
    }

    return mblock;
}
