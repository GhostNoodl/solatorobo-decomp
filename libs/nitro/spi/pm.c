#include "pm_work.h"

#pragma force_active on

u32 OS_GetProcMode(void);
u32 OS_GetCpsrIrq(void);
void PXIi_HandlerRecvFifoNotEmpty(void);
void PXI_Init(void);
void WaitByLoop(s32 count);
void func_0201d648(PXIFifoTag tag, u32 data, BOOL err);

void PMi_WaitBusy(void) {
    volatile BOOL *p = &PMi_Work.lock;

    while (*p) {
        if (((data_0208afc8 & 2) && OS_GetProcMode() == 0x12) ||
            ((data_0208afc8 & 4) && OS_GetCpsrIrq() == 0x80) ||
            ((data_0208afc8 & 8) && REG_IME == 0)) {
            PXIi_HandlerRecvFifoNotEmpty();
        }
    }
}

void PMi_DummyCallback(u32 result, void *arg) {
    if (arg) {
        *(u32 *)arg = result;
    }
}

void PMi_CallCallbackAndUnlock(u32 result) {
    PMCallback callback = PMi_Work.callback;
    void *arg = PMi_Work.callbackArg;

    PMi_Work.lock = FALSE;

    if (callback) {
        PMi_Work.callback = NULL;
        callback(result, arg);
    }
}

void PMi_WaitVBlank(void) {
    vu32 vcount = OS_GetVBlankCount();

    while (vcount == OS_GetVBlankCount()) {
    }
}

void PM_Init(void) {
    if (PMi_Work.init) {
        return;
    }

    PMi_Work.init = TRUE;
    PMi_Work.lock = FALSE;
    PMi_Work.callback = NULL;
    *(u32 *)0x02fff684 = 0;

    PXI_Init();

    while (!PXI_IsCallbackReady(PXI_FIFO_TAG_PM, PXI_PROC_ARM7)) {
        WaitByLoop(100);
    }

    PXI_SetFifoRecvCallback(PXI_FIFO_TAG_PM, (PXIFifoCallback)func_0201d648);

    PMi_Work.lcdOffCount = PMi_Work.lcdOnCount = OS_GetVBlankCount();
}

typedef struct {
    void (*func)(void *arg);
    void *arg;
} PMiTwlNotify;

void func_0228f770(u32 param);  /* TWL only */

void func_0201d648(PXIFifoTag tag, u32 data, BOOL err) {
    u16 command;
    u16 pxiResult;
    BOOL callCallback = TRUE;

    command = (u16)((data & 0x7f00) >> 8);
    pxiResult = (u16)(data & 0xff);

    if (err) {
        PMi_CallCallbackAndUnlock((command == 0x61 || command == 0x62) ? 1 : 2);
        return;
    }

    switch (command) {
    case 0x61:
        if (PMi_Work.data) {
            *PMi_Work.data = pxiResult;
        }
        pxiResult = PM_RESULT_SUCCESS;
        break;
    case 0x60:
        pxiResult = PM_RESULT_SUCCESS;
        break;
    case 0x62:
        break;
    case 0x63:
        PMi_Work.wakeUp = TRUE;
        break;
    case 0x70:
        switch (pxiResult) {
        case 0:
            func_0228f770(1);
            *(u32 *)0x02fff684 = 1;
            break;
        case 1:
        case 2:
        case 3:
            break;
        case 4:
            if (((PMiTwlNotify *)0x022919f0)->func) {
                ((PMiTwlNotify *)0x022919f0)->func(((PMiTwlNotify *)0x022919f0)->arg);
            }
            break;
        case 5:
            func_0228f770(2);
            *(u32 *)0x02fff684 = 1;
            break;
        }
        callCallback = FALSE;
        break;
    }

    if (callCallback) {
        PMi_CallCallbackAndUnlock(pxiResult);
    }
}
