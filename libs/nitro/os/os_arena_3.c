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

typedef struct {
    void *lo[OS_ARENA_MAX];
    void *hi[OS_ARENA_MAX];
    u16 initialized;
    u16 padding;
} OSArenaInfo;

#define HW_ARENA_INFO_BUF       0x02fffda0
#define OSi_GetArenaInfo()      (*(OSArenaInfo *)HW_ARENA_INFO_BUF)

#define OSi_ROUND(n, a)         (((u32) (n) + (a) - 1) & ~((a) - 1))

#define OS_CONSOLE_SIZE_MASK    0x0000000f

/* the pooled OSi_Initialized / OSi_MainExArenaEnabled pair, kept in the gap */
typedef struct OSiArenaState {
    BOOL initialized;
    BOOL mainExArenaEnabled;
} OSiArenaState;
extern OSiArenaState data_0208eeb8;
#define OSi_MainExArenaEnabled (data_0208eeb8.mainExArenaEnabled)

u32 OS_GetConsoleType(void);
#define OS_GetConsoleType OS_GetConsoleType

void *OS_GetArenaHi(OSArenaId id);
void *OS_GetArenaLo(OSArenaId id);
void *OS_AllocFromArenaLo(OSArenaId id, u32 size, u32 align);

void OS_SetArenaHi (OSArenaId id, void * newHi)
{
    OSi_GetArenaInfo().hi[id] = newHi;
}

void OS_SetArenaLo (OSArenaId id, void * newLo)
{
    OSi_GetArenaInfo().lo[id] = newLo;
}

void * OS_AllocFromArenaLo (OSArenaId id, u32 size, u32 align)
{
    void * ptr;
    u8 * arenaLo;

    ptr = OS_GetArenaLo(id);
    if (!ptr) {
        return NULL;
    }

    arenaLo = ptr = (void *)OSi_ROUND(ptr, align);
    arenaLo += size;
    arenaLo = (u8 *)OSi_ROUND(arenaLo, align);

    if (arenaLo > OS_GetArenaHi(id)) {
        return NULL;
    }

    OS_SetArenaLo(id, arenaLo);

    return ptr;
}
