#include "nnsys/snd/sndarc_stream.h"
#include "nitro/snd.h"

// Built at a lower optimization level: both setup loops jump to their test first instead of being rotated.
#pragma optimization_level 2
void NNS_SndArcStrmInit(u32 prio, NNSSndHeap *heap) {
    int i;
    int j;

    if (data_0209622c.initialized) {
        Strm_SetupPlayers(heap);
        return;
    }
    data_0209622c.initialized = TRUE;

    NNS_FndInitList(&data_02096238, 0);
    for (i = 0; i < 8; i++) {
        NNS_FndAppendListObject(&data_02096238, &data_0209625c[i]);
    }
    OS_InitMutex(&data_02096244);
    data_0209622c.unk_8 = data_020963e0;

    for (j = 0; j < 4; j++) {
        StrmPlayer *player = &data_020965e0[j];
        player->active = FALSE;
        FS_InitFile(player->file);
        NNS_SndStrmInit(&player->strm);
        player->playerNo = j;
        player->chNum = 0;
        player->buffer = NULL;
        player->bufSize = 0;
        player->chRefCount = 0;
    }
    Strm_SetupPlayers(heap);
    StrmThread_Init(&data_02096bd0, prio);
}
#pragma optimization_level reset

BOOL Strm_SetupPlayers(NNSSndHeap *heap) {
    int i;
    for (i = 0; i < 4; i++) {
        StrmPlayer *player = &data_020965e0[i];
        NNSSndArcStrmPlayerInfo *info = NNS_SndArcGetStrmPlayerInfo(i);
        int j;
        if (info == NULL) {
            continue;
        }
        player->chNum = info->numChannels;
        for (j = 0; j < info->numChannels; j++) {
            player->chList[j] = info->chNoList[j];
        }
        if (heap != NULL) {
            u32 size = player->chNum << 11;
            void *buf = NNS_SndHeapAlloc(heap, size, (NNSSndHeapDisposeCallback)StrmPlayer_OnHeapDispose, (u32)player, 0);
            if (buf == NULL) {
                return FALSE;
            }
            StrmPlayer_ForceStop(player);
            player->buffer = buf;
            player->bufSize = size;
        }
    }
    return TRUE;
}

BOOL NNS_SndArcStrmPrepare(StrmHandle *handle, int strmNo, u32 offset) {
    NNSSndArcStrmInfo *info = NNS_SndArcGetStrmInfo(strmNo);
    if (info == NULL) {
        return FALSE;
    }
    return Strm_PreparePlayer(handle, info, info->playerNo, info->playerPrio, strmNo, offset, 0, 0, NULL, 0);
}

void NNS_SndArcStrmStartPrepared(StrmHandle *handle) {
    if (handle->player != NULL) {
        handle->player->startReq = TRUE;
    }
}

BOOL NNS_SndArcStrmStart(StrmHandle *handle, int strmNo, u32 offset) {
    if (!NNS_SndArcStrmPrepare(handle, strmNo, offset)) {
        return FALSE;
    }
    NNS_SndArcStrmStartPrepared(handle);
    return TRUE;
}

void NNS_SndArcStrmStop(StrmHandle *handle, int frames) {
    if (handle->player == NULL) {
        return;
    }
    StrmPlayer_Stop(handle->player, frames);
}

void NNS_SndArcStrmSetVolume(StrmHandle *handle, int volume) {
    if (handle->player != NULL) {
        handle->player->userVolume = volume;
    }
}

void NNS_SndArcStrmMoveVolume(StrmHandle *handle, int volume, int frames) {
    StrmPlayer *player;
    if (handle->player == NULL) {
        return;
    }
    player = handle->player;
    if (player->stopReq) {
        return;
    }
    NNSi_SndFaderSet(&player->fader, volume << 8, frames);
}

void NNS_SndArcStrmInitHandle(StrmHandle *handle) {
    handle->player = NULL;
}

void NNS_SndArcStrmReleaseHandle(StrmHandle *handle) {
    StrmPlayer *player = handle->player;
    if (player != NULL) {
        player->handle = NULL;
        handle->player = NULL;
    }
}

void NNSi_SndArcStrmMain(void) {
    StrmPlayer *player;
    int playerNo;

    for (playerNo = 0; playerNo < 4; playerNo++) {
        player = &data_020965e0[playerNo];

        if (!player->active) {
            continue;
        }

        if (player->unk_11c == 0) {
            StrmPlayer_ForceStop(player);
            continue;
        }

        if (player->startReq && player->unk_120 != 0) {
            NNS_SndStrmStart(&player->strm);
            player->playing = TRUE;
            player->startReq = FALSE;
        }

        if (!player->playing) {
            continue;
        }

        NNSi_SndFaderUpdate(&player->fader);

        {
            int volume = SNDi_DecibelTable[player->volume];
            int fader = NNSi_SndFaderGet(&player->fader) >> 8;
            int user = player->userVolume;
            // "- -volume" only swaps the operands of the add to the target's order.
            volume = SNDi_DecibelTable[user] + (SNDi_DecibelTable[fader] - -volume);

            if (volume != player->curVolume) {
                NNS_SndStrmSetVolume(&player->strm, volume);
                player->curVolume = volume;
            }
        }

        if (player->stopReq && NNSi_SndFaderIsFinished(&player->fader)) {
            StrmPlayer_ForceStop(player);
        }
    }
}
