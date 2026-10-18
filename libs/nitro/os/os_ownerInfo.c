#include "nitro/os.h"
#include "nitro/mi.h"

#define HW_NVRAM_USER_INFO      0x02fffc80

#define OS_OWNERINFO_NICKNAME_MAX   10
#define OS_OWNERINFO_COMMENT_MAX    26

typedef struct OSBirthday {
    u8 month;
    u8 day;
} OSBirthday;

typedef struct OSOwnerInfo {
    u8 language;
    u8 favoriteColor;
    OSBirthday birthday;
    u16 nickName[OS_OWNERINFO_NICKNAME_MAX + 1];
    u16 nickNameLength;
    u16 comment[OS_OWNERINFO_COMMENT_MAX + 1];
    u16 commentLength;
} OSOwnerInfo;

typedef struct NVRAMConfigDate {
    u8 month;
    u8 day;
} NVRAMConfigDate;

typedef struct NVRAMConfigNickname {
    u16 str[OS_OWNERINFO_NICKNAME_MAX];
    u8 length;
    u8 rsv;
} NVRAMConfigNickname;

typedef struct NVRAMConfigComment {
    u16 str[OS_OWNERINFO_COMMENT_MAX];
    u8 length;
    u8 rsv;
} NVRAMConfigComment;

typedef struct NVRAMConfigOwnerInfo {
    u8 favoriteColor:4;
    u8 rsv:4;
    NVRAMConfigDate birthday;
    u8 pad;
    NVRAMConfigNickname nickname;
    NVRAMConfigComment comment;
} NVRAMConfigOwnerInfo;

typedef struct NVRAMConfigAlarm {
    u8 hour;
    u8 minute;
    u8 second;
    u8 pad;
    u16 enableWeek:7;
    u16 alarmOn:1;
    u16 rsv:8;
} NVRAMConfigAlarm;

typedef struct NVRAMConfigTpCalibData {
    u16 raw_x1;
    u16 raw_y1;
    u8 dx1;
    u8 dy1;
    u16 raw_x2;
    u16 raw_y2;
    u8 dx2;
    u8 dy2;
} NVRAMConfigTpCalibData;

typedef struct NVRAMConfigOption {
    u16 language:3;
    u16 agbLcd:1;
    u16 detectPullOutCardFlag:1;
    u16 detectPullOutCtrdgFlag:1;
    u16 autoBootFlag:1;
    u16 rsv:4;
    u16 input_favoriteColor:1;
    u16 input_tp:1;
    u16 input_language:1;
    u16 input_rtc:1;
    u16 input_nickname:1;
    u8 timezone;
    u8 rtcClockAdjust;
    s64 rtcOffset;
} NVRAMConfigOption;

typedef struct NVRAMConfigData {
    u8 version;
    u8 pad;
    NVRAMConfigOwnerInfo owner;
    NVRAMConfigAlarm alarm;
    NVRAMConfigTpCalibData tp;
    NVRAMConfigOption option;
} NVRAMConfigData;

typedef struct NVRAMConfig {
    NVRAMConfigData ncd;
    u16 saveCount;
    u16 crc16;
} NVRAMConfig;

void OS_GetMacAddress(u8 * macAddress);
void OS_GetOwnerInfo(OSOwnerInfo * info);

void OS_GetMacAddress (u8 * macAddress)
{
    u8 * src;

    src = (u8 *)((u32)HW_NVRAM_USER_INFO + ((sizeof(NVRAMConfig) + 3) & ~0x00000003));
    MI_CpuCopy8(src, macAddress, 6);
}

void OS_GetOwnerInfo (OSOwnerInfo * info)
{
    NVRAMConfig * src;

    src = (NVRAMConfig *)HW_NVRAM_USER_INFO;

    info->language = (u8)(src->ncd.option.language);
    info->favoriteColor = (u8)(src->ncd.owner.favoriteColor);
    info->birthday.month = (u8)(src->ncd.owner.birthday.month);
    info->birthday.day = (u8)(src->ncd.owner.birthday.day);
    info->nickNameLength = (u16)(src->ncd.owner.nickname.length);
    info->commentLength = (u16)(src->ncd.owner.comment.length);

    MI_CpuCopy16(src->ncd.owner.nickname.str, info->nickName, OS_OWNERINFO_NICKNAME_MAX * sizeof(u16));
    MI_CpuCopy16(src->ncd.owner.comment.str, info->comment, OS_OWNERINFO_COMMENT_MAX * sizeof(u16));

    info->nickName[OS_OWNERINFO_NICKNAME_MAX] = 0;
    info->comment[OS_OWNERINFO_COMMENT_MAX] = 0;
}
