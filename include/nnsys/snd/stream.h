#ifndef NNSYS_SND_STREAM_H
#define NNSYS_SND_STREAM_H

#include "types.h"
#include "nitro/pm.h"
#include "nnsys/fnd/list.h"

#ifdef __cplusplus
extern "C" {
#endif

// NitroSystem low-level stream (NNS_SndStrm*): plays looping PCM channel buffers refilled from an alarm callback.

#define NNS_SND_STRM_CHANNEL_MAX 16

#define NNS_SND_STRM_FORMAT_PCM8  0
#define NNS_SND_STRM_FORMAT_PCM16 1

#define NNS_SND_STRM_CALLBACK_SETUP    0
#define NNS_SND_STRM_CALLBACK_INTERVAL 1

typedef void (*NNSSndStrmCallback)(int status, int numChannels, void *buffer[], u32 len, int format, void *arg);

typedef struct NNSSndStrm {
    /* 0x00 */ NNSFndLink link;
    /* 0x08 */ PMSleepCallbackInfo preSleepInfo;
    /* 0x18 */ PMSleepCallbackInfo postSleepInfo;
    /* 0x28 */ int format;
    /* 0x2c */ BOOL activeFlag : 1;
    /* 0x2c */ BOOL startFlag : 1;
    /* 0x30 */ u32 chBufLen;
    /* 0x34 */ int interval;
    /* 0x38 */ NNSSndStrmCallback callback;
    /* 0x3c */ void *callbackArg;
    /* 0x40 */ int curBuffer;
    /* 0x44 */ int volume;
    /* 0x48 */ int alarmNo;
    /* 0x4c */ u32 chBitMask;
    /* 0x50 */ int numChannels;
    /* 0x54 */ u8 channelNo[NNS_SND_STRM_CHANNEL_MAX];
} NNSSndStrm; // size 0x64

void NNS_SndStrmInit(NNSSndStrm *stream);
BOOL NNS_SndStrmAllocChannel(NNSSndStrm *stream, int numChannels, const u8 chNoList[]);
void NNS_SndStrmFreeChannel(NNSSndStrm *stream);
BOOL NNS_SndStrmSetup(NNSSndStrm *stream, int format, void *buffer, u32 bufSize, int timer, int interval,
                      NNSSndStrmCallback callback, void *arg);
void NNS_SndStrmStart(NNSSndStrm *stream);
void NNS_SndStrmStop(NNSSndStrm *stream);
void NNS_SndStrmSetVolume(NNSSndStrm *stream, int volume);
void NNS_SndStrmSetChannelPan(NNSSndStrm *stream, int chNo, int pan);

#ifdef __cplusplus
}
#endif

#endif
