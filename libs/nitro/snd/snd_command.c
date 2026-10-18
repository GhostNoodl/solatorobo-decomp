#include "nitro/snd.h"
#include "nitro/os.h"
#include "nitro/pxi.h"

#define SND_CMD_COUNT 256
#define SND_CMD_WAIT_QUEUE_COUNT 8

// sCommandArray and sSharedWork are static in the SDK, but the code reaches sCommandArray through
// interior labels the delinker only knows by address, so both stay in the gap's .bss for now.
extern SNDCommand sCommandArray[SND_CMD_COUNT] __attribute__((aligned(32)));
extern SNDSharedWork sSharedWork __attribute__((aligned(32)));
static SNDCommand *sWaitingCommandListQueue[SND_CMD_WAIT_QUEUE_COUNT + 1];

typedef struct SNDCommandWork {
    SNDCommand *freeList;    // 0x00
    u32 finishedTag;         // 0x04
    SNDCommand *reserveList; // 0x08
    SNDCommand *reserveListEnd; // 0x0c
    SNDCommand *freeListEnd; // 0x10
    s32 queueRead;           // 0x14
    s32 queueWrite;          // 0x18
    s32 queueCount;          // 0x1c
    u32 currentTag;          // 0x20
} SNDCommandWork;

static SNDCommandWork sCmdWork;

#define sFreeList sCmdWork.freeList
#define sFinishedTag sCmdWork.finishedTag
#define sReserveList sCmdWork.reserveList
#define sReserveListEnd sCmdWork.reserveListEnd
#define sFreeListEnd sCmdWork.freeListEnd
#define sWaitingCommandListQueueRead sCmdWork.queueRead
#define sWaitingCommandListQueueWrite sCmdWork.queueWrite
#define sWaitingCommandListCount sCmdWork.queueCount
#define sCurrentTag sCmdWork.currentTag

static void InitPXI(void);
static void RequestCommandProc(void);
static SNDCommand *AllocCommand(void);
static BOOL IsCommandAvailable(void);

void SND_CommandInit(void) {
    SNDCommand *cmd;
    int i;

    InitPXI();

    sFreeList = &sCommandArray[0];
    for (i = 0; i < SND_CMD_COUNT - 1; i++) {
        sCommandArray[i].next = &sCommandArray[i + 1];
    }
    sCommandArray[SND_CMD_COUNT - 1].next = NULL;
    sFreeListEnd = &sCommandArray[SND_CMD_COUNT - 1];

    sReserveList = NULL;
    sReserveListEnd = NULL;

    sWaitingCommandListCount = 0;
    sWaitingCommandListQueueRead = 0;
    sWaitingCommandListQueueWrite = 0;

    sCurrentTag = 1;
    sFinishedTag = 0;

    SNDi_SharedWork = &sSharedWork;
    SNDi_InitSharedWork(SNDi_SharedWork);

    cmd = SND_AllocCommand(SND_CMD_FLAG_BLOCK);
    if (cmd == NULL) {
        return;
    }
    cmd->id = SND_CMD_SET_SHARED_WORK;
    cmd->arg[0] = (u32)SNDi_SharedWork;
    SND_PushCommand(cmd);
    (void)SND_FlushCommand(SND_CMD_FLAG_BLOCK);
}

const SNDCommand *SND_RecvCommandReply(u32 flags) {
    OSIntrMode enabled = OS_DisableInterrupts();
    SNDCommand *head;
    SNDCommand *tail;

    if (flags & SND_CMD_FLAG_BLOCK) {
        while (sFinishedTag == SNDi_GetFinishedCommandTag()) {
            (void)OS_RestoreInterrupts(enabled);
            OS_SpinWaitSysCycles(50);
            enabled = OS_DisableInterrupts();
        }
    } else {
        if (sFinishedTag == SNDi_GetFinishedCommandTag()) {
            (void)OS_RestoreInterrupts(enabled);
            return NULL;
        }
    }

    head = sWaitingCommandListQueue[sWaitingCommandListQueueRead];
    if (++sWaitingCommandListQueueRead > SND_CMD_WAIT_QUEUE_COUNT) {
        sWaitingCommandListQueueRead = 0;
    }

    tail = head;
    while (tail->next != NULL) {
        tail = tail->next;
    }

    if (sFreeListEnd != NULL) {
        sFreeListEnd->next = head;
    } else {
        sFreeList = head;
    }
    sFreeListEnd = tail;

    sWaitingCommandListCount--;
    sFinishedTag++;

    (void)OS_RestoreInterrupts(enabled);
    return head;
}

SNDCommand *SND_AllocCommand(u32 flags) {
    SNDCommand *cmd;

    if (!IsCommandAvailable()) {
        return NULL;
    }

    cmd = AllocCommand();
    if (cmd != NULL) {
        return cmd;
    }

    if ((flags & SND_CMD_FLAG_BLOCK) == 0) {
        return NULL;
    }

    if (SND_CountWaitingCommand() > 0) {
        while (SND_RecvCommandReply(SND_CMD_FLAG_NOBLOCK) != NULL) {
        }
        cmd = AllocCommand();
        if (cmd != NULL) {
            return cmd;
        }
    } else {
        (void)SND_FlushCommand(SND_CMD_FLAG_BLOCK);
    }

    RequestCommandProc();

    do {
        (void)SND_RecvCommandReply(SND_CMD_FLAG_BLOCK);
        cmd = AllocCommand();
    } while (cmd == NULL);

    return cmd;
}

void SND_PushCommand(SNDCommand *cmd) {
    OSIntrMode enabled = OS_DisableInterrupts();

    if (sReserveListEnd == NULL) {
        sReserveList = cmd;
        sReserveListEnd = cmd;
    } else {
        sReserveListEnd->next = cmd;
        sReserveListEnd = cmd;
    }
    cmd->next = NULL;

    (void)OS_RestoreInterrupts(enabled);
}

BOOL SND_FlushCommand(u32 flags) {
    OSIntrMode enabled = OS_DisableInterrupts();

    if (sReserveList == NULL) {
        (void)OS_RestoreInterrupts(enabled);
        return TRUE;
    }

    if (sWaitingCommandListCount >= SND_CMD_WAIT_QUEUE_COUNT) {
        if ((flags & SND_CMD_FLAG_BLOCK) == 0) {
            (void)OS_RestoreInterrupts(enabled);
            return FALSE;
        }
        do {
            (void)SND_RecvCommandReply(SND_CMD_FLAG_BLOCK);
        } while (sWaitingCommandListCount >= SND_CMD_WAIT_QUEUE_COUNT);

        if (sReserveList == NULL) {
            (void)OS_RestoreInterrupts(enabled);
            return TRUE;
        }
    }

    DC_FlushRange(sCommandArray, sizeof(sCommandArray));

    if (PXI_SendWordByFifo(PXI_FIFO_TAG_SOUND, (u32)sReserveList, FALSE) < 0) {
        if ((flags & SND_CMD_FLAG_BLOCK) == 0) {
            (void)OS_RestoreInterrupts(enabled);
            return FALSE;
        }
        while (sWaitingCommandListCount >= SND_CMD_WAIT_QUEUE_COUNT ||
               PXI_SendWordByFifo(PXI_FIFO_TAG_SOUND, (u32)sReserveList, FALSE) < 0) {
            (void)OS_RestoreInterrupts(enabled);
            (void)SND_RecvCommandReply(SND_CMD_FLAG_NOBLOCK);
            enabled = OS_DisableInterrupts();
            DC_FlushRange(sCommandArray, sizeof(sCommandArray));
            if (sReserveList == NULL) {
                (void)OS_RestoreInterrupts(enabled);
                return TRUE;
            }
        }
    }

    sWaitingCommandListQueue[sWaitingCommandListQueueWrite] = sReserveList;
    if (++sWaitingCommandListQueueWrite > SND_CMD_WAIT_QUEUE_COUNT) {
        sWaitingCommandListQueueWrite = 0;
    }

    sReserveList = NULL;
    sReserveListEnd = NULL;

    sWaitingCommandListCount++;
    sCurrentTag++;

    (void)OS_RestoreInterrupts(enabled);

    if (flags & SND_CMD_FLAG_IMMEDIATE) {
        RequestCommandProc();
    }
    return TRUE;
}

void SND_WaitForCommandProc(u32 tag) {
    if (SND_IsFinishedCommandTag(tag)) {
        return;
    }
    while (SND_RecvCommandReply(SND_CMD_FLAG_NOBLOCK) != NULL) {
    }
    if (SND_IsFinishedCommandTag(tag)) {
        return;
    }
    RequestCommandProc();
    if (SND_IsFinishedCommandTag(tag)) {
        return;
    }
    do {
        (void)SND_RecvCommandReply(SND_CMD_FLAG_BLOCK);
    } while (!SND_IsFinishedCommandTag(tag));
}

u32 SND_GetCurrentCommandTag(void) {
    OSIntrMode enabled = OS_DisableInterrupts();
    u32 tag;

    if (sReserveList == NULL) {
        tag = sFinishedTag;
    } else {
        tag = sCurrentTag;
    }

    (void)OS_RestoreInterrupts(enabled);
    return tag;
}

BOOL SND_IsFinishedCommandTag(u32 tag) {
    OSIntrMode enabled = OS_DisableInterrupts();
    BOOL result;

    if (tag > sFinishedTag) {
        if (tag - sFinishedTag < 0x80000000) {
            result = FALSE;
        } else {
            result = TRUE;
        }
    } else {
        if (sFinishedTag - tag < 0x80000000) {
            result = TRUE;
        } else {
            result = FALSE;
        }
    }

    (void)OS_RestoreInterrupts(enabled);
    return result;
}

s32 SND_CountFreeCommand(void) {
    OSIntrMode enabled = OS_DisableInterrupts();
    SNDCommand *cmd;
    s32 count = 0;

    for (cmd = sFreeList; cmd != NULL; cmd = cmd->next) {
        count++;
    }

    (void)OS_RestoreInterrupts(enabled);
    return count;
}

s32 SND_CountReservedCommand(void) {
    OSIntrMode enabled = OS_DisableInterrupts();
    SNDCommand *cmd;
    s32 count = 0;

    for (cmd = sReserveList; cmd != NULL; cmd = cmd->next) {
        count++;
    }

    (void)OS_RestoreInterrupts(enabled);
    return count;
}

s32 SND_CountWaitingCommand(void) {
    s32 freeCount = SND_CountFreeCommand();
    s32 reservedCount = SND_CountReservedCommand();
    return SND_CMD_COUNT - freeCount - reservedCount;
}

static void PxiFifoCallback(u32 tag, u32 data, BOOL err) {
    OSIntrMode enabled = OS_DisableInterrupts();
    SNDi_CallAlarmHandler((s32)data);
    (void)OS_RestoreInterrupts(enabled);
}

static void InitPXI(void) {
    PXI_SetFifoRecvCallback(PXI_FIFO_TAG_SOUND, PxiFifoCallback);

    if (!IsCommandAvailable()) {
        return;
    }
    if (PXI_IsCallbackReady(PXI_FIFO_TAG_SOUND, PXI_PROC_ARM7)) {
        return;
    }
    do {
        OS_SpinWaitSysCycles(50);
    } while (!PXI_IsCallbackReady(PXI_FIFO_TAG_SOUND, PXI_PROC_ARM7));
}

static void RequestCommandProc(void) {
    while (PXI_SendWordByFifo(PXI_FIFO_TAG_SOUND, 0, FALSE) < 0) {
    }
}

static SNDCommand *AllocCommand(void) {
    OSIntrMode enabled = OS_DisableInterrupts();
    SNDCommand *cmd;

    if (sFreeList == NULL) {
        (void)OS_RestoreInterrupts(enabled);
        return NULL;
    }

    cmd = sFreeList;
    sFreeList = sFreeList->next;
    if (sFreeList == NULL) {
        sFreeListEnd = NULL;
    }

    (void)OS_RestoreInterrupts(enabled);
    return cmd;
}

static BOOL IsCommandAvailable(void) {
    OSIntrMode enabled;
    u32 result;

    if (!OS_IsRunOnEmulator()) {
        return TRUE;
    }

    enabled = OS_DisableInterrupts();
    *(vu32 *)0x04fff200 = 0x10;
    result = *(vu32 *)0x04fff200;
    (void)OS_RestoreInterrupts(enabled);

    return result != 0 ? TRUE : FALSE;
}
