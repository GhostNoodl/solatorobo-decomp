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

void MI_WaitDma(u32 dmaNo);
void MI_StopDma(u32 dmaNo);
void func_0228f6b4(u32 ndmaNo);  /* TWL only */
extern u32 data_02090c80[4];

void func_0201dca4(void) {
    u32 i;

    for (i = 0; i <= 3; i++) {
        vu32 *cnt = (vu32 *)(0x040000b8 + i * 12);
        u32 mode;

        data_02090c80[i] = *cnt;
        mode = *cnt & 0x38000000;
        switch (mode) {
        case 0x28000000:
            while (*(vu32 *)0x040001a4 & 0x80000000) {
            }
            break;
        case 0x18000000:
        case 0x20000000:
            MI_WaitDma(i);
            break;
        default:
            if (!(*cnt & 0x02000000)) {
                MI_WaitDma(i);
            } else {
                MI_StopDma(i);
            }
            break;
        }
        if (OS_IsRunOnTwl()) {
            func_0228f6b4(i);
        }
    }
}
