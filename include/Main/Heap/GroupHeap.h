#ifndef MAIN_HEAP_GROUPHEAP_H
#define MAIN_HEAP_GROUPHEAP_H

#include "types.h"
#include "nnsys/fnd/list.h"

#ifdef __cplusplus
extern "C" {
#endif

// A frame heap whose allocations are grouped into levels. Each allocation can have a destructor, which runs when its
// level is freed.

typedef void (*GroupHeapDestructor)(void *data, u32 size, u32 arg0, u32 arg1);

typedef struct GroupHeapItem {
    /* 0x00 */ NNSFndLink link;
    /* 0x08 */ u32 size;
    /* 0x0c */ GroupHeapDestructor destructor;
    /* 0x10 */ u32 arg0;
    /* 0x14 */ u32 arg1;
    /* 0x18 */ u8 unk_18[8];
} GroupHeapItem; // size 0x20, followed by the item's data

typedef struct GroupHeapGroup {
    /* 0x00 */ NNSFndList items;
    /* 0x0c */ NNSFndLink link;
} GroupHeapGroup; // size 0x14

typedef struct GroupHeap {
    /* 0x00 */ void *heap;
    /* 0x04 */ NNSFndList groups;
} GroupHeap; // size 0x10

GroupHeap *func_0203053c(void *mem, u32 size);
void func_020305b0(GroupHeap *self);
void func_020305c8(GroupHeap *self);
void *func_02030684(GroupHeap *self, u32 size, GroupHeapDestructor destructor, u32 arg0, u32 arg1);
int func_020306ec(GroupHeap *self);
void func_0203073c(GroupHeap *self, int level);
u32 func_02030810(GroupHeap *self);
BOOL func_02030844(GroupHeap *self, void *heap);

#ifdef __cplusplus
}
#endif

#endif
