#include "expheap_internal.h"

static void *AllocFromHead(NNSiFndHeapHead *pHeapHd, u32 size, int alignment) {
    NNSiFndExpHeapHead *pExpHeapHd = GetExpHeapHeadPtrFromHeapHead(pHeapHd);
    const BOOL bAllocFirst = GetAllocMode(pExpHeapHd) == 0;
    NNSiFndExpHeapMBlockHead *pMBlkHd = NULL;
    NNSiFndExpHeapMBlockHead *pMBlkHdFound = NULL;
    u32 foundSize = 0xffffffff;
    void *foundMBlock = NULL;

    for (pMBlkHd = pExpHeapHd->mbFreeList.head; pMBlkHd; pMBlkHd = pMBlkHd->pMBHeadNext) {
        void *const mblock = GetMemPtrForMBlock(pMBlkHd);
        void *const reqMBlock = NNSi_FndRoundUpPtr(mblock, alignment);
        const u32 offset = GetOffsetFromPtr(mblock, reqMBlock);

        if (pMBlkHd->blkSize >= size + offset && foundSize > pMBlkHd->blkSize) {
            pMBlkHdFound = pMBlkHd;
            foundSize = pMBlkHd->blkSize;
            foundMBlock = reqMBlock;

            if (bAllocFirst || foundSize == size) {
                break;
            }
        }
    }

    if (!pMBlkHdFound) {
        return NULL;
    }

    return AllocUsedBlockFromFreeBlock(pExpHeapHd, pMBlkHdFound, foundMBlock, size, 0);
}

static void *AllocFromTail(NNSiFndHeapHead *pHeapHd, u32 size, int alignment) {
    NNSiFndExpHeapHead *pExpHeapHd = GetExpHeapHeadPtrFromHeapHead(pHeapHd);
    const BOOL bAllocFirst = GetAllocMode(pExpHeapHd) == 0;
    NNSiFndExpHeapMBlockHead *pMBlkHd = NULL;
    NNSiFndExpHeapMBlockHead *pMBlkHdFound = NULL;
    u32 foundSize = 0xffffffff;
    void *foundMBlock = NULL;

    for (pMBlkHd = pExpHeapHd->mbFreeList.tail; pMBlkHd; pMBlkHd = pMBlkHd->pMBHeadPrev) {
        void *const mblock = GetMemPtrForMBlock(pMBlkHd);
        void *const mblockEnd = AddU32ToPtr(mblock, pMBlkHd->blkSize);
        void *const reqMBlock = NNSi_FndRoundDownPtr(SubU32ToPtr(mblockEnd, size), alignment);

        if (ComparePtr(reqMBlock, mblock) >= 0 && foundSize > pMBlkHd->blkSize) {
            pMBlkHdFound = pMBlkHd;
            foundSize = pMBlkHd->blkSize;
            foundMBlock = reqMBlock;

            if (bAllocFirst || foundSize == size) {
                break;
            }
        }
    }

    if (!pMBlkHdFound) {
        return NULL;
    }

    return AllocUsedBlockFromFreeBlock(pExpHeapHd, pMBlkHdFound, foundMBlock, size, 1);
}

static BOOL RecycleRegion(NNSiFndExpHeapHead *pEHHead, const NNSiMemRegion *pRegion) {
    NNSiFndExpHeapMBlockHead *pBlkPrFree = NULL;
    NNSiMemRegion freeRgn = *pRegion;

    {
        NNSiFndExpHeapMBlockHead *pBlk;
        for (pBlk = pEHHead->mbFreeList.head; pBlk; pBlk = pBlk->pMBHeadNext) {
            if (pBlk < pRegion->start) {
                pBlkPrFree = pBlk;
                continue;
            }
            if (pBlk == pRegion->end) {
                freeRgn.end = GetMBlockEndAddr(pBlk);
                (void)RemoveMBlock(&pEHHead->mbFreeList, pBlk);
            }
            break;
        }
    }

    if (pBlkPrFree && GetMBlockEndAddr(pBlkPrFree) == pRegion->start) {
        freeRgn.start = pBlkPrFree;
        pBlkPrFree = RemoveMBlock(&pEHHead->mbFreeList, pBlkPrFree);
    }

    if (GetOffsetFromPtr(freeRgn.start, freeRgn.end) < sizeof(NNSiFndExpHeapMBlockHead)) {
        return FALSE;
    }

    (void)InsertMBlock(&pEHHead->mbFreeList, InitFreeMBlock(&freeRgn), pBlkPrFree);
    return TRUE;
}

NNSFndHeapHandle NNS_FndCreateExpHeapEx(void *startAddress, u32 size, u16 optFlag) {
    void *endAddress;

    endAddress = NNSi_FndRoundDownPtr(AddU32ToPtr(startAddress, size), MIN_ALIGNMENT);
    startAddress = NNSi_FndRoundUpPtr(startAddress, MIN_ALIGNMENT);

    if ((u32)startAddress > (u32)endAddress ||
        GetOffsetFromPtr(startAddress, endAddress) <
            sizeof(NNSiFndHeapHead) + sizeof(NNSiFndExpHeapHead) + sizeof(NNSiFndExpHeapMBlockHead) + MIN_ALIGNMENT) {
        return NULL;
    }

    {
        NNSiFndHeapHead *pHeapHd = InitExpHeap(startAddress, endAddress, optFlag);
        return pHeapHd;
    }
}

void *NNS_FndAllocFromExpHeapEx(NNSFndHeapHandle heap, u32 size, int alignment) {
    void *memory = NULL;

    if (size == 0) {
        size = 1;
    }
    size = NNSi_FndRoundUp(size, MIN_ALIGNMENT);

    if (alignment >= 0) {
        memory = AllocFromHead(heap, size, alignment);
    } else {
        memory = AllocFromTail(heap, size, -alignment);
    }
    return memory;
}

u32 NNS_FndResizeForMBlockExpHeap(NNSFndHeapHandle heap, void *memBlock, u32 size) {
    NNSiFndExpHeapHead *pEHHead;
    NNSiFndExpHeapMBlockHead *pMBHead;

    pEHHead = GetExpHeapHeadPtrFromHeapHead(heap);
    pMBHead = GetMBlockHeadPtr(memBlock);

    size = NNSi_FndRoundUp(size, MIN_ALIGNMENT);
    if (size == pMBHead->blkSize) {
        return size;
    }

    if (size > pMBHead->blkSize) {
        void *crUsedEnd = GetMBlockEndAddr(pMBHead);
        NNSiFndExpHeapMBlockHead *block;

        for (block = pEHHead->mbFreeList.head; block; block = block->pMBHeadNext) {
            if (block == crUsedEnd) {
                break;
            }
        }

        if (!block || size > pMBHead->blkSize + sizeof(NNSiFndExpHeapMBlockHead) + block->blkSize) {
            return 0;
        }

        {
            NNSiMemRegion rgnNewFree;
            void *oldFreeStart;
            NNSiFndExpHeapMBlockHead *nextBlockPrev;

            GetRegionOfMBlock(&rgnNewFree, block);
            nextBlockPrev = RemoveMBlock(&pEHHead->mbFreeList, block);

            oldFreeStart = rgnNewFree.start;
            rgnNewFree.start = AddU32ToPtr(memBlock, size);

            if (GetOffsetFromPtr(rgnNewFree.start, rgnNewFree.end) < sizeof(NNSiFndExpHeapMBlockHead)) {
                rgnNewFree.start = rgnNewFree.end;
            }

            pMBHead->blkSize = GetOffsetFromPtr(memBlock, rgnNewFree.start);

            if (GetOffsetFromPtr(rgnNewFree.start, rgnNewFree.end) >= sizeof(NNSiFndExpHeapMBlockHead)) {
                (void)InsertMBlock(&pEHHead->mbFreeList, InitFreeMBlock(&rgnNewFree), nextBlockPrev);
            }

            FillAllocMemory(heap, oldFreeStart, GetOffsetFromPtr(oldFreeStart, rgnNewFree.start));
        }
    } else {
        NNSiMemRegion rgnNewFree;
        const u32 oldBlockSize = pMBHead->blkSize;

        rgnNewFree.start = AddU32ToPtr(memBlock, size);
        rgnNewFree.end = GetMBlockEndAddr(pMBHead);

        pMBHead->blkSize = size;

        if (!RecycleRegion(pEHHead, &rgnNewFree)) {
            pMBHead->blkSize = oldBlockSize;
        }
    }

    return pMBHead->blkSize;
}

void NNS_FndFreeToExpHeap(NNSFndHeapHandle heap, void *memBlock) {
    NNSiFndHeapHead *pHeapHd = heap;
    NNSiFndExpHeapHead *pExpHeapHd = GetExpHeapHeadPtrFromHeapHead(pHeapHd);
    NNSiFndExpHeapMBlockHead *pMBHead = GetMBlockHeadPtr(memBlock);
    NNSiMemRegion region;

    GetRegionOfMBlock(&region, pMBHead);
    (void)RemoveMBlock(&pExpHeapHd->mbUsedList, pMBHead);
    (void)RecycleRegion(pExpHeapHd, &region);
}
