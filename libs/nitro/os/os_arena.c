#include "nitro/os.h"

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

/* OSi_Initialized stays in the gap: OS_GetInitArenaHi (not decompiled) reads it */
extern BOOL data_0208eeb8;
#define OSi_Initialized data_0208eeb8

void OS_InitArena(void);
void *OS_GetInitArenaHi(OSArenaId id);
void *OS_GetInitArenaLo(OSArenaId id);
void OS_SetArenaHi(OSArenaId id, void *newHi);
void OS_SetArenaLo(OSArenaId id, void *newLo);

static inline void OS_InitArenaHiAndLo (OSArenaId id)
{
    OS_SetArenaHi(id, OS_GetInitArenaHi(id));
    OS_SetArenaLo(id, OS_GetInitArenaLo(id));
}

void OS_InitArena (void)
{
    if (OSi_Initialized) {
        return;
    }

    OSi_Initialized = TRUE;

    OS_InitArenaHiAndLo(OS_ARENA_MAIN);

    OS_SetArenaLo(OS_ARENA_MAINEX, (void *)0);
    OS_SetArenaHi(OS_ARENA_MAINEX, (void *)0);

    OS_InitArenaHiAndLo(OS_ARENA_ITCM);
    OS_InitArenaHiAndLo(OS_ARENA_DTCM);
    OS_InitArenaHiAndLo(OS_ARENA_SHARED);
    OS_InitArenaHiAndLo(OS_ARENA_WRAM_MAIN);
}
