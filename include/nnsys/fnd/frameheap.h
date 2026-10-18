#ifndef NNSYS_FND_FRAMEHEAP_H
#define NNSYS_FND_FRAMEHEAP_H

#include "types.h"

#ifdef __cplusplus
extern "C" {
#endif

#include "nnsys/fnd/heapcommon.h"

#define NNS_FND_FRMHEAP_FREE_HEAD (1 << 0)
#define NNS_FND_FRMHEAP_FREE_TAIL (1 << 1)
#define NNS_FND_FRMHEAP_FREE_ALL  (NNS_FND_FRMHEAP_FREE_HEAD | NNS_FND_FRMHEAP_FREE_TAIL)

NNSFndHeapHandle NNS_FndCreateFrmHeapEx(void *startAddress, u32 size, u16 optFlag);
void NNS_FndDestroyFrmHeap(NNSFndHeapHandle heap);
void *NNS_FndAllocFromFrmHeapEx(NNSFndHeapHandle heap, u32 size, int alignment);
void NNS_FndFreeToFrmHeap(NNSFndHeapHandle heap, int mode);
u32 NNS_FndGetAllocatableSizeForFrmHeapEx(NNSFndHeapHandle heap, int alignment);
BOOL NNS_FndRecordStateForFrmHeap(NNSFndHeapHandle heap, u32 tagName);
BOOL NNS_FndFreeByStateToFrmHeap(NNSFndHeapHandle heap, u32 tagName);

#ifdef __cplusplus
}
#endif

#endif
