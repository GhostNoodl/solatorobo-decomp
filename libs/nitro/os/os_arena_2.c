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

/* the pooled OSi_Initialized / OSi_MainExArenaEnabled pair, kept in the gap */
typedef struct OSiArenaState {
    BOOL initialized;
    BOOL mainExArenaEnabled;
} OSiArenaState;
extern OSiArenaState data_0208eeb8;
#define OSi_MainExArenaEnabled (data_0208eeb8.mainExArenaEnabled)

#define OS_CONSOLE_SIZE_MASK    0x0000000f
#define OS_CONSOLE_SIZE_4MB     0x00000001
#define OS_CONSOLE_SIZE_16MB    0x00000004

u32 OS_GetConsoleType(void);
BOOL OS_IsRunOnTwl(void);

/* Linker-script symbols: __DTCM_LO from dsd, the stack sizes and the TWL
   extended arena start from config/usa/arm9/abs_symbols.txt (their values are
   only known at link time, so the compiler cannot fold them). */
extern char __DTCM_LO[];
extern char SDK_SYS_STACKSIZE[];
extern char SDK_IRQ_STACKSIZE[];
extern char SDK_SECTION_ARENA_EX_START[];
#define HW_DTCM                         ((u32)__DTCM_LO)
#define HW_DTCM_IRQ_STACK_END           (HW_DTCM + 0x3f80)
#define OSi_SYS_STACKSIZE               ((s32)SDK_SYS_STACKSIZE)
#define OSi_IRQ_STACKSIZE               ((s32)SDK_IRQ_STACKSIZE)

/* Arena bounds of this link (SDK_SECTION_ARENA_* in the SDK's .lcf). Nothing in
   the ROM relocates them, so they are plain constants here. */
#define SDK_MAIN_ARENA_LO               0x022183c0
#define SDK_LTDMAIN_ARENA_LO            0x02298140
#define SDK_SECTION_ARENA_ITCM_START    0x01ffcac0
#define SDK_SECTION_ARENA_DTCM_START    0x02fe15c0

#define HW_MAIN_MEM_MAIN_END            0x023e0000
#define HW_TWL_MAIN_MEM_MAIN_END        0x02f80000
#define HW_MAIN_MEM_EX_END              0x02700000
#define HW_TWL_MAIN_MEM_EX_END          0x0df00000
#define HW_ITCM_END                     0x02000000
#define HW_SHARED_ARENA_LO_DEFAULT      0x02fff000
#define HW_SHARED_ARENA_HI_DEFAULT      0x02fff680
#define HW_WRAM_AREA_END                0x03040000

void *OS_GetInitArenaHi(OSArenaId id);
void *OS_GetInitArenaLo(OSArenaId id);


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

void *OS_GetInitArenaHi (OSArenaId id)
{
    switch (id) {
    case OS_ARENA_MAIN:
        return OS_IsRunOnTwl() ? (void *)HW_TWL_MAIN_MEM_MAIN_END : (void *)HW_MAIN_MEM_MAIN_END;
    case OS_ARENA_MAINEX:
        if (!OSi_MainExArenaEnabled) {
            return (void *)0;
        } else {
            u32 size = OS_GetConsoleType() & OS_CONSOLE_SIZE_MASK;
            if (OS_IsRunOnTwl()) {
                if (size == OS_CONSOLE_SIZE_16MB) {
                    return (void *)0;
                }
                return (void *)HW_TWL_MAIN_MEM_EX_END;
            } else {
                if (size == OS_CONSOLE_SIZE_4MB) {
                    return (void *)0;
                }
                return (void *)HW_MAIN_MEM_EX_END;
            }
        }
    case OS_ARENA_ITCM:
        return (void *)HW_ITCM_END;
    case OS_ARENA_DTCM:
        {
            u32 irqStackLo = (u32)HW_DTCM_IRQ_STACK_END - (u32)OSi_IRQ_STACKSIZE;
            u32 sysStackLo;

            if (!OSi_SYS_STACKSIZE) {
                sysStackLo = HW_DTCM;
                if (sysStackLo < SDK_SECTION_ARENA_DTCM_START) {
                    sysStackLo = SDK_SECTION_ARENA_DTCM_START;
                }
            } else if (OSi_SYS_STACKSIZE < 0) {
                sysStackLo = SDK_SECTION_ARENA_DTCM_START - OSi_SYS_STACKSIZE;
            } else {
                sysStackLo = irqStackLo - OSi_SYS_STACKSIZE;
            }
            return (void *)sysStackLo;
        }
    case OS_ARENA_SHARED:
        return (void *)HW_SHARED_ARENA_HI_DEFAULT;
    case OS_ARENA_WRAM_MAIN:
        return (void *)HW_WRAM_AREA_END;
    default:
        return NULL;
    }
}

void *OS_GetInitArenaLo (OSArenaId id)
{
    switch (id) {
    case OS_ARENA_MAIN:
        return OS_IsRunOnTwl() ? (void *)SDK_LTDMAIN_ARENA_LO : (void *)SDK_MAIN_ARENA_LO;
    case OS_ARENA_MAINEX:
        if (!OSi_MainExArenaEnabled) {
            return (void *)0;
        } else {
            u32 size = OS_GetConsoleType() & OS_CONSOLE_SIZE_MASK;
            if (OS_IsRunOnTwl()) {
                if (size == OS_CONSOLE_SIZE_16MB) {
                    return (void *)0;
                }
                return (void *)SDK_SECTION_ARENA_EX_START;
            } else {
                if (size == OS_CONSOLE_SIZE_4MB) {
                    return (void *)0;
                }
                return (void *)HW_MAIN_MEM_MAIN_END;
            }
        }
    case OS_ARENA_ITCM:
        return (void *)SDK_SECTION_ARENA_ITCM_START;
    case OS_ARENA_DTCM:
        return (void *)SDK_SECTION_ARENA_DTCM_START;
    case OS_ARENA_SHARED:
        return (void *)HW_SHARED_ARENA_LO_DEFAULT;
    case OS_ARENA_WRAM_MAIN:
        return (void *)HW_WRAM_AREA_END;
    default:
        return NULL;
    }
}
