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


void *OS_GetInitArenaHi(OSArenaId id);


typedef struct {
    void *lo[OS_ARENA_MAX];
    void *hi[OS_ARENA_MAX];
    u16 initialized;
    u16 padding;
} OSArenaInfo;

#define HW_ARENA_INFO_BUF       0x02fffda0
#define OSi_GetArenaInfo()      (*(OSArenaInfo *)HW_ARENA_INFO_BUF)

void *OS_GetArenaHi(OSArenaId id);
void *OS_GetArenaLo(OSArenaId id);

void * OS_GetArenaHi (OSArenaId id)
{
    return OSi_GetArenaInfo().hi[id];
}

void * OS_GetArenaLo (OSArenaId id)
{
    return OSi_GetArenaInfo().lo[id];
}
