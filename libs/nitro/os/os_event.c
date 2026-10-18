#include "nitro/os.h"

typedef enum {
    OS_EVENT_MODE_AND = 0,
    OS_EVENT_MODE_OR = 1
} OSEventMode;

typedef struct OSEvent {
    vu32 flag;
    OSThreadQueue queue;
} OSEvent;

void OS_InitEvent(OSEvent *event);
u32 OSi_WaitEvent(OSEvent *event, u32 pattern, OSEventMode mode, u32 clearBit);
void OS_SignalEvent(OSEvent *event, u32 setPattern);

void OS_InitEvent (OSEvent *event)
{
    OS_InitThreadQueue(&event->queue);
    event->flag = 0;
}

u32 OSi_WaitEvent (OSEvent *event, u32 pattern, OSEventMode mode, u32 clearBit)
{
    u32 retval = 0;
    OSIntrMode enabled = OS_DisableInterrupts();

    switch (mode) {
    case OS_EVENT_MODE_AND:
        while ((event->flag & pattern) != pattern) {
            OS_SleepThread(&event->queue);
        }
        retval = event->flag;
        break;
    case OS_EVENT_MODE_OR:
        while (!(event->flag & pattern)) {
            OS_SleepThread(&event->queue);
        }
        retval = event->flag;
        break;
    }

    if (retval) {
        event->flag &= ~clearBit;
    }

    (void)OS_RestoreInterrupts(enabled);
    return retval;
}

void OS_SignalEvent (OSEvent *event, u32 setPattern)
{
    OSIntrMode enabled = OS_DisableInterrupts();

    if (setPattern) {
        event->flag |= setPattern;
        OS_WakeupThread(&event->queue);
    }

    (void)OS_RestoreInterrupts(enabled);
}
