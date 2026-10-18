#include "nnsys/snd/sndarc_stream.h"

void func_02031df0(StrmPlayer *player, int frames) {
    if (!player->playing) {
        func_02031e48(player);
        return;
    }
    if (frames == 0) {
        func_02031e48(player);
        return;
    }
    NNSi_SndFaderSet(&player->fader, 0, frames);
    player->prio = 0;
    player->stopReq = TRUE;
}

void func_02031e48(StrmPlayer *player) {
    OS_LockMutex(data_02097c98);
    if (data_0209622c.altThread != NULL) {
        OS_LockMutex(data_0209622c.altThread->mutex);
    }
    if (player->playing) {
        NNS_SndStrmStop(player);
    }
    if (player->active) {
        player->stopFn(player);
    }
    func_02031ee0(player);
    OS_UnlockMutex(data_02097c98);
    if (data_0209622c.altThread != NULL) {
        OS_UnlockMutex(data_0209622c.altThread->mutex);
    }
}

void func_02031ee0(StrmPlayer *player) {
    if (!player->active) {
        return;
    }
    func_02031f80(player);
    player->closeFn(player);
    func_0203200c(&data_02097cb0, player);
    if (data_0209622c.altThread != NULL) {
        func_0203200c(&data_0209622c.altThread->cmdList, player);
    }
    func_02031b58(player);
}

BOOL func_02031f48(StrmPlayer *player, int chNum, u8 *chList) {
    if (player->chRefCount == 0) {
        if (!NNS_SndStrmAllocChannel(player, chNum, chList)) {
            return FALSE;
        }
    }
    player->chRefCount++;
    return TRUE;
}

void func_02031f80(StrmPlayer *player) {
    if (player->chRefCount == 0) {
        return;
    }
    if (--player->chRefCount == 0) {
        NNS_SndStrmFreeChannel(player);
    }
}

void func_02031fa4(StrmThread *thread, u32 prio) {
    OS_CreateThread(thread, func_02032e58, thread, thread->stack + sizeof(thread->stack), sizeof(thread->stack), prio);
    NNS_FndInitList(&thread->cmdList, 0);
    OS_InitMutex(thread->mutex);
    thread->queueHead = thread->queueTail = NULL;
    OS_WakeupThreadDirect(thread);
}

void func_0203200c(NNSFndList *list, StrmPlayer *player) {
    u32 state = OS_DisableInterrupts();
    StrmCommand *cmd = NNS_FndGetNextListObject(list, NULL);
    StrmCommand *next;
    while (cmd != NULL) {
        next = NNS_FndGetNextListObject(list, cmd);
        if (cmd->player == player) {
            NNS_FndRemoveListObject(list, cmd);
            func_02032110(cmd);
        }
        cmd = next;
    }
    OS_RestoreInterrupts(state);
}

StrmCommand *func_0203207c(NNSFndList *list) {
    u32 state = OS_DisableInterrupts();
    StrmCommand *cmd = NNS_FndGetNextListObject(list, NULL);
    if (cmd != NULL) {
        NNS_FndRemoveListObject(list, cmd);
        cmd->player->cmdCount--;
    }
    OS_RestoreInterrupts(state);
    return cmd;
}

StrmCommand *func_020320cc(void) {
    u32 state = OS_DisableInterrupts();
    StrmCommand *cmd = NNS_FndGetNextListObject(&data_02096238, NULL);
    if (cmd != NULL) {
        NNS_FndRemoveListObject(&data_02096238, cmd);
    }
    OS_RestoreInterrupts(state);
    return cmd;
}

void func_02032110(StrmCommand *cmd) {
    u32 state = OS_DisableInterrupts();
    NNS_FndAppendListObject(&data_02096238, cmd);
    OS_RestoreInterrupts(state);
}

void func_0203213c(void *data, u32 size, u32 arg0, u32 arg1) {
    StrmPlayer *player = (StrmPlayer *)arg0;
    if (data != player->buffer) {
        return;
    }
    OS_LockMutex(data_02097c98);
    if (data_0209622c.altThread != NULL) {
        OS_LockMutex(data_0209622c.altThread->mutex);
    }
    func_02031e48(player);
    player->buffer = NULL;
    player->bufSize = 0;
    player->chNum = 0;
    if (player->chRefCount > 0) {
        NNS_SndStrmFreeChannel(player);
        player->chRefCount = 0;
    }
    OS_UnlockMutex(data_02097c98);
    if (data_0209622c.altThread != NULL) {
        OS_UnlockMutex(data_0209622c.altThread->mutex);
    }
}

void func_020321d4(int status, int numBuffers, void **buffers, u32 size, int format, void *arg) {
    StrmPlayer *player = arg;
    StrmCommand *cmd;
    StrmThread *thread;
    int i;
    if (player->cmdCount >= 2) {
        for (cmd = NNS_FndGetNextListObject(&data_02097cb0, NULL); cmd != NULL; cmd = NNS_FndGetNextListObject(&data_02097cb0, cmd)) {
            if (cmd->player == player) {
                break;
            }
        }
        for (i = 0; i < cmd->numBuffers; i++) {
            MI_CpuFill8(cmd->buffers[i], 0, cmd->size);
        }
        NNS_FndRemoveListObject(&data_02097cb0, cmd);
        player->cmdCount--;
        func_02032110(cmd);
    }
    cmd = func_020320cc();
    cmd->player = player;
    cmd->unk_0c = status;
    cmd->numBuffers = numBuffers;
    for (i = 0; i < numBuffers; i++) {
        cmd->buffers[i] = buffers[i];
    }
    cmd->size = size;
    thread = &data_02096bd0;
    if (status == 0 && data_0209622c.altThread != NULL) {
        thread = data_0209622c.altThread;
    }
    player->cmdCount++;
    NNS_FndAppendListObject(&thread->cmdList, cmd);
    OS_WakeupThread(&thread->queueHead);
}

void func_02032310(StrmPlayer *player) {
    StrmCbInfo cur;
    StrmCbNext next;
    NNSSndArcStrmInfo *info;
    int format;
    u32 rate;
    cur.playerNo = player->playerNo;
    cur.strmNo = player->strmNo;
    next.strmNo = player->strmNo;
    next.offset = 0;
    if (!player->callback(0, (u32 *)&cur, (u32 *)&next, player->callbackArg)) {
        return;
    }
    info = NNS_SndArcGetStrmInfo(next.strmNo);
    if (info == NULL) {
        return;
    }
    format = player->header.format;
    rate = player->header.sampleRate;
    player->closeFn(player);
    func_02032c54(player, info->fileId);
    if (!player->openFn(player, info->fileId)) {
        return;
    }
    if (rate != player->header.sampleRate) {
        return;
    }
    if (format == 0 && player->header.format != 0) {
        return;
    }
    if (format != 0 && player->header.format == 0) {
        return;
    }
    player->strmNo = next.strmNo;
    player->startOffset = (u32)((u64)player->header.sampleRate * next.offset / 1000);
    if (player->startOffset != 0 && player->header.format == 2) {
        player->unk_118_4 = TRUE;
    } else {
        player->unk_118_4 = FALSE;
    }
    player->unk_118_5 = FALSE;
}
