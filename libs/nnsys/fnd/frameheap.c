#include "nnsys/fnd/frameheap.h"

#define NNSI_FRMHEAP_SIGNATURE ('FRMH')
#define MIN_ALIGNMENT 4

int abs(int n);

typedef struct NNSiFndFrmHeapState NNSiFndFrmHeapState;
struct NNSiFndFrmHeapState {
    /* 0x0 */ u32 tagName;
    /* 0x4 */ void *headAllocator;
    /* 0x8 */ void *tailAllocator;
    /* 0xc */ NNSiFndFrmHeapState *pPrevState;
};

typedef struct NNSiFndFrmHeapHead {
    /* 0x0 */ void *headAllocator;
    /* 0x4 */ void *tailAllocator;
    /* 0x8 */ NNSiFndFrmHeapState *pState;
} NNSiFndFrmHeapHead;

static inline void *AddU32ToPtr(void *ptr, u32 val) {
    return (void *)(NNSiGetUIntPtr(ptr) + val);
}

static inline void *SubU32ToPtr(void *ptr, u32 val) {
    return (void *)(NNSiGetUIntPtr(ptr) - val);
}

static inline u32 GetOffsetFromPtr(const void *start, const void *end) {
    return NNSiGetUIntPtr(end) - NNSiGetUIntPtr(start);
}

static inline NNSiFndFrmHeapHead *GetFrmHeapHeadPtrFromHeapHead(NNSiFndHeapHead *pHHead) {
    return AddU32ToPtr(pHHead, sizeof(NNSiFndHeapHead));
}

static inline NNSiFndHeapHead *GetHeapHeadPtrFromFrmHeapHead(NNSiFndFrmHeapHead *pFrmHeapHd) {
    return SubU32ToPtr(pFrmHeapHd, sizeof(NNSiFndHeapHead));
}

static inline u16 GetOptForHeap(const NNSiFndHeapHead *pHeapHd) {
    return (u16)NNSi_FndGetBitValue(pHeapHd->attribute, 0, 8);
}

static inline void FillAllocMemory(NNSiFndHeapHead *pHeapHd, void *address, u32 size) {
    if (GetOptForHeap(pHeapHd) & NNS_FND_HEAP_OPT_0_CLEAR) {
        MIi_CpuClear32(0, address, size);
    }
}

static NNSiFndHeapHead *InitFrameHeap(void *startAddress, void *endAddress, u16 optFlag) {
    NNSiFndHeapHead *pHeapHd = startAddress;
    NNSiFndFrmHeapHead *pFrmHeapHd = GetFrmHeapHeadPtrFromHeapHead(pHeapHd);

    NNSi_FndInitHeapHead(pHeapHd, NNSI_FRMHEAP_SIGNATURE, AddU32ToPtr(pFrmHeapHd, sizeof(NNSiFndFrmHeapHead)),
                         endAddress, optFlag);

    pFrmHeapHd->headAllocator = pHeapHd->heapStart;
    pFrmHeapHd->tailAllocator = pHeapHd->heapEnd;
    pFrmHeapHd->pState = NULL;

    return pHeapHd;
}

static void *FrmHeap_AllocFromHead(NNSiFndFrmHeapHead *pFrmHeapHd, u32 size, int alignment) {
    void *newBlock = NNSi_FndRoundUpPtr(pFrmHeapHd->headAllocator, alignment);
    void *endAddress = AddU32ToPtr(newBlock, size);

    if (NNSiGetUIntPtr(endAddress) > NNSiGetUIntPtr(pFrmHeapHd->tailAllocator)) {
        return NULL;
    }

    FillAllocMemory(GetHeapHeadPtrFromFrmHeapHead(pFrmHeapHd), pFrmHeapHd->headAllocator,
                    GetOffsetFromPtr(pFrmHeapHd->headAllocator, endAddress));

    pFrmHeapHd->headAllocator = endAddress;

    return newBlock;
}

static void *FrmHeap_AllocFromTail(NNSiFndFrmHeapHead *pFrmHeapHd, u32 size, int alignment) {
    void *newBlock = NNSi_FndRoundDownPtr(SubU32ToPtr(pFrmHeapHd->tailAllocator, size), alignment);

    if (NNSiGetUIntPtr(newBlock) < NNSiGetUIntPtr(pFrmHeapHd->headAllocator)) {
        return NULL;
    }

    FillAllocMemory(GetHeapHeadPtrFromFrmHeapHead(pFrmHeapHd), newBlock,
                    GetOffsetFromPtr(newBlock, pFrmHeapHd->tailAllocator));

    pFrmHeapHd->tailAllocator = newBlock;

    return newBlock;
}

static void FreeHead(NNSiFndHeapHead *pHeapHd) {
    NNSiFndFrmHeapHead *pFrmHeapHd = GetFrmHeapHeadPtrFromHeapHead(pHeapHd);

    pFrmHeapHd->headAllocator = pHeapHd->heapStart;
    pFrmHeapHd->pState = NULL;
}

static void FreeTail(NNSiFndHeapHead *pHeapHd) {
    NNSiFndFrmHeapHead *pFrmHeapHd = GetFrmHeapHeadPtrFromHeapHead(pHeapHd);

    {
        NNSiFndFrmHeapState *pState;
        for (pState = pFrmHeapHd->pState; pState; pState = pState->pPrevState) {
            pState->tailAllocator = pHeapHd->heapEnd;
        }
    }

    pFrmHeapHd->tailAllocator = pHeapHd->heapEnd;
}

NNSFndHeapHandle NNS_FndCreateFrmHeapEx(void *startAddress, u32 size, u16 optFlag) {
    void *endAddress;

    endAddress = NNSi_FndRoundDownPtr(AddU32ToPtr(startAddress, size), MIN_ALIGNMENT);
    startAddress = NNSi_FndRoundUpPtr(startAddress, MIN_ALIGNMENT);

    if (NNSiGetUIntPtr(startAddress) > NNSiGetUIntPtr(endAddress) ||
        GetOffsetFromPtr(startAddress, endAddress) < sizeof(NNSiFndHeapHead) + sizeof(NNSiFndFrmHeapHead)) {
        return NULL;
    }

    {
        NNSiFndHeapHead *pHeapHd = InitFrameHeap(startAddress, endAddress, optFlag);
        return pHeapHd;
    }
}

void NNS_FndDestroyFrmHeap(NNSFndHeapHandle heap) {
    NNSi_FndFinalizeHeap(heap);
}

void *NNS_FndAllocFromFrmHeapEx(NNSFndHeapHandle heap, u32 size, int alignment) {
    void *memory = NULL;
    NNSiFndFrmHeapHead *pFrmHeapHd = GetFrmHeapHeadPtrFromHeapHead(heap);

    if (size == 0) {
        size = 1;
    }
    size = NNSi_FndRoundUp(size, MIN_ALIGNMENT);

    if (alignment >= 0) {
        memory = FrmHeap_AllocFromHead(pFrmHeapHd, size, alignment);
    } else {
        memory = FrmHeap_AllocFromTail(pFrmHeapHd, size, -alignment);
    }

    return memory;
}

void NNS_FndFreeToFrmHeap(NNSFndHeapHandle heap, int mode) {
    if (mode & NNS_FND_FRMHEAP_FREE_HEAD) {
        FreeHead(heap);
    }
    if (mode & NNS_FND_FRMHEAP_FREE_TAIL) {
        FreeTail(heap);
    }
}

u32 NNS_FndGetAllocatableSizeForFrmHeapEx(NNSFndHeapHandle heap, int alignment) {
    const NNSiFndFrmHeapHead *pFrmHeapHd = GetFrmHeapHeadPtrFromHeapHead(heap);
    const void *block;

    alignment = abs(alignment);

    block = NNSi_FndRoundUpPtr(pFrmHeapHd->headAllocator, alignment);

    if (NNSiGetUIntPtr(block) > NNSiGetUIntPtr(pFrmHeapHd->tailAllocator)) {
        return 0;
    }

    return GetOffsetFromPtr(block, pFrmHeapHd->tailAllocator);
}

BOOL NNS_FndRecordStateForFrmHeap(NNSFndHeapHandle heap, u32 tagName) {
    BOOL bRet = TRUE;
    NNSiFndFrmHeapHead *pFrmHeapHd = GetFrmHeapHeadPtrFromHeapHead(heap);
    void *oldHeadAllocator = pFrmHeapHd->headAllocator;

    NNSiFndFrmHeapState *pState = FrmHeap_AllocFromHead(pFrmHeapHd, sizeof(NNSiFndFrmHeapState), MIN_ALIGNMENT);

    if (!pState) {
        return FALSE;
    }

    pState->tagName = tagName;
    pState->headAllocator = oldHeadAllocator;
    pState->tailAllocator = pFrmHeapHd->tailAllocator;
    pState->pPrevState = pFrmHeapHd->pState;

    pFrmHeapHd->pState = pState;

    return bRet;
}

BOOL NNS_FndFreeByStateToFrmHeap(NNSFndHeapHandle heap, u32 tagName) {
    NNSiFndFrmHeapHead *pFrmHeapHd = GetFrmHeapHeadPtrFromHeapHead(heap);
    NNSiFndFrmHeapState *pState = pFrmHeapHd->pState;

    if (tagName != 0) {
        for (; pState; pState = pState->pPrevState) {
            if (pState->tagName == tagName) {
                break;
            }
        }
    }

    if (!pState) {
        return FALSE;
    }

    pFrmHeapHd->headAllocator = pState->headAllocator;
    pFrmHeapHd->tailAllocator = pState->tailAllocator;
    pFrmHeapHd->pState = pState->pPrevState;

    return TRUE;
}
