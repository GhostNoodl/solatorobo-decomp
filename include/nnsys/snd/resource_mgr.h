#ifndef NNSYS_SND_RESOURCE_MGR_H
#define NNSYS_SND_RESOURCE_MGR_H

#include "types.h"

#ifdef __cplusplus
extern "C" {
#endif

BOOL NNS_SndLockChannel(u32 chBitFlag);
void NNS_SndUnlockChannel(u32 chBitFlag);
void NNS_SndUnlockCapture(u32 capBitFlag);
int NNS_SndAllocAlarm(void);
void NNS_SndFreeAlarm(int alarmNo);
void NNSi_SndInitResourceMgr(void);

#ifdef __cplusplus
}
#endif

#endif
