#pragma ipa file
#include "nitro/snd.h"
#include "nnsys/snd/resource_mgr.h"

static u32 sChannelLock;
static u32 sCaptureLock;
static u32 sAlarmLock;

BOOL NNS_SndLockChannel(u32 chBitFlag) {
    if (chBitFlag == 0) {
        return TRUE;
    }
    if (chBitFlag & sChannelLock) {
        return FALSE;
    }

    SND_LockChannel(chBitFlag, 0);

    sChannelLock |= chBitFlag;

    return TRUE;
}

void NNS_SndUnlockChannel(u32 chBitFlag) {
    if (chBitFlag == 0) {
        return;
    }

    SND_UnlockChannel(chBitFlag, 0);

    sChannelLock &= ~chBitFlag;
}

void NNS_SndUnlockCapture(u32 capBitFlag) {
    sCaptureLock &= ~capBitFlag;
}

int NNS_SndAllocAlarm(void) {
    int alarmNo;
    u32 mask = 1;

    for (alarmNo = 0; alarmNo < SND_ALARM_COUNT; alarmNo++, mask <<= 1) {
        if ((sAlarmLock & mask) == 0) {
            sAlarmLock |= mask;
            return alarmNo;
        }
    }

    return -1;
}

void NNS_SndFreeAlarm(int alarmNo) {
    sAlarmLock &= ~(1 << alarmNo);
}

void NNSi_SndInitResourceMgr(void) {
    sChannelLock = 0;
    sCaptureLock = 0;
    sAlarmLock = 0;
}
