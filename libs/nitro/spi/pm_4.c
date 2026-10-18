#include "pm_work.h"

#pragma force_active on

u32 func_0201dbe8(u32 count) {
    if (!func_0201e280()) {
        return PM_RESULT_SUCCESS;
    }
    return PM_SendUtilityCommand(0x10, (u16)count, NULL);
}

u32 PM_GetBackLight(BOOL *top, BOOL *bottom) {
    u16 status;
    u32 result = PM_SendUtilityCommand(0xf, 3, &status);

    if (result != PM_RESULT_SUCCESS) {
        return result;
    }

    if (top) {
        *top = (status & 8) ? TRUE : FALSE;
    }
    if (bottom) {
        *bottom = (status & 4) ? TRUE : FALSE;
    }

    return result;
}

void PMi_SendPxiData(u32 data) {
    while (PXI_SendWordByFifo(PXI_FIFO_TAG_PM, data, FALSE) != 0) {
    }
}
