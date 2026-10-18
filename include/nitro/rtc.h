#ifndef NITRO_RTC_H
#define NITRO_RTC_H

// From the NitroSDK (/tmp/claude-0/-home-claude/052afc25-6b89-5b17-ace0-44ef4583ece4/scratchpad/mainlow4/t/rtc_all.h)
#include "types.h"
#include "nitro/pxi.h"

#ifdef __cplusplus
extern "C" {
#endif
#define RTC_INTERRUPT_MODE_NONE             0x0
#define RTC_INTERRUPT_MODE_32kHz            0x8
#define RTC_INTERRUPT_MODE_PULSE            0x1
#define RTC_INTERRUPT_MODE_MINUTE_EDGE      0x2
#define RTC_INTERRUPT_MODE_MINUTE_PULSE1    0x3
#define RTC_INTERRUPT_MODE_ALARM            0x4
#define RTC_INTERRUPT_MODE_MINUTE_PULSE2    0x7

#define RTC_INTERRUPT_MASK_32kHz            0x8
#define RTC_INTERRUPT_MASK_PULSE            0xb
#define RTC_INTERRUPT_MASK_MINUTE_EDGE      0xb

#define RTC_PULSE_DUTY_1HZ                  0x01
#define RTC_PULSE_DUTY_2HZ                  0x02
#define RTC_PULSE_DUTY_4HZ                  0x04
#define RTC_PULSE_DUTY_8HZ                  0x08
#define RTC_PULSE_DUTY_16HZ                 0x10

typedef struct RTCRawDate {
    u32 year :8;
    u32 month :5;
    u32 dummy0 :3;
    u32 day :6;
    u32 dummy1 :2;
    u32 week :3;
    u32 dummy2 :5;
} RTCRawDate;

typedef struct RTCRawTime {
    u32 hour :6;
    u32 afternoon :1;
    u32 dummy0 :1;
    u32 minute :7;
    u32 dummy1 :1;
    u32 second :7;
    u32 dummy2 :9;
} RTCRawTime;

typedef struct RTCRawStatus1 {
    u16 reset :1;
    u16 format :1;
    u16 dummy0 :2;
    u16 intr1 :1;
    u16 intr2 :1;
    u16 bld :1;
    u16 poc :1;
    u16 dummy1 :8;
} RTCRawStatus1;

typedef struct RTCRawStatus2 {
    u16 intr_mode :4;
    u16 dummy0 :2;
    u16 intr2_mode :1;
    u16 test :1;
    u16 dummy1 :8;
} RTCRawStatus2;

typedef struct RTCRawAlarm {
    u32 week :3;
    u32 dummy0 :4;
    u32 we :1;
    u32 hour :6;
    u32 afternoon :1;
    u32 he :1;
    u32 minute :7;
    u32 me :1;
    u32 dummy2 :8;
} RTCRawAlarm;

typedef struct RTCRawPulse {
    u32 pulse :5;
    u32 dummy :27;
} RTCRawPulse;

typedef struct RTCRawAdjust {
    u32 adjust :8;
    u32 dummy :24;
} RTCRawAdjust;

typedef struct RTCRawFree {
    u32 free :8;
    u32 dummy :24;
} RTCRawFree;

typedef union RTCRawData {
    struct {
        RTCRawDate date;
        RTCRawTime time;
    } t;
    struct {
        RTCRawStatus1 status1;
        RTCRawStatus2 status2;
        union {
            RTCRawPulse pulse;
            RTCRawAlarm alarm;
            RTCRawAdjust adjust;
            RTCRawFree free;
        };
    } a;
    u32 words[2];
    u16 halfs[4];
    u8 bytes[8];
} RTCRawData;


#define RTC_PXI_COMMAND_MASK                0x00007f00
#define RTC_PXI_COMMAND_SHIFT               8
#define RTC_PXI_RESULT_BIT_MASK             0x00008000
#define RTC_PXI_RESULT_MASK                 0x000000ff
#define RTC_PXI_RESULT_SHIFT                0

#define RTC_PXI_COMMAND_RESET               0x00
#define RTC_PXI_COMMAND_SET_HOUR_FORMAT     0x01
#define RTC_PXI_COMMAND_READ_DATETIME       0x10
#define RTC_PXI_COMMAND_READ_DATE           0x11
#define RTC_PXI_COMMAND_READ_TIME           0x12
#define RTC_PXI_COMMAND_READ_PULSE          0x13
#define RTC_PXI_COMMAND_READ_ALARM1         0x14
#define RTC_PXI_COMMAND_READ_ALARM2         0x15
#define RTC_PXI_COMMAND_READ_STATUS1        0x16
#define RTC_PXI_COMMAND_READ_STATUS2        0x17
#define RTC_PXI_COMMAND_READ_ADJUST         0x18
#define RTC_PXI_COMMAND_READ_FREE           0x19
#define RTC_PXI_COMMAND_WRITE_DATETIME      0x20
#define RTC_PXI_COMMAND_WRITE_DATE          0x21
#define RTC_PXI_COMMAND_WRITE_TIME          0x22
#define RTC_PXI_COMMAND_WRITE_PULSE         0x23
#define RTC_PXI_COMMAND_WRITE_ALARM1        0x24
#define RTC_PXI_COMMAND_WRITE_ALARM2        0x25
#define RTC_PXI_COMMAND_WRITE_STATUS1       0x26
#define RTC_PXI_COMMAND_WRITE_STATUS2       0x27
#define RTC_PXI_COMMAND_WRITE_ADJUST        0x28
#define RTC_PXI_COMMAND_WRITE_FREE          0x29
#define RTC_PXI_COMMAND_INTERRUPT           0x30

typedef enum RTCPxiResult {
    RTC_PXI_RESULT_SUCCESS = 0,
    RTC_PXI_RESULT_INVALID_COMMAND,
    RTC_PXI_RESULT_ILLEGAL_STATUS,
    RTC_PXI_RESULT_BUSY,
    RTC_PXI_RESULT_FATAL_ERROR,
    RTC_PXI_RESULT_MAX
} RTCPxiResult;


typedef enum RTCWeek {
    RTC_WEEK_SUNDAY = 0,
    RTC_WEEK_MONDAY,
    RTC_WEEK_TUESDAY,
    RTC_WEEK_WEDNESDAY,
    RTC_WEEK_THURSDAY,
    RTC_WEEK_FRIDAY,
    RTC_WEEK_SATURDAY,
    RTC_WEEK_MAX
} RTCWeek;

typedef enum RTCAlarmChan {
    RTC_ALARM_CHAN_1 = 0,
    RTC_ALARM_CHAN_2,
    RTC_ALARM_CHAN_MAX
} RTCAlarmChan;

typedef enum RTCAlarmStatus {
    RTC_ALARM_STATUS_OFF = 0,
    RTC_ALARM_STATUS_ON,
    RTC_ALARM_STATUS_MAX
} RTCAlarmStatus;

#define RTC_ALARM_ENABLE_NONE       0x0000
#define RTC_ALARM_ENABLE_WEEK       0x0001
#define RTC_ALARM_ENABLE_HOUR       0x0002
#define RTC_ALARM_ENABLE_MINUTE     0x0004
#define RTC_ALARM_ENABLE_ALL        (RTC_ALARM_ENABLE_WEEK | RTC_ALARM_ENABLE_HOUR | RTC_ALARM_ENABLE_MINUTE)

typedef enum RTCResult {
    RTC_RESULT_SUCCESS = 0,
    RTC_RESULT_BUSY,
    RTC_RESULT_ILLEGAL_PARAMETER,
    RTC_RESULT_SEND_ERROR,
    RTC_RESULT_INVALID_COMMAND,
    RTC_RESULT_ILLEGAL_STATUS,
    RTC_RESULT_FATAL_ERROR,
    RTC_RESULT_MAX
} RTCResult;

typedef void (*RTCCallback) (RTCResult result, void * arg);
typedef void (*RTCInterrupt) (void);

typedef struct RTCDate {
    u32 year;
    u32 month;
    u32 day;
    RTCWeek week;
} RTCDate;

typedef struct RTCTime {
    u32 hour;
    u32 minute;
    u32 second;
} RTCTime;

typedef struct RTCTimeEx {
    s32 hour;
    s32 minute;
    s32 second;
    s32 millisecond;
} RTCTimeEx;

typedef struct RTCAlarmParam {
    RTCWeek week;
    u32 hour;
    u32 minute;
    u32 enable;
} RTCAlarmParam;

void RTC_Init(void);

RTCResult RTC_GetDate(RTCDate * date);
RTCResult RTC_GetTime(RTCTime * time);
RTCResult RTC_GetDateTime(RTCDate * date, RTCTime * time);
RTCResult RTC_GetDateTimeExByTick(RTCDate * date, RTCTimeEx * time);

RTCResult RTC_SetDate(const RTCDate * date);
RTCResult RTC_SetTime(const RTCTime * time);
RTCResult RTC_SetDateTime(const RTCDate * date, const RTCTime * time);

RTCResult RTC_GetAlarmStatus(RTCAlarmChan chan, RTCAlarmStatus * status);
RTCResult RTC_GetAlarmParam(RTCAlarmChan chan, RTCAlarmParam * param);

RTCResult RTC_SetAlarmStatus(RTCAlarmChan chan, const RTCAlarmStatus * status);
RTCResult RTC_SetAlarmParam(RTCAlarmChan chan, const RTCAlarmParam * param);

RTCResult RTC_GetDateAsync(RTCDate * date, RTCCallback callback, void * arg);
RTCResult RTC_GetTimeAsync(RTCTime * time, RTCCallback callback, void * arg);
RTCResult RTC_GetDateTimeAsync(RTCDate * date, RTCTime * time, RTCCallback callback, void * arg);

RTCResult RTC_SetDateAsync(const RTCDate * date, RTCCallback callback, void * arg);
RTCResult RTC_SetTimeAsync(const RTCTime * time, RTCCallback callback, void * arg);
RTCResult RTC_SetDateTimeAsync(const RTCDate * date, const RTCTime * time, RTCCallback callback, void * arg);

RTCResult RTC_GetAlarmStatusAsync(RTCAlarmChan chan, RTCAlarmStatus * status, RTCCallback callback, void * arg);
RTCResult RTC_GetAlarmParamAsync(RTCAlarmChan chan, RTCAlarmParam * param, RTCCallback callback, void * arg);

void RTC_SetAlarmInterrupt(RTCInterrupt interrupt);

RTCResult RTC_SetAlarmStatusAsync(RTCAlarmChan chan, const RTCAlarmStatus * status, RTCCallback callback, void * arg);
RTCResult RTC_SetAlarmParamAsync(RTCAlarmChan chan, const RTCAlarmParam * param, RTCCallback callback, void * arg);

BOOL RTCi_ResetAsync(void);
BOOL RTCi_SetHourFormatAsync(void);
BOOL RTCi_ReadRawDateTimeAsync(void);
BOOL RTCi_WriteRawDateTimeAsync(void);
BOOL RTCi_ReadRawDateAsync(void);
BOOL RTCi_WriteRawDateAsync(void);
BOOL RTCi_ReadRawTimeAsync(void);
BOOL RTCi_WriteRawTimeAsync(void);
BOOL RTCi_ReadRawPulseAsync(void);
BOOL RTCi_WriteRawPulseAsync(void);
BOOL RTCi_ReadRawAlarm1Async(void);
BOOL RTCi_WriteRawAlarm1Async(void);
BOOL RTCi_ReadRawAlarm2Async(void);
BOOL RTCi_WriteRawAlarm2Async(void);
BOOL RTCi_ReadRawStatus1Async(void);
BOOL RTCi_WriteRawStatus1Async(void);
BOOL RTCi_ReadRawStatus2Async(void);
BOOL RTCi_WriteRawStatus2Async(void);
BOOL RTCi_ReadRawAdjustAsync(void);
BOOL RTCi_WriteRawAdjustAsync(void);
BOOL RTCi_ReadRawFreeAsync(void);
BOOL RTCi_WriteRawFreeAsync(void);

RTCResult RTCi_SetRegStatus2Async(const RTCRawStatus2 * status2, RTCCallback callback, void * arg);
RTCResult RTCi_SetRegAdjustAsync(const RTCRawAdjust * adjust, RTCCallback callback, void * arg);
RTCResult RTCi_SetRegAdjust(const RTCRawAdjust * Adjust);
RTCResult RTCi_SetRegStatus2(const RTCRawStatus2 * status2);


s32 RTC_ConvertDateToDay(const RTCDate * date);
s32 RTCi_ConvertTimeToSecond(const RTCTime * time);
s64 RTC_ConvertDateTimeToSecond(const RTCDate * date, const RTCTime * time);

void RTC_ConvertDayToDate(RTCDate * date, s32 day);
void RTCi_ConvertSecondToTime(RTCTime * time, s32 sec);
void RTC_ConvertSecondToDateTime(RTCDate * date, RTCTime * time, s64 sec);

RTCWeek RTC_GetDayOfWeek(RTCDate * date);

#ifdef __cplusplus
}
#endif

#endif
