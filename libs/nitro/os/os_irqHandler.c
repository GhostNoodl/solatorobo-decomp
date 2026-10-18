#include "nitro/os.h"
#include "nitro/os_interrupt.h"

void OS_WaitIrq (BOOL clear, OSIrqMask irqFlags)
{
    OSIntrMode enabled = OS_DisableInterrupts();

    if (clear) {
        OS_ClearIrqCheckFlag(irqFlags);
    }

    (void)OS_RestoreInterrupts(enabled);

    while (!(OS_GetIrqCheckFlag() & irqFlags)) {
        OS_SleepThread(&OSi_IrqThreadQueue);
    }
}
