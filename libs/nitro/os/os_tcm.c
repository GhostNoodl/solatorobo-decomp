#include "nitro/os.h"

#define HW_C1_ITCM_ENABLE           0x00040000
#define HW_C1_DTCM_ENABLE           0x00010000
#define OSi_TCM_REGION_BASE_MASK    0xfffff000

void OS_EnableITCM(void);
void OS_EnableDTCM(void);
u32 OS_GetDTCMAddress(void);

asm void OS_EnableITCM (void)
{
    mrc p15, 0, r0, c1, c0, 0
    orr r0, r0, #HW_C1_ITCM_ENABLE
    mcr p15, 0, r0, c1, c0, 0
    bx lr
}

asm void OS_EnableDTCM (void)
{
    mrc p15, 0, r0, c1, c0, 0
    orr r0, r0, #HW_C1_DTCM_ENABLE
    mcr p15, 0, r0, c1, c0, 0
    bx lr
}

asm u32 OS_GetDTCMAddress (void)
{
    mrc p15, 0, r0, c9, c1, 0
    ldr r1, =OSi_TCM_REGION_BASE_MASK
    and r0, r0, r1
    bx lr
}
