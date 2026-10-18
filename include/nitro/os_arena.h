#ifndef NITRO_OS_ARENA_H
#define NITRO_OS_ARENA_H

#include "types.h"

#ifdef __cplusplus
extern "C" {
#endif

typedef enum {
    OS_ARENA_MAIN = 0,
    OS_ARENA_MAIN_SUBPRIV = 1,
    OS_ARENA_MAINEX = 2,
    OS_ARENA_ITCM = 3,
    OS_ARENA_DTCM = 4,
    OS_ARENA_SHARED = 5,
    OS_ARENA_WRAM_MAIN = 6,
    OS_ARENA_WRAM_SUB = 7,
    OS_ARENA_WRAM_SUBPRIV = 8,
    OS_ARENA_MAX = 9
} OSArenaId;

void OS_InitArena(void);
void *OS_GetArenaHi(OSArenaId id);
void *OS_GetArenaLo(OSArenaId id);
void *OS_GetInitArenaHi(OSArenaId id);
void *OS_GetInitArenaLo(OSArenaId id);
void OS_SetArenaHi(OSArenaId id, void *newHi);
void OS_SetArenaLo(OSArenaId id, void *newLo);
void *OS_AllocFromArenaLo(OSArenaId id, u32 size, u32 align);

#ifdef __cplusplus
}
#endif

#endif
