#ifndef PM_WORK_H
#define PM_WORK_H

#include "nitro/os.h"
#include "nitro/pm.h"
#include "nitro/pxi.h"

#define PXI_FIFO_TAG_PM 8

#define PM_RESULT_SUCCESS 0
#define PM_RESULT_BUSY    1
#define PM_INVALID_COMMAND 0xffff

#define PM_BUSY_WAIT_CYCLES 0x51d23

typedef void (*PMCallback)(u32 result, void *arg);

typedef struct PMiWork {
    u16 init;                          // 0x00
    u16 pad_02;
    PMSleepCallbackInfo *postSleepList; // 0x04
    volatile BOOL wakeUp;              // 0x08
    u32 lcdOffCount;                   // 0x0c
    u32 lcdOnCount;                    // 0x10
    u32 unk_14;                        // 0x14
    u32 unk_18;                        // 0x18
    PMSleepCallbackInfo *preSleepList; // 0x1c
    u32 dmaCnt[4];                     // 0x20
    volatile BOOL lock;                // 0x30
    PMCallback callback;               // 0x34
    void *callbackArg;                 // 0x38
    u16 *data;                         // 0x3c
} PMiWork;

extern PMiWork data_02090c60;
#define PMi_Work data_02090c60

extern u32 data_0208afc8;

#define REG_IME    (*(vu16 *)0x04000208)
#define REG_POWCNT (*(vu16 *)0x04000304)
static inline u32 OS_GetVBlankCount(void) {
    return *(vu32 *)0x02fffc3c;
}

void PMi_WaitBusy(void);
void PMi_DummyCallback(u32 result, void *arg);
void PMi_CallCallbackAndUnlock(u32 result);
void PMi_WaitVBlank(void);
u32 PMi_SendPxiCommandList(u32 *sendData, int num, u16 *retValue, PMCallback callback, void *arg);
void PMi_SendSleepCommand(u32 *sendData, int num);
u32 PMi_SendSleepStart(u32 trigger, u32 keyIntrData);
u32 PM_SendUtilityCommandAsync(u32 number, u32 parameter, u16 *retValue, PMCallback callback, void *arg);
u32 PM_SendUtilityCommand(u32 number, u32 parameter, u16 *retValue);
u32 PMi_SetLEDAsync(u32 status, PMCallback callback, void *arg);
u32 PMi_SetLED(u32 status);
u32 PM_SetBackLightAsync(u32 target, u32 sw, PMCallback callback, void *arg);
u32 PM_SetBackLight(u32 target, u32 sw);
u32 PM_ForceToPowerOffAsync(PMCallback callback, void *arg);
u32 PMi_ForceToPowerOffAsyncAndWait(void);
void PM_ForceToPowerOff(void);
u32 func_0201dbe8(u32 count);
u32 PM_GetBackLight(BOOL *top, BOOL *bottom);
void PMi_SendPxiData(u32 data);
void func_0201dca4(void);
BOOL PMi_SetLCDPower(u32 sw, u32 led, BOOL skip, BOOL isSync);
BOOL PM_SetLCDPower(u32 sw);
BOOL func_0201e280(void);
void func_0201e45c(void);
void PMi_ExecuteList(PMSleepCallbackInfo *listp);

#endif
