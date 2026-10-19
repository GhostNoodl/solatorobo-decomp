#include "nnsys/snd/sndarc_stream.h"

StrmThread *func_02031ac0(void) {
    return &data_02096bd0;
}

StrmPlayer *func_02031acc(StrmHandle *handle, int playerNo, int prio) {
    StrmPlayer *player;
    if (handle->player != NULL) {
        func_0203199c(handle);
    }
    player = &data_020965e0[playerNo];
    if (player->buffer == NULL) {
        return NULL;
    }
    if (player->active) {
        if (prio < player->prio) {
            return NULL;
        }
        func_02031e48(player);
    }
    player->prio = prio;
    player->active = TRUE;
    player->handle = handle;
    handle->player = player;
    return player;
}

void func_02031b58(StrmPlayer *player) {
    if (player->handle != NULL) {
        player->handle->player = NULL;
        player->handle = NULL;
    }
    player->active = FALSE;
    player->startReq = FALSE;
    player->playing = FALSE;
}

BOOL func_02031b84(StrmHandle *handle, const NNSSndArcStrmInfo *info, int playerNo, int prio, u32 strmNo, u32 offset, u32 a6, u32 a7, void *a8, u32 a9) {
    StrmPlayer *player;
    int format;
    int chNum;
    player = func_02031acc(handle, playerNo, prio);
    if (player == NULL) {
        return FALSE;
    }
    func_02032c54(player, info->fileId);
    if (!player->openFn(player, info->fileId)) {
        func_02031b58(player);
        return FALSE;
    }
    player->startOffset = (u32)((u64)player->header.sampleRate * offset / 1000);
    if (player->startOffset != 0 && player->header.format == 2) {
        player->unk_118_4 = TRUE;
    } else {
        player->unk_118_4 = FALSE;
    }
    player->unk_11c = 4;
    player->unk_118_5 = FALSE;
    player->playing = FALSE;
    player->unk_120 = 0;
    player->startReq = FALSE;
    player->stopReq = FALSE;
    player->cmdCount = 0;
    player->unk_13c = a6;
    player->unk_140 = a7;
    player->callback = a8;
    player->callbackArg = a9;
    player->strmNo = strmNo;
    player->curVolume = 0;
    player->volume = info->volume;
    player->userVolume = 0x7f;
    NNSi_SndFaderInit(&player->fader);
    NNSi_SndFaderSet(&player->fader, 0x7f << 8, 1);
    switch (player->header.format) {
    case 0:
        format = 0;
        break;
    case 1:
    case 2:
        format = 1;
        break;
    }
    chNum = player->header.channels;
    if (info->flags & 1) {
        chNum = 2;
    }
    if (chNum > player->chNum) {
        chNum = player->chNum;
    }
    player->mono = chNum == 1;
    if (!func_02031f48(player, chNum, player->chList)) {
        player->closeFn(player);
        func_02031b58(player);
        return FALSE;
    }
    if (!NNS_SndStrmSetup(player, format, player->buffer, player->bufSize * chNum / player->chNum, player->header.timer, 4, func_020321d4, player)) {
        func_02031f80(player);
        player->closeFn(player);
        func_02031b58(player);
        return FALSE;
    }
    if (chNum == 2) {
        NNS_SndStrmSetChannelPan(player, 0, 0);
        NNS_SndStrmSetChannelPan(player, 1, 0x7f);
    }
    return TRUE;
}
