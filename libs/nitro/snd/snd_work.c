#include "nitro/snd.h"
#include "nitro/os.h"

SNDSharedWork *SNDi_SharedWork;

u32 SND_GetPlayerStatus(void) {
    DC_InvalidateRange(&SNDi_SharedWork->playerStatus, 4);
    return SNDi_SharedWork->playerStatus;
}

u32 SNDi_GetFinishedCommandTag(void) {
    DC_InvalidateRange(&SNDi_SharedWork->finishCommandTag, 4);
    return SNDi_SharedWork->finishCommandTag;
}

void SNDi_InitSharedWork(SNDSharedWork *work) {
    s32 i, j;

    work->playerStatus = 0;
    work->channelStatus = 0;
    work->captureStatus = 0;
    work->finishCommandTag = 0;

    for (i = 0; i < SND_PLAYER_COUNT; i++) {
        work->player[i].tickCounter = 0;
        for (j = 0; j < 16; j++) {
            work->player[i].localVariable[j] = -1;
        }
    }

    for (i = 0; i < 16; i++) {
        work->globalVariable[i] = -1;
    }

    DC_FlushRange(work, sizeof(SNDSharedWork));
}
