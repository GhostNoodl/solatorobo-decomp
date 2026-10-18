#include "nnsys/snd/sndarc.h"

extern void func_0202eac4(int playerNo, int seqMax);
extern void func_0202eae4(int playerNo, u32 allocChBitFlag);
extern BOOL func_0202eafc(int playerNo, void *heap, u32 size);
extern void *func_0202eff8(void *handle, int playerNo, int playerPrio);
extern void func_0202f094(void *seqPlayer);
extern void func_0202f0a0(void *seqPlayer, const void *seqBase, u32 seqOffset, void *bank);
extern GroupHeap *func_0202f168(int playerNo, void *seqPlayer);
extern void func_0202ecd8(void *handle, int volume);
extern void func_0202ed34(void *handle, int prio);
extern void func_0202ed94(void *handle, int seqNo);
extern void func_0202edb4(void *handle, int seqArcNo, int index);


BOOL NNS_SndArcPlayerSetup(void *heap) {
    int i;
    NNSSndArcPlayerInfo *info;
    int j;
    func_0202ff10();
    for (i = 0; i < 0x20; i++) {
        info = func_02030114(i);
        if (info == NULL) {
            continue;
        }
        func_0202eac4(i, info->seqMax);
        func_0202eae4(i, info->allocChBitFlag);
        if (info->heapSize != 0 && heap != NULL) {
            for (j = 0; j < info->seqMax; j++) {
                if (!func_0202eafc(i, heap, info->heapSize)) {
                    return FALSE;
                }
            }
        }
    }
    return TRUE;
}

BOOL NNS_SndArcPlayerStartSeq(void *handle, int seqNo) {
    NNSSndArcSeqInfo *info = func_0202ff20(seqNo);
    if (info == NULL) {
        return FALSE;
    }
    return func_020314f4(handle, info->playerNo, info->bankNo, info->playerPrio, info, seqNo);
}

BOOL NNS_SndArcPlayerStartSeqArc(void *handle, int seqArcNo, int index) {
    NNSSndArcSeqArcInfo *seqArcInfo = func_0202ff84(seqArcNo);
    SndBinaryFile *seqArc;
    NNSSndArcSeqInfo *info;
    if (seqArcInfo == NULL) {
        return FALSE;
    }
    seqArc = func_02030498(seqArcInfo->fileId);
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
    void *seqPlayer = func_0202eff8(handle, playerNo, playerPrio);
    GroupHeap *heap;
    SndBinaryFile *seq;
    void *bank;
    if (seqPlayer == NULL) {
        return FALSE;
    }
    heap = func_0202f168(playerNo, seqPlayer);
    if (func_02030b84(bankNo, NNS_SND_ARC_LOAD_BANK | NNS_SND_ARC_LOAD_WAVE, heap, FALSE, &bank) != SND_ARC_LOAD_SUCCESS) {
        func_0202f094(seqPlayer);
        return FALSE;
    }
    if (func_02030aa0(seqNo, NNS_SND_ARC_LOAD_SEQ, heap, FALSE, (void **)&seq) != SND_ARC_LOAD_SUCCESS) {
        func_0202f094(seqPlayer);
        return FALSE;
    }
    func_0202f0a0(seqPlayer, (u8 *)seq + seq->dataOffset, 0, bank);
    func_0202ecd8(handle, info->volume);
    func_0202ed34(handle, info->channelPrio);
    func_0202ed94(handle, seqNo);
    return TRUE;
}

BOOL func_020315f8(void *handle, int playerNo, int bankNo, int playerPrio, const NNSSndArcSeqInfo *info, SndBinaryFile *seqArc, int seqArcNo, int index) {
    void *seqPlayer = func_0202eff8(handle, playerNo, playerPrio);
    void *bank;
    if (seqPlayer == NULL) {
        return FALSE;
    }
    if (func_02030b84(bankNo, NNS_SND_ARC_LOAD_BANK | NNS_SND_ARC_LOAD_WAVE, func_0202f168(playerNo, seqPlayer), FALSE, &bank) != SND_ARC_LOAD_SUCCESS) {
        func_0202f094(seqPlayer);
        return FALSE;
    }
    func_0202f0a0(seqPlayer, (u8 *)seqArc + seqArc->dataOffset, info->fileId, bank);
    func_0202ecd8(handle, info->volume);
    func_0202ed34(handle, info->channelPrio);
    func_0202edb4(handle, seqArcNo, index);
    return TRUE;
}
