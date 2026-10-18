#include "nitro/os.h"

#define HW_C1_PROTECT_UNIT_ENABLE   0x00000001

void OS_EnableProtectionUnit(void);
void OS_DisableProtectionUnit(void);

asm void OS_EnableProtectionUnit (void)
{
    mrc p15, 0, r0, c1, c0, 0
    orr r0, r0, #HW_C1_PROTECT_UNIT_ENABLE
    mcr p15, 0, r0, c1, c0, 0
    bx lr
}

#pragma force_active on
asm void OS_DisableProtectionUnit (void)
{
    mrc p15, 0, r0, c1, c0, 0
    bic r0, r0, #HW_C1_PROTECT_UNIT_ENABLE
    mcr p15, 0, r0, c1, c0, 0
    bx lr
}
#pragma force_active reset
