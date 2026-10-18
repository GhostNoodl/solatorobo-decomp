#include "Main/Heap/GroupHeap.h"

#include "nnsys/fnd/frameheap.h"

u32 func_0201c61c(void);
void func_0201c414(int a);
void func_0201c5b0(u32 a);

static void func_02030834(NNSFndList *list);
static BOOL func_02030878(GroupHeap *self);
static void func_020308b4(void);

GroupHeap *func_0203053c(void *mem, u32 size) {
    u32 end = (u32)mem + size;
    u32 start = ((u32)mem + 3) & ~3;
    void *heap;
    if (start > end) {
        return NULL;
    }
    if (end - start < sizeof(GroupHeap)) {
        return NULL;
    }
    heap = NNS_FndCreateFrmHeapEx((void *)(start + sizeof(GroupHeap)), end - start - sizeof(GroupHeap), 0);
    if (heap == NULL) {
        return NULL;
    }
    if (func_02030844((GroupHeap *)start, heap)) {
        return (GroupHeap *)start;
    }
    NNS_FndDestroyFrmHeap(heap);
    return NULL;
}

void func_020305b0(GroupHeap *self) {
    func_020305c8(self);
    NNS_FndDestroyFrmHeap(self->heap);
}

void func_020305c8(GroupHeap *self) {
    GroupHeapGroup *group;
    BOOL calledDestructor = FALSE;
    GroupHeapItem *item;

    for (group = NNS_FndGetNextListObject(&self->groups, NULL); group != NULL; group = NNS_FndGetNextListObject(&self->groups, NULL)) {
        for (item = NNS_FndGetNextListObject(&group->items, NULL); item != NULL; item = NNS_FndGetNextListObject(&group->items, item)) {
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

void *func_02030684(GroupHeap *self, u32 size, GroupHeapDestructor destructor, u32 arg0, u32 arg1) {
    GroupHeapItem *item = NNS_FndAllocFromFrmHeapEx(self->heap, ((size + 0x1f) & ~0x1f) + sizeof(GroupHeapItem), 0x20);
    GroupHeapGroup *group;
    if (item == NULL) {
        return NULL;
    }
    group = NNS_FndGetNextListObject(&self->groups, NULL);
    item->size = size;
    item->destructor = destructor;
    item->arg0 = arg0;
    item->arg1 = arg1;
    NNS_FndAppendListObject(&group->items, item);
    return item + 1;
}

int func_020306ec(GroupHeap *self) {
    if (!NNS_FndRecordStateForFrmHeap(self->heap, self->groups.numObjects)) {
        return -1;
    }
    if (func_02030878(self)) {
        return self->groups.numObjects - 1;
    }
    NNS_FndFreeByStateToFrmHeap(self->heap, 0);
    return -1;
}

void func_0203073c(GroupHeap *self, int level) {
    GroupHeapGroup *group;
    BOOL calledDestructor;
    GroupHeapItem *item;

    item = NULL;
    calledDestructor = FALSE;
    if (level == 0) {
        func_020305c8(self);
        return;
    }
    while (level < self->groups.numObjects) {
        group = NNS_FndGetNextListObject(&self->groups, NULL);
        while ((item = NNS_FndGetNextListObject(&group->items, item)) != NULL) {
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

u32 func_02030810(GroupHeap *self) {
    u32 size = NNS_FndGetAllocatableSizeForFrmHeapEx(self->heap, 0x20);
    if (size < sizeof(GroupHeapItem)) {
        return 0;
    }
    return (size - sizeof(GroupHeapItem)) & ~0x1f;
}

static void func_02030834(NNSFndList *list) {
    NNS_FndInitList(list, 0);
}

BOOL func_02030844(GroupHeap *self, void *heap) {
    NNS_FndInitList(&self->groups, 0xc);
    self->heap = heap;
    return func_02030878(self) ? TRUE : FALSE;
}

static BOOL func_02030878(GroupHeap *self) {
    GroupHeapGroup *group = NNS_FndAllocFromFrmHeapEx(self->heap, sizeof(GroupHeapGroup), 4);
    if (group == NULL) {
        return FALSE;
    }
    func_02030834(&group->items);
    NNS_FndAppendListObject(&self->groups, group);
    return TRUE;
}

static void func_020308b4(void) {
    u32 state = func_0201c61c();
    func_0201c414(1);
    func_0201c5b0(state);
}
