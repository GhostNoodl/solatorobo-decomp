#include "Main/Res/ResMgr.h"
#include "Main/Save/SysCard.h"
#include "nnsys/fnd/expheap.h"
#include "nnsys/fnd/heapcommon.h"

extern "C" {

extern BOOL func_020472c4(SysCard *obj);
extern void GX_DispOff(void);
extern void GX_DispOn(void);
extern BOOL PM_SetLCDPower(u32 a);
extern void PM_GoSleepMode(u32 a, u32 b, u16 c);
extern void *OS_GetArenaLo(int arena);
extern void *OS_GetArenaHi(int arena);
extern void *OS_InitAlloc(int arena, void *lo, void *hi, int n);
extern void OS_SetArenaLo(int arena, void *p);
extern BOOL OS_IsRunOnTwl(void);
extern void *func_0201998c(int arena);
extern void NamePool_CreateTex(void);
extern void NamePool_CreatePltt(void);
extern void OS_WaitVBlankIntr(void);
extern void Vram_FlushTransfers(void);
extern u32 OS_DisableInterrupts(void);
extern u32 OS_RestoreInterrupts(u32 state);
extern void NNS_FndFreeToExpHeap(void *heap, void *ptr);
extern u32 NNS_FndResizeForMBlockExpHeap(void *heap, void *ptr, u32 size);

static inline BOOL PAD_DetectFold(void) {
    return (*(volatile u16 *)0x2ffffa8 & 0x8000) >> 15;
}

void Sys_UpdateFold(void) {
    if (PAD_DetectFold()) {
        if (func_020472c4(gSysCard) != 0 || gSysState->unk_1f != 0 || gSysState->unk_31 != 0) {
            if (gSysState->lcdOn == 1) {
                gSysState->lcdOn = 0;
                GX_DispOff();
                *(volatile u32 *)0x4001000 &= ~0x10000;
                PM_SetLCDPower(FALSE);
            }
        } else {
            PM_GoSleepMode(0xc, 0, 0);
        }
    } else if (gSysState->lcdOn == 0 && PM_SetLCDPower(TRUE)) {
        GX_DispOn();
        *(volatile u32 *)0x4001000 |= 0x10000;
        gSysState->lcdOn = 1;
    }
    gSysState->unk_1f = 0;
}

void func_0203d9e8(UnkSys *sys) {
    void *lo;
    u8 *start;
    u32 size;
    void *hi;
    lo = OS_GetArenaLo(0);
    hi = OS_GetArenaHi(0);
    start = (u8 *)OS_InitAlloc(0, lo, hi, 2);
    OS_SetArenaLo(0, hi);
    size = 0x30000;
    if (!OS_IsRunOnTwl()) {
        sys->osHeap = func_0201998c(0);
        size = 0x1c000;
    }
    sys->heapLo = NNS_FndCreateExpHeapEx(start, size, 0);
    sys->heapHi = NNS_FndCreateExpHeapEx(start + size, (u8 *)hi - (start + size), 0);
    sys->align = 4;
    gSysState->cur = gSysState->heapHi;
    NamePool_CreateTex();
    NamePool_CreatePltt();
}

void Sys_WaitVBlank(UnkSys *sys) {
    do {
        OS_WaitVBlankIntr();
    } while (sys->frameWait > sys->vcount);
    sys->vcount = 0;
}

void Sys_WaitFrame(UnkSys *sys) {
    if (sys->frameWait <= 1) {
        return;
    }
    if (sys->frameWait - 1 <= sys->vcount) {
        return;
    }
    do {
        OS_WaitVBlankIntr();
        Vram_FlushTransfers();
    } while (sys->frameWait - 1 > sys->vcount);
}

void PauseNode_Init(UnkSysNode *node) {
    node->next = NULL;
    node->value = 0x1000;
    node->unk_6_0 = 0;
    node->unk_6_2 = 0;
    node->unk_6_4 = 0;
}

#pragma push
#pragma auto_inline on
#pragma inline_depth(3)
int func_0203db40(UnkSysNode *node) {
    int value = node->value;
    if (node->next != NULL) {
        int v = func_0203db40(node->next);
        if (v != 0x1000) {
            value = v;
        }
    }
    return value;
}

#pragma inline_depth(2)
BOOL PauseNode_IsUpdatePaused(UnkSysNode *node, BOOL recurse) {
    BOOL ret = FALSE;
    if (!recurse || node->next == NULL) {
        if (node->unk_6_0 == 2 || node->unk_6_0 == 3) {
            ret = TRUE;
        }
        if (node->value == 0) {
            ret = TRUE;
        }
    } else if (PauseNode_IsUpdatePaused(node->next, TRUE)) {
        ret = TRUE;
    }
    return ret;
}

#pragma inline_depth(3)
BOOL PauseNode_IsDrawPaused(UnkSysNode *node, BOOL recurse) {
    BOOL ret = FALSE;
    if (!recurse || node->next == NULL) {
        if (node->unk_6_2 == 2 || node->unk_6_2 == 3) {
            ret = TRUE;
        }
    } else if (PauseNode_IsDrawPaused(node->next, TRUE)) {
        ret = TRUE;
    }
    return ret;
}

#pragma pop
void *Heap_Alloc(u32 size) {
    u32 irq = OS_DisableInterrupts();
    void *p = NNS_FndAllocFromExpHeapEx(gSysState->cur, size, gSysState->align);
    OS_RestoreInterrupts(irq);
    return p;
}

void *Heap_AllocArray(u32 size) {
    u32 irq = OS_DisableInterrupts();
    void *p = NNS_FndAllocFromExpHeapEx(gSysState->cur, size, gSysState->align);
    OS_RestoreInterrupts(irq);
    return p;
}

void Heap_Free(void *ptr) {
    u32 irq = OS_DisableInterrupts();
    NNS_FndFreeToExpHeap(gSysState->cur, ptr);
    OS_RestoreInterrupts(irq);
}

void Heap_FreeArray(void *ptr) {
    u32 irq = OS_DisableInterrupts();
    NNS_FndFreeToExpHeap(gSysState->cur, ptr);
    OS_RestoreInterrupts(irq);
}

void *Heap_AllocHi(u32 size, u32 align) {
    u32 irq = OS_DisableInterrupts();
    void *p = NNS_FndAllocFromExpHeapEx(gSysState->heapHi, size, align);
    OS_RestoreInterrupts(irq);
    return p;
}

void *Heap_AllocLo(u32 size, u32 align) {
    u32 irq = OS_DisableInterrupts();
    void *p = NNS_FndAllocFromExpHeapEx(gSysState->heapLo, size, align);
    OS_RestoreInterrupts(irq);
    return p;
}

void Heap_FreeHi(void *ptr) {
    u32 irq = OS_DisableInterrupts();
    NNS_FndFreeToExpHeap(gSysState->heapHi, ptr);
    OS_RestoreInterrupts(irq);
}

void Heap_FreeLo(void *ptr) {
    u32 irq = OS_DisableInterrupts();
    NNS_FndFreeToExpHeap(gSysState->heapLo, ptr);
    OS_RestoreInterrupts(irq);
}

u32 Heap_Resize(void *ptr, u32 size) {
    u32 irq = OS_DisableInterrupts();
    u32 ret = NNS_FndResizeForMBlockExpHeap(NNS_FndFindContainHeap(ptr), ptr, size);
    OS_RestoreInterrupts(irq);
    return ret;
}

}
