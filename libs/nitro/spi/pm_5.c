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
