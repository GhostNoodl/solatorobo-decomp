#include "nitro/os.h"
#include "nitro/pm.h"

#define PM_CALLBACK_PRIORITY_MAX 255
#define PM_CALLBACK_PRIORITY_MIN (-255)

#define PMi_INSERT_BEFORE_SAME_PRIORITY 0
#define PMi_INSERT_AFTER_SAME_PRIORITY 1

extern PMSleepCallbackInfo *data_02090c7c;
extern PMSleepCallbackInfo *data_02090c64;
extern u32 data_0208afc8;

typedef struct {
    u8 unk_00[0x10];
    u32 unk_10;
} PMiWork_02090c60;

extern PMiWork_02090c60 data_02090c60;

void OS_SpinWaitSysCycles(u32 cycles);
u32 PM_SetBackLight(u32 a, u32 b);
u32 PM_SetLCDPower(u32 a);

BOOL func_0201e280(void) {
    return (*(vu16 *)0x04000304 & 1) ? TRUE : FALSE;
}

void PMi_InsertList(PMSleepCallbackInfo **listp, PMSleepCallbackInfo *info, int priority, int method) {
    OSIntrMode enabled;
    PMSleepCallbackInfo *p;
    PMSleepCallbackInfo *pre;

    if (!listp) {
        return;
    }

    info->priority = priority;

    enabled = OS_DisableInterrupts();

    p = *listp;
    pre = NULL;
    while (p) {
        if (method == 0 && p->priority > priority) {
            break;
        }
        if (method == 1 && p->priority >= priority) {
            break;
        }
        pre = p;
        p = p->next;
    }

    if (p) {
        info->next = p;
    } else {
        info->next = NULL;
    }

    if (pre) {
        pre->next = info;
    } else {
        *listp = info;
    }

    (void)OS_RestoreInterrupts(enabled);
}

void PMi_DeleteList(PMSleepCallbackInfo **listp, PMSleepCallbackInfo *info) {
    OSIntrMode enabled;
    PMSleepCallbackInfo *p;
    PMSleepCallbackInfo *pre;

    if (!listp) {
        return;
    }

    enabled = OS_DisableInterrupts();

    pre = p = *listp;
    while (p) {
        if (p == info) {
            if (p == pre) {
                *listp = p->next;
            } else {
                pre->next = p->next;
            }
            break;
        }

        pre = p;
        p = p->next;
    }

    (void)OS_RestoreInterrupts(enabled);
}

void PMi_ExecuteList(PMSleepCallbackInfo *listp) {
    while (listp) {
        (listp->callback)(listp->arg);
        listp = listp->next;
    }
}

void PM_AppendPreSleepCallback(PMSleepCallbackInfo *info) {
    PMi_InsertList(&data_02090c7c, info, PM_CALLBACK_PRIORITY_MAX, 0);
}

void PM_PrependPreSleepCallback(PMSleepCallbackInfo *info) {
    PMi_InsertList(&data_02090c7c, info, PM_CALLBACK_PRIORITY_MIN, 1);
}

void PM_AppendPostSleepCallback(PMSleepCallbackInfo *info) {
    PMi_InsertList(&data_02090c64, info, PM_CALLBACK_PRIORITY_MAX, 0);
}

void PM_InsertPreSleepCallback(PMSleepCallbackInfo *info, int priority) {
    PMi_InsertList(&data_02090c7c, info, priority, 0);
}

void PM_DeletePreSleepCallback(PMSleepCallbackInfo *info) {
    PMi_DeleteList(&data_02090c7c, info);
}

void PM_DeletePostSleepCallback(PMSleepCallbackInfo *info) {
    PMi_DeleteList(&data_02090c64, info);
}

void func_0201e45c(void) {
    u32 saved;

    OS_SpinWaitSysCycles(0x360000);

    saved = data_0208afc8;
    data_0208afc8 = 14;

    if (func_0201e280() != TRUE) {
        while (PM_SetBackLight(2, 0) != 0) {
            OS_SpinWaitSysCycles(0x51d23);
        }
        while (PM_SetLCDPower(1) == 0) {
            OS_SpinWaitSysCycles(5);
        }
    }

    data_0208afc8 = saved;
}

void func_0201e504(void) {
    data_02090c60.unk_10 = *(u32 *)0x02fffc3c;
}
