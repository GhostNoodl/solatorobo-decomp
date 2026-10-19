#include "types.h"

#pragma force_active on

typedef struct {
    u8 language;
    u8 favoriteColor;
    u8 month;
    u8 day;
    u16 nickName[11];
    u16 nickNameLength;
    u16 comment[27];
    u16 commentLength;
} OSOwnerInfo;

typedef struct {
    u32 unk_00;
    u32 (*fn)(u32 a, u32 b);
    u32 a;
    u32 b;
    u32 result;
    u32 code;
} Ov004Call;

extern void OS_GetMacAddress(u8 *mac);
extern void OS_GetOwnerInfo(OSOwnerInfo *info);
extern u8 data_ov004_021cf7dc[];

s32 func_ov004_021ce874(Ov004Call *c) {
    u8 mac[6];
    OSOwnerInfo info;
    s32 i;
    s32 r;
    OS_GetMacAddress(mac);
    for (i = 0; i < 6; i++) {
        if (data_ov004_021cf7dc[i] != (mac[i] ^ 0xff)) {
            break;
        }
    }
    OS_GetOwnerInfo(&info);
    if (i == 6 && info.month == 1 && info.day == 1 && info.nickNameLength == 0) {
        c->result = c->fn(c->a, c->b);
        r = 0xfb;
        c->code = r;
    } else {
        for (i = 0; i < 6; i++) {
            if (mac[i] != 0) {
                r = 0xf1;
                goto end;
            }
        }
        c->result = c->fn(c->a, c->b);
        r = 0xfb;
        c->code = r;
    }
end:
    return r * 0xc1;
}

s32 func_ov004_021ce934(Ov004Call *c) {
    u8 mac[6];
    OSOwnerInfo info;
    s32 i;
    s32 r;
    OS_GetMacAddress(mac);
    for (i = 0; i < 6; i++) {
        if (data_ov004_021cf7dc[i] != (mac[i] ^ 0xff)) {
            break;
        }
    }
    OS_GetOwnerInfo(&info);
    if (i == 6 && info.month == 1 && info.day == 1 && info.nickNameLength == 0) {
        c->result = c->fn(c->a, c->b);
        r = 0xf1;
        c->code = r + 0xf1;
    } else {
        for (r = 0; r < 6; r++) {
            if (mac[r] != 0) {
                r = 0xfb;
                goto end;
            }
        }
        c->result = c->fn(c->a, c->b);
        c->code = 0x78;
        r = 0xf1;
    }
end:
    return r * 0xad;
}

#define CRC_STEP(c)              \
    if ((c) & 1) {               \
        (c) >>= 1;               \
    } else {                     \
        (c) = ((c) >> 1) ^ 0xedb88320; \
    }

u32 func_ov004_021cea18(const u8 *p, u32 n) {
    u32 c = ~0;
    while (n-- != 0) {
        c ^= *p++;
        CRC_STEP(c)
        CRC_STEP(c)
        CRC_STEP(c)
        CRC_STEP(c)
        CRC_STEP(c)
        CRC_STEP(c)
        CRC_STEP(c)
        CRC_STEP(c)
    }
    return ~c;
}

#pragma force_active reset
