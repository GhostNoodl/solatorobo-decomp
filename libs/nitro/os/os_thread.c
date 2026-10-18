#include "nitro/os.h"
#include "nitro/os_alarm.h"

#pragma force_active on

#define OSi_STACK_CHECKNUM_BOTTOM 0xfddb597dUL
#define OSi_STACK_CHECKNUM_TOP    0x7bf9dd5bUL
#define OSi_STACK_CHECKNUM_WARN   0x597dfbd9UL

typedef void (*OSSwitchThreadCallback)(OSThread *from, OSThread *to);

// File-local statics of os_thread.c; the compiler addresses them from one base.
typedef struct OSiThreadStatics {
    OSSwitchThreadCallback systemCallbackInSwitchThread; // 0x00
    u32 rescheduleCount;                                 // 0x04
    OSThread **currentThreadPtr;                         // 0x08
    BOOL isThreadInitialized;                            // 0x0c
    u32 unk_10;                                          // 0x10
    void *stackForDestructor;                            // 0x14
    u32 threadIdCount;                                   // 0x18
    OSThreadInfo info;                                   // 0x1c (OSi_ThreadInfo)
} OSiThreadStatics;

extern OSiThreadStatics data_0208ec24;
#define OSi_Thread data_0208ec24

extern OSThread data_0208ec50; // OSi_IdleThread
extern OSThread data_0208ed10; // OSi_LauncherThread

u32 OS_GetProcMode(void);
void OS_Halt(void);
void OS_InitContext(OSContext *context, u32 newpc, u32 stack);
BOOL OS_SaveContext(OSContext *context);
void OS_LoadContext(OSContext *context);
void MIi_CpuClear32(u32 data, void *dest, u32 size);

void OS_ExitThread(void);
void OSi_ExitThread_ArgSpecified(OSThread *thread, void *arg);
void OSi_ExitThread(void *arg);
void OSi_ExitThread_Destroy(void);
void OSi_RescheduleThread(void);
void OS_RescheduleThread(void);
OSThread *OS_SelectThread(void);
void OSi_CancelThreadAlarmForSleep(OSThread *thread);
void OS_SetThreadDestructor(OSThread *thread, OSThreadDestructor destructor);
BOOL OS_SetThreadPriority(OSThread *thread, u32 prio);
u32 OS_GetThreadPriority(const OSThread *thread);
void OS_WakeupThreadDirect(OSThread *thread);
void *OS_SetSwitchThreadCallback(OSSwitchThreadCallback callback);
u32 OS_DisableScheduler(void);
u32 OS_EnableScheduler(void);

u32 OSi_GetUnusedThreadId(void) {
    return ++OSi_Thread.threadIdCount;
}

void OSi_InsertLinkToQueue(OSThreadQueue *queue, OSThread *thread) {
    OSThread *next = queue->head;

    while (next && next->priority <= thread->priority) {
        if (next == thread) {
            return;
        }
        next = next->link.next;
    }

    if (!next) {
        OSThread *prev = queue->tail;

        if (!prev) {
            queue->head = thread;
        } else {
            prev->link.next = thread;
        }

        thread->link.prev = prev;
        thread->link.next = NULL;
        queue->tail = thread;
    } else {
        OSThread *prev = next->link.prev;

        if (!prev) {
            queue->head = thread;
        } else {
            prev->link.next = thread;
        }

        thread->link.prev = prev;
        thread->link.next = next;
        next->link.prev = thread;
    }
}

OSThread *OSi_RemoveLinkFromQueue(OSThreadQueue *queue) {
    OSThread *t = queue->head;

    if (t) {
        OSThread *next = t->link.next;

        queue->head = next;

        if (next) {
            next->link.prev = NULL;
        } else {
            queue->tail = NULL;
            t->queue = NULL;
        }
    }

    return t;
}

OSThread *OSi_RemoveSpecifiedLinkFromQueue(OSThreadQueue *queue, OSThread *thread) {
    OSThread *t = queue->head;
    OSThread *next;
    OSThread *prev;

    while (t) {
        next = t->link.next;

        if (t == thread) {
            prev = t->link.prev;

            if (queue->head == t) {
                queue->head = next;
            } else {
                prev->link.next = next;
            }

            if (queue->tail == t) {
                queue->tail = prev;
            } else {
                next->link.prev = prev;
            }

            break;
        }

        t = next;
    }

    return t;
}

OSMutex *OSi_RemoveMutexLinkFromQueue(OSMutexQueue *queue) {
    OSMutex *t = queue->head;

    if (t) {
        OSMutex *next = t->link.next;

        queue->head = next;

        if (next) {
            next->link.prev = NULL;
        } else {
            queue->tail = NULL;
        }
    }

    return t;
}

void OSi_InsertThreadToList(OSThread *thread) {
    OSThread *t = OSi_Thread.info.list;
    OSThread *pre = NULL;

    while (t && t->priority < thread->priority) {
        pre = t;
        t = t->next;
    }

    if (!pre) {
        thread->next = OSi_Thread.info.list;
        OSi_Thread.info.list = thread;
    } else {
        thread->next = pre->next;
        pre->next = thread;
    }
}

void OSi_RemoveThreadFromList(OSThread *thread) {
    OSThread *t = OSi_Thread.info.list;
    OSThread *pre = NULL;

    while (t && t != thread) {
        pre = t;
        t = t->next;
    }

    if (!pre) {
        OSi_Thread.info.list = thread->next;
    } else {
        pre->next = thread->next;
    }
}

void OSi_RescheduleThread(void) {
    if (OSi_Thread.rescheduleCount == 0) {
        OSThreadInfo *info = &OSi_ThreadInfo;

        if (OSi_Thread.info.irqDepth > 0 || OS_GetProcMode() == 0x12) {
            info->isNeedRescheduling = TRUE;
        } else {
            OSThread *currentThread = *OSi_Thread.currentThreadPtr;
            OSThread *nextThread = OS_SelectThread();

            if (currentThread == nextThread || !nextThread) {
                return;
            }

            if (currentThread->state != OS_THREAD_STATE_TERMINATED && OS_SaveContext(&currentThread->context)) {
                return;
            }

            if (OSi_Thread.systemCallbackInSwitchThread) {
                OSi_Thread.systemCallbackInSwitchThread(currentThread, nextThread);
            }

            if (info->switchCallback) {
                ((OSSwitchThreadCallback)info->switchCallback)(currentThread, nextThread);
            }

            OSi_Thread.info.current = nextThread;
            OS_LoadContext(&nextThread->context);
        }
    }
}

void OSi_IdleThreadProc(void *arg);
void OS_CreateThread(OSThread *thread, void (*func)(void *), void *arg, void *stack, u32 stackSize, u32 prio);
extern u32 data_0208ec44;
extern u32 data_0208ee98;

asm void OS_InitThread(void) {
    stmfd sp!, {r3, r4, r5, lr}
    sub sp, sp, #8
    ldr r0, =data_0208ec24
    ldr r1, [r0, #0xc]
    cmp r1, #0
    addne sp, sp, #8
    ldmnefd sp!, {r3, r4, r5, pc}
    mov r3, #1
    ldr r2, =data_0208ec44
    str r3, [r0, #0xc]
    str r2, [r0, #8]
    ldr r1, =data_0208ed10
    mov r2, #0x10
    str r2, [r1, #0x70]
    mov r2, #0
    str r2, [r1, #0x6c]
    str r3, [r1, #0x64]
    str r2, [r1, #0x68]
    str r2, [r1, #0x74]
    ldr r2, =0x1000
    str r1, [r0, #0x24]
    str r1, [r0, #0x20]
    cmp r2, #0
    ldrle r0, =0x2fe15c0
    ldrgt r1, =data_02fe0000
    ldrgt r0, =0x800
    addgt r1, r1, #0x3f80
    subgt r0, r1, r0
    sub r3, r0, r2
    ldr r1, =data_02fe0000
    ldr r0, =0x800
    add r2, r1, #0x3f80
    sub r2, r2, r0
    ldr r1, =data_0208ed10
    mov r4, #0
    str r2, [r1, #0x94]
    str r3, [r1, #0x90]
    ldr r0, =0xfddb597d
    str r4, [r1, #0x98]
    str r0, [r2, #-8]
    ldr r2, [r1, #0x90]
    ldr r3, =0x7bf9dd5b
    ldr r0, =data_0208ec24
    str r3, [r2, #0]
    str r4, [r1, #0xa0]
    str r4, [r1, #0x9c]
    strh r4, [r0, #0x1c]
    strh r4, [r0, #0x1e]
    ldr r2, =OSi_ThreadInfo
    ldr r1, =0x2ffffa0
    mov r0, r4
    str r2, [r1, #0]
    bl OS_SetSwitchThreadCallback
    ldr r5, =data_0208ec50
    mov r12, #0xc8
    mov r2, r4
    ldr r1, =OSi_IdleThreadProc
    ldr r3, =data_0208ee98
    mov r0, r5
    str r12, [sp, #0]
    mov r4, #0x1f
    str r4, [sp, #4]
    bl OS_CreateThread
    mov r0, #0x20
    str r0, [r5, #0x70]
    mov r0, #1
    str r0, [r5, #0x64]
    add sp, sp, #8
    ldmfd sp!, {r3, r4, r5, pc}
}

void OS_CreateThread(OSThread *thread, void (*func)(void *), void *arg, void *stack, u32 stackSize, u32 prio) {
    OSIntrMode enable = OS_DisableInterrupts();

    thread->id = OSi_GetUnusedThreadId();
    thread->priority = prio;
    thread->state = OS_THREAD_STATE_WAITING;
    thread->profiler = NULL;

    OSi_InsertThreadToList(thread);

    thread->stackBottom = (u32)stack;
    thread->stackWarningOffset = 0;
    thread->stackTop = (u32)stack - stackSize;

    *(u32 *)(thread->stackBottom - sizeof(u32) * 2) = OSi_STACK_CHECKNUM_BOTTOM;
    *(u32 *)thread->stackTop = OSi_STACK_CHECKNUM_TOP;

    OS_InitThreadQueue(&thread->joinQueue);

    OS_InitContext(&thread->context, (u32)func, (u32)stack - sizeof(u32) * 2);
    thread->context.r[0] = (u32)arg;
    thread->context.lr = (u32)OS_ExitThread;

    MIi_CpuClear32(0, (void *)((u32)stack - stackSize + sizeof(u32)), stackSize - sizeof(u32) * 2 - sizeof(u32));

    thread->mutex = NULL;
    thread->mutexQueue.head = NULL;
    thread->mutexQueue.tail = NULL;

    OS_SetThreadDestructor(thread, NULL);

    thread->queue = NULL;
    thread->link.prev = thread->link.next = NULL;

    MIi_CpuClear32(0, &thread->specific[0], sizeof(void *) * 3);

    thread->alarmForSleep = NULL;

    (void)OS_RestoreInterrupts(enable);
}

void OS_ExitThread(void) {
    (void)OS_DisableInterrupts();
    OSi_ExitThread_ArgSpecified(OSi_Thread.info.current, NULL);
}

void OSi_ExitThread_ArgSpecified(OSThread *thread, void *arg) {
    if (OSi_Thread.stackForDestructor) {
        OS_InitContext(&thread->context, (u32)OSi_ExitThread, (u32)OSi_Thread.stackForDestructor);
        thread->context.r[0] = (u32)arg;
        thread->context.cpsr |= 0x80;
        thread->state = OS_THREAD_STATE_READY;
        OS_LoadContext(&thread->context);
    } else {
        OSi_ExitThread(arg);
    }
}

void OSi_ExitThread(void *arg) {
    OSThread *currentThread = *OSi_Thread.currentThreadPtr;
    OSThreadDestructor destructor = currentThread->destructor;

    if (destructor) {
        currentThread->destructor = NULL;
        destructor(arg);
        (void)OS_DisableInterrupts();
    }

    OSi_ExitThread_Destroy();
}

void OSi_ExitThread_Destroy(void) {
    OSThread *currentThread = *OSi_Thread.currentThreadPtr;

    (void)OS_DisableScheduler();

    OSi_UnlockAllMutex(currentThread);

    if (currentThread->queue) {
        (void)OSi_RemoveSpecifiedLinkFromQueue(currentThread->queue, currentThread);
    }

    OSi_RemoveThreadFromList(currentThread);

    currentThread->state = OS_THREAD_STATE_TERMINATED;

    OS_WakeupThread(&currentThread->joinQueue);

    (void)OS_EnableScheduler();
    OS_RescheduleThread();

    OS_Terminate();
}

void OS_DestroyThread(OSThread *thread) {
    OSIntrMode enable = OS_DisableInterrupts();

    if (OSi_Thread.info.current == thread) {
        OSi_ExitThread_Destroy();
    }

    (void)OS_DisableScheduler();

    OSi_UnlockAllMutex(thread);
    OSi_CancelThreadAlarmForSleep(thread);

    if (thread->queue) {
        (void)OSi_RemoveSpecifiedLinkFromQueue(thread->queue, thread);
    }

    OSi_RemoveThreadFromList(thread);

    thread->state = OS_THREAD_STATE_TERMINATED;

    OS_WakeupThread(&thread->joinQueue);

    (void)OS_EnableScheduler();
    (void)OS_RestoreInterrupts(enable);

    OS_RescheduleThread();
}

void OS_KillThreadWithPriority(OSThread *thread, void *arg, u32 prio);

void OS_KillThread(OSThread *thread, void *arg) {
    OS_KillThreadWithPriority(thread, arg, OS_GetThreadPriority(thread));
}

void OS_KillThreadWithPriority(OSThread *thread, void *arg, u32 prio) {
    OSIntrMode enable = OS_DisableInterrupts();

    if (thread == OSi_Thread.info.current) {
        OSi_ExitThread_ArgSpecified(thread, arg);
    }

    OSi_CancelThreadAlarmForSleep(thread);

    {
        u32 stack = OSi_Thread.stackForDestructor ? (u32)OSi_Thread.stackForDestructor : thread->stackBottom - sizeof(u32) * 2;
        OS_InitContext(&thread->context, (u32)OSi_ExitThread, stack);
    }

    thread->context.r[0] = (u32)arg;
    thread->context.cpsr |= 0x80;
    thread->state = OS_THREAD_STATE_READY;

    (void)OS_DisableScheduler();
    (void)OS_SetThreadPriority(thread, prio);
    (void)OS_EnableScheduler();

    OSi_RescheduleThread();

    (void)OS_RestoreInterrupts(enable);
}

void OSi_CancelThreadAlarmForSleep(OSThread *thread) {
    OSAlarm *alarm = thread->alarmForSleep;

    if (alarm) {
        OS_CancelAlarm(alarm);
    }
}

BOOL OS_IsThreadTerminated(const OSThread *thread) {
    return (thread->state == OS_THREAD_STATE_TERMINATED) ? TRUE : FALSE;
}

void OS_SleepThreadDirect(OSThread *thread, OSThreadQueue *queue) {
    OSIntrMode enable = OS_DisableInterrupts();

    if (thread->state == OS_THREAD_STATE_READY) {
        if (queue) {
            thread->queue = queue;
            OSi_InsertLinkToQueue(queue, thread);
        }

        thread->state = OS_THREAD_STATE_WAITING;
        OSi_RescheduleThread();
    }

    (void)OS_RestoreInterrupts(enable);
}

void OS_SleepThread(OSThreadQueue *queue) {
    OSIntrMode enable = OS_DisableInterrupts();
    OSThread *currentThread = *OSi_Thread.currentThreadPtr;

    if (queue) {
        currentThread->queue = queue;
        OSi_InsertLinkToQueue(queue, currentThread);
    }

    currentThread->state = OS_THREAD_STATE_WAITING;
    OSi_RescheduleThread();

    (void)OS_RestoreInterrupts(enable);
}

void OS_WakeupThread(OSThreadQueue *queue) {
    OSIntrMode enable = OS_DisableInterrupts();

    if (queue->head) {
        while (queue->head) {
            OSThread *thread = OSi_RemoveLinkFromQueue(queue);

            thread->state = OS_THREAD_STATE_READY;
            thread->queue = NULL;
            thread->link.prev = thread->link.next = NULL;
        }

        OS_InitThreadQueue(queue);
        OSi_RescheduleThread();
    }

    (void)OS_RestoreInterrupts(enable);
}

void OS_WakeupThreadDirect(OSThread *thread) {
    OSIntrMode enable = OS_DisableInterrupts();

    thread->state = OS_THREAD_STATE_READY;
    OSi_RescheduleThread();

    (void)OS_RestoreInterrupts(enable);
}

OSThread *OS_SelectThread(void) {
    OSThread *t = OSi_Thread.info.list;

    while (t && t->state != OS_THREAD_STATE_READY) {
        t = t->next;
    }

    return t;
}

void OS_RescheduleThread(void) {
    OSIntrMode enable = OS_DisableInterrupts();
    OSi_RescheduleThread();
    (void)OS_RestoreInterrupts(enable);
}

void OS_SetThreadStackWarningOffset(OSThread *thread, u32 offset) {
    thread->stackWarningOffset = offset;

    if (offset != 0) {
        *(u32 *)(thread->stackTop + offset) = OSi_STACK_CHECKNUM_WARN;
    }
}

BOOL OS_SetThreadPriority(OSThread *thread, u32 prio) {
    OSThread *t = OSi_Thread.info.list;
    OSThread *pre = NULL;
    OSIntrMode enable = OS_DisableInterrupts();

    while (t && t != thread) {
        pre = t;
        t = t->next;
    }

    if (!t || t == &data_0208ec50) {
        (void)OS_RestoreInterrupts(enable);
        return FALSE;
    }

    if (t->priority != prio) {
        if (!pre) {
            OSi_Thread.info.list = thread->next;
        } else {
            pre->next = thread->next;
        }

        thread->priority = prio;
        OSi_InsertThreadToList(thread);

        OSi_RescheduleThread();
    }

    (void)OS_RestoreInterrupts(enable);
    return TRUE;
}

u32 OS_GetThreadPriority(const OSThread *thread) {
    return thread->priority;
}

static void OSi_SleepAlarmCallback(void *arg);

void OS_Sleep(u32 msec) {
    OSAlarm alarm;

    OS_CreateAlarm(&alarm);

    {
        OSThread *volatile p_thread = *OSi_Thread.currentThreadPtr;
        OSIntrMode enable = OS_DisableInterrupts();

        p_thread->alarmForSleep = &alarm;

        OS_SetAlarm(&alarm, (OSTick)((u64)msec * 33514 / 64), &OSi_SleepAlarmCallback, (void *)&p_thread);

        while (p_thread != NULL) {
            OS_SleepThread(NULL);
        }

        (void)OS_RestoreInterrupts(enable);
    }
}

static void OSi_SleepAlarmCallback(void *arg) {
    OSThread **pp_thread = (OSThread **)arg;
    OSThread *p_thread = *pp_thread;

    *pp_thread = NULL;
    p_thread->alarmForSleep = NULL;

    OS_WakeupThreadDirect(p_thread);
}

void *OS_SetSwitchThreadCallback(OSSwitchThreadCallback callback) {
    OSIntrMode enable = OS_DisableInterrupts();
    void *prev = OSi_Thread.info.switchCallback;

    OSi_Thread.info.switchCallback = (void *)callback;

    (void)OS_RestoreInterrupts(enable);
    return prev;
}

void OSi_IdleThreadProc(void *arg) {
    (void)OS_EnableInterrupts();

    while (1) {
        OS_Halt();
    }
}

u32 OS_DisableScheduler(void) {
    OSIntrMode enable = OS_DisableInterrupts();
    u32 count;

    if (OSi_Thread.rescheduleCount < (u32)(0 - 1)) {
        count = OSi_Thread.rescheduleCount++;
    }

    (void)OS_RestoreInterrupts(enable);
    return count;
}

u32 OS_EnableScheduler(void) {
    OSIntrMode enable = OS_DisableInterrupts();
    u32 count = 0;

    if (OSi_Thread.rescheduleCount > 0) {
        count = OSi_Thread.rescheduleCount--;
    }

    (void)OS_RestoreInterrupts(enable);
    return count;
}

void OS_SetThreadDestructor(OSThread *thread, OSThreadDestructor destructor) {
    thread->destructor = destructor;
}
