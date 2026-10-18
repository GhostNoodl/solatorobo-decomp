/* TWL SDK additions next to os_alloc: a 16KB extra heap at 0x02000000 on NITRO, and main-memory/VRAM range checks */
#include "nitro/os.h"
#include "nitro/os_alloc.h"

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


extern void *OSiHeapInfo[OS_ARENA_MAX];

typedef struct OSiExtraHeap {
    OSHeapHandle heap;
    OSArenaId arena;
} OSiExtraHeap;

static OSiExtraHeap OSi_ExtraHeap = { -1, (OSArenaId)-1 };

OSHeapHandle func_0201998c(OSArenaId id);
BOOL func_02019a48(u32 addr);
BOOL func_02019a94(u32 addr);

OSHeapHandle func_0201998c (OSArenaId id)
{
    int i;
    OSIntrMode enabled = OS_DisableInterrupts();
    OSHeapInfo * heapInfo = OSiHeapInfo[id];

    if (!OS_IsRunOnTwl() && OSi_ExtraHeap.heap < 0) {
        for (i = 0; i < heapInfo->numHeaps; i++) {
            HeapDesc * hd = &heapInfo->heapArray[i];
            if (hd->size < 0) {
                Cell * cell = (Cell *)0x02000000;
                hd->size = 0x4000;
                cell->prev = NULL;
                cell->next = NULL;
                cell->size = 0x4000;
                hd->free = cell;
                hd->allocated = NULL;
                OSi_ExtraHeap.heap = i;
                OSi_ExtraHeap.arena = id;
                (void)OS_RestoreInterrupts(enabled);
                return i;
            }
        }
    }

    (void)OS_RestoreInterrupts(enabled);
    return -1;
}

BOOL func_02019a48 (u32 addr)
{
    if (OS_IsRunOnTwl()) {
        return (0x0d000000 <= addr && addr < 0x0e000000) ? TRUE : FALSE;
    } else {
        return (0x02400000 <= addr && addr < 0x02800000) ? TRUE : FALSE;
    }
}

BOOL func_02019a94 (u32 addr)
{
    return (0x05000000 <= addr && addr < 0x07000800) ? TRUE : FALSE;
}
