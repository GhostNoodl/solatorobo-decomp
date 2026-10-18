#ifndef NITRO_OS_H
#define NITRO_OS_H

#include "types.h"

#ifdef __cplusplus
extern "C" {
#endif

typedef u32 OSIntrMode;

typedef struct OSThread OSThread;

typedef struct OSThreadQueue {
    OSThread *head;
    OSThread *tail;
} OSThreadQueue;

typedef struct OSMutex OSMutex;

typedef struct OSMutexLink {
    OSMutex *next;
    OSMutex *prev;
} OSMutexLink;

// attr packs the lock count (low 24 bits) and the lock type (high 8 bits).
struct OSMutex {
    OSThreadQueue queue; // 0x00
    OSThread *thread;    // 0x08
    u32 attr;            // 0x0c
    OSMutexLink link;    // 0x10
}; // size 0x18

#define OS_MUTEX_TYPE_NONE 0x00000000
#define OS_MUTEX_TYPE_STD  0x10000000
#define OS_MUTEX_TYPE_R    0x20000000
#define OS_MUTEX_TYPE_W    0x30000000

#define OSi_MUTEX_COUNT_MASK 0x00ffffff
#define OSi_MUTEX_TYPE_MASK  0xff000000

typedef struct OSMutexQueue {
    OSMutex *head;
    OSMutex *tail;
} OSMutexQueue;

struct OSThread {
    u8 unk_00[0x84];
    OSMutex *mutex;          // 0x84
    OSMutexQueue mutexQueue; // 0x88
};

typedef struct OSThreadInfo {
    u16 isNeedRescheduling; // 0x00
    u16 irqDepth;           // 0x02
    OSThread *current;      // 0x04
    OSThread *list;         // 0x08
} OSThreadInfo;

extern OSThreadInfo OSi_ThreadInfo;

static inline OSThread *OS_GetCurrentThread(void) {
    return OSi_ThreadInfo.current;
}

OSMutex *OSi_RemoveMutexLinkFromQueue(OSMutexQueue *queue);
BOOL OS_TryLockMutex(OSMutex *mutex);
void OSi_UnlockMutexCore(OSMutex *mutex, u32 type);
void OSi_UnlockAllMutex(OSThread *thread);
void OSi_EnqueueTail(OSThread *thread, OSMutex *mutex);
void OSi_DequeueItem(OSThread *thread, OSMutex *mutex);

typedef void *OSMessage;

typedef struct OSMessageQueue {
    OSThreadQueue queueSend;    // 0x00
    OSThreadQueue queueReceive; // 0x08
    OSMessage *msgArray;        // 0x10
    s32 msgCount;               // 0x14
    s32 firstIndex;             // 0x18
    s32 usedCount;              // 0x1c
} OSMessageQueue;

#define OS_MESSAGE_NOBLOCK 0
#define OS_MESSAGE_BLOCK   1

static inline void OS_InitThreadQueue(OSThreadQueue *queue) {
    queue->head = queue->tail = NULL;
}

void OS_SleepThread(OSThreadQueue *queue);
void OS_WakeupThread(OSThreadQueue *queue);

void OS_InitMessageQueue(OSMessageQueue *mq, OSMessage *msgArray, s32 msgCount);
BOOL OS_SendMessage(OSMessageQueue *mq, OSMessage msg, s32 flags);
BOOL OS_ReceiveMessage(OSMessageQueue *mq, OSMessage *msg, s32 flags);
BOOL OS_JamMessage(OSMessageQueue *mq, OSMessage msg, s32 flags);

typedef u32 OSIrqMask;

// DTCM base; the interrupt check flags live at its end
extern u8 data_02fe0000[];
#define OS_IRQ_CHECK_BUF (*(volatile OSIrqMask *)((u32)data_02fe0000 + 0x3ff8))

static inline void OS_SetIrqCheckFlag(OSIrqMask intr) {
    OS_IRQ_CHECK_BUF |= intr;
}

typedef struct OSIrqCallbackInfo {
    void (*func)(void *); // 0x0
    u32 enable;           // 0x4
    void *arg;            // 0x8
} OSIrqCallbackInfo;

typedef void (*OSIrqFunction)(void);

// DTCM-resident interrupt tables (named in the DTCM symbol list)
extern OSIrqFunction data_02fe0020[];
extern OSThreadQueue data_02fe01e0;
#define OS_IRQTable data_02fe0020
#define OSi_IrqThreadQueue data_02fe01e0

extern OSIrqCallbackInfo OSi_IrqCallbackInfo[];

void OS_InitIrqTable(void);
void OS_SetIrqFunction(OSIrqMask intrBit, OSIrqFunction function);
OSIrqFunction OS_GetIrqFunction(OSIrqMask intrBit);
void OSi_EnterDmaCallback(u32 dmaNo, void (*callback)(void *), void *arg);
void OSi_EnterTimerCallback(u32 timerNo, void (*callback)(void *), void *arg);
OSIrqMask OS_ResetRequestIrqMask(OSIrqMask mask);
OSIrqMask OS_SetIrqMask(OSIrqMask mask);
OSIrqMask OS_EnableIrqMask(OSIrqMask mask);
OSIrqMask OS_DisableIrqMask(OSIrqMask mask);

typedef struct OSLockWord {
    u32 lockFlag; // 0x0
    u16 ownerID;  // 0x4
    u16 extension; // 0x6
} OSLockWord;

s32 OSi_DoLockByWord(u16 lockID, OSLockWord *lockp, void (*ctrlFuncp)(void), BOOL disableFiq);
s32 OS_LockByWord(u16 lockID, OSLockWord *lockp, void (*ctrlFuncp)(void));
s32 OSi_DoUnlockByWord(u16 lockID, OSLockWord *lockp, void (*ctrlFuncp)(void), BOOL disableFiq);
s32 OS_UnlockByWord(u16 lockID, OSLockWord *lockp, void (*ctrlFuncp)(void));
s32 OSi_DoTryLockByWord(u16 lockID, OSLockWord *lockp, void (*ctrlFuncp)(void), BOOL disableFiq);
s32 OS_TryLockByWord(u16 lockID, OSLockWord *lockp, void (*ctrlFuncp)(void));
s32 OS_UnlockCartridge(u16 lockID);
s32 OS_TryLockCartridge(u16 lockID);
s32 OS_UnlockCard(u16 lockID);
s32 OS_TryLockCard(u16 lockID);
void OSi_AllocateCartridgeBus(void);
void OSi_FreeCartridgeBus(void);
void OSi_AllocateCardBus(void);
void OSi_FreeCardBus(void);
u16 OS_ReadOwnerOfLockWord(OSLockWord *lockp);
void OS_InitLock(void);

OSIntrMode OS_DisableInterrupts_IrqAndFiq(void);
OSIntrMode OS_RestoreInterrupts_IrqAndFiq(OSIntrMode state);

OSIntrMode OS_EnableInterrupts(void);
OSIntrMode OS_DisableInterrupts(void);
OSIntrMode OS_RestoreInterrupts(OSIntrMode state);

void OS_SpinWaitCpuCycles(u32 cycles);
void OS_SpinWaitSysCycles(u32 cycles);

BOOL OS_IsRunOnEmulator(void);

void OS_InitMutex(OSMutex *mutex);
void OS_LockMutex(OSMutex *mutex);
void OS_UnlockMutex(OSMutex *mutex);

void DC_InvalidateRange(void *startAddr, u32 nBytes);
void DC_StoreRange(const void *startAddr, u32 nBytes);
void DC_FlushRange(const void *startAddr, u32 nBytes);

// VRAM exclusive control (os/ARM9/vramExclusive.h)
#define OS_VRAM_BANK_ID_A       0x0001
#define OS_VRAM_BANK_ID_B       0x0002
#define OS_VRAM_BANK_ID_C       0x0004
#define OS_VRAM_BANK_ID_D       0x0008
#define OS_VRAM_BANK_ID_E       0x0010
#define OS_VRAM_BANK_ID_F       0x0020
#define OS_VRAM_BANK_ID_G       0x0040
#define OS_VRAM_BANK_ID_H       0x0080
#define OS_VRAM_BANK_ID_I       0x0100
#define OS_VRAM_BANK_ID_ALL     0x01ff
#define OS_VRAM_BANK_KINDS      9

void OSi_InitVramExclusive(void);
BOOL OSi_TryLockVram(u16 bank, u16 lockId);
void OSi_UnlockVram(u16 bank, u16 lockId);

void OS_Terminate(void);

// OS_Panic is OS_Terminate in final ROMs
#define OS_Panic(...) OS_Terminate()

#ifdef __cplusplus
}
#endif

#endif
