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


u32 RtcBCD2HEX(u32 bcd);
BOOL OS_IsRunOnTwl(void);
RTCResult func_022183c0(void);  /* TWL only */

#define RTC_RAW ((RTCRawData *)0x02fffde8)

void RtcCommonCallback (PXIFifoTag tag, u32 data, BOOL err)
{
#pragma unused(tag)
    RTCResult result;
    RTCPxiResult pxiresult;
    u8 command;
    RTCCallback cb;

    if (err) {
        if (rtcWork.index) {
            rtcWork.index = 0;
        }
        if (rtcWork.lock != RTC_LOCK_OFF) {
            rtcWork.lock = RTC_LOCK_OFF;
        }
        if (rtcWork.callback) {
            cb = rtcWork.callback;
            rtcWork.callback = NULL;
            cb(RTC_RESULT_FATAL_ERROR, rtcWork.callbackArg);
        }
        return;
    }

    command = (u8)((data & RTC_PXI_COMMAND_MASK) >> RTC_PXI_COMMAND_SHIFT);
    pxiresult = (RTCPxiResult)((data & RTC_PXI_RESULT_MASK) >> RTC_PXI_RESULT_SHIFT);

    if (command == RTC_PXI_COMMAND_INTERRUPT) {
        if (rtcWork.interrupt) {
            rtcWork.interrupt();
        }
        return;
    }

    if (pxiresult == RTC_PXI_RESULT_SUCCESS) {
        result = RTC_RESULT_SUCCESS;
        switch (rtcWork.sequence) {
        case RTC_SEQ_GET_DATE:
            {
                RTCDate *pDst = (RTCDate *)(rtcWork.buffer[0]);
                RTCRawDate *pSrc = &(RTC_RAW->t.date);

                pDst->year = RtcBCD2HEX(pSrc->year);
                pDst->month = RtcBCD2HEX(pSrc->month);
                pDst->day = RtcBCD2HEX(pSrc->day);
                pDst->week = RTC_GetDayOfWeek(pDst);
            }
            break;
        case RTC_SEQ_GET_TIME:
            {
                RTCTime *pDst = (RTCTime *)(rtcWork.buffer[0]);
                RTCRawTime *pSrc = &(RTC_RAW->t.time);

                pDst->hour = RtcBCD2HEX(pSrc->hour);
                pDst->minute = RtcBCD2HEX(pSrc->minute);
                pDst->second = RtcBCD2HEX(pSrc->second);
            }
            break;
        case RTC_SEQ_GET_DATETIME:
            {
                RTCDate *pDst = (RTCDate *)(rtcWork.buffer[0]);
                RTCRawDate *pSrc = &(RTC_RAW->t.date);

                /* the target masks the whole word here, unlike RTC_SEQ_GET_DATE */
                pDst->year = RtcBCD2HEX(*(u32 *)pSrc & 0xff);
                pDst->month = RtcBCD2HEX(pSrc->month);
                pDst->day = RtcBCD2HEX(pSrc->day);
                pDst->week = RTC_GetDayOfWeek(pDst);
            }
            {
                RTCTime *pDst = (RTCTime *)(rtcWork.buffer[1]);
                RTCRawTime *pSrc = &(RTC_RAW->t.time);

                pDst->hour = RtcBCD2HEX(pSrc->hour);
                pDst->minute = RtcBCD2HEX(pSrc->minute);
                pDst->second = RtcBCD2HEX(pSrc->second);
            }
            break;
        case RTC_SEQ_SET_DATE:
        case RTC_SEQ_SET_TIME:
        case RTC_SEQ_SET_DATETIME:
            break;
        case RTC_SEQ_GET_ALARM1_STATUS:
            {
                RTCAlarmStatus *pDst = (RTCAlarmStatus *)(rtcWork.buffer[0]);
                RTCRawStatus2 *pSrc = &(RTC_RAW->a.status2);

                if (pSrc->intr_mode == 4) {
                    *pDst = RTC_ALARM_STATUS_ON;
                } else {
                    *pDst = RTC_ALARM_STATUS_OFF;
                }
            }
            break;
        case RTC_SEQ_GET_ALARM2_STATUS:
            {
                RTCAlarmStatus *pDst = (RTCAlarmStatus *)(rtcWork.buffer[0]);
                RTCRawStatus2 *pSrc = &(RTC_RAW->a.status2);

                if (pSrc->intr2_mode) {
                    *pDst = RTC_ALARM_STATUS_ON;
                } else {
                    *pDst = RTC_ALARM_STATUS_OFF;
                }
            }
            break;
        case RTC_SEQ_GET_ALARM_PARAM:
            {
                RTCAlarmParam *pDst = (RTCAlarmParam *)(rtcWork.buffer[0]);
                RTCRawAlarm *pSrc = &(RTC_RAW->a.alarm);

                pDst->week = (RTCWeek)(pSrc->week);
                pDst->hour = RtcBCD2HEX(pSrc->hour);
                pDst->minute = RtcBCD2HEX(pSrc->minute);
                pDst->enable = RTC_ALARM_ENABLE_NONE;
                if (pSrc->we) {
                    pDst->enable += RTC_ALARM_ENABLE_WEEK;
                }
                if (pSrc->he) {
                    pDst->enable += RTC_ALARM_ENABLE_HOUR;
                }
                if (pSrc->me) {
                    pDst->enable += RTC_ALARM_ENABLE_MINUTE;
                }
            }
            break;
        case RTC_SEQ_SET_ALARM1_STATUS:
            if (rtcWork.index == 0) {
                RTCRawStatus2 *pSrc = &(RTC_RAW->a.status2);

                if (*(RTCAlarmStatus *)(rtcWork.buffer[0]) == RTC_ALARM_STATUS_ON) {
                    if (pSrc->intr_mode != 4) {
                        rtcWork.index++;
                        pSrc->intr_mode = 4;
                        if (!RTCi_WriteRawStatus2Async()) {
                            rtcWork.index = 0;
                            result = RTC_RESULT_SEND_ERROR;
                        }
                    }
                } else {
                    if (pSrc->intr_mode != 0) {
                        rtcWork.index++;
                        pSrc->intr_mode = 0;
                        if (!RTCi_WriteRawStatus2Async()) {
                            rtcWork.index = 0;
                            result = RTC_RESULT_SEND_ERROR;
                        }
                    }
                }
            } else {
                rtcWork.index = 0;
            }
            break;
        case RTC_SEQ_SET_ALARM2_STATUS:
            if (rtcWork.index == 0) {
                RTCRawStatus2 *pSrc = &(RTC_RAW->a.status2);

                if (*(RTCAlarmStatus *)(rtcWork.buffer[0]) == RTC_ALARM_STATUS_ON) {
                    if (!pSrc->intr2_mode) {
                        rtcWork.index++;
                        pSrc->intr2_mode = 1;
                        if (!RTCi_WriteRawStatus2Async()) {
                            rtcWork.index = 0;
                            result = RTC_RESULT_SEND_ERROR;
                        }
                    }
                } else {
                    if (pSrc->intr2_mode) {
                        rtcWork.index++;
                        pSrc->intr2_mode = 0;
                        if (!RTCi_WriteRawStatus2Async()) {
                            rtcWork.index = 0;
                            result = RTC_RESULT_SEND_ERROR;
                        }
                    }
                }
            } else {
                rtcWork.index = 0;
            }
            break;
        case RTC_SEQ_SET_ALARM1_PARAM:
        case RTC_SEQ_SET_ALARM2_PARAM:
        case RTC_SEQ_SET_HOUR_FORMAT:
        case RTC_SEQ_SET_REG_STATUS2:
        case RTC_SEQ_SET_REG_ADJUST:
            break;
        default:
            if (OS_IsRunOnTwl() == TRUE) {
                result = func_022183c0();
            } else {
                rtcWork.index = 0;
                result = RTC_RESULT_INVALID_COMMAND;
            }
        }
    } else {
        rtcWork.index = 0;
        switch (pxiresult) {
        case RTC_PXI_RESULT_INVALID_COMMAND:
            result = RTC_RESULT_INVALID_COMMAND;
            break;
        case RTC_PXI_RESULT_ILLEGAL_STATUS:
            result = RTC_RESULT_ILLEGAL_STATUS;
            break;
        case RTC_PXI_RESULT_BUSY:
            result = RTC_RESULT_BUSY;
            break;
        case RTC_PXI_RESULT_FATAL_ERROR:
        default:
            result = RTC_RESULT_FATAL_ERROR;
        }
    }

    if (rtcWork.index == 0) {
        if (rtcWork.lock != RTC_LOCK_OFF) {
            rtcWork.lock = RTC_LOCK_OFF;
        }
        if (rtcWork.callback) {
            cb = rtcWork.callback;
            rtcWork.callback = NULL;
            cb(result, rtcWork.callbackArg);
        }
    }
}
