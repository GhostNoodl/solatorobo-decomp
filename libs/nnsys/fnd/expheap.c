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
