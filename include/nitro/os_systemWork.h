#ifndef NITRO_OS_SYSTEMWORK_H
#define NITRO_OS_SYSTEMWORK_H

#include "types.h"

#ifdef __cplusplus
extern "C" {
#endif

#define HW_SYSTEM_WORK  0x02fffc00

/* TWL layout of the shared system work area (only the fields used here) */
typedef struct OSSystemWork {
    u8 pad_000[0x3c];
    u32 vblankCount;                    /* 0x03c */
    u8 pad_040[0x80 - 0x40];
    u8 nvramUserInfo[0x100];            /* 0x080 */
    u8 pad_180[0x1e8 - 0x180];
    u8 real_time_clock[8];              /* 0x1e8 */
    u8 pad_1f0[0x388 - 0x1f0];
    u32 pxiHandleChecker[2];            /* 0x388 */
    void *mic_last_address;             /* 0x390 */
    u16 mic_sampling_data;              /* 0x394 */
    u16 pad_396;
    u16 wm_rssi_pool;                   /* 0x398 */
    u8 pad_39a[0x3a8 - 0x39a];
    u16 button_XY;                      /* 0x3a8 */
    u8 touch_panel[4];                  /* 0x3aa */
} OSSystemWork;

#define OS_GetSystemWork() ((OSSystemWork *)HW_SYSTEM_WORK)

#ifdef __cplusplus
}
#endif

#endif
