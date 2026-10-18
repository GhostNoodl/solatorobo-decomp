#pragma ipa file

#include "nitro/pm.h"
#include "nitro/snd.h"
#include "nnsys/snd/capture.h"
#include "nnsys/snd/player.h"
#include "nnsys/snd/resource_mgr.h"
#include "nnsys/snd/sndarc_stream.h"

// Only sized here; the driver info functions that use it aren't linked in this game.
typedef struct SNDDriverInfo {
    u8 data[0x24c0 / 2];
} SNDDriverInfo;

void SND_ReadDriverInfo(SNDDriverInfo *info);
void DC_InvalidateRange(void *startAddr, u32 nBytes);

static PMSleepCallbackInfo sPreSleepCallback;
static PMSleepCallbackInfo sPostSleepCallback;

static SNDDriverInfo sDriverInfo[2] __attribute__((aligned(32)));
static u32 sDriverInfoCommandTag;
static s8 sCurDriverInfo;
static BOOL sDriverInfoFirstFlag;

static void BeginSleep(void *arg);
static void EndSleep(void *arg);

void NNS_SndInit(void) {
    {
        static BOOL initialized = FALSE;
        if (initialized) {
            return;
        }
        initialized = TRUE;
    }

    SND_Init();

    PM_SetSleepCallbackInfo(&sPreSleepCallback, BeginSleep, NULL);
    PM_SetSleepCallbackInfo(&sPostSleepCallback, EndSleep, NULL);

    PM_PrependPreSleepCallback(&sPreSleepCallback);
    PM_AppendPostSleepCallback(&sPostSleepCallback);

    NNSi_SndInitResourceMgr();
    NNSi_SndCaptureInit();
    NNSi_SndPlayerInit();

    sCurDriverInfo = -1;
    sDriverInfoFirstFlag = TRUE;
}

void NNS_SndMain(void) {
    while (SND_RecvCommandReply(SND_CMD_FLAG_NOBLOCK) != NULL) {
    }

    NNSi_SndPlayerMain();
    NNSi_SndCaptureMain();
    NNSi_SndArcStrmMain();

    SND_FlushCommand(SND_CMD_FLAG_NOBLOCK);
}

BOOL NNS_SndUpdateDriverInfo(void) {
    if (!sDriverInfoFirstFlag) {
        while (SND_RecvCommandReply(SND_CMD_FLAG_NOBLOCK) != NULL) {
        }

        if (!SND_IsFinishedCommandTag(sDriverInfoCommandTag)) {
            return FALSE;
        }

        if (sCurDriverInfo < 0) {
            sCurDriverInfo = 1;
        }

        SND_ReadDriverInfo(&sDriverInfo[sCurDriverInfo]);
        sDriverInfoCommandTag = SND_GetCurrentCommandTag();

        if (sCurDriverInfo == 0) {
            sCurDriverInfo = 1;
        } else {
            sCurDriverInfo = 0;
        }

        DC_InvalidateRange(&sDriverInfo[sCurDriverInfo], sizeof(SNDDriverInfo));

        SND_FlushCommand(SND_CMD_FLAG_NOBLOCK);

        return TRUE;
    } else {
        SND_ReadDriverInfo(&sDriverInfo[0]);
        sDriverInfoCommandTag = SND_GetCurrentCommandTag();
        sDriverInfoFirstFlag = FALSE;
        return FALSE;
    }
}

static void BeginSleep(void *arg) {
    u32 commandTag;

    NNSi_SndCaptureBeginSleep();

    SND_StopTimer(0, 0, 0, 0);

    commandTag = SND_GetCurrentCommandTag();
    SND_FlushCommand(SND_CMD_FLAG_BLOCK);
    SND_WaitForCommandProc(commandTag);
}

static void EndSleep(void *arg) {
    NNSi_SndCaptureEndSleep();
}
