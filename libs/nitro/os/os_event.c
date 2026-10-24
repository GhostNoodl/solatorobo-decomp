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

typedef u64 OSTitleId;
typedef struct OSDeliverArgInfo {
    u8 data[0x300];
} OSDeliverArgInfo;

void OS_InitDeliverArgInfo(OSDeliverArgInfo *info, int binSize);
int OS_EncodeDeliverArg(void);
int OS_DecodeDeliverArg(void);
void OS_SetDeliverArgStateInvalid(void);
OSTitleId OS_GetTitleIdLastBootedApp(void);

extern OSTitleId data_022919dc;  /* TWL-only .bss */
OSTitleId func_0228f624(OSTitleId id, OSTitleId mask);  /* TWL only */

void func_0201af94(void)
{
    OSDeliverArgInfo argInfo;
    s8 c;

    OS_InitDeliverArgInfo(&argInfo, 0);
    if (OS_DecodeDeliverArg() == 0) {
        data_022919dc = OS_GetTitleIdLastBootedApp();
    }
    if (data_022919dc != 0 && func_0228f624(data_022919dc, (OSTitleId)-1) == 0) {
        goto clear;
    }
    c = (s8)(data_022919dc >> 24);
    if (c == '0' || c == '1' || c == '2' || c == '3' || c == '4') {
clear:
        data_022919dc = 0;
        OS_InitDeliverArgInfo(&argInfo, 0);
        (void)OS_EncodeDeliverArg();
    } else {
        OS_SetDeliverArgStateInvalid();
    }
}
