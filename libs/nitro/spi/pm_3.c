#include "pm_work.h"

#pragma force_active on

void OS_SpinWaitSysCycles(u32 cycles);

u32 PMi_SendPxiCommandList(u32 *sendData, int num, u16 *retValue, PMCallback callback, void *arg) {
    OSIntrMode enabled = OS_DisableInterrupts();
    int n;

    if (PMi_Work.lock) {
        (void)OS_RestoreInterrupts(enabled);
        return PM_RESULT_BUSY;
    }

    PMi_Work.lock = TRUE;
    PMi_Work.data = retValue;
    PMi_Work.callback = callback;
    PMi_Work.callbackArg = arg;

    for (n = 0; n < num; n++) {
        PMi_SendPxiData(sendData[n]);
    }

    (void)OS_RestoreInterrupts(enabled);
    return PM_RESULT_SUCCESS;
}

void PMi_SendSleepCommand(u32 *sendData, int num) {
    volatile u32 result;

    while (TRUE) {
        result = 0xffff0000;

        while (PMi_SendPxiCommandList(sendData, num, NULL, PMi_DummyCallback, (void *)&result) != PM_RESULT_SUCCESS) {
            OS_SpinWaitSysCycles(PM_BUSY_WAIT_CYCLES);
        }

        while (result == 0xffff0000) {
            OS_SpinWaitSysCycles(PM_BUSY_WAIT_CYCLES);
        }

        if (result == PM_RESULT_SUCCESS) {
            return;
        }

        OS_SpinWaitSysCycles(PM_BUSY_WAIT_CYCLES);
    }
}

u32 PMi_SendSleepStart(u32 trigger, u32 keyIntrData) {
    u32 command[2];

    command[0] = 0x03006000;
    PMi_SendSleepCommand(command, 1);

    while (PMi_SetLCDPower(0, 2, 0, 1) != TRUE) {
    }

    command[0] = 0x02006200 | (trigger & 0xff);
    command[1] = 0x01010000 | (u16)keyIntrData;
    PMi_SendSleepCommand(command, 2);

    return PM_RESULT_SUCCESS;
}

u32 PM_SendUtilityCommandAsync(u32 number, u32 parameter, u16 *retValue, PMCallback callback, void *arg) {
    u32 command[2];

    command[0] = 0x02006100 | (number & 0xff);
    command[1] = 0x01010000 | (u16)parameter;

    return PMi_SendPxiCommandList(command, 2, retValue, callback, arg);
}

u32 PM_SendUtilityCommand(u32 number, u32 parameter, u16 *retValue) {
    u32 commandResult;
    u32 sendResult = PM_SendUtilityCommandAsync(number, parameter, retValue, PMi_DummyCallback, &commandResult);

    if (sendResult != PM_RESULT_SUCCESS) {
        return sendResult;
    }

    PMi_WaitBusy();
    return commandResult;
}

u32 PMi_SetLEDAsync(u32 status, PMCallback callback, void *arg) {
    u32 command;

    switch (status) {
    case 1:
        command = 1;
        break;
    case 3:
        command = 2;
        break;
    case 2:
        command = 3;
        break;
    default:
        command = 0;
        break;
    }

    return command ? PM_SendUtilityCommandAsync(command, 0, NULL, callback, arg) : PM_INVALID_COMMAND;
}

u32 PMi_SetLED(u32 status) {
    u32 commandResult;
    u32 sendResult = PMi_SetLEDAsync(status, PMi_DummyCallback, &commandResult);

    if (sendResult != PM_RESULT_SUCCESS) {
        return sendResult;
    }

    PMi_WaitBusy();
    return commandResult;
}

u32 PM_SetBackLightAsync(u32 target, u32 sw, PMCallback callback, void *arg) {
    u32 command = 0;

    if (target == 0) {
        if (sw == 1) {
            command = 6;
        }
        if (sw == 0) {
            command = 7;
        }
    } else if (target == 1) {
        if (sw == 1) {
            command = 4;
        }
        if (sw == 0) {
            command = 5;
        }
    } else if (target == 2) {
        if (sw == 1) {
            command = 8;
        }
        if (sw == 0) {
            command = 9;
        }
    }

    return command ? PM_SendUtilityCommandAsync(command, 0, NULL, callback, arg) : PM_INVALID_COMMAND;
}

u32 PM_SetBackLight(u32 target, u32 sw) {
    u32 commandResult;
    u32 sendResult = PM_SetBackLightAsync(target, sw, PMi_DummyCallback, &commandResult);

    if (sendResult != PM_RESULT_SUCCESS) {
        return sendResult;
    }

    PMi_WaitBusy();
    return commandResult;
}

u32 PM_ForceToPowerOffAsync(PMCallback callback, void *arg) {
    PMi_Work.unk_14 = 3;

    func_0201e45c();

    if (OS_IsRunOnTwl()) {
        PMi_ExecuteList(*(PMSleepCallbackInfo **)0x022919ec);
    }

    return PM_SendUtilityCommandAsync(0xe, 0, NULL, callback, arg);
}

u32 PMi_ForceToPowerOffAsyncAndWait(void) {
    volatile u32 commandResult;
    u32 sendResult = PM_ForceToPowerOffAsync(PMi_DummyCallback, (void *)&commandResult);

    if (sendResult != PM_RESULT_SUCCESS) {
        return sendResult;
    }

    *(vu32 *)&data_0208afc8 = 12;
    PMi_WaitBusy();
    *(vu32 *)&data_0208afc8 = 2;

    return commandResult;
}
