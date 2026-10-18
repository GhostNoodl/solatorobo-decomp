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
