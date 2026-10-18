#include "nnsys/gfd.h"

static inline void InitBlockFromRegion_(NNSiGfdLnkVramBlock *pBlk, const NNSiGfdLnkMemRegion *pRegion) {
    pBlk->addr = pRegion->start;
    pBlk->szByte = (u32)(pRegion->end - pRegion->start);
    pBlk->pBlkPrev = NULL;
    pBlk->pBlkNext = NULL;
}

static inline void InitBlockFromPrams_(NNSiGfdLnkVramBlock *pBlk, u32 addr, u32 szByte) {
    pBlk->addr = addr;
    pBlk->szByte = szByte;
    pBlk->pBlkPrev = NULL;
    pBlk->pBlkNext = NULL;
}

static inline void InsertBlock_(NNSiGfdLnkVramBlock **pListHead, NNSiGfdLnkVramBlock *prev) {
    if ((*pListHead) != NULL) {
        (*pListHead)->pBlkPrev = prev;
    }
    prev->pBlkNext = *pListHead;
    prev->pBlkPrev = NULL;
    *pListHead = prev;
}

static inline void RemoveBlock_(NNSiGfdLnkVramBlock **pListHead, NNSiGfdLnkVramBlock *pBlk) {
    NNSiGfdLnkVramBlock *const pPrev = pBlk->pBlkPrev;
    NNSiGfdLnkVramBlock *const pNext = pBlk->pBlkNext;

    if (pPrev) {
        pPrev->pBlkNext = pNext;
    } else {
        *pListHead = pNext;
    }
    if (pNext) {
        pNext->pBlkPrev = pPrev;
    }
}

static inline NNSiGfdLnkVramBlock *GetNewBlock_(NNSiGfdLnkVramBlock **ppBlockPoolList) {
    NNSiGfdLnkVramBlock *pNew = *ppBlockPoolList;
    if (pNew) {
        *ppBlockPoolList = pNew->pBlkNext;
    }
    return pNew;
}

static inline u32 GetBlockEndAddr_(NNSiGfdLnkVramBlock *pBlk) {
    return (u32)(pBlk->addr + pBlk->szByte);
}

static BOOL TryToMergeBlockRegion_(NNSiGfdLnkVramMan *pMan, NNSiGfdLnkVramBlock **ppBlockPoolList, NNSiGfdLnkMemRegion *pRegion) {
    NNSiGfdLnkVramBlock *pCursor = pMan->pFreeList;
    NNSiGfdLnkVramBlock *pNext = NULL;
    BOOL bMerged = FALSE;

    while (pCursor) {
        pNext = pCursor->pBlkNext;

        if (pCursor->addr == pRegion->end) {
            pRegion->end = GetBlockEndAddr_(pCursor);
            RemoveBlock_(&pMan->pFreeList, pCursor);
            InsertBlock_(ppBlockPoolList, pCursor);
            bMerged |= TRUE;
        }

        if (GetBlockEndAddr_(pCursor) == pRegion->start) {
            pRegion->start = pCursor->addr;
            RemoveBlock_(&pMan->pFreeList, pCursor);
            InsertBlock_(ppBlockPoolList, pCursor);
            bMerged |= TRUE;
        }

        pCursor = pNext;
    }
    return bMerged;
}

void NNSi_GfdInitLnkVramMan(NNSiGfdLnkVramMan *pMgr) {
    pMgr->pFreeList = NULL;
}

NNSiGfdLnkVramBlock *NNSi_GfdInitLnkVramBlockPool(NNSiGfdLnkVramBlock *pArrayHead, u32 lengthOfArray) {
    int i;
    for (i = 0; i < lengthOfArray - 1; i++) {
        pArrayHead[i].pBlkNext = &pArrayHead[i + 1];
        pArrayHead[i + 1].pBlkPrev = &pArrayHead[i];
    }
    pArrayHead[0].pBlkPrev = NULL;
    (pArrayHead + lengthOfArray)[-1].pBlkNext = NULL;
    return &pArrayHead[0];
}

BOOL NNSi_GfdAddNewFreeBlock(NNSiGfdLnkVramMan *pMan, NNSiGfdLnkVramBlock **ppBlockPoolList, u32 baseAddr, u32 szByte) {
    NNSiGfdLnkVramBlock *pNew = GetNewBlock_(ppBlockPoolList);
    if (pNew) {
        InitBlockFromPrams_(pNew, baseAddr, szByte);
        InsertBlock_(&pMan->pFreeList, pNew);
        return TRUE;
    } else {
        return FALSE;
    }
}

BOOL NNSi_GfdAllocLnkVram(NNSiGfdLnkVramMan *pMan, NNSiGfdLnkVramBlock **ppBlockPoolList, u32 *pRetAddr, u32 szByte) {
    return NNSi_GfdAllocLnkVramAligned(pMan, ppBlockPoolList, pRetAddr, szByte, 0);
}

// Best fit: picks the smallest free block that can hold the request.
BOOL NNSi_GfdAllocLnkVramAligned(NNSiGfdLnkVramMan *pMan, NNSiGfdLnkVramBlock **ppBlockPoolList, u32 *pRetAddr, u32 szByte, u32 alignment) {
    u32 alignedAddr;
    u32 szNeeded;
    u32 difference;
    u32 foundAddr;
    u32 foundNeeded;
    u32 foundDifference;
    NNSiGfdLnkVramBlock *pBlkFound = NULL;
    NNSiGfdLnkVramBlock *pBlk = pMan->pFreeList;

    while (pBlk) {
        if (alignment > 1) {
            alignedAddr = (u32)((pBlk->addr + (alignment - 1)) & ~(alignment - 1));
            difference = alignedAddr - pBlk->addr;
            szNeeded = szByte + difference;
        } else {
            alignedAddr = pBlk->addr;
            difference = 0;
            szNeeded = szByte;
        }

        if (pBlk->szByte >= szNeeded) {
            if (pBlkFound == NULL || pBlkFound->szByte > pBlk->szByte) {
                foundAddr = alignedAddr;
                foundNeeded = szNeeded;
                foundDifference = difference;
                pBlkFound = pBlk;
            }
        }
        pBlk = pBlk->pBlkNext;
    }

    if (pBlkFound) {
        if (foundDifference > 0) {
            NNSiGfdLnkVramBlock *pNewFreeBlk = GetNewBlock_(ppBlockPoolList);
            if (pNewFreeBlk) {
                InitBlockFromPrams_(pNewFreeBlk, pBlkFound->addr, foundDifference);
                InsertBlock_(&pMan->pFreeList, pNewFreeBlk);
            } else {
                goto NG_CASE;
            }
        }

        pBlkFound->szByte -= foundNeeded;
        pBlkFound->addr += foundNeeded;

        if (pBlkFound->szByte == 0) {
            RemoveBlock_(&pMan->pFreeList, pBlkFound);
            InsertBlock_(ppBlockPoolList, pBlkFound);
        }

        *pRetAddr = foundAddr;
        return TRUE;
    }

NG_CASE:
    *pRetAddr = 0;
    return FALSE;
}

void NNSi_GfdMergeAllFreeBlocks(NNSiGfdLnkVramMan *pMan, NNSiGfdLnkVramBlock **ppBlockPoolList) {
    NNSiGfdLnkMemRegion region;
    NNSiGfdLnkVramBlock *pCursor = pMan->pFreeList;

    while (pCursor) {
        region.start = pCursor->addr;
        region.end = pCursor->addr + pCursor->szByte;

        if (TryToMergeBlockRegion_(pMan, ppBlockPoolList, &region)) {
            pCursor->addr = region.start;
            pCursor->szByte = region.end - region.start;
            pCursor = pMan->pFreeList;
        } else {
            pCursor = pCursor->pBlkNext;
        }
    }
}

BOOL NNSi_GfdFreeLnkVram(NNSiGfdLnkVramMan *pMan, NNSiGfdLnkVramBlock **ppBlockPoolList, u32 addr, u32 szByte) {
    NNSiGfdLnkMemRegion region;
    NNSiGfdLnkVramBlock *pNewFreeBlk;

    region.start = addr;
    region.end = addr + szByte;

    (void)TryToMergeBlockRegion_(pMan, ppBlockPoolList, &region);

    pNewFreeBlk = GetNewBlock_(ppBlockPoolList);
    if (pNewFreeBlk == NULL) {
        return FALSE;
    } else {
        InitBlockFromRegion_(pNewFreeBlk, &region);
        InsertBlock_(&pMan->pFreeList, pNewFreeBlk);
    }
    return TRUE;
}
