#include "nnsys/snd/heap.h"

#include "nnsys/fnd/frameheap.h"

u32 SND_GetCurrentCommandTag(void);
void SND_FlushCommand(int a);
void SND_WaitForCommandProc(u32 a);

static void func_02030834(NNSFndList *list);
static BOOL func_02030878(NNSSndHeap *self);
static void func_020308b4(void);

NNSSndHeap *NNS_SndHeapCreate(void *mem, u32 size) {
    u32 end = (u32)mem + size;
    u32 start = ((u32)mem + 3) & ~3;
    void *heap;
    if (start > end) {
        return NULL;
    }
    if (end - start < sizeof(NNSSndHeap)) {
        return NULL;
    }
    heap = NNS_FndCreateFrmHeapEx((void *)(start + sizeof(NNSSndHeap)), end - start - sizeof(NNSSndHeap), 0);
    if (heap == NULL) {
        return NULL;
    }
    if (func_02030844((NNSSndHeap *)start, heap)) {
        return (NNSSndHeap *)start;
    }
    NNS_FndDestroyFrmHeap(heap);
    return NULL;
}

void NNS_SndHeapDestroy(NNSSndHeap *self) {
    NNS_SndHeapClear(self);
    NNS_FndDestroyFrmHeap(self->heap);
}

void NNS_SndHeapClear(NNSSndHeap *self) {
    NNSSndHeapFrame *group;
    BOOL calledDestructor = FALSE;
    NNSSndHeapBlock *item;

    for (group = NNS_FndGetPrevListObject(&self->groups, NULL); group != NULL; group = NNS_FndGetPrevListObject(&self->groups, NULL)) {
        for (item = NNS_FndGetPrevListObject(&group->items, NULL); item != NULL; item = NNS_FndGetPrevListObject(&group->items, item)) {
            if (item->destructor != NULL) {
                item->destructor(item + 1, item->size, item->arg0, item->arg1);
                calledDestructor = TRUE;
            }
        }
        NNS_FndRemoveListObject(&self->groups, group);
    }
    NNS_FndFreeToFrmHeap(self->heap, NNS_FND_FRMHEAP_FREE_ALL);
    if (calledDestructor) {
        func_020308b4();
    }
    func_02030878(self);
}

void *NNS_SndHeapAlloc(NNSSndHeap *self, u32 size, NNSSndHeapDisposeCallback destructor, u32 arg0, u32 arg1) {
    NNSSndHeapBlock *item = NNS_FndAllocFromFrmHeapEx(self->heap, ((size + 0x1f) & ~0x1f) + sizeof(NNSSndHeapBlock), 0x20);
    NNSSndHeapFrame *group;
    if (item == NULL) {
        return NULL;
    }
    group = NNS_FndGetPrevListObject(&self->groups, NULL);
    item->size = size;
    item->destructor = destructor;
    item->arg0 = arg0;
    item->arg1 = arg1;
    NNS_FndAppendListObject(&group->items, item);
    return item + 1;
}

int NNS_SndHeapSaveState(NNSSndHeap *self) {
    if (!NNS_FndRecordStateForFrmHeap(self->heap, self->groups.numObjects)) {
        return -1;
    }
    if (func_02030878(self)) {
        return self->groups.numObjects - 1;
    }
    NNS_FndFreeByStateToFrmHeap(self->heap, 0);
    return -1;
}

void NNS_SndHeapLoadState(NNSSndHeap *self, int level) {
    NNSSndHeapFrame *group;
    BOOL calledDestructor;
    NNSSndHeapBlock *item;

    item = NULL;
    calledDestructor = FALSE;
    if (level == 0) {
        NNS_SndHeapClear(self);
        return;
    }
    while (level < self->groups.numObjects) {
        group = NNS_FndGetPrevListObject(&self->groups, NULL);
        while ((item = NNS_FndGetPrevListObject(&group->items, item)) != NULL) {
            if (item->destructor != NULL) {
                item->destructor(item + 1, item->size, item->arg0, item->arg1);
                calledDestructor = TRUE;
            }
        }
        NNS_FndRemoveListObject(&self->groups, group);
    }
    NNS_FndFreeByStateToFrmHeap(self->heap, level);
    if (calledDestructor) {
        func_020308b4();
    }
    NNS_FndRecordStateForFrmHeap(self->heap, self->groups.numObjects);
    func_02030878(self);
}

u32 NNS_SndHeapGetFreeSize(NNSSndHeap *self) {
    u32 size = NNS_FndGetAllocatableSizeForFrmHeapEx(self->heap, 0x20);
    if (size < sizeof(NNSSndHeapBlock)) {
        return 0;
    }
    return (size - sizeof(NNSSndHeapBlock)) & ~0x1f;
}

static void func_02030834(NNSFndList *list) {
    NNS_FndInitList(list, 0);
}

BOOL func_02030844(NNSSndHeap *self, void *heap) {
    NNS_FndInitList(&self->groups, 0xc);
    self->heap = heap;
    return func_02030878(self) ? TRUE : FALSE;
}

static BOOL func_02030878(NNSSndHeap *self) {
    NNSSndHeapFrame *group = NNS_FndAllocFromFrmHeapEx(self->heap, sizeof(NNSSndHeapFrame), 4);
    if (group == NULL) {
        return FALSE;
    }
    func_02030834(&group->items);
    NNS_FndAppendListObject(&self->groups, group);
    return TRUE;
}

static void func_020308b4(void) {
    u32 state = SND_GetCurrentCommandTag();
    SND_FlushCommand(1);
    SND_WaitForCommandProc(state);
}
