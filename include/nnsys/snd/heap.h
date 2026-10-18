#ifndef NNSYS_SND_HEAP_H
#define NNSYS_SND_HEAP_H

#include "types.h"
#include "nnsys/fnd/list.h"

#ifdef __cplusplus
extern "C" {
#endif

// NitroSystem sound heap (NNS_SndHeap*): a frame heap whose allocations are grouped into levels. Each allocation can
// have a dispose callback, which runs when its level is freed.

typedef void (*NNSSndHeapDisposeCallback)(void *data, u32 size, u32 arg0, u32 arg1);

typedef struct NNSSndHeapBlock {
    /* 0x00 */ NNSFndLink link;
    /* 0x08 */ u32 size;
    /* 0x0c */ NNSSndHeapDisposeCallback destructor;
    /* 0x10 */ u32 arg0;
    /* 0x14 */ u32 arg1;
    /* 0x18 */ u8 unk_18[8];
} NNSSndHeapBlock; // size 0x20, followed by the item's data

typedef struct NNSSndHeapFrame {
    /* 0x00 */ NNSFndList items;
    /* 0x0c */ NNSFndLink link;
} NNSSndHeapFrame; // size 0x14

typedef struct NNSSndHeap {
    /* 0x00 */ void *heap;
    /* 0x04 */ NNSFndList groups;
} NNSSndHeap; // size 0x10

NNSSndHeap *NNS_SndHeapCreate(void *mem, u32 size);
void NNS_SndHeapDestroy(NNSSndHeap *self);
void NNS_SndHeapClear(NNSSndHeap *self);
void *NNS_SndHeapAlloc(NNSSndHeap *self, u32 size, NNSSndHeapDisposeCallback destructor, u32 arg0, u32 arg1);
int NNS_SndHeapSaveState(NNSSndHeap *self);
void NNS_SndHeapLoadState(NNSSndHeap *self, int level);
u32 NNS_SndHeapGetFreeSize(NNSSndHeap *self);
BOOL func_02030844(NNSSndHeap *self, void *heap);

#ifdef __cplusplus
}
#endif

#endif
