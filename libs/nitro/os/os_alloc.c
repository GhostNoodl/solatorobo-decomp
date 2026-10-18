#include "nitro/os.h"
#include "nitro/os_alloc.h"

#define OS_ERR_ALLOCFROMHEAP_NOHEAP         "OS_AllocFromHeap(): heap is not initialized."
#define OS_ERR_ALLOCFROMHEAP_INVSIZE        "OS_AllocFromHeap(): invalid size."
#define OS_ERR_ALLOCFROMHEAP_INVHEAP        "OS_AllocFromHeap(): invalid heap handle."
#define OS_ERR_ALLOCFROMHEAP_BROKENHEAP     "OS_AllocFromHeap(): heap is broken."
#define OS_ERR_ALLOCFIXED_NOHEAP            "OS_AllocFixed(): heap is not initialized."
#define OS_ERR_ALLOCFIXED_INVRANGE          "OS_AllocFixed(): invalid range."
#define OS_ERR_FREETOHEAP_NOHEAP            "OS_FreeToHeap(): heap is not initialized."
#define OS_ERR_FREETOHEAP_INVPTR            "OS_FreeToHeap(): invalid pointer."
#define OS_ERR_FREETOHEAP_INVHEAP           "OS_FreeToHeap(): invalid heap handle."
#define OS_ERR_SETCURRENTHEAP_NOHEAP        "OS_SetCurrentHeap(): heap is not initialized."
#define OS_ERR_SETCURRENTHEAP_INVHEAP       "OS_SetCurrentHeap(): invalid heap handle."
#define OS_ERR_INITALLOC_INVNUMHEAPS        "OS_InitAlloc(): invalid number of heaps."
#define OS_ERR_INITALLOC_INVRANGE           "OS_InitAlloc(): invalid range."
#define OS_ERR_INITALLOC_INSRANGE           "OS_InitAlloc(): too small range."
#define OS_ERR_CLEARALLOC_INVID             "OS_ClearAlloc(): invalid arena id."
#define OS_ERR_CREATEHEAP_NOHEAP            "OS_CreateHeap(): heap is not initialized."
#define OS_ERR_CREATEHEAP_INVRANGE          "OS_CreateHeap(): invalid range."
#define OS_ERR_CREATEHEAP_INSRANGE          "OS_CreateHeap(): too small range."
#define OS_ERR_DESTROYHEAP_NOHEAP           "OS_DestroyHeap(): heap is not initialized."
#define OS_ERR_DESTROYHEAP_INVHEAP          "OS_DestroyHeap(): invalid heap handle."
#define OS_ERR_ADDTOHEAP_NOHEAP             "OS_AddToHeap(): heap is not initialized."
#define OS_ERR_ADDTOHEAP_INVHEAP            "OS_AddToHeap(): invalid heap handle."
#define OS_ERR_ADDTOHEAP_INVRANGE           "OS_AddToHeap(): invalid range."
#define OS_ERR_ADDTOHEAP_INSRANGE           "OS_AddToHeap(): too small range."
#define OS_ERR_REFERENT_NOHEAP              "OS_ReferentSize(): heap is not initialized."
#define OS_ERR_REFERENT_INVPTR              "OS_ReferentSize(): invalid pointer."
#define OS_ERR_DUMPHEAP_NOHEAP              "OS_DumpHeap(): heap is not initialized."
#define OS_ERR_DUMPHEAP_INVHEAP             "OS_DumpHeap(): invalid heap handle."
#define OS_ERR_DUMPHEAP_BROKENHEAP          "OS_DumpHeap(): heap is broken."
#define OS_ERR_ALLOCFROMHEAP_INVID          "OS_AllocFromHeap(): illegal arena id."
#define OS_ERR_ALLOCFROMHEAP_NOINFO         "OS_AllocFromHeap(): heap not initialized."
#define OS_ERR_ALLOCFIXED_INVID             "OS_AllocFixed(): illegal arena id."
#define OS_ERR_ALLOCFIXED_NOINFO            "OS_AllocFixed(): heap not initialized."
#define OS_ERR_FREETOHEAP_INVID             "OS_FreeToHeap(): illegal arena id."
#define OS_ERR_FREETOHEAP_NOINFO            "OS_FreeToHeap(): heap not initialized."
#define OS_ERR_SETCURRENTHEAP_INVID         "OS_SetCurrentHeap(): illegal arena id."
#define OS_ERR_SETCURRENTHEAP_NOINFO        "OS_SetCurrentHeap(): heap not initialized."
#define OS_ERR_INITALLOC_INVID              "OS_SetInitAlloc(): illegal arena id."
#define OS_ERR_INITALLOC_INVINFO            "OS_SetInitAlloc(): heap already initialized."
#define OS_ERR_CREATEHEAP_INVID             "OS_CreateHeap(): illegal arena id."
#define OS_ERR_CREATEHEAP_NOINFO            "OS_CreateHeap(): heap not initialized."
#define OS_ERR_DESTROYHEAP_INVID            "OS_DestroyHeap(): illegal arena id."
#define OS_ERR_DESTROYHEAP_NOINFO           "OS_DestroyHeap(): heap not initialized."
#define OS_ERR_ADDTOHEAP_INVID              "OS_AddToHeap(): illegal arena id."
#define OS_ERR_ADDTOHEAP_NOINFO             "OS_AddToHeap(): heap not initialized."
#define OS_ERR_CHECKHEAP_INVID              "OS_CheckHeap(): illegal arena id."
#define OS_ERR_CHECKHEAP_NOINFO             "OS_CheckHeap(): heap not initialized."
#define OS_ERR_REFERENTSIZE_INVID           "OS_ReferentSize(): illegal arena id."
#define OS_ERR_REFERENTSIZE_NOINFO          "OS_ReferrentSize(): heap not initialized."
#define OS_ERR_DUMPHEAP_INVID               "OS_DumpHeap(): illegal arena id."
#define OS_ERR_DUMPHEAP_NOINFO              "OS_DumpHeap(): heap not initialized."
#define OS_ERR_VISITALLOCATED_INVID         "OS_VisitAllocated(): illegal arena id."
#define OS_ERR_VISITALLOCATED_NOINFO        "OS_VisitAllocated(): heap not initialized."

#define OFFSET(n, a)    (((u32) (n)) & ((a) - 1))
#define TRUNC(n, a)     (((u32) (n)) & ~((a) - 1))
#define ROUND(n, a)     (((u32) (n) + (a) - 1) & ~((a) - 1))

#define ALIGNMENT       32
#define MINOBJSIZE      (HEADERSIZE + ALIGNMENT)
#define HEADERSIZE      ROUND(sizeof(Cell), ALIGNMENT)

#define InRange(targ, a, b)                                             \
    ((u32)(a) <= (u32)(targ) && (u32)(targ) < (u32)(b))

#define RangeOverlap(aStart, aEnd, bStart, bEnd)                        \
    ((u32)(bStart) <= (u32)(aStart) && (u32)(aStart) < (u32)(bEnd) ||   \
     (u32)(bStart) < (u32)(aEnd) && (u32)(aEnd) <= (u32)(bEnd))

#define RangeSubset(aStart, aEnd, bStart, bEnd)                         \
    ((u32)(bStart) <= (u32)(aStart) && (u32)(aEnd) <= (u32)(bEnd))

typedef struct Cell Cell;
typedef struct HeapDesc HeapDesc;

struct Cell {
    Cell * prev;
    Cell * next;
    long size;
};

struct HeapDesc {
    long size;
    Cell * free;
    Cell * allocated;
};

typedef struct {
    volatile OSHeapHandle currentHeap;
    int numHeaps;
    void * arenaStart;
    void * arenaEnd;
    HeapDesc * heapArray;
} OSHeapInfo;

void * OSiHeapInfo[OS_ARENA_MAX] = {
    NULL,
    NULL,
    NULL,
    NULL,
    NULL,
    NULL,
    NULL,
    NULL,
    NULL
};

static Cell * DLAddFront (Cell * list, Cell * cell)
{
    cell->next = list;
    cell->prev = NULL;

    if (list) {
        list->prev = cell;
    }

    return cell;
}

static Cell * DLExtract (Cell * list, Cell * cell)
{
    if (cell->next) {
        cell->next->prev = cell->prev;
    }

    if (cell->prev == NULL) {
        return cell->next;
    } else {
        cell->prev->next = cell->next;
        return list;
    }
}

void * OS_AllocFromHeap (OSArenaId id, OSHeapHandle heap, u32 size)
{
    OSHeapInfo * heapInfo;
    HeapDesc * hd;
    Cell * cell;
    Cell * newCell;
    long leftoverSize;
    OSIntrMode enabled = OS_DisableInterrupts();

    heapInfo = OSiHeapInfo[id];

    if (!heapInfo) {
        (void)OS_RestoreInterrupts(enabled);
        return NULL;
    }

    if (heap < 0) {
        heap = heapInfo->currentHeap;
    }

    hd = &heapInfo->heapArray[heap];

    size += HEADERSIZE;
    size = ROUND(size, ALIGNMENT);

    for (cell = hd->free; cell != NULL; cell = cell->next) {
        if ((long)size <= cell->size) {
            break;
        }
    }

    if (cell == NULL) {
        (void)OS_RestoreInterrupts(enabled);
        return NULL;
    }

    leftoverSize = cell->size - (long)size;

    if (leftoverSize < MINOBJSIZE) {
        hd->free = DLExtract(hd->free, cell);
    } else {
        cell->size = (long)size;
        newCell = (Cell *) ((char *)cell + size);
        newCell->size = leftoverSize;
        newCell->prev = cell->prev;
        newCell->next = cell->next;

        if (newCell->next != NULL) {
            newCell->next->prev = newCell;
        }

        if (newCell->prev != NULL) {
            newCell->prev->next = newCell;
        } else {
            hd->free = newCell;
        }
    }

    hd->allocated = DLAddFront(hd->allocated, cell);

    (void)OS_RestoreInterrupts(enabled);
    return (void *)((char *)cell + HEADERSIZE);
}

void * OS_InitAlloc (OSArenaId id, void * arenaStart, void * arenaEnd, int maxHeaps)
{
    OSHeapInfo * heapInfo;
    u32 arraySize;
    OSHeapHandle i;
    OSIntrMode enabled = OS_DisableInterrupts();

    heapInfo = arenaStart;
    OSiHeapInfo[id] = heapInfo;

    arraySize = sizeof(HeapDesc) * maxHeaps;
    heapInfo->heapArray = (void *)((u32)arenaStart + sizeof(OSHeapInfo));
    heapInfo->numHeaps = maxHeaps;

    for (i = 0; i < heapInfo->numHeaps; i++) {
        HeapDesc * hd = &heapInfo->heapArray[i];

        hd->size = -1;
        hd->free = hd->allocated = NULL;
    }

    heapInfo->currentHeap = -1;

    arenaStart = (void *)((char *)heapInfo->heapArray + arraySize);
    arenaStart = (void *)ROUND(arenaStart, ALIGNMENT);

    heapInfo->arenaStart = arenaStart;
    heapInfo->arenaEnd = (void *)TRUNC(arenaEnd, ALIGNMENT);

    (void)OS_RestoreInterrupts(enabled);
    return heapInfo->arenaStart;
}

#ifndef SDK_NO_MESSAGE
    #define OSi_CHECK(exp)                                                       \
        do                                                                       \
        {                                                                        \
            if ( !(exp))                                                         \
            {                                                                    \
                OS_Printf("OS_CheckHeap: Failed " #exp " in %d\n", __LINE__);    \
                goto exit_OS_CheckHeap;  \
            }                                                                    \
        } while (0)
#else
    #define OSi_CHECK(exp)                                                       \
        do                                                                       \
        {                                                                        \
            if ( !(exp))                                                         \
            {                                                                    \
                goto exit_OS_CheckHeap;                                          \
            }                                                                    \
        } while (0)
#endif
