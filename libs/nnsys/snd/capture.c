#include "nitro/mi.h"
#include "nitro/os.h"
#include "nitro/snd.h"
#include "nnsys/snd/capture.h"
#include "nnsys/snd/resource_mgr.h"
#include "nnsys/snd/sndarc.h"

#define NNS_SND_CAPTURE_TYPE_REVERB 0
#define NNS_SND_CAPTURE_TYPE_EFFECT 1

typedef struct CaptureParam {
    /* 0x00 */ BOOL activeFlag;
    /* 0x04 */ int type;
    /* 0x08 */ int format;
    /* 0x0c */ void *bufferL;
    /* 0x10 */ void *bufferR;
    /* 0x14 */ u32 bufLen;
    /* 0x18 */ u32 blockSize;
    /* 0x1c */ int curBuffer;
    /* 0x20 */ u32 chBitMask;
    /* 0x24 */ u32 playChBitMask;
    /* 0x28 */ u32 capBitMask;
    /* 0x2c */ int alarmNo;
    /* 0x30 */ int interval;
    /* 0x34 */ void *callback;
    /* 0x38 */ void *callbackArg;
    /* 0x3c */ SndFader fader;
    /* 0x4c */ BOOL fadeOutFlag;
    /* 0x50 */ int volume;
} CaptureParam; // size 0x54

extern volatile BOOL data_02096150;  // sIsThreadCreated
extern OSMessageQueue data_02096158; // sMesgQ
extern CaptureParam data_02096198;   // sCapParam

void NNSi_SndCaptureInit(void) {
    data_02096150 = FALSE;
    data_02096198.activeFlag = FALSE;
}

void NNSi_SndCaptureMain(void) {
    CaptureParam *cap;
    SndFader *fader;
    int volume;

    cap = &data_02096198;

    if (cap->activeFlag && cap->type == NNS_SND_CAPTURE_TYPE_REVERB) {
        fader = &cap->fader;

        NNSi_SndFaderUpdate(fader);

        if (cap->fadeOutFlag) {
            if (NNSi_SndFaderIsFinished(fader)) {
                NNSi_SndCaptureStop();
                return;
            }
        }

        volume = (NNSi_SndFaderGet(fader) >> 8);

        if (volume != cap->volume) {
            SND_SetChannelVolume(cap->playChBitMask, volume, 0);

            cap->volume = volume;
        }
    }
}

void NNSi_SndCaptureStop(void) {
    CaptureParam *cap = &data_02096198;
    u32 commandTag;
    BOOL useAlarm;

    if (!cap->activeFlag) {
        return;
    }

    useAlarm = cap->alarmNo >= 0 ? TRUE : FALSE;

    SND_StopTimer(cap->playChBitMask, cap->capBitMask, useAlarm ? (u32)(1 << cap->alarmNo) : 0, 0);

    if (useAlarm) {
        commandTag = SND_GetCurrentCommandTag();
        SND_FlushCommand(SND_CMD_FLAG_BLOCK);
        SND_WaitForCommandProc(commandTag);

        while (OS_ReceiveMessage(&data_02096158, NULL, 0)) {
        }
    }

    if (cap->capBitMask) {
        NNS_SndUnlockCapture(cap->capBitMask);
    }
    if (cap->chBitMask) {
        NNS_SndUnlockChannel(cap->chBitMask);
    }
    if (useAlarm) {
        NNS_SndFreeAlarm(cap->alarmNo);
    }

    if (cap->type == NNS_SND_CAPTURE_TYPE_EFFECT) {
        SND_SetOutputSelector(0, 0, 0, 0);
    }

    cap->activeFlag = FALSE;
}

void NNSi_SndCaptureBeginSleep(void) {
    CaptureParam *cap;
    u32 commandTag;

    cap = &data_02096198;

    if (!cap->activeFlag) {
        return;
    }

    SND_StopTimer(cap->playChBitMask, cap->capBitMask, cap->alarmNo >= 0 ? (u32)(1 << cap->alarmNo) : 0, 0);

    commandTag = SND_GetCurrentCommandTag();
    SND_FlushCommand(SND_CMD_FLAG_BLOCK);
    SND_WaitForCommandProc(commandTag);
}

void NNSi_SndCaptureEndSleep(void) {
    CaptureParam *cap;

    cap = &data_02096198;

    if (!cap->activeFlag) {
        return;
    }

    cap->curBuffer = 0;

    MI_CpuClear32(cap->bufferL, cap->bufLen);
    MI_CpuClear32(cap->bufferR, cap->bufLen);
    DC_FlushRange(cap->bufferL, cap->bufLen);
    DC_FlushRange(cap->bufferR, cap->bufLen);

    SND_StartTimer(cap->playChBitMask, cap->capBitMask, cap->alarmNo >= 0 ? (u32)(1 << cap->alarmNo) : 0, 0);
}
