#include "nitro/os.h"

static u32 OSi_vramExclusive = 0;
static u16 OSi_vramLockId[OS_VRAM_BANK_KINDS] = { 0 };

void OSi_InitVramExclusive(void);
BOOL OSi_TryLockVram(u16 bank, u16 lockId);
void OSi_UnlockVram(u16 bank, u16 lockId);

static asm u32 OsCountZeroBits (u32 bitmap)
{
    clz r0, r0
    bx lr
}

void OSi_InitVramExclusive (void)
{
    s32 i;

    OSi_vramExclusive = 0x0000;

    for(i = 0 ; i < OS_VRAM_BANK_KINDS ; i++) {
        OSi_vramLockId[i] = 0;
    }
}

void OSi_UnlockVram (u16 bank, u16 lockId)
{
    u32 workMap;
    s32 zeroBits;
    OSIntrMode enabled = OS_DisableInterrupts();

    workMap = (u32)(bank & OSi_vramExclusive & OS_VRAM_BANK_ID_ALL);
    while (TRUE) {
        zeroBits = (s32)(31 - OsCountZeroBits((u32)workMap));
        if (zeroBits < 0) {
            break;
        }
        workMap &= ~(0x00000001 << zeroBits);
        if (OSi_vramLockId[zeroBits] == lockId) {
            OSi_vramLockId[zeroBits] = 0;
            OSi_vramExclusive &= ~(0x00000001 << zeroBits);
        }
    }

    (void)OS_RestoreInterrupts(enabled);
}

