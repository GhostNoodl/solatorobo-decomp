#include "nitro/os.h"
#include "nitro/pxi.h"

#define PXI_FIFO_TAG_OS 12

void PXI_Init(void);
void OSi_CommonCallback(u32 tag, u32 data, BOOL err);

static u16 OSi_IsInitReset = FALSE;

void OS_InitReset (void)
{
    if (OSi_IsInitReset) {
        return;
    }
    OSi_IsInitReset = TRUE;

    PXI_Init();
    while (!PXI_IsCallbackReady(PXI_FIFO_TAG_OS, PXI_PROC_ARM7)) {
    }

    PXI_SetFifoRecvCallback(PXI_FIFO_TAG_OS, OSi_CommonCallback);
}
