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

extern void DC_FlushRange(const void *addr, u32 size);
extern const s8 data_0207574c[16];
extern const s16 data_0207575c[89];

typedef enum { NNS_SND_STRM_FORMAT_PCM8, NNS_SND_STRM_FORMAT_PCM16 } NNSSndStrmFormat;
typedef void (*StrmDataCallback)(int status, int numBuffers, void **buffers, u32 size, NNSSndStrmFormat format, u32 arg);

static inline s16 StrmDecodeAdpcm(StrmAdpcmState *st, u32 data) {
    int step;
    int pred;
    int index;
    int diff;
    pred = st->pred;
    index = st->index;
    step = data_0207575c[index];
    diff = step >> 3;
    if (data & 4) {
        diff += step;
    }
    if (data & 2) {
        diff += step >> 1;
    }
    if (data & 1) {
        diff += step >> 2;
    }
    if (data & 8) {
        pred -= diff;
        if (pred < -0x8000) {
            pred = -0x8000;
        }
    } else {
        pred += diff;
        if (pred > 0x7fff) {
            pred = 0x7fff;
        }
    }
    index += data_0207574c[data];
    if (index < 0) {
        index = 0;
    } else if (index > 88) {
        index = 88;
    }
    st->pred = pred;
    st->index = index;
    return pred;
}

void func_0203244c(StrmCommand *cmd) {
    StrmPlayer *player;
    BOOL loop;
    unsigned long offset;
    u32 remain;
    u32 blockSize;
    u32 blockOffset;
    u32 filePos;
    u32 samples;
    u32 outSize;
    u32 readSize;
    int ch;
    u32 block;
    u32 blockSamples;
    u32 readOffset;
    s16 *dst;
    u8 *src;
    StrmAdpcmState *st;
    u32 readLen;

    player = cmd->player;
    if (player->unk_118_5 && player->unk_11c > 0) {
        player->unk_11c--;
    }
    remain = cmd->size;
    offset = 0;
    while (remain != 0) {
        if (player->unk_118_5) {
            for (ch = 0; ch < cmd->numBuffers; ch++) {
                MI_CpuFill8((u8 *)cmd->buffers[ch] + offset, 0, remain);
            }
            break;
        }
        block = player->startOffset / player->header.blockSamples;
        if (block < player->header.numBlocks - 1) {
            blockSamples = player->header.blockSamples;
            blockSize = player->header.blockSize;
        } else {
            blockSize = player->header.lastBlockSize;
            blockSamples = player->header.lastBlockSamples;
        }
        samples = remain;
        blockOffset = player->startOffset - block * player->header.blockSamples;
        if (player->header.format != 0) {
            samples = remain >> 1;
        }
        if (player->unk_118_4) {
            if (blockOffset == 0) {
                player->unk_118_4 = FALSE;
            } else {
                samples = blockOffset;
                blockOffset = 0;
            }
        }
        loop = FALSE;
        if (blockOffset + samples >= blockSamples) {
            samples = blockSamples - blockOffset;
            if (block >= player->header.numBlocks - 1) {
                if (player->header.loop) {
                    loop = TRUE;
                } else {
                    player->unk_118_5 = TRUE;
                }
            }
        }
        readOffset = blockOffset;
        outSize = samples;
        switch (player->header.format) {
        case 0:
            readSize = samples;
            break;
        case 1:
            outSize = samples * 2;
            readSize = outSize;
            readOffset = blockOffset * 2;
            break;
        case 2:
            readSize = ((blockOffset + samples + 1) >> 1) - (blockOffset >> 1);
            readOffset = blockOffset >> 1;
            if (blockOffset == 0) {
                readSize += 4;
            } else {
                readOffset += 4;
            }
            outSize *= 2;
            break;
        }
        filePos = block * player->header.blockSize * player->header.channels + readOffset;
        filePos += player->header.dataOffset;
        for (ch = 0; ch < cmd->numBuffers; ch++) {
            src = (u8 *)cmd->buffers[ch] + offset;
            dst = (s16 *)src;
            if (ch < player->header.channels) {
                if (player->header.format == 2) {
                    OS_LockMutex(data_02096244);
                    src = (u8 *)data_0209622c.unk_8;
                }
                readLen = player->readFn(player, src, readSize, filePos + ch * blockSize);
                if (readLen != readSize) {
                    player->unk_118_5 = TRUE;
                    outSize = 0;
                    samples = 0;
                    loop = FALSE;
                    if (player->header.format == 2) {
                        OS_UnlockMutex(data_02096244);
                    }
                    break;
                }
                if (player->header.format == 2) {
                    u8 *in;
                    u32 k;
                    u32 end;
                    u8 *work;
                    st = &player->adpcm[ch];
                    work = (u8 *)data_0209622c.unk_8;
                    in = work;
                    if (blockOffset == 0) {
                        in = work + 4;
                        *st = *(StrmAdpcmState *)work;
                    }
                    end = blockOffset + samples;
                    k = blockOffset;
                    if (blockOffset & 1) {
                        *dst++ = StrmDecodeAdpcm(st, (*in >> 4) & 0xf);
                        k++;
                        in++;
                    }
                    for (; k < (end & ~1); k += 2, in++) {
                        *dst++ = StrmDecodeAdpcm(st, *in & 0xf);
                        *dst++ = StrmDecodeAdpcm(st, (*in >> 4) & 0xf);
                    }
                    if (k < end) {
                        *dst = StrmDecodeAdpcm(st, *in & 0xf);
                    }
                    OS_UnlockMutex(data_02096244);
                }
            } else if (player->mono) {
                MI_CpuFill8(src, 0, outSize);
            } else {
                MI_CpuCopy8((u8 *)cmd->buffers[0] + offset, src, outSize);
            }
        }
        if (player->unk_118_4) {
            player->unk_118_4 = FALSE;
        } else {
            if (loop) {
                player->startOffset = player->header.loopStart;
            } else {
                player->startOffset += samples;
            }
            offset += outSize;
            remain -= outSize;
            if (player->unk_118_5 && player->callback != NULL) {
                func_02032310(player);
            }
        }
    }
    if (player->unk_13c != 0) {
        ((StrmDataCallback)player->unk_13c)(cmd->unk_0c, cmd->numBuffers, cmd->buffers, cmd->size, player->header.format == 0 ? NNS_SND_STRM_FORMAT_PCM8 : NNS_SND_STRM_FORMAT_PCM16, player->unk_140);
    }
    for (ch = 0; ch < cmd->numBuffers; ch++) {
        DC_FlushRange(cmd->buffers[ch], cmd->size);
    }
    if (cmd->unk_0c == 0) {
        player->unk_120 = 1;
    }
}
