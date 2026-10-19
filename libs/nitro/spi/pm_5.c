#include "pm_work.h"

#pragma force_active on

void OS_SpinWaitSysCycles(u32 cycles);
OSIrqMask OS_GetIrqMask(void);
BOOL OS_IsTickAvailable(void);
u16 OS_GetBootType(void);
BOOL OS_IsRunOnTwl(void);
BOOL CTRDG_IsExisting(void);
void OS_Halt(void);
BOOL GX_IsDispOn(void);
void GX_DispOff(void);

#define REG_DISPCNT    (*(vu32 *)0x04000000)
#define REG_DB_DISPCNT (*(vu32 *)0x04001000)
#define REG_IF         (*(vu32 *)0x04000214)

#define PM_TRIGGER_CARD      0x08
#define PM_TRIGGER_CARTRIDGE 0x10

static inline u16 OS_DisableIrq(void) {
    u16 prep = REG_IME;
    REG_IME = 0;
    return prep;
}

static inline u16 OS_EnableIrq(void) {
    u16 prep = REG_IME;
    REG_IME = 1;
    return prep;
}

static inline u16 OS_RestoreIrq(u16 enable) {
    u16 prep = REG_IME;
    REG_IME = enable;
    return prep;
}

void PM_GoSleepMode(u32 trigger, u32 logic, u16 keyPattern) {
    BOOL powerOffFlag = FALSE;
    u16 prepIME;
    OSIntrMode intrMode;
    OSIrqMask preIrqMask;
    u32 preGX;
    u32 preGXS;
    BOOL preLCDPower;
    BOOL preTop;
    BOOL preBottom;

    PMi_ExecuteList(PMi_Work.preSleepList);

    prepIME = OS_DisableIrq();
    intrMode = OS_DisableInterrupts();
    preIrqMask = OS_DisableIrqMask((OSIrqMask)-1);
    (void)OS_SetIrqMask(0x40000 | (OS_IsTickAvailable() ? 8 : 0));
    (void)OS_RestoreInterrupts(intrMode);
    (void)OS_EnableIrq();

    if (trigger & PM_TRIGGER_CARD) {
        u16 bootType = OS_GetBootType();
        if (bootType == 2 || bootType == 3) {
            trigger &= ~PM_TRIGGER_CARD;
        }
    }
    if (trigger & PM_TRIGGER_CARTRIDGE) {
        if (OS_IsRunOnTwl() || !CTRDG_IsExisting()) {
            trigger &= ~PM_TRIGGER_CARTRIDGE;
        }
    }

    preGX = REG_DISPCNT;
    preGXS = REG_DB_DISPCNT;
    preLCDPower = func_0201e280();

    while (PM_GetBackLight(&preTop, &preBottom) != PM_RESULT_SUCCESS) {
        OS_SpinWaitSysCycles(PM_BUSY_WAIT_CYCLES);
    }
    while (PM_SetBackLight(2, 0) != PM_RESULT_SUCCESS) {
        OS_SpinWaitSysCycles(PM_BUSY_WAIT_CYCLES);
    }

    PMi_WaitVBlank();
    REG_DISPCNT &= ~0x30000;
    REG_DB_DISPCNT &= ~0x10000;
    PMi_WaitVBlank();
    PMi_WaitVBlank();
    func_0201dca4();

    PMi_Work.wakeUp = FALSE;
    {
        u32 bottom = preBottom ? 0x80 : 0;
        u32 top = preTop ? 0x40 : 0;
        u32 sleepTrigger;

        (void)OS_SetIrqMask(0x40000);
        sleepTrigger = trigger | top;
        (void)PMi_SendSleepStart((u16)(sleepTrigger | bottom), (u16)(logic | keyPattern));
    }
    while (!PMi_Work.wakeUp) {
        OS_Halt();
    }

    (void)OS_SetIrqMask(0x40000 | (OS_IsTickAvailable() ? 8 : 0));

    if (trigger & PM_TRIGGER_CARD) {
        if (REG_IF & 0x100000) {
            powerOffFlag = TRUE;
        }
    }

    if (!powerOffFlag) {
        if (preLCDPower == TRUE) {
            while (PMi_SetLCDPower(1, 1, 1, 1) != TRUE) {
            }
        } else {
            while (PMi_SetLED(1) != PM_RESULT_SUCCESS) {
                OS_SpinWaitSysCycles(PM_BUSY_WAIT_CYCLES);
            }
        }
        REG_DISPCNT = preGX;
        REG_DB_DISPCNT = preGXS;
    }

    OS_SpinWaitSysCycles(0x360000);

    (void)OS_DisableIrq();
    (void)OS_SetIrqMask(preIrqMask);
    (void)OS_RestoreInterrupts(intrMode);
    (void)OS_RestoreIrq(prepIME);

    if (powerOffFlag) {
        PM_ForceToPowerOff();
    }

    PMi_ExecuteList(PMi_Work.postSleepList);
}

BOOL PMi_SetLCDPower(u32 sw, u32 led, BOOL skip, BOOL isSync) {
    switch (sw) {
    case 1:
        if (!skip && OS_GetVBlankCount() - PMi_Work.lcdOffCount <= 7) {
            return FALSE;
        }

        if (led) {
            if (isSync) {
                while (PMi_SetLED(led) != PM_RESULT_SUCCESS) {
                    OS_SpinWaitSysCycles(PM_BUSY_WAIT_CYCLES);
                }
            } else {
                while (PMi_SetLEDAsync(led, NULL, NULL) != PM_RESULT_SUCCESS) {
                    OS_SpinWaitSysCycles(PM_BUSY_WAIT_CYCLES);
                }
            }
        }

        REG_POWCNT |= 1;

        while (func_0201dbe8(PMi_Work.unk_18) != PM_RESULT_SUCCESS) {
            OS_SpinWaitSysCycles(PM_BUSY_WAIT_CYCLES);
        }
        break;

    case 0:
        while (func_0201dbe8(0) != PM_RESULT_SUCCESS) {
            OS_SpinWaitSysCycles(PM_BUSY_WAIT_CYCLES);
        }

        if (OS_GetVBlankCount() - PMi_Work.lcdOnCount <= 2) {
            PMi_WaitVBlank();
            PMi_WaitVBlank();
        }

        REG_POWCNT &= ~1;
        PMi_Work.lcdOffCount = OS_GetVBlankCount();

        if (led) {
            if (isSync) {
                while (PMi_SetLED(led) != PM_RESULT_SUCCESS) {
                    OS_SpinWaitSysCycles(PM_BUSY_WAIT_CYCLES);
                }
            } else {
                while (PMi_SetLEDAsync(led, NULL, NULL) != PM_RESULT_SUCCESS) {
                    OS_SpinWaitSysCycles(PM_BUSY_WAIT_CYCLES);
                }
            }
        }
        break;
    }

    return TRUE;
}

BOOL PM_SetLCDPower(u32 sw) {
    if (sw != 1) {
        sw = 0;
        if (GX_IsDispOn()) {
            GX_DispOff();
        }
    }

    return PMi_SetLCDPower(sw, 0, FALSE, TRUE);
}
