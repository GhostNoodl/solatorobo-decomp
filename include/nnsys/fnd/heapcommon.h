#ifndef NNSYS_FND_HEAPCOMMON_H
#define NNSYS_FND_HEAPCOMMON_H

#include "types.h"
#include "nnsys/fnd/list.h"

#ifdef __cplusplus
extern "C" {
#endif

typedef void *NNSFndHeapHandle;

#define NNS_FND_HEAP_OPT_0_CLEAR (1 << 0)

typedef struct NNSiFndHeapHead {
    /* 0x00 */ u32 signature;
    /* 0x04 */ NNSFndLink link;
    /* 0x0c */ NNSFndList childList;
    /* 0x18 */ void *heapStart;
    /* 0x1c */ void *heapEnd;
    /* 0x20 */ u32 attribute;
} NNSiFndHeapHead; // size 0x24

#define NNSi_FndGetBitValue(data, st, bits) (((data) >> (st)) & ((1 << (bits)) - 1))
// Written with a u32 temporary so dsi/1.3p1 emits the same code as the dsi/1.1 build of the library
#define NNSi_FndSetBitValue(data, st, bits, val)                  \
    do {                                                          \
        u32 maskBits = (u32)((1 << (bits)) - 1);                  \
        u32 newVal = (val) & maskBits;                            \
        u32 bitData = (data);                                     \
        (void)(maskBits <<= st);                                  \
        bitData &= ~maskBits;                                     \
        bitData |= newVal << (st);                                \
        data = bitData;                                           \
    } while (0)

#define NNSi_FndRoundUp(value, alignment)   (((value) + ((alignment) - 1)) & ~((alignment) - 1))
#define NNSi_FndRoundUpPtr(ptr, alignment)  ((void *)NNSi_FndRoundUp(NNSiGetUIntPtr(ptr), (alignment)))
#define NNSi_FndRoundDown(value, alignment) ((value) & ~((alignment) - 1))
#define NNSi_FndRoundDownPtr(ptr, alignment) ((void *)NNSi_FndRoundDown(NNSiGetUIntPtr(ptr), (alignment)))

static inline u32 NNSiGetUIntPtr(const void *ptr) {
    return (u32)ptr;
}

void NNSi_FndInitHeapHead(NNSiFndHeapHead *pHeapHd, u32 signature, void *heapStart, void *heapEnd, u16 optFlag);
void NNSi_FndFinalizeHeap(NNSiFndHeapHead *pHeapHd);
NNSFndHeapHandle NNS_FndFindContainHeap(const void *memBlock);

void MIi_CpuClear32(u32 data, void *dest, u32 size);

#ifdef __cplusplus
}
#endif

#endif
