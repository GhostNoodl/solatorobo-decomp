#ifndef MAIN_SYS_SYSSTATE_H
#define MAIN_SYS_SYSSTATE_H

#include "types.h"

#ifdef __cplusplus
extern "C" {
#endif

typedef struct UnkSysNode {
    /* 0x0 */ struct UnkSysNode *next;
    /* 0x4 */ s16 value;
    /* 0x6 */ u8 unk_6_0 : 2;
    /* 0x6 */ u8 unk_6_2 : 2;
    /* 0x6 */ u8 unk_6_4 : 2;
    /* 0x6 */ u8 unk_6_6 : 2;
} UnkSysNode;

// System state at gSysState: the heap selection (cur is the heap that new allocations come from),
// frame counters and the vblank hook.
typedef struct UnkSys {
    /* 0x00 */ void *cur;
    /* 0x04 */ void *heapLo; // expanded heap at the start of the main arena (0x30000, 0x1c000 on NTR)
    /* 0x08 */ void *heapHi; // expanded heap over the rest of the arena; the default cur
    /* 0x0c */ void *osHeap; // OSHeapHandle (OS_AllocFromHeap), NTR only
    /* 0x10 */ u32 align;
    /* 0x14 */ u32 frameCount;
    /* 0x18 */ void (*vblankFunc)(void);
    /* 0x1c */ u8 frameWait;
    /* 0x1d */ volatile u8 vcount;
    /* 0x1e */ u8 lcdOn; // LCD power is on (PM_SetLCDPower; turned off while the lid is closed)
    /* 0x1f */ u8 unk_1f;
    /* 0x20 */ u32 unk_20[4];
    /* 0x30 */ u8 unk_30;
    /* 0x31 */ u8 unk_31;
    /* 0x34 */ UnkSysNode node;
} UnkSys; // size 0x3c

extern UnkSys *gSysState;

#ifdef __cplusplus
}
#endif

#endif
