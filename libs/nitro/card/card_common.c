#include "card_private.h"
#include "nitro/os_valarm.h"

#pragma force_active on

typedef struct {
    vu32 flag;
    OSThreadQueue queue;
} CARDiEvent;

void OS_InitEvent(CARDiEvent *event);
u32 OSi_WaitEvent(CARDiEvent *event, u32 pattern, u32 mode, u32 clearBit);
void OS_SignalEvent(CARDiEvent *event, u32 setPattern);
s32 OS_TryLockCard(u16 lockID);
s32 OS_UnlockCard(u16 lockID);
void func_0200d85c(void);
void CARD_InitPulledOutCallback(void);
BOOL CARD_TryWaitBackupAsync(void);
BOOL CARD_WaitBackupAsync(void);

extern u32 data_0208de94;
extern CARDiCommandArg data_0208dea0;
extern u32 data_0208e540;

typedef struct CARDHookContext {
    struct CARDHookContext *next;
    void *userdata;
    void (*callback)(void *userdata, u32 event, void *arg);
} CARDHookContext;

extern CARDHookContext *data_0208e420;

typedef struct {
    CARDiEvent event;           // 0x00
    OSVAlarm valarm;            // 0x0c
    BOOL (*func)(void *arg);    // 0x34
    void *arg;                  // 0x38
    u32 pad;                    // 0x3c
} CARDiLockTask;

typedef struct {
    u8 unk_00[0x1b4];
    u32 unk_0_4 : 5;
    u32 game_card_nitro_mode : 1;
    u32 unk_6_7 : 2;
    u32 game_card_on : 1;
    u32 unk_9_14 : 6;
    u32 access_flag_0 : 1;
    u32 access_flag_1 : 1;
    u32 unk_17_31 : 15;
} CARDRomHeaderTWLAccess;

static void CARDi_LockTaskCallback(void *arg) {
    CARDiLockTask *task = (CARDiLockTask *)arg;

    if (task->func(task->arg)) {
        OS_SignalEvent(&task->event, 1);
    } else {
        OS_SetVAlarm(&task->valarm, 0xc0, 0x107, CARDi_LockTaskCallback, task);
    }
}

static BOOL CARDi_TryLockCardCallback(void *arg) {
    return OS_TryLockCard(*(u16 *)arg) == 0;
}

void CARDi_TaskThread(void *arg);

void CARD_Init(void) {
    CARDiCommon *p = &cardi_common;

    if (p->flag) {
        return;
    }

    p->flag = CARD_STAT_INIT;

    if (OS_GetBootType() == 1) {
        MI_CpuCopy8((void *)0x02fffe00, (void *)0x02fffa80, 0x160);
    }

    p->src = 0;
    p->dst = 0;
    p->len = 0;
    p->dma = (u32)-1;
    p->unk_50c = 0;
    p->unk_0c = 0x400;
    p->unk_10 = 0x2400;
    data_0208e540 = 0;
    p->priority = 4;

    CARDi_InitResources();

    p->callback = NULL;
    p->callback_arg = NULL;
    OS_InitThreadQueue(&p->busy_q);

    OS_CreateThread(&p->thread, CARDi_TaskThread, NULL, p->stack + sizeof(p->stack), sizeof(p->stack), p->priority);
    OS_WakeupThreadDirect(&p->thread);

    CARDi_InitCommand();
    func_0200d85c();

    if (OS_GetBootType() == 1) {
        CARD_Enable(TRUE);
    }

    CARD_InitPulledOutCallback();
}

BOOL CARD_IsAvailable(void) {
    return data_0208de94;
}

void CARD_CheckEnabled(void) {
    if (!CARD_IsAvailable()) {
        OS_Terminate();
    }
}

void CARD_Enable(BOOL enable) {
    data_0208de94 = enable;
}

u32 CARD_GetResultCode(void) {
    return cardi_common.cmd->result;
}

const u8 *CARD_GetRomHeader(void) {
    return (const u8 *)0x02fffa80;
}

const u8 *CARD_GetOwnRomHeader(void) {
    return (const u8 *)0x02fffe00;
}

const u8 *CARD_GetOwnRomHeaderTWL(void) {
    return (const u8 *)0x02ffe000;
}

void CARD_LockRom(u16 lock_id) {
    CARDi_LockResource(lock_id, CARD_TARGET_ROM);

    {
        CARDiLockTask task;

        OS_InitEvent(&task.event);
        OS_CreateVAlarm(&task.valarm);
        task.func = CARDi_TryLockCardCallback;
        task.arg = &lock_id;
        CARDi_LockTaskCallback(&task);
        (void)OSi_WaitEvent(&task.event, 1, 0, 1);
    }
}

void CARD_UnlockRom(u16 lock_id) {
    (void)OS_UnlockCard(lock_id);
    CARDi_UnlockResource(lock_id, CARD_TARGET_ROM);
}

void CARD_LockBackup(u16 lock_id) {
    CARDi_LockResource(lock_id, CARD_TARGET_BACKUP);
}

void CARD_UnlockBackup(u16 lock_id) {
    if (!CARD_TryWaitBackupAsync()) {
        (void)CARD_WaitBackupAsync();
    }
    CARDi_UnlockResource(lock_id, CARD_TARGET_BACKUP);
}

#pragma optimize_for_size on
void CARDi_LockResource(s32 owner, u32 target) {
    CARDiCommon *const p = &cardi_common;
    OSIntrMode bak_psr = OS_DisableInterrupts();

    if (p->lock_owner == owner) {
        if (p->lock_target != target) {
            OS_Terminate();
        }
    } else {
        while (p->lock_owner != OS_LOCK_ID_ERROR) {
            OS_SleepThread(&p->lock_queue);
        }
        p->lock_owner = owner;
        p->lock_target = target;
    }

    ++p->lock_ref;
    (void)OS_RestoreInterrupts(bak_psr);
}
#pragma optimize_for_size reset

void CARDi_UnlockResource(s32 owner, u32 target) {
    CARDiCommon *p = &cardi_common;
    OSIntrMode bak_psr = OS_DisableInterrupts();

    if (p->lock_owner != owner || !p->lock_ref) {
        OS_Terminate();
    } else {
        if (p->lock_target != target) {
            OS_Terminate();
        }
        if (!--p->lock_ref) {
            p->lock_owner = OS_LOCK_ID_ERROR;
            p->lock_target = CARD_TARGET_NONE;
            OS_WakeupThread(&p->lock_queue);
        }
    }

    (void)OS_RestoreInterrupts(bak_psr);
}

u32 CARDi_GetAccessLevel(void) {
    u32 level = 0;

    if (OS_GetBootType() == 1) {
        level = 7;
    } else if (!OS_IsRunOnTwl()) {
        level = 3;
    } else {
        const CARDRomHeaderTWLAccess *header = (const CARDRomHeaderTWLAccess *)CARD_GetOwnRomHeaderTWL();
        BOOL accessable = FALSE;

        if (header->game_card_on) {
            level |= 4;
            accessable = TRUE;
        } else if (header->game_card_nitro_mode) {
            accessable = TRUE;
        }

        if (accessable) {
            if (header->access_flag_0) {
                level |= 1;
            }
            if (header->access_flag_1) {
                level |= 2;
            }
        }
    }

    return level;
}

BOOL CARDi_WaitAsync(void) {
    return CARDi_WaitForTask(&cardi_common, FALSE, NULL, NULL);
}

BOOL CARDi_TryWaitAsync(void) {
    return !(cardi_common.flag & CARD_STAT_BUSY);
}


#pragma push
#pragma opt_propagation off
void CARDi_InitResources(void) {
    CARDiCommon *p = &cardi_common;
    p->lock_owner = OS_LOCK_ID_ERROR;
    p->lock_ref = 0;
    p->lock_target = CARD_TARGET_NONE;
    OS_InitThreadQueue(&p->lock_queue);
}
#pragma pop
