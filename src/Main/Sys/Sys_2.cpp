#include "Main/Res/ResMgr.h"

extern "C" {

extern void *data_02097e44;
extern int func_020472c4(void *obj);
extern void GX_DispOff(void);
extern void GX_DispOn(void);
extern BOOL func_0201e244(BOOL a);
extern void func_0201dd4c(int a, int b, int c);
extern void *OS_GetArenaLo(int arena);
extern void *OS_GetArenaHi(int arena);
extern void *OS_InitAlloc(int arena, void *lo, void *hi, int n);
extern void OS_SetArenaLo(int arena, void *p);
extern BOOL OS_IsRunOnTwl(void);
extern void *func_0201998c(int arena);
extern void *NNS_FndCreateExpHeapEx(void *start, u32 size, int flags);
extern void func_0203dfb0(void);
extern void func_0203e024(void);
extern void OS_WaitVBlankIntr(void);
extern void func_0203e6bc(void);
extern u32 OS_DisableInterrupts(void);
extern void OS_RestoreInterrupts(u32 state);
extern void *NNS_FndAllocFromExpHeapEx(void *heap, u32 size, u32 align);
extern void NNS_FndFreeToExpHeap(void *heap, void *ptr);
extern void *NNS_FndFindContainHeap(void *ptr);
extern u32 NNS_FndResizeForMBlockExpHeap(void *heap, void *ptr, u32 size);

static inline BOOL PAD_DetectFold(void) {
    return (*(volatile u16 *)0x2ffffa8 & 0x8000) >> 15;
}

void func_0203d8e8(void) {
    if (PAD_DetectFold()) {
        if (func_020472c4(data_02097e44) != 0 || data_02097dd0->unk_1f != 0 || data_02097dd0->unk_31 != 0) {
            if (data_02097dd0->unk_1e == 1) {
                data_02097dd0->unk_1e = 0;
                GX_DispOff();
                *(volatile u32 *)0x4001000 &= ~0x10000;
                func_0201e244(FALSE);
            }
        } else {
            func_0201dd4c(0xc, 0, 0);
        }
    } else if (data_02097dd0->unk_1e == 0 && func_0201e244(TRUE)) {
        GX_DispOn();
        *(volatile u32 *)0x4001000 |= 0x10000;
        data_02097dd0->unk_1e = 1;
    }
    data_02097dd0->unk_1f = 0;
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
        sys->unk_0c = func_0201998c(0);
        size = 0x1c000;
    }
    sys->unk_04 = NNS_FndCreateExpHeapEx(start, size, 0);
    sys->unk_08 = NNS_FndCreateExpHeapEx(start + size, (u8 *)hi - (start + size), 0);
    sys->align = 4;
    data_02097dd0->cur = data_02097dd0->unk_08;
    func_0203dfb0();
    func_0203e024();
}

void func_0203daa4(UnkSys *sys) {
    do {
        OS_WaitVBlankIntr();
    } while (sys->frameWait > sys->vcount);
    sys->vcount = 0;
}

void func_0203dacc(UnkSys *sys) {
    if (sys->frameWait <= 1) {
        return;
    }
    if (sys->frameWait - 1 <= sys->vcount) {
        return;
    }
    do {
        OS_WaitVBlankIntr();
        func_0203e6bc();
    } while (sys->frameWait - 1 > sys->vcount);
}

void func_0203db10(UnkSysNode *node) {
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
BOOL func_0203dbb0(UnkSysNode *node, BOOL recurse) {
    BOOL ret = FALSE;
    if (!recurse || node->next == NULL) {
        if (node->unk_6_0 == 2 || node->unk_6_0 == 3) {
            ret = TRUE;
        }
        if (node->value == 0) {
            ret = TRUE;
        }
    } else if (func_0203dbb0(node->next, TRUE)) {
        ret = TRUE;
    }
    return ret;
}

#pragma inline_depth(3)
BOOL func_0203dc9c(UnkSysNode *node, BOOL recurse) {
    BOOL ret = FALSE;
    if (!recurse || node->next == NULL) {
        if (node->unk_6_2 == 2 || node->unk_6_2 == 3) {
            ret = TRUE;
        }
    } else if (func_0203dc9c(node->next, TRUE)) {
        ret = TRUE;
    }
    return ret;
}

#pragma pop
void *func_0203dd9c(u32 size) {
    u32 irq = OS_DisableInterrupts();
    void *p = NNS_FndAllocFromExpHeapEx(data_02097dd0->cur, size, data_02097dd0->align);
    OS_RestoreInterrupts(irq);
    return p;
}

void *func_0203dddc(u32 size) {
    u32 irq = OS_DisableInterrupts();
    void *p = NNS_FndAllocFromExpHeapEx(data_02097dd0->cur, size, data_02097dd0->align);
    OS_RestoreInterrupts(irq);
    return p;
}

void func_0203de1c(void *ptr) {
    u32 irq = OS_DisableInterrupts();
    NNS_FndFreeToExpHeap(data_02097dd0->cur, ptr);
    OS_RestoreInterrupts(irq);
}

void func_0203de50(void *ptr) {
    u32 irq = OS_DisableInterrupts();
    NNS_FndFreeToExpHeap(data_02097dd0->cur, ptr);
    OS_RestoreInterrupts(irq);
}

void *func_0203de84(u32 size, u32 align) {
    u32 irq = OS_DisableInterrupts();
    void *p = NNS_FndAllocFromExpHeapEx(data_02097dd0->unk_08, size, align);
    OS_RestoreInterrupts(irq);
    return p;
}

void *func_0203dec8(u32 size, u32 align) {
    u32 irq = OS_DisableInterrupts();
    void *p = NNS_FndAllocFromExpHeapEx(data_02097dd0->unk_04, size, align);
    OS_RestoreInterrupts(irq);
    return p;
}

void func_0203df0c(void *ptr) {
    u32 irq = OS_DisableInterrupts();
    NNS_FndFreeToExpHeap(data_02097dd0->unk_08, ptr);
    OS_RestoreInterrupts(irq);
}

void func_0203df40(void *ptr) {
    u32 irq = OS_DisableInterrupts();
    NNS_FndFreeToExpHeap(data_02097dd0->unk_04, ptr);
    OS_RestoreInterrupts(irq);
}

u32 func_0203df74(void *ptr, u32 size) {
    u32 irq = OS_DisableInterrupts();
    u32 ret = NNS_FndResizeForMBlockExpHeap(NNS_FndFindContainHeap(ptr), ptr, size);
    OS_RestoreInterrupts(irq);
    return ret;
}

}
