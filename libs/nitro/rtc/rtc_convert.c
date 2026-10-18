#include "nitro/rtc.h"

static s32 sDayOfYear[12] = { 0, 31, 59, 90, 120, 151, 181, 212, 243, 273, 304, 334 };

static inline BOOL RTCi_IsLeapYear (u32 year)
{
    return !((year & 0x03));
}

RTCWeek RTC_GetDayOfWeek (RTCDate * date)
{
    int cent;
    int year = (int)(2000 + date->year);
    int month = (int)date->month;
    int day = (int)date->day;

    month -= 2;

    if (month < 1) {
        month += 12;
        --year;
    }

    cent = year / 100;
    year %= 100;
    return (RTCWeek)(((26 * month - 2) / 10 + day + year + year / 4 + cent / 4 + 5 * cent) % 7);
}
