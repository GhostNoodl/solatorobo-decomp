#include "nnsys/snd/player.h"

#define FADER_SHIFT 8

extern NNSFndList data_020957a8; // sFreeList
extern NNSFndList data_020957b4; // sPrioList
extern NNSSndSeqPlayer data_020957c0[SND_PLAYER_COUNT]; // sSeqPlayer
extern NNSSndPlayer data_02095c00[NNS_SND_PLAYER_NUM]; // sPlayer

static void InitPlayer(NNSSndSeqPlayer *seqPlayer);
static void ShutdownPlayer(NNSSndSeqPlayer *seqPlayer);
static void ForceStopSeq(NNSSndSeqPlayer *seqPlayer);
static NNSSndSeqPlayer *AllocSeqPlayer(int prio);
static void InsertPlayerList(NNSSndPlayer *player, NNSSndSeqPlayer *seqPlayer);
static void InsertPrioList(NNSSndSeqPlayer *seqPlayer);
static void SetPlayerPriority(NNSSndSeqPlayer *seqPlayer, int priority);
static void PlayerHeapDisposeCallback(void *mem, u32 size, u32 data1, u32 data2);

void NNS_SndPlayerSetPlayableSeqCount(int playerNo, int seqCount) {
    data_02095c00[playerNo].playableSeqCount = (u16)seqCount;
}

void NNS_SndPlayerSetAllocatableChannel(int playerNo, u32 chBitFlag) {
    data_02095c00[playerNo].allocChBitFlag = chBitFlag;
}

BOOL NNS_SndPlayerCreateHeap(int playerNo, NNSSndHeap *heap, u32 size) {
    NNSSndHeap *playerHeapHandle;
    NNSSndPlayerHeap *playerHeap;
    void *buffer;

    buffer = NNS_SndHeapAlloc(heap, sizeof(NNSSndPlayerHeap) + size, PlayerHeapDisposeCallback, 0, 0);
    if (buffer == NULL) {
        return FALSE;
    }

    playerHeap = (NNSSndPlayerHeap *)buffer;

    playerHeap->player = NULL;
    playerHeap->playerNo = playerNo;
    playerHeap->handle = NULL;

    playerHeapHandle = NNS_SndHeapCreate((u8 *)buffer + sizeof(NNSSndPlayerHeap), size);
    if (playerHeapHandle == NULL) {
        return FALSE;
    }

    playerHeap->handle = playerHeapHandle;
    NNS_FndAppendListObject(&data_02095c00[playerNo].heapList, playerHeap);

    return TRUE;
}

void NNS_SndPlayerStopSeq(NNSSndHandle *handle, int fadeFrame) {
    NNSi_SndPlayerStopSeq(handle->player, fadeFrame);
}

void NNS_SndPlayerStopSeqBySeqNo(int seqNo, int fadeFrame) {
    NNSSndSeqPlayer *seqPlayer;
    int i;

    for (i = 0; i < SND_PLAYER_COUNT; i++) {
        seqPlayer = &data_020957c0[i];

        if (seqPlayer->status != NNS_SND_SEQ_PLAYER_STATUS_STOP &&
            seqPlayer->seqType == NNS_SND_PLAYER_SEQ_TYPE_SEQ && seqPlayer->seqNo == seqNo) {
            NNSi_SndPlayerStopSeq(seqPlayer, fadeFrame);
        }
    }
}

void NNS_SndPlayerStopSeqBySeqArcIdx(int seqArcNo, int index, int fadeFrame) {
    NNSSndSeqPlayer *seqPlayer;
    int i;

    for (i = 0; i < SND_PLAYER_COUNT; i++) {
        seqPlayer = &data_020957c0[i];

        if (seqPlayer->status != NNS_SND_SEQ_PLAYER_STATUS_STOP &&
            seqPlayer->seqType == NNS_SND_PLAYER_SEQ_TYPE_SEQARC && seqPlayer->seqNo == seqArcNo &&
            seqPlayer->seqArcIndex == index) {
            NNSi_SndPlayerStopSeq(seqPlayer, fadeFrame);
        }
    }
}

void NNS_SndPlayerStopSeqAll(int fadeFrame) {
    NNSSndSeqPlayer *seqPlayer;
    int i;

    for (i = 0; i < SND_PLAYER_COUNT; i++) {
        seqPlayer = &data_020957c0[i];

        if (seqPlayer->status != NNS_SND_SEQ_PLAYER_STATUS_STOP) {
            NNSi_SndPlayerStopSeq(seqPlayer, fadeFrame);
        }
    }
}

void NNS_SndPlayerPause(NNSSndHandle *handle, BOOL flag) {
    NNSi_SndPlayerPause(handle->player, flag);
}

void NNS_SndHandleInit(NNSSndHandle *handle) {
    handle->player = NULL;
}

void NNS_SndHandleReleaseSeq(NNSSndHandle *handle) {
    if (!NNS_SndHandleIsValid(handle)) {
        return;
    }

    handle->player->handle = NULL;
    handle->player = NULL;
}

void NNS_SndPlayerSetVolume(NNSSndHandle *handle, int volume) {
    if (!NNS_SndHandleIsValid(handle)) {
        return;
    }

    handle->player->extVolume = (u8)volume;
}

void NNS_SndPlayerSetInitialVolume(NNSSndHandle *handle, int volume) {
    if (!NNS_SndHandleIsValid(handle)) {
        return;
    }

    handle->player->initVolume = (u8)volume;
}

void NNS_SndPlayerMoveVolume(NNSSndHandle *handle, int targetVolume, int frames) {
    if (!NNS_SndHandleIsValid(handle)) {
        return;
    }

    if (handle->player->status == NNS_SND_SEQ_PLAYER_STATUS_FADEOUT) {
        return;
    }

    NNSi_SndFaderSet(&handle->player->fader, targetVolume << FADER_SHIFT, frames);
}

void NNS_SndPlayerSetPlayerPriority(NNSSndHandle *handle, int priority) {
    if (!NNS_SndHandleIsValid(handle)) {
        return;
    }

    SetPlayerPriority(handle->player, priority);
}

void NNS_SndPlayerSetChannelPriority(NNSSndHandle *handle, int priority) {
    if (!NNS_SndHandleIsValid(handle)) {
        return;
    }

    SND_SetPlayerChannelPriority(handle->player->playerNo, priority);
}

void NNS_SndPlayerSetTrackPitch(NNSSndHandle *handle, u16 trackBitMask, int pitch) {
    if (!NNS_SndHandleIsValid(handle)) {
        return;
    }

    SND_SetTrackPitch(handle->player->playerNo, trackBitMask, pitch);
}

void NNS_SndPlayerSetTrackPan(NNSSndHandle *handle, u16 trackBitMask, int pan) {
    if (!NNS_SndHandleIsValid(handle)) {
        return;
    }

    SND_SetTrackPan(handle->player->playerNo, trackBitMask, pan);
}

void NNS_SndPlayerSetSeqNo(NNSSndHandle *handle, int seqNo) {
    if (!NNS_SndHandleIsValid(handle)) {
        return;
    }

    handle->player->seqType = NNS_SND_PLAYER_SEQ_TYPE_SEQ;
    handle->player->seqNo = (u16)seqNo;
}

void NNS_SndPlayerSetSeqArcNo(NNSSndHandle *handle, int seqArcNo, int index) {
    if (!NNS_SndHandleIsValid(handle)) {
        return;
    }

    handle->player->seqType = NNS_SND_PLAYER_SEQ_TYPE_SEQARC;
    handle->player->seqNo = (u16)seqArcNo;
    handle->player->seqArcIndex = (u16)index;
}

void NNSi_SndPlayerInit(void) {
    NNSSndPlayer *player;
    int playerNo;

    NNS_FndInitList(&data_020957b4, 0x14);
    NNS_FndInitList(&data_020957a8, 0x14);

    for (playerNo = 0; playerNo < SND_PLAYER_COUNT; playerNo++) {
        data_020957c0[playerNo].status = NNS_SND_SEQ_PLAYER_STATUS_STOP;
        data_020957c0[playerNo].playerNo = (u8)playerNo;
        NNS_FndAppendListObject(&data_020957a8, &data_020957c0[playerNo]);
    }

    for (playerNo = 0; playerNo < NNS_SND_PLAYER_NUM; playerNo++) {
        player = &data_02095c00[playerNo];

        NNS_FndInitList(&player->playerList, 0xc);
        NNS_FndInitList(&player->heapList, 0);
        player->volume = 127;
        player->playableSeqCount = 1;
        player->allocChBitFlag = 0;
    }
}

void NNSi_SndPlayerMain(void) {
    NNSSndSeqPlayer *seqPlayer;
    NNSSndSeqPlayer *next;
    u32 status;
    int fader;

    status = SND_GetPlayerStatus();

    for (seqPlayer = (NNSSndSeqPlayer *)NNS_FndGetNextListObject(&data_020957b4, NULL); seqPlayer != NULL;
         seqPlayer = next) {
        next = (NNSSndSeqPlayer *)NNS_FndGetNextListObject(&data_020957b4, seqPlayer);

        if (!seqPlayer->startFlag) {
            if (SND_IsFinishedCommandTag(seqPlayer->commandTag)) {
                seqPlayer->startFlag = TRUE;
            }
        }

        if (seqPlayer->startFlag) {
            if ((status & (1 << seqPlayer->playerNo)) == 0) {
                ShutdownPlayer(seqPlayer);
                continue;
            }
        }

        NNSi_SndFaderUpdate(&seqPlayer->fader);

        fader = SND_CalcDecibel(seqPlayer->initVolume) + SND_CalcDecibel(seqPlayer->extVolume) +
                SND_CalcDecibel(seqPlayer->player->volume) +
                SND_CalcDecibel(NNSi_SndFaderGet(&seqPlayer->fader) >> FADER_SHIFT);
        if (fader < -32768) {
            fader = -32768;
        } else if (fader > 32767) {
            fader = 32767;
        }

        if (fader != seqPlayer->volume) {
            SND_SetPlayerVolume(seqPlayer->playerNo, fader);
            seqPlayer->volume = (s16)fader;
        }

        if (seqPlayer->status == NNS_SND_SEQ_PLAYER_STATUS_FADEOUT) {
            if (NNSi_SndFaderIsFinished(&seqPlayer->fader)) {
                ForceStopSeq(seqPlayer);
            }
        }

        if (seqPlayer->prepareFlag) {
            SND_StartPreparedSeq(seqPlayer->playerNo);
            seqPlayer->prepareFlag = FALSE;
        }
    }
}

NNSSndSeqPlayer *NNSi_SndPlayerAllocSeqPlayer(NNSSndHandle *handle, int playerNo, int prio) {
    NNSSndSeqPlayer *seqPlayer;
    NNSSndPlayer *player;

    player = &data_02095c00[playerNo];

    if (NNS_SndHandleIsValid(handle)) {
        NNS_SndHandleReleaseSeq(handle);
    }

    if (player->playerList.numObjects >= player->playableSeqCount) {
        seqPlayer = (NNSSndSeqPlayer *)NNS_FndGetNextListObject(&player->playerList, NULL);
        if (seqPlayer == NULL) {
            return NULL;
        }
        if (prio < seqPlayer->prio) {
            return NULL;
        }

        ForceStopSeq(seqPlayer);
    }

    seqPlayer = AllocSeqPlayer(prio);
    if (seqPlayer == NULL) {
        return NULL;
    }

    InsertPlayerList(player, seqPlayer);

    seqPlayer->handle = handle;
    handle->player = seqPlayer;

    return seqPlayer;
}

void NNSi_SndPlayerFreeSeqPlayer(NNSSndSeqPlayer *seqPlayer) {
    ShutdownPlayer(seqPlayer);
}

void NNSi_SndPlayerStartSeq(NNSSndSeqPlayer *seqPlayer, const void *seqDataBase, u32 seqDataOffset, SNDBankData *bank) {
    NNSSndPlayer *player;

    player = seqPlayer->player;

    SND_PrepareSeq(seqPlayer->playerNo, seqDataBase, seqDataOffset, bank);
    if (player->allocChBitFlag) {
        SND_SetTrackAllocatableChannel(seqPlayer->playerNo, 0xffff, player->allocChBitFlag);
    }

    InitPlayer(seqPlayer);
    seqPlayer->commandTag = SND_GetCurrentCommandTag();
    seqPlayer->prepareFlag = TRUE;
    seqPlayer->status = NNS_SND_SEQ_PLAYER_STATUS_PLAY;
}

void NNSi_SndPlayerStopSeq(NNSSndSeqPlayer *seqPlayer, int fadeFrame) {
    if (seqPlayer == NULL) {
        return;
    }
    if (seqPlayer->status == NNS_SND_SEQ_PLAYER_STATUS_STOP) {
        return;
    }

    if (fadeFrame == 0) {
        ForceStopSeq(seqPlayer);
        return;
    }

    NNSi_SndFaderSet(&seqPlayer->fader, 0, fadeFrame);
    SetPlayerPriority(seqPlayer, 0);

    seqPlayer->status = NNS_SND_SEQ_PLAYER_STATUS_FADEOUT;
}

void NNSi_SndPlayerPause(NNSSndSeqPlayer *seqPlayer, BOOL flag) {
    if (seqPlayer == NULL) {
        return;
    }

    if (flag != seqPlayer->pauseFlag) {
        SND_PauseSeq(seqPlayer->playerNo, flag);
        seqPlayer->pauseFlag = (u8)flag;
    }
}

NNSSndHeap *NNSi_SndPlayerAllocHeap(int playerNo, NNSSndSeqPlayer *seqPlayer) {
    NNSSndPlayer *player;
    NNSSndPlayerHeap *heap;

    player = &data_02095c00[playerNo];

    heap = (NNSSndPlayerHeap *)NNS_FndGetNextListObject(&player->heapList, NULL);
    if (heap == NULL) {
        return NULL;
    }

    NNS_FndRemoveListObject(&player->heapList, heap);

    heap->player = seqPlayer;
    seqPlayer->heap = heap;

    NNS_SndHeapClear(heap->handle);

    return heap->handle;
}

static void InitPlayer(NNSSndSeqPlayer *seqPlayer) {
    seqPlayer->pauseFlag = FALSE;
    seqPlayer->startFlag = FALSE;
    seqPlayer->prepareFlag = FALSE;

    seqPlayer->seqType = NNS_SND_PLAYER_SEQ_TYPE_INVALID;

    seqPlayer->volume = 0;

    seqPlayer->initVolume = 127;
    seqPlayer->extVolume = 127;

    NNSi_SndFaderInit(&seqPlayer->fader);
    NNSi_SndFaderSet(&seqPlayer->fader, 127 << FADER_SHIFT, 1);
}

static void InsertPlayerList(NNSSndPlayer *player, NNSSndSeqPlayer *seqPlayer) {
    NNSSndSeqPlayer *next = NULL;
    while ((next = (NNSSndSeqPlayer *)NNS_FndGetNextListObject(&player->playerList, next)) != NULL) {
        if (seqPlayer->prio < next->prio) {
            break;
        }
    }

    NNS_FndInsertListObject(&player->playerList, next, seqPlayer);

    seqPlayer->player = player;
}

static void InsertPrioList(NNSSndSeqPlayer *seqPlayer) {
    NNSSndSeqPlayer *next = NULL;
    while ((next = (NNSSndSeqPlayer *)NNS_FndGetNextListObject(&data_020957b4, next)) != NULL) {
        if (seqPlayer->prio < next->prio) {
            break;
        }
    }

    NNS_FndInsertListObject(&data_020957b4, next, seqPlayer);
}

static void ForceStopSeq(NNSSndSeqPlayer *seqPlayer) {
    if (seqPlayer->status == NNS_SND_SEQ_PLAYER_STATUS_FADEOUT) {
        SND_SetPlayerVolume(seqPlayer->playerNo, -723);
    }
    SND_StopSeq(seqPlayer->playerNo);
    ShutdownPlayer(seqPlayer);
}

static NNSSndSeqPlayer *AllocSeqPlayer(int prio) {
    NNSSndSeqPlayer *seqPlayer;

    seqPlayer = (NNSSndSeqPlayer *)NNS_FndGetNextListObject(&data_020957a8, NULL);
    if (seqPlayer == NULL) {
        seqPlayer = (NNSSndSeqPlayer *)NNS_FndGetNextListObject(&data_020957b4, NULL);

        if (prio < seqPlayer->prio) {
            return NULL;
        }

        ForceStopSeq(seqPlayer);
    }
    NNS_FndRemoveListObject(&data_020957a8, seqPlayer);

    seqPlayer->prio = (u8)prio;

    InsertPrioList(seqPlayer);

    return seqPlayer;
}

static void ShutdownPlayer(NNSSndSeqPlayer *seqPlayer) {
    NNSSndPlayer *player;

    if (seqPlayer->handle != NULL) {
        seqPlayer->handle->player = NULL;
        seqPlayer->handle = NULL;
    }

    player = seqPlayer->player;
    NNS_FndRemoveListObject(&player->playerList, seqPlayer);
    seqPlayer->player = NULL;

    if (seqPlayer->heap != NULL) {
        NNS_FndAppendListObject(&player->heapList, seqPlayer->heap);
        seqPlayer->heap->player = NULL;
        seqPlayer->heap = NULL;
    }

    NNS_FndRemoveListObject(&data_020957b4, seqPlayer);
    NNS_FndAppendListObject(&data_020957a8, seqPlayer);

    seqPlayer->status = NNS_SND_SEQ_PLAYER_STATUS_STOP;
}

static void PlayerHeapDisposeCallback(void *mem, u32 size, u32 data1, u32 data2) {
    NNSSndPlayerHeap *heap = (NNSSndPlayerHeap *)mem;
    NNSSndSeqPlayer *seqPlayer;

    if (heap->handle == NULL) {
        return;
    }

    NNS_SndHeapDestroy(heap->handle);

    seqPlayer = heap->player;
    if (seqPlayer != NULL) {
        seqPlayer->heap = NULL;
    } else {
        NNS_FndRemoveListObject(&data_02095c00[heap->playerNo].heapList, heap);
    }
}

static void SetPlayerPriority(NNSSndSeqPlayer *seqPlayer, int priority) {
    NNSSndPlayer *player;

    player = seqPlayer->player;

    if (player != NULL) {
        NNS_FndRemoveListObject(&player->playerList, seqPlayer);
        seqPlayer->player = NULL;
    }

    NNS_FndRemoveListObject(&data_020957b4, seqPlayer);

    seqPlayer->prio = (u8)priority;

    if (player != NULL) {
        InsertPlayerList(player, seqPlayer);
    }

    InsertPrioList(seqPlayer);
}
