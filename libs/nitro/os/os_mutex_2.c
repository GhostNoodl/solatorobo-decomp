#include "nitro/os.h"

void OSi_EnqueueTail(OSThread *thread, OSMutex *mutex) {
    OSMutex *prev = thread->mutexQueue.tail;

    if (prev == NULL) {
        thread->mutexQueue.head = mutex;
    } else {
        prev->link.next = mutex;
    }

    mutex->link.prev = prev;
    mutex->link.next = NULL;
    thread->mutexQueue.tail = mutex;
}

void OSi_DequeueItem(OSThread *thread, OSMutex *mutex) {
    OSMutex *next = mutex->link.next;
    OSMutex *prev = mutex->link.prev;

    if (next == NULL) {
        thread->mutexQueue.tail = prev;
    } else {
        next->link.prev = prev;
    }

    if (prev == NULL) {
        thread->mutexQueue.head = next;
    } else {
        prev->link.next = next;
    }
}
