#include "nnsys/snd/sndarc.h"

extern void func_02019278(void *buffer, u32 size);
extern void func_0201ca68(void *bank, int index, void *waveArc);

BOOL NNS_SndArcLoadGroup(int groupNo, NNSSndHeap *heap) {
    return func_020309a4(groupNo, heap) == SND_ARC_LOAD_SUCCESS;
}

BOOL NNS_SndArcLoadSeq(int seqNo, NNSSndHeap *heap) {
    BOOL ret = TRUE;
    if (func_02030aa0(seqNo, 0xff, heap, TRUE, NULL)) {
        ret = FALSE;
    }
    return ret;
}

BOOL NNS_SndArcLoadSeqArc(int seqArcNo, NNSSndHeap *heap) {
    BOOL ret = TRUE;
    if (func_02030b24(seqArcNo, 0xff, heap, TRUE, NULL)) {
        ret = FALSE;
    }
    return ret;
}

BOOL NNS_SndArcLoadBank(int bankNo, NNSSndHeap *heap) {
    BOOL ret = TRUE;
    if (func_02030b84(bankNo, 0xff, heap, TRUE, NULL)) {
        ret = FALSE;
    }
    return ret;
}

BOOL NNS_SndArcLoadSeqEx(int seqNo, u32 loadFlag, NNSSndHeap *heap) {
    BOOL ret = TRUE;
    if (func_02030aa0(seqNo, loadFlag, heap, TRUE, NULL)) {
        ret = FALSE;
    }
    return ret;
}

int func_020309a4(int groupNo, NNSSndHeap *heap) {
    NNSSndArcGroupInfo *group = func_020301dc(groupNo);
    u32 i;
    int ret;
    if (group == NULL) {
        return SND_ARC_LOAD_ERR_INVALID_GROUP_NO;
    }
    for (i = 0; i < group->count; i++) {
        NNSSndArcGroupItem *item = &group->item[i];
        switch (item->type) {
            case 0:
                ret = func_02030aa0(item->index, item->loadFlag, heap, TRUE, NULL);
                if (ret != SND_ARC_LOAD_SUCCESS) {
                    return ret;
                }
                break;
            case 3:
                ret = func_02030b24(item->index, item->loadFlag, heap, TRUE, NULL);
                if (ret != SND_ARC_LOAD_SUCCESS) {
                    return ret;
                }
                break;
            case 1:
                ret = func_02030b84(item->index, item->loadFlag, heap, TRUE, NULL);
                if (ret != SND_ARC_LOAD_SUCCESS) {
                    return ret;
                }
                break;
            case 2:
                ret = func_02030cc4(item->index, item->loadFlag, heap, TRUE, NULL);
                if (ret != SND_ARC_LOAD_SUCCESS) {
                    return ret;
                }
                break;
        }
    }
    return SND_ARC_LOAD_SUCCESS;
}

int func_02030aa0(int seqNo, u32 loadFlag, NNSSndHeap *heap, BOOL setAddress, void **out) {
    NNSSndArcSeqInfo *info = func_0202ff20(seqNo);
    void *seq;
    int ret;
    if (info == NULL) {
        return SND_ARC_LOAD_ERR_INVALID_SEQ_NO;
    }
    ret = func_02030b84(info->bankNo, loadFlag, heap, setAddress, NULL);
    if (ret != SND_ARC_LOAD_SUCCESS) {
        return ret;
    }
    if (loadFlag & NNS_SND_ARC_LOAD_SEQ) {
        seq = func_02030dec(info->fileId, heap, setAddress);
        if (seq == NULL) {
            return SND_ARC_LOAD_ERR_FAILED_LOAD_SEQ;
        }
    } else {
        seq = func_02030498(info->fileId);
    }
    if (out != NULL) {
        *out = seq;
    }
    return SND_ARC_LOAD_SUCCESS;
}

int func_02030b24(int seqArcNo, u32 loadFlag, NNSSndHeap *heap, BOOL setAddress, void **out) {
    NNSSndArcSeqArcInfo *info = func_0202ff84(seqArcNo);
    void *seqArc;
    if (info == NULL) {
        return SND_ARC_LOAD_ERR_INVALID_SEQARC_NO;
    }
    if (loadFlag & NNS_SND_ARC_LOAD_SEQARC) {
        seqArc = func_02030e58(info->fileId, heap, setAddress);
        if (seqArc == NULL) {
            return SND_ARC_LOAD_ERR_FAILED_LOAD_SEQARC;
        }
    } else {
        seqArc = func_02030498(info->fileId);
    }
    if (out != NULL) {
        *out = seqArc;
    }
    return SND_ARC_LOAD_SUCCESS;
}

int func_02030b84(int bankNo, u32 loadFlag, NNSSndHeap *heap, BOOL setAddress, void **out) {
    NNSSndArcBankInfo *info = func_0202ffe8(bankNo);
    void *bank;
    int i;
    if (info == NULL) {
        return SND_ARC_LOAD_ERR_INVALID_BANK_NO;
    }
    if (loadFlag & NNS_SND_ARC_LOAD_BANK) {
        bank = func_02030ec4(info->fileId, heap, setAddress);
        if (bank == NULL) {
            return SND_ARC_LOAD_ERR_FAILED_LOAD_BANK;
        }
    } else {
        bank = func_02030498(info->fileId);
    }
    for (i = 0; i < 4; i++) {
        NNSSndArcWaveArcInfo *waveArcInfo;
        void *waveArc;
        int ret;
        if (info->waveArcNo[i] == 0xffff) {
            continue;
        }
        waveArcInfo = func_0203004c(info->waveArcNo[i]);
        if (waveArcInfo == NULL) {
            return SND_ARC_LOAD_ERR_INVALID_WAVEARC_NO;
        }
        ret = func_02030cc4(info->waveArcNo[i], loadFlag, heap, setAddress, &waveArc);
        if (ret != SND_ARC_LOAD_SUCCESS) {
            return ret;
        }
        if ((waveArcInfo->flags & 1) && (loadFlag & NNS_SND_ARC_LOAD_WAVE)) {
            if (!func_020312d4(waveArc, bank, i, waveArcInfo->fileId, heap)) {
                return SND_ARC_LOAD_ERR_FAILED_LOAD_WAVE;
            }
        }
        if (bank != NULL && waveArc != NULL) {
            func_0201ca68(bank, i, waveArc);
        }
    }
    if (out != NULL) {
        *out = bank;
    }
    return SND_ARC_LOAD_SUCCESS;
}

int func_02030cc4(int waveArcNo, u32 loadFlag, NNSSndHeap *heap, BOOL setAddress, void **out) {
    NNSSndArcWaveArcInfo *info = func_0203004c(waveArcNo);
    void *waveArc;
    if (info == NULL) {
        return SND_ARC_LOAD_ERR_INVALID_WAVEARC_NO;
    }
    if (loadFlag & NNS_SND_ARC_LOAD_WAVE) {
        if (info->flags & 1) {
            waveArc = func_02030f9c(info->fileId, heap, setAddress);
        } else {
            waveArc = func_02030f30(info->fileId, heap, setAddress);
        }
        if (waveArc == NULL) {
            return SND_ARC_LOAD_ERR_FAILED_LOAD_WAVE;
        }
    } else {
        waveArc = func_02030498(info->fileId);
    }
    if (out != NULL) {
        *out = waveArc;
    }
    return SND_ARC_LOAD_SUCCESS;
}

void *func_02030d48(u32 fileId, NNSSndHeapDisposeCallback callback, u32 arg0, u32 arg1, NNSSndHeap *heap) {
    u32 size = func_02030388(fileId);
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
    if (func_020303b0(fileId, buffer, size, 0) != size) {
        return NULL;
    }
    func_02019278(buffer, size);
    return buffer;
}

void *func_02030dec(u32 fileId, NNSSndHeap *heap, BOOL setAddress) {
    void *seq = func_02030498(fileId);
    if (seq == NULL) {
        seq = func_02030d48(fileId, (NNSSndHeapDisposeCallback)func_0203111c, setAddress ? (u32)func_0202ff10() : 0, fileId, heap);
        if (setAddress && seq != NULL) {
            func_020304c0(fileId, seq);
        }
    }
    return seq;
}

void *func_02030e58(u32 fileId, NNSSndHeap *heap, BOOL setAddress) {
    void *seqArc = func_02030498(fileId);
    if (seqArc == NULL) {
        seqArc = func_02030d48(fileId, (NNSSndHeapDisposeCallback)func_0203111c, setAddress ? (u32)func_0202ff10() : 0, fileId, heap);
        if (setAddress && seqArc != NULL) {
            func_020304c0(fileId, seqArc);
        }
    }
    return seqArc;
}

void *func_02030ec4(u32 fileId, NNSSndHeap *heap, BOOL setAddress) {
    void *bank = func_02030498(fileId);
    if (bank == NULL) {
        bank = func_02030d48(fileId, (NNSSndHeapDisposeCallback)func_02031144, setAddress ? (u32)func_0202ff10() : 0, fileId, heap);
        if (setAddress && bank != NULL) {
            func_020304c0(fileId, bank);
        }
    }
    return bank;
}

void *func_02030f30(u32 fileId, NNSSndHeap *heap, BOOL setAddress) {
    void *waveArc = func_02030498(fileId);
    if (waveArc == NULL) {
        waveArc = func_02030d48(fileId, (NNSSndHeapDisposeCallback)func_02031174, setAddress ? (u32)func_0202ff10() : 0, fileId, heap);
        if (setAddress && waveArc != NULL) {
            func_020304c0(fileId, waveArc);
        }
    }
    return waveArc;
}
