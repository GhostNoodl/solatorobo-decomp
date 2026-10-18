#ifndef NNSYS_SND_CAPTURE_H
#define NNSYS_SND_CAPTURE_H

#include "types.h"

#ifdef __cplusplus
extern "C" {
#endif

void NNSi_SndCaptureInit(void);
void NNSi_SndCaptureMain(void);
void NNSi_SndCaptureStop(void);
void NNSi_SndCaptureBeginSleep(void);
void NNSi_SndCaptureEndSleep(void);

#ifdef __cplusplus
}
#endif

#endif
