#include "nitro/os.h"
#include "nitro/os_tick.h"
#include "nitro/gx_disp.h"

#define HW_SYSTEM_WORK              0x02fffc00
#define OS_LOW_ENTROPY_DATA_SIZE    32

#define reg_PAD_KEYINPUT            (*(vu16 *)0x04000130)
#define reg_G3X_GXSTAT              (*(vu32 *)0x04000600)

typedef struct OSSystemWork {
    u8 pad_000[0x3c];
    u32 vblankCount;                    /* 0x03c */
    u8 pad_040[0x80 - 0x40];
    u8 nvramUserInfo[0x100];            /* 0x080 */
    u8 pad_180[0x1e8 - 0x180];
    u8 real_time_clock[8];              /* 0x1e8 */
    u8 pad_1f0[0x390 - 0x1f0];
    void *mic_last_address;             /* 0x390 */
    u16 mic_sampling_data;              /* 0x394 */
    u16 pad_396;
    u16 wm_rssi_pool;                   /* 0x398 */
    u8 pad_39a[0x3a8 - 0x39a];
    u16 button_XY;                      /* 0x3a8 */
    u8 touch_panel[4];                  /* 0x3aa */
} OSSystemWork;

#define OS_GetSystemWork() ((OSSystemWork *)HW_SYSTEM_WORK)
#define HW_BUTTON_XY_BUF   ((u32)HW_SYSTEM_WORK + 0x3a8)

extern vu64 OSi_TickCounter;

void OS_GetLowEntropyData(u32 buffer[OS_LOW_ENTROPY_DATA_SIZE / sizeof(u32)]);

void OS_GetLowEntropyData (u32 buffer[OS_LOW_ENTROPY_DATA_SIZE / sizeof(u32)])
{
    const OSSystemWork * work = OS_GetSystemWork();
    const u8 * macAddress = (u8 *)((u32)(work->nvramUserInfo) + 0x74);

    buffer[0] = (u32)((GX_GetVCount() << 16) | OS_GetTickLo());
    buffer[1] = (u32)(*(u16 *)(macAddress + 4) << 16) ^ (u32)(OSi_TickCounter);
    buffer[2] = (u32)(OSi_TickCounter >> 32) ^ *(u32 *)macAddress ^ work->vblankCount;
    buffer[2] ^= reg_G3X_GXSTAT;
    buffer[3] = *(u32 *)(&work->real_time_clock[0]);
    buffer[4] = *(u32 *)(&work->real_time_clock[4]);
    buffer[5] = (((u32)work->mic_sampling_data) << 16) ^ (u32)work->mic_last_address;
    buffer[6] = (u32)((*(u16 *)(&work->touch_panel[0]) << 16) | *(u16 *)(&work->touch_panel[2]));
    buffer[7] = (u32)((work->wm_rssi_pool << 16) | (reg_PAD_KEYINPUT | *(vu16 *)HW_BUTTON_XY_BUF));
}
