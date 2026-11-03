#include "nnsys/snd/sndarc.h"

extern void DC_StoreRange(void *buffer, u32 size);
extern void SND_AssignWaveArc(void *bank, int index, void *waveArc);

BOOL NNS_SndArcLoadGroup(int groupNo, NNSSndHeap *heap) {
    return SndArcLd_LoadGroup(groupNo, heap) == SND_ARC_LOAD_SUCCESS;
}

BOOL NNS_SndArcLoadSeq(int seqNo, NNSSndHeap *heap) {
    BOOL ret = TRUE;
    if (SndArcLd_LoadSeq(seqNo, 0xff, heap, TRUE, NULL)) {
        ret = FALSE;
    }
    return ret;
}

BOOL NNS_SndArcLoadSeqArc(int seqArcNo, NNSSndHeap *heap) {
    BOOL ret = TRUE;
    if (SndArcLd_LoadSeqArc(seqArcNo, 0xff, heap, TRUE, NULL)) {
        ret = FALSE;
    }
    return ret;
}

BOOL NNS_SndArcLoadBank(int bankNo, NNSSndHeap *heap) {
    BOOL ret = TRUE;
    if (SndArcLd_LoadBank(bankNo, 0xff, heap, TRUE, NULL)) {
        ret = FALSE;
    }
    return ret;
}

BOOL NNS_SndArcLoadSeqEx(int seqNo, u32 loadFlag, NNSSndHeap *heap) {
    BOOL ret = TRUE;
    if (SndArcLd_LoadSeq(seqNo, loadFlag, heap, TRUE, NULL)) {
        ret = FALSE;
    }
    return ret;
}

int SndArcLd_LoadGroup(int groupNo, NNSSndHeap *heap) {
    NNSSndArcGroupInfo *group = NNS_SndArcGetGroupInfo(groupNo);
    u32 i;
    int ret;
    if (group == NULL) {
        return SND_ARC_LOAD_ERR_INVALID_GROUP_NO;
    }
    for (i = 0; i < group->count; i++) {
        NNSSndArcGroupItem *item = &group->item[i];
        switch (item->type) {
            case 0:
                ret = SndArcLd_LoadSeq(item->index, item->loadFlag, heap, TRUE, NULL);
                if (ret != SND_ARC_LOAD_SUCCESS) {
                    return ret;
                }
                break;
            case 3:
                ret = SndArcLd_LoadSeqArc(item->index, item->loadFlag, heap, TRUE, NULL);
                if (ret != SND_ARC_LOAD_SUCCESS) {
                    return ret;
                }
                break;
            case 1:
                ret = SndArcLd_LoadBank(item->index, item->loadFlag, heap, TRUE, NULL);
                if (ret != SND_ARC_LOAD_SUCCESS) {
                    return ret;
                }
                break;
            case 2:
                ret = SndArcLd_LoadWaveArc(item->index, item->loadFlag, heap, TRUE, NULL);
                if (ret != SND_ARC_LOAD_SUCCESS) {
                    return ret;
                }
                break;
        }
    }
    return SND_ARC_LOAD_SUCCESS;
}

int SndArcLd_LoadSeq(int seqNo, u32 loadFlag, NNSSndHeap *heap, BOOL setAddress, void **out) {
    NNSSndArcSeqInfo *info = NNS_SndArcGetSeqInfo(seqNo);
    void *seq;
    int ret;
    if (info == NULL) {
        return SND_ARC_LOAD_ERR_INVALID_SEQ_NO;
    }
    ret = SndArcLd_LoadBank(info->bankNo, loadFlag, heap, setAddress, NULL);
    if (ret != SND_ARC_LOAD_SUCCESS) {
        return ret;
    }
    if (loadFlag & NNS_SND_ARC_LOAD_SEQ) {
        seq = SndArcLd_LoadSeqFile(info->fileId, heap, setAddress);
        if (seq == NULL) {
            return SND_ARC_LOAD_ERR_FAILED_LOAD_SEQ;
        }
    } else {
        seq = NNS_SndArcGetFileAddress(info->fileId);
    }
    if (out != NULL) {
        *out = seq;
    }
    return SND_ARC_LOAD_SUCCESS;
}

int SndArcLd_LoadSeqArc(int seqArcNo, u32 loadFlag, NNSSndHeap *heap, BOOL setAddress, void **out) {
    NNSSndArcSeqArcInfo *info = NNS_SndArcGetSeqArcInfo(seqArcNo);
    void *seqArc;
    if (info == NULL) {
        return SND_ARC_LOAD_ERR_INVALID_SEQARC_NO;
    }
    if (loadFlag & NNS_SND_ARC_LOAD_SEQARC) {
        seqArc = SndArcLd_LoadSeqArcFile(info->fileId, heap, setAddress);
        if (seqArc == NULL) {
            return SND_ARC_LOAD_ERR_FAILED_LOAD_SEQARC;
        }
    } else {
        seqArc = NNS_SndArcGetFileAddress(info->fileId);
    }
    if (out != NULL) {
        *out = seqArc;
    }
    return SND_ARC_LOAD_SUCCESS;
}

int SndArcLd_LoadBank(int bankNo, u32 loadFlag, NNSSndHeap *heap, BOOL setAddress, void **out) {
    NNSSndArcBankInfo *info = NNS_SndArcGetBankInfo(bankNo);
    void *bank;
    int i;
    if (info == NULL) {
        return SND_ARC_LOAD_ERR_INVALID_BANK_NO;
    }
    if (loadFlag & NNS_SND_ARC_LOAD_BANK) {
        bank = SndArcLd_LoadBankFile(info->fileId, heap, setAddress);
        if (bank == NULL) {
            return SND_ARC_LOAD_ERR_FAILED_LOAD_BANK;
        }
    } else {
        bank = NNS_SndArcGetFileAddress(info->fileId);
    }
    for (i = 0; i < 4; i++) {
        NNSSndArcWaveArcInfo *waveArcInfo;
        void *waveArc;
        int ret;
        if (info->waveArcNo[i] == 0xffff) {
            continue;
        }
        waveArcInfo = NNS_SndArcGetWaveArcInfo(info->waveArcNo[i]);
        if (waveArcInfo == NULL) {
            return SND_ARC_LOAD_ERR_INVALID_WAVEARC_NO;
        }
        ret = SndArcLd_LoadWaveArc(info->waveArcNo[i], loadFlag, heap, setAddress, &waveArc);
        if (ret != SND_ARC_LOAD_SUCCESS) {
            return ret;
        }
        if ((waveArcInfo->flags & 1) && (loadFlag & NNS_SND_ARC_LOAD_WAVE)) {
            if (!SndArcLd_LoadBankWaves(waveArc, bank, i, waveArcInfo->fileId, heap)) {
                return SND_ARC_LOAD_ERR_FAILED_LOAD_WAVE;
            }
        }
        if (bank != NULL && waveArc != NULL) {
            SND_AssignWaveArc(bank, i, waveArc);
        }
    }
    if (out != NULL) {
        *out = bank;
    }
    return SND_ARC_LOAD_SUCCESS;
}

int SndArcLd_LoadWaveArc(int waveArcNo, u32 loadFlag, NNSSndHeap *heap, BOOL setAddress, void **out) {
    NNSSndArcWaveArcInfo *info = NNS_SndArcGetWaveArcInfo(waveArcNo);
    void *waveArc;
    if (info == NULL) {
        return SND_ARC_LOAD_ERR_INVALID_WAVEARC_NO;
    }
    if (loadFlag & NNS_SND_ARC_LOAD_WAVE) {
        if (info->flags & 1) {
            waveArc = LoadWaveArcTable(info->fileId, heap, setAddress);
        } else {
            waveArc = SndArcLd_LoadWaveArcFile(info->fileId, heap, setAddress);
        }
        if (waveArc == NULL) {
            return SND_ARC_LOAD_ERR_FAILED_LOAD_WAVE;
        }
    } else {
        waveArc = NNS_SndArcGetFileAddress(info->fileId);
    }
    if (out != NULL) {
        *out = waveArc;
    }
    return SND_ARC_LOAD_SUCCESS;
}

void *SndArcLd_LoadFile(u32 fileId, NNSSndHeapDisposeCallback callback, u32 arg0, u32 arg1, NNSSndHeap *heap) {
    u32 size = NNS_SndArcGetFileSize(fileId);
    void *buffer;
    if (size == 0) {
        return NULL;
    }
    if (heap == NULL) {
        return NULL;
    }
    buffer = NNS_SndHeapAlloc(heap, size + 0x20, callback, arg0, arg1);
    if (buffer == NULL) {
        return NULL;
    }
    if (NNS_SndArcReadFile(fileId, buffer, size, 0) != size) {
        return NULL;
    }
    DC_StoreRange(buffer, size);
    return buffer;
}

void *SndArcLd_LoadSeqFile(u32 fileId, NNSSndHeap *heap, BOOL setAddress) {
    void *seq = NNS_SndArcGetFileAddress(fileId);
    if (seq == NULL) {
        seq = SndArcLd_LoadFile(fileId, (NNSSndHeapDisposeCallback)SndArcLd_DisposeSeq, setAddress ? (u32)NNS_SndArcGetCurrent() : 0, fileId, heap);
        if (setAddress && seq != NULL) {
            NNS_SndArcSetFileAddress(fileId, seq);
        }
    }
    return seq;
}

void *SndArcLd_LoadSeqArcFile(u32 fileId, NNSSndHeap *heap, BOOL setAddress) {
    void *seqArc = NNS_SndArcGetFileAddress(fileId);
    if (seqArc == NULL) {
        seqArc = SndArcLd_LoadFile(fileId, (NNSSndHeapDisposeCallback)SndArcLd_DisposeSeq, setAddress ? (u32)NNS_SndArcGetCurrent() : 0, fileId, heap);
        if (setAddress && seqArc != NULL) {
            NNS_SndArcSetFileAddress(fileId, seqArc);
        }
    }
    return seqArc;
}

void *SndArcLd_LoadBankFile(u32 fileId, NNSSndHeap *heap, BOOL setAddress) {
    void *bank = NNS_SndArcGetFileAddress(fileId);
    if (bank == NULL) {
        bank = SndArcLd_LoadFile(fileId, (NNSSndHeapDisposeCallback)SndArcLd_DisposeBank, setAddress ? (u32)NNS_SndArcGetCurrent() : 0, fileId, heap);
        if (setAddress && bank != NULL) {
            NNS_SndArcSetFileAddress(fileId, bank);
        }
    }
    return bank;
}

void *SndArcLd_LoadWaveArcFile(u32 fileId, NNSSndHeap *heap, BOOL setAddress) {
    void *waveArc = NNS_SndArcGetFileAddress(fileId);
    if (waveArc == NULL) {
        waveArc = SndArcLd_LoadFile(fileId, (NNSSndHeapDisposeCallback)SndArcLd_DisposeWaveArc, setAddress ? (u32)NNS_SndArcGetCurrent() : 0, fileId, heap);
        if (setAddress && waveArc != NULL) {
            NNS_SndArcSetFileAddress(fileId, waveArc);
        }
    }
    return waveArc;
}
