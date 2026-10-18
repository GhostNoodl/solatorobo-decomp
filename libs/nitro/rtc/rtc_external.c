#include "nitro/os.h"
#include "nitro/os_tick.h"
#include "nitro/os_systemWork.h"
#include "nitro/rtc.h"

typedef enum RTCLock {
    RTC_LOCK_OFF = 0,
    RTC_LOCK_ON,
    RTC_LOCK_MAX
} RTCLock;

typedef enum RTCSequence {
    RTC_SEQ_GET_DATE = 0,
    RTC_SEQ_GET_TIME,
    RTC_SEQ_GET_DATETIME,
    RTC_SEQ_SET_DATE,
    RTC_SEQ_SET_TIME,
    RTC_SEQ_SET_DATETIME,
    RTC_SEQ_GET_ALARM1_STATUS,
    RTC_SEQ_GET_ALARM2_STATUS,
    RTC_SEQ_GET_ALARM_PARAM,
    RTC_SEQ_SET_ALARM1_STATUS,
    RTC_SEQ_SET_ALARM2_STATUS,
    RTC_SEQ_SET_ALARM1_PARAM,
    RTC_SEQ_SET_ALARM2_PARAM,
    RTC_SEQ_SET_HOUR_FORMAT,
    RTC_SEQ_SET_REG_STATUS2,
    RTC_SEQ_SET_REG_ADJUST,
    RTC_SEQ_MAX
} RTCSequence;

typedef struct RTCWork {
    u32 lock;
    RTCCallback callback;
    void * buffer[2];
    void * callbackArg;
    u32 sequence;
    u32 index;
    RTCInterrupt interrupt;
    RTCResult commonResult;
} RTCWork;

u16 rtcInitialized = 0;
RTCWork rtcWork = { 0 };

void RtcCommonCallback(PXIFifoTag tag, u32 data, BOOL err);
void RtcGetResultCallback(RTCResult result, void * arg);
void RtcWaitBusy(void);

void RTC_Init (void)
{
    if (rtcInitialized) {
        return;
    }

    rtcInitialized = 1;

    rtcWork.lock = RTC_LOCK_OFF;
    rtcWork.callback = NULL;
    rtcWork.interrupt = NULL;
    rtcWork.buffer[0] = NULL;
    rtcWork.buffer[1] = NULL;

    PXI_Init();
    while (!PXI_IsCallbackReady(PXI_FIFO_TAG_RTC, PXI_PROC_ARM7)) {
    }

    PXI_SetFifoRecvCallback(PXI_FIFO_TAG_RTC, RtcCommonCallback);
}

RTCResult RTC_GetDateAsync (RTCDate * date, RTCCallback callback, void * arg)
{
    OSIntrMode enabled;

    enabled = OS_DisableInterrupts();

    if (rtcWork.lock != RTC_LOCK_OFF) {
        (void)OS_RestoreInterrupts(enabled);
        return RTC_RESULT_BUSY;
    }

    rtcWork.lock = RTC_LOCK_ON;
    (void)OS_RestoreInterrupts(enabled);

    rtcWork.sequence = RTC_SEQ_GET_DATE;
    rtcWork.index = 0;
    rtcWork.buffer[0] = (void *)date;
    rtcWork.callback = callback;
    rtcWork.callbackArg = arg;

    if (RTCi_ReadRawDateAsync()) {
        return RTC_RESULT_SUCCESS;
    } else {
        rtcWork.lock = RTC_LOCK_OFF;
        return RTC_RESULT_SEND_ERROR;
    }
}

RTCResult RTC_GetDate (RTCDate * date)
{
    rtcWork.commonResult = RTC_GetDateAsync(date, RtcGetResultCallback, NULL);
    if (rtcWork.commonResult == RTC_RESULT_SUCCESS) {
        RtcWaitBusy();
    }
    return rtcWork.commonResult;
}

RTCResult RTC_GetTimeAsync (RTCTime * time, RTCCallback callback, void * arg)
{
    OSIntrMode enabled;

    enabled = OS_DisableInterrupts();

    if (rtcWork.lock != RTC_LOCK_OFF) {
        (void)OS_RestoreInterrupts(enabled);
        return RTC_RESULT_BUSY;
    }

    rtcWork.lock = RTC_LOCK_ON;
    (void)OS_RestoreInterrupts(enabled);

    rtcWork.sequence = RTC_SEQ_GET_TIME;
    rtcWork.index = 0;
    rtcWork.buffer[0] = (void *)time;
    rtcWork.callback = callback;
    rtcWork.callbackArg = arg;

    if (RTCi_ReadRawTimeAsync()) {
        return RTC_RESULT_SUCCESS;
    } else {
        rtcWork.lock = RTC_LOCK_OFF;
        return RTC_RESULT_SEND_ERROR;
    }
}

RTCResult RTC_GetTime (RTCTime * time)
{
    rtcWork.commonResult = RTC_GetTimeAsync(time, RtcGetResultCallback, NULL);

    if (rtcWork.commonResult == RTC_RESULT_SUCCESS) {
        RtcWaitBusy();
    }

    return rtcWork.commonResult;
}

RTCResult RTC_GetDateTimeAsync (RTCDate * date, RTCTime * time, RTCCallback callback, void * arg)
{
    OSIntrMode enabled;

    enabled = OS_DisableInterrupts();

    if (rtcWork.lock != RTC_LOCK_OFF) {
        (void)OS_RestoreInterrupts(enabled);
        return RTC_RESULT_BUSY;
    }

    rtcWork.lock = RTC_LOCK_ON;
    (void)OS_RestoreInterrupts(enabled);

    rtcWork.sequence = RTC_SEQ_GET_DATETIME;
    rtcWork.index = 0;
    rtcWork.buffer[0] = (void *)date;
    rtcWork.buffer[1] = (void *)time;
    rtcWork.callback = callback;
    rtcWork.callbackArg = arg;

    if (RTCi_ReadRawDateTimeAsync()) {
        return RTC_RESULT_SUCCESS;
    } else {
        rtcWork.lock = RTC_LOCK_OFF;
        return RTC_RESULT_SEND_ERROR;
    }
}

#pragma force_active on
RTCResult RTC_GetDateTime (RTCDate * date, RTCTime * time)
{
    rtcWork.commonResult = RTC_GetDateTimeAsync(date, time, RtcGetResultCallback, NULL);
    if (rtcWork.commonResult == RTC_RESULT_SUCCESS) {
        RtcWaitBusy();
    }
    return rtcWork.commonResult;
}
#pragma force_active reset

#pragma force_active on
void *func_0201b5b8 (void)
{
    return &rtcWork;
}
#pragma force_active reset

