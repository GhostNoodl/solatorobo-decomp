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
BOOL CARDi_ExecuteOldTypeTask(CARDiTaskFunc task, BOOL async) {
    CARDiCommon *p = &cardi_common;

    if (async) {
        (void)OS_SetThreadPriority(&p->thread, p->priority);
        p->task_func = task;
        p->flag |= CARD_STAT_TASK;
        OS_WakeupThreadDirect(&p->thread);
    } else {
        task(p);
        CARDi_EndTask(p);
    }

    return async ? TRUE : (p->cmd->result == CARD_RESULT_SUCCESS);
}

void CARDi_TaskThread(void *arg) {
    CARDiCommon *const p = &cardi_common;

    for (;;) {
        OSIntrMode bak_psr = OS_DisableInterrupts();

        for (;;) {
            if (p->flag & CARD_STAT_TASK) {
                break;
            }
            OS_SleepThread(NULL);
        }

        (void)OS_RestoreInterrupts(bak_psr);
        (void)CARDi_ExecuteOldTypeTask(p->task_func, FALSE);
    }
}

BOOL CARDi_WaitForTask(CARDiCommon *p, BOOL restart, MIDmaCallback callback, void *callback_arg) {
    OSIntrMode bak_psr = OS_DisableInterrupts();

    while (p->flag & CARD_STAT_BUSY) {
        OS_SleepThread(&p->busy_q);
    }

    if (restart) {
        p->flag |= CARD_STAT_BUSY;
        p->callback = callback;
        p->callback_arg = callback_arg;
    }

    (void)OS_RestoreInterrupts(bak_psr);

    return (p->cmd->result == CARD_RESULT_SUCCESS);
}

void CARDi_EndTask(CARDiCommon *p) {
    const MIDmaCallback func = p->callback;
    void *const arg = p->callback_arg;

    {
        OSIntrMode bak_psr = OS_DisableInterrupts();
        p->flag &= ~(CARD_STAT_BUSY | CARD_STAT_TASK | CARD_STAT_CANCEL);
        OS_WakeupThread(&p->busy_q);
        (void)OS_RestoreInterrupts(bak_psr);
    }

    if (func) {
        (*func)(arg);
    }
}

const void *CARDi_GetRomAccessor(u32 type) {
    const void *accessor = NULL;
    BOOL isTwl = (type & 0x10) != 0;

    type &= ~0x10;

    if (type <= 3) {
        if (!isTwl) {
            accessor = (const void *)0x02070ee4;
        } else if (OS_IsRunOnTwl()) {
            accessor = (const void *)0x0228cce8;
        } else {
            OS_Terminate();
        }
    }

    return accessor;
}

void CARDi_ICInvalidateSmart(void *buffer, u32 length, u32 threshold) {
    if (length >= threshold) {
        IC_InvalidateAll();
    } else {
        IC_InvalidateRange(buffer, length);
    }
}

void CARDi_DCInvalidateSmart(void *buffer, u32 length, u32 threshold) {
    if (length >= threshold) {
        DC_FlushAll();
    } else {
        u32 misalign = (u32)buffer & 31;

        if (misalign) {
            buffer = (u8 *)buffer - misalign;
            DC_StoreRange(buffer, 32);
            DC_StoreRange((u8 *)buffer + length, 32);
            length += 32;
        }

        DC_InvalidateRange(buffer, length);
        DC_WaitWriteBufferEmpty();
    }
}

void CARDi_OnFifoRecv(u32 tag, u32 data, BOOL err) {
    if (tag == PXI_FIFO_TAG_FS && err) {
        CARDiCommon *const p = &cardi_common;
        p->flag &= ~CARD_STAT_REQ;
        OS_WakeupThreadDirect(p->cur_th);
    }
}
