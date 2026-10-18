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

extern RTCWork rtcWork;

/* rtcInitialized and rtcWork are one pooled block in rtc_external.c; the original
   single TU addressed rtcWork through it, which this split has to spell out */
typedef struct RTCPooledData {
    u16 initialized;
    RTCWork work;
} RTCPooledData;
extern RTCPooledData rtcInitialized;

u32 RtcBCD2HEX(u32 bcd);
void RtcGetResultCallback(RTCResult result, void * arg);
void RtcWaitBusy(void);

u32 RtcBCD2HEX (u32 bcd)
{
    u32 hex = 0;
    s32 i;
    s32 w;

    for (i = 0; i < 8; i++) {
        if (((bcd >> (i * 4)) & 0x0000000f) >= 0x0a) {
            return hex;
        }
    }

    for (i = 0, w = 1; i < 8; i++, w *= 10) {
        hex += (((bcd >> (i * 4)) & 0x0000000f) * w);
    }

    return hex;
}

void RtcGetResultCallback (RTCResult result, void * arg)
{
#pragma unused(arg)

    rtcInitialized.work.commonResult = result;
}

#pragma thumb off

asm void RtcWaitBusy (void)
{
    ldr r12, = rtcWork.lock
loop:
    ldr r0, [r12, #0]
    cmp r0, #RTC_LOCK_ON
    beq loop
    bx lr
}

#pragma thumb reset

