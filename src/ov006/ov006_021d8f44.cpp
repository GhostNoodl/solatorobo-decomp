#include "ov006/SlotManager.h"

typedef struct ov006_OwnerInfo {
    u8 unk0;
    u8 unk1;
    u8 month;
    u8 day;
    u8 unk4[0x50];
} ov006_OwnerInfo;

typedef struct ov006_Date {
    u32 year;
    u32 month;
    u32 day;
    u32 week;
} ov006_Date;

extern "C" {

void OS_GetOwnerInfo(ov006_OwnerInfo *info);
void RTC_GetDate(ov006_Date *date);
void OS_GetMacAddress(u8 *macAddr);
extern const u8 data_ov006_021eb7f0[][2];

void func_ov006_021d8f44(void) {
    u8 n;
    int i;
    u8 sum;
    const u8 *p;
    u8 mac[6];
    ov006_Date date;
    ov006_OwnerInfo info;

    {
        ov006_SlotManager *g = data_ov006_021ec884;
        for (i = 0; i < 3; i++) {
            g->unk14A[i] = 0;
        }
    }
    n = 0;
    OS_GetOwnerInfo(&info);
    RTC_GetDate(&date);
    if (date.month == info.month) {
        if (date.day == info.day) {
            data_ov006_021ec884->unk14A[n] = 9;
            n++;
        } else {
            data_ov006_021ec884->unk14A[n] = 10;
            n++;
        }
    } else {
        data_ov006_021ec884->unk14A[n] = n;
        n++;
    }
    OS_GetMacAddress(mac);
    sum = 0;
    for (i = 0; i < 6; i++) {
        sum += mac[i];
    }
    sum += (u8)date.month;
    sum += (u8)date.day;
    sum = sum % 25;
    p = data_ov006_021eb7f0[sum];
    for (i = 0; i < 2; i++) {
        if (p[i] != 0) {
            ov006_SlotManager *g = data_ov006_021ec884;
            if (n < 3) {
                g->unk14A[n] = p[i];
            }
            n++;
        }
    }
}

}
