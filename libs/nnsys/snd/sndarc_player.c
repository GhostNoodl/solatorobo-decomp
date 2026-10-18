#include "nnsys/snd/sndarc.h"

extern void NNS_SndPlayerSetPlayableSeqCount(int playerNo, int seqMax);
extern void NNS_SndPlayerSetAllocatableChannel(int playerNo, u32 allocChBitFlag);
extern BOOL NNS_SndPlayerCreateHeap(int playerNo, void *heap, u32 size);
extern void *NNSi_SndPlayerAllocSeqPlayer(void *handle, int playerNo, int playerPrio);
extern void NNSi_SndPlayerFreeSeqPlayer(void *seqPlayer);
extern void NNSi_SndPlayerStartSeq(void *seqPlayer, const void *seqBase, u32 seqOffset, void *bank);
extern NNSSndHeap *NNSi_SndPlayerAllocHeap(int playerNo, void *seqPlayer);
extern void NNS_SndPlayerSetInitialVolume(void *handle, int volume);
extern void NNS_SndPlayerSetChannelPriority(void *handle, int prio);
extern void NNS_SndPlayerSetSeqNo(void *handle, int seqNo);
extern void NNS_SndPlayerSetSeqArcNo(void *handle, int seqArcNo, int index);


BOOL NNS_SndArcPlayerSetup(void *heap) {
    int i;
    NNSSndArcPlayerInfo *info;
    int j;
    NNS_SndArcGetCurrent();
    for (i = 0; i < 0x20; i++) {
        info = NNS_SndArcGetPlayerInfo(i);
        if (info == NULL) {
            continue;
        }
        NNS_SndPlayerSetPlayableSeqCount(i, info->seqMax);
        NNS_SndPlayerSetAllocatableChannel(i, info->allocChBitFlag);
        if (info->heapSize != 0 && heap != NULL) {
            for (j = 0; j < info->seqMax; j++) {
                if (!NNS_SndPlayerCreateHeap(i, heap, info->heapSize)) {
                    return FALSE;
                }
            }
        }
    }
    return TRUE;
}

BOOL NNS_SndArcPlayerStartSeq(void *handle, int seqNo) {
    NNSSndArcSeqInfo *info = NNS_SndArcGetSeqInfo(seqNo);
    if (info == NULL) {
        return FALSE;
    }
    return func_020314f4(handle, info->playerNo, info->bankNo, info->playerPrio, info, seqNo);
}

BOOL NNS_SndArcPlayerStartSeqArc(void *handle, int seqArcNo, int index) {
    NNSSndArcSeqArcInfo *seqArcInfo = NNS_SndArcGetSeqArcInfo(seqArcNo);
    SndBinaryFile *seqArc;
    NNSSndArcSeqInfo *info;
    if (seqArcInfo == NULL) {
        return FALSE;
    }
    seqArc = NNS_SndArcGetFileAddress(seqArcInfo->fileId);
    if (seqArc == NULL) {
        return FALSE;
    }
    info = (NNSSndArcSeqInfo *)func_02032eac((SndSeqArc *)seqArc, index);
    if (info == NULL) {
        return FALSE;
    }
    return func_020315f8(handle, info->playerNo, info->bankNo, info->playerPrio, info, seqArc, seqArcNo, index);
}

BOOL func_020314f4(void *handle, int playerNo, int bankNo, int playerPrio, const NNSSndArcSeqInfo *info, int seqNo) {
    void *seqPlayer = NNSi_SndPlayerAllocSeqPlayer(handle, playerNo, playerPrio);
    NNSSndHeap *heap;
    SndBinaryFile *seq;
    void *bank;
    if (seqPlayer == NULL) {
        return FALSE;
    }
    heap = NNSi_SndPlayerAllocHeap(playerNo, seqPlayer);
    if (func_02030b84(bankNo, NNS_SND_ARC_LOAD_BANK | NNS_SND_ARC_LOAD_WAVE, heap, FALSE, &bank) != SND_ARC_LOAD_SUCCESS) {
        NNSi_SndPlayerFreeSeqPlayer(seqPlayer);
        return FALSE;
    }
    if (func_02030aa0(seqNo, NNS_SND_ARC_LOAD_SEQ, heap, FALSE, (void **)&seq) != SND_ARC_LOAD_SUCCESS) {
        NNSi_SndPlayerFreeSeqPlayer(seqPlayer);
        return FALSE;
    }
    NNSi_SndPlayerStartSeq(seqPlayer, (u8 *)seq + seq->dataOffset, 0, bank);
    NNS_SndPlayerSetInitialVolume(handle, info->volume);
    NNS_SndPlayerSetChannelPriority(handle, info->channelPrio);
    NNS_SndPlayerSetSeqNo(handle, seqNo);
    return TRUE;
}

BOOL func_020315f8(void *handle, int playerNo, int bankNo, int playerPrio, const NNSSndArcSeqInfo *info, SndBinaryFile *seqArc, int seqArcNo, int index) {
    void *seqPlayer = NNSi_SndPlayerAllocSeqPlayer(handle, playerNo, playerPrio);
    void *bank;
    if (seqPlayer == NULL) {
        return FALSE;
    }
    if (func_02030b84(bankNo, NNS_SND_ARC_LOAD_BANK | NNS_SND_ARC_LOAD_WAVE, NNSi_SndPlayerAllocHeap(playerNo, seqPlayer), FALSE, &bank) != SND_ARC_LOAD_SUCCESS) {
        NNSi_SndPlayerFreeSeqPlayer(seqPlayer);
        return FALSE;
    }
    NNSi_SndPlayerStartSeq(seqPlayer, (u8 *)seqArc + seqArc->dataOffset, info->fileId, bank);
    NNS_SndPlayerSetInitialVolume(handle, info->volume);
    NNS_SndPlayerSetChannelPriority(handle, info->channelPrio);
    NNS_SndPlayerSetSeqArcNo(handle, seqArcNo, index);
    return TRUE;
}
