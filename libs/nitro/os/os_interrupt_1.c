#include "nitro/os.h"

/* timer entries of OSi_IrqCallbackInfo (index 8..11) */
extern OSIrqCallbackInfo data_0208ebec[4];

/* tail call into the TWL-only (LTD) part of the OS library, unreachable from this module */
#pragma force_active on
asm void func_02017a94(void)
{
    ldr ip, =0x0228f574
    bx ip
}
#pragma force_active reset

void OSi_EnterTimerCallback (u32 timerNo, void (*callback)(void *), void * arg)
{
    OSIrqMask imask = (1UL << (3 + timerNo));

    data_0208ebec[timerNo].func = callback;
    data_0208ebec[timerNo].arg = arg;

    (void)OS_EnableIrqMask(imask);
    data_0208ebec[timerNo].enable = TRUE;
}
