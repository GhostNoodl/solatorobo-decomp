#ifndef NNSYS_FND_EXPHEAP_H
#define NNSYS_FND_EXPHEAP_H

#include "nnsys/fnd/heapcommon.h"

#ifdef __cplusplus
extern "C" {
#endif

typedef struct NNSiFndExpHeapMBlockHead NNSiFndExpHeapMBlockHead;
struct NNSiFndExpHeapMBlockHead {
    /* 0x00 */ u16 signature;
    /* 0x02 */ u16 attribute;
    /* 0x04 */ u32 blkSize;
    /* 0x08 */ NNSiFndExpHeapMBlockHead *pMBHeadPrev;
    /* 0x0c */ NNSiFndExpHeapMBlockHead *pMBHeadNext;
}; // size 0x10

typedef struct NNSiFndExpMBlockList {
    /* 0x0 */ NNSiFndExpHeapMBlockHead *head;
    /* 0x4 */ NNSiFndExpHeapMBlockHead *tail;
} NNSiFndExpMBlockList;

typedef struct NNSiFndExpHeapHead {
    /* 0x00 */ NNSiFndExpMBlockList mbFreeList;
    /* 0x08 */ NNSiFndExpMBlockList mbUsedList;
    /* 0x10 */ u16 groupID;
    /* 0x12 */ u16 feature;
} NNSiFndExpHeapHead; // size 0x14

NNSFndHeapHandle NNS_FndCreateExpHeapEx(void *startAddress, u32 size, u16 optFlag);
void *NNS_FndAllocFromExpHeapEx(NNSFndHeapHandle heap, u32 size, int alignment);
u32 NNS_FndResizeForMBlockExpHeap(NNSFndHeapHandle heap, void *memBlock, u32 size);
void NNS_FndFreeToExpHeap(NNSFndHeapHandle heap, void *memBlock);

#ifdef __cplusplus
}
#endif

#endif
