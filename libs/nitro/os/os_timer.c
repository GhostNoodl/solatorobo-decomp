#include "nitro/os_timer.h"
#include "nitro/os_interrupt.h"

static u16 OSi_TimerReserved = 0;

void OSi_SetTimerReserved(int timerNum);
void OSi_UnsetTimerReserved(int timerNum);

void OSi_SetTimerReserved (int timerNum)
{
    OSi_TimerReserved |= (1 << timerNum);
}

#pragma force_active on
void OSi_UnsetTimerReserved (int timerNum)
{
    OSi_TimerReserved &= ~(1 << timerNum);
}
#pragma force_active reset

