#include "nitro/os.h"

static inline u32 OSi_GetMutexType(OSMutex *mutex) {
    return mutex->attr & OSi_MUTEX_TYPE_MASK;
}

static inline void OSi_SetMutexType(OSMutex *mutex, u32 type) {
    mutex->attr = (mutex->attr & OSi_MUTEX_COUNT_MASK) | type;
}

static inline u32 OSi_GetMutexCount(OSMutex *mutex) {
    return mutex->attr & OSi_MUTEX_COUNT_MASK;
}

static inline void OSi_SetMutexCount(OSMutex *mutex, u32 count) {
    mutex->attr = (mutex->attr & OSi_MUTEX_TYPE_MASK) | (count & OSi_MUTEX_COUNT_MASK);
}

static inline void OSi_IncreaseMutexCount(OSMutex *mutex) {
    mutex->attr = (mutex->attr & OSi_MUTEX_TYPE_MASK) | ((mutex->attr + 1) & OSi_MUTEX_COUNT_MASK);
}

static inline void OSi_DecreaseMutexCount(OSMutex *mutex) {
    mutex->attr = (mutex->attr & OSi_MUTEX_TYPE_MASK) | ((mutex->attr - 1) & OSi_MUTEX_COUNT_MASK);
}

void OS_InitMutex(OSMutex *mutex) {
    OS_InitThreadQueue(&mutex->queue);
    mutex->thread = NULL;
    OSi_SetMutexCount(mutex, 0);
    OSi_SetMutexType(mutex, OS_MUTEX_TYPE_NONE);
}

void OS_LockMutex(OSMutex *mutex) {
    OSIntrMode enabled = OS_DisableInterrupts();
    OSThread *current = OS_GetCurrentThread();

    while (TRUE) {
        if (OS_TryLockMutex(mutex)) {
            break;
        }
        current->mutex = mutex;
        OS_SleepThread(&mutex->queue);
        current->mutex = NULL;
    }

    (void)OS_RestoreInterrupts(enabled);
}

void OS_UnlockMutex(OSMutex *mutex) {
    OSi_UnlockMutexCore(mutex, OS_MUTEX_TYPE_STD);
}

void OSi_UnlockAllMutex(OSThread *thread) {
    OSMutex *mutex;

    while (thread->mutexQueue.head != NULL) {
        mutex = OSi_RemoveMutexLinkFromQueue(&thread->mutexQueue);
        OSi_SetMutexCount(mutex, 0);
        mutex->thread = NULL;
        OSi_SetMutexType(mutex, OS_MUTEX_TYPE_NONE);
        OS_WakeupThread(&mutex->queue);
    }
}

BOOL OS_TryLockMutex(OSMutex *mutex) {
    OSIntrMode enabled = OS_DisableInterrupts();
    OSThread *current = OS_GetCurrentThread();
    BOOL locked;

    if (mutex->thread == NULL) {
        mutex->thread = current;
        OSi_SetMutexType(mutex, OS_MUTEX_TYPE_STD);
        OSi_IncreaseMutexCount(mutex);
        OSi_EnqueueTail(current, mutex);
        locked = TRUE;
    } else if (mutex->thread == current) {
        OSi_IncreaseMutexCount(mutex);
        locked = TRUE;
    } else {
        locked = FALSE;
    }

    (void)OS_RestoreInterrupts(enabled);
    return locked;
}
