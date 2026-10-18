#include "nnsys/snd/sndarc_stream.h"

BOOL func_020317c4(NNSSndHeap *heap) {
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
            void *buf = NNS_SndHeapAlloc(heap, size, (NNSSndHeapDisposeCallback)func_0203213c, (u32)player, 0);
            if (buf == NULL) {
                return FALSE;
            }
            func_02031e48(player);
            player->buffer = buf;
            player->bufSize = size;
        }
    }
    return TRUE;
}

BOOL func_0203188c(StrmHandle *handle, int strmNo, u32 offset) {
    NNSSndArcStrmInfo *info = NNS_SndArcGetStrmInfo(strmNo);
    if (info == NULL) {
        return FALSE;
    }
    return func_02031b84(handle, info, info->playerNo, info->playerPrio, strmNo, offset, 0, 0, NULL, 0);
}

void func_020318e8(StrmHandle *handle) {
    if (handle->player != NULL) {
        handle->player->startReq = TRUE;
    }
}

BOOL func_02031904(StrmHandle *handle, int strmNo, u32 offset) {
    if (!func_0203188c(handle, strmNo, offset)) {
        return FALSE;
    }
    func_020318e8(handle);
    return TRUE;
}

void func_0203192c(StrmHandle *handle, int frames) {
    if (handle->player == NULL) {
        return;
    }
    func_02031df0(handle->player, frames);
}

void func_02031948(StrmHandle *handle, int volume) {
    if (handle->player != NULL) {
        handle->player->userVolume = volume;
    }
}

void func_0203195c(StrmHandle *handle, int volume, int frames) {
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

void func_02031990(StrmHandle *handle) {
    handle->player = NULL;
}

void func_0203199c(StrmHandle *handle) {
    StrmPlayer *player = handle->player;
    if (player != NULL) {
        player->handle = NULL;
        handle->player = NULL;
    }
}
